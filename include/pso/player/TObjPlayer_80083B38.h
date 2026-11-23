#ifndef PSO_PLAYER_TOBJPLAYER_80083B38_H
#define PSO_PLAYER_TOBJPLAYER_80083B38_H

#include "types.h"

extern "C" {
void * *TObjPlayer__sub_80083F04(void);
void TObjPlayer__sub_80083F38(void);
saddr get_capture_texture_pixels(void);
void reset_and_release_capture_texture(void);
void reset_and_init_capture_texture(void);
void * *release_shared_capture_texture(void);
void clear_camera_capture_flags_bit2(void);
void set_camera_capture_flags_bit2(void);
void clear_camera_flag(void);
void set_camera_capture_flags_bit0(void);
}
void capture_viewport_texture(void);
void disable_camera_capture_overlay(void);
extern "C" {
}
void init_capture_texture(s32 wide);
extern "C" {
s32 is_in_shadow_range(u8 *radius, f32 farg0);
}

void begin_shadow_map_pass();
void end_shadow_map_pass();

#endif
