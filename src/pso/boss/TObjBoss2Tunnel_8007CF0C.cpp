#include "types.h"
#include "pso/boss/TObjBoss2Tunnel_8007CF0C.h"
#include "pso/boss/TObjBoss2Tunnel_803E2BAC.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/player/TObjPlayer_80083B38.h"
#include "pso/ui/TAdPlayerLoadGC_801E0C30.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/misc/TScene.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TObjPlayer_80141D1C.h"

struct Vec2_8007DD28 { f32 x; f32 y; f32 z; };

struct Vtx_8007D828 { f32 x; f32 y; f32 z; u32 color; };

struct Quad_8007D828 { f32 x0; f32 y0; f32 x1; f32 y1; f32 u0; f32 v0; f32 u1; f32 v1; };

extern Vec2_8007DD28 TObjBoss2Tunnel__data_8048DF2C;
extern const f32 lbl_805D9280;
extern const f32 lbl_805D9284;
extern u8 boss2_tunnel_state_flag;
extern s16 TObjBoss2Tunnel__snapshot_state;
extern u32 TObjBoss2Tunnel__snapshot_buffer;
extern s32 TObjBoss2Tunnel__snapshot_saved_flag;
extern "C" {
void set_depth_buffer_settings_1__Fv(void);
void restore_saved_depth_alpha_state(void);
void draw_projected_quads__15TObjBoss2TunnelFPvi(Vtx_8007D828 *, s32);
extern s32 lbl_805D63F0;
s32 TAdPlayerLoadGC__sub_801E0FA4(s32);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
s32 memmove(void *, void *, s32);
s32 memset(void *, s32, s32);
s32 query_memcard_capacity__15TAdPlayerLoadGCFl(s32, s32);
s32 set_stream_and_load_file__6TLobbyFi(s32);
u32 xmalloc__FUl(s32);
}

extern s32 screen_binary_filename;
extern u32 boss2_tunnel_snapshot_buffer;

void load_data_buffers(void) {
    s32 temp_r31;
    s32 temp_r30;
    u32 temp_r3;

    TObjBoss2Tunnel__snapshot_saved_flag = 0;
    TObjBoss2Tunnel__snapshot_buffer = xmalloc__FUl(0x1E000);
    TObjBoss2Tunnel__snapshot_state = 0;
    init_capture_texture(0);
    temp_r3 = xmalloc__FUl(0x1818C);
    boss2_tunnel_snapshot_buffer = temp_r3;
    if (temp_r3 != 0U) {
        memset((void *)temp_r3, 0, 0x1818C);
    }
    temp_r31 = ((TScene *)screen_binary_filename)->update_lobby_scene();
    if (temp_r31 <= 0x1818C) {
        temp_r30 = set_stream_and_load_file__6TLobbyFi(screen_binary_filename);
        if (temp_r30 != 0) {
            if ((u32) boss2_tunnel_snapshot_buffer != 0U) {
                memmove((void *)boss2_tunnel_snapshot_buffer, (void *)temp_r30, temp_r31);
            }
            TAdSinglePlyChrSelectGC::safe_free(temp_r30);
        }
    }
}

extern s32 TObjBoss2Tunnel__data_80438A08[];

s32 memcard_check_snapshot(s32 arg0, s32 *arg1) {
    s32 temp_r3;

    if (TAdPlayerLoadGC::get_instance() != 0) {
        return 0;
    }
    if (((TAdPlayerLoadGC *)1)->probe_card_slot() == 0) {
        if (arg1 != NULL) {
            *arg1 = -4;
        }
        return 0;
    }
    if (((TAdPlayerLoadGC *)1)->probe_and_check_card() == 0) {
        if (arg1 != NULL) {
            if ((u32)(TAdPlayerLoadGC::get_load_result((void *)1) + 0x10000) == 0xff83U) {
                if (arg1 != NULL) {
                    *arg1 = -6;
                }
            } else if ((u32)(TAdPlayerLoadGC::get_load_result((void *)1) + 0x10000) == 0xff21U) {
                if (arg1 != NULL) {
                    *arg1 = -8;
                }
            } else if (arg1 != NULL) {
                *arg1 = -2;
            }
        }
        return 0;
    }
    if (TAdPlayerLoadGC::check_memcard_status(1) != 0) {
        if (arg1 != NULL) {
            *arg1 = -3;
        }
        return 0;
    }
    if (TAdPlayerLoadGC__sub_801E1B50(1) != 0) {
        if (arg1 != NULL) {
            *arg1 = -2;
        }
        return 0;
    }
    temp_r3 = find_card_file__15TAdPlayerLoadGCFiPv(1, (const char *)TObjBoss2Tunnel__data_80438A08);
    if (temp_r3 == 0) {
        if (arg1 != NULL) {
            *arg1 = 1;
        }
        return 1;
    }
    if ((temp_r3 + 0x10000) == 0xff41U) {
        if (arg1 != NULL) {
            *arg1 = -9;
        }
        return 0;
    }
    if (arg0 != 1) {
        return 0;
    }
    if (TAdPlayerLoadGC__sub_801E0FA4(1) < 1) {
        if (arg1 != NULL) {
            *arg1 = -7;
        }
        return 0;
    }
    if (query_memcard_capacity__15TAdPlayerLoadGCFl(1, 0) < 0xF) {
        if (arg1 != NULL) {
            *arg1 = -1;
        }
        return 0;
    }
    if (arg1 != NULL) {
        *arg1 = 0;
    }
    return 1;
}

void draw_snapshot_capture_overlay(void) {
    Quad_8007D828 q;
    Vtx_8007D828 v[4];
    s32 i;
    set_default_alpha_blend();
    for (i = 0; i < 4; i++) {
        v[i].z = 0.25f;
        v[i].color = 0x8F000000;
    }
    set_depth_buffer_settings_1__Fv();
    v[0].x = 0.0f;
    v[0].y = 0.0f;
    v[1].x = 640.0f;
    v[1].y = 0.0f;
    v[2].x = 0.0f;
    v[2].y = TObjBoss2Tunnel__data_8048DF2C.y - 96.0f;
    v[3].x = 640.0f;
    v[3].y = TObjBoss2Tunnel__data_8048DF2C.y - 96.0f;
    TObjBoss2Tunnel__sub_803E2D10(1);
    draw_projected_quads__15TObjBoss2TunnelFPvi(v, 4);
    TObjBoss2Tunnel::reset_player_state();
    v[0].x = 0.0f;
    v[0].y = TObjBoss2Tunnel__data_8048DF2C.y - 96.0f;
    v[1].x = TObjBoss2Tunnel__data_8048DF2C.x - 128.0f;
    v[1].y = TObjBoss2Tunnel__data_8048DF2C.y - 96.0f;
    v[2].x = 0.0f;
    v[2].y = 480.0f;
    v[3].x = TObjBoss2Tunnel__data_8048DF2C.x - 128.0f;
    v[3].y = 480.0f;
    TObjBoss2Tunnel__sub_803E2D10(1);
    draw_projected_quads__15TObjBoss2TunnelFPvi(v, 4);
    TObjBoss2Tunnel::reset_player_state();
    v[0].x = 128.0f + TObjBoss2Tunnel__data_8048DF2C.x;
    v[0].y = TObjBoss2Tunnel__data_8048DF2C.y - 96.0f;
    v[1].x = 640.0f;
    v[1].y = TObjBoss2Tunnel__data_8048DF2C.y - 96.0f;
    v[2].x = 128.0f + TObjBoss2Tunnel__data_8048DF2C.x;
    v[2].y = 96.0f + TObjBoss2Tunnel__data_8048DF2C.y;
    v[3].x = 640.0f;
    v[3].y = 96.0f + TObjBoss2Tunnel__data_8048DF2C.y;
    TObjBoss2Tunnel__sub_803E2D10(1);
    draw_projected_quads__15TObjBoss2TunnelFPvi(v, 4);
    TObjBoss2Tunnel::reset_player_state();
    v[0].x = TObjBoss2Tunnel__data_8048DF2C.x - 128.0f;
    v[0].y = 96.0f + TObjBoss2Tunnel__data_8048DF2C.y;
    v[1].x = 640.0f;
    v[1].y = 96.0f + TObjBoss2Tunnel__data_8048DF2C.y;
    v[2].x = TObjBoss2Tunnel__data_8048DF2C.x - 128.0f;
    v[2].y = 480.0f;
    v[3].x = 640.0f;
    v[3].y = 480.0f;
    TObjBoss2Tunnel__sub_803E2D10(1);
    draw_projected_quads__15TObjBoss2TunnelFPvi(v, 4);
    TObjBoss2Tunnel::reset_player_state();
    TObjFish::set_global_param(lbl_805D63F0);
    set_draw_texture_and_color(1, -1);
    begin_screen_draw(1);
    q.x0 = TObjBoss2Tunnel__data_8048DF2C.x - 27.0f;
    q.y0 = TObjBoss2Tunnel__data_8048DF2C.y - 27.0f;
    q.x1 = TObjBoss2Tunnel__data_8048DF2C.x;
    q.y1 = TObjBoss2Tunnel__data_8048DF2C.y;
    q.u0 = 0.31764707f;
    q.v0 = 0.494117647f;
    q.u1 = 0.423529416f;
    q.v1 = 0.600000024f;
    draw_textured_quad_at_depth((f32 *)&q, 0.5f);
    q.x0 = TObjBoss2Tunnel__data_8048DF2C.x;
    q.y0 = TObjBoss2Tunnel__data_8048DF2C.y - 27.0f;
    q.x1 = 27.0f + TObjBoss2Tunnel__data_8048DF2C.x;
    q.y1 = TObjBoss2Tunnel__data_8048DF2C.y;
    q.u0 = 0.31764707f;
    q.v0 = 0.494117647f;
    q.u1 = 0.423529416f;
    q.v1 = 0.600000024f;
    q.u0 = 0.423529416f;
    q.u1 = 0.31764707f;
    draw_textured_quad_at_depth((f32 *)&q, 0.5f);
    q.x0 = TObjBoss2Tunnel__data_8048DF2C.x - 27.0f;
    q.y0 = TObjBoss2Tunnel__data_8048DF2C.y;
    q.x1 = TObjBoss2Tunnel__data_8048DF2C.x;
    q.y1 = 27.0f + TObjBoss2Tunnel__data_8048DF2C.y;
    q.u0 = 0.31764707f;
    q.v0 = 0.494117647f;
    q.u1 = 0.423529416f;
    q.v1 = 0.600000024f;
    q.v0 = 0.600000024f;
    q.v1 = 0.494117647f;
    draw_textured_quad_at_depth((f32 *)&q, 0.5f);
    q.x0 = TObjBoss2Tunnel__data_8048DF2C.x;
    q.y0 = TObjBoss2Tunnel__data_8048DF2C.y;
    q.x1 = 27.0f + TObjBoss2Tunnel__data_8048DF2C.x;
    q.y1 = 27.0f + TObjBoss2Tunnel__data_8048DF2C.y;
    q.u0 = 0.31764707f;
    q.v0 = 0.494117647f;
    q.u1 = 0.423529416f;
    q.v1 = 0.600000024f;
    q.v0 = 0.600000024f;
    q.v1 = 0.494117647f;
    q.u0 = 0.423529416f;
    q.u1 = 0.31764707f;
    draw_textured_quad_at_depth((f32 *)&q, 0.5f);
    TWindowSubStatusDisp::get_player();
    restore_saved_depth_alpha_state();
}

void TObjBoss2Tunnel__sub_8007DD24(void) {  }
void TObjBoss2Tunnel::reset_state() {
    TObjBoss2Tunnel__data_8048DF2C.x = lbl_805D9280;
    boss2_tunnel_state_flag = 0;
    TObjBoss2Tunnel__data_8048DF2C.y = lbl_805D9284;
    TObjBoss2Tunnel__snapshot_buffer = 0;
    TObjBoss2Tunnel__snapshot_state = 0;
    TObjBoss2Tunnel__snapshot_saved_flag = 0;
    TQuestListVM::reset();
}
