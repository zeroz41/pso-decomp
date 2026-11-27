#ifndef PSO_UNK_CONNECTIONINPUTBUFFERS_H
#define PSO_UNK_CONNECTIONINPUTBUFFERS_H

#include "types.h"

saddr get_connection_message_text(s32 id);
u8 *get_access_key_input_buffer(void);
u8 *get_raw_serial_input_buffer(void);


#endif
