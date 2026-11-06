#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"

extern "C" {

int set_window_flags__11TWindowCtrlFPvll(void*, void*, void*);

void TWindowCtrl::init_all(void* p, void* a1) { { int i; for (i = 0; i < 12; i++) { set_window_flags__11TWindowCtrlFPvll((void*)i, p, a1); } } }

}
