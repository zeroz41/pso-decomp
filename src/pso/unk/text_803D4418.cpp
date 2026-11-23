#include "types.h"
// gcrna audio stream ID table; IDs live after a 0x40-byte control prefix.
struct GcrnaStreamIdTable { u8 pad[0x40]; s32 streamIds[1]; };

extern "C" {
s32 gcrna_get_stream_id(GcrnaStreamIdTable *self, s32 i);
s32 gcrna_get_stream_id(GcrnaStreamIdTable *self, s32 i) {
    return self->streamIds[i];
}

}
