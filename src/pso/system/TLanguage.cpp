#include "types.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXManage.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/system/TLanguage.h"
#include "pso/unk/text_801A5778.h"
#include "pso/unk/text_803DAFA8.h"

void TLanguage::draw_string(void *filename, void *palette, s32 tlut_name) {
    GvplPalette *gvpl = (GvplPalette *)palette;
    load_gvpl_palette_file((const char *)filename, gvpl);
    init_and_load_tlut(tlut_name, gvpl->format, gvpl->entry_count, gvpl->data);
    GXDrawDone();
}
