#include "types.h"
#include "pso/npc/TObjNpcFemale.h"
#include "pso/object/base/TObjMotion.h"

const TObjMotionAction TObjNpcFemale::action_table[2] = {
    {MOTION_MODE_LOOP, -1, 0, 0.9f, 1},
    {MOTION_MODE_LOOP, -1, 2, 1.4f, ACTION_INTERPOLATE | 2},
};
u32 TObjNpcFemale::shared_resource;

void TObjNpcFemale::request_action(s32 action) {
    if (action != 1) {
        this->requested_action = 0;
        return;
    }
    this->requested_action = 1;
}

void TObjNpcFemale::free_resources() {
    if (shared_resource != 0U) {
        shared_resource = 0U;
    }
}

void TObjNpcFemale::load_resources() { shared_resource = town_npc_shared_resource; }

TObjNpcFemale::~TObjNpcFemale() {}

TObjNpcFemale::TObjNpcFemale(TObject *parent) : TObjNpcBase(parent) {
    init_motion((TObjMotionAction *)action_table, (BmlMotionEntry *)*(uaddr *)npc_town_motion_data, 0);
    set_motion_interpolation_flag();
}
