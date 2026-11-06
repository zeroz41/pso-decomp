#include "types.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8036EF0C.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"

extern "C" {
s32 Dolphin_GXSetCopyFilter(int, void *, void *, void *, void *);
}

s32 display_copy_filter_enabled = 1;
extern u8 *active_gx_render_mode;

void set_display_copy_filter(int sample_pattern) {
    display_copy_filter_enabled = (s32) sample_pattern;
    Dolphin_GXSetCopyFilter((int) (*(u8 *)((s8 *)active_gx_render_mode + 0x19)), active_gx_render_mode + 0x1A, (void *) ((u8) sample_pattern), active_gx_render_mode + 0x32, active_gx_render_mode);
}

s32 get_display_copy_filter(void) {  return display_copy_filter_enabled; }

void TObjBoss2Tunnel__sub_8036EF4C(void) { display_copy_filter_enabled = 1; }

void TObjBoss2Tunnel::enable_and_trigger() { display_copy_filter_enabled = 1; ((int (*)(void *))set_display_copy_filter)((void*)1); }
