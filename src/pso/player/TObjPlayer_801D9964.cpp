#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

u8 get_cast_technique_level(void*, s16);

s32 TObjPlayer::validate_and_clear_slot(void *techs, s16 tech) { return is_invalid_slot(get_cast_technique_level(techs, tech)); }

}
