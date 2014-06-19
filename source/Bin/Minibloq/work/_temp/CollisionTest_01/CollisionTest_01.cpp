#include <mbq.h>
#include <PingIRReceiver.h>

void setup()
{
	initBoard();
	float duration = 0;
	float distance = 0;
	while(true)
	{
		DigitalWrite(A5, false);
		delayMicroseconds(2);
		DigitalWrite(A5, true);
		delayMicroseconds(10);
		DigitalWrite(A5, false);
		duration = PulseIn(A4, true, 1000000);
		distance = (duration/2) / 29.1;
		if((distance<20))
		{
			DigitalWrite(D4, false);
			DigitalWrite(D2, false);
			DigitalWrite(D5, false);
			DigitalWrite(D7, false);
			AnalogWrite(PWM3, 0);
			AnalogWrite(PWM6, 0);
			delay(100);
		}
		else
		{
			float forwardSpeed = 50;
			DigitalWrite(D4, false);
			DigitalWrite(D2, true);
			DigitalWrite(D5, false);
			DigitalWrite(D7, true);
			AnalogWrite(PWM3, forwardSpeed);
			AnalogWrite(PWM6, forwardSpeed);
			delay(100);
		}
	}
}

void loop()
{
}
