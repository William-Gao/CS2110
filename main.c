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

	TankBullet bullets[10];
	int numBullets = 0;
	//Initializing current position of tank that will be used throughout
	int curr_r = init_r;
	int curr_c = init_c;

	//Initializing gun position
	int gun_r;
	int gun_c;

	int bul_vel = 2;

	//vblanks for delay
	int vblanks = 0;
	int button_a_delay = 0;

	drawBackground(field);
	while(1) { // Game Loop


		waitForVblank();
		vblanks++;
		// if (vblanks == 1000) {
		// 	vblanks = 0;
		// }
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
		} else if (KEY_DOWN_NOW(BUTTON_DOWN)) {
			int bottom_wall = 160 - TIGER_V2_HEIGHT;
			if (curr_r < bottom_wall) {
				rebuff_r = curr_r;
				rebuff_c = curr_c;
				rebuff_height = mvmt_speed;
				rebuff_width = TIGER_V2_WIDTH;
				
				curr_r = curr_r + mvmt_speed;
			}
		}

		else if (KEY_DOWN_NOW(BUTTON_RIGHT)) {
			int right_wall = 240 - TIGER_V2_WIDTH;
			
			if (curr_c < right_wall) {

				rebuff_c = curr_c;
				rebuff_r = curr_r;
				rebuff_height = TIGER_V2_HEIGHT;
				rebuff_width = mvmt_speed;

				curr_c = curr_c + mvmt_speed;


			}
		}

		else if (KEY_DOWN_NOW(BUTTON_LEFT)) {
			if (curr_c > mvmt_speed) {
				curr_c = curr_c - mvmt_speed;

				rebuff_r = curr_r;
				rebuff_c = curr_c + TIGER_V2_WIDTH;
				rebuff_width = mvmt_speed;
				rebuff_height = TIGER_V2_HEIGHT; 
			}
		}

		//A fires bullet
		if (KEY_DOWN_NOW(BUTTON_A)) {
			//Bullet shall be 2 x 2
			
			if (numBullets < 10) {

				if (vblanks % 5 == 0) {
					gun_c = curr_c + TIGER_V2_WIDTH;
					gun_r = curr_r + (TIGER_V2_HEIGHT / 2) - 1;

					bullets[numBullets] = (TankBullet) {gun_r, gun_c};
					numBullets++;				
				}
				
			}

		}

		//B reloads the gun for another 10 rounds
		if (KEY_DOWN_NOW(BUTTON_B)) {

			//means we've used up all our ammunition
			if (numBullets == 10){

				//last bullet has travelled off the screen
				if (bullets[9].c >= 240) {
					numBullets = 0;				
				}
			}
		}

	drawImage3(curr_r, curr_c, TIGER_V2_WIDTH, TIGER_V2_HEIGHT, Tiger_v2);

	for (int i = 0; i < numBullets; i++) {
		if (bullets[i].c < 240) {
			rebuff(bullets[i].r, bullets[i].c, 2, 2, field);
			bullets[i].c = bullets[i].c + bul_vel;

			//Only draw it off the screen if it's entirety will show up
			if (bullets[i].c < 238) {
				drawBullet(bullets[i].r, bullets[i].c, 2, 2);				
			}
		}
	}

	//This means that we need to rebuff the background
	if (!(rebuff_r == 0)) {
			rebuff(rebuff_r, rebuff_c, rebuff_width, rebuff_height, field);
		}
	} // Game Loop

}