#ifndef PSO_SYSTEM_REFCOUNTEDWORKBUFFER_H
#define PSO_SYSTEM_REFCOUNTEDWORKBUFFER_H

#include "types.h"
#include "pso/audio/SjRingBuffer.h"

void ref_counted_work_buffer_init(void);
void ref_counted_work_buffer_finish(void);
extern "C" {
void sj_split_chunk(const SjChunk *chunk, s32 size, SjChunk *prefix, SjChunk *remainder);
s32 parse_hex_size(u8 *p);
}
u8 *find_archive_entry(SjChunk *arc, const char *name, const char *stop, SjChunk *out);

#endif
