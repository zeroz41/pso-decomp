#ifndef PSO_ENEMY_BALCLAW_TOBJENEBALCLAWBODY_H
#define PSO_ENEMY_BALCLAW_TOBJENEBALCLAWBODY_H

#include "types.h"
#include "pso/enemy/balclaw/TObjEneBalClaw.h"

class TParticleCtrl;

struct TObjEneBalClawBody : public TObjEneBalClaw {
    TObjEneBalClawBody(TObject *parent, void *set_data);
    virtual ~TObjEneBalClawBody();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_60();
    virtual void vfunc_58();
    void sub_8008DC90();
    void sub_8008FC0C();
    void sub_8008FC10();
    void sub_8008FF50();
    void update_dragon_boss_state();
    static void *create(void *set_data);
    f32 m_3c0;             // xz distance squared to the target
    u32 child_ids[4];      // entity ids of the claws; the dtor destroys the first m_3d8 of them
    s32 m_3d4;             // frames since the last merge/split (not counted while idle or returning home)
    s16 m_3d8;             // how many of child_ids are in use (the ctor sets 4)
    s16 m_3da;
    TParticleCtrl *effects[4];  // queue_destruction'd by the dtor
    Vec m_3ec;
    s32 m_3f8[3];
};

typedef char TObjEneBalClawBody_size[sizeof(TObjEneBalClawBody) == 0x404 ? 1 : -1];
#endif
