#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/TItemData.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80222C28.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/system/task/TObject.h"

extern "C" {
s32 get_entity_id(TObjPlayer *);

saddr get_window_layout_position(s32);
s32 compact_items__18TCheckRoomSequenceFi(int);
s32 remove_bank_item_amount__18TCheckRoomSequenceFiii(int, int, int);
s32 copy_item_record__18TCheckRoomSequenceFiPvi(int, void *, int);
s32 copy_bank_to_card_window(int);
s32 copy_bank_item_with_stack_limit(s32 idx, void *data, s32 *out, s32 slot);
TWindowInputNumber *__ct__18TWindowInputNumberFPvllls(void *, s32, s32, s32, s32, s16);
TWindowHelpItem *__ct__15TWindowHelpItemFPvUs(void *, s32, u16);
void add_item_info_entry__20TWindowSubStatusDispFlll(TWindowMenuIconLine *, void *, s32, s32);
void TWindowSetLevelUp__sub_8026DE28(TWindowMenuIconLine *, s32);
TWindowMenuIconLine *create_item_list_window(s32, s32, u16);
}

extern const char *TShopGetItemWindow__class_name;

const char *TShopGetItemWindow__class_name = "TShopGetItemWindow";
TShopGetItemWindow::TShopGetItemWindow(void *parent, void *owner, void *player) : TShopWindowBase((TObject *)parent) {
    m_name = TShopGetItemWindow__class_name;
    m_20 = 0;
    m_24 = (TObjPlayer *)player;
    m_54 = 1;
    m_4c = 0;
    m_58 = 0;
    m_60 = 0;
    m_64 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
    m_34 = 0;
    m_5c = (TShopWindowBase *)owner;
    ((TItemData *)(&m_38))->init();
}

TShopGetItemWindow::~TShopGetItemWindow() {
    if (m_28 != NULL) { ((TWindowBase *)m_28)->close(); m_28 = 0; }
    if (m_2c != NULL) { ((TWindowBase *)m_2c)->close(); m_2c = 0; }
    if (m_30 != NULL) { ((TWindowBase *)m_30)->close(); m_30 = 0; }
    if (m_34 != NULL) { ((TWindowBase *)m_34)->close(); m_34 = 0; }
}

void TShopGetItemWindow::vfunc_11() {
    void (*empty_callback)(TShopWindowBase *);
    void (*callback)(TShopWindowBase *);
    switch (m_20) {
    case 0:
        rebuild_item_list();
        return;
    case 1:
        handle_withdraw_list_input();
        return;
    case 2:
        update_input_number();
        return;
    case 3:
        handle_withdraw_confirm();
        return;
    case 4:
        close();
        return;
    case 6:
        empty_callback = m_64;
        if (empty_callback != NULL) {
            empty_callback(m_5c);
        }
        queue_destruction();
        return;
    case 7:
        callback = m_60;
        if (callback != NULL) {
            callback(m_5c);
        }
        queue_destruction();
    default:
        return;
    }
}

void TShopGetItemWindow::rebuild_item_list() {
    u16 id;
    s32 x;
    s32 sel;
    s32 i;
    TWindowHelpItem *help;
    m_54 = 1;
    m_50 = TCheckRoomSequence::get_room_table_entry(x = sub_8022397C());
    if (m_50 == 0) {
        display_shop_message(0x3E, 1);
        set_field_20(6);
        if (m_28 != NULL) {
            m_28->reset_list();
        }
    } else {
    if (m_28 == NULL) {
        TItemData item;
        s32 count;
        m_28 = create_item_list_window(get_shop_text(0x30), 0xC8, get_entity_id(m_24));
        TWindowSetLevelUp__sub_8026DE28(m_28, 0xC8);
        for (i = 0; i < 0xC8; i++) {
            if (copy_bank_item_with_stack_limit(i, &item, &count, x) != 0) {
                if (count > 1) {
                    add_item_info_entry__20TWindowSubStatusDispFlll(m_28, &item, i, count);
                } else {
                    add_item_info_entry__20TWindowSubStatusDispFlll(m_28, &item, i, 0);
                }
            }
        }
        m_28->calc_content_extent();
        sel = ((TShopGetItemWindow *)m_28)->get_cursor_index();
    } else {
        TItemData item;
        s32 count;
        s32 j;
        ((TShopArmorListWindow *)m_28)->save_cursor_selection();
        m_28->reset_list();
        for (j = 0; j < 0xC8; j++) {
            if (copy_bank_item_with_stack_limit(j, &item, &count, x) != 0) {
                if (count > 1) {
                    add_item_info_entry__20TWindowSubStatusDispFlll(m_28, &item, j, count);
                } else {
                    add_item_info_entry__20TWindowSubStatusDispFlll(m_28, &item, j, 0);
                }
            }
        }
        ((TShopArmorListWindow *)m_28)->clamp_selection_to_valid_entry();
        m_28->calc_content_extent();
        m_28->clear_decided();
        sel = ((TShopGetItemWindow *)m_28)->get_cursor_index();
    }
    if (m_34 == NULL) {
        if (copy_item_record__18TCheckRoomSequenceFiPvi(sel, &m_38, x) != 0) {
            help = (TWindowHelpItem *)TObject::operator new(0xBC);
            if (help != NULL) {
                id = (u16)get_entity_id(m_24);
                help = __ct__15TWindowHelpItemFPvUs(help, get_window_layout_position(0x27), id);
            }
            m_34 = help;
            if (m_34 != NULL && TLobby::is_camera_ctrl_active() > 2) {
                ((TLobby *)m_34)->set_position(0.75f, 0.75f);
            }
            m_34->set_displayed_item_colored((uaddr)&m_38);
            m_58 = sel;
        }
    } else if (copy_item_record__18TCheckRoomSequenceFiPvi(sel, &m_38, x) != 0) {
        m_34->set_displayed_item_colored((uaddr)&m_38);
        m_58 = sel;
    }
    set_field_20(1);
    }
}

void TShopGetItemWindow::handle_withdraw_list_input() {
    s32 sel;
    s32 x;
    s32 count;
    TItemData item;
    f32 scale;
    x = sub_8022397C();
    if (m_28 != NULL) {
        sel = m_28->get_cursor_value();
        if (m_34 != NULL && sel != m_58) {
            if (copy_item_record__18TCheckRoomSequenceFiPvi(sel, &m_38, x) != 0) {
                m_34->set_displayed_item_colored((uaddr)&m_38);
            }
            m_58 = sel;
        }
    }
    if (sub_802239EC() != 0) {
        set_field_20(7);
        return;
    }
    if (sub_80223A48() != 0) {
        if (copy_bank_item_with_stack_limit(m_28->get_cursor_value(), &item, &count, x) != 0) {
            if (item.data1.data_u8[0] == 3 && count > 1) {
                TWindowInputNumber *obj = (TWindowInputNumber *)TObject::operator new(0x7C);
                if (obj != NULL) {
                    sel = (s16)((TShopSequence *)this)->get_child_field1c();
                    obj = __ct__18TWindowInputNumberFPvllls(obj, get_window_layout_position(0x2B), 1, count, 1, sel);
                }
                m_30 = obj;
                if (m_30 != NULL && TLobby::is_camera_ctrl_active() > 2) {
                    ((TCheckRoomSequence *)m_30)->set_position(0.75f, 0.75f);
                }
                set_field_20(2);
                return;
            }
            sel = (u16)get_entity_id(m_24);
            m_2c = create_yes_no_window((const NJS_POINT2 *)get_window_layout_position(0x2B), sel, NULL, NULL);
            ((TWindowMenu *)m_2c)->set_ready_flag();
            scale = get_scale();
            ((TWindowAddition *)m_2c)->set_position_xy(get_scale(), scale);
            set_field_20(3);
        }
    }
}

void TShopGetItemWindow::update_input_number() {
    TWindowInputNumber *w;
    w = m_30;
    if (w != NULL && w->is_confirmed() != 0) {
        if (m_2c == NULL) {
            m_2c = create_yes_no_window((const NJS_POINT2 *)get_window_layout_position(0x2B), (u16)get_entity_id(m_24), NULL, NULL);
            ((TWindowMenu *)m_2c)->set_ready_flag();
            ((TWindowAddition *)m_2c)->set_position_xy(get_scale(), get_scale());
        }
        m_54 = ((TShopEquipmentSellWindow *)m_30)->get_result();
        ((TWindowBase *)m_30)->close();
        m_30 = NULL;
        set_field_20(3);
        return;
    }
    w = m_30;
    if (w != NULL && ((TShopEquipmentSellWindow *)w)->is_confirmed() != 0) {
        ((TWindowBase *)m_30)->close();
        m_30 = NULL;
        set_field_20(4);
    }
}

void TShopGetItemWindow::handle_withdraw_confirm() {
    TItemData record;
    s32 slot;
    s32 sel;
    s32 idx;
    TWindowMenu *menu;
    TWindowMenu *menu2;
    menu = m_2c;
    if (menu != NULL && menu->is_decided() != 0) {
        slot = sub_8022397C();
        sel = m_2c->get_selected_value();
        if (sel == 0) {
            idx = m_28->get_cursor_value();
            if (copy_item_record__18TCheckRoomSequenceFiPvi(idx, &record, (int)(slot & 0xFFFFFFFFFFFFFFFFu)) != 0) {
                record.id = -1;
                if (TCheckRoomSequence::get_item_def((uaddr)&record) != 0) {
                    record.set_stack_count(m_54);
                }
                if (m_24->can_inventory_accept_item((u8 *)&record) == 0) {
                    display_shop_message(0x4B, 1);
                    set_field_20(6);
                } else {
                    m_24->request_inventory_item(&record);
                    remove_bank_item_amount__18TCheckRoomSequenceFiii(idx, m_54, slot);
                    compact_items__18TCheckRoomSequenceFi(slot);
                    copy_bank_to_card_window(slot);
                    set_field_20(0);
                }
            }
            ((TWindowBase *)m_2c)->close();
            m_2c = NULL;
            return;
        }
        if (sel == 1) {
            ((TWindowBase *)m_2c)->close();
            m_2c = NULL;
            set_field_20(4);
            return;
        }
    }
    menu2 = m_2c;
    if (menu2 != NULL && menu2->is_cancelled() != 0) {
        ((TWindowBase *)m_2c)->close();
        m_2c = NULL;
        set_field_20(4);
    }
}

void TShopGetItemWindow::close() {
    if (m_28 != NULL) {
        m_28->clear_decided();
    }
    set_field_20(1);
}

void TShopGetItemWindow::display_shop_message(s32 id, s32 flags) {
    if (this->m_5c != NULL) {
        this->m_5c->display_shop_message(id, flags);
    }
}

void TShopGetItemWindow::display_message(const char *text, s32 flags) {
    if (this->m_5c != NULL) {
        this->m_5c->display_message(text, flags);
    }
}
