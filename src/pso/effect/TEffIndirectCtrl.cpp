#include "pso/system/ResourceFile.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma readonly_strings on

#include "types.h"
#include <string.h>
#include <stdlib.h>
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/TEffIndirectCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_803DC834.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/GinjaTextureInput.h"
#include "pso/system/memory.h"
#include <dolphin/os/OSCache.h>
#include "pso/player/TObjPlayer_803E1A58.h"
#include <dolphin/gx/GXBump.h>

typedef void (TEffIndirectCtrl::*IndirectTask)();

extern "C" {
void load_texture_list(void *);
}

const char *indirect_dat_filename = "indirect.dat";
const char *indinfo_dat_filename = "indinfo.dat";
const char *TEffIndirectCtrl::class_name = "TEffIndirectCtrl";

TEffIndirectSource *TEffIndirectCtrl::source_buffers[8];
TEffIndirectCtrl *indirect_effect_ctrl_table[6];
TEffIndirectRecipe *indirect_recipe_buffer;
u8 indirect_effect_ctrl_count;
u16 *indirect_effect_tile_buffer;

// Built -inline off,deferred: functions come out in reverse source order.

TEffIndirectRecipe *get_indirect_recipe(s32 index) {
    if (index >= 0x40) return 0;
    return &indirect_recipe_buffer[index];
}

void TEffIndirectCtrl::pause_indirect_effect() { paused = 1; }

u8 TEffIndirectCtrl::get_indirect_kind() { return kind; }

void TEffIndirectCtrl::resume_indirect_effect() { paused = 0; }

void load_indirect_info() {
    s32 i;
    s32 j;
    indirect_recipe_buffer = (TEffIndirectRecipe *)xmalloc(0x200);
    memset(indirect_recipe_buffer, 0, 0x200);
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
    read_disc_file(indinfo_dat_filename, indirect_recipe_buffer);
}

u32 get_indirect_tile_coord(u8 x, u8 y, s32 width) {
    if (indirect_effect_tile_buffer != NULL) {
        return indirect_effect_tile_buffer[x + (y << 6)];
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

void load_indirect_dat() {
    s32 i;
    s32 fail;
    s32 j;
    u8 *buf;
    u8 *p;
    s32 k;
    fail = 0;
    for (i = 0; i < 8; i++) {
        TEffIndirectCtrl::source_buffers[i] = NULL;
    }
    for (i = 0; i < 8; i++) {
        TEffIndirectCtrl::source_buffers[i] = (TEffIndirectSource *)xmalloc(sizeof(TEffIndirectSource));
        if (TEffIndirectCtrl::source_buffers[i] == NULL) {
            fail = 1;
        }
    }
    if (fail != 0) {
        for (j = 0; j < 8; j++) {
            if (TEffIndirectCtrl::source_buffers[j] != NULL) {
                xfree(TEffIndirectCtrl::source_buffers[j]);
                TEffIndirectCtrl::source_buffers[j] = NULL;
            }
        }
    }
    p = (u8 *)xmalloc(0x8100);
    if (p != NULL) {
        buf = p;
        if (read_disc_file(indirect_dat_filename, p) == 0x8100) {
            for (k = 0; k < 8; k++) {
                memcpy(TEffIndirectCtrl::source_buffers[k], p, sizeof(TEffIndirectSource));
                p += sizeof(TEffIndirectSource);
            }
            if (buf != NULL) {
                xfree(buf);
            }
            load_indirect_info();
            reset_indirect_effect_ctrl_table();
        }
    }
}

void TEffIndirectCtrl::free_all() {
    s32 i;

    clear_indirect_effect_ctrl_table();
    free_buffers();
    for (i = 0; i < 8; i++) {
        if (source_buffers[i] != NULL) {
            xfree(source_buffers[i]);
            source_buffers[i] = NULL;
        }
    }
}

saddr get_indirect_source_id(u8 index) {
    if (index >= 8U) {
        index = 0;
    }
    return TEffIndirectCtrl::source_buffers[index]->texture_id;
}

u8 *get_indirect_source_pixels(u8 index) {
    if (index >= 8U) {
        index = 0;
    }
    return TEffIndirectCtrl::source_buffers[index]->pixels;
}

u32 calc_i8_tiled_texel_offset(u8 x, u8 y, u32 width) {
    u32 r = (((x >> 3) & 0x1F) << 5) + (x & 7);
    r += (((y >> 2) & 0x3F) * width) << 2;
    r += (y & 3) << 3;
    return r;
}

void deform_indirect_texture_scroll(u8 *p, u32 scroll_x, u32 scroll_y, s32 amplitude, u32 phase) {
  IndirectScrollTexel buf[64];
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
  offset = (s32) (((f32) (u8) amplitude) * sin_table_lookup((s32) (182.04445f * ((f32) phase))));
  if (scroll_x != 0)
  {
    flags |= 1;
    count = 1;
  }
  if (scroll_y != 0)
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
  pxm = scroll_x & 63;
  pym = scroll_y & 63;
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
          idx = get_indirect_tile_coord(at, line, 64);
        }
        else
        {
          idx = get_indirect_tile_coord(line, at, 64);
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
void update_indirect_texture_wave(u8 *pixels, s32 amplitude_x, s32 amplitude_y, s32 phase_x, s32 phase_y, u8 phase_step) {
    s32 off;
    s32 x;
    s32 i;
    s32 v;
    s16 row;
    s32 y;
    for (y = 0; y < 64; y++) {
        row = (s32)((f32)(u8)amplitude_y * sin_table_lookup((s32)(182.04445f * (f32)(u32)(phase_y + y * phase_step))));
        for (x = 0; x < 64; x++) {
            off = (s32)((f32)(u8)amplitude_x * sin_table_lookup((s32)(182.04445f * (f32)(u32)(phase_x + x * phase_step))) + (f32)row);
            i = get_indirect_tile_coord(x, y, 0x40);
            v = pixels[i];
            v += off;
            if ((s16)v >= 0xFF) {
                v = 0xFE;
            }
            if ((s16)v <= 0) {
                v = 0;
            }
            pixels[i] = v;
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void deform_indirect_texture_wave(u8 *pixels, s32 amplitude_x, s32 amplitude_y, s32 phase_x, s32 phase_y, u8 phase_step) {
    s32 v;
    s32 off;
    s32 y;
    s16 row;
    s32 x;
    for (y = 0; y < 64; y++) {
        row = (s32)((f32)(u8)amplitude_y * sin_table_lookup((s32)(182.04445f * (f32)(u32)(phase_y + y * phase_step))));
        for (x = 0; x < 64; x++) {
            off = (s32)((f32)(u8)amplitude_x * sin_table_lookup((s32)(182.04445f * (f32)(u32)(phase_x + x * phase_step))) + (f32)row);
            v = *pixels;
            if ((s16)v != 0xFF) {
                v = v + off;
                if ((s16)v >= 0xFF) {
                    v = 0xFE;
                }
                if ((s16)v <= 0) {
                    v = 0;
                }
            }
            *pixels++ = v;
        }
    }
}
#pragma pop

TEffIndirectCtrl::TEffIndirectCtrl(s32 kind, TObject *parent) : TObject(parent) {
    saddr global_index;
    u8 k;
    m_name = class_name;
    texture_info = (GinjaTextureInput *)::operator new(sizeof(GinjaTextureInput));
    texture_list = (NJS_TEXLIST *)::operator new(sizeof(NJS_TEXLIST));
    if (texture_list == NULL || texture_info == NULL) {
        queue_destruction();
        return;
    }
    paused = 0;
    horizontal_amplitude = 0.0f;
    vertical_amplitude = 0.0f;
    horizontal_phase = 0;
    vertical_phase = 0;
    scroll_phase = 0;
    jitter = 0.0f;
    k = kind;
    this->kind = kind;
    recipe = get_indirect_recipe(k);
    if (recipe == NULL) {
        return;
    }
    source_index = recipe->source_index;
    global_index = get_indirect_source_id(source_index);
    global_index += k * 1000;
    texture_list->textures = &texture_entry;
    texture_list->nbTexture = 1;
    texture_info->set_render_rect(NULL, 1, 0x40, 0x40);
    set_texture_name(&texture_entry, texture_info, global_index, 0x8800000);
    load_texture_list(texture_list);
    pixels = (u8 *)texture_list->textures->texture->surface->header.pixels;
    copy_and_flush_texture(get_indirect_source_pixels(source_index));
}

TEffIndirectCtrl::~TEffIndirectCtrl() {
    if (texture_list != NULL) {
        release_texture_list(texture_list);
        ::operator delete(texture_list);
    }
    if (texture_info != NULL) {
        ::operator delete(texture_info);
    }
}

void TEffIndirectCtrl::copy_and_flush_texture(u8 *source) {
    memcpy(pixels, source, 0x1000);
    DCFlushRange(pixels, 0x1000);
}

void TEffIndirectCtrl::run_task() {
    if (TObjPlayer::check_demo_mode() != 0 || paused == 0) {
        horizontal_phase += recipe->horizontal_step;
        vertical_phase += recipe->vertical_step;
        horizontal_amplitude = recipe->horizontal_amplitude;
        vertical_amplitude = recipe->vertical_amplitude;
        IndirectTask modes[3] = {
            &TEffIndirectCtrl::update_scroll_mode,
            &TEffIndirectCtrl::eff_indirect_update_and_flush,
            &TEffIndirectCtrl::update_eff_indirect,
        };
        if ((actor_frame_tick & 0x1F) == 0) {
            jitter = recipe->variation * (3.0517578e-05f * rand());
        }
        if (recipe->mode < 3) {
            (this->*modes[recipe->mode])();
        }
        source_index = recipe->source_index;
        pause_indirect_effect();
    }
}

void TEffIndirectCtrl::render() {  }

void TEffIndirectCtrl::eff_indirect_update_and_flush() {
    copy_and_flush_texture(get_indirect_source_pixels(source_index));
    update_indirect_texture_wave(pixels, (s32) horizontal_amplitude, vertical_amplitude, horizontal_phase, vertical_phase, recipe->phase_step);
    DCFlushRange(pixels, 0x1000);
}

void TEffIndirectCtrl::update_eff_indirect() {
    copy_and_flush_texture(get_indirect_source_pixels(source_index));
    deform_indirect_texture_wave(pixels, (s32) horizontal_amplitude, vertical_amplitude, horizontal_phase, vertical_phase, recipe->phase_step);
    DCFlushRange(pixels, 0x1000);
}

void TEffIndirectCtrl::update_scroll_mode() {
    s32 rate;
    copy_and_flush_texture(get_indirect_source_pixels(source_index));
    rate = (s32)horizontal_amplitude;
    scroll_phase = scroll_phase + recipe->variation;
    deform_indirect_texture_scroll(pixels, horizontal_phase, vertical_phase, rate, scroll_phase);
    DCFlushRange(pixels, 0x1000);
}

void setup_indirect_tev_alternate(TEffIndirectCtrl *ctrl, s32 unused, s32 sampler, s32 scale) {
    if ((u8)scale < 5) {
        u8 index = scale;
        GXTexCoordID coords[5] = {GX_TEXCOORD0, GX_TEXCOORD1, GX_TEXCOORD2, GX_TEXCOORD3, GX_TEXCOORD4};
        GXIndTexScale scales[5] = {GX_ITS_1, GX_ITS_2, GX_ITS_4, GX_ITS_8, GX_ITS_16};
        f32 mtx[2][3];
        GXSetNumIndStages(1);
        GXSetIndTexOrder(GX_INDTEXSTAGE0, coords[2], GX_TEXMAP5);
        GXSetIndTexCoordScale(GX_INDTEXSTAGE0, scales[index], scales[index]);
        GXSetTevIndWarp(GX_TEVSTAGE1, GX_INDTEXSTAGE0, GX_FALSE, GX_FALSE, GX_ITM_0);
        mtx[0][0] = 0.5f;
        mtx[0][1] = 0.0f;
        mtx[0][2] = 0.0f;
        mtx[1][0] = 0.0f;
        mtx[1][1] = 0.5f;
        mtx[1][2] = 0.0f;
        GXSetIndTexMtx(GX_ITM_0, mtx, 1);
        TObjFish::set_global_param(ctrl->texture_list);
        load_list_texture(0, sampler, sampler, 5);
    }
}


void setup_indirect_tev_ordinary(TEffIndirectCtrl *ctrl, s32 sampler, s32 scale, s32 second) {
    GXIndTexScale scales[5] = {GX_ITS_1, GX_ITS_2, GX_ITS_4, GX_ITS_8, GX_ITS_16};
    f32 m0[2][3];
    f32 m1[2][3];
    GXSetNumIndStages(1);
    GXSetIndTexOrder(GX_INDTEXSTAGE0, GX_TEXCOORD0, GX_TEXMAP5);
    GXSetIndTexCoordScale(GX_INDTEXSTAGE0, scales[(u8)scale], scales[(u8)scale]);
    if (second != 0) {
        static s32 shift = -2;
        static s32 unused = 0;
        static f32 k = 0.5f;
        GXSetTevIndWarp(GX_TEVSTAGE1, GX_INDTEXSTAGE0, GX_FALSE, GX_FALSE, GX_ITM_0);
        m0[0][0] = k;
        m0[0][1] = 0.0f;
        m0[0][2] = 0.0f;
        m0[1][0] = 0.0f;
        m0[1][1] = k;
        m0[1][2] = 0.0f;
        GXSetIndTexMtx(GX_ITM_0, m0, (s8)shift);
    } else {
        GXSetTevIndWarp(GX_TEVSTAGE0, GX_INDTEXSTAGE0, GX_FALSE, GX_FALSE, GX_ITM_0);
        m1[0][0] = 0.5f;
        m1[0][1] = 0.0f;
        m1[0][2] = 0.0f;
        m1[1][0] = 0.0f;
        m1[1][1] = 0.5f;
        m1[1][2] = 0.0f;
        GXSetIndTexMtx(GX_ITM_0, m1, 1);
    }
    TObjFish::set_global_param(ctrl->texture_list);
    load_list_texture(0, sampler, sampler, 5);
}

void reset_indirect_effect_ctrl_table() {
    s32 i;
    indirect_effect_ctrl_count = 0;
    for (i = 0; i < 6; i++) indirect_effect_ctrl_table[i] = 0;
}

void clear_indirect_effect_ctrl_table() {
    s32 i;
    for (i = 0; i < 6; i++) indirect_effect_ctrl_table[i] = 0;
}

void TObjPlayer::play_particle_at_active_slot(s32 kind, s32 sampler, s32 scale, s32 alternate, s32 unused, s32 second) {
    s32 indirect_effect_ctrl;

    indirect_effect_ctrl = (s32)(s8) find_indirect_effect_ctrl(kind);
    if ((indirect_effect_ctrl != -1) && (indirect_effect_ctrl_table[indirect_effect_ctrl] != NULL)) {
        if (alternate != 0) {
            setup_indirect_tev_alternate(indirect_effect_ctrl_table[indirect_effect_ctrl], unused, sampler, scale);
            return;
        }
        setup_indirect_tev_ordinary(indirect_effect_ctrl_table[indirect_effect_ctrl], sampler, scale, second);
    }
}

s8 find_indirect_effect_ctrl(s32 kind) {
    s32 i;
    for (i = 0; i < indirect_effect_ctrl_count; i++) {
        if (indirect_effect_ctrl_table[i] != 0) {
            u8 id = indirect_effect_ctrl_table[i]->get_indirect_kind();
            if (id == (u8)kind) {
                if (TObjPlayer::check_demo_mode() == 0) {
                    indirect_effect_ctrl_table[i]->resume_indirect_effect();
                }
                return i;
            }
        }
    }
    return -1;
}

void register_indirect_effect_ctrl(s32 kind) {
    if (find_indirect_effect_ctrl(kind) < 0 && indirect_effect_ctrl_count < 6) {
        indirect_effect_ctrl_table[indirect_effect_ctrl_count] = new TEffIndirectCtrl(kind, tl_01);
        indirect_effect_ctrl_count++;
    }
}

TEffIndirect::TEffIndirect(s32 kind, TObject *parent) : TObject(parent) {
    this->kind = kind;
    register_indirect_effect_ctrl(kind);
}

TEffIndirect::~TEffIndirect() {
}

void enable_indirect_tev(TEffIndirect *effect, s32 sampler, s32 scale, s32 mode) {
    TObjPlayer::play_particle_at_active_slot(effect->kind, sampler, scale, 0, mode, 0);
}

void disable_indirect_tev(TEffIndirect *effect, s32 direct) {
    if (direct != 0) {
        GXSetTevDirect(GX_TEVSTAGE1);
    } else {
        GXSetTevDirect(GX_TEVSTAGE0);
    }
    GXSetNumIndStages(0);
    set_ginja_post_texgen_count(0);
}
