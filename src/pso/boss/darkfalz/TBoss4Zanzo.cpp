#include "pso/player/PlayerStats.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/math/FloatRounding.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/BattleParameters.h"
#include "pso/unk/TLobby.h"
#include "pso/object/base/TObjBase.h"
#pragma readonly_strings on
#pragma defer_codegen on
#pragma inline_depth(1)
#pragma dont_inline off
#include "types.h"
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/unk/ModelNodeTables.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/PadRumble.h"
#include "pso/boss/darkfalz/TBoss4Type3_800524E8.h"
#include "pso/boss/darkfalz/TBoss4Zanzo.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"

#include <stddef.h>
#include "pso/boss/darkfalz/TObjBs4CutAtk.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TObjDFTenchuFuru.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/boss/darkfalz/TBoss4Bishi.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/darkfalz/TObjDFRecover.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/camera/TCameraCtrl.h"

#include "pso/ui/hud/TNowLoading.h"
#include "pso/technique/TTecGrants.h"
#include "pso/technique/TTecMegid.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/technique/TTecResta.h"


#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/unk/text_803D853C.h"
#include "pso/render/render_util.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/technique/TTecRaBarta.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/PlayerSlots.h"
#include "pso/camera/TCameraFollow.h"
#include "pso/enemy/sorcerer/TObjEneRe4Sorcerer_801E3F14.h"
#include "pso/render/model_render_state.h"
#include "pso/unk/text_80052420.h"
#include "pso/boss/darkfalz/TObjDFHorming.h"
#include "pso/boss/darkfalz/TBoss4Type1.h"
#include "pso/player/TPlyDispData.h"


const char *boss4_type2_class_name = "TBoss4Type2";

struct TBoss4Type2Action {
    const char *name;
    s32 attack_index;
    void (TBoss4Type2::*enter)();
    void (TBoss4Type2::*update_idle)();
    void (TBoss4Type2::*update)();
};
static TBoss4Type2Action boss4_type2_action_table[14] = {
    {"APPEAR", 0, &TBoss4Type2::appear_enter, &TBoss4Type2::appear_idle, &TBoss4Type2::appear_update},
    {"WAITNEXT", 0, 0, &TBoss4Type2::wait_next_idle, 0},
    {"WAITKILL", -1, 0, 0, 0},
    {"DEAD", 2, &TBoss4Type2::dead_enter, &TBoss4Type2::dead_idle, &TBoss4Type2::dead_update},
    {"MOVE", 0, &TBoss4Type2::move_enter, &TBoss4Type2::move_idle, &TBoss4Type2::move_update},
    {"JISIN", 4, &TBoss4Type2::jisin_enter, &TBoss4Type2::jisin_idle, &TBoss4Type2::jisin_update},
    {"BEAM_L", 0, &TBoss4Type2::beam_enter, &TBoss4Type2::beam_idle, &TBoss4Type2::beam_update},
    {"BEAM_R", 0, &TBoss4Type2::beam_enter, &TBoss4Type2::beam_idle, &TBoss4Type2::beam_update},
    {"TENCHU", 8, &TBoss4Type2::tenchu_enter, &TBoss4Type2::tenchu_idle, &TBoss4Type2::tenchu_update},
    {"MD_STOP1", 0, &TBoss4Type2::md_stop1_enter, &TBoss4Type2::md_stop_idle, &TBoss4Type2::md_stop_update},
    {"MD_STOP2", 0, &TBoss4Type2::md_stop2_enter, &TBoss4Type2::md_stop_idle, &TBoss4Type2::md_stop_update},
    {"MD_STOP3", 0, &TBoss4Type2::md_stop3_enter, &TBoss4Type2::md_stop_idle, &TBoss4Type2::md_stop_update},
    {"MD_STOP4", 0, &TBoss4Type2::md_stop4_enter, &TBoss4Type2::md_stop_idle, &TBoss4Type2::md_stop_update},
    {"MD_RECOVER", 3, &TBoss4Type2::md_recover_enter, &TBoss4Type2::md_recover_idle, &TBoss4Type2::md_recover_update},
};
static CollisionBody boss4_type2_collision_body_parts[1] = {
    {{0.0f, 60.0f, 0.0f}, 40.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
__declspec(section ".data") s32 boss4_zanzo_bml_index_table[2] = {
    0xb, 0xa,
};
// A row of TBoss4Type2__attack_pattern_table: how the animation ends (0 loops, 1 holds its
// last frame, 2 goes on to next) and the motion of each of the two models.
struct TBoss4Type2Motion { s32 kind, next, motions[2]; };
TBoss4Type2Motion TBoss4Type2__attack_pattern_table[10] = {
    {0, 0, 0x52, 0x51}, {2, 0, 0xd, 0xc}, {1, 0, 0x12, 0x11}, {2, 5, 0x31, 0x30}, {2, 0, 0x33, 0x32},
    {2, 0, 0x3f, 0x3e}, {2, 0, 0x3, 0x2}, {2, 0, 0x7, 0x6}, {2, 9, 0x52, 0x44}, {2, 0, 0x52, 0x3e},
};
ModelNodePositionEntry boss4_type2_node_capture_entries[4] = {
    {0xF, {0.0f, 0.0f, 0.0f}},
    {0x55, {0.0f, 0.0f, 0.0f}},
    {0x6B, {0.0f, 0.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
static Vec boss4_type2_start_position = {0.0f, -50.0f, -300.0f};
static f32 boss4_type2_next_action_weights_a[4] = {0.3f, 0.25f, 0.25f, 0.2f};
static s32 boss4_type2_next_actions_a[4] = {5, 6, 7, 13};
static f32 boss4_type2_next_action_weights_b[3] = {0.4f, 0.3f, 0.3f};
static s32 boss4_type2_next_actions_b[3] = {5, 6, 7};
// Where spawn_bishi_around_players puts its three TBoss4Bishi round each player.
struct BishiSpawnOffset { f32 x, z; };
BishiSpawnOffset bishi_spawn_offset_table[3] = {{0.0f, -12.5f}, {-10.75f, 6.25f}, {10.75f, 6.25f}};
__declspec(section ".data") s32 boss4_type2_attack_pattern_table[2] = {6, 7};

static const s32 boss4_type2_emitter_ids[2] = {0x144, 0x145};
static const ModelNodeSpec boss4_type2_model_node_table[6] = {
    {0xB, 3, 0}, {0xA, 5, 0}, {0xA, 0x60, 0}, {0xA, 0x63, 0}, {0xA, 0x65, 0}, {0xA, 0x68, 0},
};
static const Vec boss4_type2_follow_camera_offset_a = {0.0f, 19.8f, -5.0f};
static const Vec boss4_type2_follow_camera_offset_b = {0.0f, 15.43f, 55.42f};
const char *TBoss4Zanzo__name = "TBoss4Zanzo";


TBoss4Type2 *TBoss4Type2::create(TBoss4FormSetData *set_data) {
    return new TBoss4Type2(new TObjControl((TObject *)tl_04), set_data);
}

TBoss4Type2::TBoss4Type2(TObject *parent, TBoss4FormSetData *set_data) : TObjEnemy(parent) {
    s32 i;
    s32 v;

    m_name = boss4_type2_class_name;
    add_flags_2e4(8);
    owner = set_data->owner;
    apply_set_data(&set_data->entry);
    clear_lobby_object_state();
    archive = TBoss4Uro::get_instance_count();
    texlist = 0;
    model = 0;
    VecCopy(&position, &boss4_type2_start_position);
    rotation_y = 0;
    VecCopy(&prev_position, VecCopy(&home_position, VecCopy(&center, &position)));
    collision_body_parts = init_collision_body_parts(this, boss4_type2_collision_body_parts, 1);
    VecCopy(&body_center, &position);
    velocity.x = velocity.y = velocity.z = 0.0f;
    target = 0;
    bind_enemy_combat_stats(TLobby::register_boss(0x37), TLobby::dispatch_shared_handler_b(0x37), TLobby::register_object(0x37));
    referenceHp = hp;
    register_by_id();
    set_param(0x2F);
    unk_3cc = 0;
    anim = 0;
    anim_looped = 0;
    anim_speed = 0.4f;
    anim_frame = 0.0f;
    node_capture = ModelNodePositionCapture::create(boss4_type2_node_capture_entries, node_positions);
    for (i = 0; i < 2; i++) {
        parts[i] = create_particle_emitter(&position, boss4_type2_emitter_ids[i]);
    }
    for (; i < 8; i++) {
        parts[i] = 0;
    }
    node_tables.init(boss4_type2_model_node_table, 6);
    angle = 0;
    move_count = 0;
    target_player = 0xFFFF;
    move_frames = floor_to_float(TLobby::dispatch_shared_handler_a(0x37)->values.floats[0]);
    if (move_frames < 1 || move_frames > 25) {
        move_frames = 4;
    }
    move_frames *= 75;
    move_turn_frames = move_frames - 7;
    v = TLobby::dispatch_shared_handler_a(0x37)->values.integers[0];
    if (v < 1 || v > 4) {
        v = 1;
    }
    stop_action = v + 8;
    resta_level = TLobby::dispatch_shared_handler_a(0x37)->values.integers[1];
    if (resta_level < 0 || resta_level > 14) {
        resta_level = 0;
    }
    texture_scroll = 0.0f;
    hit = 0;
    beam_ratio = 0.0f;
    half_hp = hp / 2;
    hit_flash = 0.0f;
    hp_ratio = 1.0f;
    change_action(0);
}

TBoss4Type2::~TBoss4Type2() {
    s32 i;
    node_tables.destroy();
    for (i = 0; i < 8; i++) {
        if (parts[i] != 0) {
            TParticleCtrl::release(parts[i]);
            parts[i] = 0;
        }
    }
    ModelNodePositionCapture::destroy(node_capture);
    node_capture = 0;
    free_collision_body_parts(this);
    collision_body_parts = 0;
}

void TBoss4Type2::run_hit_reaction() {
    hit = 1;
    hit_flash = 1.0f;
    actorFlags &= ~0x200;
    play_sound_effect(0x4003B723, &position, 0, 1);
}

void TBoss4Type2::run_death_reaction() {
    if (action != 3 && action != 2) {
        change_action(3);
    }
}

void TBoss4Type2::run_task() {
    void (TBoss4Type2::*fn)();

    if (owner->is_floor_leader() != 0) {
        fn = boss4_type2_action_table[action].update_idle;
        if (fn != 0) {
            (this->*fn)();
        }
    }
    fn = boss4_type2_action_table[action].update;
    if (fn != 0) {
        (this->*fn)();
    }
    update_phase_timer();
    advance_afterimage();
    if (0.0f == beam_ratio) {
        collision_body_parts->flags |= 1;
        update_collisions();
        submit_cursor_candidate(this, -1);
    } else {
        collision_body_parts->flags &= ~1;
    }
    add_radar_scaled_marker(&body_center, 0xFFFFA24C, 1, 1, 5.0f);
    if (action != 2) {
        Vec pos = position;
        Vec dir = position;
        dir.y = 0.0f;
        normalize_vector(&dir);
        dir.x *= -50.0f;
        dir.z *= -50.0f;
        dir.y = 50.0f;
        vec3_add_to(&pos, &dir);
        if (parts[0] != NULL) {
            parts[0]->set_position(&pos);
        }
        if (parts[1] != NULL) {
            parts[1]->set_position(&pos);
        }
        node_tables.scroll_strips();
    }
    {
        Vec a = boss4_type2_follow_camera_offset_a;
        Vec b = boss4_type2_follow_camera_offset_b;
        request_follow_camera_offsets(&a, &b, 0xFFFF);
    }
    if ((texture_scroll += 0.022222223f) >= 1.0f) {
        texture_scroll -= 1.0f;
    }
    hit_flash += -0.06666667f;
    if (hit_flash < 0.0f) {
        hit_flash = 0.0f;
    }
    hp_ratio = (f32)hp / (f32)referenceHp;
}

void TBoss4Type2::render() { init_hanger(); }

void TBoss4Type2::advance_afterimage() {
    VecCopy(&body_center, &position);
    body_center.y += 75.0f;
}

void TBoss4Type2::init_hanger() {
    TObjPlayer::toggle_particle_effect();
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    draw_hanger();
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

#pragma push
#pragma opt_common_subs off
void TBoss4Type2::update_phase_timer() {
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
            anim = TBoss4Type2__attack_pattern_table[anim].next;
            anim_mode = TBoss4Type2__attack_pattern_table[anim].kind;
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

void TBoss4Type2::set_attack_pattern_by_index(s32 index) {
    if (index != -1) {
        anim = index;
        anim_frame = 0.0f;
        anim_mode = TBoss4Type2__attack_pattern_table[index].kind;
    }
}

void TBoss4Type2::draw_hanger() {
    s32 i;
    set_motion_packed_rotation();
    for (i = 0; i < 2; i++) {
        TObjFish::set_global_param(get_bml_texlist(archive, boss4_zanzo_bml_index_table[i]));
        switch (i) {
        case 1:
            model_render_flags |= 0x20000;
            TObjEneRe4Sorcerer__sub_801E3F1C(0.0f, texture_scroll);
            node_capture->install();
            draw_model_motion((void *)get_bml_model(archive, boss4_zanzo_bml_index_table[i]),
                (void *)get_bml_motion(archive, TBoss4Type2__attack_pattern_table[anim].motions[i]),
                anim_frame);
            node_capture->clear();
            model_render_flags &= ~0x20000;
            break;
        default:
            TBoss6PlotFalz__sub_802AC008(hit_flash, hp_ratio);
            draw_model_motion((void *)get_bml_model(archive, boss4_zanzo_bml_index_table[i]),
                (void *)get_bml_motion(archive, TBoss4Type2__attack_pattern_table[anim].motions[i]),
                anim_frame);
            TBoss6PlotFalz::update_camera_target();
            break;
        }
    }
    clear_motion_packed_rotation();
    hit = 0;
}

saddr TBoss4Type2::pick_random_angle() {
    return (s32)(49152.0f * random_ratio()) + 0x2000 + angle;
}

#pragma push
#pragma fp_contract on
void TBoss4Type2::update_orbit_position() {
    f32 radius;
    f32 height;

    angle = base_angle + (s32)(turn_ratio * (f32)angle_diff_s16(base_angle, target_angle));
    radius = 300.0f;
    height = -50.0f;
    if (beam_ratio > 0.0f) {
        f32 w = TBoss4Type3::compute_wave_offset(beam_ratio);
        radius = 30.0f * w + 300.0f;
        height = -45.0f * w + -50.0f;
    }
    position.x = radius * sin_table_lookup(angle);
    position.y = height;
    position.z = -radius * cos_table_lookup(angle);
    rotation_y = -angle;
}
#pragma pop

void TBoss4Type2::change_action(s32 next_action) {
    s32 i;
    void (TBoss4Type2::*enter)();

    action = next_action;
    for (i = 2; i < 8; i++) {
        TParticleCtrl **part = &parts[i];
        if (*part != NULL) {
            TParticleCtrl::release(*part);
            *part = NULL;
        }
    }
    if (action != 4) {
        move_count = 0;
    }
    set_attack_pattern_by_index(boss4_type2_action_table[action].attack_index);
    enter = boss4_type2_action_table[action].enter;
    if (enter != 0) {
        (this->*enter)();
    }
}

void TBoss4Type2::send_action(s32 next_action) {
    if (owner != 0) {
        owner->send_code_25_4((next_action & 0xF) | (((angle >> 12) & 0xF) << 4) | (((angle >> 12) & 0xF) << 8) | ((grid_x & 0xF) << 12) | ((grid_z & 0xF) << 16) | ((target_player & 0xF) << 20));
    }
}

void TBoss4Type2::send_turn_action(s32 next_action, s32 next_angle) {
    if (owner != 0) {
        owner->send_code_25_4((next_action & 0xF) | (((angle >> 12) & 0xF) << 4) | (((next_angle >> 12) & 0xF) << 8) | ((grid_x & 0xF) << 12) | ((grid_z & 0xF) << 16) | ((target_player & 0xF) << 20));
    }
}

void TBoss4Type2::send_attack_code(s32 next_action, u16 id) {
    if (owner != 0) {
        owner->send_code_25_4((next_action & 0xF) | (((angle >> 12) & 0xF) << 4) | (((angle >> 12) & 0xF) << 8) | ((grid_x & 0xF) << 12) | ((grid_z & 0xF) << 16) | ((id & 0xF) << 20));
    }
}

void TBoss4Type2::apply_packed_state(u32 code) {
    s32 target_bits;
    s32 next_action;

    angle = base_angle = (code << 8) & 0xF000;
    target_angle = (code << 4) & 0xF000;
    grid_x = (code >> 12) & 0xF;
    grid_z = (code >> 16) & 0xF;
    target_bits = code >> 20;
    target_player = target_bits & 0xF;
    if (((code >> 20) & 0xF) == 0xF) {
        target_player = 0xFFFF;
    }
    calc_grid_target_position();
    next_action = code & 0xF;
    if (next_action < 0 || next_action >= 14) {
        return;
    }
    change_action(next_action);
}

f32 TBoss4Type2::compute_wave_offset(f32 t) {
    return 0.5f * (1.0f - cos_table_lookup((s32) (32768.0f * t)));
}

#pragma push
#pragma fp_contract on
void TBoss4Type2::calc_grid_target_position() {
    grid_target.x = 29.375f * (0.5f + (f32)grid_x) - 235.0f;
    grid_target.y = 0.0f;
    grid_target.z = 29.375f * (0.5f + (f32)grid_z) - 235.0f;
}
#pragma pop

void TBoss4Type2::set_grid_pos(Vec *pos) {
    grid_x = (s32)((235.0f + pos->x) / 29.375f);
    grid_z = (s32)((235.0f + pos->z) / 29.375f);
}

#pragma push
#pragma opt_propagation off
void TBoss4Type2::find_target_pos(Vec *out) {
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
            if (d <= 560.0f && d > best) {
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
    a1 = (s32)((10430.38043493439) * atan2_float(-position.x, -position.z));
    b = (s32)(49152.0f * random_ratio());
    ang = b + a1;
    ang -= 0x6000;
    out->x = s * sin_table_lookup(ang);
    out->y = 0.0f;
    out->z = s * cos_table_lookup(ang);
}
#pragma pop

void TBoss4Type2::send_random_action(s32 lo, s32 hi) {
    f32 step;
    f32 acc;
    f32 scale;
    s32 t;
    s32 i;

    if (lo < 9 || lo > 12 || hi < 9 || hi > 12) {
        return;
    }
    if (hi < lo) {
        t = hi;
        hi = lo;
        lo = t;
    }
    step = 1.0f / (f32)(hi - lo + 1);
    acc = step;
    scale = random_ratio();
    for (i = lo; i < hi; i++) {
        if (scale < acc) {
            break;
        }
        acc += step;
    }
    send_action(i);
}

void TBoss4Type2::choose_next_action() {
    Vec grid;
    s32 r;
    u16 id;
    id = TBoss4Type3::pick_random_target_player();
    if (hp <= half_hp && id != 0xFFFF) {
        r = pick_weighted_random(4, boss4_type2_next_action_weights_a, boss4_type2_next_actions_a);
    } else {
        r = pick_weighted_random(3, boss4_type2_next_action_weights_b, boss4_type2_next_actions_b);
    }
    switch (r) {
    case 6:
    case 7:
        find_target_pos(&grid);
        set_grid_pos(&grid);
        send_action(r);
        break;
    case 13:
        send_attack_code(r, id);
        break;
    default:
        send_action(r);
        break;
    }
}

void TBoss4Type2::choose_action_after_move() {
    s32 base;
    s32 lo;
    s32 hi;
    if (move_count < 3 && random_ratio() < 0.1f) {
        send_turn_action(4, pick_random_angle());
        return;
    }
    if (random_ratio() < 0.1f) {
        base = stop_action;
        hi = base + 1;
        lo = base;
        if (hi < base) {
            lo = hi;
            hi = base;
        }
        if (lo < 9) {
            lo = 9;
        }
        if (hi > 0xC) {
            hi = 0xC;
        }
        send_random_action(lo, hi);
        return;
    }
    choose_next_action();
}

void TBoss4Type2::apply_resta_heal() {
    s16 power = stat_block->stats.mst;
    drain_player_hp(target_player, (power / 5) + (s32)TTecResta::calc_heal_amount(
        TLobby::dispatch_shared_handler_a(0x37)->values.integers[1]));
}

void TBoss4Type2::spawn_bishi_around_players() {
    TBoss4ZakoSetData b;
    s32 i;
    s32 j;
    TObjPlayer *pl;
    copy_set_entry(&b.set_index, &dark_falz_set_entry);
    b.owner = owner;
    b.unk_0C = 1;
    for (i = 0; i < registered_player_count; i++) {
        pl = TObjPlayer::get_player_data(i);
        if (pl != 0 && is_player_in_boss_area(pl->get_entity_id()) != 0) {
            for (j = 0; j < 3; j++) {
                if (owner->alloc_child_ids(&b.set_index, &b.entity_id) != 0) {
                    VecCopy(&b.position, &pl->position);
                    b.position.x += bishi_spawn_offset_table[j].x;
                    b.position.z += bishi_spawn_offset_table[j].z;
                    TBoss4Bishi::create(&b);
                }
            }
        }
    }
}

void TBoss4Type2::spawn_afterimages() {
    TBoss4ZanzoParams z;
    s32 i;
    VecCopy(&z.pos, &position);
    z.rotation_y = rotation_y;
    z.frame = anim_frame;
    z.fade_start = 0.75f;
    z.fade_end = 0.0f;
    z.lifetime = 10;
    for (i = 0; i < 2; i++) {
        z.texlist = get_bml_texlist(archive, boss4_zanzo_bml_index_table[i]);
        z.model = get_bml_model(archive, boss4_zanzo_bml_index_table[i]);
        z.motion = get_bml_motion(archive, TBoss4Type2__attack_pattern_table[anim].motions[i]);
        create_zanzo(this, &z);
    }
}

void TBoss4Type2::appear_enter() {
    beam_ratio = 0.0f;
    action_timer = 0x3C;
}

void TBoss4Type2::appear_idle() {
    if (action_timer == 0) {
        send_turn_action(4, pick_random_angle());
    }
}

void TBoss4Type2::appear_update() {
    if (--action_timer < 0) {
        change_action(1);
    }
}

void TBoss4Type2::wait_next_idle() {
    if (actorFlags & 0x800) {
        send_action(2);
        return;
    }
    change_action(9);
}

void TBoss4Type2::dead_enter() {
    action_timer = 75;
}

void TBoss4Type2::dead_idle() {  }

void TBoss4Type2::dead_update() {
    if (--action_timer < 0) {
        change_action(2);
    }
}

void TBoss4Type2::move_enter() {
    beam_ratio = 0.0f;
    move_count++;
    action_timer = move_frames;
}

void TBoss4Type2::move_idle() {
    if (action_timer == 0) {
        choose_action_after_move();
    }
}

void TBoss4Type2::move_update() {
    f32 ratio;
    s32 diff;
    s32 timer;

    timer = action_timer;
    if (timer > 7) {
        turn_ratio = compute_wave_offset(1.0f - ((timer - 7) / (f32)move_turn_frames));
    } else {
        turn_ratio = 1.0f;
    }
    update_orbit_position();
    if (game_difficulty_selection == 3) {
        diff = angle_diff_s16(base_angle, target_angle);
        if (!(action_timer & 3)) {
            ratio = turn_ratio;
            if (ratio > 0.05f && ratio < 0.95f && (diff <= -0x4000 || diff >= 0x4000)) {
                spawn_afterimages();
            }
        }
    }
    if (--action_timer < 0) {
        change_action(1);
    }
}

void TBoss4Type2::jisin_enter() {
    beam_ratio = 0.0f;
    action_timer = 0x4B;
}

void TBoss4Type2::jisin_idle() {  }

void TBoss4Type2::jisin_update() {
    if (action_timer == 0x1E) {
        TCameraCtrl::set_shake_preset(1);
        create_jisin(this, angle);
    }
    if (action_timer <= 0x1E) {
        play_persistent_sound(0x4003AD16, this, &position, 0, 1);
    }
    if (--action_timer < 0) {
        change_action(8);
    }
}

void TBoss4Type2::beam_enter() {
    s32 heading;
    s32 side;

    VecCopy(&beam_dir, &grid_target);
    subtract_vector(&beam_dir, &position);
    beam_dir.y = 0.0f;
    if (vector_length(&beam_dir) <= 0.01f) {
        beam_dir.x = 1.0f;
        beam_dir.y = 0.0f;
        beam_dir.z = 0.0f;
    } else {
        normalize_vector(&beam_dir);
    }
    side = (s32)((10430.38043493439) * atan2_float(beam_dir.x, beam_dir.z));
    heading = side;
    if (action - 6 == 0) {
        side = heading + 0x4000;
    } else {
        side = 0x4000;
        side = heading - side;
    }
    beam_side.x = sin_table_lookup(side);
    beam_side.z = cos_table_lookup(side);
    beam_side.y = 0.0f;
    VecCopy(&beam_pos, &position);
    beam_pos.y = 0.0f;
    normalize_vector(&beam_pos);
    beam_pos.x *= 280.0f;
    beam_pos.z *= 280.0f;
    action_timer = 0x96;
}

void TBoss4Type2::beam_idle() {  }

#pragma push
#pragma fp_contract on
void TBoss4Type2::beam_update() {
    s32 idx = action - 6;
    Vec v = node_positions[idx];
    Vec p;
    s32 a;
    s32 b;
    TParticleCtrl *effect;
    f32 t;
    if (action_timer == 0x4B) {
        set_attack_pattern_by_index(boss4_type2_attack_pattern_table[idx]);
    }
    if (anim == 6 || anim == 7) {
        t = anim_frame;
        if (t > 17.0f) {
            if (parts[2] != 0) {
                TParticleCtrl::release(parts[2]);
                parts[2] = 0;
            }
        } else if (t >= 8.0f && parts[2] == 0) {
            if ((parts[2] = create_particle_emitter(&v, 0xF7)) != 0) {
                parts[2]->set_flags(0x40);
            }
        }
        if (anim_frame >= 8.0f && anim_frame <= 17.0f) {
            play_persistent_sound(0x4003B512, this, &position, 0, 1);
        }
    }
    if (action_timer == 0x26) {
        effect = spawn_particle_effect(&v, 0xFD);
        if (effect != 0) {
            effect->set_flags(0x40);
        }
        play_sound_effect(0x4003A813, &position, 0, 1);
        start_pad_rumble_all(0xC0, 0xF);
    }
    if (action_timer <= 0x26 && action_timer >= 4 && !(action_timer & 1)) {
        VecCopy(&p, &beam_pos);
        p.x += 20.0f * beam_side.x;
        p.z += 20.0f * beam_side.z;
        if (idx == 0) {
            TTecRaBarta::create(this, &p, &p, ((TBoss4Type2Params *)TLobby::dispatch_shared_handler_a(0x36))->rabarta_level);
        } else {
            const TBoss4Type2Params *params = reinterpret_cast<const TBoss4Type2Params *>(TLobby::dispatch_shared_handler_a(0x36));
            TTecRaFoie::create(this, &p, &p, params->rafoie_level);
        }
        add_radar_scaled_marker(&p, -0x5DB4, 1, 1, 2.5f);
        beam_side.x *= -1.0f;
        beam_side.z *= -1.0f;
        if (vector_length(&beam_pos) > 280.0f) {
            normalize_vector(&beam_pos);
            beam_pos.x *= 280.0f;
            beam_pos.z *= 280.0f;
            a = (s32)((10430.38043493439) * atan2_float(beam_pos.x, beam_pos.z));
            b = (s32)((10430.38043493439) * atan2_float(beam_dir.x, beam_dir.z));
            b += angle_diff_s16(b, a);
            beam_dir.x = -sin_table_lookup(b);
            beam_dir.z = -cos_table_lookup(b);
        }
        beam_pos.x = 50.0f * beam_dir.x + beam_pos.x;
        beam_pos.z = 50.0f * beam_dir.z + beam_pos.z;
    }
    if (action_timer > 0x87) {
        beam_ratio = (f32)(0x96 - action_timer) / 15.0f;
    } else if (action_timer >= 0x11) {
        beam_ratio = 1.0f;
    } else if (action_timer > 2) {
        beam_ratio = (f32)(action_timer - 2) / 15.0f;
    } else {
        beam_ratio = 0.0f;
    }
    update_orbit_position();
    if (--action_timer < 0) {
        if (game_difficulty_selection == 3) {
            spawn_bishi_around_players();
        }
        change_action(stop_action);
    }
}
#pragma pop

void TBoss4Type2::tenchu_enter() {
    beam_ratio = 0.0f;
    pick_tenchu_furu_spots();
    action_timer = 0x96;
}

void TBoss4Type2::tenchu_idle() {  }

void TBoss4Type2::tenchu_update() {
    Vec left = node_positions[0];
    Vec right = node_positions[1];
    f32 frame;

    if (action_timer == 6) {
        spawn_tenchu_furu(this);
    } else if (action_timer == 1) {
        apply_tenchu_hits(this);
    }
    if (anim == 8) {
        frame = anim_frame;
        if (frame > 28.0f) {
            if (parts[3] != 0) {
                TParticleCtrl::release(parts[3]);
                parts[3] = 0;
            }
            if (parts[5] != 0) {
                TParticleCtrl::release(parts[5]);
                parts[5] = 0;
            }
        } else if (frame >= 15.0f) {
            if (parts[3] == 0) {
                if ((parts[3] = create_particle_emitter(&left, 0x142)) != 0) {
                    parts[3]->set_flags(0x40);
                }
            }
            if (parts[5] == 0) {
                if ((parts[5] = create_particle_emitter(&right, 0x142)) != 0) {
                    parts[5]->set_flags(0x40);
                }
            }
        }
        if (parts[3] != 0) {
            parts[3]->set_position(&left);
        }
        if (parts[5] != 0) {
            parts[5]->set_position(&right);
        }
    }
    if (anim == 9) {
        frame = anim_frame;
        if (frame > 10.0f) {
            if (parts[3] != 0) {
                TParticleCtrl::release(parts[3]);
                parts[3] = 0;
            }
            if (parts[4] != 0) {
                TParticleCtrl::release(parts[4]);
                parts[4] = 0;
            }
            if (parts[5] != 0) {
                TParticleCtrl::release(parts[5]);
                parts[5] = 0;
            }
            if (parts[6] != 0) {
                TParticleCtrl::release(parts[6]);
                parts[6] = 0;
            }
        } else if (frame >= 2.0f) {
            if (parts[3] == 0) {
                if ((parts[3] = create_particle_emitter(&left, 0x13A)) != 0) {
                    parts[3]->set_flags(0x40);
                }
                play_sound_effect(0x40039717, &position, 0, 1);
            }
            if (parts[4] == 0) {
                if ((parts[4] = create_particle_emitter(&left, 0x13B)) != 0) {
                    parts[4]->set_flags(0x40);
                }
            }
            if (parts[5] == 0) {
                if ((parts[5] = create_particle_emitter(&right, 0x13A)) != 0) {
                    parts[5]->set_flags(0x40);
                }
            }
            if (parts[6] == 0) {
                if ((parts[6] = create_particle_emitter(&right, 0x13B)) != 0) {
                    parts[6]->set_flags(0x40);
                }
            }
        }
        if (parts[3] != 0) {
            parts[3]->set_position(&left);
        }
        if (parts[4] != 0) {
            parts[4]->set_position(&left);
        }
        if (parts[5] != 0) {
            parts[5]->set_position(&right);
        }
        if (parts[6] != 0) {
            parts[6]->set_position(&right);
        }
    }
    if (action_timer > 6) {
        play_persistent_sound(0x4003AD16, this, &position, 0, 1);
    }
    if (--action_timer < 0) {
        change_action(stop_action);
    }
}

void TBoss4Type2::md_stop1_enter() {
    beam_ratio = 0.0f;
    action_timer = 0x4B;
}

void TBoss4Type2::md_stop2_enter() {
    beam_ratio = 0.0f;
    action_timer = 0x96;
}

void TBoss4Type2::md_stop3_enter() {
    beam_ratio = 0.0f;
    action_timer = 0xE1;
}

void TBoss4Type2::md_stop4_enter() {
    beam_ratio = 0.0f;
    action_timer = 0x12C;
}

void TBoss4Type2::md_stop_idle() {
    if (action_timer == 0) {
        if (random_ratio() < 0.75f) {
            choose_next_action();
            return;
        }
        send_turn_action(4, pick_random_angle());
    }
}

void TBoss4Type2::md_stop_update() {
    if (--action_timer < 0) {
        change_action(1);
    }
}

void TBoss4Type2::md_recover_enter() {
    beam_ratio = 0.0f;
    play_sound_effect(0x40039E21, &position, 0, 1);
    action_timer = 0x96;
}

void TBoss4Type2::md_recover_idle() {  }

void TBoss4Type2::md_recover_update() {
    Vec pos;
    TParticleCtrl *effect;
    TObjPlayer *player;

    if (anim == 5 && anim_frame > 28.0f) {
        if (parts[7] != 0) {
            TParticleCtrl::release(parts[7]);
            parts[7] = 0;
        }
    } else if (parts[7] == 0) {
        if ((parts[7] = create_particle_emitter(&node_positions[2], 0x143)) != 0) {
            parts[7]->set_flags(0x40);
        }
    }
    if (action_timer == 0x46) {
        effect = spawn_particle_effect(&node_positions[2], 0x13E);
        if (effect != 0) {
            effect->set_flags(0x40);
        }
        if (target_player != 0xFFFF) {
            player = get_player_by_client_id(target_player);
            if (player != 0) {
                VecCopy(&pos, player->get_position_ptr());
                pos.y += 10.0f;
                effect = spawn_particle_effect(&pos, 0x38);
                if (effect != 0) {
                    effect->set_flags(0x40);
                }
            }
        }
        apply_resta_heal();
        TObjDFRecover::create(this, target_player, &node_positions[2]);
    }
    if (--action_timer < 0) {
        play_sound_effect(0x4003AD1A, &position, 0, 1);
        TTecResta::create(this, &position, resta_level);
        change_action(stop_action);
    }
}

TBoss4Zanzo *TBoss4Type2::create_zanzo(TObject *parent, TBoss4ZanzoParams *params) {
    return new TBoss4Zanzo(parent, params);
}

void copy_zanzo_params(TBoss4ZanzoParams *dst, TBoss4ZanzoParams *src) {
    *dst = *src;
}

TBoss4Zanzo::TBoss4Zanzo(TObject *parent, TBoss4ZanzoParams *params) : TObject(parent) {
    m_name = TBoss4Zanzo__name;
    copy_zanzo_params(&this->params, params);
    age = 0;
}

TBoss4Zanzo::~TBoss4Zanzo() {}

void TBoss4Zanzo::run_task() {
    if (++age >= params.lifetime) {
        queue_destruction();
    }
}

#pragma push
#pragma fp_contract on
void TBoss4Zanzo::render() {
    f32 from = params.fade_start;
    f32 value = (((f32)age / (f32)params.lifetime) * (params.fade_end - from)) + from;
    if (!(value <= 0.01f)) {
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&params.pos.x);
        rotate_matrix_y(0, params.rotation_y);
        TObjFish::set_global_param(params.texlist);
        TObjPlayer::begin_alpha_blend(value);
        draw_model_motion(params.model, params.motion, params.frame);
        TObjPlayer::sync_player_globals();
        clear_motion_packed_rotation();
        pop_matrix();
    }
}
#pragma pop
