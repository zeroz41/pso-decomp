#include "types.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/player/TObjPlayer.h"

struct Obj_80148274 { u8 pad0[0x350]; void *anim; };

extern "C" {
u32 init_collision_body_parts(void *, void *, s32);
void *npc_default_battle_stats[9] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41a00000, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
void *npc_movement_parameters[7] = {
    (void *)0x42c80000, (void *)0x3f000000, (void *)0x400, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *npc_base_collision_body_desc[11] = {
    (void *)0x0, (void *)0x41200000, (void *)0x0, (void *)0x40a00000,
    (void *)0x0, (void *)0x0, (void *)0x30203, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void TObjNpcBase::setup_common() {
    Obj_80148274 *self = (Obj_80148274 *)this;
    ((TObjChara *)self)->set_motion_params(npc_default_battle_stats);
    this->movementParameters = npc_movement_parameters;
    init_collision_body_parts(self, npc_base_collision_body_desc, 1);
    ((TObjPlayer *)self)->register_object_by_id();
    ((TObjEnemy *)self)->update_prev_position();
    ((TBoss3VoloptHiraisin *)self)->copy_position();
    this->apply_set_params(0, 1);
}

}
