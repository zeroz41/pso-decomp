#include "pso/misc/TWindowDD.h"
#include "pso/TObject.h"
#include "pso/misc/TUnk_804EFBAC.h"

#include "types.h"

struct RecoveredGlobal_80340508_lbl_8050E208
{
  s32 value;
  u8 remaining[0x1AC];
};

struct RecoveredGlobal_803404A4_lbl_8050E208
{
  s32 value;
  u8 remaining[0x1AC];
};

struct E_803403F8 { f32 a; f32 b; f32 c; f32 d; f32 e; s32 f; };

extern const f32 lbl_805DFC34;
extern const f32 lbl_805DFC38;
extern const f32 lbl_805DFC3C;
extern "C" {
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, void *);
s32 TWindowShortListCtrl__check_controller_button(void *, void *);
extern RecoveredGlobal_80340508_lbl_8050E208 controller_input_state;
s32 apply_choice__20TWindowChoiceSettingFllll(void *, void *, int, int);
extern const f32 TWindowDD__data_805DFBFC;
extern const f32 lbl_805DFC00;
extern const f32 lbl_805DFC04;
extern const f32 lbl_805DFC08;
extern const f32 lbl_805DFC2C;
extern const f32 lbl_805DFC30;
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
int update_fade__11TWindowBaseFv(void*);

void TWindowDD::reset_entries(f32 v) {
    E_803403F8 *p = (E_803403F8 *)this;
    s32 i;
    for (i = 0; i < 8; i++) {
        p->a = lbl_805DFC30;
        p->b = lbl_805DFC30;
        p->c = v;
        p->d = lbl_805DFC30;
        p->e = lbl_805DFC30;
        p->f = -1;
        p++;
    }
}

void TWindowDD::set_quad_corners_scaled(f32 farg0, f32 farg1, f32 farg2) {
    u8 *arg0 = (u8 *)this;
  f32 temp_f0;
  f32 temp_f1;
  f32 temp_f1_2;
  s8 *new_var;
  f32 temp_f2;
  f32 temp_f4;
  float new_var4;
  f32 temp_f5;
  int new_var3;
  f32 temp_f7;
  f32 temp_f8;
  s8 *new_var2;
  temp_f4 = farg0 + farg2;
  temp_f8 = lbl_805DFC34 * farg0;
  temp_f7 = lbl_805DFC34 * farg1;
  *((f32 *) (((s8 *) arg0) + 0)) = temp_f8;
  temp_f5 = lbl_805DFC34 * (lbl_805DFC38 + farg1);
  new_var4 = lbl_805DFC34 * temp_f4;
  *((f32 *) (((s8 *) arg0) + 4)) = temp_f7;
  temp_f1 = lbl_805DFC3C + farg0;
  temp_f2 = new_var4;
  *((f32 *) (((s8 *) arg0) + 8)) = temp_f8;
  temp_f1_2 = lbl_805DFC34 * temp_f1;
  *((f32 *) (((s8 *) arg0) + 0xC)) = temp_f5;
  temp_f0 = temp_f1;
  temp_f0 = lbl_805DFC34 * (temp_f0 - farg2);
  new_var2 = ((s8 *) arg0) + 0x28;
  *((f32 *) (((s8 *) arg0) + 0x10)) = temp_f2;
  *((f32 *) (((s8 *) arg0) + 0x14)) = temp_f7;
  *((f32 *) (((s8 *) arg0) + 0x18)) = temp_f2;
  *((f32 *) (((s8 *) arg0) + 0x1C)) = temp_f5;
  *((f32 *) (((s8 *) arg0) + 0x20)) = temp_f0;
  *((f32 *) (((s8 *) arg0) + 0x24)) = temp_f7;
  new_var3 = 0x30;
  *((f32 *) new_var2) = temp_f0;
  *((f32 *) (((s8 *) arg0) + 0x2C)) = temp_f5;
  *((f32 *) (((s8 *) arg0) + new_var3)) = temp_f1_2;
  *((f32 *) (((s8 *) arg0) + 0x34)) = temp_f7;
  new_var = ((s8 *) arg0) + 0x38;
  *((f32 *) new_var) = temp_f1_2;
  *((f32 *) (((s8 *) arg0) + 0x3C)) = temp_f5;
}

typedef struct RecoveredGlobal_80340508_lbl_8050E208 RecoveredGlobal_80340508_lbl_8050E208;
typedef char RecoveredGlobal_80340508_lbl_8050E208_size[((sizeof(RecoveredGlobal_80340508_lbl_8050E208)) == 0x1B0) ? (1) : (-1)];

#pragma push
#pragma opt_dead_assignments off
typedef struct RecoveredGlobal_803404A4_lbl_8050E208 RecoveredGlobal_803404A4_lbl_8050E208;
typedef char RecoveredGlobal_803404A4_lbl_8050E208_size[((sizeof(RecoveredGlobal_803404A4_lbl_8050E208)) == 0x1B0) ? (1) : (-1)];
s32 TWindowDD::apply_both_choices(s32 arg0, s32 arg1) {
  return apply_choice__20TWindowChoiceSettingFllll((void *) (((u8 *) (&(*(RecoveredGlobal_803404A4_lbl_8050E208 *)&controller_input_state).value)) + 0x20), (void *) arg1, 6, 1) | apply_choice__20TWindowChoiceSettingFllll((void *) (((u8 *) (&(*(RecoveredGlobal_803404A4_lbl_8050E208 *)&controller_input_state).value)) + 0x160), (void *) arg1, 6, 1);
}
}
#pragma pop

s32 TWindowDD_check_input_mask(void *input_context, s32 arg1) {
  return TWindowShortListCtrl__check_controller_button((void *) (((u8 *)&controller_input_state.value) + 0x20), (void *) arg1) | test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) (((u8 *)&controller_input_state.value) + 0x160), (void *) arg1);
}
extern "C" {

void update_draw__9TWindowDDFPv(void* p) { ((TWindowDD *)p)->initialize_subwindow(); update_fade__11TWindowBaseFv(p); }

void TWindowDD::set_clamped_page(s32 arg1) {
    if (arg1 < 0) {
        this->m_80 = 0;
        return;
    }
    if (arg1 >= 3) {
        this->m_80 = 2;
        return;
    }
    this->m_80 = arg1;
}

s32 TWindowDD__sub_80340820(void* p) { return *(s32*)((char*)p + 0x68); }

#pragma push
#pragma opt_common_subs off
void TWindowDD::handle_input() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    s32 temp_r31;
    s32 temp_r3;
    temp_r31 = this->m_84;
    if (TWindowDD::apply_both_choices((s32)(arg0 + 0x60), 0x10) != 0) {
        this->m_84 = (this->m_84 - 1);
    } else if (TWindowDD::apply_both_choices((s32)(arg0 + 0x60), 0x20) != 0) {
        this->m_84 = (this->m_84 + 1);
    } else if (TWindowDD::apply_both_choices((s32)(arg0 + 0x60), 0x20000) != 0) {
        this->m_84 = 0;
    } else if (TWindowDD::apply_both_choices((s32)(arg0 + 0x60), 0x10000) != 0) {
        this->m_84 = 2;
    }
    temp_r0 = this->m_84;
    temp_r3 = this->m_80;
    if (temp_r0 < temp_r3) {
        this->m_84 = temp_r3;
    } else if (temp_r0 >= 3) {
        this->m_84 = 2;
    }
    if ((s32) this->m_84 != temp_r31) {
        TWindowDD::spawn_window();
    }
}
#pragma pop

void TWindowDD__sub_80340910(void* p) { *(s32*)((char*)p + 0x60) = 1; }

void TWindowDD__sub_8034055C();
void render_shadows__7TObjectFv();
__declspec(section ".data") void *TWindowDD__layout_constant_pair[2] = {
    (void *)0x0, (void *)0x0,
};
void *TWindowDD__layout_constants[5] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x3,
};
void *lbl_804EFBAC[7] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__13TUnk_804EFBACFv, (void *)&update_draw__9TWindowDDFPv,
    (void *)&TWindowDD__sub_8034055C, (void *)&render_shadows__7TObjectFv, (void *)0x0,
};
#define TWindowDD__layout_constant_pair ((f32 *)TWindowDD__layout_constant_pair)
#define TWindowDD__layout_constants ((f32 *)TWindowDD__layout_constants)
#define lbl_804EFBAC ((s32 *)lbl_804EFBAC)

void TWindowDD::set_clamped_selection(s32 arg1) {
    s32 temp_r0;
    s32 var_r4;
    var_r4 = arg1;
    temp_r0 = this->m_80;
    if (var_r4 < temp_r0) {
        var_r4 = temp_r0;
    } else if (var_r4 >= 3) {
        var_r4 = 2;
    }
    this->m_84 = var_r4;
    this->m_7c = 0;
}

void *__dt__13TUnk_804EFBACFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804EFBAC;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

struct W_803409A4 { u8 pad0[0x18]; void *p18; u8 pad1c[0x5C - 0x1C]; s32 f5c; s32 f60; s32 f64; s32 f68; };

#define arg0 ((W_803409A4 *)arg0v)
void *TWindowDD::construct_variant_a(void *arg0v) {
    ((TWindowDD *)arg0)->construct_base((u8 *)TWindowDD__layout_constants, (s16)4, (u8 *)TWindowDD__layout_constant_pair);
    arg0->p18 = lbl_804EFBAC;
    arg0->f60 = 1;
    arg0->f64 = 2;
    arg0->f68 = 2;
    arg0->f5c = 0x01000000;
    return arg0;
}
#undef arg0

void *TWindowDD::create() {
    void *o = __nw__7TObjectFUl(0x6C);
    if (o != NULL) {
        o = TWindowDD::construct_variant_a(o);
    }
    return o;
}

void TWindowDD::init_layout_constants() {
    TWindowDD__layout_constant_pair[0] = TWindowDD__data_805DFBFC;
    TWindowDD__layout_constant_pair[1] = lbl_805DFC00;
    TWindowDD__layout_constants[0] = lbl_805DFC04;
    TWindowDD__layout_constants[1] = lbl_805DFC08;
    TWindowDD__layout_constants[2] = lbl_805DFC2C;
}

void TWindowDD::init() { initialize_subwindow(); update_fade__11TWindowBaseFv(this); }

extern const f32 lbl_805DFC6C;

void TWindowDD::set_value_f32(s32 arg1) {
    *(f32 *)&this->m_88 = (f32) arg1;
}

void TWindowDD::set_scale(s32 arg1, s32 arg2) {
    *(f32 *)&this->m_80 = (f32) arg1;
    *(f32 *)&this->m_84 = (f32) arg2;
    *(f32 *)&this->m_7c = (f32) (lbl_805DFC6C / *(f32 *)&this->m_80);
}
}
