#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOFenceAncient01.h"
#include "pso/player/TUnk_804B1B80.h"
#include "pso/player/TObjPlayer.h"

void TUnk_804B1B80::vfunc_14() {  }
void TUnk_804B1B80::vfunc_15() {  }
void TUnk_804B1B80::vfunc_16() {  }
void TOFenceAncient01::vfunc_16() {  }
void TOFenceAncient01::vfunc_15() { *(int *)&this->m_ac = 0; this->m_d0 = 0; this->clear_player_status_flag((s32)((void*)0), (u32)((void*)8)); }
void TOFenceAncient01::vfunc_14() { *(int *)&this->m_ac = 1; this->m_d0 = 1; set_indexed_flags((s32)((void*)0), (s32)((void*)8)); }
