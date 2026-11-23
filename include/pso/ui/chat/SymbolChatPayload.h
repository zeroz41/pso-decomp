#ifndef PSO_UI_CHAT_SYMBOLCHATPAYLOAD_H
#define PSO_UI_CHAT_SYMBOLCHATPAYLOAD_H

#include <stddef.h>
#include "types.h"

struct SymbolChatPart {
    s8 id;
    u8 x;
    u8 y;
    u8 flags;
};

// Shared by saved presets, stage collision presets and the 6x07 game message.
struct SymbolChatPayload {
    u32 appearance;
    u16 facial_parts[4];
    SymbolChatPart parts[12];

    void byteswap_entry();
};

LAYOUT_ASSERT(SymbolChatPartSize, sizeof(SymbolChatPart) == 4);
LAYOUT_ASSERT(SymbolChatPayloadSize, sizeof(SymbolChatPayload) == 0x3C);
LAYOUT_ASSERT(SymbolChatPayloadFacialPartsOffset, offsetof(SymbolChatPayload, facial_parts) == 4);
LAYOUT_ASSERT(SymbolChatPayloadPartsOffset, offsetof(SymbolChatPayload, parts) == 0xC);

#endif
