#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/RenderFadeState.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/TUnk_80494968.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/moja/TObjEneMoja.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/enemy/saver/TObjEneSaver.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/shark/TObjEneShark.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/text_803D853C.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"

#include "pso/render/TUnk_80494938.h"

extern "C" void test_flag_256__13TUnk_80493450Fv();

#include <stddef.h>

struct RecoveredGlobal_800ABA9C_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
LAYOUT_ASSERT(RecoveredGlobal_800ABA9C_lbl_8058D490_size, sizeof(RecoveredGlobal_800ABA9C_lbl_8058D490) == 0x30);

struct VBase_14_800ABCBC { char pad[0x14]; };

struct VObj_14_800ABCBC : VBase_14_800ABCBC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual s32 m5();
};

struct Obj_800ABCBC { u8 pad0[0x38]; u8 sub38[0x326 - 0x38]; s16 f326; s16 state; u8 pad32a[0x390 - 0x32A]; s32 f390; };

struct RecoveredGlobal_800ABA9C_lbl_8058D490;

typedef struct Rot_800AB31C {
    s32 x, y, z;
} Rot_800AB31C;

typedef struct Obj_800AB31C {
    u8 pad0[0x18];
    void *vptr;
    Vec pos;
    Vec pos2;
    u8 mtx34[0x58 - 0x34];
    f32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
} Obj_800AB31C;

struct VBase_800ABB38 { char pad[0x18]; };

struct VObj_800ABB38 : VBase_800ABB38 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(Vec *, Vec *);
};

typedef struct Obj_800ABB38 {
    u8 pad0[0x38];
    Vec pos;
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

struct VObj_14_800ABDD8 : VBase_14_800ABDD8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8();
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

struct Fade_800ABDD8 : VBase_14_800ABDD8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    u32 x18;
};

struct Owner_800ABDD8
{
  u8 pad[0x3CC];
  Fade_800ABDD8 fades[4];
};


extern "C" {
s32 post_translate_matrix(void *);
void draw_chunk_object(void *child);
extern s32 model_render_flags;
void run_demo_task__12TObjEneSharkFv(void);
extern s32 shark_render_node_index;
s32 vec3_add_to(void *, void *);
s32 play_sound_effect(s32, void *, int, int);
void play_attack_sound__12TObjEneSharkFv(s32 arg0);
void play_death_sound__12TObjEneSharkFv(s32 arg0);
void play_hurt_sound__12TObjEneSharkFv(s32 arg0);
void play_alert_sound__12TObjEneSharkFv(s32 arg0);
void TObjPlayer__sub_800D92BC(s32 point, s32 delay);
s32 rotate_vector_by_matrix(int, void *, void *);
extern RecoveredGlobal_800ABA9C_lbl_8058D490 identity_matrix;
void spawn_death_effect__12TObjEneSharkFv(u8 *arg0);
void beast_update_appear__12TObjEneSharkFv(Obj_800ABCBC *arg0);
void set_matrix_identity(u8 *arg0);
extern uaddr TObjEneShark__attack_motion_3_trail;
extern uaddr shark_attack4_trail_buffer;
void update_attack_trail__12TObjEneSharkFv(Obj_800ABB38 *o);
void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;

#pragma push
#pragma fp_contract on
#pragma pop

void TObjEneShark::run_demo_task() {  }

void TObjEneShark::play_death_sound() {
    saddr arg0 = (saddr)this;
    play_sound_effect((((TObjEnemy *)((void *)arg0))->remap_sound_for_area(0x4003A60C)), (void *)(arg0 + 0x38), 0, 0);
    TObjPlayer::play_effect_if_v2(-0x300);
}

void TObjEneShark::play_hurt_sound() {
    saddr arg0 = (saddr)this;
    play_sound_effect((((TObjEnemy *)((void *)arg0))->remap_sound_for_area(0x4003A60B)), (void *)(arg0 + 0x38), 0, 0);
    TObjPlayer::play_effect_if_v2(-0x300);
}

void TObjEneShark::play_attack_sound() {
    saddr arg0 = (saddr)this;
    play_sound_effect((((TObjEnemy *)((void *)arg0))->remap_sound_for_area(0x4003A60D)), (void *)(arg0 + 0x38), 0, 0);
}

void TObjEneShark::play_alert_sound() {
    saddr arg0 = (saddr)this;
    play_sound_effect((((TObjEnemy *)((void *)arg0))->remap_sound_for_area(0x4003A60B)), (void *)(arg0 + 0x38), 0, 0);
    TObjPlayer::play_effect_if_v2(-0x300);
}

void TObjEneShark::spawn_death_effect() {
    u8 *arg0 = (u8 *)this;
    Vec stack;
    stack.x = 0.0f;
    stack.y = 10.0f;
    stack.z = 0.5f * *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x2B0)) + 0x10);
    push_matrix_from(&identity_matrix.value);
    rotate_matrix_y(0, this->rotation_y);
    rotate_vector_by_matrix(0, &stack.x, &stack.x);
    pop_matrix();
    vec3_add_to(&stack.x, (u8 *)&this->position);
    ((TObjPlayer *)(&stack.x))->spawn_ground_effect(0x23);
    TObjPlayer__sub_800D92BC((saddr)&stack.x, 0xF);
}

void TObjEneShark::update_attack_trail() {
    Obj_800ABB38 *o = (Obj_800ABB38 *)this;
    Vec b;
    Vec a;
    Vec *e;
    s32 idx;
    VObj_800ABB38 *eff;
    if (!(this->m_c0 < 12.0f)) {
        return;
    }
    switch (this->m_b8) {
    case 3:
        e = ((SampledMotionPoints *)((void *)TObjEneShark__attack_motion_3_trail))->lookup(this->m_c0);
        idx = 0;
        break;
    case 4:
        e = ((SampledMotionPoints *)((void *)shark_attack4_trail_buffer))->lookup(this->m_c0);
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
    matrix_mult_vec_array(NULL, e, &a, 2);
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

void TObjEneShark::beast_update_appear() {
    Obj_800ABCBC *arg0 = (Obj_800ABCBC *)this;
    ((TObjMotion *)this)->advance_animation();
    switch (*(s16 *)&this->m_328) {
    case 0:
    default:
        if (*(s32 *)&this->m_390 != 0) {
            ((TUnk_80494938 *)((u8 *)arg0 + 0x3A8))->start_fade_in();
            play_area_sound_effect((Vec *)(arg0->sub38));
            *(s16 *)&this->m_328 = 1;
        } else {
            *(s16 *)&this->m_328 = 2;
        }
        break;
    case 1:
        if (((VObj_14_800ABCBC *)((u8 *)arg0 + 0x3A8))->m5() == 1) {
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

void TObjPlayer::update_particle_by_phase(NJS_OBJECT *) {
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
typedef struct Fade_800ABDD8 Fade_800ABDD8;
typedef struct Owner_800ABDD8 Owner_800ABDD8;
typedef struct VBase_14_800ABDD8 VBase_14_800ABDD8;
typedef struct VBase_18_800ABDD8 VBase_18_800ABDD8;
typedef struct VObj_14_800ABDD8 VObj_14_800ABDD8;
typedef struct VObj_18_800ABDD8 VObj_18_800ABDD8;
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
    mode = TCameraCtrl::get_camera_mode();
  }
  res = PSO_VCALL_VObj_18_800ABDD8_m9(arg0, 200.0f, 400.0f, 30.0f);
  if (res == 0)
  {
    return;
  }
  fade = 0;
  if (TObjEneDD::check_v2_mode() != 0)
  {
    u8 *f = (u8 *) (&((Owner_800ABDD8 *) arg0)->fades[mode]);
    ((RenderFadeState *)f)->update();
    fade = ((RenderFadeState *)f)->updateFromCamera((const f32*)(arg0 + 0x2FC));
  }
  select_actor_lighting((saddr)arg0);
  model_render_flags |= 1;
  TObjFish::set_global_param(*((s32 *) (((s8 *) arg0) + 0x24)));
  push_matrix();
  translate_matrix(0, 0.0f, this->render_y_offset, 0.0f);
  post_translate_matrix((u8 *)&this->position);
  rotate_matrix_y(0, this->rotation_y);
  if (TObjPlayer::check_demo_mode() == 1)
  {
    draw_chunk_object(this->model);
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
    set_chunk_model_node_callback(TObjPlayer::update_particle_by_phase);
    if ((*(s32 *)&this->m_390) == 1)
    {
      if (((VObj_14_800ABDD8 *) (arg0 + 0x3A8))->m8() != 0)
      {
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        ((VObj_14_800ABDD8 *) (arg0 + 0x3A8))->m6();
        if (((TObject *)arg0)->defer_render() == 0)
        {
          model_render_flags |= 1;
          ((TObjMotion *)arg0)->draw();
          model_render_flags &= ~1;
        }
        ((VObj_14_800ABDD8 *) (arg0 + 0x3A8))->m7();
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
      }
    }
    else
    {
      if (fade != 0)
      {
        ((Owner_800ABDD8 *) arg0)->fades[mode].m6();
      }
      if (fade != 0)
      {
        if (((TObject *)arg0)->defer_render() == 0)
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
        ((Owner_800ABDD8 *) arg0)->fades[mode].m7();
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
      Vec v;
      v.x = 1.5f;
      v.y = 1.0f;
      v.z = 2.0f;
      ((TObjEnemy *)arg0)->draw_ground_shadow(&v, 0);
    }
  }
}

#include "pso/unk/TLobby.h"
#include "pso/enemy/beast/TObjEneBeast.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"

#include "pso/ui/hud/TNowLoading.h"

struct Sub_800ACA10 { u8 pad[0x18]; s32 level; };

typedef struct O_800AC5EC {
    u8 pad0[0x18];
    void *vptr;
    u8 pad1c[0x3C4 - 0x1C];
    void *objs[2];
} O_800AC5EC;

struct Act_800AC318 { s32 a; s32 idx; f32 c; s32 d; };

extern "C" {
extern BmlResource *shark_bml_resource;
extern s32 game_difficulty_selection;
void *__dt__13TUnk_80493450Fv(void *arg0, s16 arg1);
void free_collision_body_parts(void *);
void __destroy_arr(void *, void *, int, int);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
extern u8 __dt__15RenderFadeStateFv[];
O_800AC5EC *__dt__12TObjEneSharkFv(O_800AC5EC *arg0, s16 arg1);
extern u8 bm_ene_bm1_shark_a_bml_filename[];
extern uaddr TObjEneShark__resource_node;
extern uaddr TObjEneShark__resource_buf;
extern uaddr shark_resource_data;
extern uaddr shark_resource_buffer;
void play_group_chase_sound__13TUnk_80493450Fv(void);
void *__ct__11TObjControlFP7TObject(void *, void *);

extern void *tl_04;

extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void has_no_target__9TObjCharaFv();
extern "C" void recalc_stats__9TObjCharaFv();
extern "C" void deliver_attack_hits__9TObjCharaFf();
extern "C" void vfunc_66__9TObjCharaFv();
extern "C" void get_anim_node_position__9TObjCharaFlP3Vec();
extern "C" void vfunc_43__9TObjCharaFv();
extern "C" void vfunc_18__9TObjCharaFPUc();
extern "C" void interact__14TObjCollidableFl();
extern "C" void select_post_attack_mode__13TUnk_80493450Fv();
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
extern "C" void run_move_action__13TUnk_80493450Fv();
extern "C" void beast_idle_update__13TUnk_80493450Fv();
extern "C" void beast_retire_corpse__13TUnk_80493450Fv();
extern "C" void refresh_target__13TUnk_80493450Fv();
extern "C" void run_attack_action__13TUnk_80493450Fv();
extern "C" void beast_update_approach__13TUnk_80493450Fv();
extern "C" void beast_update_attack__13TUnk_80493450Fv();
extern "C" void beast_update_dead__13TUnk_80493450Fv();
extern "C" void beast_update_group_chase__13TUnk_80493450Fv();
extern "C" void beast_update_hurt__13TUnk_80493450Fv();
extern "C" void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
extern "C" void apply_enemy_state__9TObjEnemyFPl();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void clear_all_status_effects__9TObjCharaFv();
extern "C" void run_miss_reaction__13TUnk_80493450Fv();
extern "C" void clear_harmful_statuses__9TObjCharaFv();
extern "C" void clear_lobby_object_state__9TObjEnemyFv();
extern "C" void consume_timer_field__9TObjCharaFl();
extern "C" void cure_paralysis__9TObjCharaFv();
extern "C" void cure_poison_ailment__9TObjCharaFv();
extern "C" void enemy_spawn_jellen_effect__9TObjCharaFv();
extern "C" void enemy_spawn_zalure_effect__9TObjCharaFv();
extern "C" void run_hit_reaction__13TUnk_80493450Fv();
extern "C" void run_death_reaction__13TUnk_80493450Fv();
extern "C" void vfunc_78__9TObjCharaFl();
extern "C" void gain_photon_blast_chain_charge__9TObjCharaFv();
extern "C" void spend_photon_blast_charge__9TObjCharaFf();
extern "C" void gain_photon_blast_charge__9TObjCharaFf();
extern "C" void get_center__9TObjCharaFv();
extern "C" void get_actor_level_index__9TObjCharaFv();
extern "C" void get_name__9TObjEnemyFv();
extern "C" void get_pos__9TObjCharaFl();
extern "C" void is_actor_cadence_frame__9TObjCharaFl();
extern "C" void is_target_in_attack_range__9TObjCharaFv();
extern "C" __declspec(section ".rodata") u8 lbl_8043AD10[] = "bm1f_s_wala_body.nj";
extern "C" __declspec(section ".rodata") u8 shark_model_name_bm1tl_s_wala_body_nj[] = "bm1tl_s_wala_body.nj";
extern "C" __declspec(section ".rodata") u8 shark_model_name_bm1_s_wala_body_nj[] = "bm1_s_wala_body.nj";
extern "C" __declspec(section ".rodata") u8 shark_motion_name_appear_bm1_s_wala_body_njm[] = "appear_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 shark_motion_name_atackl_bm1_s_wala_body_njm[] = "atackl_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 shark_motion_name_atackr_bm1_s_wala_body_njm[] = "atackr_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 shark_motion_name_damage_bm1_s_wala_body_njm[] = "damage_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 shark_motion_name_deadb_bm1_s_wala_body_njm[] = "deadb_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 shark_motion_name_dead_bm1_s_wala_body_njm[] = "dead_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 shark_motion_name_leader_bm1_s_wala_body_njm[] = "leader_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 shark_motion_name_mihari_bm1_s_wala_body_njm[] = "mihari_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 shark_motion_name_run_bm1_s_wala_body_njm[] = "run_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 shark_motion_name_stund_bm1_s_wala_body_njm[] = "stund_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 shark_motion_name_wakeup_bm1_s_wala_body_njm[] = "wakeup_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 shark_motion_name_walk_bm1_s_wala_body_njm[] = "walk_bm1_s_wala_body.njm";
extern "C" __declspec(section ".rodata") u8 bm_ene_bm1_shark_bml_filename[] = "bm_ene_bm1_shark.bml";
extern "C" __declspec(section ".rodata") char TObjEneShark__class_name_string[] = "TObjEneShark";
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
extern "C" void run_idle_action__13TUnk_80493450Fv();
extern "C" void trigger_switch_attack__9TObjCharaFv(s32 arg0);
extern "C" void try_start_action__9TObjCharaFll();
extern "C" void update_action_hold_status__13TUnk_80493450Fv();
extern "C" void update_actor_ground_y__9TObjCharaFv();
extern "C" s32 update_defense_stat_status__9TObjCharaFv(u8 *player);
extern "C" void update_flag30_timer__9TObjCharaFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
extern "C" void update_poison_status__9TObjCharaFv();
extern "C" void update_shock_clock__9TObjCharaFv();
extern "C" void update_turn_toward_target__13TUnk_80493450Fv();
extern void *bm_ene_bm1_shark_model_names[4];
extern void *bm_ene_bm1_shark_motion_names[13];
void *bm_ene_bm1_shark_model_names[4] = {
    (void *)&lbl_8043AD10, (void *)&shark_model_name_bm1tl_s_wala_body_nj, (void *)&shark_model_name_bm1_s_wala_body_nj, (void *)0x0,
};
void *bm_ene_bm1_shark_motion_names[13] = {
    (void *)&shark_motion_name_appear_bm1_s_wala_body_njm, (void *)&shark_motion_name_atackl_bm1_s_wala_body_njm, (void *)&shark_motion_name_atackr_bm1_s_wala_body_njm, (void *)&shark_motion_name_damage_bm1_s_wala_body_njm,
    (void *)&shark_motion_name_deadb_bm1_s_wala_body_njm, (void *)&shark_motion_name_dead_bm1_s_wala_body_njm, (void *)&shark_motion_name_leader_bm1_s_wala_body_njm, (void *)&shark_motion_name_mihari_bm1_s_wala_body_njm,
    (void *)&shark_motion_name_run_bm1_s_wala_body_njm, (void *)&shark_motion_name_stund_bm1_s_wala_body_njm, (void *)&shark_motion_name_wakeup_bm1_s_wala_body_njm, (void *)&shark_motion_name_walk_bm1_s_wala_body_njm,
    (void *)0x0,
};
void *bm_ene_bm1_shark_resource_descriptor[4] = {
    (void *)&bm_ene_bm1_shark_bml_filename, (void *)&bm_ene_bm1_shark_model_names, (void *)&bm_ene_bm1_shark_motion_names, (void *)0x3000c,
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
    (void *)&refresh_target__13TUnk_80493450Fv, (void *)&has_no_target__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__13TUnk_80493450Fv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__13TUnk_80493450Fv, (void *)&update_slow_status__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__13TUnk_80493450Fv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&run_idle_action__13TUnk_80493450Fv, (void *)&run_move_action__13TUnk_80493450Fv,
    (void *)&run_attack_action__13TUnk_80493450Fv, (void *)&run_miss_reaction__13TUnk_80493450Fv, (void *)&run_hit_reaction__13TUnk_80493450Fv, (void *)&run_death_reaction__13TUnk_80493450Fv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&deliver_attack_hits__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&gain_photon_blast_charge__9TObjCharaFf,
    (void *)&spend_photon_blast_charge__9TObjCharaFf, (void *)&gain_photon_blast_chain_charge__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&apply_enemy_state__9TObjEnemyFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&beast_update_appear__12TObjEneSharkFv,
    (void *)&beast_idle_update__13TUnk_80493450Fv, (void *)&update_turn_toward_target__13TUnk_80493450Fv, (void *)&beast_update_approach__13TUnk_80493450Fv, (void *)&beast_update_group_chase__13TUnk_80493450Fv,
    (void *)&beast_update_attack__13TUnk_80493450Fv, (void *)&vfunc_89__13TUnk_80493450Fv, (void *)&beast_update_hurt__13TUnk_80493450Fv, (void *)&beast_update_dead__13TUnk_80493450Fv,
    (void *)&beast_retire_corpse__13TUnk_80493450Fv, (void *)&update_attack_trail__12TObjEneSharkFv, (void *)&spawn_death_effect__12TObjEneSharkFv, (void *)&play_alert_sound__12TObjEneSharkFv,
    (void *)&play_attack_sound__12TObjEneSharkFv, (void *)&play_hurt_sound__12TObjEneSharkFv, (void *)&play_death_sound__12TObjEneSharkFv, (void *)&play_group_chase_sound__13TUnk_80493450Fv,
    (void *)&select_post_attack_mode__13TUnk_80493450Fv, (void *)&run_demo_task__12TObjEneSharkFv, (void *)&request_stand_action__13TUnk_80493450Fv,
};
#define TObjEneShark__action_table ((Act_800AC318 *)TObjEneShark__action_table)

void *TObjEneShark::create(void *arg0) {
    void *o;
    void *o2;
    o = TObject::operator new(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = TObject::operator new(0x43C);
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
        delete (SampledMotionPoints *)shark_attack4_trail_buffer;
        shark_attack4_trail_buffer = 0U;
    }
    if ((u32) TObjEneShark__attack_motion_3_trail != 0U) {
        delete (SampledMotionPoints *)TObjEneShark__attack_motion_3_trail;
        TObjEneShark__attack_motion_3_trail = 0U;
    }
    if (shark_bml_resource != NULL) {
        delete shark_bml_resource;
        shark_bml_resource = NULL;
    }
}

#define G_A8 (*(s32 **)&TObjEneShark__resource_node)
#define G_AC (*(s32 **)&TObjEneShark__resource_buf)
#define G_B0 (*(s32 **)&shark_resource_data)
#define G_B4 (*(s32 **)&shark_resource_buffer)
#define G_BC (*(void **)&TObjEneShark__attack_motion_3_trail)
#define G_C0 (*(void **)&shark_attack4_trail_buffer)
void TLobby::load_shark_resources() {
    void *p;
    s32 i;
    if (TObjEneDD::check_v2_mode() != 0) {
        shark_bml_resource = load_enemy_bml_resource_named((BmlResourceDescriptor *)bm_ene_bm1_shark_resource_descriptor, (const char *)bm_ene_bm1_shark_a_bml_filename);
    } else {
        p = new BmlResource(1, (BmlResourceDescriptor *)bm_ene_bm1_shark_resource_descriptor, 0, 0, NULL);
        shark_bml_resource = (BmlResource *)p;
    }
    p = new SampledMotionPoints(2, 7.0f, 12.0f, 1.0f);
    G_BC = p;
    p = new SampledMotionPoints(2, 7.0f, 12.0f, 1.0f);
    G_C0 = p;
    ((SampledMotionPoints *)G_BC)->sample_two_nodes(shark_bml_resource->models->model, (NJS_MOTION *)shark_bml_resource->motions[TObjEneShark__action_table[3].idx].motion, 5, 8);
    ((SampledMotionPoints *)G_C0)->sample_two_nodes(shark_bml_resource->models->model, (NJS_MOTION *)shark_bml_resource->motions[TObjEneShark__action_table[4].idx].motion, 0xA, 0xD);
    G_A8 = (s32 *)mem_alloc(0xC);
    G_AC = (s32 *)mem_alloc(0xC);
    G_B0 = (s32 *)mem_alloc(0xC);
    G_B4 = (s32 *)mem_alloc(0xC);
    G_A8[0] = (saddr)TLobby::register_boss(0x4F);
    G_A8[1] = (saddr)TLobby::register_boss(0x50);
    G_A8[2] = (saddr)TLobby::register_boss(0x51);
    G_AC[0] = (saddr)TLobby::dispatch_shared_handler_b(0x54);
    G_AC[1] = (saddr)TLobby::dispatch_shared_handler_b(0x55);
    G_AC[2] = (saddr)TLobby::dispatch_shared_handler_b(0x56);
    G_B0[0] = (saddr)TLobby::register_object(0x4E);
    G_B0[1] = (saddr)TLobby::register_object(0x4F);
    G_B0[2] = (saddr)TLobby::register_object(0x50);
    G_B4[0] = (saddr)TLobby::dispatch_shared_handler_a(0x4E);
    G_B4[1] = (saddr)TLobby::dispatch_shared_handler_a(0x4F);
    G_B4[2] = (saddr)TLobby::dispatch_shared_handler_a(0x50);
    shark_render_node_index = 0;
    {
        s16 ids[3] = { 0x2F, 0x30, 0x31 };
        NpcAnimationBinding anim = { shark_bml_resource->motions, reinterpret_cast<TObjMotionAction *>(TObjEneShark__action_table), 0, 2, 12 };
        for (i = 0; i < 3; i++) {
            NpcModelRegistry::register_animated_chunk(ids[i], shark_bml_resource->models[i].model, shark_bml_resource->models[i].m_c, &anim,
                7.5f, 0.0f);
        }
    }
}

extern "C" __declspec(section ".rodata") u8 bm_ene_bm1_shark_a_bml_filename[] = "bm_ene_bm1_shark_a.bml";

O_800AC5EC *__dt__12TObjEneSharkFv(O_800AC5EC *arg0, s16 arg1) {
    s32 i;
    if (arg0 != NULL) {
        arg0->vptr = lbl_8049168C;
        for (i = 0; i < 2; i++) {
            if (arg0->objs[i] != NULL) {
                ((TObject *)arg0->objs[i])->queue_destruction();
                arg0->objs[i] = NULL;
            }
        }
        ((TUnk_80493450 *)arg0)->unlink_enemy_group_relations();
        free_collision_body_parts(arg0);
        __destroy_arr((u8 *)arg0 + 0x3CC, __dt__15RenderFadeStateFv, 0x1C, 4);
        __dt__13TUnk_80494938Fv((u8 *)arg0 + 0x3A8, -1);
        __dt__13TUnk_80493450Fv(arg0, 0);
        if (arg1 > 0) {
            TObject::operator delete(arg0);
        }
    }
    return arg0;
}

}

struct SubBase_800AC6B0 { u8 pad[0x14]; };
struct Sub_800AC6B0 : SubBase_800AC6B0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
};
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
    BmlMotionEntry *fDC;
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
    Sub_800AC6B0 f3A8;
    u8 pad3c0[0x3c4 - 0x3c0];
    void *f3C4;
    void *f3C8;
    u8 f3CC[4][0x1C];
};

extern "C" {

void __ct__13TUnk_80493450FP7TObject(void *);
}
int initialize_enemy_photon_effect(void *p);
extern "C" {
void init_collision_body_parts(void *, void *, s32);
void *__construct_array(void *, void *, void *, s32, s32);
void __ct__15RenderFadeStateFv(void *);
extern const char *TObjEneShark_name_ref;
#define lbl_804915B4 ((u8 *)lbl_804915B4)
#define lbl_80491608 ((u8 *)lbl_80491608)
void *TObjEneShark__ct(void *arg0, void *arg1, void *arg2) {
#define self ((Shark_800AC6B0 *)arg0)
    s32 color;
    s32 i;

    ((void (*)(void *, void *))__ct__13TUnk_80493450FP7TObject)(self, arg1);
    *(void **)((u8 *)self + 0x18) = lbl_8049168C;
    __ct__13TUnk_80494938Fv(((u8 *)arg0 + 0x3A8));
    __construct_array(self->f3CC, (void *)__ct__15RenderFadeStateFv, __dt__15RenderFadeStateFv, 0x1C, 4);
    *(const char **)self = TObjEneShark_name_ref;
    self->m79(arg2);
    ((TObjPlayer *)self)->init_position_vectors();
    self->f334 = self->f368;
    ((TObjEneShark *)self)->apply_clamped_mode_param();
    ((TObjEneShark *)self)->sub_800AC9DC(self->f368);
    self->fD8 = TObjEneShark__action_table;
    ((TObjMotion *)self)->set_field_d8((saddr)self->fD8);
    self->fDC = shark_bml_resource->motions;
    self->fB8 = 0;
    ((TObjMotion *)self)->set_animation(self->fB8);
    ((TObjMotion *)self)->set_field_b8(self->fB8);
    init_collision_body_parts(self, lbl_80491608 + self->f334 * 0x2C, 1);
    ((TObjEnemy *)self)->bind_enemy_combat_stats((u8 *)(((saddr *)TObjEneShark__resource_node)[self->f334]), (u8 *)(((saddr *)TObjEneShark__resource_buf)[self->f334]), (u8 *)(((saddr *)shark_resource_data)[self->f334]));
    self->f350 = lbl_804915B4 + self->f334 * 0x1C;
    self->f33E = self->f32C;
    ((TObjEnemy *)self)->update_prev_position();
    ((TBoss3VoloptHiraisin *)self)->copy_position();
    initialize_enemy_photon_effect(self);
    self->f2AC = (s32)(182.04445f * (360.0f * ((TObjChara *)self)->random_ratio()));
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
    self->f3A8.m3();
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
void TUnk_80493450::play_group_chase_sound() {  }

void TObjEneShark::sub_800AC9DC(s32 i) {
    model = shark_bml_resource->models[i].model;
    textures = shark_bml_resource->models[i].m_c;
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
const char *TObjEneShark_name_ref = TObjEneShark__class_name_string;

uaddr TObjEneShark__resource_node;
uaddr TObjEneShark__resource_buf;
uaddr shark_resource_data;
uaddr shark_resource_buffer;
BmlResource *shark_bml_resource;
uaddr TObjEneShark__attack_motion_3_trail;
uaddr shark_attack4_trail_buffer;
s32 shark_render_node_index;
}
