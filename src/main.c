#include "mandelbrot.h"

int main(int argc, char **argv)
{
    /* SDL Setup */
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
    atexit(SDL_Quit);

    SDL_Window *window;

    window = SDL_CreateWindow("SDL Mandelbrot",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WIDTH,
                              HEIGHT,
                              SDL_WINDOW_OPENGL);

    SDL_Surface *surface = SDL_GetWindowSurface(window);

    /* Initialize variables */
    double complex center = START_POS;
    double zoom = START_ZOOM;

    sdl_draw_mandelbrot(window, surface, center, zoom);

    SDL_Event event;
    int quit = 0;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = 1;
                break;
            case SDL_KEYDOWN:
                handle_keydown(event.key.keysym.sym, &center, &zoom, window, surface);
                break;
            case SDL_MOUSEBUTTONDOWN:
                handle_mousebutton(event.button, &center, &zoom, window, surface);
                break;
            }
        }

        // Continuous mouse wheel zooming
        int x, y;
        Uint32 mouse_state = SDL_GetMouseState(&x, &y);
        if (mouse_state & SDL_BUTTON(SDL_BUTTON_MIDDLE))
        {
            handle_mousebutton((SDL_MouseButtonEvent){.button = SDL_BUTTON_LEFT, .x = x, .y = y}, &center, &zoom, window, surface);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
