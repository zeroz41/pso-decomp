#include "types.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/misc/TRaderMapCore.h"
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
extern u32 TRaderMapCore__frame_model_resource;
extern u32 TRaderMapCore__data_805D5F4C;
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8019A9B8_lbl_80446184 lbl_8044A7B8;
extern RecoveredGlobal_8019A9B8_lbl_804B8F60 obj_f_enemy_resource_descriptor;
void TLobby__sub_8001FE7C(void*, int);
s32 release_texture_list(void*);

void TRaderMapCore::free_statics() {
    if ((u32) TRaderMapCore__data_805D5F4C != 0U) {
        release_texture_list((void*)TRaderMapCore__data_805D5F4C);
        TAdSinglePlyChrSelectGC::safe_free(TRaderMapCore__data_805D5F4C);
        TRaderMapCore__data_805D5F4C = 0U;
    }
    if ((u32) TRaderMapCore__frame_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TRaderMapCore__frame_model_resource, 1);
        TRaderMapCore__frame_model_resource = 0U;
    }
}
typedef char RecoveredGlobal_8019A880_lbl_804B8F70_size[sizeof(RecoveredGlobal_8019A880_lbl_804B8F70) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8019A880___vt__8TObjTank_size[sizeof(RecoveredGlobal_8019A880___vt__8TObjTank) == 0x3C ? 1 : -1];
typedef char RecoveredGlobal_8019A9B8_lbl_80446184_size[sizeof(RecoveredGlobal_8019A9B8_lbl_80446184) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_8019A9B8_lbl_804B8F60_size[sizeof(RecoveredGlobal_8019A9B8_lbl_804B8F60) == 0x10 ? 1 : -1];
void TRaderMapCore::load_frame_texture() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &obj_f_enemy_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TRaderMapCore__frame_model_resource) = var_r0;
    (*(u8 * *)&TRaderMapCore__data_805D5F4C) = load_gvm_texture_file((s32) &lbl_8044A7B8.value);
}

}
