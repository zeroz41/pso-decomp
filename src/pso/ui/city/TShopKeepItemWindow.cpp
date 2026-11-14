#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#include "types.h"
#include "pso/ui/city/TShopKeepItemWindow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80222C28.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemData.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/TShopKeepItemWindow.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/system/task/TObject.h"

struct Base_80221844 { char pad[0x18]; };
struct VObj_80221844 : Base_80221844 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
};
struct Base_8022187C_80221844 { char pad[0x18]; };
struct VObj_8022187C_80221844 : Base_8022187C_80221844 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
};

struct Base_802219A0 { char pad[0x18]; };

struct V_802219A0 : Base_802219A0 {
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3();
    virtual void m4(s32, s32);
};

#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TMessageWindowController.h"
#include "pso/ui/window/TWindowInputNumber.h"
struct VBase_80221F08 { char pad[0x18]; };

struct VObj_80221F08 : VBase_80221F08 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(s32, s32);
};

s32 bank_has_free_row(s32 slot);

extern "C" {
u32 get_entity_id(s32);
u8 *create_yes_no_window(s32 position, u16 client, u32 arg2, u32 arg3);
s32 get_window_layout_position(s32);
void memset(void *, int, int);
s32 get_item_record__23TShopJudgmentItemWindowFPv(s32, s32, s32);
s32 store_item_in_bank(u8 *item, s32 arg1, s32 slot);
void copy_bank_to_card_window(s32 slot);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 sub_80223A48__15TShopWindowBaseFv(void *);
s32 play_sound_effect(s32, s32, s32, s32);
void TWindowHelpItem__set_displayed_item_by_id(u32, s32);
u32 create_item_list_window(s32, s32, u16);
void sort_bank_items(s32 slot);
s32 get_bank_deposit_capacity_for_item(TItemData *item, s32 slot);
}

const char *TShopKeepItemWindow__class_name = "TShopKeepItemWindow";

TShopKeepItemWindow::TShopKeepItemWindow(void *arg1, void *arg2, void *arg3) : TShopWindowBase((TObject *)arg1) {
    m_name = TShopKeepItemWindow__class_name;
    this->m_370 = 0;
    this->entry_count = 0;
    this->deposit_count = 1;
    this->help_item_index = 0;
    this->m_20 = 0;
    this->message_window = (u32)arg2;
    this->item_list_window = 0;
    this->confirm_window = 0;
    this->help_window = 0;
    this->number_window = 0;
    this->m_24 = (u32)arg3;
    this->ok_callback = NULL;
    this->cancel_callback = NULL;
    memset(this->entries, 0, sizeof(this->entries));
}

TShopKeepItemWindow::~TShopKeepItemWindow() {
    if (this->item_list_window != 0) { ((TWindowBase *)this->item_list_window)->close(); this->item_list_window = 0; }
    if (this->confirm_window != 0) { ((TWindowBase *)this->confirm_window)->close(); this->confirm_window = 0; }
    if (this->number_window != 0) { ((TWindowBase *)this->number_window)->close(); this->number_window = 0; }
    if (this->help_window != 0) { ((TWindowBase *)this->help_window)->close(); this->help_window = 0; }
}

void TShopKeepItemWindow::vfunc_11() {
    u8 *arg0 = (u8 *)this;
    switch (this->m_20) {
    case 0:
        ((TShopKeepItemWindow *)arg0)->rebuild_item_list();
        return;
    case 1:
        ((TShopKeepItemWindow *)arg0)->handle_deposit_list_select();
        return;
    case 2:
        ((TShopKeepItemWindow *)arg0)->handle_deposit_confirm();
        return;
    case 3:
        ((TShopKeepItemWindow *)arg0)->close();
        return;
    case 4:
        ((TShopKeepItemWindow *)arg0)->update_number_input();
        return;
    case 5:
        ((TShopKeepItemWindow *)arg0)->close_with_ok_callback();
        return;
    case 7:
        ((TShopKeepItemWindow *)arg0)->close_with_cancel_callback();
    default:
        return;
    }
}

s32 TShopKeepItemWindow::rebuild_item_list() {
    u32 buf[30];
    s32 count;
    s32 i;
    s32 cur;
    this->deposit_count = 1;
    count = ((TObjPlayer *)(*(s32 *)((s8 *)this->m_24 + 0xD00)))->count_matching_items((int)buf);
    this->entry_count = 0;
    for (i = 0; i < count; i++) {
        if (buf[i] != 0 && ((TItem *)(buf[i]))->copy_to_item_data(&this->entries[this->entry_count].data) != 0) {
            this->entries[this->entry_count].item = (TItem *)buf[i];
            this->entries[this->entry_count].inventory_index = i;
            this->entry_count++;
        }
    }
    if (this->entry_count != 0) {
        set_field_20(1);
    } else {
        ((VObj_80221F08 *)this)->m4(0x49, 1);
        set_field_20(7);
        return;
    }
    if (this->item_list_window == 0U) {
        this->item_list_window = create_item_list_window(get_shop_text(0x30), 0x40, get_entity_id(this->m_24));
        for (s32 j = 0; j < this->entry_count; j++) {
            ((TShopJudgmentItemWindow *)(this->item_list_window))->add_list_entry((s32)this->entries[j].item, j);
        }
        ((TWindowMenuIconLine *)this->item_list_window)->calc_content_extent();
        cur = ((TShopGetItemWindow *)(this->item_list_window))->get_cursor_index();
    } else {
        ((TShopArmorListWindow *)(this->item_list_window))->save_cursor_selection();
        ((TWindowMenuIconLine *)(this->item_list_window))->reset_list();
        for (s32 j = 0; j < this->entry_count; j++) {
            ((TShopJudgmentItemWindow *)(this->item_list_window))->add_list_entry((s32)this->entries[j].item, j);
        }
        ((TShopArmorListWindow *)(this->item_list_window))->clamp_selection_to_valid_entry();
        ((TWindowMenuIconLine *)this->item_list_window)->calc_content_extent();
        ((TWindowMenuIconLine *)((void *)this->item_list_window))->clear_decided();
        cur = ((TShopGetItemWindow *)(this->item_list_window))->get_cursor_index();
    }
    if (this->help_window == 0U) {
        this->help_window = (u32)new TWindowHelpItem((void *)get_window_layout_position(0x27), get_entity_id(this->m_24));
        if (this->help_window != 0U && TLobby::is_camera_ctrl_active() > 2) {
            ((TLobby *)(this->help_window))->set_position(0.75f, 0.75f);
        }
        TWindowHelpItem__set_displayed_item_by_id(this->help_window, this->entries[cur].item->get_item_id());
        this->help_item_index = cur;
    } else {
        TWindowHelpItem__set_displayed_item_by_id(this->help_window, this->entries[cur].item->get_item_id());
        this->help_item_index = cur;
    }
}

void TShopKeepItemWindow::handle_deposit_list_select() {
    s32 bank = sub_8022397C__15TShopWindowBaseFv(this);
    s32 cur;
    s32 count;
    s32 stack;
    TItemData *data;
    if (this->item_list_window != 0U) {
        cur = ((TWindowMenuIconLine *)this->item_list_window)->get_cursor_value();
        if (this->help_window != 0U && cur != this->help_item_index) {
            TWindowHelpItem__set_displayed_item_by_id(this->help_window, this->entries[cur].item->get_item_id());
            this->help_item_index = cur;
        }
    }
    if (sub_802239EC__13TShopSequenceFv(this) != 0) {
        set_field_20(5);
        play_sound_effect(0x52D01, 0, 0, 0);
        return;
    }
    if (sub_80223A48__15TShopWindowBaseFv(this) == 0) {
        return;
    }
    cur = ((TWindowMenuIconLine *)this->item_list_window)->get_cursor_value();
    switch (this->entries[cur].data.data1.data_u8[0]) {
    case 3:
        data = &this->entries[cur].data;
        if (TItemData::lookup_item_def(data) != 0) {
            count = get_bank_deposit_capacity_for_item(data, bank);
            stack = data->get_stack_count();
            count = count < stack ? count : stack;
        } else if (bank_has_free_row(bank) != 0) {
            count = 1;
        } else {
            count = 0;
        }
        if (count == 0) {
            ((V_802219A0 *)this)->m4(0x3C, 1);
            set_field_20(7);
            return;
        }
        break;
    case 0:
    case 1:
    case 2:
    default:
        if (bank_has_free_row(bank) == 0) {
            ((V_802219A0 *)this)->m4(0x3C, 1);
            set_field_20(7);
            return;
        }
        count = 1;
        break;
    }
    if (count > 1 && this->number_window == 0U) {
        this->number_window = (u32)new TWindowInputNumber((void *)get_window_layout_position(0x2B), 1, count, 1, ((TShopSequence *)this)->get_child_field1c());
        if (this->number_window != 0U && TLobby::is_camera_ctrl_active() > 2) {
            ((TCheckRoomSequence *)this->number_window)->set_position(0.75f, 0.75f);
        }
        set_field_20(4);
        return;
    }
    if (this->confirm_window == 0U) {
        this->confirm_window = (u32)create_yes_no_window(get_window_layout_position(0x2B), get_entity_id(this->m_24), 0, 0);
        ((TCheckRoomSequence *)this->confirm_window)->set_ready_flag();
        f32 scale = get_scale();
        ((TWindowAddition *)this->confirm_window)->set_position_xy(get_scale(), scale);
        set_field_20(2);
    }
}

void TShopKeepItemWindow::update_number_input() {
    f32 temp_f31;
    u16 temp_r31;
    u32 w;
    w = this->number_window;
    if ((w != 0U) && (((TWindowInputNumber *)w)->is_confirmed() != 0)) {
        if ((u32) this->confirm_window == 0U) {
            temp_r31 = get_entity_id(this->m_24);
            this->confirm_window = (u32)create_yes_no_window(get_window_layout_position(0x2B), temp_r31, 0, 0);
            ((TCheckRoomSequence *)(this->confirm_window))->set_ready_flag();
            temp_f31 = get_scale();
            ((TWindowAddition *)(this->confirm_window))->set_position_xy(get_scale(), temp_f31);
        }
        this->deposit_count = ((TShopEquipmentSellWindow *)(this->number_window))->get_result();
        ((TWindowBase *)this->number_window)->close();
        this->number_window = 0U;
        set_field_20(2);
        return;
    }
    w = this->number_window;
    if ((w != 0U) && (((TShopEquipmentSellWindow *)w)->is_confirmed() != 0)) {
        ((TWindowBase *)this->number_window)->close();
        this->number_window = 0U;
        set_field_20(3);
    }
}

void TShopKeepItemWindow::handle_deposit_confirm() {
    s32 base;
    s32 r;
    s32 i;
    void *win;
    win = (void *)this->confirm_window;
    if (win != NULL && ((TWindowMenu *)win)->is_decided() != 0) {
        base = sub_8022397C__15TShopWindowBaseFv(this);
        r = ((TWindowMenu *)this->confirm_window)->get_selected_value();
        if (r == 0) {
            i = ((TWindowMenuIconLine *)this->item_list_window)->get_cursor_value();
            if (store_item_in_bank((u8 *)&this->entries[i].data, this->deposit_count, base) != 0) {
                get_item_record__23TShopJudgmentItemWindowFPv(this->m_24, this->entries[i].item->get_item_id(), this->deposit_count);
                copy_bank_to_card_window(base);
                play_sound_effect(0x52D01, 0, 0, 0);
                ((TWindowBase *)this->confirm_window)->close();
                this->confirm_window = 0;
                set_field_20(0);
                return;
            }
            ((V_802219A0 *) this)->m4(0x3C, 1);
            play_sound_effect(0x53F06, 0, 0, 0);
            ((TWindowBase *)this->confirm_window)->close();
            this->confirm_window = 0;
            set_field_20(7);
            return;
        }
        if (r == 1) {
            ((TWindowBase *)this->confirm_window)->close();
            this->confirm_window = 0;
            set_field_20(3);
            return;
        }
    }
    win = (void *)this->confirm_window;
    if (win != NULL && ((TWindowMenu *)win)->is_cancelled() != 0) {
        ((TWindowBase *)this->confirm_window)->close();
        this->confirm_window = 0;
        set_field_20(3);
    }
}

s32 TShopKeepItemWindow::close() {
    if ((u32) this->item_list_window != 0U) {
        ((TWindowMenuIconLine *)(this->item_list_window))->clear_decided();
    }
    set_field_20(1);
}

s32 TShopKeepItemWindow::close_with_ok_callback() {
    s32 (*temp_r12)(s32);

    temp_r12 = this->ok_callback;
    if (temp_r12 != NULL) {
        temp_r12(this->message_window);
    }
    sort_bank_items(sub_8022397C__15TShopWindowBaseFv(this));
    queue_destruction();
}

s32 TShopKeepItemWindow::close_with_cancel_callback() {
    s32 (*temp_r12)(s32);

    temp_r12 = this->cancel_callback;
    if (temp_r12 != NULL) {
        temp_r12(this->message_window);
    }
    sort_bank_items(sub_8022397C__15TShopWindowBaseFv(this));
    queue_destruction();
}

void TShopKeepItemWindow::vfunc_6() {
    struct VObj_8022187C_80221844 *o = (struct VObj_8022187C_80221844 *)this->message_window;
    if (o != NULL) {
        o->m4();
    }
}

void TShopKeepItemWindow::display_message(const char *text, s32 flags) {
    struct VObj_80221844 *temp_r3;

    temp_r3 = (struct VObj_80221844 *)this->message_window;
    if (temp_r3 != NULL) {
        temp_r3->m5();
    }
}
