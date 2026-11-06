#include "types.h"
#include "pso/unk/text_80076E84.h"
#include "pso/ui/chat/TWindowSubSymbolChat_80076F88.h"
#include "pso/ui/chat/TWindowSubSymbolChat_8007763C.h"

#include "pso/network/protocol/subcmd_6x.h"
#include <stddef.h>
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/unk/TLobby.h"

struct RecoveredGlobal_800773BC_lbl_80438830 {
    s32 value;
    u8 remaining[0x20];
};

struct E_80077480 { u8 pad[0x58]; };

struct X_80077480 { u8 pad[0x15a0]; u8 sub[0x58]; };

struct Ent_80077108 { s8 id; u8 a, b, c; };

struct Obj_80077108 { u8 pad[0x28]; Ent_80077108 e[12]; };

struct Obj_8007728C { u32 flags; u8 pad[0x1C]; u16 h[4]; };

struct Ent_8007714C { s8 id; u8 a, b, c; };

struct Obj_8007714C { u8 pad[0x28]; Ent_8007714C e[12]; };

struct Ent_80077098 { s8 a, b, c; u8 d; };
struct Obj_80077098 { u8 pad0[0x28]; Ent_80077098 e[12]; };
struct Obj_800770D0 { u8 pad0[0x20]; u16 s[4]; };
struct Obj_800771B0 { u8 pad0[0x20]; u16 s[4]; };
struct Obj_800771C4 { u8 pad0[0x20]; u16 s[4]; };
struct Ent_800771E4 { s8 a, b, c; u8 d; };
struct Obj_800771E4 { u8 pad0[0x28]; Ent_800771E4 e[12]; };

extern "C" {
void TWindowSubSymbolChat__sub_800771B0(Obj_800771B0 *arg0, s32 arg1);
s32 TWindowSubSymbolChat__sub_800771C4(Obj_800771C4 *arg0, s32 arg1);
u8 *get_message_10__20TWindowSubStatusDispFl(s32);
    extern int selected_symbol_chat_preset;
s32 is_initialized__20TWindowSubSymbolChatFv();
int get_instance__20TWindowSubSymbolChatFv(void*);
s32 strncpy(void *, void *, int);
extern s32 local_client_id;
s32 play_sound_effect(s32, u32, s16, s32);
extern RecoveredGlobal_800773BC_lbl_80438830 symbol_chat_sound_ids;
E_80077480 *get_character_save_record(u32 id);

void TWindowSubSymbolChat::send_selected_symbol_chat(s32 *arg0) {
    G_SymbolChat_6x07 packet;
    s32 symbol_chat_preset;
    TWindowSubSymbolChat__sub_80077704((&packet.header));
    symbol_chat_preset = ((s32)((int)get_symbol_chat_preset((s32)((void *)((void *) (*arg0))))));
    packet.client_id = local_client_id;
    copy_symbol_chat_entry__6TLobbyFPvPv((void *)&packet.data[0], (void *)(symbol_chat_preset + 0x1C));
    ((TWindowSubSymbolChat *)(&packet.header))->send_symbol_chat();
}

int TWindowSubSymbolChat__sub_80076FE0(void* p) { return (*(u32*)((char*)p + 0x1c) >> 9) & 0x1; }

void TWindowSubSymbolChat::set_entry_name(void *arg1) {
    u8 *arg0 = (u8 *)this;
    strncpy((u8 *)&this->m_flags, arg1, 0x16);
    *(s8 *)((s8 *)arg0 + 0x1A) = 0;
    *(s32 *)&this->m_name = (s32) (*(s32 *)&this->m_name | 1);
}

void TWindowSubSymbolChat::set_flag_bit9(s32 arg1) {
    s32 var_r4;
    var_r4 = arg1;
    if (var_r4 != 0) {
        var_r4 = 1;
    }
    *(s32 *)&this->m_1c = (s32) (*(s32 *)&this->m_1c & 0xFFFFFDFF);
    *(s32 *)&this->m_1c = (s32) (*(s32 *)&this->m_1c | (var_r4 << 9));
    *(s32 *)&this->m_name = (s32) (*(s32 *)&this->m_name | 1);
}

void TWindowSubSymbolChat::set_symbol_index(s32 arg1) {
    *(s32 *)&this->m_1c = (s32) (*(s32 *)&this->m_1c & 0xFFFFFE1F);
    *(s32 *)&this->m_1c = (s32) (*(s32 *)&this->m_1c | (arg1 << 5));
    *(s32 *)&this->m_name = (s32) (*(s32 *)&this->m_name | 1);
}

s32 TWindowSubSymbolChat::count_empty_slots() {
    Obj_80077098 *arg0 = (Obj_80077098 *)this;
    s32 n = 0;
    s32 i;
    for (i = 0; i < 12; i++) {
        if (arg0->e[i].a == -1) {
            n++;
        }
    }
    return n;
}

s32 TWindowSubSymbolChat::count_used_slots() {
    Obj_800770D0 *arg0 = (Obj_800770D0 *)this;
    s32 n = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        s32 v = (u8)arg0->s[i];
        if (v != 0xFF) {
            n++;
        }
    }
    return n;
}

s32 TWindowSubSymbolChat::find_free_entry(s32 i) {
    Obj_80077108 *self = (Obj_80077108 *)this;
    for (; i < 12; i++) {
        if (self->e[i].id == -1) {
            return i;
        }
    }
    return i;
}

void TWindowSubSymbolChat::remove_slot_shift_down(s32 i) {
    Obj_8007714C *self = (Obj_8007714C *)this;
    if (i < 11) {
        Ent_8007714C *p = &self->e[i];
        ((TLobby *)p)->move_words((u32 *)(p + 1), (s32)(((11 - i) * sizeof(Ent_8007714C)) / 4));
    }
    self->e[11].id = -1;
    self->e[11].a = 0;
    self->e[11].b = 0;
    self->e[11].c = 0;
}

void TWindowSubSymbolChat__sub_800771B0(Obj_800771B0 *arg0, s32 arg1) {
    arg0->s[arg1] = 0xFF;
}

s32 TWindowSubSymbolChat__sub_800771C4(Obj_800771C4 *arg0, s32 arg1) {
    return ((u8)arg0->s[arg1] - 0xFF) != 0 ? 1 : 0;
}

void TWindowSubSymbolChat::set_entry(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    Obj_800771E4 *arg0 = (Obj_800771E4 *)this;
    Ent_800771E4 *p = &arg0->e[arg1];
    p->a = arg2;
    p->b = arg3;
    p->c = arg4;
    p->d = arg5;
    p->d = p->d | (arg6 * 2);
}

void TWindowSubSymbolChat::add(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 *arg0 = (s32 *)this;
    s32 temp;
    temp = find_free_entry((s32)((void*)((void*)((void*)(0)))));
    if (temp < 0xC) {
        set_entry(temp, arg1, arg2, arg3, arg4, arg5);
        *arg0 |= 1;
    }
}

void TWindowSubSymbolChat::set_entry_bits(u16 v, s32 a, s32 idx, s32 b, s32 c) {
    Obj_8007728C *self = (Obj_8007728C *)this;
    u16 *p = &self->h[idx];
    *p = v;
    *p |= a << 8;
    *p |= b << 11;
    *p |= c << 12;
    self->flags |= 1;
}

void TWindowSubSymbolChat::set_symbol_flags(s32 arg1, s32 arg2) {
    *(s32 *)&this->m_1c = (s32) (*(s32 *)&this->m_1c & 0xFFFFFFE0);
    *(s32 *)&this->m_1c = (s32) (*(s32 *)&this->m_1c | (arg2 * 4));
    *(s32 *)&this->m_1c = (s32) (*(s32 *)&this->m_1c | arg1);
    *(s32 *)&this->m_name = (s32) (*(s32 *)&this->m_name | 1);
}

void TWindowSubSymbolChat::refresh_parts() { ((TWindowSubSymbolChat *)((Obj_80077098 *)get_instance__20TWindowSubSymbolChatFv(this)))->count_empty_slots(); }

void TWindowSubSymbolChat::update_layout() { ((TWindowSubSymbolChat *)((Obj_800770D0 *)get_instance__20TWindowSubSymbolChatFv(this)))->count_used_slots(); }

void TWindowSubSymbolChat::update_symbol_chat_result() { selected_symbol_chat_preset = ((int)get_symbol_chat_preset((s32)this)); }

void TWindowSubSymbolChat::update_selected_symbol() {
    if (is_initialized__20TWindowSubSymbolChatFv() != 0) {
        TWindowSubSymbolChat::play_symbol_sound((s32)(((u32) *(u32 *)&this->m_1c >> 5U) & 0xF));
    }
}

typedef char RecoveredGlobal_800773BC_lbl_80438830_size[sizeof(RecoveredGlobal_800773BC_lbl_80438830) == 0x24 ? 1 : -1];
void TWindowSubSymbolChat::play_symbol_sound(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 9)) {
        play_sound_effect(*(s32 *)((s8 *)&symbol_chat_sound_ids.value + (arg0 * 4)), 0U, 0, 0);
    }
}

u8 *TWindowSubSymbolChat::get_symbol_chat_data() {
    u8 *arg0 = (u8 *)this;
    if (is_symbol_chat_preset_in_use((u32 *)arg0) == 0) {
        return get_message_10__20TWindowSubStatusDispFl(0xCC);
    }
    if ((s8) *(u8 *)&this->m_flags == 0) {
        return get_message_10__20TWindowSubStatusDispFl(0xCD);
    }
    return (u8 *)&this->m_flags;
}

s32 is_symbol_chat_preset_in_use(u32 *arg0) {
    u32 temp_r3;
    temp_r3 = *arg0;
    if (temp_r3 & 1) {
        return 1;
    }
    return (temp_r3 & 2) ? 1 : 0;
}

u8 *get_symbol_chat_preset(s32 i) {
    E_80077480 *e = &get_character_save_record(0xFFFF)[i];
    return ((X_80077480 *)e)->sub;
}

}
