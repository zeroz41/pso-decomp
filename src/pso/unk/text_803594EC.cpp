#include "types.h"
#include "pso/render/render_util.h"

#include "pso/misc/TWindowCtrlMain.h"
#include "pso/TBoss4Fade.h"
struct E_8035959C { s32 a; s32 b; f32 c; };

struct O_8035959C { u8 pad[0x1c]; s32 idx; E_8035959C e[2]; };

typedef struct Ent_803594EC
{
  s32 active;
  u32 color;
  f32 alpha;
} Ent_803594EC;

typedef struct Fade_803594EC
{
  u8 pad0[0x1C];
  s32 cur;
  Ent_803594EC ent[2];
} Fade_803594EC;

typedef struct Quad_803594EC
{
  void *tex;
  u32 *colors;
  s32 a;
  s32 b;
  u32 col[4];
} Quad_803594EC;

extern u8 TBoss4Fade__fullscreen_vertices[];
extern const f32 lbl_805E0098;
extern const f32 lbl_805E009C;

typedef struct Ent_803594EC Ent_803594EC;
typedef struct Fade_803594EC Fade_803594EC;
typedef struct Quad_803594EC Quad_803594EC;
void TBoss4Fade::render() {
    Fade_803594EC *self = (Fade_803594EC *)this;
  u32 c;
  int new_var;
  Quad_803594EC q;
  s32 i = self->cur ^ 1;
  if (self->ent[i].active != 0)
  {
    c = (self->ent[i].color & (~0xFF000000)) | (((u32) (lbl_805E0098 * self->ent[i].alpha)) << 24);
    q.colors = q.col;
    q.col[3] = c;
    q.col[2] = c;
    new_var = 0;
    q.col[1] = c;
    q.col[new_var] = c;
    q.a = new_var;
    q.b = 4;
    q.tex = TBoss4Fade__fullscreen_vertices;
    set_depth_buffer_settings_1();
    ((TWindowCtrlMain *)(&q))->draw_strip_swap_color(4, 6, lbl_805E009C);
    restore_saved_depth_alpha_state();
  }
}

void TBoss4Fade::run_task() {
    O_8035959C *self = (O_8035959C *)this;
    self->idx ^= 1;
    self->e[self->idx].a = 0;
}
