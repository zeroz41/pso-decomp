#include "pso/ui/frontend/TAdFloorLoadGC.h"
#include "pso/ui/frontend/TAdFloorLoadCamGC.h"
#include "pso/ui/frontend/TAdFloorLoadPrtGC.h"

#include "types.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on


void TAdFloorLoadGC::render() {  }
void TAdFloorLoadGC::run_task() {  }

const char *TAdFloorLoadGC_class_name = "TAdFloorLoadGC";

TAdFloorLoadGC::~TAdFloorLoadGC() {}
TAdFloorLoadGC::TAdFloorLoadGC(TObject *parent, s32 mode) : TObject(parent) {
    this->m_name = TAdFloorLoadGC_class_name;
    new TAdFloorLoadCamGC(this, mode);
    new TAdFloorLoadPrtGC(this);
}

void TAdFloorLoadGC::cleanup() {  }
void TAdFloorLoadGC::setup() {  }
