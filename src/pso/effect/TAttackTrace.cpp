#include "pso/effect/TAttackTrace.h"

TAttackTrace::~TAttackTrace() {}

#include "types.h"

#pragma readonly_strings on


const char *TAttackTrace::class_name = "TAttackTrace";


TAttackTrace::TAttackTrace(TObject *parent) : TObject(parent) {
    m_name = class_name;
    segment_count = 0;
}
