#include "types.h"
#include "pso/npc/TObjNpcFomarl.h"
#include "pso/object/base/TObjMotion.h"

extern uaddr npc_town_motion_data;
extern u32 lbl_805D5D78;

const TObjMotionAction TObjNpcFomarl::action_table[2] = {
    {MOTION_MODE_LOOP, -1, 0, 0.9f, 1},
    {MOTION_MODE_LOOP, -1, 3, 1.4f, ACTION_INTERPOLATE | 2},
};
u32 TObjNpcFomarl::shared_resource;

void TObjNpcFomarl::request_action(s32 action) {
    if (action != 1) {
        this->requested_action = 0;
        return;
    }
    this->requested_action = 1;
}

void TObjNpcFomarl::free_resources() {
    if (shared_resource != 0U) {
        shared_resource = 0U;
    }
}

void TObjNpcFomarl::load_resources() { shared_resource = lbl_805D5D78; }

TObjNpcFomarl::~TObjNpcFomarl() {}

TObjNpcFomarl::TObjNpcFomarl(TObject *parent) : TObjNpcBase(parent) {
    init_motion((TObjMotionAction *)action_table, (BmlMotionEntry *)*(uaddr *)npc_town_motion_data, 0);
    set_motion_interpolation_flag();
}
