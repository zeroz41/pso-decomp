#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/EnemyTargeting.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/enemy/recon/TObjEneReconBomb.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/render/BlobShadow.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/recon/TObjEneRecobox.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/math/AngleLookup.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/system/task/TObject.h"


#pragma readonly_strings on

struct Sub_8031B618 { u8 pad[0xC]; f32 radius; };

struct Ctrl_8031B618 { u8 pad[0xA4]; Sub_8031B618 *sub; u8 pad2[0x2FC - 0xA8]; Vec pos; };

struct Obj_8031B618 { u8 pad[0x38]; Vec pos; u8 pad2[0x2FC - 0x44]; Vec pos2; };

struct Obj_8031B618;

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
    Vec pos;
    u8 pad44[0x248 - 0x44];
    u8 f248[0x2FC - 0x248];
    Vec pos2;
    u8 pad308[0x334 - 0x308];
    u32 target;
    u8 pad338[4];
    Vec vel;
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
u32 csnVector(void *, void *, int);
s32 project_actor_to_ground(void *, void *, void *);
s32 TObjEneRecon__sub_8031C250(u32);
s32 vec3_add_to(void *, void *);
extern s32 lbl_805D5868;


s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(void *, s32);
s32 scale_current_matrix(void *);
BmlResource *recon_bomb_bml_resource;
f32 TObjEneRecon__sub_8031C2BC(int);
f32 TObjEneRecon__sub_8031C2C8(int);
f32 TObjEneRecon__sub_8031C2D4(int);


s32 fn_8031B618(Obj_8031B618 *arg0) {
    s32 var_r30 = 0;
    Ctrl_8031B618 *c;
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&arg0->pos2, &arg0->pos);
    u16 id = find_nearest_visible_player(reinterpret_cast<TObjChara *>(arg0), NULL, (25.0f));
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
    u8 *self = (u8 *)this;
    struct { f32 x, y, z; } sc;
    s32 spC;
    s32 sp8;
    f32 temp_f0;
    f32 temp_f1;
    f32 var_f1;
    saddr bml_model;
    s32 temp_r30;
    if (recon_bomb_bml_resource == NULL) {
        ((TObject *)self)->queue_destruction();
        return;
    }
    bml_model = (saddr)get_bml_model(recon_bomb_bml_resource, 2);
    temp_r30 = (saddr)get_bml_texlist(recon_bomb_bml_resource, 2);
    push_matrix();
    translate_matrix(0, (f32) (*(f32 *)((s8 *)self + 0x38)), (f32) ((2.0f) + *(f32 *)((s8 *)self + 0x3C)), (f32) (*(f32 *)((s8 *)self + 0x40)));
    rotate_matrix_zyx(0, (this->rotation_x), (this->rotation_y), (this->rotation_z));
    TObjFish::set_global_param(temp_r30);
    draw_chunk_object((void *)bml_model);
    pop_matrix();
    push_matrix();
    translate_matrix(0, (f32) (*(f32 *)((s8 *)self + 0x38)), (f32) ((0.1f) + this->m_348), (f32) (*(f32 *)((s8 *)self + 0x40)));
    direction_to_rotation_xz(((u8 *)&this->ground_normal), (&spC), (&sp8));
    rotate_matrix_z(0, sp8);
    rotate_matrix_x(0, spC + 0x4000);
    var_f1 = *(f32 *)((s8 *)self + 0x3C) - this->m_348;
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
    Obj_8031B808 *self = (Obj_8031B808 *)this;
    Vec pos;
    s32 i;
    VObj_8031B808 *pl;
    if (self->target == 0) {
        ((TObject *)self)->queue_destruction();
        return;
    }
    if (++self->f360 > self->f358 || TObjEneRecon__sub_8031C250(self->target) != 0) {
        self->state = 3;
    }
    switch (self->state) {
    case 0:
    case 1: {
        self->vel.x *= 0.95f;
        self->vel.y += -0.1f;
        self->vel.z *= 0.95f;
        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&pos, &self->pos);
        vec3_add_to(&pos, &self->vel);
        Vec g = pos;
        if (project_actor_to_ground(self, &g, self->f248) != 0) {
            self->f348 = g.y;
            if (pos.y <= g.y) {
                pos.y = self->f348;
                if (self->state == 0) {
                    self->vel.y *= -0.5f;
                    self->state = 1;
                } else {
                    self->state = 2;
                }
            } else if (csnVector(&self->pos, &pos, 0x100) != 0) {
                ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&pos, &self->pos);
                self->state = 3;
            }
        } else {
            self->state = 3;
        }
        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->pos, &pos);
        break;
    }
    case 2:
        if (fn_8031B618((Obj_8031B618 *)self) != 0) {
            self->state = 3;
        }
        break;
    case 3:
    default:
        play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A80B), &self->pos, 0, 0);
        spawn_particle_effect_with_flags(&self->pos, 0x45, 0x40);
        spawn_particle_effect_with_flags(&self->pos, 0x46, 0x40);
        for (i = 0; i < lbl_805D5868; i++) {
            pl = (VObj_8031B808 *)TObjPlayer::get_player_data(i);
            if (TObjPlayer::is_valid_and_active((uaddr)pl) != 0 && pl != 0 && (u16)get_entity_id((saddr)pl) < 0x1000 && pl->m31() == 0) {
                if (horizontal_distance_squared((const Vec *)((u8 *)pl + 0x2FC), (const Vec *)&self->pos2) <= self->range * self->range) {
                    P_8031B808 d;
                    d.a = 0;
                    d.b = self->f350;
                    pl->m21(self->target, d, 0, -1, -1);
                    pl->m23(self->target);
                }
            }
        }
        ((TObject *)self)->queue_destruction();
        break;
    }
}

}
TObjEneReconBomb::~TObjEneReconBomb() {

}
extern "C" {

extern const char *TObjEneReconBomb__name;

TObjEneReconBomb::TObjEneReconBomb(TObject *parent, TObjEneRecon *recon, const Vec *pos) : TObjChara(parent) {
    f32 temp_f1;
    f32 temp_f31;
    u8 *temp_r5;

    *(s32 *)((s8 *)this + 0) = (saddr) TObjEneReconBomb__name;
    m_334 = (uaddr)recon;
    this->m_338 = get_entity_id(this->m_334);
    *(f32 *)((s8 *)this + 0x34C) = TObjEneRecon__sub_8031C2D4(this->m_334);
    this->m_350 = TObjEneRecon__sub_8031C2C8(this->m_334);
    *(f32 *)((s8 *)this + 0x354) = TObjEneRecon__sub_8031C2BC(this->m_334);
    this->m_358 = ((TObjEneRecon *)this->m_334)->calc_scaled_value();
    temp_r5 = (unsigned char *) (this->m_up);
    this->rotation_y = (s32) *(s32 *)((s8 *)temp_r5 + 0x60);
    VecCopy__FP3VecPC3Vec((u8 *)this + 0x38, (void *)pos, (saddr)temp_r5);
    temp_f31 = sin_table_lookup(this->rotation_y);
    temp_f1 = cos_table_lookup(this->rotation_y);
    *(f32 *)((s8 *)this + 0x33C) = (f32) (*(f32 *)((s8 *)this + 0x354) * temp_f31);
    *(f32 *)((s8 *)this + 0x340) = 0.0f;
    this->m_344 = (f32) (*(f32 *)((s8 *)this + 0x354) * temp_f1);
    this->m_360 = 0;
    this->m_35c = 0;
}

const char *TObjEneReconBomb__name = "TObjEneReconBomb";


void TObjEneReconBomb::release_resources() {  }

void *TObjEneReconBomb::create(void *parent, void *recon, void *pos) {
    return new TObjEneReconBomb((TObject *)parent, (TObjEneRecon *)recon, (const Vec *)pos);
}

void TObjEneReconBomb::load_resources() { recon_bomb_bml_resource = TObjEneRecobox::get_bml_resource(); }

}
