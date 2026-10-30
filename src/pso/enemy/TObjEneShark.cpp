#include "pso/misc/MaterialOpacityFade.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/unk/TUnk_80494968.h"
#include "pso/enemy/TObjEneRe7Berura_803E4CE0.h"
#include "types.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEneMoja.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/enemy/TObjEneSaver.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneShark.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"

extern "C" void test_flag_256__13TUnk_80493450Fv();

#include <stddef.h>
struct Stack_800ABA9C {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_800ABA9C_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
typedef char RecoveredGlobal_800ABA9C_lbl_8058D490_size[sizeof(RecoveredGlobal_800ABA9C_lbl_8058D490) == 0x30 ? 1 : -1];

struct Obj_800ABCBC { u8 pad0[0x38]; u8 sub38[0x326 - 0x38]; s16 f326; s16 state; u8 pad32a[0x390 - 0x32A]; s32 f390; };

struct RecoveredGlobal_800ABA9C_lbl_8058D490;
typedef struct Vec_800AB31C {
    f32 x, y, z;
} Vec_800AB31C;

typedef struct Rot_800AB31C {
    s32 x, y, z;
} Rot_800AB31C;

typedef struct Obj_800AB31C {
    u8 pad0[0x18];
    void *vptr;
    Vec_800AB31C pos;
    Vec_800AB31C pos2;
    u8 mtx34[0x58 - 0x34];
    f32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
} Obj_800AB31C;

typedef struct Vec_800ABB38 {
    f32 x, y, z;
} Vec_800ABB38;

struct VBase_800ABB38 { char pad[0x18]; };

struct VObj_800ABB38 : VBase_800ABB38 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(Vec_800ABB38 *, Vec_800ABB38 *);
};

typedef struct Obj_800ABB38 {
    u8 pad0[0x38];
    Vec_800ABB38 pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0xB8 - 0x64];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x3C4 - 0xC4];
    VObj_800ABB38 *effs[2];
} Obj_800ABB38;

typedef struct Pair_800AB0EC {
    s32 a;
    f32 b;
} Pair_800AB0EC;

typedef struct Obj_800AB0EC {
    u8 pad0[0x1C];
    u8 pos[0x64 - 0x1C];
    s32 f64;
    s32 f68;
} Obj_800AB0EC;

struct VBase_14_800ABDD8
{
  char pad[0x14];
};

struct VBase_18_800ABDD8
{
  char pad[0x18];
};

struct VObj_18_800ABDD8 : VBase_18_800ABDD8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual s32 m9(f32, f32, f32);
};

struct Owner_800ABDD8
{
  u8 pad[0x3CC];
  RenderFadeState fades[4];
};

struct Vec_800ABDD8
{
  f32 x;
  f32 y;
  f32 z;
};

extern "C" {
s32 post_translate_matrix(void *);
s32 draw_chunk_object(s32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
extern s32 model_render_flags;
void __dl__7TObjectFPv(void *);
void vfunc_101__12TObjEneSharkFv(void);
extern s32 shark_render_node_index;
s32 vec3_add_to(void *, void *);
s32 play_sound_effect(void *, void *, int, int);
void vfunc_96__12TObjEneSharkFv(s32 arg0);
void vfunc_98__12TObjEneSharkFv(s32 arg0);
void vfunc_97__12TObjEneSharkFv(s32 arg0);
void vfunc_95__12TObjEneSharkFv(s32 arg0);
void TObjPlayer__sub_800D92BC(s32 point, s32 delay);
s32 rotate_vector_by_matrix(int, void *, void *);
extern RecoveredGlobal_800ABA9C_lbl_8058D490 identity_matrix;
extern const f32 lbl_805D9BA0;
extern const f32 lbl_805D9BA4;
extern const f32 lbl_805D9BA8;
void vfunc_94__12TObjEneSharkFv(u8 *arg0);
void vfunc_83__12TObjEneSharkFv(Obj_800ABCBC *arg0);
s32 mult_vec_array__10TObjPlayerFUll(int, int, void *, int);
void set_matrix_identity(u8 *arg0);
extern u32 TObjEneShark__attack_motion_3_trail;
extern u32 shark_attack4_trail_buffer;
extern const f32 lbl_805D9BAC;
void vfunc_93__12TObjEneSharkFv(Obj_800ABB38 *o);
void *__nw__7TObjectFUl(int);
s32 is_split_screen();
s32 get_camera_mode__11TCameraCtrlFv();
s32 update__15RenderFadeStateFv(void *);
s32 restore_scene_lighting();
s32 select_actor_lighting(void *);
s32 defer_render__7TObjectFv(void *);
s32 translate_matrix(s32, f32, f32, f32);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern const f32 lbl_805D9BB0;
extern const f32 lbl_805D9BB4;
extern const f32 lbl_805D9BB8;
extern const f32 lbl_805D9BBC;
extern const f32 lbl_805D9BC0;
extern const f32 lbl_805D9BC4;

#pragma push
#pragma fp_contract on
#pragma pop

void TObjEneShark::vfunc_101() {  }

void TObjEneShark::vfunc_98() {
    s32 arg0 = (s32)this;
    play_sound_effect((void *) (((TObjEnemy *)((void *)arg0))->remap_sound_for_area((s32)(0x4003A60C))), (void *)(arg0 + 0x38), 0, 0);
    TObjPlayer::play_effect_if_v2(-0x300);
}

void TObjEneShark::vfunc_97() {
    s32 arg0 = (s32)this;
    play_sound_effect((void *) (((TObjEnemy *)((void *)arg0))->remap_sound_for_area((s32)(0x4003A60B))), (void *)(arg0 + 0x38), 0, 0);
    TObjPlayer::play_effect_if_v2(-0x300);
}

void TObjEneShark::vfunc_96() {
    s32 arg0 = (s32)this;
    play_sound_effect((void *) (((TObjEnemy *)((void *)arg0))->remap_sound_for_area((s32)(0x4003A60D))), (void *)(arg0 + 0x38), 0, 0);
}

void TObjEneShark::vfunc_95() {
    s32 arg0 = (s32)this;
    play_sound_effect((void *) (((TObjEnemy *)((void *)arg0))->remap_sound_for_area((s32)(0x4003A60B))), (void *)(arg0 + 0x38), 0, 0);
    TObjPlayer::play_effect_if_v2(-0x300);
}

void TObjEneShark::vfunc_94() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_800ABA9C, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800ABA9C, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800ABA9C, sp10) == 0x8) ? 1 : -1];
    Stack_800ABA9C stack;
    stack.sp8 = lbl_805D9BA0;
    stack.spC = lbl_805D9BA4;
    stack.sp10 = lbl_805D9BA8 * *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x2B0)) + 0x10);
    push_matrix_from(&identity_matrix.value);
    rotate_matrix_y(0, this->rotation_y);
    rotate_vector_by_matrix(0, &stack.sp8, &stack.sp8);
    pop_matrix();
    vec3_add_to(&stack.sp8, (u8 *)&this->position);
    ((TObjPlayer *)(&stack.sp8))->spawn_ground_effect(0x23);
    TObjPlayer__sub_800D92BC((s32)&stack.sp8, 0xF);
}

void TObjEneShark::vfunc_93() {
    Obj_800ABB38 *o = (Obj_800ABB38 *)this;
    Vec_800ABB38 b;
    Vec_800ABB38 a;
    u32 e;
    s32 idx;
    VObj_800ABB38 *eff;
    if (!(this->m_c0 < lbl_805D9BAC)) {
        return;
    }
    switch (this->m_b8) {
    case 3:
        e = TObjPlayer::lookup_entry_by_value((void *)TObjEneShark__attack_motion_3_trail, this->m_c0);
        idx = 0;
        break;
    case 4:
        e = TObjPlayer::lookup_entry_by_value((void *)shark_attack4_trail_buffer, this->m_c0);
        idx = 1;
        break;
    default:
        e = 0;
        break;
    }
    if (e == 0) {
        return;
    }
    push_matrix();
    set_matrix_identity(0);
    post_translate_matrix(&o->pos);
    rotate_matrix_y(0, this->rotation_y);
    mult_vec_array__10TObjPlayerFUll(0, e, &a, 2);
    pop_matrix();
    eff = o->effs[idx];
    if (eff != NULL) {
        eff->m4(&a, &b);
    }
}

void TObjEneShark::apply_clamped_mode_param() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x334);
    if (temp_r0 < 0) {
        *(s32 *)((s8 *)arg0 + 0x334) = 0;
    } else if (temp_r0 > 2) {
        *(s32 *)((s8 *)arg0 + 0x334) = 2;
    }
    switch (*(s32 *)((s8 *)arg0 + 0x334)) {
    case 2:
        *(s32 *)((s8 *)arg0 + 0x368) = 1;
        ((TObjEnemy *)arg0)->set_param(0x12);
        return;
    case 1:
        *(s32 *)((s8 *)arg0 + 0x368) = 0;
        ((TObjEnemy *)arg0)->set_param(0x11);
        return;
    default:
        *(s32 *)((s8 *)arg0 + 0x368) = 2;
        ((TObjEnemy *)arg0)->set_param(0x10);
        return;
    }
}

void TObjEneShark::vfunc_83() {
    Obj_800ABCBC *arg0 = (Obj_800ABCBC *)this;
    ((TObjMotion *)this)->advance_animation();
    switch (*(s16 *)&this->m_328) {
    case 0:
    default:
        if (*(s32 *)&this->m_390 != 0) {
            ((TObjEneShark *)arg0)->fade.start_fade_in();
            ((TBoss3Volopt *)(arg0->sub38))->play_area_sound_effect();
            *(s16 *)&this->m_328 = 1;
        } else {
            *(s16 *)&this->m_328 = 2;
        }
        break;
    case 1:
        if (((TObjEneShark *)arg0)->fade.advance_toward_max() == 1) {
            *(s16 *)&this->m_328 = 2;
            *(s32 *)&this->m_390 = 0;
        }
        break;
    case 2:
        this->action = 1;
        *(s16 *)&this->m_328 = 0;
        break;
    }
}

void TObjPlayer::update_particle_by_phase() {
    switch (shark_render_node_index) {
    case 0x10:
    case 0x1A:
    case 0x20:
        TParticleCtrl::begin_effect_render();
        break;
    default:
        TParticleCtrl::end_effect_render();
        break;
    }
    shark_render_node_index += 1;
}
typedef struct RenderFadeState RenderFadeState;
typedef struct Owner_800ABDD8 Owner_800ABDD8;
typedef struct VBase_14_800ABDD8 VBase_14_800ABDD8;
typedef struct VBase_18_800ABDD8 VBase_18_800ABDD8;
typedef struct MaterialColorFade MaterialColorFade;
typedef struct VObj_18_800ABDD8 VObj_18_800ABDD8;
typedef struct Vec_800ABDD8 Vec_800ABDD8;
#define PSO_VCALL_VObj_18_800ABDD8_m9(_self, _arg0, _arg1, _arg2) (((VObj_18_800ABDD8 *)(_self))->m9((_arg0), (_arg1), (_arg2)))
}

void TObjEneShark::render() {
  s32 res;
  s32 mode;
  s32 fade;
  s32 v28;
  s16 v27;
  s16 v26;
  u8 *arg0 = (u8 *)this;
  if ((*(s32 *)&this->m_30) & 0x02000000)
  {
    return;
  }
  mode = 0;
  if (is_split_screen() != 0)
  {
    mode = get_camera_mode__11TCameraCtrlFv();
  }
  res = PSO_VCALL_VObj_18_800ABDD8_m9(arg0, lbl_805D9BB0, lbl_805D9BB4, lbl_805D9BB8);
  if (res == 0)
  {
    return;
  }
  fade = 0;
  if (TObjEneDD::check_v2_mode() != 0)
  {
    u8 *f = (u8 *) (&((Owner_800ABDD8 *) arg0)->fades[mode]);
    update__15RenderFadeStateFv(f);
    fade = ((RenderFadeState *)f)->updateFromCamera((const f32*)(arg0 + 0x2FC));
  }
  select_actor_lighting(arg0);
  model_render_flags |= 1;
  TObjFish::set_global_param(*((s32 *) (((s8 *) arg0) + 0x24)));
  push_matrix();
  translate_matrix(0, lbl_805D9BA0, this->render_y_offset, lbl_805D9BA0);
  post_translate_matrix((u8 *)&this->position);
  rotate_matrix_y(0, this->rotation_y);
  if (TObjPlayer::check_demo_mode() == 1)
  {
    draw_chunk_object(*((s32 *) (((s8 *) arg0) + 0x34)));
  }
  else
  {
    switch (this->action)
    {
      case 0:
      case 1:
      case 8:
      case 9:
      {
        u8 *p = *((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*(u8 * *)&this->model)) + 0x2C)))) + 0x30)))) + 4)))) + 4));
        s16 t = *((s16 *) (((s8 *) p) + 6));
        *((s16 *) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*(u8 * *)&this->model)) + 0x2C)))) + 0x30)))) + 4)))) + 4)))) + 6)) = (u8) (*((s16 *) (((s8 *) p) + 6)));
        v28 = t;
      }
        break;
    }
    if ((*(s32 *)&this->m_378) == 0)
    {
      s16 a;
      s16 b;
      u8 *p = *((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*(u8 * *)&this->model)) + 0x2C)))) + 0x30)))) + 0x30)))) + 4)))) + 4));
      a = *((s16 *) (((s8 *) p) + 4));
      b = *((s16 *) (((s8 *) p) + 6));
      *((s16 *) (((s8 *) p) + 4)) = -0xB4;
      v26 = a;
      v27 = b;
      *((s16 *) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*(u8 * *)&this->model)) + 0x2C)))) + 0x30)))) + 0x30)))) + 4)))) + 4)))) + 6)) = -1;
    }
    TObjPlayer::toggle_particle_effect();
    shark_render_node_index = 0;
    set_chunk_model_node_callback((s32)((void *) TObjPlayer::update_particle_by_phase));
    if ((*(s32 *)&this->m_390) == 1)
    {
      if (this->fade.has_visible_opacity() != 0)
      {
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        this->fade.set_flags_and_apply_damage_color();
        if (defer_render__7TObjectFv(arg0) == 0)
        {
          model_render_flags |= 1;
          ((TObjMotion *)arg0)->draw();
          model_render_flags &= ~1;
        }
        this->fade.clear_flag_and_notify();
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
      }
    }
    else
    {
      if (fade != 0)
      {
        ((Owner_800ABDD8 *) arg0)->fades[mode].set_flags_and_apply_damage_color();
      }
      if (fade != 0)
      {
        if (defer_render__7TObjectFv(arg0) == 0)
        {
          if (res == 1)
          {
            ((TObjMotion *)arg0)->draw();
          }
          else
          {
            ((TObjEnemy *)arg0)->draw_motion_model();
          }
        }
      }
      else
        if (res == 1)
      {
        ((TObjMotion *)arg0)->draw();
      }
      else
      {
        ((TObjEnemy *)arg0)->draw_motion_model();
      }
      if (fade != 0)
      {
        ((Owner_800ABDD8 *) arg0)->fades[mode].clear_flag_and_notify();
      }
    }
    set_chunk_model_node_callback(0);
    TParticleCtrl::end_effect_render();
    if ((*(s32 *)&this->m_378) == 0)
    {
      *((s16 *) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*(u8 * *)&this->model)) + 0x2C)))) + 0x30)))) + 0x30)))) + 4)))) + 4)))) + 4)) = v26;
      *((s16 *) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*(u8 * *)&this->model)) + 0x2C)))) + 0x30)))) + 0x30)))) + 4)))) + 4)))) + 6)) = v27;
    }
    switch (this->action)
    {
      case 0:
      case 1:
      case 8:
      case 9:
        *((s16 *) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*(u8 * *)&this->model)) + 0x2C)))) + 0x30)))) + 4)))) + 4)))) + 6)) = v28;
        break;
    }
  }
  pop_matrix();
  model_render_flags &= ~1;
  restore_scene_lighting();
  switch (this->action)
  {
    case 0:
    case 1:
    case 8:
    case 9:
      return;
    default:
    {
      Vec_800ABDD8 v;
      v.x = lbl_805D9BBC;
      v.y = lbl_805D9BC0;
      v.z = lbl_805D9BC4;
      ((TObjEnemy *)arg0)->render_with_position_override((u8 *)&v, 0);
    }
  }
}

#include "pso/misc/TLobby.h"
#include "pso/enemy/TObjEneBeast.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/misc/TNowLoading.h"

struct E_800AC9DC { u8 pad[8]; s32 x8; s32 xc; };

struct G_800AC9DC { u8 pad[0x42c]; E_800AC9DC *tbl; };

struct O_800AC9DC { u8 pad[0x24]; s32 x24; u8 pad2[0xc]; s32 x34; };

struct Sub_800ACA10 { u8 pad[0x18]; s32 level; };

typedef struct O_800AC5EC {
    u8 pad0[0x18];
    void *vptr;
    u8 pad1c[0x3C4 - 0x1C];
    void *objs[2];
} O_800AC5EC;

struct Anim_800AC318 { s32 motions; void *actions; s32 initial_action; s32 counts; };

struct Pair_800AC318 { s32 a; s32 b; };

struct Bodies_800AC318 { s32 a; s32 b; s32 model; s32 textures; };

struct Res_800AC318 { u8 pad[0x42C]; Bodies_800AC318 *bodies; Pair_800AC318 *motions; };

struct Act_800AC318 { s32 a; s32 idx; f32 c; s32 d; };

extern "C" {
extern u32 shark_bml_resource;
extern s32 game_difficulty_selection;
void *__dt__13TUnk_80493450Fv(void *arg0, s16 arg1);
void free_collision_body_parts(void *);
void __destroy_arr(void *, void *, int, int);
extern u8 __dt__15RenderFadeStateFv[];
O_800AC5EC *__dt__12TObjEneSharkFv(O_800AC5EC *arg0, s16 arg1);
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
u8 *load_enemy_bml_resource_named(void *, void *);
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void draw_trail_with_colors(u8 *boss4_type3, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void *init_trail_buffer__11TBoss4Type3FPvifff(void *, s32, f32, f32, f32);
void *mem_alloc(u32 size);
void spawn_npc_enemy__6TLobbyFslllff(int, int, int, void *, f32, f32);
extern u8 lbl_8043AEDC[];
extern u32 TObjEneShark__resource_node;
extern u32 TObjEneShark__resource_buf;
extern u32 shark_resource_data;
extern u32 shark_resource_buffer;
extern const f32 lbl_805D9BC8;
extern const f32 lbl_805D9BCC;
void vfunc_99__13TUnk_80493450Fv(void);
void TLobby__sub_8001FE7C(void*, int);
void *__ct__11TObjControlFP7TObject(void *, void *);
s32 *__dt__11TBoss4Type3FPvs(s32 *arg0, s16 arg1);
void mem_free(void*);

extern void *tl_04;

extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void vfunc_29__9TObjCharaFv();
extern "C" void recalc_stats__9TObjCharaFv();
extern "C" void vfunc_67__9TObjCharaFf();
extern "C" void vfunc_66__9TObjCharaFv();
extern "C" void get_anim_node_position__9TObjCharaFlP3Vec();
extern "C" void vfunc_43__9TObjCharaFv();
extern "C" void vfunc_18__9TObjCharaFPUc();
extern "C" void interact__14TObjCollidableFl();
extern "C" void vfunc_100__13TUnk_80493450Fv();
extern "C" void render__12TObjEneSharkFv();
extern "C" void vfunc_89__13TUnk_80493450Fv();
extern "C" void vfunc_74__9TObjEnemyFl();
extern "C" void add_actor_exp__9TObjCharaFl();
extern "C" void apply_action_hold_status__9TObjCharaFf();
extern "C" void apply_anti_technique__9TObjCharaFl();
extern "C" void apply_attack_stat_status__9TObjCharaFPv();
extern "C" void apply_confusion_status__9TObjCharaFv();
extern "C" void apply_hit_message_flags__9TObjEnemyFPv();
extern "C" void apply_knockback_from_attacker__9TObjCharaFPUcf();
extern "C" void apply_movement_ailment__9TObjCharaFl();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void apply_paralysis__9TObjCharaFv();
extern "C" void apply_poison_status__9TObjCharaFv();
extern "C" void apply_set_data__9TObjEnemyFPv();
extern "C" void apply_shock_status__9TObjCharaFv();
extern "C" void apply_slow_status__9TObjCharaFv();
extern "C" void apply_switch_attack__9TObjCharaFv();
extern "C" void vfunc_59__13TUnk_80493450Fv();
extern "C" void beast_idle_update__13TUnk_80493450Fv();
extern "C" void beast_retire_corpse__13TUnk_80493450Fv();
extern "C" void beast_select_target();
extern "C" void vfunc_60__13TUnk_80493450Fv();
extern "C" void beast_update_approach__13TUnk_80493450Fv();
extern "C" void beast_update_attack__13TUnk_80493450Fv();
extern "C" void beast_update_dead__13TUnk_80493450Fv();
extern "C" void beast_update_group_chase__13TUnk_80493450Fv();
extern "C" void beast_update_hurt__13TUnk_80493450Fv();
extern "C" void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
extern "C" void vfunc_79__9TObjEnemyFPl();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void clear_all_status_effects__9TObjCharaFv();
extern "C" void vfunc_61__13TUnk_80493450Fv();
extern "C" void clear_harmful_statuses__9TObjCharaFv();
extern "C" void clear_lobby_object_state__9TObjEnemyFv();
extern "C" void consume_timer_field__9TObjCharaFl();
extern "C" void cure_paralysis__9TObjCharaFv();
extern "C" void cure_poison_ailment__9TObjCharaFv();
extern "C" void enemy_spawn_jellen_effect__9TObjCharaFv();
extern "C" void enemy_spawn_zalure_effect__9TObjCharaFv();
extern "C" void vfunc_62__13TUnk_80493450Fv();
extern "C" void enter_state_8__10TObjPlayerFv();
extern "C" void vfunc_78__9TObjCharaFl();
extern "C" void vfunc_77__9TObjCharaFv();
extern "C" void vfunc_76__9TObjCharaFv();
extern "C" void vfunc_75__9TObjCharaFf();
extern "C" void get_center__9TObjCharaFv();
extern "C" void get_actor_level_index__9TObjCharaFv();
extern "C" void get_name__9TObjEnemyFv();
extern "C" void get_pos__9TObjCharaFl();
extern "C" void is_actor_cadence_frame__9TObjCharaFl();
extern "C" void is_target_in_attack_range__9TObjCharaFv();
extern "C" __declspec(section ".rodata") u8 lbl_8043AD10[] = "bm1f_s_wala_body.nj";
extern "C" __declspec(section ".rodata") u8 lbl_8043AD24[] = "bm1tl_s_wala_body.nj";
extern "C" __declspec(section ".rodata") u8 lbl_8043AD3C[] = "bm1_s_wala_body.nj";
extern "C" __declspec(section ".rodata") u8 lbl_8043AD50[] = "appear_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 lbl_8043AD6C[] = "atackl_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 lbl_8043AD88[] = "atackr_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 lbl_8043ADA4[] = "damage_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 lbl_8043ADC0[] = "deadb_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 lbl_8043ADDC[] = "dead_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 lbl_8043ADF8[] = "leader_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 lbl_8043AE14[] = "mihari_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 lbl_8043AE30[] = "run_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 lbl_8043AE48[] = "stund_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 lbl_8043AE64[] = "wakeup_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 lbl_8043AE80[] = "walk_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 lbl_8043AE9C[] = "bm_ene_bm1_shark.bml";
extern "C" __declspec(section ".rodata") u8 lbl_8043AEB4[] = "TObjEneShark";
extern "C" void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__9TObjCharaFPvf();
extern "C" void receive_weapon_special_attack__9TObjCharaFPvPv();
extern "C" void apply_defense_stat_status__9TObjCharaFPv();
extern "C" void render_shadows__9TObjEnemyFv();
extern "C" void request_stand_action__13TUnk_80493450Fv();
extern "C" void reset_motion_fields__9TObjCharaFv();
extern "C" void reset_pose__9TObjCharaFv();
extern "C" void roll_physical_accuracy__9TObjCharaFPvlf();
extern "C" void run_task__13TUnk_80493450Fv();
extern "C" void select_melee_contact_body__9TObjCharaFPvf();
extern "C" void update_movement_status__13TUnk_80493450Fv();
extern "C" void tick_freeze_state__10TObjPlayerFv();
extern "C" void trigger_switch_attack__9TObjCharaFv(s32 arg0);
extern "C" void try_start_action__9TObjCharaFll();
extern "C" void update_action_hold_status__13TUnk_80493450Fv();
extern "C" s32 vfunc_37__9TObjCharaFv(u8 *player);
extern "C" void update_actor_ground_y__9TObjCharaFv();
extern "C" s32 update_attack_stat_status__9TObjCharaFv(u8 *player);
extern "C" s32 update_defense_stat_status__9TObjCharaFv(u8 *player);
extern "C" void update_flag30_timer__9TObjCharaFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
extern "C" void update_poison_status__9TObjCharaFv();
extern "C" void update_shock_clock__9TObjCharaFv();
extern "C" void update_turn_toward_target__13TUnk_80493450Fv();
extern void *bm_ene_bm1_shark_model_names[4];
extern void *bm_ene_bm1_shark_motion_names[13];
void *bm_ene_bm1_shark_model_names[4] = {
    (void *)&lbl_8043AD10, (void *)&lbl_8043AD24, (void *)&lbl_8043AD3C, (void *)0x0,
};
void *bm_ene_bm1_shark_motion_names[13] = {
    (void *)&lbl_8043AD50, (void *)&lbl_8043AD6C, (void *)&lbl_8043AD88, (void *)&lbl_8043ADA4,
    (void *)&lbl_8043ADC0, (void *)&lbl_8043ADDC, (void *)&lbl_8043ADF8, (void *)&lbl_8043AE14,
    (void *)&lbl_8043AE30, (void *)&lbl_8043AE48, (void *)&lbl_8043AE64, (void *)&lbl_8043AE80,
    (void *)0x0,
};
void *bm_ene_bm1_shark_resource_descriptor[4] = {
    (void *)&lbl_8043AE9C, (void *)&bm_ene_bm1_shark_model_names, (void *)&bm_ene_bm1_shark_motion_names, (void *)0x3000c,
};
void *TObjEneShark__action_table[44] = {
    (void *)0x10000, (void *)0x9, (void *)0x3f19999a, (void *)0x1,
    (void *)0x20000, (void *)0x7, (void *)0x3f19999a, (void *)0x20,
    (void *)0x10002, (void *)0xb, (void *)0x3f800000, (void *)0x1,
    (void *)0x20000, (void *)0x1, (void *)0x3f800000, (void *)0x4,
    (void *)0x20000, (void *)0x2, (void *)0x3f800000, (void *)0x4,
    (void *)0x10000, (void *)0x8, (void *)0x3f800000, (void *)0x1,
    (void *)0x20000, (void *)0x3, (void *)0x3f800000, (void *)0x8,
    (void *)0x20000, (void *)0xa, (void *)0x3f4ccccd, (void *)0x20,
    (void *)0x30000, (void *)0x5, (void *)0x3f19999a, (void *)0x10,
    (void *)0x30000, (void *)0x4, (void *)0x3f19999a, (void *)0x10,
    (void *)0x20000, (void *)0x6, (void *)0x3f19999a, (void *)0x20,
};
void *lbl_804915B4[21] = {
    (void *)0x43610000, (void *)0x3f400000, (void *)0x400, (void *)0x0,
    (void *)0x1e0000, (void *)0x1, (void *)0x0, (void *)0x437a0000,
    (void *)0x3f666666, (void *)0x400, (void *)0x0, (void *)0x1e0000,
    (void *)0x1, (void *)0x0, (void *)0x43960000, (void *)0x3f800000,
    (void *)0x400, (void *)0x0, (void *)0x1e0000, (void *)0x1,
    (void *)0x0,
};
void *lbl_80491608[33] = {
    (void *)0x0, (void *)0x41480000, (void *)0x0, (void *)0x40e00000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41480000, (void *)0x0, (void *)0x40e00000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41700000,
    (void *)0x0, (void *)0x41000000, (void *)0x0, (void *)0x0,
    (void *)0x8003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
void *lbl_8049168C[103] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__12TObjEneSharkFv, (void *)&run_task__13TUnk_80493450Fv,
    (void *)&render__12TObjEneSharkFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&beast_select_target, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__13TUnk_80493450Fv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__13TUnk_80493450Fv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__13TUnk_80493450Fv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&tick_freeze_state__10TObjPlayerFv, (void *)&vfunc_59__13TUnk_80493450Fv,
    (void *)&vfunc_60__13TUnk_80493450Fv, (void *)&vfunc_61__13TUnk_80493450Fv, (void *)&vfunc_62__13TUnk_80493450Fv, (void *)&enter_state_8__10TObjPlayerFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFv, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEnemyFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneSharkFv,
    (void *)&beast_idle_update__13TUnk_80493450Fv, (void *)&update_turn_toward_target__13TUnk_80493450Fv, (void *)&beast_update_approach__13TUnk_80493450Fv, (void *)&beast_update_group_chase__13TUnk_80493450Fv,
    (void *)&beast_update_attack__13TUnk_80493450Fv, (void *)&vfunc_89__13TUnk_80493450Fv, (void *)&beast_update_hurt__13TUnk_80493450Fv, (void *)&beast_update_dead__13TUnk_80493450Fv,
    (void *)&beast_retire_corpse__13TUnk_80493450Fv, (void *)&vfunc_93__12TObjEneSharkFv, (void *)&vfunc_94__12TObjEneSharkFv, (void *)&vfunc_95__12TObjEneSharkFv,
    (void *)&vfunc_96__12TObjEneSharkFv, (void *)&vfunc_97__12TObjEneSharkFv, (void *)&vfunc_98__12TObjEneSharkFv, (void *)&vfunc_99__13TUnk_80493450Fv,
    (void *)&vfunc_100__13TUnk_80493450Fv, (void *)&vfunc_101__12TObjEneSharkFv, (void *)&request_stand_action__13TUnk_80493450Fv,
};
#define bm_ene_bm1_shark_resource_descriptor ((u8 *)bm_ene_bm1_shark_resource_descriptor)
#define TObjEneShark__action_table ((Act_800AC318 *)TObjEneShark__action_table)
#define lbl_8049168C ((u8 *)lbl_8049168C)

void *TObjEneShark::create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x43C);
    if (o2 != NULL) {
        o2 = TObjEneShark__ct(o2, o, arg0);
    }
    return o2;
}

void TObjEneShark::free_resources() {
    if ((u32) TObjEneShark__resource_node != 0U) {
        mem_free((void*)TObjEneShark__resource_node);
        TObjEneShark__resource_node = 0U;
    }
    if ((u32) TObjEneShark__resource_buf != 0U) {
        mem_free((void*)TObjEneShark__resource_buf);
        TObjEneShark__resource_buf = 0U;
    }
    if ((u32) shark_resource_data != 0U) {
        mem_free((void*)shark_resource_data);
        shark_resource_data = 0U;
    }
    if ((u32) shark_resource_buffer != 0U) {
        mem_free((void*)shark_resource_buffer);
        shark_resource_buffer = 0U;
    }
    if ((u32) shark_attack4_trail_buffer != 0U) {
        __dt__11TBoss4Type3FPvs((s32 *)shark_attack4_trail_buffer, 1);
        shark_attack4_trail_buffer = 0U;
    }
    if ((u32) TObjEneShark__attack_motion_3_trail != 0U) {
        __dt__11TBoss4Type3FPvs((s32 *)TObjEneShark__attack_motion_3_trail, 1);
        TObjEneShark__attack_motion_3_trail = 0U;
    }
    if ((u32) shark_bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)shark_bml_resource, 1);
        shark_bml_resource = 0U;
    }
}

#define G_A8 (*(s32 **)&TObjEneShark__resource_node)
#define G_AC (*(s32 **)&TObjEneShark__resource_buf)
#define G_B0 (*(s32 **)&shark_resource_data)
#define G_B4 (*(s32 **)&shark_resource_buffer)
#define G_B8 (*(u8 **)&shark_bml_resource)
#define G_BC (*(void **)&TObjEneShark__attack_motion_3_trail)
#define G_C0 (*(void **)&shark_attack4_trail_buffer)
#define RES ((Res_800AC318 *)G_B8)
void TLobby::load_shark_resources() {
    void *p;
    s32 i;
    if (TObjEneDD::check_v2_mode() != 0) {
        G_B8 = load_enemy_bml_resource_named(bm_ene_bm1_shark_resource_descriptor, lbl_8043AEDC);
    } else {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, bm_ene_bm1_shark_resource_descriptor, 0, 0, 0);
        }
        G_B8 = (u8 *)p;
    }
    p = ::operator new(0x18);
    if (p != NULL) {
        p = init_trail_buffer__11TBoss4Type3FPvifff(p, 2, lbl_805D9BC8, lbl_805D9BAC, lbl_805D9BC0);
    }
    G_BC = p;
    p = ::operator new(0x18);
    if (p != NULL) {
        p = init_trail_buffer__11TBoss4Type3FPvifff(p, 2, lbl_805D9BC8, lbl_805D9BAC, lbl_805D9BC0);
    }
    G_C0 = p;
    draw_trail_with_colors((u8 *)G_BC, RES->bodies->model, RES->motions[TObjEneShark__action_table[3].idx].b, 5, 8);
    draw_trail_with_colors((u8 *)G_C0, RES->bodies->model, RES->motions[TObjEneShark__action_table[4].idx].b, 0xA, 0xD);
    G_A8 = (s32 *)mem_alloc(0xC);
    G_AC = (s32 *)mem_alloc(0xC);
    G_B0 = (s32 *)mem_alloc(0xC);
    G_B4 = (s32 *)mem_alloc(0xC);
    G_A8[0] = register_boss__6TLobbyFl(0x4F);
    G_A8[1] = register_boss__6TLobbyFl(0x50);
    G_A8[2] = register_boss__6TLobbyFl(0x51);
    G_AC[0] = dispatch_shared_handler_b__6TLobbyFl(0x54);
    G_AC[1] = dispatch_shared_handler_b__6TLobbyFl(0x55);
    G_AC[2] = dispatch_shared_handler_b__6TLobbyFl(0x56);
    G_B0[0] = register_object__6TLobbyFl(0x4E);
    G_B0[1] = register_object__6TLobbyFl(0x4F);
    G_B0[2] = register_object__6TLobbyFl(0x50);
    G_B4[0] = dispatch_shared_handler_a__6TLobbyFl(0x4E);
    G_B4[1] = dispatch_shared_handler_a__6TLobbyFl(0x4F);
    G_B4[2] = dispatch_shared_handler_a__6TLobbyFl(0x50);
    shark_render_node_index = 0;
    {
        s16 ids[3] = { 0x2F, 0x30, 0x31 };
        Anim_800AC318 anim = { (s32)RES->motions, TObjEneShark__action_table, 2, 0xC0000 };
        for (i = 0; i < 3; i++) {
            spawn_npc_enemy__6TLobbyFslllff(ids[i], RES->bodies[i].model, RES->bodies[i].textures, &anim,
                lbl_805D9BCC, lbl_805D9BA0);
        }
    }
}

extern "C" __declspec(section ".rodata") u8 lbl_8043AEDC[] = "bm_ene_bm1_shark_a.bml";

O_800AC5EC *__dt__12TObjEneSharkFv(O_800AC5EC *arg0, s16 arg1) {
    s32 i;
    if (arg0 != NULL) {
        arg0->vptr = lbl_8049168C;
        for (i = 0; i < 2; i++) {
            if (arg0->objs[i] != NULL) {
                queue_destruction__7TObjectFv(arg0->objs[i]);
                arg0->objs[i] = NULL;
            }
        }
        ((TUnk_80493450 *)arg0)->unlink_enemy_group_relations();
        free_collision_body_parts(arg0);
        __destroy_arr((u8 *)arg0 + 0x3CC, __dt__15RenderFadeStateFv, 0x1C, 4);
        ((TObjEneShark *)arg0)->fade.MaterialOpacityFade::~MaterialOpacityFade();
        __dt__13TUnk_80493450Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}

struct VBase_800AC6B0 { u8 pad[0x18]; };
struct VObj_800AC6B0 : VBase_800AC6B0 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75();
    virtual void m76(); virtual void m77(); virtual void m78();
    virtual void m79(void *);
    virtual void m80();
};

struct Shark_800AC6B0 : VObj_800AC6B0 {
    u8 pad1c[0x30 - 0x1c];
    u32 f30;
    u8 pad34[0xb8 - 0x34];
    s16 fB8;
    u8 padba[0xd8 - 0xba];
    void *fD8;
    s32 fDC;
    u8 pade0[0x2ac - 0xe0];
    s32 f2AC;
    u8 pad2b0[0x328 - 0x2b0];
    s16 f328;
    u8 pad32a[0x32c - 0x32a];
    s16 f32C;
    u8 pad32e[0x334 - 0x32e];
    s32 f334;
    u8 pad338[0x33a - 0x338];
    s16 f33A;
    s16 f33C;
    s16 f33E;
    u8 pad340[0x350 - 0x340];
    void *f350;
    u8 pad354[0x368 - 0x354];
    s32 f368;
    u8 pad36c[0x374 - 0x36c];
    s16 f374;
    s16 f376;
    s32 f378;
    s32 f37C;
    u8 pad380[0x390 - 0x380];
    s32 f390;
    u8 pad394[0x398 - 0x394];
    f32 f398;
    f32 f39C;
    f32 f3A0;
    f32 f3A4;
    MaterialOpacityFade f3A8;
    void *f3C4;
    void *f3C8;
    u8 f3CC[4][0x1C];
};

extern "C" {
f32 random_ratio__9TObjCharaFv(s32 arg0);

void init_enemy_base__13TUnk_80493450Fv(void *);
}
int initialize_enemy_photon_effect(void *p);
extern "C" {
void init_collision_body_parts(void *, void *, s32);
void *__construct_array(void *, void *, void *, s32, s32);
void __ct__15RenderFadeStateFv(void *);
extern s32 TObjEneShark_name_ref;
extern const f32 lbl_805D9BD0;
extern const f32 lbl_805D9BD4;
#define lbl_804915B4 ((u8 *)lbl_804915B4)
#define lbl_80491608 ((u8 *)lbl_80491608)
void *TObjEneShark__ct(void *arg0, void *arg1, void *arg2) {
#define self ((Shark_800AC6B0 *)arg0)
    s32 color;
    s32 i;

    ((void (*)(void *, void *))init_enemy_base__13TUnk_80493450Fv)(self, arg1);
    *(void **)((u8 *)self + 0x18) = lbl_8049168C;
    __ct__19MaterialOpacityFadeFv(((u8 *)arg0 + 0x3A8));
    __construct_array(self->f3CC, (void *)__ct__15RenderFadeStateFv, __dt__15RenderFadeStateFv, 0x1C, 4);
    *(s32 *)self = TObjEneShark_name_ref;
    self->m79(arg2);
    ((TObjPlayer *)self)->init_position_vectors();
    self->f334 = self->f368;
    ((TObjEneShark *)self)->apply_clamped_mode_param();
    ((TObjEneShark *)self)->sub_800AC9DC(self->f368);
    self->fD8 = TObjEneShark__action_table;
    ((TObjMotion *)self)->set_field_d8((s32)self->fD8);
    self->fDC = *(s32 *)(shark_bml_resource + 0x430);
    self->fB8 = 0;
    ((TObjMotion *)self)->set_animation(self->fB8);
    ((TObjMotion *)self)->set_field_b8(self->fB8);
    init_collision_body_parts(self, lbl_80491608 + self->f334 * 0x2C, 1);
    ((TObjEnemy *)self)->bind_enemy_combat_stats((u8 *)(((s32 *)TObjEneShark__resource_node)[self->f334]), (u8 *)(((s32 *)TObjEneShark__resource_buf)[self->f334]), (u8 *)(((s32 *)shark_resource_data)[self->f334]));
    self->f350 = lbl_804915B4 + self->f334 * 0x1C;
    self->f33E = self->f32C;
    ((TObjEnemy *)self)->update_prev_position();
    ((TBoss3VoloptHiraisin *)self)->copy_position();
    initialize_enemy_photon_effect(self);
    self->f2AC = (s32)(lbl_805D9BD0 * (lbl_805D9BD4 * random_ratio__9TObjCharaFv((s32)self)));
    self->f33A = 0xF;
    self->f33C = self->f33A;
    self->f328 = 0;
    self->f374 = 0;
    self->f376 = 0;
    self->f378 = 0;
    self->f37C = 0;
    ((TObjChara *)self)->add_flags_2e4(2);
    self->f30 |= 0x40000;
    if (TObjEneDD::check_v2_mode() != 0) {
        switch (self->f334) {
        case 0:
        default:
            color = 0xFF20FF20;
            break;
        case 1:
            color = 0xFFFF0040;
            break;
        case 2:
            color = 0xFFFFFF00;
            break;
        }
    } else {
        switch (self->f334) {
        default:
            color = 0xFF0000FF;
            break;
        case 1:
            color = 0xFFFF0000;
            break;
        case 2:
            color = 0xFFFFFF00;
            break;
        }
    }
    ((TObjEneShark *)self)->fade.reset_obstruction_fade();
    self->f390 = 1;
    self->f3C4 = TUnk_80494968::create((u32)0xA0303030, (u32)color);
    self->f3C8 = TUnk_80494968::create((u32)0xA0303030, (u32)color);
    self->f398 = (*(f32 **)(shark_resource_buffer + self->f334 * 4))[0];
    self->f3A0 = (*(f32 **)(shark_resource_buffer + self->f334 * 4))[1];
    self->f39C = (*(f32 **)(shark_resource_buffer + self->f334 * 4))[2];
    self->f3A4 = (*(f32 **)(shark_resource_buffer + self->f334 * 4))[3];
    for (i = 0; i < 4; i++) {
        ((RenderFadeState *)(self->f3CC[i]))->activate_and_dispatch();
    }
    self->m80();
    return self;
#undef self
}
#undef lbl_804915B4
#undef lbl_80491608
void TUnk_80493450::vfunc_99() {  }

void TObjEneShark::sub_800AC9DC(s32 i) {
    O_800AC9DC *self = (O_800AC9DC *)this;
    self->x34 = (*(G_800AC9DC * *)&shark_bml_resource)->tbl[i].x8;
    self->x24 = (*(G_800AC9DC * *)&shark_bml_resource)->tbl[i].xc;
}

void TObjPlayer__sub_800ACA0C(void) {  }
s32 TObjEneMoja::calc_technique_level() {
    TObjEneMoja *self = this;
    Sub_800ACA10 *p = *(Sub_800ACA10 * *)&self->m_2b0;
    s32 v = 0;
    if (p != 0) {
        v = p->level;
        if (v < 0) {
            return 0;
        }
        if (game_difficulty_selection == 3) {
            if (v > 0x1D) {
                v = 0x1D;
            }
            return v;
        }
        if (v > 0xE) {
            v = 0xE;
        }
    }
    return v;
}
}
