#include "types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/player/TObjPlayer_801C0808.h"
#include "pso/system/byteswap.h"
#include "pso/TAdRicoRing.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowActionPalette.h"
#include "pso/player/TObjPlayer.h"
#include "pso/protocol/protocol_types.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct RecoveredGlobal_801D2CF4_lbl_804C43CC {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_801D2CF4_lbl_804C43D8 {
    s32 value;
    u8 remaining[0xC];
};

struct Pos_801D2964 { u8 bytes[0x8]; };

struct Pkt_801D2964 { u8 hdr[4]; Pos_801D2964 pos; };

extern "C" {
s32 TFontSmallLobby__sub_801C0228(void *, void *);
#define TFontSmallLobby__sub_801C0228 ((int (*)(void*))TFontSmallLobby__sub_801C0228)
int TFontSmallLobby__sub_801C01BC(void*);
int read_be16_field2__10TObjPlayerFv(void*);

extern const f32 TObjPlayer__data_805DC278;

void TObjPlayer::init_cmd_6x24() {
    *(s32 *)((s8 *)this + 4) = 0;
    *(f32 *)((s8 *)this + 0x10) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)this + 0xC) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)this + 8) = (f32) TObjPlayer__data_805DC278;
    *(s8 *)((s8 *)this + 0) = 0x24;
    *(s8 *)((s8 *)this + 1) = 5;
}

void TObjPlayer::send_lobby_update() { ((TObjPlayer *)this)->byteswap_packet_body(); TLobby__send_and_handle_60((u8 *)this); }
void TObjPlayer::bswap_status_effect() { read_be16_field2__10TObjPlayerFv(this); ((TObjPlayer *)((char*)this + 0x4))->bswap_status_effect_data(); }
void TObjPlayer::set_code_13_3() { *(u8*)((char*)this + 0x0) = 13; *(u8*)((char*)this + 0x1) = 3; }
void TObjPlayer::update_and_send() { bswap_status_effect(); TLobby__send_and_handle_60((u8 *)this); }
void TObjPlayer::set_code_14_1() { *(u8*)((char*)this + 0x0) = 14; *(u8*)((char*)this + 0x1) = 1; }
void apply_status_effect__10TObjPlayerFPv(void* p) { read_be16_field2__10TObjPlayerFv(p); ((TObjPlayer *)((char*)p + 0x4))->bswap_status_effect_data(); }
#pragma push
#pragma opt_common_subs off
#pragma pop
void *TObjPlayer__sub_801C092C(void *arg0, void *arg1) {
    TFontSmallLobby__sub_801C0228(arg0);
    ((Pkt_801D2964 *)arg0)->pos = ((Pkt_801D2964 *)arg1)->pos;
    return arg0;
}
#pragma push
#pragma fp_contract on
#pragma pop
typedef char RecoveredGlobal_801D2CF4_lbl_804C43CC_size[sizeof(RecoveredGlobal_801D2CF4_lbl_804C43CC) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_801D2CF4_lbl_804C43D8_size[sizeof(RecoveredGlobal_801D2CF4_lbl_804C43D8) == 0x10 ? 1 : -1];

void TObjPlayer::set_code_12_3() { *(u8*)((char*)this + 0x0) = 12; *(u8*)((char*)this + 0x1) = 3; }
void TObjPlayer::reinit_update_sub4_and_send() { apply_status_effect__10TObjPlayerFPv(this); TLobby__send_and_handle_60((u8 *)this); }
void TObjPlayer::set_code_161_1() { *(u8*)((char*)this + 0x0) = 161; *(u8*)((char*)this + 0x1) = 1; }
void TObjPlayer::update_font() { TFontSmallLobby__sub_801C01BC(this); TLobby__send_and_handle_60((u8 *)this); }
void TObjPlayer::send_font_state() { TFontSmallLobby__sub_801C01BC(this); TLobby__send_and_handle_60((u8 *)this); }
void TObjPlayer::set_code_50_1() { *(u8*)((char*)this + 0x0) = 50; *(u8*)((char*)this + 0x1) = 1; }
void TObjPlayer::set_code_49_1() { *(u8*)((char*)this + 0x0) = 49; *(u8*)((char*)this + 0x1) = 1; }
void TObjPlayer::bswap_font_lobby() { TFontSmallLobby__sub_801C01BC(this); TLobby__send_and_handle_60((u8 *)this); }
void TObjPlayer::set_code_45_1() { *(u8*)((char*)this + 0x0) = 45; *(u8*)((char*)this + 0x1) = 1; }
void TObjPlayer::send_lobby_update_font() { TFontSmallLobby__sub_801C01BC(this); TLobby__send_and_handle_60((u8 *)this); }
void bswap_pkt_u16x2_u32__10TObjPlayerFPv(void* p) { read_be16_field2__10TObjPlayerFv(p); bswap_16((u16 *)((char*)p + 0x4)); bswap_16((u16 *)((char*)p + 0x6)); bswap_32((u32 *)((char*)p + 0x10)); ((VectorXZF *)((char*)p + 0x8))->bswap(); }
void TObjPlayer::build_6x2C_impose_hold_packet() {
    this->m_flags = 0;
    this->m_id = 0;
    *(f32 *)((s8 *)((u8 *)this) + 0xC) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)((u8 *)this) + 8) = (f32) TObjPlayer__data_805DC278;
    *(s8 *)((s8 *)((u8 *)this) + 0) = 0x2C;
    *(s8 *)((s8 *)((u8 *)this) + 1) = 5;
}

#undef TFontSmallLobby__sub_801C0228

#define TFontSmallLobby__sub_801C0228 ((s32 (*)())TFontSmallLobby__sub_801C0228)
#define bswap_pkt_u16x2_u32__10TObjPlayerFPv ((s32 (*)())bswap_pkt_u16x2_u32__10TObjPlayerFPv)
#define read_be16_field2__10TObjPlayerFv ((s32 (*)())read_be16_field2__10TObjPlayerFv)
void bswap__9TItemDataFv(s32 arg0);

void TObjPlayer::bswap_and_send_packet() {
    s32 arg0 = (s32)this;
    bswap_pkt_u16x2_u32__10TObjPlayerFPv();
    TLobby__send_and_handle_60((u8 *)arg0);
}
void TObjPlayer::bswap_body_dwords() {
    s32 arg0 = (s32)this;
    read_be16_field2__10TObjPlayerFv();
    bswap_32((u32 *)(arg0 + 4));
    bswap_32((u32 *)(arg0 + 8));
}
void *TObjPlayer::copy_pair_fields(void *arg1) {
    TFontSmallLobby__sub_801C0228();
    *(s32 *)((s8 *)this + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(s32 *)((s8 *)this + 8) = (s32) *(s32 *)((s8 *)arg1 + 8);
    return this;
}

void TObjPlayer__sub_801C0C04(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(s32 *)((s8 *)arg0 + 8) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x2E;
    *(s8 *)((s8 *)arg0 + 1) = 3;
}

void TObjPlayer::send_swapped_packet_6x30() { swap_endian__10TObjPlayerFi((s32)this); TLobby__send_and_handle_60((u8 *)this); }

void swap_endian__10TObjPlayerFi(s32 arg0) {
    read_be16_field2__10TObjPlayerFv();
    bswap_16((u16 *)(arg0 + 4));
    bswap_16((u16 *)(arg0 + 6));
    bswap_16((u16 *)(arg0 + 8));
    bswap_16((u16 *)(arg0 + 0xA));
    bswap_16((u16 *)(arg0 + 0xC));
    bswap_16((u16 *)(arg0 + 0xE));
    bswap_16((u16 *)(arg0 + 0x10));
    bswap_16((u16 *)(arg0 + 0x12));
}

void TObjPlayer::build_6x30_change_level_packet() {
    this->m_flags = 0;
    this->m_id = 0;
    *(s16 *)((s8 *)((u8 *)this) + 8) = 0;
    *(s16 *)((s8 *)((u8 *)this) + 0xA) = 0;
    *(s16 *)((s8 *)((u8 *)this) + 0xC) = 0;
    *(s16 *)((s8 *)((u8 *)this) + 0xE) = 0;
    *(s16 *)((s8 *)((u8 *)this) + 0x10) = 0;
    *(s16 *)((s8 *)((u8 *)this) + 0x12) = 0;
    *(s8 *)((s8 *)((u8 *)this) + 0) = 0x30;
    *(s8 *)((s8 *)((u8 *)this) + 1) = 5;
}

void TObjPlayer::bswap_body_dwords2() {
    s32 arg0 = (s32)this;
    read_be16_field2__10TObjPlayerFv();
    bswap_32((u32 *)(arg0 + 4));
    bswap_32((u32 *)(arg0 + 8));
}
void *TObjPlayer::copy_pair_fields2(void *arg1) {
    TFontSmallLobby__sub_801C0228();
    *(s32 *)((s8 *)this + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(s32 *)((s8 *)this + 8) = (s32) *(s32 *)((s8 *)arg1 + 8);
    return this;
}

void TObjPlayer__sub_801C0D7C(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = -1;
    *(s32 *)((s8 *)arg0 + 8) = -1;
    *(s8 *)((s8 *)arg0 + 0) = 0x28;
    *(s8 *)((s8 *)arg0 + 1) = 3;
}

void TObjPlayer::bswap_and_send_body_dwords2() { bswap_body_dwords2(); TLobby__send_and_handle_60((u8 *)this); }

void TObjPlayer::bswap_cmd_u32() {
    s32 arg0 = (s32)this;
    read_be16_field2__10TObjPlayerFv();
    bswap_32((u32 *)(arg0 + 4));
}
void *TObjPlayer::copy_field_4(void *arg1) {
    TFontSmallLobby__sub_801C0228();
    *(s32 *)((s8 *)this + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    return this;
}
}

void init_6x27_use_item_cmd(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = -1;
    *(s8 *)((s8 *)arg0 + 0) = 0x27;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::send_use_item_cmd() { bswap_cmd_u32(); TLobby__send_and_handle_60((u8 *)this); }

#undef TFontSmallLobby__sub_801C0228
#undef bswap_pkt_u16x2_u32__10TObjPlayerFPv
#undef read_be16_field2__10TObjPlayerFv

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_78 { u8 bytes[0x78]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_C { u8 bytes[0xc]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct ByteBlock_14 { u8 bytes[0x14]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct O_801C12C8 { u8 a; u8 b; u8 pad[2]; s32 c; s32 arr[30]; };

extern "C" {

void TObjPlayer::bswap_cmd_item_data() {
    s32 arg0 = (s32)this;
    read_be16_field2__10TObjPlayerFv((void*)arg0);
    bswap__9TItemDataFv(arg0 + 4);
}

void*TObjPlayer::copy(void* a1) { TObjPlayer__sub_801C0F10((u8 *)this, (u8 *)a1); *(unsigned char*)((char*)this + 0x18) = *(unsigned char*)((char*)a1 + 0x18); *(unsigned char*)((char*)this + 0x19) = *(unsigned char*)((char*)a1 + 0x19); *(short*)((char*)this + 0x1a) = *(unsigned short*)((char*)a1 + 0x1a); return this; }

u8 *TObjPlayer__sub_801C0F10(u8 *arg0, u8 *arg1) {
    TFontSmallLobby__sub_801C0228(arg0, arg1);
    *(ByteBlock_14 *)((s32) arg0 + 4) = *(const ByteBlock_14 *)((s32) arg1 + 4);
    return arg0;
}

void*TObjPlayer::init_pkt_6x2B() { set_code_43_6(); *(unsigned char*)(this) = 43; *(unsigned char*)((char*)this + 0x18) = 2; *(unsigned char*)((char*)this + 0x19) = 0; *(unsigned char*)((char*)this + 0x1a) = 0; *(unsigned char*)((char*)this + 0x1b) = 0; *(unsigned char*)((char*)this + 0x1) = 7; return this; }

void TObjPlayer::set_code_43_6() { *(u8*)((char*)this + 0x0) = 43; *(u8*)((char*)this + 0x1) = 6; }

void TObjPlayer::send_cmd_item_data() { bswap_cmd_item_data(); TLobby__send_and_handle_60((u8 *)this); }

void bswap_fields__10TObjPlayerFi(s32 arg0) {
    read_be16_field2__10TObjPlayerFv((void*)arg0);
    bswap_16((u16 *)(arg0 + 6));
    bswap_16((u16 *)(arg0 + 4));
    bswap_32((u32 *)(arg0 + 8));
    bswap_32((u32 *)(arg0 + 0xC));
    bswap_32((u32 *)(arg0 + 0x10));
    bswap_32((u32 *)(arg0 + 0x14));
}

u8 *TObjPlayer__sub_801C106C(u8 *arg0, u8 *arg1) {
    TFontSmallLobby__sub_801C0228(arg0, arg1);
    *(s16 *)((s8 *)arg0 + 4) = (s16) *(s16 *)((s8 *)arg1 + 4);
    *(s16 *)((s8 *)arg0 + 6) = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(s32 *)((s8 *)arg0 + 8) = (s32) *(s32 *)((s8 *)arg1 + 8);
    *(ByteBlock_C *)((s32) arg0 + 0xC) = *(const ByteBlock_C *)((s32) arg1 + 0xC);
    return arg0;
}

void TObjPlayer::init_6x2A() {
    this->m_flags = 0;
    this->m_id = 0;
    *(s32 *)((s8 *)((u8 *)this) + 8) = -1;
    *(f32 *)((s8 *)((u8 *)this) + 0x14) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)((u8 *)this) + 0x10) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)((u8 *)this) + 0xC) = (f32) TObjPlayer__data_805DC278;
    *(s8 *)((s8 *)((u8 *)this) + 0) = 0x2A;
    *(s8 *)((s8 *)((u8 *)this) + 1) = 6;
}

void TObjPlayer::bswap_fields_and_send() { bswap_fields__10TObjPlayerFi((s32)this); TLobby__send_and_handle_60((u8 *)this); }

void TObjPlayer::bswap_body_words() { read_be16_field2__10TObjPlayerFv(this); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }

void *TObjPlayer::copy_short_fields(void *arg1) {
    TFontSmallLobby__sub_801C0228(this, arg1);
    this->m_flags = (s16) *(s16 *)((s8 *)arg1 + 4);
    this->m_id = (s16) *(s16 *)((s8 *)arg1 + 6);
    return this;
}

void TObjPlayer::init_trap_packet() {
  this->m_flags = 0;
  this->m_id = 0;
  *((s8 *) (((s8 *) this) + 0)) = (double) 0x83;
  *((s8 *) (((s8 *) this) + 1)) = 2;
}

void TObjPlayer::bswap_body_words_and_send() { bswap_body_words(); TLobby__send_and_handle_60((u8 *)this); }

void TObjPlayer::byteswap_data() { read_be16_field2__10TObjPlayerFv(this); bswap_32((u32 *)((char*)this + 0x4)); { int i; for (i = 0; i < 30; i++) { bswap_32((u32 *)((char*)this + 0x8 + i * 4)); } } }

u8 *TObjPlayer__sub_801C1268(u8 *arg0, u8 *arg1) {
    TFontSmallLobby__sub_801C0228(arg0, arg1);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(ByteBlock_78 *)(arg0 + 4 + 4) = *(const ByteBlock_78 *)((arg1 + 4) + 4);
    return arg0;
}

void TObjPlayer::init_6xAC_packet() {
    s32 i;
    ((O_801C12C8 *)this)->c = 0;
    for (i = 0; i < 30; i++) {
        ((O_801C12C8 *)this)->arr[i] = -1;
    }
    ((O_801C12C8 *)this)->a = 0xac;
    ((O_801C12C8 *)this)->b = 0x20;
}

void TObjPlayer::bswap_body_dwords3() { read_be16_field2__10TObjPlayerFv(this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); }

void *TObjPlayer::copy_pair_fields3(void *arg1) {
    TFontSmallLobby__sub_801C0228(this, arg1);
    *(s32 *)((s8 *)this + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(s32 *)((s8 *)this + 8) = (s32) *(s32 *)((s8 *)arg1 + 8);
    return this;
}

void TObjPlayer::init_cmd_6x29() {
    *(s32 *)((s8 *)this + 4) = -1;
    *(s32 *)((s8 *)this + 8) = 0;
    *(s8 *)((s8 *)this + 0) = 0x29;
    *(s8 *)((s8 *)this + 1) = 3;
}

void TObjPlayer::bswap_body_dwords3_and_send() { bswap_body_dwords3(); TLobby__send_and_handle_60((u8 *)this); }

void TObjPlayer::bswap_body_dwords4_and_send() { bswap_body_dwords4(); TLobby__send_and_handle_60((u8 *)this); }

void TObjPlayer::bswap_body_dwords4() { read_be16_field2__10TObjPlayerFv(this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); }

void TObjPlayer::init_cmd_6x26() {
    *(s32 *)((s8 *)this + 4) = -1;
    *(s32 *)((s8 *)this + 8) = 0;
    *(s8 *)((s8 *)this + 0) = 0x26;
    *(s8 *)((s8 *)this + 1) = 3;
}

void TObjPlayer::bswap_body_dwords5() { read_be16_field2__10TObjPlayerFv(this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); }

void *TObjPlayer::copy_pair_fields4(void *arg1) {
    TFontSmallLobby__sub_801C0228(this, arg1);
    *(s32 *)((s8 *)this + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(s32 *)((s8 *)this + 8) = (s32) *(s32 *)((s8 *)arg1 + 8);
    return this;
}

void TObjPlayer::init_command() {
    *(s32 *)((s8 *)this + 4) = -1;
    *(s32 *)((s8 *)this + 8) = 0;
    *(s8 *)((s8 *)this + 0) = 0x25;
    *(s8 *)((s8 *)this + 1) = 3;
}

void TObjPlayer::bswap_body_dwords5_and_send() { bswap_body_dwords5(); TLobby__send_and_handle_60((u8 *)this); }

void TObjPlayer::bswap_pkt_u16x2_u32x2() { read_be16_field2__10TObjPlayerFv(this); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); }

void *TObjPlayer::copy_from(void *arg1) {
    TFontSmallLobby__sub_801C0228(this, arg1);
    this->m_flags = (s16) *(s16 *)((s8 *)arg1 + 4);
    this->m_id = (u16) *(u16 *)((s8 *)arg1 + 6);
    *(s32 *)((s8 *)this + 8) = (s32) *(s32 *)((s8 *)arg1 + 8);
    *(f32 *)((s8 *)this + 0xC) = (f32) *(f32 *)((s8 *)arg1 + 0xC);
    return this;
}

void TObjPlayer::build_6xAE_set_animation_state_packet() {
    this->m_flags = 0;
    this->m_id = 0;
    *(s32 *)((s8 *)((u8 *)this) + 8) = 0;
    *(f32 *)((s8 *)((u8 *)this) + 0xC) = (f32) TObjPlayer__data_805DC278;
    *(u8 *)((s8 *)((u8 *)this) + 0) = 0xAE;
    *(s8 *)((s8 *)((u8 *)this) + 1) = 4;
}

void TObjPlayer::bswap_pkt_u32x5() { read_be16_field2__10TObjPlayerFv(this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); bswap_32((u32 *)((char*)this + 0x10)); bswap_32((u32 *)((char*)this + 0x14)); }

u8 *TObjPlayer__sub_801C1664(u8 *arg0, u8 *arg1) {
    TFontSmallLobby__sub_801C0228(arg0, arg1);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(ByteBlock_C *)((s32) arg0 + 8) = *(const ByteBlock_C *)((s32) arg1 + 8);
    *(s32 *)((s8 *)arg0 + 0x14) = (s32) *(s32 *)((s8 *)arg1 + 0x14);
    return arg0;
}

void TObjPlayer::init_cmd_6x20() {
    *(s32 *)((s8 *)this + 4) = 0;
    *(f32 *)((s8 *)this + 0x10) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)this + 0xC) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)this + 8) = (f32) TObjPlayer__data_805DC278;
    *(s32 *)((s8 *)this + 0x14) = 0;
    *(s8 *)((s8 *)this + 0) = 0x20;
    *(s8 *)((s8 *)this + 1) = 6;
}

#define TFontSmallLobby__sub_801C0228 ((int (*)(void*))TFontSmallLobby__sub_801C0228)
s32 send_subcommand_to_client__6TLobbyFUl(s32, s32);
s32 send_60_sized__6TLobbyFv(s32);
int read_be16_field2__10TObjPlayerFv(void* p);

void TObjPlayer::send_player_floor_packet(void* a1) { bswap_pkt_u16x2_u32x2(); send_subcommand_to_client__6TLobbyFUl((s32)this, (s32)a1); }

void TObjPlayer::send_player_floor_packet_u32x5() { bswap_pkt_u32x5(); send_60_sized__6TLobbyFv((s32)this); }

void TObjPlayer::bswap_set_floor_packet() { read_be16_field2__10TObjPlayerFv(this); bswap_32((u32 *)((char*)this + 0x4)); }

void*TObjPlayer::handle_6x1F_set_floor(void* a1) { TFontSmallLobby__sub_801C0228(this); *(void**)((char*)this + 0x4) = *(void**)((char*)a1 + 0x4); return this; }
}

void init_6x1F_floor_packet(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x1F;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::bswap_and_send_set_floor() { bswap_set_floor_packet(); send_60_sized__6TLobbyFv((s32)this); }

void TObjPlayer::bswap_warp_packet() { read_be16_field2__10TObjPlayerFv(this); bswap_32((u32 *)((char*)this + 0x4)); }

void*TObjPlayer::copy_warp_target(void* a1) { TFontSmallLobby__sub_801C0228(this); *(void**)((char*)this + 0x4) = *(void**)((char*)a1 + 0x4); return this; }

#undef TFontSmallLobby__sub_801C0228
