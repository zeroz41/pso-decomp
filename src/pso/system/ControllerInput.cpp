#include "types.h"
#include <dolphin/os/OSResetSW.h>
#include <dolphin/pad.h>
#include "pso/system/ControllerInput.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/main_loop.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/data/pso_date.h"
#include "pso/player/TObjPlayer_80011014.h"

const u32 input_button_mask_table[14] = {
    0x10, 0x20, 0x40, 0x80, 0x100000, 0x200000, 0x400000, 0x800000,
    0x4000000, 0x8000000, 0x10000000, 0x20000000, 0x20000, 0x10000,
};

s8 lbl_805D5D08;
// Set when X+B+Start is held for 15 frames or the reset button is pressed.
u8 controller_reset_requested;
s8 keyboard_reset_button_pressed;
s8 pad_recalibration_hold_frames[4];
extern "C" {
BOOL DVDCheckDisk();
extern s32 lbl_805D49B4;
}

// Stands in for a port with no controller: nothing held.
PadSlot controller_default_pad_state = { 0, 0, 0, 0xFFFFFFFF, 0, 0, 0, 0, 0, 0, 0, 0, { 0 }, 0 };
u32 TKeyBoardControl_key_bit_table[6] = { 16, 32, 64, 128, 4, 2 };
u32 keyboard_poll_key_codes[6] = { 94, 93, 92, 95, 97, 76 };
s32 controller_device_id_table[4] = { 0, 6, 12, 18 };

extern "C" {
s32 lbl_805D34C8 = 1;
ControllerInputState controller_input_state;
ControllerInputState controller_physical_port_bank;
u32 pad_recalibration_counters[4];

void TKeyBoardControl::reset() { controller_reset_requested = 0; }


s32 TKeyBoardControl::any_pad_input_active() {
    s32 i;
    for (i = 0; i < 4; i++) {
        PadSlot *slot = controller_input_state.sources[i];
        if (slot->pressed != 0 || slot->trigR >= 10 || slot->trigL >= 10 || slot->stickX >= 10 || slot->stickX <= -10 || slot->stickY >= 10 || slot->stickY <= -10) {
            return 1;
        }
    }
    return 0;
}

s32 TKeyBoardControl::check_reset_button() {
    if (OSGetResetButtonState() != 0) {
        keyboard_reset_button_pressed = 1;
    }
    if (keyboard_reset_button_pressed != 0) {
        if (OSGetResetButtonState() != 0) {
            return 0;
        }
        keyboard_reset_button_pressed = 0;
        return 1;
    }
    return 0;
}

s32 TKeyBoardControl__sub_801A58B0(void) {
    return hardware_keyboard_state.sub_801321B4();
}

s32 TKeyBoardControl__sub_801A58D8(void) {
    return hardware_keyboard_state.sub_80132310();
}

s32 TKeyBoardControl::check_and_read(s32 arg0) {
    if (hardware_keyboard_state.check_input_ready() != 0) {
        return TKeyBoardControl::is_key_down(arg0);
    }
    return 0;
}

s32 TKeyBoardControl::read_input(u8 key) {
    if (hardware_keyboard_state.check_input_ready() != 0) {
        return update_state_from_input__16TKeyBoardControlFPv(key);
    }
    return 0;
}

s32 TKeyBoardControl::is_key_down(s32 arg0) {
    s32 i;
    s32 n;
    n = hardware_keyboard_state.get_pending_count();
    for (i = 0; i < n; i++) {
        if ((u8)arg0 == hardware_keyboard_state.sub_8013239C(i)) {
            return 1;
        }
    }
    return 0;
}

s32 update_state_from_input__16TKeyBoardControlFPv(u8 key) {
    return hardware_keyboard_state.sub_801323C8(key);
}

s32 StickEscapeDetector::check_input_angle() {
    const ControllerInputContext *current = input;
    if (current == NULL) {
        return 0;
    }
    if (current->stick_magnitude < 0.5f) {
        return 0;
    }
    const s32 previous_angle = last_stick_angle;
    last_stick_angle = current->stick_angle;
    const u16 turn = previous_angle - last_stick_angle;
    if ((s32)turn > 0x5000 && (s32)turn < 0xB000) {
        const s32 previous_frame = last_turn_frame;
        last_turn_frame = actor_frame_tick;
        if (last_turn_frame - previous_frame < 8) {
            return 1;
        }
    }
    return 0;
}
}

void init_stick_escape_detector(StickEscapeDetector *detector, const ControllerInputContext *input) {
    if (input != NULL) {
        detector->input = input;
        detector->last_stick_angle = detector->input->stick_angle;
        detector->last_turn_frame = actor_frame_tick;
    }
}

void StickEscapeDetector::reset_fields() {
    last_stick_angle = 0;
    last_turn_frame = 0;
    input = NULL;
}

s32 TKeyBoardControl::get_ascii_key() {
  short new_var;
  s32 temp_r3;
  s32 var_r3;
  u8 temp_r31;
  if (hardware_keyboard_state.get_pending_count() == 0)
  {
    return 0;
  }
  var_r3 = hardware_keyboard_state.sub_8013239C(0);
  temp_r31 = var_r3;
  temp_r3 = hardware_keyboard_state.sub_80132310();
  if ((((s32) temp_r31) >= 0x2A) && (((s32) temp_r31) <= 0x32))
  {
    return temp_r31 + 7;
  }
  if ((((s32) temp_r31) >= 0x10) && (((s32) temp_r31) <= 0x29))
  {
    var_r3 = temp_r31 + 0x51;
    if (temp_r3 != 0)
    {
      return temp_r31 + 0x31;
    }
    return var_r3;
  }
  switch (temp_r31)
  {
    case 0x33:
      return 0x30;
    case 0x61:
      return 0xD;
    case 0x4C:
      return 0x1B;
    case 0x50:
      return 8;
    case 0x51:
      return (float) 9;
    case 0x3C:
      var_r3 = 0x2C;
      if (temp_r3 != 0)
    {
      return 0x3C;
    }
      return var_r3;
    case 0x3D:
      var_r3 = 0x2E;
      if (temp_r3 != 0)
    {
      return 0x3E;
    }
      return var_r3;
    case 0x39:
      var_r3 = 0x3B;
      if (temp_r3 != 0)
    {
      return 0x2B;
    }
      return var_r3;
    case 0x3A:
      var_r3 = 0x3A;
      if (new_var = temp_r3 != 0)
    {
      return 0x2A;
    }
      return var_r3;
    case 0x52:
      if (temp_r3 != 0)
    {
      return 0x5F;
    }
    default:
      var_r3 = 0;
      return var_r3;
  }
}

void update_pad_recalibration(void) {
    s32 i;
    s32 j;
    u32 channels[4] = { 0x80000000, 0x40000000, 0x20000000, 0x10000000 };
    for (i = 0; i < 4; i++) {
        if ((controller_input_state.controllers[i].buttons & 0x40A) == 0x40A) {
            pad_recalibration_hold_frames[i]++;
            if (15.0 == (f64)pad_recalibration_hold_frames[i]) {
                controller_reset_requested = 1;
                for (j = 0; j < 4; j++) {
                    PADRecalibrate(channels[j]);
                }
            } else if ((f64)pad_recalibration_hold_frames[i] > 15.0) {
                pad_recalibration_hold_frames[i] = 0x10;
            }
        } else {
            pad_recalibration_hold_frames[i] = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if ((controller_input_state.controllers[i].buttons & 0x608) == 0x608) {
            pad_recalibration_counters[i]++;
            if ((f32)pad_recalibration_counters[i] >= 9.0e1f) {
                pad_recalibration_counters[i] = 0;
                PADRecalibrate(channels[i]);
            }
        } else {
            pad_recalibration_counters[i] = 0;
        }
    }
    if (TKeyBoardControl::check_reset_button() != 0) {
        controller_reset_requested = 1;
        for (j = 0; j < 4; j++) {
            PADRecalibrate(channels[j]);
        }
    }
}

s32 func_801A5E54(void) {
    if ((DVDCheckDisk() == 0) && (TKeyBoardControl::check_reset_button() != 0)) {
        reset_system();
    }
    return (lbl_805D49B4 != 0) ? 0 : controller_reset_requested;
}

s32 TKeyBoardControl::read_key_checked(u8 arg0) {
    return TKeyBoardControl::check_and_read((s32)(arg0));
}
void TKeyBoardControl::update_input_frame() {
    hardware_keyboard_state.sub_80132650();
    if (is_split_screen() == 0) {
        ControllerInputContext *keyboard = &controller_input_state.keyboard;
        keyboard->poll_key_state();
        update_button_hold_counters(keyboard);
    }
}
#pragma push
#pragma fp_contract on
void controller_stuff(void) {
    s32 i;
    PadSlot **sources;
    ControllerInputState *state;
    ControllerInputContext *pad;
    u32 previous;
    s32 bank;
    s32 j;
    PadSlot *slot;
    s32 stick_angle;
    s32 cstick_angle;
    f32 stick_x;
    f32 stick_y;
    f32 cstick_x;
    f32 cstick_y;
    f32 magnitude;
    if (lbl_805D34C8 != 0) {
        bind_controller_devices();
        for (bank = 0; bank < 2; bank++) {
            if (bank == 0) {
                pad = controller_input_state.controllers;
                sources = controller_input_state.sources;
                state = &controller_input_state;
            } else {
                pad = controller_physical_port_bank.controllers;
                sources = controller_physical_port_bank.sources;
                state = &controller_physical_port_bank;
            }
            for (i = 0; i < 4; pad++, i++) {
                slot = *sources++;
                if (state->source_status[i] == 1) {
                    previous = pad->buttons;
                    pad->buttons = slot->held;
                    pad->not_held = slot->notHeld;
                    pad->pressed_buttons = slot->pressed;
                    pad->released = slot->released;
                    pad->trigger_l = slot->trigL;
                    pad->trigger_r = slot->trigR;
                    stick_x = slot->stickX;
                    pad->stick_x = stick_x;
                    stick_y = slot->stickY;
                    pad->stick_y = stick_y;
                    cstick_x = slot->substickX;
                    pad->cstick_x = cstick_x;
                    cstick_y = -slot->substickY;
                    pad->cstick_y = cstick_y;
                    if ((-31.0f) < stick_x && stick_x <= 31.0f) {
                        stick_x = 0.0f;
                        pad->stick_x = 0;
                    }
                    if ((-31.0f) < stick_y && stick_y <= 31.0f) {
                        stick_y = 0.0f;
                        pad->stick_y = 0;
                    }
                    if ((-31.0f) < cstick_x && cstick_x <= 31.0f) {
                        cstick_x = 0.0f;
                        pad->cstick_x = 0;
                    }
                    if ((-31.0f) < cstick_y && cstick_y <= 31.0f) {
                        cstick_y = 0.0f;
                        pad->cstick_y = 0;
                    }
                    magnitude = newton_sqrtf(stick_x * stick_x + stick_y * stick_y);
                    if (0.0f != magnitude) {
                        magnitude *= 0.0078125f;
                    }
                    if (magnitude > 1.0f) {
                        magnitude = 1.0f;
                    }
                    pad->stick_magnitude = magnitude;
                    magnitude = newton_sqrtf(cstick_x * cstick_x + cstick_y * cstick_y);
                    if (0.0f != magnitude) {
                        magnitude *= 0.0078125f;
                    }
                    if (magnitude > 1.0f) {
                        magnitude = 1.0f;
                    }
                    pad->cstick_magnitude = magnitude;
                    pad->buttons &= ~0x30000;
                    pad->not_held &= ~0x30000;
                    pad->pressed_buttons &= ~0x30000;
                    pad->released &= ~0x30000;
                    if (pad->trigger_r > 0x70) {
                        pad->buttons |= 0x10000;
                        if (!(previous & 0x10000)) {
                            pad->pressed_buttons |= 0x10000;
                        }
                    } else {
                        pad->not_held |= 0x10000;
                        if (previous & 0x10000) {
                            pad->released |= 0x10000;
                        }
                    }
                    if (pad->trigger_l > 0x70) {
                        pad->buttons |= 0x20000;
                        if (!(previous & 0x20000)) {
                            pad->pressed_buttons |= 0x20000;
                        }
                    } else {
                        pad->not_held |= 0x20000;
                        if (previous & 0x20000) {
                            pad->released |= 0x20000;
                        }
                    }
                    previous = pad->held_with_sticks;
                    pad->held_with_sticks = pad->buttons &= 0xC30FFFFF;
                    pad->pressed_with_sticks = pad->pressed_buttons &= 0xC30FFFFF;
                    map_main_stick_to_buttons(pad, pad->stick_x, pad->stick_y, previous);
                    map_c_stick_to_buttons(pad, pad->cstick_x, pad->cstick_y, previous);
                    if (camera_ctrl_instance != NULL) {
                        if (is_split_screen() != 0) {
                            stick_angle = camera_ctrl_instance->view_yaw[i] + (s32)(10430.38043493439 * atan2_float(stick_x, stick_y));
                            cstick_angle = camera_ctrl_instance->view_yaw[i] + (s32)(10430.38043493439 * atan2_float(cstick_x, cstick_y));
                        } else {
                            stick_angle = camera_ctrl_instance->view_yaw[0] + (s32)(10430.38043493439 * atan2_float(stick_x, stick_y));
                            cstick_angle = camera_ctrl_instance->view_yaw[0] + (s32)(10430.38043493439 * atan2_float(cstick_x, cstick_y));
                        }
                    } else {
                        stick_angle = (s32)(10430.38043493439 * atan2_float(stick_x, stick_y));
                        cstick_angle = (s32)(10430.38043493439 * atan2_float(cstick_x, cstick_y));
                    }
                    pad->stick_angle = (u16)stick_angle;
                    pad->cstick_angle = (u16)cstick_angle;
                    update_button_hold_counters(pad);
                } else {
                    pad->buttons = controller_default_pad_state.held;
                    pad->not_held = controller_default_pad_state.notHeld;
                    pad->pressed_buttons = controller_default_pad_state.pressed;
                    pad->released = controller_default_pad_state.released;
                    pad->trigger_l = controller_default_pad_state.trigL;
                    pad->trigger_r = controller_default_pad_state.trigR;
                    pad->stick_x = controller_default_pad_state.stickX;
                    pad->stick_y = controller_default_pad_state.stickY;
                    pad->cstick_x = controller_default_pad_state.substickX;
                    pad->cstick_y = controller_default_pad_state.substickY;
                    pad->stick_angle = 0;
                    pad->stick_magnitude = 0.0f;
                    for (j = 0; j < 14; j++) {
                        pad->hold_frames[j] = 0;
                    }
                    pad->held_with_sticks = 0;
                    pad->pressed_with_sticks = 0;
                }
            }
        }
        update_pad_recalibration();
    }
}

#pragma pop

#pragma push

struct ControllerHoldFrameBlock {
    u32 words[7];
};

extern "C" {
void copy_state__16TKeyBoardControlFPvPv(ControllerInputContext *arg0, ControllerInputContext *arg1);

void bind_controller_devices(void) {
    PadSlot *slot;
    PadSlot **sources;
    s32 *status;
    PadSlot **bank_sources;
    s32 i;
    s32 *devices;
    s32 *bank_status;
    s32 count;
    sources = controller_input_state.sources;
    bank_sources = controller_physical_port_bank.sources;
    status = controller_input_state.source_status;
    devices = controller_device_id_table;
    bank_status = controller_physical_port_bank.source_status;
    for (i = 0; i < 4; i++) {
        slot = get_pad_slot(*devices++);
        if (*slot->conn & 1) {
            *bank_sources++ = slot;
            *bank_status++ = 1;
        } else {
            *bank_sources++ = &controller_default_pad_state;
            *bank_status++ = 0;
        }
    }
    devices = controller_device_id_table;
    if (is_split_screen() != 0) {
        for (i = 0; i < 4; i++) {
            slot = get_pad_slot(*devices++);
            if (*slot->conn & 1) {
                *sources++ = slot;
                *status++ = 1;
            } else {
                *sources++ = &controller_default_pad_state;
                *status++ = 0;
            }
        }
    } else {
        count = 0;
        for (i = 0; i < 4; i++) {
            slot = get_pad_slot(*devices++);
            if (slot != NULL && (*slot->conn & 1)) {
                *sources = slot;
                count++;
                sources++;
                *status++ = 1;
            }
        }
        for (; count < 4; count++) {
            *sources++ = &controller_default_pad_state;
            *status++ = 0;
        }
    }
}

void reset_controller_input_state(void) {
    s32 i;
    s32 j;
    ControllerInputContext *pad;

    pad = controller_input_state.controllers;
    for (i = 0; i < 4; i++) {
        pad->buttons = controller_default_pad_state.held;
        pad->not_held = controller_default_pad_state.notHeld;
        pad->pressed_buttons = controller_default_pad_state.pressed;
        pad->released = controller_default_pad_state.released;
        pad->trigger_l = controller_default_pad_state.trigL;
        pad->trigger_r = controller_default_pad_state.trigR;
        pad->stick_x = controller_default_pad_state.stickX;
        pad->stick_y = controller_default_pad_state.stickY;
        pad->cstick_x = controller_default_pad_state.substickX;
        pad->cstick_y = controller_default_pad_state.substickY;
        pad->stick_angle = 0;
        pad->stick_magnitude = 0.0f;
        for (j = 0; j < 14; j++) {
            pad->hold_frames[j] = 0;
        }
        pad->held_with_sticks = 0;
        pad->pressed_with_sticks = 0;
        pad++;
    }
    copy_state__16TKeyBoardControlFPvPv(&controller_input_state.keyboard, controller_input_state.controllers);
    TKeyBoardControl::reset();
}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void copy_state__16TKeyBoardControlFPvPv(ControllerInputContext *controller_input_context, ControllerInputContext *arg1) {
  ControllerInputContext *new_var;
  ControllerInputContext *new_var2;
  ControllerHoldFrameBlock *s;
  ControllerHoldFrameBlock *d;
  controller_input_context->buttons = arg1->buttons;
  controller_input_context->not_held = arg1->not_held;
  controller_input_context->pressed_buttons = arg1->pressed_buttons;
  controller_input_context->released = arg1->released;
  controller_input_context->trigger_r = arg1->trigger_r;
  controller_input_context->trigger_l = arg1->trigger_l;
  controller_input_context->stick_x = arg1->stick_x;
  new_var = (new_var2 = controller_input_context);
  new_var2->stick_y = arg1->stick_y;
  controller_input_context->cstick_x = arg1->cstick_x;
  new_var2->cstick_y = arg1->cstick_y;
  new_var->stick_angle = arg1->stick_angle;
  new_var2->cstick_angle = arg1->cstick_angle;
  controller_input_context->stick_magnitude = arg1->stick_magnitude;
  controller_input_context->cstick_magnitude = arg1->cstick_magnitude;
  s = reinterpret_cast<ControllerHoldFrameBlock *>(arg1->hold_frames);
  d = reinterpret_cast<ControllerHoldFrameBlock *>((new_var = new_var2)->hold_frames);
  *d = *s;
  controller_input_context->held_with_sticks = arg1->held_with_sticks;
  new_var->pressed_with_sticks = arg1->pressed_with_sticks;
}

void TKeyBoardControl::init_pad_state() {
    s32 i;
    for (i = 0; i < 4; i++) {
        pad_recalibration_counters[i] = 0;
    }
    controller_input_state.sources[0] = get_pad_slot(0);
    controller_input_state.sources[1] = get_pad_slot(6);
    controller_input_state.sources[2] = get_pad_slot(0xC);
    controller_input_state.sources[3] = get_pad_slot(0x12);
    lbl_805D5D08 = 0;
    controller_reset_requested = 0;
    keyboard_reset_button_pressed = 0;
    for (i = 0; i < 4; i++) {
        pad_recalibration_hold_frames[i] = 0;
    }
    lbl_805D34C8 = 1;
}
s32 ControllerInputContext::poll_key_state() {
    s32 i;
    u8 n;
    s32 j;
    buttons = 0;
    pressed_buttons = 0;
    for (i = 0; i < 6; i++) {
        if (TKeyBoardControl::read_input((u8)keyboard_poll_key_codes[i]) != 0) {
            buttons |= TKeyBoardControl_key_bit_table[i];
        }
    }
    n = hardware_keyboard_state.get_pending_count();
    for (j = 0; j < n; j++) {
        accumulate_key_bits(hardware_keyboard_state.sub_8013239C(j), &pressed_buttons);
    }
    held_with_sticks = buttons;
    pressed_with_sticks = pressed_buttons;
    return 0;
}
}

#pragma pop

void accumulate_key_bits(s32 key, u32 *buttons) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (key == (s32)keyboard_poll_key_codes[i]) {
            *buttons |= TKeyBoardControl_key_bit_table[i];
        }
    }
}


extern "C" {

void fn_801A6A28(ControllerInputContext *pad, u32 mask, u32 previous) {
    pad->held_with_sticks |= mask;
    if (previous & mask) {
        pad->pressed_with_sticks &= ~mask;
        return;
    }
    pad->pressed_with_sticks |= mask;
}

void map_c_stick_to_buttons(ControllerInputContext *pad, s16 x, s16 y, s32 previous) {
    if (y > 0x30) {
        fn_801A6A28(pad, 0x08000000, previous);
    } else if (y < -0x30) {
        fn_801A6A28(pad, 0x04000000, previous);
    }
    if (x > 0x30) {
        fn_801A6A28(pad, 0x20000000, previous);
        return;
    }
    if (x < -0x30) {
        fn_801A6A28(pad, 0x10000000, previous);
    }
}

void map_main_stick_to_buttons(ControllerInputContext *pad, s16 x, s16 y, s32 previous) {
    if (y > 0x30) {
        fn_801A6A28(pad, 0x200000, previous);
    } else if (y < -0x30) {
        fn_801A6A28(pad, 0x100000, previous);
    }
    if (x > 0x30) {
        fn_801A6A28(pad, 0x800000, previous);
        return;
    }
    if (x < -0x30) {
        fn_801A6A28(pad, 0x400000, previous);
    }
}

}

void update_button_hold_counter(void *pad, void *counter, int mask, int held) {
    s16 frames = *(s16 *)counter;
    if (held & mask) {
        frames++;
    } else {
        frames = 0;
    }
    *(s16 *)counter = frames;
}

extern "C" {

void update_button_hold_counters(ControllerInputContext *pad) {
    update_button_hold_counter(pad, &pad->hold_frames[0], 0x10, pad->held_with_sticks);
    update_button_hold_counter(pad, &pad->hold_frames[1], 0x20, pad->held_with_sticks);
    update_button_hold_counter(pad, &pad->hold_frames[2], 0x40, pad->held_with_sticks);
    update_button_hold_counter(pad, &pad->hold_frames[3], 0x80, pad->held_with_sticks);
    update_button_hold_counter(pad, &pad->hold_frames[4], 0x100000, pad->held_with_sticks);
    update_button_hold_counter(pad, &pad->hold_frames[5], 0x200000, pad->held_with_sticks);
    update_button_hold_counter(pad, &pad->hold_frames[6], 0x400000, pad->held_with_sticks);
    update_button_hold_counter(pad, &pad->hold_frames[7], 0x800000, pad->held_with_sticks);
    update_button_hold_counter(pad, &pad->hold_frames[8], 0x04000000, pad->held_with_sticks);
    update_button_hold_counter(pad, &pad->hold_frames[9], 0x08000000, pad->held_with_sticks);
    update_button_hold_counter(pad, &pad->hold_frames[10], 0x10000000, pad->held_with_sticks);
    update_button_hold_counter(pad, &pad->hold_frames[11], 0x20000000, pad->held_with_sticks);
    update_button_hold_counter(pad, &pad->hold_frames[12], 0x20000, pad->held_with_sticks);
    update_button_hold_counter(pad, &pad->hold_frames[13], 0x10000, pad->held_with_sticks);
}

}

s32 TRaderMapCore::pack_color_bits(s32 input, s32 mask) {
    s32 bits = mask | ((mask << 0x10) & 0xF00000);
    return bits | ((bits << 0x16) & 0x3C000000);
}

extern "C" {

s32 TRaderMapCore__sub_801A6D00(ControllerInputContext *pad, s32 mask) {
    return (mask & 0xFFFFFF0F) | ((mask << 0x16) & 0x3C000000);
}

s32 pack_flags__13TRaderMapCoreFii(s32 pad, s32 mask) {
    return (mask & 0xFF0FFFFF) | ((mask << 0x16) & 0x3C000000);
}

s32 test_flags_04_packed(ControllerInputContext *pad, s32 mask) {
    return (pad->not_held & pack_flags__13TRaderMapCoreFii((saddr)pad, mask)) != 0;
}

s32 test_controller_flag_4c_color(ControllerInputContext *pad, s32 mask) {
    return (pad->pressed_with_sticks & TRaderMapCore::pack_color_bits((saddr)pad, mask)) != 0;
}

s32 test_pressed_buttons_packed(void *pad, s32 mask) {
    return (((ControllerInputContext *)pad)->pressed_with_sticks & pack_flags__13TRaderMapCoreFii((saddr)pad, mask)) != 0;
}

s32 test_previous_buttons_color(ControllerInputContext *pad, s32 mask) {
    return (pad->held_with_sticks & TRaderMapCore::pack_color_bits((saddr)pad, mask)) != 0;
}

s32 test_previous_buttons_remapped(ControllerInputContext *pad, s32 mask) {
    return (pad->held_with_sticks & TRaderMapCore__sub_801A6D00(pad, mask)) != 0;
}

s32 test_previous_buttons_packed(void *pad, s32 mask) {
    return (((ControllerInputContext *)pad)->held_with_sticks & pack_flags__13TRaderMapCoreFii((saddr)pad, mask)) != 0;
}

}

s32 TAdMultiPlyChrSelectGC::dispatch_draw_command(saddr input, s32 buttons, s32 delay, s32 period) {
    u32 mask = TRaderMapCore::pack_color_bits(input, buttons);
    return input_press_or_repeat((ControllerInputContext *)input, mask, delay, period);
}

s32 TRaderMapCore::apply_packed_flags(saddr input, s32 buttons, s32 delay, s32 period) {
    u32 mask = pack_flags__13TRaderMapCoreFii(input, buttons);
    return check_packed_flag_match((ControllerInputContext *)input, mask, delay, period);
}

extern "C" {

s32 test_buttons_press_or_repeat(ControllerInputContext *pad, s32 buttons, s32 delay, s32 period) {
    u32 mask = pack_flags__13TRaderMapCoreFii((saddr)pad, buttons);
    return input_press_or_repeat(pad, mask, delay, period);
}

s32 check_packed_flag_match(ControllerInputContext *pad, u32 mask, s32 delay, s32 period) {
    s32 result;
    s32 i;
    s32 elapsed;
    if (mask == 0) {
        return 0;
    }
    result = 0;
    for (i = 0; i < 14; i++) {
        if (mask & input_button_mask_table[i]) {
            elapsed = pad->hold_frames[i] - (delay + 1);
            if (elapsed >= 0 && elapsed % period == 0) {
                result |= 1;
            }
        }
    }
    return result;
}

s32 input_press_or_repeat(ControllerInputContext *pad, u32 mask, s32 delay, s32 period) {
    if (!mask) return 0;
    if (pad->pressed_with_sticks & mask) return 1;
    s32 result = 0;
    for (int i = 0; i < 14; ++i) {
        if (mask & input_button_mask_table[i]) {
            const s32 elapsed = pad->hold_frames[i] - (delay + 1);
            if (elapsed >= 0 && elapsed % period == 0) result |= 1;
        }
    }
    return result;
}

}

void ControllerInputContext::reset() {
    buttons = 0;
    not_held = -1;
    pressed_buttons = 0;
    released = 0;
    trigger_r = 0;
    trigger_l = 0;
    stick_x = 0;
    stick_y = 0;
    cstick_x = 0;
    cstick_y = 0;
    stick_angle = 0;
    cstick_angle = 0;
    stick_magnitude = 0.0f;
    cstick_magnitude = 0.0f;
}
