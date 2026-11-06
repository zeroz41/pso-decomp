#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowSubComCard.h"

extern "C" {

s32 clear_entries__18TAdChrMoveEffectGCFv();
s32 TAdMultiPlyChrSelectGC__sub_802C6848();
s32 TAdMultiPlyChrSelectGC__sub_802DFFE8(s32);
s32 clear_slot_entry__23TAdSinglePlyChrSelectGCFi();
s32 play_sound_effect(s32, s32, s32, s32);

void TAdMultiPlyChrSelectGC::update_state() {
    if ((u32) *(u32 *)&this->unk_88 != 0U) {
        queue_destruction__7TObjectFv(*(void * *)&this->unk_88);
        *(u32 *)&this->unk_88 = 0U;
    }
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() <= 1) {
        if (((TAdMultiPlyChrSelectGC *)(*(u32 *)&this->unk_68))->get_player_index() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
        }
        ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) *(u32 *)&this->unk_68 != 0U) {
            queue_destruction__7TObjectFv(*(void * *)&this->unk_68);
            *(u32 *)&this->unk_68 = 0U;
        }
        *(s32 *)&this->m_20 = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() == 0x19) {
        ((TAdMultiPlyChrSelectGC *)(*(u32 *)&this->unk_68))->set_cursor_index(0xF);
        *(s32 *)&this->m_20 = 0x13;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() == 0x18) {
        if ((u32) *(u32 *)&this->unk_80 != 0U) {
            queue_destruction__7TObjectFv(*(void * *)&this->unk_80);
            *(u32 *)&this->unk_80 = 0U;
        }
        if (TAdMultiPlyChrSelectGC::get_global_state() != 0U) {
            clear_entries__18TAdChrMoveEffectGCFv();
        }
        *(s32 *)&this->m_20 = 0x12;
    }
}

void TAdMultiPlyChrSelectGC::update_card_select_state() {

    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() <= 1) {
        ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        if (((TAdMultiPlyChrSelectGC *)(*(u32 *)&this->unk_68))->get_player_index() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
            if ((u32) *(u32 *)&this->unk_68 != 0U) {
                queue_destruction__7TObjectFv(*(void * *)&this->unk_68);
                *(u32 *)&this->unk_68 = 0U;
            }
            *(s32 *)&this->m_20 = 0xB;
            return;
        }
        *(s32 *)&this->m_20 = 0xC;
        return;
    }
    TAdMultiPlyChrSelectGC::get_card_instance();
    TAdMultiPlyChrSelectGC::get_instance();
    if (TAdMultiPlyChrSelectGC__sub_802C6848() == 0) {
        ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_state_ready();
        *(s32 *)&this->m_20 = 0xE;
        return;
    }
    if (((TWindowSubComCard *)(this->m_8c))->get_card_data() != 0) {
        ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_state_ready();
        *(s32 *)&this->m_20 = 0xE;
        return;
    }
    if (((TWindowMessageYesNo *)(this->m_8c))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(this->m_8c))->get_slot_or_neg1()) {
        case 1:
            ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_state_ready();
            *(s32 *)&this->m_20 = 0xE;
            return;
        case 0:
            TAdMultiPlyChrSelectGC__sub_802DFFE8(this->m_5c);
            clear_slot_entry__23TAdSinglePlyChrSelectGCFi();
            ((TAdMultiPlyChrSelectGC *)(this->m_6c))->set_field_1c(0x16);
            *(s32 *)&this->m_20 = 0x14;
            break;
        }
    }
}

}
