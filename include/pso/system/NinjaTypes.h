#ifndef PSO_SYSTEM_NINJATYPES_H
#define PSO_SYSTEM_NINJATYPES_H

#include "types.h"

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

// Ninja motion: per-node key data played over nbFrame frames.
struct NJS_MOTION {
    void *mdata;
    u32 nbFrame;
    u16 type;
    u16 inp_fn;
};

#endif
