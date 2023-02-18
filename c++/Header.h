#pragma once
// Text starting with // are a comment, you can read them to understand a bit about it.
// You can skip the next few lines
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>

// this is a datatype representing the RGB color scheme that is widely used in graphics
// a color is defined by the three values for Red, Green and Blue
typedef struct {
	// the value of each component ranges from 0-255
	int red; // 0 means no red, 255 means completely red
	int green;
	int blue;
} rgb_t;

// we will call this function to draw a rectangle using a given color
void draw_rect(SDL_Rect rectangle, rgb_t color);

#define SIZE 800 // window size
