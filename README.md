SNES-2-USB
=====

[SNES-2-USB](https://controlleradapter.com/products/snes-2-usb) is a controller adapter that converts Super Nintendo controllers and mice into standard USB HID devices. Powered by [SNESpad](https://github.com/RobertDaleSmith/SNESpad) and [GP2040-CE](https://gp2040-ce.info/) the USB adapter can operate in X-input, PS3, PS4, Switch, or keyboard modes.

This repo will be used for issue tracking and firmware releases with proper change logs.

Firmwares
-----

# GP2040-CE Controller
	A custom GP2040-CE build for the SNES-2-USB.
- src: https://github.com/RobertDaleSmith/GP2040-CE/tree/SNES2USB
- u2f: [SNES2USB_GP2040-CE_0.7.1_KB2040.uf2](SNES2USB_GP2040-CE_0.7.1_KB2040.uf2 "download")

# USB HID Mouse
	A dedicated SNES mouse to USB HID mouse firmware for SNES-2-USB.
- src: https://github.com/RobertDaleSmith/SNESpad/blob/main/examples/mouse
- u2f: [SNES2USB_HIDMOUSE_0.1_KB2040.uf2](SNES2USB_HIDMOUSE_0.1_KB2040.uf2 "download")

Hardware
-----
Arduino Pro Micro -> https://www.amazon.com/ATmega32U4-Micro-USB-Development-Compatible-ATmega328/dp/B07PHK8SMR

SNES Arduino Shield -> https://www.flux.ai/robertdalesmith/snes-controller-arduino-nano-shield
