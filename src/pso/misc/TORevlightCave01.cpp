#include "types.h"
#include "pso/misc/TORevlightCave01_801736BC.h"
#include "pso/misc/TORevlightCave01.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80173614_lbl_804B3A70 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80173614_lbl_804B3A70_size[sizeof(RecoveredGlobal_80173614_lbl_804B3A70) == 0x10 ? 1 : -1];

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80173614_lbl_804B3A70 bm_fs_obj_yukakaiten01_resource_descriptor;
extern u32 TORevlightCave01__static_model_resource;
void TLobby__sub_8001FE7C(void*, int);

extern void *tl_05;

void *TORevlightCave01::create(void *arg0) {
    return new TORevlightCave01((TObject *)tl_05, arg0);
}

void TORevlightCave01::release_static_instance() {
    if ((u32) TORevlightCave01__static_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TORevlightCave01__static_model_resource, 1);
        TORevlightCave01__static_model_resource = 0U;
    }
}
void TORevlightCave01::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_fs_obj_yukakaiten01_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TORevlightCave01__static_model_resource) = var_r0;
}

}
