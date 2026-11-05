#ifndef PSO_PLAYER_TUNK_804A0AA8_H
#define PSO_PLAYER_TUNK_804A0AA8_H
#include "types.h"
#include "pso/TItemShootModel.h"

class TUnk_804A0AA8 : public TItemShootModel {
public:
    virtual ~TUnk_804A0AA8();
    TUnk_804A0AA8(void *owner, const Vec *pos, const Vec *dir, f32 life);
    virtual void hook();
    virtual void render();
};
typedef char TUnk_804A0AA8_size[sizeof(TUnk_804A0AA8) == 0x6C ? 1 : -1];

#endif
