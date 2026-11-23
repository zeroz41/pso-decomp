#include "types.h"
#include "pso/system/TLanguage.h"
#include "pso/unk/text_801A5778.h"

extern "C" {

s32 GXDrawDone();
s32 init_and_load_tlut(s32, u16, s16, s32);

void TLanguage::draw_string(void *arg0, void *arg1, s32 arg2) {
    load_gvpl_palette_file((const char *)arg0, (GvplPalette *)arg1);
    init_and_load_tlut(arg2, *(u16 *)((s8 *)arg1 + 4), *(s16 *)((s8 *)arg1 + 0xA), *(s32 *)((s8 *)arg1 + 0));
    GXDrawDone();
}

}
