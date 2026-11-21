#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

void *TWindowBase::get_array_entry(int index) { return entry_list.items[index]; }
