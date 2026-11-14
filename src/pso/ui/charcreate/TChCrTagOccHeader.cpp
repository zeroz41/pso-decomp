#include "types.h"
#include "pso/ui/UISprite.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TChCrTag.h"
#include "pso/ui/charcreate/TChCrTagOccHeader.h"
#include "pso/ui/charcreate/TChCrTagOccupation.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"

extern "C" {
const char *chcr_tag_occ_header_class_name = "TChCrTagOccHeader";
}

extern "C" f32 sin_table_lookup(s32 angle);
#pragma push
#pragma fp_contract on
extern "C" void fn_802A2A00(TChCrTag *tag) {
  u8 *self = (u8 *)tag;
  vec2f pos = {393.0f, 82.0f};
  vec2f scale;
  f32 f31;
  f32 alpha;
  f32 depth;
  s32 n;
  s32 id;
  f31 = (*((f32 *) (self + 0x24))) * (*((f32 *) (self + 0x30)));
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
  n = *((s32 *) (self + 0x20));
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

  if ((*((s32 *) (self + 0x20))) < 3)
  {
    id = (*((s32 *) (self + 0x20))) + 0xad;
  }
  else
  {
    id = (*((s32 *) (self + 0x20))) + 0xad;
  }
  f31 = f31;
  if (tag->vt4())
  {
    f32 s = sin_table_lookup((*((s32 *) (self + 0x3c))) << 9);
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

s32 TChCrTagOccHeader__vt4(TChCrTagOccHeader *tag);
void run_task__17TChCrTagOccHeaderFv(TChCrTagOccHeader *tag);

void TChCrTagOccHeader::run_task() {
    update_fade__8TChCrTagFPv(this);
    m_3c = m_3c + 1;
}
s32 TChCrTagOccHeader__vt4(TChCrTagOccHeader *tag) {
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        if (tag->m_20 < 3 && tag->m_20 == TChCrCharSelect::get_selected_char()) {
            return 1;
        }
        break;
    default:
        if (tag->m_20 >= 3 && tag->m_20 - 3 == TChCrCharSelect::get_instance()) {
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
    (void *)TChCrTagOccHeader__vt4,
    0,
};

}

TChCrTagOccHeader::TChCrTagOccHeader(TObject *parent, void *arg) : TChCrTag(parent, arg) {
    m_name = chcr_tag_occ_header_class_name;
    m_28 = 0.33333334f;
    m_2c = -0.11111111f;
    m_34 = 0.33333334f;
    m_38 = -0.11111111f;
}

void *create_ch_cr_tag_occ_header(void *arg0) {
    return new TChCrTagOccHeader(tl_03, arg0);
}

void create_all_ch_cr_tag_headers(void) {
    int i;
    for (i = 0; i < 15; i++) {
        create_ch_cr_tag_occ_header((void *)i);
    }
}
