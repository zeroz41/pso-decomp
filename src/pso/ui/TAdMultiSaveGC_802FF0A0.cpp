#include "types.h"
#include "pso/ui/TAdMultiSaveGC.h"
#include "pso/TAdMultiChgGameModeGC.h"
#include "pso/TMainTask.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_802FF0D8_lbl_804E6570 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_802FF0D8_lbl_804E6570_size[sizeof(RecoveredGlobal_802FF0D8_lbl_804E6570) == 0x10 ? 1 : -1];

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_802FF0D8_lbl_804E6570 TAdMultiSaveGC__shared_resource_desc;
extern u32 admultisave_shared_model_resource;
void TLobby__sub_8001FE7C(void*, int);

void TAdMultiSaveGC::free_window() {
    if ((u32) admultisave_shared_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)admultisave_shared_model_resource, 1);
        admultisave_shared_model_resource = 0U;
    }
}

void TAdMultiSaveGC::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &TAdMultiSaveGC__shared_resource_desc.value, 0, 0, 0));
    }
    (*(s32 *)&admultisave_shared_model_resource) = var_r0;
}
void TAdMultiSaveGC::render() {
    if (TMainTask::get_render_pass() == 1) return;
}

}
