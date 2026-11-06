#include "types.h"
#include "pso/technique/TTecLuker.h"

void TTecLuker::set_state(s32 v) { *(s32 *)&this->m_name = v; }
