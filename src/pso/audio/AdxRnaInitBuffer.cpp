#include "types.h"
#include "pso/audio/AdxRnaInitBuffer.h"
#include "pso/network/TLobby.h"

extern "C" {

s32 gcrna_set_audio_buffer_storage();

void adx_rna_set_buffer_storage() {
    gcrna_set_audio_buffer_storage();
}

}
