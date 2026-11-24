#include "pso/system/memory.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/map/FloorArea.h"
#include "pso/map/TMapCsnCtrl.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/BmlResource.h"
#include "pso/object/city/CityTraffic.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaTexture.h"
#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/object/city/CityDoors.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/vector.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/challenge/TChallenge.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/TUnk_804B5C08.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/TUnk_804B5BA8.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/city/TObjCityDoor_Shop.h"
#include "pso/object/city/TObjCityDoor_Guild.h"
#include "pso/object/warp/TObjCityDoor_Warp.h"
#include "pso/object/city/TObjCityDoor_Med.h"
#include "pso/object/lobby/TObjCityDoor_Lobby.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/PlayerSlots.h"

extern const char city_door_asset_de_obj_bigbeam_gj[];
__declspec(section ".rodata") const char city_door_asset_de_obj_bigbeam_gj[] ATTRIBUTE_ALIGN(4) = "de_obj_bigbeam.gj";
extern const char city_door_asset_de_obj_citybeam_gj[];
__declspec(section ".rodata") const char city_door_asset_de_obj_citybeam_gj[] ATTRIBUTE_ALIGN(4) = "de_obj_citybeam.gj";
extern const char city_door_asset_de_obj_o_aircar02_light_gj[];
__declspec(section ".rodata") const char city_door_asset_de_obj_o_aircar02_light_gj[] ATTRIBUTE_ALIGN(4) = "de_obj_o_aircar02_light.gj";
extern const char city_door_asset_de_obj_smallbeam_gj[];
__declspec(section ".rodata") const char city_door_asset_de_obj_smallbeam_gj[] ATTRIBUTE_ALIGN(4) = "de_obj_smallbeam.gj";
extern const char city_door_asset_ds_obj_o_aircar01_light_gj[];
__declspec(section ".rodata") const char city_door_asset_ds_obj_o_aircar01_light_gj[] ATTRIBUTE_ALIGN(4) = "ds_obj_o_aircar01_light.gj";
extern const char city_door_asset_ds_obj_o_aircar03_light_gj[];
__declspec(section ".rodata") const char city_door_asset_ds_obj_o_aircar03_light_gj[] ATTRIBUTE_ALIGN(4) = "ds_obj_o_aircar03_light.gj";
extern const char city_door_asset_ds_obj_o_aircar04_light_gj[];
__declspec(section ".rodata") const char city_door_asset_ds_obj_o_aircar04_light_gj[] ATTRIBUTE_ALIGN(4) = "ds_obj_o_aircar04_light.gj";
extern const char city_door_asset_ds_obj_o_aircar05_light_gj[];
__declspec(section ".rodata") const char city_door_asset_ds_obj_o_aircar05_light_gj[] ATTRIBUTE_ALIGN(4) = "ds_obj_o_aircar05_light.gj";
extern const char city_door_asset_fd_obj_n_elv_bmerge4_gj[];
__declspec(section ".rodata") const char city_door_asset_fd_obj_n_elv_bmerge4_gj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_elv_bmerge4.gj";
extern const char city_door_asset_fd_obj_n_tobira_shut_sita_gj[];
__declspec(section ".rodata") const char city_door_asset_fd_obj_n_tobira_shut_sita_gj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tobira_shut_sita.gj";
extern const char city_door_asset_fd_obj_n_tobira_shut_ue_gj[];
__declspec(section ".rodata") const char city_door_asset_fd_obj_n_tobira_shut_ue_gj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tobira_shut_ue.gj";
extern const char city_door_asset_fd_obj_shopdoor_01_gj[];
__declspec(section ".rodata") const char city_door_asset_fd_obj_shopdoor_01_gj[] ATTRIBUTE_ALIGN(4) = "fd_obj_shopdoor_01.gj";
extern const char city_door_asset_fd_obj_warp_big_gj[];
__declspec(section ".rodata") const char city_door_asset_fd_obj_warp_big_gj[] ATTRIBUTE_ALIGN(4) = "fd_obj_warp_big.gj";
extern const char city_door_asset_fd_obj_warp_small_gj[];
__declspec(section ".rodata") const char city_door_asset_fd_obj_warp_small_gj[] ATTRIBUTE_ALIGN(4) = "fd_obj_warp_small.gj";
extern const char city_door_asset_fe_hntdoor_fusagi_gj[];
__declspec(section ".rodata") const char city_door_asset_fe_hntdoor_fusagi_gj[] ATTRIBUTE_ALIGN(4) = "fe_hntdoor_fusagi.gj";
extern const char city_door_asset_fe_obj_o_aircar01_nj[];
__declspec(section ".rodata") const char city_door_asset_fe_obj_o_aircar01_nj[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_aircar01.nj";
extern const char city_door_asset_fe_obj_o_aircar02_nj[];
__declspec(section ".rodata") const char city_door_asset_fe_obj_o_aircar02_nj[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_aircar02.nj";
extern const char city_door_asset_fe_obj_o_aircar03_nj[];
__declspec(section ".rodata") const char city_door_asset_fe_obj_o_aircar03_nj[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_aircar03.nj";
extern const char city_door_asset_fe_obj_o_aircar04_nj[];
__declspec(section ".rodata") const char city_door_asset_fe_obj_o_aircar04_nj[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_aircar04.nj";
extern const char city_door_asset_fe_obj_o_aircar05_nj[];
__declspec(section ".rodata") const char city_door_asset_fe_obj_o_aircar05_nj[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_aircar05.nj";
extern const char city_door_asset_fe_obj_o_medical_door01l_gj[];
__declspec(section ".rodata") const char city_door_asset_fe_obj_o_medical_door01l_gj[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_medical_door01l.gj";
extern const char city_door_asset_hunter_door_gj[];
__declspec(section ".rodata") const char city_door_asset_hunter_door_gj[] ATTRIBUTE_ALIGN(4) = "hunter_door.gj";
extern const char city_door_asset_aircar_path1_njm[];
__declspec(section ".rodata") const char city_door_asset_aircar_path1_njm[] ATTRIBUTE_ALIGN(4) = "aircar_path1.njm";
extern const char city_door_asset_aircar_path2_njm[];
__declspec(section ".rodata") const char city_door_asset_aircar_path2_njm[] ATTRIBUTE_ALIGN(4) = "aircar_path2.njm";
extern const char city_door_asset_aircar_path3_njm[];
__declspec(section ".rodata") const char city_door_asset_aircar_path3_njm[] ATTRIBUTE_ALIGN(4) = "aircar_path3.njm";
extern const char city_door_asset_aircar_path4_njm[];
__declspec(section ".rodata") const char city_door_asset_aircar_path4_njm[] ATTRIBUTE_ALIGN(4) = "aircar_path4.njm";
extern const char city_door_asset_aircar_path5_njm[];
__declspec(section ".rodata") const char city_door_asset_aircar_path5_njm[] ATTRIBUTE_ALIGN(4) = "aircar_path5.njm";
extern const char city_door_asset_de_obj_bigbeam_njm[];
__declspec(section ".rodata") const char city_door_asset_de_obj_bigbeam_njm[] ATTRIBUTE_ALIGN(4) = "de_obj_bigbeam.njm";
extern const char city_door_asset_de_obj_citybeam_njm[];
__declspec(section ".rodata") const char city_door_asset_de_obj_citybeam_njm[] ATTRIBUTE_ALIGN(4) = "de_obj_citybeam.njm";
extern const char city_door_asset_de_obj_smallbeam_njm[];
__declspec(section ".rodata") const char city_door_asset_de_obj_smallbeam_njm[] ATTRIBUTE_ALIGN(4) = "de_obj_smallbeam.njm";
extern const char city_door_asset_fd_obj_n_tobira_shut_sita_njm[];
__declspec(section ".rodata") const char city_door_asset_fd_obj_n_tobira_shut_sita_njm[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tobira_shut_sita.njm";
extern const char city_door_asset_fd_obj_n_tobira_shut_ue_njm[];
__declspec(section ".rodata") const char city_door_asset_fd_obj_n_tobira_shut_ue_njm[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tobira_shut_ue.njm";
extern const char city_door_asset_fd_obj_shopdoor_01_njm[];
__declspec(section ".rodata") const char city_door_asset_fd_obj_shopdoor_01_njm[] ATTRIBUTE_ALIGN(4) = "fd_obj_shopdoor_01.njm";
extern const char city_door_asset_fe_obj_o_medical_door01l_njm[];
__declspec(section ".rodata") const char city_door_asset_fe_obj_o_medical_door01l_njm[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_medical_door01l.njm";
extern const char city_door_asset_hunter_door_njm[];
__declspec(section ".rodata") const char city_door_asset_hunter_door_njm[] ATTRIBUTE_ALIGN(4) = "hunter_door.njm";
extern const char city_common_model_archive_filename[];
__declspec(section ".rodata") const char city_common_model_archive_filename[] ATTRIBUTE_ALIGN(4) = "bm_obj_city_common.bml";
extern const char city_common_texture_filename[];
__declspec(section ".rodata") const char city_common_texture_filename[] ATTRIBUTE_ALIGN(4) = "bm_obj_city_common.GVM";
__declspec(section ".rodata") CollisionBody city_door_init_params ATTRIBUTE_ALIGN(8) = {{0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};
__declspec(section ".rodata") CityDoorParams TObjCityDoor_Shop__params = {1.0f, 3600.0f, 6400.0f, 2.0f, 25.0f, 800.0f, 30.0f};
__declspec(section ".rodata") CityDoorParams TObjCityDoor_Guild__params = {2.0f, 3600.0f, 6400.0f, 2.0f, 24.0f, 800.0f, 30.0f};
__declspec(section ".rodata") CityDoorParams city_door_warp_params = {1.0f, 8100.0f, 14400.0f, 50.0f, 6.5f, 800.0f, 70.0f};
__declspec(section ".rodata") CityDoorParams city_door_med_params = {1.0f, 3600.0f, 6400.0f, 4.0f, 25.0f, 800.0f, 30.0f};
__declspec(section ".rodata") Vec city_door_lobby_collision_vertices[] = {{-14.0f, 0.0f, -38.0f}, {-14.0f, 40.0f, -38.0f}, {-10.0f, 0.0f, -12.0f}, {-10.0f, 40.0f, -12.0f}, {-2.0f, 0.0f, 2.0f}, {-2.0f, 40.0f, 2.0f}, {12.0f, 0.0f, 12.0f}, {12.0f, 40.0f, 12.0f}, {38.0f, 0.0f, 16.0f}, {38.0f, 40.0f, 16.0f}};
extern const u16 city_door_lobby_quad_triangle_indices[];
__declspec(section ".rodata") const u16 city_door_lobby_quad_triangle_indices[] = {1, 0, 3, 3, 0, 2};
extern const char TObjCityDoor_Shop__class_name[];
__declspec(section ".rodata") const char TObjCityDoor_Shop__class_name[] ATTRIBUTE_ALIGN(4) = "TObjCityDoor_Shop";
extern const char TObjCityDoor_Guild__class_name[];
__declspec(section ".rodata") const char TObjCityDoor_Guild__class_name[] ATTRIBUTE_ALIGN(4) = "TObjCityDoor_Guild";
extern const char TObjCityDoor_Warp__class_name[];
__declspec(section ".rodata") const char TObjCityDoor_Warp__class_name[] ATTRIBUTE_ALIGN(4) = "TObjCityDoor_Warp";
extern const char TObjCityDoor_Med__class_name[];
__declspec(section ".rodata") const char TObjCityDoor_Med__class_name[] ATTRIBUTE_ALIGN(4) = "TObjCityDoor_Med";
extern const char TObjCityDoor_Lobby__class_name[];
__declspec(section ".rodata") const char TObjCityDoor_Lobby__class_name[] ATTRIBUTE_ALIGN(4) = "TObjCityDoor_Lobby";

struct CityDoorClassTag { const char *value; u32 padding; };
__declspec(section ".sdata") extern const char *TObjCityDoor_Shop__name;
__declspec(section ".sdata") extern const char *TObjCityDoor_Guild__name;
__declspec(section ".sdata") extern const char *TObjCityDoor_Warp__name;
__declspec(section ".sdata") extern const char *TObjCityDoor_Med__name;
__declspec(section ".sdata") extern CityDoorClassTag TObjCityDoor_Lobby__name;

struct BmObjCityCommonResourceDescriptor {
    BmlResourceDescriptor archive;
    u32 padding;
};
extern BmObjCityCommonResourceDescriptor bm_obj_city_common_resource_descriptor;
void load_city_common_resources(void);

extern "C" s32 TLobby__sub_80182E60(void) {
    if (challenge_task == NULL) {
        return -1;
    }
    return challenge_task->state;
}

TUnk_804B5BA8::TUnk_804B5BA8(TObject *parent, void *set, const CityDoorParams *params)
    : TObjCollidable(parent) {
    apply_object_set_data(set);
    phase = 0;
    end_frame = 0.0f;
    frame = 0.0f;
    this->params = params;
    CollisionBody body = city_door_init_params;
    body.radius = this->params->body_radius;
    body.half_width = this->params->body_half_width;
    init_collision_body_parts(this, &body, 1);
    register_object_by_id();
}

TUnk_804B5BA8::~TUnk_804B5BA8() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

s32 TUnk_804B5BA8::check_player_in_range(f32 range_sq) {
    return is_any_city_player_in_range(&position, range_sq);
}

s32 TUnk_804B5BA8::is_any_city_player_in_range(const Vec *center, f32 range_squared) {
    TObjPlayer *player;
    s32 area;
    s32 client;

    client = 0;
loop_1:
    player = get_player_by_client_id(client);
    if ((player != 0) && ((area = player->get_area(), ((area == AREA_PIONEER2_EP1) != 0)) || (area == AREA_PIONEER2_EP2)) && (horizontal_distance_squared(center, &player->position) < range_squared)) {
        return 1;
    }
    client += 1;
    if (client >= 4) {
        return 0;
    }
    goto loop_1;
}

void TUnk_804B5BA8::begin_state_1() {
    if (check_player_in_range(params->open_range_sq) != 0) {
        phase = 1;
        city_door_play_open_sound();
        bodies->flags &= ~1;
    }
}

void TUnk_804B5BA8::city_door_tick_opening() {
    if (check_player_in_range(params->close_range_sq) == 0) {
        phase = 3;
        city_door_play_close_sound();
        return;
    }
    frame = frame + params->speed;
    if (frame >= end_frame) {
        frame = end_frame;
        phase = 2;
    }
}

#pragma push
#pragma opt_common_subs off
void TUnk_804B5BA8::city_door_tick_closing() {
    if (check_player_in_range(params->open_range_sq) != 0) {
        phase = 1;
        city_door_play_open_sound();
    } else {
        frame -= params->speed;
        if (frame <= 0.0f) {
            frame = 0.0f;
            phase = 0;
            bodies->flags |= 1;
        }
    }
}
#pragma pop

void TUnk_804B5BA8::check_ground_or_fall() {
    if (check_player_in_range(params->close_range_sq) == 0) {
        phase = 3;
        city_door_play_close_sound();
    }
}

void TUnk_804B5BA8::city_door_play_close_sound() {
    play_sound_effect(0x42A05, &position, 0, 0);
}

void TUnk_804B5BA8::city_door_play_open_sound() {
    play_sound_effect(0x42A04, &position, 0, 0);
}

void TUnk_804B5BA8::dispatch_state() {
    switch (phase) {
    case 0:
        begin_state_1();
        return;
    case 1:
        city_door_tick_opening();
        return;
    case 2:
        check_ground_or_fall();
        return;
    case 3:
        city_door_tick_closing();
        return;
    }
}

s32 TUnk_804B5BA8::vfunc_22() {
    return update_object_view_visibility(params->view_far_depth, params->view_radius);
}

TObjCityDoor_Shop::TObjCityDoor_Shop(TObject *parent, void *set)
    : TUnk_804B5BA8(parent, set, &TObjCityDoor_Shop__params) {
    m_name = TObjCityDoor_Shop__name;
    end_frame = city_common_model_archive->motions[10].motion->frameCount - 1;
}

TObjCityDoor_Shop::~TObjCityDoor_Shop() {
}

void *TObjCityDoor_Shop::create(void *set) {
    return new TObjCityDoor_Shop(tl_05, set);
}

void TObjCityDoor_Shop::run_task() {
    dispatch_state();
}

void TObjCityDoor_Shop::render() {
    if (vfunc_22() != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(city_common_texture_list));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        draw_ginja_model_with_motion(city_common_model_archive->models[11].model, city_common_model_archive->motions[10].motion, frame);
        pop_matrix();
    }
}

TObjCityDoor_Guild::TObjCityDoor_Guild(TObject *parent, void *set)
    : TUnk_804B5BA8(parent, set, &TObjCityDoor_Guild__params) {
    m_name = TObjCityDoor_Guild__name;
    end_frame = get_city_common_motion(12)->frameCount - 1;
}

TObjCityDoor_Guild::~TObjCityDoor_Guild() {
}

void *TObjCityDoor_Guild::create(void *set) {
    return new TObjCityDoor_Guild(tl_05, set);
}

void TObjCityDoor_Guild::run_task() {
    dispatch_state();
}

void TObjCityDoor_Guild::render() {
    if (vfunc_22() != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(city_common_texture_list));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        draw_ginja_model_with_motion(get_city_common_model(0x15), get_city_common_motion(0xC), frame);
        pop_matrix();
    }
}

TObjCityDoor_Warp::TObjCityDoor_Warp(TObject *parent, void *set)
    : TUnk_804B5BA8(parent, set, &city_door_warp_params) {
    m_name = TObjCityDoor_Warp__name;
    end_frame = get_city_common_motion(8)->frameCount - 1;
}

TObjCityDoor_Warp::~TObjCityDoor_Warp() {
}

void *TObjCityDoor_Warp::create(void *set) {
    return new TObjCityDoor_Warp(tl_05, set);
}

void TObjCityDoor_Warp::city_door_tick_opening() {
    if (frame >= 24.0f && frame <= 25.0f) {
        set_sound_pitch_request(play_sound_effect(0x42A04, &position, 0, 0), -0x500, 0);
    }
    TUnk_804B5BA8::city_door_tick_opening();
}

void TObjCityDoor_Warp::city_door_play_open_sound() {
    if (is_rader_map_active() != 0) {
        set_sound_pitch_request(play_sound_effect(0x42A04, &position, 0, 0), -0x800, 0);
    }
}

void TObjCityDoor_Warp::city_door_play_close_sound() {
    set_sound_pitch_request(play_sound_effect(0x42A05, &position, 0, 0), -0x500, 0);
}

void TObjCityDoor_Warp::run_task() {
    if (is_rader_map_active() == 0) {
        phase = 0;
    }
    dispatch_state();
    if (is_rader_map_active() == 0) {
        bodies->flags |= 1;
    }
}

void TObjCityDoor_Warp::render() {
    if (vfunc_22() != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(city_common_texture_list));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        draw_ginja_model_with_motion(get_city_common_model(9), get_city_common_motion(8), frame);
        draw_ginja_model_with_motion(get_city_common_model(10), get_city_common_motion(9), frame);
        pop_matrix();
    }
}

s32 TObjCityDoor_Warp::is_rader_map_active() {
    saddr stage;

    if (TRaderMapCore::is_not_split_screen() == 1) {
        if (get_game_play_mode() == 1) {
            return 0;
        }
        goto block_6;
    }
    stage = TLobby__sub_80182E60();
    if ((stage != -1) && (stage == 1)) {
        return 0;
    }
block_6:
    return 1;
}

TObjCityDoor_Med::TObjCityDoor_Med(TObject *parent, void *set)
    : TUnk_804B5BA8(parent, set, &city_door_med_params) {
    m_name = TObjCityDoor_Med__name;
    end_frame = get_city_common_motion(11)->frameCount - 1;
}

TObjCityDoor_Med::~TObjCityDoor_Med() {
}

void *TObjCityDoor_Med::create(void *set) {
    return new TObjCityDoor_Med(tl_05, set);
}

void TObjCityDoor_Med::run_task() {
    dispatch_state();
}

void TObjCityDoor_Med::render() {
    if (vfunc_22() != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(city_common_texture_list));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        translate_matrix(0, 0.0f, 0.0f, -80.0f);
        draw_ginja_model_with_motion(get_city_common_model(0x14), get_city_common_motion(0xB), frame);
        pop_matrix();
    }
}

TObjCityDoor_Lobby::TObjCityDoor_Lobby(TObject *parent, void *set) : TObjBase(parent) {
    m_name = TObjCityDoor_Lobby__name.value;
    apply_object_set_data(set);
    collision_group.model = &collision_model;
    VecCopy(&collision_group.center, &position);
    collision_group.radius = 2000.0f;
    collision_group.flags = 0xDE0;
    collision_model.face_count = 8;
    collision_model.faces = collision_faces;
    collision_model.vertex_count = 10;
    collision_model.vertices = collision_vertices;
    collision_registered = 0;
    if (check_phase_e(this) != 0) {
        build_door_collision_triangles();
        if (TObjMapCsn::get_collision_controller() != NULL) {
            register_slot(TObjMapCsn::get_collision_controller(), &collision_group);
            collision_registered = 1;
        }
    }
}

TObjCityDoor_Lobby::~TObjCityDoor_Lobby() {
    if (collision_registered != 0 && TObjMapCsn::get_collision_controller() != NULL) {
        remove_collision_group(TObjMapCsn::get_collision_controller(), &collision_group);
    }
}

void *TObjCityDoor_Lobby::create(void *set) {
    if (is_split_screen() != 0) {
        return NULL;
    }
    return new TObjCityDoor_Lobby(tl_05, set);
}

extern "C" int check_phase_e(void *) {
    return TObjEneDD::is_phase_e();
}

#pragma push
#pragma fp_contract on

void TObjCityDoor_Lobby::build_door_collision_triangles() {
    Vec v[3];
    Vec sum;
    CsnFace *t1;
    CsnFace *t;
    s32 m;
    s32 k;
    s32 j;
    s32 i;
    f32 three;
    f32 zero;

    VecCopy(&collision_group.center, &position);
    push_matrix();
    set_matrix_identity(0);
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    t1 = collision_faces;
    j = 0;
    for (i = 0; i < 4; i++) {
        t1[0].vertex[0] = j + city_door_lobby_quad_triangle_indices[0];
        t1[0].vertex[1] = j + city_door_lobby_quad_triangle_indices[1];
        t1[0].vertex[2] = j + city_door_lobby_quad_triangle_indices[2];
        VecCopy(&v[0], &city_door_lobby_collision_vertices[t1[0].vertex[0]]);
        VecCopy(&v[1], &city_door_lobby_collision_vertices[t1[0].vertex[1]]);
        VecCopy(&v[2], &city_door_lobby_collision_vertices[t1[0].vertex[2]]);
        calc_triangle_normal(v, &t1[0].normal);
        t1[1].vertex[0] = j + city_door_lobby_quad_triangle_indices[3];
        t1[1].vertex[1] = j + city_door_lobby_quad_triangle_indices[4];
        t1[1].vertex[2] = j + city_door_lobby_quad_triangle_indices[5];
        VecCopy(&v[0], &city_door_lobby_collision_vertices[t1[1].vertex[0]]);
        VecCopy(&v[1], &city_door_lobby_collision_vertices[t1[1].vertex[1]]);
        VecCopy(&v[2], &city_door_lobby_collision_vertices[t1[1].vertex[2]]);
        calc_triangle_normal(v, &t1[1].normal);
        t1 += 2;
        j += 2;
    }
    matrix_mult_vec_array(NULL, city_door_lobby_collision_vertices, collision_vertices, 10);
    zero = 0.0f;
    t = collision_faces;
    three = 3.0f;
    for (m = 0; m < 8; m++, t++) {
        f32 dz;
        f32 dx;
        sum.x = zero;
        sum.y = zero;
        sum.z = zero;
        for (k = 0; k < 3; k++) {
            vec3_add_to(&sum, &collision_vertices[t->vertex[k]]);
        }
        sum.x /= three;
        sum.y /= three;
        sum.z /= three;
        VecCopy(&t->center, &sum);
        dx = collision_vertices[t->vertex[0]].x - sum.x;
        dz = collision_vertices[t->vertex[0]].z - sum.z;
        t->radius = newton_sqrtf(dx * dx + dz * dz);
        t->flags = 0xDE0;
    }
    pop_matrix();
}
#pragma pop

void TObjCityDoor_Lobby::dispatch_lobby_action() {
    if (check_phase_e(this) != 0) {
        build_door_collision_triangles();
        return;
    }
    process_lobby_action_14();
}

void TObjCityDoor_Lobby::run_task() {
}

void TObjCityDoor_Lobby::process_lobby_action_14() {
    if (update_object_view_visibility(400.0f, 70.0f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(city_common_texture_list));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        draw_ginja_object(get_city_common_model(0xE));
        pop_matrix();
    }
}

void TObjCityDoor_Lobby::render() {
    if (check_phase_e(this) != 0) {
        process_lobby_action_14();
    }
}

void load_city_common_resources(void) {
    BmlResource *resource = new BmlResource(5, (BmlResourceDescriptor *)&bm_obj_city_common_resource_descriptor.archive, 0, 0, NULL);
    city_common_model_archive = resource;
    city_common_texture_list = load_gvm_texture_file(city_common_texture_filename);
}

void TLobby::free_map_resources() {
    if (city_common_texture_list != NULL) {
        release_texture_list(city_common_texture_list);
        safe_free(city_common_texture_list);
        city_common_texture_list = NULL;
    }
    delete (BmlResource *)city_common_model_archive;
    city_common_model_archive = NULL;
}

const char *bm_obj_city_common_model_names[] = {city_door_asset_de_obj_bigbeam_gj, city_door_asset_de_obj_citybeam_gj, city_door_asset_de_obj_o_aircar02_light_gj, city_door_asset_de_obj_smallbeam_gj, city_door_asset_ds_obj_o_aircar01_light_gj, city_door_asset_ds_obj_o_aircar03_light_gj, city_door_asset_ds_obj_o_aircar04_light_gj, city_door_asset_ds_obj_o_aircar05_light_gj, city_door_asset_fd_obj_n_elv_bmerge4_gj, city_door_asset_fd_obj_n_tobira_shut_sita_gj, city_door_asset_fd_obj_n_tobira_shut_ue_gj, city_door_asset_fd_obj_shopdoor_01_gj, city_door_asset_fd_obj_warp_big_gj, city_door_asset_fd_obj_warp_small_gj, city_door_asset_fe_hntdoor_fusagi_gj, city_door_asset_fe_obj_o_aircar01_nj, city_door_asset_fe_obj_o_aircar02_nj, city_door_asset_fe_obj_o_aircar03_nj, city_door_asset_fe_obj_o_aircar04_nj, city_door_asset_fe_obj_o_aircar05_nj, city_door_asset_fe_obj_o_medical_door01l_gj, city_door_asset_hunter_door_gj, 0};
const char *bm_obj_city_common_motion_names[] = {city_door_asset_aircar_path1_njm, city_door_asset_aircar_path2_njm, city_door_asset_aircar_path3_njm, city_door_asset_aircar_path4_njm, city_door_asset_aircar_path5_njm, city_door_asset_de_obj_bigbeam_njm, city_door_asset_de_obj_citybeam_njm, city_door_asset_de_obj_smallbeam_njm, city_door_asset_fd_obj_n_tobira_shut_sita_njm, city_door_asset_fd_obj_n_tobira_shut_ue_njm, city_door_asset_fd_obj_shopdoor_01_njm, city_door_asset_fe_obj_o_medical_door01l_njm, city_door_asset_hunter_door_njm, 0};
BmObjCityCommonResourceDescriptor bm_obj_city_common_resource_descriptor = {{city_common_model_archive_filename, bm_obj_city_common_model_names, bm_obj_city_common_motion_names, 22, 13}, 0};
__declspec(section ".sdata") const char *TObjCityDoor_Shop__name = TObjCityDoor_Shop__class_name;
__declspec(section ".sdata") const char *TObjCityDoor_Guild__name = TObjCityDoor_Guild__class_name;
__declspec(section ".sdata") const char *TObjCityDoor_Warp__name = TObjCityDoor_Warp__class_name;
__declspec(section ".sdata") const char *TObjCityDoor_Med__name = TObjCityDoor_Med__class_name;
__declspec(section ".sdata") CityDoorClassTag TObjCityDoor_Lobby__name = {TObjCityDoor_Lobby__class_name, 0};
