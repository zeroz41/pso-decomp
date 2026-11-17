#include "types.h"
#include "pso/player/TObjPlayer_803DF7A8.h"
#include "pso/player/TObjPlayer_803E112C.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
#pragma push
#pragma fp_contract off

struct CollisionSphere { Vec_803E1B1C center; f32 radius; };
struct EdgeOrder_803E112C { s32 v[5]; };
inline const Faces_803E0ED4 *box_faces() {
    static const Faces_803E0ED4 box_face_vertex_index_table = {
        {{0, 1, 2, 3}, {4, 7, 6, 5}, {0, 3, 7, 4}, {2, 1, 5, 6}, {0, 4, 5, 1}, {3, 2, 6, 7}}};
    return &box_face_vertex_index_table;
}
inline const Faces_803E0ED4 *box_adjacent() {
    static const Faces_803E0ED4 box_edge_adjacent_face_table = {
        {{4, 3, 5, 2}, {2, 5, 3, 4}, {0, 5, 1, 4}, {0, 4, 1, 5}, {2, 1, 3, 0}, {0, 3, 1, 2}}};
    return &box_edge_adjacent_face_table;
}
inline const EdgeOrder_803E112C *box_order() {
    static const EdgeOrder_803E112C box_edge_order_table = {{0, 1, 2, 3, 0}};
    return &box_edge_order_table;
}

#pragma use_lmw_stmw off

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
static inline f32 collisionRoot(f32 x) {
    volatile f32 y;
    if (x > 0.0f) {
        f64 guess = __frsqrte(x);
        guess = 0.5 * guess * (3.0 - guess * guess * x);
        guess = 0.5 * guess * (3.0 - guess * guess * x);
        guess = 0.5 * guess * (3.0 - guess * guess * x);
        y = (f32)(x * guess);
        return y;
    }
    return x;
}

#pragma opt_loop_invariants off
s32 test_box_sphere_contact(Vec_803E1B1C *box, CollisionSphere *sphere) {
    Vec_803E1B1C boxMin;
    Vec_803E1B1C boxMax;
    Vec_803E1B1C sphereMin;
    Vec_803E1B1C sphereMax;
    calc_bounds_min_max__10TObjPlayerFPvPvPv(box, &boxMin, &boxMax);
    ((TObjPlayer *)sphere)->calc_bounds((u8 *)&sphereMin, (u8 *)&sphereMax);
    if (((TObjPlayer *)&boxMin)->test_aabb_overlap((u8 *)&boxMax, (u8 *)&sphereMin, (u8 *)&sphereMax) != 0) {
        Faces_803E0ED4 faces = *box_faces();
        Vec_803E1B1C normals[6];
        Faces_803E0ED4 adjacent = *box_adjacent();
        s32 i;
        s32 j;
        s32 inside = 1;
        f32 tdx;
        f32 px;
        f32 nscale;
        f32 py;
        f32 pz;
        f32 fx;
        f32 ex;
        f32 fy;
        f32 t;
        f32 ey;
        f32 tdy;
        f32 fz;
        f32 tscale;
        f32 dd;
        f32 ez;
        f32 ay;
        f32 dx;
        f32 dy;
        f32 ax;
        f32 scale;
        f32 tdz;
        f32 s;
        f32 dz;
        f32 az;
        for (i = 0; i < 6; i++) {
            s32 *face = faces.v[i];
            Vec_803E1B1C *n = &normals[i];
            n->x = -((box[face[1]].y - box[face[0]].y) * (box[face[2]].z - box[face[0]].z) - (box[face[1]].z - box[face[0]].z) * (box[face[2]].y - box[face[0]].y));
            n->y = -((box[face[1]].z - box[face[0]].z) * (box[face[2]].x - box[face[0]].x) - (box[face[1]].x - box[face[0]].x) * (box[face[2]].z - box[face[0]].z));
            n->z = -((box[face[1]].x - box[face[0]].x) * (box[face[2]].y - box[face[0]].y) - (box[face[1]].y - box[face[0]].y) * (box[face[2]].x - box[face[0]].x));
            nscale = 1.0f / collisionRoot(n->z * n->z + (n->x * n->x + n->y * n->y));
            n->x *= nscale;
            n->y *= nscale;
            n->z *= nscale;
        }
        for (i = 0; i < 6; i++) {
            s32 faceHit = 1;
            Vec_803E1B1C *n = &normals[i];
            s32 *face = faces.v[i];
            Vec_803E1B1C *center = &sphere->center;
            f32 d = -(n->z * box[face[0]].z + (n->x * box[face[0]].x + n->y * box[face[0]].y));
            t = -(d + (center->z * n->z + (center->x * n->x + center->y * n->y))) /
                    (n->z * n->z + (n->x * n->x + n->y * n->y));
            px = center->x + t * n->x;
            py = center->y + t * n->y;
            pz = center->z + t * n->z;
            f32 dist = collisionRoot((pz - center->z) * (pz - center->z) +
                                     ((px - center->x) * (px - center->x) + (py - center->y) * (py - center->y)));
            for (j = 0; j < 4; j++) {
                dd = dist * dist;
                EdgeOrder_803E112C order = *box_order();
                s32 k = order.v[j] << 2;
                ax = box[*(s32 *)((u8 *)face + k)].x;
                Vec_803E1B1C *b = &box[face[order.v[j + 1]]];
                ex = ax - b->x;
                ey = (ay = box[*(s32 *)((u8 *)face + k)].y) - b->y;
                ez = (az = box[*(s32 *)((u8 *)face + k)].z) - b->z;
                s = (ez * (pz - az) + (ex * (px - ax) + ey * (py - ay))) / (ez * ez + (ex * ex + ey * ey));
                fx = ex * s;
                fx += ax;
                fy = ey * s;
                fy += ay;
                fz = ez * s - -az;
                dx = fx - px;
                dy = fy - py;
                dz = fz - pz;
                scale = 1.0f / collisionRoot(dz * dz + (dx * dx + dy * dy));
                dx *= scale;
                dy *= scale;
                dz *= scale;
                if ((f32)__fabs(normals[*(s32 *)((u8 *)adjacent.v[i] + k)].x - dx) <= 0.025f &&
                    (f32)__fabs(normals[*(s32 *)((u8 *)adjacent.v[i] + k)].y - dy) <= 0.025f &&
                    (f32)__fabs(normals[*(s32 *)((u8 *)adjacent.v[i] + k)].z - dz) <= 0.025f &&
                    sphere->radius >= dist) {
                    faceHit &= 1;
                } else if (dist <= sphere->radius) {
                    if ((pz - fz) * (pz - fz) + ((px - fx) * (px - fx) + (py - fy) * (py - fy)) <=
                    sphere->radius * sphere->radius - dd) {
                        faceHit &= 1;
                    } else {
                        faceHit = 0;
                    }
                } else {
                    faceHit = 0;
                }
            }
            if (faceHit != 0) {
                return 1;
            }
            tdx = px - center->x;
            tdy = py - center->y;
            tdz = pz - center->z;
            tscale = 1.0f / collisionRoot(tdz * tdz + (tdx * tdx + tdy * tdy));
            tdx *= tscale;
            tdy *= tscale;
            tdz *= tscale;
            if ((f32)__fabs(n->x - tdx) <= 0.025f && (f32)__fabs(n->y - tdy) <= 0.025f &&
                      (f32)__fabs(n->z - tdz) <= 0.025f) inside &= 1; else inside = 0;
        }
        if (inside != 0) {
            return 1;
        }
    }
    return 0;
}
#pragma pop

#pragma pop
}

s32 spheres_overlap(u8 *arg0, u8 *arg1) {
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    temp_f3 = *(f32 *)((s8 *)arg1 + 0) - *(f32 *)((s8 *)arg0 + 0);
    temp_f4 = *(f32 *)((s8 *)arg1 + 4) - *(f32 *)((s8 *)arg0 + 4);
    temp_f2 = *(f32 *)((s8 *)arg1 + 8) - *(f32 *)((s8 *)arg0 + 8);
    temp_f5 = *(f32 *)((s8 *)arg0 + 0xC) + *(f32 *)((s8 *)arg1 + 0xC);
    return ((temp_f2 * temp_f2) + ((temp_f3 * temp_f3) + (temp_f4 * temp_f4))) <= (temp_f5 * temp_f5);
}
