#ifndef PSO_OBJECT_AMBIENT_TBUTTERFLY_H
#define PSO_OBJECT_AMBIENT_TBUTTERFLY_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct ObjectSetData;

struct TButterfly : public TObjBase {
    TButterfly(TObject *parent, ObjectSetData *set_data);
    virtual ~TButterfly();
    void init_motion();
    virtual void render();
    virtual void run_task();
    static void load_resources();
    static void destroy_instance();
    void draw_model();
    static void *create(void *set_data);

    Vec origin;        // the set position; it bobs around origin.y
    Vec velocity;
    f32 motion_frame;  // frame passed to draw_ginja_model_with_motion, wraps at 5
    f32 flap_speed;    // added to motion_frame every frame
    f32 lift;
    s16 timer;         // frames left in the current state
    s16 bob_angle;     // sine angle of the height it bobs to
    u8 state;          // 0 hover, 1 fly ahead, 2 fly ahead turning
    u8 alt_mode;       // swaps the climb for a dive until motion_frame wraps
    u8 turn_dir;       // state 2: 0 turns one way, 1 the other
    u8 pad_bb[0x1];
};

LAYOUT_ASSERT(TButterfly_size, sizeof(TButterfly) == 0xBC);

#endif
