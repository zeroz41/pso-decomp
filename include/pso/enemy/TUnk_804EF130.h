#ifndef PSO_ENEMY_TUNK_804EF130_H
#define PSO_ENEMY_TUNK_804EF130_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TUnk_804EF130 : public TObjCollidable {
public:
    virtual ~TUnk_804EF130();
    u8 unk_AC[0x34];
    void * m_e0;
    u8 unk_E4[0x18];
};
typedef char TUnk_804EF130_size[sizeof(TUnk_804EF130) == 0xFC ? 1 : -1];

#endif
