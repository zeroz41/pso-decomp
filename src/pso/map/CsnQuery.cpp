#include "libc/ctype.h"
#include "types.h"
#include "pso/system/vector.h"
#include "pso/map/CsnQuery.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/map/TMapCsnCtrl.h"
#include "pso/object/lobby/TObjButterflyLobby.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_8007A7B8.h"
#include "pso/unk/text_8007A7A0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_C { u8 bytes[0xc]; };

struct E_80079580 { u8 pad[0x24]; u32 f24; };

struct Hit_80079608 {
    Vec pos;
    Vec normal;
    u8 pad18[4];
};

struct Query_80079608 {
    s32 count;
    u8 pad4[4];
    void *flags;
    Vec origin;
    Vec *offsets;
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

struct Face_800798A0 {
    u16 idx[3];
    u16 flags;
    Vec n;
};


struct E_80079580;

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

CsnGroup **scene_collision_data;
E_80079580 *wall_query_scene_buffer;
s32 csn_query_hit_count;
f32 csn_query_nearest_hit_t;
s32 *csn_query_hit_buffer;
saddr wall_query_hit_result;
extern "C" {
s32 get_csn_group_flags(u8 arg0);
void TObjPlayer__sub_80079108(void);
s32 TObjPlayer__sub_80079118(const char *);
void TObjPlayer__sub_8007911C(void);
void TObjPlayer__sub_80079120(saddr);
}
s32 evaluate_ground_triangles(Vec *origin, u32 mask, CsnGroup **groups);
extern s32 lbl_80500140[];
extern "C" {
void TObjPlayer__sub_80079120(saddr _w0);
extern CsnGroup *csn_query_groups[];
s32 *csnVecterUnder(saddr arg0, s32 arg1);
void TObjPlayer__sub_80079124(void *, void *);
CsnGroup *TObjPlayer__sub_80079DE0(void *, void *);
f32 vec_squared_length(Vec *);
s32 intersect_wall_triangle_one_sided(void *, void *, void *, E_80079580 *, u32, s32);
s32 select_deepest_wall_ray(Query_80079608 *q, Result_80079608 *r);
void TObjPlayer__sub_80079124(void * _w0, void * _w1);
s32 query_segment_wall_meshes(void *arg0, void *arg1, uaddr arg2, Node_8007970C **list);
s32 check_line_hits_walls__10TObjPlayerFPvPviPv(void *arg0, void *arg1, saddr arg2, Node_800797DC **list);
f32 vec3_dot(void *, void *);
void vec3_cross(void *, void *, void *);
extern Vec scratch_vec;
extern Vec lbl_8050BF00;
extern Vec lbl_8050BF20;
extern Vec lbl_8050BF40;
extern Vec lbl_8050BF60;
f32 vector_length(void *);
CsnGroup *query_collision_segment_groups(Vec *a, Vec *b, u32 mask);
s32 calc_segment_xz_distance_sq(Vec *c, Vec *o, Vec *e, Vec *d, f32 radius, f32 hsq, f32 inv);

s32 get_csn_group_flags(u8 arg0) {
    return __ctype_map[arg0] & __letter;
}

void TObjPlayer__sub_80079108(void) {  }
void TObjPlayer__sub_8007910C(CsnContact *contact, NJS_ARGB *color) {  }
void TObjPlayer__sub_80079110(CsnHit *hit) {  }
void TObjPlayer__sub_80079114(CsnGroup *const *groups) {  }
// inferred: name - every caller passes its own function name ("csnLookAt()", ...)
s32 TObjPlayer__sub_80079118(const char *name) {  }
void TObjPlayer__sub_8007911C(void) {  }
void TObjPlayer__sub_80079120(saddr _w0) {  }
void TObjPlayer__sub_80079124(void * _w0, void * _w1) {  }

#pragma push
#pragma fp_contract on
s32 calc_segment_xz_distance_sq(Vec *c, Vec *o, Vec *e, Vec *d, f32 radius, f32 hsq, f32 inv) {
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
    if (proj > 0.0f) {
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
#define GT_DOWN (-10000.0f)  /* ray length downwards */
#define GT_TMAX (2.0f)       /* no hit yet */
#define GT_EPS_NY (1e-5f)    /* skip walls (normal y) */
#define GT_EPS_EDGE (-1e-4f) /* edge test tolerance */
}
s32 evaluate_ground_triangles(Vec *origin_arg, u32 mask_arg, CsnGroup **list_arg) {
  Vec *origin = origin_arg;
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
  Vec tmp;
  f32 minT;
  f32 ox;
  f32 oy;
  f32 oz;
  CsnContact *hit;
  s32 *hdr;
  lbl_80500140[0] = 0;
  hdr = lbl_80500140;
  hits = (CsnContact *) lbl_80500140[1];
  minT = GT_TMAX;
  lbl_8050BF60.x = origin->x;
  lbl_8050BF60.y = GT_DOWN + origin->y;
  lbl_8050BF60.z = origin->z;
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
#undef GT_DOWN
#undef GT_TMAX
#undef GT_EPS_NY
#undef GT_EPS_EDGE
extern s32 csn_query_map_object[];
void *query_prepared_wall_polygons(void *self);
s32 query_wall_segment(void *arg0, void *arg1, void *arg2, saddr arg3);
s32 prepare_wall_query_polygons(void *arg0, f32 r, s32 mask);
#pragma pop

s32 query_wall_segment(void *arg0, void *arg1, void *arg2, s32 arg3) {
    u8 sp8[12];
    s32 r;
    E_80079580 *p = wall_query_scene_buffer;
    vsub(arg0, arg1, sp8);
    r = 0;
    wall_query_hit_result = arg3;
    csn_query_nearest_hit_t = 2.0f;
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
    Vec end;
    s32 i;
    s32 n;
    Vec *off;
    Hit_80079608 *hit;
    f32 d;
    i = 0;
    r->hit = 0;
    r->index = -1;
    r->best = -1.0f;
    off = q->offsets;
    hit = r->hits;
    n = q->count;
    for (; i < n; off++, hit++, i++) {
        end.x = q->origin.x + off->x;
        end.y = q->origin.y + off->y;
        end.z = q->origin.z + off->z;
        if (query_wall_segment(&q->origin, &end, q->flags, (saddr)hit) != 0) {
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

s32 query_segment_wall_meshes(void *arg0, void *arg1, uaddr arg2, Node_8007970C **list) {
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
    csn_query_nearest_hit_t = 2.0f;
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

s32 check_line_hits_walls__10TObjPlayerFPvPviPv(void *arg0, void *arg1, saddr arg2, Node_800797DC **list) {
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
#define ORG ((Vec *)arg0)
#define DIR ((Vec *)arg1)
#define VERTS ((Vec *)arg4)

s32 intersect_wall_triangle_one_sided(void *arg0, void *arg1, void *arg2, E_80079580 *arg3, u32 arg4, s32 arg5) {
    Vec n;
    Vec *v;
    Vec *v1;
    f32 denom;
    f32 t;

    if ((FACE->flags & (uaddr)arg2) == 0) {
        return 0;
    }
    n.x = FACE->n.x;
    n.y = FACE->n.y;
    n.z = FACE->n.z;
    denom = vec3_dot(DIR, &n);
    if (denom >= -1e-5f) {
        return 0;
    }
    v = &VERTS[FACE->idx[0]];
    scratch_vec.x = ORG->x - v->x;
    scratch_vec.y = ORG->y - v->y;
    scratch_vec.z = ORG->z - v->z;
    t = vec3_dot(&scratch_vec, &n);
    if (t <= 1e-5f) {
        return 0;
    }
    t = -(t / denom);
    if (t > 1.0f || t < 0.0f) {
        return 0;
    }
    lbl_8050BF60.x = DIR->x * t + ORG->x;
    lbl_8050BF60.y = DIR->y * t + ORG->y;
    lbl_8050BF60.z = DIR->z * t + ORG->z;
    v1 = &VERTS[FACE->idx[1]];
    vsub(&lbl_8050BF60, v, &scratch_vec);
    vsub(&lbl_8050BF60, v1, &lbl_8050BF00);
    vec3_cross(&scratch_vec, &lbl_8050BF00, &lbl_8050BF40);
    if (vec3_dot(&lbl_8050BF40, &n) < 0.0f) {
        return 0;
    }
    vsub(&lbl_8050BF60, &VERTS[FACE->idx[2]], &lbl_8050BF20);
    vec3_cross(&lbl_8050BF00, &lbl_8050BF20, &lbl_8050BF40);
    if (vec3_dot(&lbl_8050BF40, &n) < 0.0f) {
        return 0;
    }
    vec3_cross(&lbl_8050BF20, &scratch_vec, &lbl_8050BF40);
    if (vec3_dot(&lbl_8050BF40, &n) < 0.0f) {
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
extern "C" CsnGroup *refill_csn_candidate_cache(Vec *arg0, CsnGroup **arg1, u32 arg2) {
    f32 rr;
    f32 dz;
    f32 dx;
    s32 n = 0;
    CsnGroup **it;
    CsnGroup *m;
    CsnGroup **first;
    it = TObjMapCsn::get_collision_controller()->get_collision_groups();
    first = arg1;
    while ((m = *it++) != 0) {
        if ((m->flags & arg2) && !(m->flags & 0x40000000)) {
            dz = m->center.z - arg0->z;
            dx = m->center.x - arg0->x;
            rr = m->radius;
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

CsnGroup *select_ground_query_groups(const Vec *origin, u32 mask) {
  const volatile Vec *position = origin;
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
  input = TObjMapCsn::get_collision_controller()->get_collision_groups();
  output = csn_query_groups;
  while ((group = *(input++)) != 0)
  {
    if (group->flags & mask)
    {
      const volatile f32 *groupZ = &group->center.z;
      f32 centerZ = *groupZ;
      zDelta = centerZ - position->z;
      dz = zDelta;
      r = group->radius;
      r = r * r;
      dx = group->center.x - position->x;
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
  return csn_query_groups[0];
}

CsnGroup *TObjPlayer__sub_80079DE0(void *a, void *b) {
    Vec d;
    s32 n;
    CsnGroup *w;
    CsnGroup **src;
    CsnGroup **dst;
    f32 len;
    f32 lenSq;
    f32 inv;
    f32 r;
    f32 dsq;
    n = 0;
    src = TObjMapCsn::get_collision_controller()->get_collision_groups();
    dst = csn_query_groups;
    vsub(a, b, &d);
    lenSq = d.x * d.x + d.z * d.z;
    if (0.0f == lenSq) {
        lenSq = 1e-5f;
    }
    inv = 1.0f / lenSq;
    len = newton_sqrtf(lenSq);
    while ((w = *src++) != NULL) {
        if (w->flags & 0x8000) {
            vsub(a, &w->center, &scratch_vec);
            dsq = vec_squared_length(&scratch_vec);
            r = len + w->radius;
            r *= r;
            if (dsq <= r) {
                if (calc_segment_xz_distance_sq(&w->center, (Vec *)a, (Vec *)b, &d, w->radius, lenSq, inv) != 0) {
                    if (++n >= 0x100) {
                        break;
                    }
                    *dst++ = w;
                }
            }
        }
    }
    *dst = NULL;
    TObjPlayer__sub_80079114(csn_query_groups);
    return csn_query_groups[0];
}

#pragma push
#pragma fp_contract on
s32 prepare_wall_query_polygons(void *arg0, f32 r, s32 mask) {
    Vec *pos = (Vec *)arg0;
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
    src = (Grp_80079F58 **)TObjMapCsn::get_collision_controller()->get_collision_groups();
    if (src == NULL) {
        return 0;
    }
    n = 0;
    dst = (Grp_80079F58 **)csn_query_groups;
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
    src = (Grp_80079F58 **)csn_query_groups;
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
    *(ByteBlock_C *)((saddr) (u8 *)&this->m_prev) = *(const ByteBlock_C *)((saddr) arg1 + 8);
    *(ByteBlock_C *)((saddr) (u8 *)&this->m_down) = *(const ByteBlock_C *)((saddr) arg1 + 0x14);
    *(f32 *)&this->m_20 = (f32) *(f32 *)((s8 *)arg1 + 0x20);
}

CsnGroup *query_collision_segment_groups(Vec *a, Vec *b, u32 mask) {
    Vec d;
    s32 n;
    CsnGroup *w;
    CsnGroup **src;
    CsnGroup **dst;
    f32 len;
    f32 lenSq;
    f32 inv;
    f32 r;
    f32 dsq;
    n = 0;
    src = TObjMapCsn::get_collision_controller()->get_collision_groups();
    dst = csn_query_groups;
    vsub(a, b, &d);
    len = vector_length(&d);
    lenSq = d.x * d.x + d.z * d.z;
    if (0.0f == lenSq) {
        lenSq = 1e-5f;
    }
    inv = 1.0f / lenSq;
    newton_sqrtf(lenSq);
    while ((w = *src++) != NULL) {
        if (w->flags & mask) {
            (*(Vec *)&scratch_vec).x = w->center.x - a->x;
            (*(Vec *)&scratch_vec).z = w->center.z - a->z;
            dsq = (*(Vec *)&scratch_vec).x * (*(Vec *)&scratch_vec).x + (*(Vec *)&scratch_vec).z * (*(Vec *)&scratch_vec).z;
            r = len + w->radius;
            r *= r;
            if (dsq <= r) {
                if (calc_segment_xz_distance_sq((Vec *)(&w->center), (Vec *)(a), (Vec *)(b), (Vec *)(&d), w->radius, lenSq, inv) != 0) {
                    if (++n >= 0x100) {
                        break;
                    }
                    *dst++ = w;
                }
            }
        }
    }
    *dst = NULL;
    TObjPlayer__sub_80079114(csn_query_groups);
    return csn_query_groups[0];
}

void *query_prepared_wall_polygons(void *self) {
    void *r;
    TObjPlayer__sub_8007911C();
    r = csn_query_map_object;
    if (select_deepest_wall_ray((Query_80079608 *)(self), (Result_80079608 *)(r)) == 0) {
        r = 0;
    }
    TObjPlayer__sub_80079118("csnCheckPluralVectorPolyBuff()");
    return r;
}

WallRayResult *query_wall_radial(WallRayQuery *query) {
    WallRayResult *r;
    TObjPlayer__sub_8007911C();
    r = (WallRayResult *)csn_query_map_object;
    if (prepare_wall_query_polygons(&query->origin, query->radius, query->mask) == 0) {
        r = 0;
    } else if (select_deepest_wall_ray((Query_80079608 *)(query), (Result_80079608 *)(r)) == 0) {
        r = 0;
    }
    TObjPlayer__sub_80079118("csnCheckPluralVector()");
    return r;
}

CsnHit *csnLookAt(const Vec *from, const Vec *to) {
    CsnHit *hit;
    TObjPlayer__sub_8007911C();
    hit = (CsnHit *)lbl_80500140;
    TObjPlayer__sub_80079124((void *)from, (void *)to);
    if (TObjPlayer__sub_80079DE0((void *)from, (void *)to) == NULL) {
        hit = NULL;
    } else if (check_line_hits_walls__10TObjPlayerFPvPviPv((void *)from, (void *)to, 0x8000, (Node_800797DC **)csn_query_groups) == 0) {
        hit = NULL;
    }
    TObjPlayer__sub_80079118("csnLookAt()");
    return hit;
}

CsnHit *csnVectorUnder(Vec *origin, CsnGroup **cached_groups, u32 mask) {
    CsnHit *hit;
    TObjPlayer__sub_80079108();
    TObjPlayer__sub_8007911C();
    TObjPlayer__sub_80079120((saddr)origin);
    hit = (CsnHit *)lbl_80500140;
    if (*cached_groups == NULL) {
        if (refill_csn_candidate_cache(origin, cached_groups, mask) == NULL) {
            hit = NULL;
        } else if (evaluate_ground_triangles(origin, mask, cached_groups) == 0) {
            hit = NULL;
        }
    } else {
        if (evaluate_ground_triangles(origin, mask, cached_groups) != 0) {
            goto done;
        }
        if (refill_csn_candidate_cache(origin, cached_groups, mask) == NULL) {
            hit = NULL;
        } else if (evaluate_ground_triangles(origin, mask, cached_groups) == 0) {
            hit = NULL;
        }
    }
done:
    TObjPlayer__sub_80079118("csnVectorUnder(Use Buffer)");
    return hit;
}
s32 *csnVecterUnder(saddr origin, s32 mask) {
    s32 *var_r31;
    TObjPlayer__sub_80079108();
    TObjPlayer__sub_8007911C();
    TObjPlayer__sub_80079120(origin);
    var_r31 = ((s32 *)&lbl_80500140);
    if (((uaddr)select_ground_query_groups((const Vec *)origin, mask)) == 0U) {
        var_r31 = 0;
    } else if (evaluate_ground_triangles((Vec *)origin, mask, csn_query_groups) == 0) {
        var_r31 = 0;
    }
    TObjPlayer__sub_80079118("csnVecterUnder()");
    return var_r31;
}


CsnHit *csnVector(const Vec *from, const Vec *to, u32 mask) {
    CsnHit *hit;
    TObjPlayer__sub_8007911C();
    hit = (CsnHit *)lbl_80500140;
    if (query_collision_segment_groups((Vec *)from, (Vec *)to, mask) == NULL) {
        hit = NULL;
    } else if (query_segment_wall_meshes((void *)from, (void *)to, mask, (Node_8007970C **)csn_query_groups) == 0) {
        hit = NULL;
    }
    TObjPlayer__sub_80079118("csnVector()");
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
}
u8 lbl_804FF9C0[0x380];
CsnGroup *csn_query_groups[0x100];
__declspec(section ".data") s32 lbl_80500140[2];
s32 csn_query_map_object[4];
extern "C" {

void __sinit_CsnQuery_cpp(void) {
    __construct_array(lbl_804FF9C0, (void *)TObjPlayer__sub_8007A7B8, 0, 0x1C, 0x20);
    TObjMapCsn::init_and_return((saddr)lbl_80500140);
    ((TObjMapCsn *)csn_query_map_object)->init();
}

}

__declspec(section ".ctors") static void *const __sinit_CsnQuery_cpp_ref = (void *)__sinit_CsnQuery_cpp;


CsnGroup **TMapCsnCtrl::get_collision_groups() { return groups; }

extern TMapCsnCtrl *map_csn_ctrl_instance;

TMapCsnCtrl *TObjMapCsn::get_collision_controller() {
    return map_csn_ctrl_instance;
}
void*TObjMapCsn::init() { TObjMapCsn::init_and_return((saddr)this); *(int *)&this->m_prev = -1; *(float *)&this->m_next = -1.0f; return this; }
saddr TObjMapCsn::init_and_return(saddr arg0) {
    fn_8007A7A0((u8 *)arg0);
    return arg0;
}


void fn_8007A7A0(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0) = 0;
    *(u8 **)((s8 *)arg0 + 4) = lbl_804FF9C0;
}


s32 TObjPlayer__sub_8007A7B8(saddr arg0) {
    ((TObjPlayer *)arg0)->clear_velocity_vectors();
    return arg0;
}


void TObjPlayer::clear_velocity_vectors() { *(float*)((char*)this + 0x8) = 0.0f; *(float*)((char*)this + 0x4) = 0.0f; *(float*)((char*)this + 0x0) = 0.0f; *(float*)((char*)this + 0x14) = 0.0f; *(float*)((char*)this + 0x10) = 0.0f; *(float*)((char*)this + 0xc) = 0.0f; *(int*)((char*)this + 0x18) = 0; }
