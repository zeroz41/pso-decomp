#include "pso/ui/window/MessageWindowSettingsAbi.h"
#include "types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowMessagePage.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/TLobby_8001D6A0.h"


#pragma readonly_strings on


const char *TWindowMessagePage__name = "TWindowMessagePage";


struct Page_8026AE20 { u8 pad[0x90]; s32 flags; void *msg; };

extern "C" {

s32 TWindowMessagePage::is_ready() {
    if ((u32) this->m_94 != 0U) {
        return 0;
    }
    return is_message_window_ready() != 0 ? 1 : 0;
}

void TWindowMessagePage::update_message() {
    if ((u32) this->m_94 != 0U) {
        text_builder_reset();
        this->m_94 = (uaddr)((TWindowSubStatusDisp *)this->m_94)->copy_message_page_text();
        append_line((saddr)get_shared_text_buffer(), *(s32 *)((s8 *)this + 0x90));
    }
}

extern s32 local_client_id;

void TWindowMessagePage::set_message(void *msg, s32 flags) {
    Page_8026AE20 *self = (Page_8026AE20 *)this;
    while (self->msg != NULL) {
        update_message();
    }
    self->flags = flags | 2;
    self->msg = msg;
    update_message();
}

u8 *TWindowMessagePage::create(s32 parent, saddr extent, saddr rows, s32 client) {
    TLobby__sub_80269DA4((void *)extent, (u32)rows);
    return (u8 *)new TWindowMessagePage(parent, rows, client);
}

u8 *TWindowMessagePage::set_text(s32 a, s32 b, s32 c) {
    return TWindowMessagePage::create(a, b, c, local_client_id);
}

void TWindowMessagePage::render() { { (void)(this->TWindowMessage::render()); return; } }

void TWindowMessagePage::run_task() {
    u8 *arg0 = (u8 *)this;
    TWindowMessage::run_task();
    if ((test_pressed_buttons_packed(&controller_input_state.controllers[is_player_input_active((this->client_index))], 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
        if (((TWindowMessagePage *)arg0)->is_message_window_ready() != 0) {
            update_message();
            return;
        }
        ((TWindowMessage *)arg0)->complete_reveal();
    }
}

}
TWindowMessagePage::~TWindowMessagePage() {

}

TWindowMessagePage::TWindowMessagePage(s32 parent, s32 rows, s32 client) : TWindowMessage(parent, rows, client) {
    this->m_name = TWindowMessagePage__name;
    *(s32 *)((s8 *)this + 0x90) = 0;
    this->client_index = (s16) client;
    this->m_94 = 0;
}
