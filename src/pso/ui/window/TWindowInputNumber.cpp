#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/ControllerInputState.h"
#include "pso/unk/TUnk_804CF9C8.h"
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

struct UV_802563A0 { f32 u, v; };
struct ArrowUVs { UV_802563A0 uv[2]; };
static const ArrowUVs arrow_uvs = {{{224.0f, 0.0f}, {240.0f, 0.0f}}};

extern "C" {

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
    pos = scale * (target_size[0] - 8.0f) + scale * (f32)(digitCount * 12);
    pos -= 6.0f;
    for (; i < digitCount; i++) {
        TUnk_804CF9C8 *d = static_cast<TUnk_804CF9C8 *>(get_array_entry(i));
        d->x = scale * d->width + pos;
        pos -= step;
    }
    for (; i < 6; i++) {
        TUnk_804CF9C8 *d = static_cast<TUnk_804CF9C8 *>(get_array_entry(i));
        d->flags |= 2;
    }
}
#pragma pop

void TWindowInputNumber::refresh_digit_entries() {
  s32 i;
  u8 *entry;
  s32 var_r29;
  i = 0;
  var_r29 = this->value;
  do
  {
    entry = (u8 *) ((TWindowBase *)((u8 *)this))->get_array_entry(i);
    *((s32 *) (((s8 *) entry) + 0x20)) = (s32) (var_r29 % 10);
    draw_right_aligned_number(entry);
    var_r29 = var_r29 / 10;
    i += 1;
  }
  while (((u32) i) < 6U);
}

void TWindowInputNumber::calc_digit_count() {
    s32 i = 0;
    digitCount = 0;
    while (i < 6) {
        if (maximum < number_input_decimal_place_values[i]) {
            break;
        }
        digitCount = i;
        i++;
    }
    digitCount++;
}

#pragma push
#pragma fp_contract on
void TWindowInputNumber::draw_arrows(WindowDrawContext *ctx, TUnk_804CF9C8 *digit, int confirmed) {
    ArrowUVs uvs = arrow_uvs;
    UV_802563A0 *uv;
    TexturedQuad q;
    f32 x;
    f32 y;
    f32 depth;

    if (ctx->open_tick < 0) {
        return;
    }
    uv = &uvs.uv[0];
    if (confirmed != 0) {
        uv = &uvs.uv[1];
    }
    x = ctx->inner_x + digit->x - 0.5f * digit->width - 7.0f - 1.0f;
    y = ctx->inner_y + digit->y;
    depth = -1.0f / (0.22424999f + ctx->depth);
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(0, -1);
    q.x0 = x;
    q.y0 = y - 15.0f;
    q.x1 = 14.0f + q.x0;
    q.y1 = 12.0f + q.y0;
    q.u0 = uv->u / 256.0f;
    q.v0 = uv->v / 256.0f;
    q.u1 = (14.0f + uv->u) / 256.0f;
    q.v1 = (12.0f + uv->v) / 256.0f;
    ctx->transform_quad(&q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    q.x0 = x;
    q.y0 = 25.0f + y;
    q.x1 = 14.0f + q.x0;
    q.y1 = 12.0f + q.y0;
    q.u0 = uv->u / 256.0f;
    q.v0 = (28.0f + uv->v) / 256.0f;
    q.u1 = (14.0f + uv->u) / 256.0f;
    q.v1 = (28.0f + (12.0f + uv->v)) / 256.0f;
    ctx->transform_quad(&q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    q.x0 = x;
    q.y0 = 19.0f + y;
    q.x1 = 14.0f + q.x0;
    q.y1 = 12.0f + q.y0;
    q.u0 = uv->u / 256.0f;
    q.v0 = (13.0f + uv->v) / 256.0f;
    q.u1 = (14.0f + uv->u) / 256.0f;
    q.v1 = (13.0f + (12.0f + uv->v)) / 256.0f;
    ctx->transform_quad(&q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    TWindowSubStatusDisp::get_player();
}
#pragma pop

void TWindowInputNumber::render() {
    WindowDrawContext *context = setup_window_draw_context(&scaleX);
    draw_window_frame(context);
    draw_visible_window_entries(this, &entry_list, context);
    draw_arrows(context, static_cast<TUnk_804CF9C8 *>(get_array_entry(selectedDigit)), is_confirmed());
    void *heading = reinterpret_cast<void *>(unknown70);
    if (heading != NULL) {
        static_cast<TWindowSubStatusDisp *>(heading)->forward_render(context);
    }
}

void TWindowInputNumber::run_task() {
    TWindowInputNumber *self = this;
    s32 temp_r30;
    uaddr temp_r3;
    ControllerInputContext *input;
    ControllerInputContext *temp_r29_2;
    ControllerInputContext *context;

    temp_r30 = is_player_input_active(self->client_index);
    if (!(self->window_flags & 2)) {
        self->open_tick = 0x01000000;
    }
    if ((self->is_confirmed() == 0) && !(self->inputFlags & 0x40) && (self->sub_80244994() != 0)) {
        if (self->inputFlags & 0x10) {
            input = &controller_input_state.controllers[temp_r30];
            if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (self->is_locked(0x10) != 0)) {
                self->update_value();
            }
            if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (self->is_locked(0x20) != 0)) {
                self->update();
            }
            if ((test_buttons_press_or_repeat(input, 0x40, 6, 1) != 0) || (self->is_locked(0x40) != 0)) {
                self->move_cursor_next();
            }
            if ((test_buttons_press_or_repeat(input, 0x80, 6, 1) != 0) || (self->is_locked(0x80) != 0)) {
                self->handle_decrement();
            }
        } else {
            temp_r29_2 = &controller_input_state.controllers[temp_r30];
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x10, 6, 1) != 0) || (self->is_locked(0x10) != 0)) {
                self->update_value();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x20, 6, 1) != 0) || (self->is_locked(0x20) != 0)) {
                self->update();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x40, 6, 1) != 0) || (self->is_locked(0x40) != 0)) {
                self->move_cursor_next();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x80, 6, 1) != 0) || (self->is_locked(0x80) != 0)) {
                self->handle_decrement();
            }
        }
        context = &controller_input_state.controllers[temp_r30];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (self->test_input_flag(4) != 0)) {
            self->confirm_input();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (self->test_input_flag(2) != 0)) {
            self->mark_confirmed();
        }
    }
    temp_r3 = self->unknown70;
    if ((temp_r3 != 0U) && ((f32) self->open_tick >= 7.5f)) {
        ((TWindowSubStatusDisp *)temp_r3)->update_subwindow();
    }
    reinterpret_cast<TWindowDD *>(self)->initialize_subwindow();
    self->update_fade();
    self->update_window_entry_list(&self->entry_list);
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
