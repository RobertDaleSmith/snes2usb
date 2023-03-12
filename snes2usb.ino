#include <XInput.h>
#include "SNESpad.h"

// Pins for SNES controller
#define LATCH_PIN 6
#define CLOCK_PIN 5
#define DATA_PIN 7

SNESpad snesPad = SNESpad(LATCH_PIN, CLOCK_PIN, DATA_PIN);

void setup() {
  // Initialize X-input controller
  XInput.setAutoSend(true);  // Wait for all controls before sending
  XInput.begin();
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

//  // map dpad to analog
//  int x = 127;  //set center position [0-255]
//  int y = 127;
//  XInput.setJoystick(JOY_RIGHT, x, y);  // Counter-clockwise

  // Send values to PC
  XInput.send();
}
