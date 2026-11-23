#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/challenge/TChallenge.h"
#include "pso/quest/challenge/ChallengeModeState.h"
#include "pso/player/PlayerSlots.h"

#include <stddef.h>

struct Stack_800724F0 {
    s32 sp8;
    s32 spC;
};

#include "pso/network/protocol/subcmd_6x.h"

struct Stack_80072448 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    u8 trailing_storage[0x8];
};

struct Stack_80072308 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    u8 trailing_storage[0x8];
};

struct Pkt_800725E0 { u8 pad[4]; u16 f4; u8 pad2[0x102]; };

struct Pkt_80072494 { u32 hdr; s32 idx; };

struct Stack_800722AC { s32 sp8; s32 spC; s32 sp10; s32 sp14; };

struct Pkt_80072230 { u32 hdr; s32 idx; s32 val; };

struct Pkt7C_80072230 { u32 hdr; u16 id; u8 pad6[2]; ChallengeRecord recs; };

extern "C" {
void TLobby__sub_800728FC(u8 *arg0);
extern s32 local_client_id;
void TLobby__sub_80072880(u8 *arg0);
void TLobby__sub_800727EC(u8 *arg0);
void handle_6x8A_show_challenge_time_records_window(Pkt_80072494 *pkt);
void TLobby__sub_80072758(u8 *arg0);
void TLobby__sub_80072724(TLobby *lobby);
void TLobby__sub_800722AC(s32 arg0);
void TLobby__sub_80072618(void);
void handle_6x7C_set_challenge_records(Pkt7C_80072230 *pkt);
void handle_6x9D_set_challenge_dead_flag(Pkt_80072230 *pkt);
void handle_6x95_set_challenge_time(Pkt_80072230 *pkt);
void TLobby__sub_800727A0(void *player);

void handle_6x9D_set_challenge_dead_flag(Pkt_80072230 *pkt) {
    s32 idx;
    if (TLobby::is_flag_set() == 0) {
        return;
    }
    ((TLobby *)pkt)->bswap_challenge_dead_flag();
    idx = pkt->idx;
    if (idx < 0 || idx >= 4) {
        return;
    }
    if (get_player_by_client_id(idx) != NULL) {
        challenge_mode_state.client_died[idx] = 1;
    }
}

void TLobby__sub_800722AC(s32 arg0) {
    Stack_800722AC stack;
    if (TLobby::is_flag_set() == 0) {
        return;
    }
    if (arg0 < 0 || arg0 >= 4) {
        return;
    }
    TLobby__sub_80072758((u8 *)&stack);
    stack.spC = arg0;
    TLobby__sub_80072724((TLobby *)&stack);
}

void TLobby::send_challenge_retry_cmd(s32 arg0) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_80072308, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_80072308, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_80072308, sp10) == 0x8);
    Stack_80072308 stack;
    if (TLobby::is_flag_set() != 0) {
        TLobby__sub_800727EC((u8 *)&stack.sp8);
        stack.sp10 = arg0;
        stack.spC = local_client_id;
        ((TLobby *)(&stack.sp8))->send_and_handle_60_wrapper();
    }
}
}

void handle_6x97_select_challenge_mode_failure_option(void *player) {
    s32 var_r0;

    if (TLobby::is_flag_set() != 0) {
        TLobby__sub_800727A0(player);
        var_r0 = *(s32 *)((s8 *)player + 8);
        if ((var_r0 < 0) || (var_r0 > 1)) {
            var_r0 = 0;
        }
        challenge_mode_state.pad_24 = var_r0;
    }
}

void handle_6x95_set_challenge_time(Pkt_80072230 *pkt) {
    s32 idx;
    s32 t;
    s32 r;
    if (TLobby::is_flag_set() == 0) {
        return;
    }
    ((TLobby *)pkt)->byteswap_challenge_time_packet();
    t = pkt->val;
    idx = pkt->idx;
    r = TLobby::get_valid_slot(t);
    if (idx < 0 || idx >= 4) {
        return;
    }
    if (TLobby::check_challenge_time_range(r) != 0) {
        t = TLobby::mix_seed_checked((saddr)((void *)0x8C9F));
    }
    challenge_mode_state.pad_680[idx] = t;
}

void TLobby::send_seed_state() {
    s32 arg0 = (saddr)this;
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_80072448, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_80072448, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_80072448, sp10) == 0x8);
    Stack_80072448 stack;
    TLobby__sub_80072880((u8 *)&stack.sp8);
    stack.sp10 = TLobby::mix_seed_checked(arg0);
    stack.spC = local_client_id;
    ((TLobby *)(&stack.sp8))->send_state();
}

void handle_6x8A_show_challenge_time_records_window(Pkt_80072494 *pkt) {
    if (TLobby::is_flag_set() == 0) {
        return;
    }
    ((TLobby *)pkt)->byteswap_challenge_packet();
    if (pkt->idx < 0 || pkt->idx >= 0x11) {
        return;
    }
    challenge_task->set_challenge_record_page(pkt->idx);
}

void TLobby::send_challenge_with_value(s32 arg0, s32 arg1) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_800724F0, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_800724F0, spC) == 0x4);
    Stack_800724F0 stack;
    TLobby__sub_800728FC((u8 *)&stack.sp8);
    stack.spC = arg1;
    ((TLobby *)(&stack.sp8))->send_challenge_packet();
}

void handle_6x7C_set_challenge_records(Pkt7C_80072230 *pkt) {
    s32 id;
    ChallengeClientRecords *rec;
    if (TLobby::is_flag_set() == 0) {
        return;
    }
    ((TLobby *)pkt)->bswap_6x7C_packet();
    id = pkt->id;
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
    rec->records = pkt->recs;
}

void TChallenge::send_6x7c_reset() {
    Pkt_800725E0 pkt;
    ((TLobby *)(&pkt))->init_pkt_cmd_7C();
    pkt.f4 = 0xFFFF;
    ((TLobby *)(&pkt))->send_6x7C_packet();
}

void TLobby__sub_80072618(void) {
    ChallengeClientRecords *own;
    if (TLobby::is_flag_set() != 0) {
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
    ((TLobby *)(&packet.__base_G_SetChallengeRecordsBase_6x7C.header))->init_pkt_cmd_7C();
    packet.__base_G_SetChallengeRecordsBase_6x7C.client_id = (s16) local_client_id;
    *(ChallengeRecord *)packet.records = *(ChallengeRecord *)(get_character_save_record(0xFFFF) + 0x21C4);
    ((TLobby *)(&packet.__base_G_SetChallengeRecordsBase_6x7C.header))->send_6x7C_packet();
}
