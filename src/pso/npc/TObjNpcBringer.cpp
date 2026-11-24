#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/npc/TObjNpcBringer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/object/TObjControl.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/BmlResource.h"
#include "pso/enemy/bringer/TObjEneDf2Bringer.h"
#include "pso/player/TObjPlayer_801542CC.h"

#pragma readonly_strings on

const char *TObjNpcBringer::name = "TObjNpcBringer";
TObjMotionAction npc_bringer_animation_table[2] = {
    {1, 0, 9, 0.8f, 1},
    {1, 0, 10, 1.0f, 1},
};
CollisionBody TObjNpcBringer::collision_body_parts[2] = {
    {{0.0f, 20.0f, 5.0f}, 7.0f, 0.0f, 0, 0x30203, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 20.0f, -5.0f}, 7.0f, 0.0f, 0, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

TObjNpcBringer::TObjNpcBringer(TObject *parent, void *set_data) : TObjNpcBase(parent) {
    m_name = name;
    apply_set_data(set_data);
    init_position_vectors();
    apply_set_params(0, 1);
    model = get_bml_model(TObjEneDf2Bringer::resource_bundle, 0);
    texlist = get_bml_texlist(TObjEneDf2Bringer::resource_bundle, 0);
    init_motion(npc_bringer_animation_table, TObjEneDf2Bringer::resource_bundle->motions, requested_action);
    movementParameters = &npc_movement_parameters;
    set_motion_params(&npc_default_battle_stats);
    init_collision_body_parts(this, collision_body_parts, 2);
    register_object_by_id();
    update_prev_position();
    copy_position();
}

TObjNpcBringer::~TObjNpcBringer() {}

void *TObjNpcBringer::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcBringer(control, set_data);
}
