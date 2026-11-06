#include "types.h"
#include "pso/ui/window/TWindowSubMag.h"

extern "C" {

int dispatch_item_help__15TWindowHelpItemFv(void*);
int fn_8026C7C0(void*);

void TWindowSubMag::update_help_item() { if (fn_8026C7C0(*(void**)((char*)this + 0x64)) != 0) { dispatch_item_help__15TWindowHelpItemFv(this); } }

}
