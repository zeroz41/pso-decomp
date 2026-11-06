#include "types.h"
#include "pso/ui/charcreate/TChCrTagInformation.h"
#include "pso/ui/charcreate/TChCrTagInformation_802A1FAC.h"
#include "pso/system/task/TMainTask.h"

extern "C" {

void *__nw__7TObjectFUl(int);


void *TChCrTagInformation::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x3C);
    if (o != NULL) {
        o = TChCrTagInformation__ct((TChCrTagInformation *)o, tl_03, arg0);
    }
    return o;
}

void *TChCrTagInformation::create_default() { return TChCrTagInformation::create((void *)((void*)(0))); }

}
