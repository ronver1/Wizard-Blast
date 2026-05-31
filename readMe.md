# Wizard Blast

A two-player embedded fighting game built in C++ for the **TI MSPM0G3507** microcontroller. Developed as the final project for **ECE319H (Honors Embedded Systems)** at UT Austin.

Players control wizards on an ST7735R LCD display, battling in real time using slide potentiometers as input. The game features sprite-based combat, 12-bit DAC audio, LED feedback, and full bilingual (English/Spanish) UI support.

---

## Academic Integrity Notice
- This repository is shared for educational and portfolio purposes only.
- If you are currently enrolled in ECE 319H or a similar course, please do not copy this code directly.

---

## Features

- **Two-player local combat** — each player controls a wizard via their own slide potentiometer
- **Real-time sprite rendering** on a 160×128 ST7735R LCD
- **12-bit DAC audio** for sound effects
- **Bilingual support** — English and Spanish language modes
- **LED feedback** using the onboard RGB LEDs
- **UART serial communication** between two microcontrollers (one per player)

---

## Hardware Required

| Component | Part |
|---|---|
| Microcontroller | TI MSPM0G3507 LaunchPad (LP-MSPM0G3507) |
| Display | ST7735R 160×128 LCD (Adafruit #358, HiLetgo, wide.hk, or Tyenaza variants) |
| Slide Potentiometer | Bourns PTA2043-2015CPB103 (Mouser #652-PTA20432015CPB10) |

> Two full setups are required for two-player mode — one LaunchPad per player, connected via UART.

---

## Pin Assignments

### Display (SPI1 — ST7735R LCD)
| Signal | Pin |
|---|---|
| SCLK (CLK) | PB9 |
| CS (TFT_CS) | PB6 |
| MOSI (PICO) | PB8 |
| Reset (!RST) | PB15 |
| RS | PA13 |

### Audio & Analog
| Signal | Pin |
|---|---|
| 12-bit DAC output | PA15 |
| 5-bit DAC (audio) | PB0, PB1, PB2, PB3, PB4 |
| Slide potentiometer (ADC) | PB18 (ADC1 Ch5) |
| TExaS scope | PB20 (ADC0 Ch6) |

### UART (Player-to-Player)
| Signal | Pin |
|---|---|
| TX (UART1) | PA8 → other board's PA22 |
| RX (UART2) | PA22 ← other board's PA8 |
| GND | GND (shared between boards) |

### LEDs
| LED | Pin |
|---|---|
| Red LED1 | PA0 |
| Blue LED2 | PB22 |
| Red LED2 | PB26 |
| Green LED2 | PB27 |

### Switches
| Switch | Pin | Logic |
|---|---|---|
| S2 | PA18 | Positive |
| S3 | PB21 | Negative |

---

## LaunchPad Jumper Settings

- **Remove J16, J17, J18** — disconnects the onboard light sensor from PA22, PA27, PA26
- **J4** — connects PA0 to red LED
- **J5** — connects PB22 to blue LED2
- **J6** — connects PB26 to red LED2
- **J7** — connects PB27 to green LED2

---

## Project Structure

```
Wizard-Blast/
├── Lab9HMain.cpp      # Entry point and main game loop
├── Game.cpp / .h      # Core game logic and state management
├── Images.cpp / .h    # Sprite image data
├── Sound.cpp / .h     # Sound engine
├── Sounds.cpp / .h    # Audio sample data
├── Language.cpp / .h  # Bilingual string support (EN/ES)
├── LED.cpp / .h       # LED control
├── Switch.cpp / .h    # Button/switch input handling
├── SmallFont.cpp / .h # Font rendering for LCD
├── globals.cpp / .h   # Shared global state
├── designdocuments/   # Design docs and planning materials
└── images/            # Sprite source images
```

---

## Building & Flashing

This project is built using **Code Composer Studio (CCS)** with the TI clang toolchain.

1. Open CCS and import the project from the repo root
2. Connect the LP-MSPM0G3507 via USB
3. Build the project (`Ctrl+B`)
4. Flash and run via the CCS debug interface

> The ST7735R LCD must be connected before running. The slide potentiometer connects to PB18.

---
## Author
### Ronit Verma

The University of Texas at Austin

Electrical & Computer Engineering Honors + Business Honors

LinkedIn: https://www.linkedin.com/in/ronit-verma-b0a80a383/
---

## Credits

- Built on starter code and SPI examples from **Texas Instruments**:
  - `spi_controller_multibyte_fifo_poll_LP_MSPM0G3507_nortos_ticlang`
  - `spi_controller_command_data_control_LP_MSPM0G3507_nortos_ticlang`
  - `spi_peripheral_register_format_LP_MSPM0G3507_nortos_ticlang`
- Base framework by **Jonathan Valvano**, ECE319H, UT Austin

---

## License

Simplified BSD License (FreeBSD License)  
Copyright © 2025, Jonathan Valvano, All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND. See the full license terms in the source files.

For more information: http://users.ece.utexas.edu/~valvano/
