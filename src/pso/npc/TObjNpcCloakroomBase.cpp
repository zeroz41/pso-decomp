#include "pso/system/SoundEffect.h"
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcCloakroomBase.h"
#include "pso/npc/TObjNpcConnoisseur.h"
#include "pso/npc/TObjNpcFemale.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/SoundEffect.h"

#pragma readonly_strings on

const char *bm_n_trunk_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_trunk_i_body_model_names[2] = { "n_trunk_i_body.nj", NULL };
BmlResourceDescriptor bm_n_trunk_i_body_resource_descriptor = { "bm_n_trunk_i_body.bml", bm_n_trunk_i_body_model_names, bm_n_trunk_i_body_motion_names, 1, 0 };
const char *TObjNpcCloakroomBase::name = "TObjNpcCloakroomBase";
BmlResource *TObjNpcCloakroomBase::static_instance;

void TObjNpcCloakroomBase::play_voice() {
    if (get_current_floor_area() != AREA_CAVE3) {
        play_sound_effect(0x40003804, &position, 0, 0);
        return;
    }
    play_sound_effect(0x40003802, &position, 0, 0);
}

void *TObjNpcCloakroomBase::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcCloakroomBase(control, set_data);
}

void TObjNpcCloakroomBase::destroy_static_instance() {
    if (static_instance != NULL) {
        delete static_instance;
        static_instance = NULL;
    }
}

void TObjNpcCloakroomBase::load_shared_resource() {
    static_instance = new BmlResource(1, &bm_n_trunk_i_body_resource_descriptor, 0, 0, NULL);
}

TObjNpcCloakroomBase::~TObjNpcCloakroomBase() {}

TObjNpcCloakroomBase::TObjNpcCloakroomBase(TObject *parent, void *set_data) : TObjNpcFemale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    model = static_instance->models->model;
    texlist = static_instance->models->texlist;
    this->setup_common();
}

f32 TObjNpcCloakroomBase::receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32) {
    return 0.0f;
}

