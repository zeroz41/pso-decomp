#include "types.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/main_loop.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/KeyboardInputQueries.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowChoiceSetting.h"

const u32 input_button_mask_table[14] = {
    0x10, 0x20, 0x40, 0x80, 0x100000, 0x200000, 0x400000, 0x800000,
    0x4000000, 0x8000000, 0x10000000, 0x20000000, 0x20000, 0x10000,
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
ControllerInputState controller_physical_port_bank;
u32 pad_recalibration_counters[4];
s32 OSGetResetButtonState();

void TKeyBoardControl::reset() { lbl_805D5D09 = 0; }


s32 TKeyBoardControl::any_pad_input_active() {
    s32 i;
    for (i = 0; i < 4; i++) {
        Src_801A5F1C *p = (Src_801A5F1C *)controller_input_state.sources[i];
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

s32 TKeyBoardControl::read_input(s32 arg0) {
    if (hardware_keyboard_state.check_input_ready() != 0) {
        return ((s32 (*)(s32))update_state_from_input__16TKeyBoardControlFPv)(arg0);
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

void update_state_from_input__16TKeyBoardControlFPv(u8 key) {
    hardware_keyboard_state.sub_801323C8(key);
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
void TKeyBoardControl::update_input_frame() {
    u8 *key_board_control;
    hardware_keyboard_state.sub_80132650();
    if (is_split_screen() == 0) {
        key_board_control = (u8 *)&controller_input_state.keyboard;
        ((TKeyBoardControl *)key_board_control)->poll_key_state();
        update_button_hold_counters((ControllerInputContext *)key_board_control);
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
                pad = ((Set_801A5F1C *)&controller_physical_port_bank)->pads;
                pp = (Src_801A5F1C **)&controller_physical_port_bank;
                set = (Set_801A5F1C *)&controller_physical_port_bank;
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
                        fx = 0.0f;
                        pad->sx = 0;
                    }
                    if ((-31.0f) < fy && fy <= 31.0f) {
                        fy = 0.0f;
                        pad->sy = 0;
                    }
                    if ((-31.0f) < gx && gx <= 31.0f) {
                        gx = 0.0f;
                        pad->cx = 0;
                    }
                    if ((-31.0f) < gy && gy <= 31.0f) {
                        gy = 0.0f;
                        pad->cy = 0;
                    }
                    m = newton_sqrtf(fx * fx + fy * fy);
                    if (0.0f != m) {
                        m *= 0.0078125f;
                    }
                    if (m > 1.0f) {
                        m = 1.0f;
                    }
                    pad->mag0 = m;
                    m = newton_sqrtf(gx * gx + gy * gy);
                    if (0.0f != m) {
                        m *= 0.0078125f;
                    }
                    if (m > 1.0f) {
                        m = 1.0f;
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
                    map_main_stick_to_buttons((ControllerInputContext *)pad, pad->sx, pad->sy, old);
                    map_c_stick_to_buttons((ControllerInputContext *)pad, pad->cx, pad->cy, old);
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
                    update_button_hold_counters((ControllerInputContext *)pad);
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
                    pad->mag0 = 0.0f;
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
#define controller_physical_port_bank ((s32 *)&controller_physical_port_bank)

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
saddr TKeyBoardControl__sub_803DEB74(int);
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
        p->f24 = 0.0f;
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
        if (TKeyBoardControl::read_input((u8)keyboard_poll_key_codes[i]) != 0) {
            self->f0 |= TKeyBoardControl_key_bit_table[i];
        }
    }
    n = hardware_keyboard_state.get_pending_count();
    for (j = 0; j < n; j++) {
        ((void (*)(u8, u32 *))accumulate_key_bits)((s32)hardware_keyboard_state.sub_8013239C(j), &self->f8);
    }
    self->f48 = self->f0;
    self->f4C = self->f8;
    return 0;
}
}

#undef controller_input_state
#undef controller_physical_port_bank
#pragma pop

void accumulate_key_bits(s32 arg0, s32 *arg1) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (arg0 == ((s32 *)keyboard_poll_key_codes)[i]) {
            *arg1 |= ((s32 *)TKeyBoardControl_key_bit_table)[i];
        }
    }
}

extern "C" {

void fn_801A6A28(ControllerInputContext *pad, u32 mask, u32 previous) {
    pad->previous_buttons |= mask;
    if (previous & mask) {
        pad->flags_4c &= ~mask;
        return;
    }
    pad->flags_4c |= mask;
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
    update_button_hold_counter(pad, &pad->hold_frames[0], 0x10, pad->previous_buttons);
    update_button_hold_counter(pad, &pad->hold_frames[1], 0x20, pad->previous_buttons);
    update_button_hold_counter(pad, &pad->hold_frames[2], 0x40, pad->previous_buttons);
    update_button_hold_counter(pad, &pad->hold_frames[3], 0x80, pad->previous_buttons);
    update_button_hold_counter(pad, &pad->hold_frames[4], 0x100000, pad->previous_buttons);
    update_button_hold_counter(pad, &pad->hold_frames[5], 0x200000, pad->previous_buttons);
    update_button_hold_counter(pad, &pad->hold_frames[6], 0x400000, pad->previous_buttons);
    update_button_hold_counter(pad, &pad->hold_frames[7], 0x800000, pad->previous_buttons);
    update_button_hold_counter(pad, &pad->hold_frames[8], 0x04000000, pad->previous_buttons);
    update_button_hold_counter(pad, &pad->hold_frames[9], 0x08000000, pad->previous_buttons);
    update_button_hold_counter(pad, &pad->hold_frames[10], 0x10000000, pad->previous_buttons);
    update_button_hold_counter(pad, &pad->hold_frames[11], 0x20000000, pad->previous_buttons);
    update_button_hold_counter(pad, &pad->hold_frames[12], 0x20000, pad->previous_buttons);
    update_button_hold_counter(pad, &pad->hold_frames[13], 0x10000, pad->previous_buttons);
}

}

s32 TRaderMapCore::pack_color_bits(s32 input, s32 mask) {
    s32 bits = mask | ((mask << 0x10) & 0xF00000);
    return bits | ((bits << 0x16) & 0x3C000000);
}

extern "C" {

s32 TRaderMapCore__sub_801A6D00(void *pad, s32 mask) {
    return (mask & 0xFFFFFF0F) | ((mask << 0x16) & 0x3C000000);
}

s32 pack_flags__13TRaderMapCoreFii(s32 pad, s32 mask) {
    return (mask & 0xFF0FFFFF) | ((mask << 0x16) & 0x3C000000);
}

s32 test_flags_04_packed(void *pad, s32 mask) {
    return (((ControllerInputContext *)pad)->flags_04 & pack_flags__13TRaderMapCoreFii((saddr)pad, mask)) != 0;
}

s32 test_controller_flag_4c_color(void *pad, s32 mask) {
    return (((ControllerInputContext *)pad)->flags_4c & TRaderMapCore::pack_color_bits((saddr)pad, mask)) != 0;
}

s32 TWindowShortListCtrl__check_controller_button(void *pad, s32 mask) {
    return (((ControllerInputContext *)pad)->flags_4c & pack_flags__13TRaderMapCoreFii((saddr)pad, mask)) != 0;
}

s32 test_previous_buttons_color(void *pad, s32 mask) {
    return (((ControllerInputContext *)pad)->previous_buttons & TRaderMapCore::pack_color_bits((saddr)pad, mask)) != 0;
}

s32 test_previous_buttons_remapped(void *pad, s32 mask) {
    return (((ControllerInputContext *)pad)->previous_buttons & TRaderMapCore__sub_801A6D00(pad, mask)) != 0;
}

s32 test_previous_buttons_packed(void *pad, s32 mask) {
    return (((ControllerInputContext *)pad)->previous_buttons & pack_flags__13TRaderMapCoreFii((saddr)pad, mask)) != 0;
}

}

s32 TAdMultiPlyChrSelectGC::dispatch_draw_command(s32 input, s32 buttons, s32 delay, s32 period) {
    u32 mask = TRaderMapCore::pack_color_bits(input, buttons);
    return input_press_or_repeat((ControllerInputContext *)input, mask, delay, period);
}

s32 TRaderMapCore::apply_packed_flags(saddr input, s32 buttons, s32 delay, s32 period) {
    u32 mask = pack_flags__13TRaderMapCoreFii(input, buttons);
    return check_packed_flag_match((ControllerInputContext *)input, mask, delay, period);
}

extern "C" {

s32 test_buttons_press_or_repeat(s32 input, s32 buttons, s32 delay, s32 period) {
    u32 mask = pack_flags__13TRaderMapCoreFii(input, buttons);
    return input_press_or_repeat((ControllerInputContext *)input, mask, delay, period);
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
    if (pad->flags_4c & mask) return 1;
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

void TObjPlayer::reset_state_block() { *(int*)((char*)this + 0x0) = 0; *(int*)((char*)this + 0x4) = -1; *(int*)((char*)this + 0x8) = 0; *(int*)((char*)this + 0xc) = 0; *(short*)((char*)this + 0x10) = 0; *(short*)((char*)this + 0x12) = 0; *(short*)((char*)this + 0x14) = 0; *(short*)((char*)this + 0x16) = 0; *(short*)((char*)this + 0x18) = 0; *(short*)((char*)this + 0x1a) = 0; *(int*)((char*)this + 0x1c) = 0; *(int *)&this->m_20 = 0; *(float *)&this->texlist = 0.0f; *(float *)&this->room = 0.0f; }
