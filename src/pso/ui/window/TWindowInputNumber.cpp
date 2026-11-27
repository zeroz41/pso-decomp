#include "pso/system/SoundEffect.h"
#include "pso/system/ControllerInputState.h"
#include "pso/unk/TWindowLayoutNumber.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/render/TextureState.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/HeadingEntry.h"

const char *TWindowInputNumber::class_name = "TWindowInputNumber";
// Value of one step at each digit position (1 .. 1000000).
static const s32 number_input_decimal_place_values[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};

InputNumberWindowLayout window_input_number_layout_entries = {
    1, 6,
    {4, {52.0f, 18.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
};

WindowDescriptor window_input_number_layout = {
    {104.0f, 74.0f}, 50050.0f, &window_input_number_layout_entries, 3,
};


void TWindowInputNumber::mark_confirmed() {
    if (!(this->inputFlags & 8) && (TWindowInputNumber::is_confirmed() == 0)) {
        this->inputFlags = (u16) (this->inputFlags | 4);
    }
}
void TWindowInputNumber::confirm_input() {
    s32 current;
    WindowHeading *heading_window;

    current = this->value;
    if ((current < (s32) this->minimum) || (current > (s32) this->maximum)) {
        play_sound_effect(0x53F06, 0, 0, 0);
        return;
    }
    play_sound_effect(0x52D01, 0, 0, 0);
    this->inputFlags = (u16) (this->inputFlags | 2);
    heading_window = this->heading;
    if (heading_window != NULL) {
        heading_window->set_state(2);
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
    s8 digits;

    play_sound_effect(0x54100, 0, 0, 0);
    this->selectedDigit = (u8) (this->selectedDigit + 1);
    if (this->selectedDigit >= (digits = this->digitCount)) {
        if (this->inputFlags & 1) {
            this->selectedDigit = (digits - 1);
            return;
        }
        this->selectedDigit = 0U;
    }
}

void TWindowInputNumber::set_value(f32 value) {
    this->target_size[0] = value;
    TWindowBase::save_position();
    align_digits();
}


static const ArrowUVs arrow_uvs = {{{224.0f, 0.0f}, {240.0f, 0.0f}}};


void TWindowInputNumber::create(const char *title) {
    WindowHeading *created;

    if (this->heading == NULL) {
        created = new WindowHeading(title, this->client_index);
        this->heading = created;
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
        TWindowLayoutNumber *d = static_cast<TWindowLayoutNumber *>(get_array_entry(i));
        d->x = scale * d->width + pos;
        pos -= step;
    }
    for (; i < 6; i++) {
        TWindowLayoutNumber *d = static_cast<TWindowLayoutNumber *>(get_array_entry(i));
        d->flags |= 2;
    }
}
#pragma pop

void TWindowInputNumber::refresh_digit_entries() {
    s32 i;
    TWindowLayoutNumber *entry;
    s32 rest;

    i = 0;
    rest = value;
    do {
        entry = (TWindowLayoutNumber *)get_array_entry(i);
        entry->value = rest % 10;
        entry->calc_size();
        rest = rest / 10;
        i++;
    } while ((u32)i < 6U);
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
void TWindowInputNumber::draw_arrows(WindowDrawContext *ctx, TWindowLayoutNumber *digit, int confirmed) {
    ArrowUVs uvs = arrow_uvs;
    ArrowUV *uv;
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
    set_texture_list(hud_texlist);
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
    draw_textured_quad_at_depth(&q.x0, depth);
    q.x0 = x;
    q.y0 = 25.0f + y;
    q.x1 = 14.0f + q.x0;
    q.y1 = 12.0f + q.y0;
    q.u0 = uv->u / 256.0f;
    q.v0 = (28.0f + uv->v) / 256.0f;
    q.u1 = (14.0f + uv->u) / 256.0f;
    q.v1 = (28.0f + (12.0f + uv->v)) / 256.0f;
    ctx->transform_quad(&q);
    draw_textured_quad_at_depth(&q.x0, depth);
    q.x0 = x;
    q.y0 = 19.0f + y;
    q.x1 = 14.0f + q.x0;
    q.y1 = 12.0f + q.y0;
    q.u0 = uv->u / 256.0f;
    q.v0 = (13.0f + uv->v) / 256.0f;
    q.u1 = (14.0f + uv->u) / 256.0f;
    q.v1 = (13.0f + (12.0f + uv->v)) / 256.0f;
    ctx->transform_quad(&q);
    draw_textured_quad_at_depth(&q.x0, depth);
    end_screen_draw();
}
#pragma pop

void TWindowInputNumber::render() {
    WindowDrawContext *context = setup_window_draw_context(&scaleX);
    draw_window_frame(context);
    draw_visible_window_entries(this, &entry_list, context);
    draw_arrows(context, static_cast<TWindowLayoutNumber *>(get_array_entry(selectedDigit)), is_confirmed());
    WindowHeading *heading_window = heading;
    if (heading_window != NULL) {
        heading_window->render(context);
    }
}

void TWindowInputNumber::run_task() {
    s32 port;
    WindowHeading *heading_window;
    ControllerInputContext *input;
    ControllerInputContext *pad;
    ControllerInputContext *context;

    port = is_player_input_active(this->client_index);
    if (!(this->window_flags & 2)) {
        this->open_tick = 0x01000000;
    }
    if ((this->is_confirmed() == 0) && !(this->inputFlags & 0x40) && (this->is_open_and_unblocked() != 0)) {
        if (this->inputFlags & 0x10) {
            input = &controller_input_state.controllers[port];
            if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (this->is_locked(0x10) != 0)) {
                this->update_value();
            }
            if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (this->is_locked(0x20) != 0)) {
                this->update();
            }
            if ((test_buttons_press_or_repeat(input, 0x40, 6, 1) != 0) || (this->is_locked(0x40) != 0)) {
                this->move_cursor_next();
            }
            if ((test_buttons_press_or_repeat(input, 0x80, 6, 1) != 0) || (this->is_locked(0x80) != 0)) {
                this->handle_decrement();
            }
        } else {
            pad = &controller_input_state.controllers[port];
            if ((test_buttons_press_or_repeat_color(pad, 0x10, 6, 1) != 0) || (this->is_locked(0x10) != 0)) {
                this->update_value();
            }
            if ((test_buttons_press_or_repeat_color(pad, 0x20, 6, 1) != 0) || (this->is_locked(0x20) != 0)) {
                this->update();
            }
            if ((test_buttons_press_or_repeat_color(pad, 0x40, 6, 1) != 0) || (this->is_locked(0x40) != 0)) {
                this->move_cursor_next();
            }
            if ((test_buttons_press_or_repeat_color(pad, 0x80, 6, 1) != 0) || (this->is_locked(0x80) != 0)) {
                this->handle_decrement();
            }
        }
        context = &controller_input_state.controllers[port];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (this->test_input_flag(4) != 0)) {
            this->confirm_input();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (this->test_input_flag(2) != 0)) {
            this->mark_confirmed();
        }
    }
    heading_window = this->heading;
    if ((heading_window != NULL) && ((f32) this->open_tick >= 7.5f)) {
        heading_window->update();
    }
    this->update_window();
    this->update_fade();
    this->update_window_entry_list(&this->entry_list);
}

TWindowInputNumber::~TWindowInputNumber() {
    if (heading != NULL) { delete heading; }
}


TWindowInputNumber::TWindowInputNumber(const NJS_POINT2 *position, s32 low, s32 high, s32 initial, s16 client)
    : TWindowBase((u8 *)&window_input_number_layout, client, (u8 *)position) {
    m_name = TWindowInputNumber::class_name;
    client_index = client;
    inputFlags = 0;
    selectedDigit = 0;
    minimum = low;
    maximum = high;
    value = initial;
    heading = 0;
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
    return test_buttons_press_or_repeat(&controller_input_state.keyboard, buttons, 6, 1);
}
