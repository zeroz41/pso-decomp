#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowSetLevelUp.h"
#include "pso/ui/window/TWindowShop.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TextBuilder.h"
#include "pso/player/PlayerSlots.h"



const char *TWindowSetLevelUp::class_name = "TWindowSetLevelUp";

void TWindowShop::set_capacity(s32 capacity) { this->capacity = capacity; }

// The shown stats copy as one 0x16-byte block, then HP and TP.
struct ByteBlock_16 { u8 bytes[0x16]; };

void PlayerLevelStats::copy_stat_block(const PlayerLevelStats *src) {
    *(ByteBlock_16 *)this = *(const ByteBlock_16 *)src;
    hp_max = src->hp_max;
    tp_max = src->tp_max;
}


TWindowSetLevelUp::TWindowSetLevelUp(TObject *parent, saddr stats, s32 client) : TObject(parent) {
    m_name = class_name;
    stat_gains.copy_stat_block((const PlayerLevelStats *)stats);
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
    text_builder_append((const char *)(TWindowSubStatusDisp::get_message_10(0x46)));
    switch (state) {
    case 0:
    case 1:
        player = get_player_by_client_id(client);
        if (player != NULL && player->get_stats() != 0) {
            text_builder_append("LEVEL ");
            text_builder_append_int(player->get_actor_level_index() + 1);
            TWindowCtrl::append_client_message(client, get_shared_text_buffer());
            state = 2;
        }
        break;
    case 2:
        if (stat_gains.hp_max > 0) {
            text_builder_append("HP +");
            text_builder_append_int(stat_gains.hp_max);
            TWindowCtrl::append_client_message(client, get_shared_text_buffer());
            state = 3;
            break;
        }
    case 3:
        if (stat_gains.tp_max > 0) {
            text_builder_append("TP +");
            text_builder_append_int(stat_gains.tp_max);
            TWindowCtrl::append_client_message(client, get_shared_text_buffer());
            state = 4;
            break;
        }
    case 4:
        if (stat_gains.atp > 0) {
            text_builder_append((const char *)(TWindowSubStatusDisp::get_message_10(0x83)));
            text_builder_append(" +");
            text_builder_append_int(stat_gains.atp);
            TWindowCtrl::append_client_message(client, get_shared_text_buffer());
            state = 5;
            break;
        }
    case 5:
        if (stat_gains.dfp > 0) {
            text_builder_append((const char *)(TWindowSubStatusDisp::get_message_10(0x84)));
            text_builder_append(" +");
            text_builder_append_int(stat_gains.dfp);
            TWindowCtrl::append_client_message(client, get_shared_text_buffer());
            state = 6;
            break;
        }
    case 6:
        if (stat_gains.mst > 0) {
            text_builder_append((const char *)(TWindowSubStatusDisp::get_message_10(0x85)));
            text_builder_append(" +");
            text_builder_append_int(stat_gains.mst);
            TWindowCtrl::append_client_message(client, get_shared_text_buffer());
            state = 7;
            break;
        }
    case 7:
        if (stat_gains.ata > 0) {
            text_builder_append((const char *)(TWindowSubStatusDisp::get_message_10(0x86)));
            text_builder_append(" +");
            text_builder_append_int(stat_gains.ata);
            TWindowCtrl::append_client_message(client, get_shared_text_buffer());
            state = 8;
            break;
        }
    case 8:
        if (stat_gains.evp > 0) {
            text_builder_append((const char *)(TWindowSubStatusDisp::get_message_10(0x87)));
            text_builder_append(" +");
            text_builder_append_int(stat_gains.evp);
            TWindowCtrl::append_client_message(client, get_shared_text_buffer());
            state = 9;
            break;
        }
    case 9:
        queue_destruction();
        break;
    }
    timer = 0x16;
}
