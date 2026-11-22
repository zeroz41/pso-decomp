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

#pragma readonly_strings on

extern "C" {
s32 get_entity_id(void *);

void TShopWindowBase::vfunc_11() {  }


f32 TShopWindowBase::get_scale() {
    if ((TRaderMapCore::is_not_split_screen() == 1) && (TCameraCtrl::get_view_count() > 2)) {
        return 0.75f;
    }
    return 1.0f;
}

s32 TShopWindowBase::sub_8022397C() {
    u8 *arg0 = (u8 *)this;
    uaddr temp_r3;
    temp_r3 = *(u32 *)((s8 *)arg0 + 0x24);
    if (temp_r3 != 0U) {
        return (u16)TShopGenerator__sub_80222DAC((get_entity_id((void *)temp_r3)));
    }
    return 0U;
}

s32 TShopSequence::get_child_field1c() {
    void *temp_r3 = this->player;
    if (temp_r3 != NULL) {
        return get_entity_id(temp_r3);
    }
    return 0;
}

extern s32 lbl_805D55C0;

s32 TShopWindowBase::sub_802239EC() {
    if (*(s32 *)((s8 *)((u8 *)&controller_input_state + (((TObjPlayer *)(*(saddr *)((s8 *)((u8 *)this) + 0x24)))->get_controller_port() * 0x50)) + 0x28) & 2) {
        return 1;
    }
    return test_controller_flag_4c_color(&controller_input_state.keyboard, 2) ? 1 : 0;
}

s32 TShopWindowBase::sub_80223A48() {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)((u8 *)&controller_input_state + (((TObjPlayer *)(*(saddr *)((s8 *)arg0 + 0x24)))->get_controller_port() * 0x50)) + 0x28) & 4) {
        return 1;
    }
    if (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0) {
        return 1;
    }
    return 0;
}

void TShopWindowBase::run_task() {
    if ((s32) lbl_805D55C0 == 0) {
        this->vfunc_11();
    }
}

const char *TShopWindowBase__class_name = "TShopWindowBase";

}
TShopWindowBase::~TShopWindowBase() {

}


TShopWindowBase::TShopWindowBase(TObject *parent) : TObject(parent) {
    m_name = TShopWindowBase__class_name;
    *(u32 *)((s8 *)this + 0x1C) = 0;
    *(u32 *)((s8 *)this + 0x20) = 0;
    *(u32 *)((s8 *)this + 0x24) = 0;
}

