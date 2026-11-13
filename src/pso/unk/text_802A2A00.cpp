#include "pso/ui/UISprite.h"
#include "pso/ui/charcreate/TChCrTag.h"


extern "C" f32 sin_table_lookup(s32 angle);
extern u8 lbl_80466454[];
#pragma push
#pragma fp_contract on
extern "C" void fn_802A2A00(TChCrTag *tag) {
  u8 *self = (u8 *)tag;
  vec2f pos;
  vec2f scale;
  f32 f31;
  f32 alpha;
  f32 depth;
  s32 n;
  s32 id;
  u32 *src;
  src = (u32 *) lbl_80466454;
  ((u32 *) (&pos))[0] = src[0];
  ((u32 *) (&pos))[1] = src[1];
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
