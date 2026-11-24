#ifndef PSO_PLAYER_PLAYERATTACKPARAMS_H
#define PSO_PLAYER_PLAYERATTACKPARAMS_H

#include "types.h"
#include <stddef.h>
#include "pso/system/data/FlagWord.h"

// An actor's attack parameters (TObjChara::attack_params, read with
// get_attack_params_atp_min/_atp_max and get_ata). An
// equipped item keeps its own bonus in the same layout and adds it to them.
struct AttackParams {
    s16 atp_min;
    s16 atp_max;
    s16 ata;
    u8 pad_6[2];
    f32 attack_range;
    s32 attack_angle;
    f32 damage_radius;
    u8 pad_14[0x1C];

    s16 get_ata();
    void byteswap_packet();
    f32 get_attack_range();
    void set_attack_range(f32 range);
    s32 get_attack_angle();
    f32 get_damage_radius();

    void sub_ata(s32 amount);
    void sub_atp_max(s32 amount);
    void sub_atp_min(s32 amount);
    void add_ata(s32 amount);
    void add_atp_max(s32 amount);
    void add_atp_min(s32 amount);
};

LAYOUT_ASSERT(AttackParamsRangeOffset, offsetof(AttackParams, attack_range) == 0x8);
LAYOUT_ASSERT(AttackParamsAngleOffset, offsetof(AttackParams, attack_angle) == 0xC);
LAYOUT_ASSERT(AttackParamsRadiusOffset, offsetof(AttackParams, damage_radius) == 0x10);
LAYOUT_ASSERT(AttackParamsSize, sizeof(AttackParams) == 0x30);

// An actor's parameter block (TObjChara at 0x31C); an equipped item keeps
// its own bonus in the same layout and adds it to it.
struct ActorParamBlock {
    s16 values[6];
    u8 pad_c[0x10];
    s32 value_1c;

    void swap_endian();
};

class TObjChara;

// The blocks an actor points at from 0x318 and 0x31C.
ActorParamBlock *get_actor_param_block(TObjChara *actor);
AttackParams *get_actor_attack_params(TObjChara *actor);

#endif
