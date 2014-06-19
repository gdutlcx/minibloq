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
	initBoard();
	playNote( 'c', 1, 300);
	playNote( 'c', 1, 300);
	playNote( 'g', 1, 300);
	playNote( 'g', 1, 300);
	playNote( 'a', 1, 300);
	playNote( 'a', 1, 300);
	playNote( 'g', 1, 300);
}

void loop()
{
}


