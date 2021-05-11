#include <stddef.h>
#include <stdint.h>

/******************************************************************************/
/* CONSTANTS :                                                                */
/******************************************************************************/
#define RED 0xFFFF0000
#define GREEN 0xFF00FF00
#define BLUE 0xFF0000FF
#define BLACK 0xFF000000
#define WHITE 0xFFFFFFFF

/******************************************************************************/
/* DATA TYPES :                                                               */
/******************************************************************************/
extern void *(*drb_symbol_lookup)(const char *sym);
typedef void (*drb_upload_pixel_array_fn)(const char *name, const int w,
                                          const int h, const uint32_t *pixels);

/* ---=== FOR THE PIXEL ARRAY : ===--- */
typedef struct PixelArray {
  size_t width;
  size_t height;
  uint32_t *pixels;
  char *name;

  drb_upload_pixel_array_fn drb_upload_pixel_array;
} PixelArray;

/******************************************************************************/
/* FUNCTION PROTOTYPES :                                                      */
/******************************************************************************/

// --- Creator and Destructor :
PixelArray *new_pixel_array(size_t width, size_t height, char *name);
void free_pixel_array(PixelArray *pixel_array);

// --- Geometry Management :
size_t get_pixel_array_width(PixelArray *pixel_array);
size_t get_pixel_array_height(PixelArray *pixel_array);

// --- Update :
void update_pixel_array(PixelArray *pixel_array);

// --- Drawing :
// --- Clearing the console :
void clear_pixel_array(PixelArray *pixel_array);

// --- Single Pixels :
uint32_t get_pixel_at(PixelArray *pixel_array, size_t x, size_t y);
void set_pixel_at(PixelArray *pixel_array, size_t x, size_t y, uint32_t color);

// --- Copy :
void copy_area(PixelArray *src, PixelArray *dest, size_t sx, size_t sy,
               size_t sw, size_t sh, size_t dx, size_t dy);
