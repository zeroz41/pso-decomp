#include "types.h"
#include "pso/ui/city/THunterGuildWarning.h"
#include "pso/ui/hud/TRaderMapCore.h"

extern "C" {

s32 __ct__19THunterGuildWarningFP7TObjectPv(void *, void *, s32);
void *__nw__7TObjectFUl(s32);

extern u32 THunterGuildWarning__instance;
extern void *tl_05;

void THunterGuildWarning::create_instance(s32 arg0) {
    if ((TRaderMapCore::is_not_split_screen() == 1) && ((u32) THunterGuildWarning__instance == 0U)) {
        void *obj = __nw__7TObjectFUl(0x34);
        if (obj != 0) {
            __ct__19THunterGuildWarningFP7TObjectPv(obj, tl_05, arg0);
        }
    }
}

}
