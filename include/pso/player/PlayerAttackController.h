#ifndef PSO_PLAYER_ATTACK_CONTROLLER_H
#define PSO_PLAYER_ATTACK_CONTROLLER_H
#include "types.h"
#include <stddef.h>
#include "pso/system/data/FlagWord.h"
#include "pso/player/CapturedTargetList.h"
struct TObjPlayer;

// The player's attack state block (TObjPlayer::attack_state).
struct PlayerAttackController {
    s16 attack_kind;
    s16 queued_kind;
    f32 pad_4;
    // Raised to an equipped unit's TItemProUnit::evp_scale, reset to 1.0
    // when it is removed.
    f32 evp_scale;
    s32 flags;  // FlagWord bits, set and cleared in place; init builds the word
    s16 pending_stage;
    s16 hit_count;
    s32 pad_14[3];
    f32 pad_20[4];
    CapturedTargetList lockon_targets;

    // Builds the block in place (TObjPlayer's constructors call it in member order).
    PlayerAttackController *init();
    void reset();

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

    // Counts up the pending stage, held at 2.
    void advance_and_clamp_state();
    void set_saved_attack_stage(s16 stage);
    int is_flag32_clear();
};
LAYOUT_ASSERT(AttackControllerEvpScale, offsetof(PlayerAttackController, evp_scale) == 0x08);
LAYOUT_ASSERT(AttackControllerFlags, offsetof(PlayerAttackController, flags) == 0x0C);
LAYOUT_ASSERT(AttackControllerStage, offsetof(PlayerAttackController, pending_stage) == 0x10);
LAYOUT_ASSERT(AttackControllerTargets, offsetof(PlayerAttackController, lockon_targets) == 0x30);
LAYOUT_ASSERT(AttackControllerSize, sizeof(PlayerAttackController) == 0x5C);
// Indexed by PlayerAttackController::attack_kind.
extern f32 attack_damage_scale_table[3];
extern f32 attack_type_accuracy_scales[3];
// Indexed by the validated attack stage.
extern f32 attack_combo_accuracy_multipliers[4];

extern "C" void queue_physical_attack_input(PlayerAttackController *controller,
                                            TObjPlayer *player, s32 channel, s16 maximum_stage);
#endif
