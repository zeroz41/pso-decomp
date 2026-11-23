#include "pso/ui/window/TWindowFukidasi.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowCtrl_8024B048.h"
#include "pso/object/base/TObjChara.h"
#include "pso/ui/window/TWindowCtrl_8024B7D4.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowTradeRequest.h"
#include "pso/ui/window/TWindowGetComCard.h"
#include "pso/ui/window/TWindowSimpleStatus.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowCtrl_8024B9C0.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/chat/TWindowSubShortMail_80246CB8.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/ControllerInput.h"
#include "pso/unk/TLobby.h"
#include "pso/math/AngleLookup.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal_8002ADD8.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_8030C340.h"
#include "pso/ui/window/TWindowBreakIn.h"
#include "pso/object/TObjLuker.h"
#include "pso/ui/window/TWindowMainMenu_8024E3CC.h"
#include "pso/unk/text_8026AC50.h"
#include "pso/unk/text_8026ACDC.h"
#include "pso/ui/window/TWindowCtrl_8024A1A8.h"
#include <stddef.h>
#include "pso/ui/window/TWindowCtrl_8024C6CC.h"

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

void *get_player_by_client_id(s32 i);

s32 TWindowCtrl__sub_8024B000(void *, saddr);

extern s32 local_client_id;

}

extern "C" void TWindowCtrl__sub_8024BB30(TWindowCtrl *ctrl);

extern "C" {

s32 apply_default_vec__11TWindowCtrlFll(void *, s32);

}

s32 chat_accept_submission(saddr arg0);

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

void *get_player_by_client_id(s32);
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

void *__ct__11TWindowChatFP7TObjectPv(void *, s32, void *);
void *__ct__17TWindowCtrlPlayerFP7TObjectl(void *, void *, s32);
extern const char *TWindowCtrl__name;
extern s32 local_client_id;
extern saddr tl_00;

}

LAYOUT_ASSERT(WindowCtrlFlagsOffset, offsetof(TWindowCtrl, flags) == 0x1C);
LAYOUT_ASSERT(WindowCtrlChildOffset, offsetof(TWindowCtrl, m_3c) == 0x3C);

s32 TWindowSimpleStatus::get_width() { return (s16)(*(s16 *)&this->client_index); }

s16 TWindowFukidasi::get_field_20() { return *(s16 *)&(this->client_index); }

int TWindowCtrl::is_visible() { return this->flags & 0x1; }

s32 TWindowCtrl__sub_8024C7F8(const TWindowCtrl *window) {
    return (window->flags >> 4) & 1;
}

int TWindowCtrl::is_enabled() { return (this->flags >> 3) & 0x1; }

s32 TWindowCtrl__sub_8024C7E0(const TWindowCtrl *window) {
    return (window->flags >> 2) & 1;
}

s32 TWindowCtrl__sub_8024C7D4(const TWindowCtrl *window) {
    return (window->flags >> 1) & 1;
}

s32 TWindowCtrl__sub_8024C7C4(const TWindowCtrl *window) {
    return window->m_3c != 0 ? 1 : 0;
}

void TWindowCtrl::clear_flag_bit0() {
    this->flags &= ~1;
    TRaderMapCore::show_radar();
}

void TWindowCtrl::set_radar_dirty_flag() {
    this->flags |= 1;
    TRaderMapCore::hide_radar();
}

void TWindowCtrl__sub_8024C75C(TWindowCtrl *window) {
    window->flags &= ~0x10;
}

void TWindowCtrl__sub_8024C74C(TWindowCtrl *window) {
    window->flags |= 0x10;
}

void TWindowCtrl__sub_8024C73C(TWindowCtrl *window) {
    window->flags &= ~0x8;
}

void TWindowCtrl__sub_8024C72C(TWindowCtrl *window) {
    window->flags |= 0x8;
}

void TWindowCtrl__sub_8024C71C(TWindowCtrl *window) {
    window->flags &= ~0x4;
}

void TWindowCtrl__sub_8024C70C(TWindowCtrl *window) {
    window->flags |= 0x4;
}

void TWindowCtrl__sub_8024C6FC(TWindowCtrl *window) {
    window->flags &= ~0x2;
}

void TWindowCtrl__sub_8024C6EC(TWindowCtrl *window) {
    window->flags |= 0x2;
}

void TWindowCtrl__sub_8024C6DC(TWindowCtrl *window) {
    window->flags &= ~0x40;
}

void TWindowCtrl__sub_8024C6CC(TWindowCtrl *window) {
    window->flags |= 0x40;
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
    s32 temp_r3;
    s32 current_target_id;

    if ((u32) this->m_38 != 0U) {
        temp_r3 = this->submit_cooldown;
        if (temp_r3 > 0) {
            this->submit_cooldown = (temp_r3 - 1);
        }
        if (get_player_by_client_id(local_client_id) == 0U) {
            ((TWindowChat *)(this->m_38))->update();
            return;
        }
        current_target_id = TObjPlayer::get_current_target_id();
        if ((TWindowCtrl::get_display_flag() != 0) || (TWindowCtrl::has_player_active_menu(local_client_id) != 0) || (TWindowCtrl::is_slot_visible(local_client_id) != 0) || (apply_default_vec__11TWindowCtrlFll(arg0, local_client_id) != 0) || (((u16)current_target_id != 0xffffU) && ((s32)(u16)current_target_id != (s32) local_client_id))) {
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
            player = (TObjPlayer *)get_player_by_client_id(((TWindowSimpleStatus *)status)->get_width());
            if (player == NULL) {
                return 0;
            }
            return (saddr)player->get_name();
        }
    }
    return 0;
}

}
