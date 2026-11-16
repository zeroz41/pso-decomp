#include "types.h"
#include "pso/quest/challenge/TChallenge.h"
#include "pso/system/task/TObject.h"

extern "C" {

void *TChallenge__ct(void *, void *);

extern void *tl_su;

void *TChallenge::create() {
    void *o = TObject::operator new(0x30);
    if (o != NULL) {
        o = TChallenge__ct(o, tl_su);
    }
    return o;
}

}
