
#include "myLib.h"
#include "stdio.h"
#include "garbage.h"

int main() {
	REG_DISPCNT = MODE3 | BG2_ENABLE;
	//*(OFFSET(80, 120, 240) +videoBuffer ) = YELLOW; 
	//videoBuffer[OFFSET(80, 120, 240)] = YELLOW;
	//drawRect(10, 20, 30, 40, GREEN);


	while(1) { // Game Loop


		waitForVblank();
		drawImage3(0, 0, GARBAGE_WIDTH, GARBAGE_HEIGHT, garbage);


		//0, 0, GARBAGE_WIDTH, GARBAGE_HEIGHT, 
	} // Game Loop

}