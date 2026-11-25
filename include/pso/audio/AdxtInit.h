#ifndef PSO_AUDIO_ADXT_INIT_H
#define PSO_AUDIO_ADXT_INIT_H

#include "types.h"

extern "C" {
void adxt_finish();
void adxt_init();
s32 adxt_exec_fs_server_cb(s32 context);
s32 adxt_exec_main_server_cb(s32 context);
s32 adxt_exec_vsync_server_cb(s32 context);
void adxt_error_callback(void *context, const char *message);
}

#endif
