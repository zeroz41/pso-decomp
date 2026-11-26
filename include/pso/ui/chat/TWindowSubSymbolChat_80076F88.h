#ifndef PSO_UI_CHAT_TWINDOWSUBSYMBOLCHAT_80076F88_H
#define PSO_UI_CHAT_TWINDOWSUBSYMBOLCHAT_80076F88_H

#include "pso/ui/chat/SymbolChatPreset.h"

void clear_received_symbol_chat(void);

extern "C" {
void symbol_chat_on_floor_free_stub(void);
}

void init_symbol_chat_header(void *p);

#endif
