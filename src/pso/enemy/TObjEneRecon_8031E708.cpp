#include "types.h"
#include "pso/enemy/TObjEneRecon_8031FCB0.h"
#include "pso/enemy/TObjEneRecon_8031BC38.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Stack_8031E708
{
  s32 sp8;
  s32 spC;
  s32 sp10;
  s32 sp14;
};

struct RecoveredGlobal_8031E708_lbl_804760EC
{
  s32 value;
  u8 remaining[0xC];
};

struct RecoveredGlobal_8031E708_lbl_804EC40C
{
  s32 value;
  u8 remaining[0x28];
};

struct RecoveredFields_8031E708_TObjEneRecon__data_805D6B00
{
  u8 unknown_0[0x42C];
  u8 *field_42C;
  s32 field_430;
};

struct RecoveredFields_8031E708_temp_r5
{
  u8 unknown_0[0x8];
  s32 field_8;
  s32 field_C;
};

extern "C" {
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
s32 init_from_model__11TBreakUpMdlFl(int, void *);
extern RecoveredGlobal_8031E708_lbl_804760EC recon_anim_binding;
extern RecoveredGlobal_8031E708_lbl_804EC40C TObjEneRecon__collision_body_template;
extern s32 lbl_805D6AF0;
extern s32 TObjEneRecon__attack_params;
extern s32 TObjEneRecon__resistance_params;
extern s32 TObjEneRecon__data_805D6AFC;
extern u8 *TObjEneRecon__recobox_static_instance;
extern s32 boss3_volopt_instance;
extern s32 recon_intro_stage;
extern s32 recon_model_matrix_ptr;
extern const f32 TObjEneRecon__data_805DF3C0;
typedef struct RecoveredFields_8031E708_TObjEneRecon__data_805D6B00 RecoveredFields_8031E708_TObjEneRecon__data_805D6B00;
typedef struct RecoveredFields_8031E708_temp_r5 RecoveredFields_8031E708_temp_r5;
typedef struct RecoveredGlobal_8031E708_lbl_804760EC RecoveredGlobal_8031E708_lbl_804760EC;
typedef struct RecoveredGlobal_8031E708_lbl_804EC40C RecoveredGlobal_8031E708_lbl_804EC40C;
typedef struct Stack_8031E708 Stack_8031E708;
typedef char RecoveredGlobal_8031E708_lbl_804760EC_size[((sizeof(RecoveredGlobal_8031E708_lbl_804760EC)) == 0x10) ? (1) : (-1)];
typedef char RecoveredGlobal_8031E708_lbl_804EC40C_size[((sizeof(RecoveredGlobal_8031E708_lbl_804EC40C)) == 0x2C) ? (1) : (-1)];
void TObjEneRecon::load_resources() {
  Stack_8031E708 stack;
  s32 temp_r3;
  s32 var_r4;
  u8 *temp_r5;
  TObjEneRecon__recobox_static_instance = (u8 *)TObjEneRecobox__sub_803201D0();
  temp_r3 = (var_r4 = (int)::operator new(0x10));
  if (var_r4 != 0)
  {
    var_r4 = init_from_model__11TBreakUpMdlFl((int) temp_r3, (void *) (*((s32 *) (((s8 *) ((RecoveredFields_8031E708_TObjEneRecon__data_805D6B00 *) TObjEneRecon__recobox_static_instance)->field_42C) + 8))));
  }
  boss3_volopt_instance = var_r4;
  recon_intro_stage = 0;
  recon_model_matrix_ptr = 0;
  lbl_805D6AF0 = register_boss__6TLobbyFl(0x42);
  TObjEneRecon__attack_params = dispatch_shared_handler_b__6TLobbyFl(0x42);
  TObjEneRecon__resistance_params = register_object__6TLobbyFl(0x42);
  TObjEneRecon__data_805D6AFC = dispatch_shared_handler_a__6TLobbyFl(0x42);
  TObjEneRecon__sub_8031BC94();
  stack.sp8 = *((s32 *) (((s8 *)&recon_anim_binding.value) + 0));
  stack.spC = *((s32 *) (((s8 *)&recon_anim_binding.value) + 4));
  stack.sp10 = *((s32 *) (((s8 *)&recon_anim_binding.value) + 8));
  stack.sp14 = *((s32 *) (((s8 *)&recon_anim_binding.value) + 0xC));
  stack.sp8 = ((RecoveredFields_8031E708_TObjEneRecon__data_805D6B00 *) TObjEneRecon__recobox_static_instance)->field_430;
  temp_r5 = (u8 *) ((RecoveredFields_8031E708_TObjEneRecon__data_805D6B00 *) TObjEneRecon__recobox_static_instance)->field_42C;
  TLobby::spawn_npc_enemy((s16)(0xC), (s32)((int) ((RecoveredFields_8031E708_temp_r5 *) temp_r5)->field_8), (s32)((int) ((RecoveredFields_8031E708_temp_r5 *) temp_r5)->field_C), (s32)((void *)&stack.sp8), (f32)((f32) (*((f32 *) (((s8 *)&TObjEneRecon__collision_body_template.value) + 0xC)))), (f32)((f32) TObjEneRecon__data_805DF3C0));
}

}
