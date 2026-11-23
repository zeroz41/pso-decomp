#include "pso/player/GuildCardEntry.h"
#include "pso/ui/window/PageIndicator.h"
#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/window/TWindowMenu.h"


void TWindowSubComCardList::sub_80275360() {
    GuildCardEntry *card;
    s32 n;
    s32 index;
    saddr msg;

    this->reset_entries();
    index = storage->get_type();
    index *= 7;
    for (n = 0; n < 7; n++, index++) {
        if (index >= (s32)this->card_count) {
            break;
        }
        if (this->cards != 0) {
            card = (GuildCardEntry *)(this->cards + index * 0x90);
        } else if (this->card_slots != 0) {
            card = (GuildCardEntry *)(this->card_slots + index * 0x100);
        } else {
            return;
        }
        if (card->is_active() == 0) {
            break;
        }
        this->add_text_entry((saddr)card->get_name(), 7, index);
    }
    if (this->get_field_72() <= 0) {
        switch ((s8)this->empty_message) {
        case 0:
            msg = (saddr)TWindowSubStatusDisp::get_message_10(0xD4);
            break;
        case 1:
            msg = (saddr)TWindowSubStatusDisp::get_message_10(0xD2);
            break;
        }
        add_gray_text_entry((TWindowMenu *)this, (const char *)msg, 4, -1);
    }
}
