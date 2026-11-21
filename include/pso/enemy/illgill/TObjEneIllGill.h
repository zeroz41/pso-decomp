#ifndef PSO_ENEMY_ILLGILL_TOBJENEILLGILL_H
#define PSO_ENEMY_ILLGILL_TOBJENEILLGILL_H

#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/TObjEnemy.h"
#include "pso/render/TUnk_80494938.h"

class TParticleCtrl;

struct IllGillAttackBehavior {
    f32 recoveryFrames;
    f32 animationSpeed;
    u32 unknown08[4];
    s32 specialParameter;
    s32 thirdSpecialParameter;
};

struct IllGillMovementParameters {
    f32 range;
    f32 speed;
    s32 turn;
    u32 unknown[4];
};

struct TObjEneIllGill : public TObjEnemy {
    TObjEneIllGill(TObject *parent, void *setData);
    virtual ~TObjEneIllGill();
    virtual s32 is_target_in_attack_range();
    s32 project_step_to_ground(s32);
    virtual void refresh_target();
    virtual s32 update_action_hold_status();
    virtual s32 update_movement_status();
    virtual void run_move_action();
    virtual void run_attack_action();
    virtual void run_miss_reaction();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    virtual void run_idle_action();
    TUnk_80494938 fade;
    s32 fadingIn;
    s32 attackType;
    s32 weaponSpecial;
    s32 actionTimer;
    s32 deathTimer;
    s32 hitFrame;
    s32 viewDetail;
    f32 chargeDistance;
    Vec weaponEffectPosition;
    Vec shadowEffectPosition;
    Vec chargeEffectPosition1;
    Vec chargeEffectPosition2;
    TObjChara *chargeHits[4];
    u8 unknown3F0[0x20];
    s32 chargeFrames;
    TParticleCtrl *primaryEffect;
    TParticleCtrl *secondaryEffect;
    TParticleCtrl *tertiaryEffect;
    void clear_charge_hits();
    void update_shadow_attack();
    void update_damage_recovery();
    void sub_803669B0();
    void update_weapon_attack();
    void update_forward_movement();
    void update_charge_attack();
    static void capture_effect_positions(NJS_OBJECT *);
    void update_death_fall();
    void free_resources();
    void update_chase_target();
    void update_idle();
    void move_toward_dest_with_detour();
    void render();
    void run_task();
    static void *create(void *setData);
    static void free_effect();
    static void load_shared_resources();
};

LAYOUT_ASSERT(IllGillFadeOffset, offsetof(TObjEneIllGill, fade) == 0x374);
LAYOUT_ASSERT(IllGillHitListOffset, offsetof(TObjEneIllGill, chargeHits) == 0x3E0);
LAYOUT_ASSERT(IllGillEffectsOffset, offsetof(TObjEneIllGill, primaryEffect) == 0x414);
LAYOUT_ASSERT(IllGillMovementSize, sizeof(IllGillMovementParameters) == 0x1C);
LAYOUT_ASSERT(IllGillBehaviorSize, sizeof(IllGillAttackBehavior) == 0x20);
LAYOUT_ASSERT(TObjEneIllGill_size, sizeof(TObjEneIllGill) == 0x420);
#endif
