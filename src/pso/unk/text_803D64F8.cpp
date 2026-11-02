#include "types.h"
struct Obj_803D64F8 {
    f32 a, b, c, d, e, f;
    s32 g;
    s32 h;
    f32 i, j;
};

extern "C" {
void fn_803D64F8(Obj_803D64F8 *p);
#pragma push
#pragma scheduling off
void fn_803D64F8(Obj_803D64F8 *p) {
    p->a = 0.0f;
    p->b = 0.0f;
    p->c = 0.0f;
    p->d = 0.0f;
    p->e = 0.0f;
    p->f = -1.0f;
    p->g = 0;
    p->h = 0x2aaa;
    p->i = -1.0f;
    p->j = -60000.0f;
}
#pragma pop

}
