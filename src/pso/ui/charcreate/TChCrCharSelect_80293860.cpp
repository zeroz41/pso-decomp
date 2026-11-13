#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/player/TPlyCharData.h"
#include "pso/ui/charcreate/TChCrCharSelect_802937D4.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/ui/charcreate/CharacterAppearance.h"

extern "C" {

CharacterAppearanceFields *get_class_appearance_preset(s32 arg0);
s32 copy_player_visual_record(void *, void *);

extern s32 TChCrCharSelect__selected_slot_index;
extern s32 tl_03;

void TChCrCharSelect::tick_and_apply_selection() {
    s32 temp_r0;
    CharacterAppearanceFields *temp_r31;

    temp_r0 = apply_delay - 1;
    apply_delay = temp_r0;
    if (temp_r0 <= 0) {
        temp_r31 = (CharacterAppearanceFields *)&get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF)->m_disp_data.m_disp_part2;
        copy_player_visual_record(temp_r31, get_class_appearance_preset(get_char_select_class_id(TChCrCharSelect__selected_slot_index)));
        temp_r31->section = -1;
        temp_r31->name[0] = 0;
        TCharaMaking::create((void *)tl_03, temp_r31);
        queue_destruction__7TObjectFv(this);
    }
}

}
