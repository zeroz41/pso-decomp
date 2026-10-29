#include "pso/player/PlayerAttackParams.h"
#include "types.h"
#include "pso/TObject.h"
#include "pso/object/TObjGrassWeb.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/object/obj_band.h"
#include "pso/system/vector.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjGrass.h"
#include "pso/enemy/TUnk_80494938.h"
#include "pso/map/FloorArea.h"
extern "C" void render__12TObjGrassWebFv();
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"

#include "pso/player/TObjPlayer.h"

extern "C" {
s32 lbl_805D5140;
u32 TObjGrass__bml_resource;
s32 grass_combat_stats_handle;
s32 lbl_805D514C;
s32 TObjGrass__render_node_index;
u32 TObjGrass__resource_bundle;
u32 lbl_805D5158;
u32 lbl_805D515C;
}

#pragma readonly_strings on

struct E_800BFB8C { s32 f0; s32 f4; s32 f8; s32 fc; };

struct D_800BFB8C { u8 pad[0x42c]; E_800BFB8C *entries; };

struct O_800BFB8C { u8 pad[0x24]; s32 f24; u8 pad2[0xc]; s32 f34; };

struct O_800BFB68 { u8 pad[0x3d4]; s32 arr[12]; };

struct Obj_800BF880 { u8 pad0[0x18]; void *vt; u8 pad1c[0x3CC - 0x1C]; void *items[2]; };

typedef struct Vec_800BE75C {
    f32 x, y, z;
} Vec_800BE75C;

typedef struct Range_800BE75C {
    f32 lo;
    f32 hi;
} Range_800BE75C;

typedef struct Grass_800BE75C {
    u8 pad0[0x38];
    Vec_800BE75C pos;
    u8 pad44[0x50 - 0x44];
    u8 mtx50[0x60 - 0x50];
    s32 f60;
    u8 pad64[0x2A8 - 0x64];
    s32 f2A8;
    u8 pad2AC[0x350 - 0x2AC];
    Range_800BE75C *range;
    u8 pad354[0x358 - 0x354];
    f32 f358;
    u8 pad35C[0x39C - 0x35C];
    s16 f39C;
} Grass_800BE75C;

struct Vec_800BEF8C { f32 x, y, z; };

struct Vec_800BF66C { f32 x, y, z; };

struct Quad_800BF66C { s32 a, b, c, d; };

struct Ent8_800BF66C { s32 f0; s32 f4; };

struct Model_800BF66C { s32 f0; s32 f4; s32 f8; s32 fC; };

struct Data_800BF66C { u8 pad[0x42C]; Model_800BF66C *f42c; Ent8_800BF66C *f430; };

struct VObj_800BDD70 {
    char pad[0x18];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32 *, s32 *);
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
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual s32 m20(void *, f32);
    virtual void m21();
    virtual void m22();
    virtual s32 m23(void *);
};

struct Vec_800BDD70 { f32 x, y, z; };

struct Vec_800BE4C0 { f32 x, y, z; };

struct Param_800BE4C0 { f32 f0; f32 f4; s32 f8; };

struct Anim_800BE4C0 { u8 pad[8]; f32 f8; u8 padc[4]; };

struct Vec_800BCA30 { f32 x, y, z; };

struct Vec_800BD10C { f32 x, y, z; };

struct VBase_18_800BD10C { char pad[0x18]; };

struct VObj_18_800BD10C : VBase_18_800BD10C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45();
    virtual s32 m46(s32);
};

struct Tgt_800BD10C : VObj_18_800BD10C {
    u8 pad1C[0x38 - 0x1C]; Vec_800BD10C pos; u8 pad44[0x2FC - 0x44]; Vec_800BD10C p2fc;
};

struct Grass_800BD10C {
    u8 pad0[0x30]; u32 flags30; u8 pad34[0x38 - 0x34]; Vec_800BD10C pos;
    u8 pad44[0x60 - 0x44]; s32 rotY; u8 pad64[0xB4 - 0x64]; u32 fb4; s16 fb8;
    u8 padBA[0x2A8 - 0xBA]; Tgt_800BD10C *target; u8 pad2AC[0x2FC - 0x2AC];
    Vec_800BD10C p2fc; u8 pad308[0x328 - 0x308]; s16 state; u8 pad32A[0x338 - 0x32A];
    u16 f338; u8 pad33A[2]; s16 timer; u8 pad33E[0x350 - 0x33E]; s32 *f350;
    u8 pad354[0x380 - 0x354]; Vec_800BD10C p380;
};

struct VBase_14_800BE8FC { char pad[0x14]; };

struct VObj_14_800BE8FC : VBase_14_800BE8FC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual s32 m5();
};

struct Vec_800BE8FC { f32 x, y, z; };

struct Param_800BE8FC { u8 pad0[4]; f32 speed; s32 turn; };

struct Grass_800BE8FC {
    u8 pad0[0x30];
    u32 flags30;
    u8 pad34[4];
    Vec_800BE8FC pos;
    Vec_800BE8FC prev;
    Vec_800BE8FC home;
    u8 pad5C[0x60 - 0x5C];
    s32 angle;
    u8 pad64[0xB8 - 0x64];
    s16 fB8;
    u8 padBA[0x290 - 0xBA];
    Vec_800BE8FC f290;
    Vec_800BE8FC f29C;
    u8 pad2A8[0x2FC - 0x2A8];
    Vec_800BE8FC f2FC;
    u8 pad308[0x328 - 0x308];
    s16 state;
    u8 pad32A[0x350 - 0x32A];
    Param_800BE8FC *param;
    u8 pad354[0x39C - 0x354];
    s16 f39C;
    u8 pad39E[0x3AC - 0x39E];
    s32 f3AC;
    VObj_14_800BE8FC sub;
};

struct O_800BFB68;
struct Vec_800BD4D8 { f32 x, y, z; };

struct VBase_18_800BD4D8 { char pad[0x18]; };

struct VObj_18_800BD4D8 : VBase_18_800BD4D8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17();
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual f32 m20(void *, f32);
    virtual void m21(); virtual void m22();
    virtual void m23(void *, f32);
};

struct Tgt_800BD4D8 {
    u8 pad0[0x2FC]; Vec_800BD4D8 p2fc;
};

struct Anim_800BD4D8 { u8 pad[8]; f32 f8; u8 padc[4]; };

struct Param_800BD4D8 { f32 range; f32 speed; s32 turn; };

struct Body_800BD4D8 { u8 pad[0xC]; f32 radius; };

struct Grass_800BD4D8 {
    u8 pad0[0x38];
    Vec_800BD4D8 pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0xA4 - 0x64];
    Body_800BD4D8 *body;
    u8 padA8[0xB4 - 0xA8];
    u32 fb4;
    s16 fb8;
    u8 padBA[0xC8 - 0xBA];
    f32 fc8;
    u8 padCC[0xD8 - 0xCC];
    Anim_800BD4D8 *anims;
    u8 padDC[0x29C - 0xDC];
    Vec_800BD4D8 f29c;
    Tgt_800BD4D8 *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec_800BD4D8 p2fc;
    f32 f308;
    u8 pad30C[4];
    f32 f310;
    u8 pad314[4];
    s32 f318;
    u8 pad31C[0x328 - 0x31C];
    s16 state;
    u8 pad32A[0x338 - 0x32A];
    u16 f338;
    u8 pad33A[2];
    s16 timer;
    u8 pad33E[0x350 - 0x33E];
    Param_800BD4D8 *param;
    u8 pad354[0x374 - 0x354];
    Vec_800BD4D8 f374;
    u8 pad380[0x398 - 0x380];
    f32 f398;
    u8 pad39C[0x3A4 - 0x39C];
    s32 f3a4;
    s32 f3a8;
    u8 pad3AC[0x3D4 - 0x3AC];
    VObj_18_800BD4D8 *hit[12];
};

struct VBase_14_fa0828 { char pad[0x14]; };

struct VObj_14_fa0828 : VBase_14_fa0828 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual s32 m3();
};

struct E1C_800BF924 { u8 pad[0x1C]; };

struct E2C_800BF924 { u8 pad[0x2C]; };

extern "C" {
void *spawn_particle_effect(void *pos, s32 id);
s32 apply_actor_gravity(void *, s32, f32);
s32 advance_animation_playback(void *);
s32 minimap_render_dot(void *, s32, s32, s32);
s32 play_persistent_sound(s32, void *, void *, s32, s32);
s32 play_sound_effect(void *, void *, int, int);
extern u32 TObjGrass__resource_bundle;
void TObjGrass__sub_800BFB68(O_800BFB68 *self);
void queue_destruction__7TObjectFv(void *arg0);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
extern u8 __vt__9TObjGrass[];
Obj_800BF880 *__dt__9TObjGrassFv(Obj_800BF880 *arg0, s16 arg1);
f32 step_toward_destination__10TObjPlayerFPvPvf(void *, Vec_800BE75C, f32);
s32 obj_setFlags30(void *, u32);
f32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, s32);
s32 push_matrix_from(void *);
s32 pop_matrices(int);
extern u8 identity_matrix[];
u16 find_nearest_visible_player(void *, int, f32);
s32 check_path_obstructed(void *, void *);
u8 *get_player_data__10TObjPlayerFi(s32);
s32 obj_testFlags30__14TObjCollidableFUl(void *, int);
s32 get_entity_id(void *);
s32 get_current_floor();
u8 *get_enemy_entity(u16);
u8 *get_player_by_client_id(u16);
s32 subtract_vector(void *, void *);
extern s32 lbl_8043B790[];
extern s32 registered_player_count;
extern s32 lbl_805D5870;
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
u8 *load_resource_from_descriptor(void *, int, void *, int, int, int);
u8 *load_enemy_bml_resource_named(void *, void *);
void draw_trail_with_colors(u8 *boss4_type3, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
u8 *init_trail_buffer__11TBoss4Type3FPvifff(void *, int, f32, f32, f32);
void *mem_alloc(u32 size);
extern Quad_800BF66C grass_spawn_descriptor;
extern s32 lbl_805D5140;
extern u32 TObjGrass__bml_resource;
extern s32 grass_combat_stats_handle;
extern s32 lbl_805D514C;
extern s32 TObjGrass__render_node_index;
extern u32 lbl_805D5158;
extern u32 lbl_805D515C;
void TObjGrass__sub_800BCA2C(void *);
s32 submit_cursor_candidate(void *, int);
f32 random_ratio__9TObjCharaFv(s32 arg0);
u32 lookup_entry_by_value__10TObjPlayerFPvf(void *);
s32 mult_vec_array__10TObjPlayerFUll(int, int, void *, int);
s32 scale_matrix(int, f32, f32, f32);
void set_matrix_identity(u8 *arg0);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
extern s32 enable_v2_features;
f32 enemy_move_toward(void *, s32, void *, s32, f32);
void enemy_pursue_point(void *, s32, void *, f32, f32);
f64 atan2_float(f32, f32);
f32 horizontal_distance_squared(void *, void *);
s32 angle_difference_abs(s32, s32);
}
void move_with_wall_slide(u8 *arg0);
extern "C" {
void TObjCGrass__ct(void *, void *, s32, s32);
void *__nw__7TObjectFUl(int);
f32 newton_sqrtf(f32);
s32 spawn_directional_particle(void *, void *, s32);
s32 TObjGrassWeb__ct(void *, s32, void *);
extern s32 game_difficulty_selection;
extern s32 tl_05;
void enemy_wander_home__9TObjEnemyFlfff(void *, s32, f32, f32, f32);
void enemy_set_heading_velocity(void *, s32, f32);
void enemy_turn_toward_dest(void *, s32);
f32 fabs_float(f32);
void TObjEneMe3SinowZoa__sub_800D758C(void *);
s32 approach_angle_limited(s32, s32, s32);
s32 project_actor_to_ground(void *, void *, s32);
extern Vec_800BE8FC scratch_vec;
extern Vec_800BE8FC lbl_8050BF00;
f32 get_collision_body_radius(void *, int);
s32 select_enemy_destination(void *, Vec_800BD4D8, int);
s32 copy_position_if_valid__10TObjPlayerFii(void *, Vec_800BD4D8);
s32 obj_is_hit_receivable(void *);
s32 is_split_screen();
extern s32 local_client_id;
s32 create__13TUnk_80494968FUlUl(int, int);
s32 set_param__9TObjEnemyFl(void *, int, int);
s32 __ct__9TObjEnemyFP7TObject(void *, s32, s32);
s32 init_collision_body_parts(void *, void *, int);
extern "C" u8 lbl_8043B6A0[];
extern "C" u8 lbl_8043B6B4[];
extern "C" u8 lbl_8043B6CC[];
extern "C" u8 lbl_8043B6E0[];
extern "C" u8 lbl_8043B6F8[];
extern "C" u8 lbl_8043B70C[];
extern "C" u8 lbl_8043B724[];
extern "C" u8 lbl_8043B738[];
extern "C" u8 lbl_8043B74C[];
extern "C" u8 lbl_8043B760[];
extern s32 lbl_805D2A38;
u8 *TObjGrass__ct(u8 *arg0, s32 arg1, s32 arg2);
void TLobby__sub_8001FE7C(void*, int);
void *__ct__11TObjControlFP7TObject(void *, void *);
s32 update_movement_status__9TObjCharaFv();
s32 update_action_hold_status__9TObjCharaFv();
s32 *__dt__11TBoss4Type3FPvs(s32 *arg0, s16 arg1);
void mem_free(void*);

extern "C" {
void vfunc_6__8TObjBaseFPsl();
}
extern "C" {
void get_name__8TObjBaseFv();
}
extern "C" {
void get_center__8TObjBaseFv();
}
extern "C" {
void *__dt__12TObjGrassWebFv(void *arg0, s16 arg1);
}
extern "C" {
void apply_object_set_data__8TObjBaseFPv();
}
extern "C" {
void classify_actor_view_detail__8TObjBaseFfff();
}
extern "C" {
extern u8 lbl_8043B6A0[];
}
extern "C" {
extern u8 lbl_8043B6B4[];
}
extern "C" {
extern u8 lbl_8043B6CC[];
}
extern "C" {
extern u8 lbl_8043B6E0[];
}
extern "C" {
extern u8 lbl_8043B6F8[];
}
extern "C" {
extern u8 lbl_8043B70C[];
}
extern "C" {
extern u8 lbl_8043B724[];
}
extern "C" {
extern u8 lbl_8043B738[];
}
extern "C" {
extern u8 lbl_8043B74C[];
}
extern "C" {
extern u8 lbl_8043B760[];
}
extern "C" {
void render_shadows__7TObjectFv();
}
extern "C" {
void reset_motion_fields__8TObjBaseFv();
}
extern "C" {
void run_task__12TObjGrassWebFv();
}
extern "C" {
void update_object_view_visibility__8TObjBaseFff();
}
extern void *bm_ene_grass_model_names[2];
extern void *bm_ene_grass_motion_names[9];
extern "C" {
 extern "C" u8 lbl_8043B6B4[]; extern "C" u8 lbl_8043B6CC[]; extern "C" u8 lbl_8043B6E0[];
}
extern "C" {
 extern "C" u8 lbl_8043B70C[]; extern "C" u8 lbl_8043B724[]; extern "C" u8 lbl_8043B738[];
}
extern "C" {
 extern "C" u8 lbl_8043B760[];
}
extern "C" {
extern void vfunc_6__8TObjBaseFPsl();  }
extern "C" {
extern void run_task__12TObjGrassWebFv(); }
__declspec(section ".data") void *bm_ene_grass_model_names[2] = {
    (void *)&lbl_8043B6A0, (void *)0x0,
};
void *bm_ene_grass_motion_names[9] = {
    (void *)&lbl_8043B6B4, (void *)&lbl_8043B6CC, (void *)&lbl_8043B6E0, (void *)&lbl_8043B6F8,
    (void *)&lbl_8043B70C, (void *)&lbl_8043B724, (void *)&lbl_8043B738, (void *)&lbl_8043B74C,
    (void *)0x0,
};
void *bm_ene_grass_resource_descriptor[4] = {
    (void *)&lbl_8043B760, (void *)&bm_ene_grass_model_names, (void *)&bm_ene_grass_motion_names, (void *)0x10008,
};
void *TObjGrass__grass_type_param_table[32] = {
    (void *)0x10000, (void *)0x6, (void *)0x3f333333, (void *)0x1,
    (void *)0x10001, (void *)0x7, (void *)0x3fa66666, (void *)0x1,
    (void *)0x20000, (void *)0x2, (void *)0x3f333333, (void *)0x4,
    (void *)0x20000, (void *)0x4, (void *)0x3f333333, (void *)0x4,
    (void *)0x20000, (void *)0x5, (void *)0x3f333333, (void *)0x4,
    (void *)0x20000, (void *)0x0, (void *)0x3f19999a, (void *)0x8,
    (void *)0x30005, (void *)0x1, (void *)0x3ecccccd, (void *)0x10,
    (void *)0x20001, (void *)0x3, (void *)0x3f000000, (void *)0x20,
};
void *lbl_804929E4[7] = {
    (void *)0x43c80000, (void *)0x3f400000, (void *)0x100, (void *)0x1e0000,
    (void *)0x0, (void *)0x1, (void *)0x0,
};
void *lbl_80492A00[11] = {
    (void *)0x0, (void *)0x41700000, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *__vt__12TObjGrassWeb[13] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__12TObjGrassWebFv, (void *)&run_task__12TObjGrassWebFv,
    (void *)&render__12TObjGrassWebFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__8TObjBaseFv, (void *)&get_center__8TObjBaseFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__8TObjBaseFv,
};
#define bm_ene_grass_resource_descriptor ((s32 *)bm_ene_grass_resource_descriptor)
#define TObjGrass__grass_type_param_table ((s32 *)TObjGrass__grass_type_param_table)

void TObjGrass__sub_800BCA2C(void * _w0) {  }

#pragma push
#pragma opt_common_subs off
#define arg0 ((u8 *)arg0_)
void TObjGrass::update_dying(void *arg0_) {
    obj_setFlags30(arg0, 0x04040000);
    advance_animation_playback(arg0);
    switch (((TObjEnePanarms *)arg0)->phase) {
    default:
        ((TObjEnePanarms *)arg0)->phase = 0;
    case 0:
        apply_actor_gravity(arg0, 0, (0.0f));
        if (objInBand((GameObj *)arg0, (f32)(0.0f)) != 0) {
            play_sound_effect((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003A804)), arg0 + 0x38, 0, 0);
            ((TObjEnePanarms *)arg0)->phase = 1;
        }
        break;
    case 1:
        move_with_wall_slide(arg0);
        *(f32 *)((s8 *)arg0 + 0x308) *= (0.5f);
        ((TObjEnePanarms *)arg0)->m_310 *= (0.5f);
        if (objInBand((GameObj *)arg0, (f32)(23.0f)) != 0) {
            ((TObjEnePanarms *)arg0)->phase = 2;
            spawn_particle_effect((arg0 + 0x38), 0xF0);
        }
        break;
    case 2:
        if (objInBand((GameObj *)arg0, (f32)(32.0f)) != 0) {
            Vec_800BCA30 v;
            v.y = (0.0f);
            v.x = (0.0f);
            v.z = (-15.0f);
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, ((TObjEnePanarms *)arg0)->rotation_y);
            rotate_vector_by_matrix(0, &v, &v);
            pop_matrices(1);
            vec3_add_to(&v, arg0 + 0x38);
            switch (get_current_floor_area()) {
            case AREA_CAVE1:
            case AREA_CAVE2:
            case AREA_CAVE3: {
                void *o = __nw__7TObjectFUl(0x14C);
                if (o != NULL) {
                    Vec_800BCA30 t = v;
                    TObjCGrass__ct(o, &t, (s32)((12.0f) + *(f32 *)((s8 *)arg0 + 0x360)), 0xF0);
                }
                break;
            }
            }
            play_sound_effect((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003AB0A)), arg0 + 0x38, 0, 0);
            TObjPlayer::spawn_dead_spot_default((s32)(arg0 + 0x38), 0xA);
            ((TObjPlayer *)(arg0 + 0x38))->spawn_ground_effect(0x1E);
        }
        ((TObjEnePanarms *)arg0)->scale.y -= 0.01f;
        if (((TObjEnePanarms *)arg0)->scale.y < 0.0f) {
            ((TObjEnePanarms *)arg0)->scale.y = 0.0f;
        }
        *(f32 *)((s8 *)arg0 + 0x35C) -= (0.01f);
        if (*(f32 *)((s8 *)arg0 + 0x35C) < (-5.0f)) {
            ((TObjEnePanarms *)arg0)->actorFlags |= 0x02000000;
            *(f32 *)((s8 *)arg0 + 0x35C) = (-5.0f);
            queue_destruction__7TObjectFv(arg0);
        }
        break;
    }
    if (((TObjEnePanarms *)arg0)->m_c0 < (32.0f)) {
        (*(s32 *)((s8 *)arg0 + 0x3A0))++;
        if (*(s32 *)((s8 *)arg0 + 0x3A0) == 4) {
            *(s32 *)((s8 *)arg0 + 0x3A0) = 0;
            spawn_particle_effect((arg0 + 0x38C), 0xF2);
        }
    }
}
#undef arg0
#pragma pop

Vec_800BF66C grass_camera_vec;
Vec_800BF66C grass_render_vec;
Vec_800BF66C grass_origin_vec;

extern u8 lbl_804FF5E8[];
void TObjGrass::update_camera_vec_by_stage() {
    Vec_800BF66C *v;

    switch (TObjGrass__render_node_index) {
    case 0x31:
        v = &grass_camera_vec;
        grass_camera_vec.x = (0.0f);
        v->y = (0.0f);
        v->z = (0.0f);
        TObjBoss2Tunnel::transform_vec_by_camera((s32)lbl_804FF5E8, (s32)v, (s32)v);
        break;
    case 0x32:
        break;
    case 0x34:
        break;
    case 0x35:
        v = &grass_render_vec;
        grass_render_vec.x = (0.0f);
        v->y = (0.0f);
        v->z = (0.0f);
        TObjBoss2Tunnel::transform_vec_by_camera((s32)lbl_804FF5E8, (s32)v, (s32)v);
        break;
    case 0x3F:
        break;
    case 0x49:
        break;
    case 0xC:
        v = &grass_origin_vec;
        grass_origin_vec.x = (0.0f);
        v->y = (0.0f);
        v->z = (0.0f);
        TObjBoss2Tunnel::transform_vec_by_camera((s32)lbl_804FF5E8, (s32)v, (s32)v);
        break;
    }
    TObjGrass__render_node_index++;
}

void TObjGrass::vfunc_63() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r6;
    if ((s16) *(s16 *)((s8 *)arg0 + 0x326) != 8) {
        *(s16 *)((s8 *)arg0 + 0x326) = 8;
        *(s16 *)((s8 *)arg0 + 0x328) = 0;
        *(s16 *)((s8 *)arg0 + 0xB8) = 6;
        temp_r6 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xA4));
        *(s32 *)((s8 *)temp_r6 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r6 + 0x18) & 0xFFFF7FFE);
        spawn_particle_effect((arg0 + 0x2FC), 0xF2);
        ((TObjPlayer *)arg0)->refresh_lobby_state();
        ((TObjEnemy *)arg0)->send_entity_set_flags();
    }
}

#pragma fp_contract on
s32 TObjGrass::sub_800BCE44() {
    u8 *arg0 = (u8 *)this;
  u8 *temp_r3;
  ((TObjBase *)arg0)->obj_clearFlags30((u32)(0x04040000));
  advance_animation_playback((void *) arg0);
  this->m_310 = (f32) (0.0f);
  *((f32 *) (((s8 *) arg0) + 0x308)) = (f32) (0.0f);
  apply_actor_gravity((void *)((void *) arg0), 0, (f32) (0.0f));
  ((TObjPlayer *)arg0)->update_collisions();
  if (objInBand((GameObj *)arg0, (f32) (0.0f)) != 0)
  {
    play_sound_effect((void *) ((s32)((TObjEnemy *)((void *)((void *) arg0)))->remap_sound_for_area((s32)(0x4003A603))), (u8 *)&this->position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
  }
  if ((this->m_b4) != 8U)
  {
    this->actorFlags = (s32) ((this->actorFlags) & 0xFFFFF9FF);
    temp_r3 = (u8 *)this->bodies;
    *((s32 *) (((s8 *) temp_r3) + 0x18)) = (s32) ((*((s32 *) (((s8 *) temp_r3) + 0x18))) & 0xFBFFFFFF);
    if ((this->hp) < ((this->hpmax) * (*((f32 *) (((s8 *) arg0) + 0x354)))))
    {
      this->actorFlags = (s32) ((this->actorFlags) | 0x2000);
      *((s32 *) (((s8 *) arg0) + 0x2A8)) = 0;
      this->targetId = (float) 0xFFFF;
      VecCopy((Vec *)(0x290 + arg0), (const Vec *)(arg0 + 0x2FC));
      VecCopy((Vec *)(arg0 + 0x29C), (const Vec *)(arg0 + 0x2FC));
      this->m_398 = (f32) (0.0f);
    }
    this->referenceHp = this->hp;
  }
  play_persistent_sound((s32)((void *) ((s32)((TObjEnemy *)((void *)((void *) arg0)))->remap_sound_for_area((s32)(0x4003A801)))), (void *)((void *) arg0), (u8 *)&this->position, (s32)((0) & 0xFFFFu), 0);
  TObjPlayer::play_effect_if_v2(-0x200);
  minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
}

void TObjGrass::vfunc_62() {
    if ((s16) this->mode != 7) {
        this->mode = 7;
        this->m_b8 = 5;
        this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
}

s32 TObjGrass::update() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r4;

    ((TObjBase *)arg0)->obj_clearFlags30((u32)(0x04040000));
    advance_animation_playback(arg0);
    if (!(*(s32 *)&this->actorFlags & 0x800000)) {
        apply_actor_gravity(arg0, 0, (0.0f));
    }
    ((TObjPlayer *)arg0)->update_collisions();
    play_persistent_sound(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003A801)), arg0, (u8 *)&this->position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
    temp_r4 = *(s16 *)&this->timer;
    *(s16 *)&this->timer = (temp_r4 - 1);
    if (temp_r4 < 0) {
        *(s32 *)&this->actorFlags = (s32) (*(s32 *)&this->actorFlags & 0xFFFFFEFF);
        *(s16 *)&this->timer = (s16) *(s16 *)&this->resetTimer;
        this->referenceHp = (s16) this->hp;
    }
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
}

void TObjGrass::vfunc_61() {
    if ((s16) this->mode != 6) {
        this->mode = 6;
        this->m_b8 = 0;
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFF9BFFFF);
}

s32 TObjGrass::update_web_attack() {
    Grass_800BD10C *arg0 = (Grass_800BD10C *)this;
    Vec_800BD10C v;
    Vec_800BD10C v2;
    s32 ang[3];
    if (arg0->f338 < 0x1000) {
        u8 *p = get_player_by_client_id(arg0->f338);
        if (p != NULL && ((TObjPlayer *)p)->get_field_3e4() == get_current_floor()) {
            arg0->target = (Tgt_800BD10C *)p;
        } else {
            arg0->target = NULL;
        }
    } else {
        arg0->f338 = 0xFFFF;
        arg0->target = NULL;
    }
    ((TObjBase *)arg0)->obj_clearFlags30(0x4040000);
    advance_animation_playback(arg0);
    switch (arg0->state) {
    case 0:
        if (arg0->target == NULL) {
            arg0->flags30 &= ~0x200000;
            arg0->timer = 0;
        } else {
            s32 d;
            VecCopy((Vec *)&v, (const Vec *)&arg0->target->p2fc);
            subtract_vector(&v, &arg0->p2fc);
            d = ((TObjEnemy *)arg0)->turn_toward_direction(arg0->f350[2], (Vec *)&v);
            apply_actor_gravity(arg0, 0, (0.0f));
            if (d < ((AttackParams *)(((u32 *)TObjGrass__bml_resource)[1]))->get_attack_angle()) {
                arg0->state = 1;
                arg0->fb8 = 4;
                arg0->timer = 0;
            }
        }
        break;
    case 1:
        play_persistent_sound(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x40039E07)), arg0, &arg0->pos, 0, 0);
        apply_actor_gravity(arg0, 0, (0.0f));
        if (arg0->target != NULL) {
            s32 d;
            VecCopy((Vec *)&v2, (const Vec *)&arg0->target->p2fc);
            subtract_vector(&v2, &arg0->p2fc);
            d = angle_difference_abs(arg0->rotY, (s32)((10430.38043493439) * atan2_float(v2.x, v2.z)));
            if (d < ((AttackParams *)(((u32 *)TObjGrass__bml_resource)[1]))->get_attack_angle()) {
                VecCopy((Vec *)&v2, (const Vec *)&arg0->target->pos);
                subtract_vector(&v2, &arg0->p380);
                ang[0] = (s32)((10430.38043493439) * atan2_float(v2.z, newton_sqrtf(v2.x * v2.x + v2.y * v2.y)));
                ang[1] = 0;
                ang[2] = -(s32)((10430.38043493439) * atan2_float(v2.x, v2.y));
                spawn_directional_particle(&arg0->p380, ang, 0xCA);
                if (arg0->fb4 != 4 && obj_testFlags30__14TObjCollidableFUl(arg0->target, 0x4000000) == 0) {
                    if (enable_v2_features == 1 && game_difficulty_selection == 3) {
                        arg0->target->m46(0);
                    } else {
                        void *m = __nw__7TObjectFUl(0xA8);
                        if (m != NULL) {
                            TObjGrassWeb__ct(m, tl_05, arg0->target);
                        }
                    }
                }
            } else {
                arg0->fb4 &= ~4;
            }
        } else {
            arg0->fb4 &= ~4;
        }
        if (arg0->fb4 != 4) {
            arg0->state = 2;
            arg0->fb8 = 1;
            arg0->timer = 0xF;
        }
        break;
    case 2:
        apply_actor_gravity(arg0, 0, (0.0f));
        arg0->timer--;
        if (arg0->timer < 0) {
            arg0->flags30 &= ~0x200000;
            arg0->timer = 0;
        }
        break;
    }
    ((TObjPlayer *)arg0)->update_collisions();
    play_persistent_sound(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003A801)), arg0, &arg0->pos, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
    minimap_render_dot(&arg0->pos, -0x5DB4, 1, 0);
}

#pragma push
#pragma opt_common_subs off
void TObjGrass::sub_800BD4D8() {
    Grass_800BD4D8 *o = (Grass_800BD4D8 *)this;
    if (o->f338 < 0x1000) {
        u8 *p = get_player_by_client_id(o->f338);
        if (p != NULL && ((TObjPlayer *)p)->get_field_3e4() == get_current_floor()) {
            o->target = (Tgt_800BD4D8 *)p;
        } else {
            o->target = NULL;
        }
    } else {
        o->f338 = 0xFFFF;
        o->target = NULL;
    }
    ((TObjBase *)o)->obj_clearFlags30(0x40000);
    if (o->target == NULL) {
        o->f338 = 0xFFFF;
        ((TObjBase *)o)->obj_clearFlags30(0x4202000);
        o->timer = 0;
        return;
    }
    switch (o->state) {
    default:
        o->state = 0;
    case 0:
        ((TObjBase *)o)->obj_clearFlags30(0x4000000);
        ((TObjCollidable *)o)->clear_player_status_flag(0, 0x80);
        play_persistent_sound(((TObjEnemy *)(o))->remap_sound_for_area((s32)(0x4003A801)), o, &o->pos, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x200);
        o->fc8 = (2.0f) * o->anims[o->fb8].f8;
        advance_animation_playback(o);
        apply_actor_gravity(o, 0, (0.0f));
        if (o->target != NULL) {
            Vec_800BD4D8 v;
            s32 d;
            VecCopy((Vec *)&v, (const Vec *)&o->target->p2fc);
            subtract_vector(&v, &o->p2fc);
            d = ((TObjEnemy *)o)->turn_toward_direction((s32)((2.0f) * (f32)o->param->turn), (Vec *)&v);
            if (d < ((AttackParams *)(o->f318))->get_attack_angle()) {
                s32 ang = (s32)((10430.38043493439) * atan2_float(v.x, v.z));
                o->f398 = (3e+01f) + (newton_sqrtf(TObjPlayer::calc_distance_to_client((s32)o, o->f338, (u32)0)) + get_collision_body_radius(o, 0));
                if (o->f398 < (1e+02f)) {
                    o->f398 = (1e+02f);
                }
                v.z = (0.0f);
                v.x = (0.0f);
                v.z = o->f398;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, ang);
                rotate_vector_by_matrix(0, &v, &v);
                pop_matrices(1);
                vec3_add_to(&v, &o->p2fc);
                if (select_enemy_destination(o, v, 1) != 0 || select_enemy_destination(o, o->target->p2fc, 1) != 0) {
                    o->state = 3;
                    o->fb8 = 7;
                    obj_setFlags30(o, 0x4000000);
                    ((TObjCollidable *)o)->set_indexed_flags(0, 0x80);
                    copy_position_if_valid__10TObjPlayerFii(o, o->p2fc);
                    play_sound_effect((void *)((TObjEnemy *)(o))->remap_sound_for_area((s32)(0x4003A806)), &o->pos, 0, 0);
                    TObjPlayer::play_effect_if_v2(-0x200);
                } else {
                    if (o->f338 == 0xFFFF) {
                        o->target = NULL;
                    } else {
                        o->state = 2;
                        o->fb8 = 0;
                        o->timer = 0x5A;
                    }
                    TObjGrass__sub_800BFB68((O_800BFB68 *)o);
                }
            }
        }
        break;
    case 3:
        obj_setFlags30(o, 0x4000000);
        ((TObjCollidable *)o)->set_indexed_flags(0, 0x80);
        advance_animation_playback(o);
        apply_actor_gravity(o, 0, (0.0f));
        if (o->fb4 != 0x20) {
            o->state = 1;
            o->fb8 = 1;
            ((TObjBase *)o)->obj_clearFlags30(0x4000000);
            ((TObjCollidable *)o)->clear_player_status_flag(0, 0x80);
        }
        break;
    case 1: {
        s32 k;
        s32 i;
        ((TObjBase *)o)->obj_clearFlags30(0x4000000);
        ((TObjCollidable *)o)->clear_player_status_flag(0, 0x80);
        o->fc8 = (2.0f) * o->anims[o->fb8].f8;
        advance_animation_playback(o);
        for (i = 0; i < 12; i++) {
            k = i * 4 + 0x3D4;
            if (*(VObj_18_800BD4D8 **)((u8 *)o + k) == NULL) {
                VObj_18_800BD4D8 *p = (VObj_18_800BD4D8 *)get_player_data__10TObjPlayerFi(i);
                if (p == NULL) {
                    break;
                }
                if ((u16)get_entity_id(p) >= 0x1000) {
                    break;
                }
                if (obj_is_hit_receivable(p) != 0 && ((TObjCollidable *)o)->find_actor_body_contact((u8*)p, (f32)((1e+04f))) != 0 &&
                    p->m18(o, (1.0f)) != 0) {
                    f32 dmg = p->m20(o, (1.0f));
                    obj_setFlags30(p, 0x400);
                    p->m23(o, (2.0f) * dmg);
                    if (is_split_screen() == 0 && local_client_id == (u16)get_entity_id(p)) {
                        TCameraCtrl::set_shake_preset(1);
                    }
                    *(VObj_18_800BD4D8 **)((u8 *)o + k) = p;
                }
            }
        }
        if (o->target != NULL) {
            Param_800BD4D8 *prm = o->param;
            f32 spd = (2.0f) * prm->speed;
            f32 d2;
            f32 t;
            if (enable_v2_features == 1 && game_difficulty_selection == 3) {
                spd *= (2.0f);
            }
            enemy_turn_toward_dest(o, (s32)((2.0f) * (f32)prm->turn));
            enemy_set_heading_velocity(o, o->angle, spd);
            move_with_wall_slide((u8 *)o);
            d2 = horizontal_distance_squared(&o->f29c, &o->p2fc);
            if (o->f338 == 0xFFFF) {
                o->f3a4++;
            }
            t = spd + o->body->radius;
            if (d2 < t * t || o->param->range * o->param->range < d2 || (1.5e+02f) < (f32)o->f3a4) {
                if (o->f338 == 0xFFFF) {
                    o->target = NULL;
                } else {
                    o->state = 2;
                    o->fb8 = 0;
                    o->timer = 0x5A;
                }
                TObjGrass__sub_800BFB68((O_800BFB68 *)o);
                o->f3a4 = 0;
            }
        }
        play_persistent_sound(((TObjEnemy *)(o))->remap_sound_for_area((s32)(0x4003A300)), o, &o->pos, 0, 0);
        if (o->f3a8 != 0) {
            Vec_800BD4D8 w;
            s32 ang[3];
            w.y = (0.0f);
            w.x = (0.0f);
            w.z = (4.0f);
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, o->angle);
            rotate_vector_by_matrix(0, &w, &w);
            pop_matrix();
            vec3_add_to(&o->f374, &w);
            ang[0] = -(s32)((10430.38043493439) * atan2_float(o->f310, newton_sqrtf(o->f308 * o->f308)));
            ang[1] = 0;
            ang[2] = (s32)((10430.38043493439) * atan2_float(o->f308, (0.0f)));
            spawn_directional_particle(&o->f374, ang, 0x150);
        }
        break;
    }
    case 2:
        ((TObjBase *)o)->obj_clearFlags30(0x4000000);
        ((TObjCollidable *)o)->clear_player_status_flag(0, 0x80);
        o->fc8 = (2.0f) * o->anims[o->fb8].f8;
        advance_animation_playback(o);
        apply_actor_gravity(o, 0, (0.0f));
        o->timer--;
        if (o->timer < 0) {
            ((TObjBase *)o)->obj_clearFlags30(0x200000);
            o->timer = 0;
            o->f338 = 0xFFFF;
            o->target = NULL;
        }
        break;
    }
    ((TObjCollidable *)o)->refresh_collision_body_centers();
    minimap_render_dot(&o->pos, -0x5DB4, 1, 0);
}
#pragma pop

void TObjGrass::sub_800BDD70() {
    u8 *arg0 = (u8 *)this;
    Vec_800BDD70 sp20;
    Vec_800BDD70 sp14;
    Vec_800BDD70 sp8;
    s32 ang;
    u32 ent;
    s32 idx;
    ((TObjBase *)arg0)->obj_clearFlags30(0x04040000);
    advance_animation_playback(arg0);
    switch (this->phase) {
    default:
        this->phase = 0;
    case 0:
        if (this->target == NULL) {
            *(s32 *)&this->actorFlags &= ~0x200000;
            *(s16 *)&this->timer = 0;
        } else {
            VecCopy((Vec *)&sp8, (const Vec *)(this->target + 0x2FC));
            subtract_vector(&sp8, (u8 *)&this->m_2fc);
            ang = ((TObjEnemy *)arg0)->turn_toward_direction(*(s32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 8), (Vec *)&sp8);
            apply_actor_gravity(arg0, 0, (0.0f));
            if (ang < ((AttackParams *)(*(s32 *)&this->m_318))->get_attack_angle()) {
                this->phase = 1;
                if ((0.5f) < random_ratio__9TObjCharaFv((s32)arg0)) {
                    this->m_b8 = 2;
                } else {
                    this->m_b8 = 3;
                }
            }
        }
        break;
    case 1:
        apply_actor_gravity(arg0, 0, (0.0f));
        if (objInBand((GameObj *)arg0, (f32)(14.0f)) != 0) {
            if (*(VObj_800BDD70 * *)&this->target != NULL && (*(VObj_800BDD70 * *)&this->target)->m18(arg0, (1.0f)) != 0) {
                (*(VObj_800BDD70 * *)&this->target)->m20(arg0, (1.0f));
                (*(VObj_800BDD70 * *)&this->target)->m23(arg0);
            }
            switch (get_current_floor_area()) {
            case AREA_CAVE1:
            case AREA_CAVE2:
            case AREA_CAVE3:
                play_sound_effect((void *)0x4003A60D, (u8 *)&this->position, 0, 0);
                break;
            case AREA_BATTLE1:
            case AREA_BATTLE2:
                if (enable_v2_features == 1) {
                    play_sound_effect((void *)0x30022, (u8 *)&this->position, 0, 0);
                }
                break;
            case AREA_PIONEER2_EP2:
                break;
            case AREA_VR_TEMPLE_ALPHA:
            case AREA_VR_TEMPLE_BETA:
                play_sound_effect((void *)0x3A316, (u8 *)&this->position, 0, 0);
                break;
            }
        }
        if (this->m_c0 < (2e+01f)) {
            switch (this->m_b8) {
            case 2:
                ent = lookup_entry_by_value__10TObjPlayerFPvf((void *)(*(s32 *)&lbl_805D5158));
                idx = 0;
                break;
            case 3:
                ent = lookup_entry_by_value__10TObjPlayerFPvf((void *)(*(s32 *)&lbl_805D515C));
                idx = 1;
                break;
            default:
                ent = 0;
                break;
            }
            if (ent != 0) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix((u8 *)&this->position);
                rotate_matrix_y(0, this->rotation_y);
                scale_matrix(0, (1.3f), (1.3f), (1.3f));
                mult_vec_array__10TObjPlayerFUll(0, ent, &sp14, 2);
                pop_matrix();
                if (((VObj_800BDD70 **)(arg0 + 0x3CC))[idx] != NULL) {
                    ((VObj_800BDD70 **)(arg0 + 0x3CC))[idx]->m4((s32 *)&sp14, (s32 *)&sp20);
                }
            }
        }
        if (this->m_b4 != 4U) {
            this->phase = 2;
            this->m_b8 = 0;
            *(s16 *)&this->timer = 0xF;
        }
        break;
    case 2:
        apply_actor_gravity(arg0, 0, (0.0f));
        (*(s16 *)&this->timer)--;
        if (*(s16 *)&this->timer < 0) {
            *(s32 *)&this->actorFlags &= ~0x200000;
            *(s16 *)&this->timer = 0;
        }
        break;
    }
    ((TObjPlayer *)arg0)->update_collisions();
    play_persistent_sound(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003A801)), arg0, (u8 *)&this->position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
}

void TObjGrass::vfunc_60() {

    switch (this->m_39e) {
    default:
        this->m_39e = 0;
    case 0:
        this->mode = 3;
        break;
    case 1:
        this->mode = 5;
        break;
    case 2:
        this->mode = 4;
        this->m_398 = (f32) (0.0f);
        TObjGrass__sub_800BFB68((O_800BFB68 *)(this));
        break;
    }
    this->phase = 0;
    this->m_b8 = 1;
    this->actorFlags = (s32) (this->actorFlags | 0x200000);
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
}

struct Vec_800BE1CC { f32 x, y, z; };
f32 calc_xz_distance_sq(void *, void *, Vec_800BE1CC *);
#define TBL ((u32 *)TObjGrass__bml_resource)
#define T318 (*(u32 *)((s8 *)(((u8 *)this)) + 0x318))
#define IN_RANGE() (dist <= (r + ((AttackParams *)T318)->get_attack_range()) * (r + ((AttackParams *)T318)->get_attack_range()) && ang <= ((AttackParams *)T318)->get_attack_angle())
#define BIND(n) (*(s16 *)((s8 *)(((u8 *)this)) + 0x39E)) = (n); bind_enemy_combat_stats((u8 *)0, (u8 *)(TBL[(*(s16 *)((s8 *)(((u8 *)this)) + 0x39E))]), (u8 *)0); return 1;

s32 TObjGrass::is_target_in_attack_range() {
    f32 dist;
    u8 *t;
    s32 ang;
    f32 r;
    u8 *tgt;
    s32 i;
    u16 kind;
    Vec_800BE1CC v;

    tgt = this->target;
    if (tgt != NULL && T318 != 0 && !(*(s32 *)((s8 *)tgt + 0x30) & 0x02000800)) {
    if (obj_testFlags30__14TObjCollidableFUl(this, 0x2000) != 0) {
        BIND(2)
    }
    dist = calc_xz_distance_sq(this, this->target, &v);
    ang = angle_difference_abs(this->rotation_y, (s32)((10430.38043493439) * atan2_float(v.x, v.z)));
    t = this->target;
    if (*(u8 **)((s8 *)t + 0xA4) != NULL) {
        r = *(f32 *)((s8 *)(*(u8 **)((s8 *)t + 0xA4)) + 0xC);
    } else {
        r = (1e+01f);
    }
    kind = get_entity_id(t);
    if (kind < 0x1000) {
        t = this->target;
        if (((TLobby *)t)->check_player_flag1() == 1 || (enable_v2_features == 1 && obj_testFlags30__14TObjCollidableFUl(t, 0x20) != 0)) {
            T318 = TBL[0];
            if (IN_RANGE()) {
                BIND(0)
            }
            return 0;
        }
        for (i = 0; i < 2; i++) {
            T318 = TBL[i];
            if (IN_RANGE()) {
                BIND(i)
            }
        }
    } else if (kind < 0x4000) {
        T318 = TBL[0];
        if (IN_RANGE()) {
            BIND(0)
        }
    }
    }
    return 0;
}

#undef BIND
#undef IN_RANGE
#undef T318
#undef TBL

#define arg0 ((u8 *)arg0_)
void TObjGrass::update_chase_target(void *arg0_) {
    f32 speed;
    f32 dist;
    s32 turn;
    Param_800BE4C0 *prm;
    ((TObjBase *)arg0)->obj_clearFlags30(0x04040000);
    prm = *(Param_800BE4C0 **)((s8 *)arg0 + 0x350);
    speed = prm->f4;
    turn = prm->f8;
    if (*(s32 *)((s8 *)arg0 + 0x30) & 0x2000) {
        speed *= (2.0f);
        *(f32 *)((s8 *)arg0 + 0xC8) = (2.0f) * (*(Anim_800BE4C0 **)((s8 *)arg0 + 0xD8))[*(s16 *)((s8 *)arg0 + 0xB8)].f8;
        { f32 ft = (f32)turn; ft *= (2.0f); turn = (s32)ft; }
        play_persistent_sound(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003A300)), arg0, arg0 + 0x38, 0, 0);
    } else {
        play_persistent_sound(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003A801)), arg0, arg0 + 0x38, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x200);
    }
    advance_animation_playback(arg0);
    if (*(u8 **)((s8 *)arg0 + 0x2A8) != NULL) {
        switch (*(s16 *)((s8 *)arg0 + 0x328)) {
        default:
            *(s16 *)((s8 *)arg0 + 0x328) = 0;
        case 0: {
            Vec_800BE4C0 v;
            Vec_800BE4C0 t = *(Vec_800BE4C0 *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC);
            dist = enemy_move_toward(arg0, turn, &t, 0, (0.125f) * speed);
            VecCopy((Vec *)&v, (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
            subtract_vector(&v, arg0 + 0x2FC);
            turn = angle_difference_abs(*(s32 *)((s8 *)arg0 + 0x60), (s32)((10430.38043493439) * atan2_float(v.x, v.z)));
            if (turn < ((AttackParams *)(*(s32 *)((s8 *)arg0 + 0x318)))->get_attack_angle()) {
                *(s16 *)((s8 *)arg0 + 0x328) = 1;
            }
            break;
        }
        case 1: {
            Vec_800BE4C0 t = *(Vec_800BE4C0 *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC);
            f32 r;
            enemy_pursue_point(arg0, turn, &t, speed, (4e+01f));
            dist = horizontal_distance_squared(arg0 + 0x29C, arg0 + 0x2FC);
            r = speed + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xA4)) + 0xC);
            if (dist < r * r) {
                if (*(u16 *)((s8 *)arg0 + 0x338) == 0xFFFF) {
                    *(u8 **)((s8 *)arg0 + 0x2A8) = NULL;
                } else {
                    *(s16 *)((s8 *)arg0 + 0x328) = 0;
                }
            }
            break;
        }
        }
        if ((*(Param_800BE4C0 **)((s8 *)arg0 + 0x350))->f0 * (*(Param_800BE4C0 **)((s8 *)arg0 + 0x350))->f0 < dist) {
            *(u8 **)((s8 *)arg0 + 0x2A8) = NULL;
        }
    }
    ((TObjPlayer *)arg0)->update_collisions();
    minimap_render_dot(arg0 + 0x38, -0x5DB4, 1, 0);
}
#undef arg0

s32 TObjGrass::sub_800BE75C() {
    Grass_800BE75C *o = (Grass_800BE75C *)this;
    Vec_800BE75C v;
    f32 d;
    f32 lo2;
    f32 hi2;
    obj_setFlags30(o, 0x04040000);
    advance_animation_playback(o);
    v.y = (0.0f);
    v.x = (0.0f);
    v.z = o->f358;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, o->f60);
    rotate_vector_by_matrix(0, &v, &v);
    pop_matrices(1);
    vec3_add_to(&v, o->mtx50);
    d = step_toward_destination__10TObjPlayerFPvPvf(o, v, (2.0f) * o->range->hi);
    lo2 = o->range->lo * o->range->lo;
    hi2 = o->range->hi * o->range->hi;
    if (lo2 < d || d < hi2) {
        o->f2A8 = 0;
        o->f39C = 0;
    }
    apply_actor_gravity(o, 0, (0.0f));
    play_persistent_sound(((TObjEnemy *)(o))->remap_sound_for_area((s32)(0x4003A801)), o, &o->pos, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
    minimap_render_dot(&o->pos, -0x5DB4, 1, 0);
}

void TObjGrass::vfunc_59() {
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 >= 3) || (temp_r0 < 1)) {
        this->m_b8 = 1;
        if ((s16) this->m_39c == 2) {
            this->mode = 1;
        } else {
            this->mode = 2;
        }
        this->phase = 0;
        obj_clearFlags30((u32)(0x04040000));
    }
}

#pragma push
#pragma opt_common_subs off
#define o ((Grass_800BE8FC *)arg0)
void TObjGrass::update_ai(void *arg0) {
    advance_animation_playback(o);
    switch (o->state) {
    case 0:
        obj_setFlags30(o, 0x04040000);
        TObjEneMe3SinowZoa__sub_800D758C(&o->sub);
        ((TBoss3Volopt *)(&o->pos))->play_area_sound_effect();
        o->state = 1;
        break;
    case 1:
        obj_setFlags30(o, 0x04040000);
        if (o->sub.m5() == 1) {
            o->state = 2;
            o->fB8 = 1;
            o->f3AC = 0;
        }
        break;
    default:
        o->state = 2;
    case 2:
        ((TObjBase *)o)->obj_clearFlags30(0x04040000);
        switch (o->f39C) {
        case 1:
            o->fB8 = 1;
            if ((1e+04f) < horizontal_distance_squared(&o->pos, &o->home)) {
                Vec_800BE8FC *d;
                Vec_800BE8FC *v;
                s32 ang;
                VecCopy((Vec *)&o->f29C, (const Vec *)&o->home);
                VecCopy((Vec *)&o->f290, (const Vec *)&o->f2FC);
                VecCopy((Vec *)&o->prev, (const Vec *)&o->pos);
                VecCopy((Vec *)&scratch_vec, (const Vec *)&o->home);
                subtract_vector(&scratch_vec, &o->pos);
                d = &scratch_vec;
                ang = (s32)((10430.38043493439) * atan2_float(d->x, d->z));
                v = &lbl_8050BF00;
                v->x = v->y = (0.0f);
                v->z = o->param->speed;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, ang);
                rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
                pop_matrices(1);
                vec3_add_to(&lbl_8050BF00, &o->pos);
                if (project_actor_to_ground(o, &lbl_8050BF00, 0) == 1) {
                    o->fB8 = 1;
                    VecCopy((Vec *)&o->pos, (const Vec *)&lbl_8050BF00);
                    o->angle = approach_angle_limited(o->angle, ang, o->param->turn);
                } else {
                    f32 r = fabs_float(d->z);
                    if (fabs_float(scratch_vec.x) < r) {
                        ang = (s32)((10430.38043493439) * atan2_float(scratch_vec.x, (0.0f)));
                    } else {
                        ang = (s32)((10430.38043493439) * atan2_float((0.0f), d->z));
                    }
                    v->y = (0.0f);
                    lbl_8050BF00.x = (0.0f);
                    v->z = o->param->speed;
                    push_matrix_from(identity_matrix);
                    rotate_matrix_y(0, ang);
                    rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
                    pop_matrices(1);
                    vec3_add_to(&lbl_8050BF00, &o->pos);
                    if (project_actor_to_ground(o, &lbl_8050BF00, 0) == 1) {
                        o->fB8 = 1;
                        VecCopy((Vec *)&o->pos, (const Vec *)&lbl_8050BF00);
                        o->angle = approach_angle_limited(o->angle, ang, o->param->turn);
                    } else {
                        s32 ang2;
                        r = fabs_float(d->z);
                        if (fabs_float(scratch_vec.x) < r) {
                            ang2 = (s32)((10430.38043493439) * atan2_float((0.0f), d->z));
                        } else {
                            ang2 = (s32)((10430.38043493439) * atan2_float(scratch_vec.x, (0.0f)));
                        }
                        v->y = (0.0f);
                        lbl_8050BF00.x = (0.0f);
                        v->z = o->param->speed;
                        push_matrix_from(identity_matrix);
                        rotate_matrix_y(0, ang2);
                        rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
                        pop_matrices(1);
                        vec3_add_to(&lbl_8050BF00, &o->pos);
                        if (project_actor_to_ground(o, &lbl_8050BF00, 0) == 1) {
                            o->fB8 = 1;
                            VecCopy((Vec *)&o->pos, (const Vec *)&lbl_8050BF00);
                            o->angle = approach_angle_limited(o->angle, ang2, o->param->turn);
                        } else {
                            o->fB8 = 1;
                        }
                    }
                }
                enemy_turn_toward_dest(o, o->param->turn);
                enemy_set_heading_velocity(o, o->angle, o->param->speed);
                move_with_wall_slide((u8 *)o);
            } else {
                ((void (*)(void *, f32, f32, f32, s32))enemy_wander_home__9TObjEnemyFlfff)(o, (0.25f) * o->param->speed, (1e+02f), (5e+01f), o->param->turn);
            }
            ((TObjCollidable *)o)->refresh_collision_body_centers();
            break;
        default:
            o->fB8 = 0;
            if (!(o->flags30 & 0x800000)) {
                apply_actor_gravity(o, 0, (0.0f));
            }
            break;
        }
        break;
    }
    minimap_render_dot(&o->pos, -0x5DB4, 1, 0);
    ((TObjBase *)o)->obj_clearFlags30(0x200000);
}
#undef o
#pragma pop

void TObjGrass::vfunc_58() {
    TObjGrass *self = this;
    switch (self->mode) {
    case 0:
        switch (self->phase) {
        case 0:
        case 1:
            break;
        default:
            self->phase = 2;
        case 2:
            if (*(s32 *)&self->m_3ac != 0) {
                self->phase = 0;
            }
            break;
        }
        break;
    default:
        self->mode = 0;
        if (*(s32 *)&self->m_3ac != 0) {
            self->phase = 0;
        } else {
            self->phase = 2;
        }
        self->m_b8 = 1;
        break;
    }
}

s32 TObjGrass::update_movement_status() {
    if (update_movement_status__9TObjCharaFv() != 0) {
        switch (this->mode) {
        case 0:
            this->m_3ac = 0;
            this->phase = 2;
            this->m_b8 = 1;
            obj_clearFlags30((u32)(0x04040000));
        }
        return 1;
    }
    return 0;
}

s32 TObjGrass::update_action_hold_status() {
    if (update_action_hold_status__9TObjCharaFv() != 0) {
        switch (this->mode) {
        case 0:
            this->m_3ac = 0;
            this->phase = 2;
            this->m_b8 = 1;
            obj_clearFlags30((u32)(0x04040000));
        }
        return 1;
    }
    return 0;
}

extern void *tl_04;

void TObjGrass::vfunc_28() {
    s32 best_id;
    s32 i;
    s32 id;
    u8 *p;
    f32 best;
    f32 d;
    u8 *q;
    u16 tid;
    u8 *arg0 = (u8 *)this;
    if (((TObjGrass *)(arg0))->is_actor_cadence_frame(0x1E) != 0) {
        if (*(s32 *)&this->m_3ac == 1) {
            this->targetId = 0xFFFFU;
            this->target = NULL;
            return;
        }
        if (obj_testFlags30__14TObjCollidableFUl(arg0, 0x10) != 0) {
            i = 0;
            best_id = 0xFFFF;
            Vec_800BEF8C v = *(Vec_800BEF8C *)lbl_8043B790;
            best = *(f32 *)((s8 *)(*(f32 * *)&this->movementParameters) + 0) * *(f32 *)((s8 *)(*(f32 * *)&this->movementParameters) + 0);
            for (; i < registered_player_count + lbl_805D5870; i++) {
                p = get_player_data__10TObjPlayerFi(i);
                if (p == NULL) {
                    break;
                }
                id = get_entity_id(p);
                if ((u16)id < 0x4000 && (u16)id != this->entity_id && !(*(s32 *)((s8 *)p + 0x30) & 0x02000800)) {
                    f32 xx;
                    f32 zz;
                    VecCopy((Vec *)&v, (const Vec *)(p + 0x2FC));
                    subtract_vector(&v, (u8 *)&this->m_2fc);
                    xx = v.x * v.x;
                    zz = v.z * v.z;
                    d = xx + zz;
                    if (d < best && check_path_obstructed(arg0, p + 0x2FC) != 1) {
                        best_id = id;
                        best = d;
                    }
                }
            }
            this->targetId = best_id;
        } else {
            this->targetId = find_nearest_visible_player(arg0, 0, *(f32 *)((s8 *)(*(f32 * *)&this->movementParameters) + 0));
        }
        tid = this->targetId;
        if (tid < 0x1000U) {
            q = get_player_by_client_id(tid);
            if (q != NULL) {
                if (((TObjPlayer *)q)->get_field_3e4() == get_current_floor()) {
                    this->target = q;
                    ((TObjBase *)arg0)->obj_clearFlags30(0x04040000);
                    return;
                }
            }
            this->target = NULL;
            return;
        }
        if (tid < 0x4000U) {
            this->target = get_enemy_entity(tid);
            ((TObjBase *)arg0)->obj_clearFlags30(0x04040000);
        }
    }
}

struct VBase_14_d701ad { char pad[0x14]; };
struct VObj_14_d701ad : VBase_14_d701ad {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6(s32, s32);
    virtual s32 m7();
    virtual s32 m8();
};
struct VBase_18_ca64a0 { char pad[0x18]; };
struct VObj_18_ca64a0 : VBase_18_ca64a0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual s32 m9(f32, f32, f32);
};

s32 render_with_position_override__9TObjEnemyFPUcl(void *, void *, int, f32);
void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
s32 defer_render__7TObjectFv(void *);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
void draw_chunk_object(void *child);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
struct Grass_800BF19C : VObj_18_ca64a0 {
    u8 pad1C[0x3B0 - 0x1C];
    VObj_14_d701ad sub;
};

void TObjGrass::render() {
    Grass_800BF19C *self = (Grass_800BF19C *)this;
    u8 *arg0 = (u8 *)self;

    if (*(s32 *)((s8 *)arg0 + 0x30) & 0x02000000) {
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x3A8) = self->m9((2.5e+02f), (5e+02f), (4e+01f));
    if (*(s32 *)((s8 *)arg0 + 0x3A8) == 0) {
        return;
    }
    select_actor_lighting((s32)self);
    TObjFish::set_global_param(*(s32 *)((s8 *)arg0 + 0x24));
    push_matrix();
    translate_matrix(0, (0.0f), *(f32 *)((s8 *)arg0 + 0x35C), (0.0f));
    post_translate_matrix(arg0 + 0x38);
    rotate_matrix_y(0, *(s32 *)((s8 *)arg0 + 0x60));
    scale_matrix(0, (1.3f), *(f32 *)((s8 *)arg0 + 0x6C), (1.3f));
    if (TObjPlayer::check_demo_mode() == 1) {
        draw_chunk_object((void *)(*(s32 *)((s8 *)arg0 + 0x34)));
    } else {
        TObjPlayer::toggle_particle_effect();
        TObjGrass__render_node_index = 0;
        TObjEneRe7Berura::set_global_state((s32)((void *)TObjGrass::update_camera_vec_by_stage));
        if (*(s32 *)((s8 *)arg0 + 0x3AC) == 1) {
            if ((&self->sub)->m8() != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                (&self->sub)->m6(chunk_polygon_flags_and_mask, model_render_flags);
                if (defer_render__7TObjectFv(self) == 0) {
                    ((TObjMotion *)self)->draw();
                }
                (&self->sub)->m7();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            }
        } else {
            model_render_flags |= 0x01000000;
            if (*(s32 *)((s8 *)arg0 + 0x3A8) == 1) {
                ((TObjMotion *)self)->draw();
            } else {
                ((TObjEnemy *)self)->render_world_model();
            }
            model_render_flags &= 0xFEFFFFFF;
        }
        TParticleCtrl::end_effect_render();
    }
    TObjEneRe7Berura::set_global_state((s32)NULL);
    pop_matrix();
    restore_scene_lighting();
    VecCopy((Vec *)(arg0 + 0x374), (const Vec *)&grass_camera_vec);
    VecCopy((Vec *)(arg0 + 0x380), (const Vec *)&grass_render_vec);
    VecCopy((Vec *)(arg0 + 0x38C), (const Vec *)&grass_origin_vec);
    switch (*(s16 *)((s8 *)arg0 + 0x326)) {
    case 0:
    case 1:
    case 8:
    case 9:
        break;
    default: {
        Vec_800BF66C v;
        v.x = (1.0f);
        v.y = (1.0f);
        v.z = (4.0f);
        render_with_position_override__9TObjEnemyFPUcl(self, &v, 0, (1.0f));
        break;
    }
    }
}

void TObjGrass::run_task() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r0;
    s32 temp_r30;
    u16 temp_r3;
    u8 *temp_r3_2;
    u8 *temp_r4;
    if (TObjPlayer::check_demo_mode() == 1) {
        TObjGrass__sub_800BCA2C(arg0);
        return;
    }
    temp_r3 = this->targetId;
    if (temp_r3 < 0x1000U) {
        temp_r3_2 = (u8 *)(get_player_by_client_id(temp_r3));
        if (temp_r3_2 != NULL) {
            if (((TObjPlayer *)temp_r3_2)->get_field_3e4() == get_current_floor()) {
                this->target = temp_r3_2;
                goto done;
            }
        }
        this->target = NULL;
    done:;
    } else if (temp_r3 < 0x4000U) {
        this->target = get_enemy_entity(temp_r3);
    } else {
        this->targetId = 0xFFFFU;
        this->target = NULL;
    }
    temp_r0 = this->mode;
    {
        switch (this->mode) {
        case 0:
            TObjGrass::update_ai(arg0);
            break;
        case 1:
            ((TObjGrass *)arg0)->sub_800BE75C();
            break;
        case 2:
            TObjGrass::update_chase_target(arg0);
            break;
        case 3:
            ((TObjGrass *)arg0)->sub_800BDD70();
            break;
        case 4:
            ((TObjGrass *)arg0)->sub_800BD4D8();
            break;
        case 5:
            update_web_attack();
            break;
        case 6:
            update();
            break;
        case 7:
            ((TObjGrass *)arg0)->sub_800BCE44();
            break;
        case 8:
            TObjGrass::update_dying(arg0);
            break;
        case 9:
            break;
        }
    }
    temp_r4 = this->target;
    if ((temp_r4 != NULL) && (*(s32 *)((s8 *)temp_r4 + 0x30) & 0x02000800)) {
        this->timer = 0;
        this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
        this->target = NULL;
    }
    ((TObjEnemy *)arg0)->update_prev_position();
    ((TBoss3VoloptHiraisin *)arg0)->copy_position();
    submit_cursor_candidate(arg0, -1);
    this->m_2b4 += (1.0f);
}

void *TObjGrass::create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x404);
    if (o2 != NULL) {
        o2 = TObjGrass__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

void TObjGrass::destroy_all() {
    if ((u32) TObjGrass__bml_resource != 0U) {
        mem_free((void*)TObjGrass__bml_resource);
        TObjGrass__bml_resource = 0U;
    }
    if ((u32) lbl_805D515C != 0U) {
        __dt__11TBoss4Type3FPvs((s32 *)lbl_805D515C, 1);
        lbl_805D515C = 0U;
    }
    if ((u32) lbl_805D5158 != 0U) {
        __dt__11TBoss4Type3FPvs((s32 *)lbl_805D5158, 1);
        lbl_805D5158 = 0U;
    }
    if ((u32) TObjGrass__resource_bundle != 0U) {
        TLobby__sub_8001FE7C((void*)TObjGrass__resource_bundle, 1);
        TObjGrass__resource_bundle = 0U;
    }
}

void TObjGrass::load_resources() {
    u8 *p;
    if (TObjEneDD::check_v2_mode() != 0) {
        TObjGrass__resource_bundle = (u32) load_enemy_bml_resource_named(bm_ene_grass_resource_descriptor, (void *)"bm_ene_grass_a.bml");
    } else {
        p = (u8 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, bm_ene_grass_resource_descriptor, 0, 0, 0);
        }
        TObjGrass__resource_bundle = (u32) p;
    }
    TObjGrass__render_node_index = 0;
    grass_origin_vec.x = grass_origin_vec.y = grass_origin_vec.z = (0.0f);
    p = (u8 *)::operator new(0x18);
    if (p != NULL) {
        p = init_trail_buffer__11TBoss4Type3FPvifff(p, 2, (0.0f), (2e+01f), (0.7f));
    }
    lbl_805D5158 = (u32) p;
    p = (u8 *)::operator new(0x18);
    if (p != NULL) {
        p = init_trail_buffer__11TBoss4Type3FPvifff(p, 2, (0.0f), (2e+01f), (0.7f));
    }
    lbl_805D515C = (u32) p;
    draw_trail_with_colors((u8 *)lbl_805D5158, (s32)(((Data_800BF66C *)TObjGrass__resource_bundle)->f42c->f8), (s32)(((Data_800BF66C *)TObjGrass__resource_bundle)->f430[TObjGrass__grass_type_param_table[9]].f4), 0x46, 0x48);
    draw_trail_with_colors((u8 *)lbl_805D515C, (s32)(((Data_800BF66C *)TObjGrass__resource_bundle)->f42c->f8), (s32)(((Data_800BF66C *)TObjGrass__resource_bundle)->f430[TObjGrass__grass_type_param_table[13]].f4), 0x3C, 0x3E);
    TObjGrass__bml_resource = (u32) mem_alloc(0xC);
    lbl_805D5140 = register_boss__6TLobbyFl(0x4E);
    ((s32 *) TObjGrass__bml_resource)[0] = dispatch_shared_handler_b__6TLobbyFl(0x51);
    ((s32 *) TObjGrass__bml_resource)[2] = dispatch_shared_handler_b__6TLobbyFl(0x52);
    ((s32 *) TObjGrass__bml_resource)[1] = dispatch_shared_handler_b__6TLobbyFl(0x53);
    grass_combat_stats_handle = register_object__6TLobbyFl(0x4D);
    lbl_805D514C = dispatch_shared_handler_a__6TLobbyFl(0x4D);
    {
    Quad_800BF66C q = grass_spawn_descriptor;
    q.a = (s32) ((Data_800BF66C *)TObjGrass__resource_bundle)->f430;
    TLobby::spawn_npc_enemy((s16)0x35, (s32)(((Data_800BF66C *)TObjGrass__resource_bundle)->f42c->f8), (s32)(((Data_800BF66C *)TObjGrass__resource_bundle)->f42c->fC), (s32)&q, (f32)((1e+01f)), (f32)((0.0f)));
    }
}

Obj_800BF880 *__dt__9TObjGrassFv(Obj_800BF880 *arg0, s16 arg1) {
    s32 i;
    if (arg0 != NULL) {
        i = 0;
        arg0->vt = __vt__9TObjGrass;
        do {
            if (arg0->items[i] != NULL) {
                queue_destruction__7TObjectFv(arg0->items[i]);
                arg0->items[i] = NULL;
            }
            i++;
        } while (i < 2);
        free_collision_body_parts(arg0);
        __dt__13TUnk_80494938Fv((u8 *)arg0 + 0x3B0, -1);
        __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TObjGrass__ct(u8 *arg0, s32 arg1, s32 arg2) {
    s32 t;
    __ct__9TObjEnemyFP7TObject(arg0, arg1, arg2);
    *(u8 **)((s8 *)arg0 + 0x18) = __vt__9TObjGrass;
    __ct__13TUnk_80494938Fv((arg0 + 0x3B0));
    *(s32 *)((s8 *)arg0 + 0) = lbl_805D2A38;
    ((TObjGrass *)(arg0))->apply_set_data((void *)arg2);
    ((TObjPlayer *)arg0)->init_position_vectors();
    apply_actor_gravity(arg0, 0, (0.0f));
    t = *(s32 *)((s8 *)TObjGrass__resource_bundle + 0x430);
    *(s32 *)((s8 *)arg0 + 0xDC) = t;
    ((TObjGrass *)arg0)->scale.y = (1.3f);
    *(s32 *)&((TObjGrass *)arg0)->variant = 0;
    set_param__9TObjEnemyFl(arg0, 0xC, t);
    *(s16 *)&((TObjGrass *)arg0)->resetTimer = 0x1E;
    *(s16 *)&((TObjGrass *)arg0)->timer = *(s16 *)&((TObjGrass *)arg0)->resetTimer;
    *(s32 *)&((TObjGrass *)arg0)->subtype = 0;
    ((TObjGrass *)arg0)->init_from_table_entry((s32)(*(s32 *)&((TObjGrass *)arg0)->variant));
    *(u8 * *)&((TObjGrass *)arg0)->action_table = (u8 *)TObjGrass__grass_type_param_table;
    ((TObjMotion *)arg0)->set_field_d8((s32)(*(u8 * *)&((TObjGrass *)arg0)->action_table));
    if ((0.0f) < *(f32 *)((s8 *)arg0 + 0x358)) {
        ((TObjGrass *)arg0)->m_39c = 2;
    } else {
        ((TObjGrass *)arg0)->m_39c = 1;
    }
    ((TObjGrass *)arg0)->m_b8 = 0;
    ((TObjMotion *)arg0)->set_animation(((TObjGrass *)arg0)->m_b8);
    ((TObjMotion *)arg0)->set_field_b8(((TObjGrass *)arg0)->m_b8);
    init_collision_body_parts(arg0, &((E2C_800BF924 *)lbl_80492A00)[*(s32 *)&((TObjGrass *)arg0)->variant], 1);
    ((TObjGrass *)arg0)->m_39e = 0;
    ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)lbl_805D5140, (u8 *)(((u32 *)TObjGrass__bml_resource)[((TObjGrass *)arg0)->m_39e]), (u8 *)grass_combat_stats_handle);
    *(u8 * *)&((TObjGrass *)arg0)->movementParameters = (u8 *)&((E1C_800BF924 *)lbl_804929E4)[*(s32 *)&((TObjGrass *)arg0)->variant];
    ((TObjGrass *)arg0)->referenceHp = ((TObjGrass *)arg0)->hp;
    ((TObjEnemy *)arg0)->update_prev_position();
    ((TBoss3VoloptHiraisin *)arg0)->copy_position();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TObjGrass *)arg0)->m_398 = (0.0f);
    ((TObjGrass *)arg0)->mode = 0;
    ((TObjGrass *)arg0)->phase = 0;
    *(s32 *)&((TObjGrass *)arg0)->m_3a0 = 0;
    TObjGrass__sub_800BFB68((O_800BFB68 *)(arg0));
    ((TObjChara *)arg0)->add_flags_2e4(2);
    obj_setFlags30(arg0, 0x04040000);
    ((VObj_14_fa0828 *)(arg0 + 0x3B0))->m3();
    *(s32 *)&((TObjGrass *)arg0)->m_3ac = 1;
    *(s32 *)&((TObjGrass *)arg0)->m_3cc = create__13TUnk_80494968FUlUl(0xA0303030, 0xFFFF0088);
    *(s32 *)&((TObjGrass *)arg0)->m_3d0 = create__13TUnk_80494968FUlUl(0xA0303030, 0xFFFF0088);
    *(s32 *)&((TObjGrass *)arg0)->m_3a8 = 0;
    ((TObjGrass *)(arg0))->clear_lobby_object_state();
    return arg0;
}

void TObjGrass__sub_800BFB68(O_800BFB68 *self) {
    s32 i;
    for (i = 0; i < 12; i++) {
        self->arr[i] = 0;
    }
}

void TObjGrass::init_from_table_entry(s32 i) {
    O_800BFB8C *self = (O_800BFB8C *)this;
    self->f34 = (*(D_800BFB8C * *)&TObjGrass__resource_bundle)->entries[i].f8;
    self->f24 = (*(D_800BFB8C * *)&TObjGrass__resource_bundle)->entries[i].fc;
}
}
