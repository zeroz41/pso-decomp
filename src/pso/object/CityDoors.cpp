#include "types.h"
#include "pso/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/vector.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TUnk_804B5C08.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/object/TUnk_804B5BA8.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjCityDoor_Shop.h"
#include "pso/object/TObjCityDoor_Guild.h"
#include "pso/object/TObjCityDoor_Warp.h"
#include "pso/object/TObjCityDoor_Med.h"
#include "pso/object/TObjCityDoor_Lobby.h"

struct RecoveredGlobal_8018289C_lbl_80443F4C
{
  s32 value;
  u8 remaining[0x18];
};
struct RecoveredGlobal_80182D8C_lbl_80443F20 {
    s32 value;
    u8 remaining[0x28];
};
typedef struct { f32 x, y, z; } Vec_80181BAC;
extern "C" {
extern const char lbl_80443BA8[];
__declspec(section ".rodata") const char lbl_80443BA8[] ATTRIBUTE_ALIGN(4) = "de_obj_bigbeam.gj";
extern const char lbl_80443BBC[];
__declspec(section ".rodata") const char lbl_80443BBC[] ATTRIBUTE_ALIGN(4) = "de_obj_citybeam.gj";
extern const char lbl_80443BD0[];
__declspec(section ".rodata") const char lbl_80443BD0[] ATTRIBUTE_ALIGN(4) = "de_obj_o_aircar02_light.gj";
extern const char lbl_80443BEC[];
__declspec(section ".rodata") const char lbl_80443BEC[] ATTRIBUTE_ALIGN(4) = "de_obj_smallbeam.gj";
extern const char lbl_80443C00[];
__declspec(section ".rodata") const char lbl_80443C00[] ATTRIBUTE_ALIGN(4) = "ds_obj_o_aircar01_light.gj";
extern const char lbl_80443C1C[];
__declspec(section ".rodata") const char lbl_80443C1C[] ATTRIBUTE_ALIGN(4) = "ds_obj_o_aircar03_light.gj";
extern const char lbl_80443C38[];
__declspec(section ".rodata") const char lbl_80443C38[] ATTRIBUTE_ALIGN(4) = "ds_obj_o_aircar04_light.gj";
extern const char lbl_80443C54[];
__declspec(section ".rodata") const char lbl_80443C54[] ATTRIBUTE_ALIGN(4) = "ds_obj_o_aircar05_light.gj";
extern const char lbl_80443C70[];
__declspec(section ".rodata") const char lbl_80443C70[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_elv_bmerge4.gj";
extern const char lbl_80443C88[];
__declspec(section ".rodata") const char lbl_80443C88[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tobira_shut_sita.gj";
extern const char lbl_80443CA8[];
__declspec(section ".rodata") const char lbl_80443CA8[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tobira_shut_ue.gj";
extern const char lbl_80443CC4[];
__declspec(section ".rodata") const char lbl_80443CC4[] ATTRIBUTE_ALIGN(4) = "fd_obj_shopdoor_01.gj";
extern const char lbl_80443CDC[];
__declspec(section ".rodata") const char lbl_80443CDC[] ATTRIBUTE_ALIGN(4) = "fd_obj_warp_big.gj";
extern const char lbl_80443CF0[];
__declspec(section ".rodata") const char lbl_80443CF0[] ATTRIBUTE_ALIGN(4) = "fd_obj_warp_small.gj";
extern const char lbl_80443D08[];
__declspec(section ".rodata") const char lbl_80443D08[] ATTRIBUTE_ALIGN(4) = "fe_hntdoor_fusagi.gj";
extern const char lbl_80443D20[];
__declspec(section ".rodata") const char lbl_80443D20[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_aircar01.nj";
extern const char lbl_80443D38[];
__declspec(section ".rodata") const char lbl_80443D38[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_aircar02.nj";
extern const char lbl_80443D50[];
__declspec(section ".rodata") const char lbl_80443D50[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_aircar03.nj";
extern const char lbl_80443D68[];
__declspec(section ".rodata") const char lbl_80443D68[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_aircar04.nj";
extern const char lbl_80443D80[];
__declspec(section ".rodata") const char lbl_80443D80[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_aircar05.nj";
extern const char lbl_80443D98[];
__declspec(section ".rodata") const char lbl_80443D98[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_medical_door01l.gj";
extern const char lbl_80443DB4[];
__declspec(section ".rodata") const char lbl_80443DB4[] ATTRIBUTE_ALIGN(4) = "hunter_door.gj";
extern const char lbl_80443DC4[];
__declspec(section ".rodata") const char lbl_80443DC4[] ATTRIBUTE_ALIGN(4) = "aircar_path1.njm";
extern const char lbl_80443DD8[];
__declspec(section ".rodata") const char lbl_80443DD8[] ATTRIBUTE_ALIGN(4) = "aircar_path2.njm";
extern const char lbl_80443DEC[];
__declspec(section ".rodata") const char lbl_80443DEC[] ATTRIBUTE_ALIGN(4) = "aircar_path3.njm";
extern const char lbl_80443E00[];
__declspec(section ".rodata") const char lbl_80443E00[] ATTRIBUTE_ALIGN(4) = "aircar_path4.njm";
extern const char lbl_80443E14[];
__declspec(section ".rodata") const char lbl_80443E14[] ATTRIBUTE_ALIGN(4) = "aircar_path5.njm";
extern const char lbl_80443E28[];
__declspec(section ".rodata") const char lbl_80443E28[] ATTRIBUTE_ALIGN(4) = "de_obj_bigbeam.njm";
extern const char lbl_80443E3C[];
__declspec(section ".rodata") const char lbl_80443E3C[] ATTRIBUTE_ALIGN(4) = "de_obj_citybeam.njm";
extern const char lbl_80443E50[];
__declspec(section ".rodata") const char lbl_80443E50[] ATTRIBUTE_ALIGN(4) = "de_obj_smallbeam.njm";
extern const char lbl_80443E68[];
__declspec(section ".rodata") const char lbl_80443E68[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tobira_shut_sita.njm";
extern const char lbl_80443E88[];
__declspec(section ".rodata") const char lbl_80443E88[] ATTRIBUTE_ALIGN(4) = "fd_obj_n_tobira_shut_ue.njm";
extern const char lbl_80443EA4[];
__declspec(section ".rodata") const char lbl_80443EA4[] ATTRIBUTE_ALIGN(4) = "fd_obj_shopdoor_01.njm";
extern const char lbl_80443EBC[];
__declspec(section ".rodata") const char lbl_80443EBC[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_medical_door01l.njm";
extern const char lbl_80443EDC[];
__declspec(section ".rodata") const char lbl_80443EDC[] ATTRIBUTE_ALIGN(4) = "hunter_door.njm";
extern const char city_common_model_archive_filename[];
__declspec(section ".rodata") const char city_common_model_archive_filename[] ATTRIBUTE_ALIGN(4) = "bm_obj_city_common.bml";
extern const char city_common_texture_filename[];
__declspec(section ".rodata") const char city_common_texture_filename[] ATTRIBUTE_ALIGN(4) = "bm_obj_city_common.GVM";
__declspec(section ".rodata") RecoveredGlobal_80182D8C_lbl_80443F20 city_door_init_params ATTRIBUTE_ALIGN(8) = {0x00000000, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
__declspec(section ".rodata") RecoveredGlobal_8018289C_lbl_80443F4C TObjCityDoor_Shop__params = {0x3F800000, {0x45, 0x61, 0x00, 0x00, 0x45, 0xC8, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x41, 0xC8, 0x00, 0x00, 0x44, 0x48, 0x00, 0x00, 0x41, 0xF0, 0x00, 0x00}};
__declspec(section ".rodata") u8 TObjCityDoor_Guild__params[] = {0x40, 0x00, 0x00, 0x00, 0x45, 0x61, 0x00, 0x00, 0x45, 0xC8, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x41, 0xC0, 0x00, 0x00, 0x44, 0x48, 0x00, 0x00, 0x41, 0xF0, 0x00, 0x00};
__declspec(section ".rodata") u8 city_door_warp_params[] = {0x3F, 0x80, 0x00, 0x00, 0x45, 0xFD, 0x20, 0x00, 0x46, 0x61, 0x00, 0x00, 0x42, 0x48, 0x00, 0x00, 0x40, 0xD0, 0x00, 0x00, 0x44, 0x48, 0x00, 0x00, 0x42, 0x8C, 0x00, 0x00};
__declspec(section ".rodata") u8 city_door_med_params[] = {0x3F, 0x80, 0x00, 0x00, 0x45, 0x61, 0x00, 0x00, 0x45, 0xC8, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x41, 0xC8, 0x00, 0x00, 0x44, 0x48, 0x00, 0x00, 0x41, 0xF0, 0x00, 0x00};
__declspec(section ".rodata") Vec_80181BAC city_door_lobby_collision_vertices[] = {{-14.0f, 0.0f, -38.0f}, {-14.0f, 40.0f, -38.0f}, {-10.0f, 0.0f, -12.0f}, {-10.0f, 40.0f, -12.0f}, {-2.0f, 0.0f, 2.0f}, {-2.0f, 40.0f, 2.0f}, {12.0f, 0.0f, 12.0f}, {12.0f, 40.0f, 12.0f}, {38.0f, 0.0f, 16.0f}, {38.0f, 40.0f, 16.0f}};
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

struct RecoveredGlobal_8019A9B8_lbl_804B8F60 {
    const char *value;
    const char **models;
    const char **motions;
    u32 counts;
    u32 padding;
};

struct RecoveredGlobal_8019A880_lbl_804B8F70 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8019A880___vt__8TObjTank {
    s32 value;
    u8 remaining[0x38];
};

struct Base_80181AE8 { char pad[0x18]; };

struct VObj_80181AE8 : Base_80181AE8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

extern u8 *city_common_model_archive;
extern s32 city_common_texture_list;
extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
u8 * load_gvm_texture_file(s32);
int is_phase_e__9TObjEneDDFPv(void*);
void render__18TObjCityDoor_LobbyFv(void* p);
}
extern RecoveredGlobal_8019A9B8_lbl_804B8F60 bm_obj_city_common_resource_descriptor;
void load_city_common_resources(void);
s32 get_city_common_model(s32);
extern "C" {
s32 post_translate_matrix(void *);
s32 draw_ginja_object();
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 pop_matrix();
extern const f32 lbl_805DBBE0;
extern const f32 lbl_805DBBE4;
s32 TLobby__sub_8001FE7C(s32, s32);
s32 release_texture_list(void*);

void TLobby::free_map_resources() {
    if ((u32) city_common_texture_list != 0U) {
        release_texture_list((void*)city_common_texture_list);
        TAdSinglePlyChrSelectGC::safe_free(city_common_texture_list);
        city_common_texture_list = 0U;
    }
    TLobby__sub_8001FE7C((s32)city_common_model_archive, 1);
    city_common_model_archive = 0;
}
}
typedef char RecoveredGlobal_8019A880_lbl_804B8F70_size[sizeof(RecoveredGlobal_8019A880_lbl_804B8F70) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8019A880___vt__8TObjTank_size[sizeof(RecoveredGlobal_8019A880___vt__8TObjTank) == 0x3C ? 1 : -1];
typedef char RecoveredGlobal_8019A9B8_lbl_804B8F60_size[sizeof(RecoveredGlobal_8019A9B8_lbl_804B8F60) == 0x14 ? 1 : -1];
void load_city_common_resources(void) {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &bm_obj_city_common_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&city_common_model_archive) = var_r0;
    (*(u8 * *)&city_common_texture_list) = load_gvm_texture_file((s32)city_common_texture_filename);
}
extern "C" {
void TObjCityDoor_Lobby::render() { if (is_phase_e__9TObjEneDDFPv(this) != 0) { process_lobby_action_14(); } }
void TObjCityDoor_Lobby::process_lobby_action_14() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_80181AE8 *)arg0)->m8(lbl_805DBBE0, lbl_805DBBE4) != 0) {
        TObjFish::set_global_param((*(s32 *)&city_common_texture_list));
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        get_city_common_model(0xE);
        draw_ginja_object();
        pop_matrix();
    }
}

void run_task__18TObjCityDoor_LobbyFv(void);
void dispatch_lobby_action__18TObjCityDoor_LobbyFv(s32 arg0);
int is_phase_e__9TObjEneDDFPv(void *);

void TObjCityDoor_Lobby::run_task() {  }
void TObjCityDoor_Lobby::dispatch_lobby_action() {
    s32 arg0 = (s32)this;
    if (is_phase_e__9TObjEneDDFPv((void *)arg0) != 0) {
        ((TObjCityDoor_Lobby *)arg0)->build_door_collision_triangles();
        return;
    }
    ((TObjCityDoor_Lobby *)arg0)->process_lobby_action_14();
}

#pragma push
#pragma fp_contract on

typedef struct {
    u16 idx[3];
    s16 f6;
    Vec_80181BAC normal;
    Vec_80181BAC center;
    f32 dist;
} Tri_80181BAC;

typedef struct {
    u8 pad0[0x38];
    u8 f38[0x60 - 0x38];
    s32 f60;
    u8 pad64[0x94 - 0x64];
    Vec_80181BAC f94;
    u8 padA0[0xB8 - 0xA0];
    Tri_80181BAC tris[8];
    Vec_80181BAC verts[10];
} Obj_80181BAC;

f32 newton_sqrtf(f32);
void calc_triangle_normal__10TObjPlayerFPvPv(Vec_80181BAC *, Vec_80181BAC *);
void vec3_add_to(Vec_80181BAC *, Vec_80181BAC *);
void mult_vec_array__10TObjPlayerFUll(s32, Vec_80181BAC *, Vec_80181BAC *, s32);
void set_matrix_identity(u8 *arg0);
s32 push_matrix(void);
s32 pop_matrix(void);
extern Vec_80181BAC city_door_lobby_collision_vertices[];
extern const f32 lbl_805DBBE8[1];
extern const f32 lbl_805DBBEC;

#define self ((Obj_80181BAC *)arg0)

s32 TObjCityDoor_Lobby::build_door_collision_triangles() {
    s32 arg0 = (s32)this;
    Vec_80181BAC v[3];
    Vec_80181BAC sum;
    Tri_80181BAC *t1;
    Tri_80181BAC *t;
    s32 m;
    s32 k;
    s32 j;
    s32 i;
    f32 three;
    f32 zero;

    VecCopy((Vec *)&self->f94, (const Vec *)(arg0 + 0x38));
    push_matrix();
    set_matrix_identity(0);
    post_translate_matrix(self->f38);
    rotate_matrix_y(0, self->f60);
    t1 = self->tris;
    j = 0;
    for (i = 0; i < 4; i++) {
        t1[0].idx[0] = j + city_door_lobby_quad_triangle_indices[0];
        t1[0].idx[1] = j + city_door_lobby_quad_triangle_indices[1];
        t1[0].idx[2] = j + city_door_lobby_quad_triangle_indices[2];
        VecCopy((Vec *)&v[0], (const Vec *)(&city_door_lobby_collision_vertices[t1[0].idx[0]]));
        VecCopy((Vec *)&v[1], (const Vec *)(&city_door_lobby_collision_vertices[t1[0].idx[1]]));
        VecCopy((Vec *)&v[2], (const Vec *)(&city_door_lobby_collision_vertices[t1[0].idx[2]]));
        calc_triangle_normal__10TObjPlayerFPvPv(v, &t1[0].normal);
        t1[1].idx[0] = j + city_door_lobby_quad_triangle_indices[3];
        t1[1].idx[1] = j + city_door_lobby_quad_triangle_indices[4];
        t1[1].idx[2] = j + city_door_lobby_quad_triangle_indices[5];
        VecCopy((Vec *)&v[0], (const Vec *)(&city_door_lobby_collision_vertices[t1[1].idx[0]]));
        VecCopy((Vec *)&v[1], (const Vec *)(&city_door_lobby_collision_vertices[t1[1].idx[1]]));
        VecCopy((Vec *)&v[2], (const Vec *)(&city_door_lobby_collision_vertices[t1[1].idx[2]]));
        calc_triangle_normal__10TObjPlayerFPvPv(v, &t1[1].normal);
        t1 += 2;
        j += 2;
    }
    mult_vec_array__10TObjPlayerFUll(0, city_door_lobby_collision_vertices, self->verts, 10);
    zero = lbl_805DBBE8[0];
    t = (Tri_80181BAC *)(arg0 + 0xB8);
    three = lbl_805DBBEC;
    for (m = 0; m < 8; m++, t++) {
        f32 dz;
        f32 dx;
        sum.x = zero;
        sum.y = zero;
        sum.z = zero;
        for (k = 0; k < 3; k++) {
            vec3_add_to(&sum, &self->verts[t->idx[k]]);
        }
        sum.x /= three;
        sum.y /= three;
        sum.z /= three;
        VecCopy((Vec *)&t->center, (const Vec *)&sum);
        dx = self->verts[t->idx[0]].x - sum.x;
        dz = self->verts[t->idx[0]].z - sum.z;
        t->dist = newton_sqrtf(dx * dx + dz * dz);
        t->f6 = 0xDE0;
    }
    pop_matrix();
}
#undef self
#pragma pop

s32 is_split_screen(void);
Obj_80181F10 *TObjCityDoor_Lobby__ct(Obj_80181F10 *, void *, s32);
void *__nw__7TObjectFUl(int);
extern void *tl_05;
u8 *TObjCityDoor_Lobby__create(s32 arg0);
int is_phase_e__9TObjEneDDFPv(void* p);
int is_phase_e__9TObjEneDDFv(void*);

int is_phase_e__9TObjEneDDFPv(void* p) { return is_phase_e__9TObjEneDDFv(p); }
u8 *TObjCityDoor_Lobby__create(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (is_split_screen() != 0) {
        return NULL;
    }
    temp_r3 = (u8 *)(__nw__7TObjectFUl(0x254));
    var_r0 = (u8 *)(temp_r3);
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TObjCityDoor_Lobby__ct((Obj_80181F10 *)temp_r3, tl_05, arg0));
    }
    return var_r0;
}

u8 *__dt__18TObjCityDoor_LobbyFPvs(u8 *arg0, s16 arg1);
u32 get_map_count__10TObjMapCsnFv();
void __dl__7TObjectFPv(void *);
}
void remove_value_from_id_list(s32 arg0, u32 arg1);

extern s32 __vt__18TObjCityDoor_Lobby[];
extern "C" {

u8 *__dt__18TObjCityDoor_LobbyFPvs(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjCityDoor_Lobby;
        if (((s32) ((TObjCityDoor_Lobby *)arg0)->m_250 != 0) && (get_map_count__10TObjMapCsnFv() != 0U)) {
            remove_value_from_id_list(get_map_count__10TObjMapCsnFv(), (u32)(arg0 + 0x90));
        }
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
}

struct Vec_80181F10 { f32 x, y, z; };

struct VBase_80181F10 { u8 pad[0x18]; };

struct Obj_80181F10 : VBase_80181F10 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(s32);
    u8 pad1c[0x38 - 0x1C];
    Vec_80181F10 pos;
    u8 pad44[0x90 - 0x44];
    void *x90;
    Vec_80181F10 pos94;
    f32 xa0;
    s32 xa4;
    s32 xa8;
    void *xac;
    s32 xb0;
    void *xb4;
    u8 bufb8[0x1D8 - 0xB8];
    u8 buf1d8[0x250 - 0x1D8];
    s32 x250;
};

extern "C" {
void register_slot(u32, void *);
void __ct__8TObjBaseFP7TObject(void *, void *);
struct CityDoorClassTag { const char *value; u32 padding; };
__declspec(section ".sdata") extern CityDoorClassTag TObjCityDoor_Lobby__name;
extern const f32 lbl_805DBBF0;
Obj_80181F10 *TObjCityDoor_Lobby__ct(Obj_80181F10 *self, void *arg1, s32 arg2);
Obj_80181F10 *TObjCityDoor_Lobby__ct(Obj_80181F10 *self, void *parent, s32 arg2) {
    __ct__8TObjBaseFP7TObject(self, parent);
    *(void **)((u8 *)self + 0x18) = __vt__18TObjCityDoor_Lobby;
    *(s32 *)self = (s32)TObjCityDoor_Lobby__name.value;
    self->m5(arg2);
    self->x90 = &self->xa8;
    VecCopy((Vec *)&self->pos94, (const Vec *)&self->pos);
    self->xa0 = lbl_805DBBF0;
    self->xa4 = 0xDE0;
    self->xb0 = 8;
    self->xb4 = self->bufb8;
    self->xa8 = 0xA;
    self->xac = self->buf1d8;
    self->x250 = 0;
    if (is_phase_e__9TObjEneDDFPv(self) != 0) {
        ((TObjCityDoor_Lobby *)self)->build_door_collision_triangles();
        if (get_map_count__10TObjMapCsnFv() != 0) {
            register_slot(get_map_count__10TObjMapCsnFv(), &self->x90);
            self->x250 = 1;
        }
    }
    return self;
}

}

extern "C" const f32 lbl_805DBBE8[1];

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
s32 get_city_common_motion(s32);
s32 draw_ginja_model_with_motion(s32, s32, f32);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);

extern const f32 lbl_805DBBF4;

void TObjCityDoor_Med::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_80181ff4 *)arg0)->m20() != 0) {
        TObjFish::set_global_param(city_common_texture_list);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        translate_matrix(0, lbl_805DBBE8[0], lbl_805DBBE8[0], lbl_805DBBF4);
        draw_ginja_model_with_motion(get_city_common_model(0x14), get_city_common_motion(0xB), this->m_b4);
        pop_matrix();
    }
}

void TObjCityDoor_Med::run_task() {
    struct VObj_8018208C_80181FF4 *o = (struct VObj_8018208C_80181FF4 *)this;
    o->m19();
}

void *TObjCityDoor_Med__create(void *arg0);
void *dt__16TObjCityDoor_MedFPvs(void *arg0, s16 arg1);
s32 TLobby__sub_80182E60();
s32 get_game_play_mode();
void *TObjCityDoor_Med__ct(void *, void *, void *);
}
s32 is_rader_map_active(void);
u8 *init_city_door(u8 *, s32, s32, u8 *);
extern "C" {
void *TObjPlayer__sub_80182D24(void *, s16);

void *TObjCityDoor_Med__create(void *set) {
    void *o = __nw__7TObjectFUl(0xBC);
    if (o != NULL) {
        o = TObjCityDoor_Med__ct(o, tl_05, set);
    }
    return o;
}

extern s32 __vt__16TObjCityDoor_Med[];

void *dt__16TObjCityDoor_MedFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TObjCityDoor_Med;
        TObjPlayer__sub_80182D24(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern u8 city_door_med_params[]; __declspec(section ".sdata") extern const char *TObjCityDoor_Med__name;
void *TObjCityDoor_Med__ct(void *o, void *parent, void *set) {
 init_city_door((u8*)o,(s32)parent,(s32)set,city_door_med_params);
 *(s32 **)((u8 *)o + 0x18)=__vt__16TObjCityDoor_Med;*(s32 *)((u8 *)o + 0)=(s32)TObjCityDoor_Med__name;
 ((TObjCityDoor_Med *)o)->m_b0=(f32)(*(u32 *)((u8 *)get_city_common_motion(11) + 4)-1);
 return o;
}
}

s32 is_rader_map_active(void) {
    s32 temp_r3;

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
  TObjFish::set_global_param(city_common_texture_list);push_matrix();
  post_translate_matrix((u8*)this+0x38);rotate_matrix_y(0,F(this,s32,0x60));
  draw_ginja_model_with_motion(get_city_common_model(9),get_city_common_motion(8),F(this,f32,0xB4));
  draw_ginja_model_with_motion(get_city_common_model(10),get_city_common_motion(9),F(this,f32,0xB4));
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
s32 update_technique_slot__10TTecRaFoieFl(s32, s32, s32);
s32 play_sound_effect(s32, s32, s32, s32);
void city_door_tick_opening__17TObjCityDoor_WarpFv(u8 *arg0);
extern const f32 lbl_805DBBF8;
extern const f32 lbl_805DBBFC;
void city_door_play_close_sound__17TObjCityDoor_WarpFv(s32 arg0);
void city_door_play_open_sound__17TObjCityDoor_WarpFv(s32 arg0);

void TObjCityDoor_Warp::city_door_play_close_sound() {
    s32 arg0 = (s32)this;
    update_technique_slot__10TTecRaFoieFl((s32)(play_sound_effect(0x42A05, arg0 + 0x38, 0, 0)), -0x500, 0);
}

void TObjCityDoor_Warp::city_door_play_open_sound() {
    s32 arg0 = (s32)this;
    if (is_rader_map_active() != 0) {
        s32 r = play_sound_effect(0x42A04, arg0 + 0x38, 0, 0);
        update_technique_slot__10TTecRaFoieFl((s32)(r), -0x800, 0);
    }
}
#pragma push
#pragma fp_contract on
void TObjCityDoor_Warp::city_door_tick_opening() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    temp_f1 = this->m_b4;
    if ((temp_f1 >= lbl_805DBBF8) && (temp_f1 <= lbl_805DBBFC)) {
        update_technique_slot__10TTecRaFoieFl((s32)(play_sound_effect(0x42A04, (s32)((void *) (arg0 + 0x38)), 0, 0)), -0x500, 0);
    }
    city_door_tick_opening__13TUnk_804B5BA8Fv((void *) (arg0));
}
#pragma pop

u8 *TObjCityDoor_Shop__ct(u8 *arg0, s32 arg1, s32 arg2);
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
void *TObjCityDoor_Warp__create(void *arg0);
void *dt__17TObjCityDoor_WarpFPvs(void *arg0, s16 arg1);
void render__18TObjCityDoor_GuildFv(u8 *arg0);
void *TObjCityDoor_Warp__ct(void *, void *, void *);

void *TObjCityDoor_Warp__create(void *set) {
    void *o = __nw__7TObjectFUl(0xBC);
    if (o != NULL) {
        o = TObjCityDoor_Warp__ct(o, tl_05, set);
    }
    return o;
}

extern s32 __vt__17TObjCityDoor_Warp[];

void *dt__17TObjCityDoor_WarpFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TObjCityDoor_Warp;
        TObjPlayer__sub_80182D24(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern u8 city_door_warp_params[]; __declspec(section ".sdata") extern const char *TObjCityDoor_Warp__name;
void *TObjCityDoor_Warp__ct(void *o, void *parent, void *set) {
 init_city_door((u8*)o,(s32)parent,(s32)set,city_door_warp_params);
 FOLD_F(o,s32*,0x18)=__vt__17TObjCityDoor_Warp;FOLD_F(o,s32,0)=(s32)TObjCityDoor_Warp__name;
 FOLD_F(o,f32,0xB0)=(f32)(FOLD_F(get_city_common_motion(8),u32,4)-1);
 return o;
}

void TObjCityDoor_Guild::render() {
    u8 *arg0 = (u8 *)this;

    if (((VObj_8018257c_8018245C *)arg0)->m20() != 0) {
        TObjFish::set_global_param(city_common_texture_list);
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

void *TObjCityDoor_Guild__create(void *arg0);
void run_task__17TObjCityDoor_ShopFv(void *arg0);
void *dt__18TObjCityDoor_GuildFPvs(void *arg0, s16 arg1);
void render__17TObjCityDoor_ShopFv(u8 *arg0);
void *TObjCityDoor_Guild__ct(void *, void *, void *);

void *TObjCityDoor_Guild__create(void *set) {
    void *o = __nw__7TObjectFUl(0xBC);
    if (o != NULL) {
        o = TObjCityDoor_Guild__ct(o, tl_05, set);
    }
    return o;
}

extern s32 __vt__18TObjCityDoor_Guild[];

void *dt__18TObjCityDoor_GuildFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjCityDoor_Guild;
        TObjPlayer__sub_80182D24(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern u8 TObjCityDoor_Guild__params[]; __declspec(section ".sdata") extern const char *TObjCityDoor_Guild__name;
void *TObjCityDoor_Guild__ct(void *o, void *parent, void *set) {
 init_city_door((u8*)o,(s32)parent,(s32)set,TObjCityDoor_Guild__params);
 FOLD_F(o,s32*,0x18)=__vt__18TObjCityDoor_Guild;FOLD_F(o,s32,0)=(s32)TObjCityDoor_Guild__name;
 FOLD_F(o,f32,0xB0)=(f32)(FOLD_F(get_city_common_motion(12),u32,4)-1);
 return o;
}

void TObjCityDoor_Shop::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_8018274C_8018262C *)arg0)->m20() != 0) {
        TObjFish::set_global_param(city_common_texture_list);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_ginja_model_with_motion(*(s32 *)((s8 *)(*(void **)((s8 *)city_common_model_archive + 0x42C)) + 0xB8), *(s32 *)((s8 *)(*(void **)((s8 *)city_common_model_archive + 0x430)) + 0x54), this->m_b4);
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

extern "C" {
extern RecoveredGlobal_8018289C_lbl_80443F4C TObjCityDoor_Shop__params;
extern RecoveredGlobal_8018289C_lbl_804B5B4C __vt__17TObjCityDoor_Shop;
__declspec(section ".sdata") extern const char *TObjCityDoor_Shop__name;
void *TObjCityDoor_Shop__create(void *arg0);
void *dt__17TObjCityDoor_ShopFPvs(void *arg0, s16 arg1);

void *TObjCityDoor_Shop__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xBC);
    if (o != NULL) {
        o = ((void *(*)(void *, void *, void *))TObjCityDoor_Shop__ct)(o, tl_05, arg0);
    }
    return o;
}

void *dt__17TObjCityDoor_ShopFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)&__vt__17TObjCityDoor_Shop;
        TObjPlayer__sub_80182D24(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef struct RecoveredGlobal_8018289C_lbl_80443F4C RecoveredGlobal_8018289C_lbl_80443F4C;
typedef struct RecoveredGlobal_8018289C_lbl_804B5B4C RecoveredGlobal_8018289C_lbl_804B5B4C;
typedef char RecoveredGlobal_8018289C_lbl_80443F4C_size[((sizeof(RecoveredGlobal_8018289C_lbl_80443F4C)) == 0x1C) ? (1) : (-1)];
typedef char RecoveredGlobal_8018289C_lbl_804B5B4C_size[((sizeof(RecoveredGlobal_8018289C_lbl_804B5B4C)) == 0x5C) ? (1) : (-1)];
u8 *TObjCityDoor_Shop__ct(u8 *city_door_shop, s32 arg1, s32 arg2) {
  unsigned int new_var2;
  s32 *new_var;
  new_var = &__vt__17TObjCityDoor_Shop.value;
  init_city_door(city_door_shop, arg1, arg2, (u8 *)&TObjCityDoor_Shop__params.value);
  *((s32 **) (((s8 *) city_door_shop) + 0x18)) = new_var;
  *((s32 *) (((s8 *) city_door_shop) + 0)) = (s32) TObjCityDoor_Shop__name;
  new_var2 = 1;
  ((TObjCityDoor_Shop *)city_door_shop)->m_b0 = (f32) ((*((s32 *) (((s8 *) (*((void **) (((s8 *) (*((u8 **) (((s8 *) city_common_model_archive) + 0x430)))) + 0x54)))) + 4))) - new_var2);
  return city_door_shop;
}

}

#include "pso/player/TObjPlayer.h"

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

struct RecoveredGlobal_80182D8C_lbl_804B5BA8 {
    s32 value;
    u8 remaining[0x5C];
};

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
void *TObjPlayer__sub_80182D24(void *arg0, s16 arg1);
extern void *challenge_task;
s32 TLobby__sub_80182E60(void);
s32 init_collision_body_parts(void *, void *, int, int);
s32 __ct__14TObjCollidableFP7TObject();
}
extern RecoveredGlobal_80182D8C_lbl_80443F20 city_door_init_params;
u8 *init_city_door(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3);
extern "C" {
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
f32 horizontal_distance_squared(s32, s32);
void *get_player_by_client_id(s32 i);
s32 get_field_3e0__12TBoss3VoloptFv();

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
    s32 arg0 = (s32)this;
    play_sound_effect(0x42A04, arg0 + 0x38, 0, 0);
}

void TUnk_804B5BA8::city_door_play_close_sound() {
    s32 arg0 = (s32)this;
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
  if (door->frame <= lbl_805DBBE8[0]) {
   door->frame = lbl_805DBBE8[0];
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

s32 TObjPlayer::is_player_in_range(s32 arg0, s32 arg1, f32 farg0) {
    s32 player;
    s32 temp_r3_2;
    s32 var_r30;

    var_r30 = 0;
loop_1:
    player = (s32)get_player_by_client_id(var_r30);
    if ((player != 0) && ((temp_r3_2 = get_field_3e0__12TBoss3VoloptFv(), ((temp_r3_2 == 0) != 0)) || (temp_r3_2 == 0x12)) && (horizontal_distance_squared(arg1, player + 0x38) < farg0)) {
        return 1;
    }
    var_r30 += 1;
    if (var_r30 >= 4) {
        return 0;
    }
    goto loop_1;
}
s32 TUnk_804B5BA8::check_player_in_range(s32 _w1, f32 _w2) { return TObjPlayer::is_player_in_range((s32)(this), (s32)((s8 *)this + 0x38), _w2); }
void *TObjPlayer__sub_80182D24(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = city_door_base_vtable;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__14TObjCollidableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
}

typedef char RecoveredGlobal_80182D8C_lbl_80443F20_size[sizeof(RecoveredGlobal_80182D8C_lbl_80443F20) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_80182D8C_lbl_804B5BA8_size[sizeof(RecoveredGlobal_80182D8C_lbl_804B5BA8) == 0x60 ? 1 : -1];
u8 *init_city_door(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3) {
    struct CopyStack_80182D8C { u8 bytes[0x2C]; };
    CopyStack_80182D8C copy_storage_80182D8C;
    u8 *temp_r4;
    u8 *count;
    __ct__14TObjCollidableFP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80182D8C_lbl_804B5BA8 *)&city_door_base_vtable).value;
    ((TUnk_804B5BA8 *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0xAC) = 0;
    temp_r4 = (u8 *)&city_door_init_params.value - 4;
    ((TUnk_804B5BA8 *)arg0)->m_b0 = lbl_805DBBE8[0];
    ((TUnk_804B5BA8 *)arg0)->m_b4 = lbl_805DBBE8[0];
    *(u8 **)((s8 *)arg0 + 0xB8) = arg3;
    *(ByteBlock_2C *)(copy_storage_80182D8C.bytes) = *(const ByteBlock_2C *)((s32) temp_r4 + 4);
    count = (u8 *)(*(u8 **)((s8 *)arg0 + 0xB8));
    (*(f32 *)(copy_storage_80182D8C.bytes + 0xC)) = *(f32 *)((s8 *)count + 0xC);
    (*(f32 *)(copy_storage_80182D8C.bytes + 0x10)) = *(f32 *)((s8 *)count + 0x10);
    init_collision_body_parts((void *) (arg0), (void *) ((copy_storage_80182D8C.bytes)), 1, (int) (count));
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
const char *bm_obj_city_common_model_names[] = {lbl_80443BA8, lbl_80443BBC, lbl_80443BD0, lbl_80443BEC, lbl_80443C00, lbl_80443C1C, lbl_80443C38, lbl_80443C54, lbl_80443C70, lbl_80443C88, lbl_80443CA8, lbl_80443CC4, lbl_80443CDC, lbl_80443CF0, lbl_80443D08, lbl_80443D20, lbl_80443D38, lbl_80443D50, lbl_80443D68, lbl_80443D80, lbl_80443D98, lbl_80443DB4, 0};
const char *bm_obj_city_common_motion_names[] = {lbl_80443DC4, lbl_80443DD8, lbl_80443DEC, lbl_80443E00, lbl_80443E14, lbl_80443E28, lbl_80443E3C, lbl_80443E50, lbl_80443E68, lbl_80443E88, lbl_80443EA4, lbl_80443EBC, lbl_80443EDC, 0};
RecoveredGlobal_8019A9B8_lbl_804B8F60 bm_obj_city_common_resource_descriptor = {city_common_model_archive_filename, bm_obj_city_common_model_names, bm_obj_city_common_motion_names, 0x0016000D, 0};
s32 __vt__18TObjCityDoor_Lobby[] = {0, 0, (s32)__dt__18TObjCityDoor_LobbyFPvs, (s32)run_task__18TObjCityDoor_LobbyFv, (s32)render__18TObjCityDoor_LobbyFv, (s32)render_shadows__7TObjectFv, (s32)vfunc_6__8TObjBaseFPsl, (s32)apply_object_set_data__8TObjBaseFPv, (s32)reset_motion_fields__8TObjBaseFv, (s32)get_center__8TObjBaseFv, (s32)update_object_view_visibility__8TObjBaseFff, (s32)classify_actor_view_detail__8TObjBaseFfff, (s32)get_name__8TObjBaseFv, (s32)dispatch_lobby_action__18TObjCityDoor_LobbyFv};
s32 __vt__16TObjCityDoor_Med[] = {0, 0, (s32)dt__16TObjCityDoor_MedFPvs, (s32)run_task__16TObjCityDoor_MedFv, (s32)render__16TObjCityDoor_MedFv, (s32)render_shadows__7TObjectFv, (s32)vfunc_6__8TObjBaseFPsl, (s32)apply_object_set_data__8TObjBaseFPv, (s32)reset_motion_fields__14TObjCollidableFv, (s32)get_center__8TObjBaseFv, (s32)update_object_view_visibility__8TObjBaseFff, (s32)classify_actor_view_detail__8TObjBaseFfff, (s32)get_name__8TObjBaseFv, (s32)interact__14TObjCollidableFl, (s32)check_player_in_range__13TUnk_804B5BA8Flf, (s32)begin_state_1__13TUnk_804B5BA8Fv, (s32)city_door_tick_closing__13TUnk_804B5BA8Fv, (s32)city_door_tick_opening__13TUnk_804B5BA8Fv, (s32)check_ground_or_fall__13TUnk_804B5BA8Fv, (s32)city_door_play_close_sound__13TUnk_804B5BA8Fv, (s32)city_door_play_open_sound__13TUnk_804B5BA8Fv, (s32)dispatch_state__13TUnk_804B5BA8Fv, (s32)vfunc_22__13TUnk_804B5BA8Fv};
s32 __vt__17TObjCityDoor_Warp[] = {0, 0, (s32)dt__17TObjCityDoor_WarpFPvs, (s32)run_task__17TObjCityDoor_WarpFv, (s32)render__17TObjCityDoor_WarpFv, (s32)render_shadows__7TObjectFv, (s32)vfunc_6__8TObjBaseFPsl, (s32)apply_object_set_data__8TObjBaseFPv, (s32)reset_motion_fields__14TObjCollidableFv, (s32)get_center__8TObjBaseFv, (s32)update_object_view_visibility__8TObjBaseFff, (s32)classify_actor_view_detail__8TObjBaseFfff, (s32)get_name__8TObjBaseFv, (s32)interact__14TObjCollidableFl, (s32)check_player_in_range__13TUnk_804B5BA8Flf, (s32)begin_state_1__13TUnk_804B5BA8Fv, (s32)city_door_tick_closing__13TUnk_804B5BA8Fv, (s32)city_door_tick_opening__17TObjCityDoor_WarpFv, (s32)check_ground_or_fall__13TUnk_804B5BA8Fv, (s32)city_door_play_close_sound__17TObjCityDoor_WarpFv, (s32)city_door_play_open_sound__17TObjCityDoor_WarpFv, (s32)dispatch_state__13TUnk_804B5BA8Fv, (s32)vfunc_22__13TUnk_804B5BA8Fv};
s32 __vt__18TObjCityDoor_Guild[] = {0, 0, (s32)dt__18TObjCityDoor_GuildFPvs, (s32)run_task__18TObjCityDoor_GuildFv, (s32)render__18TObjCityDoor_GuildFv, (s32)render_shadows__7TObjectFv, (s32)vfunc_6__8TObjBaseFPsl, (s32)apply_object_set_data__8TObjBaseFPv, (s32)reset_motion_fields__14TObjCollidableFv, (s32)get_center__8TObjBaseFv, (s32)update_object_view_visibility__8TObjBaseFff, (s32)classify_actor_view_detail__8TObjBaseFfff, (s32)get_name__8TObjBaseFv, (s32)interact__14TObjCollidableFl, (s32)check_player_in_range__13TUnk_804B5BA8Flf, (s32)begin_state_1__13TUnk_804B5BA8Fv, (s32)city_door_tick_closing__13TUnk_804B5BA8Fv, (s32)city_door_tick_opening__13TUnk_804B5BA8Fv, (s32)check_ground_or_fall__13TUnk_804B5BA8Fv, (s32)city_door_play_close_sound__13TUnk_804B5BA8Fv, (s32)city_door_play_open_sound__13TUnk_804B5BA8Fv, (s32)dispatch_state__13TUnk_804B5BA8Fv, (s32)vfunc_22__13TUnk_804B5BA8Fv};
RecoveredGlobal_8018289C_lbl_804B5B4C __vt__17TObjCityDoor_Shop = {0, {0, (s32)dt__17TObjCityDoor_ShopFPvs, (s32)run_task__17TObjCityDoor_ShopFv, (s32)render__17TObjCityDoor_ShopFv, (s32)render_shadows__7TObjectFv, (s32)vfunc_6__8TObjBaseFPsl, (s32)apply_object_set_data__8TObjBaseFPv, (s32)reset_motion_fields__14TObjCollidableFv, (s32)get_center__8TObjBaseFv, (s32)update_object_view_visibility__8TObjBaseFff, (s32)classify_actor_view_detail__8TObjBaseFfff, (s32)get_name__8TObjBaseFv, (s32)interact__14TObjCollidableFl, (s32)check_player_in_range__13TUnk_804B5BA8Flf, (s32)begin_state_1__13TUnk_804B5BA8Fv, (s32)city_door_tick_closing__13TUnk_804B5BA8Fv, (s32)city_door_tick_opening__13TUnk_804B5BA8Fv, (s32)check_ground_or_fall__13TUnk_804B5BA8Fv, (s32)city_door_play_close_sound__13TUnk_804B5BA8Fv, (s32)city_door_play_open_sound__13TUnk_804B5BA8Fv, (s32)dispatch_state__13TUnk_804B5BA8Fv, (s32)vfunc_22__13TUnk_804B5BA8Fv}};
s32 city_door_base_vtable[] = {0, 0, (s32)TObjPlayer__sub_80182D24, (s32)run_task__7TObjectFv, (s32)render__7TObjectFv, (s32)render_shadows__7TObjectFv, (s32)vfunc_6__8TObjBaseFPsl, (s32)apply_object_set_data__8TObjBaseFPv, (s32)reset_motion_fields__14TObjCollidableFv, (s32)get_center__8TObjBaseFv, (s32)update_object_view_visibility__8TObjBaseFff, (s32)classify_actor_view_detail__8TObjBaseFfff, (s32)get_name__8TObjBaseFv, (s32)interact__14TObjCollidableFl, (s32)check_player_in_range__13TUnk_804B5BA8Flf, (s32)begin_state_1__13TUnk_804B5BA8Fv, (s32)city_door_tick_closing__13TUnk_804B5BA8Fv, (s32)city_door_tick_opening__13TUnk_804B5BA8Fv, (s32)check_ground_or_fall__13TUnk_804B5BA8Fv, (s32)city_door_play_close_sound__13TUnk_804B5BA8Fv, (s32)city_door_play_open_sound__13TUnk_804B5BA8Fv, (s32)dispatch_state__13TUnk_804B5BA8Fv, (s32)vfunc_22__13TUnk_804B5BA8Fv, 0};
__declspec(section ".sdata") const char *TObjCityDoor_Shop__name = TObjCityDoor_Shop__class_name;
__declspec(section ".sdata") const char *TObjCityDoor_Guild__name = TObjCityDoor_Guild__class_name;
__declspec(section ".sdata") const char *TObjCityDoor_Warp__name = TObjCityDoor_Warp__class_name;
__declspec(section ".sdata") const char *TObjCityDoor_Med__name = TObjCityDoor_Med__class_name;
__declspec(section ".sdata") CityDoorClassTag TObjCityDoor_Lobby__name = {TObjCityDoor_Lobby__class_name, 0};
__declspec(section ".sdata2") const f32 lbl_805DBBE0 = 400.0f;
__declspec(section ".sdata2") const f32 lbl_805DBBE4 = 70.0f;
__declspec(section ".sdata2") const f32 lbl_805DBBE8[1] = {0.0f};
__declspec(section ".sdata2") const f32 lbl_805DBBEC = 3.0f;
__declspec(section ".sdata2") const f32 lbl_805DBBF0 = 2000.0f;
__declspec(section ".sdata2") const f32 lbl_805DBBF4 = -80.0f;
__declspec(section ".sdata2") const f32 lbl_805DBBF8 = 24.0f;
__declspec(section ".sdata2") const f32 lbl_805DBBFC = 25.0f;
}
