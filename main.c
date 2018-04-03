
#include "myLib.h"
#include "stdio.h"
#include "images/tiger.h"
#include "text.h"

int main() {
	REG_DISPCNT = MODE3 | BG2_ENABLE;

	//Starting location of the first tank
	int init_r = 100;
	int init_c = 95;

	//draws the starting location of the tank
	drawImage3(init_r, init_c, TIGER_V2_WIDTH, TIGER_V2_HEIGHT, Tiger_v2);

	//Star
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
			// int bottom_wall = 160 - 
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
	drawImage3(curr_r, curr_c, TIGER_V2_WIDTH, TIGER_V2_HEIGHT, Tiger_v2);
		//  else {
		// 	drawImage3(0, 0, GARBAGE_WIDTH, GARBAGE_HEIGHT, garbage);
		// }



		//0, 0, GARBAGE_WIDTH, GARBAGE_HEIGHT, 
	} // Game Loop

}