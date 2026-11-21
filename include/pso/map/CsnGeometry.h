#ifndef PSO_MAP_CSNGEOMETRY_H
#define PSO_MAP_CSNGEOMETRY_H

#include "types.h"
#include <dolphin/mtx.h>
#include <stddef.h>

// One collision triangle (field names inferred from evaluate_ground_triangles).
struct CsnFace {
    u16 vertex[3]; // indices into CsnModel::vertices
    u16 flags;     // surface attribute bits tested against the query mask
    Vec normal;
    Vec center;    // centre and radius of the bounding circle
    f32 radius;
};

// The triangle mesh of a collision group (field names inferred).
struct CsnModel {
    s32 vertex_count;
    Vec *vertices;
    s32 face_count;
    CsnFace *faces;
};

LAYOUT_ASSERT(CsnFaceSize, sizeof(CsnFace) == 0x24);

struct CsnGroup {
    CsnModel *model;
    Vec center;
    f32 radius;
    u32 flags;
};

LAYOUT_ASSERT(CsnGroupSize, sizeof(CsnGroup) == 0x18);
LAYOUT_ASSERT(CsnGroupCenterOffset, offsetof(CsnGroup, center) == 4);
LAYOUT_ASSERT(CsnGroupRadiusOffset, offsetof(CsnGroup, radius) == 0x10);
LAYOUT_ASSERT(CsnGroupFlagsOffset, offsetof(CsnGroup, flags) == 0x14);

LAYOUT_ASSERT(CsnModelSize, sizeof(CsnModel) == 0x10);
LAYOUT_ASSERT(CsnModelVerticesOffset, offsetof(CsnModel, vertices) == 4);
LAYOUT_ASSERT(CsnModelFacesOffset, offsetof(CsnModel, faces) == 0xC);

#endif
