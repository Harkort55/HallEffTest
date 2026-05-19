# HallEffTest

PlatformIO project for ESP32 (`esp32dev`) using the Arduino framework.

## Overview

Reads an ESP32 Hall effect sensor via `hallRead()` and toggles a GPIO output (`GPIO 25`) at two rates depending on an input (`GPIO 26`).

## Features

- Prints Hall sensor values to serial at 115200 baud
- Toggles `GPIO 25`:
	- 10 Hz when `GPIO 26` is LOW
	- 1 Hz when `GPIO 26` is HIGH (internal pull-up enabled)
- `GPIO 26` is configured as `INPUT_PULLUP` for a button or external logic input

## Pin connections

- `GPIO 25`: output (LED toggled)
- `GPIO 26`: input with pull-up (active LOW to change toggle rate; connect button to GND)
- Hall sensor: wired to board-specific pins for `hallRead()` (ESP32 internal)

## Build & upload (PlatformIO)

Run these in the project root:

```powershell
# build
platformio run

# build and upload
platformio run --target upload

# monitor serial (115200)
platformio device monitor --baud 115200
```

If you prefer the short `pio` commands, the existing quick commands still work in many setups:

```bash
# Build
pio run

# Upload (connect your ESP32)
pio run -t upload -e esp32dev

# Monitor serial
pio device monitor -b 115200
```

## Usage

1. Connect your board and upload the firmware.
2. Open the serial monitor at 115200 baud.
3. Observe `Hall sensor:` and `Pin 26:` output. Pressing a button tied to `GPIO 26` and GND will change the toggle rate of `GPIO 25`.

## Notes

- The toggle uses `millis()` for non-blocking timing so serial reads remain responsive.
- If you want to change pins, edit `src/main.cpp` accordingly.

## License

Add a license file if you want to make this project public under a specific license.

