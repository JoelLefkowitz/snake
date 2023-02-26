#ifndef COLOURS_H
#define COLOURS_H

struct RGB {
  int r;
  int g;
  int b;
};

void init_greyscale(struct RGB *rgb, int grey);
void init_colour(struct RGB *rgb, int r, int g, int b);

#endif
