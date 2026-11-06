#include "types.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"

extern "C" {

s32 Dolphin_ARAlloc(s32);

extern s32 ad_warning_aram_base;
extern s32 TAdWarningBaseGC__aram_capacity;
extern s32 warning_aram_load_done_flag;
extern s32 TAdWarningBaseGC__aram_alloc_size;
extern s32 lobby_count_value;

void TAdWarningBaseGC::init_heap() {
    TAdWarningBaseGC__aram_capacity = 0x80000;
    ad_warning_aram_base = Dolphin_ARAlloc(0x80000);
    TAdWarningBaseGC__aram_alloc_size = 0;
    warning_aram_load_done_flag = 0;
    lobby_count_value = 0;
}

}
