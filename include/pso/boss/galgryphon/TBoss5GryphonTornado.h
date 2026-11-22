#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONTORNADO_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONTORNADO_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

struct TBoss5Gryphon;
class TParticleCtrl;

struct TBoss5GryphonTornado : public TObject {
    TBoss5GryphonTornado(TObject *parent, TBoss5Gryphon *gryphon, const Vec *pos, u16 target_client_id);
    virtual ~TBoss5GryphonTornado();
    // Drops a tornado onto the floor under pos; none when the floor there is above gryphon_max_floor_height.
    static TBoss5GryphonTornado *spawn(TObject *parent, TBoss5Gryphon *gryphon, const Vec *pos, u16 target_client_id);
    static void release_particle_table();  // TBoss5Gryphon::cleanup's counterpart, empty
    static void select_particle_table();  // load_boss5_gryphon_resources picks the particle ids
    void get_target_direction(Vec *dir);  // unit xz direction to the target player, 0 without one
    virtual void render();
    virtual void run_task();

    s32 state;
    s32 timer;
    u16 target_client_id;  // the player it drifts towards (get_player_by_client_id); 0xFFFF for none
    Vec position;
    Vec velocity;
    u8 pad_40[0xC];
    TBoss5Gryphon *gryphon;  // the tornado ends when this gryphon's flag bit 6 is set
    TParticleCtrl *particles[3];  // gryphon_tornado_particle_id_table[0..2]
};

LAYOUT_ASSERT(TBoss5GryphonTornado_size, sizeof(TBoss5GryphonTornado) == 0x5C);

#endif
