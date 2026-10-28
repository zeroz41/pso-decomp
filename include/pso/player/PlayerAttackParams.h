#ifndef PSO_PLAYER_PLAYERATTACKPARAMS_H
#define PSO_PLAYER_PLAYERATTACKPARAMS_H

#include "types.h"
#include "pso/system/FlagWord.h"

// An actor's attack parameters (TObjChara::m_318, read with
// get_attack_params_atp_min/_atp_max and TObjPlayer__sub_800194E8). An
// equipped item keeps its own bonus in the same layout and adds it to them.
struct AttackParams {
    s16 atp_min;
    s16 atp_max;
    s16 ata;
    u8 pad_6[0x2A];

    void sub_ata(s32 amount);
    void sub_atp_max(s32 amount);
    void sub_atp_min(s32 amount);
    void add_ata(s32 amount);
    void add_atp_max(s32 amount);
    void add_atp_min(s32 amount);
};

// An actor's parameter block (TObjChara at 0x31C); an equipped item keeps
// its own bonus in the same layout and adds it to it.
struct ActorParamBlock {
    s16 values[6];
    u8 pad_c[0x10];
    s32 value_1c;
};

class TObjChara;

// The blocks an actor points at from 0x318 and 0x31C.
ActorParamBlock *get_actor_param_block(TObjChara *actor);
AttackParams *get_actor_attack_params(TObjChara *actor);

// The player's attack state block (TObjPlayer::attack_state, at 0x7CC).
struct PlayerAttackState {
    u8 pad_0[0x8];
    // Raised to an equipped unit's TItemProUnit::evp_scale, reset to 1.0
    // when it is removed.
    f32 evp_scale;
    FlagWord flags;

    void set_evp(f32 scale);
    f32 get_evp();

    // Bit 0x20 follows the item effect pair 0x20/0x40 (TItemEquipBase::effect_flags).
    void set_item_effect();
    void clear_item_effect();
};

#endif
