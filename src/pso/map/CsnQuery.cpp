#include "pso/system/memory.h"
#include "libc/ctype.h"
#include "types.h"
#include "pso/system/vector.h"
#include "pso/map/CsnQuery.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/map/TMapCsnCtrl.h"
#include "pso/object/lobby/TObjButterflyLobby.h"
#include "pso/render/render_util.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/ScratchVectors.h"
#include "pso/render/DebugFont.h"

#pragma inline_depth(1)
#pragma dont_inline off

LAYOUT_ASSERT(WallPolygonSize, sizeof(WallPolygon) == 0x28);

CsnGroup **scene_collision_data;
WallPolygon *wall_query_scene_buffer;
s32 csn_query_hit_count;
f32 csn_query_nearest_hit_t;
CsnHit *csn_query_hit_buffer;
CsnContact *wall_query_hit_result;
CsnContact csn_query_contacts[0x20];
CsnGroup *csn_query_groups[0x100];
__declspec(section ".data") CsnHit csn_hit_storage;
WallRayResult csn_query_map_object;
extern Vec scratch_vec3;
extern Vec scratch_vec4;
extern Vec scratch_vec5;
extern "C" {

s32 get_csn_group_flags(u8 ch) {
    return __ctype_map[ch] & __letter;
}
}

void csn_debug_hook_under_query(void) {  }
void csn_debug_hook_contact_color(CsnContact *contact, NJS_ARGB *color) {  }
void csn_debug_hook_hit_record(CsnHit *hit) {  }
void csn_debug_hook_group_list(CsnGroup *const *groups) {  }
// name is the calling query's own name, such as "csnLookAt()".
void csn_debug_hook_query_name(const char *name) {  }
void csn_debug_hook_query_begin(void) {  }
void csn_debug_hook_origin_vector(const Vec *) {  }
void csn_debug_hook_segment(const Vec *, const Vec *) {  }

#pragma push
#pragma fp_contract on
s32 calc_segment_xz_distance_sq(const Vec *c, const Vec *o, const Vec *e, const Vec *d, f32 radius, f32 hsq, f32 inv) {
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
  CsnHit *hdr;
  csn_hit_storage.hit_mask = 0;
  hdr = &csn_hit_storage;
  hits = csn_hit_storage.contact;
  minT = GT_TMAX;
  scratch_vec5.x = origin->x;
  scratch_vec5.y = GT_DOWN + origin->y;
  scratch_vec5.z = origin->z;
  vsub(origin, &scratch_vec5, &tmp);
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
        hdr->hit_mask |= 0x10;
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
        hdr->hit_mask |= 0x4;
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
        hdr->hit_mask |= 0x2;
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
        hdr->hit_mask |= 0x8;
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
        hdr->hit_mask |= 0x1;
        hit = &hits[0];
        hit->point.x = ox;
        hit->point.y = (GT_DOWN * t) + oy;
        hit->point.z = oz;
        hit->normal.x = nx;
        hit->normal.y = ny;
        hit->normal.z = nz;
        hit->flags = poly->flags;
      }
      csn_debug_hook_hit_record(hdr);
      csn_debug_hook_contact_color(hit, &debug_color_blue);
    }

  }

  return hdr->hit_mask & 1;
}
#undef GT_DOWN
#undef GT_TMAX
#undef GT_EPS_NY
#undef GT_EPS_EDGE
#pragma pop

s32 query_wall_segment(Vec *from, Vec *to, u32 mask, CsnContact *hit) {
    Vec dir;
    s32 r;
    WallPolygon *p = wall_query_scene_buffer;
    vsub(from, to, &dir);
    r = 0;
    wall_query_hit_result = hit;
    csn_query_nearest_hit_t = 2.0f;
    for (; p->vertices != NULL; p++) {
        if (intersect_wall_triangle_one_sided(from, &dir, mask, &p->face, p->vertices, 3) != 0) {
            r = 1;
        }
    }
    return r;
}

#pragma push
#pragma fp_contract on

s32 select_deepest_wall_ray(WallRayQuery *q, WallRayResult *r) {
    Vec end;
    s32 i;
    s32 n;
    Vec *off;
    CsnContact *hit;
    f32 d;
    i = 0;
    r->header.hit_mask = 0;
    r->index = -1;
    r->depth = -1.0f;
    off = q->rays;
    hit = r->header.contact;
    n = q->count;
    for (; i < n; off++, hit++, i++) {
        end.x = q->origin.x + off->x;
        end.y = q->origin.y + off->y;
        end.z = q->origin.z + off->z;
        if (query_wall_segment(&q->origin, &end, q->mask, hit) != 0) {
            f32 dz = end.z - hit->point.z;
            f32 dx = end.x - hit->point.x;
            d = fabs_float(dx * hit->normal.x + dz * hit->normal.z);
            if (r->depth < d) {
                r->header.hit_mask = 1;
                r->depth = d;
                r->index = i;
            }
        }
    }
    return r->header.hit_mask;
}
#pragma pop

s32 query_segment_wall_meshes(Vec *from, Vec *to, u32 mask, CsnGroup **groups) {
    Vec dir;
    CsnModel *model;
    s32 i;
    s32 n;
    Vec *vertices;
    CsnFace *face;
    csn_debug_hook_segment(from, to);
    csn_query_hit_buffer = &csn_hit_storage;
    csn_query_hit_buffer->hit_mask = 0;
    wall_query_hit_result = csn_query_hit_buffer->contact;
    csn_query_nearest_hit_t = 2.0f;
    vsub(from, to, &dir);
    for (; *groups != NULL; groups++) {
        model = (*groups)->model;
        i = 0;
        n = model->face_count;
        face = model->faces;
        vertices = model->vertices;
        for (; i < n; i++, face++) {
            intersect_wall_triangle_one_sided(from, &dir, mask, face, vertices, 0);
        }
    }
    return csn_query_hit_buffer->hit_mask;
}

s32 check_line_hits_walls(Vec *from, Vec *to, u32 mask, CsnGroup **groups) {
    Vec dir;
    CsnModel *model;
    s32 i;
    s32 n;
    Vec *vertices;
    CsnFace *face;
    csn_query_hit_buffer = &csn_hit_storage;
    csn_query_hit_buffer->hit_mask = 0;
    wall_query_hit_result = csn_query_hit_buffer->contact;
    vsub(from, to, &dir);
    for (; *groups != NULL; groups++) {
        model = (*groups)->model;
        i = 0;
        n = model->face_count;
        face = model->faces;
        vertices = model->vertices;
        for (; i < n; i++, face++) {
            if (intersect_wall_triangle_one_sided(from, &dir, mask, face, vertices, 1) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

#pragma push
#pragma fp_contract on

s32 intersect_wall_triangle_one_sided(Vec *origin, Vec *dir, u32 mask, CsnFace *face, Vec *vertices, s32 mode) {
    Vec n;
    Vec *v;
    Vec *v1;
    f32 denom;
    f32 t;

    if ((face->flags & mask) == 0) {
        return 0;
    }
    n.x = face->normal.x;
    n.y = face->normal.y;
    n.z = face->normal.z;
    denom = vec3_dot(dir, &n);
    if (denom >= -1e-5f) {
        return 0;
    }
    v = &vertices[face->vertex[0]];
    scratch_vec.x = origin->x - v->x;
    scratch_vec.y = origin->y - v->y;
    scratch_vec.z = origin->z - v->z;
    t = vec3_dot(&scratch_vec, &n);
    if (t <= 1e-5f) {
        return 0;
    }
    t = -(t / denom);
    if (t > 1.0f || t < 0.0f) {
        return 0;
    }
    scratch_vec5.x = dir->x * t + origin->x;
    scratch_vec5.y = dir->y * t + origin->y;
    scratch_vec5.z = dir->z * t + origin->z;
    v1 = &vertices[face->vertex[1]];
    vsub(&scratch_vec5, v, &scratch_vec);
    vsub(&scratch_vec5, v1, &scratch_vec2);
    vec3_cross(&scratch_vec, &scratch_vec2, &scratch_vec4);
    if (vec3_dot(&scratch_vec4, &n) < 0.0f) {
        return 0;
    }
    vsub(&scratch_vec5, &vertices[face->vertex[2]], &scratch_vec3);
    vec3_cross(&scratch_vec2, &scratch_vec3, &scratch_vec4);
    if (vec3_dot(&scratch_vec4, &n) < 0.0f) {
        return 0;
    }
    vec3_cross(&scratch_vec3, &scratch_vec, &scratch_vec4);
    if (vec3_dot(&scratch_vec4, &n) < 0.0f) {
        return 0;
    }
    switch (mode) {
    case 0:
        if (t < csn_query_nearest_hit_t) {
            csn_query_nearest_hit_t = t;
            csn_query_hit_buffer->hit_mask = 1;
            VecCopy(&wall_query_hit_result->point, &scratch_vec5);
            VecCopy(&wall_query_hit_result->normal, &n);
            wall_query_hit_result->flags = face->flags;
        }
        break;
    case 1:
        csn_query_hit_buffer->hit_mask = 1;
        VecCopy(&wall_query_hit_result->point, &scratch_vec5);
        VecCopy(&wall_query_hit_result->normal, &n);
        wall_query_hit_result->flags = face->flags;
        break;
    case 2:
        if (csn_query_hit_count >= 0x20) {
            return 0;
        }
        csn_query_hit_buffer->hit_mask = 1;
        VecCopy(&wall_query_hit_result->point, &scratch_vec5);
        VecCopy(&wall_query_hit_result->normal, &n);
        wall_query_hit_result->flags = face->flags;
        wall_query_hit_result++;
        csn_query_hit_count++;
        break;
    case 3:
        if (t < csn_query_nearest_hit_t) {
            csn_query_nearest_hit_t = t;
            VecCopy(&wall_query_hit_result->point, &scratch_vec5);
            VecCopy(&wall_query_hit_result->normal, &n);
            wall_query_hit_result->flags = face->flags;
        }
        break;
    }
    return 1;
}
#pragma pop

#pragma fp_contract on

#pragma push
#pragma fp_contract on
CsnGroup *refill_csn_candidate_cache(Vec *origin, CsnGroup **out_groups, u32 mask) {
    f32 rr;
    f32 dz;
    f32 dx;
    s32 n = 0;
    CsnGroup **it;
    CsnGroup *m;
    CsnGroup **first;
    it = TObjMapCsn::get_collision_controller()->get_collision_groups();
    first = out_groups;
    while ((m = *it++) != 0) {
        if ((m->flags & mask) && !(m->flags & 0x40000000)) {
            dz = m->center.z - origin->z;
            dx = m->center.x - origin->x;
            rr = m->radius;
            rr *= rr;
            if (dx * dx + dz * dz <= rr) {
                n++;
                if (n >= 0xF) {
                    break;
                }
                *out_groups++ = m;
            }
        }
    }
    *out_groups = 0;
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

CsnGroup *select_segment_query_groups(const Vec *a, const Vec *b) {
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
                if (calc_segment_xz_distance_sq(&w->center, a, b, &d, w->radius, lenSq, inv) != 0) {
                    if (++n >= 0x100) {
                        break;
                    }
                    *dst++ = w;
                }
            }
        }
    }
    *dst = NULL;
    csn_debug_hook_group_list(csn_query_groups);
    return csn_query_groups[0];
}

#pragma push
#pragma fp_contract on
s32 prepare_wall_query_polygons(const Vec *origin, f32 r, u32 mask) {
    const volatile Vec *pos = origin;
    s32 i;
    s32 count;
    s32 cnt;
    CsnFace *face;
    CsnModel *model;
    WallPolygon *out;
    CsnGroup **src;
    CsnGroup *g;
    s32 n;
    CsnGroup **dst;
    src = TObjMapCsn::get_collision_controller()->get_collision_groups();
    if (src == NULL) {
        return 0;
    }
    n = 0;
    dst = csn_query_groups;
    while ((g = *src++) != NULL) {
        if (g->flags & mask) {
            f32 b;
            const volatile f32 &center_z = g->center.z;
            f32 z = center_z;
            f32 dz = z - pos->z;
            f32 dx = g->center.x - pos->x;
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
    src = csn_query_groups;
    out = wall_query_scene_buffer;
    cnt = 0;
    while ((g = *src++) != NULL) {
        model = g->model;
        count = model->face_count;
        face = model->faces;
        for (i = 0; i < count; face++, i++) {
            const volatile f32 &center_z = face->center.z;
            f32 z = center_z;
            f32 dz = z - pos->z;
            f32 dx = face->center.x - pos->x;
            f32 b = r + face->radius;
            b *= b;
            if (dx * dx + dz * dz <= b) {
                if (++cnt >= 0x200) {
                    break;
                }
                out->copy_wall_polygon(face);
                out->vertices = model->vertices;
                out++;
            }
        }
    }
    out->vertices = NULL;
    return cnt;
}
#pragma pop


#pragma push
#pragma scheduling off
void WallPolygon::copy_wall_polygon(const CsnFace *source) {
    // The first two indices are one aligned word in each record.
    *reinterpret_cast<u32 *>(face.vertex) = *reinterpret_cast<const u32 *>(source->vertex);
    face.vertex[2] = source->vertex[2];
    face.flags = source->flags;
    *reinterpret_cast<VecWords *>(&face.normal) = *reinterpret_cast<const VecWords *>(&source->normal);
    *reinterpret_cast<VecWords *>(&face.center) = *reinterpret_cast<const VecWords *>(&source->center);
    face.radius = source->radius;
}
#pragma pop

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
            scratch_vec.x = w->center.x - a->x;
            scratch_vec.z = w->center.z - a->z;
            dsq = scratch_vec.x * scratch_vec.x + scratch_vec.z * scratch_vec.z;
            r = len + w->radius;
            r *= r;
            if (dsq <= r) {
                if (calc_segment_xz_distance_sq(&w->center, a, b, &d, w->radius, lenSq, inv) != 0) {
                    if (++n >= 0x100) {
                        break;
                    }
                    *dst++ = w;
                }
            }
        }
    }
    *dst = NULL;
    csn_debug_hook_group_list(csn_query_groups);
    return csn_query_groups[0];
}

WallRayResult *query_prepared_wall_polygons(WallRayQuery *query) {
    WallRayResult *r;
    csn_debug_hook_query_begin();
    r = &csn_query_map_object;
    if (select_deepest_wall_ray(query, r) == 0) {
        r = 0;
    }
    csn_debug_hook_query_name("csnCheckPluralVectorPolyBuff()");
    return r;
}

WallRayResult *query_wall_radial(WallRayQuery *query) {
    WallRayResult *r;
    csn_debug_hook_query_begin();
    r = &csn_query_map_object;
    if (prepare_wall_query_polygons(&query->origin, query->radius, query->mask) == 0) {
        r = 0;
    } else if (select_deepest_wall_ray(query, r) == 0) {
        r = 0;
    }
    csn_debug_hook_query_name("csnCheckPluralVector()");
    return r;
}

CsnHit *csnLookAt(const Vec *from, const Vec *to) {
    CsnHit *hit;
    csn_debug_hook_query_begin();
    hit = &csn_hit_storage;
    csn_debug_hook_segment(from, to);
    if (select_segment_query_groups(from, to) == NULL) {
        hit = NULL;
    } else if (check_line_hits_walls((Vec *)from, (Vec *)to, 0x8000, csn_query_groups) == 0) {
        hit = NULL;
    }
    csn_debug_hook_query_name("csnLookAt()");
    return hit;
}

CsnHit *csnVectorUnder(Vec *origin, CsnGroup **cached_groups, u32 mask) {
    CsnHit *hit;
    csn_debug_hook_under_query();
    csn_debug_hook_query_begin();
    csn_debug_hook_origin_vector(origin);
    hit = &csn_hit_storage;
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
    csn_debug_hook_query_name("csnVectorUnder(Use Buffer)");
    return hit;
}
CsnHit *csnVecterUnder(Vec *origin, u32 mask) {
    CsnHit *hit;
    csn_debug_hook_under_query();
    csn_debug_hook_query_begin();
    csn_debug_hook_origin_vector(origin);
    hit = &csn_hit_storage;
    if (select_ground_query_groups(origin, mask) == NULL) {
        hit = NULL;
    } else if (evaluate_ground_triangles(origin, mask, csn_query_groups) == 0) {
        hit = NULL;
    }
    csn_debug_hook_query_name("csnVecterUnder()");
    return hit;
}


CsnHit *csnVector(const Vec *from, const Vec *to, u32 mask) {
    CsnHit *hit;
    csn_debug_hook_query_begin();
    hit = &csn_hit_storage;
    if (query_collision_segment_groups((Vec *)from, (Vec *)to, mask) == NULL) {
        hit = NULL;
    } else if (query_segment_wall_meshes((Vec *)from, (Vec *)to, mask, csn_query_groups) == 0) {
        hit = NULL;
    }
    csn_debug_hook_query_name("csnVector()");
    return hit;
}

void free_wall_query_buffer(void) {
    if (wall_query_scene_buffer != NULL) {
        mem_free(wall_query_scene_buffer);
        wall_query_scene_buffer = NULL;
    }
}

void alloc_wall_query_buffer(void) { wall_query_scene_buffer = (WallPolygon *)mem_alloc(0x200 * sizeof(WallPolygon)); }

extern "C" {
void __construct_array(void *, CsnContact *(*)(CsnContact *), s32, s32, s32);
}
extern "C" {

void __sinit_CsnQuery_cpp(void) {
    __construct_array(csn_query_contacts, init_csn_contact, 0, sizeof(CsnContact), 0x20);
    csn_hit_storage.init_and_return();
    csn_query_map_object.init();
}

}

__declspec(section ".ctors") static void *const __sinit_CsnQuery_cpp_ref = (void *)__sinit_CsnQuery_cpp;


CsnGroup **TMapCsnCtrl::get_collision_groups() { return groups; }

extern TMapCsnCtrl *map_csn_ctrl_instance;

TMapCsnCtrl *TObjMapCsn::get_collision_controller() {
    return map_csn_ctrl_instance;
}
WallRayResult *WallRayResult::init() {
    header.init_and_return();
    index = -1;
    depth = -1.0f;
    return this;
}

CsnHit *CsnHit::init_and_return() {
    init_csn_hit(this);
    return this;
}

void init_csn_hit(CsnHit *hit) {
    hit->hit_mask = 0;
    hit->contact = csn_query_contacts;
}

CsnContact *init_csn_contact(CsnContact *contact) {
    contact->reset();
    return contact;
}

void CsnContact::reset() {
    point.z = 0.0f;
    point.y = 0.0f;
    point.x = 0.0f;
    normal.z = 0.0f;
    normal.y = 0.0f;
    normal.x = 0.0f;
    flags = 0;
}
