
#include "types.h"
void *__ct__12TObjEneDD_STFP7TObject(void *);
s32 init_resources__13TBoss2DeRolLeFi(s32);
void *__ct__7TObjectFP7TObject(void *, void *);
s32 register_object__6TLobbyFl(s32);
s32 dispatch_shared_handler_b__6TLobbyFl(s32);
s32 register_boss__6TLobbyFl(s32);
void reset_hp__9TObjEneDDFPUcPUcPUc(u8 *, u8 *, u8 *, u8 *);
s32 dispatch_shared_handler_a__6TLobbyFl(s32);
void invoke_initialization_hook__9TObjEneDDFPv(u8 *, void *);
s32 exchange_object_state__9TObjEnemyFls(u8 *, s32, void *);
void init_position_vectors__9TObjEneDDFv(u8 *);
void *get_bml_model(void *, void *);
void *TObjFish__sub_8001EDB0(void *, void *);
void TObjPlayer__sub_802E7EA0(u8 *);
void copy_collision_body(void *, void *);
void set_collision_body__14TObjCollidableFPv(u8 *, void *);
void transform_part_positions__9TObjEneDDFv(u8 *);
void set_field_d8__10TObjMotionFl(u8 *, s32);
void set_field_dc__10TObjMotionFl(u8 *, s32);
void set_animation__10TObjMotionFs(u8 *, s16);
void set_field_b8__10TObjMotionFs(u8 *, s16);
void check_state_flag_2__9TObjEneDDFv(u8 *);
void initialize_enemy_state__9TObjEneDDFl(u8 *, s32);
void enemy_init_acquire_period__12TObjEneDD_STFl(u8 *, s32);
void enemy_init_validate_period__12TObjEneDD_STFl(u8 *, s32);
u32 __nw__7TObjectFUl(u32);
void *mem_alloc(s32);
void set_matrix_identity(void *);
u32 __ct__14TBoss7TentacleFP7TObjectll(u32, u8 *, s32, s32);
void VecCopy__FP3VecPC3Vec(void *, const void *);
u8 *TBoss7Joint__ct(u8 *, u8 *, s32, s16, s32, s32);
void init_float_block__13TBoss2DeRolLeFPv(u8 *);
u32 __ct__16TBoss7LaserLightFP7TObjectP3Vec(u32, u8 *, u8 *);
void *__nw__FUl(u32);
u32 __ct__17AreaAttackHistoryFl(u32, s32);
s32 fill_value_array(s32);
s32 is_main_phase_15__9TObjEneDDFv(u8 *);
s32 update_lobby_state__9TObjEneDDFv(u8 *);
void TBoss7DeRolLeC__sub_802EC994(u8 *);
u32 fn_8035A860(u32, u8 *, u32);
void set_field_38__14TBoss7DeRolLeCFl(u32, s32);
void TObjPlayer__sub_802E8274(void);
extern u8 lbl_804E3BF0[];
extern u32 TBoss7DeRolLeC__class_name;
extern u8 *boss7_joint_state;
extern u8 *lbl_805D6918;
extern u8 lbl_80473C3C[];
extern const f32 lbl_805DEA10;
extern const f32 lbl_805DEA30;
extern const u32 lbl_80473F6C[3];
extern u8 controller_input_state[];
struct Vec3 {
    u32 w0;
    u32 w1;
    u32 w2;
};
extern "C" {
extern "C" void *TBoss7DeRolLeC__ct(void *self_, void *arg1, void *arg2)
{
  Vec3 stack_vec;
  u8 *base = lbl_804E3BF0;
  u8 *self = (u8 *) self_;
  int new_var2;
  long long exch_slot;
  s32 off;
  int new_var;
  s32 i;
  u32 p;
  int new_var3[2];
  u32 flags;
  u32 v;
  __ct__12TObjEneDD_STFP7TObject(self);
  *((u32 *) (self + 0x18)) = (u32) (base + 0x264);
  init_resources__13TBoss2DeRolLeFi((s32) (self + 0x630));
  init_resources__13TBoss2DeRolLeFi((s32) (self + 0x650));
  init_resources__13TBoss2DeRolLeFi((s32) (self + 0x670));
  __ct__7TObjectFP7TObject(self + 0x690, 0);
  *((u32 *) self) = TBoss7DeRolLeC__class_name;
  if (boss7_joint_state == 0)
  {
    boss7_joint_state = self;
  }
  reset_hp__9TObjEneDDFPUcPUcPUc(self, (u8 *) register_boss__6TLobbyFl(0xF), (u8 *) dispatch_shared_handler_b__6TLobbyFl(0xF), (u8 *) register_object__6TLobbyFl(0xF));
  *((u32 *) (self + 0x620)) = (u32) dispatch_shared_handler_a__6TLobbyFl(0xF);
  invoke_initialization_hook__9TObjEneDDFPv(self, arg2);
  *((u32 *) (self + 0x628)) = 0;
  if (exchange_object_state__9TObjEnemyFls(self, 0, &exch_slot) != 0)
  {
    flags = exch_slot;
    if (((flags & 0x12008u) - 1u) == 0x2008u)
    {
      *((u32 *) (self + 0x628)) |= 0x8000u;
    }
  }
  init_position_vectors__9TObjEneDDFv(self);
  *((u32 *) (self + 0x34)) = (u32) get_bml_model(lbl_805D6918, 0);
  *((u32 *) (self + 0x24)) = (u32) TObjFish__sub_8001EDB0(lbl_805D6918, 0);
  TObjPlayer__sub_802E7EA0(self);
  copy_collision_body(self + 0x3C0, lbl_80473C3C);
  set_collision_body__14TObjCollidableFPv(self, self + 0x3C0);
  transform_part_positions__9TObjEneDDFv(self);
  *((u32 *) (self + 0xB0)) = 0;
  set_field_d8__10TObjMotionFl(self, (s32) (base + 0x13C));
  set_field_dc__10TObjMotionFl(self, *((s32 *) (lbl_805D6918 + 0x430)));
  *((s16 *) (self + 0xB8)) = 0;
  set_animation__10TObjMotionFs(self, *((s16 *) (self + 0xB8)));
  set_field_b8__10TObjMotionFs(self, *((s16 *) (self + 0xB8)));
  check_state_flag_2__9TObjEneDDFv(self);
  *((u32 *) (self + 0x350)) = (u32) (base + 0x9C);
  new_var = 0x49;
  initialize_enemy_state__9TObjEneDDFl(self, new_var);
  *((f32 *) (self + 0x37C)) = lbl_805DEA30;
  enemy_init_acquire_period__12TObjEneDD_STFl(self, 0x1E);
  enemy_init_validate_period__12TObjEneDD_STFl(self, 0x1E);
  *((u32 *) (self + 0x7A8)) = 0;
  p = __nw__7TObjectFUl(0x1C);
  if (p != 0)
  {
    p = (u32) __ct__7TObjectFP7TObject((void *) p, self);
  }
  *((u32 *) (self + 0x7A4)) = p;
  *((u32 *) (self + 0x62C)) = 0;
  *((u32 *) (self + 0x6B0)) = 0;
  *((u32 *) (self + 0x6B4)) = 0;
  for (off = 0; off < 0xF0; off += 0xC)
  {
    *((f32 *) (((u32) self) + (off + 0x3EC))) = lbl_805DEA10;
    *((f32 *) (((u32) self) + (off + 0x3F0))) = lbl_805DEA10;
    *((f32 *) (((u32) self) + (off + 0x3F4))) = lbl_805DEA10;
  }

  for (off = 0; off < 0x30; off += 0xC)
  {
    *((f32 *) (((u32) self) + (off + 0x4E4))) = (*((f32 *) (((u32) self) + (off + 0x4E0))) = (*((f32 *) (((u32) self) + (off + 0x4DC))) = lbl_805DEA10));
  }

  *((u32 *) (self + 0x6D8)) = (u32) mem_alloc(0xC0);
  for (i = 0; i < 4; i++)
  {
    set_matrix_identity((void *) ((*((s32 *) (self + 0x6D8))) + (i * 0x30)));
    p = __nw__7TObjectFUl(0x16C);
    if (p != 0)
    {
      p = __ct__14TBoss7TentacleFP7TObjectll(p, self + 0x690, (*((s32 *) (self + 0x6D8))) + (i * 0x30), i);
    }
    *((u32 *) ((self + 0x6DC) + (i * 4))) = p;
  }

  stack_vec.w0 = lbl_80473F6C[0];
  stack_vec.w1 = lbl_80473F6C[1];
  stack_vec.w2 = lbl_80473F6C[2];
  new_var3[0] = (u32) ((*((u16 *) (self + 0x1C))) + 1);
  new_var3[1] = (*((s16 *) (self + 0x2C))) + 1;
  for (i = 0; i < 10; i++)
  {
    VecCopy__FP3VecPC3Vec(self + ((i * 0xC) + 0x530), &stack_vec);
    p = __nw__7TObjectFUl(0x3C8);
    if (p != 0)
    {
      new_var2 = (s16) new_var3[1];
      new_var3[0] = new_var3[0] + 1;
      new_var3[1] = new_var3[1] + 1;
      p = (u32) TBoss7Joint__ct((u8 *) p, self, ((s32) new_var3[0]) & 0xFFFF, new_var2, (s32) (self + ((((((((((i & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) * 0xC) + 0x530)), i);
    }
    *((u32 *) ((self + 0x5F8) + (i * 4))) = p;
  }

  *((u32 *) (self + 0x6C0)) = 0;
  *((u32 *) (self + 0x6C4)) = 0;
  *((u32 *) (self + 0x6C8)) = 0;
  *((u32 *) (self + 0x6CC)) = 0;
  *((u32 *) (self + 0x6D0)) = 0;
  init_float_block__13TBoss2DeRolLeFPv(self + 0x630);
  init_float_block__13TBoss2DeRolLeFPv(self + 0x650);
  init_float_block__13TBoss2DeRolLeFPv(self + 0x670);
  *((f32 *) (self + 0x6EC)) = lbl_805DEA10;
  *((f32 *) (self + 0x6F0)) = lbl_805DEA10;
  *((f32 *) (self + 0x6F4)) = lbl_805DEA10;
  v = *((u32 *) ((*((u32 *) (self + 0x620))) + 0x18));
  *((u32 *) (self + 0x6FC)) = v;
  *((u32 *) (self + 0x6F8)) = v;
  *((u32 *) (self + 0x700)) = *((u32 *) ((*((u32 *) (self + 0x620))) + 0x20));
  *((s16 *) (self + 0x32C)) = 0x4E20;
  *((s16 *) (self + 0x2B8)) = 0x4E20;
  *((u32 *) (self + 0x704)) = 0;
  p = __nw__7TObjectFUl(0x44);
  if (p != 0)
  {
    p = __ct__16TBoss7LaserLightFP7TObjectP3Vec(p, self + 0x690, self + 0x70C);
  }
  *((u32 *) (self + 0x708)) = p;
  *((f32 *) (self + 0x70C)) = lbl_805DEA10;
  *((f32 *) (self + 0x710)) = lbl_805DEA10;
  *((f32 *) (self + 0x714)) = lbl_805DEA10;
  p = (u32) __nw__FUl(0x10);
  if (p != 0)
  {
    p = __ct__17AreaAttackHistoryFl(p, 4);
  }
  *((u32 *) (self + 0x718)) = p;
  fill_value_array((s32) (*((u32 *) (self + 0x718))));
  *((u32 *) (self + 0x71C)) = 0;
  *((u32 *) (self + 0x720)) = 0;
  for (i = 0; i < 3; i++)
  {
    VecCopy__FP3VecPC3Vec((self + 0x50C) + (i * 0xC), self + 0x38);
  }

  *((u32 *) (self + 0x6BC)) = 0;
  *((u32 *) (self + 0x6D4)) = (u32) mem_alloc(0x240);
  for (i = 0; i < 12; i++)
  {
    set_matrix_identity((void *) ((*((u32 *) (self + 0x6D4))) + (i * 0x30)));
  }

  for (i = 0; i < 6; i++)
  {
    *((u32 *) ((self + 0x788) + (i * 4))) = 0;
  }

  *((u32 *) (self + 0x7A0)) = 0;
  *((u32 *) (self + 0x724)) = 0;
  *((u32 *) (self + 0x728)) = 0;
  *((u32 *) (self + 0x72C)) = 0;
  *((u32 *) (self + 0x730)) = 0;
  *((u32 *) (self + 0x734)) = 0;
  *((u32 *) (self + 0x738)) = 0;
  *((u32 *) (self + 0x73C)) = 0;
  *((u32 *) (self + 0x740)) = 0;
  *((f32 *) (self + 0x744)) = lbl_805DEA10;
  *((f32 *) (self + 0x748)) = lbl_805DEA10;
  *((f32 *) (self + 0x74C)) = lbl_805DEA10;
  *((f32 *) (self + 0x750)) = lbl_805DEA10;
  *((f32 *) (self + 0x754)) = lbl_805DEA10;
  *((f32 *) (self + 0x758)) = lbl_805DEA10;
  *((f32 *) (self + 0x75C)) = lbl_805DEA10;
  *((f32 *) (self + 0x760)) = lbl_805DEA10;
  *((f32 *) (self + 0x764)) = lbl_805DEA10;
  *((f32 *) (self + 0x768)) = lbl_805DEA10;
  *((f32 *) (self + 0x76C)) = lbl_805DEA10;
  *((f32 *) (self + 0x770)) = lbl_805DEA10;
  *((f32 *) (self + 0x774)) = lbl_805DEA10;
  *((f32 *) (self + 0x778)) = lbl_805DEA10;
  *((f32 *) (self + 0x77C)) = lbl_805DEA10;
  *((f32 *) (self + 0x780)) = lbl_805DEA10;
  *((u32 *) (((u8 *) self_) + 0x784)) = 0;
  *((u32 *) (((u8 *) self_) + 0x6AC)) = 0;
  *((u32 *) (((u8 *) self_) + 0x624)) = (u32) (&controller_input_state[0x70]);
  if (!(is_main_phase_15__9TObjEneDDFv((u8 *) self_) == 0))
  {
    if (!(update_lobby_state__9TObjEneDDFv((u8 *) self_) == 0))
    {
      *((u32 *) (((u8 *) self_) + 0x6B8)) = 0;
    }
    else
    {
      *((u32 *) (((u8 *) self_) + 0x6B8)) = 1;
    }
  }
  else
  {
    *((u32 *) (((u8 *) self_) + 0x6B8)) = 0;
  }
  TBoss7DeRolLeC__sub_802EC994((u8 *) self_);
  if (((*((u32 *) (((u8 *) self_) + 0x628))) & 0x8000u) == 0)
  {
    *((s16 *) (((u8 *) self_) + 0x326)) = 1;
    do
    {
      (*((void (**)(u8 *, s16, s32)) ((*((u32 *) (((u8 *) self_) + 0x18))) + 0x15C)))((u8 *) self_, *((s16 *) (((u8 *) self_) + 0x326)), 4);
    }
    while (0);
  }
  p = __nw__7TObjectFUl(0x3C);
  if (p != 0)
  {
    p = fn_8035A860(p, self, *((u32 *) (self + 0x34)));
  }
  *((u32 *) (((u8 *) self_) + 0x7AC)) = p;
  if ((*((u32 *) (((u8 *) self_) + 0x7AC))) != 0)
  {
    set_field_38__14TBoss7DeRolLeCFl(*((u32 *) (((u8 *) self_) + 0x7AC)), (s32) TObjPlayer__sub_802E8274);
  }
  *((u32 *) (((u8 *) self_) + 0x7B0)) = 0;
  *((f32 *) (((u8 *) self_) + 0x7B4)) = lbl_805DEA10;
  *((f32 *) (((u8 *) self_) + 0x7B8)) = lbl_805DEA10;
  *((f32 *) (((u8 *) self_) + 0x7BC)) = lbl_805DEA10;
  *((f32 *) (((u8 *) self_) + 0x7C0)) = lbl_805DEA10;
  *((f32 *) (((u8 *) self_) + 0x7C4)) = lbl_805DEA10;
  *((f32 *) (((u8 *) self_) + 0x7C8)) = lbl_805DEA10;
  *((u16 *) (((u8 *) self_) + 0x7CC)) = 0xFFFF;
  *((u16 *) (((u8 *) self_) + 0x7CE)) = 0xFFFF;
  *((u16 *) (((u8 *) self_) + 0x7D0)) = 0xFFFF;
  *((u16 *) (((u8 *) self_) + 0x7D2)) = 0xFFFF;
  return (u8 *) self_;
}

}

