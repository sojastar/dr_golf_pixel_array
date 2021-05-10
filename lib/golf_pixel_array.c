#include <dragonruby.h>
#include "golf_pixel_array.h"





/******************************************************************************/
/* GLOBAL VARIABLES :                                                         */
/******************************************************************************/
PixelArray*  pixel_array;





/******************************************************************************/
/* FUNCTIONS :                                                                */
/******************************************************************************/

/* ---=== CREATOR AND DESTRUCTOR : ===--- */
DRB_FFI
void init_pixel_array(size_t width,size_t height) {
  // --- Creating the pixel array :
  pixel_array         = (PixelArray *)malloc(sizeof(PixelArray));

  // --- Setting the console's dimensions :
  pixel_array->width  = width;
  pixel_array->height = height;

  // --- Setting the console's pixel array :
  pixel_array->pixels = (uint32_t*)calloc(pixel_array->width * pixel_array->height, sizeof(uint32_t));
  clear_pixel_array();

  // --- Miscellaneous :
  pixel_array->drb_upload_pixel_array = drb_symbol_lookup("drb_upload_pixel_array");
}

DRB_FFI
void free_pixel_array(void) {
  free(pixel_array->pixels);
}


/* ---=== UPDATE : ===--- */
DRB_FFI
void update_pixel_array(void) {
  pixel_array->drb_upload_pixel_array(  "pixel_array",
                                        pixel_array->width,
                                        pixel_array->height,
                                        pixel_array->pixels );
}


/* ---=== GEOMETRY MANAGEMENT : ===--- */
DRB_FFI
size_t get_pixel_array_width(void) {
  return pixel_array->width;
}

DRB_FFI
size_t get_pixel_array_height(void) {
  return pixel_array->height;
}

/* ---=== DRAWING : ===--- */

// --- Clearing the console :
DRB_FFI
void clear_pixel_array(void) {
  for(size_t y = 0; y < pixel_array->height; y+=1)
    for(size_t x = 0; x < pixel_array->width; x+=1)
      pixel_array->pixels[x + pixel_array->width * y] = BLACK;
}


// --- Single Glyphs :
DRB_FFI
uint32_t get_pixel_at(size_t x,size_t y) {
  return pixel_array->pixels[x + pixel_array->width * y];
}

DRB_FFI
void set_pixel_at(size_t x,size_t y,uint32_t color) {
  pixel_array->pixels[x + pixel_array->width * y] = color;
}
