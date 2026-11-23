#pragma defer_codegen on

#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowMainMenu_80263AB0.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowHelpItem_80255AB4.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/ui/window/TWindowSubCustomEquip_80275D9C.h"
#include "pso/ui/window/TWindowSubCustomSelect_80275D84.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/unk/text_80076E84.h"
#include "pso/unk/text_80263A20.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TCustomizeMenuCtrl.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubCustomEquip.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubCustomSelect.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/Language.h"
#include "pso/system/task/TObject.h"
#include "pso/weapon/WeaponSpecialSelection.h"
#include "pso/player/PlayerSlots.h"


struct Win_802758C8 {
    u8 pad0[0x20];
    s32 player;
    u8 pad24[0x30 - 0x24];
    saddr lobby;
    u16 kind;
    u16 id;
};

struct Ev_802758C8 {
    u16 kind;
    u16 id;
};

class VObj_80275A8C {
public:
    u8 pad0[0x18];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
};

struct Self_80275A8C {
    u8 pad0[0x1C];
    u8 state;
    u8 pad1d[3];
    s32 f20;
    VObj_80275A8C *f24;
    s32 f28;
    void *f2c;
};

extern "C" {
s32 *get_shared_text_buffer(void);
u8 get_cast_technique_level(void *, s16);
void text_builder_append_int(s32);
void text_builder_append();
u8 *calc_technique_parameters(u16, u8, s32);
}

void text_builder_reset();
s32 get_palette_consumable_count(u16, s32);

extern "C" {
void *get_window_layout_position(s32);
extern const f32 lbl_8044F718[2] = {190.0f, 168.0f};
}

TCustomizeMenuCtrl::TCustomizeMenuCtrl(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    main_menu = parent;
    client_id = client;
    custom_equip = (uaddr)new TWindowSubCustomEquip(client_id);
    ((TWindowBase *)custom_equip)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)main_menu, 0));
    help_window = (uaddr)TWindowMessage::create((saddr)(get_window_layout_position(0x11)), lbl_8044F718, 1, client_id);
    ((TWindowBase *)help_window)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)main_menu, 2));
    call_if_split_screen(help_window, client_id);
    custom_select = 0;
    help_kind = 0;
    help_id = 0;
    state = 0;
}

TCustomizeMenuCtrl::~TCustomizeMenuCtrl() {
    if ((void *)custom_select != NULL) {
        ((TWindowBase *)custom_select)->close();
        custom_select = 0;
    }
    if ((void *)help_window != NULL) {
        ((TWindowBase *)help_window)->close();
        help_window = 0;
    }
    if ((void *)custom_equip != NULL) {
        ((TWindowBase *)custom_equip)->close();
        custom_equip = 0;
    }
}

void TCustomizeMenuCtrl::run_task() {
    Self_80275A8C *self = (Self_80275A8C *)this;
    Ev_802758C8 ev;
    switch (self->state) {
    case 0:
    case 1:
        if (self->f2c != NULL) {
            ((TWindowBase *)self->f2c)->close();
            self->f2c = NULL;
        }
        ((TWindowSubCustomEquip *)(this->custom_equip))->clear_flag_and_set_entry_state();
        self->state = 2;
    case 2:
        ((TWindowSubCustomEquip *)(this->custom_equip))->get_cursor_pos(&ev);
        ((TCustomizeMenuCtrl *)self)->update_customize_help_text(&ev);
        if (TWindowSubCustomEquip__sub_80275DA8((void *)this->custom_equip) != 0) {
            self->f24->v7();
            self->state = 5;
        } else if (((TWindowSubCustomEquip *)(this->custom_equip))->is_selected() != 0) {
            self->state = 3;
        }
        break;
    case 3:
        self->f2c = new TWindowSubCustomSelect(client_id);
        ((TWindowBase *)self->f2c)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)self->f24, 1));
        self->state = 4;
    case 4:
        ((TCustomizeMenuCtrl *)self)->update_customize_help_text(static_cast<TWindowSubCustomSelect *>(self->f2c)->get_selected_action());
        if (fn_80275D90(self->f2c) != 0) {
            self->state = 1;
        }
        if (((TWindowSubCustomSelect *)(self->f2c))->is_active() != 0) {
            void *e = static_cast<TWindowSubCustomSelect *>(self->f2c)->get_selected_action();
            ((TWindowSubCustomEquip *)(this->custom_equip))->toggle_action_binding(e);
            self->state = 1;
        }
        break;
    case 5:
        break;
    }
}

void TCustomizeMenuCtrl::render() {  }

void TCustomizeMenuCtrl::update_customize_help_text(void *ev_arg) {
    Win_802758C8 *self = (Win_802758C8 *)this;
    Ev_802758C8 *ev = (Ev_802758C8 *)ev_arg;
    u8 *pl;
    s32 lvl;
    toggle_help_window_on_button(self->lobby, self->player);
    if (ev == NULL) {
        return;
    }
    pl = (u8 *)get_player_by_client_id(self->player);
    if (pl == NULL) {
        return;
    }
    if (self->id == ev->id && self->kind == ev->kind) {
        return;
    }
    self->kind = ev->kind;
    self->id = ev->id;
    text_builder_reset();
    switch (ev->kind) {
    case 0:
        break;
    case 2:
        if (ev->id == 2) {
            TItem *weapon = TObjPlayer::get_equipped_weapon(pl);
            if (weapon == NULL || weapon_has_extra_attack((TItemWeapon *)weapon) != 1) {
                break;
            }
        }
        get_help_text_string(ev->id + 0x13);
        text_builder_append();
        break;
    case 3:
        if (TObjPlayer::validate_and_clear_slot(pl + 0x428, ev->id) != 0) {
            break;
        }
        get_technique_name(ev->id);
        text_builder_append();
        if (ev->id != 0x11 && ev->id != 0xE) {
            lvl = get_cast_technique_level(pl + 0x428, ev->id);
            if (current_language != LANGUAGE_JAPANESE) {
                append_text_space();
            }
            get_help_text_string(0x2D);
            text_builder_append();
            text_builder_append_int(lvl + 1);
        }
        get_help_text_string(0x2E);
        text_builder_append();
        text_builder_append_int(*(s16 *)(calc_technique_parameters(ev->id, lvl, 0xFFFF) + 0x10));
        get_help_text_string(ev->id);
        text_builder_append();
        break;
    case 4:
        if (get_palette_consumable_count(ev->id, self->player) == -1) {
            break;
        }
        get_help_text_string(ev->id + 0x16);
        text_builder_append();
        break;
    case 7:
        break;
    }
    ((TWindowMessage *)(self->lobby))->append_line((saddr)get_shared_text_buffer(), 0x82);
}
