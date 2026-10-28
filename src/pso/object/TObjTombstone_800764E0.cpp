#include "types.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TObjTombstone.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern char lbl_80438748[];
extern char lbl_8043875C[];
extern const char *re_b_mark_base_model_names[2];
extern BmlResourceDescriptor tombstone_resource_descriptor;
extern const char *re_b_mark_base_motion_names[1];

struct RecoveredGlobal_800765B4_lbl_8048D240 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_800765B4_lbl_8048D240_size[sizeof(RecoveredGlobal_800765B4_lbl_8048D240) == 0x10 ? 1 : -1];

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 TObjTombstone__shared_resource_object;
void TLobby__sub_8001FE7C(void*, int);
s32 __ct__13TUnk_804AF8A0FP7TObject();

extern s32 __vt__13TObjTombstone[];
extern const char* TObjTombstone__class_name;
extern s32 local_client_id;
extern s32 TLobby__designated_client_id;

void *TObjTombstone::init(s32 arg1, s32 arg2, s32 arg3) {
    __ct__13TUnk_804AF8A0FP7TObject();
    *(s32 **)((s8 *)this + 0x18) = __vt__13TObjTombstone;
    *(s32 *)&this->m_name = (s32) TObjTombstone__class_name;
    if ((u32) TObjTombstone__shared_resource_object == 0U) {
        return this;
    }
    setup(arg2, arg3);
    init_parts();
    this->m_234 = 0;
    if ((s32) local_client_id != (s32) TLobby__designated_client_id) {
        this->m_234 = 1;
    }
    return this;
}

void TObjTombstone::destroy() {
    if ((u32) TObjTombstone__shared_resource_object != 0U) {
        TLobby__sub_8001FE7C((void*)TObjTombstone__shared_resource_object, 1);
        TObjTombstone__shared_resource_object = 0U;
        TObjTombstone::reset_matrix();
    }
}
void TObjTombstone::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    if ((void *) (*(u8 * *)&TObjTombstone__shared_resource_object) == NULL) {
        temp_r3 = (int)::operator new(0x440);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &tombstone_resource_descriptor, 0, 0, 0));
        }
        (*(u8 * *)&TObjTombstone__shared_resource_object) = (unsigned char *) ((void *) var_r0);
        TObjTombstone::reset_matrix();
    }
}

__declspec(section ".data") const char *re_b_mark_base_model_names[2] = { lbl_80438748, NULL };
BmlResourceDescriptor tombstone_resource_descriptor = { lbl_8043875C, re_b_mark_base_model_names, re_b_mark_base_motion_names, 1, 0 };
__declspec(section ".sdata") const char *re_b_mark_base_motion_names[1] = { NULL };
extern const char TObjTombstone__class_name_string[];
const char* TObjTombstone__class_name = TObjTombstone__class_name_string;
}
