#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"

extern "C" {

s32 TAdMultiPlyChrSelectGC__sub_802C6848();
s32 TAdMultiPlyChrSelectGC__sub_802DBEC4(void *, s32 *);
s32 play_sound_effect(s32, s32, s32, s32);
s32 TAdMultiPlyChrSelectGC__sub_802DFFE8(s32);
s32 get_card_index__22TAdMultiPlyChrSelectGCFv(s32, s32);

extern s32 lbl_80472868[];

void TAdMultiPlyChrSelectGC::update_state_wait_card() {
    s32 temp_r31;
    s32 temp_r3_2;

    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() <= 1) {
        play_sound_effect(0x52F16, 0, 0, 0);
        ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_state_ready();
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
        *(s32 *)&this->m_20 = 0xC;
        return;
    }
    if (((TWindowSubComCard *)(*(s32 *)&this->unk_88))->get_card_data() != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_state_ready();
        *(s32 *)&this->m_20 = 0xC;
        return;
    }
    if (((TWindowMessageYesNo *)(*(s32 *)&this->unk_88))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(*(s32 *)&this->unk_88))->get_slot_or_neg1()) {
        case 1:
            ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_state_ready();
            *(s32 *)&this->m_20 = 0xC;
            return;
        case 0:
            temp_r31 = TAdMultiPlyChrSelectGC__sub_802DFFE8(this->m_5c);
            temp_r3_2 = get_card_index__22TAdMultiPlyChrSelectGCFv(this->m_5c, 1);
            if (try_move_char__23TAdSinglePlyChrSelectGCFii(temp_r3_2 + 4, temp_r31) != 0) {
                {
                    u32 temp_u0 = TAdMultiPlyChrSelectGC::get_global_state();
                    if (temp_u0 != 0U) {
                        ((TAdChrMoveEffectGC *)temp_u0)->setup_move_effect_params(temp_r31 + 3, temp_r3_2);
                    }
                }
                *(s32 *)&this->unk_80 = TAdMultiPlyChrSelectGC__sub_802DBEC4(this, lbl_80472868);
                ((TAdMultiPlyChrSelectGC *)(this->m_6c))->set_field_1c(0x15);
                *(s32 *)&this->m_20 = 0x11;
                return;
            }
            ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_state_ready();
            *(s32 *)&this->m_20 = 0xC;
            break;
        }
    }
}

}
