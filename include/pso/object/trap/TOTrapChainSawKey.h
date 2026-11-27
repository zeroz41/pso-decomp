#ifndef PSO_OBJECT_TRAP_TOTRAPCHAINSAWKEY_H
#define PSO_OBJECT_TRAP_TOTRAPCHAINSAWKEY_H

#include "types.h"
#include "pso/object/trap/TOTrapChainSaw.h"

struct NJS_MOTION;
struct NJS_OBJECT;

// The chainsaw that sets its floor switch when it touches a player; its light
// model glows while the switch is on.
struct TOTrapChainSawKey : public TOTrapChainSaw {
    TOTrapChainSawKey(TObject *parent, void *set_data);
    virtual ~TOTrapChainSawKey();
    virtual void update_state();
    virtual void decode_params();
    virtual void select_model();
    virtual void hit_player(TObjPlayer *player);
    virtual void draw_debug_labels();
    virtual void draw_model();
    virtual void check_player_contact();
    virtual void update_run();
    s32 variant;                    // scale.z clamped to 0-1: the 2 m or 4 m saw
    NJS_OBJECT *light_model;
    NJS_MOTION *light_motion;
    f32 light_frame;
    f32 light_frame_step;
    static void *create(void *set_data);
    // The model draw callback: the light nodes draw with the effect blend.
    static void draw_node_callback(NJS_OBJECT *node);
};

LAYOUT_ASSERT(TOTrapChainSawKey_size, sizeof(TOTrapChainSawKey) == 0x10C);
#endif
