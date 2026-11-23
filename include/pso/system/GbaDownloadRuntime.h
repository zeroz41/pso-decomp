#ifndef PSO_SYSTEM_GBADOWNLOADRUNTIME_H
#define PSO_SYSTEM_GBADOWNLOADRUNTIME_H

#include "types.h"

extern "C" {
extern u8 *gba_download_data_buffer;
extern u32 gba_download_data_size;

void gba_init(void);
void stamp_joyboot_image(s32 arg0, s32 arg1);
void probe_gba_device(void);
void TLobby__sub_8032CDC0(void);
void reset_joyboot_state(void *p);
}

#endif
