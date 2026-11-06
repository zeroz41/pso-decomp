#include "types.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/system/task/TMainTask.h"

extern "C" {

u32 __nw__7TObjectFUl(s32);

extern u32 TAdDialingGC__instance;

void TAdDialingGC::create() {
    void *temp_r3;

    if ((u32) TAdDialingGC__instance == 0U) {
        temp_r3 = (void *) __nw__7TObjectFUl(0xA8);
        if (temp_r3 != NULL) {
            TAdDialingGC__ct((TAdDialingGC *)temp_r3, tl_window);
        }
    }
}

}
