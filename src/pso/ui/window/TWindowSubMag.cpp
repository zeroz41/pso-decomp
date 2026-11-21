#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/MagStats.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/unk/text_8025373C.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubMagPhoton.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/item/TItemData.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/vector.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowHelpItem_802540AC.h"

#pragma readonly_strings on

struct Obj_8027C0C4 { u8 pad[0x61]; s8 f61; u8 pad2[2]; s32 arr[1]; };

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
s32 get_photon_blast_name(s32 arg0);
}
struct TWindowSubMag_8027B62C {
    u8 pad0[0x28];
    s32 field_0x28;
    saddr field_0x2c;
    s32 field_0x30;
};
extern "C" {
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 calc_text_width();
s32 text_builder_append();
s32 set_depth__11TWindowBaseFf(void *);
s32 TWindowSubEquip__sub_80263AF8(s32, s32);
saddr get_window_layout_position(s32);
void *get_player_by_client_id(s32);
void *__ct__15TWindowHelpItemFPvUs(void *, s32, s32);
void *fn_802628C0(s32, const f32 *, s32);
s32 call_if_split_screen(void *, s32);
s32 play_sound_effect(s32, s32, s32, s32);
s32 are_status_entries_ready__13TWindowSubMagFi(void *);
void *TWindowSubMagPhoton__ct(void *, saddr, s32, s32);
int TWindowSubMag__sub_8027C0E8(void* p);
const char *TWindowSubMag__class_name = "TWindowSubMag";
// Window positions (x, y): mag slot list, the two equip-kind lists, message window.
extern const f32 lbl_8044F9E8[2] = {144.0f, 68.0f};
extern const f32 lbl_8044F9F0[2] = {206.0f, 184.0f};
extern const f32 lbl_8044F9F8[2] = {308.0f, 124.0f};
extern const f32 lbl_8044FA00[2] = {214.0f, 184.0f};
extern Pad_8027B888 controller_input_state[];
void *TWindowSubMag__ct(TWindowSubMag *arg0, s32 arg1, s32 arg2);
}
s32 get_help_text_string(s32 arg0);
extern "C" {
s32 create_equip_kind_window(saddr, const f32 *, s32);
s32 __ct__7TObjectFP7TObject();
s32 __dl__7TObjectFPv(void *);
s32 __dt__7TObjectFv(void *, s32);
}
saddr create_titled_window_menu(saddr arg0, s32 arg1, saddr arg2, s32 arg3);
void append_text_space(void);
void text_builder_reset(void);
void window_request_show(void *arg0);
void window_request_refresh(u8 *arg0);
void toggle_help_window_on_button(uaddr arg0, s32 arg1);

extern "C" const char lbl_805DD648[] = "";
// Deferred code generation: the functions are written last to first (see configure.py).
extern "C" s32 __vt__13TWindowSubMag[];

s32 TWindowSubMag::get_mag_state() { return *(s32*)((char*)this + 0x68); }

void TWindowSubMag::clear_flag60_bit8() { *(u8*)((char*)this + 0x60) &= 0xfffffff7; }

void TWindowSubMag::set_flag60_bit8() { *(u8*)((char*)this + 0x60) |= 0x8; }

bool is_mag_full(u8 *arg0) {
    return (*(f32 *)((s8 *)arg0 + 0x194) < 2.0f) == 0;
}

extern "C" {

int TWindowSubMag__sub_8027C0E8(void* p) { return *(u8*)((char*)p + 0x60) & 0x2; }

int TWindowSubMagPhoton::get_active_flag() { return this->m_60 & 0x1; }

s32 TWindowSubMag::get_selected_blast() {
    Obj_8027C0C4 *o = (Obj_8027C0C4 *)this;
    return o->arr[o->f61];
}

s32 get_photon_blast_name(s32 arg0) {
    return *(s32 *)((s8 *)(*(saddr *)((s8 *)text_language_group_table + 0x20)) + (arg0 * 4));
}

void *TWindowSubMag__ct(TWindowSubMag *window_sub_mag, s32 arg1, s32 arg2) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)window_sub_mag + 0x18) = __vt__13TWindowSubMag;
    *(s32 *)((s8 *)window_sub_mag + 0) = (saddr) TWindowSubMag__class_name;
    window_sub_mag->parent = arg1;
    window_sub_mag->client_id = arg2;
    window_sub_mag->list = window_sub_mag->setup_list();
    window_sub_mag->help = 0;
    window_sub_mag->slotwin = 0;
    window_sub_mag->card = 0;
    window_sub_mag->list2 = 0;
    window_sub_mag->photon = 0;
    window_sub_mag->message = 0;
    window_sub_mag->mag = 0;
    window_sub_mag->displayed_item = -1;
    window_sub_mag->state = 0;
    window_sub_mag->timer = 0;
    return window_sub_mag;
}

TWindowSubMag::~TWindowSubMag() {
    if (message != 0U) {
        ((TObject *)message)->queue_destruction();
        message = 0U;
    }
    if (photon != 0U) {
        ((TWindowBase *)photon)->close();
        photon = 0U;
    }
    if (list2 != 0U) {
        ((TWindowBase *)list2)->close();
        list2 = 0U;
    }
    if (card != 0U) {
        ((TWindowBase *)card)->close();
        card = 0U;
    }
    if (slotwin != 0U) {
        ((TWindowBase *)slotwin)->close();
        slotwin = 0U;
    }
    if (help != 0U) {
        ((TWindowBase *)help)->close();
        help = 0U;
    }
    if (list != 0U) {
        ((TWindowBase *)list)->close();
        list = 0U;
    }
}

#define self ((TWindowSubMag_8027B888 *)this)
void TWindowSubMag::run_task() {
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
            ((TWindowBase *)self->card)->close();
            self->card = NULL;
        }
        if (self->help == NULL) {
            w = TObject::operator new(0xBC);
            if (w != NULL) {
                w = __ct__15TWindowHelpItemFPvUs(w, get_window_layout_position(9), self->client_id);
            }
            self->help = w;
            TWindowSubEquip__sub_80263AF8((saddr)self->parent, 5);
            set_depth__11TWindowBaseFf(self->help);
        }
        if (self->slotwin == NULL) {
            self->slotwin = fn_802628C0(get_window_layout_position(0xC), lbl_8044F9E8, self->client_id);
        }
        ((TWindowHelpItem *)(self->help))->sub_80255E24();
        ((TWindowSubMag *)((saddr)self->list))->init_and_setup((void*)2);
        ((TWindowMenuIconLine *)(self->list))->clear_decided();
        ((TWindowSubMag *)(self->list))->start_scroll((188.0f));
        self->state = 2;
    case 2:
        ((TWindowSubMag *)self)->update_displayed_item();
        self->mag_state = ((TWindowSubMag *)(self->help))->get_mag_state();
        ((TWindowSubMag *)(self->slotwin))->set_mag_slot_state(((TWindowSubMag *)(self->help))->get_mag_state());
        if (((TWindowMenuIconLine *)(self->list))->is_cancelled() != 0) {
            self->parent->m7();
            self->state = 0x11;
        } else if (((TWindowMenuIconLine *)(self->list))->is_decided() != 0) {
            self->state = 3;
        }
        break;
    case 3:
        if (self->effect != NULL) {
            ((TObject *)(self->effect))->queue_destruction();
            self->effect = NULL;
        }
        if (self->photon != NULL) {
            ((TWindowBase *)self->photon)->close();
            self->photon = NULL;
        }
        if (self->list2 != NULL) {
            ((TWindowBase *)self->list2)->close();
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
            self->card = ((TWindowSubMag *)self)->create_action_menu(((TWindowMenuIconLine *)self->list)->get_cursor_value());
        }
        ((TWindowSubComCard *)(self->card))->clear_flag_and_release();
        self->state = 4;
    case 4:
        if (((TWindowMenu *)(self->card))->is_cancelled() != 0) {
            self->state = 1;
        } else if (((TWindowMenu *)(self->card))->is_decided() != 0) {
            ((TWindowSubMag *)self)->set_mag_mode(((TWindowMenu *)self->card)->get_selected_value());
        }
        break;
    case 5:
        if (self->card != NULL) {
            ((TWindowBase *)self->card)->close();
            self->card = NULL;
        }
        ((TWindowSubStatusDisp *)(self->list))->init_scroll_pos();
        ((TWindowHelpItem *)(self->help))->update_help_item(1);
        ((TWindowHelpItem *)(self->help))->set_flag60_bit4();
        if (self->list2 == NULL) {
            self->list2 = (void *)((TWindowSubMag *)self)->create_list();
        }
        ((TWindowMenuIconLine *)(self->list2))->clear_decided();
        self->state = 6;
    case 6:
        if (((TWindowMenuIconLine *)(self->list2))->is_cancelled() != 0) {
            self->state = 3;
        } else if (((TWindowMenuIconLine *)(self->list2))->is_decided() != 0) {
            self->state = 7;
        }
        break;
    case 7:
        if (TWindowShortListCtrl__check_controller_button(controller_input_state[port].sub, 2) != 0 ||
            test_controller_flag_4c_color(controller_input_state[4].sub, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            self->state = 5;
        } else if (TWindowSubItem::is_usable((saddr)player) != 0) {
            self->slots = ((TWindowSubMag *)self)->count_slots();
            TWindowSubMag::feed_mag((void*)player, (void*)(((TWindowMenuIconLine *)self->list)->get_cursor_value()), (void*)(((TWindowMenuIconLine *)self->list2)->get_cursor_value()));
            self->state = 8;
        }
        break;
    case 8:
        window_request_show(self->help);
        window_request_refresh((u8 *)self->help);
        ((TWindowSubMag *)(self->help))->set_flag60_bit8();
        ((TWindowHelpItem *)(self->help))->refresh_copied_items();
        ((TWindowSubMag *)((saddr)self->list))->init_and_setup((void*)2);
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
            ((TWindowHelpItem *)(self->help))->update_help_item(2);
            self->effect = ((TWindowSubMag *)self)->create_learned_blast_toast();
            self->state = 13;
        } else {
            self->state = 3;
            break;
        }
    case 13:
        if ((f32)self->timer++ > (9e+01f) && self->effect != NULL) {
            ((TWindowBase *)self->effect)->close();
            self->effect = NULL;
            self->state = 3;
        }
        break;
    case 14:
        if (self->card != NULL) {
            ((TWindowBase *)self->card)->close();
            self->card = NULL;
        }
        if (self->help != NULL) {
            ((TWindowLockOn *)(self->help))->request_close();
            ((TWindowSubMag *)(self->help))->set_flag60_bit8();
            ((TWindowHelpItem *)(self->help))->set_flag60_bit4();
        }
        w = TObject::operator new(0x74);
        if (w != NULL) {
            w = TWindowSubMagPhoton__ct(w, get_window_layout_position(0xA), self->mag_state, self->client_id);
        }
        self->photon = w;
        TWindowSubEquip__sub_80263AF8((saddr)self->parent, 3);
        set_depth__11TWindowBaseFf(self->photon);
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
        if ((u32)((TObjPlayer *)player)->is_action_active() == 0) {
            self->state = 1;
        }
        break;
    case 17:
        break;
    }
}
#undef self

void TWindowSubMag::render() {  }

s32 TWindowSubMag::setup_list() {
    saddr equip_kind_window;
    s32 window_layout_position;

    window_layout_position = get_window_layout_position(7);
    equip_kind_window = create_equip_kind_window(window_layout_position, lbl_8044F9F0, this->client_id);
    ((TWindowMenuIconLine *)equip_kind_window)->ensure_status_display((saddr)TWindowSubStatusDisp::get_message_10(0x29));
    TWindowSubEquip__sub_80263AF8(this->parent, 0);
    set_depth__11TWindowBaseFf((void *)equip_kind_window);
    ((TWindowSubShortCutList *)equip_kind_window)->set_flag70_bit10();
    ((TWindowSubMag *)equip_kind_window)->init_and_setup((void*)2);
    return equip_kind_window;
}

saddr TWindowSubMag::create_list() {
    saddr equip_kind_window;

    s32 window_layout_position = get_window_layout_position(0xD);
    equip_kind_window = create_equip_kind_window(window_layout_position, lbl_8044F9F8, this->client_id);
    ((TWindowMenuIconLine *)equip_kind_window)->ensure_status_display((saddr)TWindowSubStatusDisp::get_message_10(0x24));
    TWindowSubEquip__sub_80263AF8(this->parent, 2);
    set_depth__11TWindowBaseFf((void *)equip_kind_window);
    ((TWindowSubShortCutList *)equip_kind_window)->set_flag70_bit10();
    ((TShopArmorListWindow *)equip_kind_window)->close_list();
    return equip_kind_window;
}

// dead-stripped: only its literals survive. 2.0f (.sdata2 0x805DD668) is pooled after create_action_menu's
// 172.0f and ahead of run_task's literals, but its one live user is_mag_full is generated last (deferred
// codegen runs this file bottom-up), so a function generated between create_action_menu and create_list
// used it first. Minimal body after is_mag_full's check; name inferred.
static int is_mag_fed_full(TItemMag *mag) {
    return mag->feeds_while_full >= 2.0f;
}

void *TWindowSubMag::create_action_menu(s32 id) {
    TWindowSubMag_8027B62C *menu = (TWindowSubMag_8027B62C *)this;
    s32 mag[4];
    void *window;
    u8 *item;
    ((MagStats *)mag)->init();
    item = (u8 *)find_item_by_id(id);
    window = (void *)create_titled_window_menu(get_window_layout_position(8), 2, (saddr)TWindowSubStatusDisp::get_message_10(0x1D), menu->field_0x28);
    TWindowSubEquip__sub_80263AF8(menu->field_0x30, 1);
    set_depth__11TWindowBaseFf(window);
    if (((s32 (*)(u8 *))is_mag_full)(item) != 0) {
        add_gray_text_entry((TWindowSubTradeMain *)window, (const char *)(TWindowSubStatusDisp::get_message_10(0x65)), 6, 1);
    } else {
        forward_trade_action_default__16TObjCityMainWarpFPviii(window, (saddr)TWindowSubStatusDisp::get_message_10(0x65), 6, 1);
    }
    TItemData::deserialize_mag((void *)(menu->field_0x2c), (void *)mag);
    if (((MagStats *)mag)->get_photon_blast(0) != -1) {
        forward_trade_action_default__16TObjCityMainWarpFPviii(window, (saddr)TWindowSubStatusDisp::get_message_10(0x64), 6, 0);
    } else {
        add_gray_text_entry((TWindowSubTradeMain *)window, (const char *)(TWindowSubStatusDisp::get_message_10(0x64)), 6, 0);
    }
    ((TWindowMenu *)window)->set_flag70_bit10();
    ((TWindowMenu *)window)->update_layout_height((172.0f));
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(window));
    return window;
}

void *TWindowSubMag::create() {
    void *temp_r31;
    s32 window_layout_position;

    window_layout_position = get_window_layout_position(0xB);
    temp_r31 = TWindowMessage::create(window_layout_position, lbl_8044FA00, 1, this->client_id);
    TWindowSubEquip__sub_80263AF8(this->parent, 4);
    set_depth__11TWindowBaseFf(temp_r31);
    *(s32 *)((s8 *)temp_r31 + 0x5C) = 0x186A0;
    call_if_split_screen(temp_r31, this->client_id);
    return temp_r31;
}

#pragma push
#pragma fp_contract on
void *TWindowSubMag::create_learned_blast_toast() {
    Item_8027B424 item;
    NJS_POINT2 pos;
    NJS_POINT2 size;
    f32 scale;
    s32 n;
    void *win;
    ((MagStats *)((s32 *)&item))->init();
    TItemData::deserialize_mag((void *)(*(saddr *)&this->mag), (void *)((s32 *)&item));
    n = ((MagStats *)((s32 *)&item))->get_photon_blast(*(s8 *)&this->slots);
    if (n == -1) {
        return 0;
    }
    text_builder_reset();
    TWindowSubStatusDisp::get_message_10(0x64);
    text_builder_append();
    append_text_space();
    get_photon_blast_name(n);
    text_builder_append();
    TWindowSubStatusDisp::get_message_10(0x4C);
    text_builder_append();
    get_shared_text_buffer();
    n = calc_text_width();
    if (TCameraCtrl::get_camera_id() > 2) {
        scale = 0.85f;
    } else {
        scale = 1.0f;
    }
    copy_vec2((&pos), (void*)(get_window_layout_position(0xE)));
    pos.x -= (0.5f * n + 4.0f) * scale;
    size.x = 8.0f + n;
    size.y = 40.0f;
    win = TWindowMessage::create((saddr)&pos, &size.x, 1, *(s32 *)&this->client_id);
    TWindowSubEquip__sub_80263AF8(*(s32 *)&this->parent, 6);
    set_depth__11TWindowBaseFf(win);
    ((TWindowMessage *)win)->append_line((saddr)((s32 *)get_shared_text_buffer()), (int)2);
    ((TWindowAddition *)win)->set_position_xy(scale, scale);
    return win;
}
#pragma pop

void TWindowSubMag::set_mag_mode(s32 arg1) {
    switch (arg1) {
    case 1:
        this->state = 5;
        return;
    case 0:
        this->state = 0xE;
        return;
    }
}

s32 TWindowSubMag::count_slots() {
    s32 sp8;
    s32 slot;

    ((MagStats *)(&sp8))->init();
    TItemData::deserialize_mag((void *)(this->mag), (void *)(&sp8));
    slot = 0;
loop_1:
    if (((MagStats *)(&sp8))->get_photon_blast(slot) == -1) {
        return slot;
    }
    slot += 1;
    if (slot >= 3) {
        return slot;
    }
    goto loop_1;
}

void TWindowSubMag::update_displayed_item() {
    s32 temp_r3;

    temp_r3 = ((TWindowMenuIconLine *)this->list)->get_cursor_value();
    if (temp_r3 != (s32) this->displayed_item) {
        this->displayed_item = temp_r3;
        TWindowHelpItem__set_displayed_item_by_id((u8 *)this->help, temp_r3);
    }
}

void TWindowSubMag::update_mag_help() {
    s32 temp_r3;

    toggle_help_window_on_button(this->message, this->client_id);
    temp_r3 = ((TWindowSubMag *)(this->photon))->get_selected_blast();
    if (temp_r3 != (s8) this->m_1d) {
        this->m_1d = (u8) temp_r3;
        if (temp_r3 == -1) {
            ((TWindowMessage *)(this->message))->append_line((saddr)((s32 *)lbl_805DD648), (int)0x80);
            return;
        }
        ((TWindowMessage *)(this->message))->append_line((int)(get_help_text_string(temp_r3 + 0x27)), (int)0x80);
    }
}

}
