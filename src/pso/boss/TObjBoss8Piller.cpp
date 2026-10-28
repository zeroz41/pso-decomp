#include "pso/TObjBoss8Piller.h"
#include "pso/boss/TObjBoss8Piller.h"
#include "pso/system/vector.h"

TObjBoss8Piller::~TObjBoss8Piller() {}

#include "types.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8030AF60___vt__15TObjBoss8Piller {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern BmlResourceDescriptor bm_obj_boss8_piller_resource_descriptor;
extern u32 TObjBoss8Piller__shared_resource;
void __ct__7TObjectFP7TObject(void *, void *);
s32 rand(void);
extern RecoveredGlobal_8030AF60___vt__15TObjBoss8Piller __vt__15TObjBoss8Piller;
extern s32 TObjBoss8Piller__class_name;
extern const f32 lbl_805DF158;
extern const f32 lbl_805DF15C;
extern const f32 lbl_805DF160;
void TLobby__sub_8001FE7C(void*, int);

typedef char RecoveredGlobal_8030AF60___vt__15TObjBoss8Piller_size[sizeof(RecoveredGlobal_8030AF60___vt__15TObjBoss8Piller) == 0x18 ? 1 : -1];
u8 *__ct__15TObjBoss8PillerFv(u8 *object, u8 *arg1, u8 *arg2, s16 arg3) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__15TObjBoss8Piller.value;
    *(s32 *)((s8 *)object + 0) = (s32) TObjBoss8Piller__class_name;
    VecCopy((Vec *)(object + 0x1C), (const Vec *)arg2);
    *(f32 *)((s8 *)object + 0x20) = (f32) lbl_805DF158;
    *(f32 *)((s8 *)object + 0x28) = (f32) lbl_805DF158;
    *(s16 *)((s8 *)object + 0x30) = arg3;
    *(f32 *)((s8 *)object + 0x28) = (f32) (lbl_805DF15C * (lbl_805DF160 * (f32) rand()));
    *(s32 *)((s8 *)object + 0x2C) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjBoss8Piller__shared_resource) + 0x430)) + 4);
    return object;
}

void TObjBoss8Piller::free_held_object() {
    if ((u32) TObjBoss8Piller__shared_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjBoss8Piller__shared_resource, 1);
        TObjBoss8Piller__shared_resource = 0U;
    }
}
void TObjBoss8Piller::load_resource_descriptor() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &bm_obj_boss8_piller_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjBoss8Piller__shared_resource) = var_r0;
}

extern char lbl_80475658[];
extern char lbl_80475670[];
extern char lbl_80475688[];
extern char lbl_804756A4[];
extern char lbl_804756C0[];
extern char lbl_804756D8[];
extern char lbl_804756F0[];
__declspec(section ".data") const char *bm_obj_boss8_piller_model_names[5] = { lbl_80475658, lbl_80475670, lbl_80475688, lbl_804756A4, NULL };
__declspec(section ".data") const char *bm_obj_boss8_piller_motion_names[3] = { lbl_804756C0, lbl_804756D8, NULL };
BmlResourceDescriptor bm_obj_boss8_piller_resource_descriptor = { lbl_804756F0, bm_obj_boss8_piller_model_names, bm_obj_boss8_piller_motion_names, 4, 2 };
}
