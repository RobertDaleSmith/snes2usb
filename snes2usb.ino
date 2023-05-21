#include <HID.h>
#include <Mouse.h>
#include <XInput.h>
#include <Joystick.h>
#include "SNESpad.h"

// Pins for SNES controller
#define LATCH_PIN 6
#define CLOCK_PIN 5
#define DATA_PIN 7

SNESpad snesPad = SNESpad(LATCH_PIN, CLOCK_PIN, DATA_PIN);

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  8, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

void setup() {
  // Initialize X-input controller
  XInput.setAutoSend(true);  // Wait for all controls before sending
  XInput.begin();

  // initialize mouse control:
  Mouse.begin();

  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(-1, 1);
  Joystick.setYAxisRange(-1, 1);
}

void loop() {
  // Read SNES controller state
  uint32_t btns = snesPad.buttons(SNES_MOUSE_FAST);

  // Map SNES controller state to X-input controller state
  XInput.setButton(BUTTON_A, btns & SNES_B);
  XInput.setButton(BUTTON_B, btns & SNES_A);
  XInput.setButton(BUTTON_X, btns & SNES_Y);
  XInput.setButton(BUTTON_Y, btns & SNES_X);
  XInput.setButton(BUTTON_LB, btns & SNES_L);
  XInput.setButton(BUTTON_RB, btns & SNES_R);
  XInput.setButton(BUTTON_START, btns & SNES_START);
  XInput.setButton(BUTTON_BACK, btns & SNES_SELECT);
  XInput.setDpad(btns & SNES_UP, btns & SNES_DOWN, btns & SNES_LEFT, btns & SNES_RIGHT);

  Joystick.setButton(0, !!(btns & SNES_B));
  Joystick.setButton(1, !!(btns & SNES_A));
  Joystick.setButton(2, !!(btns & SNES_Y));
  Joystick.setButton(3, !!(btns & SNES_X));
  Joystick.setButton(4, !!(btns & SNES_L));
  Joystick.setButton(5, !!(btns & SNES_R));
  Joystick.setButton(6, !!(btns & SNES_SELECT));
  Joystick.setButton(7, !!(btns & SNES_START));
  
  if (btns & SNES_LEFT) Joystick.setXAxis(-1);
  else if (btns & SNES_RIGHT) Joystick.setXAxis(1);
  else Joystick.setXAxis(0);

  if (btns & SNES_UP) Joystick.setYAxis(-1);
  else if (btns & SNES_DOWN) Joystick.setYAxis(1);
  else Joystick.setYAxis(0);

  bool isMouse = ((btns & SNES_DEVICE_ID) >> 12) == SNES_MOUSE_ID;
  int x = 127;  //set center position [0-255]
  int y = 127;
  if (isMouse) {
    // Mouse X axis
    x = 0;
    if (btns & SNES_MOUSE_X) {
      x = (btns & SNES_MOUSE_X) >> 25;
      x = flipByte(x) * -1;
    }
    if (btns & SNES_MOUSE_X_SIGN) x = 127 + x;
    else x = 127 - x;

    // Mouse Y axis
    y = 0;
    if (btns & SNES_MOUSE_Y) {
      y = (btns & SNES_MOUSE_Y) >> 17;
      y = flipByte(y) * -1;
    }
    if (btns & SNES_MOUSE_Y_SIGN) y = 127 + y;
    else y = 127 - y;

    int mouseX = x-127;
    int mouseY = y-127;
    if (mouseX > 1 || mouseX < -1) mouseX = mouseX * 3;
    if (mouseY > 1 || mouseY < -1) mouseY = mouseY * 3;
    Mouse.move(mouseX, mouseY);

    if (btns & SNES_X) {
      // if the mouse is not pressed, press it:
      if (!Mouse.isPressed(MOUSE_LEFT)) Mouse.press(MOUSE_LEFT);
    }
    // else the mouse button is not pressed:
    else {
      // if the mouse is pressed, release it:
      if (Mouse.isPressed(MOUSE_LEFT)) Mouse.release(MOUSE_LEFT);
    }
    if (btns & SNES_A) {
      // if the mouse is not pressed, press it:
      if (!Mouse.isPressed(MOUSE_RIGHT)) Mouse.press(MOUSE_RIGHT);
    }
    // else the mouse button is not pressed:
    else {
      // if the mouse is pressed, release it:
      if (Mouse.isPressed(MOUSE_RIGHT)) Mouse.release(MOUSE_RIGHT);
    }
  }
  
  XInput.setJoystick(JOY_RIGHT, x, y);  // Counter-clockwise

  // Send values to PC
  XInput.send();

  Joystick.sendState();
}

byte flipByte(byte c) {
  char r=0;
  for(byte i = 0; i < 8; i++) {
    r <<= 1;
    r |= c & 1;
    c >>= 1;
  }
  return r;
}
