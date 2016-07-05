# About Window [![npm (scoped)](https://img.shields.io/npm/v/@smallstoneapps/about-window.svg?maxAge=2592000&style=flat-square)](https://www.npmjs.com/package/@smallstoneapps/about-window)&nbsp;[![MIT License](http://img.shields.io/badge/license-MIT-lightgray.svg?style=flat-square)](./LICENSE) [![Build Status](https://www.bitrise.io/app/1bba2f0bbcba4176.svg?token=dqSIrdW70Zl3Eon8aar3bg)](https://www.bitrise.io/app/1bba2f0bbcba4176)

Pebble library for easily adding an About window to your app.

## Installation

*You must be using Pebble SDK 3.12 or newer to use this library.*

To install the package to your app, use the pebble tool:

```
pebble package install @smallstoneapps/about-window
```

## Usage

````c
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
````
