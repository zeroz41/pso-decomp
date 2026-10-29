#include "types.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/object/TObjMapWarp_80141C68.h"

struct Vec_80141CBC { f32 x, y, z; };

extern "C" {
void TOTrapAncient02R__sub_80141CF0(void *a, Vec_80141CBC *v, void *b);

s32 TObjMapWarp__sub_80141C68(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
void TObjMapWarp__sub_80141CA4(void* p) { *(s32*)((char*)p + 0x0) = 0; }
void TObjMapWarp__sub_80141CB0(void) {  }

void TObjMapWarp__sub_80141CB4(void) {  }

void TObjMapWarp__sub_80141CB8(void) {  }

void fn_80141CBC(void *a, void *b, f32 s) {
    Vec_80141CBC v;
    v.x = s;
    v.y = s;
    v.z = s;
    TOTrapAncient02R__sub_80141CF0(a, (Vec_80141CBC *)(&v), b);
}

void TOTrapAncient02R__sub_80141CF0(void * _w0, Vec_80141CBC * _w1, void * _w2) {  }

void TObjRoomId__sub_80141CF4(const Vec *pos, const NJS_ARGB *color, f32 radius) {  }
#pragma fp_contract on
f32 horizontal_distance_squared(const Vec *a, const Vec *b) {
    f32 dx = b->x - a->x;
    f32 dz = b->z - a->z;
    return dx * dx + dz * dz;
}

}
