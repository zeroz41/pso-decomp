#ifndef PSO_SYSTEM_NINJATYPES_H
#define PSO_SYSTEM_NINJATYPES_H

#include <stddef.h>
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

// Ninja texture list: `nbTexture` names, each naming one texture
// (NJS_TEXNAME is defined with Ginja's loaded-texture fields in GinjaMaterialState.h).
struct NJS_TEXNAME;

struct NJS_TEXLIST {
    NJS_TEXNAME *textures;
    u32 nbTexture;
};

// One sprite cell of a texture: size, centre, uv rectangle and texture index.
struct NJS_TEXANIM {
    s16 sx, sy;
    s16 cx, cy;
    s16 u1, v1, u2, v2;
    s16 texid, attr;
};

typedef Vec NJS_POINT3;

// A Ninja camera: eye position, view direction, roll, view angle (0x10000 a
// turn) and the near and far clip planes (negative view-space z).
struct NJS_CAMERA {
    f32 px, py, pz;
    f32 vx, vy, vz;
    s32 roll;
    s32 ang;
    f32 n_clip;
    f32 f_clip;
};

// A 2D sprite: position, scale and angle, drawn from cells of `tanim`
// (texture ids into `tlist`).
struct NJS_SPRITE {
    NJS_POINT3 p;
    f32 sx, sy;
    s32 ang;
    NJS_TEXLIST *tlist;
    NJS_TEXANIM *tanim;
};

struct NJS_POINT2 {
    f32 x, y;
};

struct NJS_TEX {
    s16 u, v;
};

// `num` points with one colour each and optional texture coordinates.
struct NJS_POINT3COL {
    NJS_POINT3 *p;
    u32 *col;
    NJS_TEX *tex;
    u32 num;
};

// A Ninja colour with float channels, alpha first.
struct NJS_ARGB;
// Copies the four channels of `src` into `dst`.
void copy_argb(NJS_ARGB *dst, NJS_ARGB *src);

struct NJS_ARGB {
    f32 a;
    f32 r;
    f32 g;
    f32 b;
};

// NJS_OBJECT evalflags bits.
#define NJD_EVAL_UNIT_POS 0x1  // pos is zero: no translation
#define NJD_EVAL_UNIT_ANG 0x2  // ang is zero: no rotation
#define NJD_EVAL_UNIT_SCL 0x4  // scl is one: no scaling
#define NJD_EVAL_HIDE 0x8      // the node is not drawn
#define NJD_EVAL_BREAK 0x10    // the node's children are skipped
#define NJD_EVAL_ZXY_ANG 0x20  // ang is applied in Z, X, Y order
#define NJD_EVAL_SKIP 0x40     // the node takes no motion keys: its own pos, ang and scl are used
#define NJD_EVAL_QUATERNION 0x400  // ang (x, y, z) and quat_w are a rotation quaternion

// Chunk polygon list heads (Ninja ninjacnk.h). A chunk starts with a 16-bit
// [flags(8)|type(8)] head; the type ranges are bits, tiny, material (16-31), vertex (32-55),
// volume (56-63) and strip chunks.
#define NJD_BITSOFF 1    // bits chunks (16-bit, no size)
#define NJD_TINYOFF 8    // tiny chunks (32-bit)
#define NJD_MATOFF 16    // material chunks
#define NJD_STRIPOFF 64  // strip chunks
#define NJD_ENDOFF 255   // end chunk

#define NJD_CE (NJD_ENDOFF + 0)     // end of the list
#define NJD_CB_BA (NJD_BITSOFF + 0) // blend alpha: bits 13-8 = src/dst alpha instructions
#define NJD_CB_CP (NJD_BITSOFF + 3) // cache polygon list: bits 15-8 = cache number
#define NJD_CB_DP (NJD_BITSOFF + 4) // draw polygon list: bits 15-8 = cache number
#define NJD_CS (NJD_STRIPOFF + 0)     // strip
#define NJD_CS_UVN (NJD_STRIPOFF + 1) // strip with uv in 0-255
#define NJD_CS_UVH (NJD_STRIPOFF + 2) // strip with uv in 0-1023

// Strip chunk flags (the head's high byte).
#define NJD_FST_SHIFT 8
#define NJD_FST_IL (0x01 << NJD_FST_SHIFT)  // ignore light
#define NJD_FST_ENV (0x40 << NJD_FST_SHIFT) // environment mapping

// Chunk model streams referenced by an NJS_OBJECT.
struct NJS_CNK_MODEL {
    void *vertex_list;
    s16 *polygon_list;
    f32 center[3];
    f32 r;  // bounding radius around center
};

// Ninja model hierarchy node.
struct NJS_OBJECT {
    u32 evalflags;
    void *model;
    f32 pos[3];
    s32 ang[3];
    f32 scl[3];
    NJS_OBJECT *child;
    NJS_OBJECT *sibling;
    f32 quat_w; // with evalflags 0x400 the rotation is a quaternion: ang holds x, y, z as floats, this w (name inferred)
};

LAYOUT_ASSERT(NJS_OBJECT_size, sizeof(NJS_OBJECT) == 0x38);
LAYOUT_ASSERT(NJS_OBJECT_child_offset, offsetof(NJS_OBJECT, child) == 0x2C);

extern "C" void copy_model_node(NJS_OBJECT *dst, const NJS_OBJECT *src);

// Ninja byte colour; on this big-endian target the bytes of the ARGB word are a, r, g, b.
struct NJS_BGRA {
    u8 a;
    u8 r;
    u8 g;
    u8 b;
};

// Ninja colour: one packed ARGB word or its bytes.
union NJS_COLOR {
    u32 color;
    NJS_BGRA argb;
};

// `num` 2D points with one colour each and optional texture coordinates.
struct NJS_POINT2COL {
    NJS_POINT2 *p;
    NJS_COLOR *col;
    NJS_TEX *tex;
    u32 num;
};

// Ninja motion: per-node key data played over nbFrame frames.
struct NJS_MOTION {
    void *mdata;
    u32 nbFrame;
    u16 type;
    u16 inp_fn;
};

// NJS_MOTION::type bits: the channels each node's row of keys holds, in this order.
#define NJD_MTYPE_POS_0 0x1
#define NJD_MTYPE_ANG_1 0x2
#define NJD_MTYPE_SCL_2 0x4
#define NJD_MTYPE_VEC_3 0x8
#define NJD_MTYPE_VERT_4 0x10
#define NJD_MTYPE_NORM_5 0x20
#define NJD_MTYPE_TARGET_3 0x40
#define NJD_MTYPE_ROLL_6 0x80
#define NJD_MTYPE_ANGLE_7 0x100
#define NJD_MTYPE_QUAT_1 0x2000

// Two motions blended: motion[0] at frame[0] into motion[1] at frame[1].
struct NJS_MOTION_LINK {
    NJS_MOTION *motion[2];
    f32 frame[2];
};

// NJS_MOTION::mdata for a motion with position and angle keys per node.
struct NJS_MDATA2 {
    void *p[2];  // position keys, angle keys
    u32 nb[2];   // their counts
};

// A float key: three values at a frame.
struct NJS_MKEY_F {
    u32 keyframe;
    f32 key[3];
};

LAYOUT_ASSERT(NinjaFloatKeySize, sizeof(NJS_MKEY_F) == 0x10);


// An angle key: three angles at a frame.
struct NJS_MKEY_A {
    u32 keyframe;
    s32 key[3];
};

// A short angle key: three 16-bit angles at a 16-bit frame.
struct NJS_MKEY_SA {
    u16 keyframe;
    s16 key[3];
};

// One angle at a frame.
struct NJS_MKEY_A1 {
    u32 keyframe;
    s32 key;
};

// A rotation quaternion at a frame, real part first.
struct NJS_MKEY_QUAT {
    u32 keyframe;
    f32 key[4];
};

#endif
