#ifndef PSO_PLAYER_TOBJPLAYER_803E112C_H
#define PSO_PLAYER_TOBJPLAYER_803E112C_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include <stddef.h>

// A collision body of shape 1: the eight world-space corners built by build_collision_box_corners.
struct CollisionBox { Vec corners[8]; };

// Any other collision body: a sphere (the body's centre on the y = 0 plane and its radius).
struct CollisionSphere { Vec center; f32 radius; };

LAYOUT_ASSERT(CollisionSphereSize, sizeof(CollisionSphere) == 0x10);
LAYOUT_ASSERT(CollisionSphereRadiusOffset, offsetof(CollisionSphere, radius) == 0xC);

extern "C" {
// 1 if the sphere touches a face of the box or lies inside it.
s32 test_box_sphere_contact(Vec *corners, CollisionSphere *sphere);
}

// 1 if the two spheres touch.
s32 spheres_overlap(CollisionSphere *a, CollisionSphere *b);

#endif
