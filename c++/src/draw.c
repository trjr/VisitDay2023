#include <Header.h>

// we will modify this "function" to draw a rectangle
void draw(int frame){
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




// You do not need to understand any code behind here
SDL_Renderer* rend;

void draw_rect(SDL_Rect r, rgb_t c){
  // Set render color
  SDL_SetRenderDrawColor( rend, c.red, c.green, c.blue, 255 );

  // draw rectangle
  SDL_RenderFillRect( rend, &r );
}

#define FPS 30

int main(){

    // returns zero on success else non-zero
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        exit(1);
    }
    SDL_Window* win = SDL_CreateWindow("UoR Visit Day", // creates a window
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       SIZE, SIZE, 0);

    // triggers the program that controls
    // your graphics hardware and sets flags
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images
    rend = SDL_CreateRenderer(win, -1, render_flags);


    // annimation loop
    int frame = 0;
    while (1) {
        frame++;
        // clears the screen
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);

        // draw something
        draw(frame);

        SDL_Event event;
        // Events mangement
        // As long as there is an event, do something
        while (SDL_PollEvent(&event)) {
          switch (event.type) {

            case SDL_QUIT:
            // handling of close button
            return 1;
          default:
              break;
          }
        }
        // triggers the double buffers
        // for multiple rendering
        SDL_RenderPresent(rend);

        // calculates to FPS
        SDL_Delay(1000 / FPS);
    }

    // destroy renderer
    SDL_DestroyRenderer(rend);

    // destroy window
    SDL_DestroyWindow(win);
    return 0;
}
