#include "types.h"
#include "pso/technique/TTecSlicer.h"

struct O_8023B590 { s16 h[10]; s8 b[10]; s8 count; };

extern "C" {
void fn_8023B590(O_8023B590 *o, s16 v, s8 b);

void fn_8023B590(O_8023B590 *o, s16 v, s8 b) {
    if (o->count < 10) {
        o->h[o->count] = v;
        o->b[o->count] = b;
        o->count++;
    }
}

}
