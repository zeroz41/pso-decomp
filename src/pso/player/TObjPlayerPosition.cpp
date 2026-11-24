#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

void TObjPlayer::update_position(saddr record) {
    set_position_from((void *)(record + 8));
    save_previous_position();
    calc_attach_pos();
    set_position_history_entry(0, position.x, position.z);
}
