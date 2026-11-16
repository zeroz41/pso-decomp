#include "pso/ui/frontend/TAdFloorLoadGC.h"
#include "pso/ui/frontend/TAdFloorLoadCamGC.h"

#include "types.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

extern "C" {

void *TAdFloorLoadPrtGC__ct(void *, void *);

void TAdFloorLoadGC::render() {  }
void TAdFloorLoadGC::run_task() {  }

const char *lbl_805D4328 = "TAdFloorLoadGC";

TAdFloorLoadGC::~TAdFloorLoadGC() {}
}
TAdFloorLoadGC::TAdFloorLoadGC(TObject *object, void *arg2) : TObject(object) {
    void *o;
    void *o2;
    this->m_name = lbl_805D4328;
    o = new TAdFloorLoadCamGC(this, arg2);
    o2 = TObject::operator new(0x3A0);
    if (o2 != NULL) {
        TAdFloorLoadPrtGC__ct(o2, this);
    }
}
