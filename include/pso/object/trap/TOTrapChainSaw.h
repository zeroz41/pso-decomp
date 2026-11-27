#ifndef PSO_OBJECT_TRAP_TOTRAPCHAINSAW_H
#define PSO_OBJECT_TRAP_TOTRAPCHAINSAW_H

#include "types.h"
#include <stddef.h>
#include "pso/object/base/TObjMapObject.h"

class TObjPlayer;
struct NJS_OBJECT;
struct NJS_TEXLIST;

// A floor chainsaw: while its switch is off it runs back and forth (or sweeps
// round), hitting the players it touches; the switch pulls it back home. The
// saw advances animation_end_frame by animation_step as its motion frame.
struct TOTrapChainSaw : public TObjMapObject {
    TOTrapChainSaw(TObject *parent, void *set_data);
    virtual ~TOTrapChainSaw();
    virtual void draw_debug_labels();
    virtual void decode_params();
    virtual void select_model();
    virtual void check_player_contact();
    virtual void hit_player(TObjPlayer *player);
    virtual s32 consume_counter(TObjPlayer *player);
    virtual void set_hit_cooldown_for_player(TObjPlayer *player);
    virtual void clear_hit_cooldowns();
    virtual void update_extension();
    virtual void update_sweep();
    virtual void update_state();
    virtual void draw_model();
    // Called when a run starts from home, every frame it moves, when it
    // turns at max_offset and when it is back home.
    virtual void start_run();
    virtual void update_run();
    virtual void reach_far_end();
    virtual void reach_home();
    virtual f32 scale_by_level(f32 level);
    virtual void render();
    virtual void run_task();
    NJS_OBJECT *saw_model;
    s32 max_offset;     // set_params[1] high half: how far it extends or sweeps
    s32 step;           // set_params[1] low half: the extension or yaw step per frame
    s32 yaw_offset;
    s32 hit_cooldown[4];
    s32 switch_id;      // set_params[0] clamped to 0-255: the floor switch it follows
    s32 pause_timer;    // frames it waits after turning around
    s32 switch_on;      // the switch's state this frame
    u32 behavior;       // set_params[2] high half (0 or 1): which update runs, 0 update_extension, 1 update_sweep
    void update_demo();
    // The sound of the current area's table (index 0 run, 1 key lit, 2 key idle).
    s32 get_area_sound(s32 index);
    static void load_shared_resource();
    static void unload_static_data();
    static NJS_OBJECT *get_model(s32 index);
    static NJS_MOTION *get_motion(s32 index);
    static NJS_TEXLIST *get_texlist(s32 index);
};

LAYOUT_ASSERT(TOTrapChainSaw_size, sizeof(TOTrapChainSaw) == 0xF8);
LAYOUT_ASSERT(TOTrapChainSawCooldownOffset, offsetof(TOTrapChainSaw, hit_cooldown) == 0xD8);
#endif
