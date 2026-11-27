#include "types.h"
#include "pso/audio/AdxRnaInitBuffer.h"
#include "pso/audio/GcrnaStream.h"
#include "pso/network/TLobby.h"

extern "C" {

void adx_rna_set_buffer_storage(u8 *buffer, u32 size, s32 count) {
    gcrna_set_audio_buffer_storage(buffer, size, count);
}

}
