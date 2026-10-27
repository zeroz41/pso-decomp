#include "types.h"
#include "pso/system/byteswap.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjMotion.h"

void init_6x5E_buy_item_header(void* p);
extern "C" {
void TLobby__send_and_handle_60(u8 *arg0);
void bswap__9TItemDataFv(s32 arg0);
s32 read_be16_field2__10TObjPlayerFv();

extern s32 local_client_id;
extern s32 lbl_805D5E50;

u8 TLobby::is_matching_id(s32 arg0, u16 arg1) {
    int var_r5;

    var_r5 = 0;
    if (((s32) lbl_805D5E50 == 0) && ((s32) arg1 == (s32) local_client_id)) {
        var_r5 = 1;
    }
    return (u8) var_r5;
}

void TLobby::bswap_shop_item() { ((int (*)(void*))read_be16_field2__10TObjPlayerFv)(this); bswap__9TItemDataFv((s32)((char*)this + 0x4)); }
void TLobby::send_item_and_handle_60() { bswap_shop_item(); TLobby__send_and_handle_60((u8 *)this); }
void TLobby::copy_item_data(void* q) { *(u8 *)&this->m_name = *(u8*)((char*)q + 0x0); *(u8*)((char*)this + 0x1) = *(u8*)((char*)q + 0x1); *(u8*)((char*)this + 0x2) = *(u8*)((char*)q + 0x2); *(u8*)((char*)this + 0x3) = *(u8*)((char*)q + 0x3); *(u8 *)&this->m_flags = *(u8*)((char*)q + 0x4); *(u8*)((char*)this + 0x5) = *(u8*)((char*)q + 0x5); *(u32 *)&this->m_id = *(u32*)((char*)q + 0x6); *(u16*)((char*)this + 0xa) = *(u16*)((char*)q + 0xa); *(u32 *)&this->m_next = *(u32*)((char*)q + 0xc); *(u32 *)&this->m_up = *(u32*)((char*)q + 0x10); }
}
void init_6x5E_buy_item_header(void* p) { *(u8*)((char*)p + 0x0) = 94; *(u8*)((char*)p + 0x1) = 6; }
extern "C" {
void TLobby::bswap_6x5D() { ((int (*)(void*))read_be16_field2__10TObjPlayerFv)(this); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); ((TObjPlayer *)((char*)this + 0x8))->bswap_pkt_u32x2(); bswap__9TItemDataFv((s32)((char*)this + 0x10)); }
void TLobby::send_6x5D() { bswap_6x5D(); TLobby__send_and_handle_60((u8 *)this); }
void*TLobby::init_fields() { init_default_fields(); *(unsigned char*)((char*)this + 0x24) = 2; *(unsigned char*)((char*)this + 0x25) = 0; *(unsigned char*)((char*)this + 0x26) = 0; *(unsigned char*)((char*)this + 0x27) = 0; *(unsigned char*)((char*)this + 0x1) = 10; return this; }

    extern const float lbl_805DAA88;
void TLobby::init_default_fields() { *(short *)&this->m_flags = 0; *(short *)&this->m_id = 0; *(float *)&this->m_next = lbl_805DAA88; *(float *)&this->m_prev = lbl_805DAA88; *(unsigned char *)&this->m_name = 93; *(unsigned char*)((char*)this + 0x1) = 9; }

void bswap_pick_up_item_packet__6TLobbyFi(s32 arg0) {
    read_be16_field2__10TObjPlayerFv();
    bswap_16((u16 *)(arg0 + 4));
    bswap_16((u16 *)(arg0 + 6));
    bswap_32((u32 *)(arg0 + 8));
}
}

struct O_80103044 { u8 f0; u8 f1; u8 pad[2]; u16 f4; u16 f6; s32 f8; };

extern "C" {

void bswap_pick_up_item_packet__6TLobbyFi(s32 arg0);
void bswap_pick_up_item_request__6TLobbyFi(s32 arg0);
void dispatch_packet__6TLobbyFPv(void *src);

extern "C" {

extern "C" {

void TLobby::send_pick_up_item() {
    s32 arg0 = (s32)this;
    ((s32 (*)())bswap_pick_up_item_packet__6TLobbyFi)();
    TLobby__send_and_handle_60((u8 *)arg0);
}
void TLobby::init_6x59_packet() {
    ((O_80103044 *)this)->f4 = 0xFFFF;
    ((O_80103044 *)this)->f6 = 0;
    ((O_80103044 *)this)->f8 = -1;
    ((O_80103044 *)this)->f0 = 0x59;
    ((O_80103044 *)this)->f1 = 3;
}

}

}

extern "C" {

void TLobby::send_pick_up_item_request() {
    s32 arg0 = (s32)this;
    ((s32 (*)())bswap_pick_up_item_request__6TLobbyFi)();
    dispatch_packet__6TLobbyFPv((void *)arg0);
}

}

}

extern "C" {
void init__9TItemDataFv(void *);
extern const f32 lbl_805DAA88;
u8 *find_item_by_id(s32);
void *get_player_by_client_id(s32 i);
void TItem__sub_801031C0(void* p);
void TLobby__sub_801030EC(u8 *arg0);

void bswap_pick_up_item_request__6TLobbyFi(s32 arg0) {
    read_be16_field2__10TObjPlayerFv();
    bswap_32((u32 *)(arg0 + 4));
    bswap_16((u16 *)(arg0 + 8));
    bswap_16((u16 *)(arg0 + 0xA));
}

void TLobby__sub_801030EC(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = -1;
    *(s16 *)((s8 *)arg0 + 8) = 0;
    *(s16 *)((s8 *)arg0 + 0xA) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x5A;
    *(s8 *)((s8 *)arg0 + 1) = 3;
}

void TUnk_804B9870::set_item_count(s16 v) { this->m_1c = v; }
s32 TLobby::drop_stacked_item_passthrough() {
    s32 arg0 = (s32)this;
    init_floor_item_entry();
    return arg0;
}

void TLobby::init_floor_item_entry() {
    u8 *arg0 = (u8 *)this;
    *(s8 *)((s8 *)arg0 + 1) = 0;
    *(s8 *)&this->m_name = -1;
    *(s16 *)((s8 *)arg0 + 2) = -1;
    *(f32 *)&this->m_flags = (f32) lbl_805DAA88;
    *(f32 *)&this->m_prev = (f32) lbl_805DAA88;
    *(s16 *)&this->m_next = -1;
    *(s16 *)((s8 *)arg0 + 0xE) = 0;
    init__9TItemDataFv((u8 *)&this->m_up);
}

u8 TUnk_804AF8A0::sub_8010319C() {
    return (u8) (this->m_94 != 0xFFFF);
}

void TItem__sub_801031C0(void* p) { *(s32*)((char*)p + 0x0) = 4; }
}
