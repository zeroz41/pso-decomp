#ifndef PSO_UI_WINDOW_DEFERREDPACKETS_H
#define PSO_UI_WINDOW_DEFERREDPACKETS_H

#include "types.h"

class TPacket;
struct CharacterSaveRecord;
union packet;

// Test or rewrite a client's card window flags in its character save record.
s32 test_card_flag(s32 client, s32 mask);
void set_card_window_flags(s32 client_id, s32 bits, s32 keep_mask);
void flush_packet_send_buffer(TPacket *packet);
void append_command_to_batch_buffer(TPacket *batch, u8 *cmd);
void alloc_work_buffer(void);
// The card window flags a new character starts with.
void set_default_card_window_flags(CharacterSaveRecord *record);

void free_deferred_packet_buffer();

void buffer_reset(void);

void copy_packet(packet *pkt);

#endif
