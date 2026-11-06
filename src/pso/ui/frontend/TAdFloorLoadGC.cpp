#include "pso/ui/frontend/TAdFloorLoadGC.h"
#include "pso/ui/frontend/TAdFloorLoadCamGC.h"

#include "types.h"

extern "C" {

void *TAdFloorLoadPrtGC__ct(void *, void *);
void *__nw__7TObjectFUl(int);

void TAdFloorLoadGC::render() {  }
void TAdFloorLoadGC::run_task() {  }

extern void *lbl_805D4328;

TAdFloorLoadGC::~TAdFloorLoadGC() {}
}
TAdFloorLoadGC::TAdFloorLoadGC(TObject *object, void *arg2) : TObject(object) {
    void *o;
    void *o2;
    *(void * *)&this->m_name = lbl_805D4328;
    o = new TAdFloorLoadCamGC(this, arg2);
    o2 = __nw__7TObjectFUl(0x3A0);
    if (o2 != NULL) {
        TAdFloorLoadPrtGC__ct(o2, this);
    }
}
