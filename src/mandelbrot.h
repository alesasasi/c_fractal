#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <SDL.h>

#include <math.h>
#include <complex.h>

/*
#define WIDTH 800
#define HEIGHT 600
#define BAIL_OUT 2.0
#define FLIPS 24
*/

#define WIDTH 800
#define HEIGHT 600
#define BAIL_OUT 4.0
#define FLIPS 1

#define ZOOM_FACTOR 4
#define START_POS -0.5
#define START_ZOOM (WIDTH * 0.25296875f)

void draw_mandelbrot(SDL_Window *window, SDL_Surface *surface, complex double center, double zoom);
void draw_julia(SDL_Window *window, SDL_Surface *surface, complex double c, double zoom);
void handle_keydown(SDL_Keycode key, complex double *center, double *zoom, SDL_Window *window, SDL_Surface *surface);
void handle_mousebutton(SDL_MouseButtonEvent button, complex double *center, double *zoom, SDL_Window *window, SDL_Surface *surface);

#endif /* MANDELBROT_H */
