#include "pso/player/TPlyGuildCardTag.h"
#include "pso/player/TPlyGuildCardTag_8007B7EC.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/chat/ShortMail.h"

#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"

void TPlyGuildCardTag::bswap() {
    bswap_32(&m_guildcard_number);
    bswap_16(&m_tag2);
}


void TWindowSubShortMail__sub_8007B824(void) {
    lbl_805D63FC |= 2;
}

s32 ShortMailEntry::get_sender_card_id() { return sender_card_id; }

char *ShortMailEntry::get_sender_name() { return sender_name; }

s32 TPlyPhotonChair::get_actor_section_id() {
    s8 id = *((s8 *)this + 0x88C);
    return id;
}

const char *TObjPlayer::get_name() { return name; }
