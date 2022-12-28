#include <SPI.h>
#include <ssd1322.h>

uint8_t frame_buffer[8192];
 
char char_counter = 0;
 
void setup()
{
    Serial.begin(115200);
    // while (!Serial);

	delay(2000);
	
	SPI.begin();

	Serial.println("Initialize");
	
    ssd1322_initialize();

	Serial.println("Clear display RAM");
    ssd1322_fill_ram(0x00);
	
    ssd1322_fill_fb(frame_buffer, 0x00);
    ssd1322_display_fb(frame_buffer);

	delay(500);
}

void loop()
{
    ssd1322_fill_fb(frame_buffer, 0x00);

	for (uint8_t i = 0; i < 3; ++i)
	{
		for (uint8_t j = 0; j < 19; ++j)
		{
			draw_char_on_framebuffer(frame_buffer, char_counter + 32, j, i);			
		}
	}
    ssd1322_display_fb(frame_buffer);

	char_counter = (char_counter + 1) % 102;
		
    delay(100);
}



