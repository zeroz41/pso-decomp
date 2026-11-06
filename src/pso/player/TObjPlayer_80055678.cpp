#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/darkfalz/TBoss4Type1.h"

// TBoss4Type1's status-ailment slots, all empty: Dark Falz's first form ignores them.
void TBoss4Type1::apply_poison_status() {  }
void TBoss4Type1::apply_paralysis() {  }
void TBoss4Type1::apply_slow_status() {  }
void TBoss4Type1::apply_confusion_status() {  }
void TBoss4Type1::apply_movement_ailment(s32) {  }
void TBoss4Type1::apply_shock_status() {  }
void TBoss4Type1::clear_harmful_statuses() {  }
void*TObjPlayer::get_position_ptr() { return (char*)this + 0x38; }
