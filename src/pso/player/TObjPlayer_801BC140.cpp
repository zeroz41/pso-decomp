#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"


void TObjPlayer::update_position(saddr arg1) {
    set_position_from((void *)(arg1 + 8));
    ((TObjBase *)this)->save_previous_position();
    calc_attach_pos();
    set_position_history_entry(0, this->position.x, this->position.z);
}

