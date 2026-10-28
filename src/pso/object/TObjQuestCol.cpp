#include "types.h"
#include "pso/quest/TQuestThread.h"
#include "pso/object/TObjQuestCol.h"

extern "C" {

s32 update_trigger_state__16TObjQuestColBaseFf(f32);

int TObjQuestCol::vfunc_16() { TQuestThreadBoard::destroy_board(); TQuestThread::create(this->m_b0); }

int TObjQuestCol::vfunc_15() {
    return (u32)__cntlzw(1 - update_trigger_state__16TObjQuestColBaseFf(*(f32 *)&this->unk_AC)) >> 5;
}

}
