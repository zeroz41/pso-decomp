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

extern "C" {
void init_collision_body_parts(void *, void *, s32);
}

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
void *lbl_804A9DA8[11] = {
    (void *)0x0, (void *)0x40f00000, (void *)0x0, (void *)0x40e00000,
    (void *)0x0, (void *)0x0, (void *)0x30203, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
const char *TObjNpcLappy__name = "TObjNpcLappy";
extern u8 *rappy_bml_resource;

TObjNpcLappy::TObjNpcLappy(TObject *parent, void *set_data) : TObjNpcBase(parent) {
    m_name = TObjNpcLappy__name;
    apply_set_data(set_data);
    init_position_vectors();
    apply_set_params(0, 1);
    *(s32 *)((u8 *)this + 0x34) = *(s32 *)(*(u8 **)(rappy_bml_resource + 0x42C) + 8);
    *(s32 *)((u8 *)this + 0x24) = *(s32 *)(*(u8 **)(rappy_bml_resource + 0x42C) + 0xC);
    init_motion(npc_lappy_animation_table, (BmlMotionEntry *)*(saddr *)(rappy_bml_resource + 0x430), *(s16 *)((u8 *)this + 0xB8));
    movementParameters = &npc_movement_parameters;
    set_motion_params(&npc_default_battle_stats);
    init_collision_body_parts(this, lbl_804A9DA8, 1);
    ((TObjPlayer *)this)->register_object_by_id();
    update_prev_position();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
}

TObjNpcLappy::~TObjNpcLappy() {}

void *TObjNpcLappy__create(void *set_data) {
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
