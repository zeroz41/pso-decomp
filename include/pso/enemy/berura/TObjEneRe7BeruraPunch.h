#ifndef PSO_ENEMY_BERURA_TOBJENERE7BERURAPUNCH_H
#define PSO_ENEMY_BERURA_TOBJENERE7BERURAPUNCH_H

#include "types.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/render/TUnk_80490470.h"

class TParticleCtrl;
class AreaAttackHistory;

struct TObjEneRe7BeruraPunch : public TUnk_804928CC {
    TObjEneRe7BeruraPunch(TObject *parent, TObjBase *owner);
    virtual ~TObjEneRe7BeruraPunch();
    virtual void apply_hit_if_active(void *, f32 *);
    s32 sub_80096150();
    void update_flight();
    void snap_to_ground();
    void reset();
    virtual void run_task();
    void init();
    int is_patrol_active();
    virtual void render();
    void update_velocity_and_snap();
    void launch(s32 arg1, s32 arg2);

    u16 owner_id;  // get_entity_id(owner) in the ctor; find_entity_by_id gives the Berura back
    u8 unk_B2[0x2];
    s32 m_b4;
    s32 m_b8;
    f32 m_bc;
    f32 m_c0;
    f32 m_c4;
    f32 m_c8;
    f32 m_cc;
    TParticleCtrl *m_d0;
    TParticleCtrl *m_d4;
    AreaAttackHistory *attack_history;
    Vec m_dc;
    Vec ground_normal;  // CsnContact::normal of the ground under m_dc
    f32 m_f4;
    TUnk_80490470 m_f8;
    f32 m_114;
    s32 m_118;
};

typedef char TObjEneRe7BeruraPunch_size[sizeof(TObjEneRe7BeruraPunch) == 0x11C ? 1 : -1];

#endif
