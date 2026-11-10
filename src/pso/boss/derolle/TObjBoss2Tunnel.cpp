#include "types.h"
#include "pso/system/MatrixStack.h"
#include <string.h>
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TMainTask.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007C5C0.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007CF0C.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_803E2BAC.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F764.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/player/TObjPlayer_80083B38.h"
#include "pso/unk/text_803DCDFC.h"
#include "pso/system/main_loop.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/render/TDLGraph.h"
#include "pso/unk/TLobby.h"
#include "pso/system/scene/TScene.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/render/render_util.h"
#include "pso/system/ControllerInputState.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007EA74.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8036EF0C.h"
#include "pso/map/FloorArea.h"
#include "pso/map/CsnQuery.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/unk/TLobby_803382E4.h"
#include "pso/network/client_id.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/math/AngleLookup.h"

struct Stack_8007CBC4 {
    s32 sp8;
    u8 pad_C[0x54];
    s32 sp60;
};
struct Stack_8007CAE8 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
};
struct Load_8007CB50 { u8 pad[0x58]; s32 *data; u32 size; };
struct Card_8007CCD0 {
    char file[0x12];
    char title[0x22];
    u8 icon[0x10];
    u8 pad44[8];
    s16 f4c;
    s16 f4e;
    s32 f50;
    s16 flag; /* TAdPlayerLoadGC::build_save_file_image: 0 adds a space after the comment name */
    u8 pad56[2];
    s32 *data;
    s32 size;
};
struct VBase_8007C5C0 { char pad[0x18]; };
struct VObj_8007C5C0 : VBase_8007C5C0 {
    virtual ~VObj_8007C5C0();
    virtual void m1();
    virtual void m2();
};
struct VBase_8007C8AC { char pad[0x18]; };
struct VObj_8007C8AC : VBase_8007C8AC {
    virtual ~VObj_8007C8AC();
    virtual void m1();
    virtual void m2();
};
struct Vec2_8007DD28 { f32 x; f32 y; };
struct Vtx_8007D828 { f32 x; f32 y; f32 z; u32 color; };
struct Quad_8007D828 { f32 x0; f32 y0; f32 x1; f32 y1; f32 u0; f32 v0; f32 u1; f32 v1; };
// screen.bin / the PSO_SCREEN card file: a 256x192 capture and who was in the room.
struct ScreenSnapshot {
    u32 checksum;
    u16 width;
    u16 height;
    u8 pixels[0x18000];
    u8 bits_per_pixel;
    u8 format;
    u16 player_count;
    u32 class_flags[12];
    u32 levels[12];
    char names[12][0x18];
};
typedef char ScreenSnapshot_size[sizeof(ScreenSnapshot) == 0x1818C ? 1 : -1];
// The "GetFrameBuffer" temp buffer: the snapshot, then its card file image at the next 32-byte boundary.
struct SnapshotFrameBuffer {
    ScreenSnapshot snapshot;
    u8 pad_1818C[0x14];
    u8 save_image[0x1E000];
};
// 6xB2: play a sound at a player (bswap_6xB2_play_sound swaps it).
struct G_PlaySound_6xB2 {
    G_ClientIDHeader header;
    u8 floor;
    u8 unused;
    u16 client_id;
    u32 sound_id;
};
extern "C" {
s32 DCFlushRange(int, int);
s32 TAdPlayerLoadGC__sub_801E1538(void *, void *);
s32 TAdPlayerLoadGC__sub_801E1B50(int);
extern s32 lbl_805D49B4;
s32 draw_textured_screen_quad__10TObjPlayerFUlPfPfl(int, void *, void *, int, f32);
void poll_load_status__15TAdPlayerLoadGCFl(s32 a, void *b);
u32 calc_crc32_bitwise(u8 *arg0, u32 arg1);
void TAdPlayerLoadGC__sub_801E14E4(void *);
void TAdPlayerLoadGC__sub_801E14E8(u8 *arg0, s32 arg1);
void build_save_file_image__15TAdPlayerLoadGCFPvPv(void *, void *, void *);
s32 load_player__23TAdSinglePlyChrSelectGCFllll(s32, const char *, void *, s32);
extern char episode_i_and_ii_card_filename[];
VObj_8007C5C0 *create__8TDLGraphFv(void);
s8 func_801A5E54__Fv(void);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
extern u32 camera_ctrl_instance;
s32 verify_snapshot_checksum__15TObjBoss2TunnelFv();
void set_depth_buffer_settings_1__Fv(void);
void draw_projected_quads__15TObjBoss2TunnelFPvi(Vtx_8007D828 *, s32);
extern s32 lbl_805D63F0;
s32 TAdPlayerLoadGC__sub_801E0FA4(s32);
s32 query_memcard_capacity__15TAdPlayerLoadGCFl(s32, s32);
s32 set_stream_and_load_file__6TLobbyFi(s32);
s32 is_on_current_screen__11TCameraCtrlFv(void *, s32);
}
extern s32 screen_binary_filename;
// A velocity/position ramp: accelerate from v0 to peak, cruise, brake to rest over dist.
// init_piecewise_curve fills it, eval_piecewise_curve reads the speed, sample_piecewise_curve the distance.
struct PiecewiseCurve {
    f32 accel;
    f32 decel;
    f32 v0;
    f32 peak;
    f32 accelEnd;
    f32 decelStart;
    f32 end;
    f32 t;
    f32 accelDist;
    f32 decelPos;
    f32 dist;
};
extern "C" {
}
// The same ramp without a start speed or clock (init_acceleration_curve / sample_acceleration_curve).
struct AccelerationCurve {
    f32 accel;
    f32 decel;
    f32 peak;
    f32 accelEnd;
    f32 decelStart;
    f32 end;
    f32 accelDist;
    f32 decelPos;
    f32 dist;
};
extern "C" {
f32 sample_acceleration_curve(AccelerationCurve *c, f32 t);
void init_acceleration_curve(AccelerationCurve *c, f32 a, f32 d, f32 length, f32 speed);
void __dl__FPv(void);
s32 reset_floats__15TObjBoss2TunnelFv();
int reset_coords__15TObjBoss2TunnelFv();
s32 get_view_matrix__11TCameraCtrlFv();
int vec3_add_to(void*, void*);
int TCameraCtrl__sub_8006B370(f32 farg0);
f32 vec_squared_length();
f32 normalize_vector(void *);
}


u8 boss2_tunnel_state_flag;
s16 TObjBoss2Tunnel__snapshot_state;
s32 *boss2_tunnel_snapshot_buffer;
void *TObjBoss2Tunnel__snapshot_buffer;
s32 TObjBoss2Tunnel__snapshot_saved_flag;

// Defined outside this file: no in-file definition would leave them in .rodata unpooled.
// The snapshot's memory card file: name, comment and icon; screen.bin is the same capture on disc.
extern const char TObjBoss2Tunnel__data_80438A08[32];
extern const char lbl_80438A28[36];
extern const u8 lbl_80438A4C[16];
extern const char screen_binary_filename_string[];
// Centre of the capture frame, moved with the C stick; defined with the rest of the .data words.
extern Vec2_8007DD28 TObjBoss2Tunnel__data_8048DF2C;
// Owner name of the lobby temp buffer the snapshot borrows (TLobby::tmp_buf_use_req/tmp_buf_release).
extern char lbl_8048DF34[];
// Window text positions and widths, computed once from the window rectangles (the guards are the
// statics' init flags).
extern f32 lbl_8048DF44[2];
extern s8 lbl_805D4E98;
extern f32 lbl_805D4E9C;
extern s8 boss2_tunnel_message_shown_flag;
extern f32 lbl_8048DF4C[2];
extern s8 boss2_tunnel_confirm_loop_flag;
extern f32 lbl_805D4EA4;
extern s8 lbl_805D4EA8;

void TObjBoss2Tunnel__sub_8007EAE4(u8 *arg0) {
    *(u8 *)((s8 *)arg0 + 0) = 0xB2;
    *(s8 *)((s8 *)arg0 + 1) = 3;
}

void bswap_6xB2_play_sound(TObjPlayer *player) {
    ((G_ClientIDHeader *)player)->bswap();
    bswap_16((u16 *)((char *)player + 6));
    bswap_32((u32 *)((char *)player + 8));
}

void TObjBoss2Tunnel::finalize_and_send_60() {
    bswap_6xB2_play_sound((TObjPlayer *)this);
    send_subcommand((u8 *)this);
}

extern "C" {
f32 TObjBoss2Tunnel::update_scale() {
    f32 var_f31;
    f32 temp_f0;

    var_f31 = 0.0f;
    if (0.0f != vec_squared_length()) {
        var_f31 = normalize_vector(this);
        if (TCameraCtrl__sub_8006B370(var_f31) != 0) {
            *(f32 *)&this->m_name = var_f31 = 0.0f;
            *(f32 *)&this->m_flags = var_f31;
            *(f32 *)&this->m_prev = var_f31;
        }
    } else {
        temp_f0 = 0.0f;
        *(f32 *)&this->m_name = temp_f0;
        *(f32 *)&this->m_flags = temp_f0;
        *(f32 *)&this->m_prev = temp_f0;
    }
    return var_f31;
}

}
#pragma push
#pragma fp_contract on
f32 normalize_vector_xz(Vec *vector) {
    f32 temp_f31;
    f32 temp_f30;
    f32 temp_f29;
    f32 temp_f28;

    temp_f30 = vector->z;
    temp_f31 = vector->x;
    temp_f29 = (temp_f31 * temp_f31) + (temp_f30 * temp_f30);
    if (0.0f != temp_f29) {
        temp_f28 = 1.0f / newton_sqrtf(temp_f29);
        if (TCameraCtrl__sub_8006B370(temp_f28) != 0) {
            vector->x = (f32) 0.0f;
            vector->z = (f32) 0.0f;
            return 0.0f;
        }
        vector->x = (f32) (temp_f31 * temp_f28);
        vector->z = (f32) (temp_f30 * temp_f28);
        return temp_f29 * temp_f28;
    }
    vector->x = (f32) 0.0f;
    vector->z = (f32) 0.0f;
    return 0.0f;
}

#pragma pop
extern "C" {
void TObjBoss2Tunnel::render(void* a1) { push_matrix(); TObjPlayer::invert_matrix_in_place((u32)((void*)0)); get_current_matrix(a1); pop_matrix(); }

}
#pragma push
#pragma fp_contract on
extern "C" {
void TObjBoss2Tunnel::transform_vec_by_camera(s32 arg0, s32 arg1, s32 arg2) {
    push_matrix();
    TCameraCtrl::concat_matrix(0, get_view_matrix__11TCameraCtrlFv());
    matrix_mult_vec(NULL, (const Vec *)arg1, (Vec *)arg2);
    pop_matrix();
}

bool is_vec_xz_cross_negative(u8 *arg0, u8 *arg1) {
    return (((*(f32 *)((s8 *)arg0 + 8) * *(f32 *)((s8 *)arg1 + 0)) - (*(f32 *)((s8 *)arg0 + 0) * *(f32 *)((s8 *)arg1 + 8))) >= 0.0f) == 0;
}

void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 arg2) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f31;
    f32 temp_f3;
    temp_f31 = cos_table_lookup(arg2);
    temp_f1 = sin_table_lookup(arg2);
    temp_f0 = *arg0;
    temp_f3 = *arg1;
    *arg1 = (temp_f31 * temp_f3) - (temp_f1 * temp_f0);
    *arg0 = (temp_f1 * temp_f3) + (temp_f31 * temp_f0);
}

void rotate_vec_xz(void *arg0, void *arg1, s32 arg2) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f31;
    f32 temp_f3;
    temp_f31 = cos_table_lookup(arg2);
    temp_f1 = sin_table_lookup(arg2);
    temp_f0 = *(f32 *)((s8 *)arg0 + 0);
    temp_f3 = *(f32 *)((s8 *)arg0 + 8);
    *(f32 *)((s8 *)arg1 + 8) = (f32) ((temp_f31 * temp_f3) - (temp_f1 * temp_f0));
    *(f32 *)((s8 *)arg1 + 0) = (f32) ((temp_f1 * temp_f3) + (temp_f31 * temp_f0));
}

}
#pragma pop
extern "C" {
f32 TObjBoss2Tunnel::calc_scaled_value(s32 arg0, f32 farg0) {
    return (0.5f * farg0) / sin_table_lookup(arg0 / 2);
}

s32 TObjBoss2Tunnel::count_tree_nodes() {
    s32 var_r31;
    u8 *temp_r3;
    u8 *temp_r3_2;
    var_r31 = 1;
    temp_r3 = (u8 *)this->m_2c;
    if (temp_r3 != NULL) {
        var_r31 = ((TObjBoss2Tunnel *)temp_r3)->count_tree_nodes() + 1;
    }
    temp_r3_2 = (u8 *)this->m_30;
    if (temp_r3_2 != NULL) {
        var_r31 += ((TObjBoss2Tunnel *)temp_r3_2)->count_tree_nodes();
    }
    return var_r31;
}

s32 count_active_segments__15TObjBoss2TunnelFPv(void *arg0) {
    s32 temp_r3;
    s32 var_r31;

    var_r31 = 0;
    do {
        temp_r3 = *(s32 *)((s8 *)arg0 + 0);
        if (!(temp_r3 & 8)) {
            var_r31 += 1;
        }
        if (!(temp_r3 & 0x10)) {
            var_r31 += count_active_segments__15TObjBoss2TunnelFPv((void *)(*(void **)((s8 *)arg0 + 0x2C)));
        }
        arg0 = *(void **)((s8 *)arg0 + 0x30);
    } while (arg0 != NULL);
    return var_r31;
}

s16 TObjBoss2Tunnel::turn_toward_angle_limited(s32 arg0, s32 cur, s32 target, s32 step, s32 limit) {
    target = angle_diff_s16(arg0, target);
    if (target > limit) {
        target = limit;
    } else if (target < -limit) {
        target = -limit;
    }
    if (cur * target >= 0) {
        cur = approach_angle_limited(cur, target, step);
    } else if (cur * angle_diff_s16(cur, target) >= 0) {
        if (cur >= 0) {
            cur = cur - step;
        } else {
            cur = cur + step;
        }
    } else {
        cur = approach_angle_limited(cur, target, step);
    }
    return cur;
}

void TObjBoss2Tunnel::init_zako(void* a1, s32 _w2) { rotate_xz_pair_by_angle((f32 *)this, (f32 *)((char*)this + 0x8), (s32)_w2); vec3_add_to(this, a1); }

s32 TObjBoss2Tunnel::adjust_to_ground(s32 arg0, void *arg1) {
    s32 *temp_r3;

    VecCopy((Vec *)arg1, (const Vec *)arg0);
    ((Vec *)arg1)->y += 20.0f;
    temp_r3 = csnVecterUnder((s32)arg1, 0x16EF);
    if (temp_r3 != NULL) {
        VecCopy((Vec *)arg1, (const Vec *)(*(s32 *)((s8 *)temp_r3 + 4)));
        return 1;
    }
    VecCopy((Vec *)arg1, (const Vec *)arg0);
    return 0;
}

s32 TObjBoss2Tunnel::spawn_effect(s32 arg0, void *arg1, void *arg2) {
    s32 *temp_r3;

    VecCopy((Vec *)arg1, (const Vec *)arg0);
    ((Vec *)arg1)->y += 20.0f;
    temp_r3 = csnVecterUnder((s32)arg1, 0x16EF);
    if (temp_r3 != NULL) {
        VecCopy((Vec *)arg1, (const Vec *)(*(s32 *)((s8 *)temp_r3 + 4)));
        VecCopy((Vec *)arg2, (const Vec *)(*(s32 *)((s8 *)temp_r3 + 4) + 0xC));
        return 1;
    }
    VecCopy((Vec *)arg1, (const Vec *)arg0);
    return 0;
}

s32 TObjBoss2Tunnel::decrement_packed_timer(u32 *arg0, s32 arg1) {
    u32 temp_r5;

    temp_r5 = *arg0;
    if ((s32)((temp_r5 >> 24) - arg1) < 0) {
        *arg0 = temp_r5 & 0xFFFFFF;
        return 1;
    }
    *arg0 = ((((temp_r5 >> 24) - arg1) << 24) & 0xFF000000) | (temp_r5 & 0xFFFFFF);
    return 0;
}

s32 TObjBoss2Tunnel::reset_coords_pass(s32 arg0) {
    reset_coords__15TObjBoss2TunnelFv();
    return arg0;
}

s32 TObjBoss2Tunnel::maybe_delete(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

}
void TObjBoss2Tunnel::reset_coords() { *(float *)&this->m_flags = 0.0f; *(float *)&this->m_name = 0.0f; *(float *)&this->m_prev = 0.0f; *(float *)&this->m_down = 0.0f; *(float *)&this->m_up = 0.0f; *(float *)&this->m_next = 0.0f; *(float *)&this->m_20 = 0.0f; *(float *)&this->_pad1C = 0.0f; *(float*)((char*)this + 0x18) = 0.0f; }

extern "C" {
void init_acceleration_curve(AccelerationCurve *c, f32 a, f32 d, f32 length, f32 speed) {
    f32 sq;
    f32 up;
    f32 down;
    f32 p;
    c->accel = a;
    if (c->accel <= 0.0f) {
        c->accel = 0.1f;
    }
    c->decel = d;
    if (c->decel >= 0.0f) {
        c->decel = (-0.1f);
    }
    sq = speed * speed;
    c->dist = length;
    c->peak = speed;
    up = (0.5f * sq) / c->accel;
    down = (0.5f * -sq) / c->decel;
    if (up + down >= c->dist) {
        f32 k2 = 2.0f * c->accel;
        c->peak = newton_sqrtf((c->dist * (k2 *= c->decel)) / (c->decel - c->accel));
        sq = c->peak * c->peak;
        c->accelEnd = c->decelStart = c->peak / c->accel;
        c->accelDist = c->decelPos = (0.5f * sq) / c->accel;
        c->end = c->decelStart + (-c->peak / c->decel);
        return;
    }
    c->accelDist = up;
    c->accelEnd = c->peak / c->accel;
    c->decelPos = c->dist - down;
    c->decelStart = c->accelEnd + (c->decelPos - up) / c->peak;
    c->end = c->decelStart + (-c->peak / c->decel);
}

int TObjBoss2Tunnel::check_param_threshold(f32 arg1) {
    return arg1 >= *(f32 *)&this->m_down;
}

}
#pragma push
#pragma fp_contract on
extern "C" {
f32 sample_acceleration_curve(AccelerationCurve *c, f32 t) {
    if (t < 0.0f) {
        return 0.0f;
    }
    if (t < c->accelEnd) {
        {
        f32 k = 0.5f * c->accel;
        k *= t;
        return t * k;
        }
    }
    if (t < c->decelStart) {
        t -= c->accelEnd;
        return t * c->peak + c->accelDist;
    }
    if (t < c->end) {
        t = c->end - t;
        {
        f32 k = 0.5f * c->decel;
        k *= t;
        return t * k + c->dist;
        }
    }
    return c->dist;
}

}
#pragma pop
extern "C" {
s32 TObjBoss2Tunnel::reset_floats(s32 arg0) {
    reset_floats__15TObjBoss2TunnelFv();
    return arg0;
}

s32 TObjBoss2Tunnel::dt(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

}
void TObjBoss2Tunnel::reset_floats() { *(float *)&this->m_flags = 0.0f; *(float *)&this->m_name = 0.0f; *(float *)&this->m_next = 0.0f; *(float *)&this->m_prev = 0.0f; *(float*)((char*)this + 0x18) = 0.0f; *(float *)&this->m_down = 0.0f; *(float *)&this->m_up = 0.0f; *(float *)&this->_pad1C = 0.0f; *(float *)&this->m_28 = 0.0f; *(float *)&this->m_24 = 0.0f; *(float *)&this->m_20 = 0.0f; }

extern "C" {
void init_piecewise_curve(PiecewiseCurve *c, f32 accel, f32 decel, f32 dist, f32 v0, f32 peak) {
    f32 sq;
    f32 up;
    f32 down;
    c->t = 0.0f;
    c->accel = accel;
    if (c->accel <= 0.0f) {
        c->accel = 0.1f;
    }
    c->decel = decel;
    if (c->decel >= 0.0f) {
        c->decel = -0.1f;
    }
    c->dist = dist;
    sq = peak * peak;
    c->peak = peak;
    c->v0 = v0;
    if (c->v0 > c->peak) {
        c->accel = c->decel;
    }
    up = (0.5f * (sq - c->v0 * c->v0)) / c->accel;
    down = (-0.5f * sq) / c->decel;
    if (up + down >= c->dist) {
        if (c->v0 > c->peak) {
            c->decel = (-0.5f * (c->v0 * c->v0)) / c->dist;
            c->accelEnd = c->decelStart = c->accelDist = c->decelPos = 0.0f;
            c->end = -c->v0 / c->decel;
        } else {
            c->peak = newton_sqrtf((c->dist * (2.0f * c->accel * c->decel)) / (c->decel - c->accel));
            sq = c->peak * c->peak;
            c->accelEnd = c->decelStart = c->peak / c->accel;
            c->accelDist = c->decelPos = (0.5f * sq) / c->accel;
            c->end = c->decelStart + (-c->peak / c->decel);
        }
    } else {
        c->accelDist = up;
        c->accelEnd = (c->peak - c->v0) / c->accel;
        c->decelPos = c->dist - down;
        c->decelStart = c->accelEnd + (c->decelPos - up) / c->peak;
        c->end = c->decelStart + (-c->peak / c->decel);
    }
}

}
#pragma push
#pragma fp_contract on
extern "C" {
f32 TObjBoss2Tunnel::eval_piecewise_curve(f32 farg0) {
    PiecewiseCurve *c = (PiecewiseCurve *)this;
    f32 t;
    f32 r = 0.0f;
    if (farg0 < r) {
        r = r;
    } else {
        if (farg0 < c->accelEnd) {
            r = c->accel * farg0 + c->v0;
        } else {
            t = c->decelStart;
            if (farg0 < t) {
                r = c->peak;
            } else if (farg0 < c->end) {
                t = farg0 - t;
                r = c->decel * t + c->peak;
            }
        }
    }
    return r;
}

}
#pragma pop
extern "C" {
void TObjBoss2Tunnel::update_position() {
    eval_piecewise_curve(*(f32 *)&this->_pad1C);
}

}
#pragma push
#pragma fp_contract on
extern "C" {
s32 sample_piecewise_curve(PiecewiseCurve *c, f32 *out, f32 t) {
    s32 done = 0;
    if (t < 0.0f) {
        *out = 0.0f;
    } else if (t < c->accelEnd) {
        *out = t * (0.5f * c->accel * t + c->v0);
    } else if (t < c->decelStart) {
        t -= c->accelEnd;
        *out = t * c->peak + c->accelDist;
    } else if (t < c->end) {
        t = c->end - t;
        *out = t * (0.5f * c->decel * t) + c->dist;
    } else {
        done = 1;
        *out = c->dist;
    }
    return done;
}

}
#pragma pop
s32 TObjBoss2Tunnel::advance_phase(f32 *out) {
    PiecewiseCurve *c = (PiecewiseCurve *)this;
    s32 done = sample_piecewise_curve(c, out, c->t);
    c->t += 1.0f;
    return done;
}

void TObjBoss2Tunnel::reset_state() {
    TObjBoss2Tunnel__data_8048DF2C.x = 320.0f;
    boss2_tunnel_state_flag = 0;
    TObjBoss2Tunnel__data_8048DF2C.y = 240.0f;
    TObjBoss2Tunnel__snapshot_buffer = 0;
    TObjBoss2Tunnel__snapshot_state = 0;
    TObjBoss2Tunnel__snapshot_saved_flag = 0;
    TQuestListVM::reset();
}

void TObjBoss2Tunnel__sub_8007DD24(void) {  }

/* Moves the capture frame with the C stick and keeps it on screen. */
void TObjBoss2Tunnel__sub_8007DB80(void) {
    s16 stick_x = controller_physical_port_bank.controllers[3].cstick_x;
    s16 stick_y = controller_physical_port_bank.controllers[3].cstick_y;
    f32 magnitude = controller_physical_port_bank.controllers[3].cstick_magnitude;
    if (magnitude > 0.2f) {
        f32 speed = 0.3f * magnitude;
        s16 dx = stick_x * speed;
        s16 dy = stick_y * speed;
        dx = dx + dx % 4;
        dy = dy + dy % 4;
        TObjBoss2Tunnel__data_8048DF2C.x += dx;
        TObjBoss2Tunnel__data_8048DF2C.y += dy;
    }
    if (TObjBoss2Tunnel__data_8048DF2C.x - 128.0f <= 0.0f) {
        TObjBoss2Tunnel__data_8048DF2C.x = 128.0f;
    }
    if (128.0f + TObjBoss2Tunnel__data_8048DF2C.x >= 640.0f) {
        TObjBoss2Tunnel__data_8048DF2C.x = 512.0f;
    }
    if (TObjBoss2Tunnel__data_8048DF2C.y - 96.0f <= 0.0f) {
        TObjBoss2Tunnel__data_8048DF2C.y = 96.0f;
    }
    if (96.0f + TObjBoss2Tunnel__data_8048DF2C.y >= 480.0f) {
        TObjBoss2Tunnel__data_8048DF2C.y = 384.0f;
    }
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

/* Takes a snapshot of the screen with the C stick frame and saves it to the memory card. */
s32 TObjBoss2Tunnel__sub_8007D1D0(void) {
    SnapshotFrameBuffer *frame;
    ScreenSnapshot *snap;
    u32 *sum;
    PadSlot *pad;
    s32 filter;
    u8 *p;
    s32 mode;
    u16 *countp;
    u32 *flags;
    u32 *levels;
    char *name;
    u16 count;
    TObjPlayer *me;
    s32 i;
    TObjPlayer *player;
    TDLGraph *graph;
    s32 err;
    s32 err2;
    Card_8007CCD0 card;
    G_PlaySound_6xB2 cmd;
    f32 pos[2];
    f32 size[2];
    f32 limit;
    f32 t;

    if (get_main_phase() == 0xF &&
        (is_boss_area() != 0 || is_quest_active() != 0 || TQuestVmDownLoadServer__sub_8007EB14() != 0)) {
        return 0;
    }
    if (TQuestListVM::get_quest_bin() != NULL) {
        return 0;
    }
    if (TCameraCtrl__sub_80069304() != 0) {
        return 0;
    }
    if (is_split_screen() != 0) {
        return 0;
    }
    if (TAdPlayerLoadGC::get_instance() != 0) {
        return 0;
    }
    pad = (PadSlot *)TKeyBoardControl__sub_803DEB74(0x12);
    if (is_on_current_screen__11TCameraCtrlFv(&controller_physical_port_bank.controllers[3], 0x20000) != 0) {
        if (boss2_tunnel_state_flag == 0) {
            TObjBoss2Tunnel__sub_8007DB80();
            draw_snapshot_capture_overlay();
        }
    } else if (boss2_tunnel_state_flag == 0) {
        return 0;
    }
    if (boss2_tunnel_state_flag == 0) {
        if (pad->held & 4) {
            if (memcard_check_snapshot(0, &err) == 0) {
                TObjBoss2Tunnel::show_message_and_wait(err);
                return 0;
            }
            if (TObjBoss2Tunnel::run_confirm_message_loop() != 0) {
                boss2_tunnel_state_flag |= 1;
            } else {
                boss2_tunnel_state_flag = 0;
            }
        } else if (pad->held & 0x400) {
            if (memcard_check_snapshot(0, &err2) == 0) {
                TObjBoss2Tunnel::show_message_and_wait(err2);
                return 0;
            }
            if (TObjBoss2Tunnel::run_confirm_message_loop() != 0) {
                boss2_tunnel_state_flag |= 2;
            } else {
                boss2_tunnel_state_flag = 0;
            }
        } else {
            boss2_tunnel_state_flag = 0;
        }
        return 0;
    }
    mode = (boss2_tunnel_state_flag & 1) ^ 1;
    boss2_tunnel_state_flag = 0;
    filter = get_display_copy_filter();
    set_display_copy_filter(0);
    TObjPlayer::copy_screen_to_texture(mode, &TObjBoss2Tunnel__data_8048DF2C);
    set_display_copy_filter(filter);
    render_tick();
    if (TLobby::tmp_buf_is_free() != 0) {
        frame = (SnapshotFrameBuffer *)TLobby::tmp_buf_use_req(lbl_8048DF34);
        p = (u8 *)frame;
        sum = (u32 *)p;
        snap = (ScreenSnapshot *)p;
        *sum = 0;
        frame->snapshot.width = 0x100;
        frame->snapshot.height = 0xC0;
        p += 8;
        ((TLobby *)p)->move_data((void *)TObjPlayer__sub_800845F8(), 0x18000);
        p += 0x18000;
        *p++ = 0x18;
        *p++ = 2;
        countp = (u16 *)p;
        p += 2;
        flags = (u32 *)p;
        levels = (u32 *)(p + 0x30);
        name = (char *)(p + 0x60);
        memset(name, 0, 0x120);
        count = TLobby::get_game_mode();
        me = (TObjPlayer *)find_entity_by_id(local_client_id);
        if (me != NULL) {
            *flags++ = me->class_flags;
            if (me->get_stats() != NULL) {
                *levels++ = me->get_actor_level_index();
            }
            strncpy(name, me->name, 0x18);
            name += 0x18;
        }
        for (i = 0; i < count; i++) {
            if (i != local_client_id) {
                player = (TObjPlayer *)find_entity_by_id(i);
                if (player != NULL) {
                    *flags++ = player->class_flags;
                    if (player->get_stats() != NULL) {
                        *levels++ = player->get_actor_level_index();
                    }
                    strncpy(name, player->name, 0x18);
                    name += 0x18;
                }
            }
        }
        *countp = count;
        memset(&card, 0, sizeof(card));
        strcpy(card.file, episode_i_and_ii_card_filename);
        strcpy(card.title, lbl_80438A28);
        memcpy(card.icon, lbl_80438A4C, 0x10);
        TAdPlayerLoadGC__sub_801E14E8((u8 *)&card, 4);
        card.f4c = 1;
        card.f4e = 1;
        card.f50 = 0;
        card.flag = 0;
        card.data = (s32 *)snap;
        card.size = sizeof(ScreenSnapshot);
        *sum = calc_crc32_bitwise((u8 *)snap, sizeof(ScreenSnapshot));
        TAdPlayerLoadGC::build_save_file_image(frame->save_image, &card);
        TAdPlayerLoadGC__sub_801E14E4(&card);
        TObjBoss2Tunnel__sub_8007EAE4((u8 *)&cmd);
        cmd.floor = get_current_floor_area();
        cmd.unused = 0;
        cmd.client_id = local_client_id;
        cmd.sound_id = 0x52B20;
        ((TObjBoss2Tunnel *)&cmd)->finalize_and_send_60();
        if (memcard_check_snapshot(0, NULL) != 0) {
            if (load_player__23TAdSinglePlyChrSelectGCFllll(1, TObjBoss2Tunnel__data_80438A08, frame->save_image, 0xF) == 0) {
                t = 0.0f;
                graph = (TDLGraph *)TDLGraph::create();
                if (get_main_phase() == 0xF) {
                    reset_state_flags__6TLobbyFv();
                }
                limit = 60.0f;
                do {
                    t += 1.0f;
                    if (t > limit) {
                        t = limit;
                    }
                    func_803DCDFC__Fv();
                    controller_stuff();
                    main_task.run_tl_camera_tasks();
                    pos[0] = 192.0f;
                    pos[1] = 144.0f;
                    size[0] = 256.0f;
                    size[1] = 192.0f;
                    TParticleCtrl::begin_effect_render();
                    TObjPlayer::draw_textured_screen_quad(-1, pos, size, 1);
                    if (graph != NULL) {
                        TDLGraph::update_graph((s32)t, (s32)limit);
                        graph->run_task();
                        graph->render();
                    }
                    TLobby::update_pulse_colors(1);
                    TLobby__sub_80338534();
                    TParticleCtrl::end_effect_render();
                    render_tick();
                } while (TAdPlayerLoadGC__sub_801E1B50(1) == 0xFFFFFFFF);
                if (TAdPlayerLoadGC::get_load_result((void *)1) == 0xFFFFFF81) {
                    TObjBoss2Tunnel::show_message_and_wait(-2);
                }
                if (graph != NULL) {
                    delete graph;
                }
                if (get_main_phase() == 0xF) {
                    process_deferred_player_setup__6TLobbyFv();
                }
                TParticleCtrl::end_effect_render();
            } else {
                TObjBoss2Tunnel::show_message_and_wait(-2);
            }
        }
        TLobby::tmp_buf_release(lbl_8048DF34);
        return 1;
    }
    return 0;
}

s32 memcard_check_snapshot(s32 arg0, s32 *arg1) {
    s32 temp_r3;

    if (TAdPlayerLoadGC::get_instance() != 0) {
        return 0;
    }
    if (TAdPlayerLoadGC::probe_card_slot(1) == 0) {
        if (arg1 != NULL) {
            *arg1 = -4;
        }
        return 0;
    }
    if (TAdPlayerLoadGC::probe_and_check_card(1) == 0) {
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
    temp_r3 = TAdPlayerLoadGC::find_card_file(1, TObjBoss2Tunnel__data_80438A08);
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

void load_data_buffers(void) {
    s32 temp_r31;
    s32 temp_r30;
    s32 *buf;

    TObjBoss2Tunnel__snapshot_saved_flag = 0;
    TObjBoss2Tunnel__snapshot_buffer = xmalloc(0x1E000);
    TObjBoss2Tunnel__snapshot_state = 0;
    init_capture_texture(0);
    buf = (s32 *)xmalloc(0x1818C);
    boss2_tunnel_snapshot_buffer = buf;
    if (buf != NULL) {
        memset(buf, 0, 0x1818C);
    }
    temp_r31 = ((TScene *)screen_binary_filename)->update_lobby_scene();
    if (temp_r31 <= 0x1818C) {
        temp_r30 = set_stream_and_load_file__6TLobbyFi(screen_binary_filename);
        if (temp_r30 != 0) {
            if (boss2_tunnel_snapshot_buffer != NULL) {
                memmove(boss2_tunnel_snapshot_buffer, (void *)temp_r30, temp_r31);
            }
            TAdSinglePlyChrSelectGC::safe_free(temp_r30);
        }
    }
}

void TObjBoss2Tunnel::free_buffers() {
    TObjBoss2Tunnel__snapshot_saved_flag = 0;
    if (boss2_tunnel_snapshot_buffer != NULL) {
        xfree(boss2_tunnel_snapshot_buffer);
        boss2_tunnel_snapshot_buffer = NULL;
    }
    TObjPlayer__sub_80084694();
    if (TObjBoss2Tunnel__snapshot_buffer != NULL) {
        xfree(TObjBoss2Tunnel__snapshot_buffer);
        TObjBoss2Tunnel__snapshot_buffer = NULL;
    }
}

s32 TObjBoss2Tunnel::save_snapshot() {
    s32 sp8;

    memcard_check_snapshot(1, &sp8);
    if (sp8 == 1) {
        if ((s32) TObjBoss2Tunnel__snapshot_saved_flag != 0) {
            return -9;
        }
        save_screen_snapshot();
loop_4:
        if (TAdPlayerLoadGC::probe_card_slot(1) == 0) {
            TObjBoss2Tunnel__snapshot_saved_flag = 0;
            return -5;
        }
        if (TObjBoss2Tunnel::load_snapshot() != 0) {
            if (verify_snapshot_checksum__15TObjBoss2TunnelFv() == 0) {
                TObjBoss2Tunnel__snapshot_saved_flag = 1;
                return -9;
            }
            goto block_9;
        }
        goto loop_4;
    }
block_9:
    TObjBoss2Tunnel__snapshot_saved_flag = 0;
    return sp8;
}

s32 TObjBoss2Tunnel::save_snapshot_to_card() {
    Card_8007CCD0 c;
    s32 *p;
    if (memcard_check_snapshot(1, 0) == 0) {
        return 0;
    }
    if (TObjBoss2Tunnel__snapshot_buffer == NULL) {
        return 0;
    }
    memset(TObjBoss2Tunnel__snapshot_buffer, 0, 4);
    memset(&c, 0, 0x60);
    strcpy(c.file, episode_i_and_ii_card_filename);
    strcpy(c.title, lbl_80438A28);
    memcpy(c.icon, lbl_80438A4C, 0x10);
    TAdPlayerLoadGC__sub_801E14E8((u8 *)&c, 4);
    c.f4c = 1;
    p = boss2_tunnel_snapshot_buffer;
    c.f4e = 1;
    c.f50 = 0;
    c.flag = 0;
    *p = 0;
    *p = calc_crc32_bitwise((u8 *)boss2_tunnel_snapshot_buffer, 0x1818C);
    c.size = 0x1818C;
    c.data = boss2_tunnel_snapshot_buffer;
    build_save_file_image__15TAdPlayerLoadGCFPvPv(TObjBoss2Tunnel__snapshot_buffer, &c, boss2_tunnel_snapshot_buffer);
    TAdPlayerLoadGC__sub_801E14E4(&c);
    if (load_player__23TAdSinglePlyChrSelectGCFllll(1, TObjBoss2Tunnel__data_80438A08, TObjBoss2Tunnel__snapshot_buffer, 0xF) != 0) {
        return 0;
    }
    lbl_805D49B4 = 1;
    TObjBoss2Tunnel__snapshot_state = 1;
    return 1;
}

s32 save_screen_snapshot(void) {
    if (memcard_check_snapshot(1, 0) == 0) {
        return 0;
    }
    if (TAdSinglePlyChrSelectGC::load_player_slot(1, TObjBoss2Tunnel__data_80438A08, TObjBoss2Tunnel__snapshot_buffer) != 0) {
        return 0;
    }
    TObjBoss2Tunnel__snapshot_state = 2;
    return 1;
}

s32 TObjBoss2Tunnel::load_snapshot() {
    Stack_8007CBC4 stack;
    s32 buf;
    if (TAdPlayerLoadGC__sub_801E1B50(1) == 0) {
        if (((s32) (*(u16 *)&TObjBoss2Tunnel__snapshot_state) != 0) && ((s32) (*(u16 *)&TObjBoss2Tunnel__snapshot_state) >= 0) && ((s32) (*(u16 *)&TObjBoss2Tunnel__snapshot_state) < 3)) {
            buf = TObjPlayer__sub_800845F8();
            if (TAdPlayerLoadGC__sub_801E1538(&stack.sp8, TObjBoss2Tunnel__snapshot_buffer) == 0) {
                memcpy((void *)buf, (void *)(stack.sp60 + 8), 0x1818C);
                DCFlushRange(buf, 0x1818C);
            }
            lbl_805D49B4 = 0;
        }
        return 1;
    }
    return 0;
}

bool TObjBoss2Tunnel::verify_snapshot_checksum() {
    Load_8007CB50 ld;
    s32 *p;
    s32 saved;
    s32 sum;
    if ((u32)TAdPlayerLoadGC__sub_801E1538(&ld, TObjBoss2Tunnel__snapshot_buffer) == 0xFFFFFF20) {
        return false;
    }
    p = ld.data;
    saved = *p;
    *p = 0;
    sum = calc_crc32_bitwise((u8 *)ld.data, 0x1818C);
    *p = saved;
    return sum == saved;
}

void TObjBoss2Tunnel__sub_8007CAE8(u32 arg0) {
    Stack_8007CAE8 stack;
    if (arg0 == 0U) {
        stack.sp10 = 192.0f;
        stack.sp14 = 144.0f;
    } else {
        ((TWindowSubSymbolChatPartsSet *)(&stack.sp10))->copy_vec2((void *)arg0);
    }
    stack.sp8 = 345.6f;
    stack.spC = 259.2f;
    draw_textured_screen_quad__10TObjPlayerFUlPfPfl(-1, &stack.sp10, &stack.sp8, 1, 345.6f);
}

void TObjBoss2Tunnel::show_message_and_wait(s32 arg0) {
    static const f32 window_pos[2] = {46.0f, 131.0f};
    static const f32 window_size[2] = {548.0f, 220.0f};
    VObj_8007C8AC *win;
    s32 frames;
    if (lbl_805D4E98 == 0) {
        lbl_8048DF44[0] = 20.0f + window_pos[0];
        lbl_8048DF44[1] = 10.0f + (window_pos[1] + window_size[1]);
        lbl_805D4E98 = 1;
    }
    if (boss2_tunnel_message_shown_flag == 0) {
        lbl_805D4E9C = window_size[0] - 40.0f;
        boss2_tunnel_message_shown_flag = 1;
    }
    win = (VObj_8007C8AC *)TWindowMessage::create((s32)window_pos, window_size, (u32)1, 4);
    if (win != NULL) {
        switch (arg0) {
        case -2:
        case -9:
            ((TWindowMessage *)win)->append_line(get_localized_text_entry(0x24, 3), 3);
            break;
        case -4:
            ((TWindowMessage *)win)->append_line(get_localized_text_entry(0x24, 0xD), 3);
            break;
        default:
            ((TWindowMessage *)win)->append_line(get_localized_text_entry(0x24, 0xC), 3);
            break;
        }
        ((TWindowBase *)win)->set_depth(36900.0f);
        ((TWindowMessage *)win)->complete_reveal();
    }
    if (get_main_phase() == 0xF) {
        reset_state_flags__6TLobbyFv();
    }
    frames = 0;
    for (;;) {
        frames++;
        func_803DCDFC__Fv();
        controller_stuff();
        if (camera_ctrl_instance != 0U) {
            ((TCameraCtrl *)camera_ctrl_instance)->setup_default_view(0);
        }
        main_task.render();
        if ((f32)frames >= 30.0f) {
            break;
        }
        TLobby::wait_ready_loop();
        if (func_801A5E54__Fv() != 0) {
            break;
        }
        render_tick();
    }
    if (get_main_phase() == 0xF) {
        process_deferred_player_setup__6TLobbyFv();
    }
    if (win != NULL) {
        delete win;
    }
}

void TObjBoss2Tunnel::poll_pso_screen_load() {
    poll_load_status__15TAdPlayerLoadGCFl(1, ((u8 *)&TObjBoss2Tunnel__data_80438A08));
}

s32 TObjBoss2Tunnel::run_confirm_message_loop() {
    s32 result = 0;
    static const f32 window_pos[2] = {46.0f, 131.0f};
    static const f32 window_size[2] = {548.0f, 220.0f};
    ControllerInputContext *pad;
    VObj_8007C5C0 *win;
    VObj_8007C5C0 *graph;
    s32 frames;
    if (boss2_tunnel_confirm_loop_flag == 0) {
        lbl_8048DF4C[0] = 20.0f + window_pos[0];
        lbl_8048DF4C[1] = 10.0f + (window_pos[1] + window_size[1]);
        boss2_tunnel_confirm_loop_flag = 1;
    }
    if (lbl_805D4EA8 == 0) {
        lbl_805D4EA4 = window_size[0] - 40.0f;
        lbl_805D4EA8 = 1;
    }
    win = (VObj_8007C5C0 *)TWindowMessage::create((s32)window_pos, window_size, (u32)1, 4);
    if (win != NULL) {
        ((TWindowMessage *)win)->append_line(get_localized_text_entry(0x24, 0xB), 3);
        ((TWindowBase *)win)->set_depth(36900.0f);
    }
    ((TWindowMessage *)win)->complete_reveal();
    graph = create__8TDLGraphFv();
    if (graph != NULL) {
        ((TDLGraph *)graph)->set_graph_param(2);
    }
    frames = 0;
    if (get_main_phase() == 0xF) {
        reset_state_flags__6TLobbyFv();
    }
    pad = &controller_physical_port_bank.controllers[3];
    for (;;) {
        frames++;
        func_803DCDFC__Fv();
        controller_stuff();
        if (camera_ctrl_instance != 0U) {
            ((TCameraCtrl *)camera_ctrl_instance)->setup_default_view(0);
        }
        main_task.render();
        draw_snapshot_capture_overlay();
        TLobby::wait_ready_loop();
        if (func_801A5E54__Fv() != 0) {
            break;
        }
        TParticleCtrl::begin_effect_render();
        if (graph != NULL) {
            TDLGraph::update_graph(frames, 0x78);
            graph->m1();
            graph->m2();
        }
        win->m2();
        TParticleCtrl::end_effect_render();
        if (frames >= 6.0) {
            if (TWindowShortListCtrl__check_controller_button(pad, 2) != 0 || frames >= 0x78) {
                result = 0;
                break;
            }
            if (TWindowShortListCtrl__check_controller_button(pad, 4) != 0) {
                result = 1;
                break;
            }
        }
        render_tick();
    }
    if (graph != NULL) {
        delete graph;
    }
    if (get_main_phase() == 0xF) {
        process_deferred_player_setup__6TLobbyFv();
    }
    if (win != NULL) {
        delete win;
    }
    return result;
}

