#include "types.h"
#include "pso/effect/TEffIndirectCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjFish.h"

struct Ctrl_802A8728 {
    u8 pad0[0x1C];
    s32 buf;
    u8 *recipe;
    u8 index;
    u8 pad25[0x3C - 0x25];
    s32 amp;
    s32 period;
    u16 phase;
    u8 pad46[2];
    f32 rate;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Tbl5_802A85F0 { s32 v[5]; };

struct Owner_802A85F0 {
    u8 pad[0x2C];
    s32 list;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Tbl5_802A8448 { s32 v[5]; };

struct Owner_802A8448 {
    u8 pad[0x2C];
    s32 list;
};

extern s32 indirect_effect_ctrl_table[];
extern u8 indirect_effect_ctrl_count;
extern "C" {
void TObjPlayer__sub_802A841C(void);
void TObjPlayer__sub_802A83F4(void);
s32 DCFlushRange(s32, s32);
void deform_indirect_texture_scroll(s32, s32, s32, s32, s32);
s32 get_indirect_source_pixels(u8);
void GXSetIndTexMtx(s32, f32 (*)[3], s32);
void Dolphin_GXSetIndTexCoordScale(s32, s32, s32);
void Dolphin_GXSetIndTexOrder(s32, s32, s32);
void GXSetNumIndStages(s32);
void GXSetTevIndWarp(s32, s32, s32, s32, s32);
}
void load_list_texture(s32, s32, s32, s32);
extern Tbl5_802A85F0 indirect_tev_alternate_coord_table;
extern Tbl5_802A85F0 indirect_tev_scale_table;
extern const f32 lbl_805DE020;
extern const f32 lbl_805DE024;
s32 setup_indirect_tev_alternate(s32 arg0, s32 unused, s32 sampler, s32 arg3);
extern Tbl5_802A8448 indirect_tev_ordinary_scale_table;
s32 setup_indirect_tev_ordinary(s32 arg0, s32 sampler, s32 scale, s32 second);
void deform_indirect_texture_wave(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5);
s32 update_indirect_texture_wave(s32, s32, s32, s32, s32, u8);
extern "C" {
s8 find_indirect_effect_ctrl();

void TObjPlayer::play_particle_at_active_slot(s32 arg0, s32 sampler, s32 arg2, s32 arg3, s32 unused, s32 second) {
    s32 indirect_effect_ctrl;

    indirect_effect_ctrl = (s32)(s8) find_indirect_effect_ctrl();
    if ((indirect_effect_ctrl != -1) && ((u32) indirect_effect_ctrl_table[indirect_effect_ctrl] != 0U)) {
        if (arg3 != 0) {
            setup_indirect_tev_alternate(indirect_effect_ctrl_table[indirect_effect_ctrl], unused, sampler, arg2);
            return;
        }
        setup_indirect_tev_ordinary(indirect_effect_ctrl_table[indirect_effect_ctrl], sampler, arg2, second);
    }
}

void TObjPlayer__sub_802A83F4(void) {
    s32 i;
    for (i = 0; i < 6; i++) ((s32 *)&indirect_effect_ctrl_table)[i] = 0;
}

void TObjPlayer__sub_802A841C(void) {
    s32 i;
    indirect_effect_ctrl_count = 0;
    for (i = 0; i < 6; i++) ((s32 *)&indirect_effect_ctrl_table)[i] = 0;
}
}

void *indirect_effect_tile_buffer;

s32 setup_indirect_tev_ordinary(s32 arg0, s32 sampler, s32 scale, s32 second) {
    Tbl5_802A8448 scales = indirect_tev_ordinary_scale_table;
    f32 m0[2][3];
    f32 m1[2][3];
    GXSetNumIndStages(1);
    Dolphin_GXSetIndTexOrder(0, 0, 5);
    Dolphin_GXSetIndTexCoordScale(0, scales.v[(u8)scale], scales.v[(u8)scale]);
    if (second != 0) {
        static s32 shift = -2;
        static s32 unused = 0;
        static f32 k = lbl_805DE020;
        GXSetTevIndWarp(1, 0, 0, 0, 1);
        m0[0][0] = k;
        m0[0][1] = lbl_805DE024;
        m0[0][2] = lbl_805DE024;
        m0[1][0] = lbl_805DE024;
        m0[1][1] = k;
        m0[1][2] = lbl_805DE024;
        GXSetIndTexMtx(1, m0, (s8)shift);
    } else {
        GXSetTevIndWarp(0, 0, 0, 0, 1);
        m1[0][0] = lbl_805DE020;
        m1[0][1] = lbl_805DE024;
        m1[0][2] = lbl_805DE024;
        m1[1][0] = lbl_805DE024;
        m1[1][1] = lbl_805DE020;
        m1[1][2] = lbl_805DE024;
        GXSetIndTexMtx(1, m1, 1);
    }
    TObjFish::set_global_param(((Owner_802A8448 *)arg0)->list);
    load_list_texture(0, sampler, sampler, 5);
}

s32 setup_indirect_tev_alternate(s32 arg0, s32 unused, s32 sampler, s32 arg3) {
    if ((u8)arg3 < 5) {
        u8 scale = arg3;
        Tbl5_802A85F0 coords = indirect_tev_alternate_coord_table;
        Tbl5_802A85F0 scales = indirect_tev_scale_table;
        f32 mtx[2][3];
        GXSetNumIndStages(1);
        Dolphin_GXSetIndTexOrder(0, coords.v[2], 5);
        Dolphin_GXSetIndTexCoordScale(0, scales.v[scale], scales.v[scale]);
        GXSetTevIndWarp(1, 0, 0, 0, 1);
        mtx[0][0] = lbl_805DE020;
        mtx[0][1] = lbl_805DE024;
        mtx[0][2] = lbl_805DE024;
        mtx[1][0] = lbl_805DE024;
        mtx[1][1] = lbl_805DE020;
        mtx[1][2] = lbl_805DE024;
        GXSetIndTexMtx(1, mtx, 1);
        TObjFish::set_global_param(((Owner_802A85F0 *)arg0)->list);
        load_list_texture(0, sampler, sampler, 5);
    }
}

void TEffIndirectCtrl::update_scroll_mode() {
    Ctrl_802A8728 *self = (Ctrl_802A8728 *)this;
    s32 rate;
    ((TEffIndirectCtrl *)self)->copy_and_flush_texture(get_indirect_source_pixels(self->index));
    rate = (s32) self->rate;
    self->phase = self->phase + (s8) self->recipe[3];
    deform_indirect_texture_scroll(self->buf, self->amp, self->period, rate, self->phase);
    DCFlushRange(self->buf, 0x1000);
}

void TEffIndirectCtrl::update_eff_indirect() {
    copy_and_flush_texture(get_indirect_source_pixels(m_24));
    deform_indirect_texture_wave(m_1c, (s32) *(f32 *)unk_48, m_4c, m_3c, m_40, ((u8 *)m_20)[6]);
    DCFlushRange(m_1c, 0x1000);
}
void TEffIndirectCtrl::eff_indirect_update_and_flush() {
    copy_and_flush_texture(get_indirect_source_pixels(m_24));
    update_indirect_texture_wave(m_1c, (s32) *(f32 *)unk_48, m_4c, m_3c, m_40, ((u8 *)m_20)[6]);
    DCFlushRange(m_1c, 0x1000);
}
