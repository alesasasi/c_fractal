CFLAGS = -lm `sdl2-config --cflags --libs`
SRCDIR = src

main: $(SRCDIR)/main.c $(SRCDIR)/mandelbrot.c
	$(CC) -o fractal $(SRCDIR)/main.c $(SRCDIR)/mandelbrot.c $(CFLAGS)