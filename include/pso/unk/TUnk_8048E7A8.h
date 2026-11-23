#ifndef PSO_UNK_TUNK_8048E7A8_H
#define PSO_UNK_TUNK_8048E7A8_H
#include "types.h"
#include "pso/unk/TUnk_8048E728.h"

class TUnk_8048E7A8 : public TUnk_8048E728 {
public:
    TUnk_8048E7A8(u8 *param, u8 *pos, saddr parent, u16 flags, s16 target_id);
    TUnk_8048E7A8(void *param, void *pos, void *parent);
    virtual ~TUnk_8048E7A8();
    virtual void run_task();
    void check_radial_particle_retire();
    virtual void render();
    f32 motion_speed;          // 0xC0, motion frames per frame
};

#endif
