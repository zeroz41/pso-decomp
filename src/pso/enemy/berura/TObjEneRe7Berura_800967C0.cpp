#include "types.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/enemy/berura/TObjEneRe7BeruraPunch.h"

extern "C" {

void *__nw__7TObjectFUl(int);

void *TObjEneRe7Berura::spawn_punch(void *arg0) {
    void *o = __nw__7TObjectFUl(0x11C);
    if (o != NULL) {
        o = TObjEneRe7BeruraPunch__ct((TObjEneRe7BeruraPunch *)o, (TObject *)arg0, (TObjBase *)arg0);
    }
    return o;
}

}
