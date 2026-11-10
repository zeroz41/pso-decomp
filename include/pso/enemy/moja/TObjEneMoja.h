#ifndef PSO_ENEMY_MOJA_TOBJENEMOJA_H
#define PSO_ENEMY_MOJA_TOBJENEMOJA_H
#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/render/RenderFadeState.h"

class TUnk_80494968;

struct MojaBattleStat {
    u8 unknown_00[0x18];
    s32 techniqueLevel;
};
struct MojaCollisionState {
    u8 unknown_00[0x18];
    s32 flags;
};
// One per variant (TObjEnemy::variant); TObjEnemy::movementParameters points
// at the Moja's.
struct MojaMovementParameters {
    f32 unknown_00;
    f32 unknown_04;
    s32 unknown_08;
    u32 unknown_0C[4];
};
// The motion-binding block TLobby::spawn_npc_enemy takes (same layout as
// DelDepthAnimationBinding).
struct MojaAnimationBinding {
    BmlMotionEntry *motions;
    TObjMotionAction *actions;
    u32 unknown_08;
    u16 actionCount;
    u16 unknown_0E;
};
struct TObjEneMoja : public TObjEnemy {
    TObjEneMoja(TObject *parent, void *setData);
    virtual ~TObjEneMoja();
    static void load_resources();
    virtual s32 update_action_hold_status();
    virtual s32 update_movement_status();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual s32 is_target_in_attack_range();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_28();
    void render();
    void bindModel(int index);
    s32 appearance;
    f32 jumpSpeed;
    s32 unused_37C;
    s32 attack;
    s32 attackSequence;
    s32 roar;
    f32 sinkOffset;
    f32 techniqueChance;
    f32 jumpChance;
    TUnk_80494968 *unknown_398;
    RenderFadeState unknown_39C[4];
    static void *create(void *arg0);
    static void free_resources();
    s32 calc_technique_level();
    void select_rare_variant();
    void update_death_state();
    static s32 update_technique_state(void *self_800AD3D8);
    static s32 update_punch_attack(void *self_800ADAAC);
    s32 update_approach_state();
    void update_idle_state();
    void update_appearance_jump();
    void update_appearance_drop();
    void update_attack_jump();
    void run_task();
};
typedef char MojaSize[(sizeof(TObjEneMoja)==0x40C)?1:-1];
#include <stddef.h>
#define MOJA_OFFSET(field, offset) typedef char MojaOffset_##field[(offsetof(TObjEneMoja, field)==offset)?1:-1]
MOJA_OFFSET(appearance,0x374);
MOJA_OFFSET(attackSequence,0x384);
MOJA_OFFSET(roar,0x388);
#undef MOJA_OFFSET
#endif
