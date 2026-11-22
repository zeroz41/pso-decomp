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
    void sub_803554F0(u8 *);
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
