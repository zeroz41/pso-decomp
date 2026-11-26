#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/network/TGameProtocol.h"
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
#include "pso/object/TObjChallengeRetry.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/ControllerInput.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowCtrlMain.h"


#pragma readonly_strings on

void build_6x95_packet(u8 *packet);
void build_6x8A_packet(u8 *packet);
extern "C" {
s32 challenge_retry_cmd_table[3] = { 1, 0, 0 };
__declspec(section ".data") f32 challenge_retry_window_pos[2] = { 360.0f, 125.0f };
}

const char *obj_challenge_retry_class_name = "TObjChallengeRetry";
void send_challenge_dead_flag_packet(G_SetChallengeDeadFlag_6x9D *packet);
void build_6x9D_packet(u8 *packet);
extern "C" {
void bswap_client_id_packet(void *player);
}
void build_6x97_packet(u8 *packet);

void G_SetChallengeDeadFlag_6x9D::bswap() {
    header.bswap();
    bswap_32(&client_id);
}
void send_challenge_dead_flag_packet(G_SetChallengeDeadFlag_6x9D *packet) {
    packet->bswap();
    send_subcommand((u8 *)packet);
}

void build_6x9D_packet(u8 *packet) {
    G_ClientIDHeader *header = (G_ClientIDHeader *)packet;
    header->subcommand = 0x9D;
    header->size = 2;
}

void TLobby::send_and_handle_60_wrapper() {
    bswap_client_id_packet(this);
    send_subcommand(this);
}
extern "C" {

void bswap_client_id_packet(void *player) {
    ((G_ClientIDHeader *)player)->bswap();
    bswap_32((u32 *)((char *)player + 4));
    bswap_32((u32 *)((char *)player + 8));
    bswap_32((u32 *)((char *)player + 12));
    bswap_32((u32 *)((char *)player + 16));
}
}

void build_6x97_packet(u8 *packet) {
    G_ClientIDHeader *header = (G_ClientIDHeader *)packet;
    header->subcommand = 0x97;
    header->size = 5;
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
void build_6x95_packet(u8 *packet) {
    G_ClientIDHeader *header = (G_ClientIDHeader *)packet;
    header->subcommand = 0x95;
    header->size = 5;
}
void TLobby::byteswap_challenge_packet() {
    ((G_ClientIDHeader *)this)->bswap();
    bswap_32((u32 *)((char *)this + 4));
}
void TLobby::send_challenge_packet() {
    byteswap_challenge_packet();
    send_subcommand(this);
}
void build_6x8A_packet(u8 *packet) {
    G_ClientIDHeader *header = (G_ClientIDHeader *)packet;
    header->subcommand = 0x8A;
    header->size = 2;
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
s32 is_ready_to_draw() {
    if ((is_challenge_retry_menu_disabled() != 0) || (count_challenge_players() <= 1)) {
        return 0;
    }
    return 1;
}
extern "C" {
void TObjChallengeRetry::close_message() {
    if (this->message != NULL) {
        this->message->close();
        this->message = NULL;
    }
}

void TObjChallengeRetry::open_message() {
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
void TObjChallengeRetry::send_45_and_close_windows() {
    TObjPlayer *player;
    player = get_player_by_client_id(local_client_id);
    if ((player != NULL) && (player->check_player_flag1() != 0)) {
        send_release_hold(player);
    }
    TWindowCtrl::unsuppress_slot(local_client_id);
    TWindowCtrl::enable_client_main_menu(local_client_id);
}
void TObjChallengeRetry::show_ctrl_and_play_effect() {
    TWindowCtrl::suppress_slot(local_client_id);
    play_player_default_effect();
}

void TObjChallengeRetry::play_default_effect() {
    TWindowCtrl::disable_client_main_menu(local_client_id);
    play_player_default_effect();
}

void TObjChallengeRetry::play_player_default_effect() {
    TObjPlayer *player;
    player = get_player_by_client_id(local_client_id);
    if ((player != NULL) && (player->check_player_flag1() == 0)) {
        send_impose_hold(player, -1);
    }
}
s32 TObjChallengeRetry::is_designated_client() {
    return local_client_id == designated_client_id;
}
void TObjChallengeRetry::update_destroy_countdown() {
    s32 countdown;
    play_default_effect();
    countdown = this->countdown - 1;
    this->countdown = countdown;
    if (countdown <= 0) {
        confirm_challenge_retry();
        send_45_and_close_windows();
        close_window_2c();
        close_message();
        queue_destruction();
    }
}
void TObjChallengeRetry::handle_loss_sequence() {
    play_player_default_effect();
    switch (get_challenge_failure_choice()) {
    case 0:
        play_cue_stream_file("lose.adx");
        send_45_and_close_windows();
        close_window_2c();
        close_message();
        queue_destruction();
        return;
    case 1:
        play_sound_effect(0x52812, 0, 0, 0);
        send_45_and_close_windows();
        play_default_effect();
        close_message();
        close_window_2c();
        this->countdown = 0x1E;
        this->state = 4;
        return;
    default:
        if ((this->is_designated != 0) && (this->selection_sent == 0)) {
            send_45_and_close_windows();
            show_ctrl_and_play_effect();
            close_message();
            open_loss_menu();
            this->state = 2;
        }
        return;
    }
}
void TObjChallengeRetry::update_challenge_retry() {
    s32 selected_menu_value;
    s32 close_requested;
    show_ctrl_and_play_effect();
    if (this->menu == NULL) {
        open_loss_menu();
    }
    close_requested = 0;
    if (this->menu->is_decided() != 0) {
        selected_menu_value = this->menu->get_selected_value();
        if (selected_menu_value == 2) {
            close_requested = 1;
        } else {
            TLobby::send_challenge_retry_cmd(challenge_retry_cmd_table[selected_menu_value]);
            send_45_and_close_windows();
            play_player_default_effect();
            this->selection_sent = 1;
            this->state = 3;
            return;
        }
    }
    if ((close_requested != 0) || (test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0)) {
        close_window_2c();
        send_45_and_close_windows();
        play_default_effect();
        this->state = 1;
    }
}
void TObjChallengeRetry::handle_challenge_retry_confirm() {
    TObjPlayer *player;
    play_default_effect();
    player = get_player_by_client_id(local_client_id);
    if ((player != NULL) && (player->is_controls_locked() == 0) && (test_pressed_buttons_packed(&controller_input_state.controllers[0], 4) != 0)) {
        send_45_and_close_windows();
        show_ctrl_and_play_effect();
        this->state = 2;
    }
}


void TObjChallengeRetry::sub_8007313C() {
  s32 area;
  s32 no_player_flagged;
  int first_client;
  s32 client;
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
    first_client = 0;
    block_4:
    if (has_window_task_root() != 0)
    {
      play_player_default_effect();
      no_player_flagged = 1;
      client = first_client;
      loop_6:
      player = get_player_by_client_id(client);
      if (player != NULL && player->test_actor_flags(0x02000000) != 0)
      {
        no_player_flagged = 0;
      }
      else
      {
        client += 1;
        if (client < 4)
        {
          goto loop_6;
        }
      }
      if (no_player_flagged != 0)
      {
        if ((this->is_designated) != 0)
        {
          send_45_and_close_windows();
          show_ctrl_and_play_effect();
          this->state = 2;
          return;
        }
        send_45_and_close_windows();
        play_player_default_effect();
        open_message();
        this->state = 3;
      }
    }
  }
}

void TObjChallengeRetry::run_task() {
    this->is_designated = is_designated_client();
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
    if (is_ready_to_draw() == 0) {
        send_45_and_close_windows();
        this->close_window_2c();
        this->close_message();
        this->queue_destruction();
    }
}

TObjChallengeRetry::~TObjChallengeRetry() {
    if (is_designated != 0 && selection_sent == 0) {
        TLobby::send_challenge_retry_cmd(0);
    }
}

TObjChallengeRetry::TObjChallengeRetry(TObject *parent) : TObject(parent) {
    m_name = obj_challenge_retry_class_name;
    is_designated = is_designated_client();
    selection_sent = 0;
    menu = NULL;
    message = NULL;
    state = 0;
}

TObjChallengeRetry *TObjChallengeRetry::create(TObject *parent) {
    return new TObjChallengeRetry(parent);
}

}
