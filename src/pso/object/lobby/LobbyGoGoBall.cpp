#include "pso/system/BmlAccessors.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/BmlResource.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/system/BmlResourceDescriptor.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/map/CsnGroundQuery.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/system/ControllerInputState.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/NinjaTypes.h"
#include "pso/render/ChunkMaterialState.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TUnk_804CCA78.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803DA798.h"
#include "pso/system/vector.h"
#include "pso/object/lobby/TGoGoBallGoal.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/lobby/TGoGoBallRocket.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/byteswap.h"
#include "pso/system/TLanguage.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_801E2F94.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/lobby/TObjGoGoBall.h"
#include "pso/object/lobby/TGoGoBallGame.h"
#include <stddef.h>
#include "pso/render/render_util.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ControllerInput.h"
#include "pso/network/client_id.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/math/MatrixVector.h"
#include "pso/render/BlobShadow.h"
#include "pso/object/base/TObjBase.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/object/lobby/LobbyGoGoBall.h"
#include "pso/player/PlayerSlots.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/map/CsnQuery.h"
#include "pso/unk/text_803D853C.h"
#include "pso/render/model_render_state.h"
BmlResource *gogo_ball_bml_resource;
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
// The ten ball setups TGoGoBallGame picks from by the internet beat.
GoGoBallConfig gogo_ball_configs[10] = {
    {-0.5f, 0.875f, 0.0f, 3.5f, 2.5f, 2260, 0x80, 0xFF, 0x00, 0x00, 20.0f, {0.0f, 0.0f, 0.0f}, {-247.0f, 0.0f, 0.0f}, {247.0f, 0.0f, 0.0f}, 30.0f, 6, 8.0f, 3.0f},
    {-0.5f, 0.875f, 0.0f, 3.5f, 2.5f, 2260, 0x80, 0x00, 0x00, 0xFF, 10.0f, {0.0f, 0.0f, 0.0f}, {-247.0f, 0.0f, 0.0f}, {247.0f, 0.0f, 0.0f}, 30.0f, 2, 8.0f, 3.0f},
    {-0.1f, 0.5f, 0.0f, 2.3f, 2.3f, 2260, 0x80, 0xFF, 0x00, 0x00, 10.0f, {0.0f, 0.0f, 0.0f}, {-247.0f, 0.0f, 0.0f}, {247.0f, 0.0f, 0.0f}, 30.0f, 3, 3.0f, 3.5f},
    {-0.5f, 0.875f, 0.0f, 3.5f, 2.5f, 2260, 0x80, 0x00, 0x00, 0xFF, 10.0f, {0.0f, 0.0f, 0.0f}, {-247.0f, 0.0f, 0.0f}, {247.0f, 0.0f, 0.0f}, 30.0f, 1, 8.0f, 3.0f},
    {-0.5f, 0.875f, 0.0f, 3.5f, 2.5f, 2260, 0x80, 0xFF, 0xFF, 0x00, 10.0f, {0.0f, 0.0f, 0.0f}, {-247.0f, 0.0f, 0.0f}, {247.0f, 0.0f, 0.0f}, 30.0f, 6, 8.0f, 3.0f},
    {-0.5f, 0.875f, 0.0f, 3.5f, 2.5f, 2260, 0x80, 0x00, 0x00, 0xFF, 25.0f, {0.0f, 0.0f, 0.0f}, {-247.0f, 0.0f, 0.0f}, {247.0f, 0.0f, 0.0f}, 30.0f, 0, 8.0f, 3.0f},
    {-0.5f, 0.875f, 0.0f, 3.5f, 2.5f, 2260, 0x80, 0xFF, 0xFF, 0x00, 10.0f, {0.0f, 0.0f, 0.0f}, {-247.0f, 0.0f, 0.0f}, {247.0f, 0.0f, 0.0f}, 30.0f, 1, 8.0f, 3.0f},
    {-0.1f, 0.5f, 0.0f, 2.3f, 2.3f, 2260, 0x80, 0xFF, 0x00, 0x00, 10.0f, {0.0f, 0.0f, 0.0f}, {-247.0f, 0.0f, 0.0f}, {247.0f, 0.0f, 0.0f}, 30.0f, 3, 3.0f, 3.5f},
    {-0.5f, 0.875f, 0.0f, 3.5f, 2.5f, 2260, 0x80, 0xFF, 0xFF, 0x00, 10.0f, {0.0f, 0.0f, 0.0f}, {-247.0f, 0.0f, 0.0f}, {247.0f, 0.0f, 0.0f}, 30.0f, 2, 8.0f, 3.0f},
    {-0.5f, 0.875f, 0.0f, 3.5f, 2.5f, 2260, 0x80, 0xFF, 0xFF, 0x00, 10.0f, {0.0f, 0.0f, 0.0f}, {-247.0f, 0.0f, 0.0f}, {247.0f, 0.0f, 0.0f}, 30.0f, 0, 8.0f, 3.0f},
};
const char *biri_ball_motion_names[2] = {NULL, NULL};
const char *biri_ball_model_names[6] = {
    "biri_ball.nj", "fd_obj804_gorl03_dai.gj", "robby_cat.nj", "robby_chu.nj", "rokeorange_churoke.nj", NULL,
};
BmlResourceDescriptor language_lobby_texture_descriptor = {
    "biri_ball.bml", biri_ball_model_names, biri_ball_motion_names, 5, 0,
};
// The single cell of the blob shadow texture the ball's ground shadow is drawn from.
NJS_TEXANIM gogo_ball_shadow_texanim = {5, 5, 0, 0, 0, 0, 0xFF, 0xFF, 0, 0};
// The three-point goals of team 0 and team 1.
Vec three_point_goal_team0 = {500.0f, 20.0f, 0.0f};
Vec three_point_goal_team1 = {-500.0f, 20.0f, 0.0f};

// The lobby GVM texture lists TLanguage::load_lobby_textures loads.
NJS_TEXLIST *lobby_gvm_texture_handles[9] = {0};
const NJS_ARGB fish_draw_color[1] = {{0.2f, 0.0f, 0.0f, 0.0f}};
// spawn_particle_effect_with_rotation takes x/y/z angles (0x8000 = half turn).
const ParticleAngles boss3_volopt_init_vec = {0, 0, 0x8000};

void close_gogo_ball_timer() { TWindowCtrl::close_timer_window(); }
void add_gogo_ball_one_point_score(s32 i) {
    gogo_ball_team_scores[i] += 1;
}

void add_gogo_ball_three_point_score(s32 i) {
    gogo_ball_team_scores[i] += 3;
}


void set_gogo_ball_score(s32 team, s32 score) { gogo_ball_team_scores[team] = score; }

s16 get_gogo_ball_score(s32 team) {
    return gogo_ball_team_scores[team];
}

void G_GoGoBall_6x79::init() { header.subcommand = 0x79; header.size = 6; }

void G_GoGoBall_6x79::bswap() {
    header.bswap();
    bswap_32((u32 *)&sequence);
    bswap_32((u32 *)&angle);
    bswap_32((u32 *)&x);
    bswap_32((u32 *)&z);
}

void G_GoGoBall_6x79::send() {
    bswap();
    send_subcommand(this);
}

TObjGoGoBall::TObjGoGoBall(TObject *parent) : TObjChara(parent) {
    throw_forward_speed = 0.0f;
    throw_up_speed = 0.0f;
    pad_398[0] = 0.0f;
    pad_398[1] = 0.0f;
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    velocity.z = 0.0f;
    position.x = gogo_ball_configuration.start_position.x;
    position.y = gogo_ball_configuration.start_position.y;
    position.z = gogo_ball_configuration.start_position.z;
    time = 0;
    sequence = 0;
    heading = 0;
    roll = 0;
    gravity = gogo_ball_configuration.gravity;
    restitution = gogo_ball_configuration.restitution;
    resting = 0;
    collision_body.offset.x = 0.0f;
    collision_body.offset.y = 0.0f;
    collision_body.offset.z = 0.0f;
    collision_body.radius = 2.0f;
    collision_body.half_width = 1.0f;
    collision_body.shape = 1;
    collision_body.flags = 0x40107;
    set_collision_body(&collision_body);
    register_object_by_id();
    rest_count = 0;
    gogo_ball_sync_state.goal_flags = 0;
    gogo_ball_sync_state.mode = 0;
    scored = 0;
}

TObjGoGoBall::~TObjGoGoBall() {
    unregister_object_by_id();
    clear_collision_bodies();
}

void TObjGoGoBall::start_throw(s32 angle) {
    throw_forward_speed = gogo_ball_configuration.throw_forward_speed;
    throw_up_speed = gogo_ball_configuration.throw_up_speed;
    if ((s32)gogo_ball_sync_state.mode == 1) {
        throw_forward_speed = gogo_ball_configuration.throw_forward_speed_alt;
        throw_up_speed = gogo_ball_configuration.throw_up_speed_alt;
    }
    pad_398[0] = (0.1f);
    pad_398[1] = (0.1f);
    velocity.x = (0.0f);
    velocity.y = throw_up_speed;
    velocity.z = throw_forward_speed;
    throw_speed = vector_length(&velocity);
    rotate_vec_xz(&velocity, &velocity, angle);
    heading = angle;
    VecCopy(&home_position, &velocity);
    home_position.y = (0.0f);
}

void TObjGoGoBall::update_goal_checks(u16 id) {
    TObjPlayer *p;
    f32 len;
    s32 ang;
    p = get_player_by_client_id(id);
    if (p == NULL) {
        return;
    }
    if (xyz_distance(&gogo_ball_configuration.team1_goal, &position) <= gogo_ball_configuration.goal_radius && (0.0f) == vector_length(&velocity)) {
        gogo_ball_sync_state.goal_flags |= 2;
        if (scored == 0) {
            add_gogo_ball_one_point_score(1);
            scored = 1;
        }
    }
    if (xyz_distance(&gogo_ball_configuration.team0_goal, &position) <= gogo_ball_configuration.goal_radius && (0.0f) == vector_length(&velocity)) {
        gogo_ball_sync_state.goal_flags |= 1;
        if (scored == 0) {
            add_gogo_ball_one_point_score(0);
            scored = 1;
        }
    }
    if (xyz_distance(&three_point_goal_team0, &position) <= gogo_ball_configuration.goal_radius && (0.0f) == vector_length(&velocity)) {
        gogo_ball_sync_state.goal_flags |= 0x10;
        if (scored == 0) {
            add_gogo_ball_three_point_score(0);
            scored = 1;
        }
    }
    if (xyz_distance(&three_point_goal_team1, &position) <= gogo_ball_configuration.goal_radius && (0.0f) == vector_length(&velocity)) {
        gogo_ball_sync_state.goal_flags |= 0x20;
        if (scored == 0) {
            add_gogo_ball_three_point_score(1);
            scored = 1;
        }
    }
    if ((gogo_ball_sync_state.goal_flags & 2 || gogo_ball_sync_state.goal_flags & 1 || gogo_ball_sync_state.goal_flags & 0x20 || gogo_ball_sync_state.goal_flags & 0x10) && !(gogo_ball_sync_state.goal_flags & 8) && !(gogo_ball_sync_state.goal_flags & 4)) {
        TWindowCtrl::open(get_entity_id(), "\tC4Goal", 0x1B);
    }
    if (!(gogo_ball_sync_state.goal_flags & 0x33) && scored != 0) {
        scored = 0;
    }
    len = vector_length(&velocity);
    if ((0.0f) == len) {
        if (resting == 0) {
            rest_count++;
            TWindowCtrl::open(get_entity_id(), "Go!", 0x1B);
        }
        resting = 1;
    } else {
        resting = 0;
    }
    if (xyz_distance(&position, &p->position) > gogo_ball_configuration.radius) {
        actorFlags = 0;
        return;
    }
    if (actorFlags != 1) {
        actorFlags = 1;
        ang = 10430.38043493439 * atan2_float(position.x - p->position.x, position.z - p->position.z);
        if ((0.0f) == len) {
            throw_gogo_ball(&position, (s32)ang, (s32)time);
            send_local_player_walk();
        }
    }
}

void TObjGoGoBall::send_local_player_walk() {
    G_WalkToPosition_6x40 pkt;
    f32 x;
    f32 z;
    TObjPlayer *p;
    pkt.init();
    p = get_player_by_client_id(local_client_id);
    if (p != 0) {
        pkt.header.client_id = local_client_id;
        p->calc_movement_target(p->rotation_y, &x, &z);
        pkt.pos.x = x;
        pkt.pos.z = z;
        pkt.flags = 0;
        pkt.send();
    }
}

void TObjGoGoBall::run_task() {
    s32 i;
    Vec q;
    Vec p;
    i = 0;
    time = TLobby::get_clock_frames() % 2592;
    if (time >= gogo_ball_configuration.lifetime) {
        VecCopy((Vec *)&p, &position);
        p.y += gogo_ball_configuration.radius;
        spawn_particle_effect_with_flags(&p, 0x45, 0x40);
        spawn_particle_effect_with_flags(&p, 0x46, 0x40);
        TWindowCtrl::open(this->get_entity_id(), "Good Bye", 0x1B);
        queue_destruction();
        return;
    }
    update_goal_checks(local_client_id);
    update_best_time();
    if (position.y <= (-5e+02f)) {
        queue_destruction();
    }
    VecCopy((Vec *)&q, &position);
    velocity.y += gravity;
    vec3_add_to(&position, &velocity);
    for (;;) {
        if (i++ >= 3 || reflect_velocity_off_collision(&q, &velocity) == 0) {
            break;
        }
        VecCopy(&position, (const Vec *)&q);
        q.x += velocity.x;
        q.y += velocity.y;
        q.z += velocity.z;
    }
}

void TObjGoGoBall::update_best_time() {
    if (gogo_ball_sync_state.applied == 0 && sequence <= gogo_ball_sync_state.sequence) {
        sequence = gogo_ball_sync_state.sequence;
        position.x = gogo_ball_sync_state.position.x;
        position.y = gogo_ball_sync_state.position.y;
        position.z = gogo_ball_sync_state.position.z;
        start_throw(gogo_ball_sync_state.angle);
    }
    gogo_ball_sync_state.applied = 1;
}

void TObjGoGoBall::render() {
    Vec dir;
    NJS_ARGB color = fish_draw_color[0];
    Vec pos;
    f32 len;
    f32 rate;
    s32 step;

    VecCopy((Vec *)&pos, &position);
    pos.y += gogo_ball_configuration.radius - (2.0f * gogo_ball_configuration.radius) / 10.0f;
    color.a = (resting != 0) ? 0.0f : -0.75f;
    VecCopy((Vec *)&dir, &velocity);
    dir.y = 0.0f;
    len = vector_length(&dir);
    direction_to_rotation_yx((u8 *)&dir, &rotation_y, &rotation_z);
    heading = (u16)heading;
    rotation_y = (u16)rotation_y;
    if (0.0f != len) {
        normalize_vector(&dir);
        VecCopy(&prev_position, (const Vec *)&dir);
    } else {
        VecCopy((Vec *)&dir, &prev_position);
    }
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, 0x4000);
    matrix_mult_vec(0, &dir, &dir);
    pop_matrices(1);
    saved_model_render_flags = model_render_flags;
    copy_argb(&saved_model_draw_color, &model_material_color);
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= 0x821;
    set_chunk_material_override_pair(-1, 0x800);
    rate = (s32)(182.04445f * (4096.0f * len));
    if (0.0f != rate) {
        step = rate;
        heading = approach_angle_limited(heading, rotation_y, step);
        roll = approach_angle_limited(roll, rotation_x, step);
    }
    rotation_x += (s32)(182.04445f * (7.0f * len));
    push_matrix_from(0);
    translate_matrix_vec3((u8 *)(0), (u8 *)&pos);
    rate = 0.15f * gogo_ball_configuration.radius;
    scale_matrix(0, rate, rate, rate);
    set_constant_material((const NJS_ARGB *)((&color)));
    if (vec_squared_length(&dir)) {
        rotate_matrix_about_axis((u8 *)(0), (saddr)&dir, roll);
    }
    rotate_matrix_y(0, heading);
    if (lobby_gvm_texture_handles != 0 && gogo_ball_bml_resource != 0) {
        switch (gogo_ball_configuration.ball_type) {
        case 0:
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(lobby_gvm_texture_handles[0]));
            set_cull_back();
            draw_chunk_object(get_bml_model(gogo_ball_bml_resource, 3));
            set_cull_front();
            draw_chunk_object(get_bml_model(gogo_ball_bml_resource, 3));
            set_cull_none();
            break;
        case 1:
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(lobby_gvm_texture_handles[1]));
            set_cull_back();
            draw_chunk_object(get_bml_model(gogo_ball_bml_resource, 0));
            set_cull_front();
            draw_chunk_object(get_bml_model(gogo_ball_bml_resource, 0));
            set_cull_none();
            break;
        case 2:
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(lobby_gvm_texture_handles[2]));
            set_cull_back();
            draw_chunk_object(get_bml_model(gogo_ball_bml_resource, 0));
            set_cull_front();
            draw_chunk_object(get_bml_model(gogo_ball_bml_resource, 0));
            set_cull_none();
            break;
        case 3:
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(lobby_gvm_texture_handles[3]));
            set_cull_back();
            draw_chunk_object(get_bml_model(gogo_ball_bml_resource, 0));
            set_cull_front();
            draw_chunk_object(get_bml_model(gogo_ball_bml_resource, 0));
            set_cull_none();
            break;
        case 6:
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(lobby_gvm_texture_handles[6]));
            set_cull_back();
            draw_chunk_object(get_bml_model(gogo_ball_bml_resource, 2));
            set_cull_front();
            draw_chunk_object(get_bml_model(gogo_ball_bml_resource, 2));
            set_cull_none();
            break;
        }
    }
    set_constant_material(&chunk_material_color_half_alpha_f32);
    pop_matrices(1);
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    copy_argb(&model_material_color, &saved_model_draw_color);
    model_render_flags = saved_model_render_flags;
    draw_shadow_on_ground();
}



#pragma push
#pragma fp_contract on
s32 TObjGoGoBall::reflect_velocity_off_collision(void *p, void *v) {
    Vec end;
    Vec dir;
    Vec a;
    Vec r;
    Vec q;
    Vec s;
    CsnHit *hit;
    CsnContact *tri;
    f32 len;
    f32 d;
    f32 px, py, pz, nx, ny, nz;
    end.x = ((Vec *)p)->x + ((Vec *)v)->x;
    end.y = ((Vec *)p)->y + ((Vec *)v)->y;
    end.z = ((Vec *)p)->z + ((Vec *)v)->z;
    VecCopy((Vec *)&dir, (const Vec *)((Vec *)v));
    len = vector_length(&dir);
    if ((0.0f) != len) {
        normalize_vector(&dir);
        VecCopy((Vec *)&a, (const Vec *)((Vec *)p));
        a.x -= (3.0f) * (dir.x * len);
        a.y -= (3.0f) * (dir.y * len);
        a.z -= (3.0f) * (dir.z * len);
    } else {
        return 0;
    }
    hit = csnVector(&a, &end, 0x17EF);
    if (hit != NULL) {
    tri = hit->contact;
    px = tri->point.x;
    py = tri->point.y;
    pz = tri->point.z;
    nx = tri->normal.x;
    ny = tri->normal.y;
    nz = tri->normal.z;
    r.x = ((Vec *)v)->x;
    r.y = ((Vec *)v)->y;
    r.z = ((Vec *)v)->z;
    d = (2.0f) * vec3_dot(&r, &tri->normal);
    r.x -= d * nx;
    r.y -= d * ny;
    r.z -= d * nz;
    q.x = px - ((Vec *)p)->x;
    q.z = pz - ((Vec *)p)->z;
    q.y = (0.0f);
    vector_length(&q);
    ((Vec *)v)->x = r.x * restitution;
    ((Vec *)v)->z = r.z * restitution;
    normalize_vector(&r);
    throw_up_speed *= restitution;
    ((Vec *)v)->y = r.y * throw_up_speed;
    s.x = ((Vec *)v)->x;
    s.z = ((Vec *)v)->z;
    s.y = throw_up_speed;
    if (vector_length(&s) < (1.0f) - restitution) {
        ((Vec *)v)->x = (0.0f);
        ((Vec *)v)->y = (0.0f);
        ((Vec *)v)->z = (0.0f);
    }
    ((Vec *)p)->x += ((Vec *)v)->x;
    ((Vec *)p)->z += ((Vec *)v)->z;
    ((Vec *)p)->y = (0.001f) * r.y + py;
    return 1;
    }
    return 0;
}

void TObjGoGoBall::draw_shadow_on_ground() {
    CsnHit *hit;
    f32 t;
    f32 k;
    Vec scale;

    hit = csnVectorUnder(&position, ground_candidates.groups, 0x15);
    if (hit != 0) {
        CsnContact *src = hit->contact;
        CsnContact ground;
        ground.point.x = src->point.x;
        ground.point.y = src->point.y;
        ground.point.z = src->point.z;
        ground.normal.x = src->normal.x;
        ground.normal.y = src->normal.y;
        ground.normal.z = src->normal.z;
        t = 0.2f / (1.0f + xyz_distance(&ground.point, &position));
        f32 s = 0.85f + t;
        scale.x = s;
        scale.y = s;
        scale.z = s;
        copy_argb(&saved_model_draw_color, &model_material_color);
        k = 2.0f * t + 0.5f;
        if (k >= 1.0f) {
            k = 1.0f;
        }
        draw_shadow_quads(&ground.point, &ground.normal, 0, &scale, (f32)k);
        copy_argb(&model_material_color, &saved_model_draw_color);
    }
}


#pragma pop


void TObjGoGoBall::draw_shadow_quads(Vec *pos, Vec *dir, s32 angle, Vec *scale, f32 alpha) {
    Angle3 rot;
    NJS_ARGB col;
    NJS_SPRITE sprite;
    if (blob_shadow_texture_list == NULL) {
        return;
    }
    direction_to_rotation_xz((u8 *)dir, &rot.x, &rot.z);
    push_matrix();
    post_translate_matrix(&pos->x);
    translate_matrix(0, 0.0f, 0.3f, 0.0f);
    rotate_matrix_z(0, rot.z);
    rotate_matrix_x(0, rot.x);
    rotate_matrix_y(0, angle);
    if (scale != NULL) {
        scale_current_matrix(&scale->x);
    }
    rotate_matrix_x(0, -0x4000);
    sprite.p.x = -5.0f;
    sprite.p.y = 0.0f;
    sprite.p.z = 0.0f;
    sprite.sx = 1.0f;
    sprite.sy = 1.0f;
    sprite.ang = 0;
    sprite.tlist = blob_shadow_texture_list;
    sprite.tanim = &gogo_ball_shadow_texanim;
    col.a = alpha;
    col.r = 1.0f;
    col.g = 1.0f;
    col.b = 1.0f;
    set_constant_material(&col);
    TParticleCtrl::begin_effect_render();
    draw_shadow_quad(&sprite, 0, 0x22);
    sprite.p.x = 0.0f;
    sprite.p.y = 0.0f;
    draw_shadow_quad(&sprite, 0, 0x26);
    sprite.p.x = -5.0f;
    sprite.p.y = -5.0f;
    draw_shadow_quad(&sprite, 0, 0x2A);
    sprite.p.x = 0.0f;
    sprite.p.y = -5.0f;
    draw_shadow_quad(&sprite, 0, 0x2E);
    TParticleCtrl::end_effect_render();
    set_constant_material(&chunk_material_color_half_alpha_f32);
    pop_matrix();
}

void handle_6x79_gogo_ball(u8 *packet) {
    G_GoGoBall_6x79 *cmd = (G_GoGoBall_6x79 *)packet;
    cmd->bswap();
    gogo_ball_sync_state.applied = 0;
    gogo_ball_sync_state.position.x = cmd->x;
    gogo_ball_sync_state.position.y = 0.0f;
    gogo_ball_sync_state.position.z = cmd->z;
    gogo_ball_sync_state.angle = cmd->angle;
    gogo_ball_sync_state.mode = cmd->mode;
    gogo_ball_sync_state.sequence = cmd->sequence;
}


TGoGoBallGame::TGoGoBallGame(TObject *parent) : TObject(parent) {
    beat = TLobby::get_internet_beat();
    TWindowCtrl::create_timer();
    set_gogo_ball_score(1, 0);
    set_gogo_ball_score(0, 0);
}

TGoGoBallGame::~TGoGoBallGame() {
    close_gogo_ball_timer();
}

void GoGoBallConfig::copy_state(GoGoBallConfig *src) {
    *this = *src;
}

void TGoGoBallGame::run_task() {
    ControllerInputContext *pad;
    s32 m;
    s32 r;
    s32 idx;

    pad = &controller_input_state.controllers[0];
    if (test_previous_buttons_packed(pad, 0x10000) != 0 && test_pressed_buttons_packed(pad, 0x400) != 0) {
        set_gogo_ball_score(1, 0);
        set_gogo_ball_score(0, 0);
    }
    if (get_gogo_ball_score(1) >= 999) {
        set_gogo_ball_score(1, 0);
    } else if (get_gogo_ball_score(0) >= 999) {
        set_gogo_ball_score(0, 0);
    }
    m = TLobby::get_internet_beat();
    r = (s32)fabs_float((f32)(m - this->beat));
    if (r == 1 || r == 999) {
        gogo_ball_sync_state.applied = 1;
        idx = m % 10;
        if (idx >= 10) {
            idx = 9;
        } else if (idx < 0) {
            idx = 0;
        }
        gogo_ball_configuration.copy_state(&gogo_ball_configs[idx]);
        new TObjGoGoBall(tl_03);
        new TGoGoBallGoal(&gogo_ball_configuration.team0_goal, 1, gogo_ball_configuration.lifetime, tl_04);
        new TGoGoBallGoal(&gogo_ball_configuration.team1_goal, 0, gogo_ball_configuration.lifetime, tl_04);
        new TGoGoBallGoal(&three_point_goal_team0, 1, 1, gogo_ball_configuration.lifetime, tl_04);
        new TGoGoBallGoal(&three_point_goal_team1, 0, 1, gogo_ball_configuration.lifetime, tl_04);
    }
    this->beat = m;
}

void TGoGoBallGame::render() {
    gogo_ball_sync_state.goal_flags &= ~1;
    gogo_ball_sync_state.goal_flags &= ~2;
    gogo_ball_sync_state.goal_flags &= ~0x10;
    gogo_ball_sync_state.goal_flags &= ~0x20;
}

#pragma pool_data off
void load_lobby_textures() {
    s32 *scores = gogo_ball_team_scores;
    GoGoBallSyncState *sync = &gogo_ball_sync_state;
    BmlResource *obj;
    sync->applied = 1;
    sync->position.x = 63.0f;
    sync->position.y = 0.0f;
    sync->position.z = 63.0f;
    sync->angle = 0;
    sync->mode = 0;
    scores[0] = 0;
    scores[1] = 0;
    obj = new BmlResource(5, (BmlResourceDescriptor *)&language_lobby_texture_descriptor, 0, 0, NULL);
    gogo_ball_bml_resource = obj;
    lobby_gvm_texture_handles[0] = load_gvm_texture_file("robby_chu.gvm");
    lobby_gvm_texture_handles[1] = load_gvm_texture_file("biri_ball.gvm");
    lobby_gvm_texture_handles[2] = load_gvm_texture_file("bom_ball.gvm");
    lobby_gvm_texture_handles[3] = load_gvm_texture_file("soft_ball.gvm");
    lobby_gvm_texture_handles[4] = load_gvm_texture_file("rokeorange_churoke.gvm");
    lobby_gvm_texture_handles[5] = load_gvm_texture_file("rokeblue_pso_churoke.gvm");
    lobby_gvm_texture_handles[6] = load_gvm_texture_file("robby_cat.gvm");
    lobby_gvm_texture_handles[7] = load_gvm_texture_file("fd_obj804_gorl03.gvm");
    lobby_gvm_texture_handles[8] = load_gvm_texture_file("fd_obj804_gorl03_b.gvm");
}
#pragma pool_data reset

void free_lobby_textures() {
    s32 off;
    s32 i;
    s32 z;
    gogo_ball_sync_state.applied = 1;
    gogo_ball_sync_state.position.x = 63.0f;
    gogo_ball_sync_state.position.y = 0.0f;
    gogo_ball_sync_state.position.z = 63.0f;
    gogo_ball_sync_state.angle = 0;
    delete (BmlResource *)gogo_ball_bml_resource;
    gogo_ball_bml_resource = NULL;
    for (i = 0; i < 9; i++) {
        TObjPlayer::free_if_valid((saddr)lobby_gvm_texture_handles[i]);
        lobby_gvm_texture_handles[i] = NULL;
    }
}

void throw_gogo_ball(Vec *position, s32 angle, s32 sequence) {
    G_GoGoBall_6x79 cmd;
    cmd.init();
    cmd.sequence = sequence;
    cmd.angle = angle;
    cmd.x = position->x;
    cmd.z = position->z;
    if (test_previous_buttons_packed(&controller_input_state.controllers[0], 4) != 0) {
        play_sound_effect(0x4001A311, position, 0, 0);
        cmd.mode = 1;
    } else {
        play_sound_effect(0x4002A600, position, 0, 0);
        cmd.mode = 0;
    }
    cmd.send();
}

void TGoGoBallGame::create() {
    new TGoGoBallGame(tl_03);
}

TGoGoBallRocket::TGoGoBallRocket(Vec *position, s32 limit, s32 team0, s32 three_point, TObject *parent) : TObject(parent) {
    VecCopy(&pos, position);
    VecCopy(&initial_pos, &pos);
    pos.y -= 16.0f;
    effect = NULL;
    rot = 0;
    pad_38 = 0;
    this->limit = limit;
    counter = 0;
    timer = 0;
    this->team0 = team0;
    this->three_point = three_point;
    state = 0;
}

TGoGoBallRocket::~TGoGoBallRocket() {
    if (effect != NULL) {
        effect->queue_destruction();
        effect = NULL;
    }
}

#pragma push
#pragma fp_contract on
void TGoGoBallRocket::run_task() {
    s32 state;
    if (this->counter++ >= limit) {
        spawn_particle_effect_with_flags(&pos, 0x45, 0x40);
        spawn_particle_effect_with_flags(&pos, 0x46, 0x40);
        queue_destruction();
        return;
    }
    state = this->state;
    if (state == 0) {
        if (team0 != 0) {
            if (gogo_ball_sync_state.goal_flags & (three_point != 0 ? 0x10 : 1)) {
                play_sound_effect(0x4002A605, &pos, 0, 0);
                play_sound_effect(0x40052D15, &pos, 0, 0);
                this->state = 1;
                return;
            }
        } else {
            if (gogo_ball_sync_state.goal_flags & (three_point != 0 ? 0x20 : 2)) {
                play_sound_effect(0x4002A605, &pos, 0, 0);
                play_sound_effect(0x40052D15, &pos, 0, 0);
                this->state = 1;
                return;
            }
        }
    }
    if (state != 0) {
        if (effect == NULL) {
            ParticleAngles init = boss3_volopt_init_vec;
            if (gogo_ball_configuration.ball_type != 6) {
                effect = spawn_particle_effect_with_rotation(&pos, &init, 0xC0, 2);
            }
        }
        if (timer++ >= 1000) {
            queue_destruction();
            return;
        }
        this->rot += 0x16C;
        if (timer <= 0x14) {
            Vec v;
            VecCopy((Vec *)&v, (const Vec *)&pos);
            v.y += (18.0f);
            spawn_particle_effect(&v, 0x1DB);
        }
        pos.y = (0.001f) * (f32)(timer * timer) + pos.y;
        if (effect != NULL) {
            ((TParticleCtrl *)effect)->set_position(&pos);
        }
    }
}

#pragma pop
void TGoGoBallRocket::render() {
    if (((gogo_ball_bml_resource != NULL) || (lobby_gvm_texture_handles[4] != NULL)) && (gogo_ball_configuration.ball_type != 6)) {
        if (this->team0 == 1) {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(lobby_gvm_texture_handles[4]));
        } else {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(lobby_gvm_texture_handles[5]));
        }
        push_matrix();
        post_translate_matrix(&this->pos.x);
        rotate_matrix_y(0, this->rot);
        scale_matrix(0, 1.5f, 1.5f, 1.5f);
        draw_chunk_object(get_bml_model(gogo_ball_bml_resource, 4));
        pop_matrix();
    }
}

TGoGoBallGoal::TGoGoBallGoal(Vec *position, s32 team0, s32 lifetime, TObject *parent) : TObject(parent) {
    VecCopy(&pos, position);
    this->team0 = team0;
    age = 0;
    this->lifetime = lifetime;
    flap_angle = 0;
    goal_frames = 0;
    active = 0;
    three_point = 0;
}

TGoGoBallGoal::TGoGoBallGoal(Vec *position, s32 team0, s32 three_point, s32 lifetime, TObject *parent) : TObject(parent) {
    VecCopy(&pos, position);
    this->team0 = team0;
    age = 0;
    this->lifetime = lifetime;
    flap_angle = 0;
    goal_frames = 0;
    active = 0;
    this->three_point = three_point;
}

TGoGoBallGoal::~TGoGoBallGoal() {}

void TGoGoBallGoal::update_effects() {
    Vec v6;
    Vec v2a;
    Vec v2b;
    Vec vda;
    Vec vdb;
    if (gogo_ball_configuration.ball_type == 0) {
        (this->goal_frames)++;
        if (this->goal_frames == 1) {
            new TGoGoBallRocket(&this->pos, gogo_ball_configuration.lifetime, this->team0, this->three_point, tl_06);
        }
    } else if (gogo_ball_configuration.ball_type == 6) {
        (this->goal_frames)++;
        if (this->goal_frames % 5 == 0 && this->goal_frames <= 0x1E) {
            VecCopy((Vec *)&v6, &this->pos);
            v6.y += 7.0f;
            spawn_particle_effect_with_flags(&v6, 0x20D, 0x40);
            play_sound_effect(0x4001A82E, reinterpret_cast<const Vec *>((u8 *)&this->pos), 0, 0);
        }
    } else if (gogo_ball_configuration.ball_type == 2) {
        (this->goal_frames)++;
        if (this->team0 != 0) {
            if (this->goal_frames == 1) {
                TCameraCtrl::set_shake_preset(2);
                VecCopy((Vec *)&v2a, &this->pos);
                v2a.y += 7.0f;
                spawn_particle_effect_with_flags(&v2a, 0x45, 0x40);
                spawn_particle_effect_with_flags(&v2a, 0x189, 0x40);
                play_sound_effect(0x4001C112, reinterpret_cast<const Vec *>((u8 *)&this->pos), 0, 0);
            }
        } else {
            if (this->goal_frames == 1) {
                TCameraCtrl::set_shake_preset(2);
                VecCopy((Vec *)&v2b, &this->pos);
                v2b.y += 7.0f;
                spawn_particle_effect_with_flags(&v2b, 0x45, 0x40);
                spawn_particle_effect_with_flags(&v2b, 0x189, 0x40);
                play_sound_effect(0x4001C112, reinterpret_cast<const Vec *>((u8 *)&this->pos), 0, 0);
            }
        }
    } else if (gogo_ball_configuration.ball_type != 0) {
        (this->goal_frames)++;
        if (this->team0 != 0) {
            if (this->goal_frames % 5 == 0 && this->goal_frames <= 0x32) {
                VecCopy((Vec *)&vda, &this->pos);
                vda.y += 7.0f;
                spawn_particle_effect_with_flags(&vda, 0x20E, 0x40);
                new TUnk_804CCA78(&this->pos, 5, 0x4002A90C, 0, tl_05);
            }
        } else {
            if (this->goal_frames % 5 == 0 && this->goal_frames <= 0x32) {
                VecCopy((Vec *)&vdb, &this->pos);
                vdb.y += 7.0f;
                spawn_particle_effect_with_flags(&vdb, 0x20F, 0x40);
                new TUnk_804CCA78(&this->pos, 5, 0x4002A90C, 0, tl_05);
            }
        }
    }
}

void TGoGoBallGoal::run_task() {
    s32 t;
    if (this->team0 != 0) {
        if (gogo_ball_sync_state.goal_flags & (this->three_point != 0 ? 0x10 : 1)) {
            this->active = 1;
            update_effects();
        } else {
            this->active = 0;
            this->goal_frames = 0;
        }
    } else {
        if (gogo_ball_sync_state.goal_flags & (this->three_point != 0 ? 0x20 : 2)) {
            this->active = 1;
            update_effects();
        } else {
            this->active = 0;
            this->goal_frames = 0;
        }
    }
    t = this->age;
    this->age = t + 1;
    if (t >= this->lifetime) {
        queue_destruction();
    }
}

void TGoGoBallGoal::render() {
    NJS_OBJECT *bml_model;
    if (this->active != 0) {
        this->flap_angle = (this->flap_angle + 0x38E);
        if ((s32) this->flap_angle >= 0x4000) {
            this->flap_angle = 0x4000;
        }
    } else {
        this->flap_angle = (this->flap_angle - 0x38E);
        if ((s32) this->flap_angle <= 0) {
            this->flap_angle = 0;
        }
    }
    bml_model = get_bml_model(gogo_ball_bml_resource, 1);
    if (bml_model != NULL) {
        if ((s32) this->team0 != 0) {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(lobby_gvm_texture_handles[7]));
        } else {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(lobby_gvm_texture_handles[8]));
        }
        push_matrix();
        post_translate_matrix(&this->pos.x);
        ::draw_ginja_model(bml_model->model);
        push_matrix();
        ::draw_ginja_model(bml_model->child->model);
        pop_matrix();
        push_matrix();
        rotate_matrix_z(0, this->flap_angle);
        rotate_matrix_y(0, 0x8000);
        ::draw_ginja_model(bml_model->child->sibling->model);
        pop_matrix();
        push_matrix();
        rotate_matrix_z(0, (int) (-this->flap_angle));
        ::draw_ginja_model(bml_model->child->sibling->sibling->model);
        pop_matrix();
        pop_matrix();
    }
}
