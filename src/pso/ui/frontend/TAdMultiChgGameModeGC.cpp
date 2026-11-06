#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801334D4.h"

#include "types.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_802FFCE4_lbl_8050E208
{
  s32 value;
  u8 remaining[0x1AC];
};

struct RecoveredFields_802FFCE4_arg0
{
  u8 unknown_0[0x20];
  s32 field_20;
  s32 field_24;
  s32 field_28;
  s32 field_2C;
};

struct Txt_802FFE58 { s32 v[9]; };

struct Pos_802FFE58 { s32 v[6]; };

struct Cur_802FFE58 { s32 v[2]; };

struct Obj_802FFE58 {
    s32 f0;
    u8 pad4[0x14];
    void *vt;
    s32 f1C;
    s32 f20;
    s32 f24;
    void *f28;
    void *f2C;
};

extern "C" {
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
extern RecoveredGlobal_802FFCE4_lbl_8050E208 controller_input_state;
extern s32 lbl_805D69E8;
void *__nw__7TObjectFUl(u32);
void __ct__7TObjectFP7TObject(void *);
void __ct__9TAdBackGCFv(void *, void *);
void __ct__12TAdBackTxtGCFv(void *, void *);
void __ct__8TAdRayGCFv(void *, void *);
void __ct__10TAdTitleGCFP7TObjectl(void *, void *, s32);
void __ct__14TAdSelectTxtGCFP7TObjectPvPv(void *, void *, void *, s32);
void __ct__13TAdTitleTexGCFv(void *, void *);
void *__ct__14TAdSelectCurGCFv(void *, void *, void *, void *);
void *__ct__13TAdGuideTxtGCFv(void *, void *);
extern Txt_802FFE58 multi_chg_game_mode_text_layout;
extern Cur_802FFE58 lbl_80474E1C[];
extern Pos_802FFE58 multi_chg_game_mode_position_table;
extern void *__vt__21TAdMultiChgGameModeGC[];
extern s32 TAdMultiChgGameModeGC__name;
Obj_802FFE58 *__ct__21TAdMultiChgGameModeGCFv(Obj_802FFE58 *self);
s32 is_multiplayer_character_slot_selected(u32);
s32 TAdMultiPlyChrSelectGC__sub_802C658C(u32);

void fn_802FFC78(void) {  }
void fn_802FFC7C(void) {  }
void TAdMultiChgGameModeGC::render() {  }
s32 TAdMultiChgGameModeGC::check_players_ready(void * _w0) {
    u32 var_r31;

    var_r31 = 0U;
loop_1:
    if ((is_multiplayer_character_slot_selected(var_r31) != 0) && (TAdMultiPlyChrSelectGC__sub_802C658C(var_r31) > 3)) {
        return 1;
    }
    var_r31 += 1;
    if (var_r31 >= 4U) {
        return 0;
    }
    goto loop_1;
}
typedef struct RecoveredFields_802FFCE4_arg0 RecoveredFields_802FFCE4_arg0;
typedef struct RecoveredGlobal_802FFCE4_lbl_8050E208 RecoveredGlobal_802FFCE4_lbl_8050E208;
void TAdMultiChgGameModeGC::run_task() {
    RecoveredFields_802FFCE4_arg0 *arg0 = (RecoveredFields_802FFCE4_arg0 *)this;
  s32 *new_var;
  s32 temp_r4;
  TAdMultiChgGameModeGC::set_default_camera();
  arg0->field_20 = TAdSinglePlyChrSelectGC__sub_801334DC((void *)arg0->field_2C);
  temp_r4 = arg0->field_20;
  new_var = &arg0->field_2C;
  if (((s32) arg0->field_24) != temp_r4)
  {
    ((TAdMultiPlyChrSelectGC *)((int) arg0->field_28))->set_entry_value(0, (int) get_localized_text_entry(0x21, arg0->field_20));
  }
  if ((TWindowShortListCtrl__check_controller_button((void *) (((u8 *)&controller_input_state.value) + 0x20), 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) (((u8 *)&controller_input_state.value) + 0x160), 2) != 0))
  {
    TAdMultiChgGameModeGC::request_scene_change();
  }
  else
    if (1 == ((TAdSinglePlyChrSelectGC *)((int) arg0->field_2C))->get_selected_slot())
  {
    switch (TAdSinglePlyChrSelectGC__sub_801334DC((void *)(*new_var)))
    {
      case 0:
        TAdMultiChgGameModeGC::set_mode_state_0d();
        break;
      case 1:
        TAdMultiPlyChrSelectGC::reset_slot_selections();
        lbl_805D69E8 = 1;
        TAdMultiChgGameModeGC::set_mode_18();
        break;
      case 2:
        if (TAdMultiChgGameModeGC::check_players_ready((void *)((void *) ((u8 *) arg0))) != 0)
      {
        TAdMultiChgGameModeGC::set_mode_state_0e();
      }
      else
      {
        TAdMultiChgGameModeGC::request_scene_change();
      }
        break;
    }
  }
  arg0->field_24 = (s32) arg0->field_20;
}
TAdMultiChgGameModeGC::~TAdMultiChgGameModeGC() {}
Obj_802FFE58 *__ct__21TAdMultiChgGameModeGCFv(Obj_802FFE58 *self) {
    void *p;
    __ct__7TObjectFP7TObject(self);
    self->vt = __vt__21TAdMultiChgGameModeGC;
    self->f0 = TAdMultiChgGameModeGC__name;
    self->f1C = 0;
    self->f20 = 2;
    self->f24 = -1;
    self->f28 = 0;
    self->f2C = 0;
    if ((p = __nw__7TObjectFUl(0x24)) != NULL) {
        __ct__9TAdBackGCFv(p, self);
    }
    if ((p = __nw__7TObjectFUl(0x28)) != NULL) {
        __ct__12TAdBackTxtGCFv(p, self);
    }
    if ((p = __nw__7TObjectFUl(0x24)) != NULL) {
        __ct__8TAdRayGCFv(p, self);
    }
    if ((p = __nw__7TObjectFUl(0x138)) != NULL) {
        __ct__10TAdTitleGCFP7TObjectl(p, self, 0xF);
    }
    {
        Txt_802FFE58 txt = multi_chg_game_mode_text_layout;
        if ((p = __nw__7TObjectFUl(0xE0)) != NULL) {
            __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &txt.v[0], 0xC);
        }
        if ((p = __nw__7TObjectFUl(0xE0)) != NULL) {
            __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &txt.v[3], 0xD);
        }
        if ((p = __nw__7TObjectFUl(0xE0)) != NULL) {
            __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &txt.v[6], 0xE);
        }
        if ((p = __nw__7TObjectFUl(0x9C)) != NULL) {
            __ct__13TAdTitleTexGCFv(p, self);
        }
        {
            Cur_802FFE58 cur = lbl_80474E1C[0];
            Pos_802FFE58 pos = multi_chg_game_mode_position_table;
            p = __nw__7TObjectFUl(0x708);
            if (p != NULL) {
                p = __ct__14TAdSelectCurGCFv(p, self, &pos, &cur);
            }
            self->f2C = p;
            ((TLevelSelect *)(self->f2C))->add_item_rect(&pos.v[0]);
            ((TLevelSelect *)(self->f2C))->add_item_rect(&pos.v[2]);
            ((TLevelSelect *)(self->f2C))->add_item_rect(&pos.v[4]);
        }
    }
    ((TLobby *)(self->f2C))->set_ad_field(self->f20);
    p = __nw__7TObjectFUl(0x44);
    if (p != NULL) {
        p = __ct__13TAdGuideTxtGCFv(p, self);
    }
    self->f28 = p;
    create_draw_line_ctrl__13TAdMcSelectGCFiif((s32)self, 0xF, 0.0f);
    return self;
}

}
