#include "types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/WordSelectMessage.h"
#include "pso/ui/window/TWindowDD_80348D0C.h"
#include "pso/system/byteswap.h"
#include "pso/network/client_id.h"

struct Pkt_80348C78 { u8 hdr[2]; u16 player; u8 body[0x1c]; };

extern "C" {
void copy_chat_entry__9TWindowDDFPvPv(void *, void *);
int bswap_word_select__9TWindowDDFv(void*);

int TWindowDD::handle_word_select() { return bswap_word_select__9TWindowDDFv((char*)this + 0x4); }

void TWindowDD::send_chat_packet(void *data) {
    Pkt_80348C78 pkt;
    ((TWindowDD *)(&pkt))->init_header();
    pkt.player = local_client_id;
    copy_chat_entry__9TWindowDDFPvPv(pkt.body, data);
    ((TWindowDD *)(&pkt))->update_and_send_lobby();
}

void TWindowDD::update_and_send_lobby() { handle_word_select(); send_subcommand(this); }
void TWindowDD::init_header() { *(u8*)((char*)this + 0x0) = 116; *(u8*)((char*)this + 0x1) = 8; }

}

struct S_80348D90 { s16 count; s16 unk2; s16 items[8]; };

struct S_80348DD8 { s16 count; s16 unk2; s16 items[8]; };

struct S_80348D0C { u16 a; u16 b; u16 c[8]; u32 d; u32 e; };

extern "C" {

void TWindowDD::bswap_word_select() {
    S_80348D0C *msg = (S_80348D0C *)this;
    s32 i;
    bswap_16(&msg->a);
    bswap_16(&msg->b);
    for (i = 0; i < 8; i++) {
        bswap_16(&msg->c[i]);
    }
    bswap_32(&msg->d);
    bswap_32(&msg->e);
}

void WordSelectMessage::reset_index() { numeric_value = 0; }
void WordSelectMessage::set_field14(s32 v) { numeric_value = v; }
saddr TWindowDD__sub_80348D88(void* p) { return *(s32*)((char*)p + 0x14); }

void TWindowDD__sub_80348D90(S_80348D90 *self, s16 v) {
    if (self->count > 0) {
        self->items[self->count - 1] = v;
    }
}

void WordSelectMessage::pop_entry() {
    if (count > 0) {
        ids[--count] = -1;
    }
}

void TWindowDD__sub_80348DD8(S_80348DD8 *self, s16 v) {
    if (self->count < 8) {
        self->items[self->count++] = v;
    }
}

void WordSelectMessage::init_item_slots() {
    s32 i;
    type = 0;
    count = 0;
    for (i = 0; i < 8; i++) {
        ids[i] = -1;
    }
    numeric_value = 0;
    pad_18 = 0;
}

}
