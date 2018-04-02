
#include "myLib.h"
#include "stdio.h"
#include "garbage.h"
#include "tank.h"

int main() {
	REG_DISPCNT = MODE3 | BG2_ENABLE;
	//*(OFFSET(80, 120, 240) +videoBuffer ) = YELLOW; 
	//videoBuffer[OFFSET(80, 120, 240)] = YELLOW;
	//drawRect(10, 20, 30, 40, GREEN);


	while(1) { // Game Loop


		waitForVblank();

		if (KEY_DOWN_NOW(BUTTON_UP)) {
			drawImage3(40, 50, PIXEL_TANK_WIDTH, PIXEL_TANK_HEIGHT, pixel_tank);
		} else {
			drawImage3(0, 0, GARBAGE_WIDTH, GARBAGE_HEIGHT, garbage);
		}



		//0, 0, GARBAGE_WIDTH, GARBAGE_HEIGHT, 
	} // Game Loop

}