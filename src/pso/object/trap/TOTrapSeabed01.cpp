#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/trap/TOTrap.h"
#include "pso/object/trap/TOTrapSeabed01.h"
#include "pso/object/TObjChip.h"
#include "pso/object/seabed/TObjSuisoChip.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_80083594.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/boss/volopt/TObjVoloptCage.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/frontend/TAdEnterPasswordGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/map/FloorArea.h"
#include "pso/math/MatrixVector.h"
#include "pso/network/client_id.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/NinjaUtil.h"
#include "pso/render/render_util.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"
#include <dolphin/base/PPCArch.h>
#include "pso/system/task/TObject.h"

// One fragment chip play_sounds throws when the trap breaks: model index,
// position in the trap's frame and the chip's y angle.
struct SeabedTrapFragmentSpawn {
    s32 model;
    Vec pos;
    s32 angle_y;
};

extern "C" {
extern s32 lbl_805D3530;
}

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
static const TObjChipParams TOTrapSeabed01__transform_params = {
    {0.35f, 0.07f, 0.54f}, {0.0f, 0.0f, 0.0f}, {2.5f, 6.5f, 2.5f},
    {0x300, 0x250, 0x300}, {1, 60}, {0.0f, 1.0f}, 0, 0, 17,
};
static const s32 trap_seabed01_param_index_table[6] = {0, 1, 2, 3, 4, 5};
const char *TOTrapSeabed01_class_name = "TOTrapSeabed01";

BmlResource *TOTrapSeabed01__bml_resource;
u32 TOTrapSeabed01__texture_file;
NJS_OBJECT *TOTrapSeabed01__ginja_model;
s32 lbl_805D681C;
s32 seabed01_ginja_mesh_index;

TOTrapSeabed01::TOTrapSeabed01(TObject *parent, void *set_data) : TOTrap(parent) {
    m_name = TOTrapSeabed01_class_name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(TOTrapSeabed01__bml_resource, 0);
    current_motion = (NJS_MOTION *)get_bml_motion(TOTrapSeabed01__bml_resource, 0);
    play_speed = 1.0f;
    frame = 0.0f;
    clamp_params_and_init();
    init_collision_body_parts(this, &seabed_trap_collision_body, 1);
    refresh_collision_body_centers();
    ((TObjPlayer *)this)->register_object_by_id();
    actorFlags |= 0x60040000;
    pad_344 = 0;
    sound_handle = -1;
}

TOTrapSeabed01::~TOTrapSeabed01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TOTrapSeabed01::vfunc_6(s16 *arg1, s32 arg2) {
    if (*arg1 == 4) {
        if (arg2 == 1) {
            this->play_sounds();
        }
        if (sound_handle >= 0) {
            stop_sound_request(sound_handle);
            sound_handle = -1;
        }
        sub_802C9D38();
        set_flag8();
        queue_destruction();
    }
}

void TOTrapSeabed01::load_resources() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 5, &seabed_trap_resource_descriptor, 0, 0, 0);
    }
    TOTrapSeabed01__bml_resource = resource;
    TOTrapSeabed01__texture_file = (u32)load_gvm_texture_file((s32)"obj_seabed_turigane.gvm");
    TOTrapSeabed01__ginja_model = find_object_node((NJS_OBJECT *)get_bml_model(TOTrapSeabed01__bml_resource, 0), 5);
    lbl_805D681C = 0;
    seabed01_ginja_mesh_index = -1;
    if (TOTrapSeabed01__texture_file != 0) {
        seabed01_ginja_mesh_index = ((TObjDoorJung *)TOTrapSeabed01__texture_file)->find_entry_by_name("apk_o064_seaturigane03");
    }
}

void TOTrapSeabed01::free_static_resources() {
    if (TOTrapSeabed01__texture_file != 0) {
        release_texture_list((GinjaTextureList *)TOTrapSeabed01__texture_file);
        TAdSinglePlyChrSelectGC::safe_free(TOTrapSeabed01__texture_file);
        TOTrapSeabed01__texture_file = 0;
    }
    if (TOTrapSeabed01__bml_resource != NULL) {
        free_bin_model_request(TOTrapSeabed01__bml_resource, 1);
        TOTrapSeabed01__bml_resource = NULL;
    }
}

void *TOTrapSeabed01::create(void *set_data) {
    return new TOTrapSeabed01(tl_05, set_data);
}

inline f32 clampf_802CA5F4(f32 lo, f32 hi, f32 v) {
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
    scale.x = clampf_802CA5F4(0.1f, 10.0f, scale.x);
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

void TOTrapSeabed01::vfunc_84() {}

void TOTrapSeabed01::render() {
    if (TMainTask::get_render_pass() != 1 &&
        (projected == 0 || is_split_screen() != 0 || dispatch_input_to_instance__18TAdEnterPasswordGCFi((s32)this) == 0) &&
        m_340 == 1) {
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
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(TOTrapSeabed01__texture_file);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        draw_object_tree((NJS_OBJECT *)model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
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
                TObjFish::set_global_param(TOTrapSeabed01__texture_file);
                load_projection_tex_matrix(0x38E);
                draw_ginja_model((s32)object->model);
                reset_particle_tev();
            } else {
                draw_ginja_model((s32)object->model);
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
    TObjFish::set_global_param(TOTrapSeabed01__texture_file);
    if (actor_frame_tick != lbl_805D681C) {
        if (TOTrapSeabed01__ginja_model != NULL && seabed01_ginja_mesh_index != -1) {
            scroll_ginja_mesh_uvs(TOTrapSeabed01__ginja_model->model, 0, -20, seabed01_ginja_mesh_index, 1);
            PPCSync();
        }
        lbl_805D681C = actor_frame_tick;
    }
    set_model_node_callback((s32)TOTrapSeabed01::trigger_by_id);
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, rotation_y);
    set_depth_buffer_settings_3();
    set_draw_list_mask(1);
    draw_ginja_model_with_motion(model, current_motion, frame);
    restore_draw_list_mask();
    restore_saved_depth_alpha_state();
    TParticleCtrl::begin_effect_render();
    set_depth_buffer_settings_1();
    set_draw_list_mask(2);
    draw_ginja_model_with_motion(model, current_motion, frame);
    restore_draw_list_mask();
    restore_saved_depth_alpha_state();
    TParticleCtrl::end_effect_render();
    pop_matrix();
    set_model_node_callback(NULL);
}

// The model node callback of render_effect_layers: the glowing node draws
// with the effect render state.
void TOTrapSeabed01::trigger_by_id(u32 node) {
    if (node == (u32)TOTrapSeabed01__ginja_model) {
        TParticleCtrl::begin_effect_render();
    } else {
        TParticleCtrl::end_effect_render();
    }
}

void TOTrapSeabed01::vfunc_81() {
    frame += play_speed;
    if (frame > (f32)(current_motion->nbFrame - 1)) {
        frame = (f32)(current_motion->nbFrame - 1);
        mode = 3;
        calc_attach_pos();
        clear_player_status_flag(0, 0x08001F04);
        set_indexed_flags(0, 0x8003);
        obj_clearFlags30(0x40000);
        check_hold_player();
    }
}

void TOTrapSeabed01::vfunc_82() {
    if (--strike_timer < 0) {
        bodies->radius = 15.0f;
        set_indexed_flags(0, 0x100);
        TObjPlayer::init_all_slots();
        ((TObjPlayer *)this)->check_object_collisions();
        vfunc_67(1.0f);
        receive_physical_attack(target, 1.0f);
    }
    submit_cursor_candidate(this, -1);
}

void TOTrapSeabed01::check_hold_player() {
    TObjPlayer *held;
    f32 distance;
    target = NULL;
    player = find_nearest_visible_player((TObjEnemy *)this, NULL, range);
    if (player != 0xFFFF) {
        held = get_player_by_client_id(player);
        target = (u8 *)held;
        if (target != NULL) {
            distance = horizontal_distance_squared(&((TObjBase *)target)->position, &position);
            dist -= TObjPlayer__sub_8017A1A4(held, 0);
            if (distance < dist * dist) {
                if (TRaderMapCore::is_not_split_screen() == 1) {
                    send_6x2C_impose_hold(held, &position, -1, 0, dist);
                } else if (player == local_client_id) {
                    send_6x2C_impose_hold(held, &position, -1, 0, dist);
                }
                sub_802C9C18(0);
                return;
            }
            player = 0xFFFF;
            target = NULL;
        }
    }
}

int TOTrapSeabed01::vfunc_67(f32) {
    s32 i;
    TObjChara *chara;
    for (i = 0; i < 16; i++) {
        chara = (TObjChara *)TObjPlayer::get_battle_param(i);
        if (TObjPlayer::is_valid_and_active((u32)chara) != 0 &&
            ((TUnk_804B6C24 *)chara)->check_value_equals(lbl_805D3530) != 0) {
            chara->receive_direct_attack(this, payload, NULL, -1, -1);
            if (payload.kind < 5) {
                chara->apply_knockback_from_attacker((u8 *)this, 0.0f);
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
    copy_transform__8TObjChipFPvPv((u8 *)&params, (u8 *)&TOTrapSeabed01__transform_params);
    params.chip.textures = TOTrapSeabed01__texture_file;
    for (i = 0; i < 6; i++) {
        fragment = &seabed_trap_fragment_spawns[i];
        VecCopy((Vec *)params.chip.pos, &fragment->pos);
        params.chip.model = get_bml_model(TOTrapSeabed01__bml_resource, fragment->model);
        params.angle_y = fragment->angle_y;
        new TObjSuisoChip(this, &params);
        Vec v = *(Vec *)params.chip.pos;
        v.y = 0.0f;
        set_matrix_identity((u8 *)m);
        translate_matrix_vec3((u8 *)m, (u8 *)&position);
        rotate_matrix_y(m, rotation_y);
        matrix_mult_vec(m, &v, &v);
        TParticleCtrl *particle = (TParticleCtrl *)spawn_particle_effect(&v, 0x8B);
        if (particle != NULL) {
            particle->set_scale(0.5f, 0.5f);
        }
    }
    sub_802C9C18(1);
}

f32 TOTrapSeabed01::receive_physical_attack(void *attacker, f32 damage) {
    sub_802C9D38();
    return TOTrap::receive_physical_attack(attacker, damage);
}

// Lets the held player go (the twin of TOTrapAncient01::release_trapped_player).
void TOTrapSeabed01::sub_802C9D38() {
    TObjPlayer *held;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        if (target != NULL) {
            held = get_player_by_client_id(get_entity_id((TObjBase *)target));
            if (held != NULL) {
                if (((TLobby *)held)->check_player_flag1() != 0) {
                    TObjPlayer::send_code_45_1((s32)held);
                }
                obj_clear_flag30_20000(held);
            }
        }
    } else if (target != NULL && local_client_id == get_entity_id((TObjBase *)target)) {
        held = get_player_by_client_id(local_client_id);
        if (held != NULL && ((TLobby *)held)->check_player_flag1() != 0) {
            TObjPlayer::send_code_45_1((s32)held);
        }
    }
}

// Plays the trap's sound for the floor: 0 when it grabs a player, 1 when it breaks.
void TOTrapSeabed01::sub_802C9C18(s32 which) {
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
