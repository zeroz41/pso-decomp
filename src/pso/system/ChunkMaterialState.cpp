#include "types.h"
#include "pso/misc/TKeyBoardControl_803DE9C4.h"
#include "pso/unk/text_803E2070.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TLobby.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/player/TUnk_80494AE0.h"

struct RecoveredGlobal_803DEB74_lbl_8058D8E0 {
    s32 value;
    u8 remaining[0xCC];
};

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

typedef struct Out_803DEA18
{
  s32 f0;
  s32 f4;
  s32 held;
  s32 notHeld;
  s32 pressed;
  s32 released;
  s16 trigR;
  s16 trigL;
  s16 stickX;
  s16 stickY;
  s16 substickX;
  s16 substickY;
  u8 unk24[0xC];
  s32 *conn;
} Out_803DEA18;

extern "C" {
extern RecoveredGlobal_803DEB74_lbl_8058D8E0 keyboard_control_pad_slots;
s32 Dolphin_PADRead(void *, void *);
extern s32 keyboard_pad_status_buffer[];
extern s32 TKeyBoardControl__pad_status_buffer[];
extern Ent_803DEBC8 pad_button_map_table[];
extern u32 keyboard_pad_button_count;
extern ChunkMaterialColor model_material_color;
extern u8 TObjLight__gx_light_objects[];
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern f32 light_position_distance;
extern s32 gx_chan_ctrl_light_mask;
void GXInitLightAttnK(void *, f32, f32, f32);
extern u8 identity_matrix[];
extern u32 matrix_stack_limit;
extern u32 matrix_stack_base;
extern u32 current_matrix;
void PSMTXIdentity(void *);
extern Pad_803DEA18 TKeyBoardControl_prev_pad_state[4];
void *memmove(void *, const void *, u32);
s32 PADReset(u32);

#pragma push
#pragma scheduling off
typedef char RecoveredGlobal_803DEB74_lbl_8058D8E0_size[sizeof(RecoveredGlobal_803DEB74_lbl_8058D8E0) == 0xD0 ? 1 : -1];

void TKeyBoardControl::init_pad_slots_and_read() {
    *(s32 **)((s8 *)((s32 *)&keyboard_control_pad_slots) + 0x30) = TKeyBoardControl__pad_status_buffer;
    *(u8 **)((s8 *)((s32 *)&keyboard_control_pad_slots) + 0x64) = (unsigned char *) ((void *) ((u8 *)TKeyBoardControl__pad_status_buffer + 0x78));
    *(u8 **)((s8 *)((s32 *)&keyboard_control_pad_slots) + 0x98) = (unsigned char *) ((void *) ((u8 *)TKeyBoardControl__pad_status_buffer + 0xF0));
    *(u8 **)((s8 *)((s32 *)&keyboard_control_pad_slots) + 0xCC) = (unsigned char *) ((void *) ((u8 *)TKeyBoardControl__pad_status_buffer + 0x168));
    Dolphin_PADRead(keyboard_pad_status_buffer, TKeyBoardControl__pad_status_buffer);
}

typedef struct Out_803DEA18 Out_803DEA18;
typedef struct Pad_803DEA18 Pad_803DEA18;
typedef struct RecoveredGlobal_803DEB74_lbl_8058D8E0 RecoveredGlobal_803DEB74_lbl_8058D8E0;
#pragma push
#pragma use_lmw_stmw off
void TKeyBoardControl::read_pads() {
  u32 diff;
  unsigned short new_var;
  Pad_803DEA18 *pad;
  Pad_803DEA18 *old;
  Out_803DEA18 *out;
  int i;
  u16 cur;
  u16 released;
  u16 prev;
  memmove(TKeyBoardControl_prev_pad_state, keyboard_pad_status_buffer, 0x30);
  ((s32 (*)(void *)) Dolphin_PADRead)(keyboard_pad_status_buffer);
  for (i = 0; i < 4; i++)
  {
    pad = &((Pad_803DEA18 *) keyboard_pad_status_buffer)[i];
    old = &TKeyBoardControl_prev_pad_state[i];
    out = &((Out_803DEA18 *) (&keyboard_control_pad_slots))[i];
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

u8 *TKeyBoardControl__sub_803DEB74(u32 arg0) {
    s32 var_r5;
    var_r5 = 0;
    switch (arg0) {
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
        var_r5 = 0;
        break;
    case 6:
        var_r5 = 1;
        break;
    case 12:
        var_r5 = 2;
        break;
    case 18:
        var_r5 = 3;
        break;
    }
    return (u8 *)&keyboard_control_pad_slots.value + (var_r5 * 0x34);
}
#pragma pop

s32 TKeyBoardControl::map_pad_buttons(u16 arg0) {
    s32 r = 0;
    u32 i;
    for (i = 0; i < keyboard_pad_button_count; i++) {
        if (arg0 & pad_button_map_table[i].mask) r |= pad_button_map_table[i].val;
    }
    return r;
}

#pragma push
#pragma scheduling off
#pragma optimize_for_size off
s16 TKeyBoardControl::scale_axis_value(s16 x) {
    return (x * 128) / 89;
}
#pragma pop

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

void TObjPlayer::init_matrix_stack(s32 arg0, s32 arg1) {
    matrix_stack_base = 0xE0000000;
    current_matrix = 0xE0000000;
    matrix_stack_limit = (arg1 - 1) * 0x30 + 0xE0000000;
    PSMTXIdentity(identity_matrix == 0 ? (u8 *)0xE0000000 : identity_matrix);
    ((TLobby *)matrix_stack_base)->move_data(identity_matrix, 0x30);
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
    GXInitLightAttnK(TObjLight__gx_light_objects, 1.0f, 0.0f, 0.0f);
    reset_scene_fog();
}

}

void set_model_render_flags(u32 flags) {
    model_render_flags = flags;
}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void set_chunk_material_override_pair(s32 arg0, s32 arg1) {
    chunk_polygon_flags_and_mask = arg0;
    chunk_polygon_flags_or_mask = arg1;
}

#pragma push
#pragma peephole off
#pragma opt_common_subs off
#pragma scheduling off
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
#pragma pop
