#include "types.h"
#include "pso/ui/charcreate/TChCrTagInformation.h"

extern "C" {

void *TChCrTagInformation__ct(void *, void *, void *);
void *__nw__7TObjectFUl(int);

extern void *tl_03;

void *TChCrTagInformation::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x3C);
    if (o != NULL) {
        o = TChCrTagInformation__ct(o, tl_03, arg0);
    }
    return o;
}

void *TChCrTagInformation::create_default() { return TChCrTagInformation::create((void *)((void*)(0))); }

}
