#ifndef PSO_PLAYER_TPLAYERPARTICLEOWNER_H
#define PSO_PLAYER_TPLAYERPARTICLEOWNER_H
#include "pso/system/task/TObject.h"
class TParticleCtrl;
struct TObjPlayer;
class TPlayerParticleOwner : public TObject {
public:
    TPlayerParticleOwner(TObject* parent);
    virtual ~TPlayerParticleOwner();
    TParticleCtrl* get_particle();
    u16 player_id;
    TParticleCtrl* particle;
};
typedef char TPlayerParticleOwner_size[sizeof(TPlayerParticleOwner) == 0x24 ? 1 : -1];
#endif
