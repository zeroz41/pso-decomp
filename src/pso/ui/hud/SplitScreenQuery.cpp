#include "types.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/hud/SplitScreenQuery.h"


s32 is_not_split_screen() {
    return (u32)__cntlzw((u32)(1 - is_split_screen())) >> 5;
}

