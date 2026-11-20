#include "types.h"
struct Obj_8028A998 { u8 pad[0x2c]; Obj_8028A998 *f2c; Obj_8028A998 *next; };

struct M_8028A9CC { u32 flags; u8 pad4[0x28]; uaddr f2c; M_8028A9CC *next; };

extern "C" {
void clear_child_target_refs(Obj_8028A998 *o, Obj_8028A998 *x);
void clear_chain_flags(M_8028A9CC *arg0, u32 arg1);
void clear_child_target_refs(Obj_8028A998 *o, Obj_8028A998 *x) {
    Obj_8028A998 *p;
    if (o == 0) return;
    for (p = o->f2c; p != 0; p = p->next) {
        if (p->f2c == x) p->f2c = 0;
    }
}
void clear_chain_flags(M_8028A9CC *arg0, u32 arg1) {
    M_8028A9CC *p;
    if (arg0 == 0) return;
    arg0->flags &= ~0x10;
    for (p = (M_8028A9CC *)arg0->f2c; p != 0; p = p->next) {
        p->flags &= ~0x10;
        if (p->f2c == 0) p->f2c = arg1;
    }
}

}
