#include <mbq.h>


Adafruit_SSD1306 display(9, 10, 11, 13, 12);


void initBoard()
{
	Serial.begin(115200);

	//Uses the analog input 0, that may have the same value in some designs, but it's not so prabably:
	randomSeed(analogRead(0));

}
