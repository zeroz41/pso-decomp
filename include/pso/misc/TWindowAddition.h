#ifndef PSO_MISC_TWINDOWADDITION_H
#define PSO_MISC_TWINDOWADDITION_H
#include "types.h"
#include "pso/misc/TWindowBase.h"

class TWindowAddition : public TWindowBase {
public:
    virtual ~TWindowAddition();
    s32 sub_80266B18(s32);
    void *construct_with_parent(void *);
    void *destroy_window(s16);
    void sub_802443B4();
    void step_window_tween();
    void set_position_xy(f32, f32);
};

#endif
