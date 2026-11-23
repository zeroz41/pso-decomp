#ifndef PSO_UI_CHAT_SYMBOLCHATPRESET_H
#define PSO_UI_CHAT_SYMBOLCHATPRESET_H

#include <stddef.h>
#include "types.h"

#include "pso/ui/chat/SymbolChatPayload.h"

struct SymbolChatPreset {
    u32 flags;
    char name[0x17];
    SymbolChatPayload payload;

    void set_entry_name(const char *text);
    void set_flag_bit9(s32 arg1);
    void set_symbol_index(s32 arg1);
    s32 count_empty_slots();
    s32 count_used_slots();
    s32 find_free_entry(s32 i);
    void remove_slot_shift_down(s32 i);
    void set_entry(s32 slot, s32 part_id, s32 x, s32 y, s32 flags, s32 flag_bit_1);
    void add(s32 part_id, s32 x, s32 y, s32 flags, s32 flag_bit_1);
    void set_entry_bits(s32 v, s32 a, s32 idx, s32 b, s32 c);
    void set_symbol_flags(s32 arg1, s32 arg2);
    void update_selected_symbol();
    u8 *get_symbol_chat_data();
    SymbolChatPayload *get_data_ptr();
    int is_initialized();
    void set_flag_bit1();
    void set_flag_bit2();
    void clear_flag_bit2();
    void clear_entries();
    void bswap_entry();
    char *get_keyboard_ptr();
    SymbolChatPreset *commit(const SymbolChatPreset *src);
};

LAYOUT_ASSERT(SymbolChatPresetSize, sizeof(SymbolChatPreset) == 0x58);
LAYOUT_ASSERT(SymbolChatPresetNameOffset, offsetof(SymbolChatPreset, name) == 0x4);
LAYOUT_ASSERT(SymbolChatPresetPayloadOffset, offsetof(SymbolChatPreset, payload) == 0x1C);

// Preset bank within the character save record.
struct SavedSymbolChatPresets {
    u8 save_header[0x15A0];
    SymbolChatPreset entries[12];

    void load_symbol_chat_data();
};

LAYOUT_ASSERT(SavedSymbolChatPresetsEntriesOffset, offsetof(SavedSymbolChatPresets, entries) == 0x15A0);

extern "C" {
SymbolChatPreset *get_symbol_chat_preset(s32 index);
s32 is_symbol_chat_preset_in_use(const SymbolChatPreset *preset);
int TWindowSubSymbolChat__sub_80076FE0(const SymbolChatPreset *preset);
void TWindowSubSymbolChat__sub_800771B0(SymbolChatPreset *preset, s32 index);
s32 TWindowSubSymbolChat__sub_800771C4(const SymbolChatPreset *preset, s32 index);
extern SymbolChatPreset symbol_chat_receive_buffer;
extern u8 pending_symbol_chat_count;
}

#endif
