#include "types.h"
#include "pso/ui/hud/TLoadingCur.h"

extern "C" {

s32 pack_color_bits__13TRaderMapCoreFll();

u8 TLoadingCur::is_flag_set() {
    return (u8) ((*(s32 *)((s8 *)this + 0x48) & pack_color_bits__13TRaderMapCoreFll()) != 0);
}

}
