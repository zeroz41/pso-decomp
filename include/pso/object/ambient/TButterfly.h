#ifndef PSO_OBJECT_AMBIENT_TBUTTERFLY_H
#define PSO_OBJECT_AMBIENT_TBUTTERFLY_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TButterfly : public TObjBase {
    TButterfly(TObject *parent, void *arg2);
    virtual ~TButterfly();
    Vec home_position;  // where it spawned; y is the height it hovers around
    Vec velocity;
    f32 motion_frame; // frame passed to draw_ginja_model_with_motion, randomised by the ctor (name inferred)
    f32 phase_speed;  // how fast motion_frame advances
    f32 lift;         // the upward push towards the hover height
    s16 timer;        // frames left in the current state
    s16 angle;        // the bobbing angle
    u8 state;         // 0 hovers, 1 drifts forward, 2 turns while drifting
    u8 flag;          // 0 rising wing beat, 1 falling wing beat
    u8 turn_dir;      // which way state 2 turns
    void init_motion();
    virtual void render();
    virtual void run_task();
    static void load_resources();
    static void destroy_instance();
    void draw_model();
    u8 pad_BB[0x1];
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TButterfly_size, sizeof(TButterfly) == 0xBC);

extern "C" {
void *__dt__10TButterflyFv(void *arg0, s16 arg1);
}

extern "C" {
void *__ct__10TButterflyFP7TObjectPv(void *butterfly, void *arg1, void *arg2);
}

#endif
