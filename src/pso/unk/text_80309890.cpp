#include "types.h"
#include "pso/ui/charcreate/TChCrTagInformationStr.h"
#include "pso/unk/text_80309890.h"

extern s32 char_creation_tag_info_selected_index;
void fn_80309890(TObject *o, s32 index) {
    if (index == char_creation_tag_info_selected_index || index < -1 || index >= 0xF) {
        return;
    }
    char_creation_tag_info_selected_index = index;
    if (index != -1) {
        TChCrTagInformationStr::create(o, index);
    }
}
