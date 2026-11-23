#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowSetLevelUp.h"
#include "pso/ui/window/TWindowShop.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/player/PlayerSlots.h"


struct ByteBlock_16 { u8 bytes[0x16]; };

void text_builder_reset(void);

const char *TWindowSetLevelUp::class_name = "TWindowSetLevelUp";

void TWindowShop::set_capacity(s32 capacity) { this->capacity = capacity; }

void TWindowSetLevelUp::copy_stat_block(saddr stats) {
    saddr arg0 = (saddr)this;
    *(ByteBlock_16 *)(arg0) = *(const ByteBlock_16 *)(stats);
    *(s16 *)((s8 *)arg0 + 0x16) = (s16) *(s16 *)((s8 *)stats + 0x16);
    *(s16 *)((s8 *)arg0 + 0x18) = (s16) *(s16 *)((s8 *)stats + 0x18);
}

TWindowSetLevelUp::TWindowSetLevelUp(TObject *parent, saddr stats, s32 client) : TObject(parent) {
    ((TObjPlayer *)&stat_gains)->reset_sub_status_disp();
    m_name = class_name;
    ((TWindowSetLevelUp *)&stat_gains)->copy_stat_block(stats);
    timer = 0;
    this->client = client;
    state = 0;
}

TWindowSetLevelUp::~TWindowSetLevelUp() {
}

void TWindowSetLevelUp::run_task() {
    if (timer-- <= 0) {
        update_stat_messages();
    }
}

void TWindowSetLevelUp::render() {  }

void TWindowSetLevelUp::update_stat_messages() {
    TObjPlayer *player;

    text_builder_reset();
    text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x46)));
    switch (state) {
    case 0:
    case 1:
        player = get_player_by_client_id(client);
        if (player != NULL && player->get_stats() != 0) {
            text_builder_append((u8 *)"LEVEL ");
            text_builder_append_int(player->get_actor_level_index() + 1);
            TWindowCtrl::set_window_flags_off(client, (saddr)get_shared_text_buffer());
            state = 2;
        }
        break;
    case 2:
        if (hp_gain > 0) {
            text_builder_append((u8 *)"HP +");
            text_builder_append_int(hp_gain);
            TWindowCtrl::set_window_flags_off(client, (saddr)get_shared_text_buffer());
            state = 3;
            break;
        }
    case 3:
        if (tp_gain > 0) {
            text_builder_append((u8 *)"TP +");
            text_builder_append_int(tp_gain);
            TWindowCtrl::set_window_flags_off(client, (saddr)get_shared_text_buffer());
            state = 4;
            break;
        }
    case 4:
        if (stat_gains[0] > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x83)));
            text_builder_append((u8 *)" +");
            text_builder_append_int(stat_gains[0]);
            TWindowCtrl::set_window_flags_off(client, (saddr)get_shared_text_buffer());
            state = 5;
            break;
        }
    case 5:
        if (stat_gains[1] > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x84)));
            text_builder_append((u8 *)" +");
            text_builder_append_int(stat_gains[1]);
            TWindowCtrl::set_window_flags_off(client, (saddr)get_shared_text_buffer());
            state = 6;
            break;
        }
    case 6:
        if (stat_gains[2] > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x85)));
            text_builder_append((u8 *)" +");
            text_builder_append_int(stat_gains[2]);
            TWindowCtrl::set_window_flags_off(client, (saddr)get_shared_text_buffer());
            state = 7;
            break;
        }
    case 7:
        if (stat_gains[3] > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x86)));
            text_builder_append((u8 *)" +");
            text_builder_append_int(stat_gains[3]);
            TWindowCtrl::set_window_flags_off(client, (saddr)get_shared_text_buffer());
            state = 8;
            break;
        }
    case 8:
        if (stat_gains[4] > 0) {
            text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x87)));
            text_builder_append((u8 *)" +");
            text_builder_append_int(stat_gains[4]);
            TWindowCtrl::set_window_flags_off(client, (saddr)get_shared_text_buffer());
            state = 9;
            break;
        }
    case 9:
        queue_destruction();
        break;
    }
    timer = 0x16;
}
