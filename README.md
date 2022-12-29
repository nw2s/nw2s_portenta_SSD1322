# nw2s_portenta_SSD1322

[![.github/workflows/Arduino Lint.yaml](https://github.com/nw2s/nw2s_portenta_SSD1322/actions/workflows/Arduino Lint.yaml/badge.svg)](https://github.com/nw2s/nw2s_portenta_SSD1322/actions/workflows/Arduino Lint.yaml)

![SSD1322 OLED Display](resources/oled.jpg?raw=true "Fira Code demo")

This SSH1322 Driver works with the Arduino Portenta H7.

Wiring:

- Data, clock, and chip select are wired to SPI1 (which is connected to 'SPI' in the H7 framework)
- Reset -> GPIO0 (PC_13)
- Data/Command -> GPIO1 (PC_15)

The mjority of the low-level code is based on the library located at https://github.com/adomkwabena/SSD1322_OLED_Driver - but with the CMSIS/HAL code removed and replaced with Arduino library routines. 

The font is based on a Fira Code which I discovered using IntelliJ. I have rendered it as a set of glyphs that are 20px x 13px. An unfortunate overall dimension for various reasons, but the font is just right for the display and is a lot prettier than most of the binary bitmapped fonts that are available in the other OLED drivers. https://github.com/tonsky/FiraCode

![Font example](resources/font.png?raw=true "Font Sample")
