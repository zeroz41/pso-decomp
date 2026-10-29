#include "types.h"
#include "pso/misc/TWindowKeyBoardSoft_8024E68C.h"
#include "pso/misc/TWindowSubStatusDisp_8025B050.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/memory.h"
#include "pso/misc/TUnk_804CF930.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"

struct Win_8025B0D0 {
    u16 flags; u8 pad2[6];
    f32 f8; f32 fC; f32 f10; f32 f14; f32 f18;
    f32 f1C; f32 f20; f32 f24; f32 f28;
    s32 i2C; s32 *p30; s32 i34;
};

struct Ref_8025B0D0 { u8 pad0[0x10]; f32 f10; f32 f14; f32 f18; u8 pad1c[0x30 - 0x1C]; s32 i30; u8 pad34[4]; f32 f38; };

struct Quad_8025B0D0 { f32 v[8]; };

extern "C" {
void apply_context_transform_to_rect(void *, void *);
void draw_window_uv_sprite_part(Win_8025B0D0 *arg0, Ref_8025B0D0 *arg1);
s32 sub_80256BDC__13TUnk_804CF930Fs(void *, void *);
}

void *window_uv_sprite_part_vtable[6] = {
    0, 0,
    (void *)TWindowSubStatusDisp__sub_8025B2DC,
    (void *)TWindowSubStatusDisp::update_palette_sprite,
    (void *)draw_window_uv_sprite_part,
    0,
};

void swap_sprite_v_edges(u8 *arg0) {
    f32 temp_f1;
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x20);
    *(f32 *)((s8 *)arg0 + 0x20) = (f32) *(f32 *)((s8 *)arg0 + 0x28);
    *(f32 *)((s8 *)arg0 + 0x28) = temp_f1;
}

void swap_sprite_u_edges(u8 *arg0) {
    f32 temp_f1;
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x1C);
    *(f32 *)((s8 *)arg0 + 0x1C) = (f32) *(f32 *)((s8 *)arg0 + 0x24);
    *(f32 *)((s8 *)arg0 + 0x24) = temp_f1;
}

void set_sprite_uv_bounds(void* p, f32 a, f32 b, f32 c, f32 d) { *(f32*)((char*)p + 0x1c) = a; *(f32*)((char*)p + 0x20) = b; *(f32*)((char*)p + 0x24) = c; *(f32*)((char*)p + 0x28) = d; }

void set_sprite_uv_from_pixels(u8 *arg0, f32 farg0, f32 farg1) {
    f32 x, y;
    *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (farg0 / 256.0f);
    *(f32 *)((s8 *)arg0 + 0x20) = (f32) (farg1 / 256.0f);
    x = farg0 + *(f32 *)((s8 *)arg0 + 0x10);
    *(f32 *)((s8 *)arg0 + 0x24) = (f32) (x / 256.0f);
    y = farg1 + *(f32 *)((s8 *)arg0 + 0x14);
    *(f32 *)((s8 *)arg0 + 0x28) = (f32) (y / 256.0f);
}

void set_sprite_dimensions(void* p, f32 a, f32 b) { *(f32*)((char*)p + 0x10) = a; *(f32*)((char*)p + 0x14) = b; }

#pragma push
#pragma fp_contract on

void draw_window_uv_sprite_part(Win_8025B0D0 *arg0, Ref_8025B0D0 *arg1) {
    Quad_8025B0D0 q;
    f32 x;
    f32 y;
    f32 scale;
    f32 len;
    f32 a;
    f32 t;
    f32 lo;
    f32 hi;
    f32 w;
    x = arg1->f10 + arg0->f8;
    y = arg1->f14 + arg0->fC;
    scale = (-1.0f) / ((0.299f) * arg0->f18 + arg1->f38);
    a = arg0->fC / (21.0f);
    t = a + arg0->f8 / arg1->f18;
    t *= (7.5f);
    len = (17.0f) * ((f32)arg1->i30 - t);
    len /= (3.5f) * arg0->f10;
    if (len <= (0.0f)) {
        return;
    }
    if (len > (0.5f)) {
        len = (0.5f);
    }
    if (arg0->flags & 8) {
        set_additive_blend();
    }
    if (arg0->flags & 0xC) {
        begin_screen_draw(1);
    } else {
        begin_screen_draw(0);
    }
    TObjFish::set_global_param(*arg0->p30);
    set_draw_texture_and_color(arg0->i34, arg0->i2C);
    w = arg0->f10;
    lo = (0.5f) - len;
    hi = (0.5f) + len;
    q.v[0] = w * lo + x;
    q.v[1] = arg0->f14 * lo + y;
    q.v[2] = w * hi + x;
    q.v[3] = arg0->f14 * hi + y;
    q.v[4] = arg0->f1C;
    q.v[5] = arg0->f20;
    q.v[6] = arg0->f24;
    q.v[7] = arg0->f28;
    if (arg0->flags & 0x10) {
        apply_context_transform_to_rect(arg1, &q);
        draw_textured_quad_at_depth((f32 *)&q, scale);
    } else if (try_open__19TWindowKeyBoardSoftFii((s32)arg1, (s32)&q) != 0) {
        draw_textured_quad_at_depth((f32 *)&q, scale);
    }
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
}
#pragma pop

void TWindowSubStatusDisp::update_palette_sprite() {  }

void *TWindowSubStatusDisp__sub_8025B2DC(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void ***)((s8 *)arg0 + 4) = window_uv_sprite_part_vtable;
        ((TUnk_804CF930 *)arg0)->destroy(0);
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

u8 *TWindowSubStatusDisp::init_part_direct(u8 *arg1, s32 arg2) {
    sub_80256BDC__13TUnk_804CF930Fs(this, (void *)arg2);
    *(void ***)((s8 *)((u8 *)this) + 4) = window_uv_sprite_part_vtable;
    ((TWindowSubSymbolChatPartsSet *)(((u8 *)this) + 8))->copy_vec2(arg1 + 4);
    ((TWindowSubSymbolChatPartsSet *)(((u8 *)this) + 0x10))->copy_vec2(arg1 + 0xC);
    *(f32 *)((s8 *)((u8 *)this) + 0x1C) = (f32) *(f32 *)((s8 *)arg1 + 0x14);
    *(f32 *)((s8 *)((u8 *)this) + 0x20) = (f32) *(f32 *)((s8 *)arg1 + 0x18);
    *(f32 *)((s8 *)((u8 *)this) + 0x24) = (f32) *(f32 *)((s8 *)arg1 + 0x1C);
    *(f32 *)((s8 *)((u8 *)this) + 0x28) = (f32) *(f32 *)((s8 *)arg1 + 0x20);
    *(f32 *)((s8 *)((u8 *)this) + 0x18) = (f32) *(f32 *)((s8 *)arg1 + 0x24);
    this->m_2c = (s32) *(s32 *)((s8 *)arg1 + 0x28);
    *(s32 *)((s8 *)((u8 *)this) + 0x30) = (s32) *(s32 *)((s8 *)arg1 + 0x2C);
    this->m_34 = (s32) *(s32 *)((s8 *)arg1 + 0x30);
    *(s16 *)((s8 *)((u8 *)this) + 0) = (s16) *(s32 *)((s8 *)arg1 + 0x34);
    return ((u8 *)this);
}

u8 *init_part_scaled__20TWindowSubStatusDispFPvPvi(u8 *arg0, u8 *arg1, s32 arg2) {
    sub_80256BDC__13TUnk_804CF930Fs(arg0, (void *)arg2);
    *(void ***)((s8 *)arg0 + 4) = window_uv_sprite_part_vtable;
    ((TWindowSubSymbolChatPartsSet *)(arg0 + 8))->copy_vec2(arg1 + 4);
    ((TWindowSubSymbolChatPartsSet *)(arg0 + 0x10))->copy_vec2(arg1 + 0xC);
    *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (*(f32 *)((s8 *)arg1 + 0x14) / 256.0f);
    *(f32 *)((s8 *)arg0 + 0x20) = (f32) (*(f32 *)((s8 *)arg1 + 0x18) / 256.0f);
    {
        f32 t0 = *(f32 *)((s8 *)arg1 + 0x14) + *(f32 *)((s8 *)arg0 + 0x10);
        *(f32 *)((s8 *)arg0 + 0x24) = (f32) (t0 / 256.0f);
    }
    {
        f32 t1 = *(f32 *)((s8 *)arg1 + 0x18) + *(f32 *)((s8 *)arg0 + 0x14);
        *(f32 *)((s8 *)arg0 + 0x28) = (f32) (t1 / 256.0f);
    }
    *(f32 *)((s8 *)arg0 + 0x18) = (f32) *(f32 *)((s8 *)arg1 + 0x1C);
    *(s32 *)((s8 *)arg0 + 0x2C) = (s32) *(s32 *)((s8 *)arg1 + 0x20);
    *(s32 *)((s8 *)arg0 + 0x30) = (s32) *(s32 *)((s8 *)arg1 + 0x24);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)arg1 + 0x28);
    *(s16 *)((s8 *)arg0 + 0) = (s16) *(s32 *)((s8 *)arg1 + 0x2C);
    return arg0;
}
