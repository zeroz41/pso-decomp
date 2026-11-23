#include "types.h"
#include "pso/system/TLanguage.h"
#include "pso/unk/text_801A5778.h"

extern "C" {

s32 GXDrawDone();
s32 init_and_load_tlut(s32, u16, s16, s32);

void TLanguage::draw_string(void *filename, void *palette, s32 tlut_name) {
    load_gvpl_palette_file((const char *)filename, (GvplPalette *)palette);
    init_and_load_tlut(tlut_name, *(u16 *)((s8 *)palette + 4), *(s16 *)((s8 *)palette + 0xA), *(s32 *)((s8 *)palette + 0));
    GXDrawDone();
}

}
