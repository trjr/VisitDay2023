#include <Header.h>

// The codes here show the different stages of the development
// To use them copy and paste the content of the function to the draw.c file and replace the body of the draw function

void draw_base(int frame) {
	// This is the base version

	// define the properties of a color
	rgb_t color;
	color.red = 255;
	color.green = 255;
	color.blue = 0;

	SDL_Rect rect1;
	// define the properties of the rectangle
	rect1.x = 100; // coordinate x
	rect1.y = 200; // coordinate y
	rect1.h = 100; // height
	rect1.w = 100; // width
	// draw a specified rectangle with the given color
	draw_rect(rect1, color);
}














// Task 2.a)
void draw_a(int frame) {
	// This version uses ifs to change the coordinate depending on the frame
	rgb_t color;
	color.red = 255;
	color.green = 255;
	color.blue = 0;

	SDL_Rect rect1;

	if (frame % 2 == 0) {
		rect1.y = 100; // coordinate x
		rect1.x = 200; // coordinate y
	}
	else {
		rect1.x = 100; // coordinate x
		rect1.y = 200; // coordinate y
	}
	rect1.h = 100; // height
	rect1.w = 100; // width

	draw_rect(rect1, color);
}














void draw_b_1(int frame) {
	// This version moves the rectangle to the right
	rgb_t color;
	color.red = 255;
	color.green = 255;
	color.blue = 0;

	SDL_Rect rect1;

	rect1.y = 100; // coordinate x
	rect1.x = 0 + frame*10; // coordinate y
	rect1.h = 100; // height
	rect1.w = 100; // width

	draw_rect(rect1, color);
}










void draw_b_2(int frame) {
  // This version stops moving to the right
  rgb_t color;
  color.red = 255;
  color.green = 255;
  color.blue = 0;

  SDL_Rect rect1;

  rect1.y = 100; // coordinate x
  rect1.x = frame*10; // coordinate y
  rect1.h = 100; // height
  rect1.w = 100; // width

  // the code must be placed after the rectangle data is set, why?
  if(rect1.x + rect1.w > SIZE){
    rect1.x = SIZE - rect1.w;
  }

  draw_rect(rect1, color);
}






void draw_b_3(int frame) {
  // This version bounces the rectangle back and forth but moves outside one boundary
	rgb_t color;
	color.red = 255;
	color.green = 255;
	color.blue = 0;

	SDL_Rect rect1;


	rect1.y = 100; // coordinate x
	rect1.h = 100; // height
	rect1.w = 100; // width

  // position, we can move forward by SIZE and backward by SIZE again
  int pos = frame * 10 % (SIZE * 2);
  if(pos > SIZE){
    rect1.x = SIZE - (pos - SIZE);
  }else{
    rect1.x = pos;
  }
  printf("pos: %d\n", rect1.x);

	draw_rect(rect1, color);
}



void draw_b_4(int frame){
  // This version bounces the rectangle back and forth correctly
	rgb_t color;
	color.red = 255;
	color.green = 255;
	color.blue = 0;

	SDL_Rect rect1;


	rect1.y = 100; // coordinate x
	rect1.h = 100; // height
	rect1.w = 100; // width

  // position, we can move forward by SIZE and backward by SIZE again
  int size = SIZE - rect1.w; // the actual maximum size is smaller as the rectangle width shouldn't be outside
  int pos = frame * 10 % (size * 2);
  if(pos > size){
    rect1.x = size - (pos - size);
  }else{
    rect1.x = pos;
  }
  printf("pos: %d\n", rect1.x);

	draw_rect(rect1, color);
}










void draw_c(int frame) {
	// This version uses a for loop to place 5 rectangles on slightly different positions
	rgb_t color;
	color.red = 255;
	color.green = 255;
	color.blue = 0;

	for (int i = 0; i < 5; i++) {
		SDL_Rect rect1;
		rect1.y = 100 + 50 * i; // coordinate x
		rect1.x = 200 * i; // coordinate y

		rect1.h = 100; // height
		rect1.w = 100; // width

		draw_rect(rect1, color);
	}
}

















void draw_d(int frame) {
	// This version changes the color for the different rectangles as well
	for (int i = 0; i < 6; i++) {
		rgb_t color;
		color.red = 40 * i;
		color.green = 0;
		color.blue = 50;

		SDL_Rect rect1;
		rect1.y = 100 + 50 * i; // coordinate x
		rect1.x = 100 + 50 * i; // coordinate y

		rect1.h = 100; // height
		rect1.w = 100; // width

		draw_rect(rect1, color);
	}
}

















void draw_e(int frame) {
	// This version also makes the green color depending on the frame
	for (int i = 0; i < 6; i++) {
		rgb_t color;
		color.red = 40 * i;
		color.green = frame * 10;
		color.blue = 50;

		SDL_Rect rect1;
		rect1.y = 100 + 50 * i; // coordinate x
		rect1.x = 100 + 50 * i; // coordinate y

		rect1.h = 100; // height
		rect1.w = 100; // width

		draw_rect(rect1, color);
	}
}















void draw_e2(int frame) {
	// This version now scales the color between 1-20, then moves backward again
	for (int i = 0; i < 6; i++) {
		rgb_t color;
		color.red = 40 * i;
		// create a scale between 1-20 that counts backwards and forwards
		// hence, we need to count up to 20, then back to 0 again, we have 40 steps!
		int scale = frame % 40;
		if (scale > 20) { // count backwards again
			scale = 20 - scale;
		}
		color.green = scale * 10;
		color.blue = 50;

		SDL_Rect rect1;
		rect1.y = 100 + 50 * i; // coordinate x
		rect1.x = 100 + 50 * i; // coordinate y

		rect1.h = 100; // height
		rect1.w = 100; // width

		draw_rect(rect1, color);
	}
}




void draw_f(int frame) {
	// draw a 2D frame of rectangles
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 6; y++) {
			rgb_t color;
			color.red = 40 * y;
			// create a scale between 1-20 that counts backwards and forwards
			// hence, we need to count up to 20, then back to 0 again, we have 40 steps!
			color.green = 10;
			color.blue = 40 * x;

			SDL_Rect rect1;
			rect1.y = 100 + 100 * y; // coordinate x
			rect1.x = 100 + 100 * x; // coordinate y

			rect1.h = 100; // height
			rect1.w = 100; // width

			draw_rect(rect1, color);
		}
	}
}
















void draw_f2(int frame){
	// our 2D frame of rectangles now using the frame depending scaling
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 6; y++) {
			rgb_t color;
			color.red = 40 * y;
			// create a scale between 1-20 that counts backwards and forwards
			// hence, we need to count up to 20, then back to 0 again, we have 40 steps!
			int scale = frame % 40;
			if (scale > 20) { // count backwards again
				scale = 20 - scale;
			}
			color.green = scale * 10;
			color.blue = 40 * x;

			SDL_Rect rect1;
			rect1.y = 100 + 100 * y; // coordinate x
			rect1.x = 100 + 100 * x; // coordinate y

			rect1.h = 100; // height
			rect1.w = 100; // width

			draw_rect(rect1, color);
		}
	}
}
