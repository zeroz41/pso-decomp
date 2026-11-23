#ifndef PSO_BOSS_OLGAFLOW_TBOSS6THANKS_H
#define PSO_BOSS_OLGAFLOW_TBOSS6THANKS_H
#include "types.h"
#include "pso/system/task/TObject.h"

struct NJS_OBJECT;
struct NJS_TEXLIST;
struct AnimationMotion;
class TParticleCtrl;

// Field and function names shared with its twin TBoss4Thanks (darkfalz) where the bodies line up.
struct TBoss6Thanks : public TObject {
    TBoss6Thanks(TObject *parent);
    virtual ~TBoss6Thanks();
    s32 state;
    s32 current_motion;
    s32 next_motion;
    f32 frame0;
    f32 frame1;
    f32 opacity;
    s32 fade_frame;  // update_fade_out counts it to 120
    NJS_OBJECT *model0;
    NJS_OBJECT *model1;
    NJS_TEXLIST *texture0;
    NJS_TEXLIST *texture1;
    AnimationMotion *motions[2];
    AnimationMotion *motion1;
    TParticleCtrl *particle_emitters[4];
    virtual void run_task();
    virtual void render();
    // int: the body widens a bool (clrlwi) and its callers test r3 with a plain cmpwi.
    static s32 check_ship_door();
    // Story flag 0x9A test next to check_ship_door(); int return for the same reason.
    static s32 is_story_flag_0x9A_set();
    static void set_story_flag_0x9A();
    static void dispatch_darkfalz_phase();
    void update_particle_emitters();
    void destroy_effects();
    void clear_particle_emitters();
    static int is_player_near(void *);
    void update_fade_out();
    void advance_thanks_state();
    void mark_done();
    static void *create();
    static s32 is_ship_door_ready();
    static s32 try_dispatch_darkfalz_phase();
};
LAYOUT_ASSERT(TBoss6Thanks_size, sizeof(TBoss6Thanks) == 0x64);
#endif
