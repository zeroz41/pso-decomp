#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/quest/challenge/TChallenge.h"
#include "pso/quest/challenge/ChallengeModeState.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"

#include <stddef.h>

struct SendChallengeWithValueStack {
    s32 sp8;
    s32 spC;
};

#include "pso/network/protocol/subcmd_6x.h"
#include "pso/network/protocol/SubcommandHandlers.h"
#include "pso/unk/text_80072230.h"

struct SendChallengeTimeStack {
    s32 sp8;
    s32 spC;
    s32 sp10;
    u8 trailing_storage[0x8];
};

struct SendChallengeRetryCmdStack {
    s32 sp8;
    s32 spC;
    s32 sp10;
    u8 trailing_storage[0x8];
};

struct TLobbyStack { s32 sp8; s32 spC; s32 sp10; s32 sp14; };

void build_6x8A_packet(u8 *arg0);
void build_6x95_packet(u8 *arg0);
void build_6x97_packet(u8 *arg0);
void build_6x9D_packet(u8 *arg0);
void send_challenge_dead_flag_packet(TLobby *lobby);
extern "C" {
void TLobby__sub_800727A0(void *player);
}
void handle_6x9D_set_challenge_dead_flag(G_SetChallengeDeadFlag_6x9D *command) {
    s32 idx;
    if (is_challenge_mode() == 0) {
        return;
    }
    ((TLobby *)command)->bswap_challenge_dead_flag();
    idx = command->client_id;
    if (idx < 0 || idx >= 4) {
        return;
    }
    if (get_player_by_client_id(idx) != NULL) {
        challenge_mode_state.client_died[idx] = 1;
    }
}
extern "C" {

void TLobby__sub_800722AC(s32 arg0) {
    TLobbyStack stack;
    if (is_challenge_mode() == 0) {
        return;
    }
    if (arg0 < 0 || arg0 >= 4) {
        return;
    }
    build_6x9D_packet((u8 *)&stack);
    stack.spC = arg0;
    send_challenge_dead_flag_packet((TLobby *)&stack);
}

void TLobby::send_challenge_retry_cmd(s32 choice) {
    LAYOUT_ASSERT(sp8_offset, offsetof(SendChallengeRetryCmdStack, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(SendChallengeRetryCmdStack, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(SendChallengeRetryCmdStack, sp10) == 0x8);
    SendChallengeRetryCmdStack stack;
    if (is_challenge_mode() != 0) {
        build_6x97_packet((u8 *)&stack.sp8);
        stack.sp10 = choice;
        stack.spC = local_client_id;
        ((TLobby *)(&stack.sp8))->send_and_handle_60_wrapper();
    }
}
}

void handle_6x97_select_challenge_mode_failure_option(void *player) {
    s32 var_r0;

    if (is_challenge_mode() != 0) {
        TLobby__sub_800727A0(player);
        var_r0 = *(s32 *)((s8 *)player + 8);
        if ((var_r0 < 0) || (var_r0 > 1)) {
            var_r0 = 0;
        }
        challenge_mode_state.retry_choice = var_r0;
    }
}

void handle_6x95_set_challenge_time(G_SetChallengeTime_6x95 *command) {
    s32 idx;
    s32 t;
    s32 r;
    if (is_challenge_mode() == 0) {
        return;
    }
    ((TLobby *)command)->byteswap_challenge_time_packet();
    t = command->time;
    idx = command->client_id;
    r = decode_challenge_time(t);
    if (idx < 0 || idx >= 4) {
        return;
    }
    if (is_challenge_time_invalid(r) != 0) {
        t = encode_challenge_time(0x8C9F);
    }
    challenge_mode_state.client_time_records[idx] = t;
}

void send_challenge_time(s32 clear_time) {
    LAYOUT_ASSERT(sp8_offset, offsetof(SendChallengeTimeStack, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(SendChallengeTimeStack, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(SendChallengeTimeStack, sp10) == 0x8);
    SendChallengeTimeStack stack;
    build_6x95_packet((u8 *)&stack.sp8);
    stack.sp10 = encode_challenge_time(clear_time);
    stack.spC = local_client_id;
    ((TLobby *)(&stack.sp8))->send_state();
}

void handle_6x8A_show_challenge_time_records_window(G_ShowChallengeTimeRecordsWindow_6x8A *command) {
    if (is_challenge_mode() == 0) {
        return;
    }
    ((TLobby *)command)->byteswap_challenge_packet();
    if (command->which < 0 || command->which >= 0x11) {
        return;
    }
    challenge_task->set_challenge_record_page(command->which);
}

void TLobby::send_challenge_with_value(s32 challenge, s32 window_mode) {
    LAYOUT_ASSERT(sp8_offset, offsetof(SendChallengeWithValueStack, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(SendChallengeWithValueStack, spC) == 0x4);
    SendChallengeWithValueStack stack;
    build_6x8A_packet((u8 *)&stack.sp8);
    stack.spC = window_mode;
    ((TLobby *)(&stack.sp8))->send_challenge_packet();
}

void handle_6x7C_set_challenge_records(G_SetChallengeRecords_V3_6x7C *command) {
    s32 id;
    ChallengeClientRecords *rec;
    if (is_challenge_mode() == 0) {
        return;
    }
    command->bswap();
    id = command->__base_G_SetChallengeRecordsBase_6x7C.client_id;
    if (id == local_client_id) {
        return;
    }
    if (id == 0xFFFF) {
        TLobby::send_challenge_records((uaddr)challenge_task);
        return;
    }
    if (id < 0 || id >= 4) {
        return;
    }
    rec = &challenge_mode_state.client_records[id];
    if (rec->present == 0) {
        TLobby::send_challenge_records((uaddr)challenge_task);
    }
    rec->present = 1;
    rec->records = command->records;
}

void TChallenge::send_6x7c_reset() {
    G_SetChallengeRecords_V3_6x7C packet;
    packet.__base_G_SetChallengeRecordsBase_6x7C.client_id = 0xFFFF;
    packet.send();
}

void send_own_challenge_records(void) {
    ChallengeClientRecords *own;
    if (is_challenge_mode() != 0) {
        own = &challenge_mode_state.client_records[local_client_id];
        if (((u32)get_character_save_record(0xFFFF)) != 0) {
            own->records = *(ChallengeRecord *)(get_character_save_record(0xFFFF) + 0x21C4);
            if (challenge_task != NULL) {
                TLobby::send_challenge_records((uaddr)challenge_task);
            }
        }
    }
}

void TLobby::send_challenge_records(u32 _w0) {
    G_SetChallengeRecords_V3_6x7C packet;
    packet.__base_G_SetChallengeRecordsBase_6x7C.client_id = (s16) local_client_id;
    packet.records = *(ChallengeRecord *)(get_character_save_record(0xFFFF) + 0x21C4);
    packet.send();
}
