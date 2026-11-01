#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802DBCC4.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802DC760.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/misc/TWindowMessageYesNo.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/TLevelSelect.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/ui/TAdEnterSerialAccessGC.h"

struct RecoveredGlobal_802DCA20_TAdMultiPlyChrSelectGC__data_804727B0 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_802DCA20_lbl_804727E8 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_802DCA20_lbl_8050E3B8 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_802DCA20_TAdMultiPlyChrSelectGC__data_804727B0;
struct Ent_802DC8A0 { u8 d[0x50]; };

struct Pair_802DC8A0 { u8 d[8]; };

extern "C" {
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 play_sound_effect(s32, s32, s32, s32);
s32 TAdMultiPlyChrSelectGC__sub_802C5A44(int, void *, int);
extern RecoveredGlobal_802DCA20_TAdMultiPlyChrSelectGC__data_804727B0 TAdMultiPlyChrSelectGC__character_slot_positions;
extern RecoveredGlobal_802DCA20_lbl_804727E8 multi_chr_select_item_rect_table;
extern s32 controller_physical_port_bank[];
s32 get_instance__22TAdMultiPlyChrSelectGCFv(s32);
void TAdMultiPlyChrSelectGC::update_input_state() {

    if (TWindowShortListCtrl__check_controller_button((s8 *)controller_physical_port_bank + 0x20, 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) this->m_94 != 0U) {
            ((TWindowSubComCard *)(*(void * *)&this->m_94))->close();
            this->m_94 = 0U;
        }
        *(s32 *)&this->unk_58 = (s32) (*(s32 *)&this->unk_58 + 1);
        *(s32 *)&this->m_20 = 0x1F;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() < 0x14) {
        if (((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->unk_68))->get_player_index() < 0xE) {
            *(s32 *)&this->unk_58 = 0;
        }
        if ((u32) this->m_94 != 0U) {
            ((TWindowSubComCard *)(*(void * *)&this->m_94))->close();
            this->m_94 = 0U;
        }
        *(s32 *)&this->m_20 = 0x1D;
        return;
    }
    if (((TWindowMessageYesNo *)(this->m_94))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(this->m_94))->get_slot_or_neg1()) {
        case 0:
            *(s32 *)&this->m_20 = 0x21;
            return;
        case 1:
            if ((u32) this->m_94 != 0U) {
                ((TWindowSubComCard *)(*(void * *)&this->m_94))->close();
                this->m_94 = 0U;
            }
            *(s32 *)&this->unk_58 = (s32) (*(s32 *)&this->unk_58 + 1);
            *(s32 *)&this->m_20 = 0x1F;
            break;
        }
    }
}
typedef char RecoveredGlobal_802DCA20_TAdMultiPlyChrSelectGC__data_804727B0_size[sizeof(RecoveredGlobal_802DCA20_TAdMultiPlyChrSelectGC__data_804727B0) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_802DCA20_lbl_804727E8_size[sizeof(RecoveredGlobal_802DCA20_lbl_804727E8) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_802DCA20_lbl_8050E3B8_size[sizeof(RecoveredGlobal_802DCA20_lbl_8050E3B8) == 0x1B0 ? 1 : -1];

void TAdMultiPlyChrSelectGC__sub_802DC8A0(void *arg0) {
    u32 i;
    s32 k;
    if (*(u32 *)((s8 *)arg0 + 0x80) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x80)))->close();
        *(u32 *)((s8 *)arg0 + 0x80) = 0U;
    }
    if (*(u32 *)((s8 *)arg0 + 0x84) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x84)))->close();
        *(u32 *)((s8 *)arg0 + 0x84) = 0U;
    }
    if (TWindowShortListCtrl__check_controller_button(((Ent_802DC8A0 *)controller_physical_port_bank)[get_instance__22TAdMultiPlyChrSelectGCFv(*(s32 *)((s8 *)arg0 + 0x5C))].d + 0x20, 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x28) = 0x1B;
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1A;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->get_mode() < 0x14) {
        if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->get_player_index() < 0xE) {
            *(u32 *)((s8 *)arg0 + 0x58) = 0U;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1D;
        return;
    }
    for (i = *(u32 *)((s8 *)arg0 + 0x58); i < 3; i++) {
        k = i + 4;
        *(s32 *)((s8 *)arg0 + 0x38) = k;
        load_tables(k);
        if (is_slot_active__23TAdSinglePlyChrSelectGCFUi(k) != 0) {
            ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x60)))->set_field_100(2);
            if (*(u32 *)((s8 *)arg0 + 0x70) != 0U) {
                allow_rendering__7TObjectFv((TObject *)(*(void **)((s8 *)arg0 + 0x70)));
            }
            ((TAdEnterSerialAccessGC *)(*(u32 *)((s8 *)arg0 + 0x70)))->reset_input_state();
            ((TLevelSelect *)(*(u32 *)((s8 *)arg0 + 0x70)))->add_item_rect(&((Pair_802DC8A0 *)&TAdMultiPlyChrSelectGC__character_slot_positions)[i]);
            ((TAdEnterSerialAccessGC *)(*(u32 *)((s8 *)arg0 + 0x70)))->set_active();
            *(u32 *)((s8 *)arg0 + 0x58) = i;
            *(s32 *)((s8 *)arg0 + 0x94) = TAdMultiPlyChrSelectGC__sub_802DBD64((s32)arg0);
            *(s32 *)((s8 *)arg0 + 0x20) = 0x20;
            return;
        }
    }
    *(s32 *)((s8 *)arg0 + 0x20) = 0x26;
}

void TAdMultiPlyChrSelectGC__sub_802DCA20(u8 *arg0) {
    ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x60)))->set_index_and_close_status(2);
    if (TWindowShortListCtrl__check_controller_button((void *)((void *) ((u8 *)&(*(RecoveredGlobal_802DCA20_lbl_8050E3B8 *)&controller_physical_port_bank).value + 0x20)), 2) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x28) = 0x1B;
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1A;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->get_mode() < 0x14) {
        if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->get_player_index() < 0xE) {
            *(s32 *)((s8 *)arg0 + 0x58) = 0;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1D;
        return;
    }
    ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->reset_cursor_state();
    TAdMultiPlyChrSelectGC__sub_802C5A44((int) (*(s32 *)((s8 *)arg0 + 0x5C)), &TAdMultiPlyChrSelectGC__character_slot_positions.value, 1);
    TAdMultiPlyChrSelectGC__sub_802C5A44((int) (*(s32 *)((s8 *)arg0 + 0x5C)), (void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 8), 1);
    TAdMultiPlyChrSelectGC__sub_802C5A44((int) (*(s32 *)((s8 *)arg0 + 0x5C)), (void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 0x10), 1);
    TAdMultiPlyChrSelectGC__sub_802C5A44((int) (*(s32 *)((s8 *)arg0 + 0x5C)), &multi_chr_select_item_rect_table.value, 2);
    TAdMultiPlyChrSelectGC__sub_802C5A44((int) (*(s32 *)((s8 *)arg0 + 0x5C)), (void *) ((u8 *)&multi_chr_select_item_rect_table.value + 8), 2);
    TAdMultiPlyChrSelectGC__sub_802C5A44((int) (*(s32 *)((s8 *)arg0 + 0x5C)), (void *) ((u8 *)&multi_chr_select_item_rect_table.value + 0x10), 2);
    TAdMultiPlyChrSelectGC__sub_802C5A44((int) (*(s32 *)((s8 *)arg0 + 0x5C)), (void *) ((u8 *)&multi_chr_select_item_rect_table.value + 0x18), 2);
    *(s32 *)((s8 *)arg0 + 0x20) = 0x1F;
}

}
