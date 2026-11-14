#ifndef PSO_UNK_TUNK_804B2578_H
#define PSO_UNK_TUNK_804B2578_H
#include "types.h"
#include "pso/object/base/TObjChara.h"

// Base of the TOHangceilingCave01 hanging-ceiling objects (vtable 0x804B2578).
class TUnk_804B2578 : public TObjChara {
public:
    TUnk_804B2578(TObject *parent, void *set_data);
    virtual ~TUnk_804B2578();
    virtual void run_task();
    virtual void render();
    virtual s32 select_melee_contact_body(void *, f32);
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual f32 receive_physical_attack(void *, f32);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual void apply_knockback_from_attacker(u8 *, f32);
    virtual void vfunc_79();
    virtual void vfunc_80();
    virtual f32 vfunc_81(f32);
    s32 sub_801688C0();
    void sub_80168280(u32);
    void init_geometry();
    void sub_80168488();
    void sub_80168398();
    void sub_801682E4(s32);
    s32 sub_80168244(u32);
    void advance_wrap_offset();
    void reset_state();
    void set_scale(f32);
    u8 unk_334[0x4];
    f32 m_338;
    u32 hit_players[4];  // 0x33C: players sub_80168488 already hit (inferred name)
    s32 hit_player_count; // 0x34C: entries used in hit_players (inferred name)
    f32 m_350;
    f32 m_354;
    u32 m_358;
    s32 switch_id;  // 0x35C: set_params[0], the floor switch it waits on (inferred name)
};

typedef char TUnk_804B2578_size[sizeof(TUnk_804B2578) == 0x360 ? 1 : -1];

#endif
