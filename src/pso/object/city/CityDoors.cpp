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


struct RecoveredGlobal_8018289C_lbl_80443F4C
{
  s32 value;
  u8 remaining[0x18];
};
struct RecoveredGlobal_80182D8C_lbl_80443F20 {
    s32 value;
    u8 remaining[0x28];
};
extern "C" {
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
__declspec(section ".rodata") RecoveredGlobal_80182D8C_lbl_80443F20 city_door_init_params ATTRIBUTE_ALIGN(8) = {0x00000000, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
__declspec(section ".rodata") RecoveredGlobal_8018289C_lbl_80443F4C TObjCityDoor_Shop__params = {0x3F800000, {0x45, 0x61, 0x00, 0x00, 0x45, 0xC8, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x41, 0xC8, 0x00, 0x00, 0x44, 0x48, 0x00, 0x00, 0x41, 0xF0, 0x00, 0x00}};
__declspec(section ".rodata") u8 TObjCityDoor_Guild__params[] = {0x40, 0x00, 0x00, 0x00, 0x45, 0x61, 0x00, 0x00, 0x45, 0xC8, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x41, 0xC0, 0x00, 0x00, 0x44, 0x48, 0x00, 0x00, 0x41, 0xF0, 0x00, 0x00};
__declspec(section ".rodata") u8 city_door_warp_params[] = {0x3F, 0x80, 0x00, 0x00, 0x45, 0xFD, 0x20, 0x00, 0x46, 0x61, 0x00, 0x00, 0x42, 0x48, 0x00, 0x00, 0x40, 0xD0, 0x00, 0x00, 0x44, 0x48, 0x00, 0x00, 0x42, 0x8C, 0x00, 0x00};
__declspec(section ".rodata") u8 city_door_med_params[] = {0x3F, 0x80, 0x00, 0x00, 0x45, 0x61, 0x00, 0x00, 0x45, 0xC8, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x41, 0xC8, 0x00, 0x00, 0x44, 0x48, 0x00, 0x00, 0x41, 0xF0, 0x00, 0x00};
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
}
struct Obj_80181F10;

u8 * load_gvm_texture_file(saddr);
extern "C" {
void render__18TObjCityDoor_LobbyFv(void* p);
s32 post_translate_matrix(void *);
}

void TLobby::free_map_resources() {
    if (city_common_texture_list != NULL) {
        release_texture_list(city_common_texture_list);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)city_common_texture_list);
        city_common_texture_list = NULL;
    }
    delete (BmlResource *)city_common_model_archive;
    city_common_model_archive = NULL;
}
struct BmObjCityCommonResourceDescriptor {
    BmlResourceDescriptor archive;
    u32 padding;
};
extern BmObjCityCommonResourceDescriptor bm_obj_city_common_resource_descriptor;
void load_city_common_resources(void);
void load_city_common_resources(void) {
    BmlResource *resource = new BmlResource(5, (BmlResourceDescriptor *)&bm_obj_city_common_resource_descriptor.archive, 0, 0, NULL);
    city_common_model_archive = resource;
    city_common_texture_list = (GinjaTextureList *)load_gvm_texture_file((saddr)city_common_texture_filename);
}
extern "C" {
void TObjCityDoor_Lobby::render() { if (check_phase_e(this) != 0) { process_lobby_action_14(); } }
void TObjCityDoor_Lobby::process_lobby_action_14() {
    if (this->update_object_view_visibility(400.0f, 70.0f) != 0) {
        TObjFish::set_global_param((saddr)city_common_texture_list);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_ginja_object(get_city_common_model(0xE));
        pop_matrix();
    }
}

void run_task__18TObjCityDoor_LobbyFv(void);
void dispatch_lobby_action__18TObjCityDoor_LobbyFv(s32 arg0);

void TObjCityDoor_Lobby::run_task() {  }
void TObjCityDoor_Lobby::dispatch_lobby_action() {
    saddr arg0 = (saddr)this;
    if (check_phase_e((void *)arg0) != 0) {
        ((TObjCityDoor_Lobby *)arg0)->build_door_collision_triangles();
        return;
    }
    ((TObjCityDoor_Lobby *)arg0)->process_lobby_action_14();
}

#pragma push
#pragma fp_contract on

void vec3_add_to(Vec *, Vec *);
extern Vec city_door_lobby_collision_vertices[];

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
    post_translate_matrix((u8 *)&position);
    rotate_matrix_y(0, rotation_y);
    t1 = collision_faces;
    j = 0;
    for (i = 0; i < 4; i++) {
        t1[0].vertex[0] = j + city_door_lobby_quad_triangle_indices[0];
        t1[0].vertex[1] = j + city_door_lobby_quad_triangle_indices[1];
        t1[0].vertex[2] = j + city_door_lobby_quad_triangle_indices[2];
        VecCopy((Vec *)&v[0], (const Vec *)(&city_door_lobby_collision_vertices[t1[0].vertex[0]]));
        VecCopy((Vec *)&v[1], (const Vec *)(&city_door_lobby_collision_vertices[t1[0].vertex[1]]));
        VecCopy((Vec *)&v[2], (const Vec *)(&city_door_lobby_collision_vertices[t1[0].vertex[2]]));
        calc_triangle_normal((const Vec *)v, (Vec *)&t1[0].normal);
        t1[1].vertex[0] = j + city_door_lobby_quad_triangle_indices[3];
        t1[1].vertex[1] = j + city_door_lobby_quad_triangle_indices[4];
        t1[1].vertex[2] = j + city_door_lobby_quad_triangle_indices[5];
        VecCopy((Vec *)&v[0], (const Vec *)(&city_door_lobby_collision_vertices[t1[1].vertex[0]]));
        VecCopy((Vec *)&v[1], (const Vec *)(&city_door_lobby_collision_vertices[t1[1].vertex[1]]));
        VecCopy((Vec *)&v[2], (const Vec *)(&city_door_lobby_collision_vertices[t1[1].vertex[2]]));
        calc_triangle_normal((const Vec *)v, (Vec *)&t1[1].normal);
        t1 += 2;
        j += 2;
    }
    matrix_mult_vec_array(NULL, (const Vec *)city_door_lobby_collision_vertices, (Vec *)(collision_vertices), 10);
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
        VecCopy((Vec *)&t->center, (const Vec *)&sum);
        dx = collision_vertices[t->vertex[0]].x - sum.x;
        dz = collision_vertices[t->vertex[0]].z - sum.z;
        t->radius = newton_sqrtf(dx * dx + dz * dz);
        t->flags = 0xDE0;
    }
    pop_matrix();
}
#pragma pop

Obj_80181F10 *TObjCityDoor_Lobby__ct(Obj_80181F10 *, void *, s32);
int check_phase_e(void *) { return TObjEneDD::is_phase_e(); }
u8 *TObjCityDoor_Lobby__create(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (is_split_screen() != 0) {
        return NULL;
    }
    temp_r3 = (u8 *)(TObject::operator new(0x254));
    var_r0 = (u8 *)(temp_r3);
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TObjCityDoor_Lobby__ct((Obj_80181F10 *)temp_r3, tl_05, arg0));
    }
    return var_r0;
}

}

extern s32 __vt__18TObjCityDoor_Lobby[];


u8 *__dt__18TObjCityDoor_LobbyFPvs(u8 *city_door_lobby, s16 arg1) {
    if (city_door_lobby != NULL) {
        *(s32 **)((s8 *)city_door_lobby + 0x18) = __vt__18TObjCityDoor_Lobby;
        if (((s32) ((TObjCityDoor_Lobby *)city_door_lobby)->m_250 != 0) && (TObjMapCsn::get_collision_controller() != NULL)) {
            remove_collision_group(TObjMapCsn::get_collision_controller(),
                &((TObjCityDoor_Lobby *)city_door_lobby)->collision_group);
        }
        __dt__8TObjBaseFv(city_door_lobby, 0);
        if (arg1 > 0) {
            TObject::operator delete(city_door_lobby);
        }
    }
    return city_door_lobby;
}

struct VBase_80181F10 { u8 pad[0x18]; };

struct Obj_80181F10 : VBase_80181F10 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(s32);
    u8 pad1c[0x38 - 0x1C];
    Vec pos;
    u8 pad44[0x90 - 0x44];
    CsnGroup collision_group;
    CsnModel collision_model;
    CsnFace collision_faces[8];
    Vec collision_vertices[10];
    s32 x250;
};

extern "C" {
void __ct__8TObjBaseFP7TObject(void *, void *);
struct CityDoorClassTag { const char *value; u32 padding; };
__declspec(section ".sdata") extern CityDoorClassTag TObjCityDoor_Lobby__name;
Obj_80181F10 *TObjCityDoor_Lobby__ct(Obj_80181F10 *self, void *arg1, s32 arg2);
Obj_80181F10 *TObjCityDoor_Lobby__ct(Obj_80181F10 *self, void *parent, s32 arg2) {
    __ct__8TObjBaseFP7TObject(self, parent);
    *(void **)((u8 *)self + 0x18) = __vt__18TObjCityDoor_Lobby;
    *(saddr *)self = (saddr)TObjCityDoor_Lobby__name.value;
    self->m5(arg2);
    self->collision_group.model = &self->collision_model;
    VecCopy(&self->collision_group.center, &self->pos);
    self->collision_group.radius = 2000.0f;
    self->collision_group.flags = 0xDE0;
    self->collision_model.face_count = 8;
    self->collision_model.faces = self->collision_faces;
    self->collision_model.vertex_count = 10;
    self->collision_model.vertices = self->collision_vertices;
    self->x250 = 0;
    if (check_phase_e(self) != 0) {
        ((TObjCityDoor_Lobby *)self)->build_door_collision_triangles();
        if (TObjMapCsn::get_collision_controller() != NULL) {
            register_slot(TObjMapCsn::get_collision_controller(), &self->collision_group);
            self->x250 = 1;
        }
    }
    return self;
}

}

struct Base_8018208C_80181FF4 { char pad[0x18]; };
struct VObj_8018208C_80181FF4 : Base_8018208C_80181FF4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
};

struct Base_80181ff4 { char pad[0x18]; };
struct VObj_80181ff4 : Base_80181ff4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual s32 m20();
};
extern "C" {

void run_task__16TObjCityDoor_MedFv(void *arg0);
void render__16TObjCityDoor_MedFv(u8 *arg0);
}
extern "C" {
void draw_ginja_model_with_motion(void *model, void *motion, f32 frame);

void TObjCityDoor_Med::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_80181ff4 *)arg0)->m20() != 0) {
        TObjFish::set_global_param((saddr)city_common_texture_list);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        translate_matrix(0, 0.0f, 0.0f, -80.0f);
        draw_ginja_model_with_motion(get_city_common_model(0x14), get_city_common_motion(0xB), this->m_b4);
        pop_matrix();
    }
}

void TObjCityDoor_Med::run_task() {
    struct VObj_8018208C_80181FF4 *o = (struct VObj_8018208C_80181FF4 *)this;
    o->m19();
}

s32 get_game_play_mode();
}
s32 is_rader_map_active(void);
u8 *init_city_door(u8 *, saddr, saddr, u8 *);


void *TObjCityDoor_Med__create(void *set) {
    void *o = TObject::operator new(0xBC);
    if (o != NULL) {
        o = TObjCityDoor_Med__ct(o, tl_05, set);
    }
    return o;
}

extern s32 __vt__16TObjCityDoor_Med[];

void *dt__16TObjCityDoor_MedFPvs(void *object, s16 arg1) {
    if (object != NULL) {
        *(s32 **)((s8 *)object + 0x18) = __vt__16TObjCityDoor_Med;
        TObjPlayer__sub_80182D24(object, 0);
        if (arg1 > 0) {
            TObject::operator delete(object);
        }
    }
    return object;
}

extern u8 city_door_med_params[]; __declspec(section ".sdata") extern const char *TObjCityDoor_Med__name;
void *TObjCityDoor_Med__ct(void *o, void *parent, void *set) {
 init_city_door((u8*)o,(saddr)parent,(saddr)set,city_door_med_params);
 *(s32 **)((u8 *)o + 0x18)=__vt__16TObjCityDoor_Med;*(saddr *)((u8 *)o + 0)=(saddr)TObjCityDoor_Med__name;
 ((TObjCityDoor_Med *)o)->m_b0=(f32)(get_city_common_motion(11)->frameCount-1);
 return o;
}

s32 is_rader_map_active(void) {
    saddr temp_r3;

    if (TRaderMapCore::is_not_split_screen() == 1) {
        if (get_game_play_mode() == 1) {
            return 0;
        }
        goto block_6;
    }
    temp_r3 = TLobby__sub_80182E60();
    if ((temp_r3 != -1) && (temp_r3 == 1)) {
        return 0;
    }
block_6:
    return 1;
}

#define F(o,t,p) (*(t*)((u8*)(o)+(p)))
struct CityDoorProbeBase {char pad[0x18];};

struct CityDoorProbe : CityDoorProbeBase {
virtual void m0();
virtual void m1();
virtual void m2();
virtual void m3();
virtual void m4();
virtual void m5();
virtual void m6();
virtual void m7();
virtual void m8();
virtual void m9();
virtual void m10();
virtual void m11();
virtual s32 near(f32);
virtual void closed();virtual void closing();virtual void opening();virtual void open();
virtual void closeSound();virtual void openSound();virtual void tick();virtual s32 visible();
};

extern "C" {

void run_task__17TObjCityDoor_WarpFv(u8 *arg0);
void render__17TObjCityDoor_WarpFv(void* o);

void TObjCityDoor_Warp::render() {
 if(((CityDoorProbe*)this)->visible()!=0) {
  TObjFish::set_global_param((saddr)city_common_texture_list);push_matrix();
  post_translate_matrix((u8*)this+0x38);rotate_matrix_y(0,F(this,s32,0x60));
  draw_ginja_model_with_motion(get_city_common_model(9), get_city_common_motion(8), F(this,f32,0xB4));
  draw_ginja_model_with_motion(get_city_common_model(10), get_city_common_motion(9), F(this,f32,0xB4));
  pop_matrix();
 }
}

void TObjCityDoor_Warp::run_task() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    if (((s32 (*)(void *))is_rader_map_active)((void *) (arg0)) == 0) {
        *(s32 *)((s8 *)arg0 + 0xAC) = 0;
    }
    this->dispatch_state();
    if (((s32 (*)(void *))is_rader_map_active)((void *) (arg0)) == 0) {
        temp_r3 = *(u8 * *)&this->bodies;
        *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) | 1);
    }
}

void city_door_tick_opening__13TUnk_804B5BA8Fv(void *);
s32 play_sound_effect(s32, saddr, s32, s32);
void city_door_tick_opening__17TObjCityDoor_WarpFv(u8 *arg0);
void city_door_play_close_sound__17TObjCityDoor_WarpFv(s32 arg0);
void city_door_play_open_sound__17TObjCityDoor_WarpFv(s32 arg0);

void TObjCityDoor_Warp::city_door_play_close_sound() {
    saddr arg0 = (saddr)this;
    set_sound_pitch_request((s32)(play_sound_effect(0x42A05, arg0 + 0x38, 0, 0)), -0x500, 0);
}

void TObjCityDoor_Warp::city_door_play_open_sound() {
    saddr arg0 = (saddr)this;
    if (is_rader_map_active() != 0) {
        s32 r = play_sound_effect(0x42A04, arg0 + 0x38, 0, 0);
        set_sound_pitch_request((s32)(r), -0x800, 0);
    }
}
#pragma push
#pragma fp_contract on
void TObjCityDoor_Warp::city_door_tick_opening() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    temp_f1 = this->m_b4;
    if ((temp_f1 >= 24.0f) && (temp_f1 <= 25.0f)) {
        set_sound_pitch_request((s32)(play_sound_effect(0x42A04, (saddr)((void *) (arg0 + 0x38)), 0, 0)), -0x500, 0);
    }
    ((TUnk_804B5BA8 *)arg0)->TUnk_804B5BA8::city_door_tick_opening();
}
#pragma pop

}
#define FOLD_F(o,t,p) (*(t*)((u8*)(o)+(p)))
struct Base_80182600_8018245C { char pad[0x18]; };
struct VObj_80182600_8018245C : Base_80182600_8018245C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
};

extern "C" {

struct Base_8018257c_8018245C { u8 pad[0x18]; };
struct VObj_8018257c_8018245C : Base_8018257c_8018245C {
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3() = 0;
    virtual void m4() = 0;
    virtual void m5() = 0;
    virtual void m6() = 0;
    virtual void m7() = 0;
    virtual void m8() = 0;
    virtual void m9() = 0;
    virtual void m10() = 0;
    virtual void m11() = 0;
    virtual void m12() = 0;
    virtual void m13() = 0;
    virtual void m14() = 0;
    virtual void m15() = 0;
    virtual void m16() = 0;
    virtual void m17() = 0;
    virtual void m18() = 0;
    virtual void m19() = 0;
    virtual s32 m20() = 0;
};

void run_task__18TObjCityDoor_GuildFv(void *arg0);
void render__18TObjCityDoor_GuildFv(u8 *arg0);

void *TObjCityDoor_Warp__create(void *set) {
    void *o = TObject::operator new(0xBC);
    if (o != NULL) {
        o = TObjCityDoor_Warp__ct(o, tl_05, set);
    }
    return o;
}

extern s32 __vt__17TObjCityDoor_Warp[];

void *dt__17TObjCityDoor_WarpFPvs(void *object, s16 arg1) {
    if (object != NULL) {
        *(s32 **)((s8 *)object + 0x18) = __vt__17TObjCityDoor_Warp;
        TObjPlayer__sub_80182D24(object, 0);
        if (arg1 > 0) {
            TObject::operator delete(object);
        }
    }
    return object;
}

extern u8 city_door_warp_params[]; __declspec(section ".sdata") extern const char *TObjCityDoor_Warp__name;
void *TObjCityDoor_Warp__ct(void *o, void *parent, void *set) {
 init_city_door((u8*)o,(saddr)parent,(saddr)set,city_door_warp_params);
 FOLD_F(o,s32*,0x18)=__vt__17TObjCityDoor_Warp;FOLD_F(o,s32,0)=(saddr)TObjCityDoor_Warp__name;
 FOLD_F(o,f32,0xB0)=(f32)(get_city_common_motion(8)->frameCount-1);
 return o;
}

void TObjCityDoor_Guild::render() {
    u8 *arg0 = (u8 *)this;

    if (((VObj_8018257c_8018245C *)arg0)->m20() != 0) {
        TObjFish::set_global_param((saddr)city_common_texture_list);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_ginja_model_with_motion(get_city_common_model(0x15), get_city_common_motion(0xC), this->m_b4);
        pop_matrix();
    }
}

void TObjCityDoor_Guild::run_task() {
    struct VObj_80182600_8018245C *o = (struct VObj_80182600_8018245C *)this;
    o->m19();
}

}

struct Base_8018274C_8018262C { char pad[0x18]; };
struct VObj_8018274C_8018262C : Base_8018274C_8018262C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual s32 m20();
};
struct Base_801827CC_8018262C { char pad[0x18]; };
struct VObj_801827CC_8018262C : Base_801827CC_8018262C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
};

extern "C" {

void run_task__17TObjCityDoor_ShopFv(void *arg0);
void render__17TObjCityDoor_ShopFv(u8 *arg0);

void *TObjCityDoor_Guild__create(void *set) {
    void *o = TObject::operator new(0xBC);
    if (o != NULL) {
        o = TObjCityDoor_Guild__ct(o, tl_05, set);
    }
    return o;
}

extern s32 __vt__18TObjCityDoor_Guild[];

void *dt__18TObjCityDoor_GuildFPvs(void *object, s16 arg1) {
    if (object != NULL) {
        *(s32 **)((s8 *)object + 0x18) = __vt__18TObjCityDoor_Guild;
        TObjPlayer__sub_80182D24(object, 0);
        if (arg1 > 0) {
            TObject::operator delete(object);
        }
    }
    return object;
}

extern u8 TObjCityDoor_Guild__params[]; __declspec(section ".sdata") extern const char *TObjCityDoor_Guild__name;
void *TObjCityDoor_Guild__ct(void *o, void *parent, void *set) {
 init_city_door((u8*)o,(saddr)parent,(saddr)set,TObjCityDoor_Guild__params);
 FOLD_F(o,s32*,0x18)=__vt__18TObjCityDoor_Guild;FOLD_F(o,s32,0)=(saddr)TObjCityDoor_Guild__name;
 FOLD_F(o,f32,0xB0)=(f32)(get_city_common_motion(12)->frameCount-1);
 return o;
}

void TObjCityDoor_Shop::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_8018274C_8018262C *)arg0)->m20() != 0) {
        TObjFish::set_global_param((saddr)city_common_texture_list);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_ginja_model_with_motion((void *)((saddr)city_common_model_archive->models[11].model), (void *)(city_common_model_archive->motions[10].motion), this->m_b4);
        pop_matrix();
    }
}

void TObjCityDoor_Shop::run_task() {
    struct VObj_801827CC_8018262C *o = (struct VObj_801827CC_8018262C *)this;
    o->m19();
}

}

struct RecoveredGlobal_8018289C_lbl_804B5B4C
{
  s32 value;
  s32 remaining[22];
};


extern RecoveredGlobal_8018289C_lbl_80443F4C TObjCityDoor_Shop__params;
extern RecoveredGlobal_8018289C_lbl_804B5B4C __vt__17TObjCityDoor_Shop;
__declspec(section ".sdata") extern const char *TObjCityDoor_Shop__name;

void *TObjCityDoor_Shop__create(void *arg0) {
    void *o = TObject::operator new(0xBC);
    if (o != NULL) {
        o = ((void *(*)(void *, void *, void *))TObjCityDoor_Shop__ct)(o, tl_05, arg0);
    }
    return o;
}

void *dt__17TObjCityDoor_ShopFPvs(void *object, s16 arg1) {
    if (object != NULL) {
        *(s32 **)((s8 *)object + 0x18) = (s32 *)&__vt__17TObjCityDoor_Shop;
        TObjPlayer__sub_80182D24(object, 0);
        if (arg1 > 0) {
            TObject::operator delete(object);
        }
    }
    return object;
}

typedef struct RecoveredGlobal_8018289C_lbl_80443F4C RecoveredGlobal_8018289C_lbl_80443F4C;
typedef struct RecoveredGlobal_8018289C_lbl_804B5B4C RecoveredGlobal_8018289C_lbl_804B5B4C;
LAYOUT_ASSERT(RecoveredGlobal_8018289C_lbl_80443F4C_size, (sizeof(RecoveredGlobal_8018289C_lbl_80443F4C)) == 0x1C);
LAYOUT_ASSERT(RecoveredGlobal_8018289C_lbl_804B5B4C_size, (sizeof(RecoveredGlobal_8018289C_lbl_804B5B4C)) == 0x5C);
u8 *TObjCityDoor_Shop__ct(u8 *city_door_shop, s32 arg1, s32 arg2) {
  unsigned int new_var2;
  s32 *new_var;
  new_var = &__vt__17TObjCityDoor_Shop.value;
  init_city_door(city_door_shop, arg1, arg2, (u8 *)&TObjCityDoor_Shop__params.value);
  *((s32 **) (((s8 *) city_door_shop) + 0x18)) = new_var;
  *((s32 *) (((s8 *) city_door_shop) + 0)) = (saddr) TObjCityDoor_Shop__name;
  new_var2 = 1;
  ((TObjCityDoor_Shop *)city_door_shop)->m_b0 = (f32)((s32)city_common_model_archive->motions[10].motion->frameCount - new_var2);
  return city_door_shop;
}


struct Base_80182A58_8018291C { char pad[0x18]; };
struct VObj_80182A58_8018291C : Base_80182A58_8018291C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual s32 m12(f32);
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_2C { u8 bytes[0x2c]; };

#define F(o,t,p) (*(t*)((u8*)(o)+(p)))
struct CityDoorProbe3Base {char pad[0x18];};

struct CityDoorProbe3 : CityDoorProbe3Base {
virtual void m0();
virtual void m1();
virtual void m2();
virtual void m3();
virtual void m4();
virtual void m5();
virtual void m6();
virtual void m7();
virtual void m8();
virtual void m9();
virtual void m10();
virtual void m11();
virtual s32 m12(f32);
virtual void m13();virtual void m14();virtual void m15();virtual void m16();
virtual void m17();virtual void m18();virtual void m19();virtual s32 m20();
};

struct CityDoorParameters { f32 speed, openingDistanceSquared, closingDistanceSquared; };

struct CityDoorCollider { u8 padding[0x18]; s32 flags; };

struct CityDoorFields {
 u8 padding[0xA4]; CityDoorCollider* collider; s32 reserved;
 s32 phase; f32 endFrame, frame; CityDoorParameters* parameters;
};

extern "C" {
s32 check_player_in_range__13TUnk_804B5BA8Flf(void *arg0, s32 _w1, f32 _w2);
s32 free_collision_body_parts(void *);
extern s32 city_door_base_vtable[];
extern void *challenge_task;
s32 init_collision_body_parts(void *, void *, int);
s32 __ct__14TObjCollidableFP7TObject();
void city_door_tick_opening__13TUnk_804B5BA8Fv(void* o);
void city_door_tick_closing__13TUnk_804B5BA8Fv(void* o);
struct Vec_8018291C { char pad14[0x14]; f32 x; f32 y; };
struct Base_8018291C { char pad[0x18]; };
struct VObj_8018291C : Base_8018291C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m10(f32, f32);
    char pad2[0xB8 - 0x18 - 4];
    Vec_8018291C *m;
};
struct Base_80182C04_8018291C { char pad[0x18]; };
struct VObj_80182C04_8018291C : Base_80182C04_8018291C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual s32 m12(f32);
    virtual void m13(); virtual void m14(); virtual void m15(); virtual void m16();
    virtual void m17();
    virtual void m18();
};

void vfunc_22__13TUnk_804B5BA8Fv(VObj_8018291C *arg0);
void city_door_play_open_sound__13TUnk_804B5BA8Fv(s32 arg0);
void city_door_play_close_sound__13TUnk_804B5BA8Fv(s32 arg0);
void begin_state_1__13TUnk_804B5BA8Fv(void *arg0);
void check_ground_or_fall__13TUnk_804B5BA8Fv(void *arg0);
void dispatch_state__13TUnk_804B5BA8Fv(void *arg0);

void TUnk_804B5BA8::vfunc_22() {
    VObj_8018291C *arg0 = (VObj_8018291C *)this;
    arg0->m10(arg0->m->x, arg0->m->y);
}

void TUnk_804B5BA8::dispatch_state() {

    switch (*(s32 *)((s8 *)this + 0xAC)) {
    case 0:
        this->begin_state_1();
        return;
    case 1:
        this->city_door_tick_opening();
        return;
    case 2:
        this->check_ground_or_fall();
        return;
    case 3:
        this->city_door_tick_closing();
        return;
    }
}

void TUnk_804B5BA8::city_door_play_open_sound() {
    saddr arg0 = (saddr)this;
    play_sound_effect(0x42A04, arg0 + 0x38, 0, 0);
}

void TUnk_804B5BA8::city_door_play_close_sound() {
    saddr arg0 = (saddr)this;
    play_sound_effect(0x42A05, arg0 + 0x38, 0, 0);
}

void TUnk_804B5BA8::check_ground_or_fall() {

    if (((VObj_80182A58_8018291C *)this)->m12(*(f32 *)((s8 *)(*(void * *)&this->unk_B8) + 8)) == 0) {
        *(s32 *)((s8 *)this + 0xAC) = 3;
        this->city_door_play_close_sound();
    }
}

#pragma push
#pragma opt_common_subs off
void TUnk_804B5BA8::city_door_tick_closing() {
 CityDoorFields* door = (CityDoorFields*)this;
 if (((CityDoorProbe3*)this)->m12(door->parameters->openingDistanceSquared) != 0) {
  door->phase = 1;
  this->city_door_play_open_sound();
 } else {
  door->frame -= door->parameters->speed;
  if (door->frame <= 0.0f) {
   door->frame = 0.0f;
   door->phase = 0;
   door->collider->flags |= 1;
  }
 }
}
#pragma pop

void TUnk_804B5BA8::city_door_tick_opening() {
void* params=F(this,void*,0xB8);
if(((CityDoorProbe3*)this)->m12(F(params,f32,8))==0) {
 F(this,s32,0xAC)=3;this->city_door_play_close_sound();return;
}
F(this,f32,0xB4)=F(this,f32,0xB4)+F(F(this,void*,0xB8),f32,0);
f32 last=F(this,f32,0xB0);
if(F(this,f32,0xB4)>=last) {F(this,f32,0xB4)=F(this,f32,0xB0);F(this,s32,0xAC)=2;}
}

void TUnk_804B5BA8::begin_state_1() {
    void *temp_r3;
    VObj_80182C04_8018291C *obj = (VObj_80182C04_8018291C *)this;

    if (obj->m12(*(f32 *)((s8 *)(*(void * *)&this->unk_B8) + 4)) != 0) {
        *(s32 *)((s8 *)this + 0xAC) = 1;
        obj->m18();
        temp_r3 = this->bodies;
        *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) & 0xFFFFFFFE);
    }
}

s32 TUnk_804B5BA8::is_any_city_player_in_range(const Vec *center, f32 range_squared) {
    TObjPlayer *player;
    s32 area;
    s32 var_r30;

    var_r30 = 0;
loop_1:
    player = get_player_by_client_id(var_r30);
    if ((player != 0) && ((area = player->get_area(), ((area == AREA_PIONEER2_EP1) != 0)) || (area == AREA_PIONEER2_EP2)) && (horizontal_distance_squared(center, &player->position) < range_squared)) {
        return 1;
    }
    var_r30 += 1;
    if (var_r30 >= 4) {
        return 0;
    }
    goto loop_1;
}
s32 TUnk_804B5BA8::check_player_in_range(s32 _w1, f32 _w2) { return is_any_city_player_in_range(&position, _w2); }
void *TObjPlayer__sub_80182D24(void *collidable, s16 arg1) {
    if (collidable != NULL) {
        *(s32 **)((s8 *)collidable + 0x18) = city_door_base_vtable;
        ((TObjCollidable *)collidable)->unregister_object_by_id();
        free_collision_body_parts(collidable);
        __dt__14TObjCollidableFv(collidable, 0);
        if (arg1 > 0) {
            TObject::operator delete(collidable);
        }
    }
    return collidable;
}
}
extern RecoveredGlobal_80182D8C_lbl_80443F20 city_door_init_params;
u8 *init_city_door(u8 *arg0, saddr arg1, saddr arg2, u8 *arg3);
LAYOUT_ASSERT(RecoveredGlobal_80182D8C_lbl_80443F20_size, sizeof(RecoveredGlobal_80182D8C_lbl_80443F20) == 0x2C);
u8 *init_city_door(u8 *arg0, s32 arg1, saddr arg2, u8 *arg3) {
    struct CopyStack_80182D8C { u8 bytes[0x2C]; };
    CopyStack_80182D8C copy_storage_80182D8C;
    u8 *temp_r4;
    u8 *count;
    __ct__14TObjCollidableFP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = city_door_base_vtable;
    ((TUnk_804B5BA8 *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0xAC) = 0;
    temp_r4 = (u8 *)&city_door_init_params.value - 4;
    ((TUnk_804B5BA8 *)arg0)->m_b0 = 0.0f;
    ((TUnk_804B5BA8 *)arg0)->m_b4 = 0.0f;
    *(u8 **)((s8 *)arg0 + 0xB8) = arg3;
    *(ByteBlock_2C *)(copy_storage_80182D8C.bytes) = *(const ByteBlock_2C *)((saddr) temp_r4 + 4);
    count = (u8 *)(*(u8 **)((s8 *)arg0 + 0xB8));
    (*(f32 *)(copy_storage_80182D8C.bytes + 0xC)) = *(f32 *)((s8 *)count + 0xC);
    (*(f32 *)(copy_storage_80182D8C.bytes + 0x10)) = *(f32 *)((s8 *)count + 0x10);
    init_collision_body_parts(arg0, copy_storage_80182D8C.bytes, 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    return arg0;
}
extern "C" {

s32 TLobby__sub_80182E60(void) {
    if ((void *) challenge_task == NULL) {
        return -1;
    }
    return *(s32 *)((s8 *)challenge_task + 0x1C);
}

void interact__14TObjCollidableFl();
void reset_motion_fields__14TObjCollidableFv();
void get_name__8TObjBaseFv();
void apply_object_set_data__8TObjBaseFPv();
void vfunc_6__8TObjBaseFPsl();
void get_center__8TObjBaseFv();
void classify_actor_view_detail__8TObjBaseFfff();
void update_object_view_visibility__8TObjBaseFff();
void reset_motion_fields__8TObjBaseFv();
void render_shadows__7TObjectFv();
void render__7TObjectFv();
void run_task__7TObjectFv();
}
const char *bm_obj_city_common_model_names[] = {city_door_asset_de_obj_bigbeam_gj, city_door_asset_de_obj_citybeam_gj, city_door_asset_de_obj_o_aircar02_light_gj, city_door_asset_de_obj_smallbeam_gj, city_door_asset_ds_obj_o_aircar01_light_gj, city_door_asset_ds_obj_o_aircar03_light_gj, city_door_asset_ds_obj_o_aircar04_light_gj, city_door_asset_ds_obj_o_aircar05_light_gj, city_door_asset_fd_obj_n_elv_bmerge4_gj, city_door_asset_fd_obj_n_tobira_shut_sita_gj, city_door_asset_fd_obj_n_tobira_shut_ue_gj, city_door_asset_fd_obj_shopdoor_01_gj, city_door_asset_fd_obj_warp_big_gj, city_door_asset_fd_obj_warp_small_gj, city_door_asset_fe_hntdoor_fusagi_gj, city_door_asset_fe_obj_o_aircar01_nj, city_door_asset_fe_obj_o_aircar02_nj, city_door_asset_fe_obj_o_aircar03_nj, city_door_asset_fe_obj_o_aircar04_nj, city_door_asset_fe_obj_o_aircar05_nj, city_door_asset_fe_obj_o_medical_door01l_gj, city_door_asset_hunter_door_gj, 0};
const char *bm_obj_city_common_motion_names[] = {city_door_asset_aircar_path1_njm, city_door_asset_aircar_path2_njm, city_door_asset_aircar_path3_njm, city_door_asset_aircar_path4_njm, city_door_asset_aircar_path5_njm, city_door_asset_de_obj_bigbeam_njm, city_door_asset_de_obj_citybeam_njm, city_door_asset_de_obj_smallbeam_njm, city_door_asset_fd_obj_n_tobira_shut_sita_njm, city_door_asset_fd_obj_n_tobira_shut_ue_njm, city_door_asset_fd_obj_shopdoor_01_njm, city_door_asset_fe_obj_o_medical_door01l_njm, city_door_asset_hunter_door_njm, 0};
BmObjCityCommonResourceDescriptor bm_obj_city_common_resource_descriptor = {{city_common_model_archive_filename, bm_obj_city_common_model_names, bm_obj_city_common_motion_names, 22, 13}, 0};
s32 __vt__18TObjCityDoor_Lobby[] = {0, 0, (saddr)__dt__18TObjCityDoor_LobbyFPvs, (saddr)run_task__18TObjCityDoor_LobbyFv, (saddr)render__18TObjCityDoor_LobbyFv, (saddr)render_shadows__7TObjectFv, (saddr)vfunc_6__8TObjBaseFPsl, (saddr)apply_object_set_data__8TObjBaseFPv, (saddr)reset_motion_fields__8TObjBaseFv, (saddr)get_center__8TObjBaseFv, (saddr)update_object_view_visibility__8TObjBaseFff, (saddr)classify_actor_view_detail__8TObjBaseFfff, (saddr)get_name__8TObjBaseFv, (saddr)dispatch_lobby_action__18TObjCityDoor_LobbyFv};
s32 __vt__16TObjCityDoor_Med[] = {0, 0, (saddr)dt__16TObjCityDoor_MedFPvs, (saddr)run_task__16TObjCityDoor_MedFv, (saddr)render__16TObjCityDoor_MedFv, (saddr)render_shadows__7TObjectFv, (saddr)vfunc_6__8TObjBaseFPsl, (saddr)apply_object_set_data__8TObjBaseFPv, (saddr)reset_motion_fields__14TObjCollidableFv, (saddr)get_center__8TObjBaseFv, (saddr)update_object_view_visibility__8TObjBaseFff, (saddr)classify_actor_view_detail__8TObjBaseFfff, (saddr)get_name__8TObjBaseFv, (saddr)interact__14TObjCollidableFl, (saddr)check_player_in_range__13TUnk_804B5BA8Flf, (saddr)begin_state_1__13TUnk_804B5BA8Fv, (saddr)city_door_tick_closing__13TUnk_804B5BA8Fv, (saddr)city_door_tick_opening__13TUnk_804B5BA8Fv, (saddr)check_ground_or_fall__13TUnk_804B5BA8Fv, (saddr)city_door_play_close_sound__13TUnk_804B5BA8Fv, (saddr)city_door_play_open_sound__13TUnk_804B5BA8Fv, (saddr)dispatch_state__13TUnk_804B5BA8Fv, (saddr)vfunc_22__13TUnk_804B5BA8Fv};
s32 __vt__17TObjCityDoor_Warp[] = {0, 0, (saddr)dt__17TObjCityDoor_WarpFPvs, (saddr)run_task__17TObjCityDoor_WarpFv, (saddr)render__17TObjCityDoor_WarpFv, (saddr)render_shadows__7TObjectFv, (saddr)vfunc_6__8TObjBaseFPsl, (saddr)apply_object_set_data__8TObjBaseFPv, (saddr)reset_motion_fields__14TObjCollidableFv, (saddr)get_center__8TObjBaseFv, (saddr)update_object_view_visibility__8TObjBaseFff, (saddr)classify_actor_view_detail__8TObjBaseFfff, (saddr)get_name__8TObjBaseFv, (saddr)interact__14TObjCollidableFl, (saddr)check_player_in_range__13TUnk_804B5BA8Flf, (saddr)begin_state_1__13TUnk_804B5BA8Fv, (saddr)city_door_tick_closing__13TUnk_804B5BA8Fv, (saddr)city_door_tick_opening__17TObjCityDoor_WarpFv, (saddr)check_ground_or_fall__13TUnk_804B5BA8Fv, (saddr)city_door_play_close_sound__17TObjCityDoor_WarpFv, (saddr)city_door_play_open_sound__17TObjCityDoor_WarpFv, (saddr)dispatch_state__13TUnk_804B5BA8Fv, (saddr)vfunc_22__13TUnk_804B5BA8Fv};
s32 __vt__18TObjCityDoor_Guild[] = {0, 0, (saddr)dt__18TObjCityDoor_GuildFPvs, (saddr)run_task__18TObjCityDoor_GuildFv, (saddr)render__18TObjCityDoor_GuildFv, (saddr)render_shadows__7TObjectFv, (saddr)vfunc_6__8TObjBaseFPsl, (saddr)apply_object_set_data__8TObjBaseFPv, (saddr)reset_motion_fields__14TObjCollidableFv, (saddr)get_center__8TObjBaseFv, (saddr)update_object_view_visibility__8TObjBaseFff, (saddr)classify_actor_view_detail__8TObjBaseFfff, (saddr)get_name__8TObjBaseFv, (saddr)interact__14TObjCollidableFl, (saddr)check_player_in_range__13TUnk_804B5BA8Flf, (saddr)begin_state_1__13TUnk_804B5BA8Fv, (saddr)city_door_tick_closing__13TUnk_804B5BA8Fv, (saddr)city_door_tick_opening__13TUnk_804B5BA8Fv, (saddr)check_ground_or_fall__13TUnk_804B5BA8Fv, (saddr)city_door_play_close_sound__13TUnk_804B5BA8Fv, (saddr)city_door_play_open_sound__13TUnk_804B5BA8Fv, (saddr)dispatch_state__13TUnk_804B5BA8Fv, (saddr)vfunc_22__13TUnk_804B5BA8Fv};
RecoveredGlobal_8018289C_lbl_804B5B4C __vt__17TObjCityDoor_Shop = {0, {0, (saddr)dt__17TObjCityDoor_ShopFPvs, (saddr)run_task__17TObjCityDoor_ShopFv, (saddr)render__17TObjCityDoor_ShopFv, (saddr)render_shadows__7TObjectFv, (saddr)vfunc_6__8TObjBaseFPsl, (saddr)apply_object_set_data__8TObjBaseFPv, (saddr)reset_motion_fields__14TObjCollidableFv, (saddr)get_center__8TObjBaseFv, (saddr)update_object_view_visibility__8TObjBaseFff, (saddr)classify_actor_view_detail__8TObjBaseFfff, (saddr)get_name__8TObjBaseFv, (saddr)interact__14TObjCollidableFl, (saddr)check_player_in_range__13TUnk_804B5BA8Flf, (saddr)begin_state_1__13TUnk_804B5BA8Fv, (saddr)city_door_tick_closing__13TUnk_804B5BA8Fv, (saddr)city_door_tick_opening__13TUnk_804B5BA8Fv, (saddr)check_ground_or_fall__13TUnk_804B5BA8Fv, (saddr)city_door_play_close_sound__13TUnk_804B5BA8Fv, (saddr)city_door_play_open_sound__13TUnk_804B5BA8Fv, (saddr)dispatch_state__13TUnk_804B5BA8Fv, (saddr)vfunc_22__13TUnk_804B5BA8Fv}};
s32 city_door_base_vtable[] = {0, 0, (saddr)TObjPlayer__sub_80182D24, (saddr)run_task__7TObjectFv, (saddr)render__7TObjectFv, (saddr)render_shadows__7TObjectFv, (saddr)vfunc_6__8TObjBaseFPsl, (saddr)apply_object_set_data__8TObjBaseFPv, (saddr)reset_motion_fields__14TObjCollidableFv, (saddr)get_center__8TObjBaseFv, (saddr)update_object_view_visibility__8TObjBaseFff, (saddr)classify_actor_view_detail__8TObjBaseFfff, (saddr)get_name__8TObjBaseFv, (saddr)interact__14TObjCollidableFl, (saddr)check_player_in_range__13TUnk_804B5BA8Flf, (saddr)begin_state_1__13TUnk_804B5BA8Fv, (saddr)city_door_tick_closing__13TUnk_804B5BA8Fv, (saddr)city_door_tick_opening__13TUnk_804B5BA8Fv, (saddr)check_ground_or_fall__13TUnk_804B5BA8Fv, (saddr)city_door_play_close_sound__13TUnk_804B5BA8Fv, (saddr)city_door_play_open_sound__13TUnk_804B5BA8Fv, (saddr)dispatch_state__13TUnk_804B5BA8Fv, (saddr)vfunc_22__13TUnk_804B5BA8Fv, 0};
__declspec(section ".sdata") const char *TObjCityDoor_Shop__name = TObjCityDoor_Shop__class_name;
__declspec(section ".sdata") const char *TObjCityDoor_Guild__name = TObjCityDoor_Guild__class_name;
__declspec(section ".sdata") const char *TObjCityDoor_Warp__name = TObjCityDoor_Warp__class_name;
__declspec(section ".sdata") const char *TObjCityDoor_Med__name = TObjCityDoor_Med__class_name;
__declspec(section ".sdata") CityDoorClassTag TObjCityDoor_Lobby__name = {TObjCityDoor_Lobby__class_name, 0};
