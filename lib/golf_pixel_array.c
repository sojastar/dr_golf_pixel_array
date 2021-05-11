#include "golf_pixel_array.h"
#include <stdlib.h>
#include <string.h>

/******************************************************************************/
/* FUNCTIONS :                                                                */
/******************************************************************************/

/* ---=== CREATOR AND DESTRUCTOR : ===--- */

PixelArray *new_pixel_array(size_t width, size_t height, char *name) {

  // --- Creating the pixel array :
  PixelArray *pixel_array = (PixelArray *)malloc(sizeof(PixelArray));

  // --- Setting the console's dimensions :
  pixel_array->width = width;
  pixel_array->height = height;
  pixel_array->name = name;

  // --- Setting the console's pixel array :
  pixel_array->pixels = (uint32_t *)calloc(
      pixel_array->width * pixel_array->height, sizeof(uint32_t));
  clear_pixel_array(pixel_array);

  // --- Miscellaneous :
  pixel_array->drb_upload_pixel_array =
      drb_symbol_lookup("drb_upload_pixel_array");

  return pixel_array;
}

void free_pixel_array(PixelArray *pixel_array) {
  free(pixel_array->pixels);
  free(pixel_array);
}

/* ---=== UPDATE : ===--- */

void update_pixel_array(PixelArray *pixel_array) {
  pixel_array->drb_upload_pixel_array(pixel_array->name, pixel_array->width,
                                      pixel_array->height, pixel_array->pixels);
}

/* ---=== GEOMETRY MANAGEMENT : ===--- */

size_t get_pixel_array_width(PixelArray *pixel_array) {
  return pixel_array->width;
}

size_t get_pixel_array_height(PixelArray *pixel_array) {
  return pixel_array->height;
}

/* ---=== DRAWING : ===--- */

// --- Clearing the pixel array :

void clear_pixel_array(PixelArray *pixel_array) {
  for (size_t y = 0; y < pixel_array->height; y += 1)
    for (size_t x = 0; x < pixel_array->width; x += 1)
      pixel_array->pixels[x + pixel_array->width * y] = BLACK;
}

// --- Single piwels :

uint32_t get_pixel_at(PixelArray *pixel_array, size_t x, size_t y) {
  return pixel_array->pixels[x + pixel_array->width * y];
}

void set_pixel_at(PixelArray *pixel_array, size_t x, size_t y, uint32_t color) {
  pixel_array->pixels[x + pixel_array->width * y] = color;
}

// --- Copy :

void copy_area(PixelArray *src, PixelArray *dest, size_t sx, size_t sy,
               size_t sw, size_t sh, size_t dx, size_t dy) {
  for (size_t i = 0; i < sh; ++i)
    memcpy(dest->pixels + (sx + sw * (i + sy)),
           src->pixels + (dx + sw * (i + dy)), sw * sizeof(uint32_t));
}
