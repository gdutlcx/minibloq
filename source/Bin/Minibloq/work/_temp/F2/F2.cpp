#include <mbq.h>
void setup()
{
	float forwardSpeed, backwardSpeed, leftSpeed, rightSpeed, stopSpeed, duration, distance, tolerance;
	initBoard();
	while(true)
	{
		forwardSpeed = 50;
		DigitalWrite(D4, false);
		DigitalWrite(D2, true);
		DigitalWrite(D5, false);
		DigitalWrite(D7, true);
		AnalogWrite(PWM3, forwardSpeed);
		AnalogWrite(PWM6, forwardSpeed);
		
		delay(1000);
	}
}

void loop()
{
}
