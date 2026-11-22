#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/npc/NpcModelRegistry.h"
#include "types.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/enemy/panarms/TObjEnePanarms_800DCEB8.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/TObjEnemy.h"

#include <dolphin/mtx.h>
#include <stddef.h>
#include "pso/boss/darkfalz/TBoss4Type2.h"

#include "pso/enemy/TObjEnePanBARA.h"
#include "pso/enemy/panarms/TObjEnePanarmsAtkColli.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/darkfalz/TObjDFDemo5.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_80086B64.h"
#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/camera/TCameraCtrl.h"


#include "pso/render/RenderFadeState.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_80086D50.h"
#include "pso/render/BlobShadow.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/MatrixVector.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"


struct Stack_800DDFDC
{
  s32 sp8;
  f32 spC;
};

struct Stack_800DD9A0 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    s32 sp14;
    f32 sp18;
};

struct Obj_800DECC4 { u8 pad[0x38]; Vec pos; u8 pad2[0x248 - 0x44]; u8 f248[0x384 - 0x248]; f32 f384; };




struct Obj_800DE9F0 { u8 pad0[0x1C]; u16 f1C; };


extern const char bm7_s_paa_body_model_filename[] = "bm7_s_paa_body.nj";
extern const char bm7_s_pal_body_model_filename[] = "bm7_s_pal_body.nj";
extern const char bm7_s_par_body_model_filename[] = "bm7_s_par_body.nj";
extern const char atack_bm7_s_pal_body_motion_filename[] = "atack_bm7_s_pal_body.njm";
extern const char atack_bm7_s_par_body_motion_filename[] = "atack_bm7_s_par_body.njm";
extern const char beamdwn_bm7_s_paa_body_motion_filename[] = "beamdwn_bm7_s_paa_body.njm";
extern const char beamup_bm7_s_paa_body_motion_filename[] = "beamup_bm7_s_paa_body.njm";
extern const char btamed_bm7_s_paa_body_motion_filename[] = "btamed_bm7_s_paa_body.njm";
extern const char btameu_bm7_s_paa_body_motion_filename[] = "btameu_bm7_s_paa_body.njm";
extern const char bunri_bm7_s_pal_body_motion_filename[] = "bunri_bm7_s_pal_body.njm";
extern const char bunri_bm7_s_par_body_motion_filename[] = "bunri_bm7_s_par_body.njm";
extern const char cry_bm7_s_paa_body_motion_filename[] = "cry_bm7_s_paa_body.njm";
extern const char damage_bm7_s_paa_body_motion_filename[] = "damage_bm7_s_paa_body.njm";
extern const char damage_bm7_s_pal_body_motion_filename[] = "damage_bm7_s_pal_body.njm";
extern const char damage_bm7_s_par_body_motion_filename[] = "damage_bm7_s_par_body.njm";
extern const char deada_bm7_s_paa_body_motion_filename[] = "deada_bm7_s_paa_body.njm";
extern const char deada_bm7_s_pal_body_motion_filename[] = "deada_bm7_s_pal_body.njm";
extern const char deada_bm7_s_par_body_motion_filename[] = "deada_bm7_s_par_body.njm";
extern const char deadb_bm7_s_paa_body_motion_filename[] = "deadb_bm7_s_paa_body.njm";
extern const char deadb_bm7_s_pal_body_motion_filename[] = "deadb_bm7_s_pal_body.njm";
extern const char deadb_bm7_s_par_body_motion_filename[] = "deadb_bm7_s_par_body.njm";
extern const char gattai_bm7_s_pal_body_motion_filename[] = "gattai_bm7_s_pal_body.njm";
extern const char gattai_bm7_s_par_body_motion_filename[] = "gattai_bm7_s_par_body.njm";
extern const char heal_bm7_s_pal_body_motion_filename[] = "heal_bm7_s_pal_body.njm";
extern const char run_bm7_s_pal_body_motion_filename[] = "run_bm7_s_pal_body.njm";
extern const char run_bm7_s_par_body_motion_filename[] = "run_bm7_s_par_body.njm";
extern const char wait_bm7_s_paa_body_motion_filename[] = "wait_bm7_s_paa_body.njm";
extern const char wait_bm7_s_pal_body_motion_filename[] = "wait_bm7_s_pal_body.njm";
extern const char wait_bm7_s_par_body_motion_filename[] = "wait_bm7_s_par_body.njm";
extern const char walk_bm7_s_paa_body_motion_filename[] = "walk_bm7_s_paa_body.njm";
extern const char walk_bm7_s_pal_body_motion_filename[] = "walk_bm7_s_pal_body.njm";
extern const char walk_bm7_s_par_body_motion_filename[] = "walk_bm7_s_par_body.njm";
extern const char walkl_bm7_s_paa_body_motion_filename[] = "walkl_bm7_s_paa_body.njm";
extern const char walkr_bm7_s_paa_body_motion_filename[] = "walkr_bm7_s_paa_body.njm";
extern const char bm7_s_paa_body_bml_filename[] = "bm7_s_paa_body.bml";
extern const char TObjEnePanarms__class_name[] = "TObjEnePanarms";
const char *TObjEnePanarms__name = TObjEnePanarms__class_name;
BmlResource *TObjEnePanarms__entry_params_resource;

const char *bm7_s_paa_body_model_names[4] = {
    bm7_s_paa_body_model_filename, bm7_s_pal_body_model_filename, bm7_s_par_body_model_filename, NULL,
};
const char *bm7_s_paa_body_motion_names[32] = {
    atack_bm7_s_pal_body_motion_filename, atack_bm7_s_par_body_motion_filename, beamdwn_bm7_s_paa_body_motion_filename, beamup_bm7_s_paa_body_motion_filename,
    btamed_bm7_s_paa_body_motion_filename, btameu_bm7_s_paa_body_motion_filename, bunri_bm7_s_pal_body_motion_filename, bunri_bm7_s_par_body_motion_filename,
    cry_bm7_s_paa_body_motion_filename, damage_bm7_s_paa_body_motion_filename, damage_bm7_s_pal_body_motion_filename, damage_bm7_s_par_body_motion_filename,
    deada_bm7_s_paa_body_motion_filename, deada_bm7_s_pal_body_motion_filename, deada_bm7_s_par_body_motion_filename, deadb_bm7_s_paa_body_motion_filename,
    deadb_bm7_s_pal_body_motion_filename, deadb_bm7_s_par_body_motion_filename, gattai_bm7_s_pal_body_motion_filename, gattai_bm7_s_par_body_motion_filename,
    heal_bm7_s_pal_body_motion_filename, run_bm7_s_pal_body_motion_filename, run_bm7_s_par_body_motion_filename, wait_bm7_s_paa_body_motion_filename,
    wait_bm7_s_pal_body_motion_filename, wait_bm7_s_par_body_motion_filename, walk_bm7_s_paa_body_motion_filename, walk_bm7_s_pal_body_motion_filename,
    walk_bm7_s_par_body_motion_filename, walkl_bm7_s_paa_body_motion_filename, walkr_bm7_s_paa_body_motion_filename,
    NULL,
};
BmlResourceDescriptor lbl_80494F10 = {
    bm7_s_paa_body_bml_filename, bm7_s_paa_body_model_names, bm7_s_paa_body_motion_names, 3, 31,
};
/* The body's one collision sphere (init_collision_body_parts in the constructor). */
CollisionBody panarms_collision_body[1] = {
    { { 0.0f, 15.000001f, 0.0f }, 12.5f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
TObjMotionAction panarms_motion_param_table[12] = {
    { 1, 0, 0x17, 0.7f, 0 }, { 1, 0, 0x1d, 0.6f, 0 }, { 1, 0, 0x1e, 0.6f, 0 }, { 3, 0, 0x9, 0.6f, 0 },
    { 3, 0, 0xc, 0.7f, 0 }, { 3, 0, 0xf, 0.7f, 0 }, { 3, 0, 0x5, 0.7f, 0 }, { 2, 0, 0x3, 0.9f, 0 },
    { 3, 0, 0x4, 0.6f, 0 }, { 2, 0, 0x2, 0.8f, 0 }, { 3, 0, 0x8, 0.6f, 0 }, { 1, 0, 0x1a, 1.0f, 0 },
};

extern const NpcAnimationBinding panarms_npc_spawn_descriptor = {
    NULL, panarms_motion_param_table, 0, 11, 12,
};
extern const s32 lbl_8043CCF4[2] = { 0x10b, 0x10c };
extern const s32 lbl_8043CCFC[2] = { 1, 2 };
extern const s32 lbl_8043CD04[2] = { 0x10a, 0x107 };
extern const s32 lbl_8043CD0C[3] = { 3, 4, 0 };

/* State table of TObjEnePanarms: {enter, update} per state, indexed by state; filled by the TU's __sinit. */
typedef void (TObjEnePanarms::*PanarmsStateFn)();
struct PanarmsState { PanarmsStateFn enter; PanarmsStateFn update; };
extern PanarmsState panarms_state_table[14];
// The original's static initializer sits before the weak copies of the inline accessors this unit
// emits (0x800DFB00-0x800DFBD0), which no compiler-generated __sinit reproduces, so it is spelled out.
extern "C" {
static void __sinit_TObjEnePanarms_800DCEB8_cpp();
}
__declspec(section ".ctors") static void *const panarms_body_global_initializer = (void *)__sinit_TObjEnePanarms_800DCEB8_cpp;


struct Sub_800DD690 { u8 b[0xC]; };

struct Obj_800DD690 { u8 pad0[0xB0]; u32 flags; u8 padb4[0xC0 - 0xB4]; f32 fc0; u8 padc4[0x394 - 0xC4]; u32 items[2]; u8 pad39c[4]; Sub_800DD690 subs[1]; };

struct Sub_800DD8AC { u8 b[0xC]; };

struct Obj_800DD8AC { u8 pad0[0xB0]; u32 flags; u8 padb4[0xC0 - 0xB4]; f32 fc0; u8 padc4[0x394 - 0xC4]; u32 items[2]; u8 pad39c[4]; Sub_800DD8AC subs[1]; };


extern "C" {
s32 spawn_continuous_particle_with_direction(void *, void *, int, int);
void *spawn_directional_particle(void *pos, void *dir, s32 id);
f32 vec3_add_to(void *, void *);
f32 atan2_float(f32 y, f32 x);
s32 approach_angle_limited(s32, s32, s32);
s32 TObjEnePanarms__sub_800DE528(void *arg0, Vec *arg1);
s32 subtract_vector(void *, void *);
s32 check_ground_along_path__14TObjEnePanarmsFPvPvPvff(void *actor, Vec *arg1, Vec *arg2, f32 step, f32 dy);
u32 csnLookAt(void *, void *);
f32 horizontal_distance_squared(void *, void *);
s32 try_warp_to_position__14TObjEnePanarmsFPvPv(u8 *player, Vec *pos);
s32 rotate_matrix_z(int, int);
void translate_matrix(uaddr arg0, f32 x, f32 y, f32 z);
s32 rotate_matrix_x(int, int);
}
void direction_to_rotation_xz(u8 *dir, s32 *rot_a, s32 *rot_b);
typedef struct Stack_800DDFDC Stack_800DDFDC;


extern "C" {
extern s32 model_render_flags;
extern s32 saved_model_render_flags;
s32 minimap_render_dot(void *, s32, s32, s32);
}

/* The 0x40-byte set entry the constructor copies for each half it creates. */
struct PanarmsSetEntry {
    s16 unk_0;
    u8 unk_2[0x4];
    u16 unk_6;
    u8 unk_8[0x38];
};

/* What TLobby::dispatch_shared_handler_a(49) returns for Pan Arms. */
struct PanarmsParams {
    f32 unk_0;
    u8 unk_4[0x14];
    s32 search_range;
    s32 wait_frames;
};

// Out-of-line copies of inline accessors; defined first because the unit is emitted backwards.
int TObjEnePanarms::get_state_flag() { return (this->actorFlags >> 4) & 0x1; }

s32 TObjEnePanBARA::is_dead() {
    return (u8)(state == 8);
}

s32 TObjEnePanBARA::is_attacking() {
    return (u8)(state == 0xB);
}

int TObjEnePanBARA::is_slide_in_done() {
    u8 result = 0;
    if (state == 4 && action_timer < 0) {
        result = 1;
    }
    return result;
}

int TObjEnePanBARA::get_state_flag() { return (this->actorFlags >> 4) & 0x1; }

s32 TObjEnePanBARA::is_dying() {
    return state == 7 || state == 8;
}

void TObjMotion::init(s16 action) {
    fn_800660B8();
    change_action(action);
    sub_8002AE64();
}

static void __sinit_TObjEnePanarms_800DCEB8_cpp() {
    panarms_state_table[0].enter = &TObjEnePanarms::enter_idle;
    panarms_state_table[0].update = &TObjEnePanarms::try_activate;
    panarms_state_table[1].enter = &TObjEnePanarms::enter_wait_hidden;
    panarms_state_table[1].update = &TObjEnePanarms::update_wait_hidden;
    panarms_state_table[2].enter = &TObjEnePanarms::set_hidden_flags;
    panarms_state_table[2].update = &TObjEnePanarms::update_fall;
    panarms_state_table[3].enter = &TObjEnePanarms::enter_move;
    panarms_state_table[3].update = &TObjEnePanarms::update_move;
    panarms_state_table[4].enter = &TObjEnePanarms::enter_dead;
    panarms_state_table[4].update = &TObjEnePanarms::update_dead;
    panarms_state_table[5].enter = &TObjEnePanarms::set_state_flags_6;
    panarms_state_table[5].update = &TObjEnePanarms::update_particle_emitters_set2;
    panarms_state_table[6].enter = &TObjEnePanarms::enter_arm_attack_0;
    panarms_state_table[6].update = &TObjEnePanarms::update_destroy_child;
    panarms_state_table[7].enter = &TObjEnePanarms::set_flags_and_field_b8;
    panarms_state_table[7].update = &TObjEnePanarms::update_particle_emitters;
    panarms_state_table[8].enter = &TObjEnePanarms::enter_arm_attack_1;
    panarms_state_table[8].update = &TObjEnePanarms::update_wait_then_set_state;
    panarms_state_table[9].enter = &TObjEnePanarms::enter_split;
    panarms_state_table[9].update = &TObjEnePanarms::update_hit_effect;
    panarms_state_table[10].enter = &TObjEnePanarms::enter_separated;
    panarms_state_table[10].update = &TObjEnePanarms::update_separated_parts;
    panarms_state_table[11].enter = &TObjEnePanarms::merge_halves;
    panarms_state_table[11].update = &TObjEnePanarms::update_timed_action;
    panarms_state_table[12].enter = &TObjEnePanarms::enter_rejoin;
    panarms_state_table[12].update = &TObjEnePanarms::update_state_effect;
    panarms_state_table[13].enter = &TObjEnePanarms::enter_down_state;
    panarms_state_table[13].update = &TObjEnePanarms::update_spin;
}

PanarmsState panarms_state_table[14] = {};
/* Model nodes the constructor hands to ModelNodePositionCapture::create. */
ModelNodePositionEntry panarms_model_node_desc[6] = {
    { 0x35 }, { 0x22 }, { 0x38 }, { 0x46 }, { 0x3b }, { -1 },
};

s32 TObjEnePanarms::create(saddr setData) {
    return (saddr)new TObjEnePanarms(new TObjControl(tl_04), (void *)setData);
}

void TObjEnePanarms::load_and_spawn_npc() {
    BmlResource *resource = new BmlResource(1, (BmlResourceDescriptor *)&lbl_80494F10, 0, 0, NULL);
    TObjEnePanarms__entry_params_resource = resource;
    if (resource != NULL) {
        NpcAnimationBinding binding = panarms_npc_spawn_descriptor;
        binding.motions = resource->motions;
        NpcModelRegistry::register_animated_chunk(0x23, reinterpret_cast<void *>(resource->models[0].model),
            reinterpret_cast<void *>(resource->models[0].m_c), &binding, 12.5f, 0.0f);
        TObjEnePanarms::spawn_npc_pair();
    }
}

void TObjEnePanarms::free_data() {
    if (TObjEnePanarms__entry_params_resource != NULL) {
        delete TObjEnePanarms__entry_params_resource;
        TObjEnePanarms__entry_params_resource = NULL;
    }
}

TObjEnePanarms::TObjEnePanarms(TObject *parent, void *setData) : TObjEnemy(parent) {
    s32 i;

    m_name = TObjEnePanarms__name;
    add_flags_2e4(2);
    apply_set_data(setData);
    clear_lobby_object_state();
    texlist = (saddr)get_bml_texlist((BmlResource *)TObjEnePanarms__entry_params_resource, 0);
    model = (void *)get_bml_model((BmlResource *)TObjEnePanarms__entry_params_resource, 0);
    VecCopy(&prev_position, VecCopy(&home_position, VecCopy(&center, &position)));
    collision_body_parts = init_collision_body_parts(this, panarms_collision_body, 1);
    set_field_d8((saddr)panarms_motion_param_table);
    set_field_dc((saddr)TObjEnePanarms__entry_params_resource->motions);
    set_animation(0);
    set_field_b8(0);
    VecCopy(&body_center, &position);
    velocity.x = velocity.y = velocity.z = 0.0f;
    move_velocity.x = move_velocity.y = move_velocity.z = 0.0f;
    target = NULL;
    bind_enemy_combat_stats((u8 *)TLobby::register_boss(49), (u8 *)TLobby::dispatch_shared_handler_b(49),
                            (u8 *)TLobby::register_object(49));
    referenceHp = hp;
    register_entity_by_id(this);
    set_param(21);
    for (i = 0; i < 2; i++) {
        particle_handles[i] = 0;
    }
    motion_flags &= ~1;
    node_capture = ModelNodePositionCapture::create(panarms_model_node_desc, draw_positions);
    step_right = 1;
    attack_count = 0;
    max_hp = hp;
    has_split = 0;
    move_count = 0;
    pad_470 = ((PanarmsParams *)TLobby::dispatch_shared_handler_a(49))->unk_0;
    search_range = ((PanarmsParams *)TLobby::dispatch_shared_handler_a(49))->search_range;
    if (search_range < 5) {
        search_range = 5;
    }
    wait_frames = ((PanarmsParams *)TLobby::dispatch_shared_handler_a(49))->wait_frames;
    if (wait_frames < 0) {
        wait_frames = 0;
    }
    for (i = 0; i < 4; i++) {
        fades[i].activate_and_dispatch();
    }
    set_state(1);
    PanarmsSetEntry entry = *(PanarmsSetEntry *)setData;
    entry.unk_0 = set_index + 1;
    entry.unk_6 = entity_id + 1;
    halves[0] = create_bara(&entry, 0);
    entry.unk_0 = set_index + 2;
    entry.unk_6 = entity_id + 2;
    halves[1] = create_bara(&entry, 1);
    if (halves[0] == NULL || halves[1] == NULL) {
        return;
    }
    halves[0]->set_links(this, halves[1]);
    halves[1]->set_links(this, halves[0]);
}

TObjEnePanarms::~TObjEnePanarms() {
    ModelNodePositionCapture::destroy(node_capture);
    halves[0]->queue_destruction();
    halves[1]->queue_destruction();
    free_collision_body_parts(this);
    this->collision_body_parts = 0;
    this->destroy_handles();
}

void TObjEnePanarms::destroy_handles() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (particle_handles[i] != NULL) {
            TParticleCtrl::release(particle_handles[i]);
            particle_handles[i] = NULL;
        }
    }
}

void TObjEnePanarms::run_task() {
    PanarmsStateFn update;
    if (this->state != 0 && TObjPlayer::check_demo_mode() != 0) {
        set_state(0);
    }
    sub_800DE390();
    update = panarms_state_table[this->state].update;
    if (update) {
        (this->*update)();
        if (this->visible != 0) {
            this->actorFlags &= ~0x02000000;
        } else {
            this->actorFlags |= 0x02000000;
        }
        update_prev_position();
        if (this->state != 0) {
            if (this->visible != 0) {
                submit_cursor_candidate(this, -1);
                advance_animation();
            }
            if ((this->visible != 0 && this->state != 4) || this->state == 1) {
                minimap_render_dot(&this->body_center, -0x5DB4, 1, 0);
            }
        }
    }
}

void TObjEnePanarms::render() {
    s32 cam;
    RenderFadeState *fade;
    s32 draw;
    if (this->update_object_view_visibility(500.0f, 20.0f) == 0) {
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_mode();
    }
    if (this->visible == 0) {
        return;
    }
    TObjPlayer::toggle_particle_effect();
    saved_model_render_flags = model_render_flags;
    fade = &this->fades[cam];
    fade->update();
    if (fade->updateFromCamera(&this->body_center.x) != 0) {
        fade->set_flags_and_apply_damage_color();
        draw = 1;
        if (defer_render() != 0) {
            draw = 0;
        }
        if (draw != 0) {
            TObjEnePanarms__sub_800DEEF8(this);
        }
        fade->clear_flag_and_notify();
    } else {
        model_render_flags |= 0x01000000;
        TObjEnePanarms__sub_800DEEF8(this);
    }
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    if (this->shadow_visible != 0) {
        draw_shadow();
    }
}

void TObjEnePanarms__sub_800DEEF8(TObjEnePanarms *self) {
    push_matrix();
    post_translate_matrix(&self->position.x);
    rotate_matrix_y(NULL, self->rotation_y);
    TObjFish::set_global_param(self->texlist);
    self->node_capture->install();
    ((TObjMotion *)self)->draw();
    self->node_capture->clear();
    pop_matrix();
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TObjEnePanarms::draw_shadow() {
    Vec v;
    s32 angle_x;
    s32 angle_z;
    f32 d;
    f32 k;
    f32 t;

    if (!(this->ground_y > 19.800001f + this->position.y)) {
        push_matrix();
        translate_matrix(0, 0.25f * this->position.x + 0.75f * draw_positions[0].x, 0.2f + this->ground_y, 0.25f * this->position.z + 0.75f * draw_positions[0].z);
        direction_to_rotation_xz(((u8 *)this) + 0x248, &angle_x, &angle_z);
        rotate_matrix_z(0, angle_z);
        rotate_matrix_y(NULL, rotation_y);
        rotate_matrix_x(0, angle_x + 0x4000);
        d = this->position.y - this->ground_y;
        if (d > 40.0f) {
            d = 40.0f;
        } else if (d < 0.0f) {
            d = 0.0f;
        }
        t = 1.0f - d / 40.0f;
        k = 0.65f * t + 0.1f;
        v.z = 1.0f;
        v.x = 5.0f * k;
        v.y = 2.0f * k;
        scale_current_matrix(&v.x);
        draw_blob_shadow(0);
        pop_matrix();
    }
}

#pragma pop

void TObjEnePanarms::set_state(s32 next) {
    this->state = next;
    if (this->state < 0 || this->state >= 14) {
        return;
    }
    destroy_handles();
    PanarmsStateFn enter = panarms_state_table[this->state].enter;
    if (enter) {
        (this->*enter)();
    }
}

void TObjEnePanarms::snap_to_ground() {
    Vec v = position;
    v.y += 10.0f;
    if (project_actor_to_ground(this, &v, &ground_normal) != 0) {
        ground_y = v.y;
    }
}

#pragma push
#pragma fp_contract on
s32 try_warp_to_position__14TObjEnePanarmsFPvPv(u8 *player, Vec *pos) {
    s32 ok;
    s32 i;
    s32 ang;
    f32 c;
    f32 s;
    f32 x;
    Vec d;
    Vec p;
    Vec hit;
    ok = 0;
    if (!(horizontal_distance_squared(player + 0x38, player + 0x50) > 250000.0f)) {
        VecCopy((Vec *)&d, (const Vec *)pos);
        subtract_vector(&d, player + 0x38);
        if (0.0f != vector_length(&d)) {
            i = 1;
            do {
                VecCopy((Vec *)&p, (const Vec *)(player + 0x38));
                vec3_add_to(&p, &d);
                p.y += 10.0f;
                if (((s32 (*)(void *, void *, void *))project_actor_to_ground)(player, &p, &hit) != 0 && csnLookAt(player + 0x38, &p) == 0) {
                    VecCopy((Vec *)(player + 0x44), (const Vec *)(player + 0x38));
                    VecCopy((Vec *)(player + 0x38), (const Vec *)&p);
                    *(f32 *)((s8 *)player + 0x384) = p.y;
                    VecCopy((Vec *)(player + 0x248), (const Vec *)&hit);
                    ok = 1;
                    break;
                }
                ang = i << 12;
                if (i & 1) {
                    ang *= -1;
                }
                c = sin_table_lookup(ang);
                s = cos_table_lookup(ang);
                i++;
                x = s * d.x - c * d.z;
                d.x = x;
                d.z = c * x + s * d.z;
            } while (i < 0x10);
        }
    }
    ((TObjCollidable *)player)->update_collisions();
    return ok;
}
#pragma pop

u16 TObjEnePanarms::turn_to_nearest_player(s32 arg1, s32 mode) {
    Vec sp;
    s32 t;
    s32 var;
    if ((t = find_nearest_visible_player(this, &sp, 200.0f)) != 0xFFFF) {
        if (mode == 0 || vector_length(&sp) < 30.0f) {
            var = 0;
        } else {
            var = -0x1800;
            if (step_right == 1) {
                var *= -1;
            }
        }
        rotation_y = approach_angle_limited(rotation_y, var + (s32) (10430.38043493439 * atan2_float(sp.x, sp.z)), arg1);
    }
    return t;
}

void TObjEnePanarms::turn_toward_target(s32 arg1) {
    Vec sp;
    if (this->find_nearest_enemy_with_flag(&sp, (f32)500.0f) == 0xFFFF) {
        if (((Obj_800DE9F0 *)this)->f1C & 1) {
            arg1 *= -1;
        }
        rotation_y = rotation_y + arg1;
        return;
    }
    rotation_y = approach_angle_limited(rotation_y, (s32) (10430.38043493439 * atan2_float(sp.x, sp.z)), arg1);
}

#pragma push
#pragma opt_common_subs off
#define arg0 ((u8 *)p)
s32 TObjEnePanarms::find_combine_position(void *p) {
    Vec probe;
    Vec step;
    f32 dist;
    f32 t;
    VecCopy((Vec *)&probe, (const Vec *)(*(u8 **)((s8 *)arg0 + 0x3E4) + 0x38));
    vec3_add_to(&probe, *(u8 **)((s8 *)arg0 + 0x3E8) + 0x38);
    probe.x *= 0.5f;
    probe.y *= 0.5f;
    probe.z *= 0.5f;
    VecCopy((Vec *)&step, (const Vec *)(arg0 + 0x38));
    subtract_vector(&step, &probe);
    dist = vector_length(&step);
    if (dist >= 10.0f) {
        normalize_vector(&step);
        step.x *= 10.0f;
        step.y *= 10.0f;
        step.z *= 10.0f;
    }
    t = 0.0f;
    while (t < dist) {
        probe.y += 10.0f;
        if (project_actor_to_ground((TObjChara *)arg0, (Vec *)&probe, 0) != 0 &&
            TObjEnePanarms__sub_800DE528(arg0, (Vec *) &probe) != 0 &&
            check_ground_along_path__14TObjEnePanarmsFPvPvPvff(arg0, (Vec *) (*(u8 **)((s8 *)arg0 + 0x3E4) + 0x38), (Vec *) &probe, 10.0f, 10.0f) != 0 &&
            check_ground_along_path__14TObjEnePanarmsFPvPvPvff(arg0, (Vec *) (*(u8 **)((s8 *)arg0 + 0x3E8) + 0x38), (Vec *) &probe, 10.0f, 10.0f) != 0) {
            u8 *a;
            u8 *b;
            VecCopy((Vec *)(arg0 + 0x38), (const Vec *)&probe);
            a = *(u8 **)((s8 *)arg0 + 0x3E4);
            b = *(u8 **)((s8 *)arg0 + 0x3E8);
            ((TObjEnePanarms *)arg0)->rotation_y = (s32) (10430.38043493439 * atan2_float(
                *(f32 *)((s8 *)b + 0x38) - *(f32 *)((s8 *)a + 0x38),
                *(f32 *)((s8 *)b + 0x40) - *(f32 *)((s8 *)a + 0x40))) + 0x4000;
            return 1;
        }
        t += 10.0f;
        vec3_add_to(&probe, &step);
    }
    return 0;
}
#undef arg0
#pragma pop

s32 check_ground_along_path__14TObjEnePanarmsFPvPvPvff(void *actor, Vec *arg1, Vec *arg2, f32 step, f32 dy) {
    Vec p = *arg1;
    Vec d = *arg2;
    f32 len;
    f32 t;
    subtract_vector(&d, &p);
    len = vector_length(&d);
    if (len < step) {
        return 1;
    }
    normalize_vector(&d);
    d.x *= step;
    d.y *= step;
    d.z *= step;
    for (t = 0.0f; t < len; ) {
        p.y += dy;
        if (project_actor_to_ground((TObjChara *)actor, (Vec *)&p, 0) == 0) {
            return 0;
        }
        t += step;
        vec3_add_to(&p, &d);
    }
    return 1;
}

#pragma push
#pragma fp_contract on
s32 TObjEnePanarms__sub_800DE528(void *arg0, Vec *arg1) {
    Vec v;
    f32 r;
    s32 step;
    s32 a;
    VecCopy((Vec *)&v, (const Vec *)arg1);
    v.y += 10.0f;
    if (project_actor_to_ground((TObjChara *)arg0, (Vec *)&v, 0) == 0) {
        return 0;
    }
    for (r = 10.0f; r <= 20.0f; r += 10.0f) {
        step = (s32)(655360.0f / (6.28f * r));
        for (a = 0; a < 0x10000; a += step) {
            VecCopy((Vec *)&v, (const Vec *)arg1);
            v.x += r * sin_table_lookup(a);
            v.y += 10.0f;
            v.z += r * cos_table_lookup(a);
            if (project_actor_to_ground((TObjChara *)arg0, (Vec *)&v, 0) == 0) {
                return 0;
            }
        }
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
s32 TObjEnePanarms__sub_800DE494(void *self) {
    s32 i;
    f32 best = 250000.0f;
    for (i = 0; i < registered_player_count; i++) {
        TObjPlayer *player = TObjPlayer::get_player_data(i);
        if (player != NULL) {
            f32 d = horizontal_distance_squared((u8 *)self + 0x38, &player->body_center);
            if (d < best) {
                best = d;
            }
        }
    }
    if (best < 250000.0f) {
        return 0;
    }
    return 1;
}
#pragma pop

void TObjEnePanarms__sub_800DE430(saddr self, s32 arg1, s32 arg2) {
    Vec position;
    VecCopy((Vec *)(&position.x), (const Vec *)(self + 0x2FC));
    position.y += 10.0f;
    create_particle_controller_with_rotation(&position, (ParticleAngles *)(self + 0x5C), 0x106, arg1, arg2);
}

s32 TObjEnePanarms::sub_800DE390() {
    switch (this->state) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 10:
    case 11:
        return 0;
    default:
        if (this->halves[0]->is_dying() != 0 || this->halves[1]->is_dying() != 0) {
            set_state(10);
            return 1;
        }
        return 0;
    }
}

void TObjEnePanarms::run_death_reaction() { if (this->state != 4) { set_state(4); } }

void TObjEnePanarms::run_hit_reaction() {
    switch (state) {
    case 1:
    case 2:
        return;
    default:
        actorFlags &= 0xFFFFFDFF;
        play_sound_effect(remap_sound_for_area(0x4003BC34), &draw_positions[1], 0, 0);
        play_sound_effect(remap_sound_for_area(0x4003BC33), &draw_positions[3], 0, 0);
        break;
    }
}

void TObjEnePanarms::run_miss_reaction() { this->actorFlags &= 0xfffffeff; }

void TObjEnePanarms::enter_idle() { this->shadow_visible = 1; this->visible = 1; }

void TObjEnePanarms::try_activate() { if (TObjPlayer::check_demo_mode() == 0) { set_state(1); } }

void TObjEnePanarms::enter_wait_hidden() {
    VecCopy(&this->position, &this->home_position);
    this->snap_to_ground();
    this->position.y = (f32) (-39.600002f + this->ground_y);
    obj_setFlags30(this, 0x04040000);
    this->collision_body_parts->flags &= ~1;
    this->collision_body_parts->flags |= 0x08000000;
    this->shadow_visible = 0;
    this->visible = 0;
    this->state_timer = this->wait_frames;
}

void TObjEnePanarms::update_wait_hidden() {
    Vec sp;
    s32 r = 0;
    s32 t;
    if (--this->state_timer < 0) {
        r = 1;
    } else if ((t = find_nearest_visible_player(this, &sp, (f32) this->search_range)) != 0xFFFF) {
        this->rotation_y = (s32) (10430.38043493439 * atan2_float(sp.x, sp.z));
        r = 1;
    }
    if (r != 0) {
        set_state(2);
    }
}

void TObjEnePanarms::set_hidden_flags() {
    this->move_velocity.x = 0.0f;
    this->move_velocity.y = 7.5f;
    this->move_velocity.z = 0.0f;
    this->shadow_visible = 1;
    this->visible = 1;
    this->collision_body_parts->flags &= ~1;
    obj_clearFlags30(0x40000U);
    obj_setFlags30(this, (int)(0x04000000U));
}

void TObjEnePanarms::update_fall() {
  Vec v;
  this->move_velocity.y += -0.5f;
  vec3_add_to(&this->position, &this->move_velocity);
  if (this->move_velocity.y <= 0.0f)
  {
    if (this->position.y <= this->ground_y)
    {
      this->position.y = this->ground_y;
      spawn_particle_effect(&this->position, 0xF0);
      set_state(3);
      return;
    }
  }
  this->state_timer++;
  if ((!(this->state_timer & 7)) && (this->move_velocity.y > 0.0f))
  {
    VecCopy(&v, &this->body_center);
    v.y = 5.0f + this->ground_y;
    spawn_particle_effect(&v, 0xF0);
  }
}

void TObjEnePanarms::enter_move() {
    s16 var_r30;
    switch (this->step_right) {
    case 0:
        this->step_right = 1;
        var_r30 = 2;
        break;
    case 1:
        this->step_right = 0;
        var_r30 = 1;
        break;
    default:
        return;
    }
    this->move_count += 1;
    this->collision_body_parts->flags &= ~0x08000000;
    this->collision_body_parts->flags |= 1;
    this->obj_clearFlags30(0x04040000);
    this->state_timer = (s32) (49.999996f * (f32) ((s32) (1.99f * random_ratio()) + 1));
    set_field_b8((s16)var_r30);
}

#pragma push
#pragma fp_contract on
struct Obj_800DE9F0;
void TObjEnePanarms::update_move() {
    f32 s;
    if (this->frame >= 0.0f && this->frame <= 12.0f) {
        s32 mode = 1;
        if ((f32)this->state_timer < 49.999996f) {
            mode = 0;
        }
        if (get_state_flag() != 0) {
            turn_toward_target(0x100);
        } else {
            turn_to_nearest_player(0x100, mode);
        }
    }
    if (this->frame >= 14.0f && this->frame <= 20.0f) {
        s = sin_table_lookup((s32)(32768.0f * (this->frame - 14.0f) / 6.0f));
    } else {
        s = 0.0f;
    }
    if (s > 0.0f) {
        Vec pos = this->position;
        f32 r = 1.5f * s;
        if (this->step_right == 1) {
            r *= -1.0f;
        }
        pos.x += r * cos_table_lookup(this->rotation_y);
        pos.z += -r * sin_table_lookup(this->rotation_y);
        try_warp_to_position__14TObjEnePanarmsFPvPv((u8 *)this, (Vec *)&pos);
    }
    if (get_state_flag() == 0) {
        if (TObjEnePanarms__sub_800DE494(this) != 0) {
            set_state(1);
            return;
        }
        if (this->has_split == 0 && this->hp <= this->max_hp / 3 &&
            TObjEnePanarms__sub_800DE528(this, (Vec *)&this->position) != 0) {
            set_state(9);
            return;
        }
    }
    if (--this->state_timer > 0) {
        return;
    }
    if (get_state_flag() == 0 && this->move_count >= 3 &&
        TObjEnePanarms__sub_800DE528(this, (Vec *)&this->position) != 0) {
        this->move_count = 0;
        set_state(9);
        return;
    }
    switch (this->step_right) {
    case 0:
        this->attack_count++;
        this->spin_count = 0;
        set_state(7);
        break;
    case 1:
        set_state(5);
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEnePanarms::enter_dead() {
    s16 st;
    Vec v;
    this->state_timer = 0xA4;
    refresh_lobby_state();
    this->send_entity_set_flags();
    st = 5;
    if (find_nearest_visible_player(this, &v, 200.0f) != 0xFFFF) {
        if (v.x * sin_table_lookup(this->rotation_y) + v.z * cos_table_lookup(this->rotation_y) < 0.0f) {
            st = 4;
        }
    }
    set_field_b8((s16)st);
    play_sound_effect(this->remap_sound_for_area(0x4003B836), &this->draw_positions[1], 0, 0);
    play_sound_effect(this->remap_sound_for_area(0x4003BB35), &this->draw_positions[3], 0, 0);
    if (this->visible != 0) {
        if (this->halves[0]->is_dying() == 0) {
            this->halves[0]->reset_split();
        }
        if (this->halves[1]->is_dying() == 0) {
            this->halves[1]->reset_split();
        }
    } else {
        if (this->halves[0]->is_dying() == 0) {
            this->halves[0]->die_with_body();
        }
        if (this->halves[1]->is_dying() == 0) {
            this->halves[1]->die_with_body();
        }
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma fp_contract on
void TObjEnePanarms::update_dead() {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_800DD9A0, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_800DD9A0, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_800DD9A0, sp10) == 0x8);
    LAYOUT_ASSERT(sp14_offset, offsetof(Stack_800DD9A0, sp14) == 0xC);
    LAYOUT_ASSERT(sp18_offset, offsetof(Stack_800DD9A0, sp18) == 0x10);
    Stack_800DD9A0 stack;
    f32 motion_frame;
    s32 timer;
    this->state_timer = (this->state_timer - 1);
    // inferred name: twin of panarms_particle_frame_window in TObjEnePanBARA::update_dead
    static f32 panarms_dead_particle_frame_window = panarms_motion_param_table[4].speed;
    motion_frame = this->frame;
    if ((motion_frame >= 21.0f) && (motion_frame < (21.0f + panarms_dead_particle_frame_window))) {
        VecCopy((Vec *)(&stack.sp14), &this->body_center);
        stack.sp18 += 5.0f;
        spawn_particle_effect((const Vec *)&stack.sp14, 0xF0);
    }
    timer = this->state_timer;
    if (timer <= 0x78) {
        if (timer == 0x78) {
            stack.sp8 = (0.5f * this->position.x) + (0.5f * draw_positions[0].x);
            stack.spC = this->position.y;
            stack.sp10 = (0.5f * this->position.z) + (0.5f * draw_positions[0].z);
            spawn_ground_effect((const Vec *)&stack.sp8, 0x78);
            TObjPlayer::spawn_dead_spot_default((saddr)((void *)&stack.sp8), 6);
        }
        if (this->state_timer == 0x5A) {
            this->shadow_visible = 0;
        }
        this->position.y = (f32) (this->position.y - 0.104166664f);
        if (this->state_timer <= 0) {
            queue_destruction();
        }
    }
}
#pragma pop

void TObjEnePanarms::set_state_flags_6() {
    this->collision_body_parts->flags |= 1;
    obj_clearFlags30(0x04040000U);
    set_field_b8(6);
}

void TObjEnePanarms::update_particle_emitters_set2() {
    s32 i;
    if (((Obj_800DD8AC *)this)->fc0 >= 10.0f) {
        for (i = 0; i < 2; i++) {
            u32 *it = &((Obj_800DD8AC *)this)->items[i];
            if (*it == 0) {
                *it = (uaddr)create_particle_emitter(&((Obj_800DD8AC *)this)->subs[lbl_8043CCFC[i]], lbl_8043CCF4[i]);
            }
        }
    }
    if (((Obj_800DD8AC *)this)->flags & 0x10) {
        set_state(6);
    }
}

void TObjEnePanarms::enter_arm_attack_0() {
    s32 buffer_14[3];
    Vec direction;
    s32 temp_r6;
    this->collision_body_parts->flags |= 1;
    this->obj_clearFlags30(0x04040000U);
    temp_r6 = this->rotation_y + 0x4000;
    buffer_14[1] = 0;
    buffer_14[0] = temp_r6;
    buffer_14[2] = 0x4000;
    *(s32 *)((s8 *)this + 0x394) = spawn_continuous_particle_with_direction(&draw_positions[2], &buffer_14[0], 0x105, temp_r6);
    direction.y = 0.0f;
    direction.x = sin_table_lookup(this->rotation_y);
    direction.z = cos_table_lookup(this->rotation_y);
    TObjEnePanarmsAtkColli::create(this, &draw_positions[2], &direction, 0);
    set_field_b8(7);
    this->state_timer = 0x5A;
}

void TObjEnePanarms::update_destroy_child() {
    TParticleCtrl *temp_r3;
    if (this->frame >= 5.0f) {
        temp_r3 = this->particle_handles[0];
        if (temp_r3 != NULL) {
            TParticleCtrl::release(temp_r3);
            this->particle_handles[0] = NULL;
        }
    }
    if (--this->state_timer <= 0) {
        set_state(3);
    }
}

void TObjEnePanarms::set_flags_and_field_b8() {
    this->collision_body_parts->flags |= 1;
    obj_clearFlags30(0x04040000U);
    set_field_b8(8);
}

void TObjEnePanarms::update_particle_emitters() {
    s32 i;
    if (((Obj_800DD690 *)this)->fc0 >= 10.0f) {
        for (i = 0; i < 2; i++) {
            u32 *slot = &((Obj_800DD690 *)this)->items[i];
            if (*slot == 0) {
                *slot = (uaddr)create_particle_emitter(&((Obj_800DD690 *)this)->subs[lbl_8043CD0C[i]], lbl_8043CD04[i]);
            }
        }
    }
    if (((Obj_800DD690 *)this)->flags & 0x10) {
        set_state(8);
    }
}

void TObjEnePanarms::enter_arm_attack_1() {
    s32 buffer_14[3];
    Vec direction;
    s32 temp_r6;
    this->collision_body_parts->flags |= 1;
    this->obj_clearFlags30(0x04040000U);
    spawn_directional_particle((&draw_positions[4]), ((u8 *)this + 0x5C), 0x109);
    temp_r6 = this->rotation_y - 0x4000;
    buffer_14[1] = 0;
    buffer_14[0] = temp_r6;
    buffer_14[2] = 0x4000;
    *(s32 *)((s8 *)this + 0x394) = spawn_continuous_particle_with_direction(&draw_positions[4], &buffer_14[0], 0x108, temp_r6);
    direction.y = 0.0f;
    direction.x = sin_table_lookup(this->rotation_y);
    direction.z = cos_table_lookup(this->rotation_y);
    TObjEnePanarmsAtkColli::create(this, &draw_positions[4], &direction, 1);
    set_field_b8(9);
    this->state_timer = 0x5A;
}

void TObjEnePanarms::update_wait_then_set_state() {
    TParticleCtrl *temp_r3;
    if (this->frame >= 5.0f) {
        temp_r3 = this->particle_handles[0];
        if (temp_r3 != NULL) {
            TParticleCtrl::release(temp_r3);
            this->particle_handles[0] = NULL;
        }
    }
    if (--this->state_timer <= 0) {
        if (!(this->attack_count & 1) && (this->spin_count < 4)) {
            set_state((saddr)((void*)(0xD)));
            return;
        }
        set_state(3);
    }
}

void TObjEnePanarms::enter_split() {
    this->collision_body_parts->flags &= ~1;
    this->obj_clearFlags30((u32)(0x40000));
    obj_setFlags30(this, 0x04000000);
    TObjEnePanarms__sub_800DE430((saddr)this, 0x22, 0x3C);
    play_sound_effect(this->remap_sound_for_area(0x4003BC2D), &this->draw_positions[1], 0, 0);
    play_sound_effect(this->remap_sound_for_area(0x4003BC2C), &this->draw_positions[3], 0, 0);
    set_field_b8(0xA);
}

void TObjEnePanarms::update_hit_effect() {
    f32 temp_f1;
    temp_f1 = this->frame;
    if ((temp_f1 >= 20.0f) && (temp_f1 < 20.6f)) {
        spawn_particle_effect((const Vec *)(((u8 *)this) + 0x38), 0xF0);
    }
    if (this->motion_flags & 0x10) {
        set_state((saddr)((void*)(0xA)));
    }
}

void TObjEnePanarms::enter_separated() {
    this->collision_body_parts->flags &= ~1;
    this->obj_clearFlags30((u32)(0x40000));
    obj_setFlags30(this, 0x04000000);
    this->visible = 0;
    this->state_timer = 0x384;
    this->has_split = 1;
    play_sound_effect(this->remap_sound_for_area(0x4003BC2E), (u8 *)this + 0x38, 0, 0);
    if (this->halves[0]->is_dying() == 0) {
        this->halves[0]->start_split();
    }
    if (this->halves[1]->is_dying() == 0) {
        this->halves[1]->start_split();
    }
}

void TObjEnePanarms::update_separated_parts() {
    s32 timer;
    this->hp = (s16) (this->halves[0]->hp + this->halves[1]->hp);
    if ((this->halves[0]->is_dead() != 0) && (this->halves[1]->is_dead() != 0)) {
        this->send_entity_set_flags();
        queue_destruction();
        return;
    }
    if (this->halves[0]->is_dying() == 0) {
        switch (this->halves[1]->is_dying()) {
        case 0:
        this->state_timer = (this->state_timer - 1);
        timer = this->state_timer;
        if (timer == 0) {
            if ((this->halves[0]->is_attacking() != 0) || (this->halves[1]->is_attacking() != 0)) {
                this->state_timer += 15.0f;
                return;
            }
            TObjEnePanarms::find_combine_position(this);
            this->halves[0]->init_state();
            this->halves[1]->init_state();
            return;
        }
        if (timer < 0) {
            if ((this->halves[0]->is_slide_in_done() != 0) && (this->halves[1]->is_slide_in_done() != 0)) {
                if ((this->halves[0]->get_state_flag() != 0) || (this->halves[1]->get_state_flag() != 0)) {
                    this->state_timer = -1;
                    return;
                }
                set_state((saddr)((void*)(0xB)));
                return;
            }
            if (this->state_timer < -0x12C) {
                this->halves[0]->do_action_2();
                this->halves[1]->do_action_2();
                this->state_timer = 0x384;
            }
        }
        break;
        }
    }
}

void TObjEnePanarms::merge_halves() {
    this->visible = 0;
    this->collision_body_parts->flags &= ~1;
    obj_clearFlags30(0x40000U);
    obj_setFlags30(this, (int)(0x04000000U));
    TObjEnePanarms__sub_800DE430((saddr)this, 0x2D, 0x25);
    this->hp = (s16) (this->halves[0]->hp + this->halves[1]->hp);
    this->halves[0]->start_merge();
    this->halves[1]->start_merge();
    this->state_timer = 0x40;
}

void TObjEnePanarms::update_timed_action() {

    if ((this->halves[0]->is_dying() != 0) || (this->halves[1]->is_dying() != 0)) {
        set_state((saddr)((void*)(0xA)));
        return;
    }
    if (--this->state_timer <= 0) {
        set_state((saddr)((void*)(0xC)));
        return;
    }
    if (this->state_timer == 0x13) {
        play_sound_effect(this->remap_sound_for_area(0x4003BC32), ((u8 *)this) + 0x38, 0, 0);
    }
}

void TObjEnePanarms::enter_rejoin() {
    this->visible = 1;
    this->collision_body_parts->flags &= ~1;
    this->obj_clearFlags30((u32)(0x40000));
    obj_setFlags30(this, 0x04000000);
    play_sound_effect(this->remap_sound_for_area(0x4003BC31), &this->draw_positions[1], 0, 0);
    play_sound_effect(this->remap_sound_for_area(0x4003BC30), &this->draw_positions[3], 0, 0);
    this->init(0xA);
}

void TObjEnePanarms::update_state_effect() {
    f32 temp_f1;
    temp_f1 = this->frame;
    if ((temp_f1 >= 20.0f) && (temp_f1 < 20.6f)) {
        spawn_particle_effect((const Vec *)(((u8 *)this) + 0x38), 0xF0);
    }
    if (this->motion_flags & 0x10) {
        set_state(3);
    }
}

void TObjEnePanarms::enter_down_state() {
    this->collision_body_parts->flags |= 1;
    obj_clearFlags30(0x04040000U);
    this->state_timer = 0x1E;
    this->spin_count = this->spin_count + 1;
    set_field_b8(0xB);
}

void TObjEnePanarms::update_spin() {

    if (this->attack_count & 2) {
        this->rotation_y = (this->rotation_y + 0x111);
    } else {
        this->rotation_y = (this->rotation_y - 0x111);
    }
    if (--this->state_timer < 0) {
        set_state((saddr)((void*)(7)));
    }
}
