#include "types.h"
#include "pso/npc/TObjNpcMale.h"
#include "pso/object/base/TObjMotion.h"

const TObjMotionAction TObjNpcMale::action_table[2] = {
    { MOTION_MODE_LOOP, -1, 0, 0.9f, 0x1 },
    { MOTION_MODE_LOOP, -1, 1, 1.4f, ACTION_INTERPOLATE | 0x2 },
};
u32 TObjNpcMale::shared_resource;

void TObjNpcMale::request_action(s32 action) {
    if (action != 1) {
        this->requested_action = 0;
        return;
    }
    this->requested_action = 1;
}

void TObjNpcMale::free_resources() {
    if (shared_resource != 0U) {
        shared_resource = 0U;
    }
}

void TObjNpcMale::load_resources() { shared_resource = town_npc_shared_resource; }

TObjNpcMale::~TObjNpcMale() {}

TObjNpcMale::TObjNpcMale(TObject *parent) : TObjNpcBase(parent) {
    init_motion((TObjMotionAction *)action_table, (BmlMotionEntry *)*(uaddr *)npc_town_motion_data, 0);
    set_motion_interpolation_flag();
}
