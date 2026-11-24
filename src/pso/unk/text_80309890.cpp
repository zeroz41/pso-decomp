#include "types.h"
#include "pso/ui/charcreate/TChCrTagInformationStr.h"
#include "pso/unk/text_80309890.h"

extern s32 char_creation_tag_info_selected_index;
void fn_80309890(TObject *o, s32 v) {
    if (v == char_creation_tag_info_selected_index || v < -1 || v >= 0xF) {
        return;
    }
    char_creation_tag_info_selected_index = v;
    if (v != -1) {
        TChCrTagInformationStr::create(o, v);
    }
}
