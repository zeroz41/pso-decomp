#include "types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/WordSelectMessage.h"
#include "pso/ui/window/TWindowDD_80348D0C.h"
#include "pso/system/byteswap.h"
#include "pso/network/client_id.h"

extern "C" {
void copy_chat_entry__9TWindowDDFPvPv(void *, void *);

void G_WordSelect_6x74::bswap_message() { message.bswap(); }

void G_WordSelect_6x74::send_message(WordSelectMessage *data) {
    G_WordSelect_6x74 pkt;
    pkt.init_header();
    pkt.client_id = local_client_id;
    copy_chat_entry__9TWindowDDFPvPv(&pkt.message, data);
    pkt.send();
}

void G_WordSelect_6x74::send() { bswap_message(); send_subcommand(this); }
void G_WordSelect_6x74::init_header() { subcommand = 116; size = 8; }

}

extern "C" {

void WordSelectMessage::bswap() {
    s32 i;
    bswap_16((u16 *)&count);
    bswap_16((u16 *)&type);
    for (i = 0; i < 8; i++) {
        bswap_16((u16 *)&ids[i]);
    }
    bswap_32((u32 *)&numeric_parameter);
    bswap_32((u32 *)&unknown_a4);
}

void WordSelectMessage::reset_numeric_parameter() { numeric_parameter = 0; }
void WordSelectMessage::set_numeric_parameter(s32 value) { numeric_parameter = value; }
s32 WordSelectMessage::get_numeric_parameter() { return numeric_parameter; }

void WordSelectMessage::set_last_token(s32 id) {
    if (count > 0) {
        ids[count - 1] = id;
    }
}

void WordSelectMessage::pop_token() {
    if (count > 0) {
        ids[--count] = -1;
    }
}

void WordSelectMessage::push_token(s32 id) {
    if (count < 8) {
        ids[count++] = id;
    }
}

void WordSelectMessage::init() {
    s32 i;
    type = 0;
    count = 0;
    for (i = 0; i < 8; i++) {
        ids[i] = -1;
    }
    numeric_parameter = 0;
    unknown_a4 = 0;
}

}
