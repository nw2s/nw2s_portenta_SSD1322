#include <SPI.h>
#include <ssd1322.h>

// The sending timer and interval
uint32_t sendNow { 0 };
constexpr uint32_t sendInterval { 2500 };

// An incremental counter for testing SPI communications
uint8_t counter;

void setup()
{
    Serial.begin(115200);
    while (!Serial);

	delay(5000);

    counter = 0;
}

void loop()
{
    // put your main code here, to run repeatedly:
    if (millis() > sendNow) 
	{
        // Wait for the next cycle
        sendNow = millis() + sendInterval;
    }
}