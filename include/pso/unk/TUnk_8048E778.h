#ifndef PSO_UNK_TUNK_8048E778_H
#define PSO_UNK_TUNK_8048E778_H
#include "types.h"
#include "pso/unk/TUnk_8048E728.h"

class TUnk_8048E778 : public TUnk_8048E728 {
public:
    virtual ~TUnk_8048E778();
    virtual void run_task();
    TUnk_8048E778(void *param, void *pos, void *dir, saddr parent, u16 flags, s16 target_id);
    TUnk_8048E778(void *param, void *pos, void *parent);
    void retire_ballistic_particle_if_done();
    void draw_sprite_quad(s32);
    virtual void render();
    f32 motion_speed;          // 0xC0, motion frames per frame
    Vec velocity;              // 0xC4, step after rotation
};

#endif
