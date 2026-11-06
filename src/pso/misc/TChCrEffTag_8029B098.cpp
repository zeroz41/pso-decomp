#include "types.h"
#include "pso/ui/TChCrEffTag.h"

extern "C" {

void *__ct__14TChCrEffTagStrFP7TObjectPvPv(void *, void *, void *, void *);
void *__nw__7TObjectFUl(int);

void *TChCrEffTag::create_str(void *arg0, void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x30);
    if (o != NULL) {
        o = __ct__14TChCrEffTagStrFP7TObjectPvPv(o, arg0, arg1, arg2);
    }
    return o;
}

}
