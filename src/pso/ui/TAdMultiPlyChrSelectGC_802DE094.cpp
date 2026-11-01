#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802DBCC4.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802DE094.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802E0064.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowMessageYesNo.h"
#include "pso/misc/TWindowOptionCtrl.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/ui/TAdChrSelASlotGC.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"

struct Stack_802DE7D0 {
    s32 sp8;
    s32 spC;
};

extern "C" {
s32 queue_destruction__7TObjectFv(void *);
s32 TWindowShortListCtrl__check_controller_button(void *, s32, s32);
s32 load_tables(s32);
u32 TAdSinglePlyChrSelectGC__sub_801FE4BC(s32);
s32 is_slot_active__23TAdSinglePlyChrSelectGCFUi(s32);
u32 check_flag__23TAdSinglePlyChrSelectGCFl(s32);
s32 play_sound_effect(s32, s32, s32, s32);
u32 __nw__7TObjectFUl(s32);
s32 TAdMultiPlyChrSelectGC__sub_802C561C(s32);
s32 TAdMultiPlyChrSelectGC__sub_802C5688(s32);
s32 is_multiplayer_character_slot_selected(s32);
s32 TAdMultiPlyChrSelectGC__sub_802C6558();
s32 TAdMultiPlyChrSelectGC__sub_802C65C0(s32);
s32 TAdMultiPlyChrSelectGC__sub_802C6848(s32);
s32 TAdMultiPlyChrSelectGC__sub_802C6920();
u32 __ct__9TAdFadeGCFP7TObjectPv(u32, s32, s32);
u32 create_choice_menu__22TAdMultiPlyChrSelectGCFv(void *);
s32 TAdMultiPlyChrSelectGC__sub_802DC294(void *, s32);
s32 TAdMultiPlyChrSelectGC__sub_802DFFE8(s32);
s32 TAdMultiPlyChrSelectGC__sub_802E0024(s32, s32);
s32 restore_selection__22TAdMultiPlyChrSelectGCFv(s32);
s32 TAdChrSelASlotGC__sub_8030C3C0(u32, s32);
u32 TAdChrSelASlotGC__sub_8030CA84(u32, s32 *);
extern s32 lbl_80472850[];
extern s32 lbl_80472858[];
extern s32 controller_physical_port_bank[];
extern s32 tl_fade;
s32 destroy_windows__14TAdGameStartGCFPv(s32);
s32 set_entry_value__22TAdMultiPlyChrSelectGCFlUl(s32, s32, s32 *);
s32 clear_entry__23TAdSinglePlyChrSelectGCFi();
void clear_slot_body__23TAdSinglePlyChrSelectGCFi(s32 i);
u8 *get_or_create_slot_window__22TAdMultiPlyChrSelectGCFii(s32 arg0, s32 arg1);
s32 create__16TAdChrSelBSlotGCFPv(void *);

extern s32 TAdMultiPlyChrSelectGC__data_805DE898;

void TAdMultiPlyChrSelectGC::open_windows() {
    destroy_windows__14TAdGameStartGCFPv(*(s32 *)((s8 *)this + 0x78));
    TAdMultiPlyChrSelectGC::set_select_mode(this->m_5c, 1);
    ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x60)))->set_index_and_close_status(1);
    *(s32 *)((s8 *)this + 0x68) = (s32)get_or_create_slot_window__22TAdMultiPlyChrSelectGCFii((s32)this, 2);
    this->m_6c = create__16TAdChrSelBSlotGCFPv(this);
    set_entry_value__22TAdMultiPlyChrSelectGCFlUl(this->m_64, 0, &TAdMultiPlyChrSelectGC__data_805DE898);
    set_entry_value__22TAdMultiPlyChrSelectGCFlUl(this->m_64, 1, &TAdMultiPlyChrSelectGC__data_805DE898);
    this->m_20 = 0xC;
}

void TAdMultiPlyChrSelectGC::init_windows() {
    if ((u32) this->m_7c != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x7C)))->close();
        this->m_7c = 0U;
    }
    TAdMultiPlyChrSelectGC__sub_802E006C((u8 *)this->m_5c, 2, 2);
    ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_field_4ec((s32)((void*)(2)));
    ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_state(1);
    ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x60)))->set_field_100(1);
    *(s32 *)((s8 *)this + 0x50) = 1;
    this->m_54 = 0;
    open_windows();
}

void TAdMultiPlyChrSelectGC::open_char_select() { ((TAdMultiPlyChrSelectGC *)(*(void**)((char*)this + 0x5c)))->set_field_4ec((s32)((void*)((void*)2))); TAdMultiPlyChrSelectGC__sub_802E006C((u8 *)(*(void**)((char*)this + 0x5c)), (s32)((void*)2), (s32)((void*)2)); ((TAdMultiPlyChrSelectGC *)(*(void**)((char*)this + 0x5c)))->set_state_ready(); open_windows(); }

void TAdMultiPlyChrSelectGC::close_windows() {
    if ((u32) this->m_7c != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x7C)))->close();
        this->m_7c = 0U;
    }
    if ((u32) this->m_8c != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x8C)))->close();
        this->m_8c = 0U;
    }
    if ((u32) this->m_74 != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x74));
        this->m_74 = 0U;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x68)))->get_player_index() == 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        this->m_20 = 0;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x68)))->get_player_index() == 1) {
        this->m_20 = 0;
    }
}

void update__22TAdMultiPlyChrSelectGCFPv(void *arg0) {

    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->get_player_index() == 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        *(s32 *)((s8 *)arg0 + 0x20) = 0;
        return;
    }
    if (TAdMultiPlyChrSelectGC__sub_802C6848(TAdMultiPlyChrSelectGC::get_clamped_cursor()) == 0) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->set_state_ready();
        *(s32 *)((s8 *)arg0 + 0x20) = 3;
        return;
    }
    if (((TWindowSubComCard *)(*(s32 *)((s8 *)arg0 + 0x8C)))->get_card_data() != 0) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->set_state_ready();
        *(s32 *)((s8 *)arg0 + 0x20) = 3;
        return;
    }
    if (((TWindowMessageYesNo *)(*(s32 *)((s8 *)arg0 + 0x8C)))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(*(s32 *)((s8 *)arg0 + 0x8C)))->get_slot_or_neg1()) {
        case 1:
            ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->set_state_ready();
            *(s32 *)((s8 *)arg0 + 0x20) = 3;
            return;
        case 0:
            TAdMultiPlyChrSelectGC__sub_802DFFE8((s32)(*(s32 *)((s8 *)arg0 + 0x5C)));
            clear_entry__23TAdSinglePlyChrSelectGCFi();
            ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->set_cursor_index(0xF);
            ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->set_state_ready();
            *(s32 *)((s8 *)arg0 + 0x20) = 8;
            break;
        }
    }
}

void TAdMultiPlyChrSelectGC::update_card_select() {

    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x68)))->get_player_index() == 1) {
        if ((u32) *(u32 *)((s8 *)this + 0x7C) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)this + 0x7C)))->close();
            *(u32 *)((s8 *)this + 0x7C) = 0U;
        }
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        *(s32 *)((s8 *)this + 0x20) = 0;
        return;
    }
    if (TAdMultiPlyChrSelectGC__sub_802C6848(TAdMultiPlyChrSelectGC::get_clamped_cursor()) == 0) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x5C)))->set_state_ready();
        *(s32 *)((s8 *)this + 0x20) = 3;
        return;
    }
    if (((TWindowSubComCard *)(*(u32 *)((s8 *)this + 0x98)))->get_card_data() != 0) {
        ((TWindowSubComCard *)(*(u32 *)((s8 *)this + 0x7C)))->clear_transition_flag();
        ((TWindowSubComCard *)(*(u32 *)((s8 *)this + 0x7C)))->clear_flag_and_release();
        if ((u32) *(u32 *)((s8 *)this + 0x98) != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x98)))->close();
            *(u32 *)((s8 *)this + 0x98) = 0U;
        }
        *(s32 *)((s8 *)this + 0x20) = 5;
        return;
    }
    if (((TWindowMessageYesNo *)(*(u32 *)((s8 *)this + 0x98)))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(*(u32 *)((s8 *)this + 0x98)))->get_slot_or_neg1()) {
        case 1:
            ((TWindowSubComCard *)(*(u32 *)((s8 *)this + 0x7C)))->clear_transition_flag();
            ((TWindowSubComCard *)(*(u32 *)((s8 *)this + 0x7C)))->clear_flag_and_release();
            if ((u32) *(u32 *)((s8 *)this + 0x98) != 0U) {
                ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x98)))->close();
                *(u32 *)((s8 *)this + 0x98) = 0U;
            }
            *(s32 *)((s8 *)this + 0x20) = 5;
            return;
        case 0:
            if ((u32) *(u32 *)((s8 *)this + 0x98) != 0U) {
                ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x98)))->close();
                *(u32 *)((s8 *)this + 0x98) = 0U;
            }
            clear_slot_body__23TAdSinglePlyChrSelectGCFi(TAdMultiPlyChrSelectGC__sub_802DFFE8((s32)(*(s32 *)((s8 *)this + 0x5C))) + 4);
            ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x68)))->set_cursor_index(0xF);
            *(s32 *)((s8 *)this + 0x20) = 8;
            break;
        }
    }
}

void TAdMultiPlyChrSelectGC::update_state_option() {
    s32 selected_menu_value;

    if (((TAdMultiPlyChrSelectGC *)(*(u32 *)((s8 *)this + 0x68)))->get_player_index() == 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        *(s32 *)((s8 *)this + 0x20) = 0;
        return;
    }
    if (TAdMultiPlyChrSelectGC__sub_802C6848(TAdMultiPlyChrSelectGC::get_clamped_cursor()) == 0) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x5C)))->set_state_ready();
        *(s32 *)((s8 *)this + 0x20) = 3;
        return;
    }
    if (((TWindowMenu *)(*(s32 *)((s8 *)this + 0x7C)))->is_cancelled() != 0) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x5C)))->set_state_ready();
        *(s32 *)((s8 *)this + 0x20) = 3;
        return;
    }
    if (((TWindowMenu *)(*(s32 *)((s8 *)this + 0x7C)))->is_decided() != 0) {
        selected_menu_value = ((TWindowMenu *)(*(s32 *)((s8 *)this + 0x7C)))->get_selected_value();
        switch (selected_menu_value) {
        case 0:
            play_sound_effect(0x52D01, 0, 0, 0);
            TAdMultiPlyChrSelectGC__sub_802C561C(*(s32 *)((s8 *)this + 0x5C));
            TAdMultiPlyChrSelectGC__sub_802C5688(*(s32 *)((s8 *)this + 0x5C));
            *(s32 *)((s8 *)this + 0x20) = 0x19;
            return;
        case 1:
            play_sound_effect(0x52D01, 0, 0, 0);
            ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x5C)))->update_field_4E8();
            restore_selection__22TAdMultiPlyChrSelectGCFv(*(s32 *)((s8 *)this + 0x5C));
            TAdMultiPlyChrSelectGC__sub_802C5688(*(s32 *)((s8 *)this + 0x5C));
            ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x5C)))->set_state_ready();
            if ((u32) *(u32 *)((s8 *)this + 0x68) != 0U) {
                queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x68));
                *(u32 *)((s8 *)this + 0x68) = 0U;
            }
            *(s32 *)((s8 *)this + 0x20) = 0xA;
            return;
        case 2:
            ((TWindowOptionCtrl *)(*(s32 *)((s8 *)this + 0x7C)))->open();
            *(s32 *)((s8 *)this + 0x98) = TAdMultiPlyChrSelectGC__sub_802DBCE8((s32)this);
            *(s32 *)((s8 *)this + 0x20) = 6;
            return;
        case 3:
            ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x5C)))->set_state_ready();
            *(s32 *)((s8 *)this + 0x20) = 3;
            break;
        }
    }
}

extern s32 lbl_805D68C8;

void TAdMultiPlyChrSelectGC::update_card_confirm() {

    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x68)))->get_player_index() == 1) {
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        *(s32 *)((s8 *)this + 0x20) = 0;
        return;
    }
    if (TAdMultiPlyChrSelectGC__sub_802C6848(TAdMultiPlyChrSelectGC::get_clamped_cursor()) == 0) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x5C)))->set_state_ready();
        *(s32 *)((s8 *)this + 0x20) = 3;
        return;
    }
    if (((TWindowSubComCard *)(*(u32 *)((s8 *)this + 0x90)))->get_card_data() != 0) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x5C)))->set_state_ready();
        *(s32 *)((s8 *)this + 0x20) = 3;
        return;
    }
    if (((TWindowMessageYesNo *)(*(u32 *)((s8 *)this + 0x90)))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(*(u32 *)((s8 *)this + 0x90)))->get_slot_or_neg1()) {
        case 1:
            ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x5C)))->set_state_ready();
            *(s32 *)((s8 *)this + 0x20) = 3;
            return;
        case 0:
            play_sound_effect(0x52D01, 0, 0, 0);
            TAdMultiPlyChrSelectGC__sub_802C561C(*(s32 *)((s8 *)this + 0x5C));
            TAdMultiPlyChrSelectGC__sub_802C5688(*(s32 *)((s8 *)this + 0x5C));
            lbl_805D68C8 = 1;
            if ((u32) *(u32 *)((s8 *)this + 0x90) != 0U) {
                ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x90)))->close();
                *(u32 *)((s8 *)this + 0x90) = 0U;
            }
            *(s32 *)((s8 *)this + 0x28) = 0x1C;
            *(s32 *)((s8 *)this + 0x20) = 0x1A;
            *(s32 *)((s8 *)this + 0x2C) = 0;
            break;
        }
    }
}
void TAdMultiPlyChrSelectGC__sub_802DE7D0(void *ad_multi_ply_chr_select_gc) {
    Stack_802DE7D0 stack;
    s32 temp_r30;
    s32 temp_r30_2;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 var_r30;
    s32 var_r3;
    u32 var_r0;
    if ((u32) *(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x90) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_multi_ply_chr_select_gc + 0x90)))->close();
        *(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x90) = 0U;
    }
    if ((u32) ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_8c != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_multi_ply_chr_select_gc + 0x8C)))->close();
        ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_8c = 0U;
    }
    if ((u32) ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_7c != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_multi_ply_chr_select_gc + 0x7C)))->close();
        ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_7c = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x98) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_multi_ply_chr_select_gc + 0x98)))->close();
        *(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x98) = 0U;
    }
    if ((u32) ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_74 != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)ad_multi_ply_chr_select_gc + 0x74));
        ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_74 = 0U;
    }
    if (TAdMultiPlyChrSelectGC__sub_802C6558() > 0) {
        temp_r5 = TAdMultiPlyChrSelectGC__sub_802C6920() * 0x50;
        var_r3 = TWindowShortListCtrl__check_controller_button((s8 *)controller_physical_port_bank + temp_r5 + 0x20, 2, temp_r5);
    } else {
        temp_r5_2 = ((s32)TAdMultiPlyChrSelectGC::get_clamped_cursor()) * 0x50;
        var_r3 = TWindowShortListCtrl__check_controller_button((s8 *)controller_physical_port_bank + temp_r5_2 + 0x20, 2, temp_r5_2);
    }
    if (var_r3 != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if (TAdMultiPlyChrSelectGC__sub_802C6558() > 0) {
            TAdMultiPlyChrSelectGC::split_slot_index(TAdMultiPlyChrSelectGC__sub_802C6920(), &stack.spC, &stack.sp8);
            TAdMultiPlyChrSelectGC::init();
            ((TAdMultiPlyChrSelectGC *)(((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_5c))->set_field_4ec(stack.spC);
            TAdMultiPlyChrSelectGC__sub_802E0024(((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_5c, stack.sp8);
            return;
        }
        if (TAdMultiPlyChrSelectGC::get_chr_select_state() == 0) {
            ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 0x1B;
        }
    } else {
        var_r30 = 0;
        do {
            if ((is_multiplayer_character_slot_selected(var_r30) != 0) && (TAdMultiPlyChrSelectGC__sub_802C6848(var_r30) == 0)) {
                TAdMultiPlyChrSelectGC__sub_802C65C0(var_r30);
            }
            var_r30 += 1;
        } while (var_r30 < 4);
        if (((TAdMultiPlyChrSelectGC *)(*(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x68)))->get_player_index() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
            ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 0;
            return;
        }
        temp_r30 = TAdMultiPlyChrSelectGC__sub_802DC294(ad_multi_ply_chr_select_gc, ((TAdMultiPlyChrSelectGC *)(((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_5c))->get_cursor());
        if (((s32) *(s32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x30) != TAdMultiPlyChrSelectGC__sub_802DFFE8(((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_5c)) || ((s32) ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_34 != ((TAdMultiPlyChrSelectGC *)(((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_5c))->get_cursor())) {
            ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x60)))->set_field_100(1);
            ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_40 = 0;
            if (TAdSinglePlyChrSelectGC__sub_801FE4BC(temp_r30) != 0U) {
                load_tables(temp_r30);
                ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x60)))->set_field_100(2);
                if ((check_flag__23TAdSinglePlyChrSelectGCFl(1) != 0U) && ((s32) ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_3c != 0)) {
                    ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_40 = 1;
                }
            }
            *(s32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x30) = TAdMultiPlyChrSelectGC__sub_802DFFE8(((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_5c);
            ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_34 = ((TAdMultiPlyChrSelectGC *)(((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_5c))->get_cursor();
        }
        if (((TAdMultiPlyChrSelectGC *)(((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_5c))->get_selection() != 0) {
            load_tables(temp_r30);
            if (((TAdMultiPlyChrSelectGC *)(((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_5c))->get_cursor() == 1) {
                if (is_slot_active__23TAdSinglePlyChrSelectGCFUi(temp_r30) == 0) {
                    play_sound_effect(0x52D01, 0, 0, 0);
                    ((TAdMultiPlyChrSelectGC *)(((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_5c))->update_field_4E8();
                    restore_selection__22TAdMultiPlyChrSelectGCFv(((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_5c);
                    TAdMultiPlyChrSelectGC__sub_802C5688(((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_5c);
                    if ((u32) *(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x68) != 0U) {
                        queue_destruction__7TObjectFv(*(void **)((s8 *)ad_multi_ply_chr_select_gc + 0x68));
                        *(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x68) = 0U;
                    }
                    ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 9;
                    return;
                }
                ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_7c = create_choice_menu__22TAdMultiPlyChrSelectGCFv(ad_multi_ply_chr_select_gc);
                ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 5;
                return;
            }
            if (is_slot_active__23TAdSinglePlyChrSelectGCFUi(temp_r30) != 0) {
                if (TAdChrSelASlotGC__sub_8030C3C0(*(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x68), TAdMultiPlyChrSelectGC__sub_802DFFE8(((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_5c)) != 0) {
                    var_r0 = __nw__7TObjectFUl(0x38);
                    if (var_r0 != 0U) {
                        var_r0 = __ct__9TAdFadeGCFP7TObjectPv(var_r0, tl_fade, 0);
                    }
                    ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_74 = var_r0;
                    ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_8c = TAdChrSelASlotGC::open_yes_no_window((s32)(*(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x68)), (s32)((s32 *)&lbl_80472850), (s32)(((s32)TAdMultiPlyChrSelectGC::get_clamped_cursor())));
                    ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 7;
                    return;
                }
                play_sound_effect(0x52D01, 0, 0, 0);
                TAdMultiPlyChrSelectGC__sub_802C561C(((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_5c);
                TAdMultiPlyChrSelectGC__sub_802C5688(((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_5c);
                ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 0x19;
                return;
            }
            *(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x90) = TAdChrSelASlotGC__sub_8030CA84(*(u32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x68), lbl_80472858);
            ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 4;
            return;
        }
        if ((((TAdMultiPlyChrSelectGC *)(((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_5c))->get_field_0x530() != 0) && (TAdMultiPlyChrSelectGC__sub_802C6558() > 1) && (is_multiplayer_character_slot_selected(0) != 0)) {
            *(s32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x28) = 0x1C;
            ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 0x1A;
            *(s32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x2C) = 1;
            return;
        }
        if ((TAdMultiPlyChrSelectGC::count_ready() == TAdMultiPlyChrSelectGC__sub_802C6558()) && (is_multiplayer_character_slot_selected(0) != 0) && (TAdMultiPlyChrSelectGC__sub_802C6558() > 1)) {
            *(s32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x28) = 0x1C;
            ((TAdMultiPlyChrSelectGC *)ad_multi_ply_chr_select_gc)->m_20 = 0x1A;
            *(s32 *)((s8 *)ad_multi_ply_chr_select_gc + 0x2C) = 1;
        }
    }
}

}
