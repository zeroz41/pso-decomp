#ifndef PSO_PLAYER_ATTACK_CONTROLLER_H
#define PSO_PLAYER_ATTACK_CONTROLLER_H
#include "types.h"
#include <stddef.h>
#include "pso/system/data/FlagWord.h"
struct TObjPlayer;

// The player's attack state block (TObjPlayer::attack_state).
struct PlayerAttackController {
    s16 attack_kind;
    s16 queued_kind;
    u8 pad_4[4];
    // Raised to an equipped unit's TItemProUnit::evp_scale, reset to 1.0
    // when it is removed.
    f32 evp_scale;
    s32 flags;  // FlagWord bits, set and cleared in place; the player never constructs a FlagWord here
    s16 pending_stage;
    s16 hit_count;
    u8 pad_14[0x0C];

    // The pending stage, 0 when it is not valid.
    s16 get_validated_attack_stage();
    f32 get_attack_damage_scale();
    f32 get_attack_accuracy_scale();
    f32 calc_attack_stage_multiplier(s32 kind);

    void set_evp(f32 scale);
    f32 get_evp();

    // Bit 0x20 follows the item effect pair 0x20/0x40 (TItemEquipBase::effect_flags).
    void set_item_effect();
    void clear_item_effect();
};
LAYOUT_ASSERT(AttackControllerEvpScale, offsetof(PlayerAttackController, evp_scale) == 0x08);
LAYOUT_ASSERT(AttackControllerFlags, offsetof(PlayerAttackController, flags) == 0x0C);
LAYOUT_ASSERT(AttackControllerStage, offsetof(PlayerAttackController, pending_stage) == 0x10);
LAYOUT_ASSERT(AttackControllerSize, sizeof(PlayerAttackController) == 0x20);
// Indexed by PlayerAttackController::attack_kind.
extern f32 attack_damage_scale_table[3];
extern f32 attack_type_accuracy_scales[3];
// Indexed by the validated attack stage.
extern f32 attack_combo_accuracy_multipliers[4];

extern "C" void queue_physical_attack_input(PlayerAttackController *controller,
                                            TObjPlayer *player, s32 channel, s16 maximum_stage);
#endif
