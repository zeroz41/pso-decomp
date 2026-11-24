#include "types.h"
#include "pso/math/BoxCollision.h"

#pragma push
#pragma scheduling off

f32 project_point_onto_line(Vec *p, Line *l, Vec *out) {
    f32 t;
    f32 x;
    f32 r;
    t = (l->direction.z * (p->z - l->origin.z) + (l->direction.x * (p->x - l->origin.x) + l->direction.y * (p->y - l->origin.y))) /
        (l->direction.z * l->direction.z + (l->direction.x * l->direction.x + l->direction.y * l->direction.y));
    if (out != NULL) {
        out->x = l->origin.x + l->direction.x * t;
        out->y = l->origin.y + l->direction.y * t;
        out->z = l->origin.z + l->direction.z * t;
        x = (p->z - out->z) * (p->z - out->z) + ((p->x - out->x) * (p->x - out->x) + (p->y - out->y) * (p->y - out->y));
    } else {
        x = (p->z - (l->origin.z + l->direction.z * t)) * (p->z - (l->origin.z + l->direction.z * t)) +
            ((p->x - (l->origin.x + l->direction.x * t)) * (p->x - (l->origin.x + l->direction.x * t)) +
             (p->y - (l->origin.y + l->direction.y * t)) * (p->y - (l->origin.y + l->direction.y * t)));
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
