#ifndef PSO_TCHCRTAG_H
#define PSO_TCHCRTAG_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TChCrTag : public TObject {
public:
    TChCrTag(TObject *arg1, void *arg2);
    virtual ~TChCrTag();
    virtual void render();
    virtual s32 vt4();
public:
};

#endif
