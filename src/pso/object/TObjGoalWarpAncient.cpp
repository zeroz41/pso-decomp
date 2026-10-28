#include "types.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/object/TObjGoalWarpAncient.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8019A9B8_lbl_80446184 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8019A9B8_lbl_804B8F60 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8019A880_lbl_804B8F70 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8019A880___vt__8TObjTank {
    s32 value;
    u8 remaining[0x38];
};

extern "C" {
extern int ancient_warp_shared_resource;
extern s32 goal_warp_ancient_gvm_texture;
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8019A9B8_lbl_80446184 lbl_80443308;
extern RecoveredGlobal_8019A9B8_lbl_804B8F60 bm_o_warp_ancient_resource_descriptor;
void TObjGoalWarpAncient__sub_8017D2D4(void* a0);
int get_bml_motion(void*, void*);
int TObjFish__sub_8001EDB0(void*, void*);
int get_bml_model(void*, void*);

typedef char RecoveredGlobal_8019A880_lbl_804B8F70_size[sizeof(RecoveredGlobal_8019A880_lbl_804B8F70) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8019A880___vt__8TObjTank_size[sizeof(RecoveredGlobal_8019A880___vt__8TObjTank) == 0x3C ? 1 : -1];
typedef char RecoveredGlobal_8019A9B8_lbl_80446184_size[sizeof(RecoveredGlobal_8019A9B8_lbl_80446184) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_8019A9B8_lbl_804B8F60_size[sizeof(RecoveredGlobal_8019A9B8_lbl_804B8F60) == 0x10 ? 1 : -1];
void TObjGoalWarpAncient::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 0x1, &bm_o_warp_ancient_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&ancient_warp_shared_resource) = var_r0;
    (*(u8 * *)&goal_warp_ancient_gvm_texture) = load_gvm_texture_file((s32) &lbl_80443308.value);
}

void TObjGoalWarpAncient::register_warp_object(void* a0) { TObjFish__sub_8001EDB0((void*)ancient_warp_shared_resource, a0); }

s32 TObjGoalWarpAncient::get_instance() {
    return goal_warp_ancient_gvm_texture;
}

void TObjGoalWarpAncient::register_warp(void* a0) { get_bml_motion((void*)ancient_warp_shared_resource, a0); }

void TObjGoalWarpAncient__sub_8017D2D4(void* a0) { get_bml_model((void*)ancient_warp_shared_resource, a0); }

}
