#include "pso/render/GinjaMaterialState.h"
#include "pso/render/GinjaTextureEntryCopy.h"

LAYOUT_ASSERT(NJS_TEXNAMESize, sizeof(NJS_TEXNAME) == 0xC);

// The retail copy alternates each load with its store.
#pragma push
#pragma scheduling off
void copy_ginja_texture_entry(NJS_TEXNAME *destination, const NJS_TEXNAME *source) {
    destination->filename = source->filename;
    destination->attr = source->attr;
    destination->texaddr = source->texaddr;
}
#pragma pop
