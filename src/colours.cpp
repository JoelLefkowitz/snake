#include "headers/colours.hpp"


void init_greyscale(struct RGB* rgb, int grey) {
    rgb->r = grey;
    rgb->g = grey;
    rgb->b = grey;
}

void init_colour(struct RGB* rgb, int r, int g,
                 int b) {
    rgb->r = r;
    rgb->g = g;
    rgb->b = b;
}