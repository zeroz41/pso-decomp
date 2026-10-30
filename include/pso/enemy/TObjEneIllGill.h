#ifndef PSO_ENEMY_TOBJENEILLGILL_H
#define PSO_ENEMY_TOBJENEILLGILL_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/misc/MaterialOpacityFade.h"

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
    virtual void vfunc_28();
    virtual s32 update_action_hold_status();
    virtual s32 update_movement_status();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_58();
    MaterialOpacityFade fade;
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
    static void capture_effect_positions();
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

typedef char IllGillFadeOffset[offsetof(TObjEneIllGill, fade) == 0x374 ? 1 : -1];
typedef char IllGillHitListOffset[offsetof(TObjEneIllGill, chargeHits) == 0x3E0 ? 1 : -1];
typedef char IllGillEffectsOffset[offsetof(TObjEneIllGill, primaryEffect) == 0x414 ? 1 : -1];
typedef char IllGillMovementSize[sizeof(IllGillMovementParameters) == 0x1C ? 1 : -1];
typedef char IllGillBehaviorSize[sizeof(IllGillAttackBehavior) == 0x20 ? 1 : -1];
typedef char TObjEneIllGill_size[sizeof(TObjEneIllGill) == 0x420 ? 1 : -1];
#endif
