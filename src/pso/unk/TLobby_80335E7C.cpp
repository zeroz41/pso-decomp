// ---- pso/misc/TLobby_80335E08 [0x80335E7C-0x80336054): separate TU (own .sdata2 pool 0x805DF8C8-0x805DF8E8)
#include "types.h"
#include "pso/unk/TLobby_80335E7C.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/unk/TUnk_804EE470.h"
#include "pso/unk/TTitleScene.h"

#include "pso/ui/TTitleMenu.h"
#include "pso/unk/TLobby_80335E08.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"


#include "pso/network/TLobby.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/ui/frontend/TitleSceneTables.h"

extern "C" {



    
    
}

typedef struct Stack_80335E7C Stack_80335E7C;
void TUnk_804EE470::render() {
  TexturedQuad quad;
  TParticleCtrl::begin_effect_render();
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
  TParticleCtrl::end_effect_render();
}

void TUnk_804EE470::run_task() {  }
TUnk_804EE470::~TUnk_804EE470() {

}
TUnk_804EE470::TUnk_804EE470(TObject *parent) : TObject(parent) {
    *(void * *)&this->unk_1C = parent;
}

void TLobby__sub_80335FE0(void) {  }
void TLobby__sub_80335FE4(void) {  }

NJS_TEXLIST *get_title_texture_list(void) {
    return &title_texture_list;
}

NJS_SPRITE *TLobby::get_record(int index) { return &lobby_record_table[index]; }

void bind_title_texture_list(void) {
    set_texlist(&title_texture_list);
}

int get_transition_cursor(TTitleScene *scene) {
    return scene->transition_controller->get_cursor();
}
