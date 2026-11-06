#ifndef PSO_UI_CHARCREATE_TCHCRTAG_H
#define PSO_UI_CHARCREATE_TCHCRTAG_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TChCrTag : public TObject {
public:
    TChCrTag(TObject *parent, void *arg);
    virtual ~TChCrTag();
    virtual void render();
    virtual s32 vt4();
public:
};

// TChCrTag's destructor, run_task slot and slot 6 are still written as C functions, and the derived
// tags' constructors (C functions too) call the constructor by its symbol.
extern "C" {
void *__ct__8TChCrTagFP7TObjectPv(void *self, TObject *parent, void *arg);
void *__dt__8TChCrTagFv(void *self, s16 flag);
void update_fade__8TChCrTagFPv(u8 *self);
int TChCrTag__vt4(void);
}

#endif
