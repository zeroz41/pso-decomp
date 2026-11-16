#include "types.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/system/task/TMainTask.h"

extern "C" {

u32 __nw__7TObjectFUl(s32);

extern u32 TAdDialingGC__instance;

void TAdDialingGC::create() {
    void *ad_dialing_gc;

    if ((u32) TAdDialingGC__instance == 0U) {
        ad_dialing_gc = (void *) __nw__7TObjectFUl(0xA8);
        if (ad_dialing_gc != NULL) {
            TAdDialingGC__ct((TAdDialingGC *)ad_dialing_gc, tl_window);
        }
    }
}

}
