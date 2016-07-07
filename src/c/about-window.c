#include <pebble.h>
#include "about-window.h"
#include <@smallstoneapps/scroll-text-layer/scroll-text-layer.h>
#include <@smallstoneapps/utils/macros.h>


static void prv_window_load(Window* window);
static void prv_window_unload(Window* window);
static void prv_layer_header_update(Layer* layer, GContext* ctx);


static Window* s_window;
static Layer* s_layer_header;
static ScrollTextLayer* s_layer_scroll;
static char* s_text = NULL;
static char* s_title = NULL;


void about_window_init(void) {
  s_window = window_create();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .load = prv_window_load,
    .unload = prv_window_unload,
  });
}

void about_window_deinit(void) {
  window_destroy(s_window);
}

void about_window_show(bool animated) {
  window_stack_push(s_window, animated);
}

void about_window_set_text(char* text) {
  if (s_text != NULL) {
    free(s_text);
  }
  s_text = malloc(strlen(text) + 1);
  strcpy(s_text, text);
  if (s_layer_scroll != NULL) {
    scroll_text_layer_set_text(s_layer_scroll, s_text);
  }
}

void about_window_set_title(char* title) {
  if (s_title != NULL) {
    free(s_title);
  }
  s_title = malloc(strlen(title) + 1);
  strcpy(s_title, title);
  if (s_layer_header != NULL) {
    layer_mark_dirty(s_layer_header);
  }
}

void about_window_set_text_from_resources(uint32_t resource_id) {
  if (s_text != NULL) {
    free(s_text);
  }
  ResHandle resource = resource_get_handle(resource_id);
  size_t size = resource_size(resource);
  s_text = malloc(size + 1);
  resource_load(resource, (uint8_t*)s_text, size);
  if (s_layer_scroll != NULL) {
    scroll_text_layer_set_text(s_layer_scroll, s_text);
  }
}


static void prv_window_load(Window* window) {
  GRect window_bounds = layer_get_bounds(window_get_root_layer(window));
  GRect header_bounds = GRect(0, 0, window_bounds.size.w, 26);

  s_layer_scroll = scroll_text_layer_create(grect_inset(window_bounds,
    GEdgeInsets(26, 0, 0, 0)));
  scroll_text_layer_set_font(s_layer_scroll,
    fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  scroll_text_layer_add_to_window(s_layer_scroll, window);

  if (s_text != NULL) {
    scroll_text_layer_set_text(s_layer_scroll, s_text);
  }

  s_layer_header = layer_create(header_bounds);
  layer_set_update_proc(s_layer_header, prv_layer_header_update);
  layer_add_to_window(s_layer_header, window);
}

static void prv_window_unload(Window* window) {
  scroll_text_layer_destroy(s_layer_scroll);
  layer_destroy(s_layer_header);
}

static void prv_layer_header_update(Layer* layer, GContext* ctx) {
  graphics_context_set_fill_color(ctx, GColorBlack);
  graphics_context_set_text_color(ctx, GColorWhite);
  graphics_fill_rect(ctx, layer_get_bounds(layer), 0, GCornerNone);
  if (s_title != NULL) {
    graphics_draw_text(ctx, s_title, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD),
      GRect(0, 0, layer_get_bounds(layer).size.w, 22), 0, GTextAlignmentCenter,
      NULL);
  }
}
