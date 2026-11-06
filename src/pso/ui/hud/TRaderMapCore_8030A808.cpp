#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"

extern "C" {

s32 is_split_screen();

s32 TRaderMapCore::is_not_split_screen() {
    return (u32)__cntlzw((u32)(1 - is_split_screen())) >> 5;
}

}
