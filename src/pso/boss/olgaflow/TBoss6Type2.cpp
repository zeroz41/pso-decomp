#include "pso/system/SoundEffect.h"
#include "pso/system/memory.h"
#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjChara.h"
#include "pso/boss/olgaflow/TBoss6Mag.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/boss/olgaflow/TBoss6Type2_8036DC80.h"
#include "pso/boss/olgaflow/OlgaFlowActions.h"
#include "pso/boss/olgaflow/TBoss6Type2BattleAction.h"
#include <stddef.h>
#include "pso/boss/olgaflow/TBoss6EffHyoui.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/olgaflow/TBoss6Rock.h"
#include "pso/boss/olgaflow/TBoss6RockChase.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/BattleParameters.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/darkfalz/TObjDFDemo5.h"
#include "pso/boss/olgaflow/Boss6Type2Data.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/olgaflow/TBoss6SwordWave.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/boss/darkfalz/TObjDFJisin.h"
#include "pso/system/SoundEffect.h"
#include <stdlib.h>
#include "pso/render/render_util.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/mine/TOComputerMachine01_8023DD0C.h"
#include "pso/boss/darkfalz/TObjDFHorming.h"
#include "pso/boss/olgaflow/TBoss6Type2_80356E50.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/system/NinjaTypes.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixOps.h"
#include "pso/camera/TCameraFollow.h"
#include "pso/network/client_id.h"
#include "pso/unk/text_803D853C.h"
#include "pso/object/base/TObjBase.h"

// One row per body motion. update_motion_tracks loops a mode 0 row, holds a
// mode 2 row on its last frame and goes on to row `next`.
struct TBoss6Type2Motion {
    s32 mode;
    s32 next;
    s32 motion[1];  // BML motion of each track (motion_track_count tracks)
    f32 speed;      // frames per update
};

CollisionBody boss6_type2_collision_parts[3] = {
    { { 0.0f, 0.0f, 0.0f }, 15.0f, 0.0f, 0, 0x801B },
    { { 0.0f, 0.0f, 0.0f }, 15.0f, 0.0f, 0, 0x801B },
    { { 0.0f, 0.0f, 0.0f }, 15.0f, 0.0f, 0, 0x801B },
};

TBoss6Type2Motion TBoss6Type2__motion_table[15] = {
    { 0, 0, { 0x37 }, 0.6f },
    { 2, 0, { 0x27 }, 0.2f },
    { 0, 2, { 0x3A }, 0.28f },
    { 0, 3, { 0x3B }, 0.25f },
    { 2, 5, { 0x18 }, 0.48f },
    { 0, 5, { 0x19 }, 0.6f },
    { 2, 0, { 0x10 }, 0.35f },
    { 2, 0, { 0x06 }, 0.3f },
    { 2, 0, { 0x1B }, 0.42f },
    { 2, 0, { 0x1A }, 0.42f },
    { 2, 0, { 0x1C }, 0.45f },
    { 2, 0xD, { 0x02 }, 0.5f },
    { 2, 0, { 0x01 }, 0.6f },
    { 0, 0xD, { 0x39 }, 0.6f },
    { 0, 0xE, { 0x3C }, 0.32f },
};

// The two offsets request_default_follow_camera hands to request_follow_camera_offsets.
Vec boss6_type2_follow_camera_position = { 0.0f, 34.8f, -5.0f };
Vec boss6_type2_follow_camera_target = { 0.0f, 10.43f, 70.42f };

// The record exchange_object_state reads and writes.
struct TBoss6Type2StateRecord { s32 flags; s16 pad_04; s16 value; s32 pad_08; };



extern "C" {
void TBoss6Type2__sub_802BE4E0(s32 *arg0, s32 *boss6_type2_zero_vec);

// One leg contact for update_leg_ground_effects: its node, the particle slot it drives and
// the node height above which (up to 20 units) the slot's dust stays alive.
struct Boss6Type2LegEffect { s32 node; s32 particle_slot; f32 ground_height; };


struct ByteBlock_C { u8 bytes[0xc]; };



// Read by the TBoss6Type2_802BE588/_802BF558 units and TBoss6Rock; emitted ahead of the literal pool.
extern const f32 boss6_arena_radius = 400.0f;
extern const f32 boss6_type2_search_speed = 0.2f;
extern const f32 boss6_type2_bkjump_speed = 0.35f;
extern const f32 boss6_type2_iai_speed = 0.42f;
extern const f32 boss6_type2_bsk_speed = 0.5f;
extern const f32 boss6_type2_chg_to_cmn_speed = 0.6f;
extern const f32 boss6_type2_b_wait_speed = 0.6f;

extern const s32 boss6_type2_hit_check_value_table[] = { 1, 13, 24, 26 };
extern const Boss6Type2LegEffect boss6_type2_leg_effect_table[] = {
    { 3, 3, 11.0f }, { 4, 4, 9.0f }, { 5, 5, 5.0f }, { 8, 0, 11.0f }, { 9, 1, 9.0f }, { 10, 2, 5.0f },
};
extern const s32 boss6_type2_hit_effect_node_table[] = { 4, 9, 11, 0 };





struct Blk_802BCFD4;

// The body runs one motion track (trk[], TBoss6Type2Motion::motion[]); track 0 follows
// the motion table rows. The code loads both from .sdata2, and CW puts them inside the
// literal pool at their first user, so they are file constants read through references.
static const s32 motion_track_count = 1;
static const s32 main_motion_track = 0;

inline const s32 &get_motion_track_count() { return motion_track_count; }
inline const s32 &get_main_motion_track() { return main_motion_track; }


}

void TBoss6Type2::clear_harmful_statuses() {}

void TBoss6Type2::apply_shock_status() {}

void TBoss6Type2::apply_movement_ailment(s32) {}

void TBoss6Type2::apply_confusion_status() {}

void TBoss6Type2::apply_slow_status() {}

void TBoss6Type2::apply_paralysis() {}

void TBoss6Type2::apply_poison_status() {}

TBoss6Type2 *TBoss6Type2::create(Boss6BodySpawnParams *params) {
    return new TBoss6Type2(new TObjControl(tl_04), params);
}

void TBoss6Type2__sub_802BE4E0(s32 *arg0, s32 *boss6_type2_zero_vec) {
    *arg0 = *boss6_type2_zero_vec;
    *(ByteBlock_C *)((saddr) arg0 + 4) = *(const ByteBlock_C *)((saddr) boss6_type2_zero_vec + 4);
}

#pragma push
#pragma opt_common_subs off
TBoss6Type2::TBoss6Type2(TObject *parent, Boss6BodySpawnParams *params) : TObjEnemy(parent) {
    TBoss6Type2StateRecord record;
    s32 i;
    s32 id;
    m_name = TBoss6Type2__name;
    plot_falz = params->owner;
    apply_set_data(&params->set_entry);
    if (exchange_object_state(&record, 1) != 0) {
        record.flags = 0;
        record.value = 0;
        exchange_object_state(&record, 0);
    }
    archive = TBoss6PlotFalz::get_scene_archive();
    texlist = 0;
    model = 0;
    VecCopy(&position, &TBoss6Type2__initial_position);
    copy_xyz(&rotation_x, (void *)TBoss6Type2__initial_rotation);
    VecCopy(&prev_position, VecCopy(&home_position, VecCopy(&center, &position)));
    init_collision_body_parts(this, boss6_type2_collision_parts, 3);
    advance_position();
    velocity.z = 0.0f;
    velocity.y = 0.0f;
    velocity.x = 0.0f;
    target = 0;
    bind_enemy_combat_stats(TLobby::register_boss(0x2C), TLobby::dispatch_shared_handler_b(0x2C), TLobby::register_object(0x2C));
    referenceHp = prev_hp = hp;
    register_by_id();
    set_param(0x4E);
    id = static_cast<s8>(params->variant) % 4;
    add_flags_2e4(TBoss6Type2__initial_actor_flag_masks[id]);
    target_mode = id;
    variant = target_state = boss6_type2_variant_id_table[(static_cast<s8>(params->variant) >> 2) % 4];
    init_segment_range();
    {
    s32 k;
    for (k = 0; k < 2; k++) {
        TBoss6Type2Model *e = &body_models[k];
        id = lbl_8047128C[k];
        e->texlist = get_bml_texlist(archive, id);
        e->model = get_bml_model(archive, id);
    }
    }
    init_motion_entries();
    node_capture[0] = ModelNodePositionCapture::create(boss6_type2_effect_desc_table, node_positions);
    scroll_strips.build_tables(boss6_type2_plot_falz_entry_table, 2);
    trail_effect = TBoss6Zanzo::create(this, 7, 0xF);
    random_factor = 0;
    next_motion = 0x11;
    TBoss6Type2__sub_802BE4E0((s32 *)&move_target, (s32 *)boss6_type2_zero_vec);
    move_target.heading = rotation_y;
    VecCopy(&move_target.position, &position);
    action_flags = 0;
    for (i = 0; i < 32; i++) {
        action_history[i] = 0;
    }
    berserk = 0;
    state_progress = 0.0f;
    berserk_wait_count = 0;
    low_hp = 0;
    possess_target = 0xFFFF;
    target_client = pick_target_client();
    first_action_client = 0xFFFF;
    second_action_client = 0xFFFF;
    last_walk_def = -1;
    iai_count = 0;
    load_battle_params();
    set_screen_pos();
    copy_anim_state();
    reset_attack_counter();
    reset_indices();
    hit_flash = 0.0f;
    hp_ratio = 1.0f;
    turn_sound_played = 0;
    create_mags(0.0f);
    call_mags_to_shoulders();
    TBoss6Rock::create_rock_pool(this);
    reset_lower_contact();
    capture_boss6_player_snapshots();
    cache_fish_params();
    init_collected_entries();
    set_fields_554();
    clear_particle_emitters();
    spawn_particle_slot(0);
    spawn_particle_slot(1);
    spawn_particle_slot(2);
    spawn_particle_slot(3);
    spawn_particle_slot(4);
    spawn_particle_slot(5);
    set_action_state(0);
}
#pragma pop

TBoss6Type2::~TBoss6Type2() {
    s32 i;
    init_parts();
    reset_counters();
    TBoss6Rock::clear_owner();
    for (i = 0; i < 2; i++) {
        TBoss6Type2Model *e = &body_models[i];
        e->texlist = 0;
        e->model = 0;
    }
    scroll_strips.free_buffer_pairs();
    for (i = 0; i < 1; i++) {
        if (node_capture[i] != 0) {
            ModelNodePositionCapture::destroy(node_capture[i]);
            node_capture[i] = 0;
        }
    }
    free_collision_body_parts(this);
}

void TBoss6Type2::build_state_packet(OlgaFlowType2ActionMsg *message) {
    u16 first;
    u16 second;
    message->header.client_id = entity_id;
    message->random_factor = static_cast<u8>(127.0f * (3.0517578e-05f * static_cast<f32>(rand())));
    message->next_motion = choose_random_motion();
    message->target_mode = static_cast<s8>(target_mode);
    message->target_state = static_cast<s8>(target_state);
    message->first_client = static_cast<s8>(possess_target);
    message->second_client = static_cast<s8>(target_client);
    pick_action_clients(&first, &second);
    message->first_action_client = static_cast<s8>(first);
    message->second_action_client = static_cast<s8>(second);
}

void TBoss6Type2::parse_action_packet(OlgaFlowType2ActionMsg *packet) {
    random_factor = packet->random_factor;
    next_motion = packet->next_motion;
    set_target_state(packet->target_mode, packet->target_state);
    possess_target = packet->first_client;
    target_client = packet->second_client;
    first_action_client = packet->first_action_client;
    second_action_client = packet->second_action_client;
    if (possess_target >= 4) {
        possess_target = 0xFFFF;
    }
    if (target_client >= 4) {
        target_client = 0xFFFF;
    }
    if (first_action_client >= 4) {
        first_action_client = 0xFFFF;
    }
    if (second_action_client >= 4) {
        second_action_client = 0xFFFF;
    }
    mags[0]->set_action_field_0x408(first_action_client);
    mags[1]->set_action_field_0x408(second_action_client);
}

void TBoss6Type2::send_action_packet(s32 action) {
    OlgaFlowType2ActionMsg message;
    if (plot_falz->is_idle() != 0) {
        message.initialize();
        build_state_packet(&message);
        message.flow.action = action;
        message.send();
    }
}

void TBoss6Type2::send_action_packet_if_idle(s32 action, Boss6GridBytes *grid) {
    OlgaFlowType2ActionMsg message;
    const s8 *bytes;
    s32 i;
    if (plot_falz->is_idle() != 0) {
        message.initialize();
        build_state_packet(&message);
        bytes = &grid->grid_x;
        message.flow.action = action;
        for (i = 1; i < 4; i++) {
            (&message.flow.action)[i] = *bytes++;
        }
        message.send();
    }
}

void TBoss6Type2::update_action_state() {
    Boss6GridBytes grid;
    s32 action;

    pick_walk_target(&grid);
    action = 4;
    if (last_walk_def == 0) {
        action = 5;
    }
    send_action_packet_if_idle(action, &grid);
}

void TBoss6Type2::send_state_action_packet() {
    Boss6GridBytes grid;
    s32 action;
    if (low_hp != 0) {
        action = 7;
        if (last_walk_def == 0) {
            action = 0xA;
        }
    } else {
        action = 8;
        if (last_walk_def == 0) {
            action = 0xB;
        }
    }
    switch (action_state) {
    case 6:
    case 9:
        return;
    case 7:
    case 8:
    case 10:
    case 11:
        target_client = pick_target_client();
        action = action_state - 1;
    default:
        pick_walk_target(&grid);
        send_action_packet_if_idle(action, &grid);
        break;
    }
}

void TBoss6Type2::update_attack_target() {
    Boss6GridBytes grid;
    s32 action;
    u16 previous_target;
    u16 target;

    action = low_hp != 0 ? 0x1F : 0x21;
    switch (action_state) {
    case 0x1D:
        return;
    case 0x1E:
    case 0x1F:
    case 0x20:
    case 0x21:
        previous_target = target_client;
        target = pick_target_client();
        if (target == 0xFFFF) {
            if (TBoss6PlotFalz::is_active(get_player_by_client_id(previous_target)) != 0) {
                target = previous_target;
            }
        }
        target_client = target;
        if (TBoss6PlotFalz::get_phase() == 0 && (action_state & 1)) {
            target_client = 0xFFFF;
        }
        action = action_state - 1;
        break;
    }
    pick_walk_target(&grid);
    send_action_packet_if_idle(action, &grid);
}

#pragma push
#pragma opt_common_subs off
void TBoss6Type2::pick_walk_target(Boss6GridBytes *grid) {
    s8 grid_x;
    s8 grid_z;
    Vec target;
    Vec dir;
    f32 dist;
    s32 angle;
    s32 angle2;
    TObjPlayer *player;
    player = get_player_by_client_id(target_client);
    if (player != NULL) {
        VecCopy(&target, &player->position);
    } else {
        target_client = 0xFFFFU;
        angle = (s32) ((6144.0f * -((3.0517578e-05f * (f32) rand()) - 0.5f)) + (f32) (s32) rotation_y);
        VecCopy(&target, &position);
        target.x += 150.0f * sin_table_lookup(angle);
        target.z += 150.0f * cos_table_lookup(angle);
        if (xyz_distance(&position, (Vec *)&boss6_arena_center) > 390.0f) {
            angle2 = (s32) (65535.0f * (3.0517578e-05f * (f32) rand()));
            VecCopy(&target, &boss6_arena_center);
            target.x += 150.0f * sin_table_lookup(angle2);
            target.z += 150.0f * cos_table_lookup(angle2);
        }
    }
    target.y = 0.0f;
    VecCopy(&dir, &target);
    subtract_vector(&dir, &position);
    dir.y = 0.0f;
    dist = vector_length(&dir);
    if (dist < 7.874016f) {
        if (dist <= 1e-05f) {
            target.x = 1.0f;
        } else {
            normalize_vector(&dir);
        }
        dir.x *= 7.874016f;
        dir.z *= 7.874016f;
        VecCopy(&target, &dir);
        vec3_add_to(&target, &position);
    }
    world_to_grid_pos(&target, &grid_x, &grid_z);
    grid->grid_x = grid_x;
    grid->grid_z = grid_z;
}
#pragma pop

extern "C" void handle_6xA5_olga_flow_boss_actions(game_command_header *command) {
    OlgaFlowType2ActionMsg *packet = reinterpret_cast<OlgaFlowType2ActionMsg *>(command);
    TBoss6Type2 *boss;
    saddr state;
    packet->swap_entity_id();
    boss = (TBoss6Type2 *)get_enemy_entity(packet->header.client_id);
    if (boss == NULL) {
        return;
    }
    packet->flow.decode_target(&boss->move_target);
    boss->parse_action_packet(packet);
    state = packet->flow.action;
    if (state < 0 || state >= 36) {
        return;
    }
    boss->set_action_state(state);
}

int TBoss6Type2::get_table_entry(int a0) {  return TBoss6Type2__initial_actor_flag_masks[a0]; }

s32 TBoss6Type2::find_index_in_table(u32 v) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (v == ((const u32 *)TBoss6Type2__initial_actor_flag_masks)[i]) return i;
    }
    return 0;
}

s32 TBoss6Type2::pick_random_other_index() {
    TBoss6Type2 *o = this;
    s32 t = TBoss6Type2::find_index_in_table(o->target_attribute_mask);
    s32 r = t + (s32)(2.99f * (3.0517578e-05f * (f32)rand())) + 1;
    if (r >= 4) {
        r -= 4;
    }
    return r;
}

s32 TBoss6Type2::choose_next_index() {
    s32 k = (s32)(2.99f * (3.0517578e-05f * (f32)rand())) + 1;
    s32 r = variant + k;
    if (r > 4) {
        r -= 4;
    }
    return r;
}

void TBoss6Type2::set_target_state(s32 mode, s32 new_variant) {
    u32 old_mask;
    s32 old_variant;

    old_mask = target_attribute_mask;
    old_variant = variant;
    target_attribute_mask = get_table_entry(mode);
    variant = new_variant;
    update_segments();
    if (old_mask != target_attribute_mask || old_variant != variant) {
        set_state_0x34();
    }
    if (mags[0] != 0) {
        mags[0]->set_target_nodes(target_attribute_mask, variant);
    }
    if (mags[1] != 0) {
        mags[1]->set_target_nodes(target_attribute_mask, variant);
    }
}

s32 TBoss6Type2::count_matching_values(s32 action, s32 depth) {
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

void TBoss6Type2::run_hit_reaction() {
    actorFlags = (s32) (actorFlags & 0xFFFFFDFF);
    hit_flash = 1.0f;
    {
        int diff = prev_hp - hp;
        if (diff > 0) {
            add_damage(diff);
        }
    }
    if ((s32) berserk != 0) {
        play_sound_effect(0x68A24, &position, 0, 1);
    }
}

void TBoss6Type2::run_death_reaction() { if ((s32)action_state != 35) { set_action_state(35); } }

f32 TBoss6Type2::receive_physical_attack(void *att, f32 scale) {
    s32 hurt;
    s32 attributes;
    s32 i;

    hurt = 1;
    if (berserk != 0 && att != 0) {
        // While berserk only a weapon attribute in target_attribute_mask gets through.
        attributes = 0;
        i = 0;
        do {
            switch (*(u8 *)((TObjPlayer *)att)->get_attribute_entry(i)) {
            case 1:
                attributes |= 1;
                break;
            case 2:
                attributes |= 2;
                break;
            case 3:
                attributes |= 4;
                break;
            case 4:
                attributes |= 8;
                break;
            }
            i++;
        } while (i < 3);
        if (!(target_attribute_mask & attributes)) {
            hurt = 0;
        }
    }
    if (hurt != 0) {
        return TObjChara::receive_physical_attack(att, scale);
    }
    damage_possessed_player();
    spawn_hit_effects();
    return 0.0f;
}

f32 TBoss6Type2::receive_direct_attack(void *attacker, DirectAttackPayload msg, void *collision, s32 tech, s32 flags) {
    while ((s32)berserk != 0) {
        if (msg.kind == 0x14) {
            break;
        }
        if (TObjEneDD::query_teammate_state() != 0) {
            break;
        }
        if (msg.kind == (s32)variant) {
            break;
        }
        damage_possessed_player();
        spawn_hit_effects();
        return 0.0f;
    }
    return TObjChara::receive_direct_attack(attacker, msg, collision, tech, flags);
}

void TBoss6Type2::get_phase_values(u16 *a, u16 *b, u16 *out) {
    s32 i;
    *a = local_attacker_id;
    *b = attacker_id;
    for (i = 0; i < 4; i++) {
        out[i] = obj_getArrU16_FC(this, i);
    }
}

s32 TBoss6Type2::get_rotation_timer() { return this->berserk; }

void TBoss6Type2::get_shoulder_point(s32 index, Vec *pos, s32 *rotation) {
    VecCopy(pos, &node_positions[index + 0xE]);
    *rotation = rotation_y;
}

void TBoss6Type2::apply_damage(s32 diff) {
    if ((diff > 0) && ((s32) this->berserk == 0)) {
        add_damage(diff);
    }
}

void TBoss6Type2::on_mag_dead() {  }

void TBoss6Type2::copy_pos_59c(Vec *out) {
    VecCopy(out, &node_positions[0]);
}

void TBoss6Type2::get_push_points(Vec *first, Vec *second) {
    VecCopy(first, &node_positions[8]);
    VecCopy(second, &node_positions[3]);
}

void TBoss6Type2::copy_pos_620(Vec *out) {
    VecCopy(out, &node_positions[11]);
}

#pragma push
#pragma opt_common_subs off
void TBoss6Type2::run_task() {
    TBoss6Type2BattleHandler handler;
    update_lower_contact_delta();
    handler = boss6_type2_battle_actions[action_state].update;
    if (handler) {
        (this->*handler)();
    }
    if (((TBoss6PlotFalz *)plot_falz)->is_idle() != 0) {
        handler = boss6_type2_battle_actions[action_state].idle;
        if (handler) {
            (this->*handler)();
        }
    }
    update_motion_tracks();
    advance_position();
    this->update_collision_bodies();
    update_parts_flags();
    update_collisions();
    submit_cursor_candidate(this, -1);
    add_radar_scaled_marker(&this->position, -0x5DB4, 1, 1, 4.0f);
    apply_rock_hits_to_players();
    update_camera();
    decay_glow_and_calc_hp_ratio();
    scroll_strips.scroll_strips_uv(8, 0);
    NJS_CNK_MODEL *scroll_model = static_cast<NJS_CNK_MODEL *>(find_model_node(get_bml_model(archive, 1), 1)->model);
    TObjPlayer__sub_8023DEE0(scroll_model->polygon_list, 8, 0, 0);
    update_head_aim();
    copy_vec_array();
    if ((s32) this->berserk != 0) {
        play_persistent_sound(0x4006B00C, this, &position, 0, 0);
    }
    update_countdown();
    update_possess_target();
    update_footstep_effects();
    update_leg_ground_effects();
    update_part_positions();
    this->prev_hp = (s32) this->hp;
}
#pragma pop

void TBoss6Type2::set_action_state(s32 action) {
    s32 i;
    const TBoss6Type2BattleAction *entry;
    TBoss6Type2BattleHandler handler;
    action_state = action;
    for (i = 31; i > 0; i--) {
        action_history[i] = action_history[i - 1];
    }
    action_history[0] = action_state;
    entry = &boss6_type2_battle_actions[action_state];
    change_motion(entry->motion);
    action_flags = entry->flags;
    handler = entry->enter;
    if (handler) {
        (this->*handler)();
    }
}

Blk_802BCFD4 *TBoss6Type2::copy_block(Blk_802BCFD4 *d, const Blk_802BCFD4 *s) {
    *d = *s;
    return d;
}

void TBoss6Type2MotionTrack::copy_from(TBoss6Type2MotionTrack *src) { *this = *src; }

void TBoss6Type2::init_motion_entries() {
    s32 i;
    TBoss6Type2::copy_block((Blk_802BCFD4 *)&motion_index, &boss6_type2_zero_motion_block);
    for (i = 0; i < get_motion_track_count(); i++) {
        TBoss6Type2MotionTrack *e = &motion_tracks[i];
        AnimationMotion *motion;
        e->copy_from((TBoss6Type2MotionTrack *)&boss6_type2_motion_entry_transform);
        motion = get_bml_motion(archive, TBoss6Type2__motion_table[0].motion[i]);
        e->prev_motion = motion;
        e->motion = motion;
        e->speed = TBoss6Type2__motion_table[0].speed;
    }
}

void TBoss6Type2::update_motion_tracks() {
    s32 i;
    TBoss6Type2MotionTrack *e;
    f32 n;
    f32 lim;

    for (i = 0; i < get_motion_track_count(); i++) {
        if (i != get_main_motion_track()) {
            e = &motion_tracks[i];
            n = (f32)e->motion->frameCount;
            e->frame += e->speed;
            if (e->frame >= n) {
                e->frame -= n;
            }
            if (0.0f != e->blend) {
                if ((e->blend += e->blend_step) >= 1.0f) {
                    e->blend = 0.0f;
                }
            }
        }
    }
    e = &motion_tracks[get_main_motion_track()];
    n = (f32)e->motion->frameCount;
    e->frame += e->speed;
    switch (motion_mode) {
    case 0:
        if (e->frame >= n) {
            e->frame -= n;
        }
        break;
    case 1:
        break;
    case 2:
        lim = n - 1.0f;
        if (e->frame >= lim) {
            e->frame = lim;
            change_motion(TBoss6Type2__motion_table[motion_index].next);
        }
        break;
    }
    if (0.0f != e->blend) {
        if ((e->blend += e->blend_step) >= 1.0f) {
            e->blend = 0.0f;
        }
    }
}

void TBoss6Type2::change_motion(s32 motion) {
    if (motion != -1 && motion != motion_index) {
        TBoss6Type2Motion *ent;
        s32 i;
        motion_index = motion;
        ent = &TBoss6Type2__motion_table[motion];
        motion_mode = ent->mode;
        for (i = 0; i < get_motion_track_count(); i++) {
            TBoss6Type2MotionTrack *e = &motion_tracks[i];
            AnimationMotion *next = get_bml_motion(archive, ent->motion[i]);
            e->blend = e->blend_step;
            e->prev_motion = e->motion;
            e->prev_frame = e->frame;
            e->speed = TBoss6Type2__motion_table[motion].speed;
            e->motion = next;
            e->frame = 0.0f;
        }
    }
}

void TBoss6Type2::draw_body_models() {
    NJS_MOTION_LINK link;
    f32 zero;
    f32 a;
    ModelNodePositionCapture *capture;
    s32 done;
    s32 i;
    TBoss6Type2Model *e;
    NJS_TEXLIST *texlist;
    NJS_OBJECT *model;
    set_motion_packed_rotation();
    capture = node_capture[0];
    done = 0;
    if (capture != NULL) {
        zero = 0.0f;
        for (i = 0; i < 2; i++) {
            e = &body_models[i];
            texlist = e->texlist;
            model = e->model;
            switch (i) {
            case 0:
                a = 1.0f - this->state_progress;
                break;
            case 1:
            default:
                a = this->state_progress;
                break;
            }
            if (zero != a) {
                if (a < 1.0f) {
                    TBoss6PlotFalz::set_fade_material_color(a);
                }
                TObjFish::set_global_param(texlist);
                if (0.0f == motion_tracks[0].blend) {
                    if (done != 0) {
                        draw_model_motion(model, motion_tracks[0].motion, motion_tracks[0].frame);
                    } else {
                        capture->install();
                        draw_model_motion(model, motion_tracks[0].motion, motion_tracks[0].frame);
                        capture->clear();
                        done = 1;
                    }
                } else {
                    link.motion[0] = (NJS_MOTION *)motion_tracks[0].prev_motion;
                    link.frame[0] = motion_tracks[0].prev_frame;
                    link.motion[1] = (NJS_MOTION *)motion_tracks[0].motion;
                    link.frame[1] = motion_tracks[0].frame;
                    if (done != 0) {
                        draw_model_blend_motion(model, &link, motion_tracks[0].blend);
                    } else {
                        capture->install();
                        draw_model_blend_motion(model, &link, motion_tracks[0].blend);
                        capture->clear();
                        done = 1;
                    }
                }
                if (a < 1.0f) {
                    TObjFish::reset_fish_globals();
                }
            }
        }
    }
    clear_motion_packed_rotation();
}

void TBoss6Type2::load_battle_params() {
    const BattleMovementParams *rec;
    s32 first;
    s32 second;
    rec = TLobby::dispatch_shared_handler_a(0x2C);
    rock_damage = (s32)rec->values.floats[1];
    if ((f32)rock_damage <= 0.0f) {
        rock_damage = TBoss6Type2__default_battle_parameters.int_params[0];
    }
    possessed_damage = (s32)rec->values.floats[4];
    if ((f32)possessed_damage <= 0.0f) {
        possessed_damage = TBoss6Type2__default_battle_parameters.int_params[1];
    }
    bj_wait_duration = (s32)rec->values.floats[5];
    if ((f32)bj_wait_duration <= 0.0f) {
        bj_wait_duration = TBoss6Type2__default_battle_parameters.int_params[8];
    }
    dpb_damage_threshold = rec->values.integers[0];
    if (dpb_damage_threshold <= 0) {
        dpb_damage_threshold = TBoss6Type2__default_battle_parameters.int_params[2];
    }
    berserk_damage = rec->values.integers[1];
    if (berserk_damage <= 0) {
        berserk_damage = TBoss6Type2__default_battle_parameters.int_params[3];
    }
    release_damage = rec->values.integers[2];
    if (release_damage <= 0) {
        release_damage = TBoss6Type2__default_battle_parameters.int_params[4];
    }
    kamae_duration = rec->values.integers[3];
    if (kamae_duration <= 0) {
        kamae_duration = TBoss6Type2__default_battle_parameters.int_params[5];
    }
    iai_x2_percent = rec->values.integers[4];
    iai_x3_percent = rec->values.integers[5];
    first = iai_x2_percent;
    if ((first < 0) || (first > 100) || ((second = iai_x3_percent) < 0) || (second > 100) || (first + second > 100)) {
        iai_x2_percent = TBoss6Type2__default_battle_parameters.int_params[6];
        iai_x3_percent = TBoss6Type2__default_battle_parameters.int_params[7];
    }
    rec = TLobby::dispatch_shared_handler_a(0x2F);
    base_walk_speed = rec->values.floats[0];
    if (base_walk_speed <= 0.0f) {
        base_walk_speed = TBoss6Type2__default_battle_parameters.float_params[0];
    }
    base_turn_speed = rec->values.floats[1];
    if (base_turn_speed <= 0.0f) {
        base_turn_speed = TBoss6Type2__default_battle_parameters.float_params[1];
    }
    berserk_damage_scale = rec->values.floats[2];
    if (berserk_damage_scale <= 0.0f) {
        berserk_damage_scale = TBoss6Type2__default_battle_parameters.float_params[4];
    }
    info_stat_duration = (s32)rec->values.floats[3];
    if ((f32)info_stat_duration <= 0.0f) {
        info_stat_duration = TBoss6Type2__default_battle_parameters.last_param;
    }
    rec = TLobby::dispatch_shared_handler_a(0x2E);
    low_hp_walk_speed = rec->values.floats[2];
    if (low_hp_walk_speed <= 0.0f) {
        low_hp_walk_speed = TBoss6Type2__default_battle_parameters.float_params[2];
    }
    low_hp_turn_speed = rec->values.floats[3];
    if (low_hp_turn_speed <= 0.0f) {
        low_hp_turn_speed = TBoss6Type2__default_battle_parameters.float_params[3];
    }
}

void TBoss6Type2::set_screen_pos() {
    f32 walk_speed;
    f32 turn_speed;

    if ((s32)this->low_hp != 0) {
        walk_speed = 0.28f * this->low_hp_walk_speed;
        turn_speed = 0.28f * this->low_hp_turn_speed;
    } else {
        walk_speed = 0.28f * this->base_walk_speed;
        turn_speed = 0.28f * this->base_turn_speed;
    }
    TBoss6Type2__motion_table[2].speed = walk_speed;
    TBoss6Type2__motion_table[3].speed = walk_speed;
    TBoss6Type2__motion_table[14].speed = turn_speed;
}

void TBoss6Type2::copy_anim_state() {
    latched_hp = hp;
}

s32 TBoss6Type2::calc_field4f0_delta() {
    return this->latched_hp - this->hp;
}

void TBoss6Type2::reset_attack_counter() {
    damage_total = 0;
}

void TBoss6Type2::add_damage(s32 diff) {
    switch (action_state) {
    case 5:
    case 9:
    case 10:
    case 11:
        diff *= 2;
        break;
    }
    damage_total += diff;
}

s32 TBoss6Type2::get_hit_count() {
    return damage_total;
}

void TBoss6Type2::reset_indices() {
    switch_timer = -1;
    switch_pending = 0;
}

void TBoss6Type2::start_countdown_sound_state() {
    switch_timer = 0x34;
    switch_pending = 0;
    play_sound_if_no_target();
}

void TBoss6Type2::set_state_0x34() {
    switch_timer = 0x34;
    switch_pending = 1;
    play_sound_if_no_target();
}

s32 TBoss6Type2::is_active() {
    u8 active;

    active = 0;
    if ((switch_pending != 0 && switch_timer >= 0) || action_state == 1) {
        active = 1;
    }
    return active;
}

void TBoss6Type2::update_countdown() {
    TObjPlayer *player;

    if (is_active() != 0) {
        update_attack_switch();
    }
    if (switch_timer < 0) {
        switch_pending = 0;
        switch_timer--;
        if (switch_timer < -0x12C) {
            switch_timer = -0x12C;
        }
        if (berserk != 0 && switch_timer == -0x12C) {
            player = get_player_by_client_id(possessed_client);
            if ((TBoss6PlotFalz::is_active(player) != 0) && (player->mode == 1)) {
                start_countdown_sound_state();
            }
        }
    } else {
        if (switch_timer == 0) {
            play_phase_sound();
        }
        switch_timer--;
    }
}

void TBoss6Type2::play_sound_if_no_target() {
    if (is_target_valid() == 0) {
        play_sound_effect(TBoss6Type2__no_target_sound_ids[TBoss6Type2::find_index_in_table(this->target_attribute_mask)], &position, 0, 1);
    }
}

void TBoss6Type2::play_phase_sound() {
    s32 sound;

    if (is_target_valid() == 0) {
        switch (variant) {
        case 1:
            sound = 0x6852C;
            break;
        case 2:
            sound = 0x6852D;
            break;
        case 3:
            sound = 0x6852E;
            break;
        case 4:
            sound = 0x6852F;
            break;
        case 5:
        default:
            sound = 0x6852B;
            break;
        }
        play_sound_effect(sound, &position, 0, 1);
    }
}

void TBoss6Type2::update_attack_switch() {
    if ((switch_timer % 24) == 0) {
        spawn_particle_effect_with_flags(&position, 0x224, 0x2040);
    }
}

s32 TBoss6Type2::is_target_valid() {
    if ((s32) this->berserk == 0) {
        return 0;
    }
    if (possessed_client == 0xFFFF) {
        return 1;
    }
    if (is_split_screen() != 0) {
        return 0;
    }
    return (local_client_id - (s32)possessed_client) != 0 ? 1 : 0;
}

s32 TBoss6Type2::choose_random_motion() {
    s32 m;
    f32 r;
    f32 a;
    f32 b;

    m = choose_turn_motion();
    r = (1.0f / 32768.0f) * (f32)rand();
    if (berserk == 0) {
        if (r < 0.2f) {
            return 0x11;
        }
        return m;
    }
    if (r < 0.6f) {
        m = 0x11;
    }
    r = (1.0f / 32768.0f) * (f32)rand();
    a = (f32)iai_x3_percent / 100.0f;
    b = (f32)iai_x2_percent / 100.0f + a;
    if (r <= a) {
        m += 6;
    } else if (r <= b) {
        m += 3;
    }
    return m;
}

s32 TBoss6Type2::choose_turn_motion() {
    s32 motion;
    TObjPlayer *player;
    s32 heading;

    motion = 0xF;
    player = get_player_by_client_id(target_client);
    if (random_factor & 1) {
        motion = 0x10;
    }
    if (player == NULL) {
        return motion;
    }
    heading = (s32)(10430.38043493439 * atan2_float(player->position.x - position.x, player->position.z - position.z));
    motion = 0xF;
    if (angle_diff_s16(rotation_y, heading) < 0) {
        motion = 0x10;
    }
    return motion;
}

void TBoss6Type2::decay_glow_and_calc_hp_ratio() {
    this->hit_flash += -0.06666667f;
    if (this->hit_flash < 0.0f) {
        this->hit_flash = 0.0f;
    }
    this->hp_ratio = (f32) ((f32) this->hp / (f32) this->referenceHp);
}

void TBoss6Type2::init_segment_range() {
    ActorParamBlock *e = this->param_block;
    s32 min;
    s32 max;
    max = e->values[1];
    min = max;
    if (min > e->values[2]) { min = e->values[2]; } else if (max < e->values[2]) { max = e->values[2]; }
    if (min > e->values[3]) { min = e->values[3]; } else if (max < e->values[3]) { max = e->values[3]; }
    if (min > e->values[4]) { min = e->values[4]; } else if (max < e->values[4]) { max = e->values[4]; }
    if (min > e->values[5]) { min = e->values[5]; } else if (max < e->values[5]) { max = e->values[5]; }
    segment_min = min;
    segment_max = max;
    ((TLobby *)&this->params_copy)->copy_entry(this->param_block);
    this->param_block = &this->params_copy;
    update_segments();
}

void TBoss6Type2::update_segments() {
    s16 max;

    max = segment_max;
    params_copy.values[5] = max;
    params_copy.values[4] = max;
    params_copy.values[3] = max;
    params_copy.values[2] = max;
    params_copy.values[1] = max;
    switch ((s32)variant) {
    case 1:
        params_copy.values[1] = segment_min;
        break;
    case 2:
        params_copy.values[2] = segment_min;
        break;
    case 3:
        params_copy.values[3] = segment_min;
        break;
    case 4:
        params_copy.values[4] = segment_min;
        break;
    case 5:
        params_copy.values[5] = segment_min;
        break;
    }
    m_2f2 = params_copy.values[1];
    m_2f4 = params_copy.values[3];
    m_2f6 = params_copy.values[2];
    m_2f8 = params_copy.values[5];
    m_2fa = params_copy.values[4];
}

void TBoss6Type2::copy_vec_array() {
    Vec *src;
    Vec *end;
    Vec *dst;
    src = node_positions;
    dst = prev_node_positions;
    end = src + 19;
    for (; src < end; src++, dst++) {
        VecCopy(dst, src);
    }
}

void TBoss6Type2::advance_position() {
    VecCopy(&body_center, &position);
    body_center.y += 30.0f;
}

void TBoss6Type2::update_collision_bodies() {
    Vec v;
    s32 i;
    Vec *base;
    CollisionBody *e;
    if (this->bodies != NULL) {
        for (i = 0; i < 3; i++) {
            const Tbl_802BBE20 *t;
            e = &this->bodies[i];
            t = &lbl_8047130C[i];
            base = NULL;
            switch (t->kind) {
            case 0:
                base = this->node_positions;
                break;
            }
            if (base == NULL) {
                return;
            }
            VecCopy(&v, &base[t->idx]);
            subtract_vector(&v, &this->position);
            push_matrix();
            set_matrix_identity(0);
            rotate_matrix_y(0, -this->rotation_y);
            matrix_mult_vec(0, &v, &e->offset);
            pop_matrix();
            VecCopy(&e->center, &e->offset);
            vec3_add_to(&e->center, &this->position);
        }
    }
}

void TBoss6Type2::update_parts_flags() {
    clear_part_flags();
    if (this->action_flags & 1) {
        set_child_flags();
    }
    if (this->action_flags & 2) {
        set_owner_flag_bit0();
    }
}

void TBoss6Type2::clear_part_flags() {
    CollisionBody *p = this->bodies;
    if (p != NULL) {
        CollisionBody *end = p + 3;
        for (; p < end; p++) {
            p->flags &= ~1;
        }
    }
}

void TBoss6Type2::set_child_flags() {
    if (this->bodies != NULL) {
        this->bodies[0].flags |= 1;
        this->bodies[1].flags |= 1;
    }
}

void TBoss6Type2::set_owner_flag_bit0() {
    CollisionBody *bodies = this->bodies;
    if (bodies != NULL) {
        bodies[2].flags |= 1;
    }
}

void TBoss6Type2::spawn_sword_wave() {
    s32 end_angle = 0xFFFF;
    f32 radius = 150.0f;
    s32 start_angle = 0;
    s32 sound = 0x40069E08;
    switch (action_state) {
    case 15:
    case 18:
    case 21:
        radius = 839.99994f;
        start_angle = (rotation_y - 0x1500) & 0xFFFF;
        sound = 0x40069E09;
        end_angle = start_angle + 0x8500;
        break;
    case 16:
    case 19:
    case 22:
        radius = 839.99994f;
        start_angle = (rotation_y - 0x7000) & 0xFFFF;
        sound = 0x40069E09;
        end_angle = start_angle + 0x8500;
        break;
    case 17:
    case 20:
    case 23:
        break;
    }
    TBoss6SwordWave::create(this, &position, start_angle, end_angle, radius);
    play_sound_effect(sound, &position, 0, 1);
}

void TBoss6Type2::apply_rock_hits_to_players() {
    DirectAttackPayload a;
    f32 range;
    s32 r;
    s32 i;
    s32 mask;
    s32 j;
    Vec *rock;
    s32 hit;
    TObjChara *p;
    s32 v;
    range = 10.0f;
    for (i = 0; i < 6; i++) {
        rock = &this->node_positions[TBoss6Type2__player_hit_rock_indices[i]];
        TBoss6Rock::break_rocks_in_radius(rock, 10.0f);
        if (!(rock->y - this->position.y > range)) {
            hit = 0;
            if (xyz_distance(rock, &this->prev_node_positions[TBoss6Type2__player_hit_rock_indices[i]]) >= 1.0f) {
                hit = 1;
            }
            r = this->push_players_away(rock, 10.0f);
            if (hit != 0 && r != 0) {
                for (mask = 1, j = 0; j < 4; j++, mask <<= 1) {
                    if (mask & r) {
                        p = get_player_by_client_id(j);
                        if (TBoss6PlotFalz::is_active((TObjPlayer *)p) != 0) {
                            v = this->rock_damage;
                            if (this->berserk != 0) {
                                v = (s32)((f32)v * this->berserk_damage_scale);
                            }
                            s32 rr = TBoss6PlotFalz::rand_vary_count(v, 0.1f);
                            a.kind = 0;
                            a.power = rr;
                            p->receive_direct_attack(this, a, 0, -1, -1);
                        }
                    }
                }
            }
        }
    }
}

s32 TBoss6Type2::push_players_away(const Vec *target, f32 range) {
    Vec dir;
    Vec pos;
    Vec off;
    s32 mask;
    s32 i;
    s32 n;
    TObjPlayer *pl;
    f32 t;
    f32 dist;
    mask = 0;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        pl = TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_state_1f((TObjPlayer *)pl) == 0) {
            continue;
        }
        VecCopy(&dir, &pl->position);
        subtract_vector(&dir, target);
        dir.y = 0.0f;
        dist = vector_length(&dir);
        if (dist >= range) {
            continue;
        }
        if (dist <= 1e-05f) {
            dir.x = 1.0f;
        }
        normalize_vector(&dir);
        for (t = range; t > 5.0f; t -= 5.0f) {
            off.x = dir.x * t;
            off.y = 10.0f;
            off.z = dir.z * t;
            VecCopy(&pos, target);
            vec3_add_to(&pos, &off);
            if (project_actor_to_ground(this, &pos, 0) != 0) {
                TBoss6PlotFalz::move_player_to(pl, &pos);
                break;
            }
        }
        mask |= 1 << pl->get_entity_id();
    }
    return mask;
}

void TBoss6Type2::create_mags(f32) {
    TBoss6MagSpawnParams params;
    s16 x;
    u16 z;
    s32 i;
    params.owner = this;
    VecCopy(&params.origin, &position);
    params.origin.y += 150.0f;
    params.rotation_y = rotation_y;
    copy_set_entry(&params, plot_falz->get_set_entry());
    params.active = 1;
    VecCopy(&params.pos, &params.origin);
    params.flags = target_attribute_mask;
    x = params.x;
    z = params.z;
    params.variant = variant;
    for (i = 0; i < 2; i++) {
        params.index = i;
        params.x = x + lbl_8047133C[i];
        params.z = z + lbl_8047133C[i];
        mags[i] = TBoss6Type2::create_mag(&params);
    }
    if (mags[0] == 0 || mags[1] == 0) {
        return;
    }
    mags[0]->set_anim_frame(mags[1]);
    mags[1]->set_anim_frame(mags[0]);
}

void TBoss6Type2::release_mags() {
    if (mags[0] == 0 || mags[1] == 0) {
        return;
    }
    mags[0]->set_on_shoulder(0);
    mags[1]->set_on_shoulder(0);
}

void TBoss6Type2::call_mags_to_shoulders() {
    if (mags[0] == 0 || mags[1] == 0) {
        return;
    }
    mags[0]->set_on_shoulder(1);
    mags[1]->set_on_shoulder(1);
}

#pragma push
#pragma optimization_level 2
u16 TBoss6Type2::pick_target_client() {
    s32 count = TBoss6PlotFalz::sort_active_players();
    u16 id = 0xFFFF;
    s32 i;
    if (count < 1) {
        return id;
    }
    if ((s32)berserk == 0) {
        for (i = 0; i < count; i++) {
            id = TBoss6PlotFalz::get_sorted_player(i);
            if (TBoss6Type2::is_player_in_rock_area(id) == 0) {
                break;
            }
        }
        if (i == count) {
            id = 0xFFFF;
        }
    } else {
        for (i = count - 1; i >= 0; i--) {
            id = TBoss6PlotFalz::get_sorted_player(i);
            if (TBoss6Type2::is_player_in_rock_area(id) == 0) {
                break;
            }
        }
        if (i < 0) {
            id = 0xFFFF;
        }
    }
    return id;
}
#pragma pop

void TBoss6Type2::pick_action_clients(u16 *first, u16 *second) {
    s32 count = TBoss6PlotFalz::sort_active_players();
    *first = 0xFFFF;
    *second = 0xFFFF;
    if (count < 1) {
        return;
    }
    if ((s32)berserk == 0) {
        u16 id0 = TBoss6PlotFalz::get_sorted_player(0);
        u16 id1 = TBoss6PlotFalz::get_sorted_player(1);
        if (random_factor & 1) {
            *first = id0;
            *second = id1;
        } else {
            *first = id1;
            *second = id0;
        }
        if (TBoss6PlotFalz::get_phase() == 0) {
            s8 flags = *(s8 *)&random_factor;
            if (flags & 2) {
                if (flags & 4) {
                    *first = 0xFFFF;
                } else {
                    *second = 0xFFFF;
                }
            }
        }
    } else {
        *first = *second = TBoss6PlotFalz::get_sorted_player(count - 1);
    }
}

void TBoss6Type2::update_head_aim() {
    switch ((s32)action_state) {
    case 3:
    case 6: case 7: case 8: case 9: case 10: case 11:
    case 0x1B: case 0x1C: case 0x1D: case 0x1E: case 0x1F: case 0x20: case 0x21:
        this->update_target();
        break;
    default:
        clear_head_aim();
        break;
    }
}

void TBoss6Type2::update_target() {
    TObjPlayer *player = get_player_by_client_id(this->target_client);
    if (player != NULL) {
        this->aim_toward_point(&player->position);
        return;
    }
    this->aim_toward_point(NULL);
}

void TBoss6Type2::clear_head_aim() { aim_toward_point(NULL); }

void TBoss6Type2::update_camera() {
    switch ((s32)action_state) {
    case 0xE:
    case 0x1C:
        TBoss6Type2::request_default_follow_camera();
        break;
    default:
        init_range();
        break;
    }
}

void TBoss6Type2::request_player_camera_offsets(f32 a, f32 b) {
    Vec pp;
    Vec me;
    Vec off;
    Vec d;
    Vec cam;
    s32 n;
    s32 i;
    TObjPlayer *p;
    s32 flag;
    f32 step;
    f32 t;
    f32 dy;
    f32 k;
    f32 dist;
    f32 sum;
    f32 adj;
    f32 lim;

    n = TLobby::get_game_mode();
    step = 0.125f * b;
    for (i = 0; i < n; i++) {
        lim = fabs_float(b);
        p = TObjPlayer::get_player_data(i);
        if (p == NULL) {
            continue;
        }
        t = 0.0f;
        while (fabs_float(t) <= lim) {
            flag = 0;
            VecCopy(&off, &lbl_80471344);
            VecCopy(&pp, &p->position);
            pp.y += off.y;
            VecCopy(&me, &this->position);
            me.y += a + t;
            VecCopy(&d, &me);
            subtract_vector(&d, &pp);
            dy = d.y;
            d.y = 0.0f;
            dist = off.z + vector_length(&d);
            if (dist <= 15.0f) {
                dist = 15.0f;
            }
            cam.x = 0.0f;
            cam.z = 55.42f;
            cam.y = 25.43f - dy * cam.z / dist;
            if (cam.y < 10.0f) {
                cam.y = 10.0f;
                if (dy > 1e-05f) {
                    k = 9.799999f * dist;
                    cam.z = k / dy;
                    if (cam.z < 47.92f) {
                        sum = 47.92f + dist;
                        cam.z = 47.92f;
                        dy = 47.92f * dy - k;
                        if (fabs_float(sum) > 1e-05f) {
                            adj = dy / sum;
                            if (adj > 2.5f) {
                                adj = 2.5f;
                                flag = 1;
                            }
                            off.y += adj;
                        }
                    }
                }
            }
            request_follow_camera_offsets(&off, &cam, p->get_entity_id());
            if (flag == 0) {
                break;
            }
            t += step;
        }
    }
}

void TBoss6Type2::init_range() {
    request_player_camera_offsets(100.0f, -125.0f);
}

void TBoss6Type2::request_default_follow_camera() {
    request_follow_camera_offsets(&boss6_type2_follow_camera_position, &boss6_type2_follow_camera_target, 0xFFFFU);
}

void TBoss6Type2::drop_random_rocks(s32 force) {
    s32 avail_tbl[32];
    s32 cnt;
    s32 mult;
    s32 avail;
    s32 i;
    s32 *buf;
    s32 step;
    s32 j;
    s32 k;

    mult = 1;
    cnt = game_difficulty_selection;
    if (TBoss6PlotFalz::get_phase() == 1) {
        mult = 4;
    }
    cnt = (4 - cnt) + mult;
    if (force != 0) {
        cnt *= 2;
    }
    if (cnt < 1) {
        return;
    }
    avail = 0;
    for (i = 0; i < 32; i++) {
        avail_tbl[i] = 0;
        if (TBoss6Rock::is_rock_state_2(i) == 0) {
            avail_tbl[i] = 1;
            avail++;
        }
    }
    if (avail < 1) {
        return;
    }
    if (cnt > avail) {
        cnt = avail;
    }
    buf = (s32 *)mem_alloc(cnt * 4);
    step = (s32)(31.0f * (3.0517578e-05f * (f32)rand()));
    j = 0;
    for (k = 0; k < cnt; k++) {
        j += step;
        if (j >= 32) {
            j = 0;
        }
        while (avail_tbl[j] == 0) {
            j++;
            if (j >= 32) {
                j = 0;
            }
        }
        buf[k] = j;
        avail_tbl[j] = 0;
    }
    TBoss6Type2__sub_80356E50((saddr)buf, cnt, force);
    mem_free(buf);
    play_sound_effect(0x4006AB1D, &boss6_arena_center, 0, 1);
}

void TBoss6Type2::spawn_rocks_around_players() {
    Vec p;
    Vec q;
    s32 n;
    s32 cnt;
    s32 i;
    u8 *pl;
    n = 0;
    cnt = TLobby::get_game_mode();
    for (i = 0; i < cnt; i++) {
        pl = (u8 *)TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active((TObjPlayer *)pl) != 0) {
            f32 r = 40.0f * (3.0517578e-05f * (f32)rand()) + 10.0f;
            s32 ang = (s32)(65535.0f * (3.0517578e-05f * (f32)rand()));
            VecCopy((Vec *)&p, (const Vec *)(pl + 0x38));
            p.x += r * sin_table_lookup(ang);
            p.y = 0.0f;
            p.z += r * cos_table_lookup(ang);
            TBoss6RockChase::spawn(this, &p);
            n++;
        }
    }
    while (n < 10) {
        f32 dx = 283.68796f * (2.0f * (3.0517578e-05f * (f32)rand()) - 1.0f);
        f32 dz = 283.68796f * (2.0f * (3.0517578e-05f * (f32)rand()) - 1.0f);
        VecCopy((Vec *)&q, &boss6_arena_center);
        q.x += dx;
        q.z += dz;
        TBoss6RockChase::spawn(this, &q);
        n++;
    }
    play_sound_effect(0x4006AB1D, &boss6_arena_center, 0, 1);
}

void TBoss6Type2::create_dpbs() {
    create_dpb(this, &position, 150.0f);
    if (mags[0] != NULL && mags[0]->is_phase_active() != 0) {
        create_dpb(this, &mags[0]->position, 100.0f);
    }
    if (mags[1] != NULL && mags[1]->is_phase_active() != 0) {
        create_dpb(this, &mags[1]->position, 100.0f);
    }
}

s32 TBoss6Type2::snap_to_ground() {
    Vec p;
    f32 t;
    VecCopy(&p, &this->position);
    p.y += 10.0f;
    if (project_actor_to_ground(this, &p, 0) != 0) {
        VecCopy(&this->position, &p);
        this->position.y = 0.0f;
        return 0;
    }
    VecCopy(&p, &this->position);
    p.x -= -10000.0f;
    p.y = 0.0f;
    t = 398.0f;
    {
        Vec d = p;
        normalize_vector(&d);
        for (; t > 0.0f; t += -2.0f) {
            p.x = t * d.x + -10000.0f;
            p.y = 10.0f + this->position.y;
            p.z = t * d.z;
            if (project_actor_to_ground(this, &p, 0) != 0) {
                break;
            }
        }
    }
    VecCopy(&this->position, &p);
    this->position.y = 0.0f;
    return 1;
}

s32 TBoss6Type2::turn_toward_target_position() {
    s32 turn_step;
    f32 dist;
    s32 old_rotation;
    Vec to_target;
    VecCopy(&to_target, &move_target.position);
    subtract_vector(&to_target, &position);
    to_target.y = 0.0f;
    dist = vector_length(&to_target);
    if (dist < 10.0f) {
        return 0;
    }
    if (dist > 25.0f) {
        turn_step = 0x1B4;
        if (berserk != 0) {
            turn_step = 0x369;
        }
        old_rotation = rotation_y;
        rotation_y = approach_angle_limited(rotation_y, (s32)(10430.38043493439 * atan2_float(to_target.x, to_target.z)), turn_step);
        if (turn_step == angle_difference_abs(old_rotation, rotation_y)) {
            if (turn_sound_played == 0) {
                play_sound_effect(0x4006A602, &position, 0, 0);
                turn_sound_played = 1;
            }
        } else {
            turn_sound_played = 0;
        }
    }
    return 1;
}

void TBoss6Type2::trigger_screen_pos() {
    if (low_hp == 0 && hp_ratio < 0.33333334f) {
        low_hp = 1;
        set_screen_pos();
    }
}

s32 TBoss6Type2::should_back_jump() {
    if (iai_count >= 3) {
        return 1;
    }
    return TBoss6PlotFalz::arena_center_distance(&position) >= 350.0f;
}

s32 TBoss6Type2::should_use_dpb() {
    s32 i;
    if (count_matching_values(0xE, 3) != 0) {
        return 0;
    }
    i = 0;
    do {
        if (count_matching_values(boss6_type2_hit_check_value_table[i], 2) != 0) {
            return 0;
        }
        i++;
    } while (i < 4);
    return dpb_damage_threshold <= get_hit_count() ? 1 : 0;
}

s32 TBoss6Type2::is_phase_complete() {
    if ((s32) this->berserk == 0) {
        return 0;
    }
    if (calc_field4f0_delta() >= release_damage) {
        return 1;
    }
    if ((TBoss6PlotFalz::get_phase() == 0) && ((s32) this->berserk_wait_count >= 8)) {
        return 1;
    }
    return 0;
}

s32 TBoss6Type2::is_ready_to_attack() {
    s32 temp;
    if ((s32) this->berserk != 0) {
        return 0;
    }
    if (is_normal_difficulty() != 0) {
        return 0;
    }
    temp = calc_field4f0_delta();
    return berserk_damage <= temp ? 1 : 0;
}

void TBoss6Type2::update_leg_ground_effects() {
    f32 band = 20.0f;
    s32 i = 0;
    do {
        const Boss6Type2LegEffect *e = &boss6_type2_leg_effect_table[i];
        f32 ground = e->ground_height;
        f32 height = node_positions[e->node].y;
        if (height < ground || height > band + ground) {
            destroy_part(e->particle_slot);
        } else {
            spawn_particle_slot(e->particle_slot);
        }
        i++;
    } while (i < 6);
}

void TBoss6Type2::reset_lower_contact() { lower_contact_index = -1; }

void TBoss6Type2::update_lower_contact_delta() {
    Vec lower;
    Vec node8;
    Vec node3;
    s32 index;
    lower_contact_delta.z = 0.0f;
    lower_contact_delta.y = 0.0f;
    lower_contact_delta.x = 0.0f;
    VecCopy(&node8, &node_positions[8]);
    subtract_vector(&node8, &position);
    VecCopy(&node3, &node_positions[3]);
    subtract_vector(&node3, &position);
    index = 0;
    VecCopy(&lower, &node8);
    if (node8.y > node3.y) {
        index = 1;
        VecCopy(&lower, &node3);
    }
    if (lower_contact_index == index) {
        VecCopy(&lower_contact_delta, &previous_lower_contact);
        subtract_vector(&lower_contact_delta, &lower);
        lower_contact_delta.y = 0.0f;
    }
    lower_contact_index = index;
    VecCopy(&previous_lower_contact, &lower);
}

void TBoss6Type2::update_zako() {
    vec3_add_to(&position, &lower_contact_delta);
    snap_to_ground();
}

void TBoss6Type2::move_to_arena_center(s32 timer, s32 duration) {
    f32 t = 1.0f - (f32)timer / (f32)duration;
    f32 u;
    f32 k;
    if (t <= 0.1f) {
        u = 0.0f;
    } else if (t >= 0.7f) {
        u = 1.0f;
    } else {
        u = (t - 0.1f) / (0.7f - 0.1f);
    }
    k = TBoss6PlotFalz::cosine_ease(u);
    VecCopy(&position, &boss6_arena_center);
    subtract_vector(&position, &move_origin);
    position.x *= k;
    position.y *= k;
    position.z *= k;
    vec3_add_to(&position, &move_origin);
}

void TBoss6Type2::cache_fish_params() {
    reset_fish_fields();
    grab_texlists[0] = get_bml_texlist(archive, 0xB);
    grab_texlists[1] = get_bml_texlist(archive, 0xA);
    grab_models[0] = get_bml_model(archive, 0xB);
    grab_models[1] = get_bml_model(archive, 0xA);
}

void TBoss6Type2::reset_counters() {
    if (possessed_client != 0xFFFF) {
        restore_target_player_state();
    }
    reset_fish_fields();
    grab_texlists[0] = 0;
    grab_texlists[1] = 0;
    grab_models[0] = 0;
    grab_models[1] = 0;
}

void TBoss6Type2::update_possess_target() {
    Vec v;
    u8 *pl;
    s32 done;
    u16 id;
    id = possessed_client;
    if (id != 0xFFFF) {
        done = 0;
        pl = (u8 *)get_player_by_client_id(id);
        if (pl == NULL) {
            done = 1;
        } else if (TBoss6PlotFalz::is_active((TObjPlayer *)pl) == 0) {
            VecCopy((Vec *)&v, (const Vec *)(pl + 0x38));
            v.y += 10.0f;
            spawn_flow_soul(this, &v, 0x1E);
            TBoss6EffHyoui::create(possessed_client, 1, 0x1E);
            if (this->is_target_valid() == 0) {
                play_sound_effect(0x40069E13, &position, 0, 1);
            }
            spawn_particle_effect((const Vec *)(pl + 0x38), 0x36);
            done = 1;
        }
        if (done != 0) {
            restore_target_player_state();
            this->possess_target = 0xFFFF;
            this->target_mode = this->pick_random_other_index();
            this->target_state = this->choose_next_index();
        }
        switch (this->action_state) {
        case 0x1A:
            restore_target_player_state();
            this->possess_target = 0xFFFF;
            break;
        }
    }
}

u16 TBoss6Type2::is_falz_ready() { return TBoss6PlotFalz::pick_random_active_player(); }

s32 TBoss6Type2::check_target() {
    if (this->possess_target == 0xFFFF) {
        return 0;
    }
    if (possessed_client != 0xFFFF) {
        restore_target_player_state();
    }
    if (grab_player(this->possess_target) == 0) {
        this->possess_target = 0xFFFFU;
        return 0;
    }
    return 1;
}

s32 TBoss6Type2::grab_player(u16 client_id) {
    TObjPlayer *player;
    if ((client_id == 0xFFFF) || (possessed_client != 0xFFFF)) {
        return 0;
    }
    player = get_player_by_client_id(client_id);
    if (player == NULL) {
        return 0;
    }
    if (player->actorFlags & 0x800) {
        return 0;
    }
    possessed_client = client_id;
    grab_appearance = player->name;
    copy_texlist(&saved_look.body_textures, &player->body_textures);
    copy_texlist(&saved_look.head_textures, (NJS_TEXLIST *)player->head_textures);
    copy_texlist(&saved_look.attachment_textures, (NJS_TEXLIST *)player->attachment_textures);
    saved_look.model = player->model;
    saved_look.head_model = player->head_model;
    saved_look.hair_model = player->hair_model;
    saved_look.attachment_model = player->attachment_model;
    copy_texlist(&player->body_textures, grab_texlists[0]);
    copy_texlist((NJS_TEXLIST *)player->attachment_textures, grab_texlists[1]);
    player->model = grab_models[0];
    player->head_model = NULL;
    player->hair_model = NULL;
    player->attachment_model = (uaddr)grab_models[1];
    return 1;
}

void copy_texlist(NJS_TEXLIST *dst, NJS_TEXLIST *src) { *dst = *src; }

void TBoss6Type2::restore_target_player_state() {
    TObjPlayer *player;
    u32 id = possessed_client;
    if (id != 0xFFFF) {
        player = get_player_by_client_id(id);
        if (player == NULL) {
            reset_fish_fields();
            return;
        }
        copy_texlist(&player->body_textures, &saved_look.body_textures);
        copy_texlist((NJS_TEXLIST *)player->attachment_textures, &saved_look.attachment_textures);
        player->model = saved_look.model;
        player->head_model = saved_look.head_model;
        player->hair_model = saved_look.hair_model;
        player->attachment_model = saved_look.attachment_model;
        reset_fish_fields();
    }
}

void TBoss6Type2::reset_fish_fields() {
    possessed_client = 0xFFFF;
    grab_appearance = NULL;
    saved_look.model = NULL;
    saved_look.head_model = NULL;
    saved_look.hair_model = NULL;
    saved_look.attachment_model = 0;
}

#pragma push
#pragma opt_common_subs off
void TBoss6Type2::damage_possessed_player() {
    TObjPlayer *p;
    if (possessed_client != 0xFFFF) {
        p = get_player_by_client_id(possessed_client);
        if (TBoss6PlotFalz::is_active(p) != 0) {
            s32 r = TBoss6PlotFalz::rand_vary_count(possessed_damage, 0.1f);
            TBoss6PlotFalz::damage_player_hp(possessed_client, r);
            p->actorFlags |= 0x200;
            spawn_particle_effect_with_flags(&p->position, 0x212, 0x40);
            {
                Vec v = p->position;
                v.y += 10.0f;
                spawn_particle_effect_with_flags(&v, 0x223, 0x40);
            }
            if (this->is_target_valid() == 0) {
                play_sound_effect(0x4000AD13, 0, 0, 0);
            }
        }
    }
}
#pragma pop

void TBoss6Type2::init_collected_entries() {
    s32 i;
    for (i = 0; i < 2; i++) {
        this->aim_joints[i].node_angle = &find_model_node(this->body_models[i].model, 0x28)->ang[1];
        this->aim_joints[i].rest_angle = *this->aim_joints[i].node_angle;
        this->aim_joints[i].aim_angle = 0;
    }
}

void TBoss6Type2::aim_toward_point(const Vec *point) {
    Vec v;
    s32 ang;
    s32 i;
    if (point == NULL) {
        ang = 0;
    } else {
        VecCopy(&v, point);
        subtract_vector(&v, &position);
        ang = (s16)((s32)(10430.38043493439 * atan2_float(v.x, v.z)) - rotation_y);
    }
    if (ang < -0x2800 || ang > 0x2800) {
        ang = 0;
    }
    for (i = 0; i < 2; i++) {
        aim_joints[i].aim_angle = approach_angle_limited(aim_joints[i].aim_angle, ang, 0x2AA);
    }
}

void TBoss6Type2::sum_offsets() {
    s32 i;
    for (i = 0; i < 2; i++) {
        *this->aim_joints[i].node_angle = this->aim_joints[i].rest_angle + this->aim_joints[i].aim_angle;
    }
}

void TBoss6Type2::restore_effect_values() {
    s32 i;
    for (i = 0; i < 2; i++) {
        *this->aim_joints[i].node_angle = this->aim_joints[i].rest_angle;
    }
}

void TBoss6Type2::set_fields_554() { foot_grounded[0] = 1; foot_grounded[1] = 1; }

#pragma push
#pragma opt_common_subs off
void TBoss6Type2::update_footstep_effects() {
    Vec *feet[2];
    Vec *foot;
    s32 i;
    static f32 foot_lift_height = 7.5f;
    static f32 footstep_height_threshold = 5.0f;
    feet[0] = &node_positions[10];
    i = 0;
    feet[1] = &node_positions[5];
    do {
        if (foot_grounded[i] != 0) {
            if (feet[i]->y > foot_lift_height) {
                foot_grounded[i] = 0;
            }
        } else {
            foot = feet[i];
            if (foot->y < footstep_height_threshold) {
                foot_grounded[i] = 1;
                play_sound_effect(0x4006A300, foot, 0, 0);
                spawn_particle_effect_with_flags(foot, 0x220, 0x40);
                if ((s32)berserk == 0) {
                    spawn_particle_effect(foot, 0x222);
                } else {
                    spawn_particle_effect_with_flags(foot, 0x229, 0x2000);
                }
                TBoss6PlotFalz::apply_radial_effect_to_players(foot, (s16)0xC0, (s16)0xF, 200.0f);
            }
        }
        i++;
    } while (i < 2);
}
#pragma pop

void TBoss6Type2::clear_particle_emitters() {
    s32 i;
    for (i = 0; i < 14; i++) particle_emitters[i] = 0;
}

void TBoss6Type2::init_parts() {
    s32 i = 0;
    do {
        destroy_part(i);
        i++;
    } while (i < 14);
}

void TBoss6Type2::update_part_positions() {
    s32 i = 0;
    do {
        Vec v = position;
        const Tbl_802B9C00 *e = &TBoss6Type2__particle_attachment_table[i];
        if (particle_emitters[i] != 0) {
            s32 idx = e->b;
            if (idx >= 0) {
                VecCopy(&v, &node_positions[idx]);
            }
            particle_emitters[i]->set_position(&v);
        }
        i++;
    } while (i < 14);
}

void TBoss6Type2::spawn_particle_slot(s32 slot) {
    if (particle_emitters[slot] == 0) {
        Vec v = position;
        particle_emitters[slot] = create_particle_emitter(&v, TBoss6Type2__particle_attachment_table[slot].a);
        if (particle_emitters[slot] != 0) {
            particle_emitters[slot]->set_flags(0x40);
        }
    }
}

void TBoss6Type2::destroy_part(s32 slot) {
    if (particle_emitters[slot] != 0) {
        TParticleCtrl::release(particle_emitters[slot]);
        particle_emitters[slot] = 0;
    }
}

void TBoss6Type2::spawn_hit_effects() {
    s32 found = 0;
    CollisionBody *e;
    s32 i;
    CollisionBody *t = this->bodies;
    if (t != NULL) {
        e = t;
        for (i = 0; i < 3; i++, e++) {
            if (e->flags & 0x04000000) {
                spawn_particle_effect(&this->node_positions[boss6_type2_hit_effect_node_table[i]], 0x223);
                found = 1;
            }
        }
    }
    if (found == 0) {
        spawn_particle_effect(&body_center, 0x223);
    }
}

s32 TBoss6Type2::is_player_in_rock_area(u16 client_id) {
    Vec a;
    Vec b;
    f32 r;
    TObjPlayer *p;
    s32 i;
    f32 k;
    p = get_player_by_client_id(client_id);
    if (p == NULL) {
        return 0;
    }
    i = 0;
    k = 0.0f;
    do {
        if (TBoss6Rock::get_push_target(i, &a, &r) != 0) {
            VecCopy(&b, &p->position);
            subtract_vector(&b, &a);
            b.y = k;
            if (vector_length(&b) <= r) {
                return 1;
            }
        }
        i++;
    } while (i < 0x20);
    return 0;
}

void Boss6GridBytes::decode_grid_position(Boss6Type2MoveTarget *target) {
    target->heading = (s16)(heading << 8);
    TBoss6Type2::grid_to_world_pos(grid_x, grid_z, &target->position);
}

void Boss6Type2FlowAction::decode_target(Boss6Type2MoveTarget *target) { position.decode_grid_position(target); }

void TBoss6Type2::grid_to_world_pos(s8 grid_x, s8 grid_z, Vec *pos) {
    pos->x = (f32)((7.874016f * (f32)grid_x) + -10500.0f);
    pos->y = 0.0f;
    pos->z = (f32)((7.874016f * (f32)grid_z) + -500.0f);
}

void TBoss6Type2::world_to_grid_pos(Vec *pos, s8 *grid_x, s8 *grid_z) {
    f32 fa = 0.5f + ((pos->x - -10500.0f) / 7.874016f);
    f32 fb = 0.5f + ((pos->z - -500.0f) / 7.874016f);
    *grid_x = (s8)fa;
    *grid_z = (s8)fb;
}

s32 TBoss6Type2::get_phase() { return action_history[1]; }

void TBoss6Type2::render() { render_body_effects(); draw(); }

void TBoss6Type2::render_body_effects() {
    s32 settled;

    sum_offsets();
    TObjPlayer::toggle_particle_effect();
    push_matrix();
    post_translate_matrix((const f32 *)&position);
    rotate_matrix_y(NULL, rotation_y);
    settled = 0;
    if ((0.0f == state_progress) || (1.0f == state_progress)) {
        settled = 1;
    }
    if (settled != 0) {
        TBoss6PlotFalz__sub_802AC008(hit_flash, hp_ratio);
    }
    draw_body_models();
    if (settled != 0) {
        TBoss6PlotFalz::update_camera_target();
    }
    pop_matrix();
    TParticleCtrl::end_effect_render();
    restore_effect_values();
}

void TBoss6Type2::draw() {
    if (this->possessed_client != 65535) {
        push_matrix();
        post_translate_matrix((const f32 *)&this->node_positions[11]);
        rotate_matrix_y(NULL, this->rotation_y);
        boss6type2_draw_models((saddr)&saved_look.body_textures, (saddr)&saved_look.head_textures, (saddr)&saved_look.attachment_textures,
                               (uaddr)saved_look.model, (uaddr)saved_look.head_model, (uaddr)saved_look.hair_model,
                               saved_look.attachment_model, (saddr)grab_appearance, 1.0f);
        pop_matrix();
    }
}
