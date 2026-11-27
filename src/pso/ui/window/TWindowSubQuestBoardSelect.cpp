#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowSubQuestBoard.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/render/ColorLineList.h"
#include "pso/unk/TQuestManager.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/ControllerInputState.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubQuestBoardSelect.h"
#include "pso/ui/chat/TWindowSubSymbolChatFaceType.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/HeadingEntry.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"

void TWindowSubQuestBoardSelect::clear_decided() {
    state_flags &= ~1;
}

void TWindowCtrl::clear_quest_board_open() {
    if (TWindowCtrl::instance != NULL) {
        TWindowCtrl::instance->flags &= ~0x10;
    }
}

void TWindowCtrl::set_quest_board_open() {
    if (TWindowCtrl::instance != NULL) {
        TWindowCtrl::instance->flags |= 0x10;
    }
}

#pragma push
#pragma readonly_strings on
const char *TWindowSubQuestBoardSelect::class_name = "TWindowSubQuestBoardSelect";
#pragma pop




SubQuestBoardSelectWindowLayout window_sub_quest_board_select_layout_entries = {
    8, 1,
    {
        {3, {210.0f, 6.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
        {3, {385.0f, 53.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    },
    {
        {6, {39.0f, 97.0f}, {56.0f, 56.0f}, 151.0f, 0.0f, 0.5f, -1, &hud_texlist, 2, 4},
        {6, {103.0f, 97.0f}, {56.0f, 56.0f}, 151.0f, 0.0f, 0.5f, -1, &hud_texlist, 2, 4},
        {6, {167.0f, 97.0f}, {56.0f, 56.0f}, 151.0f, 0.0f, 0.5f, -1, &hud_texlist, 2, 4},
        {6, {231.0f, 97.0f}, {56.0f, 56.0f}, 151.0f, 0.0f, 0.5f, -1, &hud_texlist, 2, 4},
        {6, {295.0f, 97.0f}, {56.0f, 56.0f}, 151.0f, 0.0f, 0.5f, -1, &hud_texlist, 2, 4},
        {6, {392.0f, 97.0f}, {56.0f, 56.0f}, 151.0f, 0.0f, 0.5f, -1, &hud_texlist, 2, 4},
    },
};
WindowDescriptor TWindowSubQuestBoardSelect::window_parameters = {
    {434.0f, 184.0f}, 50150.0f, &window_sub_quest_board_select_layout_entries, 3,
};

void TWindowSubQuestBoardSelect::update_slot_title() {
    char *str;
    WindowTextEntry *entry_1;
    str = quest_board_handlers[(s8) this->slot].title;
    entry_1 = static_cast<WindowTextEntry *>(this->get_array_entry(1));
    set_text_entry_string(entry_1, str, 0);
    entry_1->measure_text(100000.0f);
    entry_1->x = (f32) (385.0f - entry_1->width);
}


s32 TWindowSubQuestBoardSelect::get_slot_flag(s8 slot) {
    if (slot < 0) {
        return 0;
    }
    if (slot > 6) {
        return 0;
    }
    return TQuestThread::get_register(quest_mission_manager, slot + 0x4A);
}

void TWindowSubQuestBoardSelect::update_slot_display_flags() {
    s32 i;
    s32 no_slot_open;
    WindowTextEntry *slot_entry;
    WindowTextEntry *entry_1;

    no_slot_open = 1;
    i = 0;
    do {
        slot_entry = static_cast<WindowTextEntry *>(get_array_entry(i + 2));
        if (get_slot_flag((s8) i) == 0) {
            slot_entry->flags |= 2;
        } else {
            no_slot_open = 0;
            slot_entry->flags &= 0xFFFFFFFD;
        }
        i += 1;
    } while (i < 6);
    entry_1 = static_cast<WindowTextEntry *>(get_array_entry(1));
    if (no_slot_open != 0) {
        slot = -1;
        entry_1->flags |= 2;
        state_flags |= 4;
        return;
    }
    entry_1->flags &= 0xFFFFFFFD;
    state_flags &= ~4;
}


void TWindowSubQuestBoardSelect::select_next() {
    u8 slot;

    if ((this->is_shortcut_active() == 0) && (get_slot_flag(this->slot) == 0)) {
        do {
            this->slot = (this->slot + 1);
            slot = this->slot;
            if ((s8) slot > 6) {
                this->slot = (slot - 6);
            }
        } while (get_slot_flag(this->slot) == 0);
        update_slot_title();
    }
}

extern "C" {

void draw_selection_leader_line(TWindowSubQuestBoardSelect *self, WindowDrawContext *ctx) {
    ColorLineVertex v[3];
    ColorLineList d;
    u32 colors[3];
    WindowTextEntry *e;
    f32 x;
    f32 y;
    u32 alpha;
    f32 x2;
    f32 y2;
    f32 depth;

    if (ctx->open_tick < 0) {
        return;
    }
    if (self->get_slot_flag(self->slot) == 0) {
        return;
    }
    e = static_cast<WindowTextEntry *>(self->get_array_entry(self->slot + 2));
    draw_selection_corners(ctx, &e->x, 56.0f, 0.3f);
    x = ctx->inner_x + e->x;
    y = ctx->inner_y + e->y;
    if (ctx->open_tick < 6) {
        alpha = (u32)(0.16666667f * (f32)(ctx->open_tick * 255)) << 24;
    } else {
        alpha = 0xFF000000;
    }
    e = static_cast<WindowTextEntry *>(self->get_array_entry(1));
    depth = 0.1794f + ctx->depth;
    d.verts = v;
    d.colors = colors;
    d.tex = NULL;
    d.colors[0] = alpha | 0xFF0000 | 0x7E00;
    d.colors[1] = d.colors[0];
    d.colors[2] = d.colors[0];
    d.count = 3;
    v[0].x = 28.0f + x;
    v[0].y = 7.0f + y;
    x2 = ctx->inner_x + e->x;
    y2 = ctx->inner_y + e->y;
    v[1].x = x2;
    v[1].y = 20.0f + y2;
    v[2].x = x2 + e->width;
    v[2].y = v[1].y;
    draw_color_lines(&d, 3, 0x10, depth);
}

void TWindowSubQuestBoardSelect::handle_cancel() {
    if (is_open() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        state_flags |= 2;
    }
}

void TWindowSubQuestBoardSelect::handle_decide() {
    if (this->is_shortcut_active() == 0) {
        play_sound_effect(0x52D01, 0, 0, 0);
        state_flags |= 1;
    }
}


void TWindowSubQuestBoardSelect::handle_page_input() {
    ControllerInputContext *p;
    s8 d;
    if (this->is_shortcut_active() == 0 &&
        (test_buttons_press_or_repeat((p = &controller_input_state.controllers[0]), 0xC0, 6, 1) != 0 ||
        test_buttons_press_or_repeat(&controller_input_state.keyboard, 0xC0, 6, 1) != 0)) {
        play_sound_effect(0x54100, 0, 0, 0);
        d = 0;
        if (test_buttons_press_or_repeat(p, 0x80, 6, 1) != 0 ||
            test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x80, 6, 1) != 0) {
            d = 1;
        }
        if (test_buttons_press_or_repeat(p, 0x40, 6, 1) != 0 ||
            test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x40, 6, 1) != 0) {
            d--;
        }
        if (d != 0) {
            do {
                this->slot += d;
                if (this->slot < 0) {
                    this->slot += 6;
                }
                if (this->slot >= 6) {
                    this->slot -= 6;
                }
            } while (get_slot_flag(this->slot) == 0);
            this->update_slot_title();
        }
    }
}

void TWindowSubQuestBoardSelect::render() {
    WindowDrawContext *ctx;
    ctx = draw_default_entry();
    draw_window_frame(ctx);
    status_disp->render(ctx);
    draw_selection_leader_line(this, ctx);
    draw_visible_window_entries(
        this,
        &this->entry_list,
        ctx);
}
void TWindowSubQuestBoardSelect::run_task() {
    if (this->is_open() == 0) {
        this->select_next();
        handle_page_input();
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            this->handle_decide();
        }
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            this->handle_cancel();
        }
    }
    update_window();
    if ((f32)this->open_tick >= 7.5f) {
        this->open_tick = 0x186A0;
        this->status_disp->update();
    }
    this->update_fade();
    this->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&this->entry_list));
}

TWindowSubQuestBoardSelect::~TWindowSubQuestBoardSelect() {
    delete status_disp;
}

}
#pragma push
#pragma fp_contract on
TWindowSubQuestBoardSelect::TWindowSubQuestBoardSelect() : TWindowBase((u8 *)&TWindowSubQuestBoardSelect::window_parameters, (s16)(4), (u8 *)(get_window_layout_position(0x70))) {
    f32 title_width;
    WindowTextEntry *entry_0;
    WindowHeading *heading;
    m_name = TWindowSubQuestBoardSelect::class_name;
    heading = new WindowHeading(TWindowSubStatusDisp::get_message_10(0x2B), (s32)((s32) this->client_index));
    this->status_disp = heading;
    state_flags = 0;
    entry_0 = static_cast<WindowTextEntry *>(this->get_array_entry(0));
    set_text_entry_string(entry_0, (TQuestThread::get_quest_name()), 0);
    title_width = (f32) calc_text_width(entry_0->get_text());
    entry_0->x = 210.0f - 0.5f * title_width;
    slot = -1;
    update_slot_display_flags();
    this->select_next();
}

#pragma pop
