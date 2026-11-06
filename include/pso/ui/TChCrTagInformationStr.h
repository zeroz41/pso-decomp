#ifndef PSO_UI_TCHCRTAGINFORMATIONSTR_H
#define PSO_UI_TCHCRTAGINFORMATIONSTR_H

#include "pso/TObject.h"
#include "types.h"

class TChCrTagInformationStr : public TObject {
public:
    virtual ~TChCrTagInformationStr();
    virtual void render();
    virtual void run_task();
public:
    static void *create(void *arg0, void *arg1);
};

extern "C" {
void *__ct__22TChCrTagInformationStrFv(void *arg0, s32 arg1, s32 arg2);
void run_task__22TChCrTagInformationStrFv(u8 *arg0);
}

#endif
