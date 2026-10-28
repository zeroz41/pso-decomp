#include "types.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TUnk_804CDFE8.h"
#include "pso/misc/TWindowLockOn.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowSubShortCutList.h"
#include "pso/misc/TUnk_804D0618.h"
#include "pso/misc/TWindowSubMagPhoton.h"
#include "pso/misc/TWindowSubMag.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItemMag.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TShopArmorListWindow.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowShortListCtrl.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/object/TObjCityMainWarp.h"
#include "pso/item/TItem.h"

struct Obj_8027C0C4 { u8 pad[0x61]; s8 f61; u8 pad2[2]; s32 arr[1]; };

struct Vec2_8027B424 { f32 x; f32 y; };

struct Item_8027B424 { u8 b[0x10]; };

struct TWindowSubMag_8027B62C;
struct VBase_8027B888 { u8 pad[0x18]; };

struct VObj_8027B888 : VBase_8027B888 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

struct Pad_8027B888 { u8 pad[0x20]; u8 sub[0x30]; };

struct TWindowSubMag_8027B888 {
    u8 pad0[0x1C];
    u8 state;
    s8 f1d;
    s8 slots;
    u8 pad1f;
    s16 timer;
    u8 pad22[6];
    s32 client_id;
    s32 mag_state;
    VObj_8027B888 *parent;
    void *list;
    void *list2;
    void *card;
    void *help;
    void *slotwin;
    void *photon;
    void *effect;
};

extern u8 *text_language_group_table;
extern "C" {
s32 TWindowSubMag__sub_8027C0B0(s32 arg0);
}
bool is_mag_full(u8 *arg0);
struct TWindowSubMag_8027B62C {
    u8 pad0[0x28];
    s32 field_0x28;
    s32 field_0x2c;
    s32 field_0x30;
};
extern "C" {
s32 align_menu_entry_positions(void *);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 *get_shared_text_buffer(void);
s32 get_message_10__20TWindowSubStatusDispFl(s32);
s32 deserialize_mag__9TItemDataFPvPv(s32, s32 *);
s32 calc_text_width();
s32 text_builder_append();
s32 set_field_1c__6TLobbyFf(void *);
s32 TWindowSubEquip__sub_80263AF8(s32, s32);
s32 send_and_handle__6TLobbyFii(s32, s32 *, s32);
void *create_message_window__6TLobbyFllUls(s32, s32 *, s32, s32);
s32 get_window_layout_position(s32);
void *get_player_by_client_id(s32);
s32 is_player_input_active(s32);
void TWindow__close(u8 *arg0);
void *__nw__7TObjectFUl(u32);
void *__ct__15TWindowHelpItemFPvUs(void *, s32, s32);
void *fn_802628C0(s32, void *, s32);
void queue_destruction__7TObjectFv(void *arg0);
s32 call_if_split_screen(void *, s32);
s32 select_cursor_entry__22TWindowSubShortCutListFv(s32);
s32 get_selected_menu_value(void *);
s32 update_help_item__13TWindowSubMagFv(void *, s32);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 play_sound_effect(s32, s32, s32, s32);
s32 are_status_entries_ready__13TWindowSubMagFi(void *);
s32 fn_8025373C(u8 *self);
void *TWindowSubMagPhoton__ct(void *, s32, s32, s32);
int TWindowSubMag__sub_8027C0E8(void* p);
u32 is_action_active__10TObjPlayerFv(void *);
extern u8 lbl_8044F9E8[];
extern Pad_8027B888 controller_input_state[];
void *TWindowSubMag__ct(TWindowSubMag *arg0, s32 arg1, s32 arg2);
void *__dt__13TWindowSubMagFv(TWindowSubMag *arg0, s16 arg1);
void TWindowHelpItem__set_displayed_item_by_id(u8 *arg0, s32 arg1);
s32 *get_help_text_string(s32);
s32 create_equip_kind_window(s32, s32 *, s32);
s32 __ct__7TObjectFP7TObject();
s32 __dl__7TObjectFPv(void *);
s32 __dt__7TObjectFv(void *, s32);
}
s32 create_titled_window_menu(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void append_text_space(void);
void text_builder_reset(void);
void window_request_show(void *arg0);
void window_request_refresh(u8 *arg0);
void toggle_help_window_on_button(u32 arg0, s32 arg1);

extern "C" const char lbl_805DD648[] = "";
extern "C" {

void TWindowSubMag::update_mag_help() {
    s32 temp_r3;

    toggle_help_window_on_button(this->m_4c, this->m_28);
    temp_r3 = ((TWindowSubMag *)(this->m_48))->get_selected_blast();
    if (temp_r3 != (s8) this->m_1d) {
        this->m_1d = (u8) temp_r3;
        if (temp_r3 == -1) {
            send_and_handle__6TLobbyFii(this->m_4c, (s32 *)lbl_805DD648, 0x80);
            return;
        }
        send_and_handle__6TLobbyFii(this->m_4c, get_help_text_string(temp_r3 + 0x27), 0x80);
    }
}

void TWindowSubMag::update_displayed_item() {
    s32 temp_r3;

    temp_r3 = select_cursor_entry__22TWindowSubShortCutListFv(this->m_34);
    if (temp_r3 != (s32) this->m_24) {
        this->m_24 = temp_r3;
        TWindowHelpItem__set_displayed_item_by_id((u8 *)this->m_40, temp_r3);
    }
}

s32 TWindowSubMag::count_slots() {
    s32 sp8;
    s32 slot;

    ((TItemData *)(&sp8))->initialize_mag_data();
    deserialize_mag__9TItemDataFPvPv(this->m_2c, &sp8);
    slot = 0;
loop_1:
    if (((TItemMag *)(&sp8))->get_photon_blast_at_slot(slot) == -1) {
        return slot;
    }
    slot += 1;
    if (slot >= 3) {
        return slot;
    }
    goto loop_1;
}

void TWindowSubMag::set_mag_mode(s32 arg1) {
    switch (arg1) {
    case 1:
        this->m_1c = 5;
        return;
    case 0:
        this->m_1c = 0xE;
        return;
    }
}

extern s32 lbl_8044FA00[];

#pragma push
#pragma fp_contract on
void *TWindowSubMag::create_learned_blast_toast() {
    Item_8027B424 item;
    Vec2_8027B424 pos;
    Vec2_8027B424 size;
    f32 scale;
    s32 n;
    void *win;
    ((TItemData *)((s32 *)&item))->initialize_mag_data();
    deserialize_mag__9TItemDataFPvPv(*(s32 *)&this->m_2c, (s32 *)&item);
    n = ((TItemMag *)((s32 *)&item))->get_photon_blast_at_slot(*(s8 *)&this->m_1e);
    if (n == -1) {
        return 0;
    }
    text_builder_reset();
    get_message_10__20TWindowSubStatusDispFl(0x64);
    text_builder_append();
    append_text_space();
    TWindowSubMag__sub_8027C0B0(n);
    text_builder_append();
    get_message_10__20TWindowSubStatusDispFl(0x4C);
    text_builder_append();
    get_shared_text_buffer();
    n = calc_text_width();
    if (TCameraCtrl::get_camera_id() > 2) {
        scale = 0.85f;
    } else {
        scale = 1.0f;
    }
    ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2((void*)(get_window_layout_position(0xE)));
    pos.x -= (0.5f * n + 4.0f) * scale;
    size.x = 8.0f + n;
    size.y = 40.0f;
    win = create_message_window__6TLobbyFllUls((s32)&pos, (s32 *)&size, 1, *(s32 *)&this->m_28);
    TWindowSubEquip__sub_80263AF8(*(s32 *)&this->m_30, 6);
    set_field_1c__6TLobbyFf(win);
    send_and_handle__6TLobbyFii((s32)win, (s32 *)get_shared_text_buffer(), 2);
    ((TUnk_804CDFE8 *)win)->set_position_xy(scale, scale);
    return win;
}
#pragma pop

void *TWindowSubMag::create() {
    void *temp_r31;
    s32 window_layout_position;

    window_layout_position = get_window_layout_position(0xB);
    temp_r31 = create_message_window__6TLobbyFllUls(window_layout_position, lbl_8044FA00, 1, this->m_28);
    TWindowSubEquip__sub_80263AF8(this->m_30, 4);
    set_field_1c__6TLobbyFf(temp_r31);
    *(s32 *)((s8 *)temp_r31 + 0x5C) = 0x186A0;
    call_if_split_screen(temp_r31, this->m_28);
    return temp_r31;
}

extern s32 lbl_8044F9F8[];

void *TWindowSubMag::create_action_menu(s32 id) {
    TWindowSubMag_8027B62C *menu = (TWindowSubMag_8027B62C *)this;
    s32 mag[4];
    void *window;
    u8 *item;
    ((TItemData *)mag)->initialize_mag_data();
    item = (u8 *)find_item_by_id(id);
    window = (void *)create_titled_window_menu(get_window_layout_position(8), 2, get_message_10__20TWindowSubStatusDispFl(0x1D), menu->field_0x28);
    TWindowSubEquip__sub_80263AF8(menu->field_0x30, 1);
    set_field_1c__6TLobbyFf(window);
    if (((s32 (*)(u8 *))is_mag_full)(item) != 0) {
        TWindowSubComCard::draw_text_gray((s32)window, (s32)(get_message_10__20TWindowSubStatusDispFl(0x65)), 6, 1);
    } else {
        forward_trade_action_default__16TObjCityMainWarpFPviii(window, get_message_10__20TWindowSubStatusDispFl(0x65), 6, 1);
    }
    deserialize_mag__9TItemDataFPvPv(menu->field_0x2c, mag);
    if (((TItemMag *)mag)->get_photon_blast_at_slot(0) != -1) {
        forward_trade_action_default__16TObjCityMainWarpFPviii(window, get_message_10__20TWindowSubStatusDispFl(0x64), 6, 0);
    } else {
        TWindowSubComCard::draw_text_gray((s32)window, (s32)(get_message_10__20TWindowSubStatusDispFl(0x64)), 6, 0);
    }
    ((TWindowSubComCardList *)window)->set_flag70_bit10();
    ((TWindowSubComCardList *)window)->update_layout_height((172.0f));
    align_menu_entry_positions(window);
    return window;
}

s32 TWindowSubMag::create_list() {
    s32 equip_kind_window;

    s32 window_layout_position = get_window_layout_position(0xD);
    equip_kind_window = create_equip_kind_window(window_layout_position, lbl_8044F9F8, this->m_28);
    ((TUnk_804D0618 *)equip_kind_window)->ensure_status_display(get_message_10__20TWindowSubStatusDispFl(0x24));
    TWindowSubEquip__sub_80263AF8(this->m_30, 2);
    set_field_1c__6TLobbyFf((void *)equip_kind_window);
    ((TWindowSubShortCutList *)equip_kind_window)->set_flag70_bit10();
    ((TShopArmorListWindow *)equip_kind_window)->close_list();
    return equip_kind_window;
}

extern s32 lbl_8044F9F0[];

s32 TWindowSubMag::setup_list() {
    s32 equip_kind_window;
    s32 window_layout_position;

    window_layout_position = get_window_layout_position(7);
    equip_kind_window = create_equip_kind_window(window_layout_position, lbl_8044F9F0, this->m_28);
    ((TUnk_804D0618 *)equip_kind_window)->ensure_status_display(get_message_10__20TWindowSubStatusDispFl(0x29));
    TWindowSubEquip__sub_80263AF8(this->m_30, 0);
    set_field_1c__6TLobbyFf((void *)equip_kind_window);
    ((TWindowSubShortCutList *)equip_kind_window)->set_flag70_bit10();
    ((TWindowSubMag *)equip_kind_window)->init_and_setup((void*)2);
    return equip_kind_window;
}

void TWindowSubMag::render() {  }

extern s32 __vt__13TWindowSubMag[];

extern "C" const f32 lbl_805DD668 = 2.0f;

#define self ((TWindowSubMag_8027B888 *)arg0)
void TWindowSubMag::run_task(void *arg0) {
    void *w;
    void *player;
    s32 port;
    player = get_player_by_client_id(self->client_id);
    if (player == NULL) {
        return;
    }
    port = is_player_input_active(self->client_id);
    switch (self->state) {
    case 0:
    case 1:
        if (self->card != NULL) {
            TWindow__close((u8 *)self->card);
            self->card = NULL;
        }
        if (self->help == NULL) {
            w = __nw__7TObjectFUl(0xBC);
            if (w != NULL) {
                w = __ct__15TWindowHelpItemFPvUs(w, get_window_layout_position(9), self->client_id);
            }
            self->help = w;
            TWindowSubEquip__sub_80263AF8((s32)self->parent, 5);
            set_field_1c__6TLobbyFf(self->help);
        }
        if (self->slotwin == NULL) {
            self->slotwin = fn_802628C0(get_window_layout_position(0xC), lbl_8044F9E8, self->client_id);
        }
        ((TWindowHelpItem *)(self->help))->sub_80255E24();
        ((TWindowSubMag *)((s32)self->list))->init_and_setup((void*)2);
        ((TWindowSubItem *)(self->list))->clear_selected_and_update_entry();
        ((TWindowSubMag *)(self->list))->start_scroll((188.0f));
        self->state = 2;
    case 2:
        ((TWindowSubMag *)self)->update_displayed_item();
        self->mag_state = ((TWindowSubMag *)(self->help))->get_mag_state();
        ((TWindowSubMag *)(self->slotwin))->set_mag_slot_state(((TWindowSubMag *)(self->help))->get_mag_state());
        if (((TLobby *)(self->list))->get_flag_bit2() != 0) {
            self->parent->m7();
            self->state = 0x11;
        } else if (((TUnk_804D0618 *)(self->list))->get_status_flag() != 0) {
            self->state = 3;
        }
        break;
    case 3:
        if (self->effect != NULL) {
            queue_destruction__7TObjectFv(self->effect);
            self->effect = NULL;
        }
        if (self->photon != NULL) {
            TWindow__close((u8 *)self->photon);
            self->photon = NULL;
        }
        if (self->list2 != NULL) {
            TWindow__close((u8 *)self->list2);
            self->list2 = NULL;
        }
        if (self->help != NULL) {
            window_request_show(self->help);
            ((TWindowHelpItem *)(self->help))->sub_80255E24();
            ((TWindowSubMag *)(self->help))->clear_flag60_bit8();
            call_if_split_screen(self->help, self->client_id);
        }
        ((TWindowSubMag *)(self->list))->start_scroll((188.0f));
        if (self->card == NULL) {
            self->card = ((TWindowSubMag *)self)->create_action_menu(select_cursor_entry__22TWindowSubShortCutListFv((s32)self->list));
        }
        ((TWindowSubComCard *)(self->card))->clear_flag_and_release();
        self->state = 4;
    case 4:
        if (((TWindowSubComCard *)(self->card))->get_status_flag() != 0) {
            self->state = 1;
        } else if (((TWindowMenu *)(self->card))->is_visible() != 0) {
            ((TWindowSubMag *)self)->set_mag_mode(get_selected_menu_value(self->card));
        }
        break;
    case 5:
        if (self->card != NULL) {
            TWindow__close((u8 *)self->card);
            self->card = NULL;
        }
        ((TWindowSubStatusDisp *)(self->list))->init_scroll_pos();
        update_help_item__13TWindowSubMagFv(self->help, 1);
        ((TWindowHelpItem *)(self->help))->set_flag60_bit4();
        if (self->list2 == NULL) {
            self->list2 = (void *)((TWindowSubMag *)self)->create_list();
        }
        ((TWindowSubItem *)(self->list2))->clear_selected_and_update_entry();
        self->state = 6;
    case 6:
        if (((TLobby *)(self->list2))->get_flag_bit2() != 0) {
            self->state = 3;
        } else if (((TUnk_804D0618 *)(self->list2))->get_status_flag() != 0) {
            self->state = 7;
        }
        break;
    case 7:
        if (TWindowShortListCtrl__check_controller_button(controller_input_state[port].sub, 2) != 0 ||
            test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state[4].sub, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            self->state = 5;
        } else if (TWindowSubItem::is_usable((s32)player) != 0) {
            self->slots = ((TWindowSubMag *)self)->count_slots();
            TWindowSubMag::feed_mag((void*)player, (void*)(select_cursor_entry__22TWindowSubShortCutListFv((s32)self->list)), (void*)(select_cursor_entry__22TWindowSubShortCutListFv((s32)self->list2)));
            self->state = 8;
        }
        break;
    case 8:
        window_request_show(self->help);
        window_request_refresh((u8 *)self->help);
        ((TWindowSubMag *)(self->help))->set_flag60_bit8();
        ((TWindowHelpItem *)(self->help))->refresh_copied_items();
        ((TWindowSubMag *)((s32)self->list))->init_and_setup((void*)2);
        ((TWindowSubMag *)(self->slotwin))->set_mag_slot_state(((TWindowSubMag *)(self->help))->get_mag_state());
        if (((TItemData *)(self->help))->update_mag_status_gauges() != 0) {
            self->state = 9;
        } else {
            self->state = 3;
        }
        break;
    case 9:
        if (are_status_entries_ready__13TWindowSubMagFi(self->help) != 0) {
            self->state = 10;
        }
        break;
    case 10:
        if (fn_8025373C((u8 *)self->help) != 0) {
            play_sound_effect(0x4002A80F, 0, 0, 0);
            self->timer = 0;
            self->state = 11;
        } else {
            self->state = 12;
            break;
        }
    case 11:
        if ((f32)self->timer++ > (3e+01f) && are_status_entries_ready__13TWindowSubMagFi(self->help) != 0) {
            self->state = 10;
        }
        break;
    case 12:
        if (self->slots != ((TWindowSubMag *)self)->count_slots()) {
            self->timer = 0;
            update_help_item__13TWindowSubMagFv(self->help, 2);
            self->effect = ((TWindowSubMag *)self)->create_learned_blast_toast();
            self->state = 13;
        } else {
            self->state = 3;
            break;
        }
    case 13:
        if ((f32)self->timer++ > (9e+01f) && self->effect != NULL) {
            TWindow__close((u8 *)self->effect);
            self->effect = NULL;
            self->state = 3;
        }
        break;
    case 14:
        if (self->card != NULL) {
            TWindow__close((u8 *)self->card);
            self->card = NULL;
        }
        if (self->help != NULL) {
            ((TWindowLockOn *)(self->help))->request_close();
            ((TWindowSubMag *)(self->help))->set_flag60_bit8();
            ((TWindowHelpItem *)(self->help))->set_flag60_bit4();
        }
        w = __nw__7TObjectFUl(0x74);
        if (w != NULL) {
            w = TWindowSubMagPhoton__ct(w, get_window_layout_position(0xA), self->mag_state, self->client_id);
        }
        self->photon = w;
        TWindowSubEquip__sub_80263AF8((s32)self->parent, 3);
        set_field_1c__6TLobbyFf(self->photon);
        self->effect = ((TWindowSubMag *)self)->create();
        self->f1d = -1;
        self->state = 15;
    case 15:
        ((TWindowSubMag *)self)->update_mag_help();
        if (TWindowSubMag__sub_8027C0E8(self->photon) != 0) {
            self->state = 3;
        } else if (((TWindowSubMagPhoton *)(self->photon))->get_active_flag() != 0) {
            self->state = 3;
        }
        break;
    case 16:
        if (is_action_active__10TObjPlayerFv(player) == 0) {
            self->state = 1;
        }
        break;
    case 17:
        break;
    }
}
#undef self

void *__dt__13TWindowSubMagFv(TWindowSubMag *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TWindowSubMag;
        if ((u32) arg0->m_4c != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x4C));
            arg0->m_4c = 0U;
        }
        if ((u32) arg0->m_48 != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x48)));
            arg0->m_48 = 0U;
        }
        if ((u32) arg0->m_38 != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x38)));
            arg0->m_38 = 0U;
        }
        if ((u32) arg0->m_3c != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x3C)));
            arg0->m_3c = 0U;
        }
        if ((u32) arg0->m_44 != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x44)));
            arg0->m_44 = 0U;
        }
        if ((u32) arg0->m_40 != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x40)));
            arg0->m_40 = 0U;
        }
        if ((u32) arg0->m_34 != 0U) {
            TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x34)));
            arg0->m_34 = 0U;
        }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 TWindowSubMag__class_name;

void *TWindowSubMag__ct(TWindowSubMag *window_sub_mag, s32 arg1, s32 arg2) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)window_sub_mag + 0x18) = __vt__13TWindowSubMag;
    *(s32 *)((s8 *)window_sub_mag + 0) = (s32) TWindowSubMag__class_name;
    window_sub_mag->m_30 = arg1;
    window_sub_mag->m_28 = arg2;
    window_sub_mag->m_34 = window_sub_mag->setup_list();
    window_sub_mag->m_40 = 0;
    window_sub_mag->m_44 = 0;
    window_sub_mag->m_3c = 0;
    window_sub_mag->m_38 = 0;
    window_sub_mag->m_48 = 0;
    window_sub_mag->m_4c = 0;
    window_sub_mag->m_2c = 0;
    window_sub_mag->m_24 = -1;
    window_sub_mag->m_1c = 0;
    window_sub_mag->m_20 = 0;
    return window_sub_mag;
}

s32 TWindowSubMag__sub_8027C0B0(s32 arg0) {
    return *(s32 *)((s8 *)(*(s32 *)((s8 *)text_language_group_table + 0x20)) + (arg0 * 4));
}

s32 TWindowSubMag::get_selected_blast() {
    Obj_8027C0C4 *o = (Obj_8027C0C4 *)this;
    return o->arr[o->f61];
}

int TWindowSubMagPhoton::get_active_flag() { return this->m_60 & 0x1; }
int TWindowSubMag__sub_8027C0E8(void* p) { return *(u8*)((char*)p + 0x60) & 0x2; }
}

bool is_mag_full(u8 *arg0) {
    return (*(f32 *)((s8 *)arg0 + 0x194) < *(const volatile f32 *)&lbl_805DD668) == 0;
}
extern "C" {

void TWindowSubMag::set_flag60_bit8() { *(u8*)((char*)this + 0x60) |= 0x8; }
void TWindowSubMag::clear_flag60_bit8() { *(u8*)((char*)this + 0x60) &= 0xfffffff7; }
s32 TWindowSubMag::get_mag_state() { return *(s32*)((char*)this + 0x68); }
}
