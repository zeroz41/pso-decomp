#include "types.h"
#include "pso/system/vector.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

typedef struct Vec_80325D58 { f32 x; f32 y; f32 z; } Vec_80325D58;

extern "C" {
f32 newton_sqrtf(f32);
f32 vec3_dot(void *, void *);
void normalize_vector(void *);
extern const f32 lbl_805DF630;
extern const f32 lbl_805DF634;
s32 TObjPlayer__sub_80325D58(void *arg0, Vec_80325D58 *from, Vec_80325D58 *dir, Vec_80325D58 *to, f32 dist);
int queue_destruction__7TObjectFv(void*);

int TBoss8Dragon::queue_destruction() { return queue_destruction__7TObjectFv(this); }
#pragma push
#pragma fp_contract on
#define STEP_80325D58() \
    { \
        f32 xx = d.x * d.x; \
        f32 yy = d.y * d.y; \
        f32 zz = d.z * d.z; \
        if (newton_sqrtf(zz + (xx + yy)) <= dist) { \
            return 0; \
        } \
        to->x = dir->x * dist + from->x; \
        to->y = dir->y * dist + from->y; \
        to->z = dir->z * dist + from->z; \
        return 1; \
    }
s32 TObjPlayer__sub_80325D58(void *arg0, Vec_80325D58 *from, Vec_80325D58 *dir, Vec_80325D58 *to, f32 dist) {
    Vec_80325D58 d;
    Vec_80325D58 n;
    f32 t;
    d.x = to->x - from->x;
    d.y = to->y - from->y;
    d.z = to->z - from->z;
    t = vec3_dot(dir, &d);
    if (lbl_805DF630 > t) {
        VecCopy((Vec *)to, (const Vec *)from);
        return 1;
    }
    if (lbl_805DF634 != t) {
        VecCopy((Vec *)&n, (const Vec *)&d);
        normalize_vector(&n);
        if (lbl_805DF634 != vec3_dot(dir, &n)) {
            STEP_80325D58()
        }
        STEP_80325D58()
    }
    STEP_80325D58()
}
#pragma pop

}
