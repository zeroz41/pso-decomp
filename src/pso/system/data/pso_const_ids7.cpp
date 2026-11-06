#include "types.h"
#include "pso/object/trap/TOTrapAncient02R.h"

s32 TOTrapAncient02R::is_any_player_matching_stat() { return 0; }
s32 TOTrapAncient02R::try_start_action(s32, s32) { return 1; }
s32 TOTrapAncient02R::roll_physical_accuracy(void *, s32, f32) { return 1; }
s32 TOTrapAncient02R::select_melee_contact_body(void *, f32) { return 1; }
int TOTrapAncient02R::calc_distance_accuracy_penalty(void *, void *, void *, float) { return 1; }
