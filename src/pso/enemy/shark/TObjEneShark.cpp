#include "pso/player/PlayerStats.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/model_render_state.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/TAttackTrace.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "types.h"
#include "pso/enemy/BattleParameters.h"
#include "pso/system/AreaSound.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/moja/TObjEneMoja.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/shark/TObjEneShark.h"
#include "pso/enemy/lappy/TObjEneLappy_800F5DE0.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D853C.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/TObjControl.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/player/TPlyDispData.h"

extern player_stats **TObjEneShark__resource_node;
extern AttackParams **TObjEneShark__resource_buf;
extern ActorParamBlock **shark_resource_data;
extern BattleMovementParams **shark_resource_buffer;
extern BmlResource *shark_bml_resource;
extern SampledMotionPoints *TObjEneShark__attack_motion_3_trail;
extern SampledMotionPoints *shark_attack4_trail_buffer;
extern s32 shark_render_node_index;
extern const char *TObjEneShark_name_ref;
extern __declspec(section ".rodata") char bm_ene_bm1_shark_a_bml_filename[];

void TObjEneShark::run_demo_task() {  }

void TObjEneShark::play_death_sound() {
    play_sound_effect(remap_sound_for_area(0x4003A60C), &position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x300);
}

void TObjEneShark::play_hurt_sound() {
    play_sound_effect(remap_sound_for_area(0x4003A60B), &position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x300);
}

void TObjEneShark::play_attack_sound() {
    play_sound_effect(remap_sound_for_area(0x4003A60D), &position, 0, 0);
}

void TObjEneShark::play_alert_sound() {
    play_sound_effect(remap_sound_for_area(0x4003A60B), &position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x300);
}

void TObjEneShark::spawn_death_effect() {
    Vec stack;
    stack.x = 0.0f;
    stack.y = 10.0f;
    stack.z = 0.5f * stat_block->proportions;
    push_matrix_from(&identity_matrix);
    rotate_matrix_y(0, rotation_y);
    rotate_vector_by_matrix(0, &stack, &stack);
    pop_matrix();
    vec3_add_to(&stack, &position);
    spawn_ground_effect(&stack, 0x23);
    TObjPlayer__sub_800D92BC(&stack, 0xF);
}

void TObjEneShark::update_attack_trail() {
    Vec b;
    Vec a;
    Vec *e;
    s32 idx;
    TAttackTraceStrip *trail;
    if (!(frame < 12.0f)) {
        return;
    }
    switch (requested_action) {
    case 3:
        e = TObjEneShark__attack_motion_3_trail->lookup(frame);
        idx = 0;
        break;
    case 4:
        e = shark_attack4_trail_buffer->lookup(frame);
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
    set_matrix_identity(NULL);
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    matrix_mult_vec_array(NULL, e, &a, 2);
    pop_matrix();
    trail = attack_trails[idx];
    if (trail != NULL) {
        trail->add_segment(&a, &b);
    }
}

void TObjEneShark::apply_clamped_mode_param() {
    s32 temp_r0;
    temp_r0 = subtype;
    if (temp_r0 < 0) {
        subtype = 0;
    } else if (temp_r0 > 2) {
        subtype = 2;
    }
    switch ((s32)subtype) {
    case 2:
        variant = 1;
        set_param(0x12);
        return;
    case 1:
        variant = 0;
        set_param(0x11);
        return;
    default:
        variant = 2;
        set_param(0x10);
        return;
    }
}

void TObjEneShark::beast_update_appear() {
    advance_animation();
    switch (phase) {
    case 0:
    default:
        if (appearing != 0) {
            fade.start_fade_in();
            play_area_sound_effect(&position);
            phase = 1;
        } else {
            phase = 2;
        }
        break;
    case 1:
        if (fade.advance_toward_max() == 1) {
            phase = 2;
            appearing = 0;
        }
        break;
    case 2:
        mode = 1;
        phase = 0;
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

void TObjEneShark::render() {
  s32 res;
  s32 mode;
  s32 fade;
  s32 v28;
  s16 v27;
  s16 v26;
  if (actorFlags & 0x02000000)
  {
    return;
  }
  mode = 0;
  if (is_split_screen() != 0)
  {
    mode = TCameraCtrl::get_camera_mode();
  }
  res = classify_actor_view_detail(200.0f, 400.0f, 30.0f);
  if (res == 0)
  {
    return;
  }
  fade = 0;
  if (TObjEneDD::check_v2_mode() != 0)
  {
    RenderFadeState *f = &camera_fades[mode];
    f->update();
    fade = f->updateFromCamera(&body_center.x);
  }
  select_actor_lighting(this);
  model_render_flags |= 1;
  TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
  push_matrix();
  translate_matrix(0, 0.0f, corpse_offset_y, 0.0f);
  post_translate_matrix(&position.x);
  rotate_matrix_y(0, rotation_y);
  if (TObjPlayer::check_demo_mode() == 1)
  {
    draw_chunk_object(model);
  }
  else
  {
    switch (this->mode)
    {
      case 0:
      case 1:
      case 8:
      case 9:
      {
        u8 *p = *((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) model) + 0x2C)))) + 0x30)))) + 4)))) + 4));
        s16 t = *((s16 *) (((s8 *) p) + 6));
        *((s16 *) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) model) + 0x2C)))) + 0x30)))) + 4)))) + 4)))) + 6)) = (u8) (*((s16 *) (((s8 *) p) + 6)));
        v28 = t;
      }
        break;
    }
    if (in_group == 0)
    {
      s16 a;
      s16 b;
      u8 *p = *((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) model) + 0x2C)))) + 0x30)))) + 0x30)))) + 4)))) + 4));
      a = *((s16 *) (((s8 *) p) + 4));
      b = *((s16 *) (((s8 *) p) + 6));
      *((s16 *) (((s8 *) p) + 4)) = -0xB4;
      v26 = a;
      v27 = b;
      *((s16 *) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) model) + 0x2C)))) + 0x30)))) + 0x30)))) + 4)))) + 4)))) + 6)) = -1;
    }
    TObjPlayer::toggle_particle_effect();
    shark_render_node_index = 0;
    set_chunk_model_node_callback(TObjPlayer::update_particle_by_phase);
    if (appearing == 1)
    {
      if (this->fade.has_visible_opacity() != 0)
      {
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        this->fade.set_flags_and_apply_damage_color();
        if (defer_render() == 0)
        {
          model_render_flags |= 1;
          draw();
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
        camera_fades[mode].set_flags_and_apply_damage_color();
      }
      if (fade != 0)
      {
        if (defer_render() == 0)
        {
          if (res == 1)
          {
            draw();
          }
          else
          {
            draw_motion_model();
          }
        }
      }
      else
        if (res == 1)
      {
        draw();
      }
      else
      {
        draw_motion_model();
      }
      if (fade != 0)
      {
        camera_fades[mode].clear_flag_and_notify();
      }
    }
    set_chunk_model_node_callback(0);
    TParticleCtrl::end_effect_render();
    if (in_group == 0)
    {
      *((s16 *) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) model) + 0x2C)))) + 0x30)))) + 0x30)))) + 4)))) + 4)))) + 4)) = v26;
      *((s16 *) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) model) + 0x2C)))) + 0x30)))) + 0x30)))) + 4)))) + 4)))) + 6)) = v27;
    }
    switch (this->mode)
    {
      case 0:
      case 1:
      case 8:
      case 9:
        *((s16 *) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) (*((u8 **) (((s8 *) model) + 0x2C)))) + 0x30)))) + 4)))) + 4)))) + 6)) = v28;
        break;
    }
  }
  pop_matrix();
  model_render_flags &= ~1;
  restore_scene_lighting();
  switch (this->mode)
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
      draw_ground_shadow(&v, 0);
    }
  }
}

__declspec(section ".rodata") char shark_model_name_bm1f_s_wala_body_nj[] = "bm1f_s_wala_body.nj";
__declspec(section ".rodata") char shark_model_name_bm1tl_s_wala_body_nj[] = "bm1tl_s_wala_body.nj";
__declspec(section ".rodata") char shark_model_name_bm1_s_wala_body_nj[] = "bm1_s_wala_body.nj";
__declspec(section ".rodata") char shark_motion_name_appear_bm1_s_wala_body_njm[] = "appear_bm1_s_wala_body.njm";
__declspec(section ".rodata") char shark_motion_name_atackl_bm1_s_wala_body_njm[] = "atackl_bm1_s_wala_body.njm";
__declspec(section ".rodata") char shark_motion_name_atackr_bm1_s_wala_body_njm[] = "atackr_bm1_s_wala_body.njm";
__declspec(section ".rodata") char shark_motion_name_damage_bm1_s_wala_body_njm[] = "damage_bm1_s_wala_body.njm";
__declspec(section ".rodata") char shark_motion_name_deadb_bm1_s_wala_body_njm[] = "deadb_bm1_s_wala_body.njm";
__declspec(section ".rodata") char shark_motion_name_dead_bm1_s_wala_body_njm[] = "dead_bm1_s_wala_body.njm";
__declspec(section ".rodata") char shark_motion_name_leader_bm1_s_wala_body_njm[] = "leader_bm1_s_wala_body.njm";
__declspec(section ".rodata") char shark_motion_name_mihari_bm1_s_wala_body_njm[] = "mihari_bm1_s_wala_body.njm";
__declspec(section ".rodata") char shark_motion_name_run_bm1_s_wala_body_njm[] = "run_bm1_s_wala_body.njm";
__declspec(section ".rodata") char shark_motion_name_stund_bm1_s_wala_body_njm[] = "stund_bm1_s_wala_body.njm";
__declspec(section ".rodata") char shark_motion_name_wakeup_bm1_s_wala_body_njm[] = "wakeup_bm1_s_wala_body.njm";
__declspec(section ".rodata") char shark_motion_name_walk_bm1_s_wala_body_njm[] = "walk_bm1_s_wala_body.njm";
__declspec(section ".rodata") char bm_ene_bm1_shark_bml_filename[] = "bm_ene_bm1_shark.bml";
__declspec(section ".rodata") char TObjEneShark__class_name_string[] = "TObjEneShark";

const char *bm_ene_bm1_shark_model_names[4] = {
    shark_model_name_bm1f_s_wala_body_nj, shark_model_name_bm1tl_s_wala_body_nj, shark_model_name_bm1_s_wala_body_nj, NULL,
};
const char *bm_ene_bm1_shark_motion_names[13] = {
    shark_motion_name_appear_bm1_s_wala_body_njm, shark_motion_name_atackl_bm1_s_wala_body_njm, shark_motion_name_atackr_bm1_s_wala_body_njm, shark_motion_name_damage_bm1_s_wala_body_njm,
    shark_motion_name_deadb_bm1_s_wala_body_njm, shark_motion_name_dead_bm1_s_wala_body_njm, shark_motion_name_leader_bm1_s_wala_body_njm, shark_motion_name_mihari_bm1_s_wala_body_njm,
    shark_motion_name_run_bm1_s_wala_body_njm, shark_motion_name_stund_bm1_s_wala_body_njm, shark_motion_name_wakeup_bm1_s_wala_body_njm, shark_motion_name_walk_bm1_s_wala_body_njm,
    NULL,
};
BmlResourceDescriptor bm_ene_bm1_shark_resource_descriptor = {
    bm_ene_bm1_shark_bml_filename, bm_ene_bm1_shark_model_names, bm_ene_bm1_shark_motion_names, 3, 12,
};
TObjMotionAction TObjEneShark__action_table[11] = {
    { 1, 0, 9, 0.6f, 0x1 },
    { 2, 0, 7, 0.6f, 0x20 },
    { 1, 2, 11, 1.0f, 0x1 },
    { 2, 0, 1, 1.0f, 0x4 },
    { 2, 0, 2, 1.0f, 0x4 },
    { 1, 0, 8, 1.0f, 0x1 },
    { 2, 0, 3, 1.0f, 0x8 },
    { 2, 0, 10, 0.8f, 0x20 },
    { 3, 0, 5, 0.6f, 0x10 },
    { 3, 0, 4, 0.6f, 0x10 },
    { 2, 0, 6, 0.6f, 0x20 },
};
// Per-subtype movement parameters the ctor points movementParameters at.
BeastMovementParams shark_movement_params[3] = {
    {225.0f, 0.75f, 0x400, {0, 0x1E0000, 1, 0}},
    {250.0f, 0.9f, 0x400, {0, 0x1E0000, 1, 0}},
    {300.0f, 1.0f, 0x400, {0, 0x1E0000, 1, 0}},
};
// Per-subtype collision body the ctor hands init_collision_body_parts.
CollisionBody shark_collision_body_table[3] = {
    { { 0.0f, 12.5f, 0.0f }, 7.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 12.5f, 0.0f }, 7.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 15.0f, 0.0f }, 8.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

void *TObjEneShark::create(void *setData) {
    TObjControl *parent = new TObjControl(tl_04);
    return new TObjEneShark(parent, setData);
}

void TObjEneShark::free_resources() {
    if (TObjEneShark__resource_node != NULL) {
        mem_free(TObjEneShark__resource_node);
        TObjEneShark__resource_node = NULL;
    }
    if (TObjEneShark__resource_buf != NULL) {
        mem_free(TObjEneShark__resource_buf);
        TObjEneShark__resource_buf = NULL;
    }
    if (shark_resource_data != NULL) {
        mem_free(shark_resource_data);
        shark_resource_data = NULL;
    }
    if (shark_resource_buffer != NULL) {
        mem_free(shark_resource_buffer);
        shark_resource_buffer = NULL;
    }
    if (shark_attack4_trail_buffer != NULL) {
        delete shark_attack4_trail_buffer;
        shark_attack4_trail_buffer = NULL;
    }
    if (TObjEneShark__attack_motion_3_trail != NULL) {
        delete TObjEneShark__attack_motion_3_trail;
        TObjEneShark__attack_motion_3_trail = NULL;
    }
    if (shark_bml_resource != NULL) {
        delete shark_bml_resource;
        shark_bml_resource = NULL;
    }
}

void TLobby::load_shark_resources() {
    s32 i;
    if (TObjEneDD::check_v2_mode() != 0) {
        shark_bml_resource = load_enemy_bml_resource_named(&bm_ene_bm1_shark_resource_descriptor, bm_ene_bm1_shark_a_bml_filename);
    } else {
        shark_bml_resource = new BmlResource(1, &bm_ene_bm1_shark_resource_descriptor, 0, 0, NULL);
    }
    TObjEneShark__attack_motion_3_trail = new SampledMotionPoints(2, 7.0f, 12.0f, 1.0f);
    shark_attack4_trail_buffer = new SampledMotionPoints(2, 7.0f, 12.0f, 1.0f);
    TObjEneShark__attack_motion_3_trail->sample_two_nodes(shark_bml_resource->models->model, (NJS_MOTION *)shark_bml_resource->motions[TObjEneShark__action_table[3].motion].motion, 5, 8);
    shark_attack4_trail_buffer->sample_two_nodes(shark_bml_resource->models->model, (NJS_MOTION *)shark_bml_resource->motions[TObjEneShark__action_table[4].motion].motion, 0xA, 0xD);
    TObjEneShark__resource_node = static_cast<player_stats **>(mem_alloc(3 * sizeof(*TObjEneShark__resource_node)));
    TObjEneShark__resource_buf = static_cast<AttackParams **>(mem_alloc(3 * sizeof(*TObjEneShark__resource_buf)));
    shark_resource_data = static_cast<ActorParamBlock **>(mem_alloc(3 * sizeof(*shark_resource_data)));
    shark_resource_buffer = static_cast<BattleMovementParams **>(mem_alloc(3 * sizeof(*shark_resource_buffer)));
    TObjEneShark__resource_node[0] = TLobby::register_boss(0x4F);
    TObjEneShark__resource_node[1] = TLobby::register_boss(0x50);
    TObjEneShark__resource_node[2] = TLobby::register_boss(0x51);
    TObjEneShark__resource_buf[0] = TLobby::dispatch_shared_handler_b(0x54);
    TObjEneShark__resource_buf[1] = TLobby::dispatch_shared_handler_b(0x55);
    TObjEneShark__resource_buf[2] = TLobby::dispatch_shared_handler_b(0x56);
    shark_resource_data[0] = TLobby::register_object(0x4E);
    shark_resource_data[1] = TLobby::register_object(0x4F);
    shark_resource_data[2] = TLobby::register_object(0x50);
    shark_resource_buffer[0] = TLobby::dispatch_shared_handler_a(0x4E);
    shark_resource_buffer[1] = TLobby::dispatch_shared_handler_a(0x4F);
    shark_resource_buffer[2] = TLobby::dispatch_shared_handler_a(0x50);
    shark_render_node_index = 0;
    {
        s16 ids[3] = { 0x2F, 0x30, 0x31 };
        NpcAnimationBinding anim = { shark_bml_resource->motions, TObjEneShark__action_table, 0, 2, 12 };
        for (i = 0; i < 3; i++) {
            TObjNpcEnemy::register_animated_chunk(ids[i], shark_bml_resource->models[i].model, shark_bml_resource->models[i].texlist, &anim,
                7.5f, 0.0f);
        }
    }
}

__declspec(section ".rodata") char bm_ene_bm1_shark_a_bml_filename[] = "bm_ene_bm1_shark_a.bml";

TObjEneShark::~TObjEneShark() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (attack_trails[i] != NULL) {
            attack_trails[i]->queue_destruction();
            attack_trails[i] = NULL;
        }
    }
    unlink_enemy_group_relations();
    free_collision_body_parts(this);
}

// Emitted last-first: the constructor follows the destructor in .text and
// takes the vtable from this unit's pooled .data base.
#pragma defer_codegen on

s32 TObjEneMoja::calc_technique_level() {
    TObjEneMoja *self = this;
    player_stats *p = self->stat_block;
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

void TObjPlayer__sub_800ACA0C(void) {  }

void TObjEneShark::sub_800AC9DC(s32 i) {
    model = shark_bml_resource->models[i].model;
    texlist = shark_bml_resource->models[i].texlist;
}

void TUnk_80493450::play_group_chase_sound() {  }

TObjEneShark::TObjEneShark(TObject *parent, void *setData) : TUnk_80493450(parent) {
    s32 color;
    s32 i;

    m_name = TObjEneShark_name_ref;
    apply_set_data(setData);
    init_position_vectors();
    subtype = variant;
    apply_clamped_mode_param();
    sub_800AC9DC(variant);
    action_table = TObjEneShark__action_table;
    set_action_table(action_table);
    motion_list = shark_bml_resource->motions;
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    init_collision_body_parts(this, &shark_collision_body_table[subtype], 1);
    bind_enemy_combat_stats(TObjEneShark__resource_node[subtype], TObjEneShark__resource_buf[subtype], shark_resource_data[subtype]);
    movementParameters = &shark_movement_params[subtype];
    referenceHp = hp;
    update_prev_position();
    copy_position();
    initialize_enemy_photon_effect(this);
    m_2ac = (s32)(182.04445f * (360.0f * random_ratio()));
    resetTimer = 0xF;
    timer = resetTimer;
    phase = 0;
    retreat_timer = 0;
    pad_376 = 0;
    in_group = 0;
    child_count = 0;
    add_flags_2e4(2);
    actorFlags |= 0x40000;
    if (TObjEneDD::check_v2_mode() != 0) {
        switch ((s32)subtype) {
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
        switch ((s32)subtype) {
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
    fade.reset_obstruction_fade();
    appearing = 1;
    attack_trails[0] = TAttackTraceStrip::create((u32)0xA0303030, (u32)color);
    attack_trails[1] = TAttackTraceStrip::create((u32)0xA0303030, (u32)color);
    far_move_speed = shark_resource_buffer[subtype]->values.floats[0];
    far_anim_speed = shark_resource_buffer[subtype]->values.floats[1];
    near_move_speed = shark_resource_buffer[subtype]->values.floats[2];
    near_anim_speed = shark_resource_buffer[subtype]->values.floats[3];
    for (i = 0; i < 4; i++) {
        camera_fades[i].activate_and_dispatch();
    }
    clear_lobby_object_state();
}


const char *TObjEneShark_name_ref = TObjEneShark__class_name_string;

player_stats **TObjEneShark__resource_node;
AttackParams **TObjEneShark__resource_buf;
ActorParamBlock **shark_resource_data;
BattleMovementParams **shark_resource_buffer;
BmlResource *shark_bml_resource;
SampledMotionPoints *TObjEneShark__attack_motion_3_trail;
SampledMotionPoints *shark_attack4_trail_buffer;
s32 shark_render_node_index;
