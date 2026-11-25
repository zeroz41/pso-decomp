#ifndef PSO_UI_CHAT_SYMBOLCHATSPRITE_H
#define PSO_UI_CHAT_SYMBOLCHATSPRITE_H

#include <stddef.h>
#include "types.h"

// A sprite entry of a symbol chat window's layout: its position and size, the shortcut part it
// shows (entry) and its draw kind.
struct SymbolChatSprite {
    u8 pad0[0x8];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    f32 unk_18;
    u8 pad1c[0x10];
    s32 entry;
    u8 pad30[0x4];
    s32 kind;
};

LAYOUT_ASSERT(SymbolChatSprite_entry_offset, offsetof(SymbolChatSprite, entry) == 0x2C);
LAYOUT_ASSERT(SymbolChatSprite_kind_offset, offsetof(SymbolChatSprite, kind) == 0x34);

#endif
