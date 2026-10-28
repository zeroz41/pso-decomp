#include "pso/TPlyGuildCardTag.h"
#include "pso/misc/TPlyGuildCardTag_8007B7EC.h"
#include "pso/misc/TPlyPhotonChair.h"
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

s8 TPlyPhotonChair::get_actor_section_id() {
    u8 *arg0 = (u8 *)this;
  u8 *new_var;
  new_var = &(*(arg0 + 0x88C));
  return ((s8) ((*new_var) & 0xFFFFFFFFFFFFFFFFu)) & 0xFFFF;
}

const char *TObjPlayer::get_name() { return name; }
