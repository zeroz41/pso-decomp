#ifndef PSO_MATH_BOXCOLLISION_H
#define PSO_MATH_BOXCOLLISION_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include <stddef.h>

// One row per box face: its four corner indices, or (the adjacent-face table) the face across each of its edges.
struct BoxFaces { s32 v[6][4]; };

// The four corner indices of each face of a box.
extern const BoxFaces box_face_corner_index_table;

// The four edges of a face: corner slots 0-1, 1-2, 2-3, 3-0.
struct FaceEdgeLoop { s32 v[5]; };

// A quad corner projected onto the XY, XZ or YZ plane.
struct ProjectedPoint { f32 u, v; };

// A collision body of shape 1: the eight world-space corners built by build_collision_box_corners.
struct CollisionBox { Vec corners[8]; };

// Any other collision body: a sphere (the body's centre on the y = 0 plane and its radius).
struct CollisionSphere { Vec center; f32 radius; };

LAYOUT_ASSERT(CollisionSphereSize, sizeof(CollisionSphere) == 0x10);
LAYOUT_ASSERT(CollisionSphereRadiusOffset, offsetof(CollisionSphere, radius) == 0xC);

struct Line { Vec origin; Vec direction; };

// BoxOverlap.cpp
// 1 if the boxes minA..maxA and minB..maxB (axis-aligned) overlap.
s32 test_aabb_overlap(Vec *minA, Vec *maxA, Vec *minB, Vec *maxB);
// The area of the triangle a, b, c.
f32 triangle_area(ProjectedPoint *a, ProjectedPoint *b, ProjectedPoint *c);
// 1 if a corner of the smaller of the quads a and b lies inside the larger one.
s32 quad_corner_inside(ProjectedPoint *a, ProjectedPoint *b);
// 1 if the quads a and b (four corners each) touch.
s32 quads_touch(Vec *a, Vec *b);
// The planes in which a corner of one quad lies inside the other: 4 = XY, 2 = XZ, 1 = YZ.
s32 quad_projection_overlap_mask(Vec *a, Vec *b);
// 1 if two boxes (eight corners each, as built by build_collision_box_corners) touch.
s32 test_box_overlap(Vec *cornersA, Vec *cornersB);

// BoxSphereContact.cpp
// 1 if the sphere touches a face of the box or lies inside it.
s32 test_box_sphere_contact(Vec *corners, CollisionSphere *sphere);
// 1 if the two spheres touch.
s32 spheres_overlap(CollisionSphere *a, CollisionSphere *b);

// PointLineDistance.cpp
// The distance from p to the line l; the closest point on l goes to out when it is not NULL.
f32 project_point_onto_line(Vec *p, Line *l, Vec *out);

#endif
