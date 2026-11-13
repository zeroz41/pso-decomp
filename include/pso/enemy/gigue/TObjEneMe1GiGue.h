#ifndef PSO_ENEMY_GIGUE_TOBJENEME1GIGUE_H
#define PSO_ENEMY_GIGUE_TOBJENEME1GIGUE_H

#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/render/RenderFadeState.h"
#include "pso/system/BmlResource.h"

// The tuning block TLobby::dispatch_shared_handler_a hands out for the Gi Gue
// (read by get_gigue_float_parameter and get_gigue_int_parameter).
struct GiGueParameters {
    f32 floats[6];
    s32 ints[5];
};

struct TObjEneMe1GiGue : public TObjEnemyCustom {
    virtual ~TObjEneMe1GiGue();
    void sub_802CACD8();
    virtual void run_task();
    virtual void render();
    void sub_802CCF2C();
    void sub_802CB6D4();
    void init_move();
    void update_direction();
    void load_params();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual s32 update_action_hold_status();
    virtual f32 receive_physical_attack(void *, f32);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual void vfunc_61();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_58();
    u16 m_38c;
    Vec m_390;
    Vec m_39c;
    Vec m_3a8;
    Vec m_3b4;
    s32 m_3c0;
    u16 m_3c4[12];
    s32 m_3dc;
    f32 m_3e0;
    f32 m_3e4;
    f32 m_3e8;
    f32 m_3ec;
    u8 unk_3F0[0x4];
    s32 m_3f4;
    s32 m_3f8;
    TUnk_80494938 m_3fc;
    RenderFadeState m_418;
    s32 m_434;
    f32 m_438;
    f32 m_43c;
    f32 m_440;
    f32 m_444;
    s32 m_448;
    s32 m_44c;
    s32 m_450;
    s32 m_454;
    void dispatch_state();
    void clear_flag388_bit80000();
    void sub_802CABF4();
    s32 is_active_state();
    s32 get_field_44c();
    s32 sub_802CAC48();
    Vec *update_and_get_pos();
    static void *create(void *arg0);
    static void delete_barrier();
    static void load_resources();
    void load_params_from_table(s32 i);
    static BmlResource *sub_802CAC80();
    void apply_hit_shake(TObjChara *player);
    s32 check_vector_bit(Vec *pos);
    static s32 remap_sound_id(void *obj, s32 id);
    void break_apart();
    void update_hit_reaction();
};

typedef char TObjEneMe1GiGue_size[sizeof(TObjEneMe1GiGue) == 0x458 ? 1 : -1];
#endif
