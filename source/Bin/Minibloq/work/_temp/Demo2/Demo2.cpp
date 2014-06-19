#include <mbq.h>

void forward(int speed) {
	DigitalWrite(D4, false);
	DigitalWrite(D2, true);
	DigitalWrite(D5, false);
	DigitalWrite(D7, true);
	AnalogWrite(PWM3, speed);
	AnalogWrite(PWM6, speed);
}
void backward(int speed) {
	DigitalWrite(D4, true);
	DigitalWrite(D2, false);
	DigitalWrite(D5, true);
	DigitalWrite(D7, false);
	AnalogWrite(PWM3, speed);
	AnalogWrite(PWM6, speed);
}
void left(int speed) {
	DigitalWrite(D4, true);
	DigitalWrite(D2, false);
	DigitalWrite(D5, false);
	DigitalWrite(D7, false);
	AnalogWrite(PWM3, speed);
	AnalogWrite(PWM6, speed);
}
void right(int speed) {
	DigitalWrite(D4, false);
	DigitalWrite(D2, false);
	DigitalWrite(D5, true);
	DigitalWrite(D7, false);
	AnalogWrite(PWM3, speed);
	AnalogWrite(PWM6, speed);
}
void stop() {
	DigitalWrite(D4, false);
	DigitalWrite(D2, false);
	DigitalWrite(D5, false);
	DigitalWrite(D7, false);
	AnalogWrite(PWM3, 0);
	AnalogWrite(PWM6, 0);
}
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
void initdisplay() {
	display.setTextSize(2);
	display.setTextColor(WHITE);
	display.setCursor(0,0);
	display.clearDisplay();
}
void setup()
{

	initBoard();
	while(true)
	{
		forward(50);
		delay(1000);
		stop();
		delay(1000);
		backward(50);
		delay(1000);
		stop();
		delay(1000);
	}
}

void loop()
{
}


