#include "myLib.h"
#include "stdio.h"
#include "images/tiger.h"
#include "images/field.h"
#include "text.h"

int main() {
	REG_DISPCNT = MODE3 | BG2_ENABLE;

	//upper left hand tarting location of human tank
	int init_r = 80;
	int init_c = 0;
	int mvmt_speed = 1;

	//draws the starting location of the tank


	//Star
	int curr_r = init_r;
	int curr_c = init_c;

	//int width
	drawBackground(field);
	while(1) { // Game Loop


		waitForVblank();
		volatile int rebuff_r = 0;
		volatile int rebuff_c = 0;
		volatile int rebuff_width = 0;
		volatile int rebuff_height = 0;
		
		if (KEY_DOWN_NOW(BUTTON_UP)) {
			if (curr_r > 0) {
				curr_r = curr_r - mvmt_speed;
				
				rebuff_r = curr_r + TIGER_V2_HEIGHT;
				rebuff_c = curr_c;
				rebuff_height = mvmt_speed;
				rebuff_width = TIGER_V2_WIDTH;
			}
			drawChar(4, 4, 'H', 0x7FFF);
			//b/c we're going up, it has to be 'minus'
		}

		if (KEY_DOWN_NOW(BUTTON_DOWN)) {
			int bottom_wall = 160 - TIGER_V2_HEIGHT;
			if (curr_r < bottom_wall) {
				rebuff_r = curr_r;
				rebuff_c = curr_c;
				rebuff_height = mvmt_speed;
				rebuff_width = TIGER_V2_WIDTH;
				
				curr_r = curr_r + mvmt_speed;
			}
		}

		if (KEY_DOWN_NOW(BUTTON_RIGHT)) {
			int right_wall = 240 - TIGER_V2_WIDTH;
			
			if (curr_c < right_wall) {
				rebuff_c = curr_c;

				curr_c = curr_c + mvmt_speed;

				rebuff_r = curr_r;

				rebuff_height = TIGER_V2_HEIGHT;
				rebuff_width = mvmt_speed;
			}
		}

		if (KEY_DOWN_NOW(BUTTON_LEFT)) {
			if (curr_c > mvmt_speed) {
				curr_c = curr_c - mvmt_speed;

			}
		}

	drawImage3(curr_r, curr_c, TIGER_V2_WIDTH, TIGER_V2_HEIGHT, Tiger_v2);

	//This means that we need to rebuff the background
	if (!(rebuff_r == 0)) {
			rebuff(rebuff_r, rebuff_c, rebuff_width, rebuff_height, field);
		}
	} // Game Loop

}