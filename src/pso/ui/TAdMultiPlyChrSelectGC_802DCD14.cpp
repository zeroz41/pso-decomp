#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802DCD14.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/TAdMultiChgGameModeGC.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/ui/TAdChrMoveEffectGC.h"

struct RecoveredGlobal_802DD400_lbl_8050E3B8 {
    s32 value;
    u8 remaining[0x1AC];
};

extern "C" {
s32 TAdPlyPltAnimCtrlGC__sub_80355148();
extern const f32 lbl_805DE89C;
s32 queue_destruction__7TObjectFv(void *);
s32 TWindowShortListCtrl__check_controller_button(void *, s32, s32);
s32 play_sound_effect(s32, s32, s32, s32);
s32 get_instance__22TAdMultiPlyChrSelectGCFv(s32);
extern s8 controller_physical_port_bank[];
s32 clear_entries__18TAdChrMoveEffectGCFv();
s32 create_effects__14TAdGameStartGCFPv(s32);
s32 is_multiplayer_character_slot_selected(s32);
s32 TAdMultiPlyChrSelectGC__sub_802C6558();
u32 TAdMultiPlyChrSelectGC__sub_802DBE4C(void *, s32 *);
s32 TAdMultiPlyChrSelectGC__sub_802DBEC4(void *, s32 *);
s32 TAdMultiPlyChrSelectGC__sub_802DC294(void *, s32);
s32 TAdMultiPlyChrSelectGC__sub_802E0024(s32, u32);
s32 get_card_index__22TAdMultiPlyChrSelectGCFv(s32, s32);
s32 load_tables();
s32 swap_characters__23TAdSinglePlyChrSelectGCFii(u32, s32);

void TAdMultiPlyChrSelectGC__sub_802DCD14(void *arg0) {

    TAdMultiPlyChrSelectGC::reset_slot_selections();
    switch (*(s32 *)((s8 *)arg0 + 0x48)) {
    case 0:
        if (TAdMultiPlyChrSelectGC::get_chr_select_state() != 0) {
            TAdMultiChgGameModeGC::begin_change_game_mode();
            return;
        }
        TAdMultiChgGameModeGC::set_game_mode_state();
        return;
    case 1:
        TAdMultiChgGameModeGC::request_scene_change();
        return;
    case 2:
        TAdMultiChgGameModeGC::begin_change_game_mode();
        return;
    }
}

void TAdMultiPlyChrSelectGC::update_idle_timer() {
    s32 temp_r4;
    temp_r4 = *(s32 *)&this->m_1c + 1;
    *(s32 *)&this->m_1c = temp_r4;
    if (((f32) temp_r4 > lbl_805DE89C) && (TAdMultiPlyChrSelectGC::get_selected_slot() != 0U) && (TAdPlyPltAnimCtrlGC__sub_80355148() == 0)) {
        *(s32 *)&this->m_20 = (s32) *(s32 *)&this->unk_28;
    }
}

void TAdMultiPlyChrSelectGC::update_confirm_start() {
    s32 temp_r31;
    s32 temp_r3;

    if ((((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->unk_78))->get_ready_state() == 0) && (TAdMultiPlyChrSelectGC__sub_802C6558() > 1) && (is_multiplayer_character_slot_selected(0) != 0)) {
        temp_r31 = TAdMultiPlyChrSelectGC::count_ready();
        temp_r3 = TAdMultiPlyChrSelectGC__sub_802C6558();
        if (temp_r3 != temp_r31) {
            create_effects__14TAdGameStartGCFPv(*(s32 *)&this->unk_78);
        }
    }
    ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_state_ready();
    *(s32 *)&this->m_20 = 3;
}

void TAdMultiPlyChrSelectGC::handle_cancel_state() {
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
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() == 0x1D) {
        *(s32 *)&this->unk_50 = 0;
        this->m_54 = 1;
        ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_state_ready();
        if ((u32) *(u32 *)&this->unk_68 != 0U) {
            queue_destruction__7TObjectFv(*(void * *)&this->unk_68);
            *(u32 *)&this->unk_68 = 0U;
        }
        *(s32 *)&this->m_20 = 0xB;
    }
}

void TAdMultiPlyChrSelectGC__sub_802DCF68(void *arg0) {
    s32 temp_r5;
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->get_mode() > 1) {
        temp_r5 = get_instance__22TAdMultiPlyChrSelectGCFv(*(s32 *)((s8 *)arg0 + 0x5C)) * 0x50;
        if (TWindowShortListCtrl__check_controller_button(controller_physical_port_bank + temp_r5 + 0x20, 2, temp_r5) == 0) {
            return;
        }
    }
    {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x68) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x68));
            *(u32 *)((s8 *)arg0 + 0x68) = 0U;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
    }
}

void TAdMultiPlyChrSelectGC__sub_802DD010(void *arg0) {
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->get_mode() <= 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x68) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x68));
            *(u32 *)((s8 *)arg0 + 0x68) = 0U;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(u32 *)((s8 *)arg0 + 0x68)))->get_player_index() == 0x14) {
        *(s32 *)((s8 *)arg0 + 0x20) = 0x18;
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->set_field_1c(0x1B);
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(u32 *)((s8 *)arg0 + 0x68)))->get_player_index() == 0x13) {
        if ((u32) *(u32 *)((s8 *)arg0 + 0x80) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x80));
            *(u32 *)((s8 *)arg0 + 0x80) = 0U;
        }
        if (TAdMultiPlyChrSelectGC::get_global_state() != 0U) {
            clear_entries__18TAdChrMoveEffectGCFv();
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x17;
    }
}

extern s32 lbl_80472870[];
extern s32 lbl_80472878[];

void TAdMultiPlyChrSelectGC::update_state_move() {
    s32 iter;
    u32 temp_u;
    s32 temp_r5;
    s32 ret;
    s32 temp_r3;

    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() <= 1) {
        *(s32 *)&this->m_20 = 0xC;
        return;
    }
    temp_r5 = get_instance__22TAdMultiPlyChrSelectGCFv(this->m_5c) * 0x50;
    if (TWindowShortListCtrl__check_controller_button(controller_physical_port_bank + temp_r5 + 0x20, 2, temp_r5) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) *(u32 *)&this->unk_68 != 0U) {
            queue_destruction__7TObjectFv(*(void * *)&this->unk_68);
            *(u32 *)&this->unk_68 = 0U;
        }
        *(s32 *)&this->m_20 = 0xB;
        return;
    }
    iter = 0;
loop_7:
    ret = get_card_index__22TAdMultiPlyChrSelectGCFv(this->m_5c, 1);
    if (swap_characters__23TAdSinglePlyChrSelectGCFii((u32)iter, ret + 4) == 1) {
        if ((u32) this->m_84 != 0U) {
            ((TWindowBase *)(*(void * *)&this->m_84))->close();
            this->m_84 = 0U;
        }
        temp_u = TAdMultiPlyChrSelectGC::get_global_state();
        if (temp_u != 0U) {
            ((TAdChrMoveEffectGC *)temp_u)->setup_move_effect_params(ret, (u32)iter + 3);
        }
        TAdMultiPlyChrSelectGC__sub_802E0024(this->m_5c, (u32)iter);
        ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_state(1);
        temp_r3 = TAdMultiPlyChrSelectGC__sub_802DC294(this, ((TAdMultiPlyChrSelectGC *)(this->m_5c))->get_cursor());
        load_tables();
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->unk_60))->set_status_value(temp_r3);
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->unk_60))->set_field_100(2);
        *(s32 *)&this->unk_80 = TAdMultiPlyChrSelectGC__sub_802DBEC4(this, lbl_80472870);
        ((TAdMultiPlyChrSelectGC *)(*(u32 *)&this->unk_68))->set_cursor_index(0x11);
        *(s32 *)&this->m_20 = 0x16;
        return;
    }
    iter += 1;
    if ((u32)iter >= 4U) {
        this->m_54 = 0;
        if ((u32) this->m_84 == 0U) {
            this->m_84 = TAdMultiPlyChrSelectGC__sub_802DBE4C(this, lbl_80472878);
        }
        *(s32 *)&this->m_20 = 0xE;
        return;
    }
    goto loop_7;
}

void TAdMultiPlyChrSelectGC__sub_802DD2B0(void *arg0) {
    void *temp_r3;
    temp_r3 = *(void **)((s8 *)arg0 + 0x8C);
    if ((u32) temp_r3 != 0U) {
        ((TWindowSubComCard *)temp_r3)->close();
        *(u32 *)((s8 *)arg0 + 0x8C) = 0U;
    }
    temp_r3 = *(void **)((s8 *)arg0 + 0x74);
    if ((u32) temp_r3 != 0U) {
        queue_destruction__7TObjectFv(temp_r3);
        *(u32 *)((s8 *)arg0 + 0x74) = 0U;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->get_mode() == 1) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->set_state_ready();
        *(s32 *)((s8 *)arg0 + 0x20) = 0xC;
    }
}

void TAdMultiPlyChrSelectGC::handle_confirm_state() {
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() <= 1) {
        if (((TAdMultiPlyChrSelectGC *)(*(u32 *)&this->unk_68))->get_player_index() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
        }
        ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)&this->unk_50 = 0;
        if ((u32) *(u32 *)&this->unk_68 != 0U) {
            queue_destruction__7TObjectFv(*(void * *)&this->unk_68);
            *(u32 *)&this->unk_68 = 0U;
        }
        *(s32 *)&this->m_20 = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(u32 *)&this->unk_68))->get_player_index() == 1) {
        *(s32 *)&this->unk_50 = 0;
        this->m_54 = 1;
        if ((u32) *(u32 *)&this->unk_68 != 0U) {
            queue_destruction__7TObjectFv(*(void * *)&this->unk_68);
            *(u32 *)&this->unk_68 = 0U;
        }
        *(s32 *)&this->m_20 = 0xB;
    }
}
typedef char RecoveredGlobal_802DD400_lbl_8050E3B8_size[sizeof(RecoveredGlobal_802DD400_lbl_8050E3B8) == 0x1B0 ? 1 : -1];
void TAdMultiPlyChrSelectGC__sub_802DD400(u8 *arg0) {
    s32 temp_r5;
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->get_mode() > 1) {
        temp_r5 = get_instance__22TAdMultiPlyChrSelectGCFv((s32)((int) (*(s32 *)((s8 *)arg0 + 0x5C)))) * 0x50;
        if (TWindowShortListCtrl__check_controller_button((void *)((void *) ((u8 *)&(*(RecoveredGlobal_802DD400_lbl_8050E3B8 *)&controller_physical_port_bank).value + temp_r5 + 0x20)), 2, temp_r5) != 0) {
            goto block_2;
        }
    } else {
block_2:
        if (((TAdMultiPlyChrSelectGC *)(*(u32 *)((s8 *)arg0 + 0x68)))->get_player_index() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
        }
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->set_state_ready();
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x68) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x68));
            *(u32 *)((s8 *)arg0 + 0x68) = 0U;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
    }
}

}
