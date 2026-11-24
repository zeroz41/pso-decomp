#define TOBJECT_OUT_OF_LINE_HELPERS

#include "pso/object/base/CollisionActorLookup.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/camera/TCameraCtrl.h"

#include "pso/object/base/TObjMotion.h"


#include "pso/unk/text_803D96A8.h"

#include "pso/unk/text_803E2D70.h"

#include "pso/system/vector.h"

#include "pso/enemy/TObjEnemy.h"

#include "pso/enemy/recon/TObjEneRecobox.h"

#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/render/reflection.h"

#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/enemy/dd/TObjEneDD.h"

#include "pso/enemy/berura/TObjEneRe7Berura.h"

#include "pso/render/RenderFadeState.h"

#include "pso/object/ambient/TObjFish.h"

#include "pso/player/TObjPlayer.h"

#include "pso/unk/text_803D8F74.h"

#include "pso/player/TObjPlayer_80011014.h"

#include "pso/system/MatrixOps.h"

#include "pso/unk/text_803D853C.h"

#include "pso/system/task/TObject.h"

#include "pso/map/CsnQuery.h"

#include "pso/object/TObjChip.h"

#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"

#include "pso/system/task/TMainTask.h"


#include "pso/system/task/TObject_80019A50.h"


#include "pso/render/TUnk_80494938.h"

#include "pso/enemy/dd/TObjEneDD_ST.h"

#include "pso/object/base/TObjChara.h"

#include "pso/map/FloorArea.h"

#include "pso/boss/goldragon/TBoss8Dragon.h"

#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"

#include "pso/enemy/panarms/TObjEnePanarms.h"

#include "pso/unk/TLobby.h"

#include "pso/system/SoundEffect.h"

#include "pso/math/AngleLookup.h"


#include "pso/ui/window/TWindowSubComCard.h"

#include "pso/render/model_render_state.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/player/TObjPlayer_801542CC.h"

// TObjBoss2Tunnel.cpp's debug chunk model.
extern NJS_OBJECT *debug_chunk_object;

// TObjEneDD.cpp's view-detail distances.

player_stats *recobox_boss_register_id;
AttackParams *recobox_attack_params;
ActorParamBlock *TObjEneRecobox__shared_object_handle;

void *TObjEneRecobox__attack_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};

CollisionBody recobox_collision_body = {
    {0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f,
};

const char *recobox_model_names[7] = {
    "me7_all.nj", "me7_box_all.nj", "bomb_body.nj", "b_parts_b_parts01.gj",
    "b_parts_b_parts02.gj", "b_parts_b_parts03.gj", NULL,
};

const char *recobox_motion_name_table[11] = {
    "close_me7_box_all.njm", "close_only_me7_box_all.njm", "open_me7_box_all.njm", "open_only_me7_box_all.njm",
    "attack_me7_all.njm", "b_attack_me7_all.njm", "damage_me7_all.njm", "dethpose_me7_all.njm",
    "start_me7_all.njm", "wait_me7_all.njm", NULL,
};

BmlResourceDescriptor recobox_bml_descriptor = {
    "bm_ene_recobox.bml", recobox_model_names, recobox_motion_name_table, 6, 10,
};

const char *recobox_low_model_names[7] = {
    "lo_me7_all.nj", "lo_me7_box_all.nj", "bomb_body.nj", "b_parts_b_parts01.gj",
    "b_parts_b_parts02.gj", "b_parts_b_parts03.gj", NULL,
};

const char *TObjEneRecobox__resource_bundle[11] = {
    "close_me7_box_all.njm", "close_only_me7_box_all.njm", "open_me7_box_all.njm", "open_only_me7_box_all.njm",
    "attack_me7_all.njm", "b_attack_me7_all.njm", "damage_me7_all.njm", "dethpose_me7_all.njm",
    "start_me7_all.njm", "wait_me7_all.njm", NULL,
};

BmlResourceDescriptor recobox_low_bml_descriptor = {
    "bm_ene_recobox_low.bml", recobox_low_model_names, TObjEneRecobox__resource_bundle, 6, 10,
};

const char *TObjEneRecobox_name_ref = "TObjEneRecobox";

TObjMotionAction TObjEneRecobox__animation_entries[4] = {
    {1, 0, 1, 0.1f, 0},
    {3, 0, 2, 0.6f, 0},
    {1, 0, 3, 0.1f, 0},
    {3, 0, 0, 0.6f, 0},
};


Vec lbl_80543000;

s32 recobox_behavior_params;

BmlResource *TObjEneRecobox__static_instance;

const NpcAnimationBinding recobox_resource_binding_desc = { NULL, TObjEneRecobox__animation_entries, 0, 0, 4 };

#pragma dont_inline off
#pragma inline_depth(4)
void *TObjEneRecon::get_field_38_ptr() {
    return &position;
}

void TObjEneRecobox::load_resources() {
    lbl_80543000.x = 0.0f;
    lbl_80543000.y = 0.0f;
    lbl_80543000.z = 0.0f;
    {
        BmlResource *res;
        if (is_split_screen() != 0) {
            res = load_enemy_bml_resource(&recobox_low_bml_descriptor);
        } else {
            res = load_enemy_bml_resource(&recobox_bml_descriptor);
        }
        TObjEneRecobox__static_instance = res;
    }
    recobox_boss_register_id = TLobby::register_boss(0x41);
    recobox_attack_params = TLobby::dispatch_shared_handler_b(0x41);
    TObjEneRecobox__shared_object_handle = TLobby::register_object(0x41);
    recobox_behavior_params = (saddr)TLobby::dispatch_shared_handler_a(0x41);
    TObjEneRecon::load_resources();
    {
        NpcAnimationBinding binding = recobox_resource_binding_desc;
        binding.motions = TObjEneRecobox__static_instance->motions;
        TObjNpcEnemy::register_animated_chunk(0xD, TObjEneRecobox__static_instance->models[1].model, TObjEneRecobox__static_instance->models[1].texlist, &binding, recobox_collision_body.radius, 0.0f);
    }
}

void *TObjEneRecobox::create(void *set_data) {
    return new TObjEneRecobox(tl_04, set_data);
}

void TObjEneRecobox::release_static_instance() {
    TObjEneRecon::release_static_instance();
    if (TObjEneRecobox__static_instance != NULL) {
        delete TObjEneRecobox__static_instance;
        TObjEneRecobox__static_instance = NULL;
    }
}

BmlResource *TObjEneRecobox::get_bml_resource() { return TObjEneRecobox__static_instance; }

u32 TObjEneRecobox::remap_area_sound_id(u32 id) {
    u32 ret;
    if (((s32)(id & 0xBFFF00FF) >> 16 << 16) != 0x30000) {
        return id;
    }
    ret = get_current_floor_area();
    switch (ret) {
    case 0x22:
        ret = id - 0x40010000 + 0x4E19;
        break;
    case 0x23:
        ret = id - 0x40010000 + 0x4E28;
        break;
    default:
        return id;
    }
    ret |= id & 0x8FFFFF00;
    return ret;
}

TObjEneRecobox::TObjEneRecobox(TObject *parent, void *set_data) : TObjEneDD_ST(parent) {
    s32 i;
    s32 n;
    m_name = TObjEneRecobox_name_ref;
    invoke_initialization_hook(set_data);
    init_position_vectors();
    model = TObjEneRecobox__static_instance->models[1].model;
    texlist = TObjEneRecobox__static_instance->models[1].texlist;
    init_model(&recobox_collision_body, 1);
    body_center.y = 20.0f + position.y;
    update_body_colliders();
    set_action_table(TObjEneRecobox__animation_entries);
    set_motion_list(TObjEneRecobox__static_instance->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    reset_hp(recobox_boss_register_id, recobox_attack_params, TObjEneRecobox__shared_object_handle);
    set_state_flag_4();
    movementParameters = TObjEneRecobox__attack_params;
    initialize_enemy_state(0x43);
    wall_reach = 10.0f;
    apply_set_parameters();
    n = ((s16 *)set_data)[1];
    if (n <= 1) {
        recon_total = 0;
    } else if (recon_total >= n) {
        recon_total = n - 1;
    }
    if (recon_max > recon_total) {
        recon_max = recon_total;
    }
    for (i = 0; i < 4; i++) {
        pad_3FC[i] = 0;
    }
    status_flags = 0;
    status_flags |= 1;
    fade.start_fade_in();
    live_recons = 0;
    spawned_recons = 0;
    for (i = 0; i < 30; i++) {
        recon_id_slots[i] = 0xFFFF;
    }
    for (i = 0; i < 6; i++) {
        live_recon_ids[i] = 0xFFFF;
    }
    for (i = 0; i < 4; i++) {
        fades[i].activate_and_dispatch();
    }
    spawn_timer = 0;
    spawn_interval = 0;
    floor_flags = 0;
    VecCopy(&floor_point, &position);
    pad_4E0[0] = 0;
    pad_4E0[1] = 0;
    pad_4E0[2] = 0;
    pad_4E0[3] = 0;
    m_4f0 = 0.0f;
    mode = 0;
    dispatch_action(mode, 4);
}

TObjEneRecobox::~TObjEneRecobox() {
    free_collision_body_parts(this);
}

void TObjEneRecobox::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        this->update_if_800BB858();
        return;
    }
    if (this->update_status_effects() != 4) {
        this->update_action_state();
    } else if ((s16) this->mode == 1) {
        transition_enemy_state(0);
    }
    this->update_body_colliders();
    this->restore_position();
    this->submit_default_cursor_candidate();
    this->render_minimap_dot();
    this->update_floor_probe();
}

void TObjEneRecobox::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        state_idle(reason);
        return;
    case 1:
        handle_state(reason);
        return;
    case 2:
        state_closed(reason);
        return;
    case 3:
        update_state(reason);
        return;
    case 4:
        handle_action_state(reason);
        return;
    case 5:
        state_close(reason);
        return;
    case 6:
        handle_death_state(reason);
    default:
        return;
    }
}

void TObjEneRecobox::refresh_target() {  }

void TObjEneRecobox::run_death_reaction() { if (this->mode != 6) { transition_enemy_state(6); } }

void TObjEneRecobox::run_hit_reaction() { clear_attack_receipts(); }

void TObjEneRecobox::run_miss_reaction() {  }

void TObjEneRecobox::restore_position() { VecCopy(&center, &body_center); }


void TObjEneRecobox::update_body_colliders() {
    Vec probe;
    CsnHit *hit;
    VecCopy(&probe, &body_center);
    if (mount_type == 1) {
        probe.y -= 5.0f;
    } else {
        probe.y += 5.0f;
    }
    hit = csnVectorUnder(&probe, ground_candidates.groups, 0x15);
    if (hit == NULL || body_center.y >= 40.0f + hit->contact->point.y) {
        set_colliders_contact_high();
    }
    set_part_local_pos(&body_center, 0);
}

s32 TObjEneRecobox::can_spawn_recons() {
    u8 r;
    s32 t;
    if (has_child_in_anim_5() == 1) {
        return 0;
    }
    t = (s32)TWindowSubComCard::trunc_float(recon_max / 2.0f);
    r = 0;
    if (live_recons <= t && spawned_recons < recon_total) {
        r = 1;
    }
    return r;
}

s32 TObjEneRecobox::is_out_of_range() {
    int full;

    if (has_child_in_anim_5() == 1) {
        return 1;
    }
    full = 0;
    if (live_recons >= recon_max || spawned_recons >= recon_total) {
        full = 1;
    }
    return (u8) full;
}

void TObjEneRecobox::update_child_spawn() {
    Vec dir = {0.0f, 0.0f, 0.0f};
    Vec pos;
    s32 id;
    s32 set_index;
    s32 n;
    spawn_timer++;
    if (spawn_timer < spawn_interval) {
        return;
    }
    spawn_timer = 0;
    if (live_recons >= recon_max || spawned_recons >= recon_total) {
        return;
    }
    switch (mount_type) {
    case 0:
        dir.y = 5.0f;
        break;
    case 1:
        dir.y = -5.0f;
        break;
    case 2:
        dir.x = 2.0f * sin_table_lookup(rotation_y);
        dir.z = 2.0f * cos_table_lookup(rotation_y);
        break;
    }
    id = alloc_child_id();
    set_index = this->set_index + (id - entity_id);
    VecCopy(&pos, (const Vec *)((TObjEneRecon *)this)->get_field_38_ptr());
    if (id == 0xFFFF) {
        spawned_recons = recon_total;
        return;
    }
    if (TObjEneRecon::create(this, id, set_index, &pos, &dir) != NULL) {
        n = live_recons++;
        live_recon_ids[n] = id;
        spawned_recons++;
        play_sound_effect(remap_area_sound_id(0x4003A80F), &position, 0, 0);
    }
}

#pragma push
#pragma opt_common_subs off
void TObjEneRecobox::apply_set_parameters() {
    s32 n;
    mount_type = variant;
    if (mount_type <= 0) {
        mount_type = 0;
    } else if (variant >= 2) {
        mount_type = 2;
    }
    recon_offset_max = parameters[0];
    recon_rotate_rad = parameters[1];
    if (recon_rotate_rad <= -30.0f) {
        recon_rotate_rad = -30.0f;
    }
    recon_max = (s32)parameters[3];
    n = recon_max;
    if (n < 0) {
        recon_max = 0;
    } else if (n > 6) {
        recon_max = 6;
    }
    if (recon_max == 0) {
        recon_total = 0;
        return;
    }
    recon_total = 30;
}
#pragma pop

void TObjEneRecobox::handle_state(s32 reason) {
    switch (reason) {
    case 4:
        status_flags &= ~1;
        requested_action = 0;
        set_intangible();
        set_field_378(0);
        fade.start_fade_in();
        return;
    case 3:
        if (fade.advance_toward_max() != 0) {
            transition_enemy_state(2);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        break;
    }
}

void TObjEneRecobox::state_idle(s32 reason) {
    switch (reason) {
    case 4:
        status_flags |= 1;
        requested_action = 0;
        set_intangible();
        set_field_378(0);
        return;
    case 3:
        transition_enemy_state(1);
    case 5:
    case 0:
        return;
    }
}

void TObjEneRecobox::state_closed(s32 reason) {
    switch (reason) {
    case 4:
        status_flags &= ~1;
        requested_action = 0;
        clear_intangible();
        set_field_378(2);
        return;
    case 3:
        if (acquire_target(500.0f) != 0 && can_spawn_recons() != 0) {
            transition_enemy_state(3);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        break;
    }
}

void TObjEneRecobox::update_state(s32 reason) {
    switch (reason) {
    case 4:
        status_flags &= ~1;
        requested_action = 1;
        clear_intangible();
        set_field_378(3);
        return;
    case 3:
        if (get_flag_b4() != 0) {
            spawn_timer = 0;
            spawn_interval = 30;
            transition_enemy_state(4);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        break;
    }
}

void TObjEneRecobox::handle_action_state(s32 reason) {
    switch (reason) {
    case 4:
        status_flags &= ~1;
        requested_action = 2;
        clear_intangible();
        set_field_378(2);
        return;
    case 3:
        if (is_out_of_range() != 0) {
            transition_enemy_state(5);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        update_child_spawn();
        break;
    }
}

void TObjEneRecobox::state_close(s32 reason) {
    switch (reason) {
    case 4:
        status_flags &= ~1;
        requested_action = 3;
        clear_intangible();
        set_field_378(5);
        break;
    case 3:
        if (get_flag_b4() != 0) {
            transition_enemy_state(2);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        break;
    }
}

void TObjEneRecobox::handle_death_state(s32 reason) {
    switch (reason) {
    case 4:
        refresh_lobby_state();
        status_flags |= 1;
        spawn_debris_chips();
        set_intangible();
        return;
    case 3:
        if (live_recons == 0) {
            send_entity_set_flags();
            queue_destruction();
        }
    case 5:
    case 0:
        return;
    }
}

#pragma push
#pragma pool_data off
// Called from handle_death_state: breaks the box into three
// debris chips (models 3-5 of the Recobox archive, textures of model 3).
void TObjEneRecobox::spawn_debris_chips() {
    const TObjChipParams chip0 = {
        0.5f, 0.07f, 0.26f, {this->position.x, this->position.y, this->position.z},
        {5.0f, 5.0f, 5.0f}, {0x400, 0x100, 0x400}, 5, 50, this->position.y, 0.6f,
        TObjEneRecobox__static_instance->models[3].model, TObjEneRecobox__static_instance->models[3].texlist, 20,
    };
    const TObjChipParams chip1 = {
        0.5f, 0.07f, 0.26f, {this->position.x, this->position.y, this->position.z},
        {4.0f, 4.5f, 4.0f}, {0x200, 0x100, 0x200}, 6, 50, this->position.y, 0.5f,
        TObjEneRecobox__static_instance->models[4].model, TObjEneRecobox__static_instance->models[3].texlist, 20,
    };
    const TObjChipParams chip2 = {
        0.5f, 0.07f, 0.26f, {this->position.x, this->position.y, this->position.z},
        {4.0f, 4.5f, 4.0f}, {0x200, 0x100, 0x200}, 6, 50, this->position.y, 0.5f,
        TObjEneRecobox__static_instance->models[5].model, TObjEneRecobox__static_instance->models[3].texlist, 20,
    };
    spawn_particle_effect_with_flags(&this->position, 0x45, 0x40);
    spawn_particle_effect_with_flags(&this->position, 0x46, 0x40);
    new TObjChip(tl_05, (TObjChipParams *)&chip0);
    new TObjChip(tl_05, (TObjChipParams *)&chip1);
    new TObjChip(tl_05, (TObjChipParams *)&chip2);
}
#pragma pop

s32 TObjEneRecobox::is_below_child_limit(u16 id) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < live_recons; i++) {
        TObjEneRecon *child = (TObjEneRecon *)find_entity_by_id(live_recon_ids[i]);
        if (child != NULL && id == child->get_attack_target_id()) {
            n++;
        }
    }
    if (TObjEneDD::check_v2_mode() != 0) {
        return n < 4;
    }
    return n < 2;
}

s32 TObjEneRecobox::has_child_in_anim_5() {
    s32 i;
    if (live_recons <= 0) {
        return 0;
    }
    for (i = 0; i < 6; i++) {
        TObjEneRecon *child = (TObjEneRecon *)find_entity_by_id(live_recon_ids[i]);
        if (child != NULL && child->is_anim_5() == 1) {
            return 1;
        }
    }
    return 0;
}

void TObjEneRecobox::remove_tracked_target(TObjEneRecon *child) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (find_entity_by_id(live_recon_ids[i]) == child) {
            remove_tracked_id(live_recon_ids[i]);
            live_recons--;
            live_recon_ids[i] = live_recon_ids[live_recons];
            live_recon_ids[live_recons] = 0xFFFF;
            spawned_recons--;
            if (spawned_recons < 0) {
                spawned_recons = 0;
            }
            return;
        }
    }
}

void TObjEneRecobox::remove_child_entity(u8 *child) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (find_entity_by_id(live_recon_ids[i]) == reinterpret_cast<TObjCollidable *>(child)) {
            live_recons--;
            live_recon_ids[i] = live_recon_ids[live_recons];
            live_recon_ids[live_recons] = 0xFFFF;
            return;
        }
    }
}

s32 TObjEneRecobox::is_anim_6() {
    return (u8)((u8) (this->mode == 6));
}

void TObjEneRecobox::update_floor_probe() {
    Vec probe;
    CsnHit *hit;
    if ((actor_frame_tick % 5) == 0) {
        VecCopy(&probe, &position);
        probe.y += 15.0f;
        hit = csnVectorUnder(&probe, ground_candidates.groups, 0x4000);
        if (hit != NULL) {
            floor_flags = hit->contact->flags;
            VecCopy(&floor_point, &hit->contact->point);
        } else {
            VecCopy(&floor_point, &position);
        }
    }
    if (floor_flags & 0x4000) {
        request_reflection_render();
    }
}

#pragma push
#pragma opt_propagation off
s32 TObjEneRecobox::alloc_child_id() {
    s32 slot;
    s32 i;
    s32 v;
    for (i = 0; i < recon_total; i++) {
        if (recon_id_slots[i] == 0xFFFF) {
            v = (0, entity_id + i);
            slot = i;
            recon_id_slots[slot] = v + 1;
            return (u16)recon_id_slots[slot];
        }
    }
    return (u16)0xFFFF;
}
#pragma pop

void TObjEneRecobox::remove_tracked_id(s32 id) {
    s32 i;
    for (i = 0; i < 30; i++) {
        if (recon_id_slots[i] == id) {
            recon_id_slots[i] = 0xFFFF;
            return;
        }
    }
}

void TObjEneRecobox::update_if_800BB858() { if (get_target_info() != 0) { apply_set_parameters(); } }


void TObjEneRecobox::render() {
    s32 camera_fading;
    RenderFadeState *camera_fade;
    s32 camera_mode;
    s32 view_detail;
    s32 fading_in;
    if (TObjPlayer::check_demo_mode() != 0) {
        draw_with_debug_info();
        return;
    }
    camera_mode = 0;
    if (is_split_screen() != 0) {
        camera_mode = TCameraCtrl::get_camera_mode();
    }
    if (!(status_flags & 1)) {
        if (TObjEneDD::is_main_phase_15() != 0) {
            view_detail = this->classify_actor_view_detail(25.0f + view_detail_near_depth, 50.0f + view_detail_far_depth, 120.0f);
        } else if (this->update_object_view_visibility(500.0f, 120.0f) != 0) {
            view_detail = 1;
        } else {
            view_detail = 0;
        }
        if (view_detail != 0) {
            fading_in = 0;
            if (render_trap_model_if_visible() == 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                if ((s16)mode == 1) {
                    if (this->fade.has_visible_opacity() != 0) {
                        if (defer_render() != 0) {
                            model_render_flags = saved_model_render_flags;
                            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                            return;
                        }
                        fading_in = 1;
                        this->fade.set_flags_and_apply_damage_color();
                        goto block_18;
                    }
                    model_render_flags = saved_model_render_flags;
                    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                    return;
                }
block_18:
                camera_fade = &this->fades[camera_mode];
                camera_fade->update();
                camera_fading = camera_fade->updateFromCamera(&body_center.x);
                if ((fading_in == 0) && (camera_fading != 0)) {
                    if (defer_render() != 0) {
                        model_render_flags = saved_model_render_flags;
                        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                        return;
                    }
                    camera_fade->set_flags_and_apply_damage_color();
                    goto block_23;
                }
block_23:
                update_secondary_light();
                TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
                push_matrix();
                post_translate_matrix(&position.x);
                rotate_matrix_y(0, rotation_y);
                switch (mount_type) {
                case 1:
                    rotate_matrix_x(0, 0x8000);
                    break;
                case 2:
                    rotate_matrix_x(0, 0x4000);
                    break;
                }
                TObjEneDD::clear_global_flag_400();
                TObjPlayer::toggle_particle_effect();
                if (view_detail == 1) {
                    draw();
                } else {
                    draw_motion_model();
                }
                TParticleCtrl::end_effect_render();
                pop_matrix();
                update_primary_light();
                if (fading_in != 0) {
                    this->fade.clear_flag_and_notify();
                } else if (camera_fading != 0) {
                    camera_fade->clear_flag_and_notify();
                }
                model_render_flags = saved_model_render_flags;
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                goto block_37;
            }
        } else {
            goto block_37;
        }
    } else {
block_37:
        VecCopy(&body_center, &position);
    }
}

// pool_data off: each debug string is reached with its own lis/addi.
#pragma push
#pragma pool_data off
void TObjEneRecobox::draw_with_debug_info() {
    if (get_target_info() != 0) {
        switch (this->mount_type) {
        case 0:
            debug_printf_at(pack_debug_text_position(0, 9), "TYPE : NORMAL");
            break;
        case 1:
            debug_printf_at(pack_debug_text_position(0, 9), "TYPE : BOTTOM");
            break;
        case 2:
            debug_printf_at(pack_debug_text_position(0, 9), "TYPE : SIDE");
            break;
        }
        debug_printf_at(pack_debug_text_position(0, 0xA), "RECON TOTAL + 1");
        debug_printf_at(pack_debug_text_position(0, 2), "RECON OFFSET MAX(+45.f)");
        debug_printf_at(pack_debug_text_position(0, 3), "RECON ROTATE RAD(+50.f)");
        debug_printf_at(pack_debug_text_position(0, 5), "RECON MAX(Min:0 Max:6)");
    }
    if (this->update_object_view_visibility(500.0f, 120.0f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, this->rotation_y);
        switch (this->mount_type) {
        case 1:
            rotate_matrix_x(0, 0x8000);
            break;
        case 2:
            rotate_matrix_x(0, 0x4000);
            break;
        }
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        draw_chunk_object(this->model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, this->rotation_y);
    draw_chunk_object(debug_chunk_object);
    pop_matrix();
}
#pragma pop

s32 TObjEneRecobox::render_trap_model_if_visible() {
    if ((s32)main_task.get_task_flags() & 0x20) {
        if (push_reflection_matrix(&floor_point) != 0) {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, rotation_y);
            draw();
            pop_matrix();
            restore_render_scissor(1);
        }
        return 1;
    }
    return 0;
}
