#include "pso/effect/TAttackTrace.h"

TAttackTrace::~TAttackTrace() {}

#include "types.h"

extern "C" {

void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__12TAttackTrace[];
extern void *lbl_805D2A90;

void *TAttackTrace__ct(void *attack_trace) {
    __ct__7TObjectFP7TObject(attack_trace);
    *(s32 **)((s8 *)attack_trace + 0x18) = __vt__12TAttackTrace;
    *(void * *)&((TAttackTrace *)attack_trace)->m_name = lbl_805D2A90;
    *(u32 *)((s8 *)attack_trace + 0x1C) = 0;
    return attack_trace;
}

}
