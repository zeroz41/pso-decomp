#include "types.h"
#include "pso/TObject.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/object/TObjOnlineEnding.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/CurrentArea.h"

extern "C" {

void TWindow__close(u8 *arg0);
void *__nw__7TObjectFUl(int);

    extern int player_unique_pair_entry_count;
extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void get_name__8TObjBaseFv();
extern "C" void get_center__8TObjBaseFv();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" u8 lbl_804729C8[];
extern "C" u8 lbl_804729DC[];
extern "C" u8 lbl_804729EC[];
extern "C" u8 lbl_804729FC[];
extern "C" u8 lbl_80472A0C[];
extern "C" u8 lbl_80472A1C[];
extern "C" u8 lbl_80472A2C[];
extern "C" u8 lbl_80472A3C[];
extern "C" u8 lbl_80472A4C[];
extern "C" u8 lbl_80472A5C[];
extern "C" u8 lbl_80472A6C[];
extern "C" u8 lbl_80472A7C[];
extern "C" u8 lbl_80472A8C[];
extern "C" u8 lbl_80472A9C[];
extern "C" u8 lbl_80472AAC[];
extern "C" u8 lbl_80472ABC[];
extern "C" u8 lbl_80472ACC[];
extern "C" u8 lbl_80472ADC[];
extern "C" u8 lbl_80472AEC[];
extern "C" u8 lbl_80472AFC[];
extern "C" u8 lbl_80472B0C[];
extern "C" u8 lbl_80472B1C[];
extern "C" u8 lbl_80472B2C[];
extern "C" u8 lbl_80472B3C[];
extern "C" u8 lbl_80472B4C[];
extern "C" u8 lbl_80472B5C[];
extern "C" u8 lbl_80472B70[];
extern "C" void render_shadows__7TObjectFv();
extern "C" void reset_motion_fields__8TObjBaseFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
struct Obj_802E4E44;
struct Obj_802E4C70;
void *destroy__16TObjOnlineEndingFPvs(void *arg0, s16 arg1);
void run_task__16TObjOnlineEndingFv(Obj_802E4E44 *arg0);
void render__16TObjOnlineEndingFv(Obj_802E4C70 *arg0);
extern void *onlineending_dat_model_names[2];
extern void *onlineending_dat_motion_names[26];
__declspec(section ".data") void *onlineending_dat_model_names[2] = {
    (void *)&lbl_804729C8, (void *)0x0,
};
void *onlineending_dat_motion_names[26] = {
    (void *)&lbl_804729DC, (void *)&lbl_804729EC, (void *)&lbl_804729FC, (void *)&lbl_80472A0C,
    (void *)&lbl_80472A1C, (void *)&lbl_80472A2C, (void *)&lbl_80472A3C, (void *)&lbl_80472A4C,
    (void *)&lbl_80472A5C, (void *)&lbl_80472A6C, (void *)&lbl_80472A7C, (void *)&lbl_80472A8C,
    (void *)&lbl_80472A9C, (void *)&lbl_80472AAC, (void *)&lbl_80472ABC, (void *)&lbl_80472ACC,
    (void *)&lbl_80472ADC, (void *)&lbl_80472AEC, (void *)&lbl_80472AFC, (void *)&lbl_80472B0C,
    (void *)&lbl_80472B1C, (void *)&lbl_80472B2C, (void *)&lbl_80472B3C, (void *)&lbl_80472B4C,
    (void *)&lbl_80472B5C, (void *)0x0,
};
void *lbl_804E35E8[4] = {
    (void *)&lbl_80472B70, (void *)&onlineending_dat_model_names, (void *)&onlineending_dat_motion_names, (void *)0x10019,
};
void *lbl_804E35F8[240] = {
    (void *)0xc1973333, (void *)0xc1000000, (void *)0xc1100000, (void *)0x24fa,
    (void *)0x3fa00000, (void *)0x40bb3333, (void *)0xc1000000, (void *)0xc1100000,
    (void *)0x0, (void *)0x3fa00000, (void *)0xc0bb3333, (void *)0xc1500000,
    (void *)0xc1100000, (void *)0x717, (void *)0x3fa00000, (void *)0x419acccd,
    (void *)0xc1500000, (void *)0xc1100000, (void *)0x2b12, (void *)0x3fa00000,
    (void *)0xc1900000, (void *)0xc0c00000, (void *)0xc1200000, (void *)0x14b4f,
    (void *)0x3fa00000, (void *)0x40d80000, (void *)0xc0c00000, (void *)0xc1200000,
    (void *)0x8342, (void *)0x3fa00000, (void *)0xc0c99999, (void *)0xc1280000,
    (void *)0xc1200000, (void *)0xffffef4c, (void *)0x3fa00000, (void *)0x419e6666,
    (void *)0xc1300000, (void *)0xc1200000, (void *)0xffffccaa, (void *)0x3fa00000,
    (void *)0xc1939999, (void *)0xc0d00000, (void *)0xc10fffe6, (void *)0x163e,
    (void *)0x3f99999a, (void *)0x40c99999, (void *)0xc0d00000, (void *)0xc10fffe6,
    (void *)0xffffe92f, (void *)0x3f99999a, (void *)0xc0bb3333, (void *)0xc1400000,
    (void *)0xc0afffcc, (void *)0xca1, (void *)0x3f99999a, (void *)0x41819999,
    (void *)0xc1580000, (void *)0xc0afffcc, (void *)0xfffff639, (void *)0x3f99999a,
    (void *)0xc1900000, (void *)0xc0f00000, (void *)0xc1080000, (void *)0x303,
    (void *)0x3fa00000, (void *)0x40bb3333, (void *)0xc0f00000, (void *)0xc1080000,
    (void *)0xffffe063, (void *)0x3fa00000, (void *)0xc0d80000, (void *)0xc1600000,
    (void *)0xc1280000, (void *)0xffffcc42, (void *)0x3fa00000, (void *)0x419acccd,
    (void *)0xc1600000, (void *)0xc1280000, (void *)0x1bb4, (void *)0x3fa00000,
    (void *)0xc19acccd, (void *)0xc0e00000, (void *)0xc1100000, (void *)0xffffd6d7,
    (void *)0x3f800000, (void *)0x40d80000, (void *)0xc0d00000, (void *)0xc1100000,
    (void *)0xfffffcbb, (void *)0x3f800000, (void *)0xc0900000, (void *)0xc1600000,
    (void *)0xc1100000, (void *)0x2913, (void *)0x3f800000, (void *)0x41939999,
    (void *)0xc1680000, (void *)0xc1100000, (void *)0xffffe984, (void *)0x3f800000,
    (void *)0xc1939999, (void *)0xc0c00000, (void *)0xc1100000, (void *)0x1fc7,
    (void *)0x3fa00000, (void *)0x40c99999, (void *)0xc0b00000, (void *)0xc1100000,
    (void *)0x0, (void *)0x3fa00000, (void *)0xc0c99999, (void *)0xc1400000,
    (void *)0xc1100000, (void *)0xffffe37b, (void *)0x3fa00000, (void *)0x419e6666,
    (void *)0xc1380000, (void *)0xc1100000, (void *)0x54b, (void *)0x3fa00000,
    (void *)0xc1939999, (void *)0xc0b00000, (void *)0xc1200000, (void *)0xffffcf1c,
    (void *)0x3fa00000, (void *)0x40d80000, (void *)0xc0c00000, (void *)0xc1200000,
    (void *)0xffffe5ed, (void *)0x3fa00000, (void *)0xc0d80000, (void *)0xc1400000,
    (void *)0xc1200000, (void *)0x0, (void *)0x3fa00000, (void *)0x41939999,
    (void *)0xc1480000, (void *)0xc1200000, (void *)0xffffd813, (void *)0x3fa00000,
    (void *)0xc19e6666, (void *)0xc1000000, (void *)0xc1200000, (void *)0x1e8e,
    (void *)0x3fa00000, (void *)0x40bb3333, (void *)0xc0f00000, (void *)0xc1200000,
    (void *)0xfffff2f7, (void *)0x3fa00000, (void *)0xc0f4cccc, (void *)0xc18c0000,
    (void *)0xc1200000, (void *)0x3488, (void *)0x3fa00000, (void *)0x41939999,
    (void *)0xc1840000, (void *)0xc1200000, (void *)0xffff1208, (void *)0x3fa00000,
    (void *)0xc1973333, (void *)0xc1080000, (void *)0xc1180000, (void *)0x3013,
    (void *)0x3fa00000, (void *)0x40bb3333, (void *)0xc0d00000, (void *)0xc1180000,
    (void *)0x14c7, (void *)0x3fa00000, (void *)0xc0bb3333, (void *)0xc1400000,
    (void *)0xc1180000, (void *)0x138e, (void *)0x3fa00000, (void *)0x419acccd,
    (void *)0xc1500000, (void *)0xc1180000, (void *)0xffffed43, (void *)0x3fa00000,
    (void *)0xc18c9c21, (void *)0xc0800000, (void *)0xc0630da6, (void *)0x6d,
    (void *)0x3fa00000, (void *)0x40b6df66, (void *)0xc0800000, (void *)0xc0630da6,
    (void *)0xffffd4a0, (void *)0x3fa00000, (void *)0xc0c8f15a, (void *)0xc1480000,
    (void *)0xc048c4ce, (void *)0x0, (void *)0x3fa00000, (void *)0x41865c5c,
    (void *)0xc1480000, (void *)0xc048c4ce, (void *)0xffffe71d, (void *)0x3fa00000,
    (void *)0xc19ee664, (void *)0xc0e00000, (void *)0xc16238fa, (void *)0xffff8aab,
    (void *)0x3fa00000, (void *)0x40c99999, (void *)0xc0e00000, (void *)0xc16238fa,
    (void *)0xffffddde, (void *)0x3fa00000, (void *)0xc0d3a8e0, (void *)0xc1480000,
    (void *)0xc15a4b1f, (void *)0xffffd1c8, (void *)0x3fa00000, (void *)0x41a05878,
    (void *)0xc1480000, (void *)0xc15a4b1f, (void *)0xffffb334, (void *)0x3fa00000,
    (void *)0xc198c6f3, (void *)0xc075318c, (void *)0xc0fb0279, (void *)0x1c71,
    (void *)0x3fa00000, (void *)0x40ba0de5, (void *)0xc075318c, (void *)0xc0fb0279,
    (void *)0x555, (void *)0x3fa00000, (void *)0xc0ca1e2a, (void *)0xc144c54e,
    (void *)0xc0ee567a, (void *)0xffffc9f5, (void *)0x3fa00000, (void *)0x4192ecab,
    (void *)0xc144c54e, (void *)0xc0ee567a, (void *)0xffffde94, (void *)0x3fa00000,
};
void *lbl_804E39B8[24] = {
    (void *)0x0, (void *)0x1, (void *)0x2, (void *)0x3,
    (void *)0x4, (void *)0x5, (void *)0x6, (void *)0x7,
    (void *)0x8, (void *)0x9, (void *)0xa, (void *)0xb,
    (void *)0xc, (void *)0xd, (void *)0xe, (void *)0xf,
    (void *)0x10, (void *)0x11, (void *)0x12, (void *)0x13,
    (void *)0x14, (void *)0x15, (void *)0x16, (void *)0x17,
};
void *lbl_804E3A18[4] = {
    (void *)0x2, (void *)0x1, (void *)0x0, (void *)0x3,
};
void *lbl_804E3A28[4] = {
    (void *)0x1, (void *)0x0, (void *)0x0, (void *)0x1,
};
void *lbl_804E3A38[3] = {
    (void *)0x469c4000, (void *)0x0, (void *)0x0,
};
void *online_ending_quad_vertices[8] = {
    (void *)0x43800000, (void *)0x0, (void *)0x43c00000, (void *)0x0,
    (void *)0x43000000, (void *)0x0, (void *)0x44008000, (void *)0x0,
};
void *__vt__16TObjOnlineEnding[13] = {
    (void *)0x0, (void *)0x0, (void *)&destroy__16TObjOnlineEndingFPvs, (void *)&run_task__16TObjOnlineEndingFv,
    (void *)&render__16TObjOnlineEndingFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__8TObjBaseFv, (void *)&get_center__8TObjBaseFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__8TObjBaseFv,
};
#define lbl_804E3A38 ((f32 *)lbl_804E3A38)
#define online_ending_quad_vertices ((V2_802E4C70 *)online_ending_quad_vertices)
#define __vt__16TObjOnlineEnding ((const s32 *)__vt__16TObjOnlineEnding)

int TObjOnlineEnding::get_instance() {  return player_unique_pair_entry_count; }

    extern unsigned char lbl_8050DAD0[];
void*TObjOnlineEnding::get_attack_entry(int a0) {  return (char*)lbl_8050DAD0 + a0 * 8; }

void TObjOnlineEnding::close_window() { if (*(unsigned int *)&this->m_154 != 0) { TWindow__close((u8 *)(*(void* *)&this->m_154)); *(int *)&this->m_154 = 0; } }

}

struct Vec_802E4E44 { f32 x, y, z; };

struct Ent_802E4E44 { s32 active; u16 id; u8 pad[0x28 - 6]; };

struct Obj_802E4E44 {
    u8 pad0[0xA4];
    s32 state;
    Ent_802E4E44 ent[4];
    s32 count;
    s32 timer;
    f32 fade;
};

struct Cam_802E4E44 {
    u8 pad0[0x14];
    s32 f14;
    u8 pad18[4];
    Vec_802E4E44 a;
    Vec_802E4E44 b;
    u8 pad34[0x8];
};

struct V2_802E4C70 { f32 x, y; };

struct Ent_802E4C70 { s32 active; u16 id; u8 name[0x12]; void *f18; s32 f1C; f32 f20; s32 f24; };

struct Obj_802E4C70 {
    u8 pad0[0x90];
    s32 f90;
    s32 f94;
    s32 f98;
    u8 pad9C[0xA8 - 0x9C];
    Ent_802E4C70 ent[4];
    s32 count;
    u8 pad14C[4];
    f32 f150;
};

extern "C" {
void *get_player_by_client_id(s32 i);
s32 activate_camera_mode(s32);
void set_active_camera_pose_from_params(u8 *arg0);
void queue_destruction__7TObjectFv(void *arg0);
extern Vec_802E4E44 lbl_80472B9C;
extern Vec_802E4E44 lbl_80472BA8;
u32 calc_text_width(char *s);
s32 render_status_line__15TAdSubPlyItemGCFi(void *, int, f32, f32, f32);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
extern const f32 online_ending_scene_scale;
extern f32 online_ending_quad_y_offset;
extern f32 online_ending_scene_z_offset;
extern s8 online_ending_scene_translation_initialized;
extern s8 online_ending_quad_vertices_initialized;
extern const f32 lbl_805DE930;
extern const f32 lbl_805DE934;
extern const f32 lbl_805DE938;
extern const f32 lbl_805DE93C;
extern const f32 lbl_805DE940;
extern const f32 lbl_805DE944;
s32 restore_player_cameras();
s32 TLobby__sub_80070ACC();
s32 TWindowChallengeResult__ct(s32, s32, s32, s32);
s32 TWindowSubStatusDisp__sub_800718D0();
s32 __dl__7TObjectFPv(void *);
s32 get_card_window_value__16TObjOnlineEndingFv();
s32 get_layout_id__20TWindowSubStatusDispFv(s32);
s32 is_flag_set__6TLobbyFv();

void TObjOnlineEnding::create_result_window() {
    s32 temp_r31;
    s32 temp_r30_2;
    s32 temp_r30;
    s32 var_r29;

    this->m_154 = 0;
    if (is_flag_set__6TLobbyFv() != 0) {
        temp_r30 = get_layout_id__20TWindowSubStatusDispFv(-1) - 1;
        {
        s32 t = TLobby::get_online_result_value();
        if (t == temp_r30) {
            var_r29 = (s32)__nw__7TObjectFUl(0x68);
            if (var_r29 != 0) {
                temp_r30_2 = get_card_window_value__16TObjOnlineEndingFv();
                temp_r31 = TWindowSubStatusDisp__sub_800718D0();
                var_r29 = TWindowChallengeResult__ct(var_r29, TLobby__sub_80070ACC(), temp_r31, temp_r30_2);
            }
            this->m_154 = var_r29;
        }
        }
    }
}

void TObjOnlineEnding::render() {
    Obj_802E4C70 *arg0 = (Obj_802E4C70 *)this;
    s32 i;
    Ent_802E4C70 *e;
    if (online_ending_scene_translation_initialized == 0) {
        lbl_804E3A38[2] = lbl_805DE930 + online_ending_scene_z_offset;
        online_ending_scene_translation_initialized = 1;
    }
    TParticleCtrl::begin_effect_render();
    push_matrix();
    post_translate_matrix(lbl_804E3A38);
    scale_matrix(0, online_ending_scene_scale, lbl_805DE934, lbl_805DE934);
    TObjFish::set_global_param(*(s32 *)&this->m_94);
    draw_model_motion((void *)*(s32 *)&this->m_90, (void *)*(s32 *)&this->m_98, arg0->f150);
    pop_matrix();
    for (i = 0; i < *(s32 *)&this->m_148; i++) {
        e = &arg0->ent[i];
        if (e->active != 0) {
            if (online_ending_quad_vertices_initialized == 0) {
                online_ending_quad_vertices[0].y = lbl_805DE938 + online_ending_quad_y_offset;
                online_ending_quad_vertices[1].y = lbl_805DE93C + online_ending_quad_y_offset;
                online_ending_quad_vertices[2].y = lbl_805DE93C + online_ending_quad_y_offset;
                online_ending_quad_vertices[3].y = lbl_805DE938 + online_ending_quad_y_offset;
                online_ending_quad_vertices_initialized = 1;
            }
            {
                u8 *name = e->name;
                u32 w = calc_text_width((char *)name);
                V2_802E4C70 v = online_ending_quad_vertices[i];
                v.x -= (f32)(w >> 1);
                render_status_line__15TAdSubPlyItemGCFi(name, -1, v.x, v.y, lbl_805DE940);
            }
            push_matrix();
            post_translate_matrix(lbl_804E3A38);
            post_translate_matrix(e->f18);
            rotate_matrix_y(0, e->f1C);
            scale_matrix(0, e->f20, e->f20, e->f20);
            TObjPlayer::draw_player_model_by_client(e->id, e->f24, lbl_805DE944, lbl_805DE934);
            pop_matrix();
        }
    }
    TParticleCtrl::end_effect_render();
}

void TObjOnlineEnding::run_task() {
    Obj_802E4E44 *arg0 = (Obj_802E4E44 *)this;
    s32 i;
    for (i = 0; i < arg0->count; i++) {
        if (arg0->ent[i].active != 0 && get_player_by_client_id(arg0->ent[i].id) == 0) {
            arg0->ent[i].active = 0;
        }
    }
    switch (arg0->state) {
    case 0:
        arg0->state = 1;
        break;
    case 1: {
        activate_camera_mode(9);
        Vec_802E4E44 t1 = lbl_80472B9C;
        Vec_802E4E44 t2 = lbl_80472BA8;
        Cam_802E4E44 cam;
        VecCopy((Vec *)&cam.a, (const Vec *)&t1);
        VecCopy((Vec *)&cam.b, (const Vec *)&t2);
        cam.f14 = 0x1999;
        set_active_camera_pose_from_params((u8 *)&cam);
        arg0->state = 2;
        break;
    }
    default:
        if ((arg0->fade += 0.3f) >= 17.0f) {
            arg0->fade = 17.0f;
        }
        if (++arg0->timer >= 450) {
            queue_destruction__7TObjectFv(arg0);
        }
        break;
    }
}

void *destroy__16TObjOnlineEndingFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(const s32 **)((s8 *)arg0 + 0x18) = __vt__16TObjOnlineEnding;
        ((TObjOnlineEnding *)arg0)->close_window();
        restore_player_cameras();
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

struct TObject_802E4FFC;
struct Tbl_802E4FFC { u8 pad[0xC]; s32 fC; f32 f10; };
struct Ent_802E4FFC { s32 active; s16 id; char name[0x12]; Tbl_802E4FFC *f18; s32 f1C; f32 f20; s32 f24; };
struct Obj_802E4FFC {
    void *f0;
    u8 pad4[0x14];
    void *vt;
    u8 pad1C[0x90 - 0x1C];
    s32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
    s32 fA0;
    s32 fA4;
    Ent_802E4FFC ent[4];
    s32 count;
    s32 f14C;
    f32 f150;
};

s32 get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
void __ct__8TObjBaseFP7TObject(void *, void *);
void play_area_music(char *name);
void *fn_802E6218(void *arg0);
void fn_802E6260();
char *strncpy(char *, const char *, unsigned long);
extern u8 lbl_80472BC0[];
extern u8 lbl_80472BD0[];
extern void *TObjOnlineEnding__name;
extern u32 lbl_805D68F4;
extern const f32 lbl_805DE950;
#pragma push
#pragma opt_common_subs off
#define SELF ((Obj_802E4FFC *)arg0)
void *TObjOnlineEnding__ct(void *arg0, void *parent) {
    s32 i;
    u8 *pl;
    Ent_802E4FFC *e;
    TObject_802E4FFC *obj;

    __ct__8TObjBaseFP7TObject(arg0, parent);
    SELF->vt = (void *)__vt__16TObjOnlineEnding;
    SELF->f0 = TObjOnlineEnding__name;
    SELF->fA0 = get_current_area();
    SELF->f9C = 0;
    obj = (TObject_802E4FFC *)arg0;
    switch (SELF->fA0) {
    case 14:
        SELF->f9C = 0;
        break;
    case 31:
        SELF->f9C = 1;
        break;
    default:
        queue_destruction__7TObjectFv(obj);
        return arg0;
    }
    SELF->f90 = get_bml_model(lbl_805D68F4, 0);
    SELF->f94 = TObjFish__sub_8001EDB0(lbl_805D68F4, 0);
    SELF->f98 = get_bml_motion(lbl_805D68F4, 0x18);
    SELF->count = 0;
    for (i = 0; i < 4; i++) {
        SELF->ent[i].active = 0;
        SELF->ent[i].name[0] = 0;
    }
    for (i = 0; i < 4; i++) {
        pl = (u8 *)get_player_by_client_id(i);
        if (pl != 0 && SELF->fA0 == ((TBoss3Volopt *)pl)->get_field_3e0()) {
            s32 c;
            e = &SELF->ent[SELF->count];
            e->active = 1;
            e->id = i;
            strncpy(e->name, (char *)(pl + 0x85C), 0x10);
            c = *(s8 *)(pl + 0x88D);
            {
                Tbl_802E4FFC *t = &((Tbl_802E4FFC *)lbl_804E35F8)[((s32 *)lbl_804E3A18)[SELF->count] + c * 4];
                e->f18 = t;
                e->f1C = t->fC;
                e->f20 = t->f10;
            }
            e->f24 = get_bml_motion(lbl_805D68F4, ((s32 *)lbl_804E39B8)[((s32 *)lbl_804E3A28)[SELF->count] + c * 2]);
            SELF->count++;
        }
    }
    SELF->f150 = lbl_805DE950;
    restore_player_cameras();
    switch (SELF->f9C) {
    case 0:
        play_area_music((char *)lbl_80472BC0);
        break;
    default:
    case 1:
        play_area_music((char *)lbl_80472BD0);
        break;
    }
    fn_802E6260();
    fn_802E6218(arg0);
    ((TObjOnlineEnding *)arg0)->create_result_window();
    SELF->f14C = 0;
    SELF->fA4 = 0;
    return arg0;
}

#pragma pop
#undef SELF

void TLobby__sub_8001FE7C(void*, int);
void *TObjOnlineEnding__ct(void *, void *);

void *TObjOnlineEnding::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x158);
    if (o != NULL) {
        o = TObjOnlineEnding__ct(o, arg0);
    }
    return o;
}

void TBoss4DarkFalz::free_global_instance() {
    if ((u32) lbl_805D68F4 != 0U) {
        TLobby__sub_8001FE7C((void*)lbl_805D68F4, 1);
        lbl_805D68F4 = 0U;
    }
}

}
