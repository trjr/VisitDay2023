#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>

#define SIZE 800 // window size
#define FPS 30

int move_x = 2;
int move_y = 0;

/*
 30 minute lecture, extend mini lecture with C stuff...
 60 minute lab.

 sheet maybe 2 pages, instructions for lecturer

 if
 looping for the events

 color, change of box.
 flashing light box.
*/

int animate(SDL_Rect * logo){
  // do something fun and animate the screen

  // move down by 1 pixel, every frame
  // move right by 1 pixel, every frame
  logo->x += move_x;
  logo->y += move_y;

  return 0;
}

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
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);

    // creates a surface to load an image into the main memory
    SDL_Surface* surface;

    // please provide a path for your image
    surface = IMG_Load("logo.png");

    // loads image to our graphics hardware memory.
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);

    // clears main-memory
    SDL_FreeSurface(surface);

    // our image
    SDL_Rect rect;

    // connects our texture with rect to control position
    SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);

    // adjust height and width of our image box.
    // rect.w /= 6;
    // rect.h /= 6;

    // sets initial x-position of object
    rect.x = (SIZE - rect.w) / 2;

    // sets initial y-position of object
    rect.y = (SIZE - rect.h) / 2;

    // annimation loop
    while (1) {
        animate(& rect);

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

        // clears the screen
        SDL_RenderClear(rend);
        // copy the image onto the screen
        SDL_RenderCopy(rend, tex, NULL, & rect);
        // triggers the double buffers
        // for multiple rendering
        SDL_RenderPresent(rend);

        // calculates to FPS
        SDL_Delay(1000 / FPS);
    }

    // destroy texture
    SDL_DestroyTexture(tex);

    // destroy renderer
    SDL_DestroyRenderer(rend);

    // destroy window
    SDL_DestroyWindow(win);
    return 0;
}
