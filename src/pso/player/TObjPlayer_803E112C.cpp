#include "types.h"
#include "pso/player/TObjPlayer_803DF7A8.h"
#include "pso/player/TObjPlayer_803E112C.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
#pragma push
#pragma fp_contract off

struct CollisionSphere { Vec_803E1B1C center; f32 radius; };
struct EdgeOrder_803E112C { s32 v[5]; };
extern const Faces_803E0ED4 box_face_vertex_index_table, box_edge_adjacent_face_table;
extern const EdgeOrder_803E112C lbl_8047E558;

#pragma use_lmw_stmw off

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
static inline f32 collisionRoot(f32 x) {
    volatile f32 y;
    if (x > 0.0f) {
        f64 guess = __frsqrte(x);
        guess = 0.5 * guess * (3.0 - guess * guess * x);
        guess = 0.5 * guess * (3.0 - guess * guess * x);
        guess = 0.5 * guess * (3.0 - guess * guess * x);
        y = (f32)(x * guess);
        return y;
    }
    return x;
}

static inline f32 inline_fn(Vec_803E1B1C *arg0, f32 arg1, Vec_803E1B1C *arg2) {
    return arg0->x + (arg1 * arg2->x);
}
static inline f32 inline_fn2(f32 arg0, f32 arg1) {
    return arg0 + arg1;
}
static inline f32 inline_fn23(Vec_803E1B1C *arg0, Vec_803E1B1C *arg1) {
    return arg0->x - arg1->x;
}
static inline f32 inline_fn234(Vec_803E1B1C *arg0, f32 arg1, Vec_803E1B1C *arg2) {
    return arg0->z + (arg1 * arg2->z);
}
static inline f32 inline_fn2345(f32 arg0, f32 arg1, Vec_803E1B1C *arg2) {
    return (arg0 * arg1) + arg2->x;
}
static inline f32 inline_fn23456(f32 arg0, f32 arg1, Vec_803E1B1C *arg2) {
    return (arg0 * arg1) + arg2->y;
}

s32 test_box_sphere_contact(Vec_803E1B1C *box, CollisionSphere *sphere)
{
  float new_var2;
  Vec_803E1B1C *new_var;
  Vec_803E1B1C boxMin;
  Vec_803E1B1C boxMax;
  Vec_803E1B1C sphereMin;
  u8 *new_var3;
  Vec_803E1B1C sphereMax;
  calc_bounds_min_max__10TObjPlayerFPvPvPv(box, &boxMin, &boxMax);
  new_var3 = (u8 *) (&sphereMax);
  ((TObjPlayer *)(u8 *) sphere)->calc_bounds((u8 *) (&sphereMin), new_var3);
  if (((TObjPlayer *)(u8 *) (&boxMin))->test_aabb_overlap((u8 *) (&boxMax), (u8 *) (&sphereMin), (u8 *) (&sphereMax)) != 0)
  {
    Faces_803E0ED4 faces = box_face_vertex_index_table;
    Vec_803E1B1C normals[6];
    Faces_803E0ED4 adjacent = box_edge_adjacent_face_table;
    s32 i;
    s32 j;
    s32 inside = 1;
    for (i = 0; i < 6; i++)
    {
      s32 *face = faces.v[i];
      Vec_803E1B1C *n = &normals[i];
      f32 scale;
      n->x = -(((box[face[1]].y - box[face[0]].y) * (box[face[2]].z - box[face[0]].z)) - ((box[face[1]].z - box[face[0]].z) * (box[face[2]].y - box[face[0]].y)));
      new_var = n;
      new_var->y = -(((box[face[1]].z - box[face[0]].z) * (box[face[2]].x - box[face[0]].x)) - ((box[face[1]].x - box[face[0]].x) * (box[face[2]].z - box[face[0]].z)));
      new_var->z = -(((box[face[1]].x - box[face[0]].x) * (box[face[2]].y - box[face[0]].y)) - ((box[face[1]].y - box[face[0]].y) * (box[face[2]].x - box[face[0]].x)));
      new_var2 = 1.0f / collisionRoot((new_var->z * new_var->z) + ((new_var->x * new_var->x) + (new_var->y * new_var->y)));
      scale = new_var2;
      new_var->x *= scale;
      new_var->y *= scale;
      new_var->z *= scale;
    }

    for (i = 0; i < 6; i++)
    {
      s32 faceHit = 1;
      Vec_803E1B1C *n = &normals[i];
      s32 *face = faces.v[i];
      Vec_803E1B1C *center;
      f32 d = -((n->z * box[face[0]].z) + ((n->x * box[face[0]].x) + (n->y * box[face[0]].y)));
      f32 t = (-(d + ((center->z * n->z) + ((center->x * n->x) + (center->y * n->y))))) / ((n->z * n->z) + ((n->x * n->x) + (n->y * n->y)));
      f32 px = inline_fn(center, t, n);
      f32 py = inline_fn2(center->y, t * n->y);
      f32 pz = inline_fn234(center, t, n);
      f32 dist = collisionRoot(((pz - center->z) * (pz - center->z)) + (((px - center->x) * (px - center->x)) + ((py - center->y) * (py - center->y))));
      for (j = 0; j < 4; j++)
      {
        EdgeOrder_803E112C order = lbl_8047E558;
        s32 k = order.v[j];
        Vec_803E1B1C *a = &box[face[k]];
        Vec_803E1B1C *b = &box[face[order.v[j + 1]]];
        f32 ex = inline_fn23(a, b);
        f32 ey = a->y - b->y;
        f32 ez = a->z - b->z;
        f32 s = ((ez * (pz - a->z)) + ((ex * (px - a->x)) + (ey * (py - a->y)))) / ((ez * ez) + ((ex * ex) + (ey * ey)));
        f32 fx = inline_fn2345(ex, s, a);
        f32 fz = (ez * s) + a->z;
        f32 fy = inline_fn23456(ey, s, a);
        f32 dx = fx - px;
        f32 dy = fy - py;
        f32 dz = fz - pz;
        f32 scale = 1.0f / collisionRoot((dz * dz) + ((dx * dx) + (dy * dy)));
        dx *= scale;
        dy *= scale;
        dz *= scale;
        if ((((((f32) __fabs(normals[adjacent.v[i][k]].x - dx)) <= 0.025f) && (((f32) __fabs(normals[adjacent.v[i][k]].y - dy)) <= 0.025f)) && (((f32) __fabs(normals[adjacent.v[i][k]].z - dz)) <= 0.025f)) && (sphere->radius >= dist))
        {
          faceHit &= 1;
        }
        else
          if (dist <= sphere->radius)
        {
          if ((((pz - fz) * (pz - fz)) + (((px - fx) * (px - fx)) + ((py - fy) * (py - fy)))) <= ((sphere->radius * sphere->radius) - (dist * dist)))
          {
            faceHit &= 1;
          }
          else
          {
            faceHit = 0;
          }
        }
        else
        {
          faceHit = 0;
        }
      }

      if (faceHit != 0)
      {
        return 1;
        center = &sphere->center;
      }
      f32 dx = px - sphere->center.x;
      f32 dy = py - sphere->center.y;
      f32 dz = pz - sphere->center.z;
      f32 scale = 1.0f / collisionRoot((dz * dz) + ((dx * dx) + (dy * dy)));
      dx *= scale;
      dy *= scale;
      dz *= scale;
      if (((((f32) __fabs(n->x - dx)) <= 0.025f) && (((f32) __fabs(n->y - dy)) <= 0.025f)) && (((f32) __fabs(n->z - dz)) <= 0.025f))
      {
        inside &= 1;
      }
      else
      {
        inside = 0;
      }
    }

    if (inside != 0)
    {
      return 1;
    }
  }
  return 0;
}
#pragma pop

#pragma pop
}

s32 spheres_overlap(u8 *arg0, u8 *arg1) {
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    temp_f3 = *(f32 *)((s8 *)arg1 + 0) - *(f32 *)((s8 *)arg0 + 0);
    temp_f4 = *(f32 *)((s8 *)arg1 + 4) - *(f32 *)((s8 *)arg0 + 4);
    temp_f2 = *(f32 *)((s8 *)arg1 + 8) - *(f32 *)((s8 *)arg0 + 8);
    temp_f5 = *(f32 *)((s8 *)arg0 + 0xC) + *(f32 *)((s8 *)arg1 + 0xC);
    return ((temp_f2 * temp_f2) + ((temp_f3 * temp_f3) + (temp_f4 * temp_f4))) <= (temp_f5 * temp_f5);
}
