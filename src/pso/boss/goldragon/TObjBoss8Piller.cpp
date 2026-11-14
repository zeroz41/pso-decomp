#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/goldragon/TObjBoss8Piller.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/vector.h"
#include <stdlib.h>
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"

const char *bm_obj_boss8_piller_model_names[5] = {
    "fe_obj_gol_hasira5m.nj", "fe_obj_gol_hasira1m.nj", "fe_obj_gol_hasira5m_m.nj", "fe_obj_gol_hasira1m_m.nj", NULL,
};
const char *bm_obj_boss8_piller_motion_names[3] = { "fe_obj_gol_hasira5m.njm", "fe_obj_gol_hasira1m.njm", NULL };
BmlResourceDescriptor bm_obj_boss8_piller_resource_descriptor = {
    "bm_obj_boss8_piller.bml", bm_obj_boss8_piller_model_names, bm_obj_boss8_piller_motion_names, 4, 2,
};
const char *TObjBoss8Piller__class_name = "TObjBoss8Piller";

extern "C" {

u32 TObjBoss8Piller__shared_resource;
u8 *get_enemy_entity(u16 arg0);
s32 TBoss8Dragon__sub_802FB1B0(int, f32, void *);
s32 post_translate_matrix(void *);
s32 scale_matrix(int, f32, f32, f32);
s32 draw_model_motion(int, int, f32);
s32 push_matrix();


void TObjBoss8Piller::render() {
    u8 *arg0 = (u8 *)this;
    s32 var_r31;

    if (TObjPlayer::is_any_teammate_in_state() == 0) {
        if (is_split_screen() != 0) {
            var_r31 = *(s32 *)((s8 *)(*(void **)((s8 *)TObjBoss8Piller__shared_resource + 0x42C)) + 0x28);
        } else {
            var_r31 = *(s32 *)((s8 *)(*(void **)((s8 *)TObjBoss8Piller__shared_resource + 0x42C)) + 8);
        }
        TObjFish::set_global_param((s32)((void *) (*(s32 *)((s8 *)(*(void **)((s8 *)TObjBoss8Piller__shared_resource + 0x42C)) + 0xC))));
        push_matrix();
        post_translate_matrix(arg0 + 0x1C);
        scale_matrix(0, 1.0f, 1.0f, 1.0f);
        draw_model_motion(var_r31, (int) (*(s32 *)((s8 *)arg0 + 0x2C)), (f32) (*(f32 *)((s8 *)arg0 + 0x28)));
        pop_matrix();
        set_default_alpha_blend();
    }
}
void TObjBoss8Piller::run_task() {
    u8 *arg0 = (u8 *)this;
    u32 enemy_entity;
    u32 temp_r3_2;
    *(f32 *)((s8 *)arg0 + 0x28) += 1.0f;
    enemy_entity = (u32)get_enemy_entity((*(u16 *)((s8 *)arg0 + 0x30)));
    if (enemy_entity != 0U) {
        TBoss8Dragon__sub_802FB1B0(enemy_entity, 25.0f, arg0 + 0x1C);
    }
    temp_r3_2 = *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x2C)) + 4) - 1;
    if (*(f32 *)((s8 *)arg0 + 0x28) >= (f32) temp_r3_2) {
        *(f32 *)((s8 *)arg0 + 0x28) = (f32) temp_r3_2;
        ((TObject *)arg0)->queue_destruction();
    }
}

}

TObjBoss8Piller::~TObjBoss8Piller() {}


struct RecoveredGlobal_8030AF60___vt__15TObjBoss8Piller {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_8030AF60___vt__15TObjBoss8Piller __vt__15TObjBoss8Piller;
void free_bin_model_request(void*, int);

typedef char RecoveredGlobal_8030AF60___vt__15TObjBoss8Piller_size[sizeof(RecoveredGlobal_8030AF60___vt__15TObjBoss8Piller) == 0x18 ? 1 : -1];
u8 *__ct__15TObjBoss8PillerFv(u8 *object, u8 *arg1, u8 *arg2, s16 arg3) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__15TObjBoss8Piller.value;
    *(const char **)((s8 *)object + 0) = TObjBoss8Piller__class_name;
    VecCopy((Vec *)(object + 0x1C), (const Vec *)arg2);
    *(f32 *)((s8 *)object + 0x20) = 0.0f;
    *(f32 *)((s8 *)object + 0x28) = 0.0f;
    *(s16 *)((s8 *)object + 0x30) = arg3;
    *(f32 *)((s8 *)object + 0x28) = (f32) (3.0f * (3.0517578e-05f * (f32) rand()));
    *(s32 *)((s8 *)object + 0x2C) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjBoss8Piller__shared_resource) + 0x430)) + 4);
    return object;
}

void TObjBoss8Piller::free_held_object() {
    if ((u32) TObjBoss8Piller__shared_resource != 0U) {
        free_bin_model_request((void*)TObjBoss8Piller__shared_resource, 1);
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

}
