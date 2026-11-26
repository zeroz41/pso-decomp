#include "pso/system/BmlAccessors.h"
#pragma defer_codegen on

#include "pso/object/trap/TOTrapAncient02R.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/network/protocol/protocol_types.h"

#include "types.h"
#include <string.h>

#include "pso/render/GinjaMotionDraw.h"

#include "pso/system/task/TObject.h"

#include "pso/object/trap/TOTrapChainSawEdge.h"
#include "pso/render/ModelDrawContext.h"

#include "pso/player/TObjPlayer.h"

#include "pso/object/trap/TOTrapChainSawDamage.h"

#include "pso/object/trap/TOTrapChainSawKey.h"

#include "pso/object/trap/TOTrapChainSaw.h"

#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/ObjectSetData.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/math/MatrixReflect.h"
#include "pso/object/base/ActorCollision.h"

#include "pso/map/FloorArea.h"

#include "pso/player/TObjPlayer_801AF2F0.h"

#include "pso/render/DebugFont.h"

#include "pso/system/MatrixStack.h"


#include "pso/object/base/TObjMapObject.h"

#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/network/TLobby.h"

#include "pso/object/key/TOKey.h"

#include "pso/ui/hud/TRaderMapCore.h"

#include "pso/npc/TObjNpcEnemy.h"

#include "pso/render/TextureState.h"
#include "pso/object/base/TObjBase.h"
#include "pso/network/client_id.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/system/MatrixStack.h"
#include "pso/ui/TLevelSelect.h"

#pragma readonly_strings on


// The model's light nodes (3-6) the key saw draws with the effect blend.
NJS_OBJECT *chain_saw_sekigai2m_light_nodes[5];
NJS_OBJECT *chain_saw_sekigai4m_light_nodes[5];

const char *chainsaw_ginja_model_filenames[6] = {
    "fe_obj_nokogiri_2m.gj", "fe_obj_nokogiri_4m.gj", "fe_obj_sekigai_light_moto.gj",
    "fe_obj_sekigai2m_moto.gj", "fe_obj_sekigai4m_moto.gj", NULL,
};

const char *bm_obj_jungle_nokogiri_motion_names[6] = {
    "fe_obj_nokogiri_2m.njm", "fe_obj_nokogiri_4m.njm", "fe_obj_sekigai_light_moto.njm",
    "fe_obj_sekigai2m_moto.njm", "fe_obj_sekigai4m_moto.njm", NULL,
};

BmlResourceDescriptor bm_obj_jungle_nokogiri_resource_descriptor = {
    "bm_obj_jungle_nokogiri.bml", chainsaw_ginja_model_filenames, bm_obj_jungle_nokogiri_motion_names, 5, 5,
};

const char *trap_chain_saw_name = "TOTrapChainSaw";

// Two collision bodies per variant, picked by the variant word at 0xF8.
CollisionBody chain_saw_damage_collision_body_parts[2][2] = {
    { { { -5.0f, 0.0f, 0.0f }, 3.0f, 0.0f, 0, 0x10403, { 0.0f, 0.0f, 0.0f }, 0.0f },
      { { -12.0f, 0.0f, 0.0f }, 2.0f, 8.0f, 1, 0x10503, { 0.0f, 0.0f, 0.0f }, 0.0f }, },
    { { { -5.0f, 0.0f, 0.0f }, 3.0f, 0.0f, 0, 0x10403, { 0.0f, 0.0f, 0.0f }, 0.0f },
      { { -20.0f, 0.0f, 0.0f }, 2.0f, 16.0f, 1, 0x10503, { 0.0f, 0.0f, 0.0f }, 0.0f }, },
};

CollisionBody chain_saw_collision_body_part_table[2][2] = {
    { { { 0.0f, 0.0f, 0.0f }, 3.0f, 0.0f, 0, 0x10403, { 0.0f, 0.0f, 0.0f }, 0.0f },
      { { -10.0f, 0.0f, 0.0f }, 2.0f, 8.0f, 1, 0x10503, { 0.0f, 0.0f, 0.0f }, 0.0f }, },
    { { { 0.0f, 0.0f, 0.0f }, 3.0f, 0.0f, 0, 0x10403, { 0.0f, 0.0f, 0.0f }, 0.0f },
      { { -20.0f, 0.0f, 0.0f }, 2.0f, 18.0f, 1, 0x10503, { 0.0f, 0.0f, 0.0f }, 0.0f }, },
};

BmlResource *jungle_nokogiri_resource;

#include "pso/render/NinjaUtil.h"

#include "pso/object/seabed/TObjSeabedSuisoBrakable.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/SoundEffect.h"

void TOTrapChainSaw::select_model() {  }

void TOTrapChainSaw::draw_model() {  }

void TOTrapChainSawEdge::queue_runs(s32 count) { pending_starts += count; }

void TOTrapChainSawEdge::set_target_offset(s32 offset) { extent = offset; }

void TOTrapChainSaw::reach_home() {  }

void TOTrapChainSaw::reach_far_end() {  }

void TOTrapChainSaw::update_run() {  }

void TOTrapChainSaw::start_run() {  }

void TOTrapChainSaw::hit_player(TObjPlayer *) {  }

void TOTrapChainSawEdge::check_player_contact() {  }

void TOTrapChainSaw::load_shared_resource() {
    BmlResource *p;
    s32 i;
    NJS_OBJECT *root;
    p = new BmlResource(5, &bm_obj_jungle_nokogiri_resource_descriptor, 0, 0, NULL);
    jungle_nokogiri_resource = p;
    for (i = 0; i < 5; i++) {
        chain_saw_sekigai2m_light_nodes[i] = NULL;
    }
    for (i = 0; i < 5; i++) {
        chain_saw_sekigai4m_light_nodes[i] = NULL;
    }
    if (p != NULL) {
        root = get_bml_model(p, 3);
        if (root != NULL) {
            chain_saw_sekigai2m_light_nodes[1] = find_object_node(root, 3);
            chain_saw_sekigai2m_light_nodes[2] = find_object_node(root, 4);
            chain_saw_sekigai2m_light_nodes[3] = find_object_node(root, 5);
            chain_saw_sekigai2m_light_nodes[4] = find_object_node(root, 6);
        }
        root = get_bml_model(jungle_nokogiri_resource, 4);
        if (root != NULL) {
            chain_saw_sekigai4m_light_nodes[1] = find_object_node(root, 3);
            chain_saw_sekigai4m_light_nodes[2] = find_object_node(root, 4);
            chain_saw_sekigai4m_light_nodes[3] = find_object_node(root, 5);
            chain_saw_sekigai4m_light_nodes[4] = find_object_node(root, 6);
        }
    }
}

void TOTrapChainSaw::unload_static_data() {
    s32 i;
    if (jungle_nokogiri_resource != NULL) {
        delete jungle_nokogiri_resource;
        jungle_nokogiri_resource = NULL;
    }
    for (i = 0; i < 5; i++) {
        chain_saw_sekigai2m_light_nodes[i] = NULL;
    }
    for (i = 0; i < 5; i++) {
        chain_saw_sekigai4m_light_nodes[i] = NULL;
    }
}

NJS_OBJECT *TOTrapChainSaw::get_model(s32 index) {
    if (jungle_nokogiri_resource != NULL) {
        return get_bml_model(jungle_nokogiri_resource, index);
    }
    return NULL;
}

AnimationMotion *TOTrapChainSaw::get_motion(s32 index) {
    if (jungle_nokogiri_resource != NULL) {
        return get_bml_motion(jungle_nokogiri_resource, index);
    }
    return NULL;
}

NJS_TEXLIST *TOTrapChainSaw::get_texlist(s32 index) {
    if (jungle_nokogiri_resource != NULL) {
        return get_bml_texlist(jungle_nokogiri_resource, index);
    }
    return NULL;
}

TOTrapChainSaw::TOTrapChainSaw(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = trap_chain_saw_name;
    apply_object_set_data(set_data);
    clear_hit_cooldowns();
    yaw_offset = 0;
    max_offset = 0;
    step = 0;
    saw_model = NULL;
    behavior = 0;
    switch_id = 0;
    pause_timer = 0;
}

TOTrapChainSaw::~TOTrapChainSaw() {}

void TOTrapChainSaw::decode_params() {
    s32 clamped_switch_id;
    s32 raw_switch_id;
    u32 clamped_behavior;
    u32 raw_behavior;

    switch_id = (u16)set_params[0];
    raw_switch_id = switch_id;
    if (raw_switch_id < 0) {
        clamped_switch_id = 0;
    } else {
        clamped_switch_id = 0xFF;
        if (raw_switch_id <= 0xFF) {
            clamped_switch_id = raw_switch_id;
        }
    }
    switch_id = clamped_switch_id;
    if (is_current_floor_switch_set((u16)switch_id) == 1) {
        switch_on = 1;
    } else {
        switch_on = 0;
    }
    max_offset = (u32)set_params[1] >> 16;
    step = (u16)set_params[1];
    behavior = (u32)set_params[2] >> 16;
    raw_behavior = behavior;
    if ((s32)raw_behavior < 0) {
        clamped_behavior = 0;
    } else {
        clamped_behavior = 1;
        if ((s32)raw_behavior <= 1) {
            clamped_behavior = raw_behavior;
        }
    }
    behavior = clamped_behavior;
}

void TOTrapChainSaw::run_task() {
    update_state();
    check_player_contact();
    if (is_current_floor_switch_set((u16)switch_id) == 1) {
        switch_on = 1;
        return;
    }
    switch_on = 0;
}
#pragma push
#pragma opt_propagation off
void TOTrapChainSaw::update_state() {
    static void (TOTrapChainSaw::*tbl[2])() = { &TOTrapChainSaw::update_extension, &TOTrapChainSaw::update_sweep };
    (this->*tbl[behavior])();
    if (motion != NULL) {
        animation_end_frame = animation_end_frame + animation_step;
        if (animation_end_frame > (f32)(motion->frameCount - 1)) {
            animation_end_frame = 0.0f;
        }
    }
}
#pragma pop
void TOTrapChainSaw::update_sweep() {
    if (switch_on == 0) {
        if (yaw_offset == 0) {
            start_run();
        }
        update_run();
        yaw_offset = yaw_offset + step;
        return;
    }
    yaw_offset = yaw_offset - step;
    if (yaw_offset < 0) {
        yaw_offset = 0;
    }
}

void TOTrapChainSaw::update_extension() {
    if (switch_on == 0) {
        if (pause_timer > 0) {
            pause_timer = pause_timer - 1;
            return;
        }
        if (yaw_offset == 0) {
            start_run();
        }
        update_run();
        yaw_offset = yaw_offset + step;
        if (yaw_offset < 0) {
            yaw_offset = 0;
            step *= -1.0f;
            pause_timer = (s32)(30.0f * (f32)(u16)set_params[2]);
            reach_home();
        }
        if (yaw_offset > max_offset) {
            yaw_offset = max_offset;
            step *= -1.0f;
            reach_far_end();
        }
    } else {
        step = (s32)fabs_float((f32)step);
        yaw_offset = yaw_offset - step;
        if (yaw_offset < 0) {
            yaw_offset = 0;
        }
    }
}

void TOTrapChainSaw::check_player_contact() {
    s32 i;
    TObjPlayer *p;
    s32 t;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        for (i = 0; i < 4; i++) {
            p = get_player_by_client_id(i);
            if (p != 0 && consume_counter(p) == 0) {
                if (p->get_floor() == get_current_floor()) {
                    t = rotation_y;
                    rotation_y = t + yaw_offset;
                    if (check_actor_body_contact(p, 100.0f) != 0) {
                        hit_player(p);
                        set_hit_cooldown_for_player(p);
                    }
                    rotation_y = t;
                }
            }
        }
    } else {
        TObjPlayer *q;
        s32 t2;
        q = get_player_by_client_id(local_client_id);
        if (q != 0 && consume_counter(q) == 0) {
            if (q->get_floor() == get_current_floor()) {
                t2 = rotation_y;
                rotation_y = t2 + yaw_offset;
                if (check_actor_body_contact(q, 100.0f) != 0) {
                    hit_player(q);
                    set_hit_cooldown_for_player(q);
                }
                rotation_y = t2;
            }
        }
    }
}

s32 TOTrapChainSaw::consume_counter(TObjPlayer *player) {
    s32 i = player->get_entity_id();
    if (i >= 0 && i < 4) {
        if (hit_cooldown[i] > 0) {
            hit_cooldown[i] = hit_cooldown[i] - 1;
            return 1;
        }
    }
    return 0;
}

void TOTrapChainSaw::set_hit_cooldown_for_player(TObjPlayer *player) {
    s32 i = player->get_entity_id();
    if (i >= 0 && i < 4) {
        hit_cooldown[i] = 150;
    }
}

void TOTrapChainSaw::clear_hit_cooldowns() { memset(hit_cooldown, 0, sizeof(hit_cooldown)); }

void TOTrapChainSaw::render() {
    if (update_object_view_visibility(400.0f, 50.0f) == 1) {
        draw_model();
        update_demo();
    }
}

void TOTrapChainSaw::draw_debug_labels() {  }

void TOTrapChainSaw::update_demo() {
    s32 base_yaw;

    if (TObjPlayer::check_demo_mode() == 1) {
        base_yaw = rotation_y;
        rotation_y = base_yaw + yaw_offset;
        sub_80154D78();
        rotation_y = base_yaw;
    }
}

f32 TOTrapChainSaw::scale_by_level(f32 level) {
    f32 scales[4] = { 1.0f, 2.0f, 3.0f, 6.0f };
    return level * scales[game_difficulty_selection];
}
#pragma push
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
s32 TOTrapChainSaw::get_area_sound(s32 index) {
    s32 sounds[3][3] = {
        { 0x4D01F, 0x4C122, 0x4BC21 },
        { 0x4004D01F, 0x4004C122, 0x4004BC21 },
        { 0x4004D01F, 0x4004C122, 0x4004BC21 },
    };
    s32 *row = sounds[0];
    switch (get_current_floor_area()) {
    case AREA_SEASIDE_NIGHT:
        row = sounds[1];
        break;
    case AREA_TOWER:
        row = sounds[2];
        break;
    }
    return row[index];
}

const char *TOTrapChainSawDamage_class_name = "TOTrapChainSawDamage";

TOTrapChainSawDamage::TOTrapChainSawDamage(TObject *parent, void *set_data) : TOTrapChainSaw(parent, set_data) {
    m_name = TOTrapChainSawDamage_class_name;
    decode_params();
    select_model();
    init_collision_body_parts(this, chain_saw_damage_collision_body_parts[variant], 2);
    refresh_collision_body_centers();
    register_object_by_id();
    position.y += 5.0f;
    {
        ObjectSetData edge_set = *(ObjectSetData *)set_data;
        edge_set.position.y += 10.0f;
        edges[0] = new TOTrapChainSawEdge(this, &edge_set);
        edge_set.position.y += 5.0f;
        edges[1] = new TOTrapChainSawEdge(this, &edge_set);
    }
}
TOTrapChainSawDamage::~TOTrapChainSawDamage() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TOTrapChainSawDamage::create(void *set_data) {
    return new TOTrapChainSawDamage(tl_05, set_data);
}

void TOTrapChainSawDamage::decode_params() {
    TOTrapChainSaw::decode_params();
    damage = scale.y;
}

void TOTrapChainSawDamage::select_model() {
    s32 models[2] = { 0, 1 };
    s32 motions[2] = { 0, 1 };
    s32 v;
    variant = (s32)scale.z;
    v = variant;
    variant = v < 0 ? 0 : (v > 1 ? 1 : v);
    saw_model = get_model(models[variant]);
    motion = get_motion(motions[variant]);
    texlist = get_texlist(0);
    animation_end_frame = 0.0f;
    animation_step = 1.0f;
}
void TOTrapChainSawDamage::hit_player(TObjPlayer *player) {
    DirectAttackPayload attack;
    attack.kind = 0;
    attack.power = scale_by_level(damage);
    player->receive_direct_attack(this, attack, NULL, -1, -1);
    player->set_actor_flags(0x400);
}
void TOTrapChainSawDamage::update_state() {
    TOTrapChainSaw::update_state();
    if (switch_on == 1) {
        clear_player_status_flag(1, 0x100);
        return;
    }
    set_indexed_flags(1, 0x100);
}
#pragma pop
void TOTrapChainSawDamage::draw_model() {
    set_texture_list(texlist);
    push_matrix();
    post_translate_matrix(&position.x);
    push_matrix();
    rotate_matrix_y(NULL, rotation_y);
    rotate_matrix_y(NULL, yaw_offset);
    draw_ginja_model_with_motion(saw_model, motion, animation_end_frame);
    pop_matrix();
    pop_matrix();
}

void TOTrapChainSawDamage::draw_debug_labels() {
    TOTrapChainSaw::draw_debug_labels();
    set_debug_text_color(0xFF00FF);
    debug_printf_at(0x13001D, "<- DAMAGE POWER");
    debug_printf_at(0x13001E, "<- SELECT A MODEL");
    set_debug_text_color(0xF0F0F0FF);
}

void TOTrapChainSawDamage::start_run() { tick = 0; }
#pragma push
#pragma fp_contract on
void TOTrapChainSawDamage::update_run() {
    TOTrapChainSawEdge *edge;
    tick = tick + 1;
    if (tick == 5 && (edge = edges[0]) != NULL) {
        edge->queue_runs(1);
    }
    if (tick == 10 && (edge = edges[1]) != NULL) {
        edge->queue_runs(1);
    }
    play_persistent_sound(get_area_sound(0), this, &position, 0, 0);
}
#pragma pop
void TOTrapChainSawDamage::reach_far_end() {
    if (edges[0] != NULL) {
        edges[0]->set_target_offset(yaw_offset);
    }
    if (edges[1] != NULL) {
        edges[1]->set_target_offset(yaw_offset);
    }
}

const char *trap_chain_saw_key_name = "TOTrapChainSawKey";

TOTrapChainSawKey::TOTrapChainSawKey(TObject *parent, void *set_data) : TOTrapChainSaw(parent, set_data) {
    m_name = trap_chain_saw_key_name;
    decode_params();
    select_model();
    init_collision_body_parts(this, chain_saw_collision_body_part_table[variant], 2);
    refresh_collision_body_centers();
    register_object_by_id();
}
TOTrapChainSawKey::~TOTrapChainSawKey() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TOTrapChainSawKey::create(void *set_data) {
    return new TOTrapChainSawKey(tl_05, set_data);
}

void TOTrapChainSawKey::decode_params() { TOTrapChainSaw::decode_params(); }

void TOTrapChainSawKey::select_model() {
    s32 models[2] = { 3, 4 };
    s32 motions[2] = { 3, 4 };
    s32 v;
    variant = (s32)scale.z;
    v = variant;
    variant = (v < 0) ? 0 : ((v > 1) ? 1 : v);
    saw_model = get_model(models[variant]);
    motion = get_motion(motions[variant]);
    texlist = get_texlist(3);
    animation_end_frame = 0.0f;
    animation_step = 1.0f;
    light_model = get_model(2);
    light_motion = get_motion(2);
    light_frame = 0.0f;
    light_frame_step = 1.0f;
}

void TOTrapChainSawKey::hit_player(TObjPlayer *) {
    G_SwitchStateChanged_6x05 cmd;
    cmd.init();
    cmd.header.client_id = 0xFFFF;
    cmd.unused1 = 0;
    cmd.switch_id = switch_id;
    cmd.floor = get_current_floor();
    cmd.flags = 1;
    cmd.send();
}

void TOTrapChainSawKey::update_state() {
    TOTrapChainSaw::update_state();
    light_frame = light_frame + light_frame_step;
    if (light_frame > (f32)(light_motion->frameCount - 1)) {
        light_frame = 0.0f;
    }
    play_persistent_sound(get_area_sound(2), this, &position, 0, 0);
    if (switch_on == 1) {
        play_persistent_sound(get_area_sound(1), this, &position, 0, 0);
    }
}

void TOTrapChainSawKey::draw_debug_labels() {
    TOTrapChainSaw::draw_debug_labels();
    set_debug_text_color(0xFF00FF);
    debug_printf_at(0x13001E, "<- SELECT A MODEL");
    set_debug_text_color(0xF0F0F0FF);
}

void TOTrapChainSawKey::draw_model() {
    set_texture_list(texlist);
    push_matrix();
    post_translate_matrix(&position.x);
    push_matrix();
    rotate_matrix_y(NULL, rotation_y);
    rotate_matrix_y(NULL, yaw_offset);
    set_model_node_callback(draw_node_callback);
    draw_ginja_motion(saw_model, (NJS_MOTION *)motion, animation_end_frame);
    set_model_node_callback(NULL);
    if (switch_on == 1) {
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion(light_model, light_motion, light_frame);
        TParticleCtrl::end_effect_render();
    }
    pop_matrix();
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

void TOTrapChainSawKey::check_player_contact() {
    if (switch_on != 1) {
        TOTrapChainSaw::check_player_contact();
    }
}

void TOTrapChainSawKey::update_run() {  }

void TOTrapChainSawKey::draw_node_callback(NJS_OBJECT *object) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (object == chain_saw_sekigai2m_light_nodes[i]) {
            TParticleCtrl::begin_effect_render();
            return;
        }
    }
    for (i = 0; i < 5; i++) {
        if (object == chain_saw_sekigai4m_light_nodes[i]) {
            TParticleCtrl::begin_effect_render();
            return;
        }
    }
    TParticleCtrl::end_effect_render();
}


const char *TOTrapChainSawEdge_class_name = "TOTrapChainSawEdge";

TOTrapChainSawEdge::TOTrapChainSawEdge(TObject *parent, void *set_data) : TOTrapChainSaw(parent, set_data) {
    m_name = TOTrapChainSawEdge_class_name;
    decode_params();
    select_model();
    pending_starts = 0;
    phase = 0;
}

TOTrapChainSawEdge::~TOTrapChainSawEdge() {}

void TOTrapChainSawEdge::update_extension() {
    s32 pending;
    s32 limit;

    switch (phase) {
    case 0:
        pending = pending_starts;
        if (pending > 0) {
            pending_starts = pending - 1;
            extent = max_offset;
            phase = 1;
        }
        break;
    case 1:
        yaw_offset = yaw_offset + step;
        if (yaw_offset < 0) {
            yaw_offset = 0;
            step *= -1.0f;
            phase = 0;
        }
        if (yaw_offset > (limit = max_offset)) {
            yaw_offset = limit;
            step *= -1.0f;
        }
        break;
    }
}

void TOTrapChainSawEdge::update_sweep() {
    s32 pending;

    switch (phase) {
    case 0:
        pending = pending_starts;
        if (pending > 0) {
            pending_starts = pending - 1;
            extent = max_offset;
            phase = 1;
        }
        return;
    case 1:
        yaw_offset = yaw_offset + step;
        return;
    }
}

void TOTrapChainSawEdge::draw_model() {
    set_texture_list(texlist);
    push_matrix();
    post_translate_matrix(&position.x);
    push_matrix();
    rotate_matrix_y(NULL, rotation_y);
    rotate_matrix_y(NULL, yaw_offset);
    draw_ginja_model_with_motion(saw_model, motion, animation_end_frame);
    pop_matrix();
    pop_matrix();
}

void TOTrapChainSawEdge::select_model() {
    s32 models[2] = { 0, 1 };
    s32 motions[2] = { 0, 1 };
    s32 v;
    variant = (s32)scale.z;
    v = variant;
    variant = v < 0 ? 0 : (v > 1 ? 1 : v);
    saw_model = get_model(models[variant]);
    motion = get_motion(motions[variant]);
    texlist = get_texlist(0);
    animation_end_frame = 0.0f;
    animation_step = 1.0f;
}
