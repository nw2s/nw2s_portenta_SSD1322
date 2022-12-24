#include <SPI.h>
#include <ssd1322.h>

uint8_t frame_buffer[8192];

void setup()
{
    Serial.begin(115200);
    while (!Serial);

	delay(5000);
	
	SPI.begin();

	Serial.println("Initialize");
	
    ssd1322_initialize();

	Serial.println("Clear display RAM");
    ssd1322_fill_ram(0x00);

}

void loop()
{
    ssd1322_fill_fb(frame_buffer, 0xFF);
    ssd1322_display_fb(frame_buffer);

    delay(500);

    ssd1322_fill_fb(frame_buffer, 0x00);
    ssd1322_display_fb(frame_buffer);
	
	delay(500);
}