#ifndef PSO_UNK_TEXT_803369C8_H
#define PSO_UNK_TEXT_803369C8_H

#include "types.h"

void rotate_title_background_quad(s32 owner, u8 *quad, u8 *center, s32 angle, f32 radius);
extern "C" {
void draw_title_background_pulse(s32 owner, f32 depth, s32 frame);
void draw_title_rings(s32 owner, f32 depth, s32 frame);
}

extern "C" {
void TLobby__sub_80336E44(void);
void TLobby__sub_80336E64(void);
void TLobby__sub_80336E68(void);
}
void clear_lobby_global_flags(void);

#endif
