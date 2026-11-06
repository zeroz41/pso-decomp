#ifndef PSO_BOSS_VOLOPT_TOBJVOLOPTSHUTTER_H
#define PSO_BOSS_VOLOPT_TOBJVOLOPTSHUTTER_H

#include "types.h"
#include "pso/system/task/TObject.h"

// One of the shutters of Vol Opt's room. state 1 runs update_shutter_slide
// (both panels return to 0), state 2 runs update_shutter_state (the panels move
// to -3 and -18); each finishes in two phases counted by substate.
class TObjVoloptShutter : public TObject {
public:
    s32 index;
    s32 state;
    s32 substate;
    f32 offset_y;
    f32 offset_z;
    s32 rotation_y;

    TObjVoloptShutter(s32 index);
    virtual ~TObjVoloptShutter();
    virtual void run_task();
    virtual void render();

    void update_shutter_slide();
    void update_shutter_state();
    void close();
    void open();
};

extern void *volopt_shutter_model_a;
extern void *volopt_shutter_model_b;
extern s32 volopt_shutter_global_param;

#endif
