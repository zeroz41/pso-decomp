#include "types.h"
#include "pso/object/quest/TObjQuestCol2.h"

extern "C" {

void *TObjQuestCol2__ct(TObjQuestCol2 *arg0);
s32 TObjQuestColBase__ct();
s32 update_trigger_state__16TObjQuestColBaseFf(f32);

int TObjQuestCol2::vfunc_15() {
    return (u32)__cntlzw(1 - update_trigger_state__16TObjQuestColBaseFf(*(f32 *)&this->unk_AC)) >> 5;
}

extern s32 __vt__13TObjQuestCol2[];
extern s32 lbl_805D340C;
extern s32 quest_mission_manager;
extern s32 quest_area_manager;

void *TObjQuestCol2__ct(TObjQuestCol2 *quest_col2) {

    TObjQuestColBase__ct();
    *(s32 **)((s8 *)quest_col2 + 0x18) = __vt__13TObjQuestCol2;
    *(s32 *)((s8 *)quest_col2 + 0) = (s32) lbl_805D340C;
    quest_col2->m_c0 = (s32) *(s32 *)((s8 *)quest_col2 + 0x88);
    if ((s32) quest_col2->m_c0 < 0) {
        quest_col2->m_c0 = 0;
    }
    if ((s32) quest_col2->m_c0 > 1) {
        quest_col2->m_c0 = 1;
    }
    switch (quest_col2->m_c0) {
    case 0:
        *(s32 *)((s8 *)quest_col2 + 0xBC) = (s32) quest_mission_manager;
        break;
    case 1:
        *(s32 *)((s8 *)quest_col2 + 0xBC) = (s32) quest_area_manager;
        break;
    default:
        *(s32 *)((s8 *)quest_col2 + 0xBC) = 0;
        break;
    }
    return quest_col2;
}

}
