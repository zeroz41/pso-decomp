#include "pso/ui/window/MessageWindowSettingsAbi.h"
#include "types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowMessagePage.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TextBuilder.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/network/client_id.h"


#pragma readonly_strings on


const char *TWindowMessagePage::class_name = "TWindowMessagePage";


s32 TWindowMessagePage::is_ready() {
    if ((u32) this->page_text != 0U) {
        return 0;
    }
    return is_message_window_ready() != 0 ? 1 : 0;
}

void TWindowMessagePage::update_message() {
    if ((u32) this->page_text != 0U) {
        text_builder_reset();
        this->page_text = (uaddr)((TWindowSubStatusDisp *)this->page_text)->copy_message_page_text();
        append_line((saddr)get_shared_text_buffer(), this->line_mode);
    }
}

void TWindowMessagePage::set_message(void *msg, s32 flags) {
    while (page_text != 0) {
        update_message();
    }
    line_mode = flags | 2;
    page_text = (uaddr)msg;
    update_message();
}

u8 *TWindowMessagePage::create(const NJS_POINT2 *position, saddr extent, saddr rows, s32 client) {
    set_message_window_size((void *)extent, (u32)rows);
    return (u8 *)new TWindowMessagePage(position, rows, client);
}

u8 *TWindowMessagePage::set_text(const NJS_POINT2 *position, saddr extent, saddr rows) {
    return TWindowMessagePage::create(position, extent, rows, local_client_id);
}

void TWindowMessagePage::render() { { (void)(this->TWindowMessage::render()); return; } }

void TWindowMessagePage::run_task() {
    TWindowMessage::run_task();
    if ((test_pressed_buttons_packed(&controller_input_state.controllers[is_player_input_active((this->client_index))], 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
        if (this->is_message_window_ready() != 0) {
            update_message();
            return;
        }
        this->complete_reveal();
    }
}

TWindowMessagePage::~TWindowMessagePage() {

}

TWindowMessagePage::TWindowMessagePage(const NJS_POINT2 *position, s32 rows, s32 client) : TWindowMessage(position, rows, client) {
    this->m_name = TWindowMessagePage::class_name;
    this->line_mode = 0;
    this->client_index = (s16) client;
    this->page_text = 0;
}
