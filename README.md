SNES-2-USB
=====

[SNES-2-USB](https://controlleradapter.com/products/snes-2-usb) is a controller adapter that converts Super Nintendo controllers and mice into standard USB HID devices. Powered by [SNESpad](https://github.com/RobertDaleSmith/SNESpad) and [GP2040-CE](https://gp2040-ce.info/) the USB adapter can operate in X-input, PS3, PS4, Switch, or keyboard modes.

This repo will be used for issue tracking and firmware releases with proper change logs.

Firmwares
-----

# GP2040-CE Controller
	A custom GP2040-CE build for the SNES-2-USB.
- u2f: [SNES2USB_GP2040-CE_0.7.1_KB2040.uf2](https://github.com/RobertDaleSmith/snes2usb/releases/download/v0.1/SNES2USB_GP2040-CE_0.7.1_KB2040.uf2 "download")
- src: https://github.com/RobertDaleSmith/GP2040-CE/tree/SNES2USB

# USB HID Mouse
	A dedicated SNES mouse to USB HID mouse firmware for SNES-2-USB.
- u2f: [SNES2USB_HIDMOUSE_0.1_KB2040.uf2](https://github.com/RobertDaleSmith/snes2usb/releases/download/v0.1/SNES2USB_HIDMOUSE_0.1_KB2040.uf2 "download")
- src: https://github.com/RobertDaleSmith/SNESpad/blob/main/examples/mouse

## Firmware Update Instructions

1. Disconnected adapter from the console and all connected USB devices.
2. While holding the boot(+) button, connect the USB-C port to a computer.
3. A virual drive called RPI-RP2 will appear, drag-n-drop the UF2 update file onto the drive.
4. The virtual drive will automatically unmount when the update is completed. 🚀

Hardware
-----
Adafruit KB2040 -> https://www.adafruit.com/product/5302

SNES Arduino Shield -> https://www.flux.ai/robertdalesmith/snes-controller-arduino-nano-shield
