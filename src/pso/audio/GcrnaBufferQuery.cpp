#include "types.h"
#include "pso/audio/GcrnaBufferQuery.h"
#include "pso/unk/TLobby.h"

static inline s32 gcrna_query_stream_bytes(void *self_ptr, s32 mode) {
    GcrnaBufferQueryState *state = static_cast<GcrnaBufferQueryState *>(self_ptr);
    GcrnaBufferVtable **stream = state->stream;
    GcrnaBufferVtable *vt = *stream;
    return vt->query_bytes(stream, mode, vt);
}

static inline s32 gcrna_query_is_active(TLobby *self) {
    if (self == NULL) {
        return -1;
    }
    return *(u32 *)&self->m_prev & 1;
}

static inline s32 gcrna_query_is_looping(TLobby *self) {
    if (self == NULL) {
        return -1;
    }
    return ((uaddr)self->m_prev >> 1U) & 1;
}

u32 TLobby::get_packet_size() {
    s32 bytes;

    if (this == NULL) {
        return -1U;
    }
    bytes = gcrna_query_stream_bytes(this, 0);
    if (gcrna_query_is_active(this) == 1) {
        if ((gcrna_query_is_looping(this) == 0) && (bytes > 0)) {
            bytes = 0x2000;
        }
    }
    return (u32)bytes >> 1U;
}

u32 TLobby::get_available_size() {
    s32 bytes;

    if (this == NULL) {
        return -1U;
    }
    bytes = gcrna_query_stream_bytes(this, 1);
    if (gcrna_query_is_active(this) == 1) {
        if ((gcrna_query_is_looping(this) == 0) && (bytes < 0x2000)) {
            bytes = 0;
        }
    }
    return (u32)bytes >> 1U;
}
