#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "types.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/system/byteswap.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/object/TObjChallengeRetry.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/ControllerInput.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"


#pragma readonly_strings on

void build_6x95_packet(u8 *arg0);
void build_6x8A_packet(u8 *arg0);
extern "C" {
u8 is_challenge_lobby__6TLobbyFv(void);
s32 challenge_retry_cmd_table[3] = { 1, 0, 0 };
__declspec(section ".data") f32 challenge_retry_window_pos[2] = { 360.0f, 125.0f };
}

const char *obj_challenge_retry_class_name = "TObjChallengeRetry";
void send_challenge_dead_flag_packet(TLobby *lobby);
void build_6x9D_packet(u8 *arg0);
extern "C" {
void TLobby__sub_800727A0(void *player);
}
void build_6x97_packet(u8 *arg0);

void TLobby::bswap_challenge_dead_flag() {
    ((G_ClientIDHeader *)this)->bswap();
    bswap_32((u32 *)((char *)this + 4));
}
void send_challenge_dead_flag_packet(TLobby *lobby) {
    lobby->bswap_challenge_dead_flag();
    send_subcommand((u8 *)lobby);
}

void build_6x9D_packet(u8 *arg0) {
    *(u8 *)((s8 *)arg0 + 0) = 0x9D;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TLobby::send_and_handle_60_wrapper() {
    TLobby__sub_800727A0(this);
    send_subcommand(this);
}
extern "C" {

void TLobby__sub_800727A0(void *player) {
    ((G_ClientIDHeader *)player)->bswap();
    bswap_32((u32 *)((char *)player + 4));
    bswap_32((u32 *)((char *)player + 8));
    bswap_32((u32 *)((char *)player + 12));
    bswap_32((u32 *)((char *)player + 16));
}
}

void build_6x97_packet(u8 *arg0) {
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
    send_subcommand(this);
}
void build_6x95_packet(u8 *arg0) {
    *(u8 *)((s8 *)arg0 + 0) = 0x95;
    *(s8 *)((s8 *)arg0 + 1) = 5;
}
void TLobby::byteswap_challenge_packet() {
    ((G_ClientIDHeader *)this)->bswap();
    bswap_32((u32 *)((char *)this + 4));
}
void TLobby::send_challenge_packet() {
    byteswap_challenge_packet();
    send_subcommand(this);
}
void build_6x8A_packet(u8 *arg0) {
    *(u8 *)((s8 *)arg0 + 0) = 0x8A;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}
void G_SetChallengeRecords_V3_6x7C::bswap() {
    __base_G_SetChallengeRecordsBase_6x7C.header.bswap();
    bswap_16(&__base_G_SetChallengeRecordsBase_6x7C.client_id);
    records.bswap();
}
void G_SetChallengeRecords_V3_6x7C::send() {
    bswap();
    send_subcommand(this);
}
G_SetChallengeRecords_V3_6x7C::G_SetChallengeRecords_V3_6x7C() {
    __base_G_SetChallengeRecordsBase_6x7C.header.subcommand = 0x7C;
    __base_G_SetChallengeRecordsBase_6x7C.header.size = 0x42;
}

void ChallengeRecord::bswap() {
    s32 i;
    bswap_16(&title_color);
    for (i = 0; i < 0x17; i++) {
        bswap_packet_field(&stage_times[i]);
    }
    tombstone.bswap();
    tombstone_spot.bswap();
    for (i = 0; i < 3; i++) {
        ranks[i].bswap();
    }
    ep2_split_rank.bswap();
    for (i = 0; i < 5; i++) {
        bswap_packet_field(&ep2_split_stage_times[i]);
    }
}

void ChallengeStageRank::bswap() {
    bswap_32(&award_flags);
    bswap_32((u32 *)&rank);
}
void TObjTombstoneSpot::bswap() {
    bswap_32((u32 *)&position.x);
    bswap_32((u32 *)&position.y);
    bswap_32((u32 *)&position.z);
}
void TObjTombstoneRecord::bswap() {
    bswap_16((u16 *)&deaths);
    bswap_32(&date);
    bswap_32((u32 *)&rt_index);
    bswap_32((u32 *)&position.x);
    bswap_32((u32 *)&position.y);
    bswap_32((u32 *)&position.z);
}
void bswap_packet_field(s32 *value) {
    bswap_32((u32 *)value);
}
extern "C" {
s32 TLobby::is_ready_to_draw() {
    if ((is_challenge_retry_menu_disabled() != 0) || (count_challenge_players() <= 1)) {
        return 0;
    }
    return 1;
}
void TObjChallengeRetry::sub_80072B70() {
    if (this->message != NULL) {
        this->message->close();
        this->message = NULL;
    }
}

void TObjChallengeRetry::sub_80072BB0() {
    if (this->message != NULL) {
        this->message->close();
        this->message = NULL;
    }
    this->message = TWindowMessage::create(
        get_window_layout_position(0x39),
        challenge_retry_window_pos, 1);
    if (this->message != NULL) {
        this->message->set_depth(70200.0f);
        this->message->append_line(get_message_text(0x5E), 1);
    }
}

void TObjChallengeRetry::close_window_2c() {
    if (this->menu != NULL) {
        this->menu->close();
        this->menu = NULL;
    }
}
void TObjChallengeRetry::open_loss_menu() {
    if (this->menu != NULL) {
        this->menu->close();
        this->menu = NULL;
    }
    this->menu = reinterpret_cast<TWindowSubComCardList *>(create_window_menu_default(get_window_layout_position(0x3A), 3));
    if (this->menu != NULL) {
        this->menu->add_text_entry(get_message_text(0x5B), 5, 0);
        this->menu->add_text_entry(get_message_text(0x5C), 5, 1);
        this->menu->add_text_entry(get_message_text(0x5D), 5, 2);
        this->menu->calc_window_size();
        this->menu->set_loss_flag();
        this->menu->set_selected_index(2);
    }
}
void TLobby::send_45_and_close_windows(void * _w0) {
    TObjPlayer *player;
    player = get_player_by_client_id(local_client_id);
    if ((player != NULL) && (player->check_player_flag1() != 0)) {
        send_release_hold(player);
    }
    TWindowCtrl::unsuppress_slot(local_client_id);
    TWindowCtrl::enable_client_main_menu(local_client_id);
}
void TLobby::show_ctrl_and_play_effect(void* a0) { TWindowCtrl::suppress_slot(*(int *)&local_client_id); ((TLobby *)a0)->play_player_default_effect(); }
void TLobby::play_default_effect(void* a0) { TWindowCtrl::disable_client_main_menu(local_client_id); ((TLobby *)a0)->play_player_default_effect(); }
void TLobby::play_player_default_effect() {
    TObjPlayer *player;
    player = get_player_by_client_id(local_client_id);
    if ((player != NULL) && (player->check_player_flag1() == 0)) {
        send_impose_hold(player, -1);
    }
}
u8 is_challenge_lobby__6TLobbyFv(void) {
    return (u8) (local_client_id == designated_client_id);
}
void TObjChallengeRetry::update_destroy_countdown() {
    s32 countdown;
    TLobby::play_default_effect(this);
    countdown = this->countdown - 1;
    this->countdown = countdown;
    if (countdown <= 0) {
        confirm_challenge_retry();
        TLobby::send_45_and_close_windows(this);
        close_window_2c();
        sub_80072B70();
        queue_destruction();
    }
}
void TObjChallengeRetry::handle_loss_sequence() {
    ((TLobby *)this)->play_player_default_effect();
    switch (get_challenge_failure_choice()) {
    case 0:
        play_cue_stream_file("lose.adx");
        TLobby::send_45_and_close_windows(this);
        close_window_2c();
        sub_80072B70();
        queue_destruction();
        return;
    case 1:
        play_sound_effect(0x52812, 0, 0, 0);
        TLobby::send_45_and_close_windows(this);
        TLobby::play_default_effect(this);
        sub_80072B70();
        close_window_2c();
        this->countdown = 0x1E;
        this->state = 4;
        return;
    default:
        if (((s32) this->m_20 != 0) && ((s32) this->m_24 == 0)) {
            TLobby::send_45_and_close_windows(this);
            TLobby::show_ctrl_and_play_effect(this);
            sub_80072B70();
            open_loss_menu();
            this->state = 2;
        }
        return;
    }
}
void TObjChallengeRetry::update_challenge_retry() {
    s32 selected_menu_value;
    s32 var_r31;
    TLobby::show_ctrl_and_play_effect(this);
    if (this->menu == NULL) {
        open_loss_menu();
    }
    var_r31 = 0;
    if (this->menu->is_decided() != 0) {
        selected_menu_value = this->menu->get_selected_value();
        if (selected_menu_value == 2) {
            var_r31 = 1;
            goto block_6;
        }
        TLobby::send_challenge_retry_cmd(challenge_retry_cmd_table[selected_menu_value]);
        TLobby::send_45_and_close_windows(this);
        ((TLobby *)this)->play_player_default_effect();
        this->m_24 = 1;
        this->state = 3;
        return;
    }
block_6:
    if ((var_r31 != 0) || (test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0)) {
        close_window_2c();
        TLobby::send_45_and_close_windows(this);
        TLobby::play_default_effect(this);
        this->state = 1;
    }
}
void TObjChallengeRetry::handle_challenge_retry_confirm() {
    TObjPlayer *player;
    TLobby::play_default_effect(this);
    player = get_player_by_client_id(local_client_id);
    if ((player != NULL) && (player->is_controls_locked() == 0) && (test_pressed_buttons_packed(&controller_input_state.controllers[0], 4) != 0)) {
        TLobby::send_45_and_close_windows(this);
        TLobby::show_ctrl_and_play_effect(this);
        this->state = 2;
    }
}


void TObjChallengeRetry::sub_8007313C() {
  s32 area;
  s32 var_r31;
  int new_var;
  s32 var_r30;
  TObjPlayer *player;
  area = get_current_floor_area();
  if (area != AREA_PIONEER2_EP2)
  {
    if (area < 0x12)
    {
      if (area != AREA_PIONEER2_EP1)
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
    if (has_window_task_root() != 0)
    {
      ((TLobby *)this)->play_player_default_effect();
      var_r31 = 1;
      var_r30 = new_var;
      loop_6:
      player = get_player_by_client_id(var_r30);
      if (player != NULL && player->test_actor_flags(0x02000000) != 0)
      {
        var_r31 = 0;
      }
      else
      {
        var_r30 += 1;
        if (var_r30 < 4)
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
          this->state = 2;
          return;
        }
        TLobby::send_45_and_close_windows((void *) ((u8 *)this));
        ((TLobby *)this)->play_player_default_effect();
        sub_80072BB0();
        this->state = 3;
      }
    }
  }
}

extern const char *obj_challenge_retry_class_name;
void TObjChallengeRetry::run_task() {
    u8 *arg0 = (u8 *)this;
    this->m_20 = ((s32 (*)(void *))is_challenge_lobby__6TLobbyFv)(arg0);
    switch (this->state) {
    case 0:
        this->sub_8007313C();
        break;
    case 1:
        this->handle_challenge_retry_confirm();
        break;
    case 2:
        this->update_challenge_retry();
        break;
    case 3:
        this->handle_loss_sequence();
        break;
    case 4:
        this->update_destroy_countdown();
        break;
    }
    if (TLobby::is_ready_to_draw() == 0) {
        TLobby::send_45_and_close_windows(arg0);
        this->close_window_2c();
        this->sub_80072B70();
        this->queue_destruction();
    }
}

TObjChallengeRetry::~TObjChallengeRetry() {
    if (m_20 != 0 && m_24 == 0) {
        TLobby::send_challenge_retry_cmd(0);
    }
}

TObjChallengeRetry::TObjChallengeRetry(TObject *parent) : TObject(parent) {
    m_name = obj_challenge_retry_class_name;
    m_20 = ((s32 (*)(void *))is_challenge_lobby__6TLobbyFv)(this);
    m_24 = 0;
    menu = NULL;
    message = NULL;
    state = 0;
}

TObjChallengeRetry *TObjChallengeRetry::create(TObject *parent) {
    return new TObjChallengeRetry(parent);
}

}
