#ifndef PSO_WEAPON_SHOOT_TITEMSHOOT_H
#define PSO_WEAPON_SHOOT_TITEMSHOOT_H

#include "pso/system/task/TObject.h"
#include "types.h"
class TEffStarLight2D;
#include "dolphin/mtx.h"

class TItemShoot : public TObject {
public:
 Vec m_pos;
 s32 rot_x;
 s32 rot_y;
 s32 rot_z;
 f32 m_life;
 Vec m_dir;
 Vec end_pos;
 TEffStarLight2D* star_light;  // the gun shot's star light, which follows it
 s32 m_owner_item_id; // the owner item's get_item_id(); find_equipped_item(id) == NULL ends the shot

public:
    TItemShoot(void* owner, const Vec* pos, const Vec* dir, f32 life);
    virtual ~TItemShoot();
    virtual void hook();
    virtual void run_task();
public:
    static s32 spawn_shoot_particle(u32 owner, s32 pos, s32 dir, f32 life);
    static u32 spawn_shoot_particle_attached(u32 owner, s32 pos, s32 dir, f32 life);
};

#endif
