#ifndef PSO_BOSS_OLGAFLOW_TBOSS6MAGMINE_H
#define PSO_BOSS_OLGAFLOW_TBOSS6MAGMINE_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/enemy/TObjEnemy.h"

struct BmlResource;
class TParticleCtrl;
struct TObjPlayer;

// What spawn_mag_mine_at hands create: the mag mine's 0x40-byte object set entry (copied by
// copy_set_entry) followed by where the mine starts and where it lands.
struct Boss6MagMineSetData {
    s16 set_index;  // TBoss6PlotFalz::get_next_point writes its set_index + counter here
    u8 pad_02[0x4];
    s16 entity_id;  // ...and its entity_id + counter here
    s16 flags;
    u8 pad_0A[0x6];
    Vec position;
    u8 pad_1C[0x24];
    Vec origin;
    Vec destination;
};

// A mine thrown by a TBoss6Mag (spawn_mag_mine_at): it drops away below the floor, rises again at
// its destination and explodes after 150 frames or when a player comes near. The class name is the
// one its constructor gives the object.
class TBoss6MagMine : public TObjEnemy {
public:
    TBoss6MagMine(TObject *parent, Boss6MagMineSetData *set_data);
    virtual ~TBoss6MagMine();
    void update_linked_state();
    virtual void run_death_reaction();
    virtual void run_hit_reaction();
    virtual void render();
    virtual void run_task();
    void copy_pos();
    void damage_player(TObjPlayer *player);
    void explode();
    s32 is_player_in_range();
    void state_0();
    void state_1();
    void state_2();
    void state_3();
    void state_4();
    static TBoss6MagMine *create(Boss6MagMineSetData *set_data);
    static void spawn_mag_mine_at(const Vec *origin, const Vec *destination);
    BmlResource *archive;             // TBoss6PlotFalz::get_scene_archive(): texlist, model and motion
    Vec flight_velocity;              // level, towards destination at 4.166667 a frame; falls by 0.25
    Vec destination;                  // the set data's destination
    s32 state;                        // 4 once killed
    s32 state_timer;
    f32 motion_frame;                 // draw_model_motion's frame
    s32 attack_power;                 // the param table's +4 (20 when not positive), varied 10% per hit
    s32 status_chance;                // the param table's +8, 0..100
    s32 status_count;                 // compared below status_chance before a status hit
    f32 hit_flash;                    // 1.0 on a hit, passed to the draw tint
    s32 angle_y;                      // render's rotate_matrix_y angle
    TParticleCtrl *particle_emitter;  // create_particle_emitter(&position, 0x146)
};

LAYOUT_ASSERT(Boss6MagMineSetData_size, sizeof(Boss6MagMineSetData) == 0x58);
LAYOUT_ASSERT(TBoss6MagMine_size, sizeof(TBoss6MagMine) == 0x3B4);

#endif
