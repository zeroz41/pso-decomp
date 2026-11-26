#ifndef PSO_UI_CHAT_SYMBOLCHATCOMMAND_H
#define PSO_UI_CHAT_SYMBOLCHATCOMMAND_H

#include "types.h"

extern "C" {
const char *get_technique_name(s32 id);
}

struct Handle6x07SymbolChatPacket { u8 pad[4]; s32 f4; u32 f8; };

struct Handle6x07SymbolChatSymBody { u32 w[12]; };

struct Handle6x07SymbolChatSymPair { u32 b; u32 c; };

struct CopySymbolChatEntrySym { u32 a; Handle6x07SymbolChatSymPair mid; Handle6x07SymbolChatSymBody body; };

#endif
