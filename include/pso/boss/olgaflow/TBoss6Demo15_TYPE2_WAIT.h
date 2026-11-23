#ifndef PSO_BOSS_OLGAFLOW_TBOSS6DEMO15_TYPE2_WAIT_H
#define PSO_BOSS_OLGAFLOW_TBOSS6DEMO15_TYPE2_WAIT_H
#include "types.h"
#include <dolphin/mtx.h>
#include "pso/system/task/TObject.h"

class TBoss6PlotFalz;
class TParticleCtrl;
struct NJS_OBJECT;
struct NJS_TEXLIST;
struct AnimationMotion;

// One animated part of the wait demo: model, texture list and motion from the scene archive.
struct WaitDemoPart {
    NJS_OBJECT *model;
    NJS_TEXLIST *texlist;
    AnimationMotion *motion;
};

// One TObjMapCsn of the scene: its position, scale and y rotation.
struct WaitDemoCsnEntry {
    Vec position;
    Vec scale;
    s32 rotation_y;
};

class TBoss6Demo15_TYPE2_WAIT : public TObject {
public:
    TBoss6Demo15_TYPE2_WAIT(TBoss6PlotFalz *plot);
    virtual ~TBoss6Demo15_TYPE2_WAIT();
    virtual void render();
    virtual void run_task();
    static TBoss6Demo15_TYPE2_WAIT *alloc(TBoss6PlotFalz *plot);
    s32 get_plot_state();
    void advance_offset();
    void check_any_player_near();
    void draw_parts();
    void update_orbit_position();
    void reset_orbit();
    void destroy_csn_objects();
    void create_csn_objects();

    TBoss6PlotFalz *plot;        // 0x1C
    TParticleCtrl *emitter;      // 0x20
    s32 player_near;             // 0x24: set by check_any_player_near
    WaitDemoPart parts[2];       // 0x28
    Vec position;                // 0x40
    Vec prev_position;           // 0x4C
    s32 orbit_angle;             // 0x58
    s32 radius_phase;            // 0x5C: swings the orbit radius 190..270
    TObject *csn_objects[10];    // 0x60: TObjMapCsn objects (create_csn_objects creates them)
};
LAYOUT_ASSERT(TBoss6Demo15_TYPE2_WAIT_size, sizeof(TBoss6Demo15_TYPE2_WAIT) == 0x88);

#endif
