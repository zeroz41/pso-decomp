#include "types.h"
#include <string.h>
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/unk/text_803E2070.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/unk/TLobby_803DE778.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/system/MatrixOps.h"

struct Ent_803DEBC8 { u32 mask; u32 val; };

struct ChunkMaterialColor { f32 alpha, red, green, blue; };

typedef struct Pad_803DEA18
{
  u16 button;
  s8 stickX;
  s8 stickY;
  s8 substickX;
  s8 substickY;
  u8 triggerL;
  u8 triggerR;
  u8 analogA;
  u8 analogB;
  s8 err;
  u8 pad;
} Pad_803DEA18;


extern "C" {
s32 PADRead(void *, void *);
extern s32 keyboard_pad_status_buffer[];
extern s32 TKeyBoardControl__pad_status_buffer[];
extern Ent_803DEBC8 pad_button_map_table[];
u32 keyboard_pad_button_count = 12;
extern ChunkMaterialColor model_material_color;
extern u8 gx_light_objects[];
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern f32 light_position_distance;
extern s32 gx_chan_ctrl_light_mask;
void GXInitLightAttnK(void *, f32, f32, f32);
extern Pad_803DEA18 TKeyBoardControl_prev_pad_state[4];
s32 PADReset(u32);

#pragma push
#pragma scheduling off

void TKeyBoardControl::init_pad_slots_and_read(s32, s32, s32) {
    keyboard_control_pad_slots[0].conn = TKeyBoardControl__pad_status_buffer;
    keyboard_control_pad_slots[1].conn = &TKeyBoardControl__pad_status_buffer[0x1E];
    keyboard_control_pad_slots[2].conn = &TKeyBoardControl__pad_status_buffer[0x3C];
    keyboard_control_pad_slots[3].conn = &TKeyBoardControl__pad_status_buffer[0x5A];
    PADRead(keyboard_pad_status_buffer, TKeyBoardControl__pad_status_buffer);
}

typedef struct Pad_803DEA18 Pad_803DEA18;
#pragma push
#pragma use_lmw_stmw off
void TKeyBoardControl::read_pads() {
  u32 diff;
  unsigned short new_var;
  Pad_803DEA18 *pad;
  Pad_803DEA18 *old;
  PadSlot *out;
  int i;
  u16 cur;
  u16 released;
  u16 prev;
  memmove(TKeyBoardControl_prev_pad_state, keyboard_pad_status_buffer, 0x30);
  ((s32 (*)(void *)) PADRead)(keyboard_pad_status_buffer);
  for (i = 0; i < 4; i++)
  {
    pad = &((Pad_803DEA18 *) keyboard_pad_status_buffer)[i];
    old = &TKeyBoardControl_prev_pad_state[i];
    out = &keyboard_control_pad_slots[i];
    if (pad->err == 0)
    {
      ((TKeyBoardControl *)pad)->clamp_axes();
      diff = old->button ^ (new_var = pad->button);
      cur = new_var;
      released = old->button & diff;
      out->held = TKeyBoardControl::map_pad_buttons(cur);
      out->notHeld = ~out->held;
      out->pressed = TKeyBoardControl::map_pad_buttons(cur & diff);
      out->released = TKeyBoardControl::map_pad_buttons(released);
      out->stickX = TKeyBoardControl::scale_axis_value(pad->stickX);
      out->stickY = -TKeyBoardControl::scale_axis_value(pad->stickY);
      out->substickX = pad->substickX;
      out->substickY = pad->substickY;
      out->trigL = pad->triggerL;
      out->trigR = pad->triggerR;
      *out->conn = 0x101;
    }
    else
    {
      *out->conn = 0;
      PADReset(0x80000000U >> i);
    }
  }
}
#pragma pop

PadSlot *get_pad_slot(u32 device) {
    s32 slot;
    slot = 0;
    switch (device) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
        break;
    case 0:
        slot = 0;
        break;
    case 6:
        slot = 1;
        break;
    case 12:
        slot = 2;
        break;
    case 18:
        slot = 3;
        break;
    }
    return &keyboard_control_pad_slots[slot];
}
}
#pragma pop

s32 TKeyBoardControl::map_pad_buttons(u16 released) {
    s32 r = 0;
    u32 i;
    for (i = 0; i < keyboard_pad_button_count; i++) {
        if (released & pad_button_map_table[i].mask) r |= pad_button_map_table[i].val;
    }
    return r;
}

s16 TKeyBoardControl::scale_axis_value(s16 x) {
    return (x * 128) / 89;
}

void TKeyBoardControl::clamp_axes() {
    u8 *arg0 = (u8 *)this;
    u8 temp_r0;
    u8 temp_r0_2;

    temp_r0 = *(u8 *)((s8 *)arg0 + 2);
    if ((s8) temp_r0 > 0x59) {
        *(s8 *)((s8 *)arg0 + 2) = 0x59;
    } else if ((s8) temp_r0 < -0x59) {
        *(s8 *)((s8 *)arg0 + 2) = -0x59;
    }
    temp_r0_2 = *(u8 *)((s8 *)arg0 + 3);
    if ((s8) temp_r0_2 > 0x59) {
        *(s8 *)((s8 *)arg0 + 3) = 0x59;
        return;
    }
    if ((s8) temp_r0_2 < -0x59) {
        *(s8 *)((s8 *)arg0 + 3) = -0x59;
    }
}

void TObjPlayer::init_matrix_stack(s32 player_matrix_stack_buffer, s32 arg1) {
    matrix_stack_base = (GC_Mtx *)0xE0000000;
    current_matrix = (GC_Mtx *)0xE0000000;
    matrix_stack_limit = (GC_Mtx *)0xE0000000 + (arg1 - 1);
    PSMTXIdentity(identity_matrix == 0 ? (MtxP)0xE0000000 : identity_matrix);
    move_data(matrix_stack_base, identity_matrix, 0x30);
}

void init_light_globals(s32, s32) {
    model_render_flags = 0;
    chunk_polygon_flags_and_mask = -1;
    chunk_polygon_flags_or_mask = 0;
    model_material_color.alpha = 255.0f;
    model_material_color.red = 0.0f;
    model_material_color.green = 0.0f;
    model_material_color.blue = 0.0f;
    gx_chan_ctrl_light_mask = 0;
    light_position_distance = 100000000.0f;
    GXInitLightAttnK(gx_light_objects, 1.0f, 0.0f, 0.0f);
    reset_scene_fog();
}

void set_model_render_flags(u32 flags) {
    model_render_flags = flags;
}

#pragma inline_depth(1)
#pragma dont_inline off

void set_chunk_material_override_pair(s32 first, s32 second) {
    chunk_polygon_flags_and_mask = first;
    chunk_polygon_flags_or_mask = second;
}

inline f32 clampMaterialChannel(f32 value, f32 lower, f32 upper) {
    if (value < lower) return lower;
    if (value < upper) return value;
    return upper;
}

void set_constant_material(const NJS_ARGB *color) {
    model_material_color.alpha = clampMaterialChannel(color->a, (-1.0f), 1.0f);
    model_material_color.red = clampMaterialChannel(color->r, (-1.0f), 1.0f);
    model_material_color.green = clampMaterialChannel(color->g, (-1.0f), 1.0f);
    model_material_color.blue = clampMaterialChannel(color->b, (-1.0f), 1.0f);
}

s32 keyboard_pad_status_buffer[12];
Pad_803DEA18 TKeyBoardControl_prev_pad_state[4];
PadSlot keyboard_control_pad_slots[4];
s32 TKeyBoardControl__pad_status_buffer[0x78];

Ent_803DEBC8 pad_button_map_table[12] = {
    {0x1, 0x40},     {0x2, 0x80},      {0x4, 0x20},   {0x8, 0x10},
    {0x40, 0x20000}, {0x20, 0x10000},  {0x10, 0x100}, {0x100, 0x4},
    {0x200, 0x2},    {0x400, 0x400},   {0x800, 0x200}, {0x1000, 0x8},
};
