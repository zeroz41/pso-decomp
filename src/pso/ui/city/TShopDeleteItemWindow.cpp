#pragma defer_codegen on
#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/city/TShopDeleteItemWindow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/city/TShopJudgmentItemWindow_8026DF00.h"
#include "pso/ui/window/TWindowSetLevelUp.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/text_80222C28.h"
#include "pso/object/base/TObjBase.h"

extern "C" {
s32 compact_items__18TCheckRoomSequenceFi(int);
s32 remove_bank_item_amount__18TCheckRoomSequenceFiii(int, int, int);
s32 copy_item_record__18TCheckRoomSequenceFiPvi(int, void *, int);
s32 copy_bank_to_card_window(int);

void *get_window_layout_position(int);
s32 copy_bank_item_with_stack_limit(s32 idx, void *data, s32 *out, s32 slot);
s16 get_child_field1c__13TShopSequenceFv(void *);
TWindowInputNumber *__ct__18TWindowInputNumberFPvllls(void *, void *, int, s32, int, int);
}

struct Base_80337910 { char pad[0x18]; };
struct Base_80337948_80337910 { char pad[0x18]; };
struct VBase_80337B00 { char pad[0x18]; };
struct Base_80337980_80337910 { char pad[0x18]; };
const char *TShopDeleteItemWindow__name = "TShopDeleteItemWindow";
TShopDeleteItemWindow::TShopDeleteItemWindow(void *parent, void *owner, void *player) : TShopWindowBase((TObject *)parent) {
    m_name = TShopDeleteItemWindow__name;
    state = 0;
    this->player = (TObjPlayer *)player;
    m_5c = 1;
    m_54 = 0;
    m_60 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
    m_34 = 0;
    m_38 = 0;
    m_3c = 0;
    m_64 = (TShopWindowBase *)owner;
    ((TItemData *)(&displayed_item_colored))->init();
}

extern "C" {
TShopDeleteItemWindow::~TShopDeleteItemWindow() {
    if (m_30 != NULL) { ((TWindowBase *)m_30)->close(); m_30 = 0; }
    if (m_34 != NULL) { ((TWindowBase *)m_34)->close(); m_34 = 0; }
    if (m_38 != NULL) { ((TWindowBase *)m_38)->close(); m_38 = 0; }
    if (m_3c != NULL) { ((TWindowBase *)m_3c)->close(); m_3c = 0; }
}

void TShopDeleteItemWindow::vfunc_11() {
    void (*callback)(TShopWindowBase *);
    void (*empty_callback)(TShopWindowBase *);
    switch (state) {
    case 0:
        sub_80337E2C();
        return;
    case 1:
        TShopDeleteItemWindow::update_item_select(this);
        return;
    case 2:
        handle_number_input();
        return;
    case 3:
        handle_confirm_dialog();
        return;
    case 4:
        destroy();
        return;
    case 6:
        empty_callback = m_2c;
        if (empty_callback != NULL) {
            empty_callback(m_64);
        }
        queue_destruction();
        return;
    case 7:
        callback = m_28;
        if (callback != NULL) {
            callback(m_64);
        }
        queue_destruction();
    default:
        return;
    }
}
}

#pragma push
#pragma opt_loop_invariants off

extern "C" {
void TShopDeleteItemWindow::sub_80337E2C() {
    s32 base;
    s32 cursor;
    s32 i;
    m_5c = 1;
    base = sub_8022397C();
    room_table_entry = TCheckRoomSequence::get_room_table_entry(base);
    if (room_table_entry == 0) {
        display_shop_message(0x3E, 1);
        set_state(6);
        if (m_30 != NULL) {
            m_30->reset_list();
        }
        return;
    }
    display_shop_message(0x4C, 1);
    if (m_30 == NULL) {
        TItemData item;
        s32 count;
        m_30 = (TWindowMenuIconLine *)create_item_list_window(get_shop_text(0x30), 200, ((TObjBase *)(player))->get_entity_id());
        TWindowSetLevelUp__sub_8026DE28(m_30, 200);
        for (i = 0; i < 200; i++) {
            if (copy_bank_item_with_stack_limit(i, &item, &count, base) != 0) {
                if (count > 1) {
                    ((TWindowSubStatusDisp *)m_30)->add_item_info_entry((saddr)&item, i, count);
                } else {
                    ((TWindowSubStatusDisp *)m_30)->add_item_info_entry((saddr)&item, i, 0);
                }
            }
        }
        m_30->calc_content_extent();
        cursor = ((TShopGetItemWindow *)m_30)->get_cursor_index();
    } else {
        TItemData item;
        s32 count;
        s32 j;
        ((TShopArmorListWindow *)m_30)->save_cursor_selection();
        m_30->reset_list();
        for (j = 0; j < 200; j++) {
            if (copy_bank_item_with_stack_limit(j, &item, &count, base) != 0) {
                if (count > 1) {
                    ((TWindowSubStatusDisp *)m_30)->add_item_info_entry((saddr)&item, j, count);
                } else {
                    ((TWindowSubStatusDisp *)m_30)->add_item_info_entry((saddr)&item, j, 0);
                }
            }
        }
        ((TShopArmorListWindow *)m_30)->clamp_selection_to_valid_entry();
        m_30->calc_content_extent();
        m_30->clear_decided();
        cursor = ((TShopGetItemWindow *)m_30)->get_cursor_index();
    }
    if (m_3c == NULL) {
        if (copy_item_record__18TCheckRoomSequenceFiPvi(cursor, &displayed_item_colored, base) != 0) {
            m_3c = new TWindowHelpItem(get_window_layout_position(0x27), ((TObjBase *)(player))->get_entity_id());
            if (m_3c != NULL && TLobby::is_camera_ctrl_active() > 2) {
                ((TWindowHelpItem *)(m_3c))->set_scale(0.75f, 0.75f);
            }
            m_3c->set_displayed_item_colored((uaddr)&displayed_item_colored);
            m_60 = cursor;
        }
    } else if (copy_item_record__18TCheckRoomSequenceFiPvi(cursor, &displayed_item_colored, base) != 0) {
        m_3c->set_displayed_item_colored((uaddr)&displayed_item_colored);
        m_60 = cursor;
    }
    set_state(1);
}
}

#pragma pop
#pragma push
#pragma opt_common_subs off
extern "C" {
void TShopDeleteItemWindow::update_item_select(void *arg0) {
    TItemData item;
    s32 count;
    s32 base;
    s32 cursor;
    TWindowInputNumber *p;
    s32 id;
    TShopDeleteItemWindow *self = (TShopDeleteItemWindow *)arg0;
    base = ((TShopWindowBase *)self)->sub_8022397C();
    if (self->m_30 != NULL) {
        cursor = self->m_30->get_cursor_value();
        if (self->m_3c != NULL && cursor != self->m_60) {
            if (copy_item_record__18TCheckRoomSequenceFiPvi(cursor, &self->displayed_item_colored, base) != 0) {
                self->m_3c->set_displayed_item_colored((uaddr)&self->displayed_item_colored);
            }
            self->m_60 = cursor;
        }
    }
    if (((TShopWindowBase *)self)->sub_802239EC() != 0) {
        self->set_state(7);
    } else if (self->sub_80223A48() != 0) {
        if (copy_bank_item_with_stack_limit(self->m_30->get_cursor_value(), &item, &count, base) != 0) {
            if (item.data1.data_u8[0] == 3 && count > 1) {
                p = (TWindowInputNumber *)TObject::operator new(0x7C);
                if (p != NULL) {
                    id = get_child_field1c__13TShopSequenceFv(self);
                    p = __ct__18TWindowInputNumberFPvllls(p, get_window_layout_position(0x2B), 1, count, 1, id);
                }
                self->m_38 = p;
                if (self->m_38 != NULL && TLobby::is_camera_ctrl_active() > 2) {
                    ((TWindowInputNumber *)(self->m_38))->set_scale(0.75f, 0.75f);
                }
                self->set_state(2);
            } else {
                id = ((TObjBase *)(self->player))->get_entity_id();
                self->m_34 = create_yes_no_window((const NJS_POINT2 *)((get_window_layout_position(0x2B))), id, NULL, NULL);
                ((TWindowMenu *)self->m_34)->set_ready_flag();
                ((TWindowSubComCardList *)self->m_34)->set_selected_index(1);
                ((TWindowAddition *)self->m_34)->set_position_xy(self->get_scale(), self->get_scale());
                self->set_state(3);
                self->display_shop_message(0x4D, 1);
            }
        }
    }
}
}

#pragma pop

extern "C" {
void TShopDeleteItemWindow::handle_number_input() {
    if (m_38 != NULL && m_38->is_confirmed() != 0) {
        if (m_34 == NULL) {
            u32 id = ((TObjBase *)(player))->get_entity_id();
            m_34 = create_yes_no_window((const NJS_POINT2 *)((get_window_layout_position(0x2B))), id, NULL, NULL);
            ((TWindowMenu *)m_34)->set_ready_flag();
            ((TWindowSubComCardList *)m_34)->set_selected_index(1);
            ((TWindowAddition *)m_34)->set_position_xy(get_scale(), get_scale());
        }
        m_5c = ((TWindowInputNumber *)m_38)->get_value();
        ((TWindowBase *)m_38)->close();
        m_38 = NULL;
        set_state(3);
        display_shop_message(0x4D, 1);
        return;
    }
    if (m_38 != NULL && ((TWindowInputNumber *)m_38)->is_cancelled() != 0) {
        ((TWindowBase *)m_38)->close();
        m_38 = NULL;
        set_state(4);
    }
}

void TShopDeleteItemWindow::handle_confirm_dialog() {
    TItemData record;
    s32 slot;
    s32 sel;
    s32 idx;
    TWindowMenu *menu;
    TWindowMenu *menu2;
    menu = m_34;
    if (menu != NULL && menu->is_decided() != 0) {
        slot = sub_8022397C();
        sel = m_34->get_selected_value();
        if (sel == 0) {
            idx = m_30->get_cursor_value();
            if (copy_item_record__18TCheckRoomSequenceFiPvi(idx, &record, slot) != 0) {
                remove_bank_item_amount__18TCheckRoomSequenceFiii(idx, m_5c, slot);
                compact_items__18TCheckRoomSequenceFi(slot);
                copy_bank_to_card_window(slot);
                set_state(0);
            }
            ((TWindowBase *)m_34)->close();
            m_34 = NULL;
            return;
        }
        if (sel == 1) {
            ((TWindowBase *)m_34)->close();
            m_34 = NULL;
            set_state(4);
            return;
        }
    }
    menu2 = m_34;
    if (menu2 != NULL && menu2->is_cancelled() != 0) {
        ((TWindowBase *)m_34)->close();
        m_34 = NULL;
        set_state(4);
    }
}

void TShopDeleteItemWindow::destroy() {
    if (m_30 != NULL) {
        m_30->clear_decided();
    }
    set_state(1);
    display_shop_message(0x4C, 1);
}

void TShopDeleteItemWindow::display_shop_message(s32 id, s32 flags) {
    TShopWindowBase *owner = m_64;
    if (owner != NULL) {
        owner->display_shop_message(id, flags);
    }
}

void TShopDeleteItemWindow::display_message(const char *text, s32 flags) {
    TShopWindowBase *owner = m_64;
    if (owner != NULL) {
        owner->display_message(text, flags);
    }
}
}
