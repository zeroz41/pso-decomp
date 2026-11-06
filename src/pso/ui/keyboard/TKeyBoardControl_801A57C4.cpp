#include "types.h"
#include "pso/system/main_loop.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
#include "pso/ui/keyboard/TKeyBoardControl_801A57C4.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_801A5EC4_TKeyBoardControl__data_80506270 {
    s32 value;
    u8 remaining[0xAC];
};

struct Pad_801A5C4C {
    u8 pad0[0x20];
    u32 hold;
    u8 pad24[0x50 - 0x24];
};

struct Masks_801A5C4C { u32 m[4]; };

struct Src_801A5F1C {
    u8 pad0[8];
    u32 b0, b1, b2, b3;
    u16 trig_l;
    u16 trig_r;
    s16 sx, sy, cx, cy;
};

struct Pad_801A5F1C {
    u32 hold;
    u32 rel;
    u32 press;
    u32 up;
    u16 trig_l;
    u16 trig_r;
    s16 sx, sy, cx, cy;
    s32 ang0;
    s32 ang1;
    f32 mag0;
    f32 mag1;
    s16 rep[14];
    u32 prev_hold;
    u32 prev_press;
};

struct Set_801A5F1C {
    Src_801A5F1C *src[4];
    s32 status[4];
    Pad_801A5F1C pads[4];
};

// Per-port pad sources, status and processed pads, then the keyboard state block at +0x160.
struct ControllerInputState {
    Src_801A5F1C *src[4];
    s32 status[4];
    Pad_801A5F1C pads[4];
    u8 pad_160[0x50];
};

struct Obj_801A5F1C { u8 pad0[0x94]; s32 base[4]; };

extern "C" {
s32 is_split_screen();
s32 TKeyBoardControl__sub_80132650(void *);
s32 update_button_hold_counters(int);
extern RecoveredGlobal_801A5EC4_TKeyBoardControl__data_80506270 TKeyBoardControl__global_key_state;
extern ControllerInputState controller_input_state;
s32 TKeyBoardControl__sub_80132310(s32);
u8 TKeyBoardControl__sub_8013239C(void *, u8);
s32 DVDCheckDisk();
extern s32 lbl_805D49B4;
extern u8 lbl_805D5D09;
extern s8 keyboard_reset_button_pressed;
s32 func_801A5E54__Fv(void);
s32 PADRecalibrate(u32);
extern u32 pad_recalibration_counters[];
extern s8 pad_recalibration_hold_frames[4];
void update_pad_recalibration(void);
f64 atan2_float(f32, f32);
f32 newton_sqrtf(f32);
void bind_controller_devices(void);
void map_c_stick_to_buttons(u8 *arg0, s16 arg1, s16 arg2, s32 arg3);
void map_main_stick_to_buttons(u8 *arg0, s16 arg1, s16 arg2, s32 arg3);
}
void reset_system();
extern u8 controller_physical_port_bank[];
extern s32 lbl_805D34C8;
extern u8 *camera_ctrl_instance;
extern const f32 lbl_805DC0C0;
extern const f32 lbl_805DC0C4;
extern const f32 lbl_805DC0C8;

struct Kb_801A6910 {
    u32 f0;
    u8 pad4[4];
    u32 f8;
    u8 padC[0x48 - 0xC];
    u32 f48;
    u32 f4C;
};
struct Def_804C2308 { u32 w[13]; };
void accumulate_key_bits(s32 arg0, s32 *arg1);
Def_804C2308 controller_default_pad_state = { 0, 0, 0, 0xFFFFFFFF, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
u32 TKeyBoardControl_key_bit_table[6] = { 16, 32, 64, 128, 4, 2 };
u32 keyboard_poll_key_codes[6] = { 94, 93, 92, 95, 97, 76 };
s32 controller_device_id_table[4] = { 0, 6, 12, 18 };

extern "C" {
s32 lbl_805D34C8 = 1;
ControllerInputState controller_input_state;
u8 controller_physical_port_bank[0x1B0];
u32 pad_recalibration_counters[4];
}


extern "C" {
s32 OSGetResetButtonState();
s32 TKeyBoardControl__sub_801323C8(void *, void *);

void TKeyBoardControl::reset() { lbl_805D5D09 = 0; }


s32 TKeyBoardControl::any_pad_input_active() {
    s32 i;
    for (i = 0; i < 4; i++) {
        Src_801A5F1C *p = controller_input_state.src[i];
        if (p->b2 != 0 || p->trig_l >= 10 || p->trig_r >= 10 || p->sx >= 10 || p->sx <= -10 || p->sy >= 10 || p->sy <= -10) {
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

void TKeyBoardControl__sub_801A58B0(void) {
    TKeyBoardControl__sub_801321B4((s32) &TKeyBoardControl__global_key_state.value);
}

void TKeyBoardControl__sub_801A58D8(void) {
    TKeyBoardControl__sub_80132310((s32) &TKeyBoardControl__global_key_state.value);
}

s32 TKeyBoardControl::check_and_read(s32 arg0) {
    if (TKeyBoardControl::check_input_ready((s32)&TKeyBoardControl__global_key_state) != 0) {
        return TKeyBoardControl::is_key_down(arg0);
    }
    return 0;
}

s32 TKeyBoardControl::read_input(s32 arg0) {
    if (TKeyBoardControl::check_input_ready((s32)&TKeyBoardControl__global_key_state) != 0) {
        return ((s32 (*)(s32))update_state_from_input__16TKeyBoardControlFPv)(arg0);
    }
    return 0;
}

s32 TKeyBoardControl::is_key_down(s32 arg0) {
    s32 i;
    s32 n;
    n = ((TKeyBoardControl *)&TKeyBoardControl__global_key_state)->get_key_state_2();
    for (i = 0; i < n; i++) {
        if ((u8)arg0 == TKeyBoardControl__sub_8013239C(&TKeyBoardControl__global_key_state, i)) {
            return 1;
        }
    }
    return 0;
}

void update_state_from_input__16TKeyBoardControlFPv(void *arg0) {
    TKeyBoardControl__sub_801323C8(&TKeyBoardControl__global_key_state, arg0);
}

extern s32 actor_frame_tick;

s32 TKeyBoardControl::check_input_angle() {
    s32 temp_r4_2;
    void *temp_r4;
    s32 temp_r5;
    u16 temp_r0;

    temp_r4 = *(void * *)&this->m_prev;
    if (temp_r4 == NULL) {
        return 0;
    }
    if (*(f32 *)((s8 *)temp_r4 + 0x24) < 0.5f) {
        return 0;
    }
    temp_r5 = *(s32 *)&this->m_name;
    *(s32 *)&this->m_name = *(s32 *)((s8 *)temp_r4 + 0x1C);
    temp_r0 = temp_r5 - *(s32 *)&this->m_name;
    if (((s32) temp_r0 > 0x5000) && ((s32) temp_r0 < 0xB000)) {
        temp_r4_2 = *(s32 *)&this->m_flags;
        *(s32 *)&this->m_flags = (s32) actor_frame_tick;
        if ((s32) (*(s32 *)&this->m_flags - temp_r4_2) < 8) {
            return 1;
        }
    }
    return 0;
}
}

void init_stick_escape_detector(void *arg0, void *arg1) {
    if (arg1 != NULL) {
        *(void **)((s8 *)arg0 + 8) = arg1;
        *(s32 *)((s8 *)arg0 + 0) = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)arg0 + 8)) + 0x1C);
        *(s32 *)((s8 *)arg0 + 4) = (s32) actor_frame_tick;
    }
}

void TObjPlayer::reset_fields() { *(s32*)((char*)this + 0x0) = 0; *(s32*)((char*)this + 0x4) = 0; *(s32*)((char*)this + 0x8) = 0; }

s32 TKeyBoardControl::get_ascii_key() {
  short new_var;
  s32 temp_r3;
  s32 var_r3;
  u8 temp_r31;
  if (((TKeyBoardControl *)(&TKeyBoardControl__global_key_state.value))->get_key_state_2() == 0)
  {
    return 0;
  }
  var_r3 = TKeyBoardControl__sub_8013239C((void *) (&TKeyBoardControl__global_key_state.value), 0);
  temp_r31 = var_r3;
  temp_r3 = TKeyBoardControl__sub_80132310((s32) (&TKeyBoardControl__global_key_state.value));
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
        if ((((Pad_801A5C4C *)&controller_input_state)[i].hold & 0x40A) == 0x40A) {
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
        if ((((Pad_801A5C4C *)&controller_input_state)[i].hold & 0x608) == 0x608) {
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
typedef char RecoveredGlobal_801A5EC4_TKeyBoardControl__data_80506270_size[sizeof(RecoveredGlobal_801A5EC4_TKeyBoardControl__data_80506270) == 0xB0 ? 1 : -1];
typedef char ControllerInputState_size[sizeof(ControllerInputState) == 0x1B0 ? 1 : -1];
void TKeyBoardControl::update_input_frame() {
    u8 *key_board_control;
    TKeyBoardControl__sub_80132650((void *) (&TKeyBoardControl__global_key_state.value));
    if (is_split_screen() == 0) {
        key_board_control = controller_input_state.pad_160;
        ((TKeyBoardControl *)key_board_control)->poll_key_state();
        update_button_hold_counters((int)key_board_control);
    }
}
#pragma push
#pragma fp_contract on
void controller_stuff(void) {
    s32 i;
    Src_801A5F1C **pp;
    Set_801A5F1C *set;
    Pad_801A5F1C *pad;
    u32 old;
    s32 k;
    s32 j;
    Src_801A5F1C *src;
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
                pad = ((Set_801A5F1C *)&controller_input_state)->pads;
                pp = (Src_801A5F1C **)&controller_input_state;
                set = (Set_801A5F1C *)&controller_input_state;
            } else {
                pad = ((Set_801A5F1C *)controller_physical_port_bank)->pads;
                pp = (Src_801A5F1C **)controller_physical_port_bank;
                set = (Set_801A5F1C *)controller_physical_port_bank;
            }
            for (i = 0; i < 4; pad++, i++) {
                src = *pp++;
                if (set->status[i] == 1) {
                    old = pad->hold;
                    pad->hold = src->b0;
                    pad->rel = src->b1;
                    pad->press = src->b2;
                    pad->up = src->b3;
                    pad->trig_r = src->trig_r;
                    pad->trig_l = src->trig_l;
                    fx = src->sx;
                    pad->sx = fx;
                    fy = src->sy;
                    pad->sy = fy;
                    gx = src->cx;
                    pad->cx = gx;
                    gy = -src->cy;
                    pad->cy = gy;
                    if ((-31.0f) < fx && fx <= 31.0f) {
                        fx = lbl_805DC0C0;
                        pad->sx = 0;
                    }
                    if ((-31.0f) < fy && fy <= 31.0f) {
                        fy = lbl_805DC0C0;
                        pad->sy = 0;
                    }
                    if ((-31.0f) < gx && gx <= 31.0f) {
                        gx = lbl_805DC0C0;
                        pad->cx = 0;
                    }
                    if ((-31.0f) < gy && gy <= 31.0f) {
                        gy = lbl_805DC0C0;
                        pad->cy = 0;
                    }
                    m = newton_sqrtf(fx * fx + fy * fy);
                    if (lbl_805DC0C0 != m) {
                        m *= lbl_805DC0C4;
                    }
                    if (m > lbl_805DC0C8) {
                        m = lbl_805DC0C8;
                    }
                    pad->mag0 = m;
                    m = newton_sqrtf(gx * gx + gy * gy);
                    if (lbl_805DC0C0 != m) {
                        m *= lbl_805DC0C4;
                    }
                    if (m > lbl_805DC0C8) {
                        m = lbl_805DC0C8;
                    }
                    pad->mag1 = m;
                    pad->hold &= ~0x30000;
                    pad->rel &= ~0x30000;
                    pad->press &= ~0x30000;
                    pad->up &= ~0x30000;
                    if (pad->trig_l > 0x70) {
                        pad->hold |= 0x10000;
                        if (!(old & 0x10000)) {
                            pad->press |= 0x10000;
                        }
                    } else {
                        pad->rel |= 0x10000;
                        if (old & 0x10000) {
                            pad->up |= 0x10000;
                        }
                    }
                    if (pad->trig_r > 0x70) {
                        pad->hold |= 0x20000;
                        if (!(old & 0x20000)) {
                            pad->press |= 0x20000;
                        }
                    } else {
                        pad->rel |= 0x20000;
                        if (old & 0x20000) {
                            pad->up |= 0x20000;
                        }
                    }
                    old = pad->prev_hold;
                    pad->prev_hold = pad->hold &= 0xC30FFFFF;
                    pad->prev_press = pad->press &= 0xC30FFFFF;
                    map_main_stick_to_buttons((u8 *)pad, pad->sx, pad->sy, old);
                    map_c_stick_to_buttons((u8 *)pad, pad->cx, pad->cy, old);
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
                    pad->ang0 = (u16)a;
                    pad->ang1 = (u16)b;
                    update_button_hold_counters((int)pad);
                } else {
                    pad->hold = (*(Src_801A5F1C *)&controller_default_pad_state).b0;
                    pad->rel = (*(Src_801A5F1C *)&controller_default_pad_state).b1;
                    pad->press = (*(Src_801A5F1C *)&controller_default_pad_state).b2;
                    pad->up = (*(Src_801A5F1C *)&controller_default_pad_state).b3;
                    pad->trig_r = (*(Src_801A5F1C *)&controller_default_pad_state).trig_r;
                    pad->trig_l = (*(Src_801A5F1C *)&controller_default_pad_state).trig_l;
                    pad->sx = (*(Src_801A5F1C *)&controller_default_pad_state).sx;
                    pad->sy = (*(Src_801A5F1C *)&controller_default_pad_state).sy;
                    pad->cx = (*(Src_801A5F1C *)&controller_default_pad_state).cx;
                    pad->cy = (*(Src_801A5F1C *)&controller_default_pad_state).cy;
                    pad->ang0 = 0;
                    pad->mag0 = lbl_805DC0C0;
                    for (j = 0; j < 14; j++) {
                        pad->rep[j] = 0;
                    }
                    pad->prev_hold = 0;
                    pad->prev_press = 0;
                }
            }
        }
        update_pad_recalibration();
    }
}

#pragma pop

#pragma push
#define controller_input_state ((s32 *)&controller_input_state)
#define controller_physical_port_bank ((s32 *)controller_physical_port_bank)
#define pad_recalibration_counters ((s32 *)pad_recalibration_counters)
#define TKeyBoardControl__global_key_state ((u8 *)&TKeyBoardControl__global_key_state)

struct Sub_801A67A4
{
  u32 w[7];
};

struct Rec_801A67A4
{
  s32 f0;
  s32 f4;
  s32 f8;
  s32 fC;
  u16 f10;
  u16 f12;
  s16 f14;
  s16 f16;
  s16 f18;
  s16 f1A;
  s32 f1C;
  s32 f20;
  f32 f24;
  f32 f28;
  Sub_801A67A4 f2C;
  s32 f48;
  s32 f4C;
};

struct Src_801A66B8 {
    u8 pad0[8];
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    u16 f18;
    u16 f1A;
    s16 f1C;
    s16 f1E;
    s16 f20;
    s16 f22;
};

struct Pad_801A66B8 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    u16 f10;
    u16 f12;
    s16 f14;
    s16 f16;
    s16 f18;
    s16 f1A;
    s32 f1C;
    u8 pad20[4];
    f32 f24;
    u8 pad28[4];
    s16 f2C[14];
    s32 f48;
    s32 f4C;
};

struct Ctl_801A6510 {
    u8 pad0[0x30];
    u32 *f30;
};

extern "C" {
s32 TKeyBoardControl__sub_803DEB74(int);
extern s8 lbl_805D5D08;
s32 read_input__16TKeyBoardControlFl(u8);
void copy_state__16TKeyBoardControlFPvPv(Rec_801A67A4 *arg0, Rec_801A67A4 *arg1);
s32 is_split_screen(void);

void bind_controller_devices(void) {
    Ctl_801A6510 *p;
    void **pb;
    s32 *fb;
    void **pa;
    s32 i;
    s32 *ids;
    s32 *fa;
    s32 n;
    pb = (void **)controller_input_state;
    pa = (void **)controller_physical_port_bank;
    fb = &controller_input_state[4];
    ids = controller_device_id_table;
    fa = &controller_physical_port_bank[4];
    for (i = 0; i < 4; i++) {
        p = (Ctl_801A6510 *)TKeyBoardControl__sub_803DEB74(*ids++);
        if (*p->f30 & 1) {
            *pa++ = p;
            *fa++ = 1;
        } else {
            *pa++ = (void *)&controller_default_pad_state;
            *fa++ = 0;
        }
    }
    ids = controller_device_id_table;
    if (is_split_screen() != 0) {
        for (i = 0; i < 4; i++) {
            p = (Ctl_801A6510 *)TKeyBoardControl__sub_803DEB74(*ids++);
            if (*p->f30 & 1) {
                *pb++ = p;
                *fb++ = 1;
            } else {
                *pb++ = (void *)&controller_default_pad_state;
                *fb++ = 0;
            }
        }
    } else {
        n = 0;
        for (i = 0; i < 4; i++) {
            p = (Ctl_801A6510 *)TKeyBoardControl__sub_803DEB74(*ids++);
            if (p != NULL && (*p->f30 & 1)) {
                *pb = p;
                n++;
                pb++;
                *fb++ = 1;
            }
        }
        for (; n < 4; n++) {
            *pb++ = (void *)&controller_default_pad_state;
            *fb++ = 0;
        }
    }
}

void reset_controller_input_state(void) {
    s32 i;
    s32 j;
    Pad_801A66B8 *p;

    p = (Pad_801A66B8 *)((u8 *)controller_input_state + 0x20);
    for (i = 0; i < 4; i++) {
        p->f0 = ((Src_801A66B8 *)&controller_default_pad_state)[0].f8;
        p->f4 = ((Src_801A66B8 *)&controller_default_pad_state)[0].fC;
        p->f8 = ((Src_801A66B8 *)&controller_default_pad_state)[0].f10;
        p->fC = ((Src_801A66B8 *)&controller_default_pad_state)[0].f14;
        p->f12 = ((Src_801A66B8 *)&controller_default_pad_state)[0].f1A;
        p->f10 = ((Src_801A66B8 *)&controller_default_pad_state)[0].f18;
        p->f14 = ((Src_801A66B8 *)&controller_default_pad_state)[0].f1C;
        p->f16 = ((Src_801A66B8 *)&controller_default_pad_state)[0].f1E;
        p->f18 = ((Src_801A66B8 *)&controller_default_pad_state)[0].f20;
        p->f1A = ((Src_801A66B8 *)&controller_default_pad_state)[0].f22;
        p->f1C = 0;
        p->f24 = lbl_805DC0C0;
        for (j = 0; j < 14; j++) {
            p->f2C[j] = 0;
        }
        p->f48 = 0;
        p->f4C = 0;
        p++;
    }
    copy_state__16TKeyBoardControlFPvPv((Rec_801A67A4 *)&controller_input_state[0x58], (Rec_801A67A4 *)((u8 *)controller_input_state + 0x20));
    TKeyBoardControl::reset();
}

typedef struct Rec_801A67A4 Rec_801A67A4;
typedef struct Sub_801A67A4 Sub_801A67A4;
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void copy_state__16TKeyBoardControlFPvPv(Rec_801A67A4 *arg0, Rec_801A67A4 *arg1) {
  Rec_801A67A4 *new_var;
  Rec_801A67A4 *new_var2;
  Sub_801A67A4 *s;
  Sub_801A67A4 *d;
  arg0->f0 = arg1->f0;
  arg0->f4 = arg1->f4;
  arg0->f8 = arg1->f8;
  arg0->fC = arg1->fC;
  arg0->f10 = arg1->f10;
  arg0->f12 = arg1->f12;
  arg0->f14 = arg1->f14;
  new_var = (new_var2 = arg0);
  new_var2->f16 = arg1->f16;
  arg0->f18 = arg1->f18;
  new_var2->f1A = arg1->f1A;
  new_var->f1C = arg1->f1C;
  new_var2->f20 = arg1->f20;
  arg0->f24 = arg1->f24;
  arg0->f28 = arg1->f28;
  s = &arg1->f2C;
  d = &(new_var = new_var2)->f2C;
  *d = *s;
  arg0->f48 = arg1->f48;
  new_var->f4C = arg1->f4C;
}

void TKeyBoardControl::init_pad_state() {
    s32 i;
    for (i = 0; i < 4; i++) {
        pad_recalibration_counters[i] = 0;
    }
    controller_input_state[0] = TKeyBoardControl__sub_803DEB74(0);
    controller_input_state[1] = TKeyBoardControl__sub_803DEB74(6);
    controller_input_state[2] = TKeyBoardControl__sub_803DEB74(0xC);
    controller_input_state[3] = TKeyBoardControl__sub_803DEB74(0x12);
    lbl_805D5D08 = 0;
    (*(s8 *)&lbl_805D5D09) = 0;
    keyboard_reset_button_pressed = 0;
    for (i = 0; i < 4; i++) {
        pad_recalibration_hold_frames[i] = 0;
    }
    lbl_805D34C8 = 1;
}
s32 TKeyBoardControl::poll_key_state() {
    Kb_801A6910 *self = (Kb_801A6910 *)this;
    s32 i;
    u8 n;
    s32 j;
    self->f0 = 0;
    self->f8 = 0;
    for (i = 0; i < 6; i++) {
        if (read_input__16TKeyBoardControlFl(keyboard_poll_key_codes[i]) != 0) {
            self->f0 |= TKeyBoardControl_key_bit_table[i];
        }
    }
    n = ((TKeyBoardControl *)TKeyBoardControl__global_key_state)->get_key_state_2();
    for (j = 0; j < n; j++) {
        ((void (*)(u8, u32 *))accumulate_key_bits)(((s32 (*)(void *, u8))TKeyBoardControl__sub_8013239C)(TKeyBoardControl__global_key_state, j), &self->f8);
    }
    self->f48 = self->f0;
    self->f4C = self->f8;
    return 0;
}
}

#undef controller_input_state
#undef controller_physical_port_bank
#undef pad_recalibration_counters
#undef TKeyBoardControl__global_key_state
#pragma pop

void accumulate_key_bits(s32 arg0, s32 *arg1) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (arg0 == ((s32 *)keyboard_poll_key_codes)[i]) {
            *arg1 |= ((s32 *)TKeyBoardControl_key_bit_table)[i];
        }
    }
}
