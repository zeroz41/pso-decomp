#include "types.h"
#include "pso/enemy/sorcerer/TObjEneRe4Sorcerer_800EDB98.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"

extern "C" {

s32 enemy_name_for_rt_index(s32 arg0);

const char *TObjEnemy::get_name() { return (const char *)enemy_name_for_rt_index((s32)this->control); }
s32 TObjEnemy::remap_sound_for_area(s32 sound_id) { return ::remap_area_sound_id(sound_id, (s32)this->control); }

}
