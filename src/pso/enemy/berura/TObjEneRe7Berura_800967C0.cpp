#include "types.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"

extern "C" {

u8 *TObjEneRe7BeruraPunch__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__nw__7TObjectFUl(int);

void *TObjEneRe7Berura::spawn_punch(void *arg0) {
    void *o = __nw__7TObjectFUl(0x11C);
    if (o != NULL) {
        o = TObjEneRe7BeruraPunch__ct((u8 *)o, (s32)arg0, (s32)arg0);
    }
    return o;
}

}
