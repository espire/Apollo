#include "pebble.h"

static Window *window;
static Layer *sun_layer;

static void sun_layer_update_callback(Layer *me, GContext* ctx) {
  graphics_draw_circle(ctx, GPoint(50, 50), 50);
}

int main(void) {
  window = window_create();
  window_stack_push(window, true /* Animated */);

  // Init the layer for display the image
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);
  sun_layer = layer_create(bounds);
  layer_set_update_proc(sun_layer, sun_layer_update_callback);
  layer_add_child(window_layer, sun_layer);


  app_event_loop();


  window_destroy(window);
  layer_destroy(sun_layer);
}
