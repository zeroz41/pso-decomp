#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/TItemData.h"
#include "pso/ui/window/TWindowQuantity.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "types.h"
#include "pso/ui/window/TWindowCost.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80222C28.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/item/TItem.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/city/TShopJudgmentItemWindow_8026DF00.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TObject.h"
#include <string.h>
#include "pso/player/TPlyItem.h"
#include "pso/item/TItemList.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on

#pragma inline_depth(1)

#pragma auto_inline off

#pragma dont_inline off

struct ItemData_8021CF04 {
    u8 b[0xC];
    s32 id;
};

struct Entry_8021CF04 {
    u32 id;
    ItemData_8021CF04 item;
    s32 price;
    s32 index;
};

struct Owner_8021CF04 {
    u8 pad0[0xD00];
    void *inventory;
};

struct Win_8021CF04 {
    u8 pad00[0x24];
    Owner_8021CF04 *owner;
    Entry_8021CF04 entries[30];
    u8 pad370[4];
    s32 count;
    s32 text;
    u8 pad37c[4];
    s32 cursor;
    u8 pad384[8];
    void *list_win;
    u8 pad390[8];
    void *qty_win;
    void *help_win;
    void *cost_win;
};

struct ItemData_8021CC44 {
    u8 b[0xC];
    s32 id;
};

struct Entry_8021CC44 {
    u32 id;
    ItemData_8021CC44 item;
    s32 price;
    s32 index;
};

struct Owner_8021CC44 {
    u8 pad0[0xD00];
    void *inventory;
};

struct Win_8021CC44 {
    u8 pad0[0x24];
    Owner_8021CC44 *owner;
    Entry_8021CC44 entries[30];
    u8 pad370[0x37C - 0x370];
    s32 f37c;
    u8 pad380[4];
    s32 sel;
    u8 pad388[4];
    void *list_win;
    TWindowMenu *menu_win;
    void *qty_win;
    void *status_win;
    void *help_win;
    void *cost_win;
};

struct Rec_8021C968 { saddr item; s32 w[4]; s32 price; s32 w18; };

struct Win_8021C968 {
    u8 pad00[0x24];
    saddr player;
    Rec_8021C968 recs[30];
    u8 pad370[0x37C - 0x370];
    s32 count;
    s32 sel;
    u8 pad384[0x38C - 0x384];
    void *list;
    void *card;
};

extern "C" {
const char *TShopEquipmentSellWindow__class_name = "TShopEquipmentSellWindow";
}

TShopEquipmentSellWindow::TShopEquipmentSellWindow(void *arg1, void *arg2, void *arg3, void *arg4) : TShopWindowBase((TObject *)arg1) {
    this->m_name = TShopEquipmentSellWindow__class_name;
    this->m_370 = 0;
    this->m_374 = 0;
    *(void **)((s8 *)this + 0x378) = arg4;
    this->m_20 = 0;
    this->m_37c = 1;
    this->m_380 = 0;
    this->m_384 = 0;
    this->sequence = (TShopWindowBase *)arg2;
    this->m_38c = 0;
    this->confirm_menu = 0;
    this->m_394 = 0;
    this->m_39c = 0;
    this->m_398 = 0;
    this->m_3a0 = 0;
    *(void **)((s8 *)this + 0x24) = arg3;
    this->m_3a4 = 0;
    this->m_3a8 = 0;
    memset((void *)((char *)this + 40), 0, 840);
}

extern "C" {
TShopEquipmentSellWindow::~TShopEquipmentSellWindow() {
    if (m_38c != NULL) { ((TWindowBase *)m_38c)->close(); m_38c = 0; }
    if (confirm_menu != NULL) { confirm_menu->close(); confirm_menu = 0; }
    if (m_394 != NULL) { ((TWindowBase *)m_394)->close(); m_394 = 0; }
    if (m_39c != NULL) { ((TWindowBase *)m_39c)->close(); m_39c = 0; }
    if (m_398 != NULL) { ((TWindowBase *)m_398)->close(); m_398 = 0; }
    if (m_3a0 != NULL) { ((TWindowBase *)m_3a0)->close(); m_3a0 = 0; }
}

void TShopEquipmentSellWindow::vfunc_11() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)(s32);
    s32 (*temp_r12_2)(s32);
    switch (*(u32 *)((s8 *)arg0 + 0x20)) {
    case 0:
        ((TShopEquipmentSellWindow *)arg0)->build_sell_list();
        return;
    case 1:
        ((TShopEquipmentSellWindow *)arg0)->handle_selection();
        return;
    case 2:
        ((TShopEquipmentSellWindow *)arg0)->handle_sell_confirm();
        return;
    case 3:
        ((TShopEquipmentSellWindow *)arg0)->handle_input_window_result();
        return;
    case 5:
        ((TShopEquipmentSellWindow *)arg0)->close();
        return;
    case 4:
        ((TShopEquipmentSellWindow *)arg0)->update();
        return;
    case 8:
        temp_r12 = *(s32 (**)(s32))((s8 *)arg0 + 0x3A4);
        if (temp_r12 != NULL) {
            temp_r12(*(s32 *)((s8 *)arg0 + 0x388));
        }
        ((TObject *)arg0)->queue_destruction();
        return;
    case 7:
        temp_r12_2 = *(s32 (**)(s32))((s8 *)arg0 + 0x3A8);
        if (temp_r12_2 != NULL) {
            temp_r12_2(*(s32 *)((s8 *)arg0 + 0x388));
        }
        ((TObject *)arg0)->queue_destruction();
    default:
        return;
    }
}

void TShopEquipmentSellWindow::build_sell_list() {
    Win_8021CF04 *self = (Win_8021CF04 *)this;
    uaddr ids[32];
    s32 n;
    s32 i;
    s32 v;
    void *r;
    n = ((TPlyItem *)(self->owner->inventory))->count_matching_items(ids);
    self->count = 0;
    for (i = 0; i < n; i++) {
        if (ids[i] != 0) {
            v = TShopEquipmentSellWindow::get_item_data_value(ids[i]);
            if (v > 0 && ((TItem *)(ids[i]))->copy_to_item_data((TItemData *)&self->entries[self->count].item) != 0) {
                self->entries[self->count].id = ids[i];
                self->entries[self->count].price = v / 8;
                self->entries[self->count].index = i;
                self->count++;
            }
        }
    }
    if (self->count == 0) {
        ((TShopWindowBase *)self)->set_field_20(7);
        if (self->list_win != NULL) {
            ((TWindowMenuIconLine *)(self->list_win))->reset_list();
        }
        return;
    }
    ((TShopEquipmentSellWindow *)self)->display_shop_message(0xC, 1);
    ((TShopWindowBase *)self)->set_field_20(1);
    if (self->list_win == NULL) {
        self->list_win = create_item_list_window(get_shop_text(self->text), self->count, ((TObjBase *)((saddr)self->owner))->get_entity_id());
        for (i = 0; i < self->count; i++) {
            ((TShopEquipmentSellWindow *)(self->list_win))->add_item(self->entries[i].id, self->entries[i].price, i);
        }
        ((TWindowMenuIconLine *)self->list_win)->calc_content_extent();
    } else {
        ((TWindowMenuIconLine *)(self->list_win))->reset_list();
        for (i = 0; i < self->count; i++) {
            ((TShopEquipmentSellWindow *)(self->list_win))->add_item(self->entries[i].id, self->entries[i].price, i);
        }
        if (self->cursor > self->count - 1) {
            self->cursor = self->count - 1;
        }
        ((TWindowMenuIconLine *)self->list_win)->calc_content_extent();
        ((TWindowSubShortCutList *)(self->list_win))->set_cursor_index(self->cursor);
        ((TWindowMenuIconLine *)(self->list_win))->clear_decided();
    }
    if (self->help_win == NULL) {
        self->help_win = new TWindowHelpItem((void *)get_window_layout_position(0x27), ((TObjBase *)((saddr)self->owner))->get_entity_id());
        if (self->help_win != NULL && TLobby::is_camera_ctrl_active() > 2) {
            ((TLobby *)(self->help_win))->set_position(0.75f, 0.75f);
        }
        ((TWindowHelpItem *)self->help_win)->set_displayed_item_by_id(self->entries[0].item.id);
    } else if (self->list_win != NULL) {
        v = ((TWindowMenuIconLine *)self->list_win)->get_cursor_value();
        ((TWindowHelpItem *)self->help_win)->set_displayed_item_by_id(self->entries[v].item.id);
    }
    if (self->qty_win == NULL) {
        self->qty_win = create_window_quantity((u16)((TShopSequence *)self)->get_child_field1c());
        r = ((TPlyItem *)(self->owner->inventory))->set_mode_and_refresh_object(&self->entries[0].item);
        if (r != NULL) {
            TShopEquipmentSellWindow::set_entry_count(self->qty_win, (void *)((TItemList *)r)->get_owner_if_alive());
        } else {
            TShopEquipmentSellWindow::set_entry_count(self->qty_win, 0);
        }
    } else if (self->list_win != NULL) {
        v = ((TWindowMenuIconLine *)self->list_win)->get_cursor_value();
        r = ((TPlyItem *)(self->owner->inventory))->set_mode_and_refresh_object(&self->entries[v].item);
        if (r != NULL) {
            TShopEquipmentSellWindow::set_entry_count(self->qty_win, (void *)((TItemList *)r)->get_owner_if_alive());
        } else {
            TShopEquipmentSellWindow::set_entry_count(self->qty_win, 0);
        }
    }
    if (self->cost_win == NULL) {
        self->cost_win = create_cost_window(((TObjBase *)((saddr)self->owner))->get_entity_id());
        if (self->cost_win != NULL && self->entries[0].price > 0) {
            ((TWindowCost *)self->cost_win)->set_cost(self->entries[0].price);
        }
    } else if (self->entries[self->cursor].price > 0) {
        ((TWindowCost *)self->cost_win)->set_cost(self->entries[self->cursor].price);
    }
}

void TShopEquipmentSellWindow::handle_selection() {
    Win_8021CC44 *w = (Win_8021CC44 *)this;
    s32 i;
    void *n;
    s32 type;
    if (w->list_win != NULL) {
        i = ((TWindowMenuIconLine *)(w->list_win))->get_cursor_value();
        if (w->help_win != NULL && i != w->sel) {
            ((TWindowHelpItem *)w->help_win)->set_displayed_item_by_id(w->entries[i].item.id);
        }
        if (w->status_win != NULL && i != w->sel) {
            n = ((TPlyItem *)(w->owner->inventory))->set_mode_and_refresh_object(&w->entries[i].item);
            if (n != 0) {
                TShopEquipmentSellWindow::set_entry_count(w->status_win, (void *)((TItemList *)n)->get_owner_if_alive());
            } else {
                TShopEquipmentSellWindow::set_entry_count(w->status_win, 0);
            }
        }
        if (w->cost_win != NULL && i != w->sel && w->entries[i].price > 0) {
            ((TWindowCost *)w->cost_win)->set_cost(w->entries[i].price);
        }
        w->sel = i;
    }
    if (((TShopWindowBase *)w)->sub_802239EC() != 0) {
        ((TShopWindowBase *)w)->set_field_20(8);
        play_sound_effect(0x52D01, 0, 0, 0);
        return;
    }
    if (((TShopWindowBase *)w)->sub_80223A48() != 0) {
        w->f37c = 1;
        i = ((TWindowMenuIconLine *)(w->list_win))->get_cursor_value();
        if (w->entries[i].item.b[0] == 3) {
            type = ((TItemData *)&w->entries[i].item)->get_stack_count();
            if (type > 1 && w->qty_win == NULL) {
                w->qty_win = new TWindowInputNumber((void *)get_window_layout_position(0x2B), 1, type, 1, ((TShopSequence *)w)->get_child_field1c());
                if (w->qty_win != NULL && TLobby::is_camera_ctrl_active() > 2) {
                    ((TCheckRoomSequence *)(w->qty_win))->set_position(0.75f, 0.75f);
                }
                ((TShopWindowBase *)w)->set_field_20(3);
                return;
            }
        }
        if (w->menu_win == NULL) {
            w->menu_win = create_window_menu((saddr)get_window_layout_position(0x2B), 2, ((TObjBase *)((saddr)w->owner))->get_entity_id());
            w->menu_win->add_text_entry(get_shop_text(6), 6, 0);
            w->menu_win->add_text_entry(get_shop_text(7), 6, 1);
            w->menu_win->calc_window_size();
            align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(w->menu_win));
            w->menu_win->set_ready_flag();
            w->menu_win->set_position_xy(((TShopWindowBase *)w)->get_scale(), ((TShopWindowBase *)w)->get_scale());
            ((TShopWindowBase *)w)->set_field_20(2);
        }
    }
}

void TShopEquipmentSellWindow::close() {
    if ((u32) this->m_38c != 0U) {
        ((TWindowMenuIconLine *)(*(void **)((s8 *)this + 0x38C)))->clear_decided();
    }
    set_field_20(1);
}

void TShopEquipmentSellWindow::handle_input_window_result() {

    if (((u32) this->m_394 != 0U) && (((TWindowInputNumber *)(this->m_394))->is_confirmed() != 0)) {
        if (confirm_menu == NULL) {
            this->confirm_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, ((TObjBase *)(saddr)(this->m_24))->get_entity_id());
            this->confirm_menu->add_text_entry(get_shop_text(6), 6, 0);
            this->confirm_menu->add_text_entry(get_shop_text(7), 6, 1);
            this->confirm_menu->calc_window_size();
            align_menu_entry_positions(this->confirm_menu);
            this->confirm_menu->set_ready_flag();
            this->confirm_menu->set_position_xy(get_scale(), get_scale());
        }
        this->m_37c = ((TShopEquipmentSellWindow *)(this->m_394))->get_result();
        ((TWindowBase *)this->m_394)->close();
        this->m_394 = 0U;
        set_field_20(2);
        return;
    }
    if (((u32) this->m_394 != 0U) && (((TShopEquipmentSellWindow *)(this->m_394))->is_confirmed() != 0)) {
        ((TWindowBase *)this->m_394)->close();
        this->m_394 = 0U;
        set_field_20(5);
    }
}

void TShopEquipmentSellWindow::handle_sell_confirm() {
    Win_8021C968 *w = (Win_8021C968 *)this;
    s32 r;
    if (w->card != NULL && ((TWindowMenu *)(w->card))->is_decided() != 0) {
        r = ((TWindowMenu *)w->card)->get_selected_value();
        if (r == 0) {
            s32 i = ((TWindowMenuIconLine *)w->list)->get_cursor_value();
            if (((TObjPlayer *)(w->player))->try_add_sale_meseta(((TItem *)(w->recs[i].item))->get_item_id(), w->recs[i].price * w->count, w->count) != 0) {
                ((TWindowBase *)w->card)->close();
                w->card = NULL;
                w->sel = i;
                ((TShopWindowBase *)w)->set_field_20(0);
                return;
            }
            ((TShopEquipmentSellWindow *)w)->display_shop_message(0x1C, 1);
            ((TWindowBase *)w->card)->close();
            w->card = NULL;
            ((TShopWindowBase *)w)->set_field_20(4);
            return;
        }
        if (r == 1) {
            ((TWindowBase *)w->card)->close();
            w->card = NULL;
            ((TShopWindowBase *)w)->set_field_20(5);
            return;
        }
    }
    if (w->card != NULL && ((TWindowMenu *)(w->card))->is_cancelled() != 0) {
        ((TWindowBase *)w->card)->close();
        w->card = NULL;
        ((TShopWindowBase *)w)->set_field_20(5);
    }
}

void TShopEquipmentSellWindow::update() {
    if (vfunc_10() != 0 && (sub_80223A48() != 0 || sub_802239EC() != 0)) {
        display_shop_message(0xc, 1);
        set_field_20(5);
    }
}

void TShopEquipmentSellWindow::display_shop_message(s32 id, s32 flags) {
    TShopWindowBase *sequence = this->sequence;
    if (sequence != NULL) {
        sequence->display_shop_message(id, flags);
    }
}

void TShopEquipmentSellWindow::display_message(const char *text, s32 flags) {
    TShopWindowBase *sequence = this->sequence;
    if (sequence != NULL) {
        sequence->display_message(text, flags);
    }
}
}
