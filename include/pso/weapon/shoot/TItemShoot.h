#ifndef PSO_WEAPON_SHOOT_TITEMSHOOT_H
#define PSO_WEAPON_SHOOT_TITEMSHOOT_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "dolphin/mtx.h"

class TItemShoot : public TObject {
public:
 Vec m_pos;
 s32 m_28;
 s32 m_count;
 s32 m_30;
 f32 m_life;
 Vec m_dir;
 Vec m_44;
 TObject* m_50;
 void* m_54;

public:
    TItemShoot(void* owner, const Vec* pos, const Vec* dir, f32 life);
    virtual ~TItemShoot();
    virtual void hook();
    virtual void run_task();
public:
    static s32 spawn_shoot_particle();
    static u32 spawn_shoot_particle_attached(s32 arg0, s32 arg1, s32 arg2, f32 farg0);
    void set_texture_id(s32 v);
    void set_particle_flags(s16 v);
};

#endif
