#ifndef MANDELBROT_H
#define MANDELBROT_H

#include<SDL.h>

#include <math.h>
#include <complex.h>

#define WIDTH 800
#define HEIGHT 600

#define START_POS -0.5
#define START_ZOOM (WIDTH * 0.25296875f)

#define BAIL_OUT 2.0
#define FLIPS 24

#define ZOOM_FACTOR 4

void sdl_draw_mandelbrot(SDL_Window *window, SDL_Surface *surface, complex double center, double zoom);
void handle_keydown(SDL_Keycode key, complex double *center, double *zoom, SDL_Window *window, SDL_Surface *surface);
void handle_mousebutton(SDL_MouseButtonEvent button, complex double *center, double *zoom, SDL_Window *window, SDL_Surface *surface);

#endif /* MANDELBROT_H */
