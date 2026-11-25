#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/vector.h"
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
#include "pso/ui/window/TWindowSubComCard_80265410.h"

#pragma readonly_strings on
const char *TAdYesNoBaseGC::class_name = "TAdYesNoBaseGC";

s32 TAdYesNoBaseGC::create_message_window() {
    saddr window;
    window = (saddr)create_message_window_for_size(&this->message_position, &this->message_size);
    ((TWindowMessage *)window)->append_line(get_message_text(), 1);
    return window;
}

s32 TAdYesNoBaseGC::create_menu_window() {
    TAdYesNoBaseGC *owner = this;
    NJS_POINT2 pos = {85.0f, 384.0f};
    TWindowMenu *menu = init_shop_judgment_window(&pos);
    menu->update_layout_height(470.0f);
    align_menu_entry_positions(menu);
    menu->set_selected_index((s16)owner->default_choice);
    return (saddr)menu;
}

void TAdYesNoBaseGC::init_parts(void *position, void *size) {
    copy_vec2(&message_position, position);
    copy_vec2(&message_size, size);
}


void TAdYesNoBaseGC::run_dialog() {
    s32 selected_menu_value;
    s32 timer;

    this->prev_state = (s32) this->state;
    switch (this->state) {
    case 0:
        this->message_window = create_message_window();
        this->menu_window = this->create_menu_window();
        this->state = 1;
        break;
    case 1:
        if (((TWindowMenu *)(this->menu_window))->is_decided() != 0) {
            selected_menu_value = ((TWindowMenu *)this->menu_window)->get_selected_value();
            switch (selected_menu_value) {
            case 0:
                this->on_yes_chosen();
                this->state = 2;
                this->exit_state = 3;
                break;
            case 1:
                this->on_no_chosen();
                this->state = 2;
                this->exit_state = 4;
                break;
            }
        } else if ((test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            this->state = 2;
            this->exit_state = 4;
        }
        break;
    case 2:
        if ((u32) this->message_window != 0U) {
            ((TWindowBase *)this->message_window)->close();
            this->message_window = 0U;
        }
        if ((u32) this->menu_window != 0U) {
            ((TWindowBase *)this->menu_window)->close();
            this->menu_window = 0U;
        }
        timer = this->state_frames + 1;
        this->state_frames = timer;
        if ((f32) timer > 4.5f) {
            this->state = (s32) this->exit_state;
        }
        break;
    case 3:
        on_accept();
        break;
    case 4:
        on_cancel();
        break;
    }
    if ((s32) this->prev_state != (s32) this->state) {
        this->state_frames = 0;
    }
}
TAdYesNoBaseGC::~TAdYesNoBaseGC() {
    if (message_window != 0) {
        ((TObject *)message_window)->queue_destruction();
        message_window = 0;
    }
    if (menu_window != 0) {
        ((TObject *)menu_window)->queue_destruction();
        menu_window = 0;
    }
}


TAdYesNoBaseGC::TAdYesNoBaseGC(TObject *parent) : TObject(parent) {
    void *o;
    void *o2;
    m_name = TAdYesNoBaseGC::class_name;
    state_frames = 0;
    message_position.x = 46.0f;
    message_position.y = 131.0f;
    message_size.x = 548.0f;
    message_size.y = 220.0f;
    state = 0;
    exit_state = 0;
    default_choice = 1;
    message_window = 0;
    menu_window = 0;
    o = new TAdBackGC(this);
    o2 = new TAdBackTxtGC(this);
}
