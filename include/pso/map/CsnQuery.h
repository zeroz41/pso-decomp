#ifndef PSO_MAP_CSNQUERY_H
#define PSO_MAP_CSNQUERY_H

#include "types.h"
#include <stddef.h>
#include <dolphin/mtx.h>
#include "pso/system/NinjaTypes.h"

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
    u8 pad_0[0x4];
    Vec *vertices;
    s32 face_count;
    CsnFace *faces;
};

typedef char CsnFaceSize[sizeof(CsnFace) == 0x24 ? 1 : -1];

struct CsnGroup {
    CsnModel* model;
    CsnVector center;
    f32 radius;
    u32 flags;
};

typedef char CsnVectorSize[sizeof(CsnVector) == 0xC ? 1 : -1];
typedef char CsnGroupSize[sizeof(CsnGroup) == 0x18 ? 1 : -1];
typedef char CsnGroupCenterOffset[offsetof(CsnGroup, center) == 4 ? 1 : -1];
typedef char CsnGroupRadiusOffset[offsetof(CsnGroup, radius) == 0x10 ? 1 : -1];
typedef char CsnGroupFlagsOffset[offsetof(CsnGroup, flags) == 0x14 ? 1 : -1];

CsnGroup* select_ground_query_groups(CsnVector* origin, u32 mask);

// The polygon a segment query hit: the hit point and the polygon normal.
struct CsnContact {
    Vec point;
    Vec normal;
    u32 flags;
};

// The result csnVector returns (one static record, NULL when nothing is hit).
struct CsnHit {
    u32 hit_mask;        // (inferred) bit 0: ground contact, others: per-flag contacts
    CsnContact *contact;
    u8 pad_8[0x38];
};

// A radial wall query (select_deepest_wall_ray's input): count rays from
// origin, one per entry of rays (field names inferred).
struct WallRayQuery {
    s32 count;
    f32 radius;
    u32 mask;
    Vec origin;
    Vec *rays;
};

// One ray's wall contact (field names inferred).
struct WallRayHit {
    Vec point;
    Vec normal;
    u8 pad_18[0x4];
};

// The deepest contact of a wall ray query (field names inferred).
struct WallRayResult {
    s32 hit;
    WallRayHit *hits;
    s32 index;  // the ray that went deepest
    f32 depth;
};

extern "C" {
CsnHit *csnVector(const Vec *from, const Vec *to, u32 mask);
// The deepest wall the rays of query reach within its radius, NULL for none.
WallRayResult *query_wall_radial(WallRayQuery *query);
// Line of sight: the hit record when a wall lies between from and to.
CsnHit *csnLookAt(const Vec *from, const Vec *to);
}

extern "C" {
void TObjPlayer__sub_80079108(void);
void TObjPlayer__sub_8007910C(CsnContact *contact, NJS_ARGB *color);
void TObjPlayer__sub_80079110(CsnHit *hit);
void TObjPlayer__sub_80079114(void);
s32 TObjPlayer__sub_80079118(s32 *_w0);
void TObjPlayer__sub_8007911C(void);
void TObjPlayer__sub_80079120(s32 _w0);
void TObjPlayer__sub_80079124(void *_w0, void *_w1);
s32 *csnVecterUnder(s32 origin, s32 mask);
s32 *csnVectorUnder(Vec *arg0, u32 *arg1, s32 arg2);
s32 get_csn_group_flags(u8 arg0);
}
s32 prepare_wall_query_polygons(void *arg0, f32 r, s32 mask);
void *query_prepared_wall_polygons(void *self);
s32 query_wall_segment(void *arg0, void *arg1, void *arg2, s32 arg3);
CsnGroup *select_ground_query_groups(CsnVector *origin, u32 mask);

#endif
