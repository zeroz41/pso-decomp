// ---- pso/misc/TLobby_80335E08 [0x80335E7C-0x80336054): separate TU (own .sdata2 pool 0x805DF8C8-0x805DF8E8)
#include "types.h"
#include "pso/misc/TUnk_804EE470.h"
#include "pso/ui/TUnk_804EE458.h"
#include "pso/misc/TLobby_80335E08.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/TAdTrialAgreementGC_80335958.h"


#include "pso/misc/TLobby.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"

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

struct RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270 {
    s32 value;
    u8 remaining[0xAC];
};

struct RecoveredGlobal_8000F7FC_lbl_80515F48 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_8000F9E4_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F90C_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F9CC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F8FC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F8EC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F91C_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
extern s32 __vt__13TUnk_804EE470[];
    extern unsigned char lobby_record_table[];
s32 TCameraCtrl__sub_80068EF0();








extern RecoveredGlobal_8000F7FC_lbl_80515F48 title_texture_list;

    
    
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
  draw_textured_quad_at_depth((&stack.sp8), (f32) 0.1f);
  set_draw_texture_and_color(2, -1);
  stack.sp8 = 3.2e+02f;
  stack.spC = 61.0f;
  stack.sp10 = 576.0f;
  stack.sp14 = 317.0f;
  draw_textured_quad_at_depth((&stack.sp8), (f32) 0.1f);
  TWindowSubStatusDisp::get_player();
  TCameraCtrl__sub_80068EF0();
  TParticleCtrl::end_effect_render();
}

void TUnk_804EE470::run_task() {  }
void *TUnk_804EE470::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804EE470;
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
TUnk_804EE470::TUnk_804EE470(TObject *arg1) : TObject(arg1) {
    *(void * *)&this->unk_1C = arg1;
}

void TLobby__sub_80335FE0(void) {  }
void TLobby__sub_80335FE4(void) {  }

void *get_title_texture_list(void) {
    return ((char *)&title_texture_list);
}

void*TLobby::get_record(int a0) {  return (char*)lobby_record_table + a0 * 32; }

typedef char RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270_size[sizeof(RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270) == 0xB0 ? 1 : -1];
typedef char RecoveredGlobal_8000F7FC_lbl_80515F48_size[sizeof(RecoveredGlobal_8000F7FC_lbl_80515F48) == 0x28 ? 1 : -1];
void bind_title_texture_list(void) {
    set_texlist((u32)&title_texture_list.value);
}
typedef char RecoveredGlobal_8000F90C_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F90C_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F8FC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F8FC_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F8EC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F8EC_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F91C_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F91C_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F9E4_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F9E4_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F9CC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F9CC_lbl_804FE120) == 0x18 ? 1 : -1];

int TLobby__sub_80336030(void* p) { return ((TUnk_804EE458 *)(*(void**)((char*)p + 0x24)))->sub_8033596C(); }
