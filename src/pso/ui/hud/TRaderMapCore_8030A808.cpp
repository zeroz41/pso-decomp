#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/player/TObjPlayer_80011014.h"

extern "C" {


s32 TRaderMapCore::is_not_split_screen() {
    return (u32)__cntlzw((u32)(1 - is_split_screen())) >> 5;
}

}
