#include "types.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/system/task/TMainTask.h"

extern "C" {


extern u32 TAdDialingGC__instance;

void TAdDialingGC::create() {
    void *ad_dialing_gc;

    if ((u32) TAdDialingGC__instance == 0U) {
        ad_dialing_gc = (void *)new TAdDialingGC(tl_window);
    }
}

}
