#ifndef PSO_MISC_TOKURAGE_H
#define PSO_MISC_TOKURAGE_H

#include "types.h"
#include "pso/object/TObjMapObject.h"
#include "pso/system/NinjaTypes.h"

struct AnimationMotion;

struct TOKurage : public TObjMapObject {
    TOKurage(TObject *parent, void *set_data);
    virtual ~TOKurage();
    void update_tilt();
    AnimationMotion *motion2;    // its second motion, drawn blended with motion
    Vec bob_base;    // the set position it bobs around (y is the bob's base)
    Vec velocity;    // velocity
    Vec home;    // home, check_player_distance measures from it
    f32 bob_pos;    // bob position
    f32 bob_speed;    // bob speed
    f32 lift;    // lift
    s16 timer;    // state timer
    s16 bob_phase;    // bob phase angle
    u8 state;    // state; 3 drifts home, 4 fades out
    u8 rising;    // rising
    u8 turn_dir;    // turn direction
    u8 _pad103[0x1];
    NJS_ARGB color;  // the constant material colour it draws with
    void check_player_distance();
    void update_state();
    void debug_print_ranges();
    void init();
    virtual void run_task();
    virtual void render();
    static void *create(void *set_data);
    static void destroy_static_instance();
    static void load_static_resource();
};

typedef char TOKurage_size[sizeof(TOKurage) == 0x114 ? 1 : -1];

#endif
