#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowSubStatusDisp_802598E4.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"

const char *TWindowInputNumber__name = "TWindowInputNumber";
// Value of one step at each digit position (1 .. 1000000).
static const s32 number_input_decimal_place_values[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};

// inferred: window_input_number_layout_entries, the layout table window_input_number_layout points at.
struct InputNumberWindowLayout {
    u32 cols;
    u32 rows;
    ValueLayoutRecord rec_0;
};

InputNumberWindowLayout window_input_number_layout_entries = {
    1, 6,
    {4, {52.0f, 18.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
};

WindowDescriptor window_input_number_layout = {
    {104.0f, 74.0f}, 50050.0f, &window_input_number_layout_entries, 3,
};

extern "C" {

s32 play_sound_effect(s32 a0 = 0, s32 a1 = 0, s32 a2 = 0, s32 a3 = 0);

void TWindowInputNumber::mark_confirmed() {
    if (!(this->inputFlags & 8) && (TWindowInputNumber::is_confirmed() == 0)) {
        this->inputFlags = (u16) (this->inputFlags | 4);
    }
}
void TWindowInputNumber::confirm_input() {
    s32 temp_r3;
    uaddr temp;

    temp_r3 = this->value;
    if ((temp_r3 < (s32) this->minimum) || (temp_r3 > (s32) this->maximum)) {
        play_sound_effect(0x53F06, 0, 0, 0);
        return;
    }
    play_sound_effect(0x52D01, 0, 0, 0);
    this->inputFlags = (u16) (this->inputFlags | 2);
    temp = (u32) this->unknown70;
    if (temp != 0U) {
        ((TWindowSubStatusDisp *)temp)->set_entry_state(2);
    }
}


void TWindowInputNumber::update() {
    play_sound_effect(0x54100, 0, 0, 0);
    this->value = (s32) (this->value - number_input_decimal_place_values[(s8) this->selectedDigit]);
    if ((s32) this->value < (s32) this->minimum) {
        this->value = (s32) this->maximum;
    }
    refresh_digit_entries();
    align_digits();
}

void TWindowInputNumber::update_value() {
    play_sound_effect(0x54100, 0, 0, 0);
    this->value = (s32) (this->value + number_input_decimal_place_values[(s8) this->selectedDigit]);
    if ((s32) this->value > (s32) this->maximum) {
        this->value = (s32) this->minimum;
    }
    refresh_digit_entries();
    align_digits();
}

void TWindowInputNumber::handle_decrement() {
    play_sound_effect(0x54100, 0, 0, 0);
    this->selectedDigit = (this->selectedDigit - 1);
    if ((s8) this->selectedDigit < 0) {
        if (this->inputFlags & 1) {
            this->selectedDigit = 0U;
            return;
        }
        this->selectedDigit = (this->digitCount - 1);
    }
}

void TWindowInputNumber::move_cursor_next() {
    u8 temp_r4;

    play_sound_effect(0x54100, 0, 0, 0);
    *(u8 *)&this->selectedDigit = (u8) (*(u8 *)&this->selectedDigit + 1);
    if ((s8) *(u8 *)&this->selectedDigit >= (s8) (temp_r4 = *(u8 *)&this->digitCount)) {
        if (this->inputFlags & 1) {
            *(u8 *)&this->selectedDigit = (temp_r4 - 1);
            return;
        }
        *(u8 *)&this->selectedDigit = 0U;
    }
}

void TWindowInputNumber::set_value(f32 farg0) {
    this->target_size[0] = farg0;
    TWindowBase::save_position();
    align_digits();
}

}

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
void draw_arrows__18TWindowInputNumberFv(TWindowInputNumber *, Ctx_802563A0 *, Digit_802561E8 *, int);
extern s32 hud_texlist;
void __dl__7TObjectFPv(void *);

void TWindowInputNumber::create(s32 title) {
    uaddr var_r0;

    if ((u32) this->unknown70 == 0U) {
        var_r0 = (saddr)::operator new(0x24);
        if (var_r0 != 0U) {
            uaddr saved = var_r0;
            var_r0 = (uaddr)((TWindowSubStatusDisp *)saved)->construct_type1_heading(title, this->client_index);
        }
        this->unknown70 = var_r0;
        this->window_flags = (s32) (this->window_flags | 0x40);
        this->target_size[1] += 6.0f;
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
  u8 *entry;
  s32 var_r29;
  var_r30 = 0;
  var_r29 = this->value;
  do
  {
    entry = (u8 *) ((TWindowBase *)((u8 *)this))->get_array_entry(var_r30);
    *((s32 *) (((s8 *) entry) + 0x20)) = (s32) (var_r29 % 10);
    draw_right_aligned_number(entry);
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
    TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(hud_texlist));
    set_draw_texture_and_color(0, -1);
    q.x = x;
    q.y = y - 15.0f;
    q.x2 = 14.0f + q.x;
    q.y2 = 12.0f + q.y;
    q.u = uv->u / 256.0f;
    q.v = uv->v / 256.0f;
    q.u2 = (14.0f + uv->u) / 256.0f;
    q.v2 = (12.0f + uv->v) / 256.0f;
    ((WindowDrawContext *)ctx)->transform_quad((TexturedQuad *)&q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    q.x = x;
    q.y = 25.0f + y;
    q.x2 = 14.0f + q.x;
    q.y2 = 12.0f + q.y;
    q.u = uv->u / 256.0f;
    q.v = (28.0f + uv->v) / 256.0f;
    q.u2 = (14.0f + uv->u) / 256.0f;
    q.v2 = (28.0f + (12.0f + uv->v)) / 256.0f;
    ((WindowDrawContext *)ctx)->transform_quad((TexturedQuad *)&q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    q.x = x;
    q.y = 19.0f + y;
    q.x2 = 14.0f + q.x;
    q.y2 = 12.0f + q.y;
    q.u = uv->u / 256.0f;
    q.v = (13.0f + uv->v) / 256.0f;
    q.u2 = (14.0f + uv->u) / 256.0f;
    q.v2 = (13.0f + (12.0f + uv->v)) / 256.0f;
    ((WindowDrawContext *)ctx)->transform_quad((TexturedQuad *)&q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    TWindowSubStatusDisp::get_player();
}
#pragma pop

void TWindowInputNumber::render() {
    TWindowInputNumber *arg0 = this;
    saddr ctx;

    ctx = reinterpret_cast<saddr>(((TWindowBase *)arg0)->setup_window_draw_context((f32 *)((u8 *)arg0 + 0x74)));
    ((TWindowBase *)arg0)->draw_window_frame((void *)ctx);
    draw_visible_window_entries(
        reinterpret_cast<const void *>(arg0),
        reinterpret_cast<const WindowLayoutEntries *>((u8 *)arg0 + 0x24),
        reinterpret_cast<WindowDrawContext *>(ctx));
    draw_arrows__18TWindowInputNumberFv(arg0, (Ctx_802563A0 *)ctx, (Digit_802561E8 *)((TWindowBase *)arg0)->get_array_entry(arg0->selectedDigit), arg0->is_confirmed());
    {
        void *temp_ptr = (void *) arg0->unknown70;
        if (temp_ptr != NULL) {
            ((TWindowSubStatusDisp *)((void *)(temp_ptr)))->forward_render((void *)(ctx));
        }
    }
}

void TWindowInputNumber::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r30;
    uaddr temp_r3;
    ControllerInputContext *input;
    ControllerInputContext *temp_r29_2;
    ControllerInputContext *context;

    temp_r30 = is_player_input_active(((s32) *(s16 *)((s8 *)arg0 + 0x20)));
    if (!(*(s32 *)((s8 *)arg0 + 0x2C) & 2)) {
        *(s32 *)((s8 *)arg0 + 0x5C) = 0x01000000;
    }
    if ((((TWindowInputNumber *)arg0)->is_confirmed() == 0) && !(*(u16 *)((s8 *)arg0 + 0x60) & 0x40) && (((TWindowBase *)arg0)->sub_80244994() != 0)) {
        if (*(u16 *)((s8 *)arg0 + 0x60) & 0x10) {
            input = &controller_input_state.controllers[temp_r30];
            if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (((TWindowInputNumber *)arg0)->is_locked(0x10) != 0)) {
                ((TWindowInputNumber *)arg0)->update_value();
            }
            if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (((TWindowInputNumber *)arg0)->is_locked(0x20) != 0)) {
                ((TWindowInputNumber *)arg0)->update();
            }
            if ((test_buttons_press_or_repeat(input, 0x40, 6, 1) != 0) || (((TWindowInputNumber *)arg0)->is_locked(0x40) != 0)) {
                ((TWindowInputNumber *)arg0)->move_cursor_next();
            }
            if ((test_buttons_press_or_repeat(input, 0x80, 6, 1) != 0) || (((TWindowInputNumber *)arg0)->is_locked(0x80) != 0)) {
                ((TWindowInputNumber *)arg0)->handle_decrement();
            }
        } else {
            temp_r29_2 = &controller_input_state.controllers[temp_r30];
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x10, 6, 1) != 0) || (((TWindowInputNumber *)arg0)->is_locked(0x10) != 0)) {
                ((TWindowInputNumber *)arg0)->update_value();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x20, 6, 1) != 0) || (((TWindowInputNumber *)arg0)->is_locked(0x20) != 0)) {
                ((TWindowInputNumber *)arg0)->update();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x40, 6, 1) != 0) || (((TWindowInputNumber *)arg0)->is_locked(0x40) != 0)) {
                ((TWindowInputNumber *)arg0)->move_cursor_next();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x80, 6, 1) != 0) || (((TWindowInputNumber *)arg0)->is_locked(0x80) != 0)) {
                ((TWindowInputNumber *)arg0)->handle_decrement();
            }
        }
        context = &controller_input_state.controllers[temp_r30];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (((TWindowInputNumber *)arg0)->test_input_flag(4) != 0)) {
            ((TWindowInputNumber *)arg0)->confirm_input();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (((TWindowInputNumber *)arg0)->test_input_flag(2) != 0)) {
            ((TWindowInputNumber *)arg0)->mark_confirmed();
        }
    }
    temp_r3 = *(u32 *)((s8 *)arg0 + 0x70);
    if ((temp_r3 != 0U) && ((f32) *(s32 *)((s8 *)arg0 + 0x5C) >= 7.5f)) {
        ((TWindowSubStatusDisp *)temp_r3)->update_subwindow();
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>(arg0 + 0x24));
}

TWindowInputNumber::~TWindowInputNumber() {
    if ((void *)unknown70 != NULL) { TWindowSubStatusDisp::destroy_status_display(unknown70, (s16)1); }
}

}

TWindowInputNumber::TWindowInputNumber(void *position, s32 low, s32 high, s32 initial, s16 client)
    : TWindowBase((u8 *)&window_input_number_layout, client, (u8 *)position) {
    m_name = TWindowInputNumber__name;
    client_index = client;
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

s32 TWindowInputNumber::test_input_flag(s32 buttons) {
    if (this->inputFlags & 0x20) {
        return 0U;
    }
    return test_controller_flag_4c_color(&controller_input_state.keyboard, buttons);
}

s32 TWindowInputNumber::is_locked(s32 buttons) {
    if (this->inputFlags & 0x20) {
        return 0;
    }
    return test_buttons_press_or_repeat(&controller_input_state.keyboard, (s32)buttons, 6, 1);
}
