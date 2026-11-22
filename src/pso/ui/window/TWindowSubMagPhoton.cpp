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
#include "pso/unk/TUnk_804D1818.h"
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

struct Win_8027C188 { u8 pad[0x64]; s32 pb[3]; void *mag; };

struct Win_8027C13C { u8 pad[0x61]; s8 sel; };

extern "C" {
void draw_action_palette_icon(void *e, s32 a, u16 b);
extern const s8 lbl_805DD678[4] = { 1, 2, 0, 0 };
extern const u8 lbl_805DD67C[4] = { 3, 1, 2, 0 };

void TWindowSubMagPhoton::get_cursor_origin(void *xy) {
    Win_8027C13C *w = (Win_8027C13C *)this;
    void *e = (void *)((TWindowBase *)w)->get_array_entry(lbl_805DD67C[w->sel]);
    ((TWindowSubCustomEquip *)xy)->set_relative_pos(e);
}

void TWindowSubMagPhoton::init_photon_blast_entries() {
    u8 mag[16];
    s32 i;
    ((MagStats *)mag)->init();
    TItemData::deserialize_mag(((Win_8027C188 *)this)->mag, mag);
    for (i = 0; i < 3; i++) {
        s32 blast = ((MagStats *)mag)->get_photon_blast(i);
        ((Win_8027C188 *)this)->pb[lbl_805DD678[i]] = blast;
        void *e = (void *)this->get_array_entry(i + 1);
        if (blast != -1) {
            draw_action_palette_icon(e, 5, blast);
        } else {
            draw_action_palette_icon(e, 0, 0);
        }
    }
}

}

const char *TWindowSubMagPhoton__class_name = "TWindowSubMagPhoton";
#pragma pop

extern s32 lbl_805D63F0;

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
        {6, {14.0f, 19.0f}, {150.0f, 107.0f}, 0.0f, 0.0f, 0.2f, -1, &lbl_805D63F0, 2, 4},
        {6, {64.0f, 51.0f}, {50.0f, 43.0f}, 0.0f, 0.0f, 0.7f, -1, &lbl_805D63F0, 3, 4},
        {6, {108.0f, 25.0f}, {50.0f, 43.0f}, 0.0f, 0.0f, 0.7f, -1, &lbl_805D63F0, 3, 4},
        {6, {20.0f, 77.0f}, {50.0f, 43.0f}, 0.0f, 0.0f, 0.7f, -1, &lbl_805D63F0, 3, 4},
    },
};
WindowDescriptor TWindowSubMagPhoton__layout_descriptor = {
    {186.0f, 160.0f}, 50050.0f, &window_sub_mag_photon_layout_entries, 3,
};

struct Win_8027C4C8 { u8 pad[0x62]; s16 f62; };

extern "C" {
s32 init_photon_blast_entries__19TWindowSubMagPhotonFv(void *, int);
extern s32 __vt__19TWindowSubMagPhoton[];
u8 *TWindowSubMagPhoton__ct(TWindowSubMagPhoton *arg0, saddr arg1, s32 arg2, s32 arg3);
s32 play_sound_effect(s32, s32, s32, s32);
s32 test_buttons_press_or_repeat(void *, int, int, int);
void draw_cursor_sprite__21TWindowSubCustomEquipFPvPvif(void *, void *, int, f32);
}
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
    u8 *window_choice_setting;
    window_choice_setting = (u8 *)&controller_input_state + (is_player_input_active(((s32) this->client_index)) * 0x50) + 0x20;
    if ((test_buttons_press_or_repeat(window_choice_setting, 0xF0, 6, 1) != 0) || (test_buttons_press_or_repeat((void *) ((u8 *)&controller_input_state + 0x160), 0xF0, 6, 1) != 0)) {
        play_sound_effect(0x54100, (s32)(0U), 0, 0);
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat((void *) ((u8 *)&controller_input_state + 0x160), 0x10, 6, 1) != 0)) {
            this->m_61 = (this->m_61 + 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat((void *) ((u8 *)&controller_input_state + 0x160), 0x20, 6, 1) != 0)) {
            this->m_61 = (this->m_61 - 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x80, 6, 1) != 0) || (test_buttons_press_or_repeat((void *) ((u8 *)&controller_input_state + 0x160), 0x80, 6, 1) != 0)) {
            this->m_61 = (this->m_61 + 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x40, 6, 1) != 0) || (test_buttons_press_or_repeat((void *) ((u8 *)&controller_input_state + 0x160), 0x40, 6, 1) != 0)) {
            this->m_61 = (this->m_61 - 1);
        }
        temp_r3 = this->m_61;
        if ((s8) temp_r3 < 0) {
            this->m_61 = (temp_r3 + 3);
        }
        temp_r3_2 = this->m_61;
        if ((s8) temp_r3_2 >= 3) {
            this->m_61 = (temp_r3_2 - 3);
        }
    }
}

void TWindowSubMagPhoton::draw_cursor(void *arg1) {
    u8 sp8[16];
    get_cursor_origin(sp8);
    ((void (*)(f32, void *, void *, int))draw_cursor_sprite__21TWindowSubCustomEquipFPvPvif)(0.8f, arg1, sp8, ((Win_8027C4C8 *)this)->f62);
}

void TWindowSubMagPhoton::render() {
    saddr ctx;
    ctx = reinterpret_cast<saddr>(draw_default_entry());
    draw_window_frame((void *)ctx);
    draw_visible_window_entries(
        this,
        &this->entry_list,
        reinterpret_cast<WindowDrawContext *>(ctx));
    draw_cursor((void *)ctx);
}

void TWindowSubMagPhoton::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r31;
    u8 *context;
    temp_r31 = is_player_input_active(((s32) this->client_index));
    if (((TWindowSubMagPhoton *)arg0)->get_active_flag() == 0) {
        update_selection_input();
        context = (u8 *)&controller_input_state + (temp_r31 * 0x50) + 0x20;
        if ((TWindowShortListCtrl__check_controller_button(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            play_open_sound();
        }
        if ((TWindowShortListCtrl__check_controller_button(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            handle_cancel();
        }
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&this->entry_list));
    this->m_62 = (this->m_62 + 1);
}

TWindowSubMagPhoton::~TWindowSubMagPhoton() {}

u8 *TWindowSubMagPhoton__ct(TWindowSubMagPhoton *window_sub_mag_photon, saddr parent, s32 arg2, s32 arg3) {
    s16 temp_r4;
    __ct__11TWindowBaseFPUcsPUc((void *)window_sub_mag_photon, (u8 *)&TWindowSubMagPhoton__layout_descriptor, arg3, (u8 *)parent);
    *(s32 **)((s8 *)window_sub_mag_photon + 0x18) = __vt__19TWindowSubMagPhoton;
    *(s32 *)((s8 *)window_sub_mag_photon + 0) = (saddr) TWindowSubMagPhoton__class_name;
    copy_vec2(((u8 *)window_sub_mag_photon + 0x30), (void *)parent);
    ((TWindowBase *)window_sub_mag_photon)->save_position();
    window_sub_mag_photon->client_index = arg3;
    window_sub_mag_photon->m_70 = arg2;
    window_sub_mag_photon->m_60 = 0;
    window_sub_mag_photon->m_61 = 1;
    temp_r4 = window_sub_mag_photon->m_62;
    window_sub_mag_photon->m_62 = (temp_r4 + 1);
    init_photon_blast_entries__19TWindowSubMagPhotonFv(window_sub_mag_photon, temp_r4);
    return (u8 *)window_sub_mag_photon;
}
}
