Misc [ESPHome](https://esphome.io/) based projects

## irkeyboard

Receive IR codes with `remote_receiver` and convert them into BLE HID keystrokes. Uses a [`Esp32BLEKeyboard` custom component](esp32_ble_keyboard.h) and the [ESP32 BLE Keyboard library](https://github.com/T-vK/ESP32-BLE-Keyboard).

This allows using the play/pause/etc buttons on my TV remote with my computer. I typically don't have my computer on while using other HDMI inputs, otherwise both the TV and PC might problematically react to the same input.

ESP32 required for BLE.
