#include <stddef.h>
#include <stdint.h>
#include "golf_pixel_array-bridge.h"
#include "golf_pixel_array.h"

// --- Creator and Destructor :
void bridge_init_pixel_array(int width,int height) {
  init_pixel_array((size_t)width, (size_t)height);
}

void bridge_free_pixel_array(void) {
  free_pixel_array();
}


// --- Geometry Management :
int bridge_get_pixel_array_width(void) {
  return (int)get_pixel_array_width();
}

int bridge_get_pixel_array_height(void) {
  return (int)get_pixel_array_height();
}


// --- Update :
void bridge_update_pixel_array(void) {
  update_pixel_array();
}


// --- Drawing :
// --- Clearing the console :
void bridge_clear_pixel_array(void) {
  clear_pixel_array();
}

// --- Single Pixels :
int bridge_get_pixel_at(int x,int y) {
  return (int)get_pixel_at((size_t)x, (size_t)y);
}

void bridge_set_pixel_at(int x,int y,int color) {
  set_pixel_at((size_t)x, (size_t)y, (uint32_t)color);
}
