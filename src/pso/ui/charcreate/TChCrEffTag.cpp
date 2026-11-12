#include "pso/ui/charcreate/TChCrEffTag.h"
#include "pso/ui/charcreate/TChCrEffTagStr.h"
#include "types.h"
#include <stddef.h>
#include "pso/ui/charcreate/TChCrEffTag_8029AC44.h"

struct Stack_8029AA74 {
    f32 sp8;
    f32 spC;
};

const char *TChCrEffTag__name = "TChCrEffTag";
s32 TChCrEffTag__selected_heading = -1;
static const s32 lbl_804652A4[] = {0xA4, 0xA5, 0xA6, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA3};

extern "C" {
u32 create_str__11TChCrEffTagFPvPvPv(void *, int, void *);

int restore_saved_depth_alpha_state(void);
int draw_chcr_tag_heading_frame(void*);
int set_depth_buffer_settings_1__Fv(void*);

void TChCrEffTag::render() { set_depth_buffer_settings_1__Fv(this); draw_chcr_tag_frame(); draw_chcr_tag_heading_frame(this); restore_saved_depth_alpha_state(); }
void TChCrEffTag::refresh_label() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_8029AA74, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8029AA74, spC) == 0x4) ? 1 : -1];
    Stack_8029AA74 stack;
    s32 temp_r0;
    u32 temp_r3;
    temp_r3 = *(u32 *)&this->label;
    if (temp_r3 != 0U) {
        TChCrEffTagStr__sub_8029AED0((void *)temp_r3);
        this->label = 0U;
    }
    this->heading = (s32) TChCrEffTag__selected_heading;
    temp_r0 = this->heading;
    if (temp_r0 >= 0) {
        stack.sp8 = 27.0f;
        stack.spC = 44.0f;
        *(u32 *)&this->label = create_str__11TChCrEffTagFPvPvPv(arg0, (int) lbl_804652A4[temp_r0], (void *)&stack.sp8);
    }
}

s32 get_creation_sprite_id__14TObjCMMainMenuFl(int);

}
#pragma push
#pragma fp_contract on
void TChCrEffTag::run_task()
{
  f32 temp_f1;
  f32 temp_f3;
  s32 temp_r0;
  if (((s32) heading) != ((s32) TChCrEffTag__selected_heading))
  {
    refresh_label();
  }
  temp_r0 = heading;
  if (temp_r0 >= 0)
  {
    targetWidth = (f32) (15.0f + ((f32) get_creation_sprite_id__14TObjCMMainMenuFl((int) lbl_804652A4[temp_r0])));
  }
  width = width;
  temp_f3 = targetWidth;
  if (width + 12.933333f < temp_f3)
  {
    width += 12.933333f;
  }
  else if (width - 12.933333f > temp_f3)
  {
    width -= 12.933333f;
  }
  else
  {
    width += 0.2f * (temp_f3 - width);
  }
  temp_f1 = width;
  if (temp_f1 < 1e+02f)
  {
    width = (f32) 1e+02f;
    return;
  }
  if ((temp_f3 && temp_f3) && temp_f3)
  {
  }
  if (temp_f1 > 294.0f)
  {
    width = (f32) 294.0f;
  }
}
#pragma pop

TChCrEffTag::~TChCrEffTag() {}

extern "C" {

void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__11TChCrEffTag[];


void *__ct__11TChCrEffTagFv(void *ch_cr_eff_tag, void *parent) {
    __ct__7TObjectFP7TObject(ch_cr_eff_tag);
    *(s32 **)((s8 *)ch_cr_eff_tag + 0x18) = __vt__11TChCrEffTag;
    ((TChCrEffTag *)ch_cr_eff_tag)->m_name = TChCrEffTag__name;
    ((TChCrEffTag *)ch_cr_eff_tag)->heading = -1;
    TChCrEffTag__selected_heading = -1;
    *(u32 *)((s8 *)ch_cr_eff_tag + 0x28) = 0;
    *(f32 *)((s8 *)ch_cr_eff_tag + 0x24) = 1e+02f;
    *(f32 *)((s8 *)ch_cr_eff_tag + 0x20) = 1e+02f;
    return ch_cr_eff_tag;
}

}

extern "C" {

void *__nw__7TObjectFUl(int);

    void TChCrEffTag::set_eff_tag(int a0) { TChCrEffTag__selected_heading = a0; }
}

void *create_TChCrEffTag(void *ch_cr_eff_tag) {
    void *o = __nw__7TObjectFUl(0x2C);
    if (o != NULL) {
        o = __ct__11TChCrEffTagFv(o, ch_cr_eff_tag);
    }
    return o;
}
