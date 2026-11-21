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
void fn_802A2A00(TChCrTagOccHeader *tag) {
  vec2f pos = {393.0f, 82.0f};
  vec2f scale;
  f32 f31;
  f32 alpha;
  f32 depth;
  s32 n;
  s32 id;
  f31 = (tag->m_24) * (tag->m_30);
  if (f31 <= 0.0f)
  {
    return;
  }
  if (tag->vt4())
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
  n = tag->m_20;
  if (n < 3)
  {
    id = n + 0x63;
  }
  else
  {
    id = ((n - 3) / 4) + 0x63;
  }
  draw_ui_sprite_shaded(id, &pos, &scale, depth, alpha, 1.0f);
  if (!tag->vt4() || f31 <= 0.4f)
  {
    return;
  }
  f31 = (f31 - 0.4f) / 0.6f;

  if ((tag->m_20) < 3)
  {
    id = (tag->m_20) + 0xad;
  }
  else
  {
    id = (tag->m_20) + 0xad;
  }
  f31 = f31;
  if (tag->vt4())
  {
    f32 s = sin_table_lookup((tag->m_3c) << 9);
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

extern "C" {

int render__17TChCrTagOccHeaderFv(void* p);

void TChCrTagOccHeader::render() { fn_802A2A00(this); }

s32 vt4__17TChCrTagOccHeaderFv(TChCrTagOccHeader *tag);
void run_task__17TChCrTagOccHeaderFv(TChCrTagOccHeader *tag);

void TChCrTagOccHeader::run_task() {
    update_fade__8TChCrTagFPv(this);
    m_3c = m_3c + 1;
}
s32 TChCrTagOccHeader::vt4() {
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        if (this->m_20 < 3 && this->m_20 == TChCrCharSelect::get_selected_char()) {
            return 1;
        }
        break;
    default:
        if (this->m_20 >= 3 && this->m_20 - 3 == TChCrCharSelect::get_instance()) {
            return 1;
        }
        break;
    }
    return 0;
}

extern void *__vt__17TChCrTagOccHeader[];
TChCrTagOccHeader *__dt__17TChCrTagOccHeaderFv(TChCrTagOccHeader *tag, s16 free) {
    if (tag != NULL) {
        *(void ***)((u8 *)tag + 0x18) = __vt__17TChCrTagOccHeader;
        __dt__8TChCrTagFv(tag, 0);
        if (free > 0) {
            TObject::operator delete(tag);
        }
    }
    return tag;
}

void render_shadows__7TObjectFv();
void *__vt__17TChCrTagOccHeader[] = {
    0, 0,
    (void *)__dt__17TChCrTagOccHeaderFv,
    (void *)run_task__17TChCrTagOccHeaderFv,
    (void *)render__17TChCrTagOccHeaderFv,
    (void *)render_shadows__7TObjectFv,
    (void *)vt4__17TChCrTagOccHeaderFv,
    0,
};

}

TChCrTagOccHeader::TChCrTagOccHeader(TObject *parent, s32 index) : TChCrTag(parent, index) {
    m_name = chcr_tag_occ_header_class_name;
    m_28 = 0.33333334f;
    m_2c = -0.11111111f;
    m_34 = 0.33333334f;
    m_38 = -0.11111111f;
}

TChCrTagOccHeader *create_ch_cr_tag_occ_header(s32 index) {
    return new TChCrTagOccHeader(tl_03, index);
}

void create_all_ch_cr_tag_headers(void) {
    int i;
    for (i = 0; i < 15; i++) {
        create_ch_cr_tag_occ_header(i);
    }
}
