#ifndef PSO_UI_CHAT_SYMBOLCHATCOMMAND_H
#define PSO_UI_CHAT_SYMBOLCHATCOMMAND_H

#include "types.h"

extern "C" {
const char *get_technique_name(s32 id);
}

struct G_SymbolChat_6x07;

void handle_6x07_symbol_chat(G_SymbolChat_6x07 *command);

struct Handle6x07SymbolChatSymBody { u32 w[12]; };

struct Handle6x07SymbolChatSymPair { u32 b; u32 c; };

struct CopySymbolChatEntrySym { u32 a; Handle6x07SymbolChatSymPair mid; Handle6x07SymbolChatSymBody body; };

#endif
