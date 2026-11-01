#include "types.h"
#include "pso/misc/TWindowCtrl_8024A054.h"
#include "pso/misc/TWindowInputNumber_80256170.h"
#include "pso/misc/TWindowSubStatusDisp_802598E4.h"
#include "pso/misc/TWindowChoiceSetting.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/misc/TWindowBase.h"
#include "pso/ui/TWindowInputNumber.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/object/TObjFish.h"

struct RecoveredGlobal_80256A60_lbl_804CF8EC {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80256A60___vt__18TWindowInputNumber {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_80256B0C_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

typedef struct Digit_802561E8 {
    u16 flags;
    u8 pad2[6];
    f32 x;
    f32 y;
    f32 w;
} Digit_802561E8;

struct Ctx_802563A0 {
    u8 pad0[0x10];
    f32 x;
    f32 y;
    u8 pad18[0x30 - 0x18];
    s32 visible;
    u8 pad34[0x38 - 0x34];
    f32 depth;
};

struct UV_802563A0 { f32 u, v; };
struct ArrowUVs { UV_802563A0 uv[2]; };
static const ArrowUVs arrow_uvs = {{{224.0f, 0.0f}, {240.0f, 0.0f}}};

struct Quad_802563A0 { f32 x, y, x2, y2, u, v, u2, v2; };

typedef struct InNum_802561E8 {
    u8 pad0[0x38];
    f32 x;
    u8 pad3c[0x26];
    s8 ndigits;
} InNum_802561E8;

struct Win_80256354 { u8 p0[0x62]; s8 f62; u8 p63[5]; s32 f68; };

extern "C" {
void construct_base__9TWindowDDFPUcsPUc(void *, void *, s16, void *);
extern RecoveredGlobal_80256A60_lbl_804CF8EC window_input_number_layout;
extern s32 __vt__18TWindowInputNumber[];
extern s32 TWindowInputNumber__name;
extern s8 controller_input_state[];
u8 test_input_flag__18TWindowInputNumberFv(u8 *arg0);
extern const s32 number_input_decimal_place_values[];
void draw_arrows__18TWindowInputNumberFv(TWindowInputNumber *, Ctx_802563A0 *, Digit_802561E8 *, int);
void apply_context_transform_to_rect(Ctx_802563A0 *, Quad_802563A0 *);
void begin_screen_draw(s32);
void set_draw_texture_and_color(s32, s32);
void draw_textured_quad_at_depth(Quad_802563A0 *q, f32 depth);
extern s32 lbl_805D63F0;
s32 draw_visible_window_entries(void *, void *, int);
u32 construct_type1_heading__20TWindowSubStatusDispFll(u32, s32, s16);
void __dl__7TObjectFPv(void *);
s32 forward_render__20TWindowSubStatusDispFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(int, int);

void TWindowInputNumber::create(s32 arg1) {
    u32 var_r0;

    if ((u32) this->unknown70 == 0U) {
        var_r0 = (int)::operator new(0x24);
        if (var_r0 != 0U) {
            u32 saved = var_r0;
            var_r0 = construct_type1_heading__20TWindowSubStatusDispFll(saved, arg1, this->clientIndex);
        }
        this->unknown70 = var_r0;
        this->m_2c = (s32) (this->m_2c | 0x40);
        *(f32 *)((s8 *)this + 0x3C) += 6.0f;
    }
}

#pragma push
#pragma fp_contract on
void TWindowInputNumber::align_digits() {
    s32 i;
    f32 step;
    f32 scale;
    f32 pos;
    i = 0;
    scale = 0.5f;
    step = 12.0f;
    pos = scale * (((InNum_802561E8 *)this)->x - 8.0f) + scale * (f32)(((InNum_802561E8 *)this)->ndigits * 12);
    pos -= 6.0f;
    for (; i < ((InNum_802561E8 *)this)->ndigits; i++) {
        Digit_802561E8 *d = (Digit_802561E8 *)((TWindowBase *)this)->get_array_entry(i);
        d->x = scale * d->w + pos;
        pos -= step;
    }
    for (; i < 6; i++) {
        Digit_802561E8 *d = (Digit_802561E8 *)((TWindowBase *)((InNum_802561E8 *)this))->get_array_entry(i);
        d->flags |= 2;
    }
}
#pragma pop

void TWindowInputNumber::refresh_digit_entries() {
  s32 var_r30;
  u8 *temp_r3;
  s32 var_r29;
  var_r30 = 0;
  var_r29 = this->value;
  do
  {
    temp_r3 = (u8 *) ((TWindowBase *)((u8 *)this))->get_array_entry(var_r30);
    *((s32 *) (((s8 *) temp_r3) + 0x20)) = (s32) (var_r29 % 10);
    draw_right_aligned_number(temp_r3);
    var_r29 = var_r29 / 10;
    var_r30 += 1;
  }
  while (((u32) var_r30) < 6U);
}

void TWindowInputNumber::calc_digit_count() {
    Win_80256354 *w = (Win_80256354 *)this;
    s32 i = 0;
    w->f62 = 0;
    while (i < 6) {
        if (w->f68 < number_input_decimal_place_values[i]) {
            break;
        }
        w->f62 = i;
        i++;
    }
    w->f62++;
}

#pragma push
#pragma fp_contract on
void draw_arrows__18TWindowInputNumberFv(TWindowInputNumber *self, Ctx_802563A0 *ctx, Digit_802561E8 *digit, int confirmed) {
    ArrowUVs uvs = arrow_uvs;
    UV_802563A0 *uv;
    Quad_802563A0 q;
    f32 x;
    f32 y;
    f32 depth;

    if (ctx->visible < 0) {
        return;
    }
    uv = &uvs.uv[0];
    if (confirmed != 0) {
        uv = &uvs.uv[1];
    }
    x = ctx->x + digit->x - 0.5f * digit->w - 7.0f - 1.0f;
    y = ctx->y + digit->y;
    depth = -1.0f / (0.22424999f + ctx->depth);
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D63F0);
    set_draw_texture_and_color(0, -1);
    q.x = x;
    q.y = y - 15.0f;
    q.x2 = 14.0f + q.x;
    q.y2 = 12.0f + q.y;
    q.u = uv->u / 256.0f;
    q.v = uv->v / 256.0f;
    q.u2 = (14.0f + uv->u) / 256.0f;
    q.v2 = (12.0f + uv->v) / 256.0f;
    apply_context_transform_to_rect(ctx, &q);
    draw_textured_quad_at_depth(&q, depth);
    q.x = x;
    q.y = 25.0f + y;
    q.x2 = 14.0f + q.x;
    q.y2 = 12.0f + q.y;
    q.u = uv->u / 256.0f;
    q.v = (28.0f + uv->v) / 256.0f;
    q.u2 = (14.0f + uv->u) / 256.0f;
    q.v2 = (28.0f + (12.0f + uv->v)) / 256.0f;
    apply_context_transform_to_rect(ctx, &q);
    draw_textured_quad_at_depth(&q, depth);
    q.x = x;
    q.y = 19.0f + y;
    q.x2 = 14.0f + q.x;
    q.y2 = 12.0f + q.y;
    q.u = uv->u / 256.0f;
    q.v = (13.0f + uv->v) / 256.0f;
    q.u2 = (14.0f + uv->u) / 256.0f;
    q.v2 = (13.0f + (12.0f + uv->v)) / 256.0f;
    apply_context_transform_to_rect(ctx, &q);
    draw_textured_quad_at_depth(&q, depth);
    TWindowSubStatusDisp::get_player();
}
#pragma pop

void render__18TWindowInputNumberFv(TWindowInputNumber *arg0) {
    s32 temp_r3;

    temp_r3 = ((TWindowBase *)arg0)->setup_window_draw_context((s32)((u8 *)arg0 + 0x74));
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(arg0, (u8 *)arg0 + 0x24, temp_r3);
    draw_arrows__18TWindowInputNumberFv(arg0, (Ctx_802563A0 *)temp_r3, (Digit_802561E8 *)((TWindowBase *)arg0)->get_array_entry(arg0->selectedDigit), arg0->is_confirmed());
    {
        void *temp_ptr = (void *) arg0->unknown70;
        if (temp_ptr != NULL) {
            forward_render__20TWindowSubStatusDispFv(temp_ptr, temp_r3);
        }
    }
}

void TWindowInputNumber::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r30;
    u32 temp_r3;
    u8 *input;
    u8 *temp_r29_2;
    u8 *temp_r29_3;

    temp_r30 = is_player_input_active(((s32) *(s16 *)((s8 *)arg0 + 0x20)));
    if (!(*(s32 *)((s8 *)arg0 + 0x2C) & 2)) {
        *(s32 *)((s8 *)arg0 + 0x5C) = 0x01000000;
    }
    if ((((TWindowInputNumber *)arg0)->is_confirmed() == 0) && !(*(u16 *)((s8 *)arg0 + 0x60) & 0x40) && (((TWindowBase *)arg0)->sub_80244994() != 0)) {
        if (*(u16 *)((s8 *)arg0 + 0x60) & 0x10) {
            input = (u8 *)controller_input_state + (temp_r30 * 0x50) + 0x20;
            if ((TWindowChoiceSetting::apply_choice((s32)input, 0x10, 6, 1) != 0) || (((TWindowInputNumber *)arg0)->is_locked(0x10) != 0)) {
                ((TWindowInputNumber *)arg0)->update_value();
            }
            if ((TWindowChoiceSetting::apply_choice((s32)input, 0x20, 6, 1) != 0) || (((TWindowInputNumber *)arg0)->is_locked(0x20) != 0)) {
                ((TWindowInputNumber *)arg0)->update();
            }
            if ((TWindowChoiceSetting::apply_choice((s32)input, 0x40, 6, 1) != 0) || (((TWindowInputNumber *)arg0)->is_locked(0x40) != 0)) {
                ((TWindowInputNumber *)arg0)->move_cursor_next();
            }
            if ((TWindowChoiceSetting::apply_choice((s32)input, 0x80, 6, 1) != 0) || (((TWindowInputNumber *)arg0)->is_locked(0x80) != 0)) {
                ((TWindowInputNumber *)arg0)->handle_decrement();
            }
        } else {
            temp_r29_2 = (u8 *)controller_input_state + (temp_r30 * 0x50) + 0x20;
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)temp_r29_2, 0x10, 6, 1) != 0) || (((TWindowInputNumber *)arg0)->is_locked(0x10) != 0)) {
                ((TWindowInputNumber *)arg0)->update_value();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)temp_r29_2, 0x20, 6, 1) != 0) || (((TWindowInputNumber *)arg0)->is_locked(0x20) != 0)) {
                ((TWindowInputNumber *)arg0)->update();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)temp_r29_2, 0x40, 6, 1) != 0) || (((TWindowInputNumber *)arg0)->is_locked(0x40) != 0)) {
                ((TWindowInputNumber *)arg0)->move_cursor_next();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)temp_r29_2, 0x80, 6, 1) != 0) || (((TWindowInputNumber *)arg0)->is_locked(0x80) != 0)) {
                ((TWindowInputNumber *)arg0)->handle_decrement();
            }
        }
        temp_r29_3 = (u8 *)controller_input_state + (temp_r30 * 0x50) + 0x20;
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r29_3, 4) != 0) || (((s32 (*)(void *, int))test_input_flag__18TWindowInputNumberFv)((void *)arg0, 4) != 0)) {
            ((TWindowInputNumber *)arg0)->confirm_input();
        }
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r29_3, 2) != 0) || (((s32 (*)(void *, int))test_input_flag__18TWindowInputNumberFv)((void *)arg0, 2) != 0)) {
            ((TWindowInputNumber *)arg0)->mark_confirmed();
        }
    }
    temp_r3 = *(u32 *)((s8 *)arg0 + 0x70);
    if ((temp_r3 != 0U) && ((f32) *(s32 *)((s8 *)arg0 + 0x5C) >= 7.5f)) {
        ((TWindowSubStatusDisp *)temp_r3)->update_subwindow();
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list(arg0 + 0x24);
}

void *__dt__18TWindowInputNumberFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        ((TWindowInputNumber *)arg0)->objectVtable = __vt__18TWindowInputNumber;
        if (*(void **)((s8 *)arg0 + 0x70) != NULL) { TWindowSubStatusDisp::destroy_status_display((s32)(*(void **)((s8 *)arg0 + 0x70)), (s16)1); }
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80256A60_lbl_804CF8EC_size[sizeof(RecoveredGlobal_80256A60_lbl_804CF8EC) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_80256A60___vt__18TWindowInputNumber_size[sizeof(RecoveredGlobal_80256A60___vt__18TWindowInputNumber) == 0x18 ? 1 : -1];
}

TWindowInputNumber::TWindowInputNumber(void *position, s32 low, s32 high,
                                     s32 initial, s16 client) {
    construct_base__9TWindowDDFPUcsPUc(this, &window_input_number_layout.value, client, position);
    objectVtable = __vt__18TWindowInputNumber;
    className = TWindowInputNumber__name;
    clientIndex = client;
    inputFlags = 0;
    selectedDigit = 0;
    minimum = low;
    maximum = high;
    value = initial;
    unknown70 = 0;
    scaleX = 1.0f;
    scaleY = 1.0f;
    calc_digit_count();
    refresh_digit_entries();
    align_digits();
}

typedef char RecoveredGlobal_80256B0C_lbl_8050E208_size[sizeof(RecoveredGlobal_80256B0C_lbl_8050E208) == 0x1B0 ? 1 : -1];
u8 TWindowInputNumber::test_input_flag() {
    if (this->inputFlags & 0x20) {
        return 0U;
    }
    return ((TAdSinglePlyChrSelectGC *)((u8 *)&(*(RecoveredGlobal_80256B0C_lbl_8050E208 *)&controller_input_state).value + 0x160))->test_flag_4c();
}

s32 TWindowInputNumber::is_locked(s32 arg1) {
    if (this->inputFlags & 0x20) {
        return 0;
    }
    return TWindowChoiceSetting::apply_choice((s32)(controller_input_state + 0x160), (s32)arg1, 6, 1);
}
