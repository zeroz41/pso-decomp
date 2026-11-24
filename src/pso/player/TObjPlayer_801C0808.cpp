#include "types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/player/TObjPlayer_801C0808.h"
#include "pso/system/byteswap.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/item/TItemData.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/ui/font/TFontSmallLobby_801C013C.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct Pos_801D2964 { u8 bytes[0x8]; };

struct Pkt_801D2964 { u8 hdr[4]; Pos_801D2964 pos; };

extern "C" {

extern const f32 TObjPlayer__data_805DC278;

void TObjPlayer::init_cmd_6x24() {
    *(s32 *)((s8 *)this + 4) = 0;
    *(f32 *)((s8 *)this + 0x10) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)this + 0xC) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)this + 8) = (f32) TObjPlayer__data_805DC278;
    *(s8 *)((s8 *)this + 0) = 0x24;
    *(s8 *)((s8 *)this + 1) = 5;
}

void TObjPlayer::send_lobby_update() { ((TObjPlayer *)this)->byteswap_packet_body(); send_subcommand((u8 *)this); }
void TObjPlayer::bswap_status_effect() { ((G_ClientIDHeader *)this)->bswap(); ((TObjPlayer *)((char*)this + 0x4))->bswap_status_effect_data(); }
void TObjPlayer::set_code_13_3() { *(u8*)((char*)this + 0x0) = 13; *(u8*)((char*)this + 0x1) = 3; }
void TObjPlayer::update_and_send() { bswap_status_effect(); send_subcommand((u8 *)this); }
void TObjPlayer::set_code_14_1() { *(u8*)((char*)this + 0x0) = 14; *(u8*)((char*)this + 0x1) = 1; }
void apply_status_effect__10TObjPlayerFPv(void* p) { ((G_ClientIDHeader *)p)->bswap(); ((TObjPlayer *)((char*)p + 0x4))->bswap_status_effect_data(); }
#pragma push
#pragma opt_common_subs off
#pragma pop
void *TObjPlayer__sub_801C092C(void *arg0, void *arg1) {
    copy_subcommand_header(arg0, arg1);
    ((Pkt_801D2964 *)arg0)->pos = ((Pkt_801D2964 *)arg1)->pos;
    return arg0;
}
#pragma push
#pragma fp_contract on
#pragma pop

void TObjPlayer::set_code_12_3() { *(u8*)((char*)this + 0x0) = 12; *(u8*)((char*)this + 0x1) = 3; }
void TObjPlayer::reinit_update_sub4_and_send() { apply_status_effect__10TObjPlayerFPv(this); send_subcommand((u8 *)this); }
void TObjPlayer::set_code_161_1() { *(u8*)((char*)this + 0x0) = 161; *(u8*)((char*)this + 0x1) = 1; }
void TObjPlayer::update_font() { bswap_g_client_id_header(this); send_subcommand((u8 *)this); }
void TObjPlayer::send_font_state() { bswap_g_client_id_header(this); send_subcommand((u8 *)this); }
void TObjPlayer::set_code_50_1() { *(u8*)((char*)this + 0x0) = 50; *(u8*)((char*)this + 0x1) = 1; }
void TObjPlayer::set_code_49_1() { *(u8*)((char*)this + 0x0) = 49; *(u8*)((char*)this + 0x1) = 1; }
void TObjPlayer::bswap_font_lobby() { bswap_g_client_id_header(this); send_subcommand((u8 *)this); }
void TObjPlayer::set_code_45_1() { *(u8*)((char*)this + 0x0) = 45; *(u8*)((char*)this + 0x1) = 1; }
void TObjPlayer::send_lobby_update_font() { bswap_g_client_id_header(this); send_subcommand((u8 *)this); }
void bswap_pkt_u16x2_u32__10TObjPlayerFPv(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_16((u16 *)((char*)p + 0x4)); bswap_16((u16 *)((char*)p + 0x6)); bswap_32((u32 *)((char*)p + 0x10)); ((VectorXZF *)((char*)p + 0x8))->bswap(); }
void TObjPlayer::build_6x2C_impose_hold_packet() {
    this->m_flags = 0;
    this->m_id = 0;
    *(f32 *)((s8 *)((u8 *)this) + 0xC) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)((u8 *)this) + 8) = (f32) TObjPlayer__data_805DC278;
    *(s8 *)((s8 *)((u8 *)this) + 0) = 0x2C;
    *(s8 *)((s8 *)((u8 *)this) + 1) = 5;
}

#define bswap_pkt_u16x2_u32__10TObjPlayerFPv ((s32 (*)())bswap_pkt_u16x2_u32__10TObjPlayerFPv)

void TObjPlayer::bswap_and_send_packet() {
    saddr cmd = (saddr)this;
    bswap_pkt_u16x2_u32__10TObjPlayerFPv();
    send_subcommand((u8 *)cmd);
}
void TObjPlayer::bswap_body_dwords() {
    saddr arg0 = (saddr)this;
    ((G_ClientIDHeader *)this)->bswap();
    bswap_32((u32 *)(arg0 + 4));
    bswap_32((u32 *)(arg0 + 8));
}
void *TObjPlayer::copy_pair_fields(void *command) {
    copy_subcommand_header(this, command);
    *(s32 *)((s8 *)this + 4) = (s32) *(s32 *)((s8 *)command + 4);
    *(s32 *)((s8 *)this + 8) = (s32) *(s32 *)((s8 *)command + 8);
    return this;
}

void TObjPlayer__sub_801C0C04(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(s32 *)((s8 *)arg0 + 8) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x2E;
    *(s8 *)((s8 *)arg0 + 1) = 3;
}

void TObjPlayer::send_swapped_packet_6x30() { swap_endian__10TObjPlayerFi((saddr)this); send_subcommand((u8 *)this); }

void swap_endian__10TObjPlayerFi(saddr packet) {
    ((G_ClientIDHeader *)packet)->bswap();
    bswap_16((u16 *)(packet + 4));
    bswap_16((u16 *)(packet + 6));
    bswap_16((u16 *)(packet + 8));
    bswap_16((u16 *)(packet + 0xA));
    bswap_16((u16 *)(packet + 0xC));
    bswap_16((u16 *)(packet + 0xE));
    bswap_16((u16 *)(packet + 0x10));
    bswap_16((u16 *)(packet + 0x12));
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
    saddr arg0 = (saddr)this;
    ((G_ClientIDHeader *)this)->bswap();
    bswap_32((u32 *)(arg0 + 4));
    bswap_32((u32 *)(arg0 + 8));
}
void *TObjPlayer::copy_pair_fields2(void *arg1) {
    copy_subcommand_header(this, arg1);
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

void TObjPlayer::bswap_and_send_body_dwords2() { bswap_body_dwords2(); send_subcommand((u8 *)this); }

void TObjPlayer::bswap_cmd_u32() {
    saddr arg0 = (saddr)this;
    ((G_ClientIDHeader *)this)->bswap();
    bswap_32((u32 *)(arg0 + 4));
}
void *TObjPlayer::copy_field_4(void *arg1) {
    copy_subcommand_header(this, arg1);
    *(s32 *)((s8 *)this + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    return this;
}
}

void init_6x27_use_item_cmd(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = -1;
    *(s8 *)((s8 *)arg0 + 0) = 0x27;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::send_use_item_cmd() { bswap_cmd_u32(); send_subcommand((u8 *)this); }

#undef bswap_pkt_u16x2_u32__10TObjPlayerFPv

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

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


void TObjPlayer::bswap_cmd_item_data() {
    saddr arg0 = (saddr)this;
    ((G_ClientIDHeader *)arg0)->bswap();
    ((TItemData *)(arg0 + 4))->bswap();
}

void*TObjPlayer::copy(void* source) { TObjPlayer__sub_801C0F10((u8 *)this, (u8 *)source); *(unsigned char*)((char*)this + 0x18) = *(unsigned char*)((char*)source + 0x18); *(unsigned char*)((char*)this + 0x19) = *(unsigned char*)((char*)source + 0x19); *(short*)((char*)this + 0x1a) = *(unsigned short*)((char*)source + 0x1a); return this; }

u8 *TObjPlayer__sub_801C0F10(u8 *arg0, u8 *source) {
    copy_subcommand_header(arg0, source);
    *(ByteBlock_14 *)((saddr) arg0 + 4) = *(const ByteBlock_14 *)((saddr) source + 4);
    return arg0;
}

void*TObjPlayer::init_pkt_6x2B() { set_code_43_6(); *(unsigned char*)(this) = 43; *(unsigned char*)((char*)this + 0x18) = 2; *(unsigned char*)((char*)this + 0x19) = 0; *(unsigned char*)((char*)this + 0x1a) = 0; *(unsigned char*)((char*)this + 0x1b) = 0; *(unsigned char*)((char*)this + 0x1) = 7; return this; }

void TObjPlayer::set_code_43_6() { *(u8*)((char*)this + 0x0) = 43; *(u8*)((char*)this + 0x1) = 6; }

void TObjPlayer::send_cmd_item_data() { bswap_cmd_item_data(); send_subcommand((u8 *)this); }

void bswap_fields__10TObjPlayerFi(saddr arg0) {
    ((G_ClientIDHeader *)arg0)->bswap();
    bswap_16((u16 *)(arg0 + 6));
    bswap_16((u16 *)(arg0 + 4));
    bswap_32((u32 *)(arg0 + 8));
    bswap_32((u32 *)(arg0 + 0xC));
    bswap_32((u32 *)(arg0 + 0x10));
    bswap_32((u32 *)(arg0 + 0x14));
}

u8 *TObjPlayer__sub_801C106C(u8 *arg0, u8 *source) {
    copy_subcommand_header(arg0, source);
    *(s16 *)((s8 *)arg0 + 4) = (s16) *(s16 *)((s8 *)source + 4);
    *(s16 *)((s8 *)arg0 + 6) = (s16) *(s16 *)((s8 *)source + 6);
    *(s32 *)((s8 *)arg0 + 8) = (s32) *(s32 *)((s8 *)source + 8);
    *(ByteBlock_C *)((saddr) arg0 + 0xC) = *(const ByteBlock_C *)((saddr) source + 0xC);
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

void TObjPlayer::bswap_fields_and_send() { bswap_fields__10TObjPlayerFi((saddr)this); send_subcommand((u8 *)this); }

void TObjPlayer::bswap_body_words() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }

void *TObjPlayer::copy_short_fields(void *source) {
    copy_subcommand_header(this, source);
    this->m_flags = (s16) *(s16 *)((s8 *)source + 4);
    this->m_id = (s16) *(s16 *)((s8 *)source + 6);
    return this;
}

void TObjPlayer::init_trap_packet() {
  this->m_flags = 0;
  this->m_id = 0;
  *((s8 *) (((s8 *) this) + 0)) = (double) 0x83;
  *((s8 *) (((s8 *) this) + 1)) = 2;
}

void TObjPlayer::bswap_body_words_and_send() { bswap_body_words(); send_subcommand((u8 *)this); }

void TObjPlayer::byteswap_data() { ((G_ClientIDHeader *)this)->bswap(); bswap_32((u32 *)((char*)this + 0x4)); { int i; for (i = 0; i < 30; i++) { bswap_32((u32 *)((char*)this + 0x8 + i * 4)); } } }

u8 *TObjPlayer__sub_801C1268(u8 *arg0, u8 *source) {
    copy_subcommand_header(arg0, source);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)source + 4);
    ((SubcmdPacketCopy6xAC *)arg0)->body = ((const SubcmdPacketCopy6xAC *)source)->body;
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

void TObjPlayer::bswap_body_dwords3() { ((G_ClientIDHeader *)this)->bswap(); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); }

void *TObjPlayer::copy_pair_fields3(void *source) {
    copy_subcommand_header(this, source);
    *(s32 *)((s8 *)this + 4) = (s32) *(s32 *)((s8 *)source + 4);
    *(s32 *)((s8 *)this + 8) = (s32) *(s32 *)((s8 *)source + 8);
    return this;
}

void TObjPlayer::init_cmd_6x29() {
    *(s32 *)((s8 *)this + 4) = -1;
    *(s32 *)((s8 *)this + 8) = 0;
    *(s8 *)((s8 *)this + 0) = 0x29;
    *(s8 *)((s8 *)this + 1) = 3;
}

void TObjPlayer::bswap_body_dwords3_and_send() { bswap_body_dwords3(); send_subcommand((u8 *)this); }

void TObjPlayer::bswap_body_dwords4_and_send() { bswap_body_dwords4(); send_subcommand((u8 *)this); }

void TObjPlayer::bswap_body_dwords4() { ((G_ClientIDHeader *)this)->bswap(); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); }

void TObjPlayer::init_cmd_6x26() {
    *(s32 *)((s8 *)this + 4) = -1;
    *(s32 *)((s8 *)this + 8) = 0;
    *(s8 *)((s8 *)this + 0) = 0x26;
    *(s8 *)((s8 *)this + 1) = 3;
}

void TObjPlayer::bswap_body_dwords5() { ((G_ClientIDHeader *)this)->bswap(); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); }

void *TObjPlayer::copy_pair_fields4(void *source) {
    copy_subcommand_header(this, source);
    *(s32 *)((s8 *)this + 4) = (s32) *(s32 *)((s8 *)source + 4);
    *(s32 *)((s8 *)this + 8) = (s32) *(s32 *)((s8 *)source + 8);
    return this;
}

void TObjPlayer::init_command() {
    *(s32 *)((s8 *)this + 4) = -1;
    *(s32 *)((s8 *)this + 8) = 0;
    *(s8 *)((s8 *)this + 0) = 0x25;
    *(s8 *)((s8 *)this + 1) = 3;
}

void TObjPlayer::bswap_body_dwords5_and_send() { bswap_body_dwords5(); send_subcommand((u8 *)this); }

void TObjPlayer::bswap_pkt_u16x2_u32x2() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); }

void *TObjPlayer::copy_from(void *source) {
    copy_subcommand_header(this, source);
    this->m_flags = (s16) *(s16 *)((s8 *)source + 4);
    this->m_id = (u16) *(u16 *)((s8 *)source + 6);
    *(s32 *)((s8 *)this + 8) = (s32) *(s32 *)((s8 *)source + 8);
    *(f32 *)((s8 *)this + 0xC) = (f32) *(f32 *)((s8 *)source + 0xC);
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

void TObjPlayer::bswap_pkt_u32x5() { ((G_ClientIDHeader *)this)->bswap(); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); bswap_32((u32 *)((char*)this + 0x10)); bswap_32((u32 *)((char*)this + 0x14)); }

u8 *TObjPlayer__sub_801C1664(u8 *arg0, u8 *source) {
    copy_subcommand_header(arg0, source);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)source + 4);
    *(ByteBlock_C *)((saddr) arg0 + 8) = *(const ByteBlock_C *)((saddr) source + 8);
    *(s32 *)((s8 *)arg0 + 0x14) = (s32) *(s32 *)((s8 *)source + 0x14);
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

void TObjPlayer::send_player_floor_packet(u32 client) { bswap_pkt_u16x2_u32x2(); ((game_command *)this)->send_to_client(client); }

void TObjPlayer::send_player_floor_packet_u32x5() { bswap_pkt_u32x5(); ((game_command *)this)->send(); }

void TObjPlayer::bswap_set_floor_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_32((u32 *)((char*)this + 0x4)); }

G_SetPlayerFloor_6x1F &G_SetPlayerFloor_6x1F::operator=(const G_SetPlayerFloor_6x1F &src) {
    copy_subcommand_header(this, (void *)&src);
    floor = src.floor;
    return *this;
}

void init_6x1F_floor_packet(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x1F;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TObjPlayer::bswap_and_send_set_floor() { bswap_set_floor_packet(); ((game_command *)this)->send(); }

void TObjPlayer::bswap_warp_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_32((u32 *)((char*)this + 0x4)); }

G_InterLevelWarp_6x21 &G_InterLevelWarp_6x21::operator=(const G_InterLevelWarp_6x21 &src) {
    copy_subcommand_header(this, (void *)&src);
    floor = src.floor;
    return *this;
}
