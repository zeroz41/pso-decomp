#include "pso/protocol/protocol_types.h"
#pragma readonly_strings on
#define TOBJECT_OUT_OF_LINE_HELPERS

// Built with -inline deferred (GAME_EXCEPTIONS in configure.py), which emits functions
// in reverse source order: bodies here run from the highest address down.

#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/boss/TBoss3VoloptP02.h"
#include "pso/boss/TUnk_80484A94.h"
#include "pso/boss/TUnk_80484AFC.h"
#include "pso/boss/TUnk_80484840.h"
#include "pso/boss/TUnk_80484870.h"
#include "pso/enemy/TObjEneGyaranzo.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/math/AngleLookup.h"
#include "pso/misc/TBreakUpMdl.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjVoloptCage.h"
#include "pso/object/TObjVoloptPillar.h"
#include "pso/object/obj_band.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/byteswap.h"
#include "pso/system/vector.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/object/TObjLight_80133568.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"

extern "C" {
void *find_entity_by_id(u16 id);
s32 post_translate_matrix(void *);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
extern s32 model_render_flags;
void free_collision_body_parts(void *);
void init_collision_body_parts(void *, void *, s32);
void *__dt__13TUnk_804949A8Fv(void *arg0, s16 arg1);
s32 play_persistent_sound(s32, void *, void *, s16, s32);
s32 rand(void);
extern s32 actor_frame_tick;
s32 minimap_render_dot(void *, s32, s16, s32);
s32 update_obstruction_fade(void *);
s32 submit_cursor_candidate(void *, int);
s32 play_sound_effect(s32, void *, s16, s32);
void advance_animation_playback(void *);
u16 get_entity_id(void *);
f32 atan2_float(f32, f32);
f32 fabs_float(f32);
s32 angle_difference_abs(s32, s32);
void subtract_vector(void *, void *);
extern s32 lbl_805D586C;
u16 TObjRoomId__sub_801A1DB8(void);
void vec3_add_to(void *, void *);
s32 restore_player_cameras(void);
s32 activate_camera_mode(int, f32);
s32 TCameraCtrl__sub_8006A044(int, f32);
s32 set_scripted_camera_pose(void *, void *, void *);
u8 *get_scripted_camera_playback(s16);
s32 TObjPlayer__sub_801BA42C();
s32 approach_angle_limited(s32, s32, s32);
u8 *get_player_by_client_id(s32);
s32 matrix_mult_vec(int, void *, void *);
extern u8 identity_matrix[];
void TBoss3Volopt__sub_800FD344(s32 arg0, s32 arg1, s32 arg2, void *arg3, void *arg4);
void obj_setFlags30(void *, s32);
}

void reset_status_effect_row(u8 *row);

struct NjModel {
    void *vlist;
    u8 *plist;
};

struct NjObject {
    u32 evalflags;
    NjModel *model;
    f32 pos[3];
    s32 ang[3];
    f32 scl[3];
    NjObject *child;
    NjObject *sibling;
};

struct VoloptActionEntry {
    u32 kind;
    u32 motion;
    f32 speed;
    u32 flags;
};

struct VoloptMovementParams {
    f32 radius;
    f32 scale;
    u32 turn_speed;
    u32 flags;
    u32 pad_10;
    u32 count;
    u32 pad_18;
};

struct VoloptCollisionBody {
    f32 offset[3];
    f32 radius;
    u32 pad_10[2];
    u32 flags;
    u32 pad_1C[4];
};

struct VoloptBreakupParams {
    s32 count;
    f32 values[6];
};

struct VoloptCameraCommand {
    s8 a;
    s8 b;
    s16 c;
    f32 d;
    f32 e;
};

class ViewCulledObject {
public:
    u8 pad_0[0x18];
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual s32 update_object_view_visibility(f32 radius, f32 margin);
};

class ObstructionFade {
public:
    u8 pad_0[0x14];
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void fade_out();
    virtual void restore();
};

const char *TBoss3VoloptP02_name = "TBoss3VoloptP02";

static s32 chain_node_ids_a[5] = {5, 8, 11, 14, 17};
static s32 chain_node_ids_b[5] = {21, 24, 27, 30, 33};
static s16 chain_node_ids[10] = {4, 7, 10, 13, 16, 20, 23, 26, 29, 32};
static s16 volley_node_ids[4] = {0x2E, 0x2F, 0x30, 0x31};
static VoloptActionEntry action_entries[9] = {
    {0x10000, 0x10, 0.7f, 0},
    {0x10000, 0x10, 0.7f, 1},
    {0x20000, 0xA, 0.8f, 4},
    {0x20000, 0x4, 0.6f, 8},
    {0x30004, 0x5, 0.5f, 0x10},
    {0x20000, 0xB, 0.7f, 4},
    {0x20000, 0x9, 0.8f, 4},
    {0x20000, 0x1, 0.7f, 4},
    {0x20000, 0xD, 0.6f, 1},
};
static VoloptMovementParams movement_params = {150.0f, 0.5555555f, 0x400, 0x1E0000, 0, 1, 0};
static VoloptCollisionBody collision_bodies[5] = {
    {{0.0f, 23.0f, 29.0f}, 10.0f, {0, 0}, 0x8003, {0, 0, 0, 0}},
    {{36.0f, 26.0f, 0.0f}, 15.0f, {0, 0}, 0x8003, {0, 0, 0, 0}},
    {{-36.0f, 26.0f, 0.0f}, 15.0f, {0, 0}, 0x8003, {0, 0, 0, 0}},
    {{0.0f, 25.0f, -35.0f}, 18.0f, {0, 0}, 0x8003, {0, 0, 0, 0}},
    {{0.0f, 26.0f, 0.0f}, 24.0f, {0, 0}, 0x8003, {0, 0, 0, 0}},
};
static f32 pulse_color_start[3] = {0.0f, 178.0f, 255.0f};
static f32 pulse_color_end[3] = {255.0f, 0.0f, 0.0f};
static s32 pulse_speeds[2] = {0x300, 0x2000};
static VoloptBreakupParams death_breakup_params = {0x14, {0.06f, 3.0f, 0.9f, 0.2f, 0.55f, 0.8f}};
static VoloptBreakupParams part_breakup_params = {0x14, {0.06f, 1.5f, 0.9f, 0.12f, 0.55f, 0.5f}};
static s16 part_breakup_node_ids[5] = {2, 0x12, 0x32, 0x22, 0x29};

static inline f32 max_f32(f32 a, f32 b) { return (a > b) ? a : b; }
static inline f32 min_f32(f32 a, f32 b) { return (a < b) ? a : b; }
static inline s32 max_s32(s32 a, s32 b) { return (a > b) ? a : b; }
static inline s32 min_s32(s32 a, s32 b) { return (a < b) ? a : b; }

static u8 lbl_804FF008[0x28];
static s16 wave_delays[3];
static TUnk_8048FA00 *breakup_models[5];
static u32 *breakup_flags_a[32];
static u32 *breakup_flags_b[16];
static u32 *breakup_flags_c[16];
static u32 *breakup_flags_d[16];
static NjObject *chain_nodes_a[5];
static NjObject *chain_nodes_b[5];

static void *boss_stat_handle;
static void *shared_handler_b;
static void *object_handle;
VoloptP02Params *volopt_p02_params;
static s32 *part_params;
BmlResource *lbl_805D4CE4;
static TUnk_8048FA00 *breakup_model;
static NjObject *model_node_44;
static NjObject *model_node_39;
static NjObject *model_node_27;
static NjObject *model_node_3c;
static NjObject *model_node_3f;
static u8 *node_44_color;
static u8 *node_27_color;
static u8 *node_3f_color;

void VoloptPartsMessage::init() {
    command = 0x18;
    size = 3;
}

void VoloptPartsMessage::send() {
    swap();
    send_subcommand((u8 *)this);
}

void VoloptPartsMessage::swap() {
    s32 i;
    ((G_ClientIDHeader *)this)->bswap();
    for (i = 0; i < 4; i++) {
        bswap_16((u16 *)&part_hp[i]);
    }
}

void VoloptPhase2Message::init() {
    command = 0x85;
    size = 5;
}

void VoloptPhase2Message::send() {
    swap();
    send_subcommand((u8 *)this);
}

s32 TObjVoloptCage::get_int_param(s32 index) {
    return volopt_cage_params->int_params[index];
}

void TBoss3VoloptP02::load_params_from_table(s32 index) {
    model = (void *)lbl_805D4CE4->models[index].model;
    texture_id = lbl_805D4CE4->models[index].m_c;
}

f32 TBoss3VoloptP02::get_float_param(s32 index) {
    return volopt_p02_params->float_params[index];
}

s32 TBoss3VoloptP02::get_int_param(s32 index) {
    return volopt_p02_params->int_params[index];
}

TBoss3VoloptP02::TBoss3VoloptP02(TObject *parent, void *set_data) : TObjEnemyCustom(parent) {
    ((TObjPlayer *)&fade)->init_and_activate();
    apply_set_data(set_data);
    init_params();
}

void TBoss3VoloptP02::init_params() {
    s32 i;
    m_name = TBoss3VoloptP02_name;
    motion_list = lbl_805D4CE4->motions;
    action_table = action_entries;
    set_field_d8((s32)action_table);
    init_collision_body_parts(this, collision_bodies, 5);
    variant = 0;
    movementParameters = &movement_params;
    recalc_combat_stats(boss_stat_handle, shared_handler_b, object_handle, 1.0f, 1.0f);
    m_b8 = 0;
    set_animation(m_b8);
    set_field_b8(m_b8);
    hp = hpmax;
    m_32e = m_2ba;
    referenceHp = hp;
    set_param(0x2E);
    update_prev_position();
    ((TBoss3Volopt *)this)->reset_photon_effect();
    load_params_from_table(0x13);
    for (i = 0; i < 4; i++) {
        arc_lines[i] = NULL;
    }
    for (s32 j = 0; j < 4; j++) {
        ring_lines[j] = NULL;
    }
    animationFlags &= ~1;
    reset_visual_state();
    volopt_p02_id = entity_id;
    heal_emitter = NULL;
    emitter = NULL;
    add_flags_2e4(4);
    if (part_params[6] > 0) {
        for (i = 0; i < 4; i++) {
            part_hp[i] = part_params[6 + i];
            part_hp_max[i] = part_hp[i];
        }
        m_388 |= 0x400000;
    }
    obj_setFlags30(this, 0x8000);
    wave_delays[2] = 0;
    wave_delays[1] = 0;
    wave_delays[0] = 0;
    clear_lobby_object_state();
}

TBoss3VoloptP02::~TBoss3VoloptP02() {
    free_collision_body_parts(this);
    if (heal_emitter != NULL) {
        heal_emitter->queue_destruction();
    }
    if (emitter != NULL) {
        emitter->queue_destruction();
    }
    destroy_children();
    destroy_sub_objects();
    __dt__13TUnk_804949A8Fv(&fade, -1);
}

void *TBoss3VoloptP02::create(void *set_data) {
    return new TBoss3VoloptP02(tl_04, set_data);
}

void TBoss3VoloptP02::load_resources() {
    TUnk_8048FA00 *model;
    s32 root;
    NjObject *nodes[5];
    NjObject *parts[5];
    s32 i;
    s32 j;
    s32 n;

    lbl_805D4CE4 = boss3_volopt_resources;
    model = (TUnk_8048FA00 *)((TAdSinglePlyChrSelectGC *)16)->alloc();
    if (model != NULL) {
        model = (TUnk_8048FA00 *)((TBreakUpMdl *)model)->init_from_model(lbl_805D4CE4->models[19].model);
    }
    breakup_model = model;
    root = lbl_805D4CE4->models[20].model;
    ((NjObject *)find_model_node(root, 0x44))->evalflags |= 8;
    ((NjObject *)find_model_node(root, 0x39))->evalflags |= 8;
    ((NjObject *)find_model_node(root, 0x27))->evalflags |= 8;
    ((NjObject *)find_model_node(root, 0x3C))->evalflags |= 8;
    ((NjObject *)find_model_node(root, 0x3F))->evalflags |= 8;
    for (i = 0; i < 5; i++) {
        nodes[i] = (NjObject *)find_model_node(root, part_breakup_node_ids[i]);
    }
    for (j = 0; j < 5; j++) {
        nodes[j]->sibling = NULL;
        model = (TUnk_8048FA00 *)((TAdSinglePlyChrSelectGC *)16)->alloc();
        if (model != NULL) {
            model = (TUnk_8048FA00 *)((TBreakUpMdl *)model)->init_from_model((s32)nodes[j]);
        }
        breakup_models[j] = model;
    }
    root = lbl_805D4CE4->models[19].model;
    for (i = 0; i < 5; i++) {
        parts[i] = (NjObject *)find_model_node(root, part_breakup_node_ids[i]);
    }
    n = collect_visible_nodes((NJS_OBJECT *)parts[0], (NJS_OBJECT **)breakup_flags_a);
    collect_visible_nodes((NJS_OBJECT *)parts[1], (NJS_OBJECT **)&breakup_flags_a[n]);
    n = collect_visible_nodes((NJS_OBJECT *)parts[2], (NJS_OBJECT **)breakup_flags_b);
    breakup_flags_b[n] = (u32 *)find_model_node(root, 0x3B);
    breakup_flags_b[n + 1] = (u32 *)find_model_node(root, 0x3C);
    breakup_flags_b[n + 2] = NULL;
    n = collect_visible_nodes((NJS_OBJECT *)parts[3], (NJS_OBJECT **)breakup_flags_c);
    breakup_flags_c[n] = (u32 *)find_model_node(root, 0x3A);
    breakup_flags_c[n + 1] = NULL;
    collect_visible_nodes((NJS_OBJECT *)parts[4], (NJS_OBJECT **)breakup_flags_d);
    model_node_44 = (NjObject *)find_model_node(root, 0x44);
    model_node_39 = (NjObject *)find_model_node(root, 0x39);
    model_node_27 = (NjObject *)find_model_node(root, 0x27);
    model_node_3c = (NjObject *)find_model_node(root, 0x3C);
    model_node_3f = (NjObject *)find_model_node(root, 0x3F);
    for (j = 0; j < 5; j++) {
        chain_nodes_a[j] = (NjObject *)find_model_node(root, chain_node_ids_a[j]);
    }
    for (j = 0; j < 5; j++) {
        chain_nodes_b[j] = (NjObject *)find_model_node(root, chain_node_ids_b[j]);
    }
    node_44_color = model_node_44->model->plist;
    node_27_color = model_node_27->model->plist;
    node_3f_color = model_node_3f->model->plist;
    boss_stat_handle = TLobby::register_boss(0x25);
    shared_handler_b = TLobby::dispatch_shared_handler_b(0x25);
    object_handle = TLobby::register_object(0x25);
    volopt_p02_params = (VoloptP02Params *)TLobby::dispatch_shared_handler_a(0x25);
    part_params = (s32 *)TLobby::dispatch_shared_handler_a(0x2A);
}

void TBoss3VoloptP02::free_resources() {
    s32 i;
    delete breakup_model;
    breakup_model = NULL;
    for (i = 0; i < 5; i++) {
        delete breakup_models[i];
        breakup_models[i] = NULL;
    }
}

#pragma push
#pragma fp_contract on
void TBoss3VoloptP02::run_task() {
    f32 wave;
    s32 previous;
    wave = sin_table_lookup(pulse_angle);
    node_44_color[6] = (s8)fabs_float(wave * pulse_color[0]);
    node_44_color[5] = (s8)fabs_float(wave * pulse_color[1]);
    node_44_color[4] = (s8)fabs_float(wave * pulse_color[2]);
    pulse_angle += pulse_speed;
    if (TObjPlayer::check_demo_mode() != 1) {
        if (has_flag_0x800() != 0) {
            vfunc_63();
        } else if (test_flag30_512() != 0) {
            if (TBoss3Volopt::is_v2_mode() != 0) {
                distribute_part_damage();
                actorFlags &= ~0x200;
                position[1] = 0.0f;
            } else {
                vfunc_62();
            }
        }
        if (obj_testFlags30(0x4000) != 0) {
            if (((TObjPlayer *)this)->add_status_effect_timer(4, -1) <= 0) {
                reset_status_effect_row(unk_284);
                obj_clearFlags30(0x4000);
            }
        } else {
            if (mode != (s32)next_action) {
                previous = state;
                if (previous != -1) {
                    saved_state = previous;
                    state = -1;
                    run_state();
                }
                m_380 = mode;
                mode = next_action;
                state = 0;
            }
            run_state();
            update_prev_position();
            ((TBoss3VoloptHiraisin *)this)->copy_position();
            submit_cursor_candidate(this, -1);
            minimap_render_dot(position, -0x5DB4, 1, 0);
            update_obstruction_fade(&fade);
            clear_all_status_effects();
        }
    }
}
#pragma pop

void TBoss3VoloptP02::run_state() {
    switch (mode) {
    case 0: fn_800472D4(); return;
    case 1: dispatch_state(); return;
    case 2: fn_80046CB8(); return;
    case 4: update_state(); return;
    case 5: update_death_sequence(); return;
    case 9: fn_800465B0(); return;
    case 10: fn_80046260(); return;
    case 11: update_pillar_heal_state(); return;
    case 7: update_fade_state(); return;
    case 12: fn_80044680(); return;
    case 3: return;
    case 6: return;
    case 8: return;
    }
}

void TBoss3VoloptP02::render() {
    if (!(actorFlags & 0x02000000) && (((ViewCulledObject *)this)->update_object_view_visibility(400.0f, 40.0f) != 0)) {
        if (fade.updateFromCamera((const f32 *)&m_2fc) != 0) {
            ((ObstructionFade *)&fade)->fade_out();
        }
        TObjFish::set_global_param(texture_id);
        select_actor_lighting((s32)this);
        TObjPlayer::toggle_particle_effect();
        push_matrix();
        model_render_flags &= ~0x400;
        post_translate_matrix(position);
        rotate_matrix_y(0, rotation_y);
        if (TObjPlayer::check_demo_mode() == 1) {
            draw_chunk_object(model);
        } else {
            draw();
        }
        pop_matrix();
        restore_scene_lighting();
        TParticleCtrl::end_effect_render();
        ((ObstructionFade *)&fade)->restore();
    }
}

void TBoss3VoloptP02::set_action(u16 target_id) {
    if ((obj_testFlags30(0x800) == 0) && !(m_388 & 0x20000) && (mode != 2)) {
        check_and_notify();
        targetId = target_id;
        m_388 &= ~1;
        vfunc_60();
    }
}

void TBoss3VoloptP02::check_and_trigger() {
    if ((obj_testFlags30(0x800) == 0) && !(m_388 & 0x40000)) {
        check_and_notify();
        m_388 &= ~1;
        ((TObjEneMe1GiGue *)this)->update_if_active(0xB);
    }
}

void TBoss3VoloptP02::set_motion(u16 target_id) {
    if ((obj_testFlags30(0x800) == 0) && !(m_388 & 0x10000) && (mode != 9)) {
        targetId = target_id;
        m_388 &= ~1;
        ((TObjEneMe1GiGue *)this)->update_if_active(9);
    }
}

void TBoss3VoloptP02::set_action_wait(u16 target_id) {
    if ((obj_testFlags30(0x800) == 0) && !(m_388 & 0x80000) && (mode != 0xA)) {
        check_and_notify();
        if (target_id != 0xFFFF) {
            targetId = target_id;
            m_388 &= ~1;
            ((TObjEneMe1GiGue *)this)->update_if_active(0xA);
        }
    }
}

void TBoss3VoloptP02::dispatch_state() {
    switch (state) {
    case 0:
        vfunc_58();
        break;
    case -1:
        break;
    }
}

void TBoss3VoloptP02::update_state() {
    s32 remaining;
    s32 next;
    switch (state) {
    case 0:
        hit_timer = 6;
        distribute_part_damage();
        state = 1;
    case 1:
        position[1] = 0.75f * sin_table_lookup(hit_timer * 0x3000);
        remaining = hit_timer - 1;
        hit_timer = remaining;
        if (remaining <= 0) {
            actorFlags &= ~0x200;
            m_388 &= ~1;
            next = m_380;
            next_action = next;
            mode = next;
            state = saved_state;
        }
        break;
    case -1:
        position[1] = 0.0f;
        break;
    }
}

void TBoss3VoloptP02::fn_800472D4() {
    switch (state) {
    case 0:
        actorFlags &= ~0x40000;
        m_b8 = 0;
        reset_visual_state();
        state = 1;
    case 1:
        advance_animation_playback(this);
        break;
    case -1:
        break;
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss3VoloptP02::fn_80046CB8() {
    Vec pos;
    Vec out;
    s32 i;
    if (m_388 & 0x20000) {
        next_action = 0;
    }
    target = get_player_by_client_id(targetId);
    switch ((s32)state) {
    case 0:
        m_b8 = 0;
        cycle_count = 0;
    case 1:
        timer = 0x5A;
        state = 2;
        push_players_out_of_radius();
    case 2:
        if (target == 0) {
            vfunc_58();
            break;
        }
        play_persistent_sound(0x4003C616, this, position, 0, 0);
        turn_toward_point((Vec *)(target + 0x38), 0x566, -0x4000);
        play_persistent_sound(0x4003A60E, this, position, 0, 0);
        advance_animation_playback(this);
        render_anim_model_at_pos();
        get_anim_node_position(0x3C, &line_origin);
        if (--*(s16 *)&timer <= 0) {
            m_b8 = 2;
            play_sound_effect(0x4003A817, position, 0, 0);
            state = 3;
        }
        collect_targets_in_arc();
        rebuild_parts();
        break;
    case 3:
        if (target == 0) {
            vfunc_58();
            break;
        }
        play_persistent_sound(0x4003C616, this, position, 0, 0);
        turn_toward_point((Vec *)(target + 0x38), 0x566, -0x4000);
        play_persistent_sound(0x4003A60E, this, position, 0, 0);
        advance_animation_playback(this);
        render_anim_model_at_pos();
        get_anim_node_position(0x3C, &line_origin);
        if (m_c0 >= 33.0f) {
            render_anim_model_at_pos();
            get_anim_node_position(0x39, &pos);
            emitter = (TObject *)create_particle_emitter(&pos, 0x1A0);
            timer = 0x1E;
            state = 4;
        }
        collect_targets_in_arc();
        rebuild_parts();
        if (objInBand((GameObj *)this, 15.0f) != 0) {
            play_sound_effect(0x4003A818, position, 0, 0);
        }
        break;
    case 4:
        if (target == 0) {
            vfunc_58();
            break;
        }
        turn_toward_point((Vec *)(target + 0x38), 0x566, -0x4000);
        play_persistent_sound(0x4003C616, this, position, 0, 0);
        render_anim_model_at_pos();
        get_anim_node_position(0x3C, &line_origin);
        push_matrix_from(identity_matrix);
        {
            Vec v = {38.0f, 31.0f, 0.0f};
            rotate_matrix_y(0, rotation_y);
            matrix_mult_vec(0, &v, &out);
        }
        vec3_add_to(&out, position);
        pop_matrix();
        if (emitter != NULL) {
            ((TNowLoading *)emitter)->copy_pos(&out);
        }
        play_persistent_sound(0x4003AD1A, this, position, 0, 0);
        if (--*(s16 *)&timer <= 0) {
            if (emitter != NULL) {
                emitter->queue_destruction();
                emitter = NULL;
            }
            wave_index = 0;
            state = 5;
        }
        collect_targets_in_arc();
        rebuild_parts();
        break;
    case 5:
        if (target == 0) {
            vfunc_58();
            break;
        }
        timer = TBoss3VoloptP02::get_int_param(5);
        collect_targets_in_arc();
        for (i = 0; i < arc_target_count; i++) {
            new TObjVoloptPillar(&arc_target_positions[i], this);
        }
        play_sound_effect(0x4003B722, position, 0, 0);
        state = 6;
        push_players_out_of_radius();
    case 6:
        play_persistent_sound(0x4003C616, this, position, 0, 0);
        if (--*(s16 *)&timer <= 0) {
            destroy_children();
            if (TBoss3Volopt::is_v2_mode() != 0) {
                timer = wave_delays[wave_index];
            } else {
                timer = 0x14;
            }
            state = 7;
        }
        break;
    case 7:
        if (--*(s16 *)&timer <= 0) {
            if (TBoss3Volopt::is_v2_mode() != 0) {
                timer = 0;
            } else {
                timer = 5;
            }
            m_b8 = 0;
            state = 8;
            play_sound_effect(0x4003A817, position, 0, 0);
        }
        break;
    case 8:
        advance_animation_playback(this);
        if (--*(s16 *)&timer <= 0) {
            if (++wave_index < 3) {
                state = 5;
            } else if (++cycle_count < 2) {
                state = 1;
            } else {
                vfunc_58();
            }
        }
        break;
    case -1:
        destroy_children();
        if (emitter != NULL) {
            emitter->queue_destruction();
            emitter = NULL;
        }
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TBoss3VoloptP02::fn_800465B0() {
    s32 duration;
    s32 i;

    if (m_388 & 0x10000) {
        next_action = 0;
    }
    duration = max_s32(TBoss3VoloptP02::get_int_param(4) + 120, 10);
    target = get_player_by_client_id(targetId);
    switch ((s32)state) {
    case 0:
        m_b8 = 0;
        m_388 &= ~0x300000;
        for (i = 0; i < 5; i++) {
            chain_nodes_a[i]->evalflags |= 8;
            chain_nodes_b[i]->evalflags |= 8;
        }
        {
            TObject *cage = (TObject *)find_entity_by_id(volopt_cage_id);
            if (cage != NULL) {
                cage->queue_destruction();
            }
        }
        state = 1;
    case 1:
        if (target != NULL) {
            s32 turn;
            advance_animation_playback(this);
            push_players_out_of_radius();
            turn = turn_toward_point((Vec *)(target + 0x38), 0x566, 0);
            play_persistent_sound(0x4003A60E, this, position, 0, 0);
            if ((turn < 0 ? -turn : turn) <= 0x566) {
                timer = 45;
                emitter = (TObject *)create_particle_emitter(position, 0x11F);
                state = 2;
            }
        }
        break;
    case 2: {
        Vec v = {0.0f, 30.0f, 35.0f};
        push_matrix_from(identity_matrix);
        post_translate_matrix(position);
        rotate_matrix_y(0, rotation_y);
        matrix_mult_vec(0, &v, &v);
        pop_matrix();
        if (emitter != NULL) {
            ((TNowLoading *)emitter)->copy_pos(&v);
        }
        if (--*(s16 *)&timer <= 0) {
            if (emitter != NULL) {
                emitter->queue_destruction();
                emitter = NULL;
            }
            new TUnk_80484A94(this, &v, targetId);
            m_388 |= 0x100000;
            m_b8 = 6;
            state = 3;
            play_sound_effect(0x4003A81C, position, 0, 0);
        }
        break;
    }
    case 3:
        if (!(m_388 & 0x100000)) {
            if (m_388 & 0x200000) {
                state = 4;
                play_sound_effect(0x4003A80B, position, 0, 0);
            } else {
                vfunc_58();
            }
        }
        break;
    case 4:
        advance_animation_playback(this);
        if (m_c0 >= 30.0f) {
            timer = duration;
            state = 5;
        }
        break;
    case 5: {
        f32 blend;
        f32 inverse;
        turn_toward_point((Vec *)(target + 0x38), 0x566, 0);
        play_persistent_sound(0x4003A30C, this, position, 0, 0);
        for (i = 0; i < 5; i++) {
            if (*(s16 *)&timer < (duration / 6) * (5 - i)) {
                chain_nodes_a[i]->evalflags &= ~8;
                chain_nodes_b[i]->evalflags &= ~8;
            } else {
                chain_nodes_a[i]->evalflags |= 8;
                chain_nodes_b[i]->evalflags |= 8;
            }
        }
        blend = 1.5f - (f32)*(s16 *)&timer * (1.5f / (f32)duration);
        blend = blend < 1.0f ? blend : 1.0f;
        inverse = 1.0f - blend;
        for (i = 0; i < 3; i++) {
            pulse_color[i] = inverse * pulse_color_start[i] + blend * pulse_color_end[i];
        }
        pulse_speed = (s32)(inverse * (f32)pulse_speeds[0] + blend * (f32)pulse_speeds[1]);
        if (--*(s16 *)&timer <= 0) {
            Vec v = {0.0f, 30.0f, 35.0f};
            push_matrix_from(identity_matrix);
            post_translate_matrix(position);
            rotate_matrix_y(0, rotation_y);
            matrix_mult_vec(0, &v, &v);
            pop_matrix();
            emitter = (TObject *)create_particle_emitter(&v, 0x11F);
            timer = 15;
            state = 6;
        }
        break;
    }
    case 6:
        play_persistent_sound(0x4003A81B, this, position, 0, 0);
        if (--*(s16 *)&timer <= 0) {
            TObjEnemy *cage;
            if (emitter != NULL) {
                emitter->queue_destruction();
                emitter = NULL;
            }
            cage = (TObjEnemy *)find_entity_by_id(volopt_cage_id);
            if (cage != NULL) {
                fn_80048C04((TObjVoloptCage *)cage);
                timer = 30;
                state = 7;
                render_anim_model_at_pos();
                for (i = 0; i < 10; i++) {
                    s32 dir = i < 5 ? 1 : -1;
                    get_anim_node_position(chain_node_ids[i], &chain_positions[i]);
                    new TUnk_80484840(&chain_positions[i], (Vec *)&cage->m_2fc, dir, timer);
                }
                play_sound_effect(0x4003B20D, position, -10, 0);
            } else {
                state = 8;
            }
        }
        break;
    case 7:
        render_anim_model_at_pos();
        for (s32 j = 0; j < 10; j++) {
            get_anim_node_position(chain_node_ids[j], &chain_positions[j]);
        }
        if (--*(s16 *)&timer <= 0) {
            state = 8;
        }
        break;
    case 8:
        advance_animation_playback(this);
        if (m_b4 != 4) {
            vfunc_58();
        }
        break;
    case -1:
        if (emitter != NULL) {
            emitter->queue_destruction();
            emitter = NULL;
        }
        break;
    }
}
#pragma pop

void TBoss3VoloptP02::check_and_notify() {
    TObjVoloptCage *cage = (TObjVoloptCage *)find_entity_by_id(volopt_cage_id);
    if (cage != NULL) {
        fn_80048C04(cage);
    }
}

#pragma push
#pragma opt_loop_invariants off
void TBoss3VoloptP02::fn_80046260() {
    s32 n;
    s32 i;

    if (m_388 & 0x80000) {
        next_action = 0;
    }
    target = get_player_by_client_id(targetId);
    switch ((s32)state) {
    case 0:
        timer = 0x3C;
        volley_count = 0;
        state = 1;
    case 1:
        if (target != NULL) {
            Vec v = *(Vec *)(target + 0x38);
            subtract_vector(&v, position);
            rotation_y = approach_angle_limited(rotation_y, (s32)((65536.0 / (2.0 * 3.141592f)) * atan2_float(v.x, v.z)) + 0x8000, 0x566);
        }
        if (--*(s16 *)&timer <= 0) {
            m_b8 = 7;
            advance_animation_playback(this);
            state = 2;
        }
        push_players_out_of_radius();
        break;
    case 2:
        advance_animation_playback(this);
        if (objInBand((GameObj *)this, 15.0f) != 0) {
            play_sound_effect(0x4003A811, position, 0, 0);
        }
        if (m_c0 >= 22.0f) {
            timer = 0xA;
            state = 3;
        }
        break;
    case 3:
        if (--*(s16 *)&timer <= 0) {
            state = 4;
        }
        break;
    case 4: {
        Vec pos;
        s16 count;
        volley_count++;
        render_anim_model_at_pos();
        collect_targets_in_front();
        for (i = 0; i < (count = front_target_count); i++) {
            get_anim_node_position(volley_node_ids[i], &pos);
            new TUnk_80484AFC(this, &pos, rotation_y + 0x8000, front_target_ids[i]);
        }
        if (count > 0) {
            play_sound_effect(0x4003AD13, position, 0, 0);
        }
        timer = 0xF;
        state = 5;
    }
    case 5:
        if (--*(s16 *)&timer <= 0) {
            s32 ph = get_main_phase();
            n = 4;
            if (ph == 0xF) {
                n = 2;
            }
            if (volley_count < n) {
                state = 4;
            } else {
                state = 6;
                play_sound_effect(0x4003A312, position, 0, 0);
            }
        }
        break;
    case 6:
        advance_animation_playback(this);
        if (objInBand((GameObj *)this, 35.0f) != 0) {
            play_sound_effect(0x4003A312, position, 0, 0);
        }
        if (m_b4 != 4) {
            vfunc_58();
        }
        break;
    case -1:
        break;
    }
}

#pragma pop

void TBoss3VoloptP02::update_pillar_heal_state() {
    if (m_388 & 0x40000) {
        next_action = 0;
    }
    switch ((s32)state) {
    case 0:
        m_b8 = 5;
        state = 1;
        push_players_out_of_radius();
        play_sound_effect(0x4003A817, position, 0, 0);
        break;
    case 1: {
        f32 f;
        f32 t;
        advance_animation_playback(this);
        if (objInBand((GameObj *)this, 20.0f) != 0) {
            play_sound_effect(0x4003A80B, position, 0, 0);
        }
        t = 0.083333336f * (m_c0 - 18.0f);
        f = min_f32(max_f32(t, 0.0f), 1.0f);
        node_27_color[7] = (s8)(255.0f * f);
        if (m_c0 >= 38.0f) {
            Vec out;
            push_matrix_from(identity_matrix);
            Vec v = {-38.0f, 31.0f, 0.0f};
            rotate_matrix_y(0, rotation_y);
            matrix_mult_vec(0, &v, &out);
            vec3_add_to(&out, position);
            pop_matrix();
            heal_emitter = (TObject *)create_particle_emitter(&out, 0x1A1);
            timer = 0x1E;
            state = 2;
        }
        break;
    }
    case 2: {
        play_sound_effect(0x4003A819, position, 0, 0);
        if (--*(s16 *)&timer <= 0) {
            s32 n;
            if (heal_emitter != NULL) {
                heal_emitter->queue_destruction();
                heal_emitter = NULL;
            }
            n = TBoss3VoloptP02::get_int_param(3) / 5;
            TBoss3Volopt__sub_800FD344((s32)&m_2fc, (s32)(0xFF00FF00), 0x1E, (void *)"HP", (void *)n);
            hp = min_s32(hp + n, hpmax);
            for (s32 i = 0; i < 4; i++) {
                if (part_hp[i] > 0) {
                    s32 v = part_hp[i] + n;
                    s32 lim = part_hp_max[i];
                    if (v < lim) {
                        lim = v;
                    }
                    part_hp[i] = lim;
                }
            }
            timer = 0x3C;
            hp = min_s32(hp + 0xA, hpmax);
            heal_emitter = (TObject *)create_particle_emitter(position, 0x1A2);
            state = 3;
            play_sound_effect(0x4002AB0E, position, 0, 0);
        }
        break;
    }
    case 3: {
        if (--*(s16 *)&timer <= 0) {
            if (heal_emitter != NULL) {
                heal_emitter->queue_destruction();
                heal_emitter = NULL;
            }
            state = 4;
            play_sound_effect(0x4003A817, position, 0, 0);
        }
        break;
    }
    case 4:
        advance_animation_playback(this);
        if (m_b4 != 4U) {
            vfunc_58();
        }
        break;
    case -1:
        if (heal_emitter != NULL) {
            heal_emitter->queue_destruction();
            heal_emitter = NULL;
        }
        break;
    }
}

#pragma push
#pragma fp_contract on
void TBoss3VoloptP02::update_fade_state() {
    f32 frame;
    s8 alpha;
    switch (state) {
    case 0:
        actorFlags |= 0x40000;
        m_b8 = 8;
        state = 2;
    case 2:
        advance_animation_playback(this);
        frame = m_c0;
        alpha = 0;
        if (frame >= 20.0f) {
            alpha = (s8)(13.421053f * (frame - 20.0f));
        }
        node_44_color[7] = alpha;
        node_3f_color[7] = alpha;
        pulse_angle = 0x4000;
        position[1] = 25.0f * -((0.025641026f * m_c0) - 1.0f);
        if (m_c0 >= 38.0f) {
            position[1] = 0.0f;
            m_388 &= ~1;
            vfunc_58();
            break;
        }
    case 1:
        break;
    case -1:
        actorFlags &= ~0x40000;
        break;
    }
}
#pragma pop

void TBoss3VoloptP02::update_death_sequence() {
    VoloptCameraCommand cam;
    switch ((s32)state) {
    case 0:
        destroy_children();
        m_b8 = 0;
        advance_animation_playback(this);
        timer = 0x3C;
        TCameraCtrl__sub_8006A044(0xB4, 0.04f);
        state = 1;
        TBoss3Volopt::start_rumble();
        break;
    case 1:
        cam.b = 1;
        cam.a = 2;
        cam.c = 0;
        cam.d = 0.0f;
        cam.e = 1.0f;
        activate_camera_mode(5, 0.0f);
        ((TCameraCtrl *)&cam)->cache_target_and_forward(0x160A);
        rotation_y = 0;
        set_scripted_camera_pose(&boss3_volopt_spawn_pos, &boss3_volopt_spawn_pos, &rotation_x);
        TObjPlayer::freeze_all_players();
        TWindowCtrl::init_all_slots();
        state = 2;
        break;
    case 2:
        if ((*(u16 *)(get_scripted_camera_playback((*(s16 *)&timer)--) + 2) & 1) || *(s16 *)&timer < 0) {
            restore_player_cameras();
            TWindowCtrl::init_all_slots2();
            TObjPlayer__sub_801BA42C();
            model_node_3f->evalflags |= 8;
            model_node_44->evalflags |= 8;
            m_b8 = 4;
            state = 3;
        }
        spawn_ambient_particles();
        break;
    case 3:
        advance_animation_playback(this);
        spawn_ambient_particles();
        position[1] = 0.5319149f * m_c0;
        if (m_c0 >= 47.0f) {
            TBoss3Volopt::create_breakup_mdl((s32)breakup_model, (s32)&death_breakup_params, texture_id, (s32)&m_2fc, rotation_y);
            ((TObjPlayer *)&m_2fc)->trigger_dell_biter_events();
            ((TObjPlayer *)this)->refresh_lobby_state();
            volopt_death_active = 1;
            if (TBoss3Volopt::is_death_active() != 0) {
                send_entity_set_flags();
            }
            TBoss3Volopt::update_phase();
            TBoss3Volopt::stop_rumble();
            state = 4;
            timer = 0x10;
        }
        break;
    case 4:
        if (!(*(s16 *)&timer & 3)) {
            play_sound_effect(0x4003A80F, position, 0, 1);
        }
        if (--*(s16 *)&timer <= 0) {
            TObjPlayer__sub_801BA42C();
            queue_destruction();
        }
        break;
    case -1:
        return;
    }
    play_persistent_sound(0x4003AD21, this, 0, 0, 0);
}

#pragma push
#pragma fp_contract on
void TBoss3VoloptP02::spawn_ambient_particles() {
    Vec pos;
    f32 radius;
    s32 angle;
    if (actor_frame_tick & 1) {
        radius = (10.0f * ((1.0f / 32768.0f) * (f32)rand())) + 35.0f;
        angle = (s32)(182.04445f * (360.0f * ((1.0f / 32768.0f) * (f32)rand())));
        pos.x = (radius * cos_table_lookup(angle)) + position[0];
        pos.y = (30.0f * ((1.0f / 32768.0f) * (f32)rand())) + 20.0f;
        pos.z = (radius * sin_table_lookup(angle)) + position[2];
        spawn_particle_effect(&pos, 0xFB);
    }
    play_persistent_sound(0x4003AD21, this, position, 0, 0);
}
#pragma pop

void TBoss3Volopt::create_cage(u16 target_id) {
    targetId = target_id;
    target = get_player_by_client_id(targetId);
    if (target != 0) {
        new TObjVoloptCage(this, target_id, volopt_cage_id, volopt_cage_group);
        m_388 |= 0x200000;
    }
}

void TBoss3VoloptP02::reset_visual_state() {
    pulse_speed = pulse_speeds[0];
    pulse_color[0] = pulse_color_start[0];
    pulse_color[1] = pulse_color_start[1];
    pulse_color[2] = pulse_color_start[2];
    model_node_3f->evalflags &= ~8;
    model_node_44->evalflags &= ~8;
    node_44_color[7] = 0xff;
    node_3f_color[7] = 0xff;
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
void TBoss3VoloptP02::spawn_breakup_models() {
    Vec pos;
    u32 flags = m_388;
    if (!(flags & 0x10000)) {
        m_388 = flags | 0x10000;
        render_anim_model_at_pos();
        get_anim_node_position(2, &pos);
        TBoss3Volopt::create_breakup_mdl((s32)breakup_models[0], (s32)&part_breakup_params, texture_id, (s32)&pos, rotation_y);
        get_anim_node_position(0x12, &pos);
        TBoss3Volopt::create_breakup_mdl((s32)breakup_models[1], (s32)&part_breakup_params, texture_id, (s32)&pos, rotation_y);
        hide_model_nodes((NJS_OBJECT **)breakup_flags_a);
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
void TBoss3VoloptP02::fn_800457A0() {
    Vec pos;
    u32 flags = m_388;
    if (!(flags & 0x20000)) {
        m_388 = flags | 0x20000;
        m_a4[1].flags &= ~0x10000001;
        render_anim_model_at_pos();
        get_anim_node_position(0x32, &pos);
        TBoss3Volopt::create_breakup_mdl((s32)breakup_models[2], (s32)&part_breakup_params, texture_id, (s32)&pos, rotation_y);
        hide_model_nodes((NJS_OBJECT **)breakup_flags_b);
        play_sound_effect(0x4003A80F, position, 0, 1);
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
void TBoss3VoloptP02::fn_800456E4() {
    Vec pos;
    u32 flags = m_388;
    if (!(flags & 0x40000)) {
        m_388 = flags | 0x40000;
        m_a4[2].flags &= ~0x10000001;
        render_anim_model_at_pos();
        get_anim_node_position(0x22, &pos);
        TBoss3Volopt::create_breakup_mdl((s32)breakup_models[3], (s32)&part_breakup_params, texture_id, (s32)&pos, rotation_y);
        hide_model_nodes((NJS_OBJECT **)breakup_flags_c);
        play_sound_effect(0x4003A80F, position, 0, 1);
    }
}
#pragma pop

void TBoss3VoloptP02::trigger_breakup() {
    Vec pos;
    u32 flags = m_388;
    if (!(flags & 0x80000)) {
        m_388 = flags | 0x80000;
        m_a4[3].flags &= ~0x10000001;
        render_anim_model_at_pos();
        get_anim_node_position(0x29, &pos);
        TBoss3Volopt::create_breakup_mdl((s32)breakup_models[4], (s32)&part_breakup_params, texture_id, (s32)&m_2fc, rotation_y);
        hide_model_nodes((NJS_OBJECT **)breakup_flags_d);
        play_sound_effect(0x4003A80F, position, 0, 1);
    }
}

// Not called anywhere in the game, so the linker drops it. It is the per-part
// form of TObjEneDubchik::sub_800A8A7C (same m_388 broken-part bits, same
// hide_model_nodes/show_model_nodes pair), and its use of three .bss statics is
// what makes this file's .bss pool before load_resources does.
void TBoss3VoloptP02::apply_broken_part_visibility() {
    if (m_388 & 0x10000) {
        hide_model_nodes((NJS_OBJECT **)breakup_flags_a);
    } else {
        show_model_nodes((NJS_OBJECT **)breakup_flags_a);
    }
    if (m_388 & 0x20000) {
        hide_model_nodes((NJS_OBJECT **)breakup_flags_b);
    } else {
        show_model_nodes((NJS_OBJECT **)breakup_flags_b);
    }
    if (m_388 & 0x40000) {
        hide_model_nodes((NJS_OBJECT **)breakup_flags_c);
    } else {
        show_model_nodes((NJS_OBJECT **)breakup_flags_c);
    }
    if (m_388 & 0x80000) {
        hide_model_nodes((NJS_OBJECT **)breakup_flags_d);
    } else {
        show_model_nodes((NJS_OBJECT **)breakup_flags_d);
    }
}

s16 TBoss3VoloptP02::collect_targets_in_front() {
    s32 i;
    TObjPlayer *player;
    front_target_count = 0;
    for (i = 0; i < lbl_805D586C; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player == NULL || get_entity_id(player) >= 0x1000) {
            break;
        }
        if (((TBoss3Volopt *)player)->get_field_3e0() != 0xD) {
            continue;
        }
        if (player->actorFlags & 0x02000800) {
            continue;
        }
        {
            Vec v = *(Vec *)&player->m_2fc;
            subtract_vector(&v, &m_2fc);
            if (angle_difference_abs(rotation_y + 0x8000, (s32)((65536.0 / (2.0 * 3.141592f)) * atan2_float(v.x, v.z))) > 0x1C71) {
                continue;
            }
        }
        front_target_ids[front_target_count++] = get_entity_id(player);
        if (front_target_count >= 4) {
            break;
        }
    }
    return front_target_count;
}

u16 TBoss3VoloptP02::find_facing_player() {
    s32 best = 0x10000;
    u16 id = 0xFFFF;
    s32 i;
    TObjPlayer *player;
    s32 d;
    for (i = 0; i < lbl_805D586C; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player == NULL || get_entity_id(player) >= 0x1000) {
            break;
        }
        if (((TBoss3Volopt *)player)->get_field_3e0() != 0xD) {
            continue;
        }
        if (player->actorFlags & 0x02000800) {
            continue;
        }
        {
            Vec v = *(Vec *)&player->m_2fc;
            subtract_vector(&v, &m_2fc);
            d = ABS(angle_difference_abs(rotation_y + 0x8000, (s32)((65536.0 / (2.0 * 3.141592f)) * atan2_float(v.x, v.z))));
            if (d <= best) {
                best = d;
                id = get_entity_id(player);
            }
        }
    }
    return id;
}

void TBoss3VoloptP02::broadcast_values() {
    VoloptPartsMessage message;
    s32 i;
    message.init();
    message.entity_id = entity_id;
    for (i = 0; i < 4; i++) {
        message.part_hp[i] = part_hp[i];
    }
    message.send();
}

extern "C" void handle_6x18_vol_opt2_boss_actions(VoloptPartsMessage *message) {
    TBoss3VoloptP02 *boss;
    s32 i;
    u32 bit;
    s32 j;
    message->swap();
    boss = (TBoss3VoloptP02 *)find_entity_by_id(message->entity_id);
    if (boss != NULL) {
        for (i = 0; i < 4; i++) {
            boss->part_hp[i] = message->part_hp[i];
        }
        bit = 0x10000;
        for (j = 0; j < 4; j++) {
            if (!(boss->m_388 & bit) && boss->part_hp[j] <= 0) {
                switch (j) {
                case 0:
                    boss->spawn_breakup_models();
                    break;
                case 1:
                    boss->fn_800457A0();
                    break;
                case 2:
                    boss->fn_800456E4();
                    break;
                case 3:
                    boss->trigger_breakup();
                    break;
                }
            }
            bit <<= 1;
        }
    }
}

void TBoss3VoloptP02::vfunc_79() {}

void TBoss3VoloptP02::push_players_out_of_radius() {
    s32 i;
    TObjPlayer *player;
    s32 angle;
    for (i = 0; i < lbl_805D586C; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player == NULL) {
            continue;
        }
        get_entity_id(player);
        if (TObjRoomId__sub_801A1DB8() != 0) {
            continue;
        }
        if (xz_distance_squared((Vec *)position, (Vec *)player->position) <= 1225.0f) {
            Vec v = *(Vec *)player->position;
            subtract_vector(&v, position);
            angle = (s32)((65536.0 / (2.0 * 3.141592f)) * atan2_float(v.z, v.x));
            v.x = 50.0f * cos_table_lookup(angle);
            v.z = 50.0f * sin_table_lookup(angle);
            vec3_add_to(&v, position);
            player->position[0] = v.x;
            player->position[2] = v.z;
        }
    }
}

void TBoss3VoloptP02::destroy_children() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (arc_lines[i] != 0) {
            arc_lines[i]->queue_destruction();
            arc_lines[i] = 0;
        }
    }
}

void TBoss3VoloptP02::rebuild_parts() {
    s32 i;
    for (i = 0; i < arc_target_count; i++) {
        if (arc_lines[i] != 0) {
            arc_lines[i]->queue_destruction();
        }
        arc_lines[i] = new TUnk_80484870(&line_origin, &arc_target_positions[i]);
    }
    for (; i < 4; i++) {
        if (arc_lines[i] != 0) {
            arc_lines[i]->queue_destruction();
            arc_lines[i] = 0;
        }
    }
}

void TBoss3VoloptP02::collect_targets_in_arc() {
    s32 phase2;
    s32 limit;
    s32 i;
    TObjPlayer *player;
    phase2 = TBoss3Volopt::is_v2_mode();
    limit = 0x31C7;
    if (phase2 != 0) {
        limit = 0x471C;
    }
    arc_target_count = 0;
    for (i = 0; i < lbl_805D586C; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player == NULL) {
            continue;
        }
        if (get_entity_id(player) >= 0x1000) {
            continue;
        }
        if (player->actorFlags & 0x02000800) {
            continue;
        }
        {
            Vec v = *(Vec *)&player->m_2fc;
            subtract_vector(&v, &m_2fc);
            if (angle_difference_abs(rotation_y + 0x4000, (s32)((65536.0 / (2.0 * 3.141592f)) * atan2_float(v.x, v.z))) > limit) {
                continue;
            }
        }
        arc_target_ids[arc_target_count] = get_entity_id(player);
        VecCopy(&arc_target_positions[arc_target_count], (Vec *)player->position);
        arc_target_count++;
        if (arc_target_count >= 4) {
            break;
        }
    }
}

s32 TBoss3VoloptP02::count_dead_parts() {
    s32 count = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (part_hp[i] <= 0) {
            count++;
        }
    }
    return count;
}

f32 TBoss3VoloptP02::receive_physical_attack(void *source, f32 damage) {
    u32 mask = 0x800000;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (m_a4[i].flags & 0x04000000) {
            m_388 |= mask;
        }
        mask <<= 1;
    }
    return TUnk_804806E8::receive_physical_attack(source, damage);
}

f32 TBoss3VoloptP02::receive_direct_attack(void *source, DirectAttackPayload payload, void *collider, s32, s32) {
    u32 mask = 0x800000;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (m_a4[i].flags & 0x04000000) {
            m_388 |= mask;
        }
        mask <<= 1;
    }
    return TUnk_804806E8::receive_direct_attack(source, payload, collider, -1, -1);
}

#pragma push
#pragma fp_contract on
void TBoss3VoloptP02::send_random_params() {
    VoloptPhase2Message msg;
    s32 i;
    f32 base;
    f32 range;
    msg.init();
    msg.mode = 0;
    for (i = 0; i < 3; i++) {
        base = TBoss3VoloptP02::get_float_param(4);
        range = TBoss3VoloptP02::get_float_param(5);
        { f32 r = (1.0f / 32768.0f) * (f32)rand(); msg.delays[i] = (s16)(r * range + base); }
    }
    msg.send();
}
#pragma pop

void TBoss3VoloptP02::copy_phase2_positions_to_global(const VoloptPhase2Message *message) {
    s32 i;
    for (i = 0; i < 3; i++) {
        wave_delays[i] = message->delays[i];
    }
}

void TBoss3VoloptP02::apply_hit_reaction(f32 delay) {
    if ((obj_testFlags30(0x800) == 0) && !(m_388 & 0x20000) && (mode != 0xC)) {
        check_and_notify();
        ring_radius = 55.0f + delay;
        m_388 &= ~1;
        ((TObjEneMe1GiGue *)this)->update_if_active(0xC);
    }
}

#pragma push
#pragma fp_contract on
void TBoss3VoloptP02::fn_80044680() {
    Vec pos;
    Vec out;
    s32 i;
    s32 j;
    s32 k;

    if (m_388 & 0x20000) {
        next_action = 0;
    }
    switch ((s32)state) {
    case 0:
        advance_animation_playback(this);
        m_b8 = 2;
        cycle_count = 0;
        ring_angle = 0;
        VecCopy(&line_origin, (Vec *)position);
        line_origin.y = 80.0f;
        ring_phase = 0;
        state = 1;
        break;
    case 1:
        play_persistent_sound(0x4003C616, this, position, 0, 0);
        advance_animation_playback(this);
        if (m_c0 >= 33.0f) {
            render_anim_model_at_pos();
            get_anim_node_position(0x39, &pos);
            emitter = (TObject *)create_particle_emitter(&pos, 0x1A0);
            timer = 0x1E;
            state = 2;
        }
        if (objInBand((GameObj *)this, 15.0f) != 0) {
            play_sound_effect(0x4003A818, position, 0, 0);
        }
        break;
    case 2: {
        play_persistent_sound(0x4003C616, this, position, 0, 0);
        push_matrix_from(identity_matrix);
        Vec v = {38.0f, 31.0f, 0.0f};
        rotate_matrix_y(0, rotation_y);
        matrix_mult_vec(0, &v, &out);
        vec3_add_to(&out, position);
        pop_matrix();
        if (emitter != NULL) {
            ((TNowLoading *)emitter)->copy_pos(&out);
        }
        play_persistent_sound(0x4003AD1A, this, position, 0, 0);
        if (--*(s16 *)&timer <= 0) {
            if (emitter != NULL) {
                emitter->queue_destruction();
                emitter = NULL;
            }
            wave_index = 0;
            timer = 0x12C;
            state = 3;
        }
        break;
    }
    case 3:
        state = 4;
        push_players_out_of_radius();
        ring_timer = wave_index == 0 ? TObjVoloptCage::get_int_param(1) * 0x180 : 0x1555;
    case 4: {
        play_persistent_sound(0x4003C616, this, position, 0, 0);
        ring_angle += 0x180;
        ring_timer -= 0x180;
        if (wave_index == 0) {
            ring_phase += 0x400;
            ring_radius = 25.0f * sin_table_lookup(ring_phase) + 75.0f;
        }
        push_matrix_from(identity_matrix);
        Vec v = {0.0f, 0.0f, 0.0f};
        v.z = ring_radius;
        rotate_matrix_y(0, ring_angle);
        for (i = 0; i < 4; i++) {
            matrix_mult_vec(0, &v, &ring_positions[i]);
            vec3_add_to(&ring_positions[i], position);
            rotate_matrix_y(0, 0x4000);
        }
        pop_matrix();
        if (ring_timer <= 0) {
            if (wave_index == 0) {
                for (i = 0; i < 4; i++) {
                    u8 *player = get_player_by_client_id(i);
                    if (player != NULL) {
                        for (j = 0; j < 4; j++) {
                            if (xz_distance_squared((Vec *)(player + 0x38), &ring_positions[j]) <= 100.0f) {
                                i = 4;
                                state = 5;
                                break;
                            }
                        }
                    }
                }
                if (--*(s16 *)&timer <= 0) {
                    state = 5;
                }
            } else {
                state = 5;
            }
        }
        spawn_sub_objects();
        break;
    }
    case 5:
        timer = TBoss3VoloptP02::get_int_param(5);
        for (k = 0; k < 4; k++) {
            new TObjVoloptPillar(&ring_positions[k], this);
        }
        play_sound_effect(0x4003B722, position, 0, 0);
        state = 6;
        push_players_out_of_radius();
    case 6:
        play_persistent_sound(0x4003C616, this, position, 0, 0);
        if (--*(s16 *)&timer <= 0) {
            timer = 0x14;
            state = 7;
        }
        spawn_sub_objects();
        break;
    case 7:
        if (--*(s16 *)&timer <= 0) {
            timer = 5;
            state = 8;
        }
        spawn_sub_objects();
        break;
    case 8:
        if (--*(s16 *)&timer <= 0) {
            if (++wave_index < 3) {
                state = 3;
            } else {
                play_sound_effect(0x4003A817, position, 0, 0);
                vfunc_58();
                break;
            }
        }
        spawn_sub_objects();
        break;
    case -1:
        destroy_sub_objects();
        if (emitter != NULL) {
            emitter->queue_destruction();
            emitter = NULL;
        }
        break;
    }
}
#pragma pop

void TBoss3VoloptP02::spawn_sub_objects() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (ring_lines[i] == 0) {
            ring_lines[i] = new TUnk_80484870(&line_origin, &ring_positions[i]);
        }
    }
}

void TBoss3VoloptP02::destroy_sub_objects() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (ring_lines[i] != 0) {
            ring_lines[i]->queue_destruction();
            ring_lines[i] = 0;
        }
    }
}

void TBoss3VoloptP02::distribute_part_damage() {
    s32 v;
    u32 flags;
    s32 n;
    u32 bit;
    s32 i;
    s32 dmg;
    u32 mask;
    actorFlags &= ~0x200000;
    flags = m_388;
    if (flags & 0x400000) {
        n = 0;
        bit = 0x800000;
        for (i = 0; i < 4; i++) {
            if (part_hp[i] > 0) {
                if (flags & bit) {
                    n++;
                }
                bit <<= 1;
            }
        }
        if (n > 0) {
            mask = 0x800000;
            dmg = (n + (referenceHp - hp) - 1) / n;
            dmg = dmg > 0 ? dmg : 0;
            for (i = 0; i < 4; i++) {
                if (m_388 & mask) {
                    m_388 &= ~mask;
                    s16 *p = &part_hp[i];
                    v = *p - dmg;
                    *p = v > 0 ? v : 0;
                }
                mask <<= 1;
            }
            broadcast_values();
        }
    }
    referenceHp = hp;
}

void TBoss3VoloptP02::set_flag_08000000() {
    set_indexed_flags(0, 0x08000000);
}

void TBoss3VoloptP02::clear_flag_08000000() {
    clear_player_status_flag(0, 0x08000000);
}
