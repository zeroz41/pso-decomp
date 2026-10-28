#include "pso/TAdFadeGC.h"

#include "types.h"
#include "pso/TObject.h"
#include "pso/object/TObjTradeCollision.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/ModelDrawContext.h"

struct Desc_802C79C8 { f32 *pos; u32 *col; s32 a; s32 b; };

extern "C" {
s32 get_main_phase(void);
s32 get_current_floor(void);
void *get_player_by_client_id(s32 i);
f32 xz_distance_squared(void *, void *);
void queue_destruction__7TObjectFv(void *arg0);
s32 draw_color_lines(void *, int, int, f32);
s32 draw_tri_fan_2d__14TObjCMHairMenuFllf(void *, int, int, f32, f32, f32);
f32 lbl_805D6800;
s8 lbl_805D6804;
extern const char lbl_80471D70[] = "TAdFadeGC";
const char *TAdFadeGC__name = lbl_80471D70;

void TAdFadeGC::draw_fade() {
    u8 *arg0 = (u8 *)this;
    f32 pos[8];
    Desc_802C79C8 d;
    u32 col[4];
    u32 i;
    f32 y;
    f32 y2;
    u32 c;

    d.pos = pos;
    d.col = col;
    d.a = 0;
    d.b = 4;
    switch (*(s32 *)((s8 *)arg0 + 0x28)) {
    case 0:
        set_color_blending_mode(0, 0xB);
        set_color_blending_mode(1, 4);
        for (i = 0; i < 120; i++) {
            d.pos[0] = (0.0f);
            y = (8.0f) * (f32) i;
            d.pos[1] = y;
            d.col[0] = 0x0FFFFFFF;
            d.pos[2] = *(f32 *)((s8 *)arg0 + 0x20);
            d.pos[3] = y;
            d.col[1] = 0xFFFFFFFF;
            d.pos[4] = (6.4e+02f);
            y2 = (4.0f) + y;
            d.pos[5] = y2;
            d.col[2] = 0xFFFFFFFF;
            d.pos[6] = (6.4e+02f) - *(f32 *)((s8 *)arg0 + 0x20);
            d.pos[7] = y2;
            d.col[3] = 0xFFFFFFFF;
            if (lbl_805D6804 == 0) {
                lbl_805D6804 = 1;
                lbl_805D6800 = (-1.0f);
            }
            draw_color_lines(&d, 4, 7, lbl_805D6800);
        }
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
        break;
    case 1:
    case 2:
        d.pos[0] = (0.0f);
        d.pos[1] = (0.0f);
        c = *(u32 *)((s8 *)arg0 + 0x30);
        d.col[0] = (c << 8) | (c >> 24);
        d.pos[2] = (0.0f);
        d.pos[3] = (4.8e+02f);
        c = *(u32 *)((s8 *)arg0 + 0x30);
        d.col[1] = (c << 8) | (c >> 24);
        d.pos[4] = (6.4e+02f);
        d.pos[5] = (4.8e+02f);
        c = *(u32 *)((s8 *)arg0 + 0x30);
        d.col[2] = (c << 8) | (c >> 24);
        d.pos[6] = (6.4e+02f);
        d.pos[7] = (0.0f);
        c = *(u32 *)((s8 *)arg0 + 0x30);
        d.col[3] = (c << 8) | (c >> 24);
        draw_tri_fan_2d__14TObjCMHairMenuFllf(&d, 4, 7, (-1.0f), (4.8e+02f), (0.0f));
        break;
    }
}

void TAdFadeGC::render() { if (all_parents_unqueued_for_destruction() != 0) { draw_fade(); } }

void TAdFadeGC::run_task() {
    f32 temp_f0;
    f32 temp_f1_2;
    f32 var_f2;
    if (((s32)all_parents_unqueued_for_destruction()) != 0) {
        *(s32 *)((s8 *)this + 0x1C) = (s32) (*(s32 *)((s8 *)this + 0x1C) + 1);
        switch (*(s32 *)((s8 *)this + 0x28)) {
        case 0:
            *(f32 *)((s8 *)this + 0x20) += 60.0f;
            *(f32 *)((s8 *)this + 0x20) = (*(f32 *)((s8 *)this + 0x20) > (6.4e+02f)) ? (6.4e+02f) : *(f32 *)((s8 *)this + 0x20);
            return;
        case 1: {
            *(f32 *)((s8 *)this + 0x2C) = (f32) (*(f32 *)((s8 *)this + 0x2C) + *(f32 *)((s8 *)this + 0x34));
            if (*(f32 *)((s8 *)this + 0x2C) > 1.0f) {
                *(f32 *)((s8 *)this + 0x2C) = 1.0f;
                queue_destruction__7TObjectFv(this);
                return;
            }
            *(s32 *)((s8 *)this + 0x30) = (s32) (((s32) ((255.0f) * (*(f32 *)((s8 *)this + 0x2C))) << 0x18) | 0xFF0000 | 0xFFFF);
            return;
        }
        case 2: {
            *(f32 *)((s8 *)this + 0x2C) = (f32) (*(f32 *)((s8 *)this + 0x2C) + *(f32 *)((s8 *)this + 0x34));
            temp_f1_2 = *(f32 *)((s8 *)this + 0x2C);
            if (temp_f1_2 < 0.0f) {
                *(f32 *)((s8 *)this + 0x2C) = 0.0f;
                queue_destruction__7TObjectFv(this);
                return;
            }
            *(s32 *)((s8 *)this + 0x30) = (s32) ((s32) ((255.0f) * temp_f1_2) << 0x18);
            break;
        }
        }
    }
}

void TAdFadeGC::start_fade(void *arg1) {
    switch ((s32)arg1) {
    case 0:
        break;
    case 1:
        *(f32 *)((s8 *)this + 0x2C) = (0.0f);
        *(s32 *)((s8 *)this + 0x30) = 0;
        *(f32 *)((s8 *)this + 0x34) = (0.025f);
        break;
    case 2:
        *(f32 *)((s8 *)this + 0x2C) = (1.0f);
        *(s32 *)((s8 *)this + 0x30) = 0;
        *(f32 *)((s8 *)this + 0x34) = -0.06666667f;
        break;
    }
}

TAdFadeGC::~TAdFadeGC() {}
}
TAdFadeGC::TAdFadeGC(TObject *object, void *arg2) : TObject(object) {
    *(void * *)&this->m_name = (*(void **)&TAdFadeGC__name);
    *(u32 *)((s8 *)this + 0x1C) = -1;
    *(f32 *)((s8 *)this + 0x20) = (0.0f);
    *(void **)((s8 *)this + 0x28) = arg2;
    this->start_fade((void *)(*(void **)((s8 *)this + 0x28)));
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
bool TObjTradeCollision::is_player_outside_trade_radius(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    f32 temp_f0;
    f32 temp_f31;
    s32 temp_r31;
    s32 player;
    player = (s32)get_player_by_client_id(arg1);
    if (player == 0) {
        return 0;
    }
    if (get_main_phase() != 0xF) {
        return 0;
    }
    temp_r31 = ((TObjPlayer *)player)->get_field_3e4();
    if (temp_r31 != get_current_floor()) {
        return 0;
    }
    temp_f0 = *(f32 *)&this->unk_AC;
    temp_f31 = temp_f0 * temp_f0;
    return (xz_distance_squared((void *)(player + 0x38), (void *)(arg0 + 0x38)) < temp_f31) == 0;
}
#pragma pop
