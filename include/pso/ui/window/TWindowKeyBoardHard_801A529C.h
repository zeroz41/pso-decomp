#ifndef PSO_UI_WINDOW_TWINDOWKEYBOARDHARD_801A529C_H
#define PSO_UI_WINDOW_TWINDOWKEYBOARDHARD_801A529C_H

#include "types.h"

class TPacket;

extern "C" {
void flush_packet_send_buffer(TPacket *packet);
void append_command_to_batch_buffer(TPacket *batch, u8 *cmd);
void alloc_work_buffer(void);
}
void set_fresh_card_flag(void *card);

void free_deferred_packet_buffer();

#endif
