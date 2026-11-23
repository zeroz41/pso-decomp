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
#include "pso/unk/TUnk_804B8DD0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/text_80198960.h"
#include "pso/unk/TUnk_804B8DE8.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/byteswap.h"
#include "pso/system/TLanguage.h"
#include "pso/unk/TLobby.h"
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
BmlResource *gogo_ball_bml_resource;
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {
s32 draw_chunk_object(s32);
s32 rotate_matrix_z(int, int);
s32 post_translate_matrix(void *);
extern GinjaTextureList *lobby_gvm_texture_handles[];
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_x(int, int);
}

struct Pair_80198F14;
extern "C" {
extern BmlResourceDescriptor language_lobby_texture_descriptor;
extern Pair_80198F14 gogo_ball_team_scores[];
f32 xyz_distance(Vec*,void*);
}
extern void* lbl_804B8D94[];
extern void* lbl_804B8DA0[];
extern "C" {
void *lbl_804B8A10[210] = {
    (void *)0xbf000000, (void *)0x3f600000, (void *)0x0, (void *)0x40600000,
    (void *)0x40200000, (void *)0x8d480ff, (void *)0x0, (void *)0x41a00000,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0xc3770000,
    (void *)0x0, (void *)0x0, (void *)0x43770000, (void *)0x0,
    (void *)0x0, (void *)0x41f00000, (void *)0x60000, (void *)0x41000000,
    (void *)0x40400000, (void *)0xbf000000, (void *)0x3f600000, (void *)0x0,
    (void *)0x40600000, (void *)0x40200000, (void *)0x8d48000, (void *)0xff0000,
    (void *)0x41200000, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0xc3770000, (void *)0x0, (void *)0x0, (void *)0x43770000,
    (void *)0x0, (void *)0x0, (void *)0x41f00000, (void *)0x20000,
    (void *)0x41000000, (void *)0x40400000, (void *)0xbdcccccd, (void *)0x3f000000,
    (void *)0x0, (void *)0x40133333, (void *)0x40133333, (void *)0x8d480ff,
    (void *)0x0, (void *)0x41200000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0xc3770000, (void *)0x0, (void *)0x0,
    (void *)0x43770000, (void *)0x0, (void *)0x0, (void *)0x41f00000,
    (void *)0x30000, (void *)0x40400000, (void *)0x40600000, (void *)0xbf000000,
    (void *)0x3f600000, (void *)0x0, (void *)0x40600000, (void *)0x40200000,
    (void *)0x8d48000, (void *)0xff0000, (void *)0x41200000, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0xc3770000, (void *)0x0,
    (void *)0x0, (void *)0x43770000, (void *)0x0, (void *)0x0,
    (void *)0x41f00000, (void *)0x10000, (void *)0x41000000, (void *)0x40400000,
    (void *)0xbf000000, (void *)0x3f600000, (void *)0x0, (void *)0x40600000,
    (void *)0x40200000, (void *)0x8d480ff, (void *)0xff000000, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0xc3770000,
    (void *)0x0, (void *)0x0, (void *)0x43770000, (void *)0x0,
    (void *)0x0, (void *)0x41f00000, (void *)0x60000, (void *)0x41000000,
    (void *)0x40400000, (void *)0xbf000000, (void *)0x3f600000, (void *)0x0,
    (void *)0x40600000, (void *)0x40200000, (void *)0x8d48000, (void *)0xff0000,
    (void *)0x41c80000, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0xc3770000, (void *)0x0, (void *)0x0, (void *)0x43770000,
    (void *)0x0, (void *)0x0, (void *)0x41f00000, (void *)0x0,
    (void *)0x41000000, (void *)0x40400000, (void *)0xbf000000, (void *)0x3f600000,
    (void *)0x0, (void *)0x40600000, (void *)0x40200000, (void *)0x8d480ff,
    (void *)0xff000000, (void *)0x41200000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0xc3770000, (void *)0x0, (void *)0x0,
    (void *)0x43770000, (void *)0x0, (void *)0x0, (void *)0x41f00000,
    (void *)0x10000, (void *)0x41000000, (void *)0x40400000, (void *)0xbdcccccd,
    (void *)0x3f000000, (void *)0x0, (void *)0x40133333, (void *)0x40133333,
    (void *)0x8d480ff, (void *)0x0, (void *)0x41200000, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0xc3770000, (void *)0x0,
    (void *)0x0, (void *)0x43770000, (void *)0x0, (void *)0x0,
    (void *)0x41f00000, (void *)0x30000, (void *)0x40400000, (void *)0x40600000,
    (void *)0xbf000000, (void *)0x3f600000, (void *)0x0, (void *)0x40600000,
    (void *)0x40200000, (void *)0x8d480ff, (void *)0xff000000, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0xc3770000,
    (void *)0x0, (void *)0x0, (void *)0x43770000, (void *)0x0,
    (void *)0x0, (void *)0x41f00000, (void *)0x20000, (void *)0x41000000,
    (void *)0x40400000, (void *)0xbf000000, (void *)0x3f600000, (void *)0x0,
    (void *)0x40600000, (void *)0x40200000, (void *)0x8d480ff, (void *)0xff000000,
    (void *)0x41200000, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0xc3770000, (void *)0x0, (void *)0x0, (void *)0x43770000,
    (void *)0x0, (void *)0x0, (void *)0x41f00000, (void *)0x0,
    (void *)0x41000000, (void *)0x40400000,
};
const char *biri_ball_motion_names[2] = {NULL, NULL};
const char *biri_ball_model_names[6] = {
    "biri_ball.nj", "fd_obj804_gorl03_dai.gj", "robby_cat.nj", "robby_chu.nj", "rokeorange_churoke.nj", NULL,
};
BmlResourceDescriptor language_lobby_texture_descriptor = {
    "biri_ball.bml", biri_ball_model_names, biri_ball_motion_names, 5, 0,
};
void *lbl_804B8D80[5] = {
    (void *)0x50005, (void *)0x0, (void *)0x0, (void *)0xff00ff,
    (void *)0x0,
};
}
void *lbl_804B8D94[3] = {
    (void *)0x43fa0000, (void *)0x41a00000, (void *)0x0,
};
void *lbl_804B8DA0[3] = {
    (void *)0xc3fa0000, (void *)0x41a00000, (void *)0x0,
};

// The lobby GVM texture lists TLanguage::load_lobby_textures loads.
GinjaTextureList *lobby_gvm_texture_handles[9] = {0};
const NJS_ARGB fish_draw_color[1] = {{0.2f, 0.0f, 0.0f, 0.0f}};
// spawn_particle_effect_with_rotation takes x/y/z angles (0x8000 = half turn).
struct Rot_80198A2C { s32 x, y, z; };
const Rot_80198A2C boss3_volopt_init_vec = {0, 0, 0x8000};

struct Pair_80198F14 { s32 a; s32 b; };
struct ByteBlock_C { u8 bytes[0xc]; };
struct Fx_801994DC {
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 e;
    s32 f;
    u32 g;
    void *h;
};
struct Col_801994DC { f32 r, g, b, a; };
struct Ang_801994DC { s32 x, y, z; };
extern "C" {
s32 scale_current_matrix(void *);
f32 fabs_float(f32);
struct E54_801990B4 { u8 b[0x54]; };
struct Seg_80199674 { Vec a; Vec b; };
struct Hit_80199674 { u32 f0; Seg_80199674 *seg; };
f32 xyz_distance(Vec *, void *);
}
void direction_to_rotation_xz(u8 *dir, s32 *rot_a, s32 *rot_b);
extern u8 saved_model_draw_color[];
extern u8 model_material_color[];
struct Tri_8019978C {
    Vec p;
    Vec n;
};
struct Hit_8019978C {
    u8 pad0[4];
    Tri_8019978C *tri;
};
extern "C" {
Hit_8019978C *csnVector(Vec *, Vec *, s32);
f32 vec3_dot(Vec *, Vec *);
s32 matrix_mult_vec(int, void *, void *);
extern u8 identity_matrix[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
}
void direction_to_rotation_yx(u8 *dir, s32 *rot_a, s32 *rot_b);
extern "C" {
void vec3_add_to(void *, void *);
f32 atan2_float(f32, f32);
#define gogo_ball_team_scores (*(int (*)[1])&gogo_ball_team_scores)
#define vector_length ((f32 (*)(void*,f32))vector_length)
#define xyz_distance ((f32 (*)(void*,void*))xyz_distance)
}
void init_6x40_walk_packet(void *cmd);
void close_gogo_ball_timer() { TWindowCtrl::close_timer_window(); }
void add_gogo_ball_one_point_score(s32 i) {
    ((s32 *)&gogo_ball_team_scores)[i] += 1;
}

void add_gogo_ball_three_point_score(s32 i) {
    ((s32 *)&gogo_ball_team_scores)[i] += 3;
}


void set_gogo_ball_score(s32 team, s32 score) { gogo_ball_team_scores[team] = score; }

s16 get_gogo_ball_score(s32 team) {
    return ((s32 *)&gogo_ball_team_scores)[team];
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

void TObjGoGoBall::sub_8019A44C(s32 angle) {
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
    throw_speed = vector_length(&velocity, (0.1f));
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
    if (xyz_distance(&gogo_ball_configuration.team1_goal, &position) <= gogo_ball_configuration.goal_radius && (0.0f) == ((f32 (*)(void *))vector_length)(&velocity)) {
        gogo_ball_sync_state.goal_flags |= 2;
        if (scored == 0) {
            add_gogo_ball_one_point_score(1);
            scored = 1;
        }
    }
    if (xyz_distance(&gogo_ball_configuration.team0_goal, &position) <= gogo_ball_configuration.goal_radius && (0.0f) == ((f32 (*)(void *))vector_length)(&velocity)) {
        gogo_ball_sync_state.goal_flags |= 1;
        if (scored == 0) {
            add_gogo_ball_one_point_score(0);
            scored = 1;
        }
    }
    if (xyz_distance(&(*(Vec *)&lbl_804B8D94), &position) <= gogo_ball_configuration.goal_radius && (0.0f) == ((f32 (*)(void *))vector_length)(&velocity)) {
        gogo_ball_sync_state.goal_flags |= 0x10;
        if (scored == 0) {
            add_gogo_ball_three_point_score(0);
            scored = 1;
        }
    }
    if (xyz_distance(&(*(Vec *)&lbl_804B8DA0), &position) <= gogo_ball_configuration.goal_radius && (0.0f) == ((f32 (*)(void *))vector_length)(&velocity)) {
        gogo_ball_sync_state.goal_flags |= 0x20;
        if (scored == 0) {
            add_gogo_ball_three_point_score(1);
            scored = 1;
        }
    }
    if ((gogo_ball_sync_state.goal_flags & 2 || gogo_ball_sync_state.goal_flags & 1 || gogo_ball_sync_state.goal_flags & 0x20 || gogo_ball_sync_state.goal_flags & 0x10) && !(gogo_ball_sync_state.goal_flags & 8) && !(gogo_ball_sync_state.goal_flags & 4)) {
        TWindowCtrl::open(get_entity_id(), (saddr)"\tC4Goal", 0x1B);
    }
    if (!(gogo_ball_sync_state.goal_flags & 0x33) && scored != 0) {
        scored = 0;
    }
    len = ((f32 (*)(void *))vector_length)(&velocity);
    if ((0.0f) == len) {
        if (resting == 0) {
            rest_count++;
            TWindowCtrl::open(get_entity_id(), (saddr)"Go!", 0x1B);
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
    init_6x40_walk_packet(&pkt);
    p = get_player_by_client_id(local_client_id);
    if (p != 0) {
        pkt.header.client_id = local_client_id;
        p->calc_movement_target(p->rotation_y, &x, &z);
        pkt.pos.x = x;
        pkt.pos.z = z;
        pkt.flags = 0;
        ((TNpcPlayer *)(&pkt))->sync_from_lobby();
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
        TWindowCtrl::open(this->get_entity_id(), (saddr)"Good Bye", 0x1B);
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
        sub_8019A44C(gogo_ball_sync_state.angle);
    }
    gogo_ball_sync_state.applied = 1;
}

#undef gogo_ball_team_scores
#undef vector_length
#undef xyz_distance

#define F(t, o) (*(t *)((u8 *)this + (o)))
#define vector_length ((f32 (*)(void*))vector_length)
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
    copy_argb((NJS_ARGB *)saved_model_draw_color, (NJS_ARGB *)model_material_color);
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
            TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(lobby_gvm_texture_handles[0]));
            set_cull_back();
            draw_chunk_object((saddr)get_bml_model((BmlResource *)gogo_ball_bml_resource, 3));
            set_cull_front();
            draw_chunk_object((saddr)get_bml_model((BmlResource *)gogo_ball_bml_resource, 3));
            set_cull_none();
            break;
        case 1:
            TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(lobby_gvm_texture_handles[1]));
            set_cull_back();
            draw_chunk_object((saddr)get_bml_model((BmlResource *)gogo_ball_bml_resource, 0));
            set_cull_front();
            draw_chunk_object((saddr)get_bml_model((BmlResource *)gogo_ball_bml_resource, 0));
            set_cull_none();
            break;
        case 2:
            TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(lobby_gvm_texture_handles[2]));
            set_cull_back();
            draw_chunk_object((saddr)get_bml_model((BmlResource *)gogo_ball_bml_resource, 0));
            set_cull_front();
            draw_chunk_object((saddr)get_bml_model((BmlResource *)gogo_ball_bml_resource, 0));
            set_cull_none();
            break;
        case 3:
            TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(lobby_gvm_texture_handles[3]));
            set_cull_back();
            draw_chunk_object((saddr)get_bml_model((BmlResource *)gogo_ball_bml_resource, 0));
            set_cull_front();
            draw_chunk_object((saddr)get_bml_model((BmlResource *)gogo_ball_bml_resource, 0));
            set_cull_none();
            break;
        case 6:
            TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(lobby_gvm_texture_handles[6]));
            set_cull_back();
            draw_chunk_object((saddr)get_bml_model((BmlResource *)gogo_ball_bml_resource, 2));
            set_cull_front();
            draw_chunk_object((saddr)get_bml_model((BmlResource *)gogo_ball_bml_resource, 2));
            set_cull_none();
            break;
        }
    }
    set_constant_material(&chunk_material_color_half_alpha_f32);
    pop_matrices(1);
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    copy_argb((NJS_ARGB *)model_material_color, (NJS_ARGB *)saved_model_draw_color);
    model_render_flags = saved_model_render_flags;
    draw_shadow_on_ground();
}

#undef F
#undef vector_length


#pragma push
#pragma fp_contract on
s32 TObjGoGoBall::reflect_velocity_off_collision(void *p, void *v) {
    Vec end;
    Vec dir;
    Vec a;
    Vec r;
    Vec q;
    Vec s;
    Hit_8019978C *hit;
    Tri_8019978C *tri;
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
    tri = hit->tri;
    px = tri->p.x;
    py = tri->p.y;
    pz = tri->p.z;
    nx = tri->n.x;
    ny = tri->n.y;
    nz = tri->n.z;
    r.x = ((Vec *)v)->x;
    r.y = ((Vec *)v)->y;
    r.z = ((Vec *)v)->z;
    d = (2.0f) * vec3_dot(&r, &tri->n);
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
    Hit_80199674 *hit;
    f32 t;
    f32 k;
    Vec scale;

    hit = (Hit_80199674 *)csnVectorUnder(&position, ground_candidates.groups, 0x15);
    if (hit != 0) {
        Seg_80199674 *src = hit->seg;
        Seg_80199674 seg;
        seg.a.x = src->a.x;
        seg.a.y = src->a.y;
        seg.a.z = src->a.z;
        seg.b.x = src->b.x;
        seg.b.y = src->b.y;
        seg.b.z = src->b.z;
        t = 0.2f / (1.0f + xyz_distance(&seg.a, &position));
        f32 s = 0.85f + t;
        scale.x = s;
        scale.y = s;
        scale.z = s;
        copy_argb((NJS_ARGB *)saved_model_draw_color, (NJS_ARGB *)model_material_color);
        k = 2.0f * t + 0.5f;
        if (k >= 1.0f) {
            k = 1.0f;
        }
        draw_shadow_quads(&seg.a, &seg.b, 0, &scale, (f32)k);
        copy_argb((NJS_ARGB *)model_material_color, (NJS_ARGB *)saved_model_draw_color);
    }
}


#pragma pop


void TObjGoGoBall::draw_shadow_quads(Vec *pos, Vec *dir, s32 angle, Vec *scale, f32 farg0) {
    Ang_801994DC ang;
    Col_801994DC col;
    Fx_801994DC fx;
    if (blob_shadow_texture_list == 0) {
        return;
    }
    direction_to_rotation_xz((u8 *)dir, &ang.x, &ang.z);
    push_matrix();
    post_translate_matrix(pos);
    translate_matrix(0, 0.0f, 0.3f, 0.0f);
    rotate_matrix_z(0, ang.z);
    rotate_matrix_x(0, ang.x);
    rotate_matrix_y(0, angle);
    if (scale != NULL) {
        scale_current_matrix(scale);
    }
    rotate_matrix_x(0, -0x4000);
    fx.a = -5.0f;
    fx.b = 0.0f;
    fx.c = 0.0f;
    fx.d = 1.0f;
    fx.e = 1.0f;
    fx.f = 0;
    fx.g = blob_shadow_texture_list;
    fx.h = lbl_804B8D80;
    col.r = farg0;
    col.g = 1.0f;
    col.b = 1.0f;
    col.a = 1.0f;
    set_constant_material((const NJS_ARGB *)((&col)));
    TParticleCtrl::begin_effect_render();
    ((TObjPlayer *)(&fx))->draw_shadow_quad(0, 0x22);
    fx.a = 0.0f;
    fx.b = 0.0f;
    ((TObjPlayer *)(&fx))->draw_shadow_quad(0, 0x26);
    fx.a = -5.0f;
    fx.b = -5.0f;
    ((TObjPlayer *)(&fx))->draw_shadow_quad(0, 0x2A);
    fx.a = 0.0f;
    fx.b = -5.0f;
    ((TObjPlayer *)(&fx))->draw_shadow_quad(0, 0x2E);
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

// The goal positions are copied as plain 12-byte blocks (word loads), not as Vec members.
void GoGoBallConfig::copy_state(GoGoBallConfig *src) {
    gravity = src->gravity;
    restitution = src->restitution;
    pad_8 = src->pad_8;
    throw_forward_speed = src->throw_forward_speed;
    throw_up_speed = src->throw_up_speed;
    lifetime = src->lifetime;
    pad_16[0] = src->pad_16[0];
    pad_16[1] = src->pad_16[1];
    pad_16[2] = src->pad_16[2];
    pad_16[3] = src->pad_16[3];
    radius = src->radius;
    *(ByteBlock_C *)&start_position = *(ByteBlock_C *)&src->start_position;
    *(ByteBlock_C *)&team1_goal = *(ByteBlock_C *)&src->team1_goal;
    *(ByteBlock_C *)&team0_goal = *(ByteBlock_C *)&src->team0_goal;
    goal_radius = src->goal_radius;
    ball_type = src->ball_type;
    throw_forward_speed_alt = src->throw_forward_speed_alt;
    throw_up_speed_alt = src->throw_up_speed_alt;
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
        gogo_ball_configuration.copy_state(&((GoGoBallConfig *)lbl_804B8A10)[idx]);
        new TObjGoGoBall(tl_03);
        new TUnk_804B8DD0(&gogo_ball_configuration.team0_goal, 1, gogo_ball_configuration.lifetime, tl_04);
        new TUnk_804B8DD0(&gogo_ball_configuration.team1_goal, 0, gogo_ball_configuration.lifetime, tl_04);
        new TUnk_804B8DD0((Vec *)lbl_804B8D94, 1, 1, gogo_ball_configuration.lifetime, tl_04);
        new TUnk_804B8DD0((Vec *)lbl_804B8DA0, 0, 1, gogo_ball_configuration.lifetime, tl_04);
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
    Pair_80198F14 *p = gogo_ball_team_scores;
    GoGoBallSyncState *sync = &gogo_ball_sync_state;
    BmlResource *obj;
    sync->applied = 1;
    sync->position.x = 63.0f;
    sync->position.y = 0.0f;
    sync->position.z = 63.0f;
    sync->angle = 0;
    sync->mode = 0;
    p->a = 0;
    p->b = 0;
    obj = new BmlResource(5, (BmlResourceDescriptor *)&language_lobby_texture_descriptor, 0, 0, NULL);
    gogo_ball_bml_resource = obj;
    lobby_gvm_texture_handles[0] = (GinjaTextureList *)load_gvm_texture_file("robby_chu.gvm");
    lobby_gvm_texture_handles[1] = (GinjaTextureList *)load_gvm_texture_file("biri_ball.gvm");
    lobby_gvm_texture_handles[2] = (GinjaTextureList *)load_gvm_texture_file("bom_ball.gvm");
    lobby_gvm_texture_handles[3] = (GinjaTextureList *)load_gvm_texture_file("soft_ball.gvm");
    lobby_gvm_texture_handles[4] = (GinjaTextureList *)load_gvm_texture_file("rokeorange_churoke.gvm");
    lobby_gvm_texture_handles[5] = (GinjaTextureList *)load_gvm_texture_file("rokeblue_pso_churoke.gvm");
    lobby_gvm_texture_handles[6] = (GinjaTextureList *)load_gvm_texture_file("robby_cat.gvm");
    lobby_gvm_texture_handles[7] = (GinjaTextureList *)load_gvm_texture_file("fd_obj804_gorl03.gvm");
    lobby_gvm_texture_handles[8] = (GinjaTextureList *)load_gvm_texture_file("fd_obj804_gorl03_b.gvm");
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

TUnk_804B8DE8::TUnk_804B8DE8(Vec *position, s32 limit, s32 team0, s32 three_point, TObject *parent) : TObject(parent) {
    VecCopy(&pos, position);
    VecCopy(&initial_pos, &pos);
    pos.y -= 16.0f;
    effect = NULL;
    rot = 0;
    unk_38 = 0;
    this->limit = limit;
    counter = 0;
    timer = 0;
    this->team0 = team0;
    this->three_point = three_point;
    state = 0;
}

TUnk_804B8DE8::~TUnk_804B8DE8() {
    if (effect != NULL) {
        effect->queue_destruction();
        effect = NULL;
    }
}

#pragma push
#pragma fp_contract on
void TUnk_804B8DE8::run_task() {
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
            Rot_80198A2C init = boss3_volopt_init_vec;
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
void TUnk_804B8DE8::render() {
    if (((gogo_ball_bml_resource != NULL) || (lobby_gvm_texture_handles[4] != NULL)) && (gogo_ball_configuration.ball_type != 6)) {
        if (this->team0 == 1) {
            TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(lobby_gvm_texture_handles[4]));
        } else {
            TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(lobby_gvm_texture_handles[5]));
        }
        push_matrix();
        post_translate_matrix(&this->pos);
        rotate_matrix_y(0, this->rot);
        scale_matrix(0, 1.5f, 1.5f, 1.5f);
        draw_chunk_object((saddr)get_bml_model((BmlResource *)gogo_ball_bml_resource, 4));
        pop_matrix();
    }
}

TUnk_804B8DD0::TUnk_804B8DD0(Vec *position, s32 team0, s32 lifetime, TObject *parent) : TObject(parent) {
    VecCopy(&pos, position);
    this->team0 = team0;
    age = 0;
    this->lifetime = lifetime;
    m_38 = 0;
    m_30 = 0;
    active = 0;
    three_point = 0;
}

TUnk_804B8DD0::TUnk_804B8DD0(Vec *position, s32 team0, s32 three_point, s32 lifetime, TObject *parent) : TObject(parent) {
    VecCopy(&pos, position);
    this->team0 = team0;
    age = 0;
    this->lifetime = lifetime;
    m_38 = 0;
    m_30 = 0;
    active = 0;
    this->three_point = three_point;
}

TUnk_804B8DD0::~TUnk_804B8DD0() {}

void TUnk_804B8DD0::update_effects() {
    Vec v6;
    Vec v2a;
    Vec v2b;
    Vec vda;
    Vec vdb;
    if (gogo_ball_configuration.ball_type == 0) {
        (this->m_30)++;
        if (this->m_30 == 1) {
            new TUnk_804B8DE8(&this->pos, gogo_ball_configuration.lifetime, this->team0, this->three_point, tl_06);
        }
    } else if (gogo_ball_configuration.ball_type == 6) {
        (this->m_30)++;
        if (this->m_30 % 5 == 0 && this->m_30 <= 0x1E) {
            VecCopy((Vec *)&v6, &this->pos);
            v6.y += 7.0f;
            spawn_particle_effect_with_flags(&v6, 0x20D, 0x40);
            play_sound_effect(0x4001A82E, (u8 *)&this->pos, 0, 0);
        }
    } else if (gogo_ball_configuration.ball_type == 2) {
        (this->m_30)++;
        if (this->team0 != 0) {
            if (this->m_30 == 1) {
                TCameraCtrl::set_shake_preset(2);
                VecCopy((Vec *)&v2a, &this->pos);
                v2a.y += 7.0f;
                spawn_particle_effect_with_flags(&v2a, 0x45, 0x40);
                spawn_particle_effect_with_flags(&v2a, 0x189, 0x40);
                play_sound_effect(0x4001C112, (u8 *)&this->pos, 0, 0);
            }
        } else {
            if (this->m_30 == 1) {
                TCameraCtrl::set_shake_preset(2);
                VecCopy((Vec *)&v2b, &this->pos);
                v2b.y += 7.0f;
                spawn_particle_effect_with_flags(&v2b, 0x45, 0x40);
                spawn_particle_effect_with_flags(&v2b, 0x189, 0x40);
                play_sound_effect(0x4001C112, (u8 *)&this->pos, 0, 0);
            }
        }
    } else if (gogo_ball_configuration.ball_type != 0) {
        (this->m_30)++;
        if (this->team0 != 0) {
            if (this->m_30 % 5 == 0 && this->m_30 <= 0x32) {
                VecCopy((Vec *)&vda, &this->pos);
                vda.y += 7.0f;
                spawn_particle_effect_with_flags(&vda, 0x20E, 0x40);
                new TUnk_804CCA78(&this->pos, 5, 0x4002A90C, 0, tl_05);
            }
        } else {
            if (this->m_30 % 5 == 0 && this->m_30 <= 0x32) {
                VecCopy((Vec *)&vdb, &this->pos);
                vdb.y += 7.0f;
                spawn_particle_effect_with_flags(&vdb, 0x20F, 0x40);
                new TUnk_804CCA78(&this->pos, 5, 0x4002A90C, 0, tl_05);
            }
        }
    }
}

void TUnk_804B8DD0::run_task() {
    s32 t;
    if (this->team0 != 0) {
        if (gogo_ball_sync_state.goal_flags & (this->three_point != 0 ? 0x10 : 1)) {
            this->active = 1;
            update_effects();
        } else {
            this->active = 0;
            this->m_30 = 0;
        }
    } else {
        if (gogo_ball_sync_state.goal_flags & (this->three_point != 0 ? 0x20 : 2)) {
            this->active = 1;
            update_effects();
        } else {
            this->active = 0;
            this->m_30 = 0;
        }
    }
    t = this->age;
    this->age = t + 1;
    if (t >= this->lifetime) {
        queue_destruction();
    }
}

void TUnk_804B8DD0::render() {
    u8 *bml_model;
    if (this->active != 0) {
        this->m_38 = (this->m_38 + 0x38E);
        if ((s32) this->m_38 >= 0x4000) {
            this->m_38 = 0x4000;
        }
    } else {
        this->m_38 = (this->m_38 - 0x38E);
        if ((s32) this->m_38 <= 0) {
            this->m_38 = 0;
        }
    }
    bml_model = (u8 *)(get_bml_model((BmlResource *)gogo_ball_bml_resource, 1));
    if (bml_model != NULL) {
        if ((s32) this->team0 != 0) {
            TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(lobby_gvm_texture_handles[7]));
        } else {
            TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(lobby_gvm_texture_handles[8]));
        }
        push_matrix();
        post_translate_matrix((u8 *)&this->pos);
        ::draw_ginja_model(*(void **)((s8 *)bml_model + 4));
        push_matrix();
        ::draw_ginja_model(*(void **)((s8 *)(*(u8 **)((s8 *)bml_model + 0x2C)) + 4));
        pop_matrix();
        push_matrix();
        rotate_matrix_z(0, this->m_38);
        rotate_matrix_y(0, 0x8000);
        ::draw_ginja_model(*(void **)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)bml_model + 0x2C)) + 0x30)) + 4));
        pop_matrix();
        push_matrix();
        rotate_matrix_z(0, (int) (-this->m_38));
        ::draw_ginja_model(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)bml_model + 0x2C)) + 0x30)) + 0x30)) + 4));
        pop_matrix();
        pop_matrix();
    }
}
