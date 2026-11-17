#include "types.h"
#define PSO_SDK_COMPACT_MATH
#include <libc/math.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/player/TObjPlayer_803DF7A8.h"
#include "pso/player/TObjPlayer_803E112C.h"
#include "pso/player/TObjPlayer_803E1A58.h"

extern "C" {
#pragma push
#pragma fp_contract off

// The four edges of a face: corner slots 0-1, 1-2, 2-3, 3-0.
struct FaceEdgeLoop { s32 v[5]; };
inline const BoxFaces *box_faces() {
    static const BoxFaces box_face_vertex_index_table = {
        {{0, 1, 2, 3}, {4, 7, 6, 5}, {0, 3, 7, 4}, {2, 1, 5, 6}, {0, 4, 5, 1}, {3, 2, 6, 7}}};
    return &box_face_vertex_index_table;
}
inline const BoxFaces *box_adjacent() {
    static const BoxFaces box_edge_adjacent_face_table = {
        {{4, 3, 5, 2}, {2, 5, 3, 4}, {0, 5, 1, 4}, {0, 4, 1, 5}, {2, 1, 3, 0}, {0, 3, 1, 2}}};
    return &box_edge_adjacent_face_table;
}
inline const FaceEdgeLoop *box_order() {
    static const FaceEdgeLoop box_edge_order_table = {{0, 1, 2, 3, 0}};
    return &box_edge_order_table;
}

#pragma use_lmw_stmw off

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
#pragma opt_loop_invariants off
s32 test_box_sphere_contact(Vec *corners, CollisionSphere *sphere) {
    Vec boxMin;
    Vec boxMax;
    Vec sphereMin;
    Vec sphereMax;
    calc_box_bounds(corners, &boxMin, &boxMax);
    calc_sphere_bounds(sphere, &sphereMin, &sphereMax);
    if (test_aabb_overlap(&boxMin, &boxMax, &sphereMin, &sphereMax) != 0) {
        BoxFaces faces = *box_faces();
        Vec normals[6];
        BoxFaces adjacentFaces = *box_adjacent();
        s32 i;
        s32 j;
        s32 inside = 1;
        f32 toFootX;
        f32 footX;
        f32 normalScale;
        f32 footY;
        f32 footZ;
        f32 nearX;
        f32 edgeX;
        f32 nearY;
        f32 planeT;
        f32 edgeY;
        f32 toFootY;
        f32 nearZ;
        f32 toFootScale;
        f32 planeDistSq;
        f32 edgeZ;
        f32 startY;
        f32 toEdgeX;
        f32 toEdgeY;
        f32 startX;
        f32 toEdgeScale;
        f32 toFootZ;
        f32 edgeT;
        f32 toEdgeZ;
        f32 startZ;
        for (i = 0; i < 6; i++) {
            s32 *face = faces.v[i];
            Vec *normal = &normals[i];
            normal->x = -((corners[face[1]].y - corners[face[0]].y) * (corners[face[2]].z - corners[face[0]].z) - (corners[face[1]].z - corners[face[0]].z) * (corners[face[2]].y - corners[face[0]].y));
            normal->y = -((corners[face[1]].z - corners[face[0]].z) * (corners[face[2]].x - corners[face[0]].x) - (corners[face[1]].x - corners[face[0]].x) * (corners[face[2]].z - corners[face[0]].z));
            normal->z = -((corners[face[1]].x - corners[face[0]].x) * (corners[face[2]].y - corners[face[0]].y) - (corners[face[1]].y - corners[face[0]].y) * (corners[face[2]].x - corners[face[0]].x));
            normalScale = 1.0f / sqrtf(normal->z * normal->z + (normal->x * normal->x + normal->y * normal->y));
            normal->x *= normalScale;
            normal->y *= normalScale;
            normal->z *= normalScale;
        }
        for (i = 0; i < 6; i++) {
            s32 faceHit = 1;
            Vec *normal = &normals[i];
            s32 *face = faces.v[i];
            Vec *center = &sphere->center;
            f32 planeD = -(normal->z * corners[face[0]].z + (normal->x * corners[face[0]].x + normal->y * corners[face[0]].y));
            planeT = -(planeD + (center->z * normal->z + (center->x * normal->x + center->y * normal->y))) /
                     (normal->z * normal->z + (normal->x * normal->x + normal->y * normal->y));
            footX = center->x + planeT * normal->x;
            footY = center->y + planeT * normal->y;
            footZ = center->z + planeT * normal->z;
            f32 planeDist = sqrtf((footZ - center->z) * (footZ - center->z) +
                                  ((footX - center->x) * (footX - center->x) + (footY - center->y) * (footY - center->y)));
            for (j = 0; j < 4; j++) {
                planeDistSq = planeDist * planeDist;
                FaceEdgeLoop loop = *box_order();
                s32 cornerOffset = loop.v[j] << 2;
                startX = corners[*(s32 *)((u8 *)face + cornerOffset)].x;
                Vec *end = &corners[face[loop.v[j + 1]]];
                edgeX = startX - end->x;
                edgeY = (startY = corners[*(s32 *)((u8 *)face + cornerOffset)].y) - end->y;
                edgeZ = (startZ = corners[*(s32 *)((u8 *)face + cornerOffset)].z) - end->z;
                edgeT = (edgeZ * (footZ - startZ) + (edgeX * (footX - startX) + edgeY * (footY - startY))) / (edgeZ * edgeZ + (edgeX * edgeX + edgeY * edgeY));
                nearX = edgeX * edgeT;
                nearX += startX;
                nearY = edgeY * edgeT;
                nearY += startY;
                nearZ = edgeZ * edgeT - -startZ;
                toEdgeX = nearX - footX;
                toEdgeY = nearY - footY;
                toEdgeZ = nearZ - footZ;
                toEdgeScale = 1.0f / sqrtf(toEdgeZ * toEdgeZ + (toEdgeX * toEdgeX + toEdgeY * toEdgeY));
                toEdgeX *= toEdgeScale;
                toEdgeY *= toEdgeScale;
                toEdgeZ *= toEdgeScale;
                if ((f32)__fabs(normals[*(s32 *)((u8 *)adjacentFaces.v[i] + cornerOffset)].x - toEdgeX) <= 0.025f &&
                    (f32)__fabs(normals[*(s32 *)((u8 *)adjacentFaces.v[i] + cornerOffset)].y - toEdgeY) <= 0.025f &&
                    (f32)__fabs(normals[*(s32 *)((u8 *)adjacentFaces.v[i] + cornerOffset)].z - toEdgeZ) <= 0.025f &&
                    sphere->radius >= planeDist) {
                    faceHit &= 1;
                } else if (planeDist <= sphere->radius) {
                    if ((footZ - nearZ) * (footZ - nearZ) + ((footX - nearX) * (footX - nearX) + (footY - nearY) * (footY - nearY)) <=
                        sphere->radius * sphere->radius - planeDistSq) {
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
            toFootX = footX - center->x;
            toFootY = footY - center->y;
            toFootZ = footZ - center->z;
            toFootScale = 1.0f / sqrtf(toFootZ * toFootZ + (toFootX * toFootX + toFootY * toFootY));
            toFootX *= toFootScale;
            toFootY *= toFootScale;
            toFootZ *= toFootScale;
            if ((f32)__fabs(normal->x - toFootX) <= 0.025f && (f32)__fabs(normal->y - toFootY) <= 0.025f &&
                (f32)__fabs(normal->z - toFootZ) <= 0.025f) {
                inside &= 1;
            } else {
                inside = 0;
            }
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

s32 spheres_overlap(CollisionSphere *a, CollisionSphere *b) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 reach;
    dx = b->center.x - a->center.x;
    dy = b->center.y - a->center.y;
    dz = b->center.z - a->center.z;
    reach = a->radius + b->radius;
    return ((dz * dz) + ((dx * dx) + (dy * dy))) <= (reach * reach);
}
