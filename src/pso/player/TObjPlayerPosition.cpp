#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSyncRecord.h"

void TObjPlayer::update_position(PlayerSyncRecord *record) {
    set_position_from(&record->position);
    save_previous_position();
    calc_attach_pos();
    set_position_history_entry(0, position.x, position.z);
}
