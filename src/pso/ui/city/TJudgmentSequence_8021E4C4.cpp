#include "types.h"
#include "pso/ui/city/TJudgmentSequence_8021E4C4.h"
#include "pso/ui/city/TJudgmentSequence.h"
#include "pso/system/task/TObject.h"

extern "C" {


extern void *tl_05;

void *TJudgmentSequence::create(void *arg0) {
    void *o = TObject::operator new(0x34);
    if (o != NULL) {
        o = TJudgmentSequence__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}
}

    extern int TJudgmentSequence__slot_flags[];
int get_judgment_shop_slot_flags(int a0) {  return TJudgmentSequence__slot_flags[a0]; }
