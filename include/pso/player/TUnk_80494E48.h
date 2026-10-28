#ifndef PSO_PLAYER_TUNK_80494E48_H
#define PSO_PLAYER_TUNK_80494E48_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TUnk_80494E48 : public TObjCollidable {
public:
    virtual ~TUnk_80494E48();
    void *destroy_particle_obj(s16);
    u8 unk_AC[0x4C];
    void * m_f8;
    u8 unk_FC[0x8];
};
typedef char TUnk_80494E48_size[sizeof(TUnk_80494E48) == 0x104 ? 1 : -1];

#endif
