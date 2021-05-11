#include <stdlib.h>
#include "golf_pixel_array.h"





/******************************************************************************/
/* FUNCTIONS :                                                                */
/******************************************************************************/

/* ---=== CREATOR AND DESTRUCTOR : ===--- */
PixelArray* new_pixel_array(size_t width,size_t height) {

  // --- Creating the pixel array :
  PixelArray* pixel_array = (PixelArray *)malloc(sizeof(PixelArray));

  // --- Setting the console's dimensions :
  pixel_array->width      = width;
  pixel_array->height     = height;

  // --- Setting the console's pixel array :
  pixel_array->pixels     = (uint32_t*)calloc(pixel_array->width * pixel_array->height, sizeof(uint32_t));
  clear_pixel_array(pixel_array);

  // --- Miscellaneous :
  pixel_array->drb_upload_pixel_array = drb_symbol_lookup("drb_upload_pixel_array");

  return pixel_array;
}

void free_pixel_array(PixelArray* pixel_array) {
  free(pixel_array->pixels);
  free(pixel_array);
}


/* ---=== UPDATE : ===--- */
void update_pixel_array(PixelArray* pixel_array) {
  pixel_array->drb_upload_pixel_array(  "pixel_array",
                                        pixel_array->width,
                                        pixel_array->height,
                                        pixel_array->pixels );
}


/* ---=== GEOMETRY MANAGEMENT : ===--- */
size_t get_pixel_array_width(PixelArray* pixel_array) {
  return pixel_array->width;
}

size_t get_pixel_array_height(PixelArray* pixel_array) {
  return pixel_array->height;
}

/* ---=== DRAWING : ===--- */

// --- Clearing the console :
void clear_pixel_array(PixelArray* pixel_array) {
  for(size_t y = 0; y < pixel_array->height; y+=1)
    for(size_t x = 0; x < pixel_array->width; x+=1)
      pixel_array->pixels[x + pixel_array->width * y] = BLACK;
}


// --- Single Glyphs :
uint32_t get_pixel_at(PixelArray* pixel_array,size_t x,size_t y) {
  return pixel_array->pixels[x + pixel_array->width * y];
}

void set_pixel_at(PixelArray* pixel_array,size_t x,size_t y,uint32_t color) {
  pixel_array->pixels[x + pixel_array->width * y] = color;
}
