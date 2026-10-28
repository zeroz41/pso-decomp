#include "types.h"
#include "pso/object/TObjGbAdvance.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80187DC8_lbl_804B6228 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80187DC8_lbl_804B6228_size[sizeof(RecoveredGlobal_80187DC8_lbl_804B6228) == 0x10 ? 1 : -1];

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80187DC8_lbl_804B6228 bm_obj_gba_resource_descriptor;
extern u32 TObjGbAdvance__data_805D5B74;
void TLobby__sub_8001FE7C(void*, int);

void TObjGbAdvance::free_shared_data() {
    if ((u32) TObjGbAdvance__data_805D5B74 != 0U) {
        TLobby__sub_8001FE7C((void*)TObjGbAdvance__data_805D5B74, 1);
        TObjGbAdvance__data_805D5B74 = 0U;
    }
}
void TObjGbAdvance::load_resource_instance() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &bm_obj_gba_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjGbAdvance__data_805D5B74) = var_r0;
}

}
