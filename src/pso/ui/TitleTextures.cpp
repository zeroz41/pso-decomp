// Its own TU: the title textures have their own .sdata2 pool.
#include "types.h"
#include "pso/ui/TitleTextures.h"
#include "pso/ui/TitleTextureResources.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/TTitleLogo.h"
#include "pso/ui/frontend/TTitleScene.h"

#include "pso/ui/TTitleMenu.h"
#include "pso/ui/window/ScreenQuadDraw.h"


#include "pso/network/TLobby.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PrsTextureLoad.h"
#include "pso/ui/frontend/TitleSceneTables.h"
#include "pso/ui/window/WindowDrawContext.h"

void TTitleLogo::render() {
  TexturedQuad quad;
  begin_effect_render();
  TCameraCtrl::restore_full_screen_view();
  begin_screen_draw(1);
  bind_title_texture_list();
  set_draw_texture_and_color(1, -1);
  quad.x0 = 64.0f;
  quad.y0 = 61.0f;
  quad.x1 = 3.2e+02f;
  quad.y1 = 317.0f;
  quad.v0 = (quad.u0 = 0.0f);
  quad.v1 = (quad.u1 = 1.0f);
  draw_textured_quad_at_depth((&quad.x0), 0.1f);
  set_draw_texture_and_color(2, -1);
  quad.x0 = 3.2e+02f;
  quad.y0 = 61.0f;
  quad.x1 = 576.0f;
  quad.y1 = 317.0f;
  draw_textured_quad_at_depth((&quad.x0), 0.1f);
  end_screen_draw();
  TCameraCtrl::restore_saved_view();
  end_effect_render();
}

void TTitleLogo::run_task() {  }
TTitleLogo::~TTitleLogo() {

}
TTitleLogo::TTitleLogo(TObject *parent) : TObject(parent) {
    owner = parent;
}

void free_title_texture_resources() {}
void load_title_texture_resources() {}

NJS_TEXLIST *get_title_texture_list(void) {
    return &title_texture_list;
}

NJS_SPRITE *get_record(int index) { return &lobby_record_table[index]; }

void bind_title_texture_list(void) {
    set_texlist(&title_texture_list);
}

int get_transition_cursor(TTitleScene *scene) {
    return scene->transition_controller->get_cursor();
}
