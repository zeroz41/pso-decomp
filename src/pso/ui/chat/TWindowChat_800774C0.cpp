#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChat_80076F88.h"
#include "pso/ui/chat/TWindowChat_800774C0.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

struct Ent_800774E4 { s8 id; u8 a, b, c; };

struct Obj_800774E4 { u32 f0; u8 f4; u8 pad5[0x17]; s32 f1c; u16 h[4]; Ent_800774E4 e[12]; };

struct Obj_800774E4;
struct Ent_80077544 { u8 b[0x58]; };

struct Win_80077544 { u8 pad[0x15A0]; struct Ent_80077544 e[12]; };

extern "C" {
s32 set_stream_and_load_file__6TLobbyFi(char *);
extern char symbol_chat_default_data_filename[];

void TWindowChat::open_symbol_chat(s32 *arg0) {
    get_symbol_chat_preset(*arg0);
}

void TWindowSubSymbolChat::clear_entries() {
    Obj_800774E4 *self = (Obj_800774E4 *)this;
    s32 i;
    self->f0 = 0;
    self->f4 = 0;
    self->f1c = 0;
    for (i = 0; i < 4; i++) {
        self->h[i] = 0xFF;
    }
    for (i = 0; i < 12; i++) {
        self->e[i].id = -1;
        self->e[i].a = 0;
        self->e[i].b = 0;
        self->e[i].c = 0;
    }
}

void TWindowSubSymbolChat::load_symbol_chat_data() {
    struct Win_80077544 *w = (struct Win_80077544 *)this;
    s32 i;
    s32 t;
    s32 data;
    struct Ent_80077544 *e;
    e = w->e;
    data = set_stream_and_load_file__6TLobbyFi(symbol_chat_default_data_filename);
    ((TLobby *)e)->move_data((const void *)data, (u32)0x420);
    TAdSinglePlyChrSelectGC::safe_free(data);
    for (i = 0; i < 6; i++) {
        ((TWindowSubSymbolChat *)(&e[i]))->bswap_entry();
        t = (s32)get_symbol_chat_preset(i);
        ((TWindowSubSymbolChat *)t)->set_entry_name((void *)(TWindowSubStatusDisp::get_message_10(i + 0xC6)));
    }
    for (; i < 12; i++) {
        ((TWindowSubSymbolChat *)(&e[i]))->bswap_entry();
        ((TWindowSubSymbolChat *)((Obj_800774E4 *)get_symbol_chat_preset(i)))->clear_entries();
    }
}

void TLobby__sub_80077608(void) {  }
}

    extern unsigned char symbol_chat_receive_buffer[];
    extern unsigned char pending_symbol_chat_count;
void clear_received_symbol_chat(void) { pending_symbol_chat_count = 0; ((TWindowSubSymbolChat *)symbol_chat_receive_buffer)->clear_entries(); }
