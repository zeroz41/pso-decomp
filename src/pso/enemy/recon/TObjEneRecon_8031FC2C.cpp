#include "types.h"
#include "pso/system/vector.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/recon/TObjEneRecobox.h"
#include "pso/enemy/recon/TObjEneRecon.h"

void TObjEneRecon::restore_position() { VecCopy((Vec *)((char*)this + 0x74), (const Vec *)((char*)this + 0x2fc)); }
void TObjEneRecobox::vfunc_61() {  }
void TObjEneRecobox::vfunc_62() { clear_attack_receipts(); }
void TObjEneRecobox::vfunc_63() { if (this->mode != 6) { transition_enemy_state((s16)((void*)6)); } }
void TObjEneRecobox::vfunc_28() {  }
