
#include "myLib.h"
#include "stdio.h"
#include "garbage.h"
#include "tank.h"
#include "text.h"

int main() {
	REG_DISPCNT = MODE3 | BG2_ENABLE;

	//set up tank at 200 x 55

	int init_r = 100;
	int init_c = 95;
	drawImage3(init_r, init_c, PIXEL_TANK_WIDTH, PIXEL_TANK_HEIGHT, pixel_tank);

	int curr_r = init_r;
	int curr_c = init_c;

	//int width

	while(1) { // Game Loop


		waitForVblank();

		if (KEY_DOWN_NOW(BUTTON_UP)) {
			if (curr_r > 0) {
				curr_r = curr_r - 3;
			}
			drawChar(4, 4, 'H', 0x7FFF);
			//b/c we're going up, it has to be 'minus'
		}
		if (KEY_DOWN_NOW(BUTTON_DOWN)) {
			if (curr_r < 123) {
				curr_r = curr_r + 3;
			}
		}

		if (KEY_DOWN_NOW(BUTTON_RIGHT)) {
			if (curr_c < 240) {
				curr_c = curr_c + 3;
			}
		}

		if (KEY_DOWN_NOW(BUTTON_LEFT)) {
			if (curr_c > 0) {
				curr_c = curr_c - 3;
			}
		}
		drawImage3(curr_r, curr_c, PIXEL_TANK_WIDTH, PIXEL_TANK_HEIGHT, pixel_tank);
		//  else {
		// 	drawImage3(0, 0, GARBAGE_WIDTH, GARBAGE_HEIGHT, garbage);
		// }



		//0, 0, GARBAGE_WIDTH, GARBAGE_HEIGHT, 
	} // Game Loop

}