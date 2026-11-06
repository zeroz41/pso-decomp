#include "types.h"
#include "pso/quest/challenge/TChallenge.h"

extern "C" {

void *TChallenge__ct(void *, void *);
void *__nw__7TObjectFUl(int);

extern void *tl_su;

void *TChallenge::create() {
    void *o = __nw__7TObjectFUl(0x30);
    if (o != NULL) {
        o = TChallenge__ct(o, tl_su);
    }
    return o;
}

}
