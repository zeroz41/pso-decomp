#include "types.h"
#include <dolphin/os/OSCache.h>
#include "pso/unk/text_80327844.h"
#include "pso/unk/text_803279CC.h"
#include "pso/system/memory.h"
#include "pso/render/GinjaModel.h"
#include "pso/system/scene/UvScrollBuffer.h"

void UvScrollBuffer::offset_position(s32 du, s32 dv) {
    this->u = (s16) (this->u + du);
    this->v = (s16) (this->v + dv);
    apply_uv_offset(this->u, this->v);
}

void UvScrollBuffer::apply_uv_offset(s16 du, s16 dv) {
    s16 dx = du % 256;
    s16 dy = dv % 256;
    s32 i;
    for (i = 0; i < this->totals.count; i++) {
        GinjaVertexArray *array = this->entries[i].array;
        s16 *src = this->entries[i].source;
        s16 *dst = static_cast<s16 *>(array->data);
        s32 j;
        for (j = 0; j < array->count; j++) {
            dst[0] = src[0] + dx;
            dst[1] = src[1] + dy;
            src += 2;
            dst += 2;
        }
        DCFlushRangeNoSync(array->data, array->count * 4);
    }
}

UvScrollBuffer::~UvScrollBuffer() {
    if (this->source_uvs != NULL) {
        mem_free(this->source_uvs);
        this->source_uvs = NULL;
    }
    if (this->entries != NULL) {
        mem_free(this->entries);
        this->entries = NULL;
    }
}

UvScrollBuffer::UvScrollBuffer(NJS_OBJECT *root, s32 texture_id) {
    this->totals.count = 0;
    this->totals.sum = 0;
    visit_model_tree_recursive(&this->totals, root, texture_id);
    this->entries = NULL;
    this->source_uvs = NULL;
    if (this->totals.count > 0) {
        this->entries = static_cast<UvScrollEntry *>(mem_alloc(this->totals.count * 8));
        this->source_uvs = static_cast<s16 *>(mem_alloc(this->totals.sum * 4));
        scroll_uv_entry_write_cursor = this->entries;
        scroll_uv_coordinate_write_cursor = this->source_uvs;
        visit_matching_models((saddr)this, root, texture_id);
    }
    this->u = 0;
    this->v = 0;
}
