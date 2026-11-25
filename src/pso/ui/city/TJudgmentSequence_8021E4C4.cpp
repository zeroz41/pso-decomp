#include "types.h"
#include "pso/ui/city/TJudgmentSequence_8021E4C4.h"
#include "pso/ui/city/TJudgmentSequence.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

extern "C" {
void *TJudgmentSequence::create(void *player) {
    return new TJudgmentSequence(tl_05, (TObjPlayer *)player);
}
}

int get_judgment_shop_slot_flags(int a0) {  return TJudgmentSequence::slot_flags[a0]; }
