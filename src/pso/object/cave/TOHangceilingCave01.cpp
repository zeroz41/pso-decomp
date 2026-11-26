#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/BmlAccessors.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/render/GinjaTexture.h"
#include "types.h"
#include <string.h>
#include "pso/object/cave/TOHangceilingCave01.h"
#include "pso/object/cave/TOHangceilingCave01KeyQuick.h"
#include "pso/object/cave/TOHangceilingCave01Key.h"
#include "pso/object/cave/TOHangceilingCave01Normal.h"
#include "pso/unk/TOHangceilingCaveBase.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/text_803DA798.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/TLevelSelect.h"

struct Q_801681D0 { f32 w[4]; };


BmlResource *hangceiling_cave01_model_archive;
NJS_TEXLIST **turiten_singo_texture_lists;
s32 lbl_805D59D8;
NJS_OBJECT *hangceiling_cave01_model_root;
s32 turiten_singo_key_model_index;
s32 hanging_ceiling_motion_index;


#pragma push
#pragma readonly_strings on
const char *fe_obj_turiten_moto_model_names[] = {"fe_obj_turiten_kuro.gj", "fe_obj_turiten_moto_taiki.gj", "fs_obj_turiten_singo.gj", NULL};
const char *fe_obj_turiten_moto_motion_names[] = {"fe_obj_turiten_moto.njm", "fe_obj_turiten_moto_taiki.njm", NULL};
BmlResourceDescriptor fe_obj_turiten_moto_resource_descriptor = {
    "fe_obj_turiten_moto.bml", fe_obj_turiten_moto_model_names, fe_obj_turiten_moto_motion_names, 3, 2};
__declspec(section ".data") const char *bm_obj_ruins_turiten_model_names[] = {"fe_obj_gc_turiten_moto.gj", NULL};
__declspec(section ".data") const char *bm_obj_ruins_turiten_motion_names[] = {"fe_obj_gc_turiten_moto.njm", NULL};
BmlResourceDescriptor turiten_singo_resource_descriptor = {
    "bm_obj_ruins_turiten.bml", bm_obj_ruins_turiten_model_names, bm_obj_ruins_turiten_motion_names, 1, 1};
#pragma pop
__declspec(section ".rodata") extern Q_801681D0 hang_ceiling_cave_scale_params = { 1.0f, 2.0f, 3.0f, 6.0f };
extern const char hangceiling_cave01_normal_class_name_string[] = "TOHangceilingCave01Normal";
extern const char hangceiling_cave01_key_class_name_string[] = "TOHangceilingCave01Key";
extern const char hangceiling_cave01_key_quick_class_name_string[] = "TOHangceilingCave01KeyQuick";
CollisionBody hangceiling_cave01_collision_body_parts = {{0.0f, 80.0f, 0.0f}, 17.0f, 17.0f, 0, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};

const char *hangceiling_cave01_normal_class_name = hangceiling_cave01_normal_class_name_string;
const char *hangceiling_cave01_key_class_name = hangceiling_cave01_key_class_name_string;
const char *hangceiling_cave01_key_quick_class_name = hangceiling_cave01_key_quick_class_name_string;

static const s32 hang_flag_8 = 8;

void TOHangceilingCaveBase::set_damage(f32 v) {
    damage = v;
}

void TOHangceilingCaveBase::apply_knockback_from_attacker(u8 *, f32) {
}

f32 TOHangceilingCaveBase::receive_physical_attack(void *, f32) {
    return 0.0f;
}

s32 TOHangceilingCaveBase::select_melee_contact_body(void *, f32) {
    return 1;
}

TOHangceilingCaveBase::TOHangceilingCaveBase(TObject *parent, void *set_data) : TObjChara(parent) {
    apply_object_set_data(set_data);
    model = get_bml_model(hangceiling_cave01_model_archive, turiten_singo_key_model_index);
    current_motion = (NJS_MOTION *)get_bml_motion(hangceiling_cave01_model_archive, hanging_ceiling_motion_index);
    init_collision_body_parts(this, &hangceiling_cave01_collision_body_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    clear_hit_players();
    bodies->flags |= 0x1080;
}

TOHangceilingCaveBase::~TOHangceilingCaveBase() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void load_turiten_singo_resources(void) {
    BmlResource *p;

    hangceiling_cave01_model_archive = NULL;
    turiten_singo_texture_lists = NULL;
    switch (get_current_floor_area()) {
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        p = new BmlResource(5, &turiten_singo_resource_descriptor, 0, 0, NULL);
        hangceiling_cave01_model_archive = p;
        turiten_singo_texture_lists = (NJS_TEXLIST **)mem_alloc(3 * sizeof(NJS_TEXLIST *));
        turiten_singo_texture_lists[1] = NULL;
        turiten_singo_texture_lists[0] = NULL;
        turiten_singo_texture_lists[2] = (NJS_TEXLIST *)get_bml_texlist(hangceiling_cave01_model_archive, 0);
        lbl_805D59D8 = 0;
        hangceiling_cave01_model_root = NULL;
        turiten_singo_key_model_index = 0;
        hanging_ceiling_motion_index = 0;
        break;
    default:
        p = new BmlResource(5, &fe_obj_turiten_moto_resource_descriptor, 0, 0, NULL);
        hangceiling_cave01_model_archive = p;
        turiten_singo_texture_lists = (NJS_TEXLIST **)mem_alloc(3 * sizeof(NJS_TEXLIST *));
        turiten_singo_texture_lists[0] = LoadPvmFileTls("fs_obj_turiten_singo.gvm");
        turiten_singo_texture_lists[1] = LoadPvmFileTls("fs_obj_turiten_singo_r.gvm");
        turiten_singo_texture_lists[2] = (NJS_TEXLIST *)get_bml_texlist(hangceiling_cave01_model_archive, 1);
        hangceiling_cave01_model_root = (NJS_OBJECT *)get_bml_model(hangceiling_cave01_model_archive, 2);
        turiten_singo_key_model_index = 1;
        hanging_ceiling_motion_index = 0;
        break;
    }
}

void TOHangceilingCave01::destroy_instance() {
    if (turiten_singo_texture_lists != NULL) {
        TObjPlayer::free_if_valid((saddr)turiten_singo_texture_lists[1]);
        TObjPlayer::free_if_valid((saddr)turiten_singo_texture_lists[0]);
        if (turiten_singo_texture_lists != NULL) {
            mem_free(turiten_singo_texture_lists);
            turiten_singo_texture_lists = NULL;
        }
    }
    if (hangceiling_cave01_model_archive != NULL) {
        delete hangceiling_cave01_model_archive;
        hangceiling_cave01_model_archive = NULL;
    }
}

void *TOHangceilingCave01::create(void *set_data) {
    if (set_data != NULL) {
        switch (*(s32 *)((u8 *)set_data + 0x38)) {
        case 0:
            return new TOHangceilingCave01Normal(tl_05, set_data);
        case 1:
            return new TOHangceilingCave01Key(tl_05, set_data);
        case 2:
            return new TOHangceilingCave01KeyQuick(tl_05, set_data);
        }
    }
    return NULL;
}

s32 TOHangceilingCaveBase::is_in_view() {
    Vec view;

    if (xz_distance_squared(&position, (const Vec *)&camera_ctrl_instance->pos.x) < 2500.0f) {
        visibility = 1;
        return 1;
    }
    if (update_object_view_visibility(300.0f, 50.0f) == 0) {
        return 0;
    }
    transform_point_by_current_matrix(&position.x, &view);
    if (view.z > -35.0f) {
        return 0;
    }
    return 1;
}

void TOHangceilingCaveBase::run_task() {
    if (TObjPlayer::check_demo_mode() == 0) {
        update_state();
        play_mode_sound();
        if (is_in_view() != 0 && mode != 3 && is_passing_frame(8.0f) != 0) {
            spawn_particle_effect(&position, 0x64);
        }
    }
}

void TOHangceilingCaveBase::render() {
    f32 step;
    f32 level;
    s32 lit0;
    s32 lit1;
    s32 lit2;

    if (is_in_view() != 0 || TObjPlayer::check_demo_mode() == 1) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(turiten_singo_texture_lists[2]));
        if (model != NULL && current_motion != NULL) {
            draw_ginja_model_with_motion(model, current_motion, frame);
        }
        if (hangceiling_cave01_model_root != NULL) {
            TParticleCtrl::begin_effect_render();
            if (display_mode == 0) {
                level = wait_timer;
                step = wait_interval;
                lit0 = level <= step;
                lit1 = level <= 2.0f * step;
                lit2 = level <= 3.0f * step;
                set_texture_list(reinterpret_cast<NJS_TEXLIST *>(turiten_singo_texture_lists[1]));
                if (lit0 == 1) {
                    draw_ginja_model(hangceiling_cave01_model_root->child->model);
                }
                if (lit1 == 1) {
                    draw_ginja_model(hangceiling_cave01_model_root->child->child->model);
                }
                if (lit2 == 1) {
                    draw_ginja_model(hangceiling_cave01_model_root->child->child->child->model);
                }
                set_texture_list(reinterpret_cast<NJS_TEXLIST *>(turiten_singo_texture_lists[0]));
                if (lit0 == 0) {
                    draw_ginja_model(hangceiling_cave01_model_root->child->model);
                }
                if (lit1 == 0) {
                    draw_ginja_model(hangceiling_cave01_model_root->child->child->model);
                }
                if (lit2 == 0) {
                    draw_ginja_model(hangceiling_cave01_model_root->child->child->child->model);
                }
            } else {
                if (is_current_floor_switch_set((u16)switch_id) == 1) {
                    set_texture_list(reinterpret_cast<NJS_TEXLIST *>(turiten_singo_texture_lists[0]));
                } else {
                    set_texture_list(reinterpret_cast<NJS_TEXLIST *>(turiten_singo_texture_lists[1]));
                }
                draw_ginja_object(hangceiling_cave01_model_root);
            }
            TParticleCtrl::end_effect_render();
        }
        pop_matrix();
    }
}

void TOHangceilingCaveBase::begin_wait() {
}

void TOHangceilingCaveBase::update_state() {
}

f32 TOHangceilingCaveBase::receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32) {
    return 0.0f;
}

f32 TOHangceilingCaveBase::receive_weapon_special_attack(void *, void *) {
    return 0.0f;
}

int TOHangceilingCaveBase::calc_distance_accuracy_penalty(void *, void *, void *, float) {
    return 1;
}

void TOHangceilingCaveBase::init_geometry() {
    f32 size;

    switch_id = set_params[0];
    display_mode = set_params[2];
    if (display_mode >= 3) {
        display_mode = 2;
    }
    size = 30.0f + scale.x;
    wait_interval = size - 1.0f;
    set_damage(100.0f + scale.z);
    begin_wait();
    wait_timer = 1.0f - scale.y;
}

void TOHangceilingCaveBase::hit_touching_players() {
    s32 i = 0;
    TObjPlayer *player;

    do {
        player = get_player_by_client_id(i);
        if (player != NULL && has_hit_player((uaddr)player) == 0) {
            if (player->get_floor() == get_current_floor() && check_actor_body_contact(player, 100.0f) != 0) {
                DirectAttackPayload attack;
                attack.kind = 0;
                attack.power = calc_damage(damage);
                player->receive_direct_attack(this, attack, NULL, -1, -1);
                player->set_actor_flags(0x400);
                add_hit_player((uaddr)player);
            }
        }
        i++;
    } while (i != 12);
}

void TOHangceilingCaveBase::play_mode_sound() {
    s32 area = get_current_floor_area();
    s32 id = 0;

    switch (mode) {
    case 2:
        switch (area) {
        case AREA_VR_TEMPLE_ALPHA:
        case AREA_VR_TEMPLE_BETA:
            id = 0x4BC11;
            break;
        case AREA_VR_SPACESHIP_ALPHA:
        case AREA_VR_SPACESHIP_BETA:
            id = 0x4004BC11;
            break;
        default:
            id = 0x43C18;
            break;
        }
        break;
    case 1:
        switch (area) {
        case AREA_VR_TEMPLE_ALPHA:
        case AREA_VR_TEMPLE_BETA:
            id = 0x4B212;
            break;
        case AREA_VR_SPACESHIP_ALPHA:
        case AREA_VR_SPACESHIP_BETA:
            id = 0x4004B212;
            break;
        default:
            id = 0x4321A;
            break;
        }
        break;
    }
    if (id != 0) {
        play_persistent_sound(id, this, &position, 0, 0);
    }
}

void TOHangceilingCaveBase::set_mode(s32 new_mode) {
    s16 saved;

    if (new_mode != mode) {
        mode = new_mode;
        if (access_object_saved_state(&saved, 1) != 0) {
            saved = mode;
        }
        switch (mode) {
        case 0:
        case 1:
            break;
        case 2:
            current_motion = (NJS_MOTION *)get_bml_motion(hangceiling_cave01_model_archive, hanging_ceiling_motion_index);
            frame = 22.0f;
            play_speed = 1.0f;
            frame_count = (f32)current_motion->nbFrame - 1.0f;
            break;
        }
    }
}

void TOHangceilingCaveBase::clear_hit_players() {
    memset(hit_players, 0, sizeof(hit_players));
    hit_player_count = 0;
}

void TOHangceilingCaveBase::add_hit_player(uaddr player) {
    if (hit_player_count < 4) {
        hit_players[hit_player_count++] = player;
    }
}

s32 TOHangceilingCaveBase::has_hit_player(uaddr player) {
    s32 i;

    for (i = 0; i != hit_player_count; i++) {
        if (hit_players[i] == player) {
            return 1;
        }
    }
    return 0;
}

void TOHangceilingCaveBase::advance_frame() {
    frame = frame + play_speed;
    if (frame_count < frame) {
        frame = 0.0f;
    }
}

f32 TOHangceilingCaveBase::calc_damage(f32 power) {
    Q_801681D0 q = hang_ceiling_cave_scale_params;
    return power * q.w[game_difficulty_selection];
}

TOHangceilingCave01Normal::TOHangceilingCave01Normal(TObject *parent, void *set_data)
    : TOHangceilingCaveBase(parent, set_data) {
    m_name = hangceiling_cave01_normal_class_name;
    init_geometry();
}

TOHangceilingCave01Normal::~TOHangceilingCave01Normal() {
}

void TOHangceilingCave01Normal::update_state() {
    switch (mode) {
    case 0:
        if (0.0f < wait_timer) {
            wait_timer = wait_timer - 1.0f;
            return;
        }
        set_mode(1);
        clear_hit_players();
        return;
    case 1:
        advance_frame();
        hit_touching_players();
        if (4.0f == frame) {
            bodies->flags &= ~8;
            return;
        }
        if (23.0f == frame) {
            set_mode(2);
        }
        return;
    case 2:
        advance_frame();
        if (50.0f == frame) {
            bodies->flags |= hang_flag_8;
            return;
        }
        if (frame == frame_count) {
            begin_wait();
        }
        break;
    }
}

void TOHangceilingCave01Normal::begin_wait() {
    current_motion = (NJS_MOTION *)get_bml_motion(hangceiling_cave01_model_archive, hanging_ceiling_motion_index);
    texlist = turiten_singo_texture_lists[0];
    wait_timer = 4.0f * wait_interval;
    set_mode(0);
    bodies->flags |= hang_flag_8;
    frame = 0.0f;
    play_speed = 1.0f;
    frame_count = (f32)current_motion->nbFrame - 1.0f;
}

TOHangceilingCave01Key::TOHangceilingCave01Key(TObject *parent, void *set_data)
    : TOHangceilingCaveBase(parent, set_data) {
    m_name = hangceiling_cave01_key_class_name;
    init_geometry();
}

TOHangceilingCave01Key::~TOHangceilingCave01Key() {
}

void TOHangceilingCave01Key::update_state() {
    switch (mode) {
    case 3:
        if (is_current_floor_switch_set((u16)switch_id) == 1 && frame <= frame_count) {
            set_mode(2);
        }
        advance_frame();
        break;
    case 1:
        advance_frame();
        hit_touching_players();
        if (4.0f == frame) {
            bodies->flags &= ~8;
        } else if (23.0f == frame) {
            begin_wait();
            clear_current_floor_switch((u16)switch_id);
        }
        break;
    case 2:
        advance_frame();
        if (50.0f == frame) {
            bodies->flags |= hang_flag_8;
        } else if (frame == frame_count) {
            set_mode(1);
        }
        break;
    }
}

void TOHangceilingCave01Key::begin_wait() {
    texlist = turiten_singo_texture_lists[1];
    current_motion = (NJS_MOTION *)get_bml_motion(hangceiling_cave01_model_archive, 1);
    wait_timer = 0.0f;
    set_mode(3);
    bodies->flags &= ~8;
    frame = 0.0f;
    play_speed = 1.0f;
    frame_count = (f32)current_motion->nbFrame - 1.0f;
    clear_hit_players();
}

TOHangceilingCave01KeyQuick::TOHangceilingCave01KeyQuick(TObject *parent, void *set_data)
    : TOHangceilingCaveBase(parent, set_data) {
    m_name = hangceiling_cave01_key_quick_class_name;
    init_geometry();
    set_damage(100.0f + scale.z);
}

TOHangceilingCave01KeyQuick::~TOHangceilingCave01KeyQuick() {
}

void TOHangceilingCave01KeyQuick::update_state() {
    switch (mode) {
    case 3:
        if (is_current_floor_switch_set((u16)switch_id) == 1 && frame <= frame_count) {
            set_mode(2);
        }
        advance_frame();
        return;
    case 1:
        advance_frame();
        hit_touching_players();
        if (4.0f < frame) {
            bodies->flags &= ~8;
        }
        if (23.0f == frame) {
            begin_wait();
        }
        break;
    case 2:
        if (is_current_floor_switch_set((u16)switch_id) == 1) {
            if (0.0f != frame) {
                advance_frame();
            }
            if (50.0f == frame) {
                bodies->flags |= hang_flag_8;
                return;
            }
        } else {
            if (85.0f <= frame && frame <= frame_count) {
                frame = 0.0f;
            } else if (77.0f <= frame) {
                frame = 1.0f;
            } else if (73.0f <= frame) {
                frame = 2.0f;
            } else if (65.0f <= frame) {
                frame = 3.0f;
            } else if (53.0f <= frame) {
                frame = 4.0f;
            } else {
                frame = 5.0f;
            }
            set_mode(1);
        }
        break;
    }
}

void TOHangceilingCave01KeyQuick::begin_wait() {
    texlist = turiten_singo_texture_lists[1];
    current_motion = (NJS_MOTION *)get_bml_motion(hangceiling_cave01_model_archive, 1);
    wait_timer = 0.0f;
    set_mode(3);
    bodies->flags &= ~8;
    frame = 0.0f;
    play_speed = 1.0f;
    frame_count = (f32)current_motion->nbFrame - 1.0f;
    clear_hit_players();
}
