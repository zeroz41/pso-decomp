#ifndef PSO_BOSS_DARKFALZ_TBOSS4THANKS_H
#define PSO_BOSS_DARKFALZ_TBOSS4THANKS_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TBoss4Thanks : public TObject {
    virtual ~TBoss4Thanks();
    void render();
    s32 state;
    s32 current_motion;
    s32 next_motion;
    f32 motion_frame;
    f32 fade_amount;
    s32 fade_frame;
    s32 model;
    s32 texture_list;
    s32 motions[2];
    void *particle_emitters[4];
    static u8 is_door_0x97_open();
    static int dispatch_main_phase_153();
    static int dispatch_main_phase();
    void update_particle_emitters();
    void destroy_effects();
    static int is_player_nearby(void *arg0);
    void update_fade_out();
    void advance_thanks_state();
    void mark_done();
    void run_task();
    static void *create();
    s32 is_door_open_and_ready();
    static s32 check_ready();
};

#include <stddef.h>
typedef char TBoss4Thanks_state_offset[(offsetof(TBoss4Thanks, state) == 0x1C) ? 1 : -1];
typedef char TBoss4Thanks_current_motion_offset[(offsetof(TBoss4Thanks, current_motion) == 0x20) ? 1 : -1];
typedef char TBoss4Thanks_next_motion_offset[(offsetof(TBoss4Thanks, next_motion) == 0x24) ? 1 : -1];
typedef char TBoss4Thanks_motion_frame_offset[(offsetof(TBoss4Thanks, motion_frame) == 0x28) ? 1 : -1];
typedef char TBoss4Thanks_fade_amount_offset[(offsetof(TBoss4Thanks, fade_amount) == 0x2C) ? 1 : -1];
typedef char TBoss4Thanks_fade_frame_offset[(offsetof(TBoss4Thanks, fade_frame) == 0x30) ? 1 : -1];
typedef char TBoss4Thanks_model_offset[(offsetof(TBoss4Thanks, model) == 0x34) ? 1 : -1];
typedef char TBoss4Thanks_texture_list_offset[(offsetof(TBoss4Thanks, texture_list) == 0x38) ? 1 : -1];
typedef char TBoss4Thanks_motions_offset[(offsetof(TBoss4Thanks, motions) == 0x3C) ? 1 : -1];
typedef char TBoss4Thanks_particle_emitters_offset[(offsetof(TBoss4Thanks, particle_emitters) == 0x44) ? 1 : -1];
typedef char TBoss4Thanks_size[(sizeof(TBoss4Thanks) == 0x54) ? 1 : -1];

#endif
