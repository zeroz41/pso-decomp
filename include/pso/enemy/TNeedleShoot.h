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
    // Called when the shot meets a wall (check_wall_hit) or check_target_hit finds no contact list.
    virtual void on_wall_hit();
    virtual void queue_destruction();
    virtual void vfunc_8();
    // Called by check_target_hit with the first receivable contact.
    virtual void on_target_hit(void *);
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
    // Collects the technique contacts of the shot (m_b0 picks the collector) and calls on_wall_hit or
    // on_target_hit. Defined with the KenkyuW unit, which owns its address.
    void check_target_hit(s32);
};

LAYOUT_ASSERT(TNeedleShoot_size, sizeof(TNeedleShoot) == 0xBC);

#endif
