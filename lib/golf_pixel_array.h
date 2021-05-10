#include <stddef.h>
#include <stdint.h>





/******************************************************************************/
/* CONSTANTS :                                                                */
/******************************************************************************/
#define RED   0xFFFF0000
#define GREEN 0xFF00FF00
#define BLUE  0xFF0000FF
#define BLACK 0xFF000000
#define WHITE 0xFFFFFFFF





/******************************************************************************/
/* DATA TYPES :                                                               */
/******************************************************************************/
extern  void *(*drb_symbol_lookup)(const char *sym);
typedef void (*drb_upload_pixel_array_fn)(const char *name,const int w,const int h,const uint32_t *pixels);

/* ---=== FOR THE PIXEL ARRAY : ===--- */
typedef struct PixelArray {
  size_t    width;
  size_t    height;
  uint32_t* pixels;

  drb_upload_pixel_array_fn drb_upload_pixel_array;
} PixelArray;





/******************************************************************************/
/* FUNCTION PROTOTYPES :                                                      */
/******************************************************************************/

// --- Creator and Destructor :
void init_pixel_array(size_t width,size_t height);
void free_pixel_array(void);


// --- Geometry Management :
size_t get_pixel_array_width(void);
size_t get_pixel_array_height(void);


// --- Update :
void update_pixel_array(void);


// --- Drawing :
// --- Clearing the console :
void clear_pixel_array(void);

// --- Single Pixels :
uint32_t  get_pixel_at(size_t x,size_t y);
void      set_pixel_at(size_t x,size_t y,uint32_t color);





/******************************************************************************/
/* GLOBAL VARIABLES :                                                         */
/******************************************************************************/
PixelArray*  pixel_array;
