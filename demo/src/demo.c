#include <pebble.h>
#include <@smallstoneapps/about-window/about-window.h>

static void prv_init(void) {
  about_window_init();
  about_window_set_title("About Window Demo");
  about_window_set_text("Lorem ipsum dolor sit amet, an aliquid convenire honestatis eos. Eos ad tale homero reprimique. Te option mediocrem mel, ius no quodsi tincidunt. Ad sea aliquid ullamcorper.\n\nPertinax similique philosophia no has, ad tempor fastidii pri. Ex sit postea expetendis. Phaedrum consulatu quaerendum te his, pro an doctus delenit. Nec feugiat prodesset ea, ei his tollit discere facilisis.");
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
