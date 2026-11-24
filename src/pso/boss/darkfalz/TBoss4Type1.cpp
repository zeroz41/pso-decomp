#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/BmlResource.h"
#include <stdlib.h>
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "types.h"
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/PadRumble.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/boss/darkfalz/TBoss4Type1.h"
#include "pso/unk/ModelNodeTables.h"
#include "pso/enemy/BattleParameters.h"
#include "pso/unk/TLobby.h"
#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/vector.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/ambient/TObjFish.h"


#include <stddef.h>
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"


#include "pso/boss/darkfalz/TObjDFTenchuFuru.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/technique/TTecRaBarta.h"
#include "pso/boss/darkfalz/TBoss4Type3_800524E8.h"
#include "pso/player/TObjPlayer_803E1A58.h"

#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixOps.h"
#include "pso/camera/TCameraFollow.h"
#include "pso/boss/darkfalz/TObjDFJisin.h"
#include "pso/boss/darkfalz/TObjDFHorming.h"
#include "pso/object/base/TObjBase.h"

// One row of boss4_type1_motion_states: the playback kind (update_boss4_phase_timer: 0 loop,
// 1 hold, 2 chain to next), the row it chains to and the motion of each of the six body parts.
struct TBoss4Type1Motion { s32 kind, next, motions[6]; };

// One state of the first-form controller.
struct TBoss4Type1State {
    const char *name;
    s32 motion;
    void (TBoss4Type1::*enter)();
    void (TBoss4Type1::*update_idle)();
    void (TBoss4Type1::*update)();
};

struct TBoss4Type1XZ { f32 x, z; };

// Stand angle of each slot, then the weighted attack picks of choose_next_attack.
struct TBoss4Type1AttackTables {
    s32 slot_angles[4];
    f32 low_hp_weights[3];
    s32 low_hp_attacks[3];
    f32 weights[2];
    s32 attacks[2];
};

const char *TBoss4Type1__name = "TBoss4Type1";
f32 lbl_80485AE0[10] = { 0.0f, 0.0f, 0.0f, 25.0f, 2.0f, 25.0f, 0.5f, 0.5f, 0.5f, 0.5f };
s32 boss4_type1_tenchu_hit_effect_ids[2] = { 0xFB, 0xFC };
TBoss4Type1State boss4_type1_states[11] = {
    { "APPEAR", 0, &TBoss4Type1::init_appear_state, &TBoss4Type1::check_state_if_idle, &TBoss4Type1::update_appear },
    { "WAITNEXT", 0, 0, &TBoss4Type1::update_flag800_state, 0 },
    { "MOVESTNDPOS", 0, &TBoss4Type1::init_movestndpos_state, &TBoss4Type1::update_state_transition, &TBoss4Type1::update_move_stnd_pos },
    { "DEAD", 1, &TBoss4Type1::init_dead_state, &TBoss4Type1::update_dead_idle, &TBoss4Type1::tick_state_398_timer },
    { "WAITKILL", -1, 0, 0, 0 },
    { "HAKILOOP", 2, &TBoss4Type1::start_motion_for_index, 0, &TBoss4Type1::update_spawn_uro },
    { "PAKULOOP", 2, &TBoss4Type1::start_motion_for_index, 0, &TBoss4Type1::tick_countdown_set_state7 },
    { "HAKIEND", 4, &TBoss4Type1::set_motion_for_state, &TBoss4Type1::update_state, &TBoss4Type1::update_attack_countdown },
    { "BEAM_L", 11, &TBoss4Type1::init_child_and_set_timer, &TBoss4Type1::update_scale_state, &TBoss4Type1::update_tech_charge },
    { "BEAM_R", 12, &TBoss4Type1::init_child_and_set_timer, &TBoss4Type1::update_scale_state, &TBoss4Type1::update_tech_charge },
    { "TENCHU", 13, &TBoss4Type1::init_timer, &TBoss4Type1::advance_tenchu, &TBoss4Type1::update_tenchu },
};
CollisionBody boss4_type1_collision_body_desc[3] = {
    { { 135.0f, 25.0f, 0.0f }, 30.0f, 0.0f, 0, 0x801B, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 25.0f, 135.0f }, 30.0f, 0.0f, 0, 0x801B, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -135.0f, 25.0f, 0.0f }, 30.0f, 0.0f, 0, 0x801B, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
s32 boss4_type1_model_ids[6] = { 9, 7, 5, 4, 6, 3 };
TBoss4Type1Motion boss4_type1_motion_states[15] = {
    { 0, 0, { 0x50, 0x4e, 0x4d, 0x4d, 0x4d, 0x4c } },
    { 1, 0, { 0x50, 0x4e, 0x15, 0x15, 0x15, 0x14 } },
    { 2, 3, { 0x50, 0x4e, 0x2a, 0x4d, 0x4d, 0x14 } },
    { 0, 4, { 0x50, 0x4e, 0x28, 0x4d, 0x4d, 0x14 } },
    { 2, 0, { 0x50, 0x4e, 0x2c, 0x4d, 0x4d, 0x14 } },
    { 2, 6, { 0x50, 0x4e, 0x4d, 0x2a, 0x4d, 0x14 } },
    { 0, 7, { 0x50, 0x4e, 0x4d, 0x28, 0x4d, 0x14 } },
    { 2, 0, { 0x50, 0x4e, 0x4d, 0x2c, 0x4d, 0x14 } },
    { 2, 9, { 0x50, 0x4e, 0x4d, 0x4d, 0x2a, 0x14 } },
    { 0, 0xa, { 0x50, 0x4e, 0x4d, 0x4d, 0x28, 0x14 } },
    { 2, 0, { 0x50, 0x4e, 0x4d, 0x4d, 0x2c, 0x14 } },
    { 2, 0, { 0x50, 0x4e, 0x4d, 0x4d, 0x4d, 0x0 } },
    { 2, 0, { 0x50, 0x4e, 0x4d, 0x4d, 0x4d, 0x4 } },
    { 2, 0xe, { 0x50, 0x4e, 0x4d, 0x4d, 0x4d, 0x43 } },
    { 2, 0, { 0x50, 0x4e, 0x4d, 0x4d, 0x4d, 0x3d } },
};
f32 player_collider_radius_table[6] = { 75.0f, 60.0f, 60.0f, 60.0f, 40.0f, 30.0f };
TBoss4Type1XZ boss4_type1_xz_offset_table[6] = {
    { 0.0f, 0.0f }, { 50.0f, 0.0f }, { 0.0f, 50.0f }, { -50.0f, 0.0f }, { 0.0f, -80.0f }, { 0.0f, 0.0f },
};
ModelNodePositionEntry boss4_type1_node_capture_entries[3] = {
    {0x1A, {-15.0f, 0.0f, 0.0f}},
    {0x1A, {0.0f, 7.5f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
ModelNodePositionEntry boss4_type1_core_capture_entries[3] = {
    {0xE, {0.0f, 0.0f, 0.0f}},
    {0x54, {0.0f, 0.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
Vec boss4_type1_start_position = { 0.0f, 0.0f, -120.0f };
TBoss4Type1AttackTables boss4_type1_attack_tables = {
    { 0x0, 0xc000, 0x8000, 0x4000 },
    { 0.25f, 0.25f, 0.5f }, { 8, 9, 10 },
    { 0.5f, 0.5f }, { 8, 9 },
};
Vec boss4_type1_vec_table[4] = {
    { 50.0f, 10.0f, 0.0f }, { -50.0f, 10.0f, 0.0f }, { 0.0f, 10.0f, 50.0f }, { 0.0f, 10.0f, -50.0f },
};
Vec boss4_type2_motion_vec_table[4] = {
    { 0.0f, 0.0f, -175.0f }, { 175.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 175.0f }, { -175.0f, 0.0f, 0.0f },
};
s32 boss4_type1_turn_motion_ids[3] = { 2, 5, 8 };
TBoss4Type1XZ boss4_type1_turn_xz_offsets[3] = { { 130.0f, 0.0f }, { 0.0f, 130.0f }, { -130.0f, 0.0f } };
s32 boss4_type2_state_motion_index_table[3] = { 4, 7, 10 };

extern const s32 boss4_type1_emitter_id_table[8] = { 0x144, 0x144, 0x144, 0x144, 0x145, 0x145, 0x145, 0x145 };
extern const ModelNodeSpec boss4_type1_model_node_table[7] = {
    { 9, 1, 0 }, { 7, 1, 0 }, { 5, 2, 0 }, { 4, 2, 0 }, { 6, 2, 0 }, { 3, 5, 0 }, { 3, 0x5E, 0 },
};

Vec TBoss4Type2__tenchu_furu_array[64];

extern "C" {
void pick_tenchu_furu_spots() { pick_tenchu_furu_spots_around(NULL, 0.0f); }

void pick_tenchu_furu_spots_around(const Vec *center, f32 min_dist) {
  Vec *out;
  s32 total;
  s32 cnt;
  s32 i;
  s32 k;
  s32 ang;
  s32 j;
  TObjPlayer *players[4];
  s32 tries;
  f32 ring;
  Vec w;
  Vec v;
  out = TBoss4Type2__tenchu_furu_array;
  for (total = 0; total < 0x40; total++, out++)
  {
    VecCopy(out, (const Vec *)lbl_80485AE0);
  }

  total = 0;
  out = TBoss4Type2__tenchu_furu_array;
  cnt = 0;
  if (is_split_screen())
  {
    cnt = TLobby::get_game_mode();
    if (cnt > 4)
    {
      cnt = 4;
    }
    for (i = 0; i < cnt; i++)
    {
      players[i] = TObjPlayer::get_player_data(i);
      if (players[i] == 0)
      {
        break;
      }
    }

  }
  else
  {
    players[0] = get_player_by_client_id(local_client_id);
    if (players[0] != 0)
    {
      cnt = 1;
    }
  }
  ring = 40.0f;
  for (k = 0; k < cnt; k++)
  {
    total++;
    out->x = players[k]->position.x;
    out->z = players[k]->position.z;
    out++;
    for (ang = 0, j = 0; j < 8; j++, ang += 0x2000)
    {
      out->x = players[k]->position.x + ring * sin_table_lookup(ang);
      out->z = players[k]->position.z + ring * cos_table_lookup(ang);
      out++;
      total++;
    }

  }

  tries = 0;
  while ((tries < 0x100) && (total < 0x40))
  {
    w.x = 460.0f * ((3.0517578e-05f * ((f32) rand())) - 0.5f);
    w.z = 460.0f * ((3.0517578e-05f * ((f32) rand())) - 0.5f);
    w.y = 0.0f;
    if (((w.x * w.x) + (w.z * w.z)) >= 52900.0f)
    {
      goto next;
    }
    if (center != 0)
    {
      VecCopy(&v, center);
      subtract_vector(&v, &w);
      v.y = 0.0f;
      if (vector_length(&v) <= min_dist)
      {
        goto next;
      }
    }
    Vec *p;
    s32 found;
    s32 m;
    found = 0;
    p = TBoss4Type2__tenchu_furu_array;
    for (m = 0; m < total; m++)
    {
      if (xyz_distance(&w, p) <= 12.5f)
      {
        found = 1;
        break;
      }
      p++;
    }

    if (found == 0)
    {
      out->x = w.x;
      out->z = w.z;
      out++;
      total++;
    }
    next:
    tries++;
  }
}

void spawn_tenchu_furu(TObject *parent) {
    Vec *spot = TBoss4Type2__tenchu_furu_array;
    s32 i = 0;
    do {
        TObjDFTenchuFuru::create(parent, spot);
        i += 1;
        spot++;
    } while (i < 64);
}

void apply_tenchu_hits(TObject *source) {
    Vec *spot;
    s32 i;
    s32 n;
    TObjPlayer *player;
    s32 hit;
    s32 count;
    Vec *target;
    s32 j;
    f32 power;
    Vec pos;

    power = (f32)((TBoss4Type2Params *)TLobby::dispatch_shared_handler_a(0x36))->power;
    spot = TBoss4Type2__tenchu_furu_array;
    for (i = 0; i < 0x40; i++) {
        TParticleCtrl *effect = spawn_particle_effect(spot, boss4_type1_tenchu_hit_effect_ids[i & 1]);
        if (effect != NULL) {
            effect->set_flags(0x40);
        }
        spot++;
    }
    count = TLobby::get_game_mode();
    for (n = 0; n < count; n++) {
        player = TObjPlayer::get_player_data(n);
        hit = 0;
        if (player == NULL) {
            continue;
        }
        if (is_player_in_boss_area(player->get_entity_id()) == 0) {
            continue;
        }
        target = TBoss4Type2__tenchu_furu_array;
        VecCopy(&pos, player->get_position_ptr());
        pos.y = 0.0f;
        for (j = 0; j < 0x40; j++) {
            if (xyz_distance(&pos, target) < 25.0f) {
                hit = 1;
                break;
            }
            target++;
        }
        if (hit != 0) {
            DirectAttackPayload h;
            h.kind = 0;
            h.power = power;
            player->receive_direct_attack(source, h, 0, -1, -1);
        }
    }
    play_sound_effect(0x4003A818, 0, 0, 0);
    start_pad_rumble_all(0xC0, 0xF);
}

TBoss4Type1 *TBoss4Type1::create(TBoss4FormSetData *set_data) {
    return new TBoss4Type1(new TObjControl(tl_04), set_data);
}

}

TBoss4Type1::TBoss4Type1(TObject *parent, TBoss4FormSetData *set_data) : TObjEnemy(parent) {
    s32 i;
    s32 j;

    m_name = TBoss4Type1__name;
    add_flags_2e4(8);
    owner = set_data->owner;
    apply_set_data(&set_data->entry);
    clear_lobby_object_state();
    archive = TBoss4Uro::get_instance_count();
    texlist = 0;
    model = 0;
    VecCopy(&position, &boss4_type1_start_position);
    rotation_y = 0;
    VecCopy(&prev_position, VecCopy(&home_position, VecCopy(&center, &position)));
    collision_body_parts = init_collision_body_parts(this, boss4_type1_collision_body_desc, 3);
    VecCopy(&body_center, &position);
    velocity.x = velocity.y = velocity.z = 0.0f;
    target = 0;
    bind_enemy_combat_stats(TLobby::register_boss(0x36), TLobby::dispatch_shared_handler_b(0x36), TLobby::register_object(0x36));
    referenceHp = hp;
    register_by_id();
    set_param(0x2F);
    anim_speed = 0.4f;
    for (i = 0; i < 3; i++) {
        node_captures[i] = ModelNodePositionCapture::create(boss4_type1_node_capture_entries, node_positions[i]);
    }
    core_capture = ModelNodePositionCapture::create(boss4_type1_core_capture_entries, core_positions);
    for (j = 0; j < 8; j++) {
        parts[j] = create_particle_emitter(&position, boss4_type1_emitter_id_table[j]);
    }
    for (; j < 13; j++) {
        parts[j] = 0;
    }
    model_nodes.init(boss4_type1_model_node_table, 7);
    prev_slot = 0;
    slot = 0;
    prev_turn = 1;
    turn = 1;
    move_frames = ((TBoss4Type2Params *)TLobby::dispatch_shared_handler_a(0x36))->move_seconds;
    if (move_frames < 1 || move_frames > 60) {
        move_frames = 25;
    }
    move_frames *= 30.0f;
    uro_limit = TLobby::dispatch_shared_handler_a(0x39)->values.integers[0];
    if (uro_limit < 1) {
        uro_limit = 1;
    } else if (uro_limit > 6) {
        uro_limit = 6;
    }
    uro_count = 0;
    collider_count = 5;
    hit = 0;
    half_hp = hp / 2;
    hit_flash = 0.0f;
    hp_ratio = 1.0f;
    set_state(0);
}


TBoss4Type1::~TBoss4Type1() {
    s32 i;
    s32 j;
    model_nodes.destroy();
    for (i = 0; i < 13; i++) {
        if (parts[i] != 0) {
            TParticleCtrl::release(parts[i]);
            parts[i] = 0;
        }
    }
    for (j = 0; j < 3; j++) {
        ModelNodePositionCapture::destroy(node_captures[j]);
        node_captures[j] = 0;
    }
    ModelNodePositionCapture::destroy(core_capture);
    core_capture = 0;
    free_collision_body_parts(this);
    collision_body_parts = 0;
}

void TBoss4Type1::run_hit_reaction() {
    actorFlags &= ~0x200;
    hit = 1;
    hit_flash = 1.0f;
    play_sound_effect(0x4003A822, &position, 0, 1);
}

void TBoss4Type1::run_death_reaction() {
    if (state != 3 && state != 4) {
        set_state(3);
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss4Type1::run_task() {
    void (TBoss4Type1::*act)();
    if (owner->is_floor_leader() != 0) {
        act = boss4_type1_states[state].update_idle;
        if (act) {
            (this->*act)();
        }
    }
    act = boss4_type1_states[state].update;
    if (act) {
        (this->*act)();
    }
    update_boss4_phase_timer();
    snapshot_position();
    update_collision_bodies();
    update_collisions();
    submit_cursor_candidate(this, -1);
    update_radar_markers();
    update_effect_positions();
    hit_flash += -0.06666667f;
    if (hit_flash < 0.0f) {
        hit_flash = 0.0f;
    }
    hp_ratio = (f32)hp / (f32)referenceHp;
}

#pragma pop
void TBoss4Type1::render() {
    push_players_out_of_colliders();
    render_effects();
    update_follow_camera_offsets();
}

void TBoss4Type1::snapshot_position() {
    VecCopy(&body_center, &position);
    body_center.y += 50.0f;
}

void TBoss4Type1::render_effects() {
    TObjPlayer::toggle_particle_effect();
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    draw_parts();
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

#pragma push
#pragma opt_common_subs off
void TBoss4Type1::update_boss4_phase_timer() {
    f32 frame;
    anim_looped = 0;
    anim_frame = anim_frame + anim_speed;
    switch (anim_mode) {
    case 0:
        frame = anim_frame;
        if (frame >= 30.0f) {
            anim_frame = frame - 30.0f;
            anim_looped = 1;
        }
        break;
    case 1:
        if (anim_frame >= 29.0f) {
            anim_frame = 29.0f;
            anim_looped = 1;
        }
        break;
    case 2:
        if (anim_frame >= 29.0f) {
            anim = boss4_type1_motion_states[anim].next;
            anim_mode = boss4_type1_motion_states[anim].kind;
            anim_frame = 0.0f;
            anim_looped = 1;
        }
        break;
    }
    frame = anim_frame;
    if ((frame < 0.0f) || (frame >= 30.0f)) {
        anim_frame = 0.0f;
    }
}

#pragma pop
void TBoss4Type1::set_motion_index(s32 index) {
    if (index != -1) {
        anim = index;
        anim_frame = 0.0f;
        anim_mode = boss4_type1_motion_states[index].kind;
    }
}

#pragma push
#pragma opt_propagation off
// Body parts 2..4 are the three heads (boss4_type1_model_ids models 5, 4, 6), each with a node capture.
void TBoss4Type1::draw_parts() {
    s32 i;
    s32 head;
    NJS_OBJECT *body_model;
    set_motion_packed_rotation();
    for (i = 0; i < 6; i++) {
        TObjFish::set_global_param(get_bml_texlist(archive, boss4_type1_model_ids[i]));
        switch (i) {
        case 2:
        case 3:
        case 4:
            TBoss6PlotFalz__sub_802AC008(hit_flash, hp_ratio);
            head = i - 2;
            node_captures[head]->install();
            body_model = get_bml_model(archive, boss4_type1_model_ids[i]);
            draw_model_motion(body_model, get_bml_motion(archive, boss4_type1_motion_states[anim].motions[i]), anim_frame);
            node_captures[head]->clear();
            TBoss6PlotFalz::update_camera_target();
            break;
        case 5:
            core_capture->install();
            draw_model_motion(get_bml_model(archive, boss4_type1_model_ids[i]), get_bml_motion(archive, boss4_type1_motion_states[anim].motions[i]), anim_frame);
            core_capture->clear();
            break;
        default:
            draw_model_motion(get_bml_model(archive, boss4_type1_model_ids[i]), get_bml_motion(archive, boss4_type1_motion_states[anim].motions[i]), anim_frame);
            break;
        }
    }
    clear_motion_packed_rotation();
    hit = 0;
}

#pragma pop
s32 TBoss4Type1::calc_slot_angle(s32 slot, s32 turn) {
    return boss4_type1_attack_tables.slot_angles[slot] + (turn - 1) * 0x4000;
}

void TBoss4Type1::set_state(s32 next_state) {
    s32 i;
    TParticleCtrl **p;

    state = next_state;
    for (i = 8; i < 13; i++) {
        p = &parts[i];
        if (*p != NULL) {
            TParticleCtrl::release(*p);
            *p = NULL;
        }
    }
    collider_count = 5;
    set_motion_index(boss4_type1_states[state].motion);
    void (TBoss4Type1::*f)() = boss4_type1_states[state].enter;
    if (f) {
        (this->*f)();
    }
}

void TBoss4Type1::set_pos_from_scaled_offset(Vec *from, Vec *to) {
    Vec v = *to;
    subtract_vector(&v, from);
    v.x *= move_ratio;
    v.y *= move_ratio;
    v.z *= move_ratio;
    VecCopy(&position, from);
    vec3_add_to(&position, &v);
}

void TBoss4Type1::calc_scaled_field(s32 from_angle, s32 to_angle) {
    rotation_y = from_angle + (s32)(move_ratio * (f32)angle_diff_s16(from_angle, to_angle));
}

f32 TBoss4Type1::calc_wave_offset(f32 t) {
    return 0.5f * (1.0f - cos_table_lookup((s32) (32768.0f * t)));
}

void TBoss4Type1::push_players_out_of_colliders() {
    TBoss4Type1XZ pts[7];
    Vec in;
    Vec out;
    s32 i;
    s32 p;
    TObjPlayer *pl;
    s32 j;

    push_matrix();
    set_matrix_identity(0);
    translate_matrix_vec3(0, (u8 *)&position);
    rotate_matrix_y(0, rotation_y);
    for (i = 0; i < collider_count; i++) {
        in.x = boss4_type1_xz_offset_table[i].x;
        in.y = 0.0f;
        in.z = boss4_type1_xz_offset_table[i].z;
        matrix_mult_vec(0, &in, &out);
        pts[i].x = out.x;
        pts[i].z = out.z;
    }
    pop_matrix();
    for (p = 0; p < registered_player_count; p++) {
        pl = TObjPlayer::get_player_data(p);
        if (pl != NULL && pl->get_area() == 0xE) {
            Vec pos = *pl->get_position_ptr();
            Vec d;
            Vec q;
            for (j = 0; j < collider_count; j++) {
                f32 r = player_collider_radius_table[j];
                f32 dist;
                VecCopy(&d, &pos);
                d.x = d.x - pts[j].x;
                d.y = 0.0f;
                d.z = d.z - pts[j].z;
                dist = vector_length(&d);
                if (!(dist > r)) {
                    if (0.0f == dist) {
                        VecCopy(&d, &pos);
                        d.y = 0.0f;
                        if (0.0f == vector_length(&d)) {
                            d.y = 0.0f;
                            d.x = 1.0f;
                            d.z = 0.0f;
                        }
                    }
                    normalize_vector(&d);
                    {
                        f32 s = 0.75f + r;
                        d.x *= s;
                        d.z *= s;
                    }
                    pos.x = d.x + pts[j].x;
                    pos.z = d.z + pts[j].z;
                    VecCopy(&q, &pos);
                    for (;;) {
                        f32 m;
                        q.y += 5.0f;
                        if (project_actor_to_ground(this, &q, 0) != 0) {
                            break;
                        }
                        q.y = 0.0f;
                        m = vector_length(&q) - 0.25f;
                        normalize_vector(&q);
                        q.x *= m;
                        q.z *= m;
                    }
                    VecCopy(&pos, &q);
                }
            }
            if (xyz_distance(pl->get_position_ptr(), &pos) > 0.0f) {
                pl->set_position_from(&pos);
                pl->save_previous_position();
                pl->set_indexed_flags(0, 0x900000);
                pl->actorFlags &= ~0x20;
            }
        }
    }
}

void TBoss4Type1::update_collision_bodies() {
    CollisionBody *body;
    s32 i;
    f32 s;
    f32 c;
    body = collision_body_parts;
    for (i = 0; i < 3; i++, body++) {
        Vec v = node_positions[i][0];
        VecCopy(&body->center, &v);
        subtract_vector(&v, &position);
        s = sin_table_lookup(-rotation_y);
        c = cos_table_lookup(-rotation_y);
        Vec t = v;
        v.x = c * t.x + s * t.z;
        v.z = -s * t.x + c * t.z;
        VecCopy(&body->offset, &v);
    }
}

void TBoss4Type1::send_state_to_target(s32 next_state) {
    if (owner != 0) {
        owner->send_code_25_4((next_state & 0xF) | ((slot & 3) << 4) | ((slot & 3) << 6) | ((turn & 3) << 8) | ((turn & 3) << 10) | ((grid_x & 0xF) << 12) | ((grid_z & 0xF) << 16));
    }
}

void TBoss4Type1::send_darkfalz_code(s32 next_state, s32 next_slot, s32 next_turn) {
    TBoss4DarkFalz *boss4_dark_falz;
    boss4_dark_falz = owner;
    if (boss4_dark_falz != NULL) {
        boss4_dark_falz->send_code_25_4(((((((((((((slot * 0x10) & 0x30 & ~0xF) | (next_state & 0xF)) & ~0xC0) | ((next_slot << 6) & 0xC0)) & ~0x300) | ((turn << 8) & 0x300)) & ~0xC00) | ((next_turn << 0xA) & 0xC00)) & ~0xF000) | ((grid_x << 0xC) & 0xF000)) & ~0xF0000) | ((grid_z << 0x10) & 0xF0000));
    }
}

void TBoss4Type1::apply_packed_state(u32 code) {
    s32 n;
    prev_slot = (code >> 4U) & 3;
    slot = (code >> 6U) & 3;
    prev_turn = (code >> 8U) & 3;
    turn = (code >> 0xAU) & 3;
    if (prev_turn > 2 || turn > 2) {
        return;
    }
    grid_x = (code >> 0xCU) & 0xF;
    grid_z = (code >> 0x10U) & 0xF;
    calc_target_position();
    n = code & 0xF;
    if (n < 0 || n >= 0xB) {
        return;
    }
    set_state(n);
}

void TBoss4Type1::calc_scale_slot_indices(s32 *next_slot, s32 *next_turn) {
    f32 s;
    s32 v;
    v = slot + (s32)(2.97f * random_ratio());
    v += 1;
    if (v >= 4) {
        v -= 4;
    }
    *next_slot = v;
    s = random_ratio();
    if (s <= 0.1f) {
        *next_turn = 0;
    } else if (s <= 0.90000004f) {
        *next_turn = 1;
    } else {
        *next_turn = 2;
    }
}

void TBoss4Type1::calc_target_position() {
    grid_target.x = 29.375f * (0.5f + (f32)grid_x) - 235.0f;
    grid_target.y = 0.0f;
    grid_target.z = 29.375f * (0.5f + (f32)grid_z) - 235.0f;
}

void TBoss4Type1::set_map_position(Vec *pos) {
    grid_x = (s32)((235.0f + pos->x) / 29.375f);
    grid_z = (s32)((235.0f + pos->z) / 29.375f);
}

#pragma push
#pragma opt_propagation off
void TBoss4Type1::pick_target_position(Vec *out) {
    s32 a1;
    TObjPlayer *found;
    s32 i;
    TObjPlayer *p;
    f32 best;
    f32 d;
    f32 s;
    s32 ang;
    s32 b;
    Vec res;
    best = 0.0f;
    found = NULL;
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p == NULL) {
            continue;
        }
        if (is_player_in_boss_area(p->get_entity_id()) == 0) {
            continue;
        }
        {
            Vec v = p->position;
            v.y = 0.0f;
            d = xyz_distance(&v, &position);
            if (d <= 460.0f && d > best) {
                best = d;
                found = p;
                VecCopy(&res, &v);
            }
        }
    }
    if (found != NULL) {
        VecCopy(out, &res);
        return;
    }
    s = 200.625f * random_ratio();
    a1 = (s32)(10430.38043493439 * atan2_float(-position.x, -position.z));
    b = (s32)(49152.0f * random_ratio());
    ang = b + a1;
    ang -= 0x6000;
    out->x = s * sin_table_lookup(ang);
    out->y = 0.0f;
    out->z = s * cos_table_lookup(ang);
}

#pragma pop
void TBoss4Type1::update_radar_markers() {
    f32 s;
    f32 c;
    f32 step;
    s32 i;
    s32 dist;
    Vec pos;

    add_radar_scaled_marker(&position, -0x5DB4, 1, 1, 5.0f);
    add_radar_scaled_marker(&node_positions[0][0], -0x5DB4, 1, 1, 5.0f);
    add_radar_scaled_marker(&node_positions[1][0], -0x5DB4, 1, 1, 5.0f);
    add_radar_scaled_marker(&node_positions[2][0], -0x5DB4, 1, 1, 5.0f);
    s = sin_table_lookup(rotation_y);
    c = cos_table_lookup(rotation_y);
    step = 37.5f;
    i = 0;
    dist = 0x25;
    do {
        VecCopy(&pos, &position);
        pos.x += (f32)(-dist) * c;
        pos.z += (f32)dist * s;
        add_radar_scaled_marker(&pos, -0x5DB4, 1, 1, 5.0f);
        VecCopy(&pos, &position);
        pos.x += (f32)dist * s;
        pos.z += (f32)dist * c;
        add_radar_scaled_marker(&pos, -0x5DB4, 1, 1, 5.0f);
        VecCopy(&pos, &position);
        pos.x += (f32)dist * c;
        pos.z += (f32)(-dist) * s;
        add_radar_scaled_marker(&pos, -0x5DB4, 1, 1, 5.0f);
        if (i < 2) {
            VecCopy(&pos, &position);
            pos.x += (f32)(-dist) * s;
            pos.z += (f32)(-dist) * c;
            add_radar_scaled_marker(&pos, -0x5DB4, 1, 1, 5.0f);
        }
        i += 1;
        dist = (s32) ((f32) dist + step);
    } while (i < 3);
}

void TBoss4Type1::choose_next_attack() {
    Vec target;
    s32 r;
    // The original code addresses the tables relative to the first Type 1 data object.
    TBoss4Type1AttackTables *tables = reinterpret_cast<TBoss4Type1AttackTables *>(
        reinterpret_cast<u8 *>(lbl_80485AE0) + 0x67C);
    if (turn == 1) {
        if (hp <= half_hp) {
            r = TBoss4Type2::pick_weighted_random(3, tables->low_hp_weights, tables->low_hp_attacks);
        } else {
            r = TBoss4Type2::pick_weighted_random(2, tables->weights, tables->attacks);
        }
        switch (r) {
        case 8:
        case 9:
            pick_target_position(&target);
            set_map_position(&target);
            send_state_to_target(r);
            break;
        default:
            send_state_to_target(0xA);
            break;
        }
    } else {
        check_state_transition();
    }
}

void TBoss4Type1::check_state_transition() {
    if (owner->get_live_minion_count() <= (s32) (0xC - uro_limit)) {
        send_state_to_target(5);
        return;
    }
    send_state_to_target(6);
}

void TBoss4Type1::send_move_stnd_pos() {
    s32 next_slot;
    s32 next_turn;
    calc_scale_slot_indices(&next_slot, &next_turn);
    send_darkfalz_code(2, next_slot, next_turn);
}

void TBoss4Type1::update_effect_positions() {
    Vec v;
    s32 i;
    if (state == 4) {
        return;
    }
    for (i = 0; i < 4; i++) {
        VecCopy(&v, &position);
        vec3_add_to(&v, &boss4_type1_vec_table[i]);
        if (parts[i] != NULL) {
            parts[i]->set_position(&v);
        }
        if (parts[i + 4] != NULL) {
            parts[i + 4]->set_position(&v);
        }
    }
    model_nodes.scroll_strips();
    play_persistent_sound(0x4003BC0E, this, &position, 0x40, 2);
}

void TBoss4Type1::update_follow_camera_offsets() {
    TBoss4Type1XZ pts[7];
    Vec in;
    Vec out;
    f32 best;
    s32 i;
    s32 j;
    f32 t;
    u16 cn;
    best = 0.0f;
    push_matrix();
    set_matrix_identity(0);
    translate_matrix_vec3(0, (u8 *)&position);
    rotate_matrix_y(0, rotation_y);
    for (i = 0; i < collider_count; i++) {
        in.x = boss4_type1_xz_offset_table[i].x;
        in.y = 0.0f;
        in.z = boss4_type1_xz_offset_table[i].z;
        matrix_mult_vec(0, &in, &out);
        pts[i].x = out.x;
        pts[i].z = out.z;
    }
    pop_matrix();
    {
        Vec cam = camera_ctrl_instance->pos;
        Vec d;
        for (j = 0; j < collider_count; j++) {
            f32 r = 50.0f + player_collider_radius_table[j];
            f32 len;
            d.x = cam.x - pts[j].x;
            d.y = 0.0f;
            d.z = cam.z - pts[j].z;
            len = vector_length(&d);
            if (!(len >= r)) {
                r -= len;
                if (best < r) {
                    best = r;
                }
            }
        }
    }
    {
        Vec a = { 0.0f, 19.8f, -5.0f };
        Vec b = { 0.0f, 12.93f, 55.42f };
        if (best > 40.42f) {
            best = 40.42f;
        }
        t = best / 40.42f;
        if (t > 0.0f) {
            a.y = -6.869999f * t + 19.8f;
            a.z = -5.0f;
            b.y = 12.93f;
            b.z = -40.42f * t + 55.42f;
        }
        cn = TCameraCtrl::get_nth_view_player_id(TCameraCtrl::get_camera_no());
        request_follow_camera_offsets(&a, &b, cn);
    }
}

void TBoss4Type1::init_appear_state() { state_timer = 75; }

void TBoss4Type1::check_state_if_idle() {
    if (state_timer == 0) {
        check_state_transition();
    }
}

void TBoss4Type1::update_appear() {
    move_ratio = calc_wave_offset(1.0f - (f32)state_timer / 75.0f);
    Vec a = { 0.0f, 0.0f, -120.0f };
    Vec b = { 0.0f, 0.0f, -175.0f };
    set_pos_from_scaled_offset(&a, &b);
    if (--state_timer < 0) {
        set_state(1);
    }
}

void TBoss4Type1::update_flag800_state() {
    if (actorFlags & 0x800) {
        send_state_to_target(4);
        return;
    }
    send_move_stnd_pos();
}

void TBoss4Type1::init_movestndpos_state() { state_timer = move_frames; }

void TBoss4Type1::update_state_transition() {
    if (state_timer == 0) {
        check_state_transition();
    }
}

void TBoss4Type1::update_move_stnd_pos() {
    move_ratio = calc_wave_offset(1.0f - (f32)state_timer / (f32)move_frames);
    {
        Vec a = boss4_type2_motion_vec_table[prev_slot];
        Vec b = boss4_type2_motion_vec_table[slot];
        set_pos_from_scaled_offset(&a, &b);
    }
    calc_scaled_field(calc_slot_angle(prev_slot, prev_turn), calc_slot_angle(slot, turn));
    play_persistent_sound(0x4003A80D, this, &position, 0, 0);
    if (--state_timer < 0) {
        prev_slot = slot;
        prev_turn = turn;
        set_state(1);
    }
}

void TBoss4Type1::init_dead_state() { state_timer = 75; }

void TBoss4Type1::update_dead_idle() {  }

void TBoss4Type1::tick_state_398_timer() {
    if (--state_timer < 0) {
        set_state(4);
    }
}

void copy_vec2(void *dst, void *src) {
    ((f32 *)dst)[0] = ((f32 *)src)[0];
    ((f32 *)dst)[1] = ((f32 *)src)[1];
}

void TBoss4Type1::start_motion_for_index() {
    set_motion_index(boss4_type1_turn_motion_ids[turn]);
    uro_count = 0;
    copy_vec2(&boss4_type1_xz_offset_table[5], &boss4_type1_turn_xz_offsets[turn]);
    collider_count = 6;
    if (state == 5) {
        state_timer = 0x12C;
    } else {
        state_timer = 0x96;
    }
}

void TBoss4Type1::update_spawn_uro() {
    TBoss4ZakoSetData p;
    Vec *s;
    s32 t;
    s = &node_positions[turn][1];
    t = state_timer;
    if (t < 0x106 && (t & 0x1F) == 0 && uro_count < uro_limit) {
        copy_set_entry(&p.set_index, &dark_falz_set_entry);
        if (owner->alloc_child_ids(&p.set_index, &p.entity_id) != 0) {
            p.owner = owner;
            p.unk_0C = 1;
            VecCopy(&p.position, s);
            if (TBoss4Uro::create(&p) != NULL) {
                spawn_particle_effect(s, 0x7D);
                play_sound_effect(0x4003A810, s, 0, 1);
                uro_count++;
            }
        }
    }
    owner->get_live_minion_count();
    if (state_timer == 0x106) {
        play_sound_effect(0x4003AD0F, s, 0, 1);
    }
    if (--state_timer < 0) {
        collider_count = 5;
        set_state(7);
    }
}

void TBoss4Type1::tick_countdown_set_state7() {
    if (--state_timer < 0) {
        collider_count = 5;
        set_state(7);
    }
}

void TBoss4Type1::set_motion_for_state() {
    set_motion_index(boss4_type2_state_motion_index_table[turn]);
    state_timer = 0x3C;
}

void TBoss4Type1::update_state() {
    if (state_timer == 0) {
        if (turn == 1) {
            choose_next_attack();
            return;
        }
        send_move_stnd_pos();
    }
}

void TBoss4Type1::update_attack_countdown() {
    if (state_timer == 0x2D) {
        play_sound_effect(0x4003AD11, &node_positions[turn][1], 0, 1);
    }
    if (--state_timer < 0) {
        set_state(1);
    }
}

void TBoss4Type1::init_child_and_set_timer() {
    TObjDFBeamCursor::create(this, &grid_target);
    state_timer = 75;
}

void TBoss4Type1::update_scale_state() {
    Vec target;
    s32 next_state;

    if (state_timer == 0) {
        if (random_ratio() < 0.5) {
            send_move_stnd_pos();
            return;
        }
        next_state = 8;
        if (state == 8) {
            next_state = 9;
        }
        pick_target_position(&target);
        set_map_position(&target);
        send_state_to_target(next_state);
    }
}

void TBoss4Type1::update_tech_charge() {
    s32 idx;
    Vec *ent;
    TParticleCtrl *particle;
    idx = state - 8;
    ent = &core_positions[idx];
    if (anim_frame > 17.0f) {
        if (parts[8] != 0) {
            TParticleCtrl::release(parts[8]);
            parts[8] = 0;
        }
    } else if (anim_frame >= 8.0f && parts[8] == 0) {
        if ((parts[8] = create_particle_emitter(ent, 0xF7)) != 0) {
            parts[8]->set_flags(0x40);
        }
    }
    if (anim_frame >= 8.0f && anim_frame <= 17.0f) {
        play_persistent_sound(0x4003B512, this, &position, 0, 1);
    }
    if (state_timer == 0x26) {
        if ((particle = spawn_particle_effect(ent, 0xFD)) != 0) {
            particle->set_flags(0x40);
        }
        play_sound_effect(0x4003A813, &position, 0, 1);
        if (idx == 0) {
            TBoss4Type2Params *params = (TBoss4Type2Params *)TLobby::dispatch_shared_handler_a(0x36);
            TTecRaBarta::create(this, &grid_target, &grid_target, params->rabarta_level);
        } else {
            TBoss4Type2Params *params = (TBoss4Type2Params *)TLobby::dispatch_shared_handler_a(0x36);
            TTecRaFoie::create(this, &grid_target, &grid_target, params->rafoie_level);
        }
        start_pad_rumble_all(0xC0, 0xF);
    }
    if (--state_timer < 0) {
        set_state(1);
    }
}

void TBoss4Type1::init_timer() {
    pick_tenchu_furu_spots_around(&position, 125.0f);
    state_timer = 0x96;
}

void TBoss4Type1::advance_tenchu() {
    if (state_timer == 0) {
        if (random_ratio() < 0.75f) {
            choose_next_attack();
            return;
        }
        send_move_stnd_pos();
    }
}

void TBoss4Type1::update_tenchu() {
    Vec *pos0;
    Vec *pos1;
    pos0 = &core_positions[0];
    pos1 = &core_positions[1];
    if (state_timer == 6) {
        spawn_tenchu_furu(this);
    } else if (state_timer == 1) {
        apply_tenchu_hits(this);
    }
    if (anim == 0xD) {
        f32 frame = anim_frame;
        if (frame > 28.0f) {
            if (parts[9] != 0) {
                TParticleCtrl::release(parts[9]);
                parts[9] = 0;
            }
            if (parts[11] != 0) {
                TParticleCtrl::release(parts[11]);
                parts[11] = 0;
            }
        } else if (frame >= 15.0f) {
            if (parts[9] == 0) {
                if ((parts[9] = create_particle_emitter(pos0, 0x142)) != 0) {
                    parts[9]->set_flags(0x40);
                }
            }
            if (parts[11] == 0) {
                if ((parts[11] = create_particle_emitter(pos1, 0x142)) != 0) {
                    parts[11]->set_flags(0x40);
                }
            }
        }
        if (parts[9] != 0) {
            parts[9]->set_position(pos0);
        }
        if (parts[11] != 0) {
            parts[11]->set_position(pos1);
        }
    }
    if (anim == 0xE) {
        f32 frame = anim_frame;
        if (frame > 10.0f) {
            if (parts[9] != 0) {
                TParticleCtrl::release(parts[9]);
                parts[9] = 0;
            }
            if (parts[10] != 0) {
                TParticleCtrl::release(parts[10]);
                parts[10] = 0;
            }
            if (parts[11] != 0) {
                TParticleCtrl::release(parts[11]);
                parts[11] = 0;
            }
            if (parts[12] != 0) {
                TParticleCtrl::release(parts[12]);
                parts[12] = 0;
            }
        } else if (frame >= 2.0f) {
            if (parts[9] == 0) {
                if ((parts[9] = create_particle_emitter(pos0, 0x13A)) != 0) {
                    parts[9]->set_flags(0x40);
                }
                play_sound_effect(0x40039717, &position, 0, 1);
            }
            if (parts[10] == 0) {
                if ((parts[10] = create_particle_emitter(pos0, 0x13B)) != 0) {
                    parts[10]->set_flags(0x40);
                }
            }
            if (parts[11] == 0) {
                if ((parts[11] = create_particle_emitter(pos1, 0x13A)) != 0) {
                    parts[11]->set_flags(0x40);
                }
            }
            if (parts[12] == 0) {
                if ((parts[12] = create_particle_emitter(pos1, 0x13B)) != 0) {
                    parts[12]->set_flags(0x40);
                }
            }
        }
        if (parts[9] != 0) {
            parts[9]->set_position(pos0);
        }
        if (parts[10] != 0) {
            parts[10]->set_position(pos0);
        }
        if (parts[11] != 0) {
            parts[11]->set_position(pos1);
        }
        if (parts[12] != 0) {
            parts[12]->set_position(pos1);
        }
    }
    if (--state_timer < 0) {
        set_state(1);
    }
}
