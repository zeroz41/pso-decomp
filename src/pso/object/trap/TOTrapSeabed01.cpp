#include "pso/system/memory.h"
#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaTexture.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/trap/TOTrap.h"
#include "pso/object/trap/TOTrapSeabed01.h"
#include "pso/object/TObjChip.h"
#include "pso/object/seabed/TObjSuisoChip.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/render/TextureState.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/render/CameraCapture.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/player/PlayerCommands.h"
#include "pso/boss/volopt/TObjVoloptCage.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/unk/TDeferredRenderQueue.h"
#include "pso/network/TLobby.h"
#include "pso/audio/SoundRequests.h"
#include "pso/render/DebugFont.h"
#include "pso/math/MatrixReflect.h"
#include "pso/map/FloorArea.h"
#include "pso/math/MatrixVector.h"
#include "pso/network/client_id.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/NinjaUtil.h"
#include "pso/render/render_util.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/SoundEffect.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"
#include <dolphin/base/PPCArch.h>
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"


const char *seabed_trap_model_filenames[] = {
    "obj_o_seaturigane2.gj",
    "obj_o_seaturigane2_hahen01.gj",
    "obj_o_seaturigane2_hahen02.gj",
    NULL,
};
const char *seabed_trap_motion_filenames[] = {"obj_o_seaturigane2.njm", NULL};
BmlResourceDescriptor seabed_trap_resource_descriptor = {
    "bm_obj_seabed_turigane.bml", seabed_trap_model_filenames, seabed_trap_motion_filenames, 3, 1,
};
CollisionBody seabed_trap_collision_body = {
    {0.0f, 20.0f, 0.0f}, 14.0f, 0.0f, 0, 0x08011F04, {0.0f, 0.0f, 0.0f}, 0.0f,
};
SeabedTrapFragmentSpawn seabed_trap_fragment_spawns[6] = {
    {2, {9.0f, 21.0f, 9.0f}, -24576},
    {2, {9.0f, 21.0f, -9.0f}, -8192},
    {2, {-9.0f, 21.0f, 9.0f}, 24576},
    {2, {-9.0f, 21.0f, -9.0f}, 8192},
    {1, {-4.0f, 0.0f, -4.0f}, 0},
    {1, {4.0f, 0.0f, 4.0f}, 32768},
};
static const TObjChipParams trap_seabed01_transform_params = {
    0.35f, 0.07f, 0.54f, {0.0f, 0.0f, 0.0f}, {2.5f, 6.5f, 2.5f},
    {0x300, 0x250, 0x300}, 1, 60, 0.0f, 1.0f, 0, 0, 17,
};
static const s32 trap_seabed01_param_index_table[6] = {0, 1, 2, 3, 4, 5};
const char *TOTrapSeabed01_class_name = "TOTrapSeabed01";

BmlResource *trap_seabed01_bml_resource;
NJS_TEXLIST *trap_seabed01_texture_file;
NJS_OBJECT *trap_seabed01_ginja_model;
s32 effect_uv_scroll_last_tick;
s32 seabed01_ginja_mesh_index;

TOTrapSeabed01::TOTrapSeabed01(TObject *parent, void *set_data) : TOTrap(parent) {
    m_name = TOTrapSeabed01_class_name;
    apply_object_set_data(set_data);
    model = get_bml_model(trap_seabed01_bml_resource, 0);
    current_motion = (NJS_MOTION *)get_bml_motion(trap_seabed01_bml_resource, 0);
    play_speed = 1.0f;
    frame = 0.0f;
    clamp_params_and_init();
    init_collision_body_parts(this, &seabed_trap_collision_body, 1);
    refresh_collision_body_centers();
    this->register_object_by_id();
    actorFlags |= 0x60040000;
    pad_344 = 0;
    sound_handle = -1;
}

TOTrapSeabed01::~TOTrapSeabed01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TOTrapSeabed01::apply_saved_state(s16 *state, s32 live) {
    if (*state == 4) {
        if (live == 1) {
            this->play_sounds();
        }
        if (sound_handle >= 0) {
            stop_sound_request(sound_handle);
            sound_handle = -1;
        }
        release_trapped_player();
        set_flag8();
        queue_destruction();
    }
}

void TOTrapSeabed01::load_resources() {
    BmlResource *resource = new BmlResource(5, &seabed_trap_resource_descriptor, 0, 0, NULL);
    trap_seabed01_bml_resource = resource;
    trap_seabed01_texture_file = LoadPvmFileTls("obj_seabed_turigane.gvm");
    trap_seabed01_ginja_model = find_object_node(get_bml_model(trap_seabed01_bml_resource, 0), 5);
    effect_uv_scroll_last_tick = 0;
    seabed01_ginja_mesh_index = -1;
    if (trap_seabed01_texture_file != NULL) {
        seabed01_ginja_mesh_index = find_texture_entry_by_name(trap_seabed01_texture_file, "apk_o064_seaturigane03");
    }
}

void TOTrapSeabed01::free_static_resources() {
    if (trap_seabed01_texture_file != NULL) {
        release_texture_list(trap_seabed01_texture_file);
        safe_free(trap_seabed01_texture_file);
        trap_seabed01_texture_file = NULL;
    }
    if (trap_seabed01_bml_resource != NULL) {
        delete trap_seabed01_bml_resource;
        trap_seabed01_bml_resource = NULL;
    }
}

void *TOTrapSeabed01::create(void *set_data) {
    return new TOTrapSeabed01(tl_05, set_data);
}

inline f32 clamp_f32(f32 lo, f32 hi, f32 v) {
    f32 r;
    if (lo > v) {
        r = lo;
    } else if (hi < v) {
        r = hi;
    } else {
        r = v;
    }
    return r;
}

inline s32 CLAMPI(s32 v, s32 lo, s32 hi) {
    s32 r;
    if (v < lo) {
        r = lo;
    } else {
        r = hi;
        if (v <= hi) {
            r = v;
        }
    }
    return r;
}

void TOTrapSeabed01::clamp_params_and_init() {
    scale.x = clamp_f32(0.1f, 10.0f, scale.x);
    set_params[0] = CLAMPI(set_params[0], 1, 60);
    set_params[1] = CLAMPI(set_params[1], 0, 1);
    mode = 0;
    range = 15.0f;
    dist = 15.0f;
    strike_timer = (s32)(30.0f * (f32)set_params[0]);
    if (set_params[1] != 0) {
        projected = 1;
    } else {
        projected = 0;
    }
    play_speed = scale.x;
    if (scale.y < 0.0f) {
        scale.y = 0.0f;
    }
    payload.power = scale_by_table_value(scale.y);
    set_params[2] = CLAMPI(set_params[2], 0, 5);
    payload.kind = trap_seabed01_param_index_table[set_params[2]];
}

void TOTrapSeabed01::update_effects() {}

void TOTrapSeabed01::render() {
    if (TMainTask::get_render_pass() != 1 &&
        (projected == 0 || is_split_screen() != 0 || TDeferredRenderQueue::enqueue_in_instance(this) == 0) &&
        visible == 1) {
        switch (mode) {
        case 0:
        case 1:
            draw();
            break;
        case 2:
        case 3:
            render_effect_layers();
            break;
        }
    }
}

void TOTrapSeabed01::draw() {
    if (TRaderMapCore::is_not_split_screen() != 1 || projected == 0) {
        set_depth_buffer_settings_3();
        set_draw_list_mask(1);
        begin_effect_render();
        set_texture_list(trap_seabed01_texture_file);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation.y);
        draw_object_tree(model);
        pop_matrix();
        end_effect_render();
        restore_draw_list_mask();
        restore_saved_depth_alpha_state();
    }
}

void TOTrapSeabed01::draw_object_tree(NJS_OBJECT *object) {
    u32 flags;
    do {
        flags = object->evalflags;
        push_matrix();
        if (!(flags & 1)) {
            post_translate_matrix(object->pos);
        }
        if (!(flags & 2)) {
            rotate_matrix_by_node_angles(object->ang, flags & 0x20);
        }
        if (!(flags & 4)) {
            scale_current_matrix(object->scl);
        }
        if (!(flags & 8)) {
            if (projected != 0) {
                setup_particle_tev(0);
                set_texture_list(trap_seabed01_texture_file);
                load_projection_tex_matrix(0x38E);
                draw_ginja_model(object->model);
                reset_particle_tev();
            } else {
                draw_ginja_model(object->model);
            }
        }
        if (!(flags & 0x10) && object->child != NULL) {
            draw_object_tree(object->child);
        }
        pop_matrix();
        object = object->sibling;
    } while (object != NULL);
}

void TOTrapSeabed01::render_effect_layers() {
    set_texture_list(trap_seabed01_texture_file);
    if (actor_frame_tick != effect_uv_scroll_last_tick) {
        if (trap_seabed01_ginja_model != NULL && seabed01_ginja_mesh_index != -1) {
            scroll_ginja_mesh_uvs(static_cast<GinjaModel *>(trap_seabed01_ginja_model->model), 0, -20, seabed01_ginja_mesh_index, 1);
            PPCSync();
        }
        effect_uv_scroll_last_tick = actor_frame_tick;
    }
    set_model_node_callback(TOTrapSeabed01::trigger_by_id);
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, rotation.y);
    set_depth_buffer_settings_3();
    set_draw_list_mask(1);
    draw_ginja_model_with_motion(model, current_motion, frame);
    restore_draw_list_mask();
    restore_saved_depth_alpha_state();
    begin_effect_render();
    set_depth_buffer_settings_1();
    set_draw_list_mask(2);
    draw_ginja_model_with_motion(model, current_motion, frame);
    restore_draw_list_mask();
    restore_saved_depth_alpha_state();
    end_effect_render();
    pop_matrix();
    set_model_node_callback(NULL);
}

// The model node callback of render_effect_layers: the glowing node draws
// with the effect render state.
void TOTrapSeabed01::trigger_by_id(NJS_OBJECT *node) {
    if (node == trap_seabed01_ginja_model) {
        begin_effect_render();
    } else {
        end_effect_render();
    }
}

void TOTrapSeabed01::update_springing() {
    frame += play_speed;
    if (frame > (current_motion->nbFrame - 1)) {
        frame = (current_motion->nbFrame - 1);
        mode = 3;
        calc_attach_pos();
        clear_player_status_flag(0, 0x08001F04);
        set_indexed_flags(0, 0x8003);
        clear_actor_flags(0x40000);
        check_hold_player();
    }
}

void TOTrapSeabed01::update_holding() {
    if (--strike_timer < 0) {
        bodies->radius = 15.0f;
        set_indexed_flags(0, 0x100);
        clear_battle_param_slots();
        this->check_object_collisions();
        deliver_attack_hits(1.0f);
        receive_physical_attack(target, 1.0f);
    }
    submit_cursor_candidate(this, -1);
}

void TOTrapSeabed01::check_hold_player() {
    TObjPlayer *held;
    f32 distance;
    target = NULL;
    player = find_nearest_visible_player(this, NULL, range);
    if (player != 0xFFFF) {
        held = get_player_by_client_id(player);
        target = held;
        if (target != NULL) {
            distance = horizontal_distance_squared(&target->position, &position);
            dist -= held->get_body_radius(0);
            if (distance < dist * dist) {
                if (TRaderMapCore::is_not_split_screen() == 1) {
                    send_6x2C_impose_hold(held, &position, -1, 0, dist);
                } else if (player == local_client_id) {
                    send_6x2C_impose_hold(held, &position, -1, 0, dist);
                }
                play_floor_sound(0);
                return;
            }
            player = 0xFFFF;
            target = NULL;
        }
    }
}

int TOTrapSeabed01::deliver_attack_hits(f32) {
    s32 i;
    TObjChara *chara;
    for (i = 0; i < 16; i++) {
        chara = (TObjChara *)TObjPlayer::get_battle_param(i);
        if (TObjCollidable::is_valid_and_active(chara) != 0 &&
            chara->check_value_equals(TObjPlayer_name) != 0) {
            chara->receive_direct_attack(this, payload, NULL, -1, -1);
            if (payload.kind < 5) {
                chara->apply_knockback_from_attacker(this, 0.0f);
            }
        }
    }
    return 1;
}

void TOTrapSeabed01::play_sounds() {
    f32 m[3][4];
    TObjChipSpawnParams params;
    SeabedTrapFragmentSpawn *fragment;
    s32 i;
    TObjChip::copy_transform(&params, const_cast<TObjChipParams *>(&trap_seabed01_transform_params));
    params.chip.textures = trap_seabed01_texture_file;
    for (i = 0; i < 6; i++) {
        fragment = &seabed_trap_fragment_spawns[i];
        VecCopy(&params.chip.pos, &fragment->pos);
        params.chip.model = get_bml_model(trap_seabed01_bml_resource, fragment->model);
        params.angle_y = fragment->angle_y;
        new TObjSuisoChip(this, &params);
        Vec v = params.chip.pos;
        v.y = 0.0f;
        set_matrix_identity((u8 *)m);
        translate_matrix_vec3((u8 *)m, (u8 *)&position);
        rotate_matrix_y(m, rotation.y);
        matrix_mult_vec(m, &v, &v);
        TParticleCtrl *particle = spawn_particle_effect(&v, 0x8B);
        if (particle != NULL) {
            particle->set_scale(0.5f, 0.5f);
        }
    }
    play_floor_sound(1);
}

f32 TOTrapSeabed01::receive_physical_attack(TObjChara *attacker, f32 damage) {
    release_trapped_player();
    return TOTrap::receive_physical_attack(attacker, damage);
}

// Lets the held player go (the twin of TOTrapAncient01::release_trapped_player).
void TOTrapSeabed01::release_trapped_player() {
    TObjPlayer *held;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        if (target != NULL) {
            held = get_player_by_client_id(target->get_entity_id());
            if (held != NULL) {
                if (held->check_player_flag1() != 0) {
                    send_release_hold(held);
                }
                obj_clear_flag30_20000(held);
            }
        }
    } else if (target != NULL && local_client_id == target->get_entity_id()) {
        held = get_player_by_client_id(local_client_id);
        if (held != NULL && held->check_player_flag1() != 0) {
            send_release_hold(held);
        }
    }
}

// Plays the trap's sound for the floor: 0 when it grabs a player, 1 when it breaks.
void TOTrapSeabed01::play_floor_sound(s32 which) {
    const s32 sounds[4][2] = {
        {0x4B71E, 0x4BC16},
        {0x4004B71E, 0x4004BC16},
        {0x4004B71E, 0x4004BC16},
        {0x4004B71E, 0x4004BC16},
    };
    switch (get_current_floor_area()) {
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        sound_handle = play_sound_effect(sounds[0][which], &position, 0, 0);
        break;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        sound_handle = play_sound_effect(sounds[1][which], &position, 0, 0);
        break;
    case AREA_SEASIDE_NIGHT:
        sound_handle = play_sound_effect(sounds[2][which], &position, 0, 0);
        break;
    case AREA_TOWER:
        sound_handle = play_sound_effect(sounds[3][which], &position, 0, 0);
        break;
    }
}
