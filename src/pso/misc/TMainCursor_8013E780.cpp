#include "types.h"
#include "pso/misc/TMainCursor.h"

extern "C" {
int set_target_index__11TMainCursorFs(void*, void* a1);

extern "C" {
s32 init_gc_tag();

}

int TMainCursor::set_target_index_at_60(void* _w1) { return set_target_index__11TMainCursorFs((void*)((char*)this + 0x60), _w1); }

#include "pso/ui/TAdRicoRing.h"
#include "pso/misc/TLockOnCursor.h"
#include "pso/misc/TWindowActionPalette.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 TMainCursor::reset() {
    s32 arg0 = (s32)this;
    init_gc_tag();
    ((TMainCursor *)arg0)->reset_target();
    return arg0;
}

}

}
