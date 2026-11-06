#include "types.h"
#include "pso/ui/TChCrCharSelect.h"

extern "C" {

void *__nw__7TObjectFUl(int);

void *TChCrCharSelect::create(void *object) {
    void *o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__15TChCrCharSelectFv(o, object);
    }
    return o;
}

}
