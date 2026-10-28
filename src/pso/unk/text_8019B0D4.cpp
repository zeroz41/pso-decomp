#include "types.h"
#include "pso/unk/text_8019B0D4.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8019B0D4_lbl_804B8FE0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8019B0D4_lbl_804B8FE0_size[sizeof(RecoveredGlobal_8019B0D4_lbl_804B8FE0) == 0x10 ? 1 : -1];

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8019B0D4_lbl_804B8FE0 fe_obj_tutate_resource_descriptor;
extern s32 TObjTuitate__bml_resource;
void fn_8019B0D4(void) {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &fe_obj_tutate_resource_descriptor.value, 0, 0, 0));
    }
    TObjTuitate__bml_resource = var_r0;
}

}
