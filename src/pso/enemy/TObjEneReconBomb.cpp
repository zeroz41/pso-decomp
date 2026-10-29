#include "types.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEneReconBomb.h"
#include "pso/enemy/TObjEneRecobox.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

#pragma readonly_strings on

struct Vec_8031B618 { f32 x, y, z; };

struct Sub_8031B618 { u8 pad[0xC]; f32 radius; };

struct Ctrl_8031B618 { u8 pad[0xA4]; Sub_8031B618 *sub; u8 pad2[0x2FC - 0xA8]; Vec_8031B618 pos; };

struct Obj_8031B618 { u8 pad[0x38]; Vec_8031B618 pos; u8 pad2[0x2FC - 0x44]; Vec_8031B618 pos2; };

struct Obj_8031B618;
struct Vec_8031B808 { f32 x, y, z; };

struct P_8031B808 { s32 a; f32 b; };

struct VBase_8031B808 { char pad[0x18]; };

struct VObj_8031B808 : VBase_8031B808 {
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
    virtual void m20();
    virtual void m21(u32, P_8031B808, s32, s32, s32);
    virtual void m22();
    virtual void m23(u32);
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual s32 m31();
};

struct Obj_8031B808 {
    u8 pad0[0x38];
    Vec_8031B808 pos;
    u8 pad44[0x248 - 0x44];
    u8 f248[0x2FC - 0x248];
    Vec_8031B808 pos2;
    u8 pad308[0x334 - 0x308];
    u32 target;
    u8 pad338[4];
    Vec_8031B808 vel;
    f32 f348;
    f32 range;
    f32 f350;
    u8 pad354[4];
    s32 f358;
    s32 state;
    s32 f360;
};

extern "C" {
s32 VecCopy__FP3VecPC3Vec(void *, void *, int);
s16 get_entity_id(int);
s32 fn_8031B618(Obj_8031B618 *arg0);
int get_player_data__10TObjPlayerFi(int a0);
u32 csnVector(void *, void *, int);
s32 project_actor_to_ground(void *, void *, void *);
s32 play_sound_effect(s32, void *, int, int);
s32 TObjEneRecon__sub_8031C250(u32);
s32 vec3_add_to(void *, void *);
extern s32 lbl_805D5868;
extern const f32 lbl_805DF3AC;
extern const f32 lbl_805DF3B0;
extern const f32 lbl_805DF3B4;
s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, void *);
s32 push_matrix();
s32 scale_current_matrix(void *);
s32 find_nearest_visible_player(void *, int, f32);
void *get_player_by_client_id(s32 i);
extern u32 recon_bomb_bml_resource;
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
s32 calc_scaled_value__12TObjEneReconFv(int);
f32 TObjEneRecon__sub_8031C2BC(int);
f32 TObjEneRecon__sub_8031C2C8(int);
f32 TObjEneRecon__sub_8031C2D4(int);
s32 __ct__9TObjCharaFP7TObject();
void __dl__7TObjectFPv(void *);

extern s32 __vt__16TObjEneReconBomb[];

s32 fn_8031B618(Obj_8031B618 *arg0) {
    s32 var_r30 = 0;
    Ctrl_8031B618 *c;
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&arg0->pos2, &arg0->pos);
    u16 id = find_nearest_visible_player(arg0, 0, (25.0f));
    if (id != 0xFFFF) {
        c = (Ctrl_8031B618 *)get_player_by_client_id(id);
        if (c != 0) {
            if (!(horizontal_distance_squared((const Vec *)&arg0->pos2, (const Vec *)&c->pos) > ((1.0f) + c->sub->radius) * ((1.0f) + c->sub->radius))) {
                var_r30 = 1;
            }
        }
    }
    return var_r30;
}

#pragma push
#pragma fp_contract on
void TObjEneReconBomb::render() {
    u8 *arg0 = (u8 *)this;
    struct { f32 x, y, z; } sc;
    s32 spC;
    s32 sp8;
    f32 temp_f0;
    f32 temp_f1;
    f32 var_f1;
    s32 bml_model;
    s32 temp_r30;
    if ((u32) recon_bomb_bml_resource == 0U) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    bml_model = get_bml_model((void *)recon_bomb_bml_resource, 2);
    temp_r30 = TObjFish__sub_8001EDB0((void *)recon_bomb_bml_resource, 2);
    push_matrix();
    translate_matrix(0, (f32) (*(f32 *)((s8 *)arg0 + 0x38)), (f32) ((2.0f) + *(f32 *)((s8 *)arg0 + 0x3C)), (f32) (*(f32 *)((s8 *)arg0 + 0x40)));
    rotate_matrix_zyx(0, (*(s32 *)&this->rotation_x), (this->rotation_y), (this->rotation_z));
    TObjFish::set_global_param(temp_r30);
    draw_chunk_object((void *)bml_model);
    pop_matrix();
    push_matrix();
    translate_matrix(0, (f32) (*(f32 *)((s8 *)arg0 + 0x38)), (f32) ((0.1f) + this->m_348), (f32) (*(f32 *)((s8 *)arg0 + 0x40)));
    direction_to_rotation_xz(((u8 *)&this->m_248), (&spC), (&sp8));
    rotate_matrix_z(0, sp8);
    rotate_matrix_x(0, (void *)(spC + 0x4000));
    var_f1 = *(f32 *)((s8 *)arg0 + 0x3C) - this->m_348;
    if (var_f1 > 40.0f) {
        var_f1 = 40.0f;
    } else if (var_f1 < 0.0f) {
        var_f1 = 0.0f;
    }
    sc.x = sc.y = 0.65f * (1.0f - (var_f1 / 40.0f)) + 0.1f;
    sc.z = 1.0f;
    scale_current_matrix(&sc);
    draw_blob_shadow(0);
    pop_matrix();
}
#pragma pop

void TObjEneReconBomb::run_task() {
    Obj_8031B808 *arg0 = (Obj_8031B808 *)this;
    Vec_8031B808 pos;
    s32 i;
    VObj_8031B808 *pl;
    if (arg0->target == 0) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    if (++arg0->f360 > arg0->f358 || TObjEneRecon__sub_8031C250(arg0->target) != 0) {
        arg0->state = 3;
    }
    switch (arg0->state) {
    case 0:
    case 1: {
        arg0->vel.x *= lbl_805DF3AC;
        arg0->vel.y += lbl_805DF3B0;
        arg0->vel.z *= lbl_805DF3AC;
        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&pos, &arg0->pos);
        vec3_add_to(&pos, &arg0->vel);
        Vec_8031B808 g = pos;
        if (project_actor_to_ground(arg0, &g, arg0->f248) != 0) {
            arg0->f348 = g.y;
            if (pos.y <= g.y) {
                pos.y = arg0->f348;
                if (arg0->state == 0) {
                    arg0->vel.y *= lbl_805DF3B4;
                    arg0->state = 1;
                } else {
                    arg0->state = 2;
                }
            } else if (csnVector(&arg0->pos, &pos, 0x100) != 0) {
                ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&pos, &arg0->pos);
                arg0->state = 3;
            }
        } else {
            arg0->state = 3;
        }
        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&arg0->pos, &pos);
        break;
    }
    case 2:
        if (fn_8031B618((Obj_8031B618 *)arg0) != 0) {
            arg0->state = 3;
        }
        break;
    case 3:
    default:
        play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A80B), &arg0->pos, 0, 0);
        spawn_particle_effect_with_flags(&arg0->pos, 0x45, 0x40);
        spawn_particle_effect_with_flags(&arg0->pos, 0x46, 0x40);
        for (i = 0; i < lbl_805D5868; i++) {
            pl = (VObj_8031B808 *)get_player_data__10TObjPlayerFi(i);
            if (TObjPlayer::is_valid_and_active((u32)pl) != 0 && pl != 0 && (u16)get_entity_id((int)pl) < 0x1000 && pl->m31() == 0) {
                if (horizontal_distance_squared((const Vec *)((u8 *)pl + 0x2FC), (const Vec *)&arg0->pos2) <= arg0->range * arg0->range) {
                    P_8031B808 d;
                    d.a = 0;
                    d.b = arg0->f350;
                    pl->m21(arg0->target, d, 0, -1, -1);
                    pl->m23(arg0->target);
                }
            }
        }
        queue_destruction__7TObjectFv(arg0);
        break;
    }
}

void *__dt__16TObjEneReconBombFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TObjEneReconBomb;
        __dt__9TObjCharaFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern const char *TObjEneReconBomb__name;

u8 *TObjEneReconBomb__ct(TObjEneReconBomb *ene_recon_bomb, s32 arg1, s32 arg2, s32 arg3) {
    f32 temp_f1;
    f32 temp_f31;
    u8 *temp_r5;

    __ct__9TObjCharaFP7TObject();
    *(s32 **)((s8 *)ene_recon_bomb + 0x18) = (s32 *) __vt__16TObjEneReconBomb;
    *(s32 *)((s8 *)ene_recon_bomb + 0) = (s32) TObjEneReconBomb__name;
    ene_recon_bomb->m_334 = arg2;
    ene_recon_bomb->m_338 = get_entity_id(ene_recon_bomb->m_334);
    *(f32 *)((s8 *)ene_recon_bomb + 0x34C) = TObjEneRecon__sub_8031C2D4(ene_recon_bomb->m_334);
    ene_recon_bomb->m_350 = TObjEneRecon__sub_8031C2C8(ene_recon_bomb->m_334);
    *(f32 *)((s8 *)ene_recon_bomb + 0x354) = TObjEneRecon__sub_8031C2BC(ene_recon_bomb->m_334);
    ene_recon_bomb->m_358 = calc_scaled_value__12TObjEneReconFv(ene_recon_bomb->m_334);
    temp_r5 = (unsigned char *) (ene_recon_bomb->m_up);
    ene_recon_bomb->rotation_y = (s32) *(s32 *)((s8 *)temp_r5 + 0x60);
    VecCopy__FP3VecPC3Vec((u8 *)ene_recon_bomb + 0x38, (void *)arg3, (int)temp_r5);
    temp_f31 = sin_table_lookup(ene_recon_bomb->rotation_y);
    temp_f1 = cos_table_lookup(ene_recon_bomb->rotation_y);
    *(f32 *)((s8 *)ene_recon_bomb + 0x33C) = (f32) (*(f32 *)((s8 *)ene_recon_bomb + 0x354) * temp_f31);
    *(f32 *)((s8 *)ene_recon_bomb + 0x340) = (f32) (0.0f);
    ene_recon_bomb->m_344 = (f32) (*(f32 *)((s8 *)ene_recon_bomb + 0x354) * temp_f1);
    ene_recon_bomb->m_360 = 0;
    ene_recon_bomb->m_35c = 0;
    return (u8 *)ene_recon_bomb;
}

__declspec(section ".sdata2") extern const f32 lbl_805DF3AC = 0.94999998807907104f;
__declspec(section ".sdata2") extern const f32 lbl_805DF3B0 = -0.10000000149011612f;
__declspec(section ".sdata2") extern const f32 lbl_805DF3B4 = -0.5f;

const char *TObjEneReconBomb__name = "TObjEneReconBomb";

}
