#ifndef PSO_MAP_CSNGEOMETRY_H
#define PSO_MAP_CSNGEOMETRY_H

#include "types.h"
#include <dolphin/mtx.h>
#include <stddef.h>

struct CsnVector {
    f32 x, y, z;
};

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

typedef char CsnFaceSize[sizeof(CsnFace) == 0x24 ? 1 : -1];

struct CsnGroup {
    CsnModel *model;
    CsnVector center;
    f32 radius;
    u32 flags;
};

typedef char CsnVectorSize[sizeof(CsnVector) == 0xC ? 1 : -1];
typedef char CsnGroupSize[sizeof(CsnGroup) == 0x18 ? 1 : -1];
typedef char CsnGroupCenterOffset[offsetof(CsnGroup, center) == 4 ? 1 : -1];
typedef char CsnGroupRadiusOffset[offsetof(CsnGroup, radius) == 0x10 ? 1 : -1];
typedef char CsnGroupFlagsOffset[offsetof(CsnGroup, flags) == 0x14 ? 1 : -1];

typedef char CsnModelSize[sizeof(CsnModel) == 0x10 ? 1 : -1];
typedef char CsnModelVerticesOffset[offsetof(CsnModel, vertices) == 4 ? 1 : -1];
typedef char CsnModelFacesOffset[offsetof(CsnModel, faces) == 0xC ? 1 : -1];

#endif
