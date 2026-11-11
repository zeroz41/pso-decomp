#ifndef PSO_PLAYER_TUNK_804A2548_H
#define PSO_PLAYER_TUNK_804A2548_H
#include "types.h"
#include "pso/item/TUnk_804E355C.h"

class TUnk_804A2548 : public TUnk_804E355C {
public:
    TUnk_804A2548(TObject *parent, S_802E451C *params);
    virtual ~TUnk_804A2548();
    virtual void run_task();
    f32 pad_C4; // run_task grows body.radius up to it, then destroys the collider
};
typedef char TUnk_804A2548_size[sizeof(TUnk_804A2548) == 0xC8 ? 1 : -1];

#endif
