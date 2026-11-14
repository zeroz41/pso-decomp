#include "pso/ui/charcreate/TChCrEffTag.h"
#include "pso/ui/charcreate/TChCrEffTagStr.h"
#include "types.h"
#include <stddef.h>
#include "pso/math/TMath.h"

const char *TChCrEffTag__name = "TChCrEffTag";
s32 TChCrEffTag__selected_heading = -1;
static const s32 lbl_804652A4[] = {0xA4, 0xA5, 0xA6, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA3};

extern "C" {

int restore_saved_depth_alpha_state(void);
int draw_chcr_tag_heading_frame(void*);
int set_depth_buffer_settings_1__Fv(void*);

void TChCrEffTag::render() { set_depth_buffer_settings_1__Fv(this); draw_chcr_tag_frame(); draw_chcr_tag_heading_frame(this); restore_saved_depth_alpha_state(); }
void TChCrEffTag::refresh_label() {
    vec2f pos;
    s32 temp_r0;
    if (label != NULL) {
        TChCrEffTagStr__sub_8029AED0(label);
        label = NULL;
    }
    this->heading = (s32) TChCrEffTag__selected_heading;
    temp_r0 = this->heading;
    if (temp_r0 >= 0) {
        pos.x = 27.0f;
        pos.y = 44.0f;
        label = (TChCrEffTagStr *)create_str(this, (void *)lbl_804652A4[temp_r0], &pos);
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
    width = 294.0f;
  }
}
#pragma pop

TChCrEffTag::~TChCrEffTag() {}

TChCrEffTag::TChCrEffTag(TObject *parent) : TObject(parent) {
    m_name = TChCrEffTag__name;
    heading = -1;
    TChCrEffTag__selected_heading = -1;
    label = NULL;
    targetWidth = 1e+02f;
    width = 1e+02f;
}

extern "C" {

void *__nw__7TObjectFUl(int);

    void TChCrEffTag::set_eff_tag(int a0) { TChCrEffTag__selected_heading = a0; }
}

void *create_TChCrEffTag(void *ch_cr_eff_tag) {
    return new TChCrEffTag((TObject *)ch_cr_eff_tag);
}
