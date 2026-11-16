#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/hud/TRaderMapCore_801A6CEC.h"

extern "C" {

s32 pack_color_bits__13TRaderMapCoreFll();

u8 TAdSinglePlyChrSelectGC::test_flag_4c() {
    return (u8) ((this->m_4c & pack_color_bits__13TRaderMapCoreFll()) != 0);
}

s32 TWindowShortListCtrl__check_controller_button(void *pad, s32 mask) {
    return (*(s32 *)((s8 *)pad + 0x4C) & pack_flags__13TRaderMapCoreFii((s32)pad, mask)) != 0;
}

}
