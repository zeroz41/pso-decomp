#include "types.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"

void*TWindowSubStatusDisp::get_message_10(s32 index) { return (void*)get_localized_text_entry(10, index); }
