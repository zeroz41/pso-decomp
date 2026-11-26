#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubAreaMap.h"
#include "pso/ui/window/TWindowMainMenu.h"

#include "pso/ui/window/TWindowSubAreaMapDisp.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"
#include "pso/system/SoundEffect.h"

#pragma readonly_strings on


void TWindowSubAreaMap::render() {  }


void TWindowSubAreaMap::run_task() {
    if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        parent_menu->on_submenu_closed();
    }
}

TWindowSubAreaMap::~TWindowSubAreaMap() {
    if (map_disp != NULL) { map_disp->close(); map_disp = NULL; }
}
const char *TWindowSubAreaMap::class_name = "TWindowSubAreaMap";
TWindowSubAreaMap::TWindowSubAreaMap(TObject *parent, s32 client) : TObject(parent) {
    this->m_name = TWindowSubAreaMap::class_name;
    parent_menu = static_cast<TWindowMainMenu *>(parent);
    this->client = client;
    map_disp = new TWindowSubAreaMapDisp();
}

void TWindowSubAreaMapDisp::update_manual_scroll() {
    ControllerInputContext *temp_r31;
    if ((s32) this->map_open != 0) {
        temp_r31 = &controller_input_state.controllers[0];
        if ((test_previous_buttons_packed(temp_r31, 0x10) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x10) != 0)) {
            this->pan_y += 6.0f;
        }
        if ((test_previous_buttons_packed(temp_r31, 0x20) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x20) != 0)) {
            this->pan_y -= 6.0f;
        }
        if ((test_previous_buttons_packed(temp_r31, 0x40) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x40) != 0)) {
            this->pan_x += 6.0f;
        }
        if ((test_previous_buttons_packed(temp_r31, 0x80) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x80) != 0)) {
            this->pan_x -= 6.0f;
        }
        if (test_previous_buttons_packed(temp_r31, 0x20000) != 0) {
            this->zoom -= 6.0f;
        }
        if (test_previous_buttons_packed(temp_r31, 0x10000) != 0) {
            this->zoom += 6.0f;
        }
        TRaderMapCore::pan_horizontal(this->pan_x);
        TRaderMapCore::pan_vertical(this->pan_y);
        TRaderMapCore::add_zoom_distance(this->zoom);
        this->pan_x *= 0.8f;
        this->pan_y *= 0.8f;
        this->zoom *= 0.8f;
    }
}
