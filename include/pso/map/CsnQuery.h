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

// The deepest contact of a wall ray query (field names inferred).
struct WallRayResult {
    CsnHit header;  // one contact per ray
    s32 index;  // the ray that went deepest
    f32 depth;

    WallRayResult *init();
};

LAYOUT_ASSERT(WallRayResultSize, sizeof(WallRayResult) == 0x10);
LAYOUT_ASSERT(WallRayResultHeaderOffset, offsetof(WallRayResult, header) == 0);

// The collision groups of the floor's loaded c.rel module (NULL when none).
extern CsnGroup **scene_collision_data;

CsnHit *csnVector(const Vec *from, const Vec *to, u32 mask);
extern "C" {
CsnGroup *select_ground_query_groups(const Vec *origin, u32 mask);
}
// The deepest wall the rays of query reach within its radius, NULL for none.
WallRayResult *query_wall_radial(WallRayQuery *query);
extern "C" {
// Line of sight: the hit record when a wall lies between from and to.
CsnHit *csnLookAt(const Vec *from, const Vec *to);
}

// The scene buffer prepare_wall_query_polygons copies wall polygons into.
void free_wall_query_buffer(void);
void alloc_wall_query_buffer(void);
void csn_debug_hook_ground_query(void);
void csn_debug_hook_contact_color(CsnContact *contact, NJS_ARGB *color);
void csn_debug_hook_hit_record(CsnHit *hit);
void csn_debug_hook_group_list(CsnGroup *const *groups);
void csn_debug_hook_query_name(const char *name);
void csn_debug_hook_query_begin(void);
void csn_debug_hook_origin_vector(const Vec *origin);
void csn_debug_hook_segment(const Vec *from, const Vec *to);
extern "C" {
s32 get_csn_group_flags(u8 ch);
}
s32 calc_segment_xz_distance_sq(Vec *c, Vec *o, Vec *e, Vec *d, f32 radius, f32 hsq, f32 inv);
s32 select_deepest_wall_ray(WallRayQuery *query, WallRayResult *result);
s32 query_segment_wall_meshes(Vec *from, Vec *to, u32 mask, CsnGroup **groups);
s32 check_line_hits_walls(Vec *from, Vec *to, u32 mask, CsnGroup **groups);
s32 intersect_wall_triangle_one_sided(Vec *origin, Vec *dir, u32 mask, CsnFace *face, Vec *vertices, s32 mode);
extern "C" {
CsnGroup *refill_csn_candidate_cache(Vec *origin, CsnGroup **cache, u32 mask);
}
CsnGroup *select_segment_query_groups(Vec *from, Vec *to);
CsnGroup *query_collision_segment_groups(Vec *a, Vec *b, u32 mask);
s32 evaluate_ground_triangles(Vec *origin, u32 mask, CsnGroup **groups);
s32 prepare_wall_query_polygons(const Vec *pos, f32 r, u32 mask);
WallRayResult *query_prepared_wall_polygons(WallRayQuery *query);
s32 query_wall_segment(Vec *from, Vec *to, u32 mask, CsnContact *hit);
struct CsnContact;
struct CsnHit;

CsnContact *init_csn_contact(CsnContact *contact);
void init_csn_hit(CsnHit *hit);

#endif
