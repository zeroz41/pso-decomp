#ifndef PSO_UI_WINDOW_TWINDOWKEYBOARDHARD_801A529C_H
#define PSO_UI_WINDOW_TWINDOWKEYBOARDHARD_801A529C_H

#include "types.h"

class TPacket;
struct CharacterSaveRecord;

void flush_packet_send_buffer(TPacket *packet);
void append_command_to_batch_buffer(TPacket *batch, u8 *cmd);
void alloc_work_buffer(void);
// The card window flags a new character starts with.
void set_default_card_window_flags(CharacterSaveRecord *record);

void free_deferred_packet_buffer();

void buffer_reset(void);

#endif
