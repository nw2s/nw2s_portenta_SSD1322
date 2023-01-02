# nw2s Arduino Portenta SSD1322

[![Badge](https://github.com/nw2s/nw2s_portenta_SSD1322/actions/workflows/ArduinoLint.yaml/badge.svg)](https://github.com/nw2s/nw2s_portenta_SSD1322/actions/workflows/ArduinoLint.yaml)

![SSD1322 OLED Display](resources/oled.jpg?raw=true "Fira Code demo")

This SSH1322 Driver works with the Arduino Portenta H7.

Wiring:

- Data, clock, and chip select are wired to SPI1 (which is connected to 'SPI' in the H7 framework)
- Reset -> GPIO0 (PC_13)
- Data/Command -> GPIO1 (PC_15)

The mjority of the low-level code is based on the library located at https://github.com/adomkwabena/SSD1322_OLED_Driver - but with the CMSIS/HAL code removed and replaced with Arduino library routines. 

The font is based on a Fira Code which I discovered using IntelliJ. I have rendered it as a set of glyphs that are 20px x 13px. An unfortunate overall dimension for various reasons, but the font is just right for the display and is a lot prettier than most of the binary bitmapped fonts that are available in the other OLED drivers. https://github.com/tonsky/FiraCode

![Font example](resources/font.png?raw=true "Font Sample")


## Hardware

This code has been tested on both the NHD 2.8" 256x64 display and the more generic 3.12" model that seems to be available from many AliExpress vendors. There are others it's likely to work with just as well. I prefer the models available on Ali simply because the pin placement is more compact and allows you to squeeze the display closer to the top of a eurorack module. The only problem with the AliExpress models is that the interface (serial vs parallel) is hardwired using 0ohm resistors. You will need to adjust the placement of the resistors to allow for SPI (serial) operation. 

- NHD 2.8 256x64 vendors on Octopart https://octopart.com/nhd-2.8-25664ucb2-newhaven+display-20012480
- NHD 2.8 256x64 Product Page https://newhavendisplay.com/2-8-inch-blue-graphic-oled-module/
- AliExpress 3.12 256x64 Examples https://www.aliexpress.us/item/3256804444062750.html https://www.aliexpress.us/item/3256802981939778.html

## Wiring

### NHD

| Display Pin | Description | Portenta Pin | Description |
|-------------|-------------|--------------|-------------|
|             |             |              |             |
|             |             |              |             |
|             |             |              |             |

### AliExpress

| Display Pin | Description | Portenta Pin | Description |
|-------------|-------------|--------------|-------------|
|             |             |              |             |
|             |             |              |             |
|             |             |              |             |


## Code Samples

### Simple Interface

The simple interface is just a straightforward C interface. The frame buffer is a 128 x 64 byte buffer where each pixel is 4 bits (16 levels of gray scale) - resulting in 256x64 pixels.

1. allocate a frame buffer
2. start SPI
3. initialize/clear display
4. draw on frame buffer
5. display what's in the frame buffer

```c
	
uint8_t frame_buffer[8192];

SPI.begin();

ssd1322_initialize();

ssd1322_fill_ram(0x00);

ssd1322_fill_fb(frame_buffer, 0x00);
ssd1322_display_fb(frame_buffer);

draw_char_on_framebuffer(frame_buffer, char_counter + 32, j, i);			

ssd1322_display_fb(frame_buffer);

```

TODO in 0.2.0 - Full pin configuration

### RTOS Driver

This driver assumes you are running mbed RTOS threads. It sets up a thread and updates the display about 25 times a second. While you may say - "Hey - why don't you only update when necessary?!" - Well, the thing about DSP is that you need predicable load to ensure a guaranteed latency. You should also redude the amount of conditional code as that is harder to optimize. For this reason, we will predictably update the display at a fixed rate. 

Ideally, you would do this on the M4 processor while your M7 is dedidated to something more intensive like audio DSP or CV code. 

TODO in 0.3.0



