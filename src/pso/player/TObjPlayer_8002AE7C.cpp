#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/misc/TWindowKeyBoardHard.h"

extern s32 TLobby__data_805D6144;

void TObjMotion::set_field_dc(s32 v) { *(s32 *)&this->motion_list = v; }
void TObjMotion::set_field_d8(s32 v) { (*(s32 *)&this->action_table) = v; }
void TObjPlayer::reset_lobby_model() { reset_type(); }
void TObjPlayer::reset_type() { *(s32*)((char*)this + 0x0) = 0; }
void TObjPlayer::set_type(s32 v) { *(s32*)((char*)this + 0x0) = v; }
void TObjPlayer::send_6x12_packet() { bswap_6x12_packet(); send_subcommand((u8 *)this); }
void TObjPlayer::bswap_6x12_packet() { read_be16_field2(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); }
void TObjPlayer::set_type_dragon() { *(u8*)((char*)this + 0x0) = 18; *(u8*)((char*)this + 0x1) = 5; }
void TObjPlayer::bswap_dragon_boss_fields() { read_be16_field2(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); }
void TObjPlayer::bswap_stats() { read_be16_field2(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); }
s32 TObjEnemy::exchange_object_state(s32 arg1, s16 arg2) {
    s16 temp_r31;
    temp_r31 = *(s16 *)&this->m_2c;
    if ((temp_r31 < 0) || (temp_r31 > 0xB4F)) {
        return 0;
    }
    if (arg2 == 0) {
        ((TLobby *)(TLobby__data_805D6144 + (temp_r31 * 0xC)))->copy_header((void *)arg1);
    }
    if (arg2 == 1) {
        ((TLobby *)arg1)->copy_header((void *) (TLobby__data_805D6144 + (temp_r31 * 0xC)));
    }
    return 1;
}
