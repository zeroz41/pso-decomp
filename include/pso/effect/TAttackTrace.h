#ifndef PSO_EFFECT_TATTACKTRACE_H
#define PSO_EFFECT_TATTACKTRACE_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TAttackTrace : public TObject {
public:
    TAttackTrace(TObject *parent);
    virtual ~TAttackTrace();
};

#endif
