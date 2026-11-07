#include "types.h"
#include "pso/npc/TUnk_804A8640.h"
#include "pso/object/base/TObjMotion.h"

// The action table every TUnk_804A8640 NPC starts with.
const TObjMotionAction npc_female_base_action_table[2] = {
    {MOTION_MODE_LOOP, -1, 0, 0.9f, 1},
    {MOTION_MODE_LOOP, -1, 2, 1.4f, ACTION_INTERPOLATE | 2},
};
u32 lbl_805D5758;

void TUnk_804A8640::request_action(s32 action) {
    if (action != 1) {
        this->requested_action = 0;
        return;
    }
    this->requested_action = 1;
}

void TObjNpcFemaleBase__sub_80149C64(void) {
    if (lbl_805D5758 != 0U) {
        lbl_805D5758 = 0U;
    }
}

extern "C" {
u8 * TObjNpcBase__ct(void *);
extern s32 __vt__13TUnk_804A8640[];
extern s32 *npc_town_motion_data;
extern u32 lbl_805D5D78;
}

void TObjNpcFemaleBase__sub_80149C7C(void) { lbl_805D5758 = lbl_805D5D78; }

TUnk_804A8640::~TUnk_804A8640() {}

u8 *TUnk_804A8640::construct_female_base() {
    TObjNpcBase__ct(this);
    *(s32 **)((u8 *)this + 0x18) = __vt__13TUnk_804A8640;
    init_motion((TObjMotionAction *)npc_female_base_action_table, (BmlMotionEntry *)*npc_town_motion_data, 0);
    set_motion_interpolation_flag();
    return (u8 *)this;
}
