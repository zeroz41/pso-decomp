#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/render/ColorLineList.h"
#include "pso/unk/TUnk_804C8678.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/ControllerInputState.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubQuestBoard.h"
#include "pso/ui/window/TWindowSubQuestBoardSelect.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/WindowLayout.h"

#pragma push
#pragma readonly_strings on
const char *TWindowSubQuestBoardSelect__class_name = "TWindowSubQuestBoardSelect";
#pragma pop

struct Ctx_8027D444 {
    u8 pad0[0x10];
    f32 x;
    f32 y;
    u8 pad18[0x30 - 0x18];
    s32 fade;
    u8 pad34[0x38 - 0x34];
    f32 depth;
};

struct Entry_8027D444 {
    u8 pad0[0x8];
    f32 x;
    f32 y;
    f32 w;
};

struct Ent_8027D6A0 { u8 pad0[0x20]; u8 f20[0x30]; };



// inferred: window_sub_quest_board_select_layout_entries, the layout table
// TWindowSubQuestBoardSelect__window_parameters points at (two text entries, six slot sprites).
struct SubQuestBoardSelectWindowLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord text[2];
    SpritePartLayoutRecord slot[6];
};
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
WindowDescriptor TWindowSubQuestBoardSelect__window_parameters = {
    {434.0f, 184.0f}, 50150.0f, &window_sub_quest_board_select_layout_entries, 3,
};



extern "C" {
void measure_message_text_width(void *, f32);
extern u8 quest_board_handlers[];

void TWindowSubQuestBoardSelect::sub_8027D230() {
    u8 *arg0 = (u8 *)this;
    u8 *str;
    u8 *temp_r3;
    str = (u8 *)&quest_board_handlers + ((s8) this->slot * 0x24);
    temp_r3 = (u8 *)(((TWindowBase *)arg0)->get_array_entry(1));
    set_text_entry_string((u8 *)temp_r3, (uaddr)str, 0);
    measure_message_text_width(temp_r3, 100000.0f);
    *(f32 *)((s8 *)temp_r3 + 8) = (f32) (385.0f - *(f32 *)((s8 *)temp_r3 + 0x10));
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
    s32 var_r29;
    u16 *temp_r31;
    u16 *array_entry;

    var_r29 = 1;
    i = 0;
    do {
        temp_r31 = (u16 *)get_array_entry(i + 2);
        if (get_slot_flag((s8) i) == 0) {
            *temp_r31 |= 2;
        } else {
            var_r29 = 0;
            *temp_r31 &= 0xFFFFFFFD;
        }
        i += 1;
    } while (i < 6);
    array_entry = (u16 *)get_array_entry(1);
    if (var_r29 != 0) {
        *(s8 *)&this->slot = -1;
        *array_entry |= 2;
        this->m_60 = (u8) (this->m_60 | 4);
        return;
    }
    *array_entry &= 0xFFFFFFFD;
    this->m_60 = (u8) (this->m_60 & 0xFFFFFFFB);
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
        sub_8027D230();
    }
}

void TWindowSubSymbolChatFaceType__sub_80283C84(void *, void *, f32, f32);

void TWindowSubQuestBoardSelect__sub_8027D444(TWindowSubQuestBoardSelect *self, Ctx_8027D444 *ctx) {
    ColorLineVertex v[3];
    ColorLineList d;
    u32 colors[3];
    Entry_8027D444 *e;
    f32 x;
    f32 y;
    u32 alpha;
    f32 x2;
    f32 y2;
    f32 depth;

    if (ctx->fade < 0) {
        return;
    }
    if (self->get_slot_flag(self->slot) == 0) {
        return;
    }
    e = (Entry_8027D444 *)self->get_array_entry(self->slot + 2);
    TWindowSubSymbolChatFaceType__sub_80283C84(ctx, &e->x, 56.0f, 0.3f);
    x = ctx->x + e->x;
    y = ctx->y + e->y;
    if (ctx->fade < 6) {
        alpha = (u32)(0.16666667f * (f32)(ctx->fade * 255)) << 24;
    } else {
        alpha = 0xFF000000;
    }
    e = (Entry_8027D444 *)self->get_array_entry(1);
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
    x2 = ctx->x + e->x;
    y2 = ctx->y + e->y;
    v[1].x = x2;
    v[1].y = 20.0f + y2;
    v[2].x = x2 + e->w;
    v[2].y = v[1].y;
    draw_color_lines(&d, 3, 0x10, depth);
}

void play_sound_effect(s32, s32, s32, s32);

void TWindowSubQuestBoardSelect::handle_cancel() {
    if (is_open() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->m_60 = (u8) (this->m_60 | 2);
    }
}

void TWindowSubQuestBoardSelect::handle_decide() {
    if (this->is_shortcut_active() == 0) {
        play_sound_effect(0x52D01, 0, 0, 0);
        this->m_60 = (u8) (this->m_60 | 1);
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
            this->sub_8027D230();
        }
    }
}

void TWindowSubQuestBoardSelect::render() {
    saddr ctx;
    ctx = reinterpret_cast<saddr>(draw_default_entry());
    draw_window_frame((void *)ctx);
    m_64->forward_render((void *)ctx);
    TWindowSubQuestBoardSelect__sub_8027D444(this, (Ctx_8027D444 *)ctx);
    draw_visible_window_entries(
        this,
        &this->entry_list,
        reinterpret_cast<WindowDrawContext *>(ctx));
}
void TWindowSubQuestBoardSelect::run_task() {
    u8 *arg0 = (u8 *)this;
    if (((TWindowSubQuestBoardSelect *)arg0)->is_open() == 0) {
        ((TWindowSubQuestBoardSelect *)arg0)->select_next();
        handle_page_input();
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            ((TWindowSubQuestBoardSelect *)arg0)->handle_decide();
        }
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            ((TWindowSubQuestBoardSelect *)arg0)->handle_cancel();
        }
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    if ((f32) *(s32 *)&this->open_tick >= 7.5f) {
        *(s32 *)&this->open_tick = 0x186A0;
        this->m_64->update_subwindow();
    }
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&this->entry_list));
}

TWindowSubQuestBoardSelect::~TWindowSubQuestBoardSelect() {
    TWindowSubStatusDisp::destroy_status_display((saddr)(*(void **)((s8 *)this + 0x64)), (s16)1);
}

u32 calc_text_width();
s32 update_slot_display_flags__26TWindowSubQuestBoardSelectFv(void *, f32, f32);
#pragma push
#pragma fp_contract on
TWindowSubQuestBoardSelect::TWindowSubQuestBoardSelect() : TWindowBase((u8 *)&TWindowSubQuestBoardSelect__window_parameters, (s16)(4), (u8 *)(get_window_layout_position(0x70))) {
    f32 temp_f2;
    saddr temp_r30;
    saddr var_r30;
    m_name = TWindowSubQuestBoardSelect__class_name;
    var_r30 = (saddr)::operator new(0x24);
    if (var_r30 != 0) {
        var_r30 = (saddr)((TWindowSubStatusDisp *)var_r30)->construct_type1_heading((saddr)TWindowSubStatusDisp::get_message_10(0x2B), (s32)((s32) this->client_index));
    }
    this->m_64 = (TWindowSubStatusDisp *)var_r30;
    *(s8 *)&this->m_60 = 0;
    temp_r30 = reinterpret_cast<saddr>(((TWindowBase *)this)->get_array_entry(0));
    set_text_entry_string((u8 *)temp_r30, (uaddr)(TQuestThread::get_quest_name()), 0);
    ((TWindowSubComCard *)temp_r30)->get_field_20();
    temp_f2 = (f32) calc_text_width();
    *(f32 *)((s8 *)temp_r30 + 8) = 210.0f - 0.5f * temp_f2;
    *(s8 *)&this->slot = -1;
    update_slot_display_flags__26TWindowSubQuestBoardSelectFv(this, 0.5f, temp_f2);
    this->select_next();
}

#pragma pop

}
