#include "types.h"
#include "pso/TObject.h"
#include "pso/TWindowSetLevelUp.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct Scroll_8026D790 { u8 pad0[4]; f32 height; s32 frame; };

struct Ctx_8026D790 {
    f32 x, y, width, height;
    u8 pad10[0x1C - 0x10];
    f32 clip_height;
    u8 pad20[0x30 - 0x20];
    s32 x30;
    u8 pad34[4];
    f32 x38;
};

struct Quad_8026D790 { f32 x, y, r, b, u, v, ur, vb; };

struct ByteBlock_16 { u8 bytes[0x16]; };

struct VOff_8026DD70_arg0_8026DCE0 { char pad_0[0x24]; char f_24[1]; };

struct VObj_8026DA44 {
    char pad[0x18];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual s32 get_level();
};

typedef struct LvUp_8026DA44 {
    u8 pad0[0x1C];
    s8 state;
    u8 pad1d;
    s16 timer;
    s32 client;
    s16 d24;
    s16 d26;
    s16 d28;
    s16 d2a;
    s16 d2c;
    u8 pad2e[0xC];
    s16 d3a;
    s16 d3c;
} LvUp_8026DA44;
extern "C" {

void queue_destruction__7TObjectFv(void *);
s32 *get_shared_text_buffer(void);
void __dl__FPv(void);
void *get_player_by_client_id(s32 i);
void TWindowSubStatusDisp__sub_80228F5C(s32);
void text_builder_append(u8 *str);
void __ct__7TObjectFP7TObject(void *);
void apply_context_transform_to_rect(void *, Quad_8026D790 *);
s32 copy_position__11TWindowMenuFPv();
void draw_window_scrollbar(Scroll_8026D790 *scroll, Ctx_8026D790 *c, f32 *offset);
void update_stat_messages__17TWindowSetLevelUpFv(LvUp_8026DA44 *self);
void render__17TWindowSetLevelUpFv(void);
void * __ct__17TWindowSetLevelUpFv(void *arg0, void *arg1, void *arg2, void *arg3);
void TWindowSetLevelUp__sub_8026DE28(void* p, s32 v);
void begin_screen_draw(s32 arg0);
void draw_textured_quad_at_depth(f32 *q, f32 depth);
void set_draw_texture_and_color(s32 idx, s32 arg1);
}
u32 calc_pulse_flash_color(u8 r, u8 g, u8 b, s32 frame, s32 period, s32 start, s32 peak, s32 end);
void text_builder_reset(void);
void set_constant_material_color(u32 x);
extern "C" {

void *__dt__17TWindowSetLevelUpFv(void *arg0, s16 arg1);
void run_task__17TWindowSetLevelUpFv(u8 *arg0);
void render_shadows__7TObjectFv(void);
void __dt__7TObjectFv(void *, int);
void __dl__7TObjectFPv(void *);
void *__vt__17TWindowSetLevelUp[6] = {
    0, 0,
    (void *)__dt__17TWindowSetLevelUpFv,
    (void *)run_task__17TWindowSetLevelUpFv,
    (void *)render__17TWindowSetLevelUpFv,
    (void *)render_shadows__7TObjectFv,
};
extern char lbl_8044F534[];
extern char lbl_8044F53C[];
extern char lbl_8044F544[];
extern void *lbl_805D39C8;
extern void *lbl_805D63F0;
extern const f32 lbl_805DD2FC;
extern const f32 lbl_805DD300;
extern const f32 lbl_805DD304;
extern const f32 lbl_805DD308;
extern const f32 lbl_805DD30C;
extern const f32 lbl_805DD310;
extern const f32 lbl_805DD314;
extern const f32 lbl_805DD318;
extern const f32 lbl_805DD31C;
extern const f32 lbl_805DD320;
extern const f32 lbl_805DD324;
extern const f32 lbl_805DD328;
extern const f32 lbl_805DD32C;
extern const f32 lbl_805DD330;
extern char lbl_805DD338[4];

void draw_window_scrollbar(Scroll_8026D790 *scroll, Ctx_8026D790 *c, f32 *offset) {
    Quad_8026D790 q;
    f32 depth;
    f32 x;
    f32 y;
    f32 t;
    if (c->x30 < 0) {
        return;
    }
    if (scroll->height <= c->clip_height) {
        return;
    }
    if (c->height < lbl_805DD2FC) {
        return;
    }
    x = c->x + c->width - lbl_805DD300;
    y = lbl_805DD304 + c->y;
    begin_screen_draw(0);
    TObjFish::set_global_param((s32)lbl_805D63F0);
    set_draw_texture_and_color(0, 0xFF646464);
    depth = lbl_805DD308 / (lbl_805DD30C + c->x38);
    q.x = x;
    q.r = lbl_805DD310 + x;
    q.y = y;
    q.b = (y + c->height) - lbl_805DD314;
    q.u = lbl_805DD318;
    q.v = lbl_805DD31C;
    q.ur = lbl_805DD320;
    q.vb = lbl_805DD324;
    apply_context_transform_to_rect(c, &q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    set_constant_material_color(calc_pulse_flash_color(0x86, 0xFF, 0x41, scroll->frame, 0x1C2, 0x12C, 0x13B, 0x14A));
    depth = lbl_805DD308 / (lbl_805DD328 + c->x38);
    t = c->height;
    if (t >= lbl_805DD2FC) {
        t -= lbl_805DD314;
        if (scroll->height <= t) {
            q.y = y;
            q.b = y + t;
        } else {
            q.y = y + offset[1] * t / scroll->height;
            q.b = q.y + c->clip_height * t / scroll->height;
        }
    }
    q.x = x;
    q.r = lbl_805DD310 + x;
    q.u = lbl_805DD32C;
    q.v = lbl_805DD31C;
    q.ur = lbl_805DD330;
    q.vb = lbl_805DD324;
    apply_context_transform_to_rect(c, &q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    TWindowSubStatusDisp::get_player();
}

void TWindowSubStatusDisp::increment_counter() {
    *(s32 *)&this->m_prev = (s32) (*(s32 *)&this->m_prev + 1);
}

s32 TWindowSubStatusDisp::destroy_allocation(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

void *TWindowSubStatusDisp::reset_selection() {
    copy_position__11TWindowMenuFPv();
    this->m_prev = 0;
    return this;
}

void TWindowSetLevelUp::update_stat_messages() {
    LvUp_8026DA44 *self = (LvUp_8026DA44 *)this;
    VObj_8026DA44 *pl;

    text_builder_reset();
    text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x46)));
    switch (self->state) {
    case 0:
    case 1:
        pl = (VObj_8026DA44 *)get_player_by_client_id(self->client);
        if (pl != NULL && ((TObjPlayer *)pl)->get_stats() != 0) {
            text_builder_append((u8 *)lbl_8044F534);
            TWindowSubStatusDisp__sub_80228F5C(pl->get_level() + 1);
            ((TWindowCtrl *)(self->client))->set_window_flags_off((s32)get_shared_text_buffer());
            self->state = 2;
        }
        break;
    case 2:
        if (self->d3a > 0) {
            text_builder_append((u8 *)lbl_8044F53C);
            TWindowSubStatusDisp__sub_80228F5C(self->d3a);
            ((TWindowCtrl *)(self->client))->set_window_flags_off((s32)get_shared_text_buffer());
            self->state = 3;
            break;
        }
    case 3:
        if (self->d3c > 0) {
            text_builder_append((u8 *)lbl_8044F544);
            TWindowSubStatusDisp__sub_80228F5C(self->d3c);
            ((TWindowCtrl *)(self->client))->set_window_flags_off((s32)get_shared_text_buffer());
            self->state = 4;
            break;
        }
    case 4:
        if (self->d24 > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x83)));
            text_builder_append((u8 *)lbl_805DD338);
            TWindowSubStatusDisp__sub_80228F5C(self->d24);
            ((TWindowCtrl *)(self->client))->set_window_flags_off((s32)get_shared_text_buffer());
            self->state = 5;
            break;
        }
    case 5:
        if (self->d26 > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x84)));
            text_builder_append((u8 *)lbl_805DD338);
            TWindowSubStatusDisp__sub_80228F5C(self->d26);
            ((TWindowCtrl *)(self->client))->set_window_flags_off((s32)get_shared_text_buffer());
            self->state = 6;
            break;
        }
    case 6:
        if (self->d28 > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x85)));
            text_builder_append((u8 *)lbl_805DD338);
            TWindowSubStatusDisp__sub_80228F5C(self->d28);
            ((TWindowCtrl *)(self->client))->set_window_flags_off((s32)get_shared_text_buffer());
            self->state = 7;
            break;
        }
    case 7:
        if (self->d2a > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x86)));
            text_builder_append((u8 *)lbl_805DD338);
            TWindowSubStatusDisp__sub_80228F5C(self->d2a);
            ((TWindowCtrl *)(self->client))->set_window_flags_off((s32)get_shared_text_buffer());
            self->state = 8;
            break;
        }
    case 8:
        if (self->d2c > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x87)));
            text_builder_append((u8 *)lbl_805DD338);
            TWindowSubStatusDisp__sub_80228F5C(self->d2c);
            ((TWindowCtrl *)(self->client))->set_window_flags_off((s32)get_shared_text_buffer());
            self->state = 9;
            break;
        }
    case 9:
        queue_destruction__7TObjectFv(self);
        break;
    }
    self->timer = 0x16;
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
void render__17TWindowSetLevelUpFv(void) {  }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
void run_task__17TWindowSetLevelUpFv(u8 *arg0) {
    s16 temp_r5;
    temp_r5 = *(s16 *)((s8 *)arg0 + 0x1E);
    *(s16 *)((s8 *)arg0 + 0x1E) = (temp_r5 - 1);
    if (temp_r5 <= 0) {
        ((s32 (*)(void))update_stat_messages__17TWindowSetLevelUpFv)();
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
void *__dt__17TWindowSetLevelUpFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)__vt__17TWindowSetLevelUp;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
void *__ct__17TWindowSetLevelUpFv(void *window_set_level_up, void *arg1, void *arg2, void *arg3) {
    struct VOff_8026DD70_arg0_8026DCE0 *self = (struct VOff_8026DD70_arg0_8026DCE0 *)window_set_level_up;
    __ct__7TObjectFP7TObject(window_set_level_up);
    *(s32 **)((s8 *)window_set_level_up + 0x18) = (s32 *)__vt__17TWindowSetLevelUp;
    ((TObjPlayer *)(self->f_24))->reset_sub_status_disp();
    *(void * *)&((TWindowSetLevelUp *)window_set_level_up)->m_name = lbl_805D39C8;
    ((TWindowSetLevelUp *)(self->f_24))->copy_stat_block((s32)arg2);
    *(u16 *)((s8 *)window_set_level_up + 0x1E) = 0;
    *(void **)((s8 *)window_set_level_up + 0x20) = arg3;
    *(u8 *)((s8 *)window_set_level_up + 0x1C) = 0;
    return window_set_level_up;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
void TWindowSetLevelUp::copy_stat_block(s32 arg1) {
    s32 arg0 = (s32)this;
    *(ByteBlock_16 *)(arg0) = *(const ByteBlock_16 *)(arg1);
    *(s16 *)((s8 *)arg0 + 0x16) = (s16) *(s16 *)((s8 *)arg1 + 0x16);
    *(s16 *)((s8 *)arg0 + 0x18) = (s16) *(s16 *)((s8 *)arg1 + 0x18);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
void TWindowSetLevelUp__sub_8026DE28(void* p, s32 v) { *(s32*)((char*)p + 0x88) = v; }
}
#pragma pop
