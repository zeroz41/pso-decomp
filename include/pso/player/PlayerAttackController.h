#ifndef PSO_PLAYER_ATTACK_CONTROLLER_H
#define PSO_PLAYER_ATTACK_CONTROLLER_H
#include "types.h"
#include <stddef.h>
#include "pso/system/data/FlagWord.h"
#include "pso/player/CapturedTargetList.h"
#include <dolphin/mtx.h>
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

extern "C" {

// --- functions defined in PlayerAttackController.cpp ---
s32 TObjPlayer__sub_801D2EE8(s16 stage);
s16 TObjPlayer__sub_801D2F0C(void *record);
s16 TObjPlayer__sub_801D2F4C(s16 *stage_ptr);
s32 TObjPlayer__sub_801D2F8C(s16 stage);
void apply_anim_action__10TObjPlayerFPvi(u8 *controller, saddr player);
s32 get_first_target_position__10TObjPlayerFPvPv(void *controller, Vec *out);
void *capture_lockon_targets(PlayerAttackController *controller, TObjPlayer *player);
s32 *TObjPlayer__sub_801D345C(void *p);
void handle_6x54(void);
void handle_6x8C(void);
void handle_6x65(void);
void handle_6x8B(void);
void handle_6x64(void);
}
void begin_player_attack(u8 *controller, s32 arg1, s16 stage, s32 arg3);

#endif
