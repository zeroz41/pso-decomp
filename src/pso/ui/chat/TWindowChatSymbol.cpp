#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/chat/TWindowChatSymbol.h"

extern "C" {

int initialize_subwindow__9TWindowDDFv(void*);

void TWindowChatSymbol::run_task() { initialize_subwindow__9TWindowDDFv(this); update_fade(); update_window_entry_list((char*)this + 0x24); }

}
