#include "pso/system/memory.h"
#include "pso/player/PlayerCommands.h"
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
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/TChallenge.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/TextureState.h"
#include "pso/object/TObjCityVerticalModel.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/TObjCityDoorBase.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/city/TObjCityDoor_Shop.h"
#include "pso/object/city/TObjCityDoor_Guild.h"
#include "pso/object/warp/TObjCityDoor_Warp.h"
#include "pso/object/city/TObjCityDoor_Med.h"
#include "pso/object/lobby/TObjCityDoor_Lobby.h"
#include "pso/math/MatrixReflect.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixVector.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/audio/SoundRequests.h"
#include "pso/render/DebugFont.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/GameModeQueries.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/player/PlayerSlots.h"

__declspec(section ".rodata") extern const char city_door_asset_de_obj_bigbeam_gj[] ATTRIBUTE_ALIGN(4) = "de_obj_bigbeam.gj";
__declspec(section ".rodata") extern const char city_door_asset_de_obj_citybeam_gj[] ATTRIBUTE_ALIGN(4) = "de_obj_citybeam.gj";
__declspec(section ".rodata") extern const char city_door_asset_de_obj_o_aircar02_light_gj[] ATTRIBUTE_ALIGN(4) = "de_obj_o_aircar02_light.gj";
__declspec(section ".rodata") extern const char city_door_asset_de_obj_smallbeam_gj[] ATTRIBUTE_ALIGN(4) = "de_obj_smallbeam.gj";
__declspec(section ".rodata") extern const char city_door_asset_ds_obj_o_aircar01_light_gj[] ATTRIBUTE_ALIGN(4) = "ds_obj_o_aircar01_light.gj";
__declspec(section ".rodata") extern const char city_door_asset_ds_obj_o_aircar03_light_gj[] ATTRIBUTE_ALIGN(4) = "ds_obj_o_aircar03_light.gj";
__declspec(section ".rodata") extern const char city_door_asset_ds_obj_o_aircar04_light_gj[] ATTRIBUTE_ALIGN(4) = "ds_obj_o_aircar04_light.gj";
__declspec(section ".rodata") extern const char city_door_asset_ds_obj_o_aircar05_light_gj[] ATTRIBUTE_ALIGN(4) = "ds_obj_o_aircar05_light.gj";
__declspec(section ".rodata") extern const char city_door_asset_fd_obj_n_elv_bmerge4_gj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_elv_bmerge4.gj";
__declspec(section ".rodata") extern const char city_door_asset_fd_obj_n_tobira_shut_sita_gj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tobira_shut_sita.gj";
__declspec(section ".rodata") extern const char city_door_asset_fd_obj_n_tobira_shut_ue_gj[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tobira_shut_ue.gj";
__declspec(section ".rodata") extern const char city_door_asset_fd_obj_shopdoor_01_gj[] ATTRIBUTE_ALIGN(4) = "fd_obj_shopdoor_01.gj";
__declspec(section ".rodata") extern const char city_door_asset_fd_obj_warp_big_gj[] ATTRIBUTE_ALIGN(4) = "fd_obj_warp_big.gj";
__declspec(section ".rodata") extern const char city_door_asset_fd_obj_warp_small_gj[] ATTRIBUTE_ALIGN(4) = "fd_obj_warp_small.gj";
__declspec(section ".rodata") extern const char city_door_asset_fe_hntdoor_fusagi_gj[] ATTRIBUTE_ALIGN(4) = "fe_hntdoor_fusagi.gj";
__declspec(section ".rodata") extern const char city_door_asset_fe_obj_o_aircar01_nj[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_aircar01.nj";
__declspec(section ".rodata") extern const char city_door_asset_fe_obj_o_aircar02_nj[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_aircar02.nj";
__declspec(section ".rodata") extern const char city_door_asset_fe_obj_o_aircar03_nj[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_aircar03.nj";
__declspec(section ".rodata") extern const char city_door_asset_fe_obj_o_aircar04_nj[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_aircar04.nj";
__declspec(section ".rodata") extern const char city_door_asset_fe_obj_o_aircar05_nj[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_aircar05.nj";
__declspec(section ".rodata") extern const char city_door_asset_fe_obj_o_medical_door01l_gj[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_medical_door01l.gj";
__declspec(section ".rodata") extern const char city_door_asset_hunter_door_gj[] ATTRIBUTE_ALIGN(4) = "hunter_door.gj";
__declspec(section ".rodata") extern const char city_door_asset_aircar_path1_njm[] ATTRIBUTE_ALIGN(4) = "aircar_path1.njm";
__declspec(section ".rodata") extern const char city_door_asset_aircar_path2_njm[] ATTRIBUTE_ALIGN(4) = "aircar_path2.njm";
__declspec(section ".rodata") extern const char city_door_asset_aircar_path3_njm[] ATTRIBUTE_ALIGN(4) = "aircar_path3.njm";
__declspec(section ".rodata") extern const char city_door_asset_aircar_path4_njm[] ATTRIBUTE_ALIGN(4) = "aircar_path4.njm";
__declspec(section ".rodata") extern const char city_door_asset_aircar_path5_njm[] ATTRIBUTE_ALIGN(4) = "aircar_path5.njm";
__declspec(section ".rodata") extern const char city_door_asset_de_obj_bigbeam_njm[] ATTRIBUTE_ALIGN(4) = "de_obj_bigbeam.njm";
__declspec(section ".rodata") extern const char city_door_asset_de_obj_citybeam_njm[] ATTRIBUTE_ALIGN(4) = "de_obj_citybeam.njm";
__declspec(section ".rodata") extern const char city_door_asset_de_obj_smallbeam_njm[] ATTRIBUTE_ALIGN(4) = "de_obj_smallbeam.njm";
__declspec(section ".rodata") extern const char city_door_asset_fd_obj_n_tobira_shut_sita_njm[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tobira_shut_sita.njm";
__declspec(section ".rodata") extern const char city_door_asset_fd_obj_n_tobira_shut_ue_njm[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tobira_shut_ue.njm";
__declspec(section ".rodata") extern const char city_door_asset_fd_obj_shopdoor_01_njm[] ATTRIBUTE_ALIGN(4) = "fd_obj_shopdoor_01.njm";
__declspec(section ".rodata") extern const char city_door_asset_fe_obj_o_medical_door01l_njm[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_medical_door01l.njm";
__declspec(section ".rodata") extern const char city_door_asset_hunter_door_njm[] ATTRIBUTE_ALIGN(4) = "hunter_door.njm";
__declspec(section ".rodata") extern const char city_common_model_archive_filename[] ATTRIBUTE_ALIGN(4) = "bm_obj_city_common.bml";
__declspec(section ".rodata") extern const char city_common_texture_filename[] ATTRIBUTE_ALIGN(4) = "bm_obj_city_common.GVM";
__declspec(section ".rodata") CollisionBody city_door_init_params ATTRIBUTE_ALIGN(8) = {{0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};
__declspec(section ".rodata") CityDoorParams city_door_shop_params = {1.0f, 3600.0f, 6400.0f, 2.0f, 25.0f, 800.0f, 30.0f};
__declspec(section ".rodata") CityDoorParams city_door_guild_params = {2.0f, 3600.0f, 6400.0f, 2.0f, 24.0f, 800.0f, 30.0f};
__declspec(section ".rodata") CityDoorParams city_door_warp_params = {1.0f, 8100.0f, 14400.0f, 50.0f, 6.5f, 800.0f, 70.0f};
__declspec(section ".rodata") CityDoorParams city_door_med_params = {1.0f, 3600.0f, 6400.0f, 4.0f, 25.0f, 800.0f, 30.0f};
__declspec(section ".rodata") Vec city_door_lobby_collision_vertices[] = {{-14.0f, 0.0f, -38.0f}, {-14.0f, 40.0f, -38.0f}, {-10.0f, 0.0f, -12.0f}, {-10.0f, 40.0f, -12.0f}, {-2.0f, 0.0f, 2.0f}, {-2.0f, 40.0f, 2.0f}, {12.0f, 0.0f, 12.0f}, {12.0f, 40.0f, 12.0f}, {38.0f, 0.0f, 16.0f}, {38.0f, 40.0f, 16.0f}};
__declspec(section ".rodata") extern const u16 city_door_lobby_quad_triangle_indices[] = {1, 0, 3, 3, 0, 2};

struct BmObjCityCommonResourceDescriptor {
    BmlResourceDescriptor archive;
    u32 padding;
};
extern BmObjCityCommonResourceDescriptor bm_obj_city_common_resource_descriptor;
void load_city_common_resources(void);

s32 get_challenge_state() {
    if (challenge_task == NULL) {
        return -1;
    }
    return challenge_task->state;
}

TObjCityDoorBase::TObjCityDoorBase(TObject *parent, void *set, const CityDoorParams *params)
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

TObjCityDoorBase::~TObjCityDoorBase() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

s32 TObjCityDoorBase::check_player_in_range(f32 range_sq) {
    return is_any_city_player_in_range(&position, range_sq);
}

s32 TObjCityDoorBase::is_any_city_player_in_range(const Vec *center, f32 range_squared) {
    TObjPlayer *player;
    s32 area;
    s32 client;

    for (client = 0; client < 4; client++) {
        player = get_player_by_client_id(client);
        if (player != NULL) {
            area = player->get_area();
            if ((area == AREA_PIONEER2_EP1 || area == AREA_PIONEER2_EP2) && horizontal_distance_squared(center, &player->position) < range_squared) {
                return 1;
            }
        }
    }
    return 0;
}

void TObjCityDoorBase::begin_state_1() {
    if (check_player_in_range(params->open_range_sq) != 0) {
        phase = 1;
        city_door_play_open_sound();
        bodies->flags &= ~1;
    }
}

void TObjCityDoorBase::city_door_tick_opening() {
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
void TObjCityDoorBase::city_door_tick_closing() {
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

void TObjCityDoorBase::check_ground_or_fall() {
    if (check_player_in_range(params->close_range_sq) == 0) {
        phase = 3;
        city_door_play_close_sound();
    }
}

void TObjCityDoorBase::city_door_play_close_sound() {
    play_sound_effect(0x42A05, &position, 0, 0);
}

void TObjCityDoorBase::city_door_play_open_sound() {
    play_sound_effect(0x42A04, &position, 0, 0);
}

void TObjCityDoorBase::dispatch_state() {
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

s32 TObjCityDoorBase::is_in_view() {
    return update_object_view_visibility(params->view_far_depth, params->view_radius);
}

TObjCityDoor_Shop::TObjCityDoor_Shop(TObject *parent, void *set)
    : TObjCityDoorBase(parent, set, &city_door_shop_params) {
    m_name = class_name;
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
    if (is_in_view() != 0) {
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(city_common_texture_list));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        draw_ginja_model_with_motion(city_common_model_archive->models[11].model, city_common_model_archive->motions[10].motion, frame);
        pop_matrix();
    }
}

TObjCityDoor_Guild::TObjCityDoor_Guild(TObject *parent, void *set)
    : TObjCityDoorBase(parent, set, &city_door_guild_params) {
    m_name = class_name;
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
    if (is_in_view() != 0) {
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(city_common_texture_list));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        draw_ginja_model_with_motion(get_city_common_model(0x15), get_city_common_motion(0xC), frame);
        pop_matrix();
    }
}

TObjCityDoor_Warp::TObjCityDoor_Warp(TObject *parent, void *set)
    : TObjCityDoorBase(parent, set, &city_door_warp_params) {
    m_name = class_name;
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
    TObjCityDoorBase::city_door_tick_opening();
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
    if (is_in_view() != 0) {
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(city_common_texture_list));
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
    } else {
        stage = get_challenge_state();
        if ((stage != -1) && (stage == 1)) {
            return 0;
        }
    }
    return 1;
}

TObjCityDoor_Med::TObjCityDoor_Med(TObject *parent, void *set)
    : TObjCityDoorBase(parent, set, &city_door_med_params) {
    m_name = class_name;
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
    if (is_in_view() != 0) {
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(city_common_texture_list));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        translate_matrix(0, 0.0f, 0.0f, -80.0f);
        draw_ginja_model_with_motion(get_city_common_model(0x14), get_city_common_motion(0xB), frame);
        pop_matrix();
    }
}

TObjCityDoor_Lobby::TObjCityDoor_Lobby(TObject *parent, void *set) : TObjBase(parent) {
    m_name = class_name;
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
    if (is_phase_e() != 0) {
        build_door_collision_triangles();
        if (TObjMapCsn::get_collision_controller() != NULL) {
            TObjMapCsn::get_collision_controller()->add_group(&collision_group);
            collision_registered = 1;
        }
    }
}

TObjCityDoor_Lobby::~TObjCityDoor_Lobby() {
    if (collision_registered != 0 && TObjMapCsn::get_collision_controller() != NULL) {
        TObjMapCsn::get_collision_controller()->remove_group(&collision_group);
    }
}

void *TObjCityDoor_Lobby::create(void *set) {
    if (is_split_screen() != 0) {
        return NULL;
    }
    return new TObjCityDoor_Lobby(tl_05, set);
}

s32 TObjCityDoor_Lobby::is_phase_e() {
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
    if (is_phase_e() != 0) {
        build_door_collision_triangles();
        return;
    }
    process_lobby_action_14();
}

void TObjCityDoor_Lobby::run_task() {
}

void TObjCityDoor_Lobby::process_lobby_action_14() {
    if (update_object_view_visibility(400.0f, 70.0f) != 0) {
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(city_common_texture_list));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        draw_ginja_object(get_city_common_model(0xE));
        pop_matrix();
    }
}

void TObjCityDoor_Lobby::render() {
    if (is_phase_e() != 0) {
        process_lobby_action_14();
    }
}

void load_city_common_resources(void) {
    BmlResource *resource = new BmlResource(5, (BmlResourceDescriptor *)&bm_obj_city_common_resource_descriptor.archive, 0, 0, NULL);
    city_common_model_archive = resource;
    city_common_texture_list = LoadPvmFileTls(city_common_texture_filename);
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
#pragma push
#pragma readonly_strings on
const char *TObjCityDoor_Shop::class_name = "TObjCityDoor_Shop";
const char *TObjCityDoor_Guild::class_name = "TObjCityDoor_Guild";
const char *TObjCityDoor_Warp::class_name = "TObjCityDoor_Warp";
const char *TObjCityDoor_Med::class_name = "TObjCityDoor_Med";
const char *TObjCityDoor_Lobby::class_name = "TObjCityDoor_Lobby";
#pragma pop
