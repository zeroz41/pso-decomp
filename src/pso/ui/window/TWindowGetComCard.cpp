#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowGetComCard_8007B54C.h"
#include "pso/unk/text_8024AC64.h"
#include "pso/unk/text_8024ACA8.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowGetComCard.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowMessagePage.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowFukidasi.h"

#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ControllerInput.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/unk/text_8024AB98.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowCtrl_8024A1A8.h"

#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowCtrl.h"

const char *TWindowGetComCard::class_name = "TWindowGetComCard";
__declspec(section ".data") NJS_POINT2 TWindowGetComCard::window_rect = {152.0f, 370.0f};

extern "C" {
void TWindowFukidasi__sub_80252C38(void* p) { *(u8*)((char*)p + 0x71) |= 0x4; }
void TWindowFukidasi::clear_visible_flag() { this->m_71 &= 0xfe; }
void TWindowFukidasi::set_flag() { this->m_71 |= 0x1; }
void TWindowFukidasi::set_balloon_visible() { this->m_71 |= 0x20; }
int TWindowFukidasi::is_flag_set() { return this->m_71 & 0x1; }
void TWindowFukidasi::clear_flag_20() { this->m_71 &= 0xffffffdf; }
int TWindowFukidasi::is_active() { return (this->m_71 >> 2) & 0x1; }
void TWindowFukidasi::clear_flag() { this->m_71 &= 0xfffffffb; }
int TWindowFukidasi::is_balloon_visible() { return (this->m_71 >> 5) & 0x1; }
int fn_80252CBC(void* p) { return *(u16*)((char*)p + 0x0) & 0x10; }
}

void TWindowGetComCard::render() {  }

void TWindowGetComCard::run_task() {
    s32 port = is_player_input_active(local_client_id);
    switch (state) {
    case 0:
    case 1:
        if (((TWindowMessagePage *)(message))->is_message_window_ready() != 0) {
            state = 2;
        }
        if (test_pressed_buttons_packed(&controller_input_state.controllers[0], 4) != 0) {
            message->complete_reveal();
            state = 2;
        }
        break;
    case 2:
        if (timer != 0) {
            state = 5;
            break;
        }
        if (confirmation == 0) {
            confirmation = reinterpret_cast<TWindowMenu *>(init_shop_judgment_window(&window_rect));
            ((TWindowSubComCardList *)(confirmation))->set_flag70_bit10();
        }
        confirmation->clear_flag_and_release();
        state = 3;
    case 3:
        if (confirmation->is_cancelled() != 0) {
            TWindowGetComCard__sub_8007B54C();
            queue_destruction();
            state = 6;
        } else if (confirmation->is_decided() != 0) {
            s32 r = confirmation->get_selected_value();
            if (r == 0) {
                state = 4;
            }
            if (r == 1) {
                TWindowGetComCard__sub_8007B54C();
                queue_destruction();
                state = 6;
            }
        }
        break;
    case 4:
        if (TAdPlayerLoadGC::get_instance() == 0) {
            TWindowSubComCard::start_player_data_load((saddr)TWindowGetComCard__sub_8007B594());
            TWindowGetComCard__sub_8007B54C();
            queue_destruction();
            state = 6;
        } else if (test_pressed_buttons_packed(&controller_input_state.controllers[port], 2) != 0 ||
                   test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            state = 2;
        }
        break;
    case 5:
        if (timer-- <= 0 || test_pressed_buttons_packed(&controller_input_state.controllers[0], 4) != 0) {
            TWindowGetComCard__sub_8007B54C();
            queue_destruction();
            state = 6;
        }
        break;
    case 6:
        break;
    }
}

void text_builder_reset(void);
TWindowGetComCard::~TWindowGetComCard() {
    TObjPlayer *player;
    if (confirmation != NULL) {
        confirmation->close();
        confirmation = NULL;
    }
    if (message != NULL) {
        message->close();
        message = NULL;
    }
    TWindowReturnCity__sub_8024ACA8(local_client_id);
    TWindowCtrl::enable_client_main_menu(local_client_id);
    if ((TWindowCtrl__sub_8024A314() == 0) && ((player = get_player_by_client_id(local_client_id)) != NULL)) {
        player->init_parts();
    }
}

TWindowGetComCard::TWindowGetComCard(TObject *parent) : TObject(parent) {
    TObjPlayer *player;
    static const f32 pos[2] = {10.0f, 277.0f};
    static const f32 size[3] = {264.0f, 104.0f, 0.0f};
    m_name = class_name;
    message = reinterpret_cast<TWindowMessage *>(TWindowMessage::create((const NJS_POINT2 *)pos, (const f32 *)size, 1));
    confirmation = NULL;
    if (TWindowSubComCard::init_com_card() != 0) {
        GuildCardEntry *card = TWindowGetComCard__sub_8007B594();
        text_builder_reset();
        text_builder_append(reinterpret_cast<u8 *>(card->get_name()));
        text_builder_append(static_cast<u8 *>(TWindowSubStatusDisp::get_message_10(0x36)));
        message->append_line((saddr) (get_shared_text_buffer()), 2);
        timer = 0;
    } else {
        message->append_line((saddr) (TWindowSubStatusDisp::get_message_10(0x37)), 0);
        timer = 0x384;
    }
    if ((player = get_player_by_client_id(local_client_id)) != NULL) {
        player->reset_equip_slots();
    }
    TWindowCtrl::disable_client_main_menu(local_client_id);
    fn_8024AC64((local_client_id));
    state = 0;
}
