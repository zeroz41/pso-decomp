#include "types.h"
#include "versions.h"
#include "pso/quest/challenge/TChallenge.h"
#include "pso/system/task/TObject.h"

extern "C" {

void *TChallenge__ct(void *, void *);

extern void *tl_su;

void *TChallenge::create() {
#if VERSION == VERSION_GPOP8P
    void *o = TObject::operator new(0x44);
#else
    void *o = TObject::operator new(0x30);
#endif
    if (o != NULL) {
        o = TChallenge__ct(o, tl_su);
    }
    return o;
}

}
