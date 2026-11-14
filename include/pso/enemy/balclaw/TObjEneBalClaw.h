#ifndef PSO_ENEMY_BALCLAW_TOBJENEBALCLAW_H
#define PSO_ENEMY_BALCLAW_TOBJENEBALCLAW_H

#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/render/TUnk_80490470.h"

struct TObjEneBalClaw : public TObjEnemyCustom {
    TObjEneBalClaw(TObject *parent);
    virtual ~TObjEneBalClaw();
    void set_attack_distance_flag();
    void clear_attack_flag();
    int get_flag_0x388_b24();
    virtual void vfunc_62();
    virtual void vfunc_61();
    virtual void vfunc_59();
    virtual s32 update_movement_status();
    virtual s32 update_action_hold_status();
    virtual s32 is_target_in_attack_range();
    s32 m_38c;
    TUnk_80490470 fade;
    f32 m_3ac;
    f32 m_3b0;
    f32 m_3b4;
    s32 m_3b8;
    void render_scaled(s32 arg1);
    void update_wobble();
    void update_claw_angle();
    static void release_global_805D4F20();
    void clear_flag_in_state7();
    f32 m_3bc;
};

typedef char TObjEneBalClaw_size[sizeof(TObjEneBalClaw) == 0x3C0 ? 1 : -1];

struct BmlResource;
struct BmlMotionEntry;
struct NJS_OBJECT;

// A movement row TObjEnemy::movementParameters points at.
struct BalClawMovement {
    EnemyMoveParams move;
    s32 m_c;
    s32 m_10;
    s32 m_14;
    s32 m_18;
};

// The motion-binding block TLobby::spawn_npc_enemy takes (same layout as
// MojaAnimationBinding and DelDepthAnimationBinding).
struct BalClawSpawnParams {
    BmlMotionEntry *motions;
    TObjMotionAction *actions;
    u32 unknown_08;
    u16 actionCount;
    u16 unknown_0E;
};

// The Bal Claw BML archive, loaded by TObjEneBalClaw__sub_8008D924.
extern BmlResource *lbl_805D4F20;
// Per claw slot, the visible model nodes of that claw (NULL-terminated).
extern NJS_OBJECT *balclaw_arm_part_models[4][11];
// The body's combat-stat tables from TLobby, filled by TObjEneBalClaw__sub_8008D924.
extern u8 *lbl_805007A8[];
extern u8 *lbl_805007B0[];
extern u8 *lbl_805007B8[];
extern u8 *lbl_805007C0[];

extern "C" {
void TObjEneBalClawClaw__sub_8008DC14(void);
void TObjEneBalClaw__sub_8008D68C(void);
void TObjEneBalClaw__sub_8008D924(void);
}

#endif
