#include "types.h"
#include "pso/system/vector.h"
#include "pso/map/CsnQuery.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/object/lobby/TObjButterflyLobby.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_8007A7B8.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_C { u8 bytes[0xc]; };

struct RecoveredGlobal_800790F0_lbl_804F5800 {
    s32 value;
    u8 remaining[0xFC];
};

struct Obj_8007A32C { s32 f0; f32 f4; s32 f8; u8 fc[4]; };

struct E_80079580 { u8 pad[0x24]; u32 f24; };

struct Vec_80079608 {
    f32 x;
    f32 y;
    f32 z;
};

struct Hit_80079608 {
    Vec_80079608 pos;
    Vec_80079608 normal;
    u8 pad18[4];
};

struct Query_80079608 {
    s32 count;
    u8 pad4[4];
    void *flags;
    Vec_80079608 origin;
    Vec_80079608 *offsets;
};

struct Result_80079608 {
    s32 hit;
    Hit_80079608 *hits;
    s32 index;
    f32 best;
};

struct Poly_8007970C { u8 pad[0x24]; };

struct Mesh_8007970C {
    u8 pad0[4];
    u32 flags;
    s32 count;
    Poly_8007970C *polys;
};

struct Node_8007970C {
    Mesh_8007970C *mesh;
};

struct Poly_800797DC { u8 pad[0x24]; };

struct Mesh_800797DC {
    u8 pad0[4];
    u32 flags;
    s32 count;
    Poly_800797DC *polys;
};

struct Node_800797DC {
    Mesh_800797DC *mesh;
};

struct Vec_800798A0 {
    f32 x;
    f32 y;
    f32 z;
};

struct Face_800798A0 {
    u16 idx[3];
    u16 flags;
    Vec_800798A0 n;
};

struct M_80079C64 { u8 pad[4]; f32 x; f32 y; f32 z; f32 rad; u32 flags; };

struct P_80079C64 { f32 x; f32 y; f32 z; };

struct E_80079580;
struct V_80079F58 { f32 x, y, z; };

struct Poly_80079F58 {
    u8 pad0[0x14];
    f32 x;
    f32 y;
    f32 z;
    f32 radius;
};

struct Mesh_80079F58 {
    u32 f0;
    u32 id;
    s32 count;
    Poly_80079F58 *polys;
};

struct Grp_80079F58 {
    Mesh_80079F58 *mesh;
    f32 x;
    f32 y;
    f32 z;
    f32 radius;
    s32 flags;
};

struct Out_80079F58 { u8 pad[0x24]; u32 id; };

struct Vec_8007A138 { f32 x, y, z; };

struct Wall_8007A138 {
    u32 f0;
    Vec_8007A138 pos;
    f32 radius;
    u32 flags;
};

extern RecoveredGlobal_800790F0_lbl_804F5800 __ctype_map;
extern "C" {
s32 get_csn_group_flags(u8 arg0);
void TObjPlayer__sub_80079108(void);
s32 TObjPlayer__sub_80079118(s32 *);
void TObjPlayer__sub_8007911C(void);
void TObjPlayer__sub_80079120(s32);
s32 evaluate_ground_triangles(Vec *origin, u32 mask, CsnGroup **groups);
extern s32 lbl_804389CC[];
extern s32 lbl_80500140[];
s32 *csnVectorUnder(Vec *arg0, u32 *arg1, s32 arg2);
s32 TObjPlayer__sub_80079118(s32 * _w0);
void TObjPlayer__sub_80079120(s32 _w0);
extern u32 lbl_804FFD40[];
extern s32 lbl_804389E8[];
s32 *csnVecterUnder(s32 arg0, s32 arg1);
void *query_wall_radial(Obj_8007A32C *self);
void TObjPlayer__sub_80079124(void *, void *);
u32 TObjPlayer__sub_80079DE0(void *, void *);
f32 vec_squared_length(Vec_800798A0 *);
extern s32 lbl_804389C0[];
s32 intersect_wall_triangle_one_sided(void *, void *, void *, E_80079580 *, u32, s32);
f32 fabs_float(f32);
extern const f32 lbl_805D9204;
s32 select_deepest_wall_ray(Query_80079608 *q, Result_80079608 *r);
void TObjPlayer__sub_80079124(void * _w0, void * _w1);
extern s32 *csn_query_hit_buffer;
s32 query_segment_wall_meshes(void *arg0, void *arg1, u32 arg2, Node_8007970C **list);
s32 check_line_hits_walls__10TObjPlayerFPvPviPv(void *arg0, void *arg1, int arg2, Node_800797DC **list);
f32 vec3_dot(void *, void *);
void vec3_cross(void *, void *, void *);
extern Vec_800798A0 scratch_vec;
extern Vec_800798A0 lbl_8050BF00;
extern Vec_800798A0 lbl_8050BF20;
extern Vec_800798A0 lbl_8050BF40;
extern Vec_800798A0 lbl_8050BF60;
extern s32 csn_query_hit_count;
extern const f32 lbl_805D91F0;
extern const f32 lbl_805D91FC;
extern const f32 lbl_805D9208;
extern const f32 lbl_805D920C;
CsnGroup **get_data_ptr__10TObjMapCsnFv();
M_80079C64 *refill_csn_candidate_cache(P_80079C64 *arg0, M_80079C64 **arg1, u32 arg2);
f32 newton_sqrtf(f32);
void TObjPlayer__sub_80079114(void);
f32 vector_length(void *);
Wall_8007A138 *query_collision_segment_groups(Vec_8007A138 *a, Vec_8007A138 *b, u32 mask);
s32 calc_segment_xz_distance_sq(Vec_8007A138 *c, Vec_8007A138 *o, Vec_8007A138 *e, Vec_8007A138 *d, f32 radius, f32 hsq, f32 inv);

typedef char RecoveredGlobal_800790F0_lbl_804F5800_size[sizeof(RecoveredGlobal_800790F0_lbl_804F5800) == 0x100 ? 1 : -1];
s32 get_csn_group_flags(u8 arg0) {
    return *(u8 *)((s8 *)((u8 *)&__ctype_map.value + arg0) + 0) & 0xC0;
}

void TObjPlayer__sub_80079108(void) {  }
void TObjPlayer__sub_8007910C(CsnContact *contact, NJS_ARGB *color) {  }
void TObjPlayer__sub_80079110(CsnHit *hit) {  }
void TObjPlayer__sub_80079114(void) {  }
s32 TObjPlayer__sub_80079118(s32 * _w0) {  }
void TObjPlayer__sub_8007911C(void) {  }
void TObjPlayer__sub_80079120(s32 _w0) {  }
void TObjPlayer__sub_80079124(void * _w0, void * _w1) {  }

#pragma push
#pragma fp_contract on
s32 calc_segment_xz_distance_sq(Vec_8007A138 *c, Vec_8007A138 *o, Vec_8007A138 *e, Vec_8007A138 *d, f32 radius, f32 hsq, f32 inv) {
    f32 x;
    f32 z;
    f32 cx;
    f32 cz;
    f32 ddx;
    f32 ddz;
    f32 proj;
    f32 dx;
    f32 dz;
    f32 dist;
    cz = c->z;
    cx = c->x;
    x = cx - o->x;
    z = cz - o->z;
    ddz = d->z;
    ddx = d->x;
    proj = ddx * x + ddz * z;
    if (proj > lbl_805D91F0) {
        if (proj >= hsq) {
            dx = e->x - cx;
            dz = e->z - cz;
            dist = dx * dx + dz * dz;
        } else {
            f32 t = proj * inv;
            dz = z - t * ddz;
            dx = x - t * ddx;
            dist = dx * dx + dz * dz;
        }
    } else {
        dist = x * x + z * z;
    }
    return dist <= radius * radius;
}

// Drops a vertical ray from origin through the faces of the listed groups and
// records the nearest ground contact plus one contact per special surface bit.
extern const f32 lbl_805D91F4;
extern const f32 lbl_805D91F8;
extern const f32 lbl_805D9200;
#define GT_DOWN (*(f32 *)&lbl_805D91F8)     /* -10000.0f: ray length downwards */
#define GT_TMAX (*(f32 *)&lbl_805D91F4)     /* 2.0f: no hit yet */
#define GT_EPS_NY (*(f32 *)&lbl_805D91FC)   /* 1e-5f: skip walls (normal y) */
#define GT_EPS_EDGE (*(f32 *)&lbl_805D9200) /* -1e-4f: edge test tolerance */
void vsub(void *, void *, void *);
s32 evaluate_ground_triangles(Vec *origin_arg, u32 mask_arg, CsnGroup **list_arg) {
  CsnVector *origin = (CsnVector *) origin_arg;
  u32 mask = mask_arg;
  u32 m10;
  u32 m4;
  u32 m2;
  f32 ax;
  u32 m8;
  u32 mz;
  s32 i;
  s32 count;
  Vec *verts;
  CsnFace *poly;
  CsnContact *hits;
  CsnModel *mesh;
  CsnVector tmp;
  f32 minT;
  f32 ox;
  f32 oy;
  f32 oz;
  CsnContact *hit;
  s32 *hdr;
  lbl_80500140[0] = 0;
  hdr = lbl_80500140;
  hits = (CsnContact *) lbl_80500140[1];
  lbl_8050BF60.x = origin->x;
  lbl_8050BF60.y = GT_DOWN + origin->y;
  lbl_8050BF60.z = origin->z;
  minT = GT_TMAX;
  vsub(origin, &lbl_8050BF60, &tmp);
  ox = origin->x;
  oy = origin->y;
  oz = origin->z;
  m10 = mask & 0x10;
  m4 = mask & 0x4;
  m2 = mask & 0x2;
  m8 = mask & 0x8;
  mz = mask & (~0x1E);
  for (; (*list_arg) != 0; list_arg++)
  {
    mesh = (*list_arg)->model;
    count = mesh->face_count;
    poly = mesh->faces;
    verts = mesh->vertices;
    for (i = 0; i < count; i++, poly++)
    {
      f32 dx;
      f32 nx;
      f32 ny;
      f32 nz;
      f32 k;
      f32 t;
      f32 ay;
      f32 az;
      f32 bx;
      f32 bz;
      f32 cx;
      f32 cz;
      Vec *a;
      Vec *b;
      Vec *c;
      f32 hy;
      f32 dz;
      if (!(poly->flags & mask))
      {
        continue;
      }
      dx = poly->center.x - ox;
      t = poly->radius * poly->radius;
      dz = (0, poly->center.z - oz);
      if (((dx * dx) + (dz * dz)) > t)
      {
        continue;
      }
      if (poly->normal.y < GT_EPS_NY)
      {
        continue;
      }
      a = &verts[poly->vertex[0]];
      b = &verts[poly->vertex[1]];
      c = &verts[poly->vertex[2]];
      if (((a->y > oy) && (b->y > oy)) && (c->y > oy))
      {
        continue;
      }
      ax = a->x - ox;
      az = a->z - oz;
      bx = b->x - ox;
      bz = b->z - oz;
      if (((az * bx) - (ax * bz)) < GT_EPS_EDGE)
      {
        continue;
      }
      cx = c->x - ox;
      cz = c->z - oz;
      if (((bz * cx) - (bx * cz)) < GT_EPS_EDGE)
      {
        continue;
      }
      if (((cz * ax) - (cx * az)) < GT_EPS_EDGE)
      {
        continue;
      }
      ny = poly->normal.y;
      nx = poly->normal.x;
      nz = poly->normal.z;
      k = GT_DOWN;
      ay = a->y - oy;
      t = (-(((ax * poly->normal.x) + (ay * ny)) + (az * poly->normal.z))) / (k * ny);
      t = -t;
      if (m10 && (poly->flags & 0x10))
      {
        hdr[0] |= 0x10;
        hit = &hits[1];
        hit->point.x = ox;
        hit->point.y = (GT_DOWN * t) + oy;
        hit->point.z = oz;
        hit->normal.x = nx;
        hit->normal.y = ny;
        hit->normal.z = nz;
        hit->flags = poly->flags;
      }
      if (m4 && (poly->flags & 0x4))
      {
        hdr[0] |= 0x4;
        hit = &hits[2];
        hit->point.x = ox;
        hit->point.y = (GT_DOWN * t) + oy;
        hit->point.z = oz;
        hit->normal.x = nx;
        hit->normal.y = ny;
        hit->normal.z = nz;
        hit->flags = poly->flags;
      }
      if (m2 && (poly->flags & 0x2))
      {
        hdr[0] |= 0x2;
        hit = &hits[3];
        hit->point.x = ox;
        hit->point.y = (GT_DOWN * t) + oy;
        hit->point.z = oz;
        hit->normal.x = nx;
        hit->normal.y = ny;
        hit->normal.z = nz;
        hit->flags = poly->flags;
      }
      if (m8 && (poly->flags & 0x8))
      {
        hdr[0] |= 0x8;
        hit = &hits[4];
        hit->point.x = ox;
        hit->point.y = (GT_DOWN * t) + oy;
        hit->point.z = oz;
        hit->normal.x = nx;
        hit->normal.y = ny;
        hit->normal.z = nz;
        hit->flags = poly->flags;
      }
      if ((poly->flags & mz) && (t < minT))
      {
        minT = t;
        hdr[0] |= 0x1;
        hit = &hits[0];
        hit->point.x = ox;
        hit->point.y = (GT_DOWN * t) + oy;
        hit->point.z = oz;
        hit->normal.x = nx;
        hit->normal.y = ny;
        hit->normal.z = nz;
        hit->flags = poly->flags;
      }
      TObjPlayer__sub_80079110((CsnHit *) hdr);
      TObjPlayer__sub_8007910C(hit, &debug_color_blue);
    }

  }

  return hdr[0] & 1;
}
}
#undef GT_DOWN
#undef GT_TMAX
#undef GT_EPS_NY
#undef GT_EPS_EDGE
extern s32 csn_query_map_object[];
extern s32 lbl_80438988[];
void *query_prepared_wall_polygons(void *self);
extern s32 lbl_804389A8[];
void vsub(void *, void *, void *);
extern E_80079580 *wall_query_scene_buffer;
extern f32 csn_query_nearest_hit_t;
extern s32 wall_query_hit_result;
extern const f32 lbl_805D91F4;
s32 query_wall_segment(void *arg0, void *arg1, void *arg2, s32 arg3);
CsnGroup *select_ground_query_groups(CsnVector *arg0, u32 arg1);
s32 prepare_wall_query_polygons(void *arg0, f32 r, s32 mask);
#pragma pop

s32 query_wall_segment(void *arg0, void *arg1, void *arg2, s32 arg3) {
    u8 sp8[12];
    s32 r;
    E_80079580 *p = wall_query_scene_buffer;
    vsub(arg0, arg1, sp8);
    r = 0;
    wall_query_hit_result = arg3;
    csn_query_nearest_hit_t = lbl_805D91F4;
    for (; p->f24 != 0; p = (E_80079580 *)((u8 *)p + 0x28)) {
        if (intersect_wall_triangle_one_sided(arg0, sp8, arg2, p, p->f24, 3) != 0) {
            r = 1;
        }
    }
    return r;
}

#pragma push
#pragma fp_contract on

s32 select_deepest_wall_ray(Query_80079608 *q, Result_80079608 *r) {
    Vec_80079608 end;
    s32 i;
    s32 n;
    Vec_80079608 *off;
    Hit_80079608 *hit;
    f32 d;
    i = 0;
    r->hit = 0;
    r->index = -1;
    r->best = lbl_805D9204;
    off = q->offsets;
    hit = r->hits;
    n = q->count;
    for (; i < n; off++, hit++, i++) {
        end.x = q->origin.x + off->x;
        end.y = q->origin.y + off->y;
        end.z = q->origin.z + off->z;
        if (query_wall_segment(&q->origin, &end, q->flags, (s32)hit) != 0) {
            f32 dz = end.z - hit->pos.z;
            f32 dx = end.x - hit->pos.x;
            d = fabs_float(dx * hit->normal.x + dz * hit->normal.z);
            if (r->best < d) {
                r->hit = 1;
                r->best = d;
                r->index = i;
            }
        }
    }
    return r->hit;
}
#pragma pop

s32 query_segment_wall_meshes(void *arg0, void *arg1, u32 arg2, Node_8007970C **list) {
    u8 dir[12];
    Mesh_8007970C *mesh;
    s32 i;
    s32 n;
    u32 flags;
    Poly_8007970C *poly;
    TObjPlayer__sub_80079124(arg0, arg1);
    csn_query_hit_buffer = lbl_80500140;
    csn_query_hit_buffer[0] = 0;
    wall_query_hit_result = csn_query_hit_buffer[1];
    csn_query_nearest_hit_t = lbl_805D91F4;
    vsub(arg0, arg1, dir);
    for (; *list != NULL; list++) {
        mesh = (*list)->mesh;
        i = 0;
        n = mesh->count;
        poly = mesh->polys;
        flags = mesh->flags;
        for (; i < n; i++, poly++) {
            intersect_wall_triangle_one_sided(arg0, dir, (void *)arg2, (E_80079580 *)poly, flags, 0);
        }
    }
    return csn_query_hit_buffer[0];
}

s32 check_line_hits_walls__10TObjPlayerFPvPviPv(void *arg0, void *arg1, int arg2, Node_800797DC **list) {
    u8 dir[12];
    Mesh_800797DC *mesh;
    s32 i;
    s32 n;
    u32 flags;
    Poly_800797DC *poly;
    csn_query_hit_buffer = lbl_80500140;
    csn_query_hit_buffer[0] = 0;
    wall_query_hit_result = csn_query_hit_buffer[1];
    vsub(arg0, arg1, dir);
    for (; *list != NULL; list++) {
        mesh = (*list)->mesh;
        i = 0;
        n = mesh->count;
        poly = mesh->polys;
        flags = mesh->flags;
        for (; i < n; i++, poly++) {
            if (intersect_wall_triangle_one_sided(arg0, dir, (void *)arg2, (E_80079580 *)poly, flags, 1) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

#pragma push
#pragma fp_contract on
#define FACE ((Face_800798A0 *)arg3)
#define ORG ((Vec_800798A0 *)arg0)
#define DIR ((Vec_800798A0 *)arg1)
#define VERTS ((Vec_800798A0 *)arg4)

s32 intersect_wall_triangle_one_sided(void *arg0, void *arg1, void *arg2, E_80079580 *arg3, u32 arg4, s32 arg5) {
    Vec_800798A0 n;
    Vec_800798A0 *v;
    Vec_800798A0 *v1;
    f32 denom;
    f32 t;

    if ((FACE->flags & (u32)arg2) == 0) {
        return 0;
    }
    n.x = FACE->n.x;
    n.y = FACE->n.y;
    n.z = FACE->n.z;
    denom = vec3_dot(DIR, &n);
    if (denom >= lbl_805D9208) {
        return 0;
    }
    v = &VERTS[FACE->idx[0]];
    scratch_vec.x = ORG->x - v->x;
    scratch_vec.y = ORG->y - v->y;
    scratch_vec.z = ORG->z - v->z;
    t = vec3_dot(&scratch_vec, &n);
    if (t <= lbl_805D91FC) {
        return 0;
    }
    t = -(t / denom);
    if (t > lbl_805D920C || t < lbl_805D91F0) {
        return 0;
    }
    lbl_8050BF60.x = DIR->x * t + ORG->x;
    lbl_8050BF60.y = DIR->y * t + ORG->y;
    lbl_8050BF60.z = DIR->z * t + ORG->z;
    v1 = &VERTS[FACE->idx[1]];
    vsub(&lbl_8050BF60, v, &scratch_vec);
    vsub(&lbl_8050BF60, v1, &lbl_8050BF00);
    vec3_cross(&scratch_vec, &lbl_8050BF00, &lbl_8050BF40);
    if (vec3_dot(&lbl_8050BF40, &n) < lbl_805D91F0) {
        return 0;
    }
    vsub(&lbl_8050BF60, &VERTS[FACE->idx[2]], &lbl_8050BF20);
    vec3_cross(&lbl_8050BF00, &lbl_8050BF20, &lbl_8050BF40);
    if (vec3_dot(&lbl_8050BF40, &n) < lbl_805D91F0) {
        return 0;
    }
    vec3_cross(&lbl_8050BF20, &scratch_vec, &lbl_8050BF40);
    if (vec3_dot(&lbl_8050BF40, &n) < lbl_805D91F0) {
        return 0;
    }
    switch (arg5) {
    case 0:
        if (t < csn_query_nearest_hit_t) {
            csn_query_nearest_hit_t = t;
            *csn_query_hit_buffer = 1;
            VecCopy((Vec *)wall_query_hit_result, (const Vec *)&lbl_8050BF60);
            VecCopy((Vec *)(wall_query_hit_result + 0xC), (const Vec *)&n);
            *(u32 *)((s8 *)wall_query_hit_result + 0x18) = FACE->flags;
        }
        break;
    case 1:
        *csn_query_hit_buffer = 1;
        VecCopy((Vec *)wall_query_hit_result, (const Vec *)&lbl_8050BF60);
        VecCopy((Vec *)(wall_query_hit_result + 0xC), (const Vec *)&n);
        *(u32 *)((s8 *)wall_query_hit_result + 0x18) = FACE->flags;
        break;
    case 2:
        if (csn_query_hit_count >= 0x20) {
            return 0;
        }
        *csn_query_hit_buffer = 1;
        VecCopy((Vec *)wall_query_hit_result, (const Vec *)&lbl_8050BF60);
        VecCopy((Vec *)(wall_query_hit_result + 0xC), (const Vec *)&n);
        *(u32 *)((s8 *)wall_query_hit_result + 0x18) = FACE->flags;
        wall_query_hit_result += 0x1C;
        csn_query_hit_count++;
        break;
    case 3:
        if (t < csn_query_nearest_hit_t) {
            csn_query_nearest_hit_t = t;
            VecCopy((Vec *)wall_query_hit_result, (const Vec *)&lbl_8050BF60);
            VecCopy((Vec *)(wall_query_hit_result + 0xC), (const Vec *)&n);
            *(u32 *)((s8 *)wall_query_hit_result + 0x18) = FACE->flags;
        }
        break;
    }
    return 1;
}
#pragma pop
#undef FACE
#undef ORG
#undef DIR
#undef VERTS

#pragma fp_contract on

#pragma push
#pragma fp_contract on
M_80079C64 *refill_csn_candidate_cache(P_80079C64 *arg0, M_80079C64 **arg1, u32 arg2) {
    f32 rr;
    f32 dz;
    f32 dx;
    s32 n = 0;
    M_80079C64 **it;
    M_80079C64 *m;
    M_80079C64 **first;
    TObjMapCsn::get_map_count();
    it = (M_80079C64 **)get_data_ptr__10TObjMapCsnFv();
    first = arg1;
    while ((m = *it++) != 0) {
        if ((m->flags & arg2) && !(m->flags & 0x40000000)) {
            dz = m->z - arg0->z;
            dx = m->x - arg0->x;
            rr = m->rad;
            rr *= rr;
            if (dx * dx + dz * dz <= rr) {
                n++;
                if (n >= 0xF) {
                    break;
                }
                *arg1++ = m;
            }
        }
    }
    *arg1 = 0;
    return *first;
}
#pragma pop

CsnGroup *select_ground_query_groups(CsnVector *origin, u32 mask) {
  f32 dx;
  f32 dz;
  f32 r;
  int capacityReached;
  s32 count = 0;
  CsnGroup **input;
  CsnGroup *group;
  float zSquared;
  CsnGroup **output;
  float zDelta;
  TObjMapCsn::get_map_count();
  input = get_data_ptr__10TObjMapCsnFv();
  output = ((CsnGroup * *)&lbl_804FFD40);
  while ((group = *(input++)) != 0)
  {
    if (group->flags & mask)
    {
      zDelta = group->center.z - origin->z;
      dz = zDelta;
      r = group->radius;
      r = r * r;
      dx = group->center.x - origin->x;
      zSquared = dz * dz;
      if (((dx * dx) + zSquared) <= r)
      {
        count++;
        capacityReached = count >= 0x100;
        if (capacityReached)
        {
          break;
        }
        *(output++) = group;
      }
    }
  }
  *output = 0;
  return ((CsnGroup * *)&lbl_804FFD40)[0];
}

u32 TObjPlayer__sub_80079DE0(void *a, void *b) {
    Vec_8007A138 d;
    s32 n;
    Wall_8007A138 *w;
    Wall_8007A138 **src;
    Wall_8007A138 **dst;
    f32 len;
    f32 lenSq;
    f32 inv;
    f32 r;
    f32 dsq;
    n = 0;
    TObjMapCsn::get_map_count();
    src = (Wall_8007A138 **)get_data_ptr__10TObjMapCsnFv();
    dst = (Wall_8007A138 **)lbl_804FFD40;
    vsub(a, b, &d);
    lenSq = d.x * d.x + d.z * d.z;
    if (lbl_805D91F0 == lenSq) {
        lenSq = lbl_805D91FC;
    }
    inv = lbl_805D920C / lenSq;
    len = newton_sqrtf(lenSq);
    while ((w = *src++) != NULL) {
        if (w->flags & 0x8000) {
            vsub(a, &w->pos, &scratch_vec);
            dsq = vec_squared_length(&scratch_vec);
            r = len + w->radius;
            r *= r;
            if (dsq <= r) {
                if (calc_segment_xz_distance_sq(&w->pos, (Vec_8007A138 *)a, (Vec_8007A138 *)b, &d, w->radius, lenSq, inv) != 0) {
                    if (++n >= 0x100) {
                        break;
                    }
                    *dst++ = w;
                }
            }
        }
    }
    *dst = NULL;
    ((void (*)(void *))TObjPlayer__sub_80079114)(lbl_804FFD40);
    return lbl_804FFD40[0];
}

#pragma push
#pragma fp_contract on
s32 prepare_wall_query_polygons(void *arg0, f32 r, s32 mask) {
    V_80079F58 *pos = (V_80079F58 *)arg0;
    Grp_80079F58 **lp;
    s32 i;
    s32 count;
    s32 cnt;
    Poly_80079F58 *poly;
    Mesh_80079F58 *mesh;
    Out_80079F58 *out;
    Grp_80079F58 **src;
    Grp_80079F58 *g;
    s32 n;
    Grp_80079F58 **dst;
    TObjMapCsn::get_map_count();
    src = (Grp_80079F58 **)get_data_ptr__10TObjMapCsnFv();
    if (src == NULL) {
        return 0;
    }
    n = 0;
    dst = (Grp_80079F58 **)lbl_804FFD40;
    while ((g = *src++) != NULL) {
        if (g->flags & mask) {
            f32 b;
            f32 dz = g->z - pos->z;
            f32 dx = g->x - pos->x;
            b = r + g->radius;
            b *= b;
            if (dx * dx + dz * dz <= b) {
                if (++n >= 0x100) {
                    break;
                }
                *dst++ = g;
            }
        }
    }
    *dst = NULL;
    src = (Grp_80079F58 **)lbl_804FFD40;
    out = (Out_80079F58 *)wall_query_scene_buffer;
    cnt = 0;
    while ((g = *src++) != NULL) {
        mesh = g->mesh;
        count = mesh->count;
        poly = mesh->polys;
        for (i = 0; i < count; poly++, i++) {
            f32 dz = poly->z - pos->z;
            f32 dx = poly->x - pos->x;
            f32 b = r + poly->radius;
            b *= b;
            if (dx * dx + dz * dz <= b) {
                if (++cnt >= 0x200) {
                    break;
                }
                ((TObjPlayer *)out)->copy_wall_polygon((u8 *)poly);
                out->id = mesh->id;
                out++;
            }
        }
    }
    out->id = 0;
    return cnt;
}
#pragma pop

void TObjPlayer::copy_wall_polygon(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0) = (s32) *(s32 *)((s8 *)arg1 + 0);
    this->m_flags = (u16) *(u16 *)((s8 *)arg1 + 4);
    this->m_id = (u16) *(u16 *)((s8 *)arg1 + 6);
    *(ByteBlock_C *)((s32) (u8 *)&this->m_prev) = *(const ByteBlock_C *)((s32) arg1 + 8);
    *(ByteBlock_C *)((s32) (u8 *)&this->m_down) = *(const ByteBlock_C *)((s32) arg1 + 0x14);
    *(f32 *)&this->m_20 = (f32) *(f32 *)((s8 *)arg1 + 0x20);
}

Wall_8007A138 *query_collision_segment_groups(Vec_8007A138 *a, Vec_8007A138 *b, u32 mask) {
    Vec_8007A138 d;
    s32 n;
    Wall_8007A138 *w;
    Wall_8007A138 **src;
    Wall_8007A138 **dst;
    f32 len;
    f32 lenSq;
    f32 inv;
    f32 r;
    f32 dsq;
    n = 0;
    TObjMapCsn::get_map_count();
    src = (Wall_8007A138 **)get_data_ptr__10TObjMapCsnFv();
    dst = (Wall_8007A138 **)lbl_804FFD40;
    vsub(a, b, &d);
    len = vector_length(&d);
    lenSq = d.x * d.x + d.z * d.z;
    if (lbl_805D91F0 == lenSq) {
        lenSq = lbl_805D91FC;
    }
    inv = lbl_805D920C / lenSq;
    newton_sqrtf(lenSq);
    while ((w = *src++) != NULL) {
        if (w->flags & mask) {
            (*(Vec_8007A138 *)&scratch_vec).x = w->pos.x - a->x;
            (*(Vec_8007A138 *)&scratch_vec).z = w->pos.z - a->z;
            dsq = (*(Vec_8007A138 *)&scratch_vec).x * (*(Vec_8007A138 *)&scratch_vec).x + (*(Vec_8007A138 *)&scratch_vec).z * (*(Vec_8007A138 *)&scratch_vec).z;
            r = len + w->radius;
            r *= r;
            if (dsq <= r) {
                if (calc_segment_xz_distance_sq((Vec_8007A138 *)(&w->pos), (Vec_8007A138 *)(a), (Vec_8007A138 *)(b), (Vec_8007A138 *)(&d), w->radius, lenSq, inv) != 0) {
                    if (++n >= 0x100) {
                        break;
                    }
                    *dst++ = w;
                }
            }
        }
    }
    *dst = NULL;
    ((void (*)(void *))TObjPlayer__sub_80079114)(lbl_804FFD40);
    return (Wall_8007A138 *)lbl_804FFD40[0];
}

void *query_prepared_wall_polygons(void *self) {
    void *r;
    TObjPlayer__sub_8007911C();
    r = csn_query_map_object;
    if (select_deepest_wall_ray((Query_80079608 *)(self), (Result_80079608 *)(r)) == 0) {
        r = 0;
    }
    TObjPlayer__sub_80079118(lbl_80438988);
    return r;
}

void *query_wall_radial(Obj_8007A32C *self) {
    void *r;
    TObjPlayer__sub_8007911C();
    r = csn_query_map_object;
    if (prepare_wall_query_polygons(self->fc, self->f4, self->f8) == 0) {
        r = 0;
    } else if (select_deepest_wall_ray((Query_80079608 *)(self), (Result_80079608 *)(r)) == 0) {
        r = 0;
    }
    TObjPlayer__sub_80079118(lbl_804389A8);
    return r;
}

CsnHit *csnLookAt(const Vec *from, const Vec *to) {
    CsnHit *hit;
    TObjPlayer__sub_8007911C();
    hit = (CsnHit *)lbl_80500140;
    TObjPlayer__sub_80079124((void *)from, (void *)to);
    if (TObjPlayer__sub_80079DE0((void *)from, (void *)to) == 0U) {
        hit = NULL;
    } else if (check_line_hits_walls__10TObjPlayerFPvPviPv((void *)from, (void *)to, 0x8000, (Node_800797DC **)((void *) (((s32 *)&lbl_804FFD40)))) == 0) {
        hit = NULL;
    }
    TObjPlayer__sub_80079118(lbl_804389C0);
    return hit;
}

s32 *csnVectorUnder(Vec *arg0, u32 *arg1, s32 arg2) {
    s32 *var_r31;
    TObjPlayer__sub_80079108();
    TObjPlayer__sub_8007911C();
    TObjPlayer__sub_80079120((s32)arg0);
    var_r31 = lbl_80500140;
    if ((u32) *arg1 == 0U) {
        if (((u32)refill_csn_candidate_cache((P_80079C64 *)(arg0), (M_80079C64 **)(arg1), arg2)) == 0U) {
            var_r31 = NULL;
        } else if (evaluate_ground_triangles(arg0, arg2, (CsnGroup **)arg1) == 0) {
            var_r31 = NULL;
        }
    } else {
        if (evaluate_ground_triangles(arg0, arg2, (CsnGroup **)arg1) != 0) {
            goto done;
        }
        if (((u32)refill_csn_candidate_cache((P_80079C64 *)(arg0), (M_80079C64 **)(arg1), arg2)) == 0U) {
            var_r31 = NULL;
        } else if (evaluate_ground_triangles(arg0, arg2, (CsnGroup **)arg1) == 0) {
            var_r31 = NULL;
        }
    }
done:
    TObjPlayer__sub_80079118(lbl_804389CC);
    return var_r31;
}
s32 *csnVecterUnder(s32 origin, s32 mask) {
    s32 *var_r31;
    TObjPlayer__sub_80079108();
    TObjPlayer__sub_8007911C();
    TObjPlayer__sub_80079120(origin);
    var_r31 = ((s32 *)&lbl_80500140);
    if (((u32)select_ground_query_groups((CsnVector *)(origin), mask)) == 0U) {
        var_r31 = 0;
    } else if (evaluate_ground_triangles((Vec *)origin, mask, (CsnGroup **)lbl_804FFD40) == 0) {
        var_r31 = 0;
    }
    TObjPlayer__sub_80079118(lbl_804389E8);
    return var_r31;
}

extern "C" {
void *mem_alloc(u32 size);
void mem_free(void *p);
extern s32 lbl_804389FC[];
}

CsnHit *csnVector(const Vec *from, const Vec *to, u32 mask) {
    CsnHit *hit;
    TObjPlayer__sub_8007911C();
    hit = (CsnHit *)lbl_80500140;
    if (query_collision_segment_groups((Vec_8007A138 *)from, (Vec_8007A138 *)to, mask) == NULL) {
        hit = NULL;
    } else if (query_segment_wall_meshes((void *)from, (void *)to, mask, (Node_8007970C **)lbl_804FFD40) == 0) {
        hit = NULL;
    }
    TObjPlayer__sub_80079118(lbl_804389FC);
    return hit;
}

void TObjButterflyLobby::free_singleton_805D4E6C() {
    if (wall_query_scene_buffer != NULL) {
        mem_free(wall_query_scene_buffer);
        wall_query_scene_buffer = NULL;
    }
}

void TObjButterflyLobby::alloc_scene_buffer() { wall_query_scene_buffer = (E_80079580 *)mem_alloc(0x5000); }

extern "C" {
void __construct_array(void *, void *, s32, s32, s32);
u8 lbl_804FF9C0[0x380];
u32 lbl_804FFD40[0x100];
__declspec(section ".data") s32 lbl_80500140[2];
s32 csn_query_map_object[4];

void __sinit_CsnQuery_cpp(void) {
    __construct_array(lbl_804FF9C0, (void *)TObjPlayer__sub_8007A7B8, 0, 0x1C, 0x20);
    TObjMapCsn::init_and_return((s32)lbl_80500140);
    ((TObjMapCsn *)csn_query_map_object)->init();
}

}

__declspec(section ".ctors") static void *const __sinit_CsnQuery_cpp_ref = (void *)__sinit_CsnQuery_cpp;
