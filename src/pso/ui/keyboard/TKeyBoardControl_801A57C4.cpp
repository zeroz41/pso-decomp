#include "types.h"
#include "pso/system/main_loop.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/unk/text_801A6A5C.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
#include "pso/ui/keyboard/TKeyBoardControl_801A57C4.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/player/TObjPlayer.h"

const u32 input_button_mask_table[14] = {
    0x10, 0x20, 0x40, 0x80, 0x100000, 0x200000, 0x400000, 0x800000,
    0x4000000, 0x8000000, 0x10000000, 0x20000000, 0x20000, 0x10000,
};

struct Masks_801A5C4C { u32 m[4]; };

struct Obj_801A5F1C { u8 pad0[0x94]; s32 base[4]; };

s8 lbl_805D5D08;
u8 lbl_805D5D09;
s8 keyboard_reset_button_pressed;
s8 pad_recalibration_hold_frames[4];
extern "C" {
s32 is_split_screen();
s32 DVDCheckDisk();
extern s32 lbl_805D49B4;
s32 func_801A5E54__Fv(void);
s32 PADRecalibrate(u32);
extern u32 pad_recalibration_counters[];
void update_pad_recalibration(void);
f64 atan2_float(f32, f32);
f32 newton_sqrtf(f32);
void bind_controller_devices(void);
}
void reset_system();
extern u8 *camera_ctrl_instance;
extern const f32 lbl_805DC0C0;
extern const f32 lbl_805DC0C4;
extern const f32 lbl_805DC0C8;

void accumulate_key_bits(s32 key, u32 *buttons);
PadSlot controller_default_pad_state = {0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, {0}, NULL};
u32 TKeyBoardControl_key_bit_table[6] = { 16, 32, 64, 128, 4, 2 };
u32 keyboard_poll_key_codes[6] = { 94, 93, 92, 95, 97, 76 };
s32 controller_device_id_table[4] = { 0, 6, 12, 18 };

extern "C" {
s32 lbl_805D34C8 = 1;
ControllerInputState controller_input_state;
ControllerInputState controller_physical_port_bank;
u32 pad_recalibration_counters[4];
s32 OSGetResetButtonState();

void TKeyBoardControl::reset() { lbl_805D5D09 = 0; }


s32 TKeyBoardControl::any_pad_input_active() {
    s32 i;
    for (i = 0; i < 4; i++) {
        PadSlot *p = controller_input_state.sources[i];
        if ((u32)p->pressed != 0 || p->trigR >= 10 || p->trigL >= 10 ||
            p->stickX >= 10 || p->stickX <= -10 || p->stickY >= 10 || p->stickY <= -10) {
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

extern s32 actor_frame_tick;

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
    Masks_801A5C4C masks = { 0x80000000, 0x40000000, 0x20000000, 0x10000000 };
    for (i = 0; i < 4; i++) {
        if ((controller_input_state.controllers[i].buttons & 0x40A) == 0x40A) {
            pad_recalibration_hold_frames[i]++;
            if (15.0 == (f64)pad_recalibration_hold_frames[i]) {
                lbl_805D5D09 = 1;
                for (j = 0; j < 4; j++) {
                    PADRecalibrate(masks.m[j]);
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
                PADRecalibrate(masks.m[i]);
            }
        } else {
            pad_recalibration_counters[i] = 0;
        }
    }
    if (TKeyBoardControl::check_reset_button() != 0) {
        lbl_805D5D09 = 1;
        for (j = 0; j < 4; j++) {
            PADRecalibrate(masks.m[j]);
        }
    }
}

s32 func_801A5E54__Fv(void) {
    if ((DVDCheckDisk() == 0) && (TKeyBoardControl::check_reset_button() != 0)) {
        reset_system();
    }
    return (lbl_805D49B4 != 0) ? 0 : lbl_805D5D09;
}

s32 TKeyBoardControl::read_key_checked(u8 arg0) {
    return TKeyBoardControl::check_and_read((s32)(arg0));
}
void TKeyBoardControl::update_input_frame() {
    ControllerInputContext *key_board_control;
    hardware_keyboard_state.sub_80132650();
    if (is_split_screen() == 0) {
        key_board_control = &controller_input_state.keyboard;
        key_board_control->poll_key_state();
        update_button_hold_counters(key_board_control);
    }
}
#pragma push
#pragma fp_contract on
void controller_stuff(void) {
    s32 i;
    PadSlot **pp;
    ControllerInputState *set;
    ControllerInputContext *pad;
    u32 old;
    s32 k;
    s32 j;
    PadSlot *src;
    s32 a;
    s32 b;
    f32 fx;
    f32 fy;
    f32 gx;
    f32 gy;
    f32 m;
    if (lbl_805D34C8 != 0) {
        bind_controller_devices();
        for (k = 0; k < 2; k++) {
            if (k == 0) {
                pad = controller_input_state.controllers;
                pp = controller_input_state.sources;
                set = &controller_input_state;
            } else {
                pad = controller_physical_port_bank.controllers;
                pp = controller_physical_port_bank.sources;
                set = &controller_physical_port_bank;
            }
            for (i = 0; i < 4; pad++, i++) {
                src = *pp++;
                if (set->source_status[i] == 1) {
                    old = pad->buttons;
                    pad->buttons = src->held;
                    pad->flags_04 = src->notHeld;
                    pad->pressed_buttons = src->pressed;
                    pad->released = src->released;
                    // The processed record reads the two raw trigger fields in reverse order.
                    pad->trigger_right = src->trigL;
                    pad->trigger_left = src->trigR;
                    fx = src->stickX;
                    pad->stick_x = fx;
                    fy = src->stickY;
                    pad->stick_y = fy;
                    gx = src->substickX;
                    pad->cstick_x = gx;
                    gy = -src->substickY;
                    pad->cstick_y = gy;
                    if ((-31.0f) < fx && fx <= 31.0f) {
                        fx = lbl_805DC0C0;
                        pad->stick_x = 0;
                    }
                    if ((-31.0f) < fy && fy <= 31.0f) {
                        fy = lbl_805DC0C0;
                        pad->stick_y = 0;
                    }
                    if ((-31.0f) < gx && gx <= 31.0f) {
                        gx = lbl_805DC0C0;
                        pad->cstick_x = 0;
                    }
                    if ((-31.0f) < gy && gy <= 31.0f) {
                        gy = lbl_805DC0C0;
                        pad->cstick_y = 0;
                    }
                    m = newton_sqrtf(fx * fx + fy * fy);
                    if (lbl_805DC0C0 != m) {
                        m *= lbl_805DC0C4;
                    }
                    if (m > lbl_805DC0C8) {
                        m = lbl_805DC0C8;
                    }
                    pad->stick_magnitude = m;
                    m = newton_sqrtf(gx * gx + gy * gy);
                    if (lbl_805DC0C0 != m) {
                        m *= lbl_805DC0C4;
                    }
                    if (m > lbl_805DC0C8) {
                        m = lbl_805DC0C8;
                    }
                    pad->cstick_magnitude = m;
                    pad->buttons &= ~0x30000;
                    pad->flags_04 &= ~0x30000;
                    pad->pressed_buttons &= ~0x30000;
                    pad->released &= ~0x30000;
                    if (pad->trigger_left > 0x70) {
                        pad->buttons |= 0x10000;
                        if (!(old & 0x10000)) {
                            pad->pressed_buttons |= 0x10000;
                        }
                    } else {
                        pad->flags_04 |= 0x10000;
                        if (old & 0x10000) {
                            pad->released |= 0x10000;
                        }
                    }
                    if (pad->trigger_right > 0x70) {
                        pad->buttons |= 0x20000;
                        if (!(old & 0x20000)) {
                            pad->pressed_buttons |= 0x20000;
                        }
                    } else {
                        pad->flags_04 |= 0x20000;
                        if (old & 0x20000) {
                            pad->released |= 0x20000;
                        }
                    }
                    old = pad->previous_buttons;
                    pad->previous_buttons = pad->buttons &= 0xC30FFFFF;
                    pad->flags_4c = pad->pressed_buttons &= 0xC30FFFFF;
                    map_main_stick_to_buttons(reinterpret_cast<u8 *>(pad), pad->stick_x, pad->stick_y, old);
                    map_c_stick_to_buttons(reinterpret_cast<u8 *>(pad), pad->cstick_x, pad->cstick_y, old);
                    if (camera_ctrl_instance != NULL) {
                        if (is_split_screen() != 0) {
                            a = ((Obj_801A5F1C *)camera_ctrl_instance)->base[i] + (s32)(10430.38043493439 * atan2_float(fx, fy));
                            b = ((Obj_801A5F1C *)camera_ctrl_instance)->base[i] + (s32)(10430.38043493439 * atan2_float(gx, gy));
                        } else {
                            a = *(s32 *)(camera_ctrl_instance + 0x94) + (s32)(10430.38043493439 * atan2_float(fx, fy));
                            b = *(s32 *)(camera_ctrl_instance + 0x94) + (s32)(10430.38043493439 * atan2_float(gx, gy));
                        }
                    } else {
                        a = (s32)(10430.38043493439 * atan2_float(fx, fy));
                        b = (s32)(10430.38043493439 * atan2_float(gx, gy));
                    }
                    pad->stick_angle = (u16)a;
                    pad->cstick_angle = (u16)b;
                    update_button_hold_counters(pad);
                } else {
                    pad->buttons = controller_default_pad_state.held;
                    pad->flags_04 = controller_default_pad_state.notHeld;
                    pad->pressed_buttons = controller_default_pad_state.pressed;
                    pad->released = controller_default_pad_state.released;
                    pad->trigger_right = controller_default_pad_state.trigL;
                    pad->trigger_left = controller_default_pad_state.trigR;
                    pad->stick_x = controller_default_pad_state.stickX;
                    pad->stick_y = controller_default_pad_state.stickY;
                    pad->cstick_x = controller_default_pad_state.substickX;
                    pad->cstick_y = controller_default_pad_state.substickY;
                    pad->stick_angle = 0;
                    pad->stick_magnitude = lbl_805DC0C0;
                    for (j = 0; j < 14; j++) {
                        pad->hold_counters.frames[j] = 0;
                    }
                    pad->previous_buttons = 0;
                    pad->flags_4c = 0;
                }
            }
        }
        update_pad_recalibration();
    }
}

#pragma pop

#pragma push
extern "C" {
void copy_state__16TKeyBoardControlFPvPv(ControllerInputContext *arg0, ControllerInputContext *arg1);
s32 is_split_screen(void);

void bind_controller_devices(void) {
    PadSlot *p;
    PadSlot **pb;
    s32 *fb;
    PadSlot **pa;
    s32 i;
    s32 *ids;
    s32 *fa;
    s32 n;
    pb = controller_input_state.sources;
    pa = controller_physical_port_bank.sources;
    fb = controller_input_state.source_status;
    ids = controller_device_id_table;
    fa = controller_physical_port_bank.source_status;
    for (i = 0; i < 4; i++) {
        p = (PadSlot *)TKeyBoardControl__sub_803DEB74(*ids++);
        if (*p->conn & 1) {
            *pa++ = p;
            *fa++ = 1;
        } else {
            *pa++ = &controller_default_pad_state;
            *fa++ = 0;
        }
    }
    ids = controller_device_id_table;
    if (is_split_screen() != 0) {
        for (i = 0; i < 4; i++) {
            p = (PadSlot *)TKeyBoardControl__sub_803DEB74(*ids++);
            if (*p->conn & 1) {
                *pb++ = p;
                *fb++ = 1;
            } else {
                *pb++ = &controller_default_pad_state;
                *fb++ = 0;
            }
        }
    } else {
        n = 0;
        for (i = 0; i < 4; i++) {
            p = (PadSlot *)TKeyBoardControl__sub_803DEB74(*ids++);
            if (p != NULL && (*p->conn & 1)) {
                *pb = p;
                n++;
                pb++;
                *fb++ = 1;
            }
        }
        for (; n < 4; n++) {
            *pb++ = &controller_default_pad_state;
            *fb++ = 0;
        }
    }
}

void reset_controller_input_state(void) {
    s32 i;
    s32 j;
    ControllerInputContext *p;

    p = controller_input_state.controllers;
    for (i = 0; i < 4; i++) {
        p->buttons = controller_default_pad_state.held;
        p->flags_04 = controller_default_pad_state.notHeld;
        p->pressed_buttons = controller_default_pad_state.pressed;
        p->released = controller_default_pad_state.released;
        p->trigger_right = controller_default_pad_state.trigL;
        p->trigger_left = controller_default_pad_state.trigR;
        p->stick_x = controller_default_pad_state.stickX;
        p->stick_y = controller_default_pad_state.stickY;
        p->cstick_x = controller_default_pad_state.substickX;
        p->cstick_y = controller_default_pad_state.substickY;
        p->stick_angle = 0;
        p->stick_magnitude = lbl_805DC0C0;
        for (j = 0; j < 14; j++) {
            p->hold_counters.frames[j] = 0;
        }
        p->previous_buttons = 0;
        p->flags_4c = 0;
        p++;
    }
    copy_state__16TKeyBoardControlFPvPv(&controller_input_state.keyboard, controller_input_state.controllers);
    TKeyBoardControl::reset();
}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void copy_state__16TKeyBoardControlFPvPv(ControllerInputContext *arg0, ControllerInputContext *arg1) {
  ControllerInputContext *new_var;
  ControllerInputContext *new_var2;
  ControllerButtonHoldCounters *s;
  ControllerButtonHoldCounters *d;
  arg0->buttons = arg1->buttons;
  arg0->flags_04 = arg1->flags_04;
  arg0->pressed_buttons = arg1->pressed_buttons;
  arg0->released = arg1->released;
  arg0->trigger_left = arg1->trigger_left;
  arg0->trigger_right = arg1->trigger_right;
  arg0->stick_x = arg1->stick_x;
  new_var = (new_var2 = arg0);
  new_var2->stick_y = arg1->stick_y;
  arg0->cstick_x = arg1->cstick_x;
  new_var2->cstick_y = arg1->cstick_y;
  new_var->stick_angle = arg1->stick_angle;
  new_var2->cstick_angle = arg1->cstick_angle;
  arg0->stick_magnitude = arg1->stick_magnitude;
  arg0->cstick_magnitude = arg1->cstick_magnitude;
  s = &arg1->hold_counters;
  d = &(new_var = new_var2)->hold_counters;
  *d = *s;
  arg0->previous_buttons = arg1->previous_buttons;
  new_var->flags_4c = arg1->flags_4c;
}

void TKeyBoardControl::init_pad_state() {
    s32 i;
    for (i = 0; i < 4; i++) {
        pad_recalibration_counters[i] = 0;
    }
    controller_input_state.sources[0] = (PadSlot *)TKeyBoardControl__sub_803DEB74(0);
    controller_input_state.sources[1] = (PadSlot *)TKeyBoardControl__sub_803DEB74(6);
    controller_input_state.sources[2] = (PadSlot *)TKeyBoardControl__sub_803DEB74(0xC);
    controller_input_state.sources[3] = (PadSlot *)TKeyBoardControl__sub_803DEB74(0x12);
    lbl_805D5D08 = 0;
    (*(s8 *)&lbl_805D5D09) = 0;
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
    previous_buttons = buttons;
    flags_4c = pressed_buttons;
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
