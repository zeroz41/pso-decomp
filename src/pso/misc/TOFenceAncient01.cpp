#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOFenceAncient01.h"
#include "pso/player/TUnk_804B1B80.h"
#include "pso/player/TObjPlayer.h"

void TOFenceAncient01::update_demo() {  }
void TOFenceAncient01::close() { *(int *)&this->m_ac = 0; this->is_open = 0; this->clear_player_status_flag((s32)((void*)0), (u32)((void*)8)); }
void TOFenceAncient01::open() { *(int *)&this->m_ac = 1; this->is_open = 1; set_indexed_flags((s32)((void*)0), (s32)((void*)8)); }
