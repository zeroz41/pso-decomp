#include "pso/player/TPlyGuildCardTag.h"
#include "pso/player/TPlyGuildCardTag_8007B7EC.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/player/TObjPlayer.h"

#include "types.h"

void TPlyGuildCardTag::bswap() {
    bswap_32(&m_guildcard_number);
    bswap_16(&m_tag2);
}

extern u16 lbl_805D63FC;

void TWindowSubShortMail__sub_8007B824(void) {
    lbl_805D63FC |= 2;
}

s32 TWindowSubShortMail__sub_8007B834(void* p) { return *(s32*)((char*)p + 0x0); }

void* fn_8007B83C(void* p) { return (char*)p + 0x8; }

s32 TPlyPhotonChair::get_actor_section_id() {
    s8 id = *((s8 *)this + 0x88C);
    return id;
}

const char *TObjPlayer::get_name() { return name; }
