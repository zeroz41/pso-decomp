#include "types.h"
#include "pso/npc/TUnk_804A92A8.h"
#include "pso/object/base/TObjMotion.h"

// The action table every TUnk_804A92A8 NPC starts with.
const TObjMotionAction town_npc_animation_init_data[2] = {
    {MOTION_MODE_LOOP, -1, 0, 0.9f, 1},
    {MOTION_MODE_LOOP, -1, 3, 1.4f, ACTION_INTERPOLATE | 2},
};
u32 lbl_805D5798;

void TUnk_804A92A8::request_action(s32 action) {
    if (action != 1) {
        this->requested_action = 0;
        return;
    }
    this->requested_action = 1;
}

void TObjNpcFemaleTall__sub_8014AA48(void) {
    if (lbl_805D5798 != 0U) {
        lbl_805D5798 = 0U;
    }
}

extern uaddr npc_town_motion_data;
extern u32 lbl_805D5D78;

void TObjNpcFemaleTall__sub_8014AA60(void) { lbl_805D5798 = lbl_805D5D78; }

TUnk_804A92A8::~TUnk_804A92A8() {}

TUnk_804A92A8::TUnk_804A92A8(TObject *parent) : TObjNpcBase(parent) {
    init_motion((TObjMotionAction *)town_npc_animation_init_data, (BmlMotionEntry *)*(uaddr *)npc_town_motion_data, 0);
    set_motion_interpolation_flag();
}
