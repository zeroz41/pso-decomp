#include "types.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXManage.h>
#undef PSO_SDK_COMPACT_MATH
#include <dolphin/os/OSCache.h>
#include "pso/system/TLanguage.h"
#include "pso/render/GvplPaletteFile.h"
#include "pso/render/GinjaTextureHeader.h"

// Loads the palette into `tlut_name`, then a copy with every colour inverted (opaque
// where it was translucent) into `inverted_tlut_name`.
void TLanguage::decode_font_data(const char *filename, GvplPalette *palette, s32 tlut_name, s32 inverted_tlut_name) {
    s32 i;
    u16 *entry;
    u16 color;

    load_palette_tlut(filename, palette, tlut_name);
    entry = (u16 *)palette->data;
    for (i = palette->entry_count; i > 0; i--) {
        color = *entry;
        if (color & 0x8000) {
            *entry = color ^ 0x7FFF;
        } else {
            *entry = color ^ 0xFFF;
            *entry |= 0x7000;
        }
        entry += 1;
    }
    DCStoreRange(palette->data, 0x40000);
    init_and_load_tlut(inverted_tlut_name, palette->format, palette->entry_count, palette->data);
    GXDrawDone();
}

void TLanguage::load_palette_tlut(const char *filename, GvplPalette *palette, s32 tlut_name) {
    load_gvpl_palette_file(filename, palette);
    init_and_load_tlut(tlut_name, palette->format, palette->entry_count, palette->data);
    GXDrawDone();
}
