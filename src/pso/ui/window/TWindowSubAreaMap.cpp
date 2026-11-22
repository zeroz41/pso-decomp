#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubAreaMap.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"

#include "pso/ui/window/TWindowSubAreaMapDisp.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

struct RecoveredGlobal_80271480_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_802715F0_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

extern "C" {
s32 play_sound_effect(int, int, int, int);
extern RecoveredGlobal_80271480_lbl_8050E208 controller_input_state;

void TWindowSubAreaMap::render() {  }


LAYOUT_ASSERT(RecoveredGlobal_80271480_lbl_8050E208_size, sizeof(RecoveredGlobal_80271480_lbl_8050E208) == 0x1B0);
void TWindowSubAreaMap::run_task() {
    if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)&controller_input_state.value + 0x20), 2) != 0) || (test_controller_flag_4c_color((void *) ((u8 *)&controller_input_state.value + 0x160), 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        parent_menu->on_submenu_closed();
    }
}

}
TWindowSubAreaMap::~TWindowSubAreaMap() {
    if (map_disp != NULL) { map_disp->close(); map_disp = NULL; }
}
const char *TWindowSubAreaMap__name = "TWindowSubAreaMap";
TWindowSubAreaMap::TWindowSubAreaMap(TObject *object, void *arg2) : TObject(object) {
    this->m_name = TWindowSubAreaMap__name;
    parent_menu = static_cast<TWindowMainMenu *>(object);
    *(void **)((s8 *)this + 0x1C) = arg2;
    map_disp = new TWindowSubAreaMapDisp();
}

LAYOUT_ASSERT(RecoveredGlobal_802715F0_lbl_8050E208_size, sizeof(RecoveredGlobal_802715F0_lbl_8050E208) == 0x1B0);
void TWindowSubAreaMapDisp::update_manual_scroll() {
    u8 *temp_r31;
    if ((s32) this->m_6c != 0) {
        temp_r31 = (u8 *)&(*(RecoveredGlobal_802715F0_lbl_8050E208 *)&controller_input_state).value + 0x20;
        if ((test_previous_buttons_packed(temp_r31, 0x10) != 0) || (test_previous_buttons_color((void *) ((u8 *)&(*(RecoveredGlobal_802715F0_lbl_8050E208 *)&controller_input_state).value + 0x160), 0x10) != 0)) {
            this->m_64 += 6.0f;
        }
        if ((test_previous_buttons_packed(temp_r31, 0x20) != 0) || (test_previous_buttons_color((void *) ((u8 *)&(*(RecoveredGlobal_802715F0_lbl_8050E208 *)&controller_input_state).value + 0x160), 0x20) != 0)) {
            this->m_64 -= 6.0f;
        }
        if ((test_previous_buttons_packed(temp_r31, 0x40) != 0) || (test_previous_buttons_color((void *) ((u8 *)&(*(RecoveredGlobal_802715F0_lbl_8050E208 *)&controller_input_state).value + 0x160), 0x40) != 0)) {
            *(f32 *)&this->unk_60 += 6.0f;
        }
        if ((test_previous_buttons_packed(temp_r31, 0x80) != 0) || (test_previous_buttons_color((void *) ((u8 *)&(*(RecoveredGlobal_802715F0_lbl_8050E208 *)&controller_input_state).value + 0x160), 0x80) != 0)) {
            *(f32 *)&this->unk_60 -= 6.0f;
        }
        if (test_previous_buttons_packed(temp_r31, 0x20000) != 0) {
            *(f32 *)&this->unk_68 -= 6.0f;
        }
        if (test_previous_buttons_packed(temp_r31, 0x10000) != 0) {
            *(f32 *)&this->unk_68 += 6.0f;
        }
        TRaderMapCore::pan_horizontal((f32) (*(f32 *)&this->unk_60));
        TRaderMapCore::pan_vertical(this->m_64);
        TRaderMapCore::add_zoom_distance((f32) (*(f32 *)&this->unk_68));
        *(f32 *)&this->unk_60 *= 0.8f;
        this->m_64 *= 0.8f;
        *(f32 *)&this->unk_68 *= 0.8f;
    }
}
