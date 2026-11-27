#ifndef PSO_UI_CHAT_SYMBOLCHATCOMMAND_H
#define PSO_UI_CHAT_SYMBOLCHATCOMMAND_H

#include "types.h"

extern "C" {
const char *get_technique_name(s32 id);
}

struct G_SymbolChat_6x07;

void handle_6x07_symbol_chat(G_SymbolChat_6x07 *command);

#endif
