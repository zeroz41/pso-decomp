#include "types.h"
#include <dolphin/ar.h>
#include "pso/system/GbaDownloadRuntime.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"

void TAdWarningBaseGC::init_heap() {
    TAdWarningBaseGC__aram_capacity = 0x80000;
    ad_warning_aram_base = ARAlloc(0x80000);
    TAdWarningBaseGC__aram_alloc_size = 0;
    warning_aram_load_done_flag = 0;
    lobby_count_value = 0;
}
