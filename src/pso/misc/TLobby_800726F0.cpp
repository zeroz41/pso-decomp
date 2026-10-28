#include "pso/protocol/protocol_types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "types.h"
#include "pso/system/byteswap.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TObjChallengeRetry.h"
#include "pso/map/CurrentArea.h"

struct W4_80072994 { u8 b[4]; };

struct W8_80072994 { u8 b[8]; };

struct S_80072994 {
    u16 h;
    u8 pad2[2];
    W4_80072994 a[0x17];
    u8 x60[0x50];
    u8 xB0[0x10];
    W8_80072994 c[3];
    u8 padD8[0xC];
    u8 xE4[8];
    W4_80072994 e[5];
};

struct Obj_80072BB0 { u8 pad[0x30]; u32 f30; };

extern "C" {
void TLobby__sub_80072880(u8 *arg0);
void TLobby__sub_800728FC(u8 *arg0);
void TLobby__sub_80072AB8(void *arg0);
s32 TLobby__sub_8006FBE4();
void TWindow__close(u8 *arg0);
s32 TQuestVmDownLoadServer__sub_8006EF6C(s32);
s32 get_window_layout_position(s32);
u32 check_room_seq_4__16TAdChrSelASlotGCFl(s32, s32);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
void TLobby__sub_8024AC20(s32 arg0);
s32 get_player_by_client_id(s32);
s32 check_player_flag1__6TLobbyFv();
extern s32 local_client_id;
void TObjPlayer__sub_8024ABDC(s32 arg0);
void play_effect_default__10TObjPlayerFii(s32 arg0, s32 arg1);
extern s32 TLobby__designated_client_id;
u8 is_challenge_lobby__6TLobbyFv(void);
void queue_destruction__7TObjectFv(void *arg0);
s32 TLobby__sub_80070DA8();
void play_player_default_effect__6TLobbyFv(s32 _w0);
s32 play_sound_effect(s32, s32, s32, s32);
void play_cue_stream_file(s32 name);
extern s32 lbl_804385D4[];
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 get_selected_menu_value(u32);
s32 challenge_retry_cmd_table[3] = { 1, 0, 0 };
extern s8 controller_input_state[];
s32 check_flag_100__10TObjPlayerFPv();
u32 set_window_mode_4__6TLobbyFPvll(s32, void *, s32);
__declspec(section ".data") f32 challenge_retry_window_pos[2] = { 360.0f, 125.0f };
extern const f32 lbl_805D9110;
void TLobby__sub_80072724(TLobby *arg0);
void TLobby__sub_80072758(u8 *arg0);
void TLobby__sub_800727A0(void *arg0);
void TLobby__sub_800727EC(u8 *arg0);

void TLobby::bswap_challenge_dead_flag() {
    ((G_ClientIDHeader *)this)->bswap();
    bswap_32((u32 *)((char *)this + 4));
}

void TLobby__sub_80072724(TLobby *lobby) {
    lobby->bswap_challenge_dead_flag();
    send_subcommand((u8 *)lobby);
}

void TLobby__sub_80072758(u8 *arg0) {
    *(u8 *)((s8 *)arg0 + 0) = 0x9D;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TLobby::send_and_handle_60_wrapper() {
    TLobby__sub_800727A0(this);
    send_subcommand((u8 *)this);
}

void TLobby__sub_800727A0(void *player) {
    ((G_ClientIDHeader *)player)->bswap();
    bswap_32((u32 *)((char *)player + 4));
    bswap_32((u32 *)((char *)player + 8));
    bswap_32((u32 *)((char *)player + 12));
    bswap_32((u32 *)((char *)player + 16));
}

void TLobby__sub_800727EC(u8 *arg0) {
    *(u8 *)((s8 *)arg0 + 0) = 0x97;
    *(s8 *)((s8 *)arg0 + 1) = 5;
}

void TLobby::byteswap_challenge_time_packet() {
    ((G_ClientIDHeader *)this)->bswap();
    bswap_32((u32 *)((char *)this + 4));
    bswap_32((u32 *)((char *)this + 8));
    bswap_32((u32 *)((char *)this + 12));
    bswap_32((u32 *)((char *)this + 16));
}

void TLobby::send_state() {
    byteswap_challenge_time_packet();
    send_subcommand((u8 *)this);
}
void TLobby__sub_80072880(u8 *arg0) {
    *(u8 *)((s8 *)arg0 + 0) = 0x95;
    *(s8 *)((s8 *)arg0 + 1) = 5;
}
void TLobby::byteswap_challenge_packet() {
    ((G_ClientIDHeader *)this)->bswap();
    bswap_32((u32 *)((char *)this + 4));
}
void TLobby::send_challenge_packet() {
    byteswap_challenge_packet();
    send_subcommand((u8 *)this);
}
void TLobby__sub_800728FC(u8 *arg0) {
    *(u8 *)((s8 *)arg0 + 0) = 0x8A;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}
void TLobby::bswap_6x7C_packet() {
    s32 arg0 = (s32)this;
    ((G_ClientIDHeader *)arg0)->bswap();
    bswap_16((u16 *)(arg0 + 4));
    ((TLobby *)(arg0 + 8))->bswap_challenge_battle_records();
}
void TLobby::send_6x7C_packet() {
    s32 arg0 = (s32)this;
    bswap_6x7C_packet();
    send_subcommand((u8 *)arg0);
}
void TLobby::init_pkt_cmd_7C() {
    *(s8 *)&this->m_name = 0x7C;
    *(s8 *)((s8 *)((u8 *)this) + 1) = 0x42;
}

s32 TLobby::bswap_challenge_battle_records() {
    s32 arg0 = (s32)this;
    S_80072994 *s = (S_80072994 *)arg0;
    s32 i;
    bswap_16((u16 *)arg0);
    for (i = 0; i < 0x17; i++) {
        ((TLobby *)(&s->a[i]))->bswap_packet_field();
    }
    TLobby__sub_80072AB8(s->x60);
    ((TLobby *)(s->xB0))->bswap_fields_4_8_12();
    for (i = 0; i < 3; i++) {
        ((TLobby *)(&s->c[i]))->bswap_fields_0_4();
    }
    ((TLobby *)(s->xE4))->bswap_fields_0_4();
    for (i = 0; i < 5; i++) {
        ((TLobby *)(&s->e[i]))->bswap_packet_field();
    }
}

void TLobby::bswap_fields_0_4() {
    bswap_32((u32 *)this);
    bswap_32((u32 *)((char *)this + 4));
}
void TLobby::bswap_fields_4_8_12() {
    bswap_32((u32 *)((char *)this + 4));
    bswap_32((u32 *)((char *)this + 8));
    bswap_32((u32 *)((char *)this + 12));
}
void TLobby__sub_80072AB8(void *arg0) {
    bswap_16((u16 *)((void *)((char *)arg0 + 4)));
    bswap_32((u32 *)((char *)arg0 + 8));
    bswap_32((u32 *)((char *)arg0 + 12));
    bswap_32((u32 *)((char *)arg0 + 16));
    bswap_32((u32 *)((char *)arg0 + 20));
    bswap_32((u32 *)((char *)arg0 + 24));
}
void TLobby::bswap_packet_field() {
    bswap_32((u32 *)this);
}
s32 TLobby::is_ready_to_draw() {
    if ((TLobby::get_flag_value_if_set() != 0) || (TLobby__sub_8006FBE4() <= 1)) {
        return 0;
    }
    return 1;
}
void TObjChallengeRetry::sub_80072B70() {
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x30) != 0U) {
        TWindow__close((u8 *)(*(void **)((s8 *)((u8 *)this) + 0x30)));
        *(u32 *)((s8 *)((u8 *)this) + 0x30) = 0U;
    }
}

void TObjChallengeRetry::sub_80072BB0() {
    if (((Obj_80072BB0 *)this)->f30 != 0) {
        TWindow__close((u8 *)((void *)((Obj_80072BB0 *)this)->f30));
        ((Obj_80072BB0 *)this)->f30 = 0;
    }
    ((Obj_80072BB0 *)this)->f30 = set_window_mode_4__6TLobbyFPvll(get_window_layout_position(0x39), challenge_retry_window_pos, 1);
    if (((Obj_80072BB0 *)this)->f30 != 0) {
        ((TLobby *)(((Obj_80072BB0 *)this)->f30))->set_field_1c(lbl_805D9110);
        ((TLobby *)(((Obj_80072BB0 *)this)->f30))->send_and_handle(TQuestVmDownLoadServer__sub_8006EF6C(0x5E), 1);
    }
}

void TObjChallengeRetry::close_window_2c() { if (*(unsigned int*)((char*)this + 0x2c) != 0) { TWindow__close((u8 *)(*(void**)((char*)this + 0x2c))); *(int*)((char*)this + 0x2c) = 0; } }
void TObjChallengeRetry::open_loss_menu() {
    if ((u32) *(u32 *)((s8 *)this + 0x2C) != 0U) {
        TWindow__close((u8 *)(*(u32 *)((s8 *)this + 0x2C)));
        *(u32 *)((s8 *)this + 0x2C) = 0U;
    }
    *(u32 *)((s8 *)this + 0x2C) = check_room_seq_4__16TAdChrSelASlotGCFl(get_window_layout_position(0x3A), 3);
    if ((u32) *(u32 *)((s8 *)this + 0x2C) != 0U) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)(*(u32 *)((s8 *)this + 0x2C)), (int)(TQuestVmDownLoadServer__sub_8006EF6C(0x5B)), 5, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)(*(u32 *)((s8 *)this + 0x2C)), (int)(TQuestVmDownLoadServer__sub_8006EF6C(0x5C)), 5, 1);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)(*(u32 *)((s8 *)this + 0x2C)), (int)(TQuestVmDownLoadServer__sub_8006EF6C(0x5D)), 5, 2);
        ((TWindowSubComCard *)(*(u32 *)((s8 *)this + 0x2C)))->calc_window_size();
        ((TLobby *)(*(u32 *)((s8 *)this + 0x2C)))->set_loss_flag();
        ((TWindowSubComCardList *)(*(u32 *)((s8 *)this + 0x2C)))->set_selected_index(2);
    }
}
void TLobby::send_45_and_close_windows(void * _w0) {
    s32 player;
    player = get_player_by_client_id(local_client_id);
    if ((player != 0) && (check_player_flag1__6TLobbyFv() != 0)) {
        TObjPlayer::send_code_45_1(player);
    }
    ((TWindowCtrl *)local_client_id)->unsuppress_slot();
    TLobby__sub_8024AC20(local_client_id);
}
void TLobby::show_ctrl_and_play_effect(void* a0) { ((TWindowCtrl *)(*(int *)&local_client_id))->suppress_slot(); play_player_default_effect__6TLobbyFv((s32)a0); }
void TLobby::play_default_effect(void* a0) { TObjPlayer__sub_8024ABDC(((*(int *)&local_client_id))); play_player_default_effect__6TLobbyFv((s32)a0); }
void play_player_default_effect__6TLobbyFv(s32 _w0) {
    s32 player;
    player = get_player_by_client_id(local_client_id);
    if ((player != 0) && (check_player_flag1__6TLobbyFv() == 0)) {
        play_effect_default__10TObjPlayerFii(player, -1);
    }
}
u8 is_challenge_lobby__6TLobbyFv(void) {
    return (u8) (local_client_id == TLobby__designated_client_id);
}
void TObjChallengeRetry::update_destroy_countdown() {
    s32 temp_r0;
    TLobby::play_default_effect(this);
    temp_r0 = *(s32 *)((s8 *)this + 0x28) - 1;
    *(s32 *)((s8 *)this + 0x28) = temp_r0;
    if (temp_r0 <= 0) {
        TLobby::advance_state_if_flag_set();
        TLobby::send_45_and_close_windows(this);
        close_window_2c();
        sub_80072B70();
        queue_destruction__7TObjectFv(this);
    }
}
void TObjChallengeRetry::handle_loss_sequence() {
    play_player_default_effect__6TLobbyFv((s32)this);
    switch (TLobby__sub_80070DA8()) {
    case 0:
        play_cue_stream_file((s32)lbl_804385D4);
        TLobby::send_45_and_close_windows(this);
        close_window_2c();
        sub_80072B70();
        queue_destruction__7TObjectFv(this);
        return;
    case 1:
        play_sound_effect(0x52812, 0, 0, 0);
        TLobby::send_45_and_close_windows(this);
        TLobby::play_default_effect(this);
        sub_80072B70();
        close_window_2c();
        *(s32 *)((s8 *)this + 0x28) = 0x1E;
        *(s32 *)&this->_pad1c = 4;
        return;
    default:
        if (((s32) this->m_20 != 0) && ((s32) this->m_24 == 0)) {
            TLobby::send_45_and_close_windows(this);
            TLobby::show_ctrl_and_play_effect(this);
            sub_80072B70();
            open_loss_menu();
            *(s32 *)&this->_pad1c = 2;
        }
        return;
    }
}
void TObjChallengeRetry::update_challenge_retry() {
    s32 selected_menu_value;
    s32 var_r31;
    TLobby::show_ctrl_and_play_effect(this);
    if ((u32) *(u32 *)((s8 *)this + 0x2C) == 0U) {
        open_loss_menu();
    }
    var_r31 = 0;
    if (((TWindowMenu *)(*(u32 *)((s8 *)this + 0x2C)))->is_visible() != 0) {
        selected_menu_value = get_selected_menu_value(*(u32 *)((s8 *)this + 0x2C));
        if (selected_menu_value == 2) {
            var_r31 = 1;
            goto block_6;
        }
        TLobby::send_challenge_retry_cmd(challenge_retry_cmd_table[selected_menu_value]);
        TLobby::send_45_and_close_windows(this);
        play_player_default_effect__6TLobbyFv((s32)this);
        this->m_24 = 1;
        *(s32 *)&this->_pad1c = 3;
        return;
    }
block_6:
    if ((var_r31 != 0) || (TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 2) != 0)) {
        close_window_2c();
        TLobby::send_45_and_close_windows(this);
        TLobby::play_default_effect(this);
        *(s32 *)&this->_pad1c = 1;
    }
}
void TObjChallengeRetry::handle_challenge_retry_confirm() {
    TLobby::play_default_effect(this);
    if ((((u32)get_player_by_client_id(local_client_id)) != 0U) && (check_flag_100__10TObjPlayerFPv() == 0) && (TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 4) != 0)) {
        TLobby::send_45_and_close_windows(this);
        TLobby::show_ctrl_and_play_effect(this);
        *(s32 *)&this->_pad1c = 2;
    }
}

s32 obj_testFlags30__13TUnk_804AF8A0FUl(void *, s32);

s32 TWindowCtrlMain__sub_8024CE58(void);

void TObjChallengeRetry::sub_8007313C() {
  s32 global_state;
  s32 var_r31;
  int new_var;
  u32 var_r30;
  u8 *temp_r3_2;
  global_state = get_current_area();
  if (global_state != 0x12)
  {
    if (global_state < 0x12)
    {
      if (global_state != 0)
      {
        return;
      }
      goto block_4;
    }
  }
  else
  {
    new_var = 0;
    block_4:
    if (TWindowCtrlMain__sub_8024CE58() != 0)
    {
      ((s32 (*)(void *))play_player_default_effect__6TLobbyFv)((void *) ((u8 *)this));
      var_r31 = 1;
      var_r30 = new_var;
      loop_6:
      temp_r3_2 = (u8 *) ((s32 (*)(u32))get_player_by_client_id)(var_r30);
      if ((temp_r3_2 != 0) && (obj_testFlags30__13TUnk_804AF8A0FUl(temp_r3_2, 0x02000000) != 0))
      {
        var_r31 = 0;
      }
      else
      {
        var_r30 += 1;
        if (((s32) var_r30) < 4)
        {
          goto loop_6;
        }
      }
      if (var_r31 != 0)
      {
        if ((this->m_20) != 0)
        {
          TLobby::send_45_and_close_windows((void *) ((u8 *)this));
          TLobby::show_ctrl_and_play_effect((void *) ((u8 *)this));
          *((s32 *) (((s8 *) ((u8 *)this)) + 0x1C)) = 2;
          return;
        }
        TLobby::send_45_and_close_windows((void *) ((u8 *)this));
        ((s32 (*)(void *))play_player_default_effect__6TLobbyFv)((void *) ((u8 *)this));
        sub_80072BB0();
        *((s32 *) (((s8 *) ((u8 *)this)) + 0x1C)) = 3;
      }
    }
  }
}

void *fn_800733C4(void *arg0);
void *__ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__18TObjChallengeRetry[];
extern s32 TObjChallengeRetry__class_name;
void *TObjChallengeRetry__ct(void *, void *);
void *__nw__7TObjectFUl(int);
void TObjChallengeRetry::run_task() {
    u8 *arg0 = (u8 *)this;
    this->m_20 = ((s32 (*)(void *))is_challenge_lobby__6TLobbyFv)(arg0);
    switch (*(s32 *)&this->_pad1c) {
    case 0:
        ((TObjChallengeRetry *)arg0)->sub_8007313C();
        break;
    case 1:
        ((TObjChallengeRetry *)arg0)->handle_challenge_retry_confirm();
        break;
    case 2:
        ((TObjChallengeRetry *)arg0)->update_challenge_retry();
        break;
    case 3:
        ((TObjChallengeRetry *)arg0)->handle_loss_sequence();
        break;
    case 4:
        ((TObjChallengeRetry *)arg0)->update_destroy_countdown();
        break;
    }
    if (TLobby::is_ready_to_draw() == 0) {
        TLobby::send_45_and_close_windows(arg0);
        ((TObjChallengeRetry *)arg0)->close_window_2c();
        ((TObjChallengeRetry *)arg0)->sub_80072B70();
        queue_destruction__7TObjectFv(arg0);
    }
}

TObjChallengeRetry::~TObjChallengeRetry() {
    if (m_20 != 0 && m_24 == 0) {
        TLobby::send_challenge_retry_cmd(0);
    }
}

void *TObjChallengeRetry__ct(void *challenge_retry, void *parent) {
    __ct__7TObjectFP7TObject(challenge_retry, parent);
    *(s32 **)((s8 *)challenge_retry + 0x18) = __vt__18TObjChallengeRetry;
    *(s32 *)((s8 *)challenge_retry + 0) = (s32) TObjChallengeRetry__class_name;
    ((TObjChallengeRetry *)challenge_retry)->m_20 = ((s32 (*)(void *))is_challenge_lobby__6TLobbyFv)(challenge_retry);
    ((TObjChallengeRetry *)challenge_retry)->m_24 = 0;
    *(s32 *)((s8 *)challenge_retry + 0x2C) = 0;
    *(s32 *)((s8 *)challenge_retry + 0x30) = 0;
    *(s32 *)((s8 *)challenge_retry + 0x1C) = 0;
    return challenge_retry;
}

void *fn_800733C4(void *parent) {
    void *o = __nw__7TObjectFUl(0x34);
    if (o != NULL) {
        o = TObjChallengeRetry__ct(o, parent);
    }
    return o;
}

}
