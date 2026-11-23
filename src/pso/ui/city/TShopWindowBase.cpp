#include "pso/ui/city/TShopWindowBase.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_80222C28.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/city/TShopSequence.h"

#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/ControllerInput.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on

void TShopWindowBase::update_state() {  }


f32 TShopWindowBase::get_scale() {
    if ((TRaderMapCore::is_not_split_screen() == 1) && (TCameraCtrl::get_view_count() > 2)) {
        return 0.75f;
    }
    return 1.0f;
}

s32 TShopWindowBase::get_split_screen_slot() {
    if (player != NULL) {
        return (u16)get_client_split_screen_slot(player->get_entity_id());
    }
    return 0U;
}

u16 TShopWindowBase::get_player_entity_id() {
    if (player != NULL) {
        return player->get_entity_id();
    }
    return 0;
}

extern "C" s32 lbl_805D55C0;

s32 TShopWindowBase::is_cancel_pressed() {
    if (controller_input_state.controllers[player->get_controller_port()].pressed_buttons & 2) {
        return 1;
    }
    return test_controller_flag_4c_color(&controller_input_state.keyboard, 2) ? 1 : 0;
}

s32 TShopWindowBase::is_decide_pressed() {
    if (controller_input_state.controllers[player->get_controller_port()].pressed_buttons & 4) {
        return 1;
    }
    if (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0) {
        return 1;
    }
    return 0;
}

void TShopWindowBase::run_task() {
    if ((s32) lbl_805D55C0 == 0) {
        this->update_state();
    }
}

const char *TShopWindowBase__class_name = "TShopWindowBase";
TShopWindowBase::~TShopWindowBase() {

}


TShopWindowBase::TShopWindowBase(TObject *parent) : TObject(parent) {
    m_name = TShopWindowBase__class_name;
    pad_1C = 0;
    state = 0;
    player = NULL;
}

