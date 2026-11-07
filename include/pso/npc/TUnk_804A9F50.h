#ifndef PSO_NPC_TUNK_804A9F50_H
#define PSO_NPC_TUNK_804A9F50_H
#include "types.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/object/base/TObjMotion.h"

// Male town NPC base: twin of TUnk_804A8640 (construct_female_base); base of the
// HHM/HRM/NFM/Male*/Soldier* NPCs.
class TUnk_804A9F50 : public TObjNpcBase {
public:
    virtual ~TUnk_804A9F50();
    virtual void request_action(s32 action);
    u8 *construct_male_npc_base();
};

// Idle and talk motions installed by construct_male_npc_base.
extern const TObjMotionAction male_npc_idle_animation_parameters[2];

// The floor resource load/free callbacks of its shared data (TLobby_800F795C).
extern "C" {
void TObjNpcLappy__sub_8014B828(void);
void TObjNpcLappy__sub_8014B840(void);
}

#endif
