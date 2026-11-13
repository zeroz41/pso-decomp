#include <stddef.h>

#include "types.h"
#include "pso/network/BufferRef.h"
#include "pso/network/NetStackTypes.h"
#include "pso/network/netcfg.h"
#include "pso/network/TLobby_8041112C.h"

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

s32 reset_net_value(void) {
    TLobby__sub_803F89D8(&network_buffer_pool_state);
    network_buffer_pool_state.count = 0;
    return 0;
}

s32 TLobby__sub_80415690(void) {
    NetBufferPool* p;
    s16* step;
    u8 *cursor;
    s16 i;
    NetBufferPoolEntry* out;
    s32 tmp;

    init_buffer_desc_a(&network_buffer_pool_state);
    p = &network_buffer_pool_state;
    cursor = p->data;
    step = &p->size;
    out = p->ents;
    for (i = 0; i < p->count; i++) {
        out->buf = cursor;
        tmp = *step;
        cursor += (u16)tmp;
        out->free_segs = 8;
        out->free_bytes = *step;
        out->segs[0].owner = -1;
        out->segs[0].offset = 0;
        out->segs[0].len = (u16)*step;
        out->segs[1].owner = 0;
        out->segs[1].offset = (u16)*step;
        out->segs[1].len = 0;
        out->segs[2].owner = 0;
        out->segs[2].offset = (u16)*step;
        out->segs[2].len = 0;
        out->segs[3].owner = 0;
        out->segs[3].offset = (u16)*step;
        out->segs[3].len = 0;
        out->segs[4].owner = 0;
        out->segs[4].offset = (u16)*step;
        out->segs[4].len = 0;
        out->segs[5].owner = 0;
        out->segs[5].offset = (u16)*step;
        out->segs[5].len = 0;
        out->segs[6].owner = 0;
        out->segs[6].offset = (u16)*step;
        out->segs[6].len = 0;
        out->segs[7].owner = 0;
        out->segs[7].offset = (u16)*step;
        out->segs[7].len = 0;
        out++;
    }
    return 0;
}

s16 TLobby__sub_8041579C(NetBufferRef *self)
{
  s32 pos;
  s16 f;
  u8 *a;
  long long new_var;
  s16 id1;
  u8 *b;
  s16 id2;
  u8 *e;
  s16 m;
  u8 *rec;
  int new_var2;
  u32 word;
  if (self->kind == 4)
  {
    TLobby__sub_803F8D84(self->value);
    return 0;
  }
  word = self->value;
  id1 = (s16) (word >> 24);
  id2 = (s16) ((word >> 16) & 0xff);
  if ((id1 < 0) || (id2 < 0))
  {
    return -1;
  }
  if (id1 > network_buffer_pool_state.count)
  {
    return -1;
  }
  if (id2 > 8)
  {
    return -1;
  }
  rec = (u8 *)network_buffer_pool_state.ents;
  rec += id1 * (s32)sizeof(NetBufferPoolEntry);
  new_var = id2 * (s32)sizeof(NetBufferSegment);
  e = rec + new_var;
  if ((*((s16 *) (e += offsetof(NetBufferPoolEntry, segs)))) == (-1))
  {
    return -1;
  }
  *((s16 *) e) = -1;
  *((s32 *) (rec + offsetof(NetBufferPoolEntry, free_segs))) += 1;
  *((s32 *) (rec + offsetof(NetBufferPoolEntry, free_bytes))) += *((u16 *) ((e = rec + (id2 * (s32)sizeof(NetBufferSegment))) + offsetof(NetBufferPoolEntry, segs[0].len)));
  if ((id2 == 7) || ((*((s16 *) (e + offsetof(NetBufferPoolEntry, segs[1].owner)))) != (-1)))
  {
    pos = (u16) id2;
  }
  else
  {
    pos = id2 + 1;
  }
  pos = (s16) pos;
  new_var2 = pos - 1;
  m = new_var2;
  a = rec + (m * (s32)sizeof(NetBufferSegment));
  b = rec + (pos * (s32)sizeof(NetBufferSegment));
  while ((m >= 0) && ((f = *((s16 *) (a + offsetof(NetBufferPoolEntry, segs[0].owner)))) <= 0))
  {
    if (f == 0)
    {
      *((s16 *) (a + offsetof(NetBufferPoolEntry, segs[0].owner))) = -1;
      *((s16 *) (b + offsetof(NetBufferPoolEntry, segs[0].owner))) = 0;
      *((u16 *) (a + offsetof(NetBufferPoolEntry, segs[0].offset))) = *((u16 *) (b + offsetof(NetBufferPoolEntry, segs[0].offset)));
      *((u16 *) (a + offsetof(NetBufferPoolEntry, segs[0].len))) = *((u16 *) (b + offsetof(NetBufferPoolEntry, segs[0].len)));
      *((u16 *) (b + offsetof(NetBufferPoolEntry, segs[0].offset))) = (*((u16 *) (b + offsetof(NetBufferPoolEntry, segs[0].offset)))) + (*((u16 *) (a + offsetof(NetBufferPoolEntry, segs[0].len))));
      *((u16 *) (b + offsetof(NetBufferPoolEntry, segs[0].len))) = 0;
    }
    else
      if (f == (-1))
    {
      *((s16 *) (b + offsetof(NetBufferPoolEntry, segs[0].owner))) = 0;
      *((u16 *) (a + offsetof(NetBufferPoolEntry, segs[0].len))) = (*((u16 *) (a + offsetof(NetBufferPoolEntry, segs[0].len)))) + (*((u16 *) (b + offsetof(NetBufferPoolEntry, segs[0].len))));
      *((u16 *) (b + offsetof(NetBufferPoolEntry, segs[0].len))) = 0;
      *((u16 *) (b + offsetof(NetBufferPoolEntry, segs[0].offset))) = (*((u16 *) (a + offsetof(NetBufferPoolEntry, segs[0].offset)))) + (*((u16 *) (a + offsetof(NetBufferPoolEntry, segs[0].len))));
    }
    else
    {
      break;
    }
    b = b - (s32)sizeof(NetBufferSegment);
    a = a - (s32)sizeof(NetBufferSegment);
    m--;
  }

  return 0;
}

#pragma push
#pragma opt_common_subs on
s16 TLobby__sub_80415954(void *out_, int size, s16 owner) {
    NetBufferRef *ref = (NetBufferRef *)out_;
    NetBufferPool *pool;
    NetBufferPoolEntry *e;
    u32 p;
    s16 i;
    s16 j;

    if (owner == 1) {
        p = alloc_buffer_slot(size);
        if (p == 0) {
            return -1;
        }
        ref->kind = 4;
        ref->value = p;
        return 0;
    }
    if (size < 0x400) {
        size = 0x400;
    }
    pool = &network_buffer_pool_state;
    e = pool->ents;
    for (i = 0; i < pool->count; i++, e++) {
        if (e->free_segs == 0 || size > e->free_bytes) {
            continue;
        }
        for (j = 0; j < 8; j++) {
            if (e->segs[j].owner != 0 && e->segs[j].owner == -1 && e->segs[j].len >= (u16)size) {
                ref->value = (i << 24) + (j << 16);
                ref->kind = 2;
                e->segs[j].owner = owner;
                if (j + 1 < 8 && e->segs[j].len - (u16)size != 0 && e->segs[j + 1].owner == 0) {
                    e->segs[j + 1].offset = e->segs[j].offset + size;
                    e->segs[j + 1].len = e->segs[j].len - size;
                    e->segs[j + 1].owner = -1;
                    e->segs[j].len = size;
                }
                e->free_segs--;
                e->free_bytes -= e->segs[j].len;
                return 0;
            }
        }
    }
    return -1;
}
#pragma pop

NetBufferPool network_buffer_pool_state;
