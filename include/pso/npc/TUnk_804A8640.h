#ifndef PSO_NPC_TUNK_804A8640_H
#define PSO_NPC_TUNK_804A8640_H
#include "types.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/object/base/TObjMotion.h"

class TUnk_804A8640 : public TObjNpcBase {
public:
    virtual ~TUnk_804A8640();
    virtual void request_action(s32 action);
    u8 *construct_female_base();
};

// Idle and talk motions installed by construct_female_base.
extern const TObjMotionAction npc_female_base_action_table[2];

// The floor resource load/free callbacks of its shared data (TLobby_800F795C).
extern "C" {
void TObjNpcFemaleBase__sub_80149C64(void);
void TObjNpcFemaleBase__sub_80149C7C(void);
}

#endif
