#ifndef PSO_EFFECT_TATTACKTRACE_H
#define PSO_EFFECT_TATTACKTRACE_H

#include "pso/TObject.h"
#include "types.h"

class TAttackTrace : public TObject {
public:
    virtual ~TAttackTrace();
};

extern "C" {
void *TAttackTrace__ct(void *attack_trace);
}

#endif
