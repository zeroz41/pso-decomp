// ---- pso/misc/TLobby_80335E08 [0x80335E7C-0x80336054): separate TU (own .sdata2 pool 0x805DF8C8-0x805DF8E8)
#include "types.h"
#include "pso/unk/TLobby_80335E7C.h"
#include "pso/unk/TUnk_804EE470.h"
#include "pso/unk/TTitleScene.h"

#include "pso/ui/TUnk_804EE458.h"
#include "pso/unk/TLobby_80335E08.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/frontend/TAdTrialAgreementGC_80335958.h"


#include "pso/unk/TLobby.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/ui/frontend/TitleSceneTables.h"

struct Stack_80335E7C
{
  f32 sp8;
  f32 spC;
  f32 sp10;
  f32 sp14;
  f32 sp18;
  f32 sp1C;
  f32 sp20;
  f32 sp24;
};

extern "C" {



    
    
}

typedef struct Stack_80335E7C Stack_80335E7C;
void TUnk_804EE470::render() {
  Stack_80335E7C stack;
  TParticleCtrl::begin_effect_render();
  TCameraCtrl::restore_full_screen_view();
  begin_screen_draw(1);
  bind_title_texture_list();
  set_draw_texture_and_color(1, -1);
  stack.sp8 = 64.0f;
  stack.spC = 61.0f;
  stack.sp10 = 3.2e+02f;
  stack.sp14 = 317.0f;
  stack.sp1C = (stack.sp18 = 0.0f);
  stack.sp24 = (stack.sp20 = 1.0f);
  draw_textured_quad_at_depth((&stack.sp8), 0.1f);
  set_draw_texture_and_color(2, -1);
  stack.sp8 = 3.2e+02f;
  stack.spC = 61.0f;
  stack.sp10 = 576.0f;
  stack.sp14 = 317.0f;
  draw_textured_quad_at_depth((&stack.sp8), 0.1f);
  TWindowSubStatusDisp::get_player();
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

int TLobby__sub_80336030(TTitleScene *scene) {
    return scene->transition_controller->sub_8033596C();
}
