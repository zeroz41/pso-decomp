#include "pso/system/SoundEffect.h"
#include "pso/ui/window/WindowSpritePart.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/item/MagStats.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "types.h"
#include "pso/ui/window/TWindowSubMagPhoton.h"
#include "pso/item/TItemData.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/ui/window/TWindowSubCustomEquip.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/system/PadRumble.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowSubStatusDisp_80248BE8.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/ui/window/TWindowSubOption.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowSubQuestBoard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/vector.h"
#pragma push
#pragma readonly_strings on

extern "C" {
void draw_action_palette_icon(void *e, s32 a, u16 b);
extern const s8 lbl_805DD678[4] = { 1, 2, 0, 0 };
extern const u8 lbl_805DD67C[4] = { 3, 1, 2, 0 };

void TWindowSubMagPhoton::get_cursor_origin(NJS_POINT2 *position) {
    WindowSpritePart *entry = static_cast<WindowSpritePart *>(get_array_entry(lbl_805DD67C[static_cast<s8>(selected_blast_index)]));
    set_relative_pos(position, entry);
}

void TWindowSubMagPhoton::init_photon_blast_entries() {
    MagStats stats;
    s32 i;
    stats.init();
    TItemData::deserialize_mag(mag_item, &stats);
    for (i = 0; i < 3; i++) {
        s32 blast = stats.get_photon_blast(i);
        photon_blasts[lbl_805DD678[i]] = blast;
        void *e = (void *)this->get_array_entry(i + 1);
        if (blast != -1) {
            draw_action_palette_icon(e, 5, blast);
        } else {
            draw_action_palette_icon(e, 0, 0);
        }
    }
}

}

const char *TWindowSubMagPhoton::class_name = "TWindowSubMagPhoton";
#pragma pop


// inferred: window_sub_mag_photon_layout_entries, the layout table
// TWindowSubMagPhoton__layout_descriptor points at (a frame sprite and three photon blast icons).
struct SubMagPhotonWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec[4];
};
SubMagPhotonWindowLayout window_sub_mag_photon_layout_entries = {
    4, 1,
    {
        {6, {14.0f, 19.0f}, {150.0f, 107.0f}, 0.0f, 0.0f, 0.2f, -1, &hud_texlist, 2, 4},
        {6, {64.0f, 51.0f}, {50.0f, 43.0f}, 0.0f, 0.0f, 0.7f, -1, &hud_texlist, 3, 4},
        {6, {108.0f, 25.0f}, {50.0f, 43.0f}, 0.0f, 0.0f, 0.7f, -1, &hud_texlist, 3, 4},
        {6, {20.0f, 77.0f}, {50.0f, 43.0f}, 0.0f, 0.0f, 0.7f, -1, &hud_texlist, 3, 4},
    },
};
WindowDescriptor TWindowSubMagPhoton__layout_descriptor = {
    {186.0f, 160.0f}, 50050.0f, &window_sub_mag_photon_layout_entries, 3,
};

extern "C" {

void TWindowSubMagPhoton::handle_cancel() {
    if (get_active_flag() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->m_60 = (u8) (this->m_60 | 2);
    }
}

void TWindowSubMagPhoton::play_open_sound() {
    play_sound_effect(0x52D01, 0, 0, 0);
    this->m_60 = (u8) (this->m_60 | 1);
}

void TWindowSubMagPhoton::update_selection_input() {
    u8 temp_r3;
    u8 temp_r3_2;
    ControllerInputContext *window_choice_setting;
    window_choice_setting = &controller_input_state.controllers[is_player_input_active(((s32) this->client_index))];
    if ((test_buttons_press_or_repeat(window_choice_setting, 0xF0, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0xF0, 6, 1) != 0)) {
        play_sound_effect(0x54100, NULL, 0, 0);
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
            this->selected_blast_index = (this->selected_blast_index + 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
            this->selected_blast_index = (this->selected_blast_index - 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x80, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x80, 6, 1) != 0)) {
            this->selected_blast_index = (this->selected_blast_index + 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x40, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x40, 6, 1) != 0)) {
            this->selected_blast_index = (this->selected_blast_index - 1);
        }
        temp_r3 = this->selected_blast_index;
        if ((s8) temp_r3 < 0) {
            this->selected_blast_index = (temp_r3 + 3);
        }
        temp_r3_2 = this->selected_blast_index;
        if ((s8) temp_r3_2 >= 3) {
            this->selected_blast_index = (temp_r3_2 - 3);
        }
    }
}

void TWindowSubMagPhoton::draw_cursor(WindowDrawContext *context) {
    NJS_POINT2 position;
    get_cursor_origin(&position);
    TWindowSubCustomEquip::draw_cursor_sprite(0.8f, context, &position, cursor_frame);
}

void TWindowSubMagPhoton::render() {
    WindowDrawContext *ctx;
    ctx = draw_default_entry();
    draw_window_frame(ctx);
    draw_visible_window_entries(
        this,
        &this->entry_list,
        ctx);
    draw_cursor(ctx);
}

void TWindowSubMagPhoton::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r31;
    ControllerInputContext *context;
    temp_r31 = is_player_input_active(((s32) this->client_index));
    if (((TWindowSubMagPhoton *)arg0)->get_active_flag() == 0) {
        update_selection_input();
        context = &controller_input_state.controllers[temp_r31];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            play_open_sound();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            handle_cancel();
        }
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&this->entry_list));
    this->cursor_frame = (this->cursor_frame + 1);
}

TWindowSubMagPhoton::~TWindowSubMagPhoton() {}

TWindowSubMagPhoton::TWindowSubMagPhoton(const NJS_POINT2 *position, TItemData *mag_state, s32 client)
    : TWindowBase((u8 *)&TWindowSubMagPhoton__layout_descriptor, client, (u8 *)position) {
    m_name = class_name;
    copy_vec2(target_position, const_cast<NJS_POINT2 *>(position));
    save_position();
    client_index = client;
    mag_item = mag_state;
    m_60 = 0;
    selected_blast_index = 1;
    cursor_frame++;
    init_photon_blast_entries();
}
}
