#include "types.h"
#include "pso/enemy/TObjEneDD_800BABA4.h"
#include "pso/enemy/TObjEneDD_800BB804.h"
#include "pso/enemy/TObjEneEpsilon_800B92AC.h"
#include "pso/boss/TBoss5Gryphon.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/misc/TLobby.h"

struct O_800B98C0;
extern "C" {
void enemy_clear_target__12TObjEneDD_STFUs(O_800B98C0 *self, u16 _w1);
s32 enemy_tick_target_acquisition__12TObjEneDD_STFPllf(u8 *arg0, s32 *counter, s32 limit, f32 scale);
void select_nearest_target__12TObjEneDD_STFf(s32 arg0);
u16 enemy_find_nearest_player_in_range(void *, f32);
#define enemy_clear_target__12TObjEneDD_STFUs ((s32 (*)(void *))enemy_clear_target__12TObjEneDD_STFUs)
#define enemy_tick_target_acquisition__12TObjEneDD_STFPllf ((int (*)(void *, void *, void *))enemy_tick_target_acquisition__12TObjEneDD_STFPllf)
s32 transform_relative_position__9TObjEneDDFPv(void *, int);

f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
s32 is_player_entity_id(u16);
s16 approach_angle_limited(s32, s32, s32);
void VecCopy__FP3VecPC3Vec(void *, const void *);
s32 calc_shot_position__13TBoss5GryphonFPUcfff(void *, s32, f32, f32, f32);
f64 atan2_float(f32, f32);

void TObjEneEpsilon__sub_800B92AC(u8 *ene_epsilon, s32 arg1, f32 farg0) {
    s32 sp8;
    ((TObjEneEpsilon *)ene_epsilon)->fire_attack_a((s32) &sp8, arg1, farg0);
    ((TObjEneEpsilon *)(ene_epsilon))->vfunc_101((u8 *)&sp8);
}

void TObjEneEpsilon__sub_800B92F8(u8 *ene_epsilon, s32 arg1, f32 farg0) {
    s32 sp8;
    ((TObjEneEpsilon *)ene_epsilon)->fire_attack_b((s32) &sp8, arg1, farg0);
    ((TObjEneEpsilon *)(ene_epsilon))->vfunc_101((u8 *)&sp8);
}
}

void enemy_turn_and_move_on_ground(u8 *arg0, s32 arg1, f32 farg0) {
    s32 sp8;
    ((TObjEneEpsilon *)arg0)->fire_attack_b((s32) &sp8, arg1, farg0);
    ((TBoss5Gryphon *)arg0)->try_move_actor_xz_on_ground((u8 *)&sp8);
}

void TObjEneEpsilon__sub_800B9384(u8 *arg0, s32 arg1, f32 farg0) {
    s32 sp8;
    ((TObjEneEpsilon *)arg0)->fire_attack_c((s32) &sp8, arg1, farg0);
    ((TBoss5Gryphon *)arg0)->try_move_actor_xz_on_ground((u8 *)&sp8);
}

void TObjEneEpsilon::fire_attack_a(s32 out, s32 arg2, f32 farg0) {
    f32 dist;

    dist = farg0;
    turn_toward_target_direction(arg2);
    calc_wall_clamped_destination((void *)this, (void *)out, (f32)(sin_table_lookup(this->rotation_y)), (f32)((f32)cos_table_lookup(this->rotation_y)), (f32)((f32)dist));
}

void TObjEneEpsilon::fire_attack_b(s32 arg1, s32 arg2, f32 farg0) {
    f32 dz;
    f32 dist;

    dist = farg0;
    turn_toward_target_direction(arg2);
    dz = cos_table_lookup(this->rotation_y);
    calc_wall_slide_destination((void *)this, (void *)arg1, (f32)(sin_table_lookup(this->rotation_y)), (f32)((f32)dz), (f32)((f32)dist));
}

void TObjEneEpsilon::fire_attack_c(s32 arg1, s32 arg2, f32 farg0) {
    f32 temp_f30;

    temp_f30 = farg0;
    turn_toward_target_direction(arg2);
    calc_shot_position__13TBoss5GryphonFPUcfff(this, arg1, sin_table_lookup(this->rotation_y), cos_table_lookup(this->rotation_y), temp_f30);
}


void TObjEneDD::turn_toward_target_direction(s32 arg1) {
    this->rotation_y = (s32) approach_angle_limited(this->rotation_y, (s32) (10430.38043493439 * atan2_float(*(f32 *)((s8 *)this + 0x3A0), *(f32 *)((s8 *)this + 0x3A8))), arg1);
}

s32 TObjEneEpsilon::update_death_check() {
    if ((this->vfunc_99() == 0) && (is_player_entity_id(this->m_38c) == 0)) {
        enemy_clear_target__12TObjEneDD_STFUs(this);
        return 0;
    }
    return enemy_validate_retained_target((u8 *)this);
}

s32 enemy_validate_retained_target(u8 *ene_dd_st) {
    if (tick_period_counter((s32)ene_dd_st, (s32 *)(ene_dd_st + 0x3B8), (*(s32 *)((s8 *)ene_dd_st + 0x3BC))) != 0) {
        if (transform_relative_position__9TObjEneDDFPv(ene_dd_st, (int) (*(s32 *)((s8 *)ene_dd_st + 0x390))) != 0) {
            return 1;
        }
        goto block_5;
    }
    if (((TObjEneDD_ST *)ene_dd_st)->enemy_has_live_target() != 0) {
        return 1;
    }
block_5:
    enemy_clear_target__12TObjEneDD_STFUs(ene_dd_st);
    return 0;
}

void TObjEneDD_ST::enemy_init_validate_period(s32 arg1) {
    *(s32 *)((s8 *)((u8 *)this) + 0x3BC) = arg1;
    *(s32 *)((s8 *)((u8 *)this) + 0x3B8) = (s32) ((this->entity_id + 3) % *(s32 *)((s8 *)((u8 *)this) + 0x3BC));
}

void TObjEneDD::set_target_destination(const Vec *position) { VecCopy__FP3VecPC3Vec((char *)this + 0x394, position); }
void TObjEneDD_ST::enemy_copy_target_destination() {
    u32 temp_r4;
    temp_r4 = *(u32 *)((s8 *)((u8 *)this) + 0x390);
    if (temp_r4 != 0U) {
        set_target_destination((const Vec *)(temp_r4 + 0x38));
    }
}

#undef enemy_clear_target__12TObjEneDD_STFUs
#undef enemy_tick_target_acquisition__12TObjEneDD_STFPllf

#define enemy_clear_target__12TObjEneDD_STFUs ((s32 (*)(void *))enemy_clear_target__12TObjEneDD_STFUs)

s32 TObjEneDD_ST::update_linked_position(f32 scale) {
    return enemy_tick_target_acquisition__12TObjEneDD_STFPllf((u8 *)this, (s32 *)((u8 *)this + 0x3B0),
                               *(s32 *)((s8 *)this + 0x3B4), scale);
}
s32 TObjEneDD_ST::enemy_tick_target_acquisition(s32 *counter, s32 limit, f32 scale) {
    s32 var_r31;
    if (tick_period_counter((s32)this, counter, limit) != 0) {
        var_r31 = this->vfunc_104(scale);
    } else {
        var_r31 = enemy_has_live_target();
        if (var_r31 == 0) {
            enemy_clear_target__12TObjEneDD_STFUs(this);
        }
    }
    return var_r31;
}

#undef enemy_clear_target__12TObjEneDD_STFUs

s32 TObjEneDD_ST::select_nearest_target(f32 distance) {
    u16 target = enemy_find_nearest_player_in_range(this, distance);
    return enemy_bind_or_clear_target(this, target);
}


extern "C" {

u16 set_squared_value__9TObjEneDDFf(void *, f32);

s32 TObjEneDD_ST::select_and_apply_target(f32 farg0) {
    u16 temp_r3;
    u16 var_r4;

    if (this->vfunc_99() != 0) {
        temp_r3 = set_squared_value__9TObjEneDDFf(this, farg0);
        var_r4 = temp_r3;
        if (temp_r3 == 0xFFFF) {
            var_r4 = enemy_find_nearest_player_in_range(this, farg0);
        }
    } else {
        var_r4 = enemy_find_nearest_player_in_range(this, farg0);
    }
    return enemy_bind_or_clear_target(this, var_r4);
}

}



struct O_800B98C0 { u8 pad[0x38c]; u16 f38c; u8 pad2[2]; s32 f390; };

struct Obj_800B9958 { u8 pad[0x38c]; u16 id; u8 pad2[2]; s32 ptr; };

struct Obj_800B98D8 { u8 pad[0x38c]; u16 target_id; u8 pad2[2]; void *target; };

extern "C" {
s32 find_active_entity_by_id(u16);
void enemy_set_target_id(Obj_800B9958 *self, u16 id);
void *get_player_data__10TObjPlayerFi(s32);
u16 get_entity_id(void *);

s32 enemy_bind_or_clear_target(void *self, u16 x) {
    if (x != 0xFFFF) {
        enemy_set_target_id((Obj_800B9958 *)(self), x);
        return 1;
    }
    enemy_clear_target__12TObjEneDD_STFUs((O_800B98C0 *)(self), x);
    return 0;
}

s32 TObjEneDD_ST::vfunc_104(f32 distance) { return select_nearest_target(distance); }

void TObjEneDD_ST::enemy_init_acquire_period(s32 arg1) {
    *(s32 *)((s8 *)((u8 *)this) + 0x3B0) = (s32) (this->entity_id % arg1);
    *(s32 *)((s8 *)((u8 *)this) + 0x3B4) = arg1;
}

void TObjEneDD_ST::enemy_clear_target(u16 _w1) {
    ((O_800B98C0 *)this)->f390 = 0;
    ((O_800B98C0 *)this)->f38c = 0xFFFF;
}

void TObjEneDD_ST::set_target_player(void *player) {
    Obj_800B98D8 *self = (Obj_800B98D8 *)this;
    s32 n;
    s32 i;
    self->target_id = 0xFFFF;
    self->target = 0;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        if (player == get_player_data__10TObjPlayerFi(i)) {
            self->target_id = get_entity_id(player);
            self->target = player;
            return;
        }
    }
}

void enemy_set_target_id(Obj_800B9958 *self, u16 id) {
    self->id = id;
    if (id != 0xFFFF) {
        self->ptr = find_active_entity_by_id(self->id);
    } else {
        self->id = 0xFFFF;
        self->ptr = 0;
    }
}

}
