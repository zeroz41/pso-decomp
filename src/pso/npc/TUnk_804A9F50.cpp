#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/object/base/TObjMotion.h"

const TObjMotionAction male_npc_idle_animation_parameters[2] = {
    { MOTION_MODE_LOOP, -1, 0, 0.9f, 0x1 },
    { MOTION_MODE_LOOP, -1, 1, 1.4f, ACTION_INTERPOLATE | 0x2 },
};
u32 npc_lappy_cached_object;

void TUnk_804A9F50::request_action(s32 action) {
    if (action != 1) {
        this->requested_action = 0;
        return;
    }
    this->requested_action = 1;
}

void TObjNpcLappy__sub_8014B828(void) {
    if (npc_lappy_cached_object != 0U) {
        npc_lappy_cached_object = 0U;
    }
}

extern uaddr npc_town_motion_data;
extern u32 lbl_805D5D78;

void TObjNpcLappy__sub_8014B840(void) { npc_lappy_cached_object = lbl_805D5D78; }

TUnk_804A9F50::~TUnk_804A9F50() {}

TUnk_804A9F50::TUnk_804A9F50(TObject *parent) : TObjNpcBase(parent) {
    init_motion((TObjMotionAction *)male_npc_idle_animation_parameters, (BmlMotionEntry *)*(uaddr *)npc_town_motion_data, 0);
    set_motion_interpolation_flag();
}
