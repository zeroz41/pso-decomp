#include "types.h"
#include "pso/object/TObjMapObject.h"
#include "pso/misc/TOBarrierEnergy01.h"

void TOBarrierEnergy01::update_closing() { this->update_anim_phase(); this->m_ac = 0; this->play_ambient_loop_sound(); }
