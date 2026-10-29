#include "types.h"
#include "pso/misc/TODoorBase.h"

s32 TODoorBase::init_door_switch_binding() {
    s32 temp_r0;

    this->switch_id = (s32) this->set_params[0];
    temp_r0 = this->switch_id;
    if (temp_r0 > 0x100) {
        this->lock_mode = 0;
    } else if (temp_r0 < 0) {
        this->lock_mode = 1;
    } else {
        this->lock_mode = 2;
    }
    return this->switch_id;
}
