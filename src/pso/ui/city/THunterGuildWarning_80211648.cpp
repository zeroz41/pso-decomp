#include "types.h"
#include "pso/ui/city/THunterGuildWarning.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/hud/TRaderMapCore.h"

extern "C" {

void queue_destruction__7TObjectFv(void *arg0);

extern u32 THunterGuildWarning__instance;

void THunterGuildWarning::queue_destruction() {
    if ((TRaderMapCore::is_not_split_screen() == 1) && ((u32) THunterGuildWarning__instance != 0U) && (((TObject *)THunterGuildWarning__instance)->all_parents_unqueued_for_destruction() != 0)) {
        queue_destruction__7TObjectFv((void *)THunterGuildWarning__instance);
    }
}

}
