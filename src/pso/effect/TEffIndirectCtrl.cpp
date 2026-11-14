#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma readonly_strings on

#include "types.h"
#include <string.h>
#include <stdlib.h>
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/TEffIndirectCtrl.h"
#include "pso/effect/TEffIndirectCtrl_802A88AC.h"
#include "pso/effect/TEffIndirectCtrl_802A9284.h"
#include "pso/unk/text_802A8210.h"
#include "pso/system/scene/TScene.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_802A8368.h"
#include "pso/player/TObjPlayer_803DC834.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/memory.h"
#include "pso/system/task/TObject.h"

struct E_802A9568 { s32 a; s32 b; };

struct Ctrl_802A8728 {
    u8 pad0[0x1C];
    s32 buf;
    u8 *recipe;
    u8 index;
    u8 pad25[0x3C - 0x25];
    s32 amp;
    s32 period;
    u16 phase;
    u8 pad46[2];
    f32 rate;
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

extern "C" {
s32 GXSetNumIndStages(s32);
s32 GXSetTevDirect(s32);
void GXSetIndTexMtx(s32, f32 (*)[3], s32);
void Dolphin_GXSetIndTexCoordScale(s32, s32, s32);
void Dolphin_GXSetIndTexOrder(s32, s32, s32);
void GXSetTevIndWarp(s32, s32, s32, s32, s32);
s32 DCFlushRange(s32, s32);
s32 read_disc_file(const char *, void *);
void set_texture_name(void *, void *, void *, s32);
void load_texture_list(void *);
void release_texture_list(void *);
Ctrl_802A8B58 *TEffIndirectCtrl__ct(Ctrl_802A8B58 *self, s32 kind, void *parent);
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__16TEffIndirectCtrl[];
E_802A9568 *get_indirect_recipe(s32 i);
}
void load_list_texture(s32, s32, s32, s32);

const char *indirect_dat_filename = "indirect.dat";
const char *indinfo_dat_filename = "indinfo.dat";
const char *TEffIndirectCtrl__name = "TEffIndirectCtrl";

s32 TEffIndirectCtrl__source_buffers[8];
TEffIndirectCtrl *indirect_effect_ctrl_table[6];
E_802A9568 *indirect_recipe_buffer;
u8 indirect_effect_ctrl_count;
u16 *indirect_effect_tile_buffer;

// Built -inline off,deferred: functions come out in reverse source order.

E_802A9568 *get_indirect_recipe(s32 i) {
    if (i >= 0x40) return 0;
    return &indirect_recipe_buffer[i];
}

void TEffIndirectCtrl::sub_802A955C() { this->m_46 = 1; }

u8 TEffIndirectCtrl__sub_802A9554(void* p) { return *(u8*)((char*)p + 0x25); }

void TEffIndirectCtrl__sub_802A9548(void* p) { *(s16*)((char*)p + 0x46) = 0; }

void load_indirect_info(void) {
    s32 i;
    s32 j;
    indirect_recipe_buffer = (E_802A9568 *)xmalloc(0x200);
    memset((void *)indirect_recipe_buffer, 0, 0x200);
    indirect_effect_tile_buffer = (u16 *)xmalloc(0x2000);
    if (indirect_effect_tile_buffer != NULL) {
        i = 0;
        do {
            j = 0;
            do {
                indirect_effect_tile_buffer[i * 0x40 + j] = calc_i8_tiled_texel_offset(j, i, 0x40);
                j++;
            } while (j < 0x40);
            i++;
        } while (i < 0x40);
    }
    read_disc_file(indinfo_dat_filename, (void *)indirect_recipe_buffer);
}

u16 get_indirect_tile_coord(u8 arg0, s32 arg1) {
    if (indirect_effect_tile_buffer != NULL) {
        return indirect_effect_tile_buffer[arg0 + ((arg1 << 6) & 0x3FC0)];
    }
    return 0U;
}

void TEffIndirectCtrl::free_buffers() {
    if (indirect_recipe_buffer != NULL) {
        xfree(indirect_recipe_buffer);
        indirect_recipe_buffer = NULL;
    }
    if (indirect_effect_tile_buffer != NULL) {
        xfree(indirect_effect_tile_buffer);
        indirect_effect_tile_buffer = NULL;
    }
}

void load_indirect_dat(void) {
    s32 i;
    s32 fail;
    s32 j;
    u8 *buf;
    u8 *p;
    s32 k;
    fail = 0;
    for (i = 0; i < 8; i++) {
        TEffIndirectCtrl__source_buffers[i] = 0;
    }
    for (i = 0; i < 8; i++) {
        TEffIndirectCtrl__source_buffers[i] = (s32)xmalloc(0x1020);
        if ((u32)TEffIndirectCtrl__source_buffers[i] == 0) {
            fail = 1;
        }
    }
    if (fail != 0) {
        for (j = 0; j < 8; j++) {
            if ((u32)TEffIndirectCtrl__source_buffers[j] != 0) {
                xfree((void *)TEffIndirectCtrl__source_buffers[j]);
                TEffIndirectCtrl__source_buffers[j] = 0;
            }
        }
    }
    p = (u8 *)xmalloc(0x8100);
    if (p != NULL) {
        buf = p;
        if (read_disc_file(indirect_dat_filename, p) == 0x8100) {
            for (k = 0; k < 8; k++) {
                memcpy((void *)TEffIndirectCtrl__source_buffers[k], p, 0x1020);
                p += 0x1020;
            }
            if (buf != NULL) {
                xfree(buf);
            }
            load_indirect_info();
            TObjPlayer__sub_802A841C();
        }
    }
}

void TEffIndirectCtrl::free_all() {
    s32 var_r28;
    s32 var_r30;
    s32 var_r31;
    s32 allocation;

    TObjPlayer__sub_802A83F4();
    TEffIndirectCtrl::free_buffers();
    var_r31 = 0;
    var_r30 = var_r31;
    var_r28 = 0;
    do {
        allocation = *(TEffIndirectCtrl__source_buffers + var_r31);
        if ((u32)allocation != 0U) {
            xfree((void *)allocation);
            *(TEffIndirectCtrl__source_buffers + var_r31) = var_r30;
        }
        var_r28 += 1;
        var_r31 += 1;
    } while (var_r28 < 8);
}

s32 get_indirect_source_id(u8 arg0) {
    u8 var_r3;
    var_r3 = arg0;
    if (var_r3 >= 8U) {
        var_r3 = 0;
    }
    return *(s32 *)(TEffIndirectCtrl__source_buffers[var_r3] + 8);
}

s32 get_indirect_source_pixels(u8 arg0) {
    u8 var_r3;
    var_r3 = arg0;
    if (var_r3 >= 8U) {
        var_r3 = 0;
    }
    return TEffIndirectCtrl__source_buffers[var_r3] + 0x20;
}

u32 calc_i8_tiled_texel_offset(u8 x, u8 y, u32 w) {
    u32 r = (((x >> 3) & 0x1F) << 5) + (x & 7);
    r += (((y >> 2) & 0x3F) * w) << 2;
    r += (y & 3) << 3;
    return r;
}

void deform_indirect_texture_scroll(u8 *p, u32 px, u32 py, s32 amp, u32 phase) {
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
  offset = (s32) (((f32) (u8) amp) * sin_table_lookup((s32) (182.04445f * ((f32) phase))));
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

Ctrl_802A8B58 *TEffIndirectCtrl__ct(Ctrl_802A8B58 *self, s32 kind, void *parent) {
    u8 *tex;
    u8 k;
    __ct__7TObjectFP7TObject(self, parent);
    self->vt = ((s32 *)&__vt__16TEffIndirectCtrl);
    self->f0 = (s32)TEffIndirectCtrl__name;
    self->f28 = ::operator new(0x24);
    self->f2c = (P2C_802A8B58 *)::operator new(8);
    {
    void *obj = self;
    if (self->f2c == NULL || self->f28 == NULL) {
        ((TObject *)obj)->queue_destruction();
        return self;
    }
    }
    self->f46 = 0;
    self->f48 = 0.0f;
    self->f4c = 0.0f;
    self->f3c = 0;
    self->f40 = 0;
    self->f44 = 0;
    self->f50 = 0.0f;
    k = kind;
    self->f25 = kind;
    self->f20 = (u8 *)get_indirect_recipe(k);
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

TEffIndirectCtrl::~TEffIndirectCtrl() {
    if (*(void **)((s8 *)this + 0x2C) != NULL) { release_texture_list(*(void **)((s8 *)this + 0x2C)); ::operator delete(*(void **)((s8 *)this + 0x2C)); }
    if (*(void **)((s8 *)this + 0x28) != NULL) { ::operator delete(*(void **)((s8 *)this + 0x28)); }
}

void TEffIndirectCtrl::copy_and_flush_texture(s32 arg1) {
    memcpy((void *)this->m_1c, (void *)arg1, 0x1000);
    DCFlushRange(this->m_1c, 0x1000);
}

void TEffIndirectCtrl::run_task() {
    if (TObjPlayer::check_demo_mode() != 0 || m_46 == 0) {
        m_3c += (s8)((u8 *)m_20)[4];
        m_40 += (s8)((u8 *)m_20)[5];
        *(f32 *)unk_48 = (s8)((u8 *)m_20)[1];
        m_4c = (s8)((u8 *)m_20)[2];
        void (TEffIndirectCtrl::*modes[3])() = {
            &TEffIndirectCtrl::update_scroll_mode,
            &TEffIndirectCtrl::eff_indirect_update_and_flush,
            &TEffIndirectCtrl::update_eff_indirect,
        };
        if ((actor_frame_tick & 0x1F) == 0) {
            *(f32 *)unk_50 = (s8)((u8 *)m_20)[3] * (3.0517578e-05f * rand());
        }
        if (((u8 *)m_20)[0] < 3) {
            (this->*modes[((u8 *)m_20)[0]])();
        }
        m_24 = ((u8 *)m_20)[7];
        sub_802A955C();
    }
}

void TEffIndirectCtrl::render() {  }

void TEffIndirectCtrl::eff_indirect_update_and_flush() {
    copy_and_flush_texture(get_indirect_source_pixels(m_24));
    update_indirect_texture_wave(m_1c, (s32) *(f32 *)unk_48, m_4c, m_3c, m_40, ((u8 *)m_20)[6]);
    DCFlushRange(m_1c, 0x1000);
}

void TEffIndirectCtrl::update_eff_indirect() {
    copy_and_flush_texture(get_indirect_source_pixels(m_24));
    deform_indirect_texture_wave(m_1c, (s32) *(f32 *)unk_48, m_4c, m_3c, m_40, ((u8 *)m_20)[6]);
    DCFlushRange(m_1c, 0x1000);
}

void TEffIndirectCtrl::update_scroll_mode() {
    Ctrl_802A8728 *self = (Ctrl_802A8728 *)this;
    s32 rate;
    ((TEffIndirectCtrl *)self)->copy_and_flush_texture(get_indirect_source_pixels(self->index));
    rate = (s32) self->rate;
    self->phase = self->phase + (s8) self->recipe[3];
    deform_indirect_texture_scroll((u8 *)self->buf, self->amp, self->period, rate, self->phase);
    DCFlushRange(self->buf, 0x1000);
}

s32 setup_indirect_tev_alternate(s32 arg0, s32 unused, s32 sampler, s32 arg3) {
    if ((u8)arg3 < 5) {
        u8 scale = arg3;
        s32 coords[5] = {0, 1, 2, 3, 4};
        s32 scales[5] = {0, 1, 2, 3, 4};
        f32 mtx[2][3];
        GXSetNumIndStages(1);
        Dolphin_GXSetIndTexOrder(0, coords[2], 5);
        Dolphin_GXSetIndTexCoordScale(0, scales[scale], scales[scale]);
        GXSetTevIndWarp(1, 0, 0, 0, 1);
        mtx[0][0] = 0.5f;
        mtx[0][1] = 0.0f;
        mtx[0][2] = 0.0f;
        mtx[1][0] = 0.0f;
        mtx[1][1] = 0.5f;
        mtx[1][2] = 0.0f;
        GXSetIndTexMtx(1, mtx, 1);
        TObjFish::set_global_param(((TEffIndirectCtrl *)arg0)->m_2c);
        load_list_texture(0, sampler, sampler, 5);
    }
}


s32 setup_indirect_tev_ordinary(s32 arg0, s32 sampler, s32 scale, s32 second) {
    s32 scales[5] = {0, 1, 2, 3, 4};
    f32 m0[2][3];
    f32 m1[2][3];
    GXSetNumIndStages(1);
    Dolphin_GXSetIndTexOrder(0, 0, 5);
    Dolphin_GXSetIndTexCoordScale(0, scales[(u8)scale], scales[(u8)scale]);
    if (second != 0) {
        static s32 shift = -2;
        static s32 unused = 0;
        static f32 k = 0.5f;
        GXSetTevIndWarp(1, 0, 0, 0, 1);
        m0[0][0] = k;
        m0[0][1] = 0.0f;
        m0[0][2] = 0.0f;
        m0[1][0] = 0.0f;
        m0[1][1] = k;
        m0[1][2] = 0.0f;
        GXSetIndTexMtx(1, m0, (s8)shift);
    } else {
        GXSetTevIndWarp(0, 0, 0, 0, 1);
        m1[0][0] = 0.5f;
        m1[0][1] = 0.0f;
        m1[0][2] = 0.0f;
        m1[1][0] = 0.0f;
        m1[1][1] = 0.5f;
        m1[1][2] = 0.0f;
        GXSetIndTexMtx(1, m1, 1);
    }
    TObjFish::set_global_param(((TEffIndirectCtrl *)arg0)->m_2c);
    load_list_texture(0, sampler, sampler, 5);
}

void TObjPlayer__sub_802A841C(void) {
    s32 i;
    indirect_effect_ctrl_count = 0;
    for (i = 0; i < 6; i++) indirect_effect_ctrl_table[i] = 0;
}

void TObjPlayer__sub_802A83F4(void) {
    s32 i;
    for (i = 0; i < 6; i++) indirect_effect_ctrl_table[i] = 0;
}

void TObjPlayer::play_particle_at_active_slot(s32 arg0, s32 sampler, s32 arg2, s32 arg3, s32 unused, s32 second) {
    s32 indirect_effect_ctrl;

    indirect_effect_ctrl = (s32)(s8) find_indirect_effect_ctrl(arg0);
    if ((indirect_effect_ctrl != -1) && (indirect_effect_ctrl_table[indirect_effect_ctrl] != NULL)) {
        if (arg3 != 0) {
            setup_indirect_tev_alternate((s32)indirect_effect_ctrl_table[indirect_effect_ctrl], unused, sampler, arg2);
            return;
        }
        setup_indirect_tev_ordinary((s32)indirect_effect_ctrl_table[indirect_effect_ctrl], sampler, arg2, second);
    }
}

s8 find_indirect_effect_ctrl(s32 kind) {
    s32 i;
    for (i = 0; i < indirect_effect_ctrl_count; i++) {
        if (indirect_effect_ctrl_table[i] != 0) {
            u8 id = TEffIndirectCtrl__sub_802A9554(indirect_effect_ctrl_table[i]);
            if (id == (u8)kind) {
                if (TObjPlayer::check_demo_mode() == 0) {
                    TEffIndirectCtrl__sub_802A9548(indirect_effect_ctrl_table[i]);
                }
                return i;
            }
        }
    }
    return -1;
}

void register_indirect_effect_ctrl(s32 kind) {
    Ctrl_802A8B58 *p;
    if (find_indirect_effect_ctrl(kind) < 0 && indirect_effect_ctrl_count < 6) {
        p = (Ctrl_802A8B58 *)TObject::operator new(0x54);
        if (p != NULL) {
            p = TEffIndirectCtrl__ct(p, kind, tl_01);
        }
        indirect_effect_ctrl_table[indirect_effect_ctrl_count] = (TEffIndirectCtrl *)p;
        indirect_effect_ctrl_count++;
    }
}

TUnk_804DDF04::TUnk_804DDF04(s32 kind, TObject *parent) : TObject(parent) {
    indirect_kind = kind;
    register_indirect_effect_ctrl(kind);
}

TUnk_804DDF04::~TUnk_804DDF04() {
}

void TScene::draw_field_1c(s32 sampler, s32 arg2, s32 arg3) {
    TObjPlayer::play_particle_at_active_slot(*(u8 *)((s8 *)this + 0x1C), sampler, arg2, 0, arg3, 0);
}

void TScene::set_indirect_tev(s32 ignored, s32 arg1) {
    if (arg1 != 0) {
        GXSetTevDirect(1);
    } else {
        GXSetTevDirect(0);
    }
    GXSetNumIndStages(0);
    set_ginja_post_texgen_count(0);
}
