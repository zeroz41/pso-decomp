#ifndef PSO_RENDER_STRIPBUFFERPAIR_H
#define PSO_RENDER_STRIPBUFFERPAIR_H

#include "types.h"

struct NJS_OBJECT;

// One strip of a chunk model and the copy of its original UVs.
struct StripUvRef {
    s16 *strip;
    s16 *uv;
};

// The strips of a model that use one texture, with a copy of their UVs, so the
// texture can be scrolled over them.
struct StripBufferPair {
    StripBufferPair(NJS_OBJECT *model, s32 texture_filter);
    ~StripBufferPair();
    // Rewrites every strip's UVs as the original UVs plus the scroll (mod 256).
    void scroll_uvs(s16 scroll_u, s16 scroll_v);

    s32 uv_count;
    s32 strip_count;
    StripUvRef *strips;
    s16 *uvs;
    u8 pad_10[0x4];

private:
    void collect_model_strips_by_texture(NJS_OBJECT *node, s32 texture_filter);
    void collect_plist_strips_by_texture(s16 *plist, s32 texture_filter);
    void count_model_strips_by_texture(NJS_OBJECT *node, s32 texture_filter);
    void count_plist_strips_by_texture(s16 *plist, s32 texture_filter);
};

LAYOUT_ASSERT(StripBufferPairSize, sizeof(StripBufferPair) == 0x14);

#endif
