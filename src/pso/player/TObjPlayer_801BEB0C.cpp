#include "types.h"
#include "pso/player/TObjPlayer_801BEB0C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TPlyPhotonChair.h"

extern "C" {

int unregister_object_by_id__14TObjCollidableFv(void*);
int TObjPlayer__sub_801BED98(void*);
int TObjPlayer__sub_801BEDA0(void*);
int TObjPlayer__sub_801BEDA8(void*);
int TObjPlayer__sub_801BEDB0(void*);
int TObjPlayer__sub_801BEDB8(void*);

s32 TObjPlayer__sub_801BEB0C(void* p) { return *(s32*)((char*)p + 0x334); }
int TObjPlayer::unregister_sub() { return unregister_object_by_id__14TObjCollidableFv(this); }
void TObjPlayer::set_control_role(s32 v) { *(s32 *)&this->unk_3E8 = v; }
u8 TObjPlayer__sub_801BEB3C(void* p) { return *(u8*)((char*)p + 0x2e7); }
u8 TObjPlayer__sub_801BEB44(void* p) { return *(u8*)((char*)p + 0x2cb); }
u8 TObjPlayer__sub_801BEB4C(void* p) { return *(u8*)((char*)p + 0x2af); }
void TObjPlayer::set_play_time(s32 v) { this->m_3bc = v; }
void TObjPlayer::reset_entrance_id() { *(s32*)((char*)this + 0x3c8) = -1; }
int TObjPlayer__sub_801BEB68(void* p) { return TObjPlayer__sub_801BED98((char*)p + 0x374); }
u8 TObjPlayer__sub_801BEB8C(void* p) { return *(u8*)((char*)p + 0x293); }
int TObjPlayer::query_field374() { return TObjPlayer__sub_801BEDA0((char*)this + 0x374); }
u8 TObjPlayer__sub_801BEBB8(void* p) { return *(u8*)((char*)p + 0x277); }
int TObjPlayer::query_flags_374() { return TObjPlayer__sub_801BEDA8((char*)this + 0x374); }
u8 TObjPlayer__sub_801BEBE4(void* p) { return *(u8*)((char*)p + 0x25b); }
int TObjPlayer::get_quest_status() { return TObjPlayer__sub_801BEDB0((char*)this + 0x374); }
u8 TObjPlayer__sub_801BEC10(void* p) { return *(u8*)((char*)p + 0x23f); }
int TObjPlayer::get_field_0x374() { return TObjPlayer__sub_801BEDB8((char*)this + 0x374); }
u8 TObjPlayer__sub_801BEC3C(void* p) { return *(u8*)((char*)p + 0x223); }

}
