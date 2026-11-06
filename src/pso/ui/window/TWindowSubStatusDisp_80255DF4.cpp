#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowInputNumber.h"

s16 TWindowSubStatusDisp::get_item_type() { return *(s16*)((char*)this + 0x2fa); }
s16 TWindowSubStatusDisp::get_field_2F8() { return *(s16*)((char*)this + 0x2f8); }
s16 TWindowSubStatusDisp::get_stat() { return *(s16*)((char*)this + 0x2f2); }

s16 TWindowSubStatusDisp::get_value() { return *(s16*)((char*)this + 0x2ce); }
