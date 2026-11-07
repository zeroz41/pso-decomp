#ifndef PSO_UNK_TUNK_8048E790_H
#define PSO_UNK_TUNK_8048E790_H
#include "types.h"
#include "pso/unk/TUnk_8048E728.h"

class TUnk_8048E790 : public TUnk_8048E728 {
public:
    virtual ~TUnk_8048E790();
    virtual void run_task();
    void *init_random_particle(void *, void *, void *, void *);
    void retire_orbit_particle();
    virtual void render();
    f32 unk_C0;                // 0xC0, motion frame step
    f32 orbit_center_x;        // 0xC4
    f32 orbit_center_z;        // 0xC8
    u8 pad_cc[0x4];
    f32 orbit_radius;          // 0xD0
    f32 orbit_height;          // 0xD4
    s32 orbit_angle;           // 0xD8
    s32 m_dc;
};

#endif
