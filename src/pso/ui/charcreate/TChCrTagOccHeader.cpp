#include "types.h"
#include "pso/ui/UISprite.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TChCrTag.h"
#include "pso/ui/charcreate/TChCrTagOccHeader.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/math/AngleLookup.h"


const char *chcr_tag_occ_header_class_name = "TChCrTagOccHeader";

#pragma push
#pragma fp_contract on
void TChCrTagOccHeader::draw_header() {
  vec2f pos = {393.0f, 82.0f};
  vec2f scale;
  f32 f31;
  f32 alpha;
  f32 depth;
  s32 n;
  s32 id;
  f31 = (m_fade) * (m_highlight);
  if (f31 <= 0.0f)
  {
    return;
  }
  if (is_selected())
  {
    depth = -2.4375f;
  }
  else
  {
    depth = -3.0625f;
  }
  alpha = f31 / 0.4f;
  alpha = alpha * alpha;
  if (alpha > 1.0f)
  {
    alpha = 1.0f;
  }
  scale.y = 1.0f;
  scale.x = 1.0f;
  if (f31 < 0.4f)
  {
    f32 t = (0.4f - f31) / 0.4f;
    f32 k = 0.15f * t;
    scale.x = 1.0f + k;
    scale.y = scale.x;
  }
  n = m_index;
  if (n < 3)
  {
    id = n + 0x63;
  }
  else
  {
    id = ((n - 3) / 4) + 0x63;
  }
  draw_ui_sprite_shaded(id, &pos, &scale, depth, alpha, 1.0f);
  if (!is_selected() || f31 <= 0.4f)
  {
    return;
  }
  f31 = (f31 - 0.4f) / 0.6f;

  if ((m_index) < 3)
  {
    id = (m_index) + 0xad;
  }
  else
  {
    id = (m_index) + 0xad;
  }
  f31 = f31;
  if (is_selected())
  {
    f32 s = sin_table_lookup((m_frame) << 9);
    f31 = (0.25f * s) + f31;
    if (f31 < 0.0f)
    {
      f31 = 0.0f;
    }
    else
      if (f31 > 1.0f)
    {
      f31 = 1.0f;
    }
  }
  draw_ui_sprite_shaded(id, &pos, &scale, -2.125f, f31, 1.0f);
}
#pragma pop

void TChCrTagOccHeader::render() { draw_header(); }

void TChCrTagOccHeader::run_task() {
    TChCrTag::run_task();
    m_frame = m_frame + 1;
}
s32 TChCrTagOccHeader::is_selected() {
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        if (this->m_index < 3 && this->m_index == TChCrCharSelect::get_selected_char()) {
            return 1;
        }
        break;
    default:
        if (this->m_index >= 3 && this->m_index - 3 == TChCrCharSelect::get_instance()) {
            return 1;
        }
        break;
    }
    return 0;
}

TChCrTagOccHeader::~TChCrTagOccHeader() {}

TChCrTagOccHeader::TChCrTagOccHeader(TObject *parent, s32 index) : TChCrTag(parent, index) {
    m_name = chcr_tag_occ_header_class_name;
    m_fade_in_step = 0.33333334f;
    m_fade_out_step = -0.11111111f;
    m_highlight_in_step = 0.33333334f;
    m_highlight_out_step = -0.11111111f;
}

TChCrTagOccHeader *create_ch_cr_tag_occ_header(s32 index) {
    return new TChCrTagOccHeader(tl_03, index);
}

void create_all_ch_cr_tag_headers(void) {
    saddr i;
    for (i = 0; i < 15; i++) {
        create_ch_cr_tag_occ_header(i);
    }
}
