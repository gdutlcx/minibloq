#include <mbq.h>
#include <PingIRReceiver.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(9, 10, 11, 13, 12);

void setup()
{
	float forwardSpeed, backwardSpeed, leftSpeed, rightSpeed, duration, distance;
	initBoard();
	while(true)
	{
		delay(100);
	}
}

void loop()
{
}
