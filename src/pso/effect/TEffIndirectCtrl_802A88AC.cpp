#include "types.h"
#include "pso/effect/TEffIndirectCtrl.h"
#include "pso/effect/TEffIndirectCtrl_802A88AC.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/memory.h"

#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_802A9234_TEffIndirectCtrl__data_80540AF0 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_802A925C_TEffIndirectCtrl__data_80540AF0 {
    s32 value;
    u8 remaining[0x1C];
};

struct P2C_802A8B58 { void *a; s32 b; };

struct Ctrl_802A8B58 {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *vt;
    u32 f1c;
    u8 *f20;
    u8 f24;
    u8 f25;
    u8 pad26[2];
    void *f28;
    P2C_802A8B58 *f2c;
    u8 f30[0xC];
    s32 f3c;
    s32 f40;
    s16 f44;
    s16 f46;
    f32 f48;
    f32 f4c;
    f32 f50;
};

struct Cell_802A8FD8
{
  u16 idx;
  u16 val;
};

extern RecoveredGlobal_802A9234_TEffIndirectCtrl__data_80540AF0 TEffIndirectCtrl__source_buffers;
extern "C" {
f32 sin_table_lookup(s32);
void __ct__7TObjectFP7TObject(void *, void *);
u8 *get_indirect_recipe(u8);
void set_texture_name(void *, void *, void *, s32);
void load_texture_list(void *);
extern s32 __vt__16TEffIndirectCtrl[];
extern s32 TEffIndirectCtrl__name;
extern const f32 lbl_805DE024;
Ctrl_802A8B58 *TEffIndirectCtrl__ct(Ctrl_802A8B58 *self, s32 kind, void *parent);
extern const f32 TEffIndirectCtrl__data_805DE02C;
s32 DCFlushRange(s32, s32);
void release_texture_list(void *);
s32 memcpy(s32, s32, s32);

void TEffIndirectCtrl::render() {  }

void TEffIndirectCtrl::copy_and_flush_texture(s32 arg1) {
    memcpy(this->m_1c, arg1, 0x1000);
    DCFlushRange(this->m_1c, 0x1000);
}

}
TEffIndirectCtrl::~TEffIndirectCtrl() {
    if (*(void **)((s8 *)this + 0x2C) != NULL) { release_texture_list(*(void **)((s8 *)this + 0x2C)); ::operator delete(*(void **)((s8 *)this + 0x2C)); }
    if (*(void **)((s8 *)this + 0x28) != NULL) { ::operator delete(*(void **)((s8 *)this + 0x28)); }
}

typedef char RecoveredGlobal_802A9234_TEffIndirectCtrl__data_80540AF0_size[sizeof(RecoveredGlobal_802A9234_TEffIndirectCtrl__data_80540AF0) == 0x20 ? 1 : -1];

Ctrl_802A8B58 *TEffIndirectCtrl__ct(Ctrl_802A8B58 *self, s32 kind, void *parent) {
    u8 *tex;
    u8 k;
    __ct__7TObjectFP7TObject(self, parent);
    self->vt = ((s32 *)&__vt__16TEffIndirectCtrl);
    self->f0 = TEffIndirectCtrl__name;
    self->f28 = ::operator new(0x24);
    self->f2c = (P2C_802A8B58 *)::operator new(8);
    {
    void *obj = self;
    if (self->f2c == NULL || self->f28 == NULL) {
        queue_destruction__7TObjectFv(obj);
        return self;
    }
    }
    self->f46 = 0;
    self->f48 = lbl_805DE024;
    self->f4c = lbl_805DE024;
    self->f3c = 0;
    self->f40 = 0;
    self->f44 = 0;
    self->f50 = lbl_805DE024;
    k = kind;
    self->f25 = kind;
    self->f20 = get_indirect_recipe(k);
    if (self->f20 == NULL) {
        return self;
    }
    self->f24 = self->f20[7];
    tex = (u8 *)get_indirect_source_id(self->f24) + k * 1000;
    self->f2c->a = self->f30;
    self->f2c->b = 1;
    ((TObjPlayer *)(self->f28))->set_render_rect(0, 1, 0x40, 0x40);
    set_texture_name(self->f30, self->f28, tex, 0x8800000);
    load_texture_list(self->f2c);
    self->f1c = *(u32 *)(*(u8 **)(*(u8 **)((u8 *)self->f2c->a + 8) + 0xC) + 0x20);
    ((TEffIndirectCtrl *)self)->copy_and_flush_texture(get_indirect_source_pixels(self->f24));
    return self;
}

#pragma push
#pragma fp_contract on
void deform_indirect_texture_wave(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5) {
    s32 v;
    s32 off;
    s32 y;
    s16 row;
    s32 x;
    for (y = 0; y < 64; y++) {
        row = (s32)((f32)(u8)arg2 * sin_table_lookup((s32)(182.04445f * (f32)(u32)(arg4 + y * arg5))));
        for (x = 0; x < 64; x++) {
            off = (s32)((f32)(u8)arg1 * sin_table_lookup((s32)(182.04445f * (f32)(u32)(arg3 + x * arg5))) + (f32)row);
            v = *(u8 *)arg0;
            if ((s16)v != 0xFF) {
                v = v + off;
                if ((s16)v >= 0xFF) {
                    v = 0xFE;
                }
                if ((s16)v <= 0) {
                    v = 0;
                }
            }
            *(u8 *)arg0 = v;
            arg0++;
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 update_indirect_texture_wave(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5) {
    s32 off;
    s32 x;
    s32 i;
    s32 v;
    s16 row;
    s32 y;
    for (y = 0; y < 64; y++) {
        row = (s32)((f32)(u8)arg2 * sin_table_lookup((s32)(182.04445f * (f32)(u32)(arg4 + y * arg5))));
        for (x = 0; x < 64; x++) {
            off = (s32)((f32)(u8)arg1 * sin_table_lookup((s32)(182.04445f * (f32)(u32)(arg3 + x * arg5))) + (f32)row);
            i = ((s32 (*)(u8, u8, s32))get_indirect_tile_coord)(x, y, 0x40);
            v = ((u8 *)arg0)[i];
            v += off;
            if ((s16)v >= 0xFF) {
                v = 0xFE;
            }
            if ((s16)v <= 0) {
                v = 0;
            }
            ((u8 *)arg0)[i] = v;
        }
    }
}
#pragma pop

typedef struct Cell_802A8FD8 Cell_802A8FD8;

void deform_indirect_texture_scroll(u8 *p, u32 px, u32 py, u8 amp, u32 phase) {
  Cell_802A8FD8 buf[64];
  s32 pxm;
  s32 pym;
  s16 off16;
  u32 first;
  u32 flags;
  s32 count;
  u32 start;
  u32 at;
  s32 axis;
  s32 line;
  s32 k;
  s32 offset;
  s32 i;
  s32 j;
  s32 v;
  u32 idx;
  u32 w;
  flags = 0;
  count = 0;
  offset = (s32) (((f32) amp) * sin_table_lookup((s32) (TEffIndirectCtrl__data_805DE02C * ((f32) phase))));
  if (px != 0)
  {
    flags |= 1;
    count = 1;
  }
  if (py != 0)
  {
    flags |= 2;
    count++;
  }
  if (flags == 0)
  {
    for (i = 0; i < 64; i++)
    {
      for (j = 0; j < 64; j++)
      {
        v = *p;
        if (((s16) v) != 0xFF)
        {
          v += offset;
          if (((s16) v) >= 0xFF)
          {
            v = 0xFE;
          }
          if (((s16) v) <= 0)
          {
            v = 0;
          }
        }
        *(p++) = v;
      }
    }
    return;
  }
  pxm = px & 63;
  pym = py & 63;
  off16 = offset;
  for (axis = 0; axis < count; axis++)
  {
    first = flags & 1;
    start = (u32) ((first) ? (pxm) : (pym));
    for (line = 0; line < 64; line++)
    {
      off16++;
      off16--;
      at = start;
      for (k = 0; k < 64; k++)
      {
        if (first)
        {
          idx = ((u32 (*)(u8, u8, s32)) get_indirect_tile_coord)(at, line, 64);
        }
        else
        {
          idx = ((u32 (*)(u8, u8, s32)) get_indirect_tile_coord)(line, at, 64);
        }
        w = p[idx];
        if (w != 0xFF)
        {
          w += off16;
          if (w >= 0xFF)
          {
            w = 0xFE;
          }
          if (w <= 0)
          {
            w = 0;
          }
        }
        buf[k].val = w;
        buf[at].idx = idx;
        at++;
        if (at >= 64)
        {
          at -= 64;
        }
      }
      for (k = 0; k < 64; k++)
      {
        p[buf[k].idx] = buf[k].val;
      }
    }
    if (first)
    {
      flags &= ~1;
    }
    else
    {
      flags &= ~2;
    }
  }
}

u32 calc_i8_tiled_texel_offset(u32 x, u32 y, u32 w) {
    u32 r = (((x >> 3) & 0x1F) << 5) + (x & 7);
    r += (((y >> 2) & 0x3F) * w) << 2;
    r += (y & 3) << 3;
    return r;
}

s32 get_indirect_source_pixels(u8 arg0) {
    u8 var_r3;
    var_r3 = arg0;
    if (var_r3 >= 8U) {
        var_r3 = 0;
    }
    return *(s32 *)((s8 *)&TEffIndirectCtrl__source_buffers.value + ((var_r3 * 4) & 0x3FC)) + 0x20;
}
typedef char RecoveredGlobal_802A925C_TEffIndirectCtrl__data_80540AF0_size[sizeof(RecoveredGlobal_802A925C_TEffIndirectCtrl__data_80540AF0) == 0x20 ? 1 : -1];
s32 get_indirect_source_id(u8 arg0) {
    u8 var_r3;
    var_r3 = arg0;
    if (var_r3 >= 8U) {
        var_r3 = 0;
    }
    return *(s32 *)((s8 *)(*(s32 *)((s8 *)(&(*(RecoveredGlobal_802A925C_TEffIndirectCtrl__data_80540AF0 *)&TEffIndirectCtrl__source_buffers).value) + ((var_r3 * 4) & 0x3FC))) + 8);
}
