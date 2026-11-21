#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcCloakroomBase.h"
#include "pso/npc/TObjNpcConnoisseur.h"
#include "pso/npc/TUnk_804A8640.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"

#pragma readonly_strings on

extern "C" {
extern const char *bm_n_trunk_i_body_motion_names[1];
extern const char *bm_n_trunk_i_body_model_names[2];
const char *bm_n_trunk_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_trunk_i_body_model_names[2] = { "n_trunk_i_body.nj", NULL };
BmlResourceDescriptor bm_n_trunk_i_body_resource_descriptor = { "bm_n_trunk_i_body.bml", bm_n_trunk_i_body_model_names, bm_n_trunk_i_body_motion_names, 1, 0 };
const char *TObjNpcCloakroomBase__name = "TObjNpcCloakroomBase";
u32 TObjNpcCloakroomBase__static_instance;
}


extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
s32 play_sound_effect(s32, s32, s32, s32);
void free_bin_model_request(void*, int);

void TObjNpcCloakroomBase::play_voice() {
    s32 arg0 = (s32)this;
    if (get_current_floor_area() != AREA_CAVE3) {
        play_sound_effect(0x40003804, arg0 + 0x38, 0, 0);
        return;
    }
    play_sound_effect(0x40003802, arg0 + 0x38, 0, 0);
}

extern void *tl_04;

void *TObjNpcCloakroomBase::create(void *set_data) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjNpcCloakroomBase(control, set_data);
}

void TObjNpcCloakroomBase::destroy_static_instance() {
    if ((u32) TObjNpcCloakroomBase__static_instance != 0U) {
        free_bin_model_request((void*)TObjNpcCloakroomBase__static_instance, 1);
        TObjNpcCloakroomBase__static_instance = 0U;
    }
}

void TObjNpcCloakroomBase::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_n_trunk_i_body_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcCloakroomBase__static_instance) = var_r0;
}

}
TObjNpcCloakroomBase::~TObjNpcCloakroomBase() {}


TObjNpcCloakroomBase::TObjNpcCloakroomBase(TObject *parent, void *arg2) : TUnk_804A8640(parent) {
    *(s32 *)((s8 *)this + 0) = (s32) TObjNpcCloakroomBase__name;
    ((TObjNpcCloakroomBase *)this)->apply_set_data(arg2);
    ((TObjPlayer *)this)->init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcCloakroomBase__static_instance) + 0x42C)) + 8);
    ((TObjNpcCloakroomBase *)this)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcCloakroomBase__static_instance) + 0x42C)) + 0xC);
    ((TObjNpcBase *)this)->setup_common();
}

f32 TObjNpcCloakroomBase::receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32) {
    return 0.0f;
}

void *TObjNpcConnoisseur__create(void *set_data) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjNpcConnoisseur(control, set_data);
}

