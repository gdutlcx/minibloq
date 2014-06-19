#include <mbq.h>
#include <PingIRReceiver.h>

void setup()
{
	initBoard();
	while(true)
	{
		float forwardSpeed = 100;
		DigitalWrite(D4, false);
		DigitalWrite(D2, true);
		DigitalWrite(D5, false);
		DigitalWrite(D7, true);
		AnalogWrite(PWM3, forwardSpeed);
		AnalogWrite(PWM6, forwardSpeed);
		delay(1000);
		DigitalWrite(D4, false);
		DigitalWrite(D2, false);
		DigitalWrite(D5, false);
		DigitalWrite(D7, false);
		AnalogWrite(PWM3, 0);
		AnalogWrite(PWM6, 0);
		delay(1000);
		float rightSpeed = 50;
		DigitalWrite(D4, false);
		DigitalWrite(D2, false);
		DigitalWrite(D5, true);
		DigitalWrite(D7, false);
		AnalogWrite(PWM3, rightSpeed);
		AnalogWrite(PWM6, rightSpeed);
		delay(1000);
		DigitalWrite(D4, false);
		DigitalWrite(D2, false);
		DigitalWrite(D5, false);
		DigitalWrite(D7, false);
		AnalogWrite(PWM3, 0);
		AnalogWrite(PWM6, 0);
		delay(1000);
	}
}

void loop()
{
}
