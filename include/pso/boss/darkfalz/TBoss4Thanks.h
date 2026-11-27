#ifndef PSO_BOSS_DARKFALZ_TBOSS4THANKS_H
#define PSO_BOSS_DARKFALZ_TBOSS4THANKS_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct NJS_OBJECT;
struct NJS_TEXLIST;
struct NJS_MOTION;
class TParticleCtrl;

struct TBoss4Thanks : public TObject {
    TBoss4Thanks(TObject *);
    virtual ~TBoss4Thanks();
    void render();
    s32 state;
    s32 current_motion;
    s32 next_motion;
    f32 motion_frame;
    f32 fade_amount;
    s32 fade_frame;
    NJS_OBJECT *model;
    NJS_TEXLIST *texture_list;
    NJS_MOTION *motions[2];
    TParticleCtrl *particle_emitters[4];
    // Story flag 151, set by check_ready (dispatch_main_phase) when the fight earns the thanks.
    // int: the body widens a bool (clrlwi) and its callers test r3 with a plain cmpwi.
    static s32 is_thanks_earned();
    // Story flag 153, set by the destructor (dispatch_main_phase_153) once the thanks were shown.
    static s32 is_thanks_shown();
    static void dispatch_main_phase_153();
    static void dispatch_main_phase();
    void update_particle_emitters();
    void destroy_effects();
    void clear_particle_emitters();
    int is_player_nearby();
    void update_fade_out();
    void advance_thanks_state();
    void mark_done();
    void run_task();
    static void *create();
    static s32 is_door_open_and_ready();
    static s32 check_ready();
    static const char *class_name;
};

#include <stddef.h>
LAYOUT_ASSERT(TBoss4Thanks_state_offset, offsetof(TBoss4Thanks, state) == 0x1C);
LAYOUT_ASSERT(TBoss4Thanks_current_motion_offset, offsetof(TBoss4Thanks, current_motion) == 0x20);
LAYOUT_ASSERT(TBoss4Thanks_next_motion_offset, offsetof(TBoss4Thanks, next_motion) == 0x24);
LAYOUT_ASSERT(TBoss4Thanks_motion_frame_offset, offsetof(TBoss4Thanks, motion_frame) == 0x28);
LAYOUT_ASSERT(TBoss4Thanks_fade_amount_offset, offsetof(TBoss4Thanks, fade_amount) == 0x2C);
LAYOUT_ASSERT(TBoss4Thanks_fade_frame_offset, offsetof(TBoss4Thanks, fade_frame) == 0x30);
LAYOUT_ASSERT(TBoss4Thanks_model_offset, offsetof(TBoss4Thanks, model) == 0x34);
LAYOUT_ASSERT(TBoss4Thanks_texture_list_offset, offsetof(TBoss4Thanks, texture_list) == 0x38);
LAYOUT_ASSERT(TBoss4Thanks_motions_offset, offsetof(TBoss4Thanks, motions) == 0x3C);
LAYOUT_ASSERT(TBoss4Thanks_particle_emitters_offset, offsetof(TBoss4Thanks, particle_emitters) == 0x44);
LAYOUT_ASSERT(TBoss4Thanks_size, sizeof(TBoss4Thanks) == 0x54);

// A particle emitter of the Thanks scene, alive while fade_frame is in [first_frame, last_frame]
// (the TBoss6Thanks twin's Boss6ThanksEmitter).
struct Boss4ThanksEmitter { s32 id; s32 first_frame; s32 last_frame; };

s32 any_player_has_listed_item(void);

// Takes no argument: the body calls is_thanks_earned() without setting r3.
s32 is_boss4_door_open(void);

#endif
