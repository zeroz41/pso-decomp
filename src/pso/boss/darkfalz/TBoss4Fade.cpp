#include "types.h"
#include "pso/render/ColorLineList.h"
#include "pso/render/render_util.h"

#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/boss/darkfalz/TBoss4Fade.h"
#include "pso/system/task/TMainTask.h"
void TBoss4Fade::set_fade(s32 color, f32 alpha) {
    frames[write_index].active = 1;
    frames[write_index].color = color;
    frames[write_index].alpha = alpha;
}

typedef struct Quad_803594EC
{
  void *tex;
  u32 *colors;
  s32 a;
  s32 b;
  u32 col[4];
} Quad_803594EC;

// The 640x480 screen corners the fade quad is drawn over.
f32 TBoss4Fade__fullscreen_vertices[4][2] = {
    {0.0f, 0.0f}, {640.0f, 0.0f}, {640.0f, 480.0f}, {0.0f, 480.0f},
};

typedef struct Quad_803594EC Quad_803594EC;
void TBoss4Fade::render() {
  u32 c;
  int new_var;
  Quad_803594EC q;
  s32 i = write_index ^ 1;
  if (frames[i].active != 0)
  {
    c = (frames[i].color & (~0xFF000000)) | (((u32) (255.0f * frames[i].alpha)) << 24);
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
    reinterpret_cast<ColorLineList *>(&q)->draw_strip_swap_color(4, 6, -1.0f);
    restore_saved_depth_alpha_state();
  }
}

void TBoss4Fade::run_task() {
    write_index ^= 1;
    frames[write_index].active = 0;
}

TBoss4Fade::~TBoss4Fade() {}


#pragma readonly_strings on

const char *TBoss4Fade__name = "TBoss4Fade";

TBoss4Fade::TBoss4Fade(TObject *parent) : TObject(parent) {
    m_name = TBoss4Fade__name;
    frames[0].active = 0;
    frames[1].active = 0;
    write_index = 0;
}

// The fade runs under the window controller, or under tl_clipout when there is none.
TBoss4Fade *create_boss4_fade() {
    TObject *parent = reinterpret_cast<TObject *>(TWindowCtrlMain::get_instance());
    if (parent == NULL) {
        parent = tl_clipout;
    }
    return new TBoss4Fade(parent);
}
