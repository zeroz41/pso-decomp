#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/player/TPlyCharData.h"
#include "pso/ui/charcreate/TChCrCharSelect_802937D4.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/system/task/TObject.h"

extern "C" {

s32 get_class_appearance_preset();
s32 copy_player_visual_record(int, int);

extern s32 TChCrCharSelect__selected_slot_index;
extern s32 tl_03;

void TChCrCharSelect::tick_and_apply_selection() {
    s32 temp_r0;
    u8 *temp_r31;

    temp_r0 = *(s32 *)((s8 *)((u8 *)this) + 0x1C) - 1;
    *(s32 *)((s8 *)((u8 *)this) + 0x1C) = temp_r0;
    if (temp_r0 <= 0) {
        temp_r31 = (unsigned char *)&get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF)->m_disp_data.m_disp_part2;
        get_char_select_class_id((TChCrCharSelect__selected_slot_index));
        copy_player_visual_record((int)temp_r31, (int) (get_class_appearance_preset()));
        *(s8 *)((s8 *)temp_r31 + 0x30) = -1;
        *(s8 *)((s8 *)temp_r31 + 0) = 0;
        TCharaMaking::create((void *)tl_03, (void *)temp_r31);
        queue_destruction();
    }
}

}
