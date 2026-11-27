#ifndef PSO_WEAPON_SHOOT_TITEMSHOOT_H
#define PSO_WEAPON_SHOOT_TITEMSHOOT_H

#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
class TEffStarLight2D;
struct TItemWeapon;
#include "dolphin/mtx.h"

class TItemShoot : public TObject {
public:
 static const char *class_name;
 Vec m_pos;
 Angle3 rot;
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
    static TItemShoot *spawn_shoot_particle(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life);
    static TItemShoot *spawn_shoot_particle_attached(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life);
};

TItemShoot *create_shoot_model_rot_z(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life);

TItemShoot *create_gun_shot(TItemWeapon *owner, const Vec *pos, const Vec *endpoint, f32 life);

TItemShoot *create_shoot_model_with_particles(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life);

// A shoot particle with flag 4 and effect 0x9F in its first slot.
TItemShoot *spawn_shoot_particle_9f(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life);

#endif
