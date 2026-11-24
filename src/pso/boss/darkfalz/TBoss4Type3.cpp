#include "pso/system/BmlAccessors.h"
#include "pso/effect/particle/ParticleFactory.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/object/TObjControl.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/boss/darkfalz/TObjBs4CutAtk.h"
#include "pso/effect/TAttackTrace.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "types.h"
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/unk/ModelNodeTables.h"
#include "pso/system/PadRumble.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/BattleParameters.h"
#include "pso/unk/TLobby.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/render/render_util.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/object/ambient/TObjFish.h"


#include "pso/system/task/TObject.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/TObjBase.h"

extern const char TObjBs4CutAtk_type_name[] = "TObjBs4CutAtk";
extern const char TBoss4Type3_type_name[] = "TBoss4Type3";
extern const char boss4_type3_state_name_appear[] = "APPEAR";
extern const char boss4_type3_state_name_wait_next[] = "WAITNEXT";
extern const char boss4_type3_state_name_wait_kill[] = "WAITKILL";
extern const char boss4_type3_state_name_dead[] = "DEAD";
extern const char boss4_type3_state_name_cut2[] = "CUT2";
extern const char boss4_type3_state_name_cut3[] = "CUT3";
extern const char boss4_type3_state_name_cut4[] = "CUT4";
extern const char boss4_type3_state_name_cut5[] = "CUT5";
extern const char boss4_type3_state_name_go_up[] = "GOUP";
extern const char boss4_type3_state_name_go_down[] = "GODOWN";
extern const char boss4_type3_state_name_homing[] = "HORMING";
extern const char boss4_type3_state_name_light_magic[] = "LMAGIC";
extern const char boss4_type3_state_name_dark_magic[] = "DMAGIC";
extern const char boss4_type3_state_name_capture[] = "CAPTURE";
extern const char boss4_type3_state_name_bura[] = "BURA";
extern const char boss4_type3_state_name_libera[] = "LIBERA";
extern const char boss4_type3_state_name_cut[] = "CUT";
extern const ModelNodeSpec boss4_type3_model_node_specs[2] = {{12, 74, 1}, {14, 74, 1}};
extern const s32 boss4_type3_effect_ids[8] = {326,326,326,326,328,327,327,323};
const char *TObjBs4CutAtk_name = TObjBs4CutAtk_type_name;
const char *TBoss4Type3_name = TBoss4Type3_type_name;
typedef TBoss4Type3Handler Type3Handler;
// A row of TBoss4Type3__anim_state_table: how the animation ends (0 loops, 1 holds
// its last frame, 2 goes on to next) and the motion of each of the three models.
struct Type3MotionView { s32 kind, next, motions[3]; };
#include "pso/boss/darkfalz/TBoss4Zanzo.h"
#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/darkfalz/TObjDFRecover.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/technique/TTecGrants.h"
#include "pso/technique/TTecRaBarta.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/technique/TTecResta.h"
#include "pso/boss/darkfalz/TBoss4Type3_800524E8.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/math/MatrixVector.h"
#include "pso/camera/TCameraFollow.h"
#include "pso/enemy/sorcerer/TObjEneRe4Sorcerer_801E3F14.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/network/client_id.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TargetCursorList.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecMegid.h"
#include "pso/unk/text_80052420.h"
#include "pso/unk/text_803D853C.h"

#pragma defer_codegen on

TBoss4Type3State boss4_type3_states[17] = {
    { boss4_type3_state_name_appear, 0x0, &TBoss4Type3::enter_appear, &TBoss4Type3::advance_appear, &TBoss4Type3::update_appear },
    { boss4_type3_state_name_wait_next, 0x0, 0, &TBoss4Type3::advance_wait_next, 0 },
    { boss4_type3_state_name_wait_kill, -1, 0, 0, 0 },
    { boss4_type3_state_name_dead, 0x9, &TBoss4Type3::enter_dead, &TBoss4Type3::advance_dead, &TBoss4Type3::update_dead },
    { boss4_type3_state_name_cut, 0x3, &TBoss4Type3::enter_cut, &TBoss4Type3::advance_cut, &TBoss4Type3::update_cut },
    { boss4_type3_state_name_cut2, 0x4, &TBoss4Type3::enter_cut, &TBoss4Type3::advance_cut, &TBoss4Type3::update_cut },
    { boss4_type3_state_name_cut3, 0x3, &TBoss4Type3::enter_cut, &TBoss4Type3::advance_cut, &TBoss4Type3::update_cut },
    { boss4_type3_state_name_cut4, 0x4, &TBoss4Type3::enter_cut, &TBoss4Type3::advance_cut, &TBoss4Type3::update_cut },
    { boss4_type3_state_name_cut5, 0x3, &TBoss4Type3::enter_cut, &TBoss4Type3::advance_cut, &TBoss4Type3::update_cut },
    { boss4_type3_state_name_go_up, 0x1, &TBoss4Type3::enter_go_up, &TBoss4Type3::advance_go_up, &TBoss4Type3::update_go_up },
    { boss4_type3_state_name_go_down, 0x2, &TBoss4Type3::enter_go_down, &TBoss4Type3::advance_go_down, &TBoss4Type3::update_go_down },
    { boss4_type3_state_name_homing, 0x0, &TBoss4Type3::enter_homing, &TBoss4Type3::advance_homing, &TBoss4Type3::update_homing },
    { boss4_type3_state_name_light_magic, 0x0, &TBoss4Type3::enter_light_magic, &TBoss4Type3::advance_light_magic, &TBoss4Type3::update_light_magic },
    { boss4_type3_state_name_dark_magic, 0x7, &TBoss4Type3::enter_dark_magic, &TBoss4Type3::advance_dark_magic, &TBoss4Type3::update_dark_magic },
    { boss4_type3_state_name_capture, 0x0, &TBoss4Type3::enter_capture, &TBoss4Type3::advance_capture, &TBoss4Type3::update_capture },
    { boss4_type3_state_name_bura, 0x0, &TBoss4Type3::enter_bura, &TBoss4Type3::advance_bura, &TBoss4Type3::update_bura },
    { boss4_type3_state_name_libera, 0x0, &TBoss4Type3::enter_libera, &TBoss4Type3::advance_libera, &TBoss4Type3::update_libera },
};
CollisionBody boss4_type3_collision_body_desc[1] = {
    {{0.0f, 20.0f, 0.0f}, 45.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
s32 boss4_type3_model_ids[3] = {0xc, 0xd, 0xd};
s32 boss4_type3_index_table[3] = {0xe, 0xf, 0xf};
Type3MotionView TBoss4Type3__anim_state_table[10] = {
    { 0, 0, 83, 84, 85 },
    { 0, 0, 52, 53, 54 },
    { 0, 0, 55, 56, 57 },
    { 2, 0, 64, 65, 66 },
    { 2, 0, 72, 73, 74 },
    { 2, 0, 89, 84, 85 },
    { 2, 0, 58, 59, 60 },
    { 2, 0, 37, 84, 85 },
    { 2, 0, 14, 15, 16 },
    { 1, 0, 19, 84, 85 },
};
ModelNodePositionEntry boss4_type3_body_node_captures[7] = {
    {0x38, {0.0f, 0.0f, 0.0f}},
    {0x34, {0.0f, 0.0f, 0.0f}},
    {0x35, {0.0f, 0.0f, 0.0f}},
    {0x9, {0.0f, 0.0f, 0.0f}},
    {0xA, {0.0f, 0.0f, 0.0f}},
    {0x39, {0.0f, 0.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
ModelNodePositionEntry boss4_type3_wing_node_captures[3] = {
    {0xB, {0.0f, 0.0f, 0.0f}},
    {0xC, {0.0f, 0.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
Vec boss4_type3_start_position = {10000.0f, -10.0f, 0.0f};
const ModelNodePositionEntry *boss4_type3_effect_desc_ptr_table[3] = {
    boss4_type3_body_node_captures, boss4_type3_wing_node_captures, boss4_type3_wing_node_captures,
};
__declspec(section ".data") s32 boss4_type3_run_task_params[2] = {0x34, 0x35};
Vec boss4_type3_zero_vec = {0.0f, 0.0f, 0.0f};
Vec boss4_type3_default_position = {10000.0f, -10.0f, 0.0f};
Vec boss4_type3_interp_origin_vec = {10000.0f, 300.0f, 0.0f};
u32 boss4_type3_radar_marker_colors[4] = {0xffff0000, 0xff00ff00, 0xffffff00, 0xff0000ff};

struct Pair_8005A438 { void *p; f32 f; };

struct Words_8005A438 { void *p; u32 w; };

TObjBs4CutAtk *TObjBs4CutAtk::create(TObject *parent, s32 heading, s32 side) {
    return new TObjBs4CutAtk(parent, heading, side);
}

TObjBs4CutAtk::TObjBs4CutAtk(TObject *parent, s32 heading, s32 side) : TObject(parent) {
    m_name = TObjBs4CutAtk_name;
    if (side == 0) {
        angle = -0x1554;
        angle = angle + (heading << 12);
        angle_step = 0x71C;
    } else {
        angle = 0xE38;
        angle = angle + (heading << 12);
        angle_step = -0x71C;
    }
    age = 0;
}

TObjBs4CutAtk::~TObjBs4CutAtk() {}

void TObjBs4CutAtk::run_task() {
    s32 lo;
    s32 hi;
    s32 i;
    TObjPlayer *player;
    void *attacker;
    u16 ang;

    lo = (u16)angle;
    hi = lo + 0x71C;
    if (TObjEneDD::query_teammate_state() != 0) {
        return;
    }
    for (i = 0; i < TLobby::get_game_mode(); i++) {
        player = TObjPlayer::get_player_data(i);
        if (is_player_in_boss_area(player->get_entity_id()) == 0) {
            continue;
        }
        ang = (s32)(10430.38043493439 * atan2_float(-(player->position.x - 10000.0f), player->position.z));
        if (ang >= lo && ang < hi) {
            DirectAttackPayload hit;
            attacker = m_up;
            hit.kind = 0;
            hit.power = *(s16 *)TLobby::register_boss(0x38);
            player->receive_direct_attack(attacker, hit, NULL, -1, -1);
        }
    }
    if (++age >= 6) {
        queue_destruction();
        return;
    }
    angle += angle_step;
}

void TObjBs4CutAtk::render() {  }

TBoss4Type3 *TBoss4Type3::create(TBoss4FormSetData *set_data) {
    return new TBoss4Type3(new TObjControl(tl_04), set_data);
}

TBoss4Type3::TBoss4Type3(TObject *parent, TBoss4FormSetData *set_data) : TObjEnemy(parent) {
    s32 i;
    NJS_OBJECT *body;

    m_name = TBoss4Type3_name;
    add_flags_2e4(8);
    owner = set_data->owner;
    apply_set_data(&set_data->entry);
    archive = TBoss4Uro::get_instance_count();
    texlist = 0;
    model = 0;
    VecCopy(&position, &boss4_type3_start_position);
    rotation_y = 0;
    VecCopy(&prev_position, VecCopy(&home_position, VecCopy(&center, &position)));
    collision = init_collision_body_parts(this, boss4_type3_collision_body_desc, 1);
    VecCopy(&body_center, &position);
    velocity.x = velocity.y = velocity.z = 0.0f;
    target = 0;
    bind_enemy_combat_stats(TLobby::register_boss(0x38), TLobby::dispatch_shared_handler_b(0x38), TLobby::register_object(0x38));
    referenceHp = drained_hp = hp;
    register_by_id();
    set_param(0x2F);
    anim = 0;
    anim_looped = 0;
    anim_speed = 0.6f;
    anim_frame = 0.0f;
    for (i = 0; i < 3; i++) {
        render_lists[i] = ModelNodePositionCapture::create(boss4_type3_effect_desc_ptr_table[i], node_positions[i]);
    }
    set_motion_packed_rotation();
    body = (NJS_OBJECT *)get_bml_model(archive, boss4_type3_model_ids[0]);
    trail_samples[0] = new SampledMotionPoints(2, 3.0f, 9.0f, 0.6f);
    trail_samples[0]->sample_two_nodes(body, (NJS_MOTION *)get_bml_motion(archive, TBoss4Type3__anim_state_table[3].motions[0]), 0x16, 0x17);
    trails[0] = TAttackTraceStrip::create(0xA0303030, 0xFFFF0088);
    trail_samples[1] = new SampledMotionPoints(2, 3.0f, 9.0f, 0.6f);
    trail_samples[1]->sample_two_nodes(body, (NJS_MOTION *)get_bml_motion(archive, TBoss4Type3__anim_state_table[4].motions[0]), 9, 10);
    trails[1] = TAttackTraceStrip::create(0xA0303030, 0xFFFF0088);
    clear_motion_packed_rotation();
    create_particle_emitters();
    node_tables.init(boss4_type3_model_node_specs, 2);
    prev_hp = hp;
    radius_shown = 0;
    radius_hidden = TLobby::dispatch_shared_handler_a(0x38)->values.integers[3];
    fade = 1.0f;
    fade_timer = 0;
    prev_node = 0x10;
    node = 0x10;
    prev_heading = 0;
    heading = 0;
    capture_target = 0xFFFF;
    captured_player = 0xFFFF;
    radar_color = -0x5DB4;
    move_count = 0;
    captured_fade = 0.0f;
    rumble_timer = 0;
    texture_scroll = 0.0f;
    capture_hp = hp / 2;
    hit_flash = 0.0f;
    hp_ratio = 1.0f;
    camera_mode = 0;
    set_action_from_table(0);
}

TBoss4Type3::~TBoss4Type3() {
    s32 i;
    node_tables.destroy();
    destroy_parts();
    if (trail_samples[0] != 0) {
        delete trail_samples[0];
        trail_samples[0] = 0;
    }
    if (trails[0] != 0) {
        trails[0]->queue_destruction();
        trails[0] = 0;
    }
    if (trail_samples[1] != 0) {
        delete trail_samples[1];
        trail_samples[1] = 0;
    }
    if (trails[1] != 0) {
        trails[1]->queue_destruction();
        trails[1] = 0;
    }
    for (i = 0; i < 3; i++) {
        ModelNodePositionCapture::destroy(render_lists[i]);
        render_lists[i] = 0;
    }
    free_collision_body_parts(this);
    collision = 0;
}

void TBoss4Type3::run_hit_reaction() {
    actorFlags &= ~0x200;
    hit_flash = 1.0f;
    play_sound_effect(0x4003B734, &position, 0, 1);
}

void TBoss4Type3::run_death_reaction() {
    if (state != 3 && state != 2) {
        capture_target = 0xFFFF;
        captured_player = 0xFFFF;
        set_action_from_table(3);
    }
}

#pragma push
#pragma fp_contract on
void TBoss4Type3::run_task() {
    Vec v[2];
    Type3Handler fn;
    SampledMotionPoints *p;
    f32 lim;
    Vec *e;

    if (captured_player != 0xFFFF && is_player_in_boss_area(captured_player) == 0) {
        captured_player = 0xFFFF;
    }
    if (capture_target != 0xFFFF && is_player_in_boss_area(capture_target) == 0) {
        capture_target = 0xFFFF;
    }
    if (owner->is_floor_leader()) {
        fn = boss4_type3_states[state].advance;
        if (fn) {
            (this->*fn)();
        }
    }
    fn = boss4_type3_states[state].update;
    if (fn) {
        (this->*fn)();
    }
    update_phase_timer();
    advance_afterimage();
    if (node != 17) {
        collision->flags |= 1;
        update_collisions();
        submit_cursor_candidate(this, -1);
    } else {
        collision->flags &= ~1;
    }
    update_radar_markers();
    update_scale_sound();
    collision->unk_28 = fade * (f32)(radius_shown - radius_hidden) + (f32)radius_hidden;
    handle_damage_taken();
    if (state != 2) {
        copy_positions_to_parts();
        node_tables.scroll_strips();
    }
    if (captured_player == 0xFFFF) {
        if ((captured_fade -= 0.06666667f) < 0.0f) {
            captured_fade = 0.0f;
        }
    } else {
        if ((captured_fade += 0.06666667f) > 1.0f) {
            captured_fade = 1.0f;
        }
        if (get_player_by_client_id(captured_player) == 0) {
            captured_fade = 0.0f;
        }
    }
    update_target_effect_timer();
    prev_hp = hp;
    request_follow_camera_default_offsets();
    if ((texture_scroll += 0.022222223f) >= 1.0f) {
        texture_scroll -= 1.0f;
    }
    lim = anim_frame;
    if (lim > 29.0f) {
        lim = 29.0f;
    }
    p = new SampledMotionPoints(2, lim, lim, 0.6f);
    set_motion_packed_rotation();
    p->sample((NJS_OBJECT *)get_bml_model(archive, boss4_type3_model_ids[0]), (NJS_MOTION *)get_bml_motion(archive, TBoss4Type3__anim_state_table[anim].motions[0]), boss4_type3_run_task_params, NULL);
    clear_motion_packed_rotation();
    e = p->lookup(lim);
    push_matrix();
    set_matrix_identity(0);
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    matrix_mult_vec(0, &e[0], &v[0]);
    matrix_mult_vec(0, &e[1], &v[1]);
    pop_matrix();
    if (e != 0) {
        if (effect_parts[5] != 0) {
            effect_parts[5]->set_position(&v[0]);
        }
        if (effect_parts[6] != 0) {
            effect_parts[6]->set_position(&v[1]);
        }
    }
    delete p;
    hit_flash += -0.06666667f;
    if (hit_flash < 0.0f) {
        hit_flash = 0.0f;
    }
    hp_ratio = (f32)hp / (f32)referenceHp;
}
#pragma pop

void TBoss4Type3::render() { draw(); }

void TBoss4Type3::advance_afterimage() {
    VecCopy(&body_center, &position);
    body_center.y += 25.0f;
}

void TBoss4Type3::draw() {
    TObjPlayer::toggle_particle_effect();
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    draw_faded_models();
    pop_matrix();
    push_matrix();
    post_translate_matrix(&node_positions[0][5].x);
    rotate_matrix_y(0, rotation_y);
    TObjPlayer::draw_player_model_by_id(captured_player, captured_fade);
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

#pragma push
#pragma opt_common_subs off
void TBoss4Type3::update_phase_timer() {
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
            anim = TBoss4Type3__anim_state_table[anim].next;
            anim_mode = TBoss4Type3__anim_state_table[anim].kind;
            anim_frame = 0.0f;
            anim_looped = 1;
        }
        break;
    }
    frame = anim_frame;
    if (frame < 0.0f || frame >= 30.0f) {
        anim_frame = 0.0f;
    }
}
#pragma pop

void TBoss4Type3::set_anim_state(s32 index) {
    if (index != -1) {
        anim = index;
        anim_frame = 0.0f;
        anim_mode = TBoss4Type3__anim_state_table[index].kind;
    }
}

#pragma push
#pragma opt_propagation off
void TBoss4Type3::draw_model_set(const s32 *tbl, f32 t) {
    f32 c;
    s32 i;
    f32 v;

    if (anim < 0 || anim >= 0xA) {
        return;
    }
    v = anim_frame;
    c = 0.0f;
    if (v < c || v >= 30.0f) {
        return;
    }
    if (c == t) {
        return;
    }
    if (t < 1.0f) {
        TObjPlayer::begin_alpha_blend(t);
    } else if (tbl == boss4_type3_model_ids) {
        TBoss6PlotFalz__sub_802AC008(hit_flash, hp_ratio);
    }
    model_render_flags |= 0x20000;
    TObjEneRe4Sorcerer__sub_801E3F1C(0.0f, texture_scroll);
    set_motion_packed_rotation();
    for (i = 0; i < 3; i++) {
        TObjFish::set_global_param(get_bml_texlist(archive, tbl[i]));
        render_lists[i]->install();
        draw_model_motion((void *)get_bml_model(archive, tbl[i]), (void *)get_bml_motion(archive, TBoss4Type3__anim_state_table[anim].motions[i]), anim_frame);
        render_lists[i]->clear();
    }
    clear_motion_packed_rotation();
    model_render_flags &= ~0x20000;
    if (t < 1.0f) {
        TObjPlayer::sync_player_globals();
        return;
    }
    if (tbl == boss4_type3_model_ids) {
        TBoss6PlotFalz::update_camera_target();
    }
}
#pragma pop

void TBoss4Type3::copy_pair(void* q) { *(u32 *)&this->m_name = *(u32*)((char*)q + 0x0); (*(f32 *)&this->m_flags) = *(f32*)((char*)q + 0x4); }

void TBoss4Type3::draw_faded_models() {
    Pair_8005A438 b;
    Pair_8005A438 a;
    Words_8005A438 tmp;
    Pair_8005A438 *pb = &b;
    a.p = boss4_type3_model_ids;
    a.f = fade;
    b.p = boss4_type3_index_table;
    b.f = 1.0f - a.f;
    if (a.f < 0.5f) {
        tmp.p = boss4_type3_model_ids;
        tmp.w = *(u32 *)&a.f;
        ((TBoss4Type3 *)(&a))->copy_pair(pb);
        ((TBoss4Type3 *)pb)->copy_pair(&tmp);
    }
    this->draw_model_set((const s32 *)a.p, a.f);
    this->draw_model_set((const s32 *)b.p, b.f);
}

void TBoss4Type3::set_action_from_table(s32 action) {
    Type3Handler m;
    release_state_effects();
    state = action;
    set_anim_state(boss4_type3_states[state].animation);
    m = boss4_type3_states[state].enter;
    if (m != 0) {
        (this->*m)();
    }
}

void TBoss4Type3::create_particle_emitters() {
    s32 i;
    for (i = 0; i < 8; i++) {
        effect_parts[i] = create_particle_emitter(&position, boss4_type3_effect_ids[i]);
        if (effect_parts[i] != 0) {
            effect_parts[i]->set_flags(0x40);
        }
    }
    for (; i < 13; i++) {
        effect_parts[i] = 0;
    }
}

void TBoss4Type3::destroy_parts() {
    s32 i;
    for (i = 0; i < 13; i++) {
        if (effect_parts[i] != 0) {
            TParticleCtrl::release(effect_parts[i]);
            effect_parts[i] = 0;
        }
    }
}

void TBoss4Type3::copy_positions_to_parts() {
    Vec *pos[8] = {
        &node_positions[1][0], &node_positions[1][1], &node_positions[2][0], &node_positions[2][1],
        &node_positions[0][0], &node_positions[0][1], &node_positions[0][2], 0
    };
    Vec **p = pos;
    s32 i;
    for (i = 0; i < 8; i++, p++) {
        if (effect_parts[i] != 0 && *p != 0) {
            effect_parts[i]->set_position(*p);
        }
    }
    if (captured_player == 0xFFFF) {
        effect_parts[7]->set_position(&boss4_type3_zero_vec);
    } else {
        effect_parts[7]->set_position(&node_positions[0][5]);
    }
}

void TBoss4Type3::release_state_effects() {
    s32 i;
    for (i = 8; i < 13; i++) {
        TParticleCtrl **slot = &effect_parts[i];
        if (*slot != 0) {
            TParticleCtrl::release(*slot);
            *slot = 0;
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss4Type3::update_scale_sound() {
    f32 prev;
    s32 s;
    s32 t;
    s = state;
    prev = fade;
    if (s == 2 || s == 3) {
        if ((fade += 0.1f) > 1.0f) {
            fade = 1.0f;
        }
    } else {
        fade_timer++;
        t = fade_timer;
        if (t < 0x78) {
            fade = 1.0f;
        } else if (t < 0x96) {
            if ((fade += -0.033333335f) < 0.0f) {
                fade = 0.0f;
            }
        } else if (t < 0x10E) {
            fade = 0.0f;
        } else if (t < 0x12C) {
            if ((fade += 0.033333335f) > 1.0f) {
                fade = 1.0f;
            }
        } else {
            fade = 1.0f;
            fade_timer = 0;
        }
        if ((0.0f == prev && fade > 0.0f) || (1.0f == prev && fade < 1.0f)) {
            play_sound_effect(0x4003B02F, &position, 0, 1);
        }
        if (prev > 0.0f && 0.0f == fade) {
            play_sound_effect(0x4003AD30, &position, 0, 1);
        }
    }
}
#pragma pop

void TBoss4Type3::send_action(s32 action) {
    if (owner != 0) {
        owner->send_code_25_4((action & 0x1F) | ((node & 0x1F) << 5) | ((node & 0x1F) << 10) | ((heading & 0xF) << 15) | ((heading & 0xF) << 19) | ((capture_target & 0xF) << 23) | ((captured_player & 0xF) << 27));
    }
}

void TBoss4Type3::send_packed_action(s32 action, s32 next_node, s32 next_heading) {
    if (owner != 0) {
        owner->send_code_25_4((action & 0x1F) | ((node & 0x1F) << 5) | ((next_node & 0x1F) << 10) | ((heading & 0xF) << 15) | ((next_heading & 0xF) << 19) | ((capture_target & 0xF) << 23) | ((captured_player & 0xF) << 27));
    }
}

void TBoss4Type3::send_attack_code(s32 action, u16 target) {
    if (owner != 0) {
        owner->send_code_25_4((action & 0x1F) | ((node & 0x1F) << 5) | ((node & 0x1F) << 10) | ((heading & 0xF) << 15) | ((heading & 0xF) << 19) | ((target & 0xF) << 23) | ((captured_player & 0xF) << 27));
    }
}

void TBoss4Type3::spawn_random_effect() {
    s32 sector;

    sector = (s32)(15.99f * random_ratio());
    send_packed_action(0xF, sector, sector);
}

// Unpacks an action sent by send_action, send_attack_code or send_packed_action.
void TBoss4Type3::apply_packed_state(u32 packed) {
    u16 v;
    s32 action;
    prev_node = (packed >> 5) & 0x1F;
    node = (packed >> 10) & 0x1F;
    prev_heading = (packed >> 15) & 0xF;
    heading = (packed >> 19) & 0xF;
    v = (packed >> 23) & 0xF;
    capture_target = v;
    if (v == 0xF) {
        capture_target = 0xFFFF;
    }
    v = (packed >> 27) & 0xF;
    captured_player = v;
    if (v == 0xF) {
        captured_player = 0xFFFF;
    }
    action = packed & 0x1F;
    if (action < 0 || action >= 17) {
        return;
    }
    set_action_from_table(action);
}

#pragma push
#pragma fp_contract on
void TBoss4Type3::interp_position_between_nodes() {
    Vec pts[2];
    s32 ids[2];
    s32 id;
    Vec *p;
    s32 a;
    s32 i;

    a = prev_heading << 12;
    rotation_y = approach_angle_limited(rotation_y, -(a + (s32)(move_ratio * (f32)angle_diff_s16(a, heading << 12))), 0x888);
    ids[0] = prev_node;
    ids[1] = node;
    for (i = 0; i < 2; i++) {
        id = ids[i];
        switch (id) {
        case 16:
            VecCopy(&pts[i], &boss4_type3_default_position);
            break;
        case 17:
            VecCopy(&pts[i], &boss4_type3_interp_origin_vec);
            break;
        default:
            p = &pts[i];
            VecCopy(p, &boss4_type3_default_position);
            id <<= 12;
            p->x += (-100.0f) * sin_table_lookup(id);
            p->z += 100.0f * cos_table_lookup(id);
            break;
        }
    }
    VecCopy(&position, &pts[1]);
    subtract_vector(&position, &pts[0]);
    position.x *= move_ratio;
    position.y *= move_ratio;
    position.z *= move_ratio;
    vec3_add_to(&position, &pts[0]);
}
#pragma pop

s32 TBoss4Type3::choose_attack_heading_sector() {
    Vec v;
    f32 dx;
    u16 id;
    id = pick_random_target_player();
    if (id == 0xFFFFU || is_player_in_boss_area(id) == 0) {
        return get_random_scaled();
    }
    VecCopy(&v, &get_player_by_client_id(id)->position);
    dx = v.x - 10000.0f;
    v.x = dx;
    return ((u32)((s32)(10430.38043493439 * atan2_float(-dx, v.z)) + 0x800) >> 12) & 0xF;
}

s32 TBoss4Type3::get_random_scaled() {
    return (s32)(15.84f * random_ratio());
}

void TBoss4Type3::turn_toward_player(s32 id) {
    TObjPlayer *p;
    if ((u16)id != 0xFFFF) {
        p = get_player_by_client_id((u16)id);
        if (p != NULL) {
            rotation_y = approach_angle_limited(rotation_y, (s32)(10430.38043493439 * atan2_float(p->position.x - 10000.0f, p->position.z)), 0x888);
            calc_grid_index();
        }
    }
}

void TBoss4Type3::calc_grid_index() {
    prev_heading = (s32)(((u32)-(rotation_y + 0x800) >> 12) & 0xF);
    heading = (s32)(((u32)-(rotation_y + 0x800) >> 12) & 0xF);
}

void TBoss4Type3::send_random_action(s32 lo, s32 hi) {
    s32 sector = choose_attack_heading_sector();
    s32 n = (s64)(s32)(0.99f * (f32)(hi - lo + 1) * random_ratio());
    n += lo;
    send_packed_action(n + 4, sector, sector);
}

void TBoss4Type3::update_radar_markers() {
    s32 c[3];
    Vec v;
    u32 col;
    s32 sh;
    u8 tgt;
    u16 id;
    s32 i;
    s32 d;
    TObjPlayer *p;
    f32 f;
    s32 n;
    s32 j;
    col = 0xFFFFA24C;
    id = captured_player;
    if (id != 0xFFFF) {
        if (id >= 4) return;
        col = boss4_type3_radar_marker_colors[id];
    }
    for (i = 0, sh = 0; i < 3; i++, sh += 8) {
        tgt = col >> sh;
        c[i] = (u8)(radar_color >> sh);
        d = tgt - c[i];
        if (d > 0) {
            if ((c[i] = c[i] + 0x10) > tgt) c[i] = tgt;
        } else if (d < 0) {
            if ((c[i] = c[i] - 0x10) < tgt) c[i] = tgt;
        }
    }
    radar_color = c[0] | ((c[2] << 16) | 0xFF000000 | (c[1] << 8));
    if (0.0f == fade && (radar_frame & 4)) {
        add_radar_scaled_marker(&body_center, -1, 1, 1, 5.0f);
    } else {
        add_radar_scaled_marker(&body_center, radar_color, 1, 1, 5.0f);
    }
    if (!(radar_frame & 1) && captured_player != 0xFFFF) {
        p = get_player_by_client_id(captured_player);
        if (p != NULL) {
            VecCopy(&v, &p->position);
            subtract_vector(&v, &position);
            v.y = 0.0f;
            f = vector_length(&v);
            if (!(f < 25.0f)) {
                n = (s32)(f / 25.0f);
                if (n > 0xE) n = 0xE;
                normalize_vector(&v);
                v.x *= 25.0f;
                v.z *= 25.0f;
                {
                Vec w = position;
                vec3_add_to(&w, &v);
                for (j = 0; j < n; j++) {
                    add_radar_scaled_marker(&w, boss4_type3_radar_marker_colors[captured_player], 1, 1, 2.5f);
                    vec3_add_to(&w, &v);
                }
                }
            }
        }
    }
    radar_frame++;
}

void TBoss4Type3::handle_damage_taken() {
    TObjPlayer *p;
    s32 i;
    TParticleCtrl *e;
    if (captured_player == 0xFFFF || state == 2 || state == 3 || hp >= drained_hp ||
        (p = get_player_by_client_id(captured_player)) == NULL) {
        drained_hp = hp;
        return;
    }
    drain_player_hp(captured_player, drained_hp - hp);
    drained_hp = hp;
    create_yutai(this, 2, captured_player);
    Vec pos = p->body_center;
    Vec tgt = node_positions[0][5];
    Vec dir;
    VecCopy(&dir, &tgt);
    subtract_vector(&dir, &pos);
    if (vector_length(&dir) <= 0.01f) {
        return;
    }
    normalize_vector(&dir);
    dir.x *= 25.0f;
    dir.y *= 25.0f;
    dir.z *= 25.0f;
    for (i = 0; i < 8; i++) {
        e = spawn_particle_effect(&pos, 0x38);
        if (e != 0) {
            e->set_flags(0x40);
        }
        vec3_add_to(&pos, &dir);
        if (xyz_distance(&pos, &tgt) <= 12.75f) {
            break;
        }
    }
}

void TBoss4Type3::update_target_effect_timer() {
    s32 frame;
    s32 active;

    active = 1;
    if (state == 0x10) {
        active = 0;
    }
    if (is_split_screen() != 0) {
        if (captured_player == 0xFFFF) {
            active = 0;
        }
    } else if (captured_player != local_client_id) {
        active = 0;
    }
    if (active == 0) {
        rumble_timer = 0;
        return;
    }
    static s32 sound_frame = (s32)8.0f;
    frame = rumble_timer % 39;
    if (frame == 0) {
        start_pad_rumble_client(0x60, 0xF, (s16)captured_player);
    }
    if (frame == sound_frame) {
        play_sound_effect(0x4003C133, 0, 0, 0);
    }
    rumble_timer = rumble_timer + 1;
}

#pragma push
#pragma pool_data off
void TBoss4Type3::request_follow_camera_default_offsets() {
    if (camera_mode == 1) {
        Vec target = {0.0f, 3.0f, 32.0f};
        Vec position = {0.0f, 28.8f, -5.0f};
        request_follow_camera_offsets(&position, &target, 0xFFFF);
        return;
    }
    Vec target = {0.0f, 25.43f, 45.42f};
    Vec position = {0.0f, 19.8f, -5.0f};
    request_follow_camera_offsets(&position, &target, 0xFFFF);
}
#pragma pop

void TBoss4Type3::enter_appear() { state_timer = 147; }

void TBoss4Type3::advance_appear() {
    if (state_timer == 0) {
        send_random_action(0, 2);
    }
}

void TBoss4Type3::update_appear() {
    if (--state_timer < 0) {
        set_action_from_table(1);
    }
}

void TBoss4Type3::advance_wait_next() {
    if (actorFlags & 0x800) {
        send_action(2);
    } else {
        capture_target = 0xFFFF;
        captured_player = 0xFFFF;
        send_action(10);
    }
}

void TBoss4Type3::enter_dead() {
    anim_speed = 0.2f;
    state_timer = 0x31;
}

void TBoss4Type3::advance_dead() {  }

void TBoss4Type3::update_dead() {
    if (--state_timer < 0) {
        set_action_from_table(2);
    }
}

void TBoss4Type3::enter_cut() {
    trails[0]->clear_segments();
    trails[1]->clear_segments();
    set_anim_state(((state - 4) & 1) + 3);
    camera_mode = 0;
    state_timer = 0x31;
}

void TBoss4Type3::advance_cut() {
    s32 sector;
    if (state_timer == 0) {
        if (state == 4) {
            move_count = 0;
            spawn_random_effect();
            return;
        }
        sector = get_random_scaled();
        send_packed_action(state - 1, sector, sector);
    }
}

void TBoss4Type3::update_cut() {
    Vec seg[2];
    s32 side;
    Vec *e;
    if (state_timer > 0x2A) {
        move_ratio = 1.0f - ((state_timer - 0x2A) / 7.0f);
    } else {
        move_ratio = 1.0f;
    }
    interp_position_between_nodes();
    if (state_timer == 0x28) {
        TObjBs4CutAtk::create(this, heading, (state - 4) & 1);
        play_sound_effect(0x4003B228, &position, 0, 1);
    }
    if (anim_frame >= 3.0f && anim_frame <= 9.0f) {
        side = (state - 4) & 1;
        e = trail_samples[side]->lookup(anim_frame);
        if (e != 0) {
            push_matrix();
            set_matrix_identity(0);
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, rotation_y);
            matrix_mult_vec(0, &e[0], &seg[0]);
            matrix_mult_vec(0, &e[1], &seg[1]);
            pop_matrix();
            trails[side]->add_segment(&seg[0], &seg[1]);
        }
    }
    if (--state_timer < 0) {
        set_action_from_table(1);
    }
}

void TBoss4Type3::enter_go_up() {
    prev_node = node;
    node = 0x11;
    prev_heading = heading;
    play_sound_effect(0x4003B031, &position, 0, 1);
    camera_mode = 1;
    state_timer = 0x31;
}

void TBoss4Type3::advance_go_up() {
    u16 id;
    if (state_timer == 0) {
        if (captured_player != 0xFFFF) {
            send_action(0xD);
        } else {
            id = pick_random_target_player();
            if (id != 0xFFFF) {
                send_attack_code(0xB, id);
            } else {
                send_action(0xC);
            }
        }
    }
}

void TBoss4Type3::update_go_up() {
    move_ratio = 1.0f - ((f32)state_timer / 49.0f);
    move_ratio = ease_out_pow6(move_ratio);
    interp_position_between_nodes();
    if (--state_timer < 0) {
        set_action_from_table(1);
    }
}

void TBoss4Type3::enter_go_down() {
    prev_node = 0x11;
    node = 0x10;
    prev_heading = heading;
    play_sound_effect(0x4003B032, &position, 0, 1);
    if (captured_player == 0xFFFF) {
        play_sound_effect(0x4003C62D, 0, 0, 0);
    }
    camera_mode = 0;
    state_timer = 0x31;
}

void TBoss4Type3::advance_go_down() {
    u16 id;
    if (state_timer == 0) {
        if (captured_player != 0xFFFF) {
            send_action(16);
            return;
        }
        id = pick_random_target_player();
        if (hp <= capture_hp && id != 0xFFFF) {
            send_attack_code(14, id);
            return;
        }
        send_random_action(0, 2);
    }
}

void TBoss4Type3::update_go_down() {
    move_ratio = 1.0f - ((f32)state_timer / 49.0f);
    move_ratio = ease_out_pow6(move_ratio);
    interp_position_between_nodes();
    if (--state_timer < 0) {
        set_action_from_table(1);
    }
}

void TBoss4Type3::enter_homing() {
    node = 0x11;
    prev_node = 0x11;
    prev_heading = heading;
    camera_mode = 1;
    state_timer = 0xC4;
}

void TBoss4Type3::advance_homing() {
    if (state_timer == 0) {
        capture_target = 0xFFFF;
        send_action(0xC);
    }
}

void TBoss4Type3::update_homing() {
    Vec *a;
    Vec *b;
    s32 n;
    s32 step;
    s32 v;
    s32 i;
    u16 id;
    a = &node_positions[0][1];
    b = &node_positions[0][2];
    id = capture_target;
    if (id == 0xFFFF) {
        set_action_from_table(1);
        return;
    }
    if (state_timer > 0x93) {
        turn_toward_player(id);
    } else if (state_timer == 0x93) {
        if ((effect_parts[8] = create_particle_emitter(a, 0xF7)) != 0) {
            effect_parts[8]->set_flags(0x40);
        }
        if ((effect_parts[9] = create_particle_emitter(b, 0xF7)) != 0) {
            effect_parts[9]->set_flags(0x40);
        }
        set_anim_state(6);
    } else if (state_timer == 0x75) {
        if (effect_parts[8] != 0) {
            TParticleCtrl::release(effect_parts[8]);
            effect_parts[8] = 0;
        }
        if (effect_parts[9] != 0) {
            TParticleCtrl::release(effect_parts[9]);
            effect_parts[9] = 0;
        }
        camera_mode = 0;
    }
    n = TLobby::dispatch_shared_handler_a(0x38)->values.integers[2];
    if (n < 1 || n > 8) {
        n = 4;
    }
    step = 0x42 / n;
    if (step < 1) {
        step = 1;
    }
    v = 0x75;
    for (i = 0; i < n; i++) {
        if (state_timer == v) {
            create_horming(this, a, capture_target);
            create_horming(this, b, capture_target);
            play_sound_effect(0x4003B229, &position, 0, 1);
            break;
        }
        v += step;
    }
    if (effect_parts[8] != 0) {
        effect_parts[8]->set_position(a);
    }
    if (effect_parts[9] != 0) {
        effect_parts[9]->set_position(b);
    }
    if (--state_timer < 0) {
        set_action_from_table(1);
    }
}

void TBoss4Type3::enter_light_magic() {
    node = 0x11;
    prev_node = 0x11;
    prev_heading = heading;
    camera_mode = 1;
    state_timer = 0x93;
}

void TBoss4Type3::advance_light_magic() {
    if (state_timer == 0) {
        send_action(10);
    }
}

void TBoss4Type3::update_light_magic() {
    TParticleCtrl *p;
    s32 level;
    Vec *origin;
    s32 i;
    origin = &node_positions[0][4];
    if (state_timer == 0x62) {
        set_anim_state(7);
    }
    if (state_timer == 0x49) {
        p = spawn_particle_effect(origin, 0x133);
        if (p != 0) {
            p->set_flags(0x40);
        }
    }
    if (state_timer == 0x45) {
        level = TLobby::dispatch_shared_handler_a(0x38)->values.integers[0];
        for (i = 0; i < 4; i++) {
            if (is_player_in_boss_area(i) != 0) {
                TargetCursorList targets;
                clear_target_cursor_list(&targets);
                targets.count = 1;
                targets.records[0].id = i;
                targets.records[0].flag = 0;
                TTecGrants::create(this, origin, &targets, level);
            }
        }
        start_pad_rumble_all(0xC0, 0xF);
    }
    if (--state_timer < 0) {
        set_action_from_table(1);
    }
}

void TBoss4Type3::enter_dark_magic() {
    node = 0x11;
    prev_node = 0x11;
    prev_heading = heading;
    play_sound_effect(0x4003B238, 0, 0, 0);
    camera_mode = 1;
    state_timer = 0x62;
}

void TBoss4Type3::advance_dark_magic() {
    if (state_timer == 0) {
        send_action(12);
    }
}

#pragma push
#pragma fp_contract on
#pragma opt_loop_invariants off
void TBoss4Type3::update_dark_magic() {
    TObjPlayer *player;
    Vec *target;
    s32 level;
    s32 i;
    f32 s;
    if (state_timer == 0x46) {
        level = TLobby::dispatch_shared_handler_a(0x38)->values.integers[1];
        for (i = 0; i < TLobby::get_game_mode(); i++) {
            player = get_player_by_client_id(i);
            if (is_player_in_boss_area(i) != 0) {
                Vec v = position;
                target = &player->body_center;
                subtract_vector(&v, target);
                if (0.0f == vector_length(&v)) {
                    v.y = 1.0f;
                } else {
                    normalize_vector(&v);
                }
                s = 40.0f * (3.0517578e-05f * (f32)rand()) + 35.0f;
                v.x *= s;
                v.y *= s;
                v.z *= s;
                vec3_add_to(&v, target);
                TTecMegid::create((saddr)this, (saddr)&v, (saddr)target, level);
            }
        }
        start_pad_rumble_all(0xC0, 0xF);
    }
    if (--state_timer < 0) {
        set_action_from_table(1);
    }
}
#pragma pop

void TBoss4Type3::enter_capture() {
    play_sound_effect(0x4003C12B, 0, 0, 0);
    camera_mode = 0;
    state_timer = 0x62;
}

void TBoss4Type3::advance_capture() {
    if (is_player_in_boss_area(capture_target) == 0) {
        capture_target = 0xFFFF;
        captured_player = 0xFFFF;
        send_random_action(0, 2);
        return;
    }
    if (state_timer == 0) {
        captured_player = capture_target;
        capture_target = 0xFFFF;
        play_sound_effect(0x4003C12C, 0, 0, 0);
        move_count = 0;
        spawn_random_effect();
    }
}

void TBoss4Type3::update_capture() {
    Vec v;
    TObjPlayer *p;
    u16 id;
    Vec *pos;
    TParticleCtrl *h;
    id = capture_target;
    if (id == 0xFFFF) {
        set_action_from_table(1);
        return;
    }
    if (id == 0xFFFF || (p = get_player_by_client_id(id)) == NULL) {
        v.x = v.y = v.z = 0.0f;
    } else {
        VecCopy(&v, &p->body_center);
    }
    turn_toward_player(capture_target);
    if (state_timer == 0x31) {
        play_sound_effect(0x4003AA2E, 0, 0, 0);
        start_pad_rumble_client(0xC0, 0xF, (s16)capture_target);
        set_anim_state(5);
    }
    pos = &node_positions[0][4];
    if (state_timer < 0x12) {
        if (effect_parts[10] != NULL) {
            TParticleCtrl::release(effect_parts[10]);
            effect_parts[10] = NULL;
        }
    } else if (state_timer <= 0x21 && effect_parts[10] == 0) {
        h = create_particle_emitter(pos, 0x142);
        effect_parts[10] = h;
        if (h != 0) {
            effect_parts[10]->set_flags(0x40);
        }
    }
    if (effect_parts[10] != NULL) {
        effect_parts[10]->set_position(pos);
    }
    if (state_timer == 0x21) {
        create_yutai(this, 0, capture_target);
    }
    if (state_timer == 0x1C) {
        h = spawn_particle_effect(&v, 0x38);
        if (h != 0) {
            h->set_flags(0x40);
        }
    }
    pos = &v;
    if (state_timer < 2) {
        if (effect_parts[11] != NULL) {
            TParticleCtrl::release(effect_parts[11]);
            effect_parts[11] = NULL;
        }
        if (effect_parts[12] != NULL) {
            TParticleCtrl::release(effect_parts[12]);
            effect_parts[12] = NULL;
        }
    } else if (state_timer <= 0x12) {
        if (effect_parts[11] == 0) {
            h = create_particle_emitter(pos, 0xEA);
            effect_parts[11] = h;
            if (h != 0) {
                effect_parts[11]->set_flags(0x40);
            }
        }
        if (effect_parts[12] == 0) {
            h = create_particle_emitter(pos, 0x139);
            effect_parts[12] = h;
            if (h != 0) {
                effect_parts[12]->set_flags(0x40);
            }
        }
    }
    if (effect_parts[11] != NULL) {
        effect_parts[11]->set_position(pos);
    }
    if (effect_parts[12] != NULL) {
        effect_parts[12]->set_position(pos);
    }
    if (--state_timer < 0) {
        set_action_from_table(1);
    }
}

void TBoss4Type3::enter_bura() {
    camera_mode = 0;
    state_timer = 147;
}

void TBoss4Type3::advance_bura() {
    s32 count;
    u16 id = captured_player;
    if (id != 0xFFFF && is_player_in_boss_area(id) == 0) {
        capture_target = 0xFFFF;
        captured_player = 0xFFFF;
    }
    if (state_timer == 0) {
        move_count = move_count + 1;
        count = move_count;
        if (count >= 5 || (count >= 2 && random_ratio() < 0.5f)) {
            send_action(9);
            return;
        }
        spawn_random_effect();
    }
}

void TBoss4Type3::update_bura() {
    if (state_timer > 0x48) {
        move_ratio = 1.0f - (state_timer - 0x48) / 75.0f;
    } else {
        move_ratio = 1.0f;
    }
    move_ratio = ease_out_pow6(move_ratio);
    interp_position_between_nodes();
    if (--state_timer < 0) {
        set_action_from_table(1);
    }
}

void TBoss4Type3::enter_libera() {
    create_yutai(this, 1, captured_player);
    camera_mode = 0;
    state_timer = 0x62;
}

void TBoss4Type3::advance_libera() {
    if (is_player_in_boss_area(captured_player) == 0) {
        capture_target = 0xFFFF;
        captured_player = 0xFFFF;
        send_random_action(0, 2);
        return;
    }
    if (state_timer == 0) {
        capture_target = 0xFFFF;
        captured_player = 0xFFFF;
        send_random_action(0, 2);
    }
}

void TBoss4Type3::update_libera() {
    u16 id = captured_player;
    if (id == 0xFFFF) {
        set_action_from_table(1);
        return;
    }
    turn_toward_player(id);
    if (state_timer == 0x31) {
        start_pad_rumble_client(0xC0, 0xF, (s16)captured_player);
        capture_target = 0xFFFF;
        captured_player = 0xFFFF;
    }
    if (--state_timer < 0) {
        set_action_from_table(1);
    }
}

void TBoss4Type2::clear_harmful_statuses() {  }

void TBoss4Type2::apply_shock_status() {  }

void TBoss4Type2::apply_movement_ailment(s32) {  }

void TBoss4Type2::apply_confusion_status() {  }

void TBoss4Type2::apply_slow_status() {  }

void TBoss4Type2::apply_paralysis() {  }

void TBoss4Type2::apply_poison_status() {  }
