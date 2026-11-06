#ifndef PSO_SYSTEM_SCENE_TENDINGPIC_H
#define PSO_SYSTEM_SCENE_TENDINGPIC_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TEndingPic : public TObject {
public:
    virtual ~TEndingPic();
    virtual void run_task();
    virtual void render();
public:
    void advance_animation_state();
    void draw_current_pic();
    void init_positions();
};

extern "C" {
u8 *__ct__10TEndingPicFv(u8 *arg0, u8 *arg1);
}
int get_ending_ab_wall_texture_list(void);

#endif
