#ifndef PSO_NPC_TUNK_804A92A8_H
#define PSO_NPC_TUNK_804A92A8_H
#include "types.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/object/base/TObjMotion.h"

// Twin of TUnk_804A8640 (same vtable but for the dtor and request_action); base of HFW00/HFW01.
class TUnk_804A92A8 : public TObjNpcBase {
public:
    virtual ~TUnk_804A92A8();
    virtual void request_action(s32 action);
    u8 *fn_8014AAC4();
};

// Idle and talk motions installed by fn_8014AAC4.
extern const TObjMotionAction town_npc_animation_init_data[2];

// The floor resource load/free callbacks of its shared data (TLobby_800F795C).
extern "C" {
void TObjNpcFemaleTall__sub_8014AA48(void);
void TObjNpcFemaleTall__sub_8014AA60(void);
}

#endif
