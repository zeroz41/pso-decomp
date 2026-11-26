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
    // Scales the attack animation: evp_scale, a quarter faster for kinds 1 and 2.
    f32 attack_speed;
    // Raised to an equipped unit's TItemProUnit::evp_scale, reset to 1.0
    // when it is removed.
    f32 evp_scale;
    // 1: the swing is over, 2: it struck, 4: the next input came too early,
    // 8: the burst is complete.
    FlagWord flags;
    s16 pending_stage;
    s16 hit_count;
    s32 begun_stage;
    s32 burst_count;
    // Frames left before the swing ends.
    s32 recovery_timer;
    // The lock-on slot's cone at capture time (LockOnActionSlot).
    f32 lock_range;
    f32 horizontal_cone_cos;
    f32 vertical_cone_cos;
    f32 cone_apex_offset;
    CapturedTargetList lockon_targets;

    // Clears the block; the lock-on list and the flag word are built first.
    PlayerAttackController();
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

    f32 get_attack_speed();
    void set_queued_kind(s16 kind);
    FlagWord *get_flags();
    void set_lockon_targets(CapturedTargetList *src);
    void end_swing();
    void increment_hit_count();
    void set_recovery_timer(s32 frames);
    s32 get_recovery_timer();
    s16 get_hit_count();
    // The stage begin() started the swing at.
    s32 get_begun_stage();

    s16 get_validated_queued_kind();
    s16 get_validated_attack_kind();
    void set_attack_kind(s16 kind);
    CapturedTargetList *get_lockon_targets();
    // Queues the next combo stage from an action channel, up to maximum_stage.
    void queue_physical_attack_input(TObjPlayer *player, s32 channel, s16 maximum_stage);
    s32 tick_burst_recovery();
    s32 tick_recovery_timer();
    void register_strike(TObjPlayer *player);
    void begin(TObjPlayer *player, s32 stage, s32 begun);
    s32 get_first_target_position(Vec *out);
    CapturedTargetList *capture_lockon_targets(TObjPlayer *player);
    CapturedTarget *get_first_target();
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

s32 is_valid_attack_stage(s16 stage);
s32 is_valid_attack_kind(s16 kind);

// --- functions defined in PlayerAttackController.cpp ---
void handle_6x54(void);
void handle_6x8C(void);
void handle_6x65(void);
void handle_6x8B(void);
void handle_6x64(void);

#endif
