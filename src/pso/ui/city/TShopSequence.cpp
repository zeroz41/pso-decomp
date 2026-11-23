#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TMessageWindowController.h"
#include "pso/camera/TCameraConversation.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_8022350C.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

#pragma readonly_strings on


extern "C" {
const char *TShopSequence__class_name = "TShopSequence";

// Conversation camera per service counter; the alternate set is used while a TLobby runs.
static const s32 service_counter_camera_table[7] = {6, 5, 3, 0, 2, 1, 4};
static const s32 service_counter_camera_alt_table[7] = {16, 15, 13, 10, 12, 11, 14};

TCameraConversation *set_service_counter_camera(void *sequence, s32 counter) {
    if (TLobby::get_instance() == 0) {
        return create_conversation_camera(service_counter_camera_table[counter]);
    }
    return create_conversation_camera(service_counter_camera_alt_table[counter]);
}

s32 is_split_screen();

int TShopSequence::is_message_ready() {
    if (message_window != NULL) {
        return message_window->is_ready();
    }
    return 1;
}

void TShopSequence::close_message_window() {
    if (message_window != NULL) {
        message_window->close();
        delete message_window;
        message_window = NULL;
    }
}

u32 TShopSequence::create_message_window(s32 x, s32 y) {
    if (message_window != NULL) {
        if (player != NULL) {
            return (uaddr)message_window->create_message_window(x, y, (u16)((TObjBase *)((uaddr)player))->get_entity_id());
        }
        return (uaddr)message_window->create_window(x, y);
    }
    return 0;
}

void TShopSequence::display_guild_message(s32 index, s32 flags) {
    if (message_window != NULL) {
        message_window->format_guild_message(index, flags);
    }
}

void TShopSequence::send_message(s32 id, s32 flags) {
    if (message_window != NULL) {
        message_window->send_message(id, flags);
    }
}

void TShopSequence::display_message(const char *text, s32 flags) {
    if (message_window != NULL) {
        message_window->display_message(text, flags);
    }
}

void TShopSequence::display_shop_message(s32 id, s32 flags) {
    if (message_window != NULL) {
        message_window->format_shop_message(id, flags);
    }
}

void TShopSequence::close_if_single_screen() {
    if ((TAdSinglePlyChrSelectGC::get_game_mode() != 0) && (is_split_screen() == 0)) {
        TAdSinglePlyChrSelectGC::load_character_from_card(0);
    }
}
void TShopSequence::close_window() {
    s32 client;

    if (player != NULL) {
        TWindowCtrl::unsuppress_slot((u16)player->get_entity_id());
        if (TRaderMapCore::is_not_split_screen() != 1) {
            client = 0;
            do {
                TObjPlayer *other = (TObjPlayer *)get_player_by_client_id(client);
                if (other != NULL) {
                    other->activate_body_collision();
                }
                client += 1;
            } while (client < 4);
        }
        TObjPlayer::clear_lobby_flag(player);
    }
}
void TShopSequence::restore_player_state() {
    s32 client;

    if (player != NULL) {
        player->init_effect_5f0();
        if (TRaderMapCore::is_not_split_screen() != 1) {
            client = 0;
            do {
                TObjPlayer *other = (TObjPlayer *)get_player_by_client_id(client);
                if (other != NULL) {
                    other->deactivate_body_collision();
                }
                client += 1;
            } while (client < 4);
        }
        TWindowCtrl::suppress_slot((u16)player->get_entity_id());
    }
}
TShopSequence::~TShopSequence() {
    if (message_window != NULL) {
        delete message_window;
        message_window = NULL;
    }
}

}

TShopSequence::TShopSequence(TObject *parent) : TShopWindowBase(parent) {
    m_name = TShopSequence__class_name;
    message_window = new TMessageWindowController();
}
