#include "pso/system/memory.h"
#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/unk/text_801A5778.h"
#include "pso/unk/text_803DAFA8.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include <dolphin/os/OSCache.h>

void load_gvpl_palette_file(const char *filename, GvplPalette *palette) {
    GvplChunk *file;
    file = (GvplChunk *)load_disc_file(filename);
    load_gvpl_palette(file, palette);
    DCStoreRange(palette->data, 0x40000);
    safe_free(file);
}
