#ifndef PSO_PLAYER_TPLAYERSOUL_H
#define PSO_PLAYER_TPLAYERSOUL_H
#include "pso/player/TPlayerParticleOwner.h"
class TPlayerSoul : public TPlayerParticleOwner {
public:
    TPlayerSoul(TObject* parent, u16 player_id);
    virtual ~TPlayerSoul();
    void set_player_id(u16);
    void set_particle(TParticleCtrl*);
    TObjPlayer*get_player();
    virtual void run_task();
};
LAYOUT_ASSERT(TPlayerSoul_size, sizeof(TPlayerSoul) == 0x24);
#endif
