#include <mbq.h>

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    DigitalWrite(D8, true);
    delayMicroseconds(tone);
    DigitalWrite(D8, false);
    delayMicroseconds(tone);
  }
}
void playNote(char note, int beat, int tempo) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], beat * tempo);
    }
 }
}

void setup()
{
	float forwardSpeed, backwardSpeed, leftSpeed, rightSpeed, stopSpeed, duration, distance, tolerance;

	display.begin(SSD1306_SWITCHCAPVCC);
	display.display();
	delay(1000);
	display.clearDisplay();
	display.setTextSize(2);
	display.setTextColor(WHITE);
	display.setCursor(0,0);
	display.clearDisplay();

	initBoard();
	while(true)
	{
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
			stopSpeed = 0;
		DigitalWrite(D4, false);
		DigitalWrite(D2, false);
		DigitalWrite(D5, false);
		DigitalWrite(D7, false);
		AnalogWrite(PWM3, stopSpeed);
		AnalogWrite(PWM6, stopSpeed);
		
			delay(1000);
			display.setCursor((int)0, (int)0);
			display.println("STOP");
	display.display();
		
			display.clearDisplay();
		}
		else
		{
			forwardSpeed = 50;
		DigitalWrite(D4, false);
		DigitalWrite(D2, true);
		DigitalWrite(D5, false);
		DigitalWrite(D7, true);
		AnalogWrite(PWM3, forwardSpeed);
		AnalogWrite(PWM6, forwardSpeed);
		
			delay(1000);
			display.setCursor((int)0, (int)0);
			display.println("FORWARD");
	display.display();
		
			display.clearDisplay();
		}
	}
}

void loop()
{
}


