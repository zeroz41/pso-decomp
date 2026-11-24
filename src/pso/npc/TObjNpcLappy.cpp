#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"

#pragma readonly_strings on

#include "pso/npc/TObjNpcMaleBase.h"
#include "pso/system/task/TObject.h"
#include "pso/system/BmlResource.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/player/TObjPlayer_801542CC.h"


TObjMotionAction npc_lappy_animation_table[10] = {
    {1, 0, 5, 0.7f, 0},
    {1, 1, 9, 1.8f, 1},
    {1, 2, 6, 0.9f, 0},
    {2, 1, 8, 0.7f, 0},
    {1, 4, 3, 1.2f, 1},
    {2, 0, 0, 1.0f, 4},
    {2, 0, 1, 1.0f, 8},
    {3, 6, 2, 0.6f, 0x10},
    {2, 4, 4, 0.9f, 1},
    {2, 4, 7, 0.5f, 0},
};
CollisionBody TObjNpcLappy::collision_body_parts = {{0.0f, 7.5f, 0.0f}, 7.0f, 0.0f, 0, 0x30203, {0.0f, 0.0f, 0.0f}, 0.0f};
const char *TObjNpcLappy::name = "TObjNpcLappy";

TObjNpcLappy::TObjNpcLappy(TObject *parent, void *set_data) : TObjNpcBase(parent) {
    m_name = name;
    apply_set_data(set_data);
    init_position_vectors();
    apply_set_params(0, 1);
    model = rappy_bml_resource->models[0].model;
    texlist = rappy_bml_resource->models[0].texlist;
    init_motion(npc_lappy_animation_table, rappy_bml_resource->motions, requested_action);
    movementParameters = &npc_movement_parameters;
    set_motion_params(&npc_default_battle_stats);
    init_collision_body_parts(this, &collision_body_parts, 1);
    register_object_by_id();
    update_prev_position();
    copy_position();
}

TObjNpcLappy::~TObjNpcLappy() {}

void *TObjNpcLappy::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcLappy(control, set_data);
}

void TObjNpcLappy::request_action(s32) {
    if ((s16) this->mode != 2) {
        this->requested_action = 0;
        return;
    }
    this->requested_action = 1;
}
