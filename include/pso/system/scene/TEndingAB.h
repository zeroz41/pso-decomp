#ifndef PSO_SYSTEM_SCENE_TENDINGAB_H
#define PSO_SYSTEM_SCENE_TENDINGAB_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TEndingAB : public TObject {
public:
    virtual ~TEndingAB();
    virtual void run_task();
    virtual void render();
public:
    void advance_fade_sequence();
    void draw_overlay();
    static void set_fish_global_param();
    void init_float_table();
    static void destroy_instance();
};

extern "C" {
void TEndingAB__sub_8008CCC0(TEndingAB *self);
}

#endif
