#include "types.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjFish.h"
#include "pso/quest/TQuestThread.h"

struct Base1_80148e54 { char pad[0x18]; };
struct VObj1_80148e54 : Base1_80148e54 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

struct VBase_18_3eea3b
{
  char pad[0x18];
};

struct VObj_18_3eea3b : VBase_18_3eea3b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual s32 m81();
    virtual s32 m82();
    virtual s32 m83();
    virtual s32 m84();
};

extern "C" {
s32 advance_animation_playback(void *);
s32 submit_cursor_candidate(void *, int);
extern u8 *quest_mission_manager;
extern u8 *quest_area_manager;
void draw_chunk_object(void *child);
void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
u16 find_nearest_visible_player(void *, s32, f32 *, f32);
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix_from(void *src);
s32 pop_matrix();
void *get_player_by_client_id(s32 i);

void TObjNpcBase::vfunc_28() {
    f32 *temp_r5;

    if ((s16) this->mode != 3) {
        if (this->is_actor_cadence_frame(30) != 0) {
            temp_r5 = *(f32 * *)&this->movementParameters;
            this->targetId = find_nearest_visible_player(this, 0, temp_r5, *temp_r5);
            {
                u32 tmp338 = (u32) this->targetId;
                if (tmp338 != 0xFFFF) {
                    *(s32 *)&this->target = (s32)get_player_by_client_id(tmp338);
                } else {
                    this->target = 0;
                }
            }
        }
    }
}

extern s32 model_render_flags;

void TObjPlayer::draw_model() {
    u8 *arg0 = (u8 *)this;
    VObj1_80148e54 *self = (VObj1_80148e54 *)arg0;
    if ((self->m8(*(f32 *)&this->unk_398, *(f32 *)((s8 *)arg0 + 0x39C)) != 0) && ((s32) *(s32 *)&this->unk_390 == 1)) {
        select_actor_lighting((s32)arg0);
        model_render_flags |= 1;
        TObjFish::set_global_param(this->texlist);
        push_matrix_from(0);
        translate_matrix_vec3((u8 *)(0), (u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjPlayer::set_global_flag();
        if ((s32) this->m_394 != 0) {
            draw_chunk_object(this->model);
        } else {
            ((TObjMotion *)arg0)->draw();
        }
        TObjPlayer::clear_global_state();
        pop_matrix();
        model_render_flags &= 0xFFFFFFFE;
        restore_scene_lighting();
        ((TObjEnemy *)arg0)->render_with_position_override(0, 0);
    }
}
typedef struct VBase_18_3eea3b VBase_18_3eea3b;
typedef struct VObj_18_3eea3b VObj_18_3eea3b;
void TObjNpcBase::run_task() {
  s32 temp_r4;
  s32 temp_r4_2;
  u8 *new_var;
  u8 *var_r31;
  if ((((s32) (*((s32 *) (((s8 *) ((u8 *)this)) + ((((((((((0x3A0 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu))))) <= 0) && (((s32)this->m_3a4) <= 0))
  {
    this->m_390 = 1;
    set_indexed_flags(0, 1);
  }
  else
  {
    if (((s32)this->m_38c) == 0)
    {
      var_r31 = (u8 *) quest_mission_manager;
    }
    else
    {
      var_r31 = (u8 *) quest_area_manager;
    }
    temp_r4 = this->m_3a0;
    if (temp_r4 > 0)
    {
      if (TQuestThread::get_register(var_r31, temp_r4) != 0)
      {
        this->m_390 = 1;
        set_indexed_flags(0, 1);
      }
      else
      {
        this->m_390 = 0;
        this->clear_player_status_flag(0, 1U);
      }
    }
    temp_r4_2 = this->m_3a4;
    if ((temp_r4_2 > 0) && (TQuestThread::get_register(var_r31, temp_r4_2) != 0))
    {
      this->m_390 = 0;
      this->clear_player_status_flag(0, 1U);
    }
  }
  switch (this->mode)
  {
    case 0:
      (this->vfunc_83());
      break;
    case 1:
      (this->update_standing());
      break;
    case 2:
      (this->update_wandering());
      break;
    case 3:
      (this->update_conversation());
      break;
  }
  advance_animation_playback((void *) ((u8 *)this));
  this->update_prev_position();
  new_var = ((u8 *)this);
  ((TBoss3VoloptHiraisin *)new_var)->copy_position();
  if ((((s32)this->m_3a8) > 0) && (TRaderMapCore::is_not_split_screen() == 0))
  {
    submit_cursor_candidate((void *) this, -1);
  }
  this->obj_clearFlags30(0x1B3FU);
}

}
