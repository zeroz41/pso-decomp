// The De Rol Le tunnel particles' common parent: TObjBoss2Tunnel__sub_8003B2B0 creates the TObject that
// detach_children and release_children re-parent the particles to. Its own TU (twin: text_802F190C.cpp for
// Boss7): its .sbss (TObjBoss2Tunnel_parent_object and pad, 0x805D4BF8) sits between TObjBoss2DustCtrl's and
// TObjBoss2Tunnel's 8-aligned .sbss, and TObjBoss2Tunnel's .sdata2 pool starts with render (0x8003B2EC).
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8003B138.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixOps.h"

struct Child_8003B250 { u8 pad0[0x44]; f32 f44; };
struct Obj_8003B250 { u8 pad0[0x14]; Child_8003B250 *child; };
struct Obj_8003B1FC { u8 pad[0x14]; Obj_8003B1FC *child; u8 pad2[0x3c - 0x18]; Vec xf; };

TObject *TObjBoss2Tunnel_parent_object;

void TObjBoss2Tunnel::detach_children(void *offset) {
    Obj_8003B1FC *c;
    while ((c = ((Obj_8003B1FC *)this)->child) != 0) {
        vec3_add_to(&c->xf, (const Vec *)offset);
        ((TObject *)c)->set_parent(TObjBoss2Tunnel_parent_object);
    }
}

void TObjBoss2Tunnel::release_children(void *particle, f32 speed) {
    Child_8003B250 *c;
    while ((c = ((Obj_8003B250 *)particle)->child) != NULL) {
        c->f44 = c->f44 + speed;
        ((TObject *)c)->set_parent(TObjBoss2Tunnel_parent_object);
    }
}

void TObjBoss2Tunnel__sub_8003B2B0(void) {
    TObjBoss2Tunnel_parent_object = new TObject(tl_07);
}
