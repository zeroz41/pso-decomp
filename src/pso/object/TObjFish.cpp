#include "types.h"
#include "pso/TMainTask.h"
#include "pso/TObject.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_80141550.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/depth_buffer.h"
#include "pso/system/vector.h"
#include "pso/TLevelSelect.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOKey.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjFish.h"
#include "pso/misc/TOKeyJungleMain.h"
#include "pso/map/FloorArea.h"

struct Base_8029D3A4_8029CF68;
struct Base_8029CF68;
struct VBase_18_076902;
struct RecoveredGlobal_8029D238_TOKeyJungleMain__data_804653C8;
struct RecoveredGlobal_8029CFEC_lbl_804DC590;
struct RecoveredGlobal_8029D200_TOKeyJungleMain__data_804653C8;
struct VBase_18_1a504b;
struct RecoveredGlobal_8029D438_lbl_804DC5A0;
struct RecoveredGlobal_8029D438___vt__15TOKeyJungleMain;
struct VBase_18_26a62c;
struct SVec_8029D5C8;
struct Fish_8029D5C8;
struct Vec_8029E170;
struct Ent_8029E170;
extern "C" {
void * __nw__7TObjectFUl(int);
void render__8TObjFishFv(u8 *arg0);
s32 init_fish_school__8TObjFishFPvll(u8 *arg0, Vec_8029E170 *arg1, s32 arg2, s32 arg3);
extern s32 TObjFish__area_bml_resource;
extern void* __vt__8TObjFish[];
extern void* fish_resource_name_table[];
}

struct Base_8029D3A4_8029CF68 { char pad[0x18]; };

struct VObj_8029D3A4_8029CF68 : Base_8029D3A4_8029CF68 {
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
};

struct Base_8029CF68 { char pad[0x18]; };

struct VObj_8029CF68 : Base_8029CF68 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct VBase_18_076902 { char pad[0x18]; };

struct RecoveredGlobal_8029D238_TOKeyJungleMain__data_804653C8 { s32 value; u8 remaining[0x8]; };
typedef char RecoveredGlobal_8029D238_TOKeyJungleMain__data_804653C8_size[sizeof(RecoveredGlobal_8029D238_TOKeyJungleMain__data_804653C8) == 0xC ? 1 : -1];

struct RecoveredGlobal_8029CFEC_lbl_804DC590 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8029CFEC_lbl_804DC590_size[sizeof(RecoveredGlobal_8029CFEC_lbl_804DC590) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8029D200_TOKeyJungleMain__data_804653C8 {
    s32 value;
    u8 remaining[0x8];
};

struct VBase_18_1a504b { char pad[0x18]; };

struct RecoveredGlobal_8029D438_lbl_804DC5A0 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8029D438___vt__15TOKeyJungleMain {
    s32 value;
    u8 remaining[0x70];
};

extern "C" {
s32 post_translate_matrix(void *);
s32 draw_ginja_object();
s32 draw_ginja_model_with_motion(s32, s32, f32);
s32 get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 set_global_param__8TObjFishFl();
extern u32 TOKeyJungleMain__static_model_resource;
void render__15TOKeyJungleMainFv(TOKeyJungleMain *arg0);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void *__dt__5TOKeyFv(void *arg0, s16 arg1);
extern s32 __vt__15TOKeyJungleMain[];
void *__dt__15TOKeyJungleMainFv(void *arg0, s16 arg1);
s32 is_lobby_event_active();
extern s32 TObjFish__area_event_stage;
u8 update_state__8TObjFishFv(void *arg0);
extern const f32 lbl_805DDD38;
extern const f32 lbl_805DDD3C;
extern RecoveredGlobal_8029D238_TOKeyJungleMain__data_804653C8 TOKeyJungleMain__data_804653C8;
extern s32 game_difficulty_selection;
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8029CFEC_lbl_804DC590 bm_obj_jungle_mkey_resource_descriptor;
s32 dispatch_by_phase__15TOKeyJungleMainFlUs(void *, int);
s32 init_collision_body_parts(void *, void *, int);
void *TOKey__ct(TOKey *arg0);
extern RecoveredGlobal_8029D438_lbl_804DC5A0 TOKeyJungleMain_collision_body_parts;
extern s32 lbl_805D3D50;
u8 *TOKeyJungleMain__ct(TOKeyJungleMain *arg0, s32 arg1, s32 arg2);
void debug_printf_at(s32, const char *, ...);
extern char lbl_80465A2C[];
void TLobby__sub_8001FE7C(void*, int);

void *TOKeyJungleMain::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xF0);
    if (o != NULL) {
        o = TOKeyJungleMain__ct((TOKeyJungleMain *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOKeyJungleMain::release_static_resource() {
    if ((u32) TOKeyJungleMain__static_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOKeyJungleMain__static_model_resource, 1);
        TOKeyJungleMain__static_model_resource = 0U;
    }
}

void TOKeyJungleMain::load_static_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &bm_obj_jungle_mkey_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TOKeyJungleMain__static_model_resource) = var_r0;
}

void TOKeyJungleMain::debug_draw_key_id() {
    *(s32 *)&this->m_e4 = this->set_params[0];
    if (*(s32 *)&this->m_e4 < 0) {
        *(s32 *)&this->m_e4 = 0;
    }
    if (*(s32 *)&this->m_e4 > 2) {
        *(s32 *)&this->m_e4 = 2;
    }
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, lbl_80465A2C, ((s32 *)&TOKeyJungleMain__data_804653C8)[*(s32 *)&this->m_e4]);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void render__15TOKeyJungleMainFv(TOKeyJungleMain *key_jungle_main) {
    if (((VObj_8029CF68 *)key_jungle_main)->m8(key_jungle_main->m_c0, *(f32 *)((s8 *)key_jungle_main + 0xC4)) == 1) {
        switch (key_jungle_main->m_d4) {
        case 0:
            TObjFish__sub_8001EDB0((*(s32 *)&TOKeyJungleMain__static_model_resource), 1);
            set_global_param__8TObjFishFl();
            push_matrix();
            post_translate_matrix((u8 *)key_jungle_main + 0x38);
            rotate_matrix_y(0, key_jungle_main->rotation_y);
            get_bml_model((*(s32 *)&TOKeyJungleMain__static_model_resource), 1);
            draw_ginja_object();
            pop_matrix();
            return;
        case 1:
            TObjFish__sub_8001EDB0((*(s32 *)&TOKeyJungleMain__static_model_resource), 1);
            set_global_param__8TObjFishFl();
            push_matrix();
            post_translate_matrix((u8 *)key_jungle_main + 0x38);
            rotate_matrix_y(0, key_jungle_main->rotation_y);
            draw_ginja_model_with_motion(get_bml_model((*(s32 *)&TOKeyJungleMain__static_model_resource), 1), get_bml_motion((*(s32 *)&TOKeyJungleMain__static_model_resource), 1), key_jungle_main->m_e8);
            TParticleCtrl::begin_effect_render();
            draw_ginja_model_with_motion(get_bml_model((*(s32 *)&TOKeyJungleMain__static_model_resource), 0), get_bml_motion((*(s32 *)&TOKeyJungleMain__static_model_resource), 0), *(f32 *)((s8 *)key_jungle_main + 0xEC));
            TParticleCtrl::end_effect_render();
            pop_matrix();
            break;
        }
    }
}

typedef char RecoveredGlobal_8029D200_TOKeyJungleMain__data_804653C8_size[sizeof(RecoveredGlobal_8029D200_TOKeyJungleMain__data_804653C8) == 0xC ? 1 : -1];
void TOKeyJungleMain::send_switch_on() {
    dispatch_by_phase__15TOKeyJungleMainFlUs((void *)game_difficulty_selection, (int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_8029D200_TOKeyJungleMain__data_804653C8 *)&TOKeyJungleMain__data_804653C8).value) + (this->m_e4 * 4))));
}

void TOKeyJungleMain::update_lock_state() {
    s32 temp_r31;
    if ((s32) this->m_d0 != 2) {
        temp_r31 = this->m_d4;
        if (TLevelSelect::get_difficulty_flag_bit(game_difficulty_selection, *(s32 *)((s8 *)&TOKeyJungleMain__data_804653C8.value + (this->m_e4 * 4))) != 0) {
            this->m_d4 = 1;
        } else {
            this->m_d4 = 0;
        }
        if (temp_r31 != (s32) this->m_d4) {
            this->play_activate_sound();
        }
    }
}

void TOKeyJungleMain::vfunc_16() {
    u8 *arg0 = (u8 *)this;
  unsigned int new_var;
  s32 bml_motion;
  s32 temp_r3_3;
  u32 temp_r3_2;
  new_var = 0;
  bml_motion = get_bml_motion((s32)((*(u8 * *)&TOKeyJungleMain__static_model_resource)), 1);
  this->m_e8 = (f32) ((this->m_e8) + lbl_805DDD38);
  temp_r3_2 = (*((s32 *) (((s8 *) bml_motion) + 4))) - 1;
  if ((this->m_e8) > ((f32) temp_r3_2))
  {
    this->m_e8 = (f32) temp_r3_2;
  }
  temp_r3_3 = get_bml_motion((s32)((*(u8 * *)&TOKeyJungleMain__static_model_resource)), new_var);
  *((f32 *) (((s8 *) arg0) + 0xEC)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0xEC))) + lbl_805DDD38);
  temp_r3_2 = (*((s32 *) (((s8 *) temp_r3_3) + 4))) - 1;
  if ((*((f32 *) (((s8 *) arg0) + 0xEC))) > ((f32) temp_r3_2))
  {
    *((f32 *) (((s8 *) arg0) + 0xEC)) = (f32) lbl_805DDD3C;
  }
}

void TOKeyJungleMain::vfunc_17() {
    struct VObj_8029D3A4_8029CF68 *o = (struct VObj_8029D3A4_8029CF68 *)this;
    o->m18();
}
void *__dt__15TOKeyJungleMainFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TOKeyJungleMain;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__5TOKeyFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_8029D438_lbl_804DC5A0_size[sizeof(RecoveredGlobal_8029D438_lbl_804DC5A0) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8029D438___vt__15TOKeyJungleMain_size[sizeof(RecoveredGlobal_8029D438___vt__15TOKeyJungleMain) == 0x74 ? 1 : -1];
u8 *TOKeyJungleMain__ct(TOKeyJungleMain *key_jungle_main, s32 arg1, s32 arg2) {
    TOKey__ct((key_jungle_main));
    *(s32 **)((s8 *)key_jungle_main + 0x18) = &(*(RecoveredGlobal_8029D438___vt__15TOKeyJungleMain *)&__vt__15TOKeyJungleMain).value;
    *(s32 *)((s8 *)key_jungle_main + 0) = (s32) lbl_805D3D50;
    ((TOKeyJungleMain *)(key_jungle_main))->apply_object_set_data((void *)arg2);
    ((TOKey *)key_jungle_main)->init_switch_id();
    init_collision_body_parts(key_jungle_main, &TOKeyJungleMain_collision_body_parts.value, 1);
    ((TObjCollidable *)key_jungle_main)->refresh_collision_body_centers();
    ((TObjPlayer *)key_jungle_main)->register_object_by_id();
    key_jungle_main->m_d0 = 0;
    key_jungle_main->m_e4 = (s32) key_jungle_main->set_params[0];
    if ((s32) key_jungle_main->m_e4 < 0) {
        key_jungle_main->m_e4 = 0;
    }
    if ((s32) key_jungle_main->m_e4 > 2) {
        key_jungle_main->m_e4 = 2;
    }
    key_jungle_main->m_e8 = (f32) lbl_805DDD3C;
    *(f32 *)((s8 *)key_jungle_main + 0xEC) = (f32) lbl_805DDD3C;
    return (u8 *)key_jungle_main;
}

u8 TObjFish::update_state() {
    if ((s32) TObjFish__area_event_stage == 0) {
        switch (*(s16 *)((s8 *)this + 0x90)) {
        case 0:
            if (is_lobby_event_active() == 0) {
                *(s16 *)((s8 *)this + 0x90) = 2;
                this->m_92 = 0x28;
            }
            goto Lend;
        case 2:
            this->m_92 = (this->m_92 - 1);
            if (this->m_92 <= 0) {
                *(s16 *)((s8 *)this + 0x90) = 3;
            }
            goto Lend;
        case 3:
        default:
            if (is_lobby_event_active() != 0) {
                *(s16 *)((s8 *)this + 0x90) = 0;
            }
        }
Lend:
        return (u8) (*(s16 *)((s8 *)this + 0x90) == 3);
    }
    return 1U;
}

#pragma push
extern const char lbl_80465A48[] = "lobby_suisou_sakana01_yellow.gj";
extern const char lbl_80465A68[] = "lobby_suisou_sakana02_red.gj";
extern const char lbl_80465A88[] = "lobby_suisou_sakana03_bule.gj";
extern const char lbl_80465AA8[] = "lobby_suisou_sakana01_yellow.njm";
extern const char lbl_80465ACC[] = "lobby_suisou_sakana02_red.njm";
extern const char lbl_80465AEC[] = "lobby_suisou_sakana03_bule.njm";
extern const char lbl_80465B0C[] = "bm_sakana_obj_lobby.bml";
extern const char lbl_80465B24[] = "sakana_jungle21.gj";
extern const char lbl_80465B38[] = "sakana_jungle22.gj";
extern const char lbl_80465B4C[] = "sakana_jungle23.gj";
extern const char lbl_80465B60[] = "sakana_jungle21.njm";
extern const char lbl_80465B74[] = "sakana_jungle22.njm";
extern const char lbl_80465B88[] = "sakana_jungle23.njm";
extern const char lbl_80465B9C[] = "bm_sakana_obj_jungle2.bml";
extern const char lbl_80465BB8[] = "sakana_jungle51.gj";
extern const char lbl_80465BCC[] = "sakana_jungle52.gj";
extern const char lbl_80465BE0[] = "sakana_jungle53.gj";
extern const char lbl_80465BF4[] = "sakana_jungle51.njm";
extern const char lbl_80465C08[] = "sakana_jungle52.njm";
extern const char lbl_80465C1C[] = "sakana_jungle53.njm";
extern const char lbl_80465C30[] = "bm_sakana_obj_jungle5.bml";
extern const char lbl_80465C4C[] = "sakana01_obj1.gj";
extern const char lbl_80465C60[] = "sakana02_obj1.gj";
extern const char lbl_80465C74[] = "sakana03_obj1.gj";
extern const char lbl_80465C88[] = "sakana01_obj1.njm";
extern const char lbl_80465C9C[] = "sakana02_obj1.njm";
extern const char lbl_80465CB0[] = "sakana03_obj1.njm";
extern const char lbl_80465CC4[] = "bm_sakana_obj_seabed1.bml";
extern const char lbl_80465CE0[] = "sakana04_obj1.gj";
extern const char lbl_80465CF4[] = "sakana05_obj1.gj";
extern const char lbl_80465D08[] = "sakana06_obj1.gj";
extern const char lbl_80465D1C[] = "sakana04_obj1.njm";
extern const char lbl_80465D30[] = "sakana05_obj1.njm";
extern const char lbl_80465D44[] = "sakana06_obj1.njm";
extern const char lbl_80465D58[] = "bm_sakana_obj_seabed2.bml";

extern const f32 lbl_80465D74[15] = { 1.0f, 1.0f, 1.0f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.0f, 0.0f, 0.0f };
extern const f32 lbl_80465DB0[15] = { 30.0f, 30.0f, 30.0f, 5.0f, 20.0f, 30.0f, 5.0f, 5.0f, 5.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f };
extern const char lbl_80465DEC[] = "TObjFish";
#pragma pop
}

struct VBase_18_26a62c { char pad[0x18]; };
struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct SVec_8029D5C8 { s16 x, y, z; };
struct Fish_8029D5C8 {
    f32 x, y, z;
    f32 tx, ty, tz;
    u8 pad18[0xC];
    s32 ang;
    f32 frame;
    s16 rot;
    u8 pad2e[2];
    s16 kind;
    u8 pad32[2];
    s32 seen;
    u8 pad38[0xC];
};

extern "C" {

extern u8 *camera_ctrl_instance;
extern const f32 lbl_805DDD40;
extern const f32 TObjFish__data_805DDD44;
extern const f32 lbl_805DDD48;

#pragma push
#pragma fp_contract on
#pragma dont_inline off
#pragma inline_depth(4)
inline void wrap_8029D5C8(s16 *p) {
    if (*p > 0) {
        *p -= 0x4000;
    } else {
        *p += 0x4000;
    }
}

#define F(T, o) (*(T *)(arg0 + (o)))
void render__8TObjFishFv(u8 *arg0) {
    Fish_8029D5C8 *f;
    s32 n;
    struct { f32 x, y, z; } d;

    if (TMainTask::get_render_pass() != 1 &&
        ((VObj_18_26a62c *)arg0)->m8(lbl_805DDD40, TObjFish__data_805DDD44) != 0 &&
        F(Fish_8029D5C8 *, 0xA0) != NULL && ((s32 (*)(void *))update_state__8TObjFishFv)(arg0) != 0) {
        f = F(Fish_8029D5C8 *, 0xA0);
        n = F(s32, 0x94);
        push_matrix();
        translate_matrix_vec3(0, arg0 + 0x38);
        rotate_matrix_y(0, F(s32, 0x60));
        if (camera_ctrl_instance != NULL) {
            d.x = *(f32 *)(camera_ctrl_instance + 0x178) - F(f32, 0x38);
            d.y = *(f32 *)(camera_ctrl_instance + 0x17C) - F(f32, 0x3C);
            d.z = *(f32 *)(camera_ctrl_instance + 0x180) - F(f32, 0x40);
        }
        while (n-- != 0) {
            s16 a;
            s16 *pa;
            f32 r;
            pa = &a;
            *pa = (s16)f->ang - f->rot;
            if (*pa > 0) {
                *pa -= 0x4000;
            } else {
                *pa += 0x4000;
            }
            r = lbl_805DDD48 * a;
            {
                struct { f32 x, y, z; } e, t;
                e.x = d.x - f->x;
                e.y = d.y - f->y;
                e.z = d.z - f->z;
                t.x = f->tx - f->x;
                t.y = f->ty - f->y;
                t.z = f->tz - f->z;
                if (f->seen == 0 || e.x * e.x + e.y * e.y + e.z * e.z < t.x * t.x + t.y * t.y + t.z * t.z) {
                    f->seen = 1;
                    f->tx = d.x;
                    f->ty = d.y;
                    f->tz = d.z;
                }
            }
            push_matrix();
            post_translate_matrix(f);
            rotate_matrix_y(0, f->rot + (s32)r);
            set_depth_buffer_settings_id(3);
            if (get_current_floor_area() == AREA_SEABED_UPPER) {
                switch (f->kind) {
                case 1:
                    TObjFish__sub_8001EDB0(TObjFish__area_bml_resource, 1);
                    set_global_param__8TObjFishFl();
                    get_bml_model(TObjFish__area_bml_resource, 1);
                    draw_ginja_object();
                    break;
                case 2:
                    TObjFish__sub_8001EDB0(TObjFish__area_bml_resource, 2);
                    set_global_param__8TObjFishFl();
                    get_bml_model(TObjFish__area_bml_resource, 2);
                    draw_ginja_object();
                    break;
                default:
                    TObjFish__sub_8001EDB0(TObjFish__area_bml_resource, 0);
                    set_global_param__8TObjFishFl();
                    get_bml_model(TObjFish__area_bml_resource, 0);
                    draw_ginja_object();
                    break;
                }
            } else {
                TObjPlayer::set_global_flag();
                switch (f->kind) {
                case 1:
                    TObjFish__sub_8001EDB0(TObjFish__area_bml_resource, 1);
                    set_global_param__8TObjFishFl();
                    draw_ginja_model_with_motion(get_bml_model(TObjFish__area_bml_resource, 1), get_bml_motion(TObjFish__area_bml_resource, 1), f->frame);
                    break;
                case 2:
                    TObjFish__sub_8001EDB0(TObjFish__area_bml_resource, 2);
                    set_global_param__8TObjFishFl();
                    draw_ginja_model_with_motion(get_bml_model(TObjFish__area_bml_resource, 2), get_bml_motion(TObjFish__area_bml_resource, 2), f->frame);
                    break;
                default:
                    TObjFish__sub_8001EDB0(TObjFish__area_bml_resource, 0);
                    set_global_param__8TObjFishFl();
                    draw_ginja_model_with_motion(get_bml_model(TObjFish__area_bml_resource, 0), get_bml_motion(TObjFish__area_bml_resource, 0), f->frame);
                    break;
                }
                TObjPlayer::clear_global_state();
            }
            restore_draw_list_mask();
            pop_matrix();
            f++;
        }
        pop_matrix();
    }
}
#undef F
#pragma pop

}

struct Vec_8029E170 { f32 x, y, z; };
struct Ent_8029E170 {
    Vec_8029E170 pos;
    Vec_8029E170 v0c;
    Vec_8029E170 v18;
    s32 f24;
    f32 f28;
    s16 f2c;
    s16 f2e;
    s16 f30;
    s16 f32;
    s32 f34;
    s32 f38;
    u8 pad3c[8];
};

extern "C" {

int rand(void);
extern const f32 lbl_805DDD60;
extern const f32 lbl_805DDD64;
extern const f32 lbl_805DDD70;
extern const f32 lbl_805DDD7C;

#pragma push
#pragma fp_contract on
s32 TObjFish::init_fish_school(void *arg1_arg, s32 arg2, s32 arg3) {
    Vec_8029E170 *arg1 = (Vec_8029E170 *)arg1_arg;
    Ent_8029E170 *p;
    s32 i;

    if (TObjFish__area_event_stage == 0 && is_lobby_event_active() != 0) {
        *(s16 *)((s8 *)((u8 *)this) + 0x90) = 0;
    } else {
        *(s16 *)((s8 *)((u8 *)this) + 0x90) = 3;
    }
    this->m_92 = 0;
    if (*(s32 *)&this->m_94 < 1) {
        return 0;
    }
    *(Ent_8029E170 * *)&this->m_a0 = (Ent_8029E170 *) ((TQuestVmDownLoadServer *)(*(s32 *)&this->m_94 * 0x44))->alloc();
    if (*(Ent_8029E170 * *)&this->m_a0 == NULL) {
        return 0;
    }
    p = *(Ent_8029E170 * *)&this->m_a0;
    for (i = 0; i < *(s32 *)&this->m_94; i++) {
        p->pos.x = lbl_805DDD70 * (arg1->x * (lbl_805DDD64 * (f32) rand() - lbl_805DDD60));
        p->pos.y = lbl_805DDD70 * (arg1->y * (lbl_805DDD64 * (f32) rand() - lbl_805DDD60));
        p->pos.z = lbl_805DDD70 * (arg1->z * (lbl_805DDD64 * (f32) rand() - lbl_805DDD60));
        p->v18.x = lbl_805DDD7C;
        p->v18.y = lbl_805DDD7C;
        p->v18.z = lbl_805DDD7C;
        if (i < arg2) {
            p->f30 = 0;
        } else if (i < arg2 + arg3) {
            p->f30 = 1;
        } else {
            p->f30 = 2;
        }
        p->f32 = TObjFish__data_805DDD44 * (lbl_805DDD64 * (f32) rand());
        p->f24 = 0;
        p->f28 = lbl_805DDD64 * (f32) rand();
        p->f2c = 0;
        p->f2e = 0;
        p->f38 = 0;
        p->f34 = 0;
        p->v0c.x = lbl_805DDD7C;
        p->v0c.y = lbl_805DDD7C;
        p->v0c.z = lbl_805DDD7C;
        p++;
    }
    return 1;
}
#pragma pop

}

#include "pso/ui/TAdSinglePlyChrSelectGC.h"

#define __nw__7TObjectFUl ((u8 * (*)(s32))__nw__7TObjectFUl)
#define init_fish_school__8TObjFishFPvll ((s32 (*)(void *, void *, int, int))init_fish_school__8TObjFishFPvll)

extern "C" {
s32 is_split_screen(void);
u8 *TObjFish__create(u8 *arg0);
s32 __ct__8TObjBaseFP7TObject();
extern s32 lbl_805D3D58;
u8 *TObjFish__ct(u8 *arg0, s32 arg1, u8 *arg2);
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void *__dt__8TObjFishFv(void *arg0, s16 arg1);

void *__dt__8TObjFishFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)__vt__8TObjFish;
        if (*(void **)((s8 *)arg0 + 0xA0) != NULL) { TAdSinglePlyChrSelectGC::safe_free((u32)(*(void **)((s8 *)arg0 + 0xA0))); ((TObjFish *)arg0)->m_a0 = 0; }
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TObjFish__ct(u8 *fish, s32 arg1, u8 *arg2) {
    f32 temp_f0;
    f32 var_f1;
    __ct__8TObjBaseFP7TObject();
    *(s32 **)((s8 *)fish + 0x18) = (s32 *)__vt__8TObjFish;
    *(s32 *)((s8 *)fish + 0) = (s32) lbl_805D3D58;
    ((TObjFish *)fish)->m_a0 = 0;
    VecCopy((Vec *)(fish + 0x38), (const Vec *)(arg2 + 0xC));
    ((TObjPlayer *)(fish + 0x5C))->copy_xyz(arg2 + 0x18);
    VecCopy((Vec *)(fish + 0x68), (const Vec *)(arg2 + 0x24));
    var_f1 = ((TObjFish *)fish)->scale.x;
    temp_f0 = ((TObjFish *)fish)->scale.y;
    if (var_f1 < temp_f0) {
        var_f1 = temp_f0;
    }
    if (var_f1 < temp_f0) {
        var_f1 = temp_f0;
    }
    *(f32 *)((s8 *)fish + 0x9C) = var_f1;
    ((TObjFish *)fish)->m_94 = *(s32 *)((s8 *)arg2 + 0x30) + *(s32 *)((s8 *)arg2 + 0x34) + *(s32 *)((s8 *)arg2 + 0x38);
    ((TObjFish *)fish)->m_98 = 0;
    if ((s32) ((TObjFish *)fish)->m_94 < 1) {
        ((TObjFish *)fish)->m_94 = 1;
    }
    if (init_fish_school__8TObjFishFPvll(fish, fish + 0x68, (int) (*(s32 *)((s8 *)arg2 + 0x30)), (int) (*(s32 *)((s8 *)arg2 + 0x34))) == 0) {
        queue_destruction__7TObjectFv((fish));
    }
    return fish;
}

u8 *TObjFish__create(u8 *arg0) {
    u8 *fish;
    u8 *var_r0;
    if (is_split_screen() != 0) {
        return NULL;
    }
    fish = (u8 *)(__nw__7TObjectFUl(0xA4));
    var_r0 = fish;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TObjFish__ct(fish, (s32)((*(s32 *)&tl_05)), arg0));
    }
    return var_r0;
}

void TObjFish::free_resource() {
    if ((u32) (*(u32 *)&TObjFish__area_bml_resource) != 0U) {
        TLobby__sub_8001FE7C((void*)(*(u32 *)&TObjFish__area_bml_resource), 1);
        (*(u32 *)&TObjFish__area_bml_resource) = 0U;
    }
}
void vfunc_6__8TObjBaseFPsl();
void get_name__8TObjBaseFv();
void get_center__8TObjBaseFv();
void apply_object_set_data__8TObjBaseFPv();
void classify_actor_view_detail__8TObjBaseFfff();
void render_shadows__7TObjectFv();
void reset_motion_fields__8TObjBaseFv();
void run_task__8TObjFishFv();
void update_object_view_visibility__8TObjBaseFff();
#pragma push
extern const f64 lbl_80465E00 = 10430.38043493439;
#pragma pop
void *fish_resource_name_table[60] = {
    (void *)lbl_80465A48,
    (void *)lbl_80465A68,
    (void *)lbl_80465A88,
    0,
    (void *)lbl_80465AA8,
    (void *)lbl_80465ACC,
    (void *)lbl_80465AEC,
    0,
    (void *)lbl_80465B0C,
    (void *)&fish_resource_name_table[0],
    (void *)&fish_resource_name_table[4],
    (void *)0x30003,
    (void *)lbl_80465B24,
    (void *)lbl_80465B38,
    (void *)lbl_80465B4C,
    0,
    (void *)lbl_80465B60,
    (void *)lbl_80465B74,
    (void *)lbl_80465B88,
    0,
    (void *)lbl_80465B9C,
    (void *)&fish_resource_name_table[12],
    (void *)&fish_resource_name_table[16],
    (void *)0x30003,
    (void *)lbl_80465BB8,
    (void *)lbl_80465BCC,
    (void *)lbl_80465BE0,
    0,
    (void *)lbl_80465BF4,
    (void *)lbl_80465C08,
    (void *)lbl_80465C1C,
    0,
    (void *)lbl_80465C30,
    (void *)&fish_resource_name_table[24],
    (void *)&fish_resource_name_table[28],
    (void *)0x30003,
    (void *)lbl_80465C4C,
    (void *)lbl_80465C60,
    (void *)lbl_80465C74,
    0,
    (void *)lbl_80465C88,
    (void *)lbl_80465C9C,
    (void *)lbl_80465CB0,
    0,
    (void *)lbl_80465CC4,
    (void *)&fish_resource_name_table[36],
    (void *)&fish_resource_name_table[40],
    (void *)0x30003,
    (void *)lbl_80465CE0,
    (void *)lbl_80465CF4,
    (void *)lbl_80465D08,
    0,
    (void *)lbl_80465D1C,
    (void *)lbl_80465D30,
    (void *)lbl_80465D44,
    0,
    (void *)lbl_80465D58,
    (void *)&fish_resource_name_table[48],
    (void *)&fish_resource_name_table[52],
    (void *)0x30003,
};
void *__vt__8TObjFish[13] = {
    0,
    0,
    (void *)__dt__8TObjFishFv,
    (void *)run_task__8TObjFishFv,
    (void *)render__8TObjFishFv,
    (void *)render_shadows__7TObjectFv,
    (void *)vfunc_6__8TObjBaseFPsl,
    (void *)apply_object_set_data__8TObjBaseFPv,
    (void *)reset_motion_fields__8TObjBaseFv,
    (void *)get_center__8TObjBaseFv,
    (void *)update_object_view_visibility__8TObjBaseFff,
    (void *)classify_actor_view_detail__8TObjBaseFfff,
    (void *)get_name__8TObjBaseFv,
};

void TObjFish::load_area_resource() {
    u8 *base = (u8 *)fish_resource_name_table;
    u8 *p;
    switch (get_current_floor_area()) {
    case AREA_JUNGLE_NORTH:
        TObjFish__area_event_stage = 1;
        p = (u8 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, base + 0x50, 0, 0, 0);
        }
        (*(u32 *)&TObjFish__area_bml_resource) = (u32)p;
        break;
    case AREA_SEASIDE:
    case AREA_SEASIDE_NIGHT:
        TObjFish__area_event_stage = 2;
        p = (u8 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, base + 0x80, 0, 0, 0);
        }
        (*(u32 *)&TObjFish__area_bml_resource) = (u32)p;
        break;
    case AREA_SEABED_UPPER:
        TObjFish__area_event_stage = 3;
        p = (u8 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, base + 0xB0, 0, 0, 0);
        }
        (*(u32 *)&TObjFish__area_bml_resource) = (u32)p;
        break;
    case AREA_SEABED_LOWER:
        TObjFish__area_event_stage = 4;
        p = (u8 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, base + 0xE0, 0, 0, 0);
        }
        (*(u32 *)&TObjFish__area_bml_resource) = (u32)p;
        break;
    case AREA_LOBBY:
    default:
        TObjFish__area_event_stage = 0;
        p = (u8 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, base + 0x20, 0, 0, 0);
        }
        (*(u32 *)&TObjFish__area_bml_resource) = (u32)p;
        break;
    }
}

}
#undef __nw__7TObjectFUl
#undef init_fish_school__8TObjFishFPvll
