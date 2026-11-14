#include "types.h"
#include <string.h>
#include "pso/object/cave/TOHangceilingCave01.h"
#include "pso/object/cave/TOHangceilingCave01KeyQuick.h"
#include "pso/object/cave/TOHangceilingCave01Key.h"
#include "pso/object/cave/TOHangceilingCave01Normal.h"
#include "pso/unk/TUnk_804B2578.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/map/FloorArea.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D8F74.h"

struct Q_801681D0 { f32 w[4]; };

extern s32 game_difficulty_selection;
extern TCameraCtrl *camera_ctrl_instance;

BmlResource *TOHangceilingCave01__model_archive;
s32 *turiten_singo_texture_lists;
s32 lbl_805D59D8;
NJS_OBJECT *TOHangceilingCave01__model_root;
s32 turiten_singo_key_model_index;
s32 hanging_ceiling_motion_index;

extern const char lbl_804416F8[] = "fe_obj_turiten_kuro.gj";
extern const char lbl_80441710[] = "fe_obj_turiten_moto_taiki.gj";
extern const char lbl_80441730[] = "fs_obj_turiten_singo.gj";
extern const char lbl_80441748[] = "fe_obj_turiten_moto.njm";
extern const char lbl_80441760[] = "fe_obj_turiten_moto_taiki.njm";
extern const char lbl_80441780[] = "fe_obj_turiten_moto.bml";
extern const char lbl_80441798[] = "fe_obj_gc_turiten_moto.gj";
extern const char lbl_804417B4[] = "fe_obj_gc_turiten_moto.njm";
extern const char lbl_804417D0[] = "bm_obj_ruins_turiten.bml";
__declspec(section ".rodata") extern Q_801681D0 hang_ceiling_cave_scale_params = { 1.0f, 2.0f, 3.0f, 6.0f };
extern const char TOHangceilingCave01Normal__class_name_string[] = "TOHangceilingCave01Normal";
extern const char TOHangceilingCave01Key__class_name_string[] = "TOHangceilingCave01Key";
extern const char TOHangceilingCave01KeyQuick__class_name_string[] = "TOHangceilingCave01KeyQuick";

const char *fe_obj_turiten_moto_model_names[] = {lbl_804416F8, lbl_80441710, lbl_80441730, NULL};
const char *fe_obj_turiten_moto_motion_names[] = {lbl_80441748, lbl_80441760, NULL};
BmlResourceDescriptor fe_obj_turiten_moto_resource_descriptor = {
    lbl_80441780, fe_obj_turiten_moto_model_names, fe_obj_turiten_moto_motion_names, 3, 2};
__declspec(section ".data") const char *bm_obj_ruins_turiten_model_names[] = {lbl_80441798, NULL};
__declspec(section ".data") const char *bm_obj_ruins_turiten_motion_names[] = {lbl_804417B4, NULL};
BmlResourceDescriptor turiten_singo_resource_descriptor = {
    lbl_804417D0, bm_obj_ruins_turiten_model_names, bm_obj_ruins_turiten_motion_names, 1, 1};
CollisionBody lbl_804B2174 = {{0.0f, 80.0f, 0.0f}, 17.0f, 17.0f, 0, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};

const char *TOHangceilingCave01Normal__class_name = TOHangceilingCave01Normal__class_name_string;
const char *TOHangceilingCave01Key__class_name = TOHangceilingCave01Key__class_name_string;
const char *TOHangceilingCave01KeyQuick__class_name = TOHangceilingCave01KeyQuick__class_name_string;

static const s32 hang_flag_8 = 8;

void TUnk_804B2578::set_scale(f32 v) {
    m_338 = v;
}

void TUnk_804B2578::apply_knockback_from_attacker(u8 *, f32) {
}

f32 TUnk_804B2578::receive_physical_attack(void *, f32) {
    return 0.0f;
}

s32 TUnk_804B2578::select_melee_contact_body(void *, f32) {
    return 1;
}

TUnk_804B2578::TUnk_804B2578(TObject *parent, void *set_data) : TObjChara(parent) {
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(TOHangceilingCave01__model_archive, turiten_singo_key_model_index);
    current_motion = (NJS_MOTION *)get_bml_motion(TOHangceilingCave01__model_archive, hanging_ceiling_motion_index);
    init_collision_body_parts(this, &lbl_804B2174, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    reset_state();
    bodies->flags |= 0x1080;
}

TUnk_804B2578::~TUnk_804B2578() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void load_turiten_singo_resources(void) {
    void *p;

    TOHangceilingCave01__model_archive = NULL;
    turiten_singo_texture_lists = NULL;
    switch (get_current_floor_area()) {
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, &turiten_singo_resource_descriptor, 0, 0, 0);
        }
        TOHangceilingCave01__model_archive = (BmlResource *)p;
        turiten_singo_texture_lists = (s32 *)mem_alloc(0xC);
        turiten_singo_texture_lists[1] = 0;
        turiten_singo_texture_lists[0] = 0;
        turiten_singo_texture_lists[2] = TObjFish__sub_8001EDB0(TOHangceilingCave01__model_archive, 0);
        lbl_805D59D8 = 0;
        TOHangceilingCave01__model_root = NULL;
        turiten_singo_key_model_index = 0;
        hanging_ceiling_motion_index = 0;
        break;
    default:
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, &fe_obj_turiten_moto_resource_descriptor, 0, 0, 0);
        }
        TOHangceilingCave01__model_archive = (BmlResource *)p;
        turiten_singo_texture_lists = (s32 *)mem_alloc(0xC);
        turiten_singo_texture_lists[0] = (s32)load_gvm_texture_file((s32)"fs_obj_turiten_singo.gvm");
        turiten_singo_texture_lists[1] = (s32)load_gvm_texture_file((s32)"fs_obj_turiten_singo_r.gvm");
        turiten_singo_texture_lists[2] = TObjFish__sub_8001EDB0(TOHangceilingCave01__model_archive, 1);
        TOHangceilingCave01__model_root = (NJS_OBJECT *)get_bml_model(TOHangceilingCave01__model_archive, 2);
        turiten_singo_key_model_index = 1;
        hanging_ceiling_motion_index = 0;
        break;
    }
}

void TOHangceilingCave01::destroy_instance() {
    if (turiten_singo_texture_lists != NULL) {
        TObjPlayer::free_if_valid(turiten_singo_texture_lists[1]);
        TObjPlayer::free_if_valid(turiten_singo_texture_lists[0]);
        if (turiten_singo_texture_lists != NULL) {
            mem_free(turiten_singo_texture_lists);
            turiten_singo_texture_lists = NULL;
        }
    }
    if (TOHangceilingCave01__model_archive != NULL) {
        free_bin_model_request(TOHangceilingCave01__model_archive, 1);
        TOHangceilingCave01__model_archive = NULL;
    }
}

void *TOHangceilingCave01__create(void *set_data) {
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

s32 TUnk_804B2578::sub_801688C0() {
    Vec view;

    if (xz_distance_squared(&position, (const Vec *)&camera_ctrl_instance->pos_x) < 2500.0f) {
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

void TUnk_804B2578::run_task() {
    if (TObjPlayer::check_demo_mode() == 0) {
        vfunc_80();
        sub_80168398();
        if (sub_801688C0() != 0 && mode != 3 && is_passing_frame(8.0f) != 0) {
            spawn_particle_effect(&position, 0x64);
        }
    }
}

void TUnk_804B2578::render() {
    f32 step;
    f32 level;
    s32 lit0;
    s32 lit1;
    s32 lit2;

    if (sub_801688C0() != 0 || TObjPlayer::check_demo_mode() == 1) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(turiten_singo_texture_lists[2]);
        if (model != NULL && current_motion != NULL) {
            draw_ginja_model_with_motion(model, current_motion, frame);
        }
        if (TOHangceilingCave01__model_root != NULL) {
            TParticleCtrl::begin_effect_render();
            if (m_358 == 0) {
                level = m_354;
                step = m_350;
                lit0 = level <= step;
                lit1 = level <= 2.0f * step;
                lit2 = level <= 3.0f * step;
                TObjFish::set_global_param(turiten_singo_texture_lists[1]);
                if (lit0 == 1) {
                    draw_ginja_model((s32)TOHangceilingCave01__model_root->child->model);
                }
                if (lit1 == 1) {
                    draw_ginja_model((s32)TOHangceilingCave01__model_root->child->child->model);
                }
                if (lit2 == 1) {
                    draw_ginja_model((s32)TOHangceilingCave01__model_root->child->child->child->model);
                }
                TObjFish::set_global_param(turiten_singo_texture_lists[0]);
                if (lit0 == 0) {
                    draw_ginja_model((s32)TOHangceilingCave01__model_root->child->model);
                }
                if (lit1 == 0) {
                    draw_ginja_model((s32)TOHangceilingCave01__model_root->child->child->model);
                }
                if (lit2 == 0) {
                    draw_ginja_model((s32)TOHangceilingCave01__model_root->child->child->child->model);
                }
            } else {
                if (is_current_floor_switch_set((u16)switch_id) == 1) {
                    TObjFish::set_global_param(turiten_singo_texture_lists[0]);
                } else {
                    TObjFish::set_global_param(turiten_singo_texture_lists[1]);
                }
                draw_ginja_object(TOHangceilingCave01__model_root);
            }
            TParticleCtrl::end_effect_render();
        }
        pop_matrix();
    }
}

void TUnk_804B2578::vfunc_79() {
}

void TUnk_804B2578::vfunc_80() {
}

f32 TUnk_804B2578::receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32) {
    return 0.0f;
}

f32 TUnk_804B2578::receive_weapon_special_attack(void *, void *) {
    return 0.0f;
}

int TUnk_804B2578::calc_distance_accuracy_penalty(void *, void *, void *, float) {
    return 1;
}

void TUnk_804B2578::init_geometry() {
    f32 size;

    switch_id = set_params[0];
    m_358 = set_params[2];
    if (m_358 >= 3) {
        m_358 = 2;
    }
    size = 30.0f + scale.x;
    m_350 = size - 1.0f;
    set_scale(100.0f + scale.z);
    vfunc_79();
    m_354 = 1.0f - scale.y;
}

void TUnk_804B2578::sub_80168488() {
    s32 i = 0;
    TObjPlayer *player;

    do {
        player = get_player_by_client_id(i);
        if (player != NULL && sub_80168244((u32)player) == 0) {
            if (player->get_floor() == get_current_floor() && check_actor_body_contact(player, 100.0f) != 0) {
                DirectAttackPayload attack;
                attack.kind = 0;
                attack.power = vfunc_81(m_338);
                player->receive_direct_attack(this, attack, NULL, -1, -1);
                obj_setFlags30(player, 0x400);
                sub_80168280((u32)player);
            }
        }
        i++;
    } while (i != 12);
}

void TUnk_804B2578::sub_80168398() {
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
        play_persistent_sound(id, (s32)this, (u32)&position, 0, 0);
    }
}

void TUnk_804B2578::sub_801682E4(s32 new_mode) {
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
            current_motion = (NJS_MOTION *)get_bml_motion(TOHangceilingCave01__model_archive, hanging_ceiling_motion_index);
            frame = 22.0f;
            play_speed = 1.0f;
            frame_count = (f32)current_motion->nbFrame - 1.0f;
            break;
        }
    }
}

void TUnk_804B2578::reset_state() {
    memset(hit_players, 0, sizeof(hit_players));
    hit_player_count = 0;
}

void TUnk_804B2578::sub_80168280(u32 player) {
    if (hit_player_count < 4) {
        hit_players[hit_player_count++] = player;
    }
}

s32 TUnk_804B2578::sub_80168244(u32 player) {
    s32 i;

    for (i = 0; i != hit_player_count; i++) {
        if (hit_players[i] == player) {
            return 1;
        }
    }
    return 0;
}

void TUnk_804B2578::advance_wrap_offset() {
    frame = frame + play_speed;
    if (frame_count < frame) {
        frame = 0.0f;
    }
}

f32 TUnk_804B2578::vfunc_81(f32 power) {
    Q_801681D0 q = hang_ceiling_cave_scale_params;
    return power * q.w[game_difficulty_selection];
}

TOHangceilingCave01Normal::TOHangceilingCave01Normal(TObject *parent, void *set_data)
    : TUnk_804B2578(parent, set_data) {
    m_name = TOHangceilingCave01Normal__class_name;
    init_geometry();
}

TOHangceilingCave01Normal::~TOHangceilingCave01Normal() {
}

void TOHangceilingCave01Normal::vfunc_80() {
    switch (mode) {
    case 0:
        if (0.0f < m_354) {
            m_354 = m_354 - 1.0f;
            return;
        }
        sub_801682E4(1);
        reset_state();
        return;
    case 1:
        advance_wrap_offset();
        sub_80168488();
        if (4.0f == frame) {
            bodies->flags &= ~8;
            return;
        }
        if (23.0f == frame) {
            sub_801682E4(2);
        }
        return;
    case 2:
        advance_wrap_offset();
        if (50.0f == frame) {
            bodies->flags |= hang_flag_8;
            return;
        }
        if (frame == frame_count) {
            vfunc_79();
        }
        break;
    }
}

void TOHangceilingCave01Normal::vfunc_79() {
    current_motion = (NJS_MOTION *)get_bml_motion(TOHangceilingCave01__model_archive, hanging_ceiling_motion_index);
    texlist = turiten_singo_texture_lists[0];
    m_354 = 4.0f * m_350;
    sub_801682E4(0);
    bodies->flags |= hang_flag_8;
    frame = 0.0f;
    play_speed = 1.0f;
    frame_count = (f32)current_motion->nbFrame - 1.0f;
}

TOHangceilingCave01Key::TOHangceilingCave01Key(TObject *parent, void *set_data)
    : TUnk_804B2578(parent, set_data) {
    m_name = TOHangceilingCave01Key__class_name;
    init_geometry();
}

TOHangceilingCave01Key::~TOHangceilingCave01Key() {
}

void TOHangceilingCave01Key::vfunc_80() {
    switch (mode) {
    case 3:
        if (is_current_floor_switch_set((u16)switch_id) == 1 && frame <= frame_count) {
            sub_801682E4(2);
        }
        advance_wrap_offset();
        break;
    case 1:
        advance_wrap_offset();
        sub_80168488();
        if (4.0f == frame) {
            bodies->flags &= ~8;
        } else if (23.0f == frame) {
            vfunc_79();
            clear_current_floor_switch((u16)switch_id);
        }
        break;
    case 2:
        advance_wrap_offset();
        if (50.0f == frame) {
            bodies->flags |= hang_flag_8;
        } else if (frame == frame_count) {
            sub_801682E4(1);
        }
        break;
    }
}

void TOHangceilingCave01Key::vfunc_79() {
    texlist = turiten_singo_texture_lists[1];
    current_motion = (NJS_MOTION *)get_bml_motion(TOHangceilingCave01__model_archive, 1);
    m_354 = 0.0f;
    sub_801682E4(3);
    bodies->flags &= ~8;
    frame = 0.0f;
    play_speed = 1.0f;
    frame_count = (f32)current_motion->nbFrame - 1.0f;
    reset_state();
}

TOHangceilingCave01KeyQuick::TOHangceilingCave01KeyQuick(TObject *parent, void *set_data)
    : TUnk_804B2578(parent, set_data) {
    m_name = TOHangceilingCave01KeyQuick__class_name;
    init_geometry();
    set_scale(100.0f + scale.z);
}

TOHangceilingCave01KeyQuick::~TOHangceilingCave01KeyQuick() {
}

void TOHangceilingCave01KeyQuick::vfunc_80() {
    switch (mode) {
    case 3:
        if (is_current_floor_switch_set((u16)switch_id) == 1 && frame <= frame_count) {
            sub_801682E4(2);
        }
        advance_wrap_offset();
        return;
    case 1:
        advance_wrap_offset();
        sub_80168488();
        if (4.0f < frame) {
            bodies->flags &= ~8;
        }
        if (23.0f == frame) {
            vfunc_79();
        }
        break;
    case 2:
        if (is_current_floor_switch_set((u16)switch_id) == 1) {
            if (0.0f != frame) {
                advance_wrap_offset();
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
            sub_801682E4(1);
        }
        break;
    }
}

void TOHangceilingCave01KeyQuick::vfunc_79() {
    texlist = turiten_singo_texture_lists[1];
    current_motion = (NJS_MOTION *)get_bml_motion(TOHangceilingCave01__model_archive, 1);
    m_354 = 0.0f;
    sub_801682E4(3);
    bodies->flags &= ~8;
    frame = 0.0f;
    play_speed = 1.0f;
    frame_count = (f32)current_motion->nbFrame - 1.0f;
    reset_state();
}
