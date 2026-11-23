#ifndef PSO_UNK_TEXT_8022350C_H
#define PSO_UNK_TEXT_8022350C_H

#include "types.h"
#include "pso/camera/TCameraConversation.h"

extern "C" {
// Opens the conversation camera of a service counter (an index into
// service_counter_camera_table); sequence, the counter's sequence, is unused.
TCameraConversation *set_service_counter_camera(void *sequence, s32 counter);
}

#endif
