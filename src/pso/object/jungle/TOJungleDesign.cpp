#include "types.h"
#include "pso/object/jungle/TOJungleDesign.h"
#include "pso/object/jungle/TOJungleDesign_802FEEB4.h"

extern "C" {

void *__nw__7TObjectFUl(int);

extern void *tl_05;

void *TOJungleDesign__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xB4);
    if (o != NULL) {
        o = TOJungleDesign__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

}
