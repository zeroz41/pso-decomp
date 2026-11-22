#include "pso/effect/TAttackTrace.h"

TAttackTrace::~TAttackTrace() {}

#include "types.h"

#pragma readonly_strings on


const char *lbl_805D2A90 = "TAttackTrace";


TAttackTrace::TAttackTrace(TObject *parent) : TObject(parent) {
    m_name = lbl_805D2A90;
    *(u32 *)((s8 *)this + 0x1C) = 0;
}
