#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 save_position__14TBoss4DarkFalzFv(void *);
s32 set_position_from__8TObjBaseFPv(void *, s32);

void TObjPlayer::update_position(s32 arg1) {
    set_position_from__8TObjBaseFPv(this, arg1 + 8);
    save_position__14TBoss4DarkFalzFv(this);
    calc_attach_pos();
    set_position_history_entry(0, this->position.x, this->position.z);
}

}
