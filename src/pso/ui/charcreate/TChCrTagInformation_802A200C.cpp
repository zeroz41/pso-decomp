#include "types.h"
#include "pso/ui/charcreate/TChCrTagInformation.h"
#include "pso/system/task/TMainTask.h"

extern "C" {

void *TChCrTagInformation::create(void *arg0) {
    return new TChCrTagInformation(tl_03, arg0);
}

void *TChCrTagInformation::create_default() { return TChCrTagInformation::create(NULL); }

}
