#ifndef PSO_AUDIO_ADX_RNA_INIT_BUFFER_H
#define PSO_AUDIO_ADX_RNA_INIT_BUFFER_H

#include "types.h"

extern "C" {
void adx_rna_set_buffer_storage(u8 *buffer, u32 size, s32 count);
}

#endif
