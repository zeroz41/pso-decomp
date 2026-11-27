#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/network/TSocket.h"
#include "types.h"
#include "pso/network/TPacket.h"
#include "pso/network/TProtocol.h"
#include "pso/ui/window/TWindowKeyBoardHard_801A529C.h"
#include "pso/network/packet_copy.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include <string.h>
#include "pso/network/TProtocol.h"

extern "C" {
saddr deferred_packet_buffer;
s32 deferred_packet_buffer_used;
s32 lbl_805D5D00;
s32 deferred_packet_buffer_state;
}

s32 TWindowKeyBoardHard::test_card_flag(s32 client, s32 mask) {
    CharacterSaveRecord *character_save_record;

    character_save_record = (CharacterSaveRecord *)get_character_save_record((u32)client);
    if (character_save_record == NULL) {
        return 0;
    }
    return (character_save_record->card_window_flags & mask) ? 1 : 0;
}

void TWindowKeyBoardHard::set_card_window_flags(s32 client_id, s32 bits, s32 keep_mask) {
    CharacterSaveRecord *character_save_record;

    character_save_record = (CharacterSaveRecord *)get_character_save_record((u32)client_id);
    if (character_save_record != NULL) {
        character_save_record->card_window_flags = (s32) (character_save_record->card_window_flags & keep_mask);
        character_save_record->card_window_flags = (s32) (character_save_record->card_window_flags | bits);
    }
}

void set_default_card_window_flags(CharacterSaveRecord *record) {
    if (record != NULL) {
        record->card_window_flags = 0x40058;
    }
}

void TLobby::drain_deferred_packets() {
    deferred_packet_buffer_used = 0;
    deferred_packet_buffer_state = 2;
    s32 i;
    while ((i = deferred_packet_buffer_used) < 0x10000) {
        packet *p;
        u16 n;
        p = (packet *)(deferred_packet_buffer + i);
        n = (u16)to_be_uint16_t(p->pkt.header.size);
        if (p->pkt.header.command == 0) {
            break;
        }
        protocol_instance->handle_command(p);
        deferred_packet_buffer_used += n;
    }
}
void copy_packet(packet *pkt) {
    s32 len;

    len = (u16) to_be_uint16_t(pkt->pkt.header.size);
    if (deferred_packet_buffer_used + len <= 0x10000) {
        memcpy((void *)(deferred_packet_buffer + deferred_packet_buffer_used), pkt, len);
        deferred_packet_buffer_used += len;
    }
}

void buffer_reset(void) {
    deferred_packet_buffer_used = 0;
    lbl_805D5D00 = 0;
    memset((void *)deferred_packet_buffer, 0, 0x10000);
    deferred_packet_buffer_state = 1;
}


void free_deferred_packet_buffer(void) { mem_free((void *)deferred_packet_buffer); deferred_packet_buffer = 0; }


void alloc_work_buffer(void) {
    deferred_packet_buffer_used = 0;
    lbl_805D5D00 = 0;
    deferred_packet_buffer_state = 0;
    deferred_packet_buffer = (saddr)mem_alloc(0x10000);
    memset((void *)deferred_packet_buffer, 0, 0x10000);
}

// Sends what the packet's send buffer holds, padded to a multiple of 4 bytes
// (TGameProtocol::run_task clears the buffer afterwards).
void flush_packet_send_buffer(TPacket *packet) {
    s32 length;

    length = packet->m_send_size;
    if (length > 0) {
        if (length & 3) {
            packet->m_send_size = (length + 3);
            packet->m_send_size = (s32) (packet->m_send_size & 0xFFFFFFFC);
        }
        packet->send(packet->m_send_buffer, packet->m_send_size);
    }
}
void append_command_to_batch_buffer(TPacket *batch, u8 *cmd) {
    s32 n;
    s32 i;
    if (batch->m_send_size + cmd[1] * 4 > 0x5B4) {
        return;
    }
    n = cmd[1] * 4;
    for (i = 0; i < n; i++) {
        batch->m_send_buffer[batch->m_send_size++] = *cmd++;
    }
}
