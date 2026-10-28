#include "types.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/unk/text_8019DBB4.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8019DBB4_lbl_80446470 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8019DBB4_lbl_804B90FC {
    s32 value;
    u8 remaining[0xC];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
}
extern RecoveredGlobal_8019DBB4_lbl_80446470 lbl_80446470;
extern RecoveredGlobal_8019DBB4_lbl_804B90FC forest_warp_resource_descriptor;
extern s32 forest_warp_bml_resource;
extern u8 *forest_warp_texture_list;
typedef char RecoveredGlobal_8019DBB4_lbl_80446470_size[sizeof(RecoveredGlobal_8019DBB4_lbl_80446470) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_8019DBB4_lbl_804B90FC_size[sizeof(RecoveredGlobal_8019DBB4_lbl_804B90FC) == 0x10 ? 1 : -1];
void load_forest_warp_resources(void) {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &forest_warp_resource_descriptor.value, 0, 0, 0));
    }
    forest_warp_bml_resource = var_r0;
    forest_warp_texture_list = load_gvm_texture_file((s32) &lbl_80446470.value);
}
