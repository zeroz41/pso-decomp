#include "pso/ui/frontend/TAdFloorLoadGC.h"
#include "pso/ui/frontend/TAdFloorLoadCamGC.h"
#include "pso/ui/frontend/TAdFloorLoadPrtGC.h"

#include "types.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

extern "C" {

void TAdFloorLoadGC::render() {  }
void TAdFloorLoadGC::run_task() {  }

const char *lbl_805D4328 = "TAdFloorLoadGC";

TAdFloorLoadGC::~TAdFloorLoadGC() {}
}
TAdFloorLoadGC::TAdFloorLoadGC(TObject *object, void *arg2) : TObject(object) {
    this->m_name = lbl_805D4328;
    new TAdFloorLoadCamGC(this, arg2);
    new TAdFloorLoadPrtGC(this);
}
