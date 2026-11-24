#include "types.h"
#include <string.h>
#include <dolphin/pad.h>
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/render/GinjaDrawUtil.h"
#include "pso/render/SceneFog.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/TLobby.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/unk/TLobby_803DE778.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/render/model_render_state.h"
#include "pso/unk/text_803DD5E0.h"
#include "pso/system/MatrixOps.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXLighting.h>
#undef PSO_SDK_COMPACT_MATH

// Defined at the end of the unit.
extern PADStatus pad_status[4];
extern PADStatus prev_pad_status[4];
extern s32 pad_slot_state_buffer[0x78];

u32 keyboard_pad_button_count = 12;

extern "C" {

#pragma push
#pragma scheduling off

void init_pad_slots_and_read(s32, s32, s32) {
    keyboard_control_pad_slots[0].conn = pad_slot_state_buffer;
    keyboard_control_pad_slots[1].conn = &pad_slot_state_buffer[0x1E];
    keyboard_control_pad_slots[2].conn = &pad_slot_state_buffer[0x3C];
    keyboard_control_pad_slots[3].conn = &pad_slot_state_buffer[0x5A];
    PADRead(pad_status);
}

#pragma push
#pragma use_lmw_stmw off
void read_pads() {
  u32 diff;
  u16 buttons;
  PADStatus *pad;
  PADStatus *old;
  PadSlot *out;
  int i;
  u16 cur;
  u16 released;
  u16 prev;
  memmove(prev_pad_status, pad_status, sizeof(prev_pad_status));
  PADRead(pad_status);
  for (i = 0; i < 4; i++)
  {
    pad = &pad_status[i];
    old = &prev_pad_status[i];
    out = &keyboard_control_pad_slots[i];
    if (pad->err == 0)
    {
      clamp_pad_axes(pad);
      diff = old->button ^ (buttons = pad->button);
      cur = buttons;
      released = old->button & diff;
      out->held = map_pad_buttons(cur);
      out->notHeld = ~out->held;
      out->pressed = map_pad_buttons(cur & diff);
      out->released = map_pad_buttons(released);
      out->stickX = scale_axis_value(pad->stickX);
      out->stickY = -scale_axis_value(pad->stickY);
      out->substickX = pad->substickX;
      out->substickY = pad->substickY;
      out->trigL = pad->triggerLeft;
      out->trigR = pad->triggerRight;
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

s32 map_pad_buttons(u16 released) {
    s32 r = 0;
    u32 i;
    for (i = 0; i < keyboard_pad_button_count; i++) {
        if (released & pad_button_map_table[i].pad_mask) r |= pad_button_map_table[i].button;
    }
    return r;
}

s16 scale_axis_value(s16 x) {
    return (x * 128) / 89;
}

void clamp_pad_axes(PADStatus *pad) {
    if (pad->stickX > 0x59) {
        pad->stickX = 0x59;
    } else if (pad->stickX < -0x59) {
        pad->stickX = -0x59;
    }
    if (pad->stickY > 0x59) {
        pad->stickY = 0x59;
    } else if (pad->stickY < -0x59) {
        pad->stickY = -0x59;
    }
}

void init_matrix_stack(s32 buffer, s32 depth) {
    matrix_stack_base = (GC_Mtx *)0xE0000000;
    current_matrix = (GC_Mtx *)0xE0000000;
    matrix_stack_limit = (GC_Mtx *)0xE0000000 + (depth - 1);
    PSMTXIdentity(identity_matrix == 0 ? (MtxP)0xE0000000 : identity_matrix);
    move_data(matrix_stack_base, identity_matrix, 0x30);
}

void init_light_globals(s32, s32) {
    model_render_flags = 0;
    chunk_polygon_flags_and_mask = -1;
    chunk_polygon_flags_or_mask = 0;
    model_material_color.a = 255.0f;
    model_material_color.r = 0.0f;
    model_material_color.g = 0.0f;
    model_material_color.b = 0.0f;
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
    model_material_color.a = clampMaterialChannel(color->a, (-1.0f), 1.0f);
    model_material_color.r = clampMaterialChannel(color->r, (-1.0f), 1.0f);
    model_material_color.g = clampMaterialChannel(color->g, (-1.0f), 1.0f);
    model_material_color.b = clampMaterialChannel(color->b, (-1.0f), 1.0f);
}

PADStatus pad_status[4];
PADStatus prev_pad_status[4];
PadSlot keyboard_control_pad_slots[4];
s32 pad_slot_state_buffer[0x78];

PadButtonMapping pad_button_map_table[12] = {
    {0x1, 0x40},     {0x2, 0x80},      {0x4, 0x20},   {0x8, 0x10},
    {0x40, 0x20000}, {0x20, 0x10000},  {0x10, 0x100}, {0x100, 0x4},
    {0x200, 0x2},    {0x400, 0x400},   {0x800, 0x200}, {0x1000, 0x8},
};
