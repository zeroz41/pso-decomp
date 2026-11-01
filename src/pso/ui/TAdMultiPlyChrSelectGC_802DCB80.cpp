#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/unk/text_802A1144.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/TAdMultiChgGameModeGC.h"
#include "pso/misc/TWindowSubComCard.h"

struct Obj_802DCCA4 { u8 pad[0x2C]; s32 f2C; };

extern "C" {
void collect_player_slots__22TAdMultiPlyChrSelectGCFv(void *);
extern s32 multi_chr_select_serial_access_state;
void TAdMultiPlyChrSelectGC__sub_802DCCA4(Obj_802DCCA4 *arg0);
s32 set_entry_value__22TAdMultiPlyChrSelectGCFlUl(s32, s32, s32 *);
s32 TWindowShortListCtrl__check_controller_button(char *, s32);
s32 play_sound_effect(s32, s32, s32, s32);

extern char controller_physical_port_bank[];
extern s32 TAdMultiPlyChrSelectGC__data_805DE898;

void TAdMultiPlyChrSelectGC::close_and_reset() {
    if ((u32) *(u32 *)&this->unk_80 != 0U) {
        ((TWindowBase *)(*(void * *)&this->unk_80))->close();
        *(u32 *)&this->unk_80 = 0U;
    }
    if ((u32) this->m_94 != 0U) {
        ((TWindowSubComCard *)(*(void * *)&this->m_94))->close();
        this->m_94 = 0U;
    }
    ((TAdMultiPlyChrSelectGC *)(this->m_5c))->reset_cursor_state();
    if ((u32) *(u32 *)&this->unk_70 != 0U) {
        disallow_rendering__7TObjectFv((TObject *)(*(void * *)&this->unk_70));
    }
    ((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->unk_60))->set_field_100(1);
    set_entry_value__22TAdMultiPlyChrSelectGCFlUl(*(s32 *)&this->m_64, 0, &TAdMultiPlyChrSelectGC__data_805DE898);
    set_entry_value__22TAdMultiPlyChrSelectGCFlUl(*(s32 *)&this->m_64, 1, &TAdMultiPlyChrSelectGC__data_805DE898);
    *(s32 *)&this->unk_30 = -1;
    if ((((TAdMultiPlyChrSelectGC *)(this->m_6c))->is_state_closing() == 0) && (TWindowShortListCtrl__check_controller_button(controller_physical_port_bank + 0x20, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)&this->unk_28 = 0x1B;
        *(s32 *)&this->m_20 = 0x1A;
        return;
    }
    if ((((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->unk_68))->get_player_index() == 0xE) && (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() == 0x14)) {
        *(s32 *)&this->m_20 = 0x1E;
    }
}
void TAdMultiPlyChrSelectGC__sub_802DCCA4(Obj_802DCCA4 *arg0) {
    multi_chr_select_serial_access_state = get_field_118__22TAdEnterSerialAccessGCFv();
    switch (arg0->f2C) {
    case 2:
        break;
    case 0:
        set_opening_movie_purpose(1);
        TKeyBoardControl__sub_8000F9CC(3);
        break;
    case 1:
        collect_player_slots__22TAdMultiPlyChrSelectGCFv(arg0);
        TAdMultiChgGameModeGC::begin_transition();
        break;
    }
}

}
