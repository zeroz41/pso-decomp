#include "types.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowMainMenu1P.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"

struct RecoveredGlobal_80288838___vt__17TWindowMainMenu1P { s32 value; u8 remaining[0x24]; };
typedef char RecoveredGlobal_80288838___vt__17TWindowMainMenu1P_size[sizeof(RecoveredGlobal_80288838___vt__17TWindowMainMenu1P) == 0x28 ? 1 : -1];

extern "C" {
extern s32 __vt__17TWindowMainMenu1P[];
extern const f32 lbl_805DD8A0;
extern const f32 lbl_805DD8A4;
extern const f32 lbl_805DD8A8;
extern const f32 lbl_805DD8AC;
extern const f32 lbl_805DD8B0;
extern const f32 lbl_805DD8B4;
extern const f32 lbl_805DD8B8;
extern const f32 lbl_805DD8BC;
extern const f32 lbl_805DD8C0;
extern const f32 lbl_805DD8C4;
extern const f32 lbl_805DD8C8;
void TWindowMainMenu__ct(void *);

#pragma fp_contract on
void TWindowMainMenu1P::update_backdrop_transition() {
    u8 *arg0 = (u8 *)this;
  f32 temp_f1;
  s32 temp_r3;
  s32 temp_r3_2;
  temp_r3 = *((s32 *) (((s8 *) arg0) + 0x4C));
  if (!(temp_r3 & 1))
  {
    *((u8 *) (((s8 *) arg0) + 0x60)) = (u8) ((*((u8 *) (((s8 *) arg0) + 0x60))) - 1);
    *((u8 *) (((s8 *) arg0) + 0x61)) = (u8) ((*((u8 *) (((s8 *) arg0) + 0x61))) + -1);
    if (((s8) (*((u8 *) (((s8 *) arg0) + 0x60)))) < 0)
    {
      *((u8 *) (((s8 *) arg0) + 0x60)) = 0U;
    }
    if (((s8) (*((u8 *) (((s8 *) arg0) + 0x61)))) < 0)
    {
      *((u8 *) (((s8 *) arg0) + 0x61)) = 0U;
    }
    if ((((s8) (*((u8 *) (((s8 *) arg0) + 0x60)))) == 0) && (((s8) (*((u8 *) (((s8 *) arg0) + 0x61)))) == 0))
    {
      temp_r3_2 = *((s32 *) (((s8 *) arg0) + 0x4C));
      if (temp_r3_2 & 2)
      {
        *((s32 *) (((s8 *) arg0) + 0x4C)) = (s32) (temp_r3_2 & 0xFFFFFFFD);
        end_view_override();
      }
    }
  }
  else
    if (temp_r3 & 8)
  {
    *((u8 *) (((s8 *) arg0) + 0x60)) = (u8) ((*((u8 *) (((s8 *) arg0) + 0x60))) + 1);
    *((u8 *) (((s8 *) arg0) + 0x61)) = (u8) ((*((u8 *) (((s8 *) arg0) + 0x61))) - 1);
    if (((f32) ((s8) (*((u8 *) (((s8 *) arg0) + 0x60))))) > lbl_805DD8A0)
    {
      *((u8 *) (((s8 *) arg0) + 0x60)) = 6U;
    }
    if (((s8) (*((u8 *) (((s8 *) arg0) + 0x61)))) < 0)
    {
      *((u8 *) (((s8 *) arg0) + 0x61)) = 0U;
    }
  }
  else
  {
    *((u8 *) (((s8 *) arg0) + 0x60)) = (u8) ((*((u8 *) (((s8 *) arg0) + 0x60))) + 1);
    *((u8 *) (((s8 *) arg0) + 0x61)) = (u8) ((*((u8 *) (((s8 *) arg0) + 0x61))) + 1);
    if (((f32) ((s8) (*((u8 *) (((s8 *) arg0) + 0x60))))) > lbl_805DD8A4)
    {
      *((u8 *) (((s8 *) arg0) + 0x60)) = 3U;
    }
    if (((f32) ((s8) (*((u8 *) (((s8 *) arg0) + 0x61))))) > lbl_805DD8A4)
    {
      *((u8 *) (((s8 *) arg0) + 0x61)) = 3U;
    }
  }
  this->m_6c = (f32) ((lbl_805DD8AC * ((f32) ((s8) (*((u8 *) (((s8 *) arg0) + 0x60)))))) + lbl_805DD8A8);
  *((f32 *) (((s8 *) arg0) + 0x70)) = (f32) (-((lbl_805DD8B4 * ((f32) ((s8) (*((u8 *) (((s8 *) arg0) + 0x61)))))) - lbl_805DD8B0));
  TWindowCtrlMain::set_depth(lbl_805DD8B8 * ((f32) ((s8) (*((u8 *) (((s8 *) arg0) + 0x60))))), *((s32 *) (((s8 *) arg0) + 0x54)));
  TWindowCtrlMain::set_field18(-((lbl_805DD8C0 * ((f32) ((s8) (*((u8 *) (((s8 *) arg0) + 0x61)))))) - lbl_805DD8BC), *((s32 *) (((s8 *) arg0) + 0x54)));
  this->m_a4 = (f32) ((lbl_805DD8C4 - (this->m_6c)) / lbl_805DD8A8);
  *((f32 *) (((s8 *) arg0) + 0xA8)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x70))) / lbl_805DD8B0);
  temp_f1 = *((f32 *) (((s8 *) arg0) + 0xA8));
  if ((this->m_a4) < (*((f32 *) (((s8 *) arg0) + 0xA8))))
  {
    this->m_a4 = *((f32 *) (((s8 *) arg0) + 0xA8));
  }
  *((f32 *) (((s8 *) arg0) + 0xA8)) = (f32) (lbl_805DD8C8 * (this->m_a4));
  if ((*((s32 *) (((s8 *) arg0) + 0x4C))) & 2)
  {
    ((CameraViewParams *)(((u8 *) arg0) + 0x64))->apply_if_overridden();
  }
}

void TWindowMainMenu1P::render() {  }
void TWindowMainMenu1P::run_task() { handle_menu_selection(); sub_80263FE0(); update_backdrop_transition(); }

extern void *TWindowMainMenu1P__name;
extern const f32 lbl_805DD8CC;
extern const f32 lbl_805DD8D0;
extern const f32 lbl_805DD8D4;
extern const f32 lbl_805DD8D8;
TWindowMainMenu1P::~TWindowMainMenu1P() {
    if (*(s32 *)((s8 *)this + 0x4C) & 2) {
        end_view_override();
    }
}

void *TWindowMainMenu1P__ct(TWindowMainMenu1P *window_main_menu1_p) {
    TWindowMainMenu__ct(window_main_menu1_p);
    *(s32 **)((s8 *)window_main_menu1_p + 0x18) = __vt__17TWindowMainMenu1P;
    *(void * *)&window_main_menu1_p->m_name = TWindowMainMenu1P__name;
    *(u8 *)((s8 *)window_main_menu1_p + 0x60) = 0;
    *(u8 *)((s8 *)window_main_menu1_p + 0x61) = 0;
    window_main_menu1_p->m_6c = lbl_805DD8A8;
    *(f32 *)((s8 *)window_main_menu1_p + 0x70) = lbl_805DD8B0;
    window_main_menu1_p->m_8c = lbl_805DD8C4;
    *(f32 *)((s8 *)window_main_menu1_p + 0x90) = lbl_805DD8BC;
    window_main_menu1_p->m_94 = lbl_805DD8CC;
    *(f32 *)((s8 *)window_main_menu1_p + 0x98) = lbl_805DD8CC;
    window_main_menu1_p->m_9c = lbl_805DD8D0;
    *(f32 *)((s8 *)window_main_menu1_p + 0xA0) = lbl_805DD8D4;
    window_main_menu1_p->m_a4 = lbl_805DD8D8;
    *(f32 *)((s8 *)window_main_menu1_p + 0xA8) = lbl_805DD8C8;
    return window_main_menu1_p;
}

}
