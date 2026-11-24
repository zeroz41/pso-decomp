#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TProtocol.h"
#include "pso/player/TPlyDispData.h"
#include "pso/ui/window/TWindowFukidasi.h"
#include "pso/ui/window/TWindowCtrl_8024A1A8.h"
#include "pso/ui/window/WindowCtrlCallback.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/object/base/TObjChara.h"
#include <stddef.h>
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowTimer.h"
#include "pso/ui/window/TWindowArea.h"
#include "pso/object/switch/TOChatSensorCapture.h"
#include "pso/unk/text_8024AADC.h"
#include "pso/unk/text_8024AB18.h"
#include "pso/unk/text_8024AB98.h"
#include "pso/unk/text_8024AB54.h"
#include "pso/unk/text_8024AC64.h"
#include "pso/unk/text_8024ACA8.h"
#include "pso/unk/text_8024ACEC.h"
#include "pso/unk/text_8024AD30.h"
#include "pso/ui/window/TWindowCtrl_8024ADAC.h"
#include "pso/ui/window/TWindowCtrl_8024B048.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/window/TWindowCtrl_8024B1A0.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowSetLevelUp.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowEffectParty.h"
#include "pso/ui/window/TWindowCtrl_8024B7D4.h"
#include "pso/ui/window/TWindowTradeRequest.h"
#include "pso/ui/window/TWindowGetComCard.h"
#include "pso/ui/window/TWindowSimpleStatus.h"
#include "pso/ui/window/TWindowCtrl_8024B9C0.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/chat/TWindowSubShortMail_80246CB8.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/ControllerInput.h"
#include "pso/math/AngleLookup.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal_8002ADD8.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_8030C340.h"
#include "pso/ui/window/TWindowBreakIn.h"
#include "pso/object/TObjLuker.h"
#include "pso/ui/window/TWindowMainMenu_8024E3CC.h"
#include "pso/unk/text_8026AC50.h"
#include "pso/unk/text_8026ACDC.h"
#include "pso/unk/text_80076BC4.h"

TWindowCtrl *TWindowCtrl::instance;
u16 lbl_805D63FC;

extern "C" {

s32 get_multiplayer_controller_active_index(s32);

}

extern "C" {

s32 TLobby__sub_80077798(s32, s32 *);

s32 open_hard_keyboard__6TLobbyFPv(s32);

extern s32 local_client_id;

}

struct RecoveredFields_8024A688_arg1
{
  u8 unknown_0[0x38];
  f32 field_38;
  f32 field_3C;
  f32 field_40;
};

struct RecoveredFields_8024A688_temp_r3
{
  u8 unknown_0[0x38];
  f32 field_38;
  f32 field_3C;
  f32 field_40;
};

struct Ctrl_8024A928 { u8 pad[0x84]; void *slots[4]; };

struct Ctrl_8024A714 { u8 pad[0x84]; void *arr[4]; };

struct Obj_8024A7CC { u8 pad[0x84]; void *arr[4]; };

struct Obj_8024AA08 { u8 pad[4]; u32 f4; };

struct Ply_8024AA08 { u8 pad[0xDB0]; u32 f; };

extern "C" {

s32 TWindowCtrl__sub_8024A314(void);

void TLobby__sub_8024AAA0(s32 arg0, s32 arg1);

u32 get_window__11TWindowCtrlFl(void);
s32 update_field28__15TWindowCtrlMainFv(u32 a0 = 0, s32 a1 = 0);

void TWindowCtrl__sub_8024A228(saddr client_id);

bool TWindowCtrl__sub_8024A1A8(void);

u8 *find_entity_by_id(u16);

f32 get_entity_distance_or_default__11TWindowCtrlFiPvUs(s32 arg0, RecoveredFields_8024A688_arg1 *arg1, u16 arg2);

extern s32 local_client_id;


void get_speaker_balloon_anchor__11TWindowCtrlFPviPvPv(Ctrl_8024A928 *arg0, s32 arg1, f32 *arg2, s32 *arg3);

}

extern "C" {

s32 free_member__15TWindowCtrlMainFv(u32 a0 = 0, s32 a1 = 0);

}

extern "C" {

saddr get_window_layout_position(s32);

}

struct Ctrl_8024B1A0 { u8 pad[0x1C]; u16 flags; };

struct Win_8024B1A0 { u8 pad[0x40]; f32 x; f32 y; f32 w; f32 h; };

struct Ctrl_8024B328 { u8 pad[0x84]; void *win[4]; };

struct Ctrl_8024B3B4 { u8 pad[0x84]; void *win[4]; };

struct Ctrl_8024B440 { u8 pad[0x84]; void *win[4]; };

extern "C" {

s32 post_chat_log_message();

extern s32 local_client_id;

}

extern "C" {

s32 update_child_2c__15TWindowCtrlMainFv(u32, s32, s32);

}

extern "C" {

int set_window_flags__11TWindowCtrlFPvll(void*, void*, void*);

}


const char *TWindowCtrl__name = "TWindowCtrl";
/* frame of the open sequence at which each window appears: split screen / single player */
static const s16 split_open_times[6] = {0, 4, 8, 12, 0, 0};
static const s16 open_times[4] = {24, 30, 36, 0};

typedef struct Ctrl_8024B8A0 {
    u8 pad0[0x1E];
    s16 timer;
    u8 pad20[4];
    u32 color;
} Ctrl_8024B8A0;

extern "C" {

s32 TWindowCtrl__sub_8024B000(void *, saddr);

extern s32 local_client_id;

}

extern "C" void TWindowCtrl__sub_8024BB30(TWindowCtrl *ctrl);

extern "C" {

s32 apply_default_vec__11TWindowCtrlFll(void *, s32);

}


typedef struct Win_8024BE80 {
    u8 pad0[0x34];
    f32 y;
    u8 pad38[0x50 - 0x38];
    s32 fade;
} Win_8024BE80;

typedef struct Ctrl_8024BE80 {
    u8 pad0[0x78];
    Win_8024BE80 *slots[3];
} Ctrl_8024BE80;

void window_request_show(void *);

extern "C" {

void TWindowCtrl__sub_8024BB30(TWindowCtrl *ctrl);

}

typedef struct Win_8024C024 {
    u8 pad0[0x50];
    s32 fade;
} Win_8024C024;

typedef struct Ctrl_8024C024 {
    u8 pad0[0x1E];
    s16 timer;
    s16 step;
    u8 pad22[0x48 - 0x22];
    Win_8024C024 *split[12];
    Win_8024C024 *slots[3];
} Ctrl_8024C024;

struct TWindowCtrl_8024C160 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1C[0x2C - 0x1C];
    void *f2C;
    void *f30;
    void *f34;
    void *f38;
    void *f3C;
    void *f40;
    void *f44;
    void *objs[12];
    void *wins78[3];
    void *wins84[4];
};

struct TWindowCtrl_8024C308 {
    const char *name;
    u8 pad4[0x18 - 0x4];
    void *vt;
    s16 f1C;
    s16 f1E;
    s16 f20;
    s16 f22;
    s32 f24;
    u16 f28;
    void *f2C;
    void *f30;
    void *f34;
    void *f38;
    void *f3C;
    void *f40;
    void *f44;
    void *objs[12];
    void *wins78[3];
    void *wins84[4];
    u8 f94[4];
};

extern "C" {

void *__ct__11TWindowChatFP7TObjectPv(void *, TObject *, void *);

void *__ct__17TWindowCtrlPlayerFP7TObjectl(void *, void *, s32);
extern s32 local_client_id;

}

LAYOUT_ASSERT(WindowCtrlFlagsOffset, offsetof(TWindowCtrl, flags) == 0x1C);
LAYOUT_ASSERT(WindowCtrlChildOffset, offsetof(TWindowCtrl, m_3c) == 0x3C);

s32 TWindowSimpleStatus::get_width() { return this->client_index; }

s16 TWindowFukidasi::get_field_20() { return this->client_index; }

s32 TWindowCtrl::is_visible() { return this->flags & 0x1; }

s32 TWindowCtrl::is_status_window_hidden() {
    return (this->flags >> 4) & 1;
}

int TWindowCtrl::is_enabled() { return (this->flags >> 3) & 0x1; }

s32 TWindowCtrl::is_lock_on_window_hidden() {
    return (this->flags >> 2) & 1;
}

s32 TWindowCtrl::is_main_menu_disabled() {
    return (this->flags >> 1) & 1;
}

s32 TWindowCtrl::has_get_com_card_window() {
    return this->m_3c != 0 ? 1 : 0;
}

void TWindowCtrl::clear_flag_bit0() {
    this->flags &= ~1;
    TRaderMapCore::show_radar();
}

void TWindowCtrl::set_radar_dirty_flag() {
    this->flags |= 1;
    TRaderMapCore::hide_radar();
}

void TWindowCtrl::show_status_window() {
    this->flags &= ~0x10;
}

void TWindowCtrl::hide_status_window() {
    this->flags |= 0x10;
}

void TWindowCtrl::end_keyboard_hold() {
    this->flags &= ~0x8;
}

void TWindowCtrl::begin_keyboard_hold() {
    this->flags |= 0x8;
}

void TWindowCtrl::show_lock_on_window() {
    this->flags &= ~0x4;
}

void TWindowCtrl::hide_lock_on_window() {
    this->flags |= 0x4;
}

void TWindowCtrl::enable_main_menu() {
    this->flags &= ~0x2;
}

void TWindowCtrl::disable_main_menu() {
    this->flags |= 0x2;
}

void TWindowCtrl::release_balloon_slot_0() {
    this->flags &= ~0x40;
}

void TWindowCtrl::reserve_balloon_slot_0() {
    this->flags |= 0x40;
}

extern "C" {

s32 TWindowCtrl::get_display_flag() {
    if (is_split_screen() != 0) {
        return 0;
    }
    if (instance == NULL) {
        return 0;
    }
    return ((u16) instance->flags >> 1U) & 1;
}

}

s32 TWindowCtrl::get_flag_bit5() {
    if (instance == NULL) {
        return 0;
    }
    return ((u16) instance->flags >> 5U) & 1;
}

s32 TWindowCtrl::get_flag_bit4() {
    if (instance == NULL) {
        return 0;
    }
    return ((u16) instance->flags >> 4U) & 1;
}

saddr TWindowCtrl::get_window(s32 client_id) {
    if (instance == NULL) {
        return 0;
    }
    if (client_id < 0) {
        return 0;
    }
    if (client_id >= 0xC) {
        return 0;
    }
    return ((saddr *)((s8 *)instance + 0x48))[client_id];
}

extern "C" {

int TWindowFukidasi::get_flag_bit1() { return ((this->m_71) >> 1) & 0x1; }

}

extern "C" {

u16 TWindowFukidasi::get_speaker_id() { return this->speaker_id; }

}

extern "C" {

void TWindowCtrl::set_flag1e_bit40() { this->m_1e |= 0x40; }

}

extern "C" {

s32 TWindowCtrl__sub_8024C5C4(const TWindowChat *chat) {
    if (chat->flags & 2) return 0;
    return 1;
}

}

void TWindowCtrl::clear_flag1e_bit8() { this->m_1e &= 0xfffffff7; }

void TWindowCtrl::set_flag1e_bit8() { this->m_1e |= 0x8; }

int TWindowCtrl::is_flag_2_set() { return this->m_flags & 0x4; }

void TWindowCtrl::close() {
    TWindowMainMenu__sub_8024E3D0();
    TLobby__sub_8026ACDC();
    instance = NULL;
}

void TWindowCtrl::shutdown() {
    if (instance != NULL) {
        instance->queue_destruction();
        instance = NULL;
    }
    fn_8026AC50();
    TWindowMainMenu__sub_8024E3CC();
}

extern "C" {

TWindowCtrl::TWindowCtrl(TObject *parent) : TObject(parent) {
    TWindowCtrl_8024C308 *self = (TWindowCtrl_8024C308 *)this;
    s32 i;
    void *p;
    self->name = TWindowCtrl__name;
    if (instance != NULL) {
        instance->queue_destruction();
    }
    instance = this;
    self->f1C = 0;
    self->f1E = 0;
    self->f20 = 0;
    self->f22 = 0;
    self->f24 = 0;
    self->f28 = 0xFFFF;
    self->f2C = NULL;
    self->f30 = NULL;
    self->f34 = NULL;
    self->f38 = NULL;
    self->f3C = NULL;
    self->f40 = NULL;
    self->f44 = NULL;
    for (i = 0; i < 12; i++) {
        self->objs[i] = NULL;
    }
    for (i = 0; i < 3; i++) {
        self->wins78[i] = NULL;
    }
    for (i = 0; i < 4; i++) {
        self->wins84[i] = NULL;
    }
    p = new TWindowBreakIn();
    self->f2C = p;
    if (is_split_screen() == 0) {
        p = TObject::operator new(0x3C);
        if (p != NULL) {
            p = __ct__11TWindowChatFP7TObjectPv(p, tl_00, self->f94);
        }
        self->f38 = p;
        ((TWindowCtrl *)(self->f38))->set_flag1e_bit40();
    }
    if (is_split_screen() != 0) {
        for (i = 0; i < 4; i++) {
            p = TObject::operator new(0x40);
            if (p != NULL) {
                p = __ct__17TWindowCtrlPlayerFP7TObjectl(p, self, i);
            }
            self->objs[i] = p;
            ((TObject *)(self->objs[i]))->suspend_update();
        }
    } else {
        p = TObject::operator new(0x40);
        if (p != NULL) {
            p = __ct__17TWindowCtrlPlayerFP7TObjectl(p, self, local_client_id);
        }
        self->objs[local_client_id] = p;
        for (i = 0; i < 3; i++) {
            if (get_current_floor_area() != AREA_LOBBY && is_split_screen() == 0) {
                self->wins78[i] = create_party_status_window(i);
                ((TObject *)(self->wins78[i]))->suspend_update();
            }
        }
    }
    if (TObjPlayer::get_player_count() == 1) {
        TWindowCtrl::open_status_112();
    }
}

}

TWindowCtrl::~TWindowCtrl() {
    TWindowCtrl_8024C160 *self = (TWindowCtrl_8024C160 *)this;
    s32 i;
    for (i = 3; i >= 0; i--) {
        if (self->wins84[i] != NULL) {
            ((TWindowBase *)(self->wins84[i]))->close();
            self->wins84[i] = NULL;
        }
    }
    if (self->f44 != NULL) {
        ((TWindowBase *)self->f44)->close();
        self->f44 = NULL;
    }
    if (self->f34 != NULL) {
        ((TWindowBase *)self->f34)->close();
        self->f34 = NULL;
    }
    if (self->f30 != NULL) {
        ((TWindowBase *)self->f30)->close();
        self->f30 = NULL;
    }
    if (self->f40 != NULL) {
        ((TObject *)self->f40)->queue_destruction();
        self->f40 = NULL;
    }
    if (self->f3C != NULL) {
        ((TObject *)self->f3C)->queue_destruction();
        self->f3C = NULL;
    }
    for (i = 2; i >= 0; i--) {
        if (self->wins78[i] != NULL) {
            ((TWindowBase *)(self->wins78[i]))->close();
            self->wins78[i] = NULL;
        }
    }
    for (i = 11; i >= 0; i--) {
        if (self->objs[i] != NULL) {
            ((TObject *)self->objs[i])->queue_destruction();
            self->objs[i] = NULL;
        }
    }
    if (self->f38 != NULL) {
        ((TObject *)self->f38)->queue_destruction();
        self->f38 = NULL;
    }
    if (self->f2C != NULL) {
        ((TWindowBase *)self->f2C)->close();
        self->f2C = NULL;
    }
    if (instance == this) {
        instance = NULL;
    }
}

void TWindowCtrl::run_task() { update_open_sequence(); update(); TLobby::update_game_modes(); }

void TWindowCtrl::render() {  }

extern "C" {

void TWindowCtrl::update_open_sequence() {
    Ctrl_8024C024 *o = (Ctrl_8024C024 *)this;
    if (is_split_screen() != 0) {
        if (o->timer == split_open_times[o->step]) {
            if (o->split[o->step] != NULL) {
                ((TObject *)(o->split[o->step]))->clear_update_suspension();
            }
            o->step++;
        }
    } else {
        if (o->timer == open_times[o->step]) {
            if (o->slots[o->step] != NULL) {
                ((TObject *)(o->slots[o->step]))->clear_update_suspension();
                ((TWindowCtrl *)o)->update_party_status_rows();
                o->slots[o->step]->fade = 0;
            }
            o->step++;
        }
    }
    if (o->timer > 30000) {
        o->timer -= 10000;
    }
    o->timer++;
}

}

extern "C" {

void TWindowCtrl::update() { update_party_status_rows(); update_window_visibility(); update_com_card_window(); update_trade_request_window(); TWindowCtrl__sub_8024BB30(this); handle_controller(); update_trade_window(); TWindowCtrl__sub_8024B9C0(this); update_pulse_color(); }

}

extern "C" {

void TWindowCtrl::update_party_status_rows() {
    f32 y;
    u32 i;
    void *pl;
    Win_8024BE80 *w;
    y = ((TWindowLockOn *)(0xAB))->get_target_distance();
    for (i = 0; i < 3; i++) {
        w = ((Ctrl_8024BE80 *)this)->slots[i];
        if (w != NULL && ((TWindowCtrl *)w)->is_flag_2_set() == 0) {
            pl = get_player_by_client_id(((TWindowSimpleStatus *)w)->get_width());
            if (pl == NULL || TWindowCtrl::has_player_active_menu(local_client_id) != 0 ||
                TWindowCtrl::is_slot_visible(local_client_id) != 0 || TWindowCtrl__sub_8024B048(this) != 0 ||
                ((TObjPlayer *)pl)->is_script_controlled() != 0 ||
                (((TObjChara *)pl)->obj_isState3_324() != 0 &&
                 (((TObjPlayer *)pl)->get_field_828() != 0 || static_cast<TObjPlayer *>(pl)->get_npc_controller() == 0xFFFF))) {
                ((TWindowLockOn *)w)->request_close();
            } else {
                window_request_show(w);
                if (w->y != y) {
                    w->y = y;
                    w->fade = 0xF;
                }
                y += 55.0f;
            }
        }
    }
}

}

extern "C" {

void TWindowCtrl::update_window_visibility() {
    u8 *arg0 = (u8 *)this;
    s32 submit_cooldown;
    u16 current_target_id;

    if ((u32) this->m_38 != 0U) {
        submit_cooldown = this->submit_cooldown;
        if (submit_cooldown > 0) {
            this->submit_cooldown = (submit_cooldown - 1);
        }
        if (get_player_by_client_id(local_client_id) == 0U) {
            ((TWindowChat *)(this->m_38))->update();
            return;
        }
        current_target_id = TObjPlayer::get_current_target_id();
        if ((TWindowCtrl::get_display_flag() != 0) || (TWindowCtrl::has_player_active_menu(local_client_id) != 0) || (TWindowCtrl::is_slot_visible(local_client_id) != 0) || (apply_default_vec__11TWindowCtrlFll(arg0, local_client_id) != 0) || ((current_target_id != 0xffffU) && (current_target_id != local_client_id))) {
            ((TWindowChat *)(this->m_38))->update();
            return;
        }
        ((TWindowChat *)(this->m_38))->open_input();
        if ((((TWindowChat *)(this->m_38))->is_mode_bit4() != 0) && (chat_accept_submission((saddr)&this->m_94) != 0)) {
            TWindowChat__sub_80247E50(reinterpret_cast<TWindowChat *>(m_38));
        }
        if (((TWindowChat *)(this->m_38))->is_visible() != 0) {
            TWindowChat__sub_80247DFC(reinterpret_cast<TWindowChat *>(m_38));
        }
    }
}

}

extern "C" {

void TWindowCtrl::update_com_card_window() {
    TWindowGetComCard *temp_r3;
    uaddr temp_r3_2;
    TWindowGetComCard *temp_r3_3;
    temp_r3 = this->m_3c;
    if ((temp_r3 != NULL) && (temp_r3->all_parents_unqueued_for_destruction() == 0)) {
        this->m_3c = NULL;
    }
    if ((is_guild_card_receive_active() == 0) || (TWindowCtrl::has_player_active_menu(local_client_id) != 0) || (TWindowCtrl::is_slot_visible(local_client_id) != 0) || (TWindowCtrl::get_flag_bit5() != 0) || (trade_request != NULL) || ((temp_r3_2 = this->m_38, ((temp_r3_2 == 0U) == 0)) && (TWindowCtrl__sub_8024701C(reinterpret_cast<TWindowChat *>((void *)temp_r3_2)) != 0))) {
        temp_r3_3 = this->m_3c;
        if (temp_r3_3 != NULL) {
            temp_r3_3->queue_destruction();
            this->m_3c = NULL;
        }
    } else if (this->m_3c == NULL) {
        this->m_3c = new TWindowGetComCard(this);
    }
}

}

extern "C" {

void TWindowCtrl::update_trade_request_window() {
    if ((is_trade_active() == 0) || (TWindowCtrl::has_player_active_menu(local_client_id) != 0) || (TWindowCtrl::is_slot_visible(local_client_id) != 0) || (this->m_3c != 0U) || (((uaddr) *(void * *)&this->m_38 != 0U) && (TWindowCtrl__sub_8024701C(reinterpret_cast<TWindowChat *>(*(void * *)&this->m_38)) != 0))) {
        if (trade_request != NULL) {
            trade_request->queue_destruction();
            trade_request = NULL;
        }
    } else if (trade_request == NULL) {
        trade_request = new TWindowTradeRequest(this);
    }
}

}

void TWindowCtrl__sub_8024BB30(TWindowCtrl *ctrl) {
    u32 i;
    for (i = 0; i < 4; i++) {
        TWindowFukidasi *child = ctrl->balloons[i];
        if (child != 0 && child->all_parents_unqueued_for_destruction() == 0) {
            if (ctrl->window_id == child->get_speaker_id()) {
                ctrl->window_id = 0xFFFF;
            }
            ctrl->balloons[i] = 0;
        }
    }
}

extern "C" {

void TWindowCtrl::handle_controller() {
    saddr arg0 = (saddr)this;
    if ((get_current_floor_area() == AREA_LOBBY) && (TWindowCtrl::is_slot_visible(local_client_id) == 0) && (TWindowCtrl__sub_8024B000((void *)arg0, (s32)local_client_id) == 0) && (TWindowCtrl::has_player_active_menu(local_client_id) == 0) && (test_pressed_buttons_packed(&controller_input_state.controllers[0], fn_8002AE08(local_client_id)) != 0)) {
        TWindowCtrlMain::advance_card_status(local_client_id);
    }
}

}

extern "C" {

void TWindowCtrl::update_trade_window() {
    if (this->m_34 != NULL) {
        if ((TWindowCtrl::is_slot_visible(local_client_id) != 0) || (TWindowCtrl__sub_8024B000(this, local_client_id) != 0) || ((is_split_screen() != 0) && (TRaderMapCore::is_active() == 0))) {
            ((TWindowLockOn *)(this->m_34))->request_close();
            return;
        }
        window_request_show((void *)this->m_34);
    }
}

}

extern "C" {

void TWindowCtrl__sub_8024B9C0(void *arg0) {
    if ((u32) *(u32 *)((s8 *)arg0 + 0x30) != 0U) {
        if (TWindowCtrl::is_slot_visible(local_client_id) != 0) {
            ((TWindowLockOn *)(*(uaddr *)((s8 *)arg0 + 0x30)))->request_close();
            return;
        }
        window_request_show((void *)(*(uaddr *)((s8 *)arg0 + 0x30)));
    }
}

}

extern "C" {

#pragma push

#pragma fp_contract on
void TWindowCtrl::update_pulse_color() {
    Ctrl_8024B8A0 *o = (Ctrl_8024B8A0 *)this;
    f32 t;
    f32 a;
    t = (u32)o->timer % 100;
    if (t > 50.0f) {
        t = 100.0f - t;
    }
    t = t / 100.0f;
    a = 0.85f * (1.0f + cos_table_lookup((s32)(65536.0f * t)));
    if (a > 1.0f) {
        a = 1.0f;
    }
    o->color = (u8)(s32)(53.0f * a + 19.0f * (1.0f - a)) |
               ((((u8)(s32)(255.0f * a + 187.0f * (1.0f - a)) << 16) | 0xFF000000) |
                ((u8)(s32)(174.0f * a + 83.0f * (1.0f - a)) << 8));
}

#pragma pop

}

extern "C" {

saddr TWindowCtrl__sub_8024B7D4(s32 n) {
    s32 i;
    TWindowSimpleStatus *status;
    TObjPlayer *player;

    if (TWindowCtrl::instance == NULL) {
        return 0;
    }
    if (get_current_floor_area() == AREA_LOBBY) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        status = TWindowCtrl::instance->simple_status[i];
        if (status != NULL && status->sub_80244994() != 0 && n-- == 0) {
            player = get_player_by_client_id(((TWindowSimpleStatus *)status)->get_width());
            if (player == NULL) {
                return 0;
            }
            return (saddr)player->get_name();
        }
    }
    return 0;
}

}

void TWindowCtrl::dispatch_to_child(s32 client, s32 kind) {
    uaddr *p = (uaddr *)instance;
    if (p != 0 && p[client + 18] != 0U) {
        ((TWindowCtrlMain *)p[client + 18])->spawn_palette_slot_light(kind);
    }
}

void TWindowCtrl::create_party_effect(u16 from, u16 to) { TWindowEffectParty::create((void *)tl_07, from, to, 0); }

extern "C" {

void TWindowCtrl::show_party_effect(u16 from, u16 to, u32 kind) { TWindowEffectParty::create((void *)tl_07, from, to, kind); }

}

void TWindowCtrl::init_all_default() {
    TWindowCtrl::init_all(this, 0);
}

extern "C" {

void TWindowCtrl::init_all(void* p, void* a1) { { saddr i; for (i = 0; i < 12; i++) { set_window_flags__11TWindowCtrlFPvll((void*)i, p, a1); } } }

}

void TWindowCtrl::set_window_flags_off(s32 client, s32 flags) {
    TWindowCtrl::set_window_flags((void *)(saddr)client, flags, 0);
}

extern "C" {

void TWindowCtrl::set_window_flags(void *client_id, s32 flags, s32 arg2) {
    u32 window;

    window = (u32)TWindowCtrl::get_window((saddr)client_id);
    if (window != 0U) {
        update_child_2c__15TWindowCtrlMainFv(window, flags, arg2 | 0xE);
    }
}

}

void TWindowCtrl::create_level_up_window(saddr stats, saddr client) {
    new TWindowSetLevelUp(tl_07, stats, client);
}

int TWindowCtrl::open_default(u16 id, const char *text) { return TWindowCtrl::open(id, text, 15); }

extern "C" {

saddr TWindowCtrl::open(u16 id, const char *text, s32 flags) {
    saddr temp_r3;

    if (instance == NULL) {
        return 0;
    }
    if (flags & 0x40) {
        post_chat_log_message();
    }
    temp_r3 = (saddr)instance->show_chat_balloon(id, flags, text, static_cast<s32>(local_client_id));
    if (temp_r3 == 0) {
        return 0;
    }
    set_text__15TWindowFukidasiFPvii((u8 *)temp_r3, (saddr)text, flags);
    return temp_r3;
}

}

s32 TWindowCtrl::open_balloon(u16 player, u8 *arg1, s32 flags, s32 client) {
    saddr temp_r3;
    if (instance == 0U) {
        return 0;
    }
    temp_r3 = reinterpret_cast<saddr>(instance->acquire_balloon_slot(player, flags, client));
    if (temp_r3 == 0) {
        return 0;
    }
    open__15TWindowFukidasiFPvPvi((u8 *)temp_r3, (u32 *)arg1, flags);
    return temp_r3;
}

s32 is_actor_speech_balloon_done(u16 id) {
    u32 i;
    void *w;
    if (TWindowCtrl::instance == NULL) {
        return 1;
    }
    for (i = 0; i < 4; i++) {
        w = ((Ctrl_8024B440 *)TWindowCtrl::instance)->win[i];
        if (w != NULL && ((TObject *)w)->all_parents_unqueued_for_destruction() != 0 && id == reinterpret_cast<TWindowFukidasi *>(w)->get_speaker_id() && is_speech_balloon_ready((u8 *)w) == 0) {
            return 0;
        }
    }
    return 1;
}

void complete_actor_speech_balloons(u16 id) {
    u32 i;
    void *w;
    if (TWindowCtrl::instance != NULL) {
        for (i = 0; i < 4; i++) {
            w = ((Ctrl_8024B3B4 *)TWindowCtrl::instance)->win[i];
            if (w != NULL && ((TObject *)w)->all_parents_unqueued_for_destruction() != 0 && id == reinterpret_cast<TWindowFukidasi *>(w)->get_speaker_id()) {
                complete_speech_balloon((u8 *)w);
            }
        }
    }
}

void TWindowCtrl::close_windows_by_flags(u16 flags) {
    u32 i;
    void *w;
    if (instance != NULL) {
        for (i = 0; i < 4; i++) {
            w = ((Ctrl_8024B328 *)instance)->win[i];
            if (w != NULL && ((TObject *)w)->all_parents_unqueued_for_destruction() != 0 && flags == reinterpret_cast<TWindowFukidasi *>(w)->get_speaker_id()) {
                ((TWindowBase *)w)->close();
            }
        }
    }
}

extern "C" {

u16 TWindowCtrl::get_window_id() {
    if (instance == NULL) {
        return 0xFFFFU;
    }
    return instance->window_id;
}

}

extern "C" {

void TWindowCtrl::set_field28(u16 arg0) {
    if (instance != NULL) {
        instance->window_id = arg0;
    }
}

}

extern "C" {

#pragma push

#pragma fp_contract on
s8 TWindowFukidasi::alloc_nearest_free_slot() {
    s32 i;
    s32 mask;
    s8 best;
    f32 cx;
    f32 cy;
    f32 bestd;
    NJS_POINT2 *m;
    f32 dx;
    f32 dy;
    f32 d;
    if (TWindowCtrl::instance == NULL) {
        return 0;
    }
    if (get_flag_bit1() != 0) {
        TWindowCtrl::instance->flags |= 0x200;
        return 3;
    }
    mask = 0x40;
    best = -1;
    i = 0;
    cx = (0.5f * ((Win_8024B1A0 *)this)->w) + ((Win_8024B1A0 *)this)->x;
    bestd = 1000000.0f;
    cy = (0.5f * ((Win_8024B1A0 *)this)->h) + ((Win_8024B1A0 *)this)->y;
    do {
        if (!(TWindowCtrl::instance->flags & mask)) {
            m = (NJS_POINT2 *)TWindowCtrl::get_message_by_type((s8)i, get_field_20());
            if (m != NULL) {
                dx = cx - m->x;
                dy = cy - m->y;
                d = (dx * dx) + (dy * dy);
                if (!(bestd <= d)) {
                    best = (s8)i;
                    bestd = d;
                }
            }
        }
        i++;
        mask <<= 1;
    } while (i < 3);
    if (best == -1) {
        best = 3;
    }
    TWindowCtrl::instance->flags |= (0x40 << best);
    return best;
}

#pragma pop

}

extern "C" {

void TWindowCtrl::release_slot(s8 *arg0) {
    s8 temp_r4;

    if (instance != NULL) {
        temp_r4 = *arg0;
        if ((temp_r4 >= 0) && (temp_r4 < 4)) {
            instance->flags &= ~(0x40 << temp_r4);
            *arg0 = -1;
        }
    }
}

}

extern "C" {

saddr TWindowCtrl::get_message_by_type(s8 type, s32 client_id) {
    saddr window;
    s32 var_r3;

    window = TWindowCtrl::get_window(client_id);
    if (window == 0) {
        return 0;
    }
    if (((TWindowCtrlMain *)window)->get_main_menu_message() != 0) {
        var_r3 = 0x4D;
    } else if (((TWindowCtrl *)window)->get_active_menu() != 0) {
        var_r3 = 0x48;
    } else {
        var_r3 = 0x43;
    }
    return get_window_layout_position(var_r3 + type);
}

}

s32 TWindowCtrl::query_window(s32 client_id, PlayerWindowQuery pmf) {
    TWindowCtrl *w = (TWindowCtrl *)TWindowCtrl::get_window(client_id);
    if (w == NULL) {
        return 0;
    }
    return (w->*pmf)();
}

s32 TWindowCtrl::is_slot_visible(s32 local_client_id) {
    PlayerWindowQuery callback = &TWindowCtrl::is_visible;
    return TWindowCtrl::query_window(local_client_id, callback);
}

int TWindowCtrl__sub_8024B048(void* p) { return (*(u16*)((char*)p + 0x1c) >> 2) & 0x1; }

s32 TWindowCtrl__sub_8024B000(void *window, saddr client_id) {
    PlayerWindowQuery callback = &TWindowCtrl::is_main_menu_disabled;
    return TWindowCtrl::query_window(client_id, callback);
}

void TWindowCtrl::apply_default_vec(s32 arg0, saddr client_id) {
    PlayerWindowQuery callback = &TWindowCtrl::has_get_com_card_window;
    TWindowCtrl::query_window(client_id, callback);
}

s32 TWindowCtrl::has_player_active_menu(s32 local_client_id) {
    PlayerWindowQuery callback = &TWindowCtrl::get_active_menu;
    return TWindowCtrl::query_window(local_client_id, callback);
}

void TWindowCtrl::call_window_method(s32 client_id, PlayerWindowCommand pmf) {
    TWindowCtrl *w = (TWindowCtrl *)TWindowCtrl::get_window(client_id);
    if (w != NULL) {
        (w->*pmf)();
    }
}

void TWindowCtrl::unsuppress_slot(s32 local_client_id) {
    PlayerWindowCommand callback = &TWindowCtrl::clear_flag_bit0;
    TWindowCtrl::call_window_method(local_client_id, callback);
}

void TWindowCtrl::suppress_slot(s32 local_client_id) {
    PlayerWindowCommand callback = &TWindowCtrl::set_radar_dirty_flag;
    TWindowCtrl::call_window_method(local_client_id, callback);
}

void TWindowCtrl::init_all_slots2() {
    saddr i;

    i = 0;
    do {
        TWindowCtrl::unsuppress_slot(i);
        i += 1;
    } while (i < 0xC);
}

void TWindowCtrl::init_all_slots() {
    saddr i;

    i = 0;
    do {
        TWindowCtrl::suppress_slot(i);
        i += 1;
    } while (i < 0xC);
}

extern "C" {

void TWindowCtrl__sub_8024ADF0(saddr client_id) {
    PlayerWindowCommand callback = &TWindowCtrl::show_status_window;
    TWindowCtrl::call_window_method(client_id, callback);
}

}

extern "C" {

void TWindowCtrl__sub_8024ADAC(saddr client_id) {
    PlayerWindowCommand callback = &TWindowCtrl::hide_status_window;
    TWindowCtrl::call_window_method(client_id, callback);
}

}

void TWindowCtrl::clear_flag_bit2() {
    if (instance != NULL) {
        instance->flags &= ~4;
    }
}

void TWindowCtrl::set_flag_bit2() {
    if (instance != NULL) {
        instance->flags |= 4;
    }
}

void end_player_keyboard_hold(saddr client_id) {
    TWindowCtrl::call_window_method(client_id, &TWindowCtrl::end_keyboard_hold);
}

void begin_player_keyboard_hold(saddr client_id) {
    TWindowCtrl::call_window_method(client_id, &TWindowCtrl::begin_keyboard_hold);
}

void TWindowReturnCity__sub_8024ACA8(saddr client_id) {
    TWindowCtrl::call_window_method(client_id, &TWindowCtrl::show_lock_on_window);
}

void fn_8024AC64(saddr client_id) {
    TWindowCtrl::call_window_method(client_id, &TWindowCtrl::hide_lock_on_window);
}

void TWindowCtrl::enable_client_main_menu(s32 client) {
    TWindowCtrl::call_window_method(client, &TWindowCtrl::enable_main_menu);
}

void TWindowCtrl::disable_client_main_menu(s32 client) {
    TWindowCtrl::call_window_method(client, &TWindowCtrl::disable_main_menu);
}

void TWindowSubComCard__sub_8024AB98(saddr client_id) {
    TWindowCtrl::call_window_method(client_id, &TWindowCtrl::release_balloon_slot_0);
}

void fn_8024AB54(saddr client_id) {
    TWindowCtrl::call_window_method(client_id, &TWindowCtrl::reserve_balloon_slot_0);
}

void close_window_if_active(s32 client) { if (TWindowCtrl::get_flag_bit4() == 0) { TWindowCtrl::disable_client_main_menu(client); } }

extern "C" {

void fn_8024AADC(s32 client_id, s32 arg1) {
    u32 window = (u32)TWindowCtrl::get_window(client_id);
    if (window != 0U) {
        free_member__15TWindowCtrlMainFv(window, arg1);
    }
}

}

extern "C" {

void TLobby__sub_8024AAA0(s32 local_client_id, s32 arg1) {
    u32 temp_r3 = get_window__11TWindowCtrlFl();
    if (temp_r3 != 0U) {
        update_field28__15TWindowCtrlMainFv(temp_r3, arg1);
    }
}

}

extern "C" {

void TWindowCtrl::handle_chat_message(char *arg1) {
    Obj_8024AA08 *arg0 = (Obj_8024AA08 *)this;
    s32 i;
    u32 key;
    char *v;
    Ply_8024AA08 *p;
    if (instance != NULL) {
        v = TWindowCtrl::skip_name_prefix(instance, arg1);
        key = arg0->f4;
        for (i = 0; i < 12; i++) {
            p = (Ply_8024AA08 *)get_player_by_client_id(i);
            if (p != NULL && p->f == key) {
                break;
            }
        }
        if (i < 12) {
            u16 slot = i;
            TOChatSensorCapture::capture_message(slot, v);
            TWindowCtrl::open(slot, v, 0xCB);
        }
    }
}

}

extern "C" {

TWindowFukidasi *TWindowCtrl::show_chat_balloon(u16 player, s32 flags, const char *text, s32 client) {
    u32 i;
    if (instance == NULL) {
        return 0;
    }
    if (flags & 8) {
        for (i = 0; i < 4; i++) {
            TWindowFukidasi *b = balloons[i];
            if (b != 0 && b->all_parents_unqueued_for_destruction() != 0 &&
                player == b->get_speaker_id() &&
                b->check_card_match_enabled(text) != 0) {
                b->rearm_balloon(flags);
                return 0;
            }
        }
    }
    return instance->acquire_balloon_slot(player, flags, client);
}

}

extern "C" {

TWindowFukidasi *TWindowCtrl::acquire_balloon_slot(u16 player, s32 flags, s32 client) {
    f32 f;
    s32 n;
    u32 i;
    TWindowFukidasi *b;
    get_speaker_balloon_anchor(player, &f, &n);
    i = 4;
    if (!(flags & 0x10)) {
        for (i = 0; i < 4; i++) {
            b = balloons[i];
            if (b != 0 && b->all_parents_unqueued_for_destruction() != 0 &&
                player == b->get_speaker_id()) {
                break;
            }
        }
    }
    if (i >= 4) {
        i = count_balloon_slots();
        if (i >= 4) {
            i = find_farthest_balloon_slot(player);
        }
        if (i >= 4) {
            return 0;
        }
        if (balloons[i] != 0) {
            balloons[i]->close();
        }
        b = new TWindowFukidasi(player, n, client, f);
        balloons[i] = b;
    }
    return balloons[i];
}

}

extern "C" {

s32 TWindowCtrl::count_balloon_slots() {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (balloons[i] == 0) break;
        n++;
    }
    return n;
}

}

extern "C" {

s32 TWindowCtrl::find_farthest_balloon_slot(u16 speaker) {
    s32 i;
    s32 result;
    RecoveredFields_8024A688_arg1 *local;
    f32 farthest;
    f32 d;
    TWindowFukidasi *b;
    u16 id;

    local = (RecoveredFields_8024A688_arg1 *)get_player_by_client_id(local_client_id);
    if (local == NULL) {
        return 4;
    }
    result = 4;
    farthest = ((f32 (*)(void *, RecoveredFields_8024A688_arg1 *, u16))get_entity_distance_or_default__11TWindowCtrlFiPvUs)(this, local, speaker);
    for (i = 0; i < 4; i++) {
        b = balloons[i];
        if (b != NULL) {
            id = b->get_speaker_id();
            d = ((f32 (*)(void *, RecoveredFields_8024A688_arg1 *, u16))get_entity_distance_or_default__11TWindowCtrlFiPvUs)(this, local, id);
            if (!(farthest > d)) {
                farthest = d;
                result = i;
            }
        }
    }
    return result;
}

}

extern "C" {

f32 get_entity_distance_or_default__11TWindowCtrlFiPvUs(s32 arg0, RecoveredFields_8024A688_arg1 *arg1, u16 id) {
  f32 temp_f2;
  f32 temp_f3;
  f32 temp_f4;
  u8 *entity;
  if (id == ((-1) & 0xFFFF))
  {
    return 1000000.0f;
  }
  entity = (u8 *) find_entity_by_id(id);
  if (entity == 0)
  {
    return 1000000.0f;
  }
  temp_f4 = arg1->field_38 - ((RecoveredFields_8024A688_temp_r3 *) entity)->field_38;
  temp_f3 = arg1->field_3C - ((RecoveredFields_8024A688_temp_r3 *) entity)->field_3C;
  temp_f2 = arg1->field_40 - ((RecoveredFields_8024A688_temp_r3 *) entity)->field_40;
  return (temp_f2 * temp_f2) + ((temp_f4 * temp_f4) + (temp_f3 * temp_f3));
}

}

extern "C" {

void TWindowCtrl::get_speaker_balloon_anchor(u16 id, f32 *height, s32 *name) {
    u8 *entity;
    u8 *obj;
    player_stats *q;
    entity = find_entity_by_id(id);
    if (entity != NULL && obj_is_hit_receivable(reinterpret_cast<TObjCollidable *>(entity)) == 1) {
        obj = entity;
    } else {
        obj = NULL;
    }
    if (obj == NULL) {
        *height = 0.0f;
        *name = 0;
        return;
    }
    q = reinterpret_cast<player_stats *>(((TObjChara *)obj)->get_stats());
    if (q == NULL) {
        *height = 0.0f;
    } else {
        *height = 0.92f * q->proportions;
    }
    if (((TObjChara *)obj)->obj_isState2_324() != 0 || TObjPlayer::is_locally_controlled(obj) != 0) {
        u8 *p = obj + 0x85C;
        if (p == NULL) {
            *name = 0;
            return;
        }
        *name = (saddr)p;
        return;
    }
    *name = 0;
}


}

extern "C" {

char *TWindowCtrl::skip_name_prefix(void *self, char *s) {
    char *p;
    for (p = s; *p != '\0'; p++) {
        if (*p == '\t') break;
    }
    if (*p == '\0') return s;
    return p + 1;
}

}

extern "C" {

void TWindowCtrl::create_alt_timer() {
    if ((instance != NULL) && (instance->m_30 == NULL)) {
        instance->m_30 = TWindowTimer::create_alt();
    }
}

}

extern "C" {

void TWindowCtrl::close_timer_window() {
    if ((instance != NULL) && (instance->m_30 != NULL)) {
        instance->m_30->close();
        instance->m_30 = NULL;
    }
}

}

extern "C" {

void TWindowCtrl::set_timer_window_time(u32 secs) {
    TWindowTimer *timer;
    if (instance != NULL) {
        timer = instance->m_30;
        if (timer != NULL) {
            timer->set_time(secs);
        }
    }
}

}

extern "C" {

void TWindowCtrl::create_timer() {
    if ((instance != NULL) && (instance->m_30 == NULL)) {
        instance->m_30 = TWindowTimer::create();
    }
}

}

extern "C" {

void TWindowCtrl::ensure_initialized() {
    if ((instance != NULL) && (instance->m_34 == NULL)) {
        instance->m_34 = create_window_area();
    }
}

}

extern "C" {

void TWindowCtrl::close_active_window() {
    if ((instance != NULL) && (instance->m_34 != NULL)) {
        instance->m_34->close();
        instance->m_34 = NULL;
    }
}

}

extern "C" {

void TWindowCtrl::open_status_112() {
    if ((instance != NULL) && (instance->m_34 == NULL)) {
        instance->m_34 = create_area_window(TWindowSubStatusDisp::get_message_10(0x112));
    }
}

}

extern "C" {

void TWindowCtrl::open_status_111() {
    if ((instance != NULL) && (instance->m_34 == NULL)) {
        instance->m_34 = create_area_window(TWindowSubStatusDisp::get_message_10(0x111));
    }
}

}

extern "C" {

s32 TWindowCtrl__sub_8024A314(void) {
    if (TWindowCtrl::instance == NULL) {
        return 0;
    }
    if (TWindowCtrl::instance->m_38 == 0U) {
        return 0;
    }
    return TWindowCtrl__sub_8024701C((TWindowChat *)TWindowCtrl::instance->m_38);
}

}

extern "C" {

s32 TWindowCtrl::get_active_sub() {
    if (instance == NULL) {
        return 0;
    }
    if (instance->m_38 == 0U) {
        return 0;
    }
    return TWindowCtrl__sub_8024C5C4((TWindowChat *)instance->m_38);
}

}

extern "C" {

void TWindowCtrl::update_focused() {
    if ((instance != NULL) && (instance->m_38 != 0U)) {
        ((TWindowChat *)instance->m_38)->update();
    }
}

}

extern "C" {

bool TWindowCtrl::is_submit_cooldown_clear() {
    if (instance == NULL) {
        return 0;
    }
    return instance->submit_cooldown <= 0;
}

}

extern "C" {

void TWindowCtrl__sub_8024A228(saddr client_id) {
    PlayerWindowQuery callback = &TWindowCtrl::is_countdown_done;
    TWindowCtrl::query_window(client_id, callback);
}

}

extern "C" {

void TWindowCtrl::set_field22() {
    if (instance != NULL) {
        instance->submit_cooldown = 0x2D;
    }
}

}

extern "C" {

void TWindowCtrl::call_window_method_with_default_vec(s32 client_id) {
    PlayerWindowCommand callback = &TWindowCtrl::start_countdown;
    TWindowCtrl::call_window_method(client_id, callback);
}

}

extern "C" {

bool TWindowCtrl__sub_8024A1A8(void) {
    if (TWindowCtrl::instance == NULL) {
        return 0;
    }
    return TWindowCtrl::instance->m_3c != 0;
}

}

extern "C" {

void TLobby::send_card_window_state() {
    s32 parameters[5];
    s32 character_save_record;

    character_save_record = get_character_save_record(0xFFFF);
    parameters[0] = open_hard_keyboard__6TLobbyFPv(local_client_id) ? 1 : 0;
    TLobby__sub_80077798(character_save_record + 0x22EC, parameters);
    protocol_instance->send_choice_search_parameters((TPlyChoiceSearchConfig &)parameters);
}

}

extern "C" {

s32 is_player_input_active(s32 client) {
    if (client >= 4) {
        return 0;
    }
    if (TAdMultiChgGameModeGC::is_input_phase_active() != 0) {
        return get_multiplayer_controller_active_index(client);
    }
    TObjPlayer *player = get_player_by_client_id(client);
    if (player == NULL) {
        return 0;
    }
    return player->get_controller_port();
}

}

extern "C" {

void TWindowCtrl__sub_8024A08C(void) {
    TObject *object;
    lbl_805D63FC &= 0xFFFFFFFD;
    if (TWindowCtrl::instance != NULL) {
        object = (TObject *)TWindowCtrl::instance->m_3c;
        if (object != NULL) {
            object->queue_destruction();
            TWindowCtrl::instance->m_3c = 0;
        }
    }
}

}

extern "C" {

void TWindowCtrl::clear_flag() {
    if ((instance != NULL) && (instance->m_38 != 0U)) {
        ((TWindowCtrl *)instance->m_38)->clear_flag1e_bit8();
    }
}

}
