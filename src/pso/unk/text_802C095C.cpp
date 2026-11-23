#include "types.h"
#include "pso/object/TUnk_804E0898.h"
#include "pso/system/task/TMainTask.h"


void *TUnk_804E0898::create(void *set_data) {
    return new TUnk_804E0898(tl_05, set_data);
}

