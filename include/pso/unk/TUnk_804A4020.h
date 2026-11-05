#ifndef PSO_UNK_TUNK_804A4020_H
#define PSO_UNK_TUNK_804A4020_H
#include "types.h"
#include "pso/TItemShootModel.h"

// The shot model TObjPlayer::spawn_shot_effect news for TUnk_804A403C.
class TUnk_804A4020 : public TItemShootModel {
public:
    TUnk_804A4020(void *owner, const Vec *pos, const Vec *dir, f32 life);
    virtual ~TUnk_804A4020();
    virtual void hook();
    virtual void render();
};

extern "C" {
// Picks the model the owning weapon draws its shots with (0x188 while flag 4 is set, else 0x184).
s32 TObjPlayer__sub_801290D0(u8 *arg0);
}

typedef char TUnk_804A4020_size[sizeof(TUnk_804A4020) == 0x6C ? 1 : -1];

#endif
