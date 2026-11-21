#ifndef PSO_SYSTEM_NINJATYPES_H
#define PSO_SYSTEM_NINJATYPES_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

// Ninja texture list: `nbTexture` names, each naming one texture.
struct NJS_TEXNAME {
    void *filename;
    u32 attr;
    u32 texaddr;
};

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
    u8 pad_34[0x4];
};

typedef char NJS_OBJECT_size[sizeof(NJS_OBJECT) == 0x38 ? 1 : -1];

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

#endif
