#include "types.h"
#include "pso/player/TObjPlayer_803E18C0.h"

#pragma push
#pragma scheduling off

f32 project_point_onto_line(V_803E18C0 *p, Line_803E18C0 *l, V_803E18C0 *out) {
    f32 t;
    f32 x;
    f32 r;
    t = (l->d.z * (p->z - l->o.z) + (l->d.x * (p->x - l->o.x) + l->d.y * (p->y - l->o.y))) /
        (l->d.z * l->d.z + (l->d.x * l->d.x + l->d.y * l->d.y));
    if (out != NULL) {
        out->x = l->o.x + l->d.x * t;
        out->y = l->o.y + l->d.y * t;
        out->z = l->o.z + l->d.z * t;
        x = (p->z - out->z) * (p->z - out->z) + ((p->x - out->x) * (p->x - out->x) + (p->y - out->y) * (p->y - out->y));
    } else {
        x = (p->z - (l->o.z + l->d.z * t)) * (p->z - (l->o.z + l->d.z * t)) +
            ((p->x - (l->o.x + l->d.x * t)) * (p->x - (l->o.x + l->d.x * t)) +
             (p->y - (l->o.y + l->d.y * t)) * (p->y - (l->o.y + l->d.y * t)));
    }
    if (x < 0.025f) {
        return 0.0f;
    }
    if (x > 0.0f) {
        volatile f32 y;
        f64 g = __frsqrte(x);
        g = 0.5 * g * (3.0 - g * g * x);
        g = 0.5 * g * (3.0 - g * g * x);
        g = 0.5 * g * (3.0 - g * g * x);
        y = (f32)(x * g);
        r = y;
    } else {
        r = x;
    }
    return r;
}
#pragma pop
