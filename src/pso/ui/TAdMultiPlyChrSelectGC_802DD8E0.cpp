#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802DD8E0.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/ui/TAdChrSelASlotGC.h"

struct Stack_802DDF40 {
    s32 sp8;
    s32 spC;
};

struct RecoveredGlobal_802DDD08_TAdMultiPlyChrSelectGC__data_804727B0 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_802DDD08_lbl_8050E3B8 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_802DDBA8_lbl_804727E8 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_802DDBA8_lbl_8050E3B8 {
    s32 value;
    u8 remaining[0x1AC];
};

extern "C" {
s32 queue_destruction__7TObjectFv(void *);
s32 is_slot_active__23TAdSinglePlyChrSelectGCFUi();
s32 is_multiplayer_character_slot_selected(s32);
s32 TAdMultiPlyChrSelectGC__sub_802C6558();
s32 TAdMultiPlyChrSelectGC__sub_802C658C();
s32 TAdMultiPlyChrSelectGC__sub_802C6920();
s32 TAdMultiPlyChrSelectGC__sub_802E0024(s32, s32);
s32 create_effects__14TAdGameStartGCFPv(s32);
s32 get_or_create_slot_window__22TAdMultiPlyChrSelectGCFii(void *, s32);
s32 clear_entries__18TAdChrMoveEffectGCFv();
s32 TWindowShortListCtrl__check_controller_button(void *, s32, s32);
s32 play_sound_effect(s32, s32, s32, s32);
s32 get_instance__22TAdMultiPlyChrSelectGCFv(s32);
extern RecoveredGlobal_802DDD08_TAdMultiPlyChrSelectGC__data_804727B0 TAdMultiPlyChrSelectGC__character_slot_positions;
extern s32 controller_physical_port_bank[];
s32 TAdMultiPlyChrSelectGC__sub_802C5A44(int, void *, int);
extern RecoveredGlobal_802DDBA8_lbl_804727E8 multi_chr_select_item_rect_table;
s32 is_slot_state_one__16TAdChrSelBSlotGCFlUl(s32, s32);
s32 create_confirm_window__22TAdMultiPlyChrSelectGCFv(void *, s32);
s32 TAdMultiPlyChrSelectGC__sub_802DC294(void *, s32);
u32 __ct__9TAdFadeGCFP7TObjectPv(u32, s32, s32);
u32 __nw__7TObjectFUl(s32);
s32 *TAdSinglePlyChrSelectGC__sub_801FE3E4(u32 i);
s32 TAdSinglePlyChrSelectGC__sub_801FE800(u32 i);
s32 TAdMultiPlyChrSelectGC__sub_802DFFE8(s32);
u32 check_slot_flags__23TAdSinglePlyChrSelectGCFlUl(s32, s32);

void load_tables(int a0);
extern s32 lbl_80472860[];
extern s32 tl_fade;

void TAdMultiPlyChrSelectGC::update_select() {
    s32 temp_r30;
    s32 temp_r5;
    u32 var_r0;

    if ((u32) *(u32 *)&this->unk_90 != 0U) {
        ((TWindowSubComCard *)(*(void * *)&this->unk_90))->close();
        *(u32 *)&this->unk_90 = 0U;
    }
    if ((u32) *(u32 *)&this->m_8c != 0U) {
        ((TWindowSubComCard *)(*(void * *)&this->m_8c))->close();
        *(u32 *)&this->m_8c = 0U;
    }
    if ((u32) this->m_74 != 0U) {
        queue_destruction__7TObjectFv(*(void * *)&this->m_74);
        this->m_74 = 0U;
    }
    temp_r5 = get_instance__22TAdMultiPlyChrSelectGCFv(this->m_5c) * 0x50;
    if (TWindowShortListCtrl__check_controller_button((s32 *)((s8 *)controller_physical_port_bank + temp_r5 + 0x20), 2, temp_r5) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) *(u32 *)&this->unk_68 != 0U) {
            queue_destruction__7TObjectFv(*(void * *)&this->unk_68);
            *(u32 *)&this->unk_68 = 0U;
        }
        *(s32 *)&this->m_20 = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() <= 1) {
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
    temp_r30 = TAdMultiPlyChrSelectGC__sub_802DC294(this, ((TAdMultiPlyChrSelectGC *)(this->m_5c))->get_cursor());
    if ((s32) *(s32 *)&this->unk_30 != TAdMultiPlyChrSelectGC__sub_802DFFE8(this->m_5c)) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->unk_60))->set_field_100(1);
        *(s32 *)&this->m_40 = 0;
        if (TAdSinglePlyChrSelectGC__sub_801FE3E4(temp_r30) != 0U) {
            load_tables(temp_r30);
            ((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->unk_60))->set_status_value(temp_r30);
            ((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->unk_60))->set_field_100(2);
            if ((check_slot_flags__23TAdSinglePlyChrSelectGCFlUl(temp_r30, 1) != 0U) && ((s32) *(s32 *)&this->m_3c != 0)) {
                *(s32 *)&this->m_40 = 1;
            }
        }
        *(s32 *)&this->unk_30 = TAdMultiPlyChrSelectGC__sub_802DFFE8(this->m_5c);
    }
    if ((s32) *(s32 *)&this->unk_50 != 0) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->unk_60))->set_field_100(1);
        *(s32 *)&this->m_20 = 0x15;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(this->m_5c))->get_selection() != 0) {
        load_tables(temp_r30);
        if (TAdSinglePlyChrSelectGC__sub_801FE800(temp_r30) != 0) {
            if (is_slot_state_one__16TAdChrSelBSlotGCFlUl(this->m_6c, temp_r30) == 0) {
                *(s32 *)&this->unk_88 = create_confirm_window__22TAdMultiPlyChrSelectGCFv(this, get_instance__22TAdMultiPlyChrSelectGCFv(this->m_5c));
                *(s32 *)&this->m_20 = 0xF;
                return;
            }
            var_r0 = __nw__7TObjectFUl(0x38);
            if (var_r0 != 0U) {
                var_r0 = __ct__9TAdFadeGCFP7TObjectPv(var_r0, tl_fade, 0);
            }
            this->m_74 = var_r0;
            *(u32 *)&this->m_8c = TAdChrSelASlotGC::open_yes_no_window((s32)(*(u32 *)&this->unk_68), (s32)lbl_80472860, (s32)(get_instance__22TAdMultiPlyChrSelectGCFv(this->m_5c)));
            *(s32 *)&this->m_20 = 0x10;
            return;
        }
        ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_state_ready();
    }
}

typedef char RecoveredGlobal_802DDD08_TAdMultiPlyChrSelectGC__data_804727B0_size[sizeof(RecoveredGlobal_802DDD08_TAdMultiPlyChrSelectGC__data_804727B0) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_802DDD08_lbl_8050E3B8_size[sizeof(RecoveredGlobal_802DDD08_lbl_8050E3B8) == 0x1B0 ? 1 : -1];

typedef char RecoveredGlobal_802DDBA8_lbl_804727E8_size[sizeof(RecoveredGlobal_802DDBA8_lbl_804727E8) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_802DDBA8_lbl_8050E3B8_size[sizeof(RecoveredGlobal_802DDBA8_lbl_8050E3B8) == 0x1B0 ? 1 : -1];
void TAdMultiPlyChrSelectGC__sub_802DDBA8(u8 *arg0) {
    s32 temp_r5;
    temp_r5 = get_instance__22TAdMultiPlyChrSelectGCFv((s32)((int) (*(s32 *)((s8 *)arg0 + 0x5C)))) * 0x50;
    if (TWindowShortListCtrl__check_controller_button((void *)((void *) ((u8 *)&(*(RecoveredGlobal_802DDBA8_lbl_8050E3B8 *)&controller_physical_port_bank).value + temp_r5 + 0x20)), 2, temp_r5) != 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x68) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x68));
            *(u32 *)((s8 *)arg0 + 0x68) = 0U;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->get_mode() <= 1) {
        play_sound_effect(0x52F16, 0, 0, 0);
        if (((TAdMultiPlyChrSelectGC *)(*(u32 *)((s8 *)arg0 + 0x68)))->get_player_index() == 1) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
            if ((u32) *(u32 *)((s8 *)arg0 + 0x68) != 0U) {
                queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x68));
                *(u32 *)((s8 *)arg0 + 0x68) = 0U;
            }
            *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
            return;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0xC;
        return;
    }
    TAdMultiPlyChrSelectGC__sub_802C5A44((int) (*(s32 *)((s8 *)arg0 + 0x5C)), &multi_chr_select_item_rect_table.value, 2);
    TAdMultiPlyChrSelectGC__sub_802C5A44((int) (*(s32 *)((s8 *)arg0 + 0x5C)), (void *) ((u8 *)&multi_chr_select_item_rect_table.value + 8), 2);
    TAdMultiPlyChrSelectGC__sub_802C5A44((int) (*(s32 *)((s8 *)arg0 + 0x5C)), (void *) ((u8 *)&multi_chr_select_item_rect_table.value + 0x10), 2);
    TAdMultiPlyChrSelectGC__sub_802C5A44((int) (*(s32 *)((s8 *)arg0 + 0x5C)), (void *) ((u8 *)&multi_chr_select_item_rect_table.value + 0x18), 2);
    *(s32 *)((s8 *)arg0 + 0x20) = 0xE;
}

void TAdMultiPlyChrSelectGC__sub_802DDD08(u8 *arg0) {
    s32 temp_r0;
    s32 temp_r5;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x88) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x88)))->close();
        *(u32 *)((s8 *)arg0 + 0x88) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x8C) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x8C)))->close();
        *(u32 *)((s8 *)arg0 + 0x8C) = 0U;
    }
    ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x60)))->set_field_100(1);
    if ((u32) *(u32 *)((s8 *)arg0 + 0x74) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x74));
        *(u32 *)((s8 *)arg0 + 0x74) = 0U;
    }
    *(s32 *)((s8 *)arg0 + 0x30) = -1;
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->is_state_closing() == 0) {
        temp_r5 = get_instance__22TAdMultiPlyChrSelectGCFv((s32)((int) (*(s32 *)((s8 *)arg0 + 0x5C)))) * 0x50;
        if (TWindowShortListCtrl__check_controller_button((void *)((void *) ((u8 *)&(*(RecoveredGlobal_802DDD08_lbl_8050E3B8 *)&controller_physical_port_bank).value + temp_r5 + 0x20)), 2, temp_r5) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            if ((u32) *(u32 *)((s8 *)arg0 + 0x68) != 0U) {
                queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x68));
                *(u32 *)((s8 *)arg0 + 0x68) = 0U;
            }
            *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
            return;
        }
    }
    ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->clear_slot_entries(2);
    if (((TAdMultiPlyChrSelectGC *)(*(u32 *)((s8 *)arg0 + 0x68)))->get_player_index() >= 0xE) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->init_slot_position((s32)&TAdMultiPlyChrSelectGC__character_slot_positions.value, 0, 1);
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->init_slot_position((s32)((void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 8)), 1, 1);
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->init_slot_position((s32)((void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 0x10)), 2, 1);
    } else {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->init_slot_position((s32)&TAdMultiPlyChrSelectGC__character_slot_positions.value, 0, 0);
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->init_slot_position((s32)((void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 8)), 1, 0);
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->init_slot_position((s32)((void *) ((u8 *)&TAdMultiPlyChrSelectGC__character_slot_positions.value + 0x10)), 2, 0);
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->get_mode() == 0x14) {
        *(s32 *)((s8 *)arg0 + 0x20) = 0xD;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(u32 *)((s8 *)arg0 + 0x68)))->get_player_index() == 1) {
        temp_r0 = *(s32 *)((s8 *)arg0 + 0x1C) + 1;
        *(s32 *)((s8 *)arg0 + 0x1C) = temp_r0;
        if (temp_r0 > 0xA) {
            TAdMultiPlyChrSelectGC::reset_slot_selections();
            play_sound_effect(0x52F16, 0, 0, 0);
            if ((u32) *(u32 *)((s8 *)arg0 + 0x68) != 0U) {
                queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x68));
                *(u32 *)((s8 *)arg0 + 0x68) = 0U;
            }
            *(s32 *)((s8 *)arg0 + 0x20) = 0xB;
        }
    }
}

void TAdMultiPlyChrSelectGC::reset_to_select() {
    Stack_802DDF40 stack;
    s32 temp_r31;
    s32 temp_r3;
    if (TAdMultiPlyChrSelectGC::get_global_state() != 0U) {
        clear_entries__18TAdChrMoveEffectGCFv();
    }
    if (TAdMultiPlyChrSelectGC__sub_802C6558() > 0) {
        TAdMultiPlyChrSelectGC__sub_802C6920();
        TAdMultiPlyChrSelectGC__sub_802C658C();
        if ((is_slot_active__23TAdSinglePlyChrSelectGCFUi() == 0) || ((s32) this->m_54 == 0)) {
            TAdMultiPlyChrSelectGC::split_slot_index(TAdMultiPlyChrSelectGC__sub_802C6920(), &stack.spC, &stack.sp8);
            TAdMultiPlyChrSelectGC::init();
            ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_field_4ec(stack.spC);
            TAdMultiPlyChrSelectGC__sub_802E0024(this->m_5c, stack.sp8);
        }
    }
    if ((u32) *(u32 *)&this->m_6c != 0U) {
        queue_destruction__7TObjectFv(*(void * *)&this->m_6c);
        *(u32 *)&this->m_6c = 0U;
    }
    if ((u32) this->m_84 != 0U) {
        ((TWindowBase *)(*(void * *)&this->m_84))->close();
        this->m_84 = 0U;
    }
    if ((u32) *(u32 *)&this->unk_88 != 0U) {
        ((TWindowSubComCard *)(*(void * *)&this->unk_88))->close();
        *(u32 *)&this->unk_88 = 0U;
    }
    *(s32 *)&this->unk_50 = 0;
    *(s32 *)&this->unk_68 = get_or_create_slot_window__22TAdMultiPlyChrSelectGCFii(this, 1);
    TAdMultiPlyChrSelectGC::set_select_mode(this->m_5c, 0);
    ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_state_ready();
    if ((((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->unk_78))->get_ready_state() == 0) && (TAdMultiPlyChrSelectGC__sub_802C6558() > 1) && (is_multiplayer_character_slot_selected(0) != 0)) {
        temp_r31 = TAdMultiPlyChrSelectGC::count_ready();
        temp_r3 = TAdMultiPlyChrSelectGC__sub_802C6558();
        if (temp_r3 != temp_r31) {
            create_effects__14TAdGameStartGCFPv(*(s32 *)&this->unk_78);
        }
    }
    *(s32 *)&this->m_20 = 0;
}

}
