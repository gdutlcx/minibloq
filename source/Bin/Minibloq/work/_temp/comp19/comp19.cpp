#include <mbq.h>
#include <PingIRReceiver.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void setup()
{
	float forwardSpeed, backwardSpeed, leftSpeed, rightSpeed, duration, distance, tolerance;
	initBoard();
	tolerance = 20;
	DigitalWrite(A5, false);
	delayMicroseconds(2);
	DigitalWrite(A5, true);
	delayMicroseconds(10);
	DigitalWrite(A5, false);
	duration = PulseIn(A4, true, 1000000);
	distance = duration/58;
	if (distance < tolerance)
	{
		forwardSpeed = 0;
		DigitalWrite(D4, false);
		DigitalWrite(D2, true);
		DigitalWrite(D5, false);
		DigitalWrite(D7, true);
		AnalogWrite(PWM3, forwardSpeed);
		AnalogWrite(PWM6, forwardSpeed);
		
	}
	else
	{
	}
}

void loop()
{
}
