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

#pragma readonly_strings on

extern "C" {


void init_collision_body_parts(void *, void *, s32);
extern u8 *TObjEneDf2Bringer__resource_bundle;
}

const char *TObjNpcBringer__name = "TObjNpcBringer";
TObjMotionAction npc_bringer_animation_table[2] = {
    {1, 0, 9, 0.8f, 1},
    {1, 0, 10, 1.0f, 1},
};
void *lbl_804A7EC0[22] = {
    (void *)0x0, (void *)0x41a00000, (void *)0x40a00000, (void *)0x40e00000,
    (void *)0x0, (void *)0x0, (void *)0x30203, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41a00000, (void *)0xc0a00000, (void *)0x40e00000, (void *)0x0,
    (void *)0x0, (void *)0x10003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};

TObjNpcBringer::TObjNpcBringer(TObject *parent, void *set_data) : TObjNpcBase(parent) {
    m_name = TObjNpcBringer__name;
    apply_set_data(set_data);
    init_position_vectors();
    apply_set_params(0, 1);
    *(s32 *)((u8 *)this + 0x34) = (saddr)get_bml_model((BmlResource *)TObjEneDf2Bringer__resource_bundle, 0);
    *(s32 *)((u8 *)this + 0x24) = (saddr)get_bml_texlist((BmlResource *)TObjEneDf2Bringer__resource_bundle, 0);
    init_motion(npc_bringer_animation_table, (BmlMotionEntry *)*(saddr *)(TObjEneDf2Bringer__resource_bundle + 0x430), *(s16 *)((u8 *)this + 0xB8));
    movementParameters = &npc_movement_parameters;
    set_motion_params(&npc_default_battle_stats);
    init_collision_body_parts(this, lbl_804A7EC0, 2);
    ((TObjPlayer *)this)->register_object_by_id();
    update_prev_position();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
}

TObjNpcBringer::~TObjNpcBringer() {}

void *TObjNpcBringer::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcBringer(control, set_data);
}
