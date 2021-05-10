#include <stdint.h>

/******************************************************************************/
/* DATA TYPES :                                                               */
/******************************************************************************/

/* ---=== FOR THE PIXEL ARRAY : ===--- */
typedef struct PixelArray PixelArray;





/******************************************************************************/
/* FUNCTION PROTOTYPES :                                                      */
/******************************************************************************/

// --- Creator and Destructor :
void bridge_init_pixel_array(int width,int height);
void bridge_free_pixel_array(void);


// --- Geometry Management :
int bridge_get_pixel_array_width(void);
int bridge_get_pixel_array_height(void);


// --- Update :
void bridge_update_pixel_array(void);


// --- Drawing :
// --- Clearing the console :
void bridge_clear_pixel_array(void);

// --- Single Pixels :
uint32_t  bridge_get_pixel_at(int x,int y);
void      bridge_set_pixel_at(int x,int y,int color);
