#include "types.h"
#include "pso/ui/city/THunterGuildWarning.h"

extern s32 THunterGuildWarning__instance;

u8 THunterGuildWarning::is_active() {
    return (u8) (THunterGuildWarning__instance != 0);
}
