#ifndef PSO_SYSTEM_SCENE_UVSCROLLBUFFER_H
#define PSO_SYSTEM_SCENE_UVSCROLLBUFFER_H

#include "types.h"
#include "pso/unk/text_803279CC.h"

struct NJS_OBJECT;
struct GinjaVertexArray;

// One scrolled uv vertex array and the copy of its original uvs.
struct UvScrollEntry {
    GinjaVertexArray *array;
    s16 *source;
};

// The uv vertex arrays of a model tree that use one scrolling texture, with
// their original uvs; offset_position moves them all by whole texels.
class UvScrollBuffer {
public:
    ScrolledStripTotals totals; // 0x00 uv pairs (sum) and vertex arrays (count)
    UvScrollEntry *entries;     // 0x08
    s16 *source_uvs;            // 0x0C
    s16 u;                      // 0x10
    s16 v;                      // 0x12

    UvScrollBuffer(NJS_OBJECT *root, s32 texture_id);
    ~UvScrollBuffer();
    void offset_position(s32 du, s32 dv);
    void apply_uv_offset(s16 du, s16 dv);
};

// Write cursors collect_scroll_uv_entries appends entries and uvs at.
extern UvScrollEntry *scroll_uv_entry_write_cursor;
extern s16 *scroll_uv_coordinate_write_cursor;

LAYOUT_ASSERT(UvScrollBuffer_size, sizeof(UvScrollBuffer) == 0x14);

#endif
