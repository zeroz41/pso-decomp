#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/frontend/TAdYesNoBaseGC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMenu.h"

#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ControllerInput.h"

#include "pso/system/NinjaTypes.h"

extern "C" {
u8 *init_shop_judgment_window(void *p);

void copy_vec2__FPvPv(void *);

#pragma readonly_strings on
const char *TAdYesNoBaseGC__class_name = "TAdYesNoBaseGC";

s32 TAdYesNoBaseGC::sub_8032C0B4() {
    saddr message_window;
    message_window = (saddr)create_message_window_for_size((NJS_POINT2 *)&this->unk_30, (NJS_POINT2 *)&this->unk_38);
    ((TWindowMessage *)message_window)->append_line(vfunc_10(), 1);
    return message_window;
}

s32 TAdYesNoBaseGC::create_menu_window() {
    TAdYesNoBaseGC *arg0 = this;
    NJS_POINT2 pos = {85.0f, 384.0f};
    saddr r = (saddr)init_shop_judgment_window(&pos);
    ((TWindowMenu *)r)->update_layout_height(470.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(r));
    ((TWindowSubComCardList *)r)->set_selected_index((s16)arg0->m_2c);
    return r;
}

void TAdYesNoBaseGC::init_parts(void *arg1, void *arg2) {
    copy_vec2__FPvPv((void *)((char *)this + 48));
    ((void (*)(void *, void *))copy_vec2__FPvPv)((void *)((char *)this + 56), arg2);
}


void TAdYesNoBaseGC::vfunc_11() {
    s32 selected_menu_value;
    s32 temp_r4;

    this->m_20 = (s32) this->m_1c;
    switch (this->m_1c) {
    case 0:
        this->m_40 = sub_8032C0B4();
        this->m_44 = this->create_menu_window();
        this->m_1c = 1;
        break;
    case 1:
        if (((TWindowMenu *)(this->m_44))->is_decided() != 0) {
            selected_menu_value = ((TWindowMenu *)this->m_44)->get_selected_value();
            switch (selected_menu_value) {
            case 0:
                this->vfunc_8();
                this->m_1c = 2;
                this->m_24 = 3;
                break;
            case 1:
                this->vfunc_9();
                this->m_1c = 2;
                this->m_24 = 4;
                break;
            }
        } else if ((test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            this->m_1c = 2;
            this->m_24 = 4;
        }
        break;
    case 2:
        if ((u32) this->m_40 != 0U) {
            ((TWindowBase *)this->m_40)->close();
            this->m_40 = 0U;
        }
        if ((u32) this->m_44 != 0U) {
            ((TWindowBase *)this->m_44)->close();
            this->m_44 = 0U;
        }
        temp_r4 = this->m_28 + 1;
        this->m_28 = temp_r4;
        if ((f32) temp_r4 > 4.5f) {
            this->m_1c = (s32) this->m_24;
        }
        break;
    case 3:
        vfunc_6();
        break;
    case 4:
        vfunc_7();
        break;
    }
    if ((s32) this->m_20 != (s32) this->m_1c) {
        this->m_28 = 0;
    }
}


}
TAdYesNoBaseGC::~TAdYesNoBaseGC() {
    if (*(void **)((s8 *)this + 0x40) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x40)))->queue_destruction(); this->m_40 = 0; }
    if (*(void **)((s8 *)this + 0x44) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x44)))->queue_destruction(); this->m_44 = 0; }
}


TAdYesNoBaseGC::TAdYesNoBaseGC(TObject *parent) : TObject(parent) {
    void *o;
    void *o2;
    m_name = TAdYesNoBaseGC__class_name;
    m_28 = 0;
    *(f32 *)((s8 *)this + 0x30) = 46.0f;
    m_34 = 131.0f;
    *(f32 *)((s8 *)this + 0x38) = 548.0f;
    m_3c = 220.0f;
    m_1c = 0;
    m_24 = 0;
    m_2c = 1;
    m_40 = 0;
    m_44 = 0;
    o = new TAdBackGC(this);
    o2 = new TAdBackTxtGC(this);
}
