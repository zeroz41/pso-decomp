#ifndef PSO_ENEMY_TNEEDLESHOOT_H
#define PSO_ENEMY_TNEEDLESHOOT_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include <dolphin/mtx/GeoTypes.h>

struct TechniqueContactBody;

struct TNeedleShoot : public TObject {
    TNeedleShoot(s32 owner, Vec *from, Vec *to);
    virtual ~TNeedleShoot();
    virtual void vfunc_6();
    virtual void queue_destruction();
    virtual void vfunc_8();
    virtual void vfunc_9(void *);
    uaddr m_1c;
    f32 range;     // the shot is destroyed once distance passes it
    f32 distance;  // speed summed each frame
    Vec prev_pos;
    u16 m_34;
    u8 _pad36[0x2];
    TechniqueContactBody *m_38;
    CollisionBody collision_body;  // m_68's only body
    TObjCollidable *m_68;
    Vec pos;
    u8 pad_78[0x10];
    Vec pad_88;  // set to 1, 1, 1
    Vec dir;
    s32 m_a0;
    s32 m_a4;
    s32 m_a8;
    f32 speed;  // pos moves by dir * speed each frame
    u32 m_b0;
    f32 pad_b4;
    s32 m_b8;
    virtual void run_task();
    virtual void render();
    void update_position();
    void check_wall_hit();
    void*get_shoot_data();
    void update_lifetime();
    void sub_802A4668();
};

LAYOUT_ASSERT(TNeedleShoot_size, sizeof(TNeedleShoot) == 0xBC);

#endif
