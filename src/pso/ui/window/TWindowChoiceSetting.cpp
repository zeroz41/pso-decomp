#include "pso/ui/window/WindowScrollBar.h"
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenuInfomation.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#include "pso/ui/window/WindowTextEntry.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/WindowLayout.h"

const char *lbl_805D3970 = "TWindowMenuInfomation";
static const NJS_POINT2 lbl_8044F3A0 = {425.0f, 188.0f};

extern "C" {
s32 TWindowSubComCard__sub_8026906C(void);

void TWindowMenuInfomation::request_close() {
    if (!(this->m_70 & 8) && (TWindowMenuInfomation::is_open() == 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->m_70 = (u16) (this->m_70 | 4);
    }
}
void TWindowMenuInfomation::draw() {
    get_array_entry(this->index);
    if (TWindowSubComCard__sub_8026906C() == 0) {
        play_sound_effect(0x52D01, 0, 0, 0);
        this->m_70 = (u16) (this->m_70 | 2);
        if (this->heading != 0) {
            this->heading->set_entry_state(2);
        }
    }
}
void TWindowMenuInfomation::move_next_choice() {
    s16 var_r31;

    play_sound_effect(0x54100, 0, 0, 0);
    var_r31 = this->index;
loop_1:
    var_r31 += 1;
    if (var_r31 >= entry_capacity) {
        if (!(this->m_70 & 1)) {
            var_r31 = 0;
            goto block_4;
        }
    } else {
block_4:
        if (var_r31 != (s16) this->index) {
            if (sub_80266B18(var_r31) != 0) {
                this->index = var_r31;
            } else {
                goto loop_1;
            }
        }
    }
}
void TWindowMenuInfomation::move_cursor_prev() {
    s16 var_r31;

    play_sound_effect(0x54100, 0, 0, 0);
    var_r31 = this->index;
loop_1:
    var_r31 -= 1;
    if (var_r31 < 0) {
        if (!(this->m_70 & 1)) {
            var_r31 = entry_capacity - 1;
            goto block_4;
        }
    } else {
block_4:
        if (var_r31 != (s16) this->index) {
            if (sub_80266B18(var_r31) != 0) {
                this->index = var_r31;
            } else {
                goto loop_1;
            }
        }
    }
}
void TWindowMenuInfomation::create_sub_window(const char *title) {
    TWindowSubStatusDisp *heading;

    if (this->heading == NULL) {
        heading = (TWindowSubStatusDisp *)::operator new(0x24);
        if (heading != NULL) {
            heading = (TWindowSubStatusDisp *)heading->construct_type1_heading((saddr)title, this->client_index);
        }
        this->heading = heading;
        this->window_flags |= 0x40;
    }
}
}
struct W_802689EC { u8 pad[0x4C]; f32 f4c; u32 f50; u8 pad54[0x6C - 0x54]; f32 f6c; u8 pad70[4]; s16 f74; u8 pad76[0x7C - 0x76]; u32 f7c; };

// dead-stripped: only its literals survive. 0.0f, 20.0f and 6.0f (.sdata2 0x805DD1D8-0x805DD1E0) open the pool
// ahead of update_scroll_offset's 9/0.5/16/10 although their live user clamp_scroll follows it in .text: a function
// compiled before update_scroll_offset built the same scroll clip. Minimal body after clamp_scroll's clip; name
// inferred.
static void get_scroll_clip(TWindowMenuInfomation *window, f32 *clip) {
    clip[0] = 0.0f;
    clip[1] = window->frame_size[1] - 20.0f;
    if (window->heading != 0) {
        clip[1] -= 6.0f;
    }
}

#pragma push
#pragma fp_contract on

void TWindowMenuInfomation::update_scroll_offset() {
    W_802689EC *w = (W_802689EC *)this;
    f32 v;
    if (w->f7c != 0 && w->f50 == 0) {
        v = 9.0f + (f32)(w->f74 * 20);
        v -= 0.5f * ((w->f4c - 16.0f) - 10.0f);
        w->f6c += v - w->f6c;
    }
}
#pragma pop

void TWindowMenuInfomation::clamp_scroll() {
    u8 *arg0 = (u8 *)this;
    NJS_POINT2 range;
    f32 temp_f1;
    if (scroll_bar != NULL) {
        range.x = 0.0f;
        temp_f1 = this->frame_size[1] - 20.0f;
        range.y = temp_f1;
        if (this->heading != 0) {
            range.y = temp_f1 - 6.0f;
        }
        scroll_bar->clamp_offset(scroll_offset, &range);
    }
}


void TWindowMenuInfomation::draw_setting(WindowDrawContext *context) {
    u16 *entry;

    entry = (u16 *)this->get_array_entry(this->index);
    if (*entry & 1) {
        draw_selection_bar(context, (u8 *)entry, this->is_open());
    }
}

void TWindowMenuInfomation__ct(TWindowMenuInfomation *window, u32 rows) {
    u32 i;
    WindowTextEntry *entry;
    window->m_name = lbl_805D3970;
    window->next_entry = 0;
    window->index = 0;
    window->entry_capacity = (s16)rows;
    window->m_70 = 0;
    window->heading = NULL;
    window->scroll_bar = NULL;
    for (i = 0; i < rows; i++) {
        entry = static_cast<WindowTextEntry *>(window->get_array_entry(i));
        entry->y = (f32)(i * 0x14);
    }
    window->set_depth(39000.0f);
}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

// inferred: choice_setting_popup_layout_entries, the layout table choice_setting_popup_window_descriptor
// points at (one type-9 record; fn_80268C5C fills in the row count).
struct ChoiceSettingPopupLayout {
    u32 cols;
    u32 rows;
    TypeLayoutRecord rec;
};
ChoiceSettingPopupLayout choice_setting_popup_layout_entries = {1, 0, {9}};
WindowDescriptor choice_setting_popup_window_descriptor = {
    {0.0f, 0.0f}, 50050.0f, &choice_setting_popup_layout_entries, 3,
};

TWindowMenuInfomation *create_information_counter_window(s32 rows) {
    TWindowMenuInfomation *window;

    fn_80268C5C(&lbl_8044F3A0, rows);
    window = new TWindowMenuInfomation((void *)get_window_layout_position(0xAE), rows);
    window->create_sub_window("Information Counter");
    return window;
}

void fn_80268C5C(const NJS_POINT2 *extent, s32 rows) {
    choice_setting_popup_window_descriptor.pad_00[0] = extent->x;
    choice_setting_popup_window_descriptor.pad_00[1] = extent->y;
    choice_setting_popup_layout_entries.rows = rows;
}

extern "C" {

void TWindowMenuInfomation::render() {
    WindowDrawContext *draw_context;

    draw_context = get_draw_context();
    ((TWindowBase *)((u8 *)this))->draw_window_frame(draw_context);
    draw_visible_window_entries(
        reinterpret_cast<const void *>(((u8 *)this)),
        reinterpret_cast<const WindowLayoutEntries *>(((u8 *)this) + 0x24),
        draw_context);
    draw_setting(draw_context);
    if (this->heading != 0) {
        ((TWindowSubStatusDisp *)((saddr)this->heading))->forward_render(draw_context);
    }
    if (scroll_bar != NULL) {
        draw_window_scrollbar(scroll_bar, draw_context, scroll_offset);
    }
}

void TWindowMenuInfomation::run_task() {
    u8 *arg0 = (u8 *)this;
    uaddr temp_r3;
    WindowScrollBar *temp_r3_2;
    ControllerInputContext *input;
    ControllerInputContext *temp_r30_2;
    ControllerInputContext *context;
    if ((this->is_selected() == 0) && (this->is_open() == 0)) {
        if (*(u16 *)((s8 *)arg0 + 0x70) & 0x10) {
            input = &controller_input_state.controllers[0];
            if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                this->move_cursor_prev();
            }
            if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
                this->move_next_choice();
            }
        } else {
            temp_r30_2 = &controller_input_state.controllers[0];
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r30_2, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                this->move_cursor_prev();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r30_2, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
                this->move_next_choice();
            }
        }
        context = &controller_input_state.controllers[0];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            this->draw();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            this->request_close();
        }
    }
    if ((f32) *(s32 *)&this->open_tick >= 7.5f) {
        temp_r3 = *(u32 *)((s8 *)arg0 + 0x78);
        if (temp_r3 != 0U) {
            ((TWindowSubStatusDisp *)temp_r3)->update_subwindow();
        }
        temp_r3_2 = scroll_bar;
        if (temp_r3_2 != NULL) {
            temp_r3_2->increment_counter();
        }
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowAddition *)arg0)->step_window_tween();
    this->update_scroll_offset();
    this->clamp_scroll();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&(*(void * *)((u8 *)this + 0x24))));
}

TWindowMenuInfomation::~TWindowMenuInfomation() {
    TWindowSubStatusDisp::destroy_allocation(reinterpret_cast<saddr>(scroll_bar), (s16)1);
    TWindowSubStatusDisp::destroy_status_display((saddr)this->heading, (s16)1);
}
TWindowMenuInfomation::TWindowMenuInfomation(void *parent, s32 rows)
    : TWindowAddition((u8 *)&choice_setting_popup_window_descriptor, 4, (u8 *)parent) {
    TWindowMenuInfomation__ct(this, (u32)rows);
}

}
