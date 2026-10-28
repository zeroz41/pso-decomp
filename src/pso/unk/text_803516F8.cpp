#include "types.h"
#include "pso/unk/text_803516F8.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_803516F8_lbl_804F0E4C { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_803516F8_lbl_804F0E4C_size[sizeof(RecoveredGlobal_803516F8_lbl_804F0E4C) == 0x10 ? 1 : -1];

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_803516F8_lbl_804F0E4C bm_butterfly_lobby_resource_descriptor;
extern s32 lobby_butterfly_bml_resource;
void fn_803516F8(void) {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_butterfly_lobby_resource_descriptor.value, 0, 0, 0));
    }
    lobby_butterfly_bml_resource = var_r0;
}

}
