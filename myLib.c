#include "myLib.h"

#define OFFSET_DST(r, c) ((r)*240 + (c))
#define OFFSET_SRC(r, c, width) ((r)*(width) + (c))

volatile unsigned short *videoBuffer = (volatile unsigned short *)0x6000000;

/* drawimage3
* A function that will draw an arbitrary sized image
* onto the screen (with DMA).
* @param r row to draw the image
* @param c column to draw the image
* @param width width of the image
* @param height height of the image
* @param image Pointer to the first element of the image.
*/
void drawImage3 (int r, int c, int width, int height, const u16* image) {

	volatile unsigned short* dst_start_pointer;
	volatile unsigned short* src_start_pointer;

	for (int row = 0; row < height; row++) {

		//modifies the src and dst pointers to point to beginning of next row
		src_start_pointer = (unsigned short*) (OFFSET_SRC(row, 0, width) + image);

		//with each run of the loop, we move to the next thing
		dst_start_pointer = OFFSET_DST(r + row, c) + videoBuffer;

		DMA[3].src = src_start_pointer;
		DMA[3].dst = dst_start_pointer;
		DMA[3].cnt = width | DMA_NOW | DMA_ON;
	}

}

/**
 *rebuffs the background so that when objects move the background is properly redrawn
 * @param r row to draw the image
 * @param c column to draw the image
 * @param width width of the rebuff
 * @param height height of the rebuff
 * @param image Pointer to the first element of the background img.
 */
void rebuff(int r, int c, int width, int height, const u16* background) {
	
	volatile unsigned short* dst_start_pointer;
	volatile unsigned short* src_start_pointer;
	
	for (int row = 0; row < height; row++) {

		//modifies the src and dst pointers to point to beginning of next row
		src_start_pointer = (unsigned short*) (OFFSET_SRC(row + r, 0, 240) + background);

		//with each run of the loop, we move to the next thing
		dst_start_pointer = OFFSET_DST(row + r, c) + videoBuffer;

		DMA[3].src = src_start_pointer;
		DMA[3].dst = dst_start_pointer;
		DMA[3].cnt = width | DMA_NOW | DMA_ON;
	}
}

void drawBackground(const u16* image) {
	DMA[3].src = image;
	DMA[3].dst = videoBuffer;
	DMA[3].cnt = 0x9600 | DMA_NOW | DMA_ON;
}


// setPixel -- set the pixel at (row, col) to color
void setPixel(int row, int col, unsigned short color) {
	videoBuffer[OFFSET(row, col, 240)] = color;
}


void waitForVblank() {
	while (SCANLINECOUNTER > 160)
				;
	while (SCANLINECOUNTER < 160)
				;
}