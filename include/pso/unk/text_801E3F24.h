#ifndef PSO_UNK_TEXT_801E3F24_H
#define PSO_UNK_TEXT_801E3F24_H

#include "types.h"

u32 *copy_u32(u32 *p, const u32 *q);
extern "C" {
void gx_write_u32(s32 value);
void gx_write_f32x3(f32 x, f32 y, f32 z);
void gx_write_f32x2(f32 x, f32 y);
}
void handle_6x02(void);
void handle_6x03(void);
struct G_LegacyActivateSwitchByToken_6x04;
void handle_6x04_legacy_activate_switch_by_token(G_LegacyActivateSwitchByToken_6x04 *packet);
void handle_6x9E_player_camera_shutter_sound(void);

#endif
