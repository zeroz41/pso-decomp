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
#include "pso/ui/window/LabelValueRow.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"

#include "pso/ui/window/WindowTextEntry.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/WindowLayout.h"

const char *TWindowMenuInfomation::class_name = "TWindowMenuInfomation";
static const NJS_POINT2 choice_setting_popup_extent = {425.0f, 188.0f};

extern "C" {
void TWindowMenuInfomation::request_close() {
    if (!(this->state_flags & 8) && (TWindowMenuInfomation::is_open() == 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->state_flags = (u16) (this->state_flags | 4);
    }
}
void TWindowMenuInfomation::draw() {
    if (static_cast<LabelValueRow *>(get_array_entry(this->index))->is_flag80_set() == 0) {
        play_sound_effect(0x52D01, 0, 0, 0);
        this->state_flags = (u16) (this->state_flags | 2);
        if (this->heading != 0) {
            this->heading->set_state(2);
        }
    }
}
void TWindowMenuInfomation::move_next_choice() {
    s16 candidate;

    play_sound_effect(0x54100, 0, 0, 0);
    candidate = this->index;
loop_1:
    candidate += 1;
    if (candidate >= entry_capacity) {
        if (!(this->state_flags & 1)) {
            candidate = 0;
            goto block_4;
        }
    } else {
block_4:
        if (candidate != (s16) this->index) {
            if (sub_80266B18(candidate) != 0) {
                this->index = candidate;
            } else {
                goto loop_1;
            }
        }
    }
}
void TWindowMenuInfomation::move_cursor_prev() {
    s16 candidate;

    play_sound_effect(0x54100, 0, 0, 0);
    candidate = this->index;
loop_1:
    candidate -= 1;
    if (candidate < 0) {
        if (!(this->state_flags & 1)) {
            candidate = entry_capacity - 1;
            goto block_4;
        }
    } else {
block_4:
        if (candidate != (s16) this->index) {
            if (sub_80266B18(candidate) != 0) {
                this->index = candidate;
            } else {
                goto loop_1;
            }
        }
    }
}
void TWindowMenuInfomation::create_sub_window(const char *title) {
    WindowHeading *heading;

    if (this->heading == NULL) {
        heading = new WindowHeading((saddr)title, this->client_index);
        this->heading = heading;
        this->window_flags |= 0x40;
    }
}
}
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
    f32 v;
    if (scroll_bar != 0 && tween_ticks == 0) {
        v = 9.0f + (f32)(index * 20);
        v -= 0.5f * ((frame_size[1] - 16.0f) - 10.0f);
        scroll_offset[1] += v - scroll_offset[1];
    }
}
#pragma pop

void TWindowMenuInfomation::clamp_scroll() {
    NJS_POINT2 range;
    f32 height;
    if (scroll_bar != NULL) {
        range.x = 0.0f;
        height = this->frame_size[1] - 20.0f;
        range.y = height;
        if (this->heading != 0) {
            range.y = height - 6.0f;
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
    window->m_name = TWindowMenuInfomation::class_name;
    window->next_entry = 0;
    window->index = 0;
    window->entry_capacity = (s16)rows;
    window->state_flags = 0;
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
// points at (one type-9 record; set_choice_setting_popup_size fills in the row count).
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

    set_choice_setting_popup_size(&choice_setting_popup_extent, rows);
    window = new TWindowMenuInfomation((void *)get_window_layout_position(0xAE), rows);
    window->create_sub_window("Information Counter");
    return window;
}

void set_choice_setting_popup_size(const NJS_POINT2 *extent, s32 rows) {
    choice_setting_popup_window_descriptor.size[0] = extent->x;
    choice_setting_popup_window_descriptor.size[1] = extent->y;
    choice_setting_popup_layout_entries.rows = rows;
}


void TWindowMenuInfomation::render() {
    WindowDrawContext *draw_context;

    draw_context = get_draw_context();
    this->draw_window_frame(draw_context);
    draw_visible_window_entries(
        reinterpret_cast<const void *>((this)),
        &entry_list,
        draw_context);
    draw_setting(draw_context);
    if (this->heading != 0) {
        this->heading->render(draw_context);
    }
    if (scroll_bar != NULL) {
        draw_window_scrollbar(scroll_bar, draw_context, scroll_offset);
    }
}

void TWindowMenuInfomation::run_task() {
    WindowHeading *heading_window;
    WindowScrollBar *scroll;
    ControllerInputContext *input;
    ControllerInputContext *pad;
    ControllerInputContext *context;
    if ((this->is_selected() == 0) && (this->is_open() == 0)) {
        if (state_flags & 0x10) {
            input = &controller_input_state.controllers[0];
            if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                this->move_cursor_prev();
            }
            if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
                this->move_next_choice();
            }
        } else {
            pad = &controller_input_state.controllers[0];
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command(pad, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                this->move_cursor_prev();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command(pad, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
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
    if ((f32) open_tick >= 7.5f) {
        heading_window = heading;
        if (heading_window != NULL) {
            heading_window->update();
        }
        scroll = scroll_bar;
        if (scroll != NULL) {
            scroll->increment_counter();
        }
    }
    update_window();
    this->step_window_tween();
    this->update_scroll_offset();
    this->clamp_scroll();
    update_window_entry_list(&entry_list);
}

TWindowMenuInfomation::~TWindowMenuInfomation() {
    delete scroll_bar;
    delete this->heading;
}
TWindowMenuInfomation::TWindowMenuInfomation(void *parent, s32 rows)
    : TWindowAddition((u8 *)&choice_setting_popup_window_descriptor, 4, (u8 *)parent) {
    TWindowMenuInfomation__ct(this, (u32)rows);
}

s32 LabelValueRow::get_entry_id() { return id; }
int LabelValueRow::is_flag80_set() { return flags & 0x80; }
