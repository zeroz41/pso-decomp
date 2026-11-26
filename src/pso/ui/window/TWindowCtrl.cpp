#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/network/protocol/choice_search.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/network/TLobby.h"
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
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include "pso/ui/window/TWindowCtrlPlayer.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowSetLevelUp.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowEffectParty.h"
#include "pso/ui/window/TWindowTradeRequest.h"
#include "pso/ui/window/TWindowGetComCard.h"
#include "pso/ui/window/TWindowSimpleStatus.h"
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
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/window/TWindowPartyStatus.h"
#include "pso/ui/window/TWindowBreakIn.h"
#include "pso/ui/window/TWindowMessageLog.h"
#include "pso/object/TObjLuker.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/unk/text_8026AC50.h"
#include "pso/unk/text_8026ACDC.h"
#include "pso/unk/text_80076BC4.h"
#include "pso/ui/frontend/TAdChrSelPlyPlateGC.h"
#include "pso/network/client_id.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TWindowMessageLog.h"

TWindowCtrl *TWindowCtrl::instance;
u16 short_mail_flags;











const char *TWindowCtrl::class_name = "TWindowCtrl";
/* frame of the open sequence at which each window appears: split screen / single player */
static const s16 split_open_times[6] = {0, 4, 8, 12, 0, 0};
static const s16 open_times[4] = {24, 30, 36, 0};




void prune_destroyed_balloons(TWindowCtrl *ctrl);



LAYOUT_ASSERT(WindowCtrlFlagsOffset, offsetof(TWindowCtrl, flags) == 0x1C);
LAYOUT_ASSERT(WindowCtrlChildOffset, offsetof(TWindowCtrl, com_card_window) == 0x3C);

s32 TWindowSimpleStatus::get_width() { return this->client_index; }

s16 TWindowFukidasi::get_field_20() { return this->client_index; }

s32 TWindowCtrlPlayer::is_suppressed() { return this->flags & 0x1; }

s32 TWindowCtrlPlayer::is_status_window_hidden() {
    return (this->flags >> 4) & 1;
}

s32 TWindowCtrlPlayer::is_keyboard_held() { return (this->flags >> 3) & 0x1; }

s32 TWindowCtrlPlayer::is_lock_on_window_hidden() {
    return (this->flags >> 2) & 1;
}

s32 TWindowCtrlPlayer::is_main_menu_disabled() {
    return (this->flags >> 1) & 1;
}

s32 TWindowCtrlPlayer::has_short_list() {
    return this->short_list != NULL ? 1 : 0;
}

void TWindowCtrlPlayer::unsuppress() {
    this->flags &= ~1;
    TRaderMapCore::show_radar();
}

void TWindowCtrlPlayer::suppress() {
    this->flags |= 1;
    TRaderMapCore::hide_radar();
}

void TWindowCtrlPlayer::show_status_window() {
    this->flags &= ~0x10;
}

void TWindowCtrlPlayer::hide_status_window() {
    this->flags |= 0x10;
}

void TWindowCtrlPlayer::end_keyboard_hold() {
    this->flags &= ~0x8;
}

void TWindowCtrlPlayer::begin_keyboard_hold() {
    this->flags |= 0x8;
}

void TWindowCtrlPlayer::show_lock_on_window() {
    this->flags &= ~0x4;
}

void TWindowCtrlPlayer::hide_lock_on_window() {
    this->flags |= 0x4;
}

void TWindowCtrlPlayer::enable_main_menu() {
    this->flags &= ~0x2;
}

void TWindowCtrlPlayer::disable_main_menu() {
    this->flags |= 0x2;
}

void TWindowCtrlPlayer::unlock_main_menu() {
    this->flags &= ~0x40;
}

void TWindowCtrlPlayer::lock_main_menu() {
    this->flags |= 0x40;
}


s32 TWindowCtrl::get_display_flag() {
    if (is_split_screen() != 0) {
        return 0;
    }
    if (instance == NULL) {
        return 0;
    }
    return ((u16) instance->flags >> 1U) & 1;
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

TWindowCtrlPlayer *TWindowCtrl::get_window(s32 client_id) {
    if (instance == NULL) {
        return NULL;
    }
    if (client_id < 0) {
        return NULL;
    }
    if (client_id >= 0xC) {
        return NULL;
    }
    return instance->players[client_id];
}


int TWindowFukidasi::get_flag_bit1() { return ((this->balloon_flags) >> 1) & 0x1; }



u16 TWindowFukidasi::get_speaker_id() { return this->speaker_id; }



void TWindowChat::set_flag1e_bit40() { flags |= 0x40; }



s32 fn_8024C5C4(const TWindowChat *chat) {
    if (chat->flags & 2) return 0;
    return 1;
}


void TWindowChat::clear_flag1e_bit8() { flags &= 0xfffffff7; }

void TWindowChat::set_flag1e_bit8() { flags |= 0x8; }

int TWindowCtrl::is_flag_2_set() { return this->m_flags & 0x4; }

void TWindowCtrl::close() {
    TWindowMainMenu__sub_8024E3D0();
    init_chat_log_heap();
    instance = NULL;
}

void TWindowCtrl::shutdown() {
    if (instance != NULL) {
        instance->queue_destruction();
        instance = NULL;
    }
    free_chat_log_lines();
    TWindowMainMenu__sub_8024E3CC();
}


TWindowCtrl::TWindowCtrl(TObject *parent) : TObject(parent) {
    s32 i;
    m_name = TWindowCtrl::class_name;
    if (instance != NULL) {
        instance->queue_destruction();
    }
    instance = this;
    flags = 0;
    tick = 0;
    open_step = 0;
    submit_cooldown = 0;
    pulse_color = 0;
    window_id = 0xFFFF;
    break_in = NULL;
    timer_window = NULL;
    area_window = NULL;
    chat_window = NULL;
    com_card_window = NULL;
    trade_request = NULL;
    message_log = NULL;
    for (i = 0; i < 12; i++) {
        players[i] = NULL;
    }
    for (i = 0; i < 3; i++) {
        simple_status[i] = NULL;
    }
    for (i = 0; i < 4; i++) {
        balloons[i] = NULL;
    }
    break_in = new TWindowBreakIn();
    if (is_split_screen() == 0) {
        chat_window = new TWindowChat(tl_00, &submission);
        chat_window->set_flag1e_bit40();
    }
    if (is_split_screen() != 0) {
        for (i = 0; i < 4; i++) {
            players[i] = new TWindowCtrlPlayer(this, i);
            players[i]->suspend_update();
        }
    } else {
        players[local_client_id] = new TWindowCtrlPlayer(this, local_client_id);
        for (i = 0; i < 3; i++) {
            if (get_current_floor_area() != AREA_LOBBY && is_split_screen() == 0) {
                simple_status[i] = (TWindowSimpleStatus *)create_party_status_window(i);
                simple_status[i]->suspend_update();
            }
        }
    }
    if (TObjPlayer::get_player_count() == 1) {
        TWindowCtrl::open_status_112();
    }
}


TWindowCtrl::~TWindowCtrl() {
    s32 i;
    for (i = 3; i >= 0; i--) {
        if (balloons[i] != NULL) {
            balloons[i]->close();
            balloons[i] = NULL;
        }
    }
    if (message_log != NULL) {
        message_log->close();
        message_log = NULL;
    }
    if (area_window != NULL) {
        area_window->close();
        area_window = NULL;
    }
    if (timer_window != NULL) {
        timer_window->close();
        timer_window = NULL;
    }
    if (trade_request != NULL) {
        trade_request->queue_destruction();
        trade_request = NULL;
    }
    if (com_card_window != NULL) {
        com_card_window->queue_destruction();
        com_card_window = NULL;
    }
    for (i = 2; i >= 0; i--) {
        if (simple_status[i] != NULL) {
            simple_status[i]->close();
            simple_status[i] = NULL;
        }
    }
    for (i = 11; i >= 0; i--) {
        if (players[i] != NULL) {
            players[i]->queue_destruction();
            players[i] = NULL;
        }
    }
    if (chat_window != NULL) {
        chat_window->queue_destruction();
        chat_window = NULL;
    }
    if (break_in != NULL) {
        break_in->close();
        break_in = NULL;
    }
    if (instance == this) {
        instance = NULL;
    }
}

void TWindowCtrl::run_task() { update_open_sequence(); update(); TLobby::update_game_modes(); }

void TWindowCtrl::render() {  }


void TWindowCtrl::update_open_sequence() {
    if (is_split_screen() != 0) {
        if (tick == split_open_times[open_step]) {
            if (players[open_step] != NULL) {
                players[open_step]->clear_update_suspension();
            }
            open_step++;
        }
    } else {
        if (tick == open_times[open_step]) {
            if (simple_status[open_step] != NULL) {
                simple_status[open_step]->clear_update_suspension();
                update_party_status_rows();
                simple_status[open_step]->tween_ticks = 0;
            }
            open_step++;
        }
    }
    if (tick > 30000) {
        tick -= 10000;
    }
    tick++;
}



void TWindowCtrl::update() { update_party_status_rows(); update_window_visibility(); update_com_card_window(); update_trade_request_window(); prune_destroyed_balloons(this); handle_controller(); update_trade_window(); update_timer_window(this); update_pulse_color(); }



void TWindowCtrl::update_party_status_rows() {
    f32 y;
    u32 i;
    TObjPlayer *pl;
    TWindowSimpleStatus *w;
    y = get_window_layout_y(0xAB);
    for (i = 0; i < 3; i++) {
        w = simple_status[i];
        if (w != NULL && ((TWindowCtrl *)w)->is_flag_2_set() == 0) {
            pl = get_player_by_client_id(w->get_width());
            if (pl == NULL || TWindowCtrl::has_player_active_menu(local_client_id) != 0 ||
                TWindowCtrl::is_slot_visible(local_client_id) != 0 || is_flag_bit2_set() != 0 ||
                pl->is_script_controlled() != 0 ||
                (pl->obj_isState3_324() != 0 &&
                 (pl->is_pk_enabled() != 0 || pl->get_npc_controller() == 0xFFFF))) {
                w->request_close();
            } else {
                w->request_show();
                if (w->target_position[1] != y) {
                    w->target_position[1] = y;
                    w->tween_ticks = 0xF;
                }
                y += 55.0f;
            }
        }
    }
}



void TWindowCtrl::update_window_visibility() {
    s32 submit_cooldown;
    u16 current_target_id;

    if (chat_window != NULL) {
        submit_cooldown = this->submit_cooldown;
        if (submit_cooldown > 0) {
            this->submit_cooldown = (submit_cooldown - 1);
        }
        if (get_player_by_client_id(local_client_id) == 0U) {
            chat_window->update();
            return;
        }
        current_target_id = TObjPlayer::get_current_target_id();
        if ((TWindowCtrl::get_display_flag() != 0) || (TWindowCtrl::has_player_active_menu(local_client_id) != 0) || (TWindowCtrl::is_slot_visible(local_client_id) != 0) || (has_client_short_list(local_client_id) != 0) || ((current_target_id != 0xffffU) && (current_target_id != local_client_id))) {
            chat_window->update();
            return;
        }
        chat_window->open_input();
        if ((chat_window->is_mode_bit4() != 0) && (chat_accept_submission((saddr)&this->submission) != 0)) {
            consume_active_flag(chat_window);
        }
        if (chat_window->is_visible() != 0) {
            consume_input_active_flag(chat_window);
        }
    }
}



void TWindowCtrl::update_com_card_window() {
    TWindowGetComCard *card_before;
    TWindowChat *chat;
    TWindowGetComCard *card;
    card_before = this->com_card_window;
    if ((card_before != NULL) && (card_before->all_parents_unqueued_for_destruction() == 0)) {
        this->com_card_window = NULL;
    }
    if ((is_guild_card_receive_active() == 0) || (TWindowCtrl::has_player_active_menu(local_client_id) != 0) || (TWindowCtrl::is_slot_visible(local_client_id) != 0) || (TWindowCtrl::get_flag_bit5() != 0) || (trade_request != NULL) || ((chat = chat_window, ((chat == NULL) == 0)) && (chat->is_chat_in_use() != 0))) {
        card = this->com_card_window;
        if (card != NULL) {
            card->queue_destruction();
            this->com_card_window = NULL;
        }
    } else if (this->com_card_window == NULL) {
        this->com_card_window = new TWindowGetComCard(this);
    }
}



void TWindowCtrl::update_trade_request_window() {
    if ((is_trade_active() == 0) || (TWindowCtrl::has_player_active_menu(local_client_id) != 0) || (TWindowCtrl::is_slot_visible(local_client_id) != 0) || (this->com_card_window != 0U) || ((chat_window != NULL) && (chat_window->is_chat_in_use() != 0))) {
        if (trade_request != NULL) {
            trade_request->queue_destruction();
            trade_request = NULL;
        }
    } else if (trade_request == NULL) {
        trade_request = new TWindowTradeRequest(this);
    }
}


void prune_destroyed_balloons(TWindowCtrl *ctrl) {
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


void TWindowCtrl::handle_controller() {
    if ((get_current_floor_area() == AREA_LOBBY) && (TWindowCtrl::is_slot_visible(local_client_id) == 0) && (is_client_main_menu_disabled(local_client_id) == 0) && (TWindowCtrl::has_player_active_menu(local_client_id) == 0) && (test_pressed_buttons_packed(&controller_input_state.controllers[0], get_control_button_mask(local_client_id)) != 0)) {
        advance_card_status(local_client_id);
    }
}



void TWindowCtrl::update_trade_window() {
    if (this->area_window != NULL) {
        if ((TWindowCtrl::is_slot_visible(local_client_id) != 0) || (is_client_main_menu_disabled(local_client_id) != 0) || ((is_split_screen() != 0) && (TRaderMapCore::is_active() == 0))) {
            this->area_window->request_close();
            return;
        }
        this->area_window->request_show();
    }
}



void update_timer_window(TWindowCtrl *ctrl) {
    if (ctrl->timer_window != NULL) {
        if (TWindowCtrl::is_slot_visible(local_client_id) != 0) {
            ctrl->timer_window->request_close();
            return;
        }
        ctrl->timer_window->request_show();
    }
}



#pragma push

#pragma fp_contract on
void TWindowCtrl::update_pulse_color() {
    f32 t;
    f32 a;
    t = (u32)tick % 100;
    if (t > 50.0f) {
        t = 100.0f - t;
    }
    t = t / 100.0f;
    a = 0.85f * (1.0f + cos_table_lookup((s32)(65536.0f * t)));
    if (a > 1.0f) {
        a = 1.0f;
    }
    pulse_color = (u8)(s32)(53.0f * a + 19.0f * (1.0f - a)) |
               ((((u8)(s32)(255.0f * a + 187.0f * (1.0f - a)) << 16) | 0xFF000000) |
                ((u8)(s32)(174.0f * a + 83.0f * (1.0f - a)) << 8));
}

#pragma pop



saddr get_party_member_name(s32 n) {
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
        if (status != NULL && status->is_open_and_unblocked() != 0 && n-- == 0) {
            player = get_player_by_client_id(status->get_width());
            if (player == NULL) {
                return 0;
            }
            return (saddr)player->get_name();
        }
    }
    return 0;
}


void TWindowCtrl::dispatch_to_child(s32 client, s32 kind) {
    if (instance != NULL && instance->players[client] != NULL) {
        instance->players[client]->spawn_palette_slot_light(kind);
    }
}

void TWindowCtrl::create_party_effect(u16 from, u16 to) { TWindowEffectParty::create(tl_07, from, to, 0); }


void TWindowCtrl::show_party_effect(u16 from, u16 to, u32 kind) { TWindowEffectParty::create(tl_07, from, to, kind); }


void TWindowCtrl::append_message_all(const char *text) {
    TWindowCtrl::append_message_all(text, 0);
}


void TWindowCtrl::append_message_all(const char *text, s32 mode) {
    s32 i;
    for (i = 0; i < 12; i++) {
        TWindowCtrl::append_client_message(i, text, mode);
    }
}


void TWindowCtrl::append_client_message(s32 client, const char *text) {
    TWindowCtrl::append_client_message(client, text, 0);
}


void TWindowCtrl::append_client_message(s32 client, const char *text, s32 mode) {
    TWindowCtrlPlayer *window = TWindowCtrl::get_window(client);
    if (window != NULL) {
        window->append_message_line(text, mode | 0xE);
    }
}


void TWindowCtrl::create_level_up_window(saddr stats, saddr client) {
    new TWindowSetLevelUp(tl_07, stats, client);
}

int TWindowCtrl::open_default(u16 id, const char *text) { return TWindowCtrl::open(id, text, 15); }


saddr TWindowCtrl::open(u16 id, const char *text, s32 flags) {
    saddr balloon;

    if (instance == NULL) {
        return 0;
    }
    if (flags & 0x40) {
        post_chat_log_message(id, text);
    }
    balloon = (saddr)instance->show_chat_balloon(id, flags, text, static_cast<s32>(local_client_id));
    if (balloon == 0) {
        return 0;
    }
    ((TWindowFukidasi *)balloon)->set_text(text, flags);
    return balloon;
}


s32 TWindowCtrl::open_balloon(u16 player, u8 *text, s32 flags, s32 client) {
    saddr balloon;
    if (instance == 0U) {
        return 0;
    }
    balloon = reinterpret_cast<saddr>(instance->acquire_balloon_slot(player, flags, client));
    if (balloon == 0) {
        return 0;
    }
    ((TWindowFukidasi *)balloon)->open((u32 *)text, flags);
    return balloon;
}

s32 is_actor_speech_balloon_done(u16 id) {
    u32 i;
    TWindowFukidasi *w;
    if (TWindowCtrl::instance == NULL) {
        return 1;
    }
    for (i = 0; i < 4; i++) {
        w = TWindowCtrl::instance->balloons[i];
        if (w != NULL && w->all_parents_unqueued_for_destruction() != 0 && id == w->get_speaker_id() && w->is_speech_balloon_ready() == 0) {
            return 0;
        }
    }
    return 1;
}

void complete_actor_speech_balloons(u16 id) {
    u32 i;
    TWindowFukidasi *w;
    if (TWindowCtrl::instance != NULL) {
        for (i = 0; i < 4; i++) {
            w = TWindowCtrl::instance->balloons[i];
            if (w != NULL && w->all_parents_unqueued_for_destruction() != 0 && id == w->get_speaker_id()) {
                w->show_immediately();
            }
        }
    }
}

void TWindowCtrl::close_windows_by_flags(u16 flags) {
    u32 i;
    TWindowFukidasi *w;
    if (instance != NULL) {
        for (i = 0; i < 4; i++) {
            w = instance->balloons[i];
            if (w != NULL && w->all_parents_unqueued_for_destruction() != 0 && flags == w->get_speaker_id()) {
                w->close();
            }
        }
    }
}


u16 TWindowCtrl::get_window_id() {
    if (instance == NULL) {
        return 0xFFFFU;
    }
    return instance->window_id;
}



void TWindowCtrl::set_window_id(u16 id) {
    if (instance != NULL) {
        instance->window_id = id;
    }
}



#pragma push

#pragma fp_contract on
s8 TWindowFukidasi::alloc_nearest_free_slot() {
    s32 i;
    s32 mask;
    s8 best;
    f32 cx;
    f32 cy;
    f32 bestd;
    const NJS_POINT2 *m;
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
    cx = (0.5f * frame_size[0]) + frame_position[0];
    bestd = 1000000.0f;
    cy = (0.5f * frame_size[1]) + frame_position[1];
    do {
        if (!(TWindowCtrl::instance->flags & mask)) {
            m = TWindowCtrl::get_message_by_type((s8)i, get_field_20());
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



void TWindowCtrl::release_slot(s8 *slot) {
    s8 value;

    if (instance != NULL) {
        value = *slot;
        if ((value >= 0) && (value < 4)) {
            instance->flags &= ~(0x40 << value);
            *slot = -1;
        }
    }
}



const NJS_POINT2 *TWindowCtrl::get_message_by_type(s8 type, s32 client_id) {
    TWindowCtrlPlayer *window;
    s32 base;

    window = TWindowCtrl::get_window(client_id);
    if (window == NULL) {
        return 0;
    }
    if (window->is_log_active() != 0) {
        base = 0x4D;
    } else if (window->is_main_menu_open() != 0) {
        base = 0x48;
    } else {
        base = 0x43;
    }
    return get_window_layout_position(base + type);
}


s32 TWindowCtrl::query_window(s32 client_id, PlayerWindowQuery pmf) {
    TWindowCtrlPlayer *w = TWindowCtrl::get_window(client_id);
    if (w == NULL) {
        return 0;
    }
    return (w->*pmf)();
}

s32 TWindowCtrl::is_slot_visible(s32 local_client_id) {
    PlayerWindowQuery callback = &TWindowCtrlPlayer::is_suppressed;
    return TWindowCtrl::query_window(local_client_id, callback);
}

s32 TWindowCtrl::is_flag_bit2_set() { return (flags >> 2) & 0x1; }

s32 TWindowCtrl::is_client_main_menu_disabled(s32 client_id) {
    PlayerWindowQuery callback = &TWindowCtrlPlayer::is_main_menu_disabled;
    return TWindowCtrl::query_window(client_id, callback);
}

s32 TWindowCtrl::has_client_short_list(s32 client_id) {
    PlayerWindowQuery callback = &TWindowCtrlPlayer::has_short_list;
    return TWindowCtrl::query_window(client_id, callback);
}

s32 TWindowCtrl::has_player_active_menu(s32 local_client_id) {
    PlayerWindowQuery callback = &TWindowCtrlPlayer::is_main_menu_open;
    return TWindowCtrl::query_window(local_client_id, callback);
}

void TWindowCtrl::call_window_method(s32 client_id, PlayerWindowCommand pmf) {
    TWindowCtrlPlayer *w = TWindowCtrl::get_window(client_id);
    if (w != NULL) {
        (w->*pmf)();
    }
}

void TWindowCtrl::unsuppress_slot(s32 local_client_id) {
    PlayerWindowCommand callback = &TWindowCtrlPlayer::unsuppress;
    TWindowCtrl::call_window_method(local_client_id, callback);
}

void TWindowCtrl::suppress_slot(s32 local_client_id) {
    PlayerWindowCommand callback = &TWindowCtrlPlayer::suppress;
    TWindowCtrl::call_window_method(local_client_id, callback);
}

void TWindowCtrl::unsuppress_all_slots() {
    saddr i;

    i = 0;
    do {
        TWindowCtrl::unsuppress_slot(i);
        i += 1;
    } while (i < 0xC);
}

void TWindowCtrl::suppress_all_slots() {
    saddr i;

    i = 0;
    do {
        TWindowCtrl::suppress_slot(i);
        i += 1;
    } while (i < 0xC);
}

void TWindowCtrl::show_client_status_window(s32 client_id) {
    PlayerWindowCommand callback = &TWindowCtrlPlayer::show_status_window;
    TWindowCtrl::call_window_method(client_id, callback);
}

void TWindowCtrl::hide_client_status_window(s32 client_id) {
    PlayerWindowCommand callback = &TWindowCtrlPlayer::hide_status_window;
    TWindowCtrl::call_window_method(client_id, callback);
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

void TWindowCtrl::end_client_keyboard_hold(s32 client_id) {
    TWindowCtrl::call_window_method(client_id, &TWindowCtrlPlayer::end_keyboard_hold);
}

void TWindowCtrl::begin_client_keyboard_hold(s32 client_id) {
    TWindowCtrl::call_window_method(client_id, &TWindowCtrlPlayer::begin_keyboard_hold);
}

void TWindowCtrl::show_client_lock_on_window(s32 client_id) {
    TWindowCtrl::call_window_method(client_id, &TWindowCtrlPlayer::show_lock_on_window);
}

void TWindowCtrl::hide_client_lock_on_window(s32 client_id) {
    TWindowCtrl::call_window_method(client_id, &TWindowCtrlPlayer::hide_lock_on_window);
}

void TWindowCtrl::enable_client_main_menu(s32 client) {
    TWindowCtrl::call_window_method(client, &TWindowCtrlPlayer::enable_main_menu);
}

void TWindowCtrl::disable_client_main_menu(s32 client) {
    TWindowCtrl::call_window_method(client, &TWindowCtrlPlayer::disable_main_menu);
}

void TWindowCtrl::unlock_client_main_menu(s32 client_id) {
    TWindowCtrl::call_window_method(client_id, &TWindowCtrlPlayer::unlock_main_menu);
}

void TWindowCtrl::lock_client_main_menu(s32 client_id) {
    TWindowCtrl::call_window_method(client_id, &TWindowCtrlPlayer::lock_main_menu);
}

void close_window_if_active(s32 client) { if (TWindowCtrl::get_flag_bit4() == 0) { TWindowCtrl::disable_client_main_menu(client); } }


void TWindowCtrl::try_open_battle_menu(s32 client_id, s16 key) {
    TWindowCtrlPlayer *window = TWindowCtrl::get_window(client_id);
    if (window != NULL) {
        window->try_open_battle_menu(key);
    }
}



void TWindowCtrl::replace_submenu(s32 client_id, s16 id) {
    TWindowCtrlPlayer *window = TWindowCtrl::get_window(client_id);
    if (window != NULL) {
        window->replace_submenu(id);
    }
}



void TWindowCtrl::handle_recv_chat(TPlyGuildCardTag &tag, char *message) {
    s32 i;
    u32 key;
    char *v;
    TObjPlayer *p;
    if (TWindowCtrl::instance != NULL) {
        v = TWindowCtrl::skip_name_prefix(TWindowCtrl::instance, message);
        key = tag.m_guildcard_number;
        for (i = 0; i < 12; i++) {
            p = get_player_by_client_id(i);
            if (p != NULL && p->guild_card_tag.guildcard_number == key) {
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



TWindowFukidasi *TWindowCtrl::acquire_balloon_slot(u16 player, s32 flags, s32 client) {
    f32 f;
    char *n;
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



s32 TWindowCtrl::count_balloon_slots() {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (balloons[i] == 0) break;
        n++;
    }
    return n;
}



s32 TWindowCtrl::find_farthest_balloon_slot(u16 speaker) {
    s32 i;
    s32 result;
    TObjBase *local;
    f32 farthest;
    f32 d;
    TWindowFukidasi *b;
    u16 id;

    local = get_player_by_client_id(local_client_id);
    if (local == NULL) {
        return 4;
    }
    result = 4;
    farthest = get_squared_distance_to_entity(local, speaker);
    for (i = 0; i < 4; i++) {
        b = balloons[i];
        if (b != NULL) {
            id = b->get_speaker_id();
            d = get_squared_distance_to_entity(local, id);
            if (!(farthest > d)) {
                farthest = d;
                result = i;
            }
        }
    }
    return result;
}



f32 TWindowCtrl::get_squared_distance_to_entity(TObjBase *from, u16 id) {
  f32 dz;
  f32 dy;
  f32 dx;
  TObjCollidable *entity;
  if (id == ((-1) & 0xFFFF))
  {
    return 1000000.0f;
  }
  entity = find_entity_by_id(id);
  if (entity == 0)
  {
    return 1000000.0f;
  }
  dx = from->position.x - entity->position.x;
  dy = from->position.y - entity->position.y;
  dz = from->position.z - entity->position.z;
  return (dz * dz) + ((dx * dx) + (dy * dy));
}



void TWindowCtrl::get_speaker_balloon_anchor(u16 id, f32 *height, char **name) {
    TObjPlayer *entity;
    TObjPlayer *obj;
    player_stats *q;
    entity = reinterpret_cast<TObjPlayer *>(find_entity_by_id(id));
    if (entity != NULL && obj_is_hit_receivable(entity) == 1) {
        obj = entity;
    } else {
        obj = NULL;
    }
    if (obj == NULL) {
        *height = 0.0f;
        *name = 0;
        return;
    }
    q = reinterpret_cast<player_stats *>(obj->get_stats());
    if (q == NULL) {
        *height = 0.0f;
    } else {
        *height = 0.92f * q->proportions;
    }
    if (obj->obj_isState2_324() != 0 || obj->is_locally_controlled() != 0) {
        char *p = obj->name;
        if (p == NULL) {
            *name = 0;
            return;
        }
        *name = p;
        return;
    }
    *name = 0;
}




char *TWindowCtrl::skip_name_prefix(void *self, char *s) {
    char *p;
    for (p = s; *p != '\0'; p++) {
        if (*p == '\t') break;
    }
    if (*p == '\0') return s;
    return p + 1;
}



void TWindowCtrl::create_alt_timer() {
    if ((instance != NULL) && (instance->timer_window == NULL)) {
        instance->timer_window = TWindowTimer::create_alt();
    }
}



void TWindowCtrl::close_timer_window() {
    if ((instance != NULL) && (instance->timer_window != NULL)) {
        instance->timer_window->close();
        instance->timer_window = NULL;
    }
}



void TWindowCtrl::set_timer_window_time(u32 secs) {
    TWindowTimer *timer;
    if (instance != NULL) {
        timer = instance->timer_window;
        if (timer != NULL) {
            timer->set_time(secs);
        }
    }
}



void TWindowCtrl::create_timer() {
    if ((instance != NULL) && (instance->timer_window == NULL)) {
        instance->timer_window = TWindowTimer::create();
    }
}



void TWindowCtrl::ensure_initialized() {
    if ((instance != NULL) && (instance->area_window == NULL)) {
        instance->area_window = create_window_area();
    }
}



void TWindowCtrl::close_active_window() {
    if ((instance != NULL) && (instance->area_window != NULL)) {
        instance->area_window->close();
        instance->area_window = NULL;
    }
}



void TWindowCtrl::open_status_112() {
    if ((instance != NULL) && (instance->area_window == NULL)) {
        instance->area_window = create_area_window(TWindowSubStatusDisp::get_message_10(0x112));
    }
}



void TWindowCtrl::open_status_111() {
    if ((instance != NULL) && (instance->area_window == NULL)) {
        instance->area_window = create_area_window(TWindowSubStatusDisp::get_message_10(0x111));
    }
}



s32 TWindowCtrl::is_chat_window_in_use() {
    if (TWindowCtrl::instance == NULL) {
        return 0;
    }
    if (TWindowCtrl::instance->chat_window == NULL) {
        return 0;
    }
    return TWindowCtrl::instance->chat_window->is_chat_in_use();
}



s32 TWindowCtrl::get_active_sub() {
    if (instance == NULL) {
        return 0;
    }
    if (instance->chat_window == NULL) {
        return 0;
    }
    return fn_8024C5C4(instance->chat_window);
}



void TWindowCtrl::update_focused() {
    if ((instance != NULL) && (instance->chat_window != NULL)) {
        instance->chat_window->update();
    }
}



s32 TWindowCtrl::is_submit_cooldown_clear() {
    if (instance == NULL) {
        return 0;
    }
    return instance->submit_cooldown <= 0 ? 1 : 0;
}


s32 TWindowCtrl::is_client_countdown_done(s32 client_id) {
    PlayerWindowQuery callback = &TWindowCtrlPlayer::is_countdown_done;
    return TWindowCtrl::query_window(client_id, callback);
}


void TWindowCtrl::start_submit_cooldown() {
    if (instance != NULL) {
        instance->submit_cooldown = 0x2D;
    }
}



void TWindowCtrl::start_client_countdown(s32 client_id) {
    PlayerWindowCommand callback = &TWindowCtrlPlayer::start_countdown;
    TWindowCtrl::call_window_method(client_id, callback);
}



bool is_com_card_window_open(void) {
    if (TWindowCtrl::instance == NULL) {
        return 0;
    }
    return TWindowCtrl::instance->com_card_window != 0;
}



void TLobby::send_card_window_state() {
    TPlyChoiceSearchConfig parameters;
    CharacterSaveRecord *card;

    card = (CharacterSaveRecord *)get_character_save_record(0xFFFF);
    parameters.disabled = TLobby::open_hard_keyboard(local_client_id) ? 1 : 0;
    copy_choice_search_selections(card->choice_search, &parameters);
    protocol_instance->send_choice_search_parameters(parameters);
}



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



void destroy_com_card_window(void) {
    TObject *object;
    short_mail_flags &= 0xFFFFFFFD;
    if (TWindowCtrl::instance != NULL) {
        object = (TObject *)TWindowCtrl::instance->com_card_window;
        if (object != NULL) {
            object->queue_destruction();
            TWindowCtrl::instance->com_card_window = 0;
        }
    }
}



void TWindowCtrl::clear_flag() {
    if ((instance != NULL) && (instance->chat_window != NULL)) {
        instance->chat_window->clear_flag1e_bit8();
    }
}

