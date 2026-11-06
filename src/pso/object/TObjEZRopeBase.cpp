#include "pso/object/TObjEZRopeBase.h"
#include "pso/TObject.h"
#include "pso/object/TObjHMS_EZRope_Player.h"
#include "pso/object/TObjEZBoneRotPlayer.h"
#include "pso/player/TObjPlayer_800FEFCC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" void run_task__21TObjHMS_EZRope_PlayerFv();
extern "C" void render_shadows__7TObjectFv();
f32 ezrope_chunk_material_color_table[12] = {
    0.5f, 1.0f, 1.0f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
};
f32 TObjEZBoneRotPlayer__chain_gravity[3] = { 0.0f, -0.75f, 0.0f };
#pragma push
#pragma force_active on
void *__vt__21TObjHMS_EZRope_Player[6] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__21TObjHMS_EZRope_PlayerFv, (void *)&run_task__21TObjHMS_EZRope_PlayerFv,
    (void *)&render__21TObjHMS_EZRope_PlayerFv, (void *)&render_shadows__7TObjectFv,
};
#pragma pop

TObjEZRopeBase::~TObjEZRopeBase() {
    if (m_2c != nullptr) { TAdSinglePlyChrSelectGC::safe_free((u32)m_2c); m_2c = nullptr; }
}

#include "types.h"

extern "C" {

void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__14TObjEZRopeBase[];
extern void *TObjEZRopeBase__name;

void *TObjEZRopeBase__ct(void *obj_ez_rope_base) {
    __ct__7TObjectFP7TObject(obj_ez_rope_base);
    *(s32 **)((s8 *)obj_ez_rope_base + 0x18) = __vt__14TObjEZRopeBase;
    *(void * *)&((TObjEZRopeBase *)obj_ez_rope_base)->m_name = TObjEZRopeBase__name;
    *(u32 *)((s8 *)obj_ez_rope_base + 0x1C) = 0;
    *(u32 *)((s8 *)obj_ez_rope_base + 0x20) = 0;
    *(u32 *)((s8 *)obj_ez_rope_base + 0x24) = 0;
    ((TObjEZRopeBase *)obj_ez_rope_base)->m_28 = 0;
    *(u32 *)((s8 *)obj_ez_rope_base + 0x2C) = 0;
    return obj_ez_rope_base;
}

extern char lbl_8043DF18[];
void *TObjEZRopeBase__name = lbl_8043DF18;
}
