#include "types.h"
#include "pso/object/TObjMapObject.h"
#include "pso/misc/TOBarrierEnergy01.h"

void TOBarrierEnergy01::vfunc_16() { this->update_anim_phase(); this->play_ambient_loop_sound(); this->m_ac = 2; }
