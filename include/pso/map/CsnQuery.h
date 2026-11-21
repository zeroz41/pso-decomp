#ifndef PSO_MAP_CSNQUERY_H
#define PSO_MAP_CSNQUERY_H

#include "types.h"
#include "pso/map/CsnGroundQuery.h"
#include <stddef.h>
#include <dolphin/mtx.h>
#include "pso/system/NinjaTypes.h"

#include "pso/map/CsnGeometry.h"

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
CsnGroup *select_ground_query_groups(const Vec *origin, u32 mask);
// The deepest wall the rays of query reach within its radius, NULL for none.
WallRayResult *query_wall_radial(WallRayQuery *query);
// Line of sight: the hit record when a wall lies between from and to.
CsnHit *csnLookAt(const Vec *from, const Vec *to);
}

extern "C" {
void TObjPlayer__sub_80079108(void);
void TObjPlayer__sub_8007910C(CsnContact *contact, NJS_ARGB *color);
void TObjPlayer__sub_80079110(CsnHit *hit);
void TObjPlayer__sub_80079114(CsnGroup *const *groups);
void TObjPlayer__sub_80079118(const char *name);
void TObjPlayer__sub_8007911C(void);
void TObjPlayer__sub_80079120(saddr _w0);
void TObjPlayer__sub_80079124(void *_w0, void *_w1);
s32 *csnVecterUnder(saddr origin, s32 mask);
s32 get_csn_group_flags(u8 arg0);
}
s32 prepare_wall_query_polygons(void *arg0, f32 r, s32 mask);
void *query_prepared_wall_polygons(void *self);
s32 query_wall_segment(void *arg0, void *arg1, void *arg2, s32 arg3);
#endif
