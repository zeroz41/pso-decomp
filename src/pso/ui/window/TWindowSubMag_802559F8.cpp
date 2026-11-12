#include "types.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowHelpItem.h"

extern "C" {

int fn_8026C7C0(void*);

void TWindowSubMag::update_help_item() { if (fn_8026C7C0(*(void**)((char*)this + 0x64)) != 0) { ((TWindowHelpItem *)this)->dispatch_item_help(); } }

}
