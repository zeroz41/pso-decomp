#ifndef PSO_PLAYER_TUNK_80494E48_H
#define PSO_PLAYER_TUNK_80494E48_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TUnk_80494E48 : public TObjCollidable {
public:
    virtual ~TUnk_80494E48();
    virtual void run_task();
    u8 unk_AC[0x4C];
    void * m_f8;
    u8 unk_FC[0x8];
};
LAYOUT_ASSERT(TUnk_80494E48_size, sizeof(TUnk_80494E48) == 0x104);

#endif
