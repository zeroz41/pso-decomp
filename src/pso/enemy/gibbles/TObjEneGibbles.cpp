#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/map/CsnQuery.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/effect/GroundContactSound.h"
#include "pso/player/PlayerAttackParams.h"
struct NJS_OBJECT;
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/RenderFadeState.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/TObjControl.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/gibbles/TObjEneGibbles.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/system/vector.h"
#include "pso/render/TUnk_80494938.h"
#include <stddef.h>
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/player/PlayerSlots.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/camera/TCameraCtrl_8006A03C.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/object/base/CollisionActorLookup.h"
struct Obj_800A6B14;
struct Vec_802DA0BC { s32 x, y, z; };
struct Sub_802D8984 { u8 pad[0x18]; u32 f18; };
struct Prm_802D8984 { u8 pad[0xC]; f32 fC; u8 pad10[8]; s32 f18; };
// inferred: actions/action_count hold gibbles_action_table and its 10 entries (same layout as GeeAnimationBinding)

struct O_802DBC94;
extern "C" {
f32 calc_xz_distance_sq(saddr arg0, uaddr arg1, void *arg2);
f32 atan2_float(f32 y, f32 x);
s32 angle_difference_abs(s32, s32);
extern uaddr gibbles_combat_stat_entries;
s16 get_attack_params_atp_min(void *);
s32 get_current_floor();
void check_enemy_body_collisions(void *arg0);
s32 minimap_render_dot(void *, int, int, int);
s32 enemy_move_toward(void *, s32, void *, int, f32);
s32 select_enemy_destination(void *, Vec_802DA0BC *, int);
s32 copy_position_if_valid(s32 arg0, s32 arg1);
f32 horizontal_distance_squared(int, void *);
extern u8 *TObjEneGibbles__ai_parameters;
s32 is_split_screen();
f32 subtract_vector(void *, void *);
s32 check_path_obstructed(void *, void *);
u16 get_entity_id(void *);
void calc_velocity_toward_destination(void *, Vec_802DA0BC, Vec_802DA0BC, f32);
f32 newton_sqrtf(f32);
extern saddr gibbles_boss_stat_handle;
extern saddr gibbles_combat_stats_handle;
extern uaddr TObjEneGibbles__resource_bundle;
void init_collision_body_parts(void *, void *, int);
struct Stack_802D7ED4 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};
struct RecoveredGlobal_802D7ED4_lbl_80472780 {
    s32 value;
    u8 remaining[0xC];
};
struct RecoveredGlobal_802D7ED4_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};
LAYOUT_ASSERT(RecoveredGlobal_802D7ED4_lbl_80472780_size, sizeof(RecoveredGlobal_802D7ED4_lbl_80472780) == 0x10);
LAYOUT_ASSERT(RecoveredGlobal_802D7ED4_lbl_8058D490_size, sizeof(RecoveredGlobal_802D7ED4_lbl_8058D490) == 0x30);
struct E_802DBC94 { s32 a; s32 b; s32 c; s32 d; };
struct G_802DBC94 { u8 pad[0x42c]; E_802DBC94 *e; };
struct O_802DBC94 { u8 pad[0x24]; s32 f24; u8 pad2[0xc]; s32 f34; };
struct Tgt_800A6B14 { u8 pad[0x2fc]; Vec pos; };
struct Obj_800A6B14 {
    u8 pad[0x60]; s32 angle;
    u8 pad2[0x2a8 - 0x64]; Tgt_800A6B14 *target;
    u8 pad3[0x2fc - 0x2ac]; Vec pos;
};
f32 calc_distance_to_client__10TObjPlayerFlUsUl(void *, u16, Vec *);
s32 obj_setFlags30(void *, int);
void start_camera_shake(s32, f32);
s32 rotate_xz_pair_by_angle(f32 *, f32 *, s32, f32);
void TObjPlayer__sub_800D93C4(s32 point, s32 delay);
s32 angle_diff_s16(s32, s32);
s32 lerp_angle_half__Fll(s32, s32);
s32 vec3_add_to(f32 *, void *);
s32 matrix_mult_vec(int, void *, void *);
s32 rotate_matrix_x(s32, s32);
f32 post_translate_matrix(void *);
extern RecoveredGlobal_802D7ED4_lbl_8058D490 identity_matrix;
extern s32 local_client_id;
struct Gib_802D8984 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[4];
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0xA4 - 0x64];
    Sub_802D8984 *fA4;
    u8 padA8[0xB8 - 0xA8];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    f32 fC4;
    f32 fC8;
    u8 padCC[0x290 - 0xCC];
    Vec_802DA0BC f290;
    Vec_802DA0BC f29C;
    Gib_802D8984 *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec_802DA0BC f2FC;
    u8 pad308[0x326 - 0x308];
    s16 mode;
    s16 sub;
    u8 pad32A[0x338 - 0x32A];
    u16 idx;
    u8 pad33A[0x374 - 0x33A];
    u32 f374;
    u8 pad378[0x38C - 0x378];
    f32 f38C;
    f32 f390;
    u8 pad394[0x3A4 - 0x394];
    s32 f3A4;
    s32 f3A8;
};
extern const char *TObjEneGibbles__model_filenames[2];
extern const char *TObjEneGibbles__motion_names_and_resource_descriptor[11];
extern const char *lbl_804E286C[2];
extern const char *gibbles_motion_name_table[11];
__declspec(section ".data") const char *TObjEneGibbles__model_filenames[2] = {
    "gibb_body.nj", NULL,
};
const char *TObjEneGibbles__motion_names_and_resource_descriptor[11] = {
    "attack_gibb_body.njm", "damage_gibb_body.njm", "dead_gibb_body.njm", "guard_gibb_body.njm",
    "jump_gibb_body.njm", "kamae_gibb_body.njm", "landing_gibb_body.njm", "punch_gibb_body.njm",
    "wait_gibb_body.njm", "walk_gibb_body.njm", NULL,
};
void *lbl_804E285C[4] = {
    (void *)"bm_ene_gibbles.bml", (void *)&TObjEneGibbles__model_filenames, (void *)&TObjEneGibbles__motion_names_and_resource_descriptor, (void *)0x1000a,
};
__declspec(section ".data") const char *lbl_804E286C[2] = {
    "lo_gibb_body.nj", NULL,
};
const char *gibbles_motion_name_table[11] = {
    "attack_gibb_body.njm", "damage_gibb_body.njm", "dead_gibb_body.njm", "guard_gibb_body.njm",
    "jump_gibb_body.njm", "kamae_gibb_body.njm", "landing_gibb_body.njm", "punch_gibb_body.njm",
    "wait_gibb_body.njm", "walk_gibb_body.njm", NULL,
};
void *lbl_804E28A0[4] = {
    (void *)"bm_ene_gibbles_low.bml", (void *)&lbl_804E286C, (void *)&gibbles_motion_name_table, (void *)0x1000a,
};
TObjMotionAction gibbles_action_table[10] = {
    {1, 0, 8, 0.3f, 1},
    {1, 0, 9, 0.5f, 1},
    {2, 0, 0, 0.7f, 4},
    {2, 0, 7, 0.6f, 4},
    {1, 0, 5, 0.3f, 4},
    {2, 6, 4, 0.7f, 4},
    {1, 0, 6, 0.7f, 4},
    {1, 0, 3, 0.8f, 0x20},
    {2, 0, 1, 0.8f, 8},
    {3, 0, 2, 0.7f, 0x10},
};
const char *TObjEneGibbles__class_name = "TObjEneGibbles";
const NpcAnimationBinding gibbles_resource_binding_desc = { NULL, reinterpret_cast<TObjMotionAction *>(gibbles_action_table), 0, 1, 10 };
const Vec lbl_80472768 = {0.0f, 0.0f, 0.0f};
const Vec lbl_80472774 = {0.0f, 0.0f, 0.0f};
const RecoveredGlobal_802D7ED4_lbl_80472780 gibbles_joint_zero_vec = {0};
void *lbl_804E2950[7] = {
    (void *)0x437a0000, (void *)0x3fa00000, (void *)0x400, (void *)0x0,
    (void *)0x64, (void *)0x0, (void *)0x0,
};
void *lbl_804E296C[33] = {
    (void *)0x0, (void *)0x41700000, (void *)0x0, (void *)0x41700000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41700000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x41f00000, (void *)0x0, (void *)0x0,
    (void *)0x8003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
}
void apply_actor_gravity(TObjEnemy *enemy, s32 *arg1, f32 farg0);
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 TObjEneGibbles__render_node_index;
extern s32 TObjEneGibbles__render_rotation_x;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern s32 registered_player_count;
void move_with_wall_slide(u8 *arg0);
int initialize_enemy_photon_effect(void *p);
extern "C" {
s16 TObjPlayer__sub_800A776C(void *p);
#define PRM ((Prm_802D8984 *)TObjEneGibbles__ai_parameters)
// movementParameters (lbl_804E2950): 250.0f, 1.25f, 0x400
struct GibblesMoveParams { f32 radius; f32 speed; s32 turn_speed; };
extern "C" s32 obj_is_hit_receivable(u8 *arg0);
extern s32 actor_frame_tick;
#define TGT_802D9EB4 (((void **)gibbles_combat_stat_entries)[(*(s16 *)(self + 0x37C))])
void free_collision_body_parts(void *);
saddr gibbles_boss_stat_handle;
uaddr gibbles_combat_stat_entries;
saddr gibbles_combat_stats_handle;
u8 *TObjEneGibbles__ai_parameters;
uaddr TObjEneGibbles__resource_bundle;
}
s32 TObjEneGibbles__render_node_index;
s32 TObjEneGibbles__render_rotation_x;

// The file is compiled -inline off,deferred, which emits the functions in the
// reverse of the order they are written in.
void TObjEneGibbles::sub_802DBC94(s32 i) {
    ((O_802DBC94 *)this)->f34 = (*(G_802DBC94 * *)&TObjEneGibbles__resource_bundle)->e[i].c;
    ((O_802DBC94 *)this)->f24 = (*(G_802DBC94 * *)&TObjEneGibbles__resource_bundle)->e[i].d;
}

void *TObjEneGibbles::get_center() { return (char*)this + 0x2fc; }

TObjEneGibbles::TObjEneGibbles(TObject *parent, void *setData) : TObjEnemy(parent) {
    s32 i;
    m_name = TObjEneGibbles__class_name;
    apply_set_data(setData);
    ((TObjPlayer *)this)->init_position_vectors();
    scale.x = scale.y = scale.z = 1.0f;
    init_params();
    mode = 0;
    phase = 0;
    variant = 0;
    set_param(0x3D);
    subtype = 0;
    sub_802DBC94(variant);
    action_table = gibbles_action_table;
    set_field_d8((saddr)action_table);
    *(s32 *)((s8 *)this + 0xDC) = *(s32 *)((s8 *)TObjEneGibbles__resource_bundle + 0x430);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    init_collision_body_parts(this, lbl_804E296C, 1);
    m_37c = 0;
    *(s16 *)((s8 *)this + 0x37E) = 0;
    movementParameters = (void *)lbl_804E2950;
    bind_enemy_combat_stats((u8 *)gibbles_boss_stat_handle, (u8 *)(((saddr *)gibbles_combat_stat_entries)[m_37c]), (u8 *)gibbles_combat_stats_handle);
    referenceHp = hp;
    update_position();
    update_shadow_height();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
    initialize_enemy_photon_effect(this);
    m_374 = 1;
    m_3b0 = NULL;
    m_3bc = 0;
    add_flags_2e4(0x11);
    actorFlags |= 0x06040000;
    m_380 = 0x101;
    *(s32 *)((s8 *)this + 0x384) = 0x101;
    attack_colliders[0] = new TObjCollidable(NULL);
    init_collision_body_parts(attack_colliders[0], (u8 *)lbl_804E296C + 0x2C, 1);
    attack_colliders[1] = new TObjCollidable(NULL);
    init_collision_body_parts(attack_colliders[1], (u8 *)lbl_804E296C + 0x58, 1);
    fade.reset_obstruction_fade();
    for (i = 0; i < 4; i++) {
        fades[i].activate_and_dispatch();
    }
    clear_lobby_object_state();
}

TObjEneGibbles::~TObjEneGibbles() {
    if (attack_colliders[0] != NULL) {
        free_collision_body_parts(attack_colliders[0]);
        delete attack_colliders[0];
        attack_colliders[0] = NULL;
    }
    if (attack_colliders[1] != NULL) {
        free_collision_body_parts(attack_colliders[1]);
        delete attack_colliders[1];
        attack_colliders[1] = NULL;
    }
    free_collision_body_parts(this);
}

void TObjEneGibbles::load_resources() {
    u8 *p;
    if (is_split_screen() != 0) {
        p = (u8 *)new BmlResource(1, (BmlResourceDescriptor *)lbl_804E28A0, 0, 0, NULL);
        TObjEneGibbles__resource_bundle = (uaddr) p;
    } else {
        p = (u8 *)new BmlResource(1, (BmlResourceDescriptor *)lbl_804E285C, 0, 0, NULL);
        TObjEneGibbles__resource_bundle = (uaddr) p;
    }
    TObjEneGibbles__render_node_index = 0;
    TObjEneGibbles__render_rotation_x = 0;
    gibbles_combat_stat_entries = (uaddr) mem_alloc(0xC);
    gibbles_boss_stat_handle = (saddr)TLobby::register_boss(0x3D);
    ((s32 *) gibbles_combat_stat_entries)[0] = (saddr)TLobby::dispatch_shared_handler_b(0x3D);
    ((s32 *) gibbles_combat_stat_entries)[2] = (saddr)TLobby::dispatch_shared_handler_b(0x3E);
    ((s32 *) gibbles_combat_stat_entries)[1] = (saddr)TLobby::dispatch_shared_handler_b(0x3F);
    gibbles_combat_stats_handle = (saddr)TLobby::register_object(0x3D);
    (*(s32 *)&TObjEneGibbles__ai_parameters) = (saddr)TLobby::dispatch_shared_handler_a(0x3D);
    NpcAnimationBinding s = gibbles_resource_binding_desc;
    s.motions = reinterpret_cast<BmlMotionEntry *>(*(s32 *)((s8 *)TObjEneGibbles__resource_bundle + 0x430));
    NpcModelRegistry::register_animated_chunk((s16)0x44, reinterpret_cast<void *>((*(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneGibbles__resource_bundle + 0x42C)) + 8))), reinterpret_cast<void *>((*(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneGibbles__resource_bundle + 0x42C)) + 0xC))), &s, (f32)(((f32 *)lbl_804E296C)[3]), 0.0f);
}

void TObjEneGibbles::free_static() {
    if ((u32) gibbles_combat_stat_entries != 0U) {
        mem_free((void*)gibbles_combat_stat_entries);
        gibbles_combat_stat_entries = 0U;
    }
    if ((u32) TObjEneGibbles__resource_bundle != 0U) {
        delete (BmlResource *)TObjEneGibbles__resource_bundle;
        TObjEneGibbles__resource_bundle = 0U;
    }
}

void *TObjEneGibbles::create(void *arg0) {
    TObjControl *parent = new TObjControl(tl_04);
    return new TObjEneGibbles(parent, arg0);
}

void TObjEneGibbles::init_params() {
    s16 temp_r0;
    s32 temp_r0_2;

    temp_r0 = (s16) (100.0f + this->parameters[0]);
    this->m_388 = temp_r0;
    *(s16 *)&this->unk_38A = temp_r0;
    this->m_39c = (s32) *(f32 *)((s8 *)this + 0x358);
    temp_r0_2 = this->m_39c;
    if (temp_r0_2 < 0) {
        this->m_39c = 0;
    } else if (temp_r0_2 > 8) {
        this->m_39c = 8;
    }
    target_class_mask = 0;
    target_class_mask |= 1 << this->m_39c;
    this->m_394 = (f32) this->parameters[2];
    *(f32 *)&this->unk_398 = (f32) *(f32 *)((s8 *)this + 0x360);
}

void TObjEneGibbles::run_task() {
    s16 temp_r0;
    u8 *temp_r4;
    if (TObjPlayer::check_demo_mode() == 1) {
        sub_802D7E3C();
        return;
    }
    {
        switch (this->mode) {
        case 0:
            this->init_state();
            break;
        case 1:
            this->update_spawn_state();
            break;
        case 2:
            this->update_death_sequence();
            break;
        case 3:
            this->sub_802DA0BC();
            break;
        case 4:
            sub_802D9110();
            break;
        case 5:
            sub_802D8E8C();
            break;
        case 6:
            this->sub_802D8984();
            break;
        case 7:
            sub_802D8580();
            break;
        case 8:
            this->update_action_state();
            break;
        case 9:
            this->sub_802D8140();
            break;
        case 10:
            this->sub_802DA7A4();
            break;
        case 11:
            this->update_wander();
            break;
        }
    }
    temp_r4 = (u8 *)(this->target);
    if ((temp_r4 != NULL) && (*(s32 *)((s8 *)temp_r4 + 0x30) & 0x02000800)) {
        *(s16 *)((s8 *)this + 0x37E) = 0;
        this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
        this->m_374 = (s32) (this->m_374 & 0xFFFF0000);
        this->target = NULL;
    }
    this->update_position();
    this->update_shadow_height();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
    this->sync_state();
    this->m_2b4 += 1.0f;
}

void TObjEneGibbles::render() {
    Vec v;
    s32 fade;
    s32 vis;
    s32 cam;
    cam = 0;
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_mode();
    }
    if (get_current_floor_area() == AREA_TOWER) {
        vis = this->classify_actor_view_detail(600.0f, 600.0f, 30.0f);
    } else {
        vis = this->classify_actor_view_detail(300.0f, 600.0f, 30.0f);
    }
    if (vis != 0) {
        this->fades[cam].update();
        fade = this->fades[cam].updateFromCamera((const f32*)((u8 *)this + 0x2FC));
        select_actor_lighting(this);
        TObjFish::set_global_param(this->texlist);
        push_matrix_from(0);
        VecCopy((Vec *)&v, (const Vec *)((Vec *)((u8 *)this + 0x38)));
        switch (this->mode) {
        case 2:
        case 6:
        case 10:
            v.y += this->m_38c;
            break;
        }
        translate_matrix_vec3((u8 *)(0), (u8 *)&v);
        rotate_matrix_y(0, this->rotation_y);
        scale_matrix_vec3(0, (u8 *)this + 0x68);
        TObjEneGibbles__render_node_index = 0;
        TObjEneGibbles__render_rotation_x = this->m_3bc;
        set_chunk_model_node_callback(gibbles_render_node_callback);
        TObjPlayer::toggle_particle_effect();
        switch (this->mode) {
        case 0:
            break;
        case 1:
        case 2:
        case 10:
            if (this->fade.has_visible_opacity() != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                model_render_flags |= 1;
                this->fade.set_flags_and_apply_damage_color();
                if (defer_render() == 0) {
                    ((TObjMotion *)this)->draw();
                }
                this->fade.clear_flag_and_notify();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            }
            break;
        default:
            if (fade != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                this->fades[cam].set_flags_and_apply_damage_color();
                if (defer_render() == 0) {
                    if (vis == 1) {
                        ((TObjMotion *)this)->draw();
                    } else {
                        ((TObjEnemy *)this)->draw_motion_model();
                    }
                }
                this->fades[cam].clear_flag_and_notify();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            } else if (vis == 1) {
                ((TObjMotion *)this)->draw();
            } else {
                ((TObjEnemy *)this)->draw_motion_model();
            }
            break;
        }
        TParticleCtrl::end_effect_render();
        set_chunk_model_node_callback(NULL);
        pop_matrix();
        restore_scene_lighting();
        if (!(this->m_374 & 1)) {
            ((TObjEnemy *)this)->draw_ground_shadow(0, 0);
        }
    } else {
        this->update_position();
    }
}

void gibbles_render_node_callback(NJS_OBJECT *) {
    if ((s32) TObjEneGibbles__render_node_index == 0x18) {
        rotate_matrix_x(0, TObjEneGibbles__render_rotation_x);
    }
    TObjEneGibbles__render_node_index += 1;
}

void TObjEneGibbles::clamp_angle(s32 arg1) {
    s32 target_rot;

    target_rot = arg1;
    if (target_rot < -0x238E) {
        target_rot = -0x238E;
    } else if (target_rot > 0x238E) {
        target_rot = 0x238E;
    }
    this->m_3bc = lerp_angle_half__Fll(this->m_3bc, target_rot);
}

void TObjEneGibbles::turn_toward_target() {
    Vec d;
    VecCopy((Vec *)&d, (const Vec *)(&((Obj_800A6B14 *)this)->target->pos));
    subtract_vector(&d, &((Obj_800A6B14 *)this)->pos);
    ((TObjEneGibbles *)((Obj_800A6B14 *)this))->clamp_angle(angle_diff_s16(((Obj_800A6B14 *)this)->angle, (s32)(10430.38043493439 * atan2_float(d.x, d.z))));
}

void TObjEneGibbles::refresh_target() {
    if (m_374 & 0x40) {
        targetId = 0xFFFF;
        target = NULL;
        return;
    }
    if (is_actor_cadence_frame(0x1E) == 0) {
        return;
    }
    if (obj_testFlags30(0x10) != 0) {
        s32 best_id;
        s32 i;
        u8 *p;
        s32 id;
        f32 best;
        f32 d;
        u16 tid;
        i = 0;
        best_id = 0xFFFF;
        Vec v = lbl_80472768;
        best = *(f32 *)movementParameters * *(f32 *)movementParameters;
        for (; i < registered_player_count + registered_enemy_count; i++) {
            p = (u8 *)TObjPlayer::get_player_data(i);
            if (TObjPlayer::is_valid_and_active((uaddr)p) != 0 && p != (u8 *)this) {
                id = ((s32 (*)(void *))get_entity_id)(p);
                if ((u16)id < 0x4000 && (u16)id != entity_id && !(((TObjChara *)p)->actorFlags & 0x02000800)) {
                    VecCopy((Vec *)&v, (const Vec *)((Vec *)(p + 0x2FC)));
                    subtract_vector(&v, &body_center);
                    d = v.x * v.x + v.z * v.z;
                    if (d < best && check_path_obstructed(this, p + 0x2FC) != 1) {
                        best_id = id;
                        best = d;
                    }
                }
            }
        }
        targetId = best_id;
        tid = targetId;
        if (tid < 0x1000U) {
            u8 *q = (u8 *)get_player_by_client_id(tid);
            if (q != NULL) {
                if (((TObjPlayer *)q)->get_floor() == get_current_floor()) {
                    target = q;
                    return;
                }
            }
            target = NULL;
            return;
        }
        if (tid < 0x4000U) {
            target = get_enemy_entity(tid);
        }
        return;
    }
    {
        s32 best_id2;
        s32 best_id;
        u8 *p;
        u8 *best_p2;
        u8 *best_p;
        s32 i;
        f32 best2;
        f32 best;
        f32 d;
        Vec v = lbl_80472774;
        best_id = 0xFFFF;
        best_p2 = NULL;
        best_id2 = best_id;
        best_p = NULL;
        i = 0;
        best = *(f32 *)movementParameters * *(f32 *)movementParameters;
        best2 = best;
        for (; i < registered_player_count; i++) {
            p = (u8 *)TObjPlayer::get_player_data(i);
            if (p == NULL) continue;
            if ((u16)((s32 (*)(void *))get_entity_id)(p) >= 0x1000) continue;
            if (((TObjPlayer *)p)->get_floor() != get_current_floor()) continue;
            if (((TObjChara *)p)->actorFlags & 0x02000800) continue;
            VecCopy((Vec *)&v, (const Vec *)((Vec *)(p + 0x2FC)));
            subtract_vector(&v, &body_center);
            d = v.x * v.x + v.z * v.z;
            if ((((TObjPlayer *)p)->class_flags & target_class_mask) && d < best &&
                check_path_obstructed(this, p + 0x2FC) != 1) {
                best_id = ((s32 (*)(void *))get_entity_id)(p);
                best = d;
                best_p = p;
            }
            if (d < best2 && check_path_obstructed(this, p + 0x2FC) != 1) {
                best_id2 = ((s32 (*)(void *))get_entity_id)(p);
                best2 = d;
                best_p2 = p;
            }
        }
        if (best2 < 900.0f && best_p2 != NULL) {
            targetId = best_id2;
            target = best_p2;
            return;
        }
        if (best_p != NULL) {
            targetId = best_id;
            target = best_p;
            return;
        }
        if (best_p2 != NULL) {
            targetId = best_id2;
            target = best_p2;
            return;
        }
        targetId = 0xFFFF;
        target = NULL;
    }
}

s32 TObjEneGibbles::update_action_hold_status() {
    u8 *self = (u8 *)this;
    if (TObjChara::update_action_hold_status() != 0) {
        switch (this->mode) {
        case 0:
        case 1:
        case 2:
        case 0xa:
            if (((TObjEneGibbles *)self)->fade.advance_toward_max() == 1) {
                this->m_374 &= ~0x143;
                this->m_374 |= 4;
                this->mode = 3;
                this->phase = 0;
                this->requested_action = 1;
                ((TObjBase *)self)->obj_clearFlags30(0x06240000);
            }
            break;
        }
        return 1;
    }
    return 0;
}

s32 TObjEneGibbles::update_movement_status() {
    u8 *self = (u8 *)this;
    if (TObjChara::update_movement_status() != 0) {
        switch (this->mode) {
        case 0:
        case 1:
        case 2:
        case 0xa:
            if (((TObjEneGibbles *)self)->fade.advance_toward_max() == 1) {
                this->m_374 &= ~0x143;
                this->m_374 |= 4;
                this->mode = 3;
                this->phase = 0;
                this->requested_action = 1;
                ((TObjBase *)self)->obj_clearFlags30(0x06240000);
            }
            break;
        }
        return 1;
    }
    return 0;
}

void TObjEneGibbles::run_idle_action() {
    u8 *self = (u8 *)this;
    u8 *temp_r3;

    switch (this->mode) {
    case 0:
        if (((TObjEneGibbles *)self)->fade.has_visible_opacity() != 0) {
            this->mode = 0xA;
            this->phase = 0;
            this->requested_action = 0;
            ((TObjBase *)self)->obj_clearFlags30(0x200000);
            obj_setFlags30(self, 0x06040000);
            this->m_374 = (s32) (this->m_374 & 0xFFFF0000);
            temp_r3 = (unsigned char *) (this->bodies);
            *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) & 0xFFFFFFFE);
        }
    case 6:
    case 11:
        return;
    case 10:
        if (!(this->m_374 & 0x40)) {
            this->mode = 0;
            return;
        }
        break;
    default:
        this->phase = 0;
        this->mode = 0xB;
        this->requested_action = 1;
        this->actorFlags = (s32) (this->actorFlags & 0xF99BFFFF);
        break;
    }
}

void TObjEneGibbles::init_state() {
    u8 *self = (u8 *)this;
    u8 *temp_r3;

    ((TObjBase *)self)->set_position_from((void *) (self + 0x50));
    ((TObjCollidable *)self)->refresh_collision_body_centers();
    (this->actorFlags) = (s32) ((this->actorFlags) & 0xFFDFFFFF);
    (this->actorFlags) = (s32) ((this->actorFlags) | 0x06040000);
    temp_r3 = (unsigned char *) (this->bodies);
    *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) & 0xFFFFFFFE);
}

void TObjEneGibbles::update_wander() {
    f32 var_f1;
    f32 var_f2;
    f32 var_f3;
    s32 var_r5;
    s32 var_r6;
    u8 *var_r31;
    u8 *var_r3;
    u8 *var_r4;
    var_r31 = (u8 *)(this);
    this->advance_animation();
    if ((u32) *(u32 *)((s8 *)var_r31 + 0x2A8) != 0U) {
        var_r3 = (u8 *)((void *)3);
        *(s16 *)((s8 *)var_r31 + 0x326) = 3;
        var_r3 = var_r31;
        var_r4 = (u8 *)((void *)0x06240000);
        *(s16 *)((s8 *)var_r31 + 0x328) = 0;
        ((TObjBase *)var_r3)->obj_clearFlags30(0x06240000);
        *(s32 *)((s8 *)var_r31 + 0x374) = (s32) (*(s32 *)((s8 *)var_r31 + 0x374) & 0xFFFF0000);
        *(s32 *)((s8 *)var_r31 + 0x374) = (s32) (*(s32 *)((s8 *)var_r31 + 0x374) | 4);
        var_r3 = (u8 *)(*(u8 **)((s8 *)var_r31 + 0xA4));
        *(s32 *)((s8 *)var_r3 + 0x18) = (s32) (*(s32 *)((s8 *)var_r3 + 0x18) | 1);
    } else {
        *(s32 *)((s8 *)var_r31 + 0x374) = (s32) (*(s32 *)((s8 *)var_r31 + 0x374) & 0xFFFFFFFB);
    }
    var_f2 = 100.0f;
    var_r3 = var_r31;
    var_r4 = (u8 *)(*(u8 **)((s8 *)var_r31 + 0x350));
    var_f3 = var_f2;
    var_f1 = *(f32 *)((s8 *)var_r4 + 4);
    var_r4 = (u8 *)(*(u8 **)((s8 *)var_r4 + 8));
    ((TObjEnemy *)var_r3)->enemy_wander_home((f32)var_f1, (f32)var_f2, (f32)var_f3, (saddr)var_r4);
    var_r3 = var_r31;
    ((TObjCollidable *)var_r3)->refresh_collision_body_centers();
    var_r3 = var_r31;
    ((TObjPlayer *)var_r3)->check_object_collisions();
    var_r3 = var_r31;
    check_enemy_body_collisions((var_r3));
    var_r3 = var_r31;
    ((TObjPlayer *)var_r3)->update_enemy_collision_flags();
    var_r3 = var_r31;
    var_r4 = (u8 *)((void *)0x200000);
    ((TObjBase *)var_r3)->obj_clearFlags30(0x200000);
    var_r3 = var_r31;
    ((TObjEneGibbles *)var_r3)->play_ground_contact_sound();
    var_r3 = (u8 *)(var_r31 + 0x38);
    var_r4 = (u8 *)((void *)-0x5DB4);
    var_r5 = 1;
    var_r6 = 0;
    minimap_render_dot(var_r3, -0x5DB4, 1, 0);
    var_r3 = var_r31;
    var_r4 = (u8 *)((void *)-1);
    ((s32 (*)(int, int))submit_cursor_candidate)((saddr)var_r3, -1);
}

void TObjEneGibbles::sub_802DA7A4() {
    u8 *temp_r4;
    this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
    this->actorFlags = (s32) (this->actorFlags | 0x06040000);
    this->m_374 = (s32) (this->m_374 & ~0x107);
    temp_r4 = (unsigned char *) (this->bodies);
    *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFFFFFFFE);
    advance_animation();
    switch (this->phase) {
    default:
    case 0:
        this->phase = 1;
        this->requested_action = 5;
        this->m_38c = 0.0f;
        *(f32 *)&this->unk_390 = 16.483517f;
        apply_actor_gravity((TObjEnemy *)(this), (s32 *)(0), 0.0f);
        break;
    case 1:
        if (is_passing_frame(8.0f) != 0) {
            this->phase = 2;
            spawn_ground_contact_effect();
            play_sound_effect((int)(this->resolve_sound_id((u32)(0x3A82F))), (void *) (((u8 *)this) + 0x38), 0, 0);
            this->fade.reset_color();
        }
        apply_actor_gravity((TObjEnemy *)(this), (s32 *)(0), 0.0f);
        break;
    case 2:
        if (this->fade.decay_value_toward_floor() == 1) {
            this->phase = 3;
        } else {
            this->m_38c = (f32) (this->m_38c + *(f32 *)&this->unk_390);
            *(f32 *)&this->unk_390 = (f32) (*(f32 *)&this->unk_390 - 1.0989012f);
        }
        break;
    case 3:
        this->set_position_from((void *) (((u8 *)this) + 0x50));
        this->update_prev_position();
        this->scale.z = 1.0f;
        this->scale.y = 1.0f;
        this->scale.x = 1.0f;
        this->m_374 = (s32) (this->m_374 & 0xFFFF0000);
        this->m_374 = (s32) (this->m_374 | 1);
        break;
    }
    minimap_render_dot((void *) (((u8 *)this) + 0x38), -0x5DB4, 1, 0);
}

void TObjEneGibbles::run_move_action() {
  s32 temp_r4;
  void *temp_r3;
  void *temp_r3_2;
  switch (this->mode)
  {
    default:
      temp_r4 = this->m_374;
      if (temp_r4 & 4)
    {
      this->mode = 3;
      this->phase = 0;
      this->requested_action = 1;
      this->actorFlags = (s32) ((this->actorFlags) & 0xF9FBFFFF);
    }
    else
      if (temp_r4 & 1)
    {
      this->mode = 1;
      this->phase = 0;
      this->actorFlags = (s32) ((this->actorFlags) | 0x06040000);
    }
      temp_r3 = this->bodies;
      *((s32 *) (((s8 *) temp_r3) + 0x18)) = (s32) ((*((s32 *) (((s8 *) temp_r3) + 0x18))) | 1);
      return;

    case 1:
      if ((this->m_374) & 2)
    {
      this->mode = 2;
      this->phase = 0;
      this->actorFlags = (s32) ((this->actorFlags) | 0x06040000);
    }
      return;

    case 2:
      if ((this->m_374) & 4)
    {
      this->mode = 3;
      this->phase = 0;
      this->requested_action = 1;
      this->actorFlags = (s32) ((this->actorFlags) & 0xF9FBFFFF);
      return;
    }
      break;

    case 3:
      if ((this->m_374) & 3)
    {
      this->mode = 1;
      this->phase = 0;
      this->actorFlags = (s32) ((this->actorFlags) | 0x06040000);
      this->m_374 = (s32) ((this->m_374) & 0xFFFF0000);
      this->m_374 = (s32) ((this->m_374) | 1);
      temp_r3_2 = this->bodies;
      *((s32 *) (((s8 *) temp_r3_2) + 0x18)) = (s32) ((*((s32 *) (((s8 *) temp_r3_2) + 0x18))) | 1);
      return;
    }
      break;

  }

  return;
}

void TObjEneGibbles::update_spawn_state() {
    u8 *self = (u8 *)this;

    (this->actorFlags) = (s32) ((this->actorFlags) & 0xFFDFFFFF);
    (this->actorFlags) = (s32) ((this->actorFlags) | 0x06040000);
    *(s32 *)((s8 *)this->bodies + 0x18) = (s32) (*(s32 *)((s8 *)this->bodies + 0x18) & 0xFFFFFFFE);
    switch (this->phase) {
    case 0:
        this->phase = 1;
        apply_actor_gravity((TObjEnemy *)self, (s32 *)(0), 0.0f);
        return;
    case 1:
        if (horizontal_distance_squared((saddr) ((this->target) + 0x2FC), (void *) (self + 0x2FC)) < 40000.0f) {
            this->phase = 3;
        }
    case 2:
        return;
    case 3:
        this->m_374 = (s32) (this->m_374 & 0xFFFF0000);
        this->m_374 = (s32) (this->m_374 | 2);
        break;
    }
}

void TObjEneGibbles::update_death_sequence() {
    u8 *self = (u8 *)this;
    u8 *temp_r4;

    (this->actorFlags) = (s32) ((this->actorFlags) & 0xFFDFFFFF);
    (this->actorFlags) = (s32) ((this->actorFlags) | 0x06040000);
    temp_r4 = (unsigned char *) (this->bodies);
    *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFFFFFFFE);
    ((TObjMotion *)self)->advance_animation();
    switch (this->phase) {
    case 2:
        break;
    case 0:
        this->phase = 1;
        this->requested_action = 5;
        ((TUnk_80494938 *)((void *) (self + 0x3C0)))->start_fade_in();
        this->m_38c = 100.00001f;
        *(f32 *)&this->unk_390 = 1.0989012f;
        apply_actor_gravity((TObjEnemy *)(self), (s32 *)(0), 0.0f);
        break;
    case 1:
        if (((TObjEneGibbles *)self)->fade.advance_toward_max() != 0) {
            this->m_38c = (f32) (this->m_38c - *(f32 *)&this->unk_390);
            *(f32 *)&this->unk_390 += 1.0989012f;
        } else {
            this->frame = 22.0f;
        }
        if (((TObjMotion *)self)->is_passing_frame((this->frame_count - 1.0f) - this->play_speed) != 0) {
            this->m_38c = 0.0f;
            *(f32 *)&this->unk_390 = 0.0f;
            switch (sub_802D9A04()) {
            case 0:
                TObjEneGibbles__sub_800D8988((Vec *)(self + 0x38));
                break;
            default:
            case 1:
                play_sound_effect(((TObjEneGibbles *)self)->resolve_sound_id(0x3AD32), self + 0x38, 0, 0);
                break;
            }
            sub_802D7A54();
            this->phase = 3;
        }
        break;
    case 3:
        if (((TObjMotion *)self)->is_passing_frame((this->frame_count - 1.0f) - this->play_speed) != 0) {
            this->m_374 = (s32) (this->m_374 & 0xFFFF0000);
            this->m_374 = (s32) (this->m_374 | 4);
        }
        break;
    }
    minimap_render_dot((void *) (self + 0x38), -0x5DB4, 1, 0);
}

void TObjEneGibbles::sub_802DA0BC() {
    f32 d;
    s32 ok;
    *(u32 *)((s8 *)(this->bodies) + 0x18) |= 1;
    this->actorFlags &= 0xF9DBFFFF;
    if (this->target == NULL) {
        return;
    }
    switch (this->phase) {
    case 2:
        break;
    case 0: {
        Vec_802DA0BC v = *(Vec_802DA0BC *)(this->target + 0x2FC);
        if (select_enemy_destination(this, &v, 7) != 0) {
            this->phase = 1;
            {
                Vec_802DA0BC v2 = *(Vec_802DA0BC *)(((u8 *)this) + 0x2FC);
                copy_position_if_valid((saddr)this, (saddr)&v2);
            }
            apply_actor_gravity((TObjEnemy *)this, (s32 *)(0), 0.0f);
            *(f32 *)((s8 *)((u8 *)this) + 0x3A0) = 0.0f;
        } else {
            this->phase = 0;
            this->mode = 0xB;
            this->requested_action = 1;
            this->actorFlags &= 0xF99BFFFF;
        }
        break;
    }
    case 1:
        {
            f32 dt = *(f32 *)((s8 *)TObjEneGibbles__ai_parameters + 8);
            *(f32 *)((s8 *)((u8 *)this) + 0x3A0) += dt;
            Vec_802DA0BC v = *(Vec_802DA0BC *)(this->target + 0x2FC);
            enemy_move_toward(this, *(s32 *)((s8 *)(this->movementParameters) + 8), &v, 0, dt);
        }
        d = horizontal_distance_squared((saddr)(((u8 *)this) + 0x29C), ((u8 *)this) + 0x38);
        {
            Vec_802DA0BC v = *(Vec_802DA0BC *)(this->target + 0x2FC);
            ok = select_enemy_destination(this, &v, 1);
        }
        if (d >= 22500.0f && ok != 0) {
            this->m_374 |= 0x10;
        } else if (*(f32 *)((s8 *)((u8 *)this) + 0x3A0) >= 50.0f) {
            *(f32 *)((s8 *)((u8 *)this) + 0x3A0) = 0.0f;
            if (((TObjChara *)this)->random_ratio() < this->m_394 && ok != 0) {
                this->m_374 |= 0x10;
            } else {
                this->m_374 &= ~0x10;
            }
        } else {
            this->m_374 &= ~0x10;
        }
        {
            f32 r = *(f32 *)((s8 *)(this->movementParameters) + 4) + *(f32 *)((s8 *)(this->bodies) + 0xC);
            if (d < r * r) {
                this->phase = 3;
            }
        }
        break;
    case 3:
        this->m_374 &= ~0x10;
        this->phase = 0;
        break;
    }
    play_ground_contact_sound();
    advance_animation();
    turn_toward_target();
    this->check_object_collisions();
    check_enemy_body_collisions(this);
    this->update_enemy_collision_flags();
    minimap_render_dot(((u8 *)this) + 0x38, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
}

s32 TObjEneGibbles::is_target_in_attack_range() {
    u8 *self = (u8 *)this;
    Vec v;
    f32 rad;
    f32 dist;
    s32 ang;
    u8 *obj;
    u8 *sub;
    if (this->mode >= 3) {
        obj = this->target;
        if (obj != NULL && this->m_318 != 0 && !(*(s32 *)((s8 *)obj + 0x30) & 0x02000800)) {
            dist = calc_xz_distance_sq((saddr)self, (uaddr)obj, (void *)&v);
            ang = angle_difference_abs(this->rotation_y, (s32)(10430.38043493439 * atan2_float(v.x, v.z)));
            sub = *(u8 **)(this->target + 0xA4);
            if (sub != NULL) {
                rad = *(f32 *)((s8 *)sub + 0xC);
            } else {
                rad = 10.0f;
            }
            if (this->m_374 & 8) {
                this->m_37c = 2;
                if (dist <= (rad + ((AttackParams *)TGT_802D9EB4)->get_attack_range()) * (rad + ((AttackParams *)TGT_802D9EB4)->get_attack_range()) && ang <= ((AttackParams *)TGT_802D9EB4)->get_attack_angle()) {
                    return 1;
                }
            } else if (this->m_374 & 0x10) {
                this->m_37c = 1;
                if (dist <= (150.0f + rad) * (150.0f + rad) && ang <= 0xAAA) {
                    return 1;
                }
            } else {
                this->m_37c = 0;
                if (dist <= (rad + ((AttackParams *)TGT_802D9EB4)->get_attack_range()) * (rad + ((AttackParams *)TGT_802D9EB4)->get_attack_range()) && ang <= ((AttackParams *)TGT_802D9EB4)->get_attack_angle()) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void TObjEneGibbles::run_attack_action() {
    u8 *self = (u8 *)this;
    Vec v;
    switch (this->m_37c) {
    case 0:
    default: {
        VecCopy((Vec *)((Vec *) &v), (const Vec *)((Vec *) (this->target + 0x2FC)));
        subtract_vector(&v, (u8 *)&this->body_center);
        f64 t = atan2_float(v.x, v.z);
        this->mode = 4;
        if ((s32) (10430.38043493439 * t) < 0x10) {
            this->phase = 1;
            this->requested_action = 2;
        } else {
            this->phase = 0;
            this->requested_action = 1;
        }
        break;
    }
    case 2:
        this->mode = 5;
        this->phase = 0;
        this->requested_action = 3;
        break;
    case 1:
        this->mode = 6;
        this->phase = 0;
        this->requested_action = 4;
        this->m_374 = (s32) (this->m_374 & 0xFFFFFF7F);
        break;
    }
    ((TObjEnemy *)self)->bind_enemy_combat_stats((u8 *)(0), ((u8 **) gibbles_combat_stat_entries)[this->m_37c], (u8 *)(0));
    *(s32 *)((s8 *)(this->bodies) + 0x18) |= 1;
    this->actorFlags = (s32) (this->actorFlags & 0xF9FBFFFF);
    this->actorFlags = (s32) (this->actorFlags | 0x200000);
}

void TObjEneGibbles::slam_damage_players(s32 arg1) {
    Vec v;
    DirectAttackPayload a;
    f32 d;
    s32 i;
    u8 *p;
    saddr target = (saddr)this;

    if (arg1 == 0x35) {
        render_and_get_joint_pos(&v, 0x35);
    } else if (arg1 == 0x1F) {
        render_and_get_joint_pos(&v, 0x1F);
    } else {
        return;
    }
    v.y += 20.0f;
    if (csnVecterUnder(&v, 0x16EF) != 0) {
        if (((TObjEneGibbles *)target)->spawn_ground_impact_effects(&v, 2.0f) == 0) {
            v.y += 5.0f;
            spawn_particle_effect(&v, 0x64);
        }
        for (i = 0; i < lbl_805D5868; i++) {
            p = (u8 *)TObjPlayer::get_player_data(i);
            if (TObjPlayer::is_valid_and_active((uaddr)p) != 0 && get_entity_id(p) < 0x1000) {
                d = horizontal_distance_squared((saddr)(p + 0x2FC), &v);
                if (d <= ((AttackParams *)(*(void **)gibbles_combat_stat_entries))->get_damage_radius() * ((AttackParams *)(*(void **)gibbles_combat_stat_entries))->get_damage_radius()) {
                    a.kind = 0;
                    a.power = get_attack_params_atp_min(*(void **)gibbles_combat_stat_entries);
                    ((TObjChara *)p)->apply_knockback_from_attacker((u8 *)target, ((TObjChara *)p)->receive_direct_attack((void *)target, a, NULL, -1, -1));
                }
            }
        }
    }
}

#pragma push
#pragma opt_loop_invariants off
s32 TObjEneGibbles::sub_802D9A04() {
    s32 i;
    TObjPlayer *pl;

    for (i = 0; i < lbl_805D5868; i++) {
        pl = TObjPlayer::get_player_data(i);
        if (TObjPlayer::is_valid_and_active((uaddr)pl) != 0 && get_entity_id(pl) < 0x1000U) {
            f32 dist = horizontal_distance_squared((saddr)&pl->body_center, &position);
            if (dist <= ((AttackParams *)(*(void **)((s8 *)gibbles_combat_stat_entries + 4)))->get_damage_radius() * ((AttackParams *)(*(void **)((s8 *)gibbles_combat_stat_entries + 4)))->get_damage_radius()) {
                DirectAttackPayload attack;
                attack.kind = 0;
                attack.power = get_attack_params_atp_min(*(void **)((s8 *)gibbles_combat_stat_entries + 4));
                f32 res = pl->receive_direct_attack(this, attack, NULL, -1, -1);
                pl->apply_knockback_from_attacker((u8 *)this, res);
                if (res > 0.0f) {
                    obj_setFlags30(pl, 0x600);
                }
            }
        }
    }
    return spawn_ground_contact_effect();
}

extern "C" s32 TObjEneGibbles__sub_802D9824(void *self, s32 arg, f32 scale) {
    TObjEneGibbles *g;
    s32 done = 0;
    TObjCollidable **p;
    s32 i;

    if (actor_frame_tick % 5) {
        return 0;
    }
    ((TObjEneGibbles *)self)->render_and_get_joint_pos(&((TObjEneGibbles *)self)->attack_colliders[0]->position, 0x35);
    TObjPlayer::init_all_slots();
    p = ((TObjEneGibbles *)self)->attack_colliders;
    (*p)->check_object_collisions();
    if ((*p)->bodies->flags & 0x80000) {
        for (i = 0; i < 16; i++) {
            TObjChara *obj = (TObjChara *)TObjPlayer::get_battle_param(i);
            if (!obj) {
                break;
            }
            if (!obj_is_hit_receivable((u8 *)obj)) {
                continue;
            }
            g = (TObjEneGibbles *)self;
            if (obj->select_melee_contact_body(g, 1.0f) == 0) {
                continue;
            }
            if (scale <= 0.0f) {
                scale = obj->receive_physical_attack(g, 1.0f);
            } else {
                DirectAttackPayload h;
                h.kind = 0;
                h.power = scale;
                scale = obj->receive_direct_attack(g, h, 0, -1, -1);
            }
            obj->apply_knockback_from_attacker((u8 *)g, scale);
            if (arg == 1 && scale > 0.0f) {
                obj_setFlags30(obj, 0x600);
                g->m_388 = (s16)(g->m_388 + scale);
                g->m_380 = 0x10e;
            }
            done = 1;
        }
    }
    return done;
}

extern "C" s32 TObjEneGibbles__sub_802D9644(void *self, s32 arg, f32 scale) {
    TObjEneGibbles *g;
    s32 done = 0;
    TObjCollidable **p;
    s32 i;

    if (actor_frame_tick % 5) {
        return 0;
    }
    ((TObjEneGibbles *)self)->render_and_get_joint_pos(&((TObjEneGibbles *)self)->attack_colliders[0]->position, 0x1f);
    TObjPlayer::init_all_slots();
    p = ((TObjEneGibbles *)self)->attack_colliders;
    (*p)->check_object_collisions();
    if ((*p)->bodies->flags & 0x80000) {
        for (i = 0; i < 16; i++) {
            TObjChara *obj = (TObjChara *)TObjPlayer::get_battle_param(i);
            if (!obj) {
                break;
            }
            if (!obj_is_hit_receivable((u8 *)obj)) {
                continue;
            }
            g = (TObjEneGibbles *)self;
            if (obj->select_melee_contact_body(g, 1.0f) == 0) {
                continue;
            }
            if (scale <= 0.0f) {
                scale = obj->receive_physical_attack(g, 1.0f);
            } else {
                DirectAttackPayload h;
                h.kind = 0;
                h.power = scale;
                scale = obj->receive_direct_attack(g, h, 0, -1, -1);
            }
            obj->apply_knockback_from_attacker((u8 *)g, scale);
            if (arg == 1 && scale > 0.0f) {
                obj_setFlags30(obj, 0x600);
                g->m_388 = (s16)(g->m_388 + scale);
                g->m_380 = 0x10e;
            }
            done = 1;
        }
    }
    return done;
}

void TObjEneGibbles::sub_802D9110() {
    bodies->flags |= 1;
    actorFlags &= 0xF9FBFFFF;
    u16 id = targetId;
    if (id < 0x1000) {
        TObjPlayer *p = get_player_by_client_id(id);
        if (p != NULL && p->get_floor() == get_current_floor()) {
            target = (u8 *)p;
        } else {
            target = NULL;
        }
    } else if (id < 0x4000) {
        target = get_enemy_entity(id);
    } else {
        targetId = 0xFFFF;
        target = NULL;
    }
    switch (phase) {
    case 0:
        if (target == NULL) {
            phase = 0;
            actorFlags &= 0xFFDFFFFF;
            resetTimer = 0;
        } else {
            Vec d;
            s32 diff;
            VecCopy(&d, &((TObjChara *)target)->body_center);
            subtract_vector(&d, &body_center);
            diff = turn_toward_direction(((GibblesMoveParams *)movementParameters)->turn_speed, &d);
            if (!(actorFlags & 0x800000)) {
                apply_actor_gravity(this, (s32 *)(0), 0.0f);
            }
            if (diff < 0x10) {
                m_374 |= 0x100;
                phase = 1;
                requested_action = 2;
                if (check_path_obstructed(this, &((TObjChara *)target)->body_center) == 1) {
                    velocity.x = velocity.y = velocity.z = 0.0f;
                } else {
                    ((void (*)(void *, Vec, Vec, f32))calc_velocity_toward_destination)(this, body_center, ((TObjChara *)target)->body_center, ((GibblesMoveParams *)movementParameters)->speed);
                }
            }
        }
        break;
    case 1:
        requested_action = 2;
        if (is_passing_frame(5.0f) != 0) {
            phase = 2;
            play_sound_effect(resolve_sound_id((u32)(0x3AD34)), &position, 0, 0);
        }
        break;
    case 2:
        requested_action = 2;
        if (is_passing_frame(8.0f) != 0) {
            slam_damage_players(0x1F);
        } else {
            TObjEneGibbles__sub_802D9644(this, 0, 0.0f);
        }
        if (13.0f <= frame && frame <= 19.0f) {
            sub_802D8034();
        }
        if (is_passing_frame(15.0f) != 0) {
            phase = 3;
        }
        break;
    case 3:
        requested_action = 2;
        move_with_wall_slide((u8 *)this);
        if (is_passing_frame(19.0f) != 0) {
            phase = 4;
            play_sound_effect(resolve_sound_id((u32)(0x3AD34)), &position, 0, 0);
        }
        break;
    case 4:
        requested_action = 2;
        if (is_passing_frame(23.0f) != 0) {
            slam_damage_players(0x35);
        } else {
            TObjEneGibbles__sub_802D9824(this, 0, 0.0f);
        }
        if (24.0f <= frame && frame <= 34.0f) {
            sub_802D8034();
        }
        if (is_passing_frame(31.0f) != 0) {
            phase = 5;
        }
        break;
    case 5:
        requested_action = 2;
        move_with_wall_slide((u8 *)this);
        if (is_passing_frame(38.0f) != 0) {
            phase = 6;
            play_sound_effect(resolve_sound_id((u32)(0x3AD34)), &position, 0, 0);
        }
        break;
    case 6:
        requested_action = 2;
        if (is_passing_frame(40.0f) != 0) {
            slam_damage_players(0x1F);
        } else {
            TObjEneGibbles__sub_802D9644(this, 0, 0.0f);
        }
        if (43.0f <= frame && frame <= 54.0f) {
            sub_802D8034();
        }
        if (is_passing_frame((frame_count - 1.0f) - play_speed) != 0) {
            requested_action = 0;
            phase = 7;
            resetTimer = (s16)*(f32 *)(TObjEneGibbles__ai_parameters + 4);
        }
        break;
    case 7:
        if (--resetTimer < 0) {
            requested_action = 1;
            phase = 0;
            actorFlags &= 0xFFDFFFFF;
            resetTimer = 0;
            m_374 &= ~0x100;
        }
        break;
    }
    play_distance_sound();
    advance_animation();
    clamp_angle(0);
    ((TObjPlayer *)this)->check_object_collisions();
    check_enemy_body_collisions(this);
    ((TObjPlayer *)this)->update_enemy_collision_flags();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
}

void TObjEneGibbles::sub_802D8E8C() {
    TObjPlayer *p;
    u16 id;
    id = targetId;
    if (id < 0x1000) {
        p = get_player_by_client_id(id);
        if (p != NULL && p->get_floor() == get_current_floor()) {
            target = (u8 *)p;
        } else {
            target = NULL;
        }
    } else if (id < 0x4000) {
        target = get_enemy_entity(id);
    } else {
        targetId = 0xFFFF;
        target = NULL;
    }
    bodies->flags |= 1;
    actorFlags &= 0xF9FBFFFF;
    play_ground_contact_sound();
    advance_animation();
    clamp_angle(0);
    switch (phase) {
    case 0:
        phase = 1;
        apply_actor_gravity(this, (s32 *)(0), 0.0f);
        m_374 |= 0x100;
        play_sound_effect(resolve_sound_id((u32)(0x3AD2E)), &position, 0, 0);
        break;
    case 1:
    case 2:
        if (!(actorFlags & 0x800000)) {
            apply_actor_gravity(this, (s32 *)(0), 0.0f);
        }
        if (is_passing_frame(10.0f) != 0) {
            play_sound_effect(resolve_sound_id((u32)(0x3A82D)), &body_center, 0, 0);
        }
        if (is_passing_frame(24.0f) != 0) {
            phase = 2;
        }
        if (phase == 1) {
            TObjEneGibbles__sub_802D9644(this, 1, get_attack_params_atp_min(*(void **)((s8 *)gibbles_combat_stat_entries + 8)));
        }
        if (action_flags != 4) {
            phase = 3;
            combo_count++;
        }
        break;
    case 3:
        update_move_state();
        if (combo_count >= 2) {
            combo_count = 0;
            m_374 &= ~0x108;
        }
        actorFlags &= 0xFFDFFFFF;
        break;
    }
    ((TObjPlayer *)this)->check_object_collisions();
    check_enemy_body_collisions(this);
    ((TObjPlayer *)this)->update_enemy_collision_flags();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
}
void TObjEneGibbles::sub_802D8984() {
    Gib_802D8984 *o = (Gib_802D8984 *)this;
    if (o->idx < 0x1000) {
        Gib_802D8984 *p = (Gib_802D8984 *)get_player_by_client_id(o->idx);
        if (p != NULL && ((TObjPlayer *)p)->get_floor() == get_current_floor()) {
            o->target = p;
        } else {
            o->target = NULL;
        }
    } else if (o->idx < 0x4000) {
        o->target = (Gib_802D8984 *)get_enemy_entity(o->idx);
    } else {
        o->idx = 0xFFFF;
        o->target = NULL;
    }
    ((TObjMotion *)o)->advance_animation();
    ((TObjEneGibbles *)o)->clamp_angle(0);
    switch (o->sub) {
    case 2:
        break;
    case 0:
        o->f38C = 0.0f;
        if (!(o->f30 & 0x800000)) {
            apply_actor_gravity((TObjEnemy *)((u8 *)o), (s32 *)(0), 0.0f);
        }
        o->f3A4 = 0;
        if (o->f374 & 0x80) {
            o->f3A8 = PRM->f18;
            TObjEneGibbles::set_min_clamped_entry_value((saddr)o, 6, PRM->fC);
        } else {
            o->f3A8 = PRM->f18;
            TObjEneGibbles::set_min_clamped_entry_value((saddr)o, 6, PRM->fC);
        }
        o->sub = 4;
        o->f30 &= 0xF9FFFFFF;
        o->f374 &= ~0x80;
        o->f374 |= 0x100;
        break;
    case 4:
        o->f3A4++;
        if (o->f3A4 >= o->f3A8) {
            if (o->target != NULL) {
                Vec v;
                Vec_802DA0BC t = o->target->f2FC;
                if (select_enemy_destination(o, &t, 1) != 0) {
                    f32 dist;
                    o->sub = 1;
                    {
                        Vec_802DA0BC q = o->f2FC;
                        copy_position_if_valid((saddr)o, (saddr)&q);
                    }
                    VecCopy((Vec *)&v, (const Vec *)((Vec *)&o->f29C));
                    subtract_vector(&v, &o->f2FC);
                    dist = newton_sqrtf(v.x * v.x + v.z * v.z);
                    dist -= 15.0f;
                    calc_velocity_toward_destination(o, o->f290, o->f29C, 0.026923077f * dist);
                    play_sound_effect(((TObjEneGibbles*)(o))->resolve_sound_id((u32)(0x3A82F)), &o->pos, 0, 0);
                    o->f390 = 12.5f;
                    o->fB8 = 5;
                    o->f30 |= 0x06000000;
                    o->fA4->f18 &= ~1;
                    goto done;
                }
            }
            enemy_set_heading_velocity(0.0f, (TObjEnemy *)(o), o->angle);
            o->f374 &= ~0x100;
            o->mode = 3;
            o->sub = 0;
            o->fB8 = 1;
            o->f30 &= 0xF9FBFFFF;
        done:
            ((TObjEneGibbles *)o)->spawn_ground_contact_effect();
        }
        submit_cursor_candidate(o, -1);
        break;
    case 1:
        if (o->fC0 >= 8.0f) {
            move_with_wall_slide((u8 *)o);
            o->f38C += o->f390;
            if (o->fC0 >= 25.0f) {
                o->f390 -= 1.0989012f;
            } else {
                o->f390 -= 0.5f;
            }
        }
        if (((TObjMotion *)o)->is_passing_frame(o->fC4 - 1.0f - o->fC8) != 0) {
            o->sub = 3;
            o->f38C = 0.0f;
            switch (sub_802D9A04()) {
            case 0:
                TObjEneGibbles__sub_800D8988(&o->pos);
                break;
            case 1:
            default:
                play_sound_effect(((TObjEneGibbles*)(o))->resolve_sound_id((u32)(0x3AD32)), &o->pos, 0, 0);
                break;
            }
            o->f30 &= 0xF9FFFFFF;
            o->fA4->f18 |= 1;
            o->f374 &= ~0x10;
            o->fB8 = 6;
            sub_802D7A54();
        }
        break;
    case 3:
        if (!(o->f30 & 0x800000)) {
            apply_actor_gravity((TObjEnemy *)((u8 *)o), (s32 *)(0), 0.0f);
        }
        if (((TObjMotion *)o)->is_passing_frame(o->fC4 - 1.0f - o->fC8) != 0) {
            o->f30 &= ~0x200000;
            enemy_set_heading_velocity(0.0f, (TObjEnemy *)(o), o->angle);
            o->f374 &= ~0x100;
            o->mode = 3;
            o->sub = 0;
            o->fB8 = 1;
            o->f30 &= 0xF9FBFFFF;
        }
        submit_cursor_candidate(o, -1);
        break;
    }
    minimap_render_dot(&o->pos, -0x5DB4, 1, 0);
}

#pragma pop
int TObjEneGibbles::test_flag_256() {
    u8 *self = (u8 *)this;
    Vec v;
    u8 *pl;
    s32 i;
    s32 flags;
    flags = this->m_374;
    if (flags & 0x20) {
        return 1;
    }
    if ((flags & 4) && this->mode != 6 && this->m_388 > 0) {
        for (i = 0; i < registered_player_count; i++) {
            pl = (u8 *)TObjPlayer::get_player_data(i);
            if (pl != NULL && !(((TObjPlayer *)pl)->actorFlags & 0x800)
                && calc_distance_to_client__10TObjPlayerFlUsUl(self, i, &v) < 900.0f
                && angle_difference_abs(this->rotation_y, (s32) (10430.38043493439 * atan2_float(v.x, v.z))) < 0x2AAA
                && ((TObjPlayer *)pl)->test_action_mask(0xE0) != 0) {
                VecCopy((Vec *)((Vec *) &v), (const Vec *)((Vec *) (self + 0x2FC)));
                subtract_vector(&v, pl + 0x2FC);
                if (angle_difference_abs(((TObjPlayer *)pl)->rotation_y, (s32) (10430.38043493439 * atan2_float(v.x, v.z))) < 0x2AAA) {
                    this->m_3b0 = pl;
                    this->m_374 |= 0x20;
                    return 1;
                }
            }
        }
    }
    return 0;
}

void TObjEneGibbles::run_miss_reaction() {
    s16 temp_r0;
    void *temp_r5;

    temp_r0 = this->mode;
    if ((temp_r0 != 7) && (temp_r0 != 6)) {
        this->mode = 7;
        this->phase = 0;
        this->requested_action = 7;
    }
    temp_r5 = this->bodies;
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) | 1);
    this->actorFlags = (s32) (this->actorFlags & 0xF99BFFFF);
}

#pragma push
#pragma fp_contract on
void TObjEneGibbles::sub_802D8580() {
    this->advance_animation();
    this->clamp_angle(0);
    if (!(this->actorFlags & 0x800000)) {
        apply_actor_gravity(this, (s32 *)0, 0.0f);
    }
    switch (this->phase) {
    case 0:
        this->phase = 1;
        apply_actor_gravity(this, (s32 *)0, 0.0f);
        if (this->m_3b0 != NULL) {
            this->m_388 = (s16)((f32)this->m_388 - 0.2f * (f32)(((TObjPlayer *)this->m_3b0)->get_field_2c8() + ((TObjChara *)this->m_3b0)->get_actor_attack_params_atp_min() + TObjPlayer__sub_800A776C(this->m_3b0) - *(s16 *)((u8 *)this + 0x2CE)));
            if (this->m_388 <= 0) {
                this->m_388 = 0;
                this->m_374 |= 8;
            }
        }
        this->actorFlags |= 0x04000000;
        play_sound_effect(this->resolve_sound_id(0x3A330), (u8 *)this + 0x38, 0, 0);
        break;
    case 1:
        if (this->is_passing_frame(5.0f) != 0) {
            this->m_380 = 0x107;
        }
        if (this->is_passing_frame(12.0f) != 0) {
            this->actorFlags &= 0xFBFFFEFF;
            this->m_374 &= ~0x20;
            if (this->test_flag_256() != 0) {
                this->phase = 0;
                this->frame = 0.0f;
            } else {
                this->phase = 3;
            }
            this->update_move_state();
        }
        break;
    case 3:
    default:
        this->actorFlags &= 0xFBFFFEFF;
        this->m_374 &= ~0x20;
        break;
    }
    ((TObjPlayer *)this)->check_object_collisions();
    check_enemy_body_collisions(this);
    ((TObjPlayer *)this)->update_enemy_collision_flags();
    minimap_render_dot((u8 *)this + 0x38, -0x5DB4, 1, 0);
    this->actorFlags &= 0xFFDFFFFF;
}

#pragma pop
void TObjEneGibbles::run_hit_reaction() {
    if (this->mode != 8) {
        if (this->m_374 & 0x100) {
            s32 i;
            this->referenceHp = this->hp;
            this->actorFlags &= ~0x200;
            this->m_2dc = 0;
            for (i = 0; i < this->body_count; i++) {
                bodies[i].flags &= ~0x04000000;
            }
        } else {
            Vec v;
            TObjPlayer *pl = get_player_by_client_id(this->attacker_id);
            if (pl != NULL) {
                VecCopy(&v, &pl->body_center);
                subtract_vector(&v, (u8 *)this + 0x2FC);
                angle_difference_abs(this->rotation_y, (s32) (10430.38043493439 * atan2_float(v.x, v.z)));
            }
            this->mode = 8;
            this->requested_action = 8;
            this->phase = 0;
            this->actorFlags &= 0xF9DBFFFF;
        }
    }
    bodies->flags |= 1;
}

void TObjEneGibbles::update_action_state() {
    u8 *self = (u8 *)this;
    u8 *temp_r4;

    advance_animation();
    clamp_angle(0);
    switch (this->phase) {
    case 2:
        break;
    case 0:
        this->phase = 1;
        apply_actor_gravity((TObjEnemy *)(self), (s32 *)(0), 0.0f);
        play_sound_effect(((TObjEneGibbles*)((void *)((void *)(self))))->resolve_sound_id((u32)(0x3AD34)), (void *) (self + 0x38), 0, 0);
        break;
    case 1:
        this->velocity.z = 0.0f;
        this->velocity.x = 0.0f;
        apply_actor_gravity((TObjEnemy *)(self), (s32 *)(0), 0.0f);
        if ((u32) this->action_flags != 8U) {
            this->phase = 3;
        }
        break;
    case 3:
        if (!((this->actorFlags) & 0x800000)) {
            apply_actor_gravity((TObjEnemy *)(self), (s32 *)(0), 0.0f);
        }
        (this->actorFlags) = (s32) ((this->actorFlags) & 0xFFFFF9FF);
        temp_r4 = (unsigned char *) (this->bodies);
        *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFBFFFFFF);
        this->referenceHp = (s16) this->hp;
        if (((TObjChara *)self)->random_ratio() < *(f32 *)&this->unk_398) {
            this->mode = 6;
            this->phase = 0;
            this->requested_action = 4;
            this->m_374 = (s32) (this->m_374 | 0x90);
        }
        break;
    }
    ((TObjPlayer *)self)->check_object_collisions();
    check_enemy_body_collisions((self));
    ((TObjPlayer *)self)->update_enemy_collision_flags();
    minimap_render_dot((void *) (self + 0x38), -0x5DB4, 1, 0);
    submit_cursor_candidate(self, -1);
    (this->actorFlags) = (s32) ((this->actorFlags) & 0xFFDFFFFF);
}

void TObjEneGibbles::run_death_reaction() {
    void *temp_r4;

    if ((s16) this->mode != 9) {
        this->mode = 9;
        this->phase = 0;
        this->requested_action = 9;
        temp_r4 = this->bodies;
        *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFFFFFFFE);
        ((TObjPlayer *)this)->refresh_lobby_state();
        send_entity_set_flags();
    }
}

void TObjEneGibbles::sub_802D8140() {
  Vec stack;
  switch (this->phase)
  {
    case 0:
      this->phase = 1;
      *((f32 *) (((s8 *) ((u8 *)this)) + 0x3A0)) = 0.0f;
      apply_actor_gravity((TObjEnemy *)this, (s32 *)(0), 0.0f);
      play_sound_effect(this->resolve_sound_id(0x3A333), &position, 0, 0);
      return;
    case 1:
      advance_animation();
      if ((this->motion_flags) & 0x10)
    {
      this->phase = 4;
      stack.x = 0.0f;
      stack.y = 0.0f;
      stack.z = -10.0f;
      rotate_xz_pair_by_angle(&stack.x, &stack.z, this->rotation_y, 0.0f);
      vec3_add_to(&stack.x, ((u8 *)this) + 0x38);
      TObjPlayer__sub_800D93C4((saddr)&stack.x, 0xA);
      ((TObjPlayer *)(&stack.x))->spawn_effect_at_ground(0x46);
    }
    case 2:
      return;
    case 4:
      *((f32 *) (((s8 *) ((u8 *)this)) + 0x3C)) = (f32) ((*((f32 *) (((s8 *) ((u8 *)this)) + 0x3C))) - 0.1f);
      *((f32 *) (((s8 *) ((u8 *)this)) + 0x3A0)) += 0.1f;
      if ((*((f32 *) (((s8 *) ((u8 *)this)) + 0x3A0))) > 25.0f)
    {
      this->phase = 3;
      return;
    }
      break;
    case 3:
      queue_destruction();
      break;
    return;
  }
}

void TObjEneGibbles::update_move_state() {
    s16 temp_r0;
    s16 temp_r6;

    temp_r0 = *(s16 *)&this->unk_38A;
    temp_r6 = this->m_388;
    if (temp_r0 == temp_r6) {
        this->m_380 = 0x101;
        return;
    }
    if ((0.5f * (f32) temp_r0) < (f32) temp_r6) {
        this->m_380 = 0x102;
        return;
    }
    if (temp_r6 > 0) {
        this->m_380 = 0x103;
        return;
    }
    this->m_380 = 0;
}

void TObjEneGibbles::sync_state() {
    s32 temp_r3;

    switch (this->m_380) {
    case 0x0:
        break;
    default:
        update_move_state();
    case 0x107:
    case 0x10E:
        if (this->m_374 & 4) {
            if ((s32) *(s32 *)&this->unk_384 != (s32) this->m_380) {
                *(s32 *)&this->unk_384 = this->m_380;
            }
        }
        break;
    }
}

void TObjEneGibbles::sub_802D8034() {}

u32 TObjEneGibbles::resolve_sound_id(u32 sound_id) {
  s32 area;
  u32 pvVar2;
  area = get_current_floor_area();
  if (sound_id == 0x3a83d) {
    pvVar2 = (u32)(0x4003a321);
    if (area != AREA_TOWER) {
      pvVar2 = sound_id;
    }
  }
  else if (sound_id == 0x3a83e) {
    pvVar2 = (u32)(0x4003a322);
    if (area != AREA_TOWER) {
      pvVar2 = sound_id;
    }
  }
  else if (sound_id == 0x3a83f) {
    pvVar2 = (u32)(0x4003a323);
    if (area != AREA_TOWER) {
      pvVar2 = sound_id;
    }
  }
  else {
    pvVar2 = (u32)(this->remap_sound_for_area((s32)(sound_id)));
  }
  return pvVar2;
}

void TObjEneGibbles::render_and_get_joint_pos(Vec *out, s32 node) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_802D7ED4, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_802D7ED4, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_802D7ED4, sp10) == 0x8);
    Stack_802D7ED4 stack;
    set_motion_packed_rotation();
    push_matrix_from((void *) (&identity_matrix.value));
    post_translate_matrix(&position);
    rotate_matrix_y(0, rotation_y);
    scale_matrix_vec3(NULL, (u8 *)&scale);
    set_motion_packed_rotation();
    calc_joint_matrices(frame);
    clear_motion_packed_rotation();
    pop_matrix();
    push_matrix_from(anim_model_matrix_array[node]);
    stack.sp8 = *(s32 *)((s8 *)(&gibbles_joint_zero_vec.value) + 0);
    stack.spC = *(s32 *)((s8 *)(&gibbles_joint_zero_vec.value) + 4);
    stack.sp10 = *(s32 *)((s8 *)(&gibbles_joint_zero_vec.value) + 8);
    matrix_mult_vec(0, (void *) (&stack.sp8), out);
    pop_matrix();
    clear_motion_packed_rotation();
}
void TObjEneGibbles::update_position() {
    u8 *self = (u8 *)this;

    VecCopy((Vec *)(self + 0x2FC), &this->position);
    this->body_center.y += 15.0f;
    switch (this->mode) {
    case 2:
    case 6:
    case 0xA:
        this->body_center.y = (f32) (this->body_center.y + this->m_38c);
        break;
    }
}

void TObjEneGibbles::update_shadow_height() {
    *(f32 *)((s8 *)this->bodies + 4) = (f32) (this->body_center.y - this->position.y);
}

void TObjEneGibbles::sub_802D7E3C() {}

void TObjEneGibbles::play_ground_contact_sound() {
    if (is_passing_frame(7.0f) != 0 || is_passing_frame(20.0f) != 0) {
        if (spawn_ground_impact_effects(&position, 3.0f) != 0) {
            TObjEneGibbles__sub_800D8988(&position);
            return;
        }
        play_sound_effect(resolve_sound_id(0x3A82B), &position, 0, 0);
    }
}

void TObjEneGibbles::play_distance_sound() {
    if (is_passing_frame(8.0f) != 0) {
        if (spawn_ground_impact_effects(&position, 3.0f) != 0) {
            TObjEneGibbles__sub_800D8988(&position);
            return;
        }
        play_sound_effect(resolve_sound_id(0x3A83D), &position, 0, 0);
        return;
    }
    if (is_passing_frame(23.0f) != 0) {
        if (spawn_ground_impact_effects(&position, 3.0f) != 0) {
            TObjEneGibbles__sub_800D8988(&position);
            return;
        }
        play_sound_effect(resolve_sound_id(0x3A83E), &position, 0, 0);
        return;
    }
    if (is_passing_frame(40.0f) != 0) {
        if (spawn_ground_impact_effects(&position, 3.0f) != 0) {
            TObjEneGibbles__sub_800D8988(&position);
            return;
        }
        play_sound_effect(resolve_sound_id(0x3A83F), &position, 0, 0);
    }
}

s32 TObjEneGibbles::spawn_ground_contact_effect() {
    Vec point;
    VecCopy(&point, &position);
    point.y += 15.0f;
    CsnHit *hit = csnVectorUnder(&point, (CsnGroup **)&m_120, 0x15);
    if (hit != NULL) {
        if (hit->hit_mask & 4) {
            spawn_ground_impact_effects(&position, 3.0f);
            return 0;
        }
        spawn_particle_effect(&position, 0x20E);
        return 1;
    }
    return 2;
}

s32 TObjEneGibbles::spawn_ground_impact_effects(const Vec *pos, f32 scale) {
    Vec point;
    if (scale <= 0.0f) {
        return 0;
    }
    VecCopy(&point, pos);
    point.y += 15.0f;
    CsnHit *hit = csnVectorUnder(&point, (CsnGroup **)&m_120, 5);
    if (hit != NULL && (hit->hit_mask & 4) != 0) {
        TParticleCtrl *spray = (TParticleCtrl *)spawn_particle_effect(&hit->contact[2].point, 0x49);
        if (spray != NULL) {
            attach_particle_model((u8 *)spray, TParticleCtrl::get_particle_model(2),
                                  TParticleCtrl::get_instance(), 0, 1, 1.0f);
            spray->set_scale(scale, 1.0f);
        }
        TParticleCtrl *ripple = (TParticleCtrl *)spawn_particle_effect(&hit->contact[2].point, 0xA4);
        if (ripple != NULL) {
            ripple->set_scale(scale, 1.5f);
        }
        return 1;
    }
    return 0;
}

void TObjEneGibbles::sub_802D7A54() {
    s16 t;
    s16 u;
    TObjPlayer *r;
    if ((get_main_phase() == 0xF || is_split_screen() == 0) && (r = get_player_by_client_id(local_client_id)) != 0) {
        t = (s32)((TObjBase *)r)->get_room();
        u = (s32)get_room();
        if (u == t) {
            start_camera_shake(0x1E, 0.1f);
        }
    }
}
void TObjEneGibbles::set_min_clamped_entry_value(s32 arg0, s32 arg1, f32 fC) {
  f32 var_f1;
  var_f1 = fC;
  if (var_f1 < 0.1f)
  {
    var_f1 = 0.1f;
  }
  gibbles_action_table[arg1].speed = var_f1;
}

