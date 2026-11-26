#ifndef PSO_UI_LOADINGINFOICON_H
#define PSO_UI_LOADINGINFOICON_H

#include "types.h"

void draw_loading_compass(void);
void render_info_icon_overlay(void);
void draw_loading_overlay(void);
void free_info_icon_texture(void);
void load_info_icon(void);
void handle_flag2_request();
void load_now_loading_texture();
void update_pulse_colors(s32 request);

#endif
