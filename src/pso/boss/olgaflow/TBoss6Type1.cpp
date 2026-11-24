#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/BmlResource.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/boss/olgaflow/OlgaFlowActions.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/boss/olgaflow/TBoss6SwordShot.h"
#include "types.h"
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/system/vector.h"
#include "pso/system/SoundEffect.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/BattleParameters.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/boss/olgaflow/TBoss6Type1_802B20C0.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/boss/olgaflow/TBoss6Zanzo.h"
#include "pso/boss/olgaflow/TBoss6Mine.h"
#include "pso/boss/darkfalz/TObjDFHorming.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz_802AABEC.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D8F74.h"
#include <stdlib.h>
#include "pso/render/render_util.h"


#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_803E18C0.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/PlayerSlots.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/MatrixStack.h"
#include "pso/camera/TCameraFollow.h"
#include "pso/object/base/TObjBase.h"









// A row of TBoss6Type1__effect_slot_table: the emitter's effect and the node it follows (-1: position).
struct Boss6EffectSlotDesc { s32 effect_id; s32 node; };













// A row of TBoss6Type1__part_position_sources: kind 1 reads node_points, 0 arm_node_positions, at idx.
struct Boss6PartPositionSource { s32 kind; s32 idx; };












// The two motions and frames draw_model_blend_motion blends.
struct Boss6BlendMotion { AnimationMotion *motions[2]; f32 frames[2]; };

// init_collision_body_parts copies these 7 spheres in TBoss6Type1__ct.
CollisionBody TBoss6Type1__collision_body_parts[7] = {
    {{0.0f, 0.0f, 0.0f}, 35.0f, 0.0f, 0, 0x801B, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 50.0f, 0.0f, 0, 0x801B, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x801B, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x801B, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x801B, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x801B, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x801B, {0.0f, 0.0f, 0.0f}, 0.0f},
};
__declspec(section ".data") s32 boss6_type1_part_model_ids[2] = {3, 6};

extern "C" {
Boss6Type1MotionSet TBoss6Type1__motion_set_table[21] = {
    {0, 0, 44, 45}, {0, 1, 42, 45}, {0, 2, 44, 56}, {2, 0, 40, 41}, {2, 2, 44, 53},
    {2, 0, 37, 38}, {2, 2, 37, 38}, {2, 8, 29, 30}, {0, 8, 13, 14}, {2, 1, 47, 48},
    {2, 2, 44, 22}, {2, 2, 44, 23}, {2, 2, 44, 43}, {2, 2, 44, 46}, {2, 2, 51, 52},
    {2, 16, 44, 17}, {0, 16, 44, 18}, {2, 18, 44, 19}, {0, 18, 44, 20}, {2, 2, 44, 21},
    {2, 2, 44, 15},
};

const s8 boss6_type1_low_attack_heights[2] = { 0x12, 0x0A };
const s8 boss6_type1_mid_attack_heights[2] = { 0x12, -2 };
static const s32 boss6_type1_slot_count = 24;
static const s32 boss6_type1_sway_target_min = 256;
static const s32 boss6_type1_sway_target_range = 64;
static const s32 boss6_type1_sway_delay_min = 20;
static const s32 boss6_type1_sway_delay_range = 20;
static const s32 boss6_type1_anim_count = 2;
static const s32 boss6_type1_main_anim_index = 1;

inline const s32 &slot_count() { return boss6_type1_slot_count; }
inline const s32 &sway_target_min() { return boss6_type1_sway_target_min; }
inline const s32 &sway_target_range() { return boss6_type1_sway_target_range; }
inline const s32 &sway_delay_min() { return boss6_type1_sway_delay_min; }
inline const s32 &sway_delay_range() { return boss6_type1_sway_delay_range; }
inline const s32 &anim_count() { return boss6_type1_anim_count; }
inline const s32 &main_anim_index() { return boss6_type1_main_anim_index; }



}



struct ByteBlock_C_boss6_1 { u8 bytes[0xc]; };

#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/object/TObjControl.h"


// The record exchange_object_state reads and writes.
struct TBoss6Type1StateRecord { s32 flags; s16 pad_04; s16 value; s32 pad_08; };


// The class name and the tables TBoss6Type1's code reads, in .rodata order.
const char TBoss6Type1__class_name_string[] = "TBoss6Type1";
const char *TBoss6Type1__name = TBoss6Type1__class_name_string;
const Vec boss6_type1_spawn_position = {0.0f, 300.0f, 280.0f};
const Vec boss6_type1_base_position = {0.0f, 100.0f, 280.0f};
const s32 TBoss6Type1__param_table[12] = {20, 20, 20, 20, 200, 200, 200, 200, 90, 180, 7, 7};
const s32 boss6_type1_spawn_rotation[3] = {0x8000, 0, 0};
const Boss6EffectSlotDesc TBoss6Type1__effect_slot_table[4] = {{0x210, -1}, {0x211, -1}, {0x215, 7}, {0x21E, -1}};
// Node -1 ends a node list.
const ModelNodePositionEntry boss6_type1_model_node_desc[12] = {
    {0x06, {0.0f, 0.0f, 0.0f}},
    {0x09, {20.0f, 20.0f, 0.0f}},
    {0x10, {0.0f, 0.0f, 0.0f}},
    {0x23, {0.0f, 0.0f, 0.0f}},
    {0x24, {0.0f, 0.0f, 0.0f}},
    {0x27, {0.0f, 0.0f, 0.0f}},
    {0x28, {0.0f, 0.0f, 0.0f}},
    {0x2A, {0.0f, 0.0f, 0.0f}},
    {0x37, {0.0f, 0.0f, 0.0f}},
    {0x38, {0.0f, 0.0f, 0.0f}},
    {0x38, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
const ModelNodePositionEntry boss6_type1_model_node_desc_b[8] = {
    {0x0F, {25.0f, 0.0f, 0.0f}},
    {0x1C, {25.0f, 0.0f, 0.0f}},
    {0x29, {25.0f, 0.0f, 0.0f}},
    {0x36, {25.0f, 0.0f, 0.0f}},
    {0x3C, {25.0f, 0.0f, 0.0f}},
    {0x4D, {0.0f, 0.0f, 0.0f}},
    {0x53, {0.0f, 0.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
const Boss6StripDesc boss6_type1_build_table[2] = {{3, 1, 0}, {6, 1, 0}};
const Boss6StripDesc boss6_type1_scroll_strip_descs[1] = {{0, 0, 0}};
const Vec boss6_type1_origin = {0.0f, 0.0f, 0.0f};
const s32 boss6_type1_random_action_table[5] = {4, 0x16, 5, 8, 2};
const Boss6Type1MotionState boss6_type1_initial_motion_set = {2, 0};
const Boss6PartMotion boss6_type1_initial_part_motion = {NULL, 0.0f, 0.5f, 0.0f, 1.0f / 15.0f, NULL, 0.0f};
const Boss6PartPositionSource TBoss6Type1__part_position_sources[7] = {{1, 2}, {1, 1}, {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}};
const f32 TBoss6Type1__sword_shot_hit_radii[4] = {15.0f, 20.0f, 25.0f, 50.0f};
// Model nodes the five kakusan shots of TBoss6Type1::fire_kakusan_shots leave from.
const s32 boss6_type1_kakusan_shot_nodes[5] = {4, 3, 7, 5, 6};
// The zero vector TBoss6Type1::spawn_mines starts the mine offsets from.
const Vec boss6_type1_zero_offset = {0.0f, 0.0f, 0.0f};
const u32 boss6_type1_trail_point_offsets[7] = {
    0xFFFF4000, 0xFFFFFF60, 0xFFFFFF60, 0xFFFF4000, 0xFFFFFF60, 0xFFFFFF60, 0xFFFF4000,
};
const u32 boss6_type1_effect_point_colors[2] = {0xFFFF4000, 0xFFFFFFC0};
const Vec boss6_type1_camera_eye = {0.0f, 19.8f, -5.0f};
const Vec boss6_type1_camera_target = {0.0f, 25.43f, 45.42f};
const Vec boss6_type1_laser_camera_eye_shift = {0.0f, -5.0f, 5.0f};
const Vec boss6_type1_laser_camera_target_shift = {0.0f, 40.0f, 40.0f};
const Vec boss6_type1_top_camera_eye = {0.0f, 24.8f, -5.0f};
const Vec boss6_type1_top_camera_target = {0.0f, 15.43f, 70.42f};
const Vec boss6_type1_default_camera_eye = {0.0f, 19.8f, -5.0f};
const Vec boss6_type1_default_camera_target = {0.0f, 50.43f, 45.42f};
const s32 boss6_type1_effect_direction[3] = {0x8000, 0, 0};
const Vec boss6_map_csn_offset = {62.5f, 0.0f, -35.0f};
const Vec boss6_map_csn_scale = {30.0f, 25.0f, 30.0f};

void OlgaFlowActionMsg::initialize() {
    header.subcommand = 0xA4;
    header.size = 5;
}

void OlgaFlowActionMsg::send() {
    swap_entity_id();
    send_subcommand(this);
}

void OlgaFlowActionMsg::swap_entity_id() { header.bswap(); }
int TBoss6PlotFalz::is_idle() { return not_floor_leader == 0; }
TBoss6PlotFalzSetEntry *TBoss6PlotFalz::get_set_entry() { return &set_entry; }
void TBoss6Type1::clear_harmful_statuses() {  }
void TBoss6Type1::apply_shock_status() {  }
void TBoss6Type1::apply_movement_ailment(s32) {  }
void TBoss6Type1::apply_confusion_status() {  }
void TBoss6Type1::apply_slow_status() {  }
void TBoss6Type1::apply_paralysis() {  }

void TBoss6Type1::apply_poison_status() {  }

TBoss6Type1 *TBoss6Type1::create(Boss6BodySpawnParams *params) {
    return new TBoss6Type1(new TObjControl(tl_04), params);
}
extern "C" {


u8 * TBoss6Type1__sub_802B96C0(saddr arg0, saddr arg1) {
    *(ByteBlock_C_boss6_1 *)(arg0) = *(const ByteBlock_C_boss6_1 *)(arg1);
    return (u8 *)arg0;
}
}

#pragma push
#pragma opt_common_subs off
TBoss6Type1::TBoss6Type1(TObject *parent, Boss6BodySpawnParams *params) : TObjEnemy(parent) {
    TBoss6Type1StateRecord record;
    s32 i;

    m_name = TBoss6Type1__name;
    add_flags_2e4(8);
    plot_falz = params->owner;
    apply_set_data(&params->set_entry);
    if (exchange_object_state(&record, 1) != 0) {
        record.flags = 0;
        record.value = 0;
        exchange_object_state(&record, 0);
    }
    bml_resource = TBoss6PlotFalz::get_scene_archive();
    texlist = 0;
    model = 0;
    VecCopy(&position, &boss6_type1_spawn_position);
    copy_xyz(&rotation_x, (void *)boss6_type1_spawn_rotation);
    VecCopy(&prev_position, VecCopy(&home_position, VecCopy(&center, &position)));
    init_collision_body_parts(this, TBoss6Type1__collision_body_parts, 7);
    update_position();
    velocity.z = 0.0f;
    velocity.y = 0.0f;
    velocity.x = 0.0f;
    target = 0;
    bind_enemy_combat_stats(TLobby::register_boss(0x2B), TLobby::dispatch_shared_handler_b(0x2B), TLobby::register_object(0x2B));
    referenceHp = hp;
    register_by_id();
    set_param(0x4E);
    init_motions();
    draw_callback_lists[1] = ModelNodePositionCapture::create(boss6_type1_model_node_desc, node_points);
    draw_callback_lists[0] = ModelNodePositionCapture::create(boss6_type1_model_node_desc_b, arm_node_positions);
    scroll_strips_u.build_tables(boss6_type1_build_table, 2);
    scroll_strips_v.build_tables(boss6_type1_scroll_strip_descs, 1);
    trail_point_receiver = TBoss6Zanzo::create(this, 7, 0xF);
    effect_point_receiver = TBoss6Zanzo::create(this, 2, 0xF);
    target_mode = 0;
    random_factor = 0;
    TBoss6Type1__sub_802B96C0((saddr)&target_position, (saddr)&boss6_type1_origin);
    VecCopy(&target_position.v, &position);
    TBoss6Type1__sub_802B96C0((saddr)&pad_42C, (saddr)&boss6_type1_origin);
    attack_mode = 1;
    active_parts = 0;
    for (i = 0; i < 32; i++) {
        action_history[i] = 0;
    }
    load_params_from_table();
    low_hp_flag = 0;
    damage_step_scale = 1.0f;
    latch_phase_counter();
    chal_ud_count = 0;
    center_trip_count = 0;
    centop_count = 0;
    cenbtm_count = 0;
    hit_flash = 0.0f;
    hp_ratio = 1.0f;
    reset_fields_4e0();
    reset_param();
    reset_sway();
    frame_counter = 0;
    clear_effect_slots();
    clear_slot_array();
    clear_map_csn();
    VecCopy(&last_beam_point, &position);
    set_action_state(0);
}
#pragma pop

TBoss6Type1::~TBoss6Type1() {
    s32 i;
    destroy_map_csn();
    destroy_slot_particles();
    release_effect_slots();
    scroll_strips_v.free_buffer_pairs();
    scroll_strips_u.free_buffer_pairs();
    for (i = 0; i < 2; i++) {
        if (draw_callback_lists[i] != NULL) {
            ModelNodePositionCapture::destroy(draw_callback_lists[i]);
            draw_callback_lists[i] = NULL;
        }
    }
    free_collision_body_parts(this);
}

void TBoss6Type1::set_sync_data(OlgaFlowActionMsg *message) {
    message->header.client_id = entity_id;
    message->attack_mode = static_cast<s8>(attack_mode);
    message->target_mode = static_cast<s8>(target_mode);
    message->random_factor = static_cast<s8>(127.0f * (0.000030517578f * static_cast<f32>(rand())));
}

#pragma push
#pragma scheduling off
void TBoss6Type1::load_params(const OlgaFlowActionMsg *message) {
    attack_mode = message->attack_mode;
    target_mode = message->target_mode;
    random_factor = message->random_factor;
}
#pragma pop

void send_flow_action_if_idle(TBoss6Type1 *boss6_type1, s32 action) {
    OlgaFlowActionMsg message;
    if (boss6_type1->plot_falz->is_idle() != 0) {
        message.initialize();
        boss6_type1->set_sync_data(&message);
        message.flow.action = static_cast<s8>(action);
        message.send();
    }
}

void TBoss6Type1::send_6xA4_action(s32 t, const Boss6Type1AttackTarget *src) {
    OlgaFlowActionMsg message;
    const s8 *bytes;
    s32 i;
    if (plot_falz->is_idle() != 0) {
        message.initialize();
        set_sync_data(&message);
        message.flow.action = t;
        bytes = reinterpret_cast<const s8 *>(src);
        for (i = 1; i < 4; i++) {
            (&message.flow.action)[i] = *bytes++;
        }
        message.send();
    }
}

void TBoss6Type1::init_attack_params(Boss6Type1AttackTarget *atk) {
    s8 dir = (u8)((u32)rotation_y >> 8);
    u8 kind;
    dir += 160.0f * (0.000030517578f * (f32)rand() - 0.5f);
    atk->angle = dir;
    kind = 0x12;
    if (0.000030517578f * (f32)rand() < 0.5f) {
        kind = 0x1C;
    }
    atk->radius = kind;
    atk->height = 10;
}
void TBoss6Type1::randomize_attack(Boss6Type1AttackTarget *atk) {
    const s8 *tab;
    s8 base;
    s8 v;
    f32 r;
    s8 w;
    s8 u;
    init_attack_params(atk);
    base = (u8)((u32)rotation_y >> 8);
    v = 80.0f * (0.000030517578f * (f32)rand()) + 32.0f;
    if (0.000030517578f * (f32)rand() < 0.5f) {
        v = -v;
    }
    atk->angle = base + v;
    if ((s32)atk->radius == 0x12 && is_near_center() == 0) return;
    atk->radius = 0x1C;
    if (is_high() != 0) {
        r = 0.000030517578f * (f32)rand();
        w = 0x12;
        if (r < 0.1f) {
            w = -2;
        } else if (r < 0.3f) {
            w = 10;
        }
        atk->height = w;
        return;
    }
    tab = is_low() != 0 ? boss6_type1_low_attack_heights : boss6_type1_mid_attack_heights;
    u = tab[0];
    if (0.000030517578f * (f32)rand() < 0.5f) {
        u = tab[1];
    }
    atk->height = u;
}

void TBoss6Type1::do_attack() {
    Boss6Type1AttackTarget atk;

    if ((s32) this->target_mode == 0) {
        init_attack_params(&atk);
    } else {
        randomize_attack(&atk);
    }
    this->attack_mode = 1;
    send_6xA4_action(2, &atk);
}

void TBoss6Type1::send_ret_rnd() {
    Boss6Type1AttackTarget s;
    s32 r4;
    init_attack_params(&s);
    s.radius = 0x1C;
    r4 = 0x21;
    attack_mode = 1;
    if (position.y < -20.0f) {
        r4 = 0x26;
    }
    send_6xA4_action(r4, &s);
}

void TBoss6Type1::choose_attack() {
    Boss6Type1AttackTarget s;
    s32 r4;
    s32 n;
    s32 id;
    switch (target_mode) {
    case 0:
        if (is_near_center() != 0) {
            send_flow_action_if_idle(this, rand_range_inclusive(5, 6));
            break;
        }
        switch (pick_remapped_list_value(3, 5, 0x20)) {
        case 3:
            send_flow_action_if_idle(this, (s8)(3));
            return;
        case 5:
            send_flow_action_if_idle(this, rand_range_inclusive(5, 6));
            return;
        case 4:
            return;
        }
        break;
    case 1:
        randomize_attack(&s);
        if (is_low() != 0) {
            id = 0x15;
            n = count_matches(0x15, 8);
            if (n == 0 || 0.000030517578f * (f32)rand() < 0.4f / (f32)n) {
                s.height = -2;
            } else {
                id = 2;
            }
            send_6xA4_action(id, &s);
            break;
        }
        if (is_high() != 0) {
            send_6xA4_action(4, &s);
            break;
        }
        r4 = pick_random_entry(boss6_type1_random_action_table, 5);
        switch (r4) {
        case 4:
            if (s.height == -2) {
                r4 = 2;
            } else {
                s.radius = 0x1C;
            }
            break;
        case 22:
            s.height = 10;
            break;
        case 5:
            s.height = 10;
            r4 = rand_range_inclusive(6, 7);
            break;
        case 8:
            s.height = 10;
            r4 = rand_range_inclusive(8, 10);
            break;
        }
        send_6xA4_action(r4, &s);
        break;
    }
}
#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_lifetimes off
void TBoss6Type1::send_chal_ud() {
    Boss6Type1AttackTarget atk;
    s8 v;
    f32 ratio;
    s32 total;
    v = ((u32)rotation_y >> 8) & 0xFF;
    v = 128.0f * (0.000030517578f * (f32)rand() - 0.5f) + v;
    ratio = 0.5f;
    atk.radius = 0x1C;
    atk.angle = v;
    total = centop_count + cenbtm_count;
    if (total > 0) {
        ratio = (f32)centop_count / (f32)total;
    }
    v = 20;
    if (0.000030517578f * (f32)rand() < ratio) {
        v = -5;
    }
    atk.height = v;
    attack_mode = 1;
    send_6xA4_action(0x18, &atk);
}
#pragma pop


void handle_6xA4_olga_flow_boss_actions(game_command_header *command) {
    OlgaFlowActionMsg *msg = reinterpret_cast<OlgaFlowActionMsg *>(command);
    TBoss6Type1 *boss;
    s32 action;

    msg->swap_entity_id();
    boss = (TBoss6Type1 *)get_enemy_entity(msg->header.client_id);
    if (boss == NULL) {
        return;
    }
    msg->flow.decode_target(&boss->target_position.v);
    boss->load_params(msg);
    action = msg->flow.action;
    if (action < 0 || action >= 41) {
        return;
    }
    boss->set_action_state(action);
}

void TBoss6Type1::run_hit_reaction() {
    this->actorFlags = (s32) (this->actorFlags & 0xFFFFFDFF);
    this->hit_flash = 1.0f;
    play_sound_effect(0x39E01, &node_points[1], 0, 1);
}

void TBoss6Type1::run_death_reaction() {
    if ((s32)action_state != 40) {
        set_action_state(40);
    }
}

void TBoss6Type1::render_shadows() {
    if (this->position.y >= -30.0f) {
        TObjEnemy::render_shadows();
    }
}

void TBoss6Type1::run_task() {
    void (TBoss6Type1::*action)();
    action = boss6_type1_action_table[this->action_state].update;
    if (action != 0) {
        (this->*action)();
    }
    if (this->plot_falz->is_idle() != 0) {
        action = boss6_type1_action_table[this->action_state].idle;
        if (action != 0) {
            (this->*action)();
        }
    }
    advance_animations();
    update_turn_to_center();
    update_position();
    update_part_positions();
    update_parts_flags();
    update_collisions();
    submit_cursor_candidate(this, -1);
    add_radar_scaled_marker(&this->node_points[1], -0x5DB4, 1, 1, 5.0f);
    update_action_camera();
    this->hit_flash += -0.06666667f;
    if (this->hit_flash < 0.0f) {
        this->hit_flash = 0.0f;
    }
    this->hp_ratio = (f32)this->hp / (f32)this->referenceHp;
    scroll_strips_u.scroll_strips_uv(8, 0);
    scroll_strips_v.scroll_strips_uv(0, 0x22);
    update_sway();
    update_effect_slots();
    this->frame_counter += 1;
}
void TBoss6Type1::set_action_state(s32 state) {
    void (TBoss6Type1::*action)();
    TBoss6Type1Action *e;
    s32 i;
    this->action_state = state;
    for (i = 31; i > 0; i--) {
        this->action_history[i] = this->action_history[i - 1];
    }
    this->action_history[0] = this->action_state;
    switch ((s32)this->action_state) {
    case 24:
        this->chal_ud_count++;
        break;
    case 26:
        this->center_trip_count++;
        this->centop_count++;
        break;
    case 34:
        this->center_trip_count++;
        this->cenbtm_count++;
        break;
    }
    e = &boss6_type1_action_table[this->action_state];
    set_motion_set(e->anim);
    this->active_parts = e->param;
    action = e->act;
    if (action != 0) {
        (this->*action)();
    }
}


Boss6Type1MotionState *TBoss6Type1::copy_block(Boss6Type1MotionState *d, const Boss6Type1MotionState *s) {
    *d = *s;
    return d;
}

void Boss6PartMotion::copy_from(Boss6PartMotion *src) {
    *this = *src;
}

void TBoss6Type1::init_motions() {
    s32 i;
    Boss6PartMotion *a;
    copy_block(&motion_state, &boss6_type1_initial_motion_set);
    for (i = 0; i < anim_count(); i++) {
        a = &motion_state.part_motions[i];
        a->copy_from((Boss6PartMotion *)&boss6_type1_initial_part_motion);
        a->motion = a->prev_motion = get_bml_motion(bml_resource, TBoss6Type1__motion_set_table[2].ids[i]);
    }
}

void TBoss6Type1::advance_animations() {
    s32 cur;
    s32 i;
    Boss6PartMotion *a;
    f32 len;
    f32 b;
    f32 lim;
    s32 n;
    cur = main_anim_index();
    n = anim_count();
    for (i = 0; i < n; i++) {
        if (i == cur) continue;
        a = &motion_state.part_motions[i];
        len = a->motion->frameCount;
        a->frame += a->speed;
        if (a->frame >= len) a->frame -= len;
        if (0.0f != a->blend) {
            if ((a->blend += a->blend_step) >= 1.0f) a->blend = 0.0f;
        }
    }
    a = &motion_state.part_motions[main_anim_index()];
    len = a->motion->frameCount;
    a->frame += a->speed;
    switch (this->motion_state.motion_mode) {
    case 0:
        if (a->frame >= len) a->frame -= len;
        break;
    case 1:
        break;
    case 2:
        lim = len - 1.0f;
        if (a->frame >= lim) {
            a->frame = lim;
            set_motion_set(TBoss6Type1__motion_set_table[motion_state.motion_set].next_set);
        }
        break;
    }
    if (0.0f != a->blend) {
        if ((a->blend += a->blend_step) >= 1.0f) a->blend = 0.0f;
    }
}

#pragma push
#pragma opt_propagation off
void TBoss6Type1::set_motion_set(s32 set) {
    f32 z;
    s32 n;
    Boss6Type1MotionSet *t;
    s32 i;
    Boss6PartMotion *a;

    if (set != -1 && set != motion_state.motion_set) {
    motion_state.motion_set = set;
    z = 0.0f;
    n = anim_count();
    t = &TBoss6Type1__motion_set_table[set];
    this->motion_state.motion_mode = t->mode;
    for (i = 0; i < n; i++) {
        a = &motion_state.part_motions[i];
        AnimationMotion *motion = get_bml_motion(this->bml_resource, t->ids[i]);
        a->blend = a->blend_step;
        a->prev_motion = a->motion;
        a->prev_frame = a->frame;
        a->motion = motion;
        a->frame = z;
    }
    }
}
#pragma pop
#pragma push
#pragma opt_propagation off
void TBoss6Type1::draw_part_motions() {
    Boss6BlendMotion b;
    s32 i;
    saddr id;
    NJS_TEXLIST *textures;
    Boss6PartMotion *a;
    ModelNodePositionCapture *cb;
    set_motion_packed_rotation();
    for (i = 0; i < 2; i++) {
        {
            s32 t = boss6_type1_part_model_ids[i];
            id = t;
            textures = get_bml_texlist(bml_resource, t);
        }
        id = (saddr)get_bml_model(bml_resource, id);
        cb = draw_callback_lists[i];
        a = &motion_state.part_motions[i];
        if (cb != 0) {
            TObjFish::set_global_param(textures);
            if (0.0f == a->blend) {
                cb->install();
                draw_model_motion((void *)id, a->motion, a->frame);
                cb->clear();
            } else {
                b.motions[0] = a->prev_motion;
                b.frames[0] = a->prev_frame;
                b.motions[1] = a->motion;
                b.frames[1] = a->frame;
                cb->install();
                draw_model_blend_motion((void *)id, &b, a->blend);
                cb->clear();
            }
        }
    }
    clear_motion_packed_rotation();
}
#pragma pop
void TBoss6Type1::load_params_from_table() {
    const BattleMovementParams *rec = TLobby::dispatch_shared_handler_a(0x2B);
    this->beam_damage = (s32)rec->values.floats[0];
    if ((f32) this->beam_damage <= 0.0f) {
        this->beam_damage = (s32) TBoss6Type1__param_table[0];
    }
    this->sweep_damage = (s32)rec->values.floats[2];
    if ((f32) this->sweep_damage <= 0.0f) {
        this->sweep_damage = (s32) TBoss6Type1__param_table[1];
    }
    this->laser_damage = (s32)rec->values.floats[3];
    if ((f32) this->laser_damage <= 0.0f) {
        this->laser_damage = (s32) TBoss6Type1__param_table[2];
    }
    this->center_damage = (s32)rec->values.floats[4];
    if ((f32) this->center_damage <= 0.0f) {
        this->center_damage = (s32) TBoss6Type1__param_table[3];
    }
    this->float_time = (s32)rec->values.floats[5];
    if ((f32) this->float_time <= 0.0f) {
        this->float_time = (s32) TBoss6Type1__param_table[10];
    }
    this->scream_threshold = rec->values.integers[0];
    if ((s32) this->scream_threshold <= 0) {
        this->scream_threshold = (s32) TBoss6Type1__param_table[4];
    }
    this->chal_ud_threshold = rec->values.integers[1];
    if ((s32) this->chal_ud_threshold <= 0) {
        this->chal_ud_threshold = (s32) TBoss6Type1__param_table[5];
    }
    this->damage_step = rec->values.integers[2];
    if ((s32) this->damage_step <= 0) {
        this->damage_step = (s32) TBoss6Type1__param_table[6];
    }
    this->delta_threshold = rec->values.integers[3];
    if ((s32) this->delta_threshold <= 0) {
        this->delta_threshold = (s32) TBoss6Type1__param_table[7];
    }
    this->laser_charge_time = rec->values.integers[4];
    if ((s32) this->laser_charge_time <= 0) {
        this->laser_charge_time = (s32) TBoss6Type1__param_table[8];
    }
    this->laser_fire_time = rec->values.integers[5];
    if (this->laser_fire_time <= 0) {
        this->laser_fire_time = (s32) TBoss6Type1__param_table[9];
    }
    this->low_hp_float_time = (s32)TLobby::dispatch_shared_handler_a(0x2F)->values.floats[5];
    if ((f32) this->low_hp_float_time <= 0.0f) {
        this->low_hp_float_time = (s32) TBoss6Type1__param_table[11];
    }
}

void TBoss6Type1::latch_phase_counter() {
    this->latched_hp = (s32) this->hp;
}

s32 TBoss6Type1::calc_field4b0_delta() {
    return this->latched_hp - this->hp;
}

void TBoss6Type1::update_turn_to_center() {
    Vec to_center;
    s32 heading;
    s32 pitch;
    pitch = 0;
    if (attack_mode != 0) {
        pitch = 0x8000;
    }
    if (angle_difference_abs(rotation_x, pitch) < 0x666) {
        rotation_x = pitch;
    } else {
        rotation_x = rotation_x + 0x666;
    }
    to_center.x = -position.x;
    to_center.z = -position.z;
    to_center.y = 0.0f;
    if (!(vector_length(&to_center) <= 0.00001f)) {
        heading = (s32)(10430.38043493439 * atan2_float(to_center.x, to_center.z));
        if (attack_mode != 0) {
            heading += 0x8000;
        }
        rotation_y = approach_angle_limited(rotation_y, heading, target_mode == 0 ? 0x1B4 : 0x1555);
    }
}

void TBoss6Type1::reset_sway() {
    sway_offset = 0.0f;
    sway_phase = 0;
    sway_speed = sway_target_min();
    sway_delay = sway_delay_min();
}
void TBoss6Type1::update_sway() {
    f32 d;
    f32 target;
    s32 v;
    if (--sway_delay < 0) {
        sway_speed = (f32)sway_target_range() * (0.000030517578f * (f32)rand()) + (f32)sway_target_min();
        sway_delay = (f32)sway_delay_range() * (0.000030517578f * (f32)rand()) + (f32)sway_delay_min();
    }
    target = 0.0f;
    switch ((s32)action_state) {
    case 29:
    case 30:
    case 31:
    case 32:
    case 37:
        break;
    case 23:
        target = sway_offset - 2.5f * fabs_float(sin_table_lookup(sway_phase));
        break;
    default:
        v = sway_speed;
        if (sway_offset < 0.0f) {
            v = 5.0f * (f32)v;
        }
        sway_phase += v;
        target = 15.0f * sin_table_lookup(sway_phase);
        break;
    }
    d = 0.75f * (target - sway_offset);
    if (d < -5.0f) {
        d = -5.0f;
    } else if (d > 5.0f) {
        d = 5.0f;
    }
    sway_offset += d;
}

void TBoss6Type1::update_position() {
    VecCopy(&body_center, &this->position);
    if ((s32) this->attack_mode != 0) {
        body_center.y = (f32) (body_center.y - 75.0f);
        return;
    }
    body_center.y = (f32) (body_center.y - 50.0f);
}

void TBoss6Type1::update_part_positions() {
    Vec v;
    s32 i;
    Vec *base;
    CollisionBody *e;
    if (this->bodies != NULL) {
        for (i = 0; i < 7; i++) {
            const Boss6PartPositionSource *t;
            e = &bodies[i];
            t = &TBoss6Type1__part_position_sources[i];
            base = NULL;
            switch (t->kind) {
            case 1:
                base = node_points;
                break;
            case 0:
                base = arm_node_positions;
                break;
            }
            if (base == NULL) {
                return;
            }
            VecCopy((Vec *)&v, (const Vec *)&base[t->idx]);
            subtract_vector(&v, &position);
            push_matrix();
            set_matrix_identity(0);
            rotate_matrix_y(0, -this->rotation_y);
            matrix_mult_vec(0, &v, &e->offset);
            pop_matrix();
            VecCopy(&e->center, &e->offset);
            vec3_add_to(&e->center, &position);
        }
    }
}

void TBoss6Type1::update_parts_flags() {
    clear_part_flag_bit0();
    if (this->active_parts & 1) {
        set_child_flags();
    }
    if (this->active_parts & 2) {
        enable_parts();
    }
}

void TBoss6Type1::clear_part_flag_bit0() {
    CollisionBody *p = bodies;
    if (p != NULL) {
        CollisionBody *end = p + 7;
        for (; p < end; p++) {
            p->flags &= ~1;
        }
    }
}

void TBoss6Type1::set_child_flags() {
    if (this->bodies != NULL) {
        this->bodies[0].flags |= 1;
        this->bodies[1].flags |= 1;
    }
}

void TBoss6Type1::enable_parts() {
    if (this->bodies != NULL) {
        this->bodies[2].flags |= 1;
        this->bodies[3].flags |= 1;
        this->bodies[4].flags |= 1;
        this->bodies[5].flags |= 1;
        this->bodies[6].flags |= 1;
    }
}
void TBoss6Type1::update_beam_attack() {
    Line line;
    Vec v;
    Vec w;
    Vec out;
    Vec A;
    Vec B;
    f32 t = motion_state.part_motions[1].frame;
    AnimationMotion *motion = motion_state.part_motions[1].motion;
    s32 n;
    s32 i;

    if (motion != get_bml_motion(bml_resource, TBoss6Type1__motion_set_table[13].ids[1])) return;
    if (t < 12.5f || t > 22.0f) return;
    {
    f32 end = 12.5f + motion_state.part_motions[1].speed;
    if (t >= 12.5f && t < end) {
        play_sound_effect(0x40039209, &node_points[9], 0, 0);
    }
    }
    init_parts();
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        TObjPlayer *p = TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active(p) != 0) {
            Vec *a = &node_points[8];
            VecCopy(&v, &p->position);
            v.y = 0.0f;
            VecCopy(&w, &node_points[9]);
            subtract_vector(&w, a);
            line.o.x = a->x;
            line.o.y = 0.0f;
            line.o.z = a->z;
            line.d.x = w.x;
            line.d.y = 0.0f;
            line.d.z = w.z;
            if (!(project_point_onto_line(&v, &line, &out) > 15.0f)) {
                A.x = line.o.x;
                A.y = line.o.z;
                B.x = line.o.x + line.d.x;
                B.z = line.o.z + line.d.z;
                subtract_vector(&A, &out);
                subtract_vector(&B, &out);
                A.y = 0.0f;
                B.y = 0.0f;
                if (!(vec3_dot(&A, &B) > 0.0f)) {
                    DirectAttackPayload attack;
                    s32 power = TBoss6PlotFalz::rand_vary_count(beam_damage, 0.1f);
                    attack.kind = 0;
                    attack.power = power;
                    p->receive_direct_attack(this, attack, 0, -1, -1);
                }
            }
        }
    }
    if (frame_counter & 1) return;
    Vec c = node_points[9];
    f32 dist;
    c.y = 0.0f;
    dist = xyz_distance(&c, &last_beam_point);
    if (!(dist < 50.0f)) {
        f32 r = dist / 50.0f;
        Vec e = c;
        Vec dlt;
        s32 cnt;
        f32 s;
        s32 j;
        cnt = (s32)(1.0f + r);
        if (cnt > 4) cnt = 4;
        s = 1.0f / (f32)cnt;
        VecCopy(&dlt, &last_beam_point);
        subtract_vector(&dlt, &c);
        dlt.x *= s;
        dlt.y *= s;
        dlt.z *= s;
        for (j = 0; j < cnt; j++) {
            spawn_particle_effect_with_flags(&e, 0x212, 0x40);
            spawn_particle_effect_with_flags(&e, 0x213, 0x40);
            vec3_add_to(&e, &dlt);
        }
        VecCopy(&last_beam_point, &c);
    }
    {
        play_sound_effect(0x4003B00A, &c, 0, 0);
        TBoss6PlotFalz::apply_radial_effect_to_players(&c, 0xC0, 0xF, 100.0f);
    }
}
void TBoss6Type1::spawn_sword_shots() {
    Vec *a;
    Vec *b;
    s32 ok;
    s32 flag;
    Vec p;
    Vec d;
    f32 sc;
    f32 t;
    s32 idx;
    update_trail_points();
    a = &node_points[8];
    b = &node_points[9];
    ok = 0;
    if ((b->y < a->y && b->y < 0.0f) || (b->y > a->y && b->y > 0.0f)) {
        ok = 1;
    }
    if (fabs_float(a->y) > 150.0f || fabs_float(b->y) > 150.0f) {
        ok = 0;
    }
    if (ok != 0) {
        VecCopy((Vec *)&d, (const Vec *)b);
        subtract_vector(&d, a);
        if (d.y <= 0.00001f) {
            t = 1.0f;
        } else {
            t = -a->y / d.y;
        }
        p.x = t * d.x + a->x;
        p.y = 0.0f;
        p.z = t * d.z + a->z;
        idx = game_difficulty_selection;
        if (idx < 0 || idx >= 4) {
            idx = 0;
        }
        sc = TBoss6Type1__sword_shot_hit_radii[idx];
        flag = 0;
        if ((frame_counter & 3) == 0) {
            flag = 1;
        }
        TBoss6SwordShot::create((TObject *)this, &p, flag, sc);
        if (flag != 0) {
            play_sound_effect(0x4003B210, &p, 0, 0);
            TBoss6PlotFalz::apply_radial_effect_to_players(&p, 0xC0, 0xF, 100.0f);
        }
    }
}
// Swept-arm hit test: damages every player inside the triangle the arm tip (arm_node_positions[6])
// swept since the previous frame, between frames 10.5 and 15 of motion set 14.
void TBoss6Type1::check_sweep_hits() {
    f32 frame = motion_state.part_motions[0].frame;
    AnimationMotion *motion = motion_state.part_motions[0].motion;
    Vec *tip = (Vec *)&arm_node_positions[6];
    s32 i;
    s32 n;
    Vec v[2];
    Vec *corner[4];
    f32 side[3];
    Vec cross;
    s32 inside;
    s32 j;

    if (motion == get_bml_motion(bml_resource, TBoss6Type1__motion_set_table[14].ids[0]) &&
        !(frame < 10.5f || frame > 15.0f)) {
        f32 end = 10.5f + motion_state.part_motions[0].speed;
        if (frame >= 10.5f && frame < end) {
            play_sound_effect(0x40038A0E, &arm_node_positions[5], 0, 0);
        }
        update_effect_points();
        n = TLobby::get_game_mode();
        for (i = 0; i < n; i++) {
            inside = 1;
            TObjPlayer *p = TObjPlayer::get_player_data(i);
            if (TBoss6PlotFalz::is_active((TObjPlayer *)p) != 0) {
                corner[0] = corner[3] = &position;
                corner[1] = &prev_effect_point;
                corner[2] = tip;
                for (j = 0; j < 3; j++) {
                    VecCopy(&v[0], corner[j + 1]);
                    subtract_vector(&v[0], corner[j]);
                    VecCopy(&v[1], &p->position);
                    subtract_vector(&v[1], corner[j]);
                    v[0].y = 0.0f;
                    v[1].y = 0.0f;
                    vec3_cross(&v[0], &v[1], &cross);
                    side[j] = cross.y;
                    if (j > 0 && ((side[j - 1] < 0.0f && side[j] >= 0.0f) || (side[j - 1] > 0.0f && side[j] <= 0.0f))) {
                        inside = 0;
                        break;
                    }
                }
                if (inside != 0) {
                    s32 damage = TBoss6PlotFalz::rand_vary_count(sweep_damage, 0.1f);
                    DirectAttackPayload hit;
                    hit.kind = 0;
                    hit.power = (f32)damage;
                    p->receive_direct_attack(this, hit, 0, -1, -1);
                }
            }
        }
    }
    VecCopy(&prev_effect_point, tip);
}
void TBoss6Type1::check_laser_hits() {
    s32 n;
    Vec *p4;
    Vec *p3;
    Vec *p2;
    Vec *p1;
    Vec *pA;
    Vec *pB;
    s32 i;
    TObjPlayer *pl;
    s32 inside;
    Vec *a;
    Vec *b;
    s32 j;
    f32 prev;
    f32 t;
    Vec pts[5];
    Line line;
    Vec A;
    Vec B;
    Vec mid;
    Vec off;
    Vec e;
    Vec f;
    Vec c;
    Vec m;
    Vec d3;
    Vec d0;
    Vec q2;
    Vec q1;
    if (0.0f == laser_scale) {
        return;
    }
    n = TLobby::get_game_mode();
    b = &node_points[6];
    a = &node_points[4];
    if (xyz_distance(a, b) < 10.0f) {
        return;
    }
    VecCopy((Vec *)&mid, (const Vec *)a);
    vec3_add_to(&mid, b);
    mid.x *= 0.5f;
    mid.y *= 0.5f;
    mid.z *= 0.5f;
    pA = &A;
    pB = &B;
    p4 = &pts[4];
    p3 = &pts[3];
    p2 = &pts[2];
    p1 = &pts[1];
    A.x = laser_scale * (a->x - mid.x) + mid.x;
    A.y = laser_scale * (a->y - mid.y) + mid.y;
    A.z = laser_scale * (a->z - mid.z) + mid.z;
    B.x = laser_scale * (b->x - mid.x) + mid.x;
    B.y = laser_scale * (b->y - mid.y) + mid.y;
    B.z = laser_scale * (b->z - mid.z) + mid.z;
    for (i = 0; i < n; i++) {
        pl = TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active(pl) == 0) {
            continue;
        }
        inside = 1;
        VecCopy((Vec *)&pts[0], (const Vec *)((void *)VecCopy((Vec *)((Vec *)p3), (const Vec *)((void *)VecCopy((Vec *)((Vec *)p4), (const Vec *)((const Vec *)pA))))));
        VecCopy((Vec *)p1, (const Vec *)((void *)VecCopy((Vec *)((Vec *)p2), (const Vec *)((const Vec *)pB))));
        off.x = -500.0f * sin_table_lookup(rotation_y);
        off.y = 0.0f;
        off.z = -500.0f * cos_table_lookup(rotation_y);
        vec3_add_to(p2, &off);
        vec3_add_to(p3, &off);
        for (j = 0; j < 4; j++) {
            VecCopy((Vec *)&e, (const Vec *)&pts[j + 1]);
            subtract_vector(&e, &pts[j]);
            e.y = 0.0f;
            VecCopy(&f, &pl->position);
            subtract_vector(&f, &pts[j]);
            e.y = 0.0f;
            vec3_cross(&e, &f, &c);
            if (j > 0 && ((prev < 0.0f && c.y >= 0.0f)
                          || (prev > 0.0f && c.y <= 0.0f))) {
                inside = 0;
                break;
            }
            prev = c.y;
        }
        if (inside == 0) {
            continue;
        }
        DirectAttackPayload attack;
        s32 power = TBoss6PlotFalz::rand_vary_count(laser_damage, 0.1f);
        attack.kind = 0;
        attack.power = power;
        pl->receive_direct_attack(this, attack, 0, -1, -1);
        VecCopy((Vec *)&d0, (const Vec *)pA);
        subtract_vector(&d0, pB);
        d0.y = 0.0f;
        VecCopy(&d3, &pl->position);
        d3.y = 0.0f;
        line.o.x = 0.5f * (A.x + B.x);
        line.o.y = 0.0f;
        line.o.z = 0.5f * (A.z + B.z);
        line.d.x = -sin_table_lookup(rotation_y);
        line.d.y = 0.0f;
        line.d.z = -cos_table_lookup(rotation_y);
        t = project_point_onto_line(&d3, &line, NULL);
        t = 0.5f * vector_length(&d0) - t;
        if (t <= 0.0f) {
            continue;
        }
        VecCopy((Vec *)&m, (const Vec *)pA);
        subtract_vector(&m, pB);
        m.y = 0.0f;
        if (vector_length(&m) <= 0.00001f) {
            continue;
        }
        normalize_vector(&m);
        m.x *= t;
        m.z *= t;
        VecCopy((Vec *)&q2, (const Vec *)pA);
        subtract_vector(&q2, &pl->position);
        q2.y = 0.0f;
        VecCopy((Vec *)&q1, (const Vec *)pB);
        subtract_vector(&q1, &pl->position);
        q1.y = 0.0f;
        t = vector_length(&q1);
        if (vector_length(&q2) > t) {
            m.x *= -1.0f;
            m.z *= -1.0f;
        }
        vec3_add_to(&m, &pl->position);
        if (project_actor_to_ground((TObjChara *)this, (Vec *)&m, 0) == 0) {
            m.y = 0.0f;
            if (vector_length(&m) <= 0.00001f) {
                continue;
            }
            normalize_vector(&m);
            m.x *= 95.0f;
            m.z *= 95.0f;
        }
        TBoss6PlotFalz::move_player_to(pl, &m);
    }
}

void TBoss6Type1::damage_players_in_range() {
    s32 n;
    s32 i;
    TObjPlayer *p;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active(p) != 0) {
            Vec v = p->position;
            v.y = 0.0f;
            if (!(vector_length(&v) > 10.0f)) {
                DirectAttackPayload attack;
                s32 power = TBoss6PlotFalz::rand_vary_count(center_damage, 0.1f);
                attack.kind = 1;
                attack.power = power;
                p->receive_direct_attack(this, attack, 0, -1, -1);
            }
        }
    }
}


// Fires five kakusan shots from body nodes, fanned across the boss's front (inferred). Off Normal
// difficulty each shot is given the next player slot, starting at the slot in random_factor.
void TBoss6Type1::fire_kakusan_shots() {
    f32 side = -92.5f;
    s32 first = random_factor & 3;
    u16 target = first;
    f32 height = 5.0f * first;
    for (s32 i = 0; i < 5; i++) {
        Vec pos = node_points[boss6_type1_kakusan_shot_nodes[i]];
        Vec dir;
        dir.x = side * cos_table_lookup(-rotation_y);
        dir.y = height;
        dir.z = side * sin_table_lookup(-rotation_y);
        subtract_vector(&dir, &pos);
        f32 len = vector_length(&dir);
        if (len <= 0.00001f) {
            dir.x = len = 1.0f;
        }
        f32 scale = 7.5f / len;
        dir.x *= scale;
        dir.y *= scale;
        dir.z *= scale;
        if (is_normal_difficulty()) {
            TBoss6Type1::create_kakusan(this, &pos, &dir, 0xFFFF, 7.5f);
        } else {
            TBoss6Type1::create_kakusan(this, &pos, &dir, target, 7.5f);
        }
        target = (target + 1) & 3;
        side += 46.25f;
    }
    play_sound_effect(0x4003A10B, &node_points[7], 0, 0);
}
void TBoss6Type1::spawn_grav_ball() {
    Vec v;
    s32 flag;
    TObjPlayer *pl;
    s8 b;
    s32 ang;
    f32 r;
    flag = 1;
    pl = get_player_by_client_id(random_factor & 3);
    if (TBoss6PlotFalz::is_active(pl) != 0) {
        VecCopy(&v, &pl->position);
        flag = 0;
        v.y = position.y;
    }
    b = random_factor;
    if (b & 0x40) {
        flag = 1;
    }
    if (flag != 0) {
        ang = (b & 0xF) << 12;
        r = 80.0f * ((f32)((b >> 3) & 0xF) / 15.0f) + 10.0f;
        VecCopy(&v, &position);
        v.x += r * sin_table_lookup(ang);
        v.z += r * cos_table_lookup(ang);
    }
    TBoss6Type1::create_grav_ball(this, &v);
}


// Spreads the mines over rings around node 0 in a shuffled order (inferred: the mine attack). The
// spawn data starts as a copy of the mag mine's set entry; each mine gets its ring offset, a heading
// and the next seed.
void TBoss6Type1::spawn_mines() {
    s32 seed = random_factor;
    TBoss6MineSetData set;
    reset_fields_4e0();
    copy_set_entry(&set, plot_falz->get_set_entry());
    set.owner = this;
    VecCopy(&set.origin, &node_points[0]);
    VecCopy(&set.offset, &boss6_type1_zero_offset);
    set.room = 0;
    VecCopy(&set.position, &set.origin);
    s32 heading = 0;
    s32 count = TBoss6PlotFalz::get_phase() == 0 ? 18 : 36;
    s32 total = 1;
    s32 rings = 0;
    s32 step = 3;
    while (count > total) {
        total += step;
        step += 3;
        rings++;
    }
    Vec *points = (Vec *)mem_alloc(total * sizeof(Vec));
    VecCopy(&points[0], &boss6_type1_zero_offset);
    if (total > 1 && rings > 0) {
        f32 spacing = 95.0f / rings;
        f32 radius = spacing;
        s32 k = 1;
        s32 angle = 0;
        s32 angle_step = 0x10000 / 3;
        s32 ring = 1;
        while (true) {
            points[k].x = radius * sin_table_lookup(angle);
            points[k].y = 0.0f;
            points[k].z = radius * cos_table_lookup(angle);
            if (++k >= total) {
                break;
            }
            angle += angle_step;
            if (angle > 0x10000 - angle_step / 2) {
                ring++;
                angle_step = 0x10000 / (ring * 3);
                radius += spacing;
                angle = 0;
                if (ring & 1) {
                    angle = angle_step / 2;
                }
            }
        }
    }
    s32 swaps = total / 2;
    if (swaps > 1) {
        for (s32 j = 0; j < swaps; j++) {
            s32 r = next_random_seed(seed);
            seed = next_random_seed(r);
            s32 a = r % total;
            s32 b = seed % total;
            if (a == b) {
                b += j + 1;
                b %= total;
            }
            Vec tmp = points[a];
            VecCopy(&points[a], &points[b]);
            VecCopy(&points[b], &tmp);
        }
    }
    timer_limit = 0;
    s32 i = 0;
    while (i < count) {
        VecCopy(&set.offset, &points[i]);
        set.heading = heading;
        seed = next_random_seed(seed);
        set.seed = seed;
        if (((TBoss6PlotFalz *)plot_falz)->get_next_point(&set.set_index, &set.entity_id) == 0) {
            break;
        }
        if (TBoss6Mine::create(&set) == NULL) {
            break;
        }
        i++;
        heading = (i << 16) / count;
        timer_limit++;
    }
    mem_free(points);
    if (timer_limit > 0) {
        play_sound_effect(0x4003B51B, &position, 0, 0);
    }
}

void TBoss6Type1::increase_field_clamped_max() {
    this->laser_scale += 0.033333335f;
    if (this->laser_scale > 1.0f) {
        this->laser_scale = 1.0f;
    }
}
void TBoss6Type1::decrease_field_clamped_min() {
    this->laser_scale += -0.13333334f;
    if (this->laser_scale < 0.0f) {
        this->laser_scale = 0.0f;
    }
}

void TBoss6Type1::reset_param() {
    this->laser_scale = 0.0f;
}
// Draws bml model 0 at node_points[7], turned to face the viewing player and scaled by laser_scale.
void TBoss6Type1::render_laser() {
    if (this->laser_scale != 0.0f) {
        NJS_TEXLIST *textures = get_bml_texlist(bml_resource, 0);
        NJS_OBJECT *model = get_bml_model(bml_resource, 0);
        s32 pitch = 0;
        Vec pos = this->node_points[7];
        s32 yaw = this->rotation_y + 0x8000;
        static f32 s_min_width = 0.15f;
        static f32 s_max_width = 0.625f;
        static f32 s_grow_end = 0.1f;
        f32 width = s_min_width;
        f32 height;
        if (this->laser_scale < s_grow_end) {
            height = this->laser_scale / s_grow_end;
        } else {
            width = (this->laser_scale - s_grow_end) / (1.0f - s_grow_end) * (s_max_width - s_min_width) + s_min_width;
            height = 1.0f;
        }
        TObjPlayer *player = get_player_by_client_id(
            (u16)TCameraCtrl::get_split_screen_view_index(TCameraCtrl::get_camera_mode()));
        if (player != NULL) {
            Vec from;
            Vec to;
            VecCopy(&from, &this->node_points[7]);
            VecCopy(&to, &player->position);
            to.y += 14.0f;
            subtract_vector(&to, &from);
            Vec flat = to;
            flat.y = 0.0f;
            pitch = (s32)(10430.38043493439 * atan2_float(-to.y, vector_length(&flat)));
            if (pitch > 0x1000) {
                pitch = 0x1000;
            }
        }
        push_matrix();
        post_translate_matrix(&pos.x);
        rotate_matrix_y(0, yaw);
        rotate_matrix_x(0, pitch);
        rotate_matrix_z(0, 0);
        scale_matrix(0, width, 1.0f, height);
        TObjFish::set_global_param(textures);
        draw_chunk_object(model);
        pop_matrix();
    }
}


void TBoss6Type1::init_parts() {
    set_part_default_value(&node_points[8]);
    set_part_default_value(&node_points[9]);
    set_part_default_value(&node_points[10]);
    update_trail_points();
}

void TBoss6Type1::update_trail_points() {
    Vec points[7];
    Vec delta;
    VecCopy(&points[0], (const Vec *)&node_points[8]);
    VecCopy(&points[3], (const Vec *)&node_points[9]);
    VecCopy(&delta, (const Vec *)&node_points[10]);
    subtract_vector(&delta,&points[3]);
    f32 length=vector_length(&delta);
    if(length <= 0.00001f) length=1.0f;
    f32 scale=15.0f/length;
    delta.x*=scale;delta.y*=scale;delta.z*=scale;
    VecCopy(&points[1], (const Vec *)&points[0]);
    VecCopy(&points[5], (const Vec *)&points[0]);
    subtract_vector(&points[1],&delta);
    vec3_add_to(&points[5],&delta);
    VecCopy(&points[2], (const Vec *)&points[1]);
    VecCopy(&points[4], (const Vec *)&points[1]);
    subtract_vector(&points[2],&delta);
    vec3_add_to(&points[4],&delta);
    VecCopy((Vec *)&points[6], (const Vec *)&points[0]);
    trail_point_receiver->set_effect_points(points, boss6_type1_trail_point_offsets);
}

void TBoss6Type1::update_effect_points() {
    Vec points[2];
    VecCopy(&points[0], (const Vec *)&arm_node_positions[5]);
    VecCopy(&points[1], (const Vec *)&arm_node_positions[6]);
    set_part_default_value(&points[1]);
    effect_point_receiver->set_effect_points(points, boss6_type1_effect_point_colors);
}

void TBoss6Type1::set_part_default_value(Vec *point) { point->y = 10.0f; }


s32 TBoss6Type1::is_raised() const {
    return position.y > 100.0f;
}

s32 TBoss6Type1::is_near_center() {
    Vec v = position;
    v.y = 0.0f;
    return vector_length(&v) < 230.0f;
}

s32 TBoss6Type1::is_high() {
    return position.y > 140.0f;
}

s32 TBoss6Type1::is_low() {
    return position.y < 40.0f;
}

void TBoss6Type1::set_flag_on_threshold() {
    if (((s32) this->low_hp_flag == 0) && (this->hp_ratio < 0.33333334f)) {
        this->low_hp_flag = 1;
    }
}

int TBoss6Type1::is_time_up() {
    if ((s32) this->target_mode == 0) {
        return 0;
    }
    return calc_field4b0_delta() >= (s32) this->chal_ud_threshold ? 1 : 0;
}

s32 TBoss6Type1::check_field4b0_threshold() {
    s32 threshold = (s32)(damage_step_scale * (f32)damage_step);
    if (calc_field4b0_delta() >= threshold) {
        this->damage_step_scale *= 1.5f;
        return 1;
    }
    return 0;
}

s32 TBoss6Type1::is_ready() {
    if (((s32) this->target_mode == 0) && (calc_field4b0_delta() >= (s32) this->scream_threshold)) {
        return 1;
    }
    return 0;
}

int TBoss6Type1::is_field4b0_delta_reached() {
    return calc_field4b0_delta() >= delta_threshold ? 1 : 0;
}
s32 TBoss6Type1::is_field3F8_over_0x20() {
    return this->plot_falz->count_free_child_ids() > 0x20;
}

void TBoss6Type1::reset_fields_4e0() { this->timer_limit = 0; this->timer_elapsed = 0; }

void TBoss6Type1::tick_timer() {
    if (timer_limit <= 0 || timer_elapsed < 0) return;
    timer_elapsed++;
}

s32 TBoss6Type1::is_timer_expired() {
    if (timer_limit <= 0 || timer_elapsed < 0) {
        return 1;
    }
    return timer_limit <= timer_elapsed;
}

void TBoss6Type1::update_action_camera() {
    switch (this->action_state) {
    case 1:
    case 2:
    case 4:
    case 24:
    case 25:
        request_float_camera();
        break;
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        request_top_jittered_camera();
        break;
    case 22:
        request_laser_camera();
        break;
    case 21:
        request_tail_attack_camera();
        break;
    case 26:
        request_float_camera();
        break;
    case 30:
    case 31:
        request_top_jittered_camera();
        break;
    case 27:
        request_top_jittered_camera();
        break;
    case 32:
        request_top_jittered_camera();
        break;
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 34:
    case 35:
    case 36:
        this->request_default_jittered_camera();
        break;
    case 37:
        if (this->action_timer > (s32) ((f32) this->action_duration - 30.0f)) {
            this->request_default_jittered_camera();
            break;
        }
        break;
    default:
        request_jittered_camera(NULL, NULL, 0xFFFF);
        break;
    }
}
void TBoss6Type1::fire_at_all_players(f32 dy) {
    Vec me;
    Vec pp;
    Vec ofs;
    Vec d;
    Vec out;
    s32 n;
    s32 i;
    TObjPlayer *p;
    f32 h;
    f32 dist;
    f32 a;
    f32 b;
    f32 c;

    n = TLobby::get_game_mode();
    VecCopy(&me, &position);
    if (attack_mode != 0) {
        me.y -= dy;
    } else {
        me.y += dy;
    }
    for (i = 0; i < n; i++) {
        p = TObjPlayer::get_player_data(i);
        VecCopy((Vec *)&ofs, (const Vec *)&boss6_type1_camera_eye);
        if (p == 0) continue;
        VecCopy(&pp, &p->position);
        pp.y += ofs.y;
        VecCopy((Vec *)&d, (const Vec *)&me);
        subtract_vector(&d, &pp);
        h = d.y;
        d.y = 0.0f;
        dist = ofs.z + vector_length(&d);
        if (dist <= 1.0f) dist = 1.0f;
        out.x = 0.0f;
        out.z = 45.42f;
        out.y = 25.43f - h * out.z / dist;
        if (out.y < 5.0f) {
            out.y = 5.0f;
            if (h > 1e-5f) {
                a = 14.799999f * dist;
                out.z = a / h;
                if (out.z < 35.42f) {
                    b = 35.42f + dist;
                    out.z = 35.42f;
                    c = 35.42f * h - a;
                    if (fabs_float(b) > 1e-5f) {
                        a = c / b;
                        if (a > 10.0f) a = 10.0f;
                        ofs.y += a;
                    }
                }
            }
        }
        request_jittered_camera(&ofs, &out, p->get_entity_id());
    }
}

void TBoss6Type1::request_float_camera() {
    fire_at_all_players(80.0f);
}
void TBoss6Type1::request_laser_camera() {
    Vec eye = boss6_type1_camera_eye;
    Vec target = boss6_type1_camera_target;
    f32 t = laser_scale;
    if (t > 0.0f) {
        eye.x += t * boss6_type1_laser_camera_eye_shift.x;
        eye.y += t * boss6_type1_laser_camera_eye_shift.y;
        eye.z += t * boss6_type1_laser_camera_eye_shift.z;
        target.x += t * boss6_type1_laser_camera_target_shift.x;
        target.y += t * boss6_type1_laser_camera_target_shift.y;
        target.z += t * boss6_type1_laser_camera_target_shift.z;
    }
    request_jittered_camera(&eye, &target, 0xFFFF);
}

void TBoss6Type1::request_tail_attack_camera() {
    fire_at_all_players(0.0f);
}
void TBoss6Type1::request_top_jittered_camera() {
    request_jittered_camera(&boss6_type1_top_camera_eye, &boss6_type1_top_camera_target, 0xFFFF);
}

void TBoss6Type1::request_default_jittered_camera() {
    request_jittered_camera(&boss6_type1_default_camera_eye, &boss6_type1_default_camera_target, 0xFFFF);
}
void TBoss6Type1::request_jittered_camera(const Vec *eye, const Vec *target, u16 client_id) {
    f32 dist;
    Vec off;
    if (eye == NULL) {
        eye = &boss6_type1_camera_eye;
    }
    if (target == NULL) {
        target = &boss6_type1_camera_target;
    }
    dist = 0.1f * xyz_distance((Vec *)eye, (Vec *)target);
    if (dist < 4.0f) {
        dist = 4.0f;
    }
    off.x = dist * (0.000030517578f * (f32)rand() - 0.5f);
    off.y = dist * (0.000030517578f * (f32)rand() - 0.5f);
    off.z = dist * (0.000030517578f * (f32)rand() - 0.5f);
    {
        Vec p = *eye;
        vec3_add_to(&p, &off);
        request_follow_camera_offsets(&p, (Vec *)target, client_id);
    }
}

void Boss6PolarBytes::decode_polar_position(Vec *position) {
    f32 distance;
    f32 elevation;
    s32 yaw;
    yaw = static_cast<s32>(angle) * 256;
    distance = static_cast<f32>(radius * 10);
    elevation = static_cast<f32>(height * 10);
    position->x = distance * sin_table_lookup(yaw);
    position->z = distance * cos_table_lookup(yaw);
    position->y = elevation;
}

void Boss6FlowAction::decode_target(Vec *target) { position.decode_polar_position(target); }
void TBoss6Type1::calc_grid_cell_position(Vec *out) {
    u32 t = action_state;
    s8 b = random_factor;
    s32 sh = (t >> 1) & 3;
    s32 a = (b >> sh) & 0xF;
    s32 c = (b >> ((sh + 2) & 3)) & 0xF;
    if (t & 1) {
        a = ~a & 0xF;
        c = ~c & 0xF;
    }
    out->x = 7.9787235f * (f32)a - 63.82979f;
    out->y = position.y;
    out->z = 7.9787235f * (f32)c - 63.82979f;
}
void TBoss6Type1::pick_sword_move_target(Vec *out) {
    f32 radius;
    s32 angle;
    s32 turn;
    u32 seed;
    s32 far;
    {
        s32 k = action_state * 0x12D687;
        s8 c = random_factor;
        seed = c * k;
    }
    turn = ((seed & 3) * 0x1800) + 0x2000;
    far = (seed >> 3) & 1;
    if ((seed >> 2) & 1) {
        turn = -turn;
    }
    radius = 180.0f;
    angle = rotation_y + turn;
    if (far != 0) {
        radius = 280.0f;
    }
    out->x = radius * sin_table_lookup(angle);
    out->y = 100.0f;
    out->z = radius * cos_table_lookup(angle);
}

void TBoss6Type1::clamp_to_arena_radius(Vec *out) {
    Vec v = position;
    f32 len;
    f32 s;
    v.y = 0.0f;
    len = vector_length(&v);
    if (len <= 0.00001f) {
        VecCopy(out, &position);
        return;
    }
    s = 180.0f / len;
    v.x = v.x * s;
    v.z = v.z * s;
    out->x = v.x;
    out->y = 100.0f;
    out->z = v.z;
}

s32 TBoss6Type1::pick_remapped_list_value(s32 a, s32 b, s32 n) {
    s32 i;
    if (n > 0x20) {
        n = 0x20;
    }
    for (i = 0; i < n; i++) {
        s32 v = action_history[i];
        if (v == a) {
            return b;
        }
        if (v == b) {
            return a;
        }
    }
    if (0.000030517578f * (f32)rand() < 0.5f) {
        return a;
    }
    return b;
}
int TBoss6Type1::rand_range_inclusive(int lo, int hi) {
    if (lo >= hi) {
        return lo;
    }
    return (int)((0.99f + ((f32)hi - (f32)lo)) * (0.000030517578f * (f32)rand()) + (f32)lo);
}

s32 TBoss6Type1::pick_random_entry(const s32 *table, s32 count) {
    s32 i = (s32)(((f32)count - 0.01f) * (0.000030517578f * (f32)rand()));
    if (i >= count) {
        i = 0;
    }
    return table[i];
}

s32 TBoss6Type1::count_matches(s32 action, s32 depth) {
    s32 i;
    s32 cnt;
    if (depth > 0x20) {
        depth = 0x20;
    }
    cnt = 0;
    for (i = 0; i < depth; i++) {
        if (action_history[i] == action) {
            cnt++;
        }
    }
    return cnt;
}

void TBoss6Type1::update_appear_position(s32 step, s32 total) {
    Vec pos;
    f32 peak;
    f32 t;
    f32 k;
    s32 angle;
    t = 1.0f - ((f32)step / (f32)total);
    if (t < 0.0f) {
        t = 0.0f;
    } else if (t > 1.0f) {
        t = 1.0f;
    }
    angle = (s32)(24576.0f * t);
    peak = sin_table_lookup(0x6000);
    k = sin_table_lookup(angle) / peak;
    if (angle > 0x4000) {
        k += (1.0f - k) * TBoss6PlotFalz::cosine_ease((t - 0.6666667f) / 0.3333333f);
    }
    VecCopy(&pos, &boss6_type1_base_position);
    subtract_vector(&pos, &boss6_type1_spawn_position);
    pos.x *= k;
    pos.y *= k;
    pos.z *= k;
    vec3_add_to(&pos, &boss6_type1_spawn_position);
    VecCopy(&position, &pos);
}
void TBoss6Type1::ease_toward_target(s32 a, s32 b) {
    s32 h = b / 2;
    if (b <= 0 || a <= h) return;
    position.y += 0.25f * ((-300.0f + target_position.v.y) - position.y);
}
void TBoss6Type1::interpolate_pos_to_target(s32 step, s32 total) {
    Vec v;
    s32 a0;
    s32 a1;
    f32 r0;
    f32 r1;
    f32 t;
    f32 k;
    f32 r;
    s32 a;
    if (total <= 0) return;
    if (step <= 0) {
        VecCopy(&position, &target_position.v);
        return;
    }
    VecCopy(&v, &position);
    v.y = 0.0f;
    r0 = vector_length(&v);
    a0 = 10430.38043493439 * atan2_float(v.x, v.z);
    VecCopy(&v, &target_position.v);
    v.y = 0.0f;
    r1 = vector_length(&v);
    a1 = 10430.38043493439 * atan2_float(v.x, v.z);
    t = (f32)step / (f32)total;
    if (total <= 10 || t <= 0.1f) {
        k = 1.0f / (f32)step;
    } else {
        k = 2.0f * sin_table_lookup(32768.0f * t) / (f32)step;
    }
    r = k * (r1 - r0) + r0;
    a = k * (f32)angle_diff_s16(a0, a1) + (f32)a0;
    position.x = r * sin_table_lookup(a);
    position.z = r * cos_table_lookup(a);
    position.y += k * (target_position.v.y - position.y);
}

void TBoss6Type1::rotate_around_center(s32 num, s32 den) {
    Vec v;
    f32 dist;
    s32 angle;
    s32 off;
    if (den <= 0 || num <= 0) {
        return;
    }
    {
    {
        VecCopy((Vec *)&v, &this->position);
        v.y = 0.0f;
        dist = vector_length(&v);
        angle = (s32)(10430.38043493439 * atan2_float(v.x, v.z));
        off = (s32)(40960.0f * sin_table_lookup((s32)(32768.0f * ((f32)num / (f32)den))) / (f32)num);
        if (random_factor & 1) {
            off *= -1;
        }
        angle += off;
        position.x = dist * sin_table_lookup(angle);
        position.z = dist * cos_table_lookup(angle);
        }
    }
}

void TBoss6Type1::clear_effect_slots() {
    s32 i;
    for (i = 0; i < 4; i++) effect_slots[i] = 0;
}

void TBoss6Type1::release_effect_slots() {
    s32 i;
    for (i = 0; i < 4; i++) {
        release_effect_slot(i);
    }
}
void TBoss6Type1::update_effect_slots() {
    s32 i;
    const Boss6EffectSlotDesc *t = TBoss6Type1__effect_slot_table;
    for (i = 0; i < 4; i++) {
        Vec v = position;
        const Boss6EffectSlotDesc *e = &t[i];
        if (effect_slots[i] != 0) {
            s32 k = e->node;
            if (k >= 0) {
                VecCopy(&v, &node_points[k]);
            }
            effect_slots[i]->set_position(&v);
            switch (i) {
            case 0:
            case 1:
                effect_slots[i]->set_direction((void *)boss6_type1_effect_direction);
                break;
            }
        }
    }
}

void TBoss6Type1::spawn_effect_slot(s32 slot) {
    if (effect_slots[slot] == 0) {
        Vec v = position;
        effect_slots[slot] = create_particle_emitter(&v, TBoss6Type1__effect_slot_table[slot].effect_id);
        if (effect_slots[slot] != 0) {
            effect_slots[slot]->set_flags(0x40);
        }
    }
}
void TBoss6Type1::release_effect_slot(s32 slot) {
    if (effect_slots[slot] != 0) {
        TParticleCtrl::release(effect_slots[slot]);
        effect_slots[slot] = 0;
    }
}

void TBoss6Type1::clear_slot_array() {
    s32 i;
    this->laser_frames = 0;
    for (i = 0; i < slot_count(); i++) slot_particles[i] = 0;
}

void TBoss6Type1::destroy_slot_particles() { release_slot_particles(); }

void TBoss6Type1::count_laser_frame() {
    laser_frames += 1;
}

void TBoss6Type1::release_slot_particles() {
    s32 i;
    laser_frames = 0;
    for (i = 0; i < slot_count(); i++) {
        TParticleCtrl *slot = slot_particles[i];
        if (slot != 0) {
            TParticleCtrl::release(slot);
            slot_particles[i] = 0;
        }
    }
}
void TBoss6Type1::clear_map_csn() { map_csn = 0; }

void TBoss6Type1::destroy_map_csn() { release_map_csn(); }

void TBoss6Type1::spawn_map_csn() {
    MapCsnSetData data;
    Vec offset;
    VecCopy(&data.position, &position);
    push_matrix();
    set_matrix_identity(0);
    rotate_matrix_y(0, rotation_y);
    rotate_vector_by_matrix(0, &boss6_map_csn_offset, &offset);
    data.position.x += offset.x;
    data.position.y = 0.0f;
    data.position.z += offset.z;
    pop_matrix();
    data.rotation_x = 0;
    data.rotation_y = rotation_y;
    data.rotation_z = 0;
    VecCopy(&data.scale, &boss6_map_csn_scale);
    data.params[0] = 2;
    data.params[1] = 0;
    map_csn = TObjMapCsn::create(&data);
}

void TBoss6Type1::release_map_csn() {
    if (map_csn != 0) {
        map_csn->queue_destruction();
        map_csn = 0;
    }
}

void TBoss6Type1::render() {
    draw_model();
    render_laser();
}

void TBoss6Type1::draw_model() {
    TObjPlayer::toggle_particle_effect();
    push_matrix();
    Vec pos = *&position;
    pos.y = pos.y + sway_offset;
    post_translate_matrix(&pos.x);
    rotate_matrix_y(0, rotation_y);
    rotate_matrix_x(0, rotation_x);
    TBoss6PlotFalz__sub_802AC008(hit_flash, hp_ratio);
    draw_part_motions();
    TBoss6PlotFalz::update_camera_target();
    pop_matrix();
    TParticleCtrl::end_effect_render();
}
