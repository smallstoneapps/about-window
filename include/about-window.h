#pragma once

void about_window_init(void);
void about_window_deinit(void);
void about_window_show(bool animated);
void about_window_set_text(char* text);
void about_window_set_title(char* title);
void about_window_set_text_from_resources(uint32_t resource_id);
