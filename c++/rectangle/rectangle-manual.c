#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>

#define SIZE 800 // window size
#define FPS 60

int animate(SDL_Rect * logo){
  SDL_Event event;
  // movement speed
  int speed = 600;

  // do something fun
  // move down by 1 pixel, every frame
  // logo->y += 1;
  // move right by 1 pixel, every frame
  // logo->x += 1;

  // Events mangement
  // As long as there is an event, do something
  while (SDL_PollEvent(&event)) {
      switch (event.type) {

      case SDL_QUIT:
          // handling of close button
          return 1;
          break;

      case SDL_KEYDOWN:
          // keyboard API for key pressed
          switch (event.key.keysym.scancode) {
          case SDL_SCANCODE_W:
          case SDL_SCANCODE_UP:
              logo->y -= speed / FPS;
              break;
          case SDL_SCANCODE_A:
          case SDL_SCANCODE_LEFT:
              logo->x -= speed / FPS;
              break;
          case SDL_SCANCODE_S:
          case SDL_SCANCODE_DOWN:
              logo->y += speed / FPS;
              break;
          case SDL_SCANCODE_D:
          case SDL_SCANCODE_RIGHT:
              logo->x += speed / FPS;
              break;
          default:
          break;
          }
      }
  }

  // handle out-of-screen situation

  // right boundary
  if (logo->x + logo->w > SIZE){
    logo->x = SIZE - logo->w;
  }

  // left boundary
  if (logo->x < 0){
    logo->x = 0;
  }

  // bottom boundary
  if (logo->y + logo->h > SIZE){
    logo->y = SIZE - logo->h;
  }

  // upper boundary
  if (logo->y < 0){
    logo->y = 0;
  }

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

    // let us control our image position
    // so that we can move it with our keyboard.
    SDL_Rect dest;

    // connects our texture with dest to control position
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);

    // adjust height and width of our image box.
    // dest.w /= 6;
    // dest.h /= 6;

    // sets initial x-position of object
    dest.x = (SIZE - dest.w) / 2;

    // sets initial y-position of object
    dest.y = (SIZE - dest.h) / 2;

    // controls annimation loop
    int close = 0;

    // annimation loop
    while (!close) {
        close = animate(& dest);

        // clears the screen
        SDL_RenderClear(rend);
        // copy the image onto the screen
        SDL_RenderCopy(rend, tex, NULL, & dest);
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
