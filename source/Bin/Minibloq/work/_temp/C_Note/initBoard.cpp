#include <mbq.h>




void initBoard()
{
	Serial.begin(115200);

	//Uses the analog input 0, that may have the same value in some designs, but it's not so prabably:
	randomSeed(analogRead(0));

}
