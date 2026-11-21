#include "types.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/system/task/TMainTask.h"

void TAdDialingGC::create() {
    if (TAdDialingGC__instance == NULL) {
        new TAdDialingGC(tl_window);
    }
}
