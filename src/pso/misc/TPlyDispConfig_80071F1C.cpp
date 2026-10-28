#include "types.h"
#include "pso/TPlyDispData.h"
#include "pso/misc/TPlyDispConfig_80071F1C.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"

extern "C" {

void fn_80071F90(void *);

s32 TPlyDispConfig::free_if_valid(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

void *__ct__14TPlyDispConfigFv(void *arg0) {
    fn_80071F90(arg0);
    fn_80071F90((void *)((char *)arg0 + 36));
    return arg0;
}

}
