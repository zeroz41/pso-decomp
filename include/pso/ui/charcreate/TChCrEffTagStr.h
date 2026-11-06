#ifndef PSO_UI_CHARCREATE_TCHCREFFTAGSTR_H
#define PSO_UI_CHARCREATE_TCHCREFFTAGSTR_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TChCrEffTagStr : public TObject {
public:
    TChCrEffTagStr(TObject *arg1, void *arg2, void *arg3);
    virtual ~TChCrEffTagStr();
    virtual void run_task();
    virtual void render();
};

extern "C" {
void TChCrEffTagStr__sub_8029AED0(void *p);
}

#endif
