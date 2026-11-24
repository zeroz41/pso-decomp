#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubAreaMap.h"
#include "pso/ui/window/TWindowMainMenu.h"

#include "pso/ui/window/TWindowSubAreaMapDisp.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

extern "C" {

void TWindowSubAreaMap::render() {  }


void TWindowSubAreaMap::run_task() {
    if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
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

void TWindowSubAreaMapDisp::update_manual_scroll() {
    ControllerInputContext *temp_r31;
    if ((s32) this->m_6c != 0) {
        temp_r31 = &controller_input_state.controllers[0];
        if ((test_previous_buttons_packed(temp_r31, 0x10) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x10) != 0)) {
            this->m_64 += 6.0f;
        }
        if ((test_previous_buttons_packed(temp_r31, 0x20) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x20) != 0)) {
            this->m_64 -= 6.0f;
        }
        if ((test_previous_buttons_packed(temp_r31, 0x40) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x40) != 0)) {
            *(f32 *)&this->unk_60 += 6.0f;
        }
        if ((test_previous_buttons_packed(temp_r31, 0x80) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x80) != 0)) {
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
