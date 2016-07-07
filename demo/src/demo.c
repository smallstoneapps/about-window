#include <pebble.h>
#include <@smallstoneapps/about-window/about-window.h>

static void prv_init(void) {
  about_window_init();
  about_window_set_title("About Window Demo");
  about_window_set_text_from_resources(RESOURCE_ID_TEXT_ABOUT);
  about_window_show(true);
}

static void prv_deinit(void) {
  about_window_deinit();
}

int main(void) {
  prv_init();
  app_event_loop();
  prv_deinit();
}
