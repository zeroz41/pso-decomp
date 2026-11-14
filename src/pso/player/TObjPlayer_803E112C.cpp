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
static const Faces_803E0ED4 box_face_vertex_index_table = {
    {{0, 1, 2, 3}, {4, 7, 6, 5}, {0, 3, 7, 4}, {2, 1, 5, 6}, {0, 4, 5, 1}, {3, 2, 6, 7}}};
static const Faces_803E0ED4 box_edge_adjacent_face_table = {
    {{4, 3, 5, 2}, {2, 5, 3, 4}, {0, 5, 1, 4}, {0, 4, 1, 5}, {2, 1, 3, 0}, {0, 3, 1, 2}}};
static const EdgeOrder_803E112C lbl_8047E558 = {{0, 1, 2, 3, 0}};

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

s32 test_box_sphere_contact(Vec_803E1B1C *box, CollisionSphere *sphere) {
    Vec_803E1B1C boxMin;
    Vec_803E1B1C boxMax;
    Vec_803E1B1C sphereMin;
    Vec_803E1B1C sphereMax;
    calc_bounds_min_max__10TObjPlayerFPvPvPv(box, &boxMin, &boxMax);
    ((TObjPlayer *)sphere)->calc_bounds((u8 *)&sphereMin, (u8 *)&sphereMax);
    if (((TObjPlayer *)&boxMin)->test_aabb_overlap((u8 *)&boxMax, (u8 *)&sphereMin, (u8 *)&sphereMax) != 0) {
        Faces_803E0ED4 faces = box_face_vertex_index_table;
        Vec_803E1B1C normals[6];
        Faces_803E0ED4 adjacent = box_edge_adjacent_face_table;
        s32 i;
        s32 j;
        s32 inside = 1;
        for (i = 0; i < 6; i++) {
            s32 *face = faces.v[i];
            Vec_803E1B1C *n = &normals[i];
            f32 scale;
            n->x = -((box[face[1]].y - box[face[0]].y) * (box[face[2]].z - box[face[0]].z) - (box[face[1]].z - box[face[0]].z) * (box[face[2]].y - box[face[0]].y));
            n->y = -((box[face[1]].z - box[face[0]].z) * (box[face[2]].x - box[face[0]].x) - (box[face[1]].x - box[face[0]].x) * (box[face[2]].z - box[face[0]].z));
            n->z = -((box[face[1]].x - box[face[0]].x) * (box[face[2]].y - box[face[0]].y) - (box[face[1]].y - box[face[0]].y) * (box[face[2]].x - box[face[0]].x));
            scale = 1.0f / collisionRoot(n->z * n->z + (n->x * n->x + n->y * n->y));
            n->x *= scale;
            n->y *= scale;
            n->z *= scale;
        }
        for (i = 0; i < 6; i++) {
            s32 faceHit = 1;
            Vec_803E1B1C *n = &normals[i];
            s32 *face = faces.v[i];
            Vec_803E1B1C *center = &sphere->center;
            f32 d = -(n->z * box[face[0]].z + (n->x * box[face[0]].x + n->y * box[face[0]].y));
            f32 t = -(d + (center->z * n->z + (center->x * n->x + center->y * n->y))) /
                    (n->z * n->z + (n->x * n->x + n->y * n->y));
            f32 px = center->x + t * n->x;
            f32 py = center->y + t * n->y;
            f32 pz = center->z + t * n->z;
            f32 dist = collisionRoot((pz - center->z) * (pz - center->z) +
                                     ((px - center->x) * (px - center->x) + (py - center->y) * (py - center->y)));
            for (j = 0; j < 4; j++) {
                EdgeOrder_803E112C order = lbl_8047E558;
                Vec_803E1B1C *a = &box[face[order.v[j]]];
                Vec_803E1B1C *b = &box[face[order.v[j + 1]]];
                f32 ex = a->x - b->x;
                f32 ey = a->y - b->y;
                f32 ez = a->z - b->z;
                f32 s = (ez * (pz - a->z) + (ex * (px - a->x) + ey * (py - a->y))) / (ez * ez + (ex * ex + ey * ey));
                f32 fx = ex * s + a->x;
                f32 fy = ey * s + a->y;
                f32 fz = ez * s + a->z;
                f32 dx = fx - px;
                f32 dy = fy - py;
                f32 dz = fz - pz;
                f32 scale = 1.0f / collisionRoot(dz * dz + (dx * dx + dy * dy));
                dx *= scale;
                dy *= scale;
                dz *= scale;
                if ((f32)__fabs(normals[adjacent.v[i][order.v[j]]].x - dx) <= 0.025f &&
                    (f32)__fabs(normals[adjacent.v[i][order.v[j]]].y - dy) <= 0.025f &&
                    (f32)__fabs(normals[adjacent.v[i][order.v[j]]].z - dz) <= 0.025f &&
                    sphere->radius >= dist) {
                    faceHit &= 1;
                } else if (dist <= sphere->radius) {
                    if ((pz - fz) * (pz - fz) + ((px - fx) * (px - fx) + (py - fy) * (py - fy)) <=
                    sphere->radius * sphere->radius - dist * dist) {
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
            f32 dx = px - sphere->center.x;
            f32 dy = py - sphere->center.y;
            f32 dz = pz - sphere->center.z;
            f32 scale = 1.0f / collisionRoot(dz * dz + (dx * dx + dy * dy));
            dx *= scale;
            dy *= scale;
            dz *= scale;
            if ((f32)__fabs(n->x - dx) <= 0.025f && (f32)__fabs(n->y - dy) <= 0.025f &&
                      (f32)__fabs(n->z - dz) <= 0.025f) inside &= 1; else inside = 0;
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
