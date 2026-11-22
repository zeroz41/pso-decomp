#ifndef PSO_BOSS_OLGAFLOW_TBOSS6MINE_H
#define PSO_BOSS_OLGAFLOW_TBOSS6MINE_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/enemy/TObjEnemy.h"

struct BmlResource;
class TParticleCtrl;
struct TBoss6Type1;

// What TBoss6Type1's mine attack (TBoss6Type1::spawn_mines) hands TBoss6Mine::create: a 0x40-byte object
// set entry copied from the mag mine's (copy_set_entry) followed by the mine's own spawn data.
// The TBoss6Mine constructor reads 0x40-0x60 and passes the whole record to apply_set_data. Names inferred from those uses.
struct TBoss6MineSetData {
    s16 set_index; // TBoss6PlotFalz::get_next_point writes its set_index + counter here
    u8 pad_02[0x4];
    s16 entity_id; // ...and its entity_id + counter here
    s16 room;  // TBoss6PlotFalzSetEntry::room (copy_set_entry); spawn_mines clears it
    u8 pad_0A[0x6];
    Vec position;
    u8 pad_1C[0x24];
    TBoss6Type1 *owner;
    Vec origin;
    Vec offset;
    s32 heading;
    s32 seed;
};

struct TBoss6Mine : public TObjEnemy {
    TBoss6Mine(TObject *parent, TBoss6MineSetData *set_data);
    virtual ~TBoss6Mine();
    virtual void run_task();
    virtual void run_death_reaction();
    virtual void run_hit_reaction();
    virtual void render_shadows();
    virtual void render();
    BmlResource *scene_archive;
    TBoss6Type1 *owner;
    s32 heading;
    s32 state;
    s32 damage; // boss parameter 0x2D, each player in the blast takes about this much
    s32 seed; // state of next_random_float's sequence
    s32 state_frames;
    s32 yaw;   // turned towards its flight direction
    s32 pitch; // tilted to the climb of its flight, at most 0x2000
    s32 spin;  // spins 0x888 per frame while it flies
    f32 anim_frame;
    u32 rise_delay;
    u32 spread_frames;
    u32 arm_delay;
    f32 travel_distance;
    Vec start_pos;
    Vec target_pos;
    f32 fade_amount;
    TParticleCtrl *emitter;
    void copy_pos();
    void draw();
    void update_facing_angles();
    s32 is_far_from_origin();
    static TBoss6Mine *create(TBoss6MineSetData *set_data);
    static f32 next_random_float(s32 *seed);
    void explode_damage_players();
    void state_0();
    void state_1();
    void state_2();
    void state_3();
    void state_4();
    void state_5();
    void state_6();
    void state_7();
};

LAYOUT_ASSERT(TBoss6MineSetData_size, sizeof(TBoss6MineSetData) == 0x64);
LAYOUT_ASSERT(TBoss6Mine_size, sizeof(TBoss6Mine) == 0x3D0);

#endif
