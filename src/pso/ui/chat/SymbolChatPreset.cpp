#include "pso/system/SoundEffect.h"
#include "pso/system/memory.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/ui/chat/SymbolChatCommand.h"
#include "pso/ui/chat/SymbolChatPreset.h"
#include <string.h>

#include "pso/network/protocol/subcmd_6x.h"
#include <stddef.h>
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/TGameProtocol.h"
#include "pso/system/byteswap.h"
#include "pso/system/MemoryMove.h"
#include "pso/network/client_id.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"

static const s32 symbol_chat_sound_ids[9] = {
    0x53507, 0x52608, 0x52A09, 0x5250A, 0x5230B, 0x5250C, 0x5280D, 0x5250E, 0x53719,
};


    extern int selected_symbol_chat_preset;

void send_selected_symbol_chat(s32 *preset_index) {
    G_SymbolChat_6x07 packet;
    SymbolChatPreset *preset;
    init_symbol_chat_header(&packet);
    preset = get_symbol_chat_preset(*preset_index);
    packet.client_id = local_client_id;
    TLobby::copy_symbol_chat_entry(&packet.data, &preset->payload);
    packet.send();
}

int is_preset_flag_bit9_set(const SymbolChatPreset *preset) { return (preset->payload.appearance >> 9) & 1; }

void SymbolChatPreset::set_entry_name(const char *text) {
    strncpy(name, text, 0x16);
    name[0x16] = 0;
    flags = flags | 1;
}

void SymbolChatPreset::set_flag_bit9(s32 enable) {
    s32 bit;
    bit = enable;
    if (bit != 0) {
        bit = 1;
    }
    payload.appearance = payload.appearance & 0xFFFFFDFF;
    payload.appearance = payload.appearance | (bit << 9);
    flags = flags | 1;
}

void SymbolChatPreset::set_symbol_index(s32 symbol_index) {
    payload.appearance = payload.appearance & 0xFFFFFE1F;
    payload.appearance = payload.appearance | (symbol_index << 5);
    flags = flags | 1;
}

s32 SymbolChatPreset::count_empty_slots() {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 12; i++) {
        if (payload.parts[i].id == -1) {
            n++;
        }
    }
    return n;
}

s32 SymbolChatPreset::count_used_slots() {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        s32 v = (u8)payload.facial_parts[i];
        if (v != 0xFF) {
            n++;
        }
    }
    return n;
}

s32 SymbolChatPreset::find_free_entry(s32 i) {
    for (; i < 12; i++) {
        if (payload.parts[i].id == -1) {
            return i;
        }
    }
    return i;
}

void SymbolChatPreset::remove_slot_shift_down(s32 i) {
    if (i < 11) {
        SymbolChatPart *p = &payload.parts[i];
        move_words(p, p + 1, (11 - i) * sizeof(SymbolChatPart) / sizeof(u32));
    }
    payload.parts[11].id = -1;
    payload.parts[11].x = 0;
    payload.parts[11].y = 0;
    payload.parts[11].flags = 0;
}

void clear_facial_part(SymbolChatPreset *preset, s32 index) {
    preset->payload.facial_parts[index] = 0xFF;
}

s32 is_facial_part_set(const SymbolChatPreset *preset, s32 index) {
    return ((u8)preset->payload.facial_parts[index] - 0xFF) != 0 ? 1 : 0;
}

void SymbolChatPreset::set_entry(s32 index, s32 part_id, s32 x, s32 y, s32 part_flags, s32 flag_bit_1) {
    SymbolChatPart *p = &payload.parts[index];
    p->id = part_id;
    p->x = x;
    p->y = y;
    p->flags = part_flags;
    p->flags = p->flags | (flag_bit_1 * 2);
}

void SymbolChatPreset::add(s32 part_id, s32 x, s32 y, s32 part_flags, s32 flag_bit_1) {
    s32 temp;
    temp = find_free_entry(0);
    if (temp < 0xC) {
        set_entry(temp, part_id, x, y, part_flags, flag_bit_1);
        flags |= 1;
    }
}

void SymbolChatPreset::set_entry_bits(s32 v, s32 a, s32 idx, s32 b, s32 c) {
    u16 *p = &payload.facial_parts[idx];
    *p = v;
    *p |= a << 8;
    *p |= b << 11;
    *p |= c << 12;
    flags |= 1;
}

void SymbolChatPreset::set_symbol_flags(s32 low_bits, s32 mode) {
    payload.appearance = payload.appearance & 0xFFFFFFE0;
    payload.appearance = payload.appearance | (mode * 4);
    payload.appearance = payload.appearance | low_bits;
    flags = flags | 1;
}

s32 TWindowSubSymbolChat::count_instance_empty_slots() { return reinterpret_cast<SymbolChatPreset *>(TWindowSubSymbolChat::get_instance())->count_empty_slots(); }

s32 TWindowSubSymbolChat::update_layout() { return reinterpret_cast<SymbolChatPreset *>(TWindowSubSymbolChat::get_instance())->count_used_slots(); }

void TWindowSubSymbolChat::update_symbol_chat_result(s32 index) { selected_symbol_chat_preset = ((saddr)get_symbol_chat_preset(index)); }

void SymbolChatPreset::update_selected_symbol() {
    if (is_initialized() != 0) {
        TWindowSubSymbolChat::play_symbol_sound((payload.appearance >> 5) & 0xF);
    }
}

void TWindowSubSymbolChat::play_symbol_sound(s32 sound_index) {
    if ((sound_index >= 0) && (sound_index < 9)) {
        play_sound_effect(symbol_chat_sound_ids[sound_index], 0, 0, 0);
    }
}

u8 *SymbolChatPreset::get_symbol_chat_data() {
    if (is_symbol_chat_preset_in_use(this) == 0) {
        return (u8 *)(TWindowSubStatusDisp::get_message_10(0xCC));
    }
    if (name[0] == 0) {
        return (u8 *)(TWindowSubStatusDisp::get_message_10(0xCD));
    }
    return reinterpret_cast<u8 *>(name);
}

s32 is_symbol_chat_preset_in_use(const SymbolChatPreset *preset) {
    u32 flags;
    flags = preset->flags;
    if (flags & 1) {
        return 1;
    }
    return (flags & 2) ? 1 : 0;
}

SymbolChatPreset *get_symbol_chat_preset(s32 i) {
    u8 *save = reinterpret_cast<u8 *>(get_character_save_record(0xFFFF));
    return reinterpret_cast<SymbolChatPreset *>(save + offsetof(SavedSymbolChatPresets, entries)) + i;
}



SymbolChatPreset *TWindowChat::open_symbol_chat(s32 *index) {
    return get_symbol_chat_preset(*index);
}

void SymbolChatPreset::clear_entries() {
    s32 i;
    flags = 0;
    name[0] = 0;
    payload.appearance = 0;
    for (i = 0; i < 4; i++) {
        payload.facial_parts[i] = 0xFF;
    }
    for (i = 0; i < 12; i++) {
        payload.parts[i].id = -1;
        payload.parts[i].x = 0;
        payload.parts[i].y = 0;
        payload.parts[i].flags = 0;
    }
}

void SavedSymbolChatPresets::load_symbol_chat_data() {
    s32 i;
    SymbolChatPreset *preset;
    saddr data;
    SymbolChatPreset *e;
    e = entries;
    data = (saddr)load_disc_file("symbolchat.dat");
    move_data(e, ((const void *)data), (u32)0x420);
    safe_free(reinterpret_cast<void *>(data));
    for (i = 0; i < 6; i++) {
        e[i].bswap_entry();
        preset = get_symbol_chat_preset(i);
        preset->set_entry_name((const char *)(TWindowSubStatusDisp::get_message_10(i + 0xC6)));
    }
    for (; i < 12; i++) {
        e[i].bswap_entry();
        get_symbol_chat_preset(i)->clear_entries();
    }
}

void symbol_chat_on_floor_free_stub(void) {  }

int selected_symbol_chat_preset;
unsigned char pending_symbol_chat_count;
void clear_received_symbol_chat(void) { pending_symbol_chat_count = 0; symbol_chat_receive_buffer.clear_entries(); }


SymbolChatPayload *SymbolChatPreset::get_data_ptr() { return &payload; }
void G_SymbolChat_6x07::bswap() {
    header.bswap();
    bswap_32(&client_id);
    data.byteswap_entry();
}
void SymbolChatPayload::byteswap_entry() { bswap_32(&appearance); { int i; for (i = 0; i < 4; i++) { bswap_16(&facial_parts[i]); } } }
void G_SymbolChat_6x07::send() {
    bswap();
    broadcast_subcommand(this);
}
void init_symbol_chat_header(G_SymbolChat_6x07 *cmd) {
    cmd->header.subcommand = 0x07;
    cmd->header.size = sizeof(G_SymbolChat_6x07) / 4;
}

saddr TWindowSubSymbolChat::get_instance() {  return selected_symbol_chat_preset; }

int SymbolChatPreset::is_initialized() { return flags & 1; }
void SymbolChatPreset::bswap_entry() { bswap_32(&flags); payload.byteswap_entry(); }

const char *TWindowSubStatusDisp::get_message_10(s32 index) { return get_localized_text_entry(10, index); }
