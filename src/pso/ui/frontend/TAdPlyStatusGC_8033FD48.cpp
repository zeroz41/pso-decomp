#define TOBJECT_OUT_OF_LINE_HELPERS
// ---- pso/ui/frontend/TAdPlyStatusGC_8033FD48
#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/ui/frontend/TAdPlyStatusGC_8033FD48.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/ui/frontend/TAdPlyStatusGC.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer.h"

struct Vec_8034009C { f32 x, y, z; };

struct E_8034009C { Vec_8034009C a; Vec_8034009C b; s32 f18; };

static const Vec lbl_80478430 = {-10000.0f, 0.0f, 0.0f};
// Ten map CSN objects created by fn_8034009C: position, scale, angle.
static const E_8034009C lbl_8047843C[10] = {
    {{-10010.0f, 0.0f, -30.0f}, {145.0f, 100.0f, 80.0f}, 0},
    {{-10040.0f, 0.0f, 50.0f}, {110.0f, 75.0f, 100.0f}, 0},
    {{-10095.0f, 0.0f, -35.0f}, {80.0f, 15.0f, 15.0f}, 0xD800},
    {{-10000.0f, 0.0f, -125.0f}, {30.0f, 10.0f, 150.0f}, 0xEE00},
    {{-9958.0f, 0.0f, -95.0f}, {15.0f, 10.0f, 50.0f}, 0},
    {{-9930.0f, 0.0f, -37.0f}, {38.0f, 40.0f, 100.0f}, 0xEE00},
    {{-9982.0f, 0.0f, 125.0f}, {17.0f, 10.0f, 75.0f}, 0xFA00},
    {{-9958.0f, 0.0f, 140.0f}, {45.0f, 10.0f, 5.0f}, 0x1000},
    {{-10005.0f, 0.0f, 137.0f}, {45.0f, 10.0f, 5.0f}, 0xDC00},
    {{-10112.0f, 0.0f, 125.0f}, {20.0f, 10.0f, 120.0f}, 0xF2C0},
};
static const Vec lbl_80478554 = {-10000.0f, 0.0f, 0.0f};

extern "C" {
s32 push_matrix();
f32 post_translate_matrix(void *);
extern const f32 lbl_805DFAF8;
u32 TAdPlyStatusGC__ct(u32, s32, s32);
u32 __nw__7TObjectFUl(s32);

extern u32 ply_status_gc_instance;

u32 TAdPlyStatusGC::get_instance(s32 arg0, s32 arg1) {
    u32 var_r0;

    if ((u32) ply_status_gc_instance == 0U) {
        var_r0 = __nw__7TObjectFUl(0x70);
        if (var_r0 != 0U) {
            var_r0 = TAdPlyStatusGC__ct(var_r0, arg0, arg1);
        }
        ply_status_gc_instance = var_r0;
    }
    return ply_status_gc_instance;
}

    extern int guide_button_instance;
int TAdPlyStatusGC::get_player_index() {  return guide_button_instance; }
void TObjPlayer__sub_8033FDB0(s32 arg0) {
  s32 var_r31;
  u8 *temp_r30;
  s32 var_r29;
  push_matrix();
  set_motion_packed_rotation();
  post_translate_matrix((Vec *)&lbl_80478430);
  var_r29 = 0;
  var_r31 = 0;
  do
  {
    temp_r30 = (u8 *) (arg0 + (var_r31 & 0xFFFFFFFFFFFFFFFF));
    TObjFish::set_global_param((int) (*((s32 *) (((s8 *) temp_r30) + 0x2C))));
    draw_model_motion((void *)(*((s32 *) (((s8 *) temp_r30) + 0x28))), (void *)(*((s32 *) (((s8 *) temp_r30) + 0x30))), (f32) lbl_805DFAF8);
    var_r29 += 1;
    var_r31 += 0xC;
  }
  while (var_r29 < 2);
  clear_motion_packed_rotation();
  pop_matrix();
}

}

// ---- pso/player/TObjPlayer_8033FE28
#include "types.h"
#include "pso/player/TObjPlayer.h"

s32 TObjPlayer::get_plot_state() { return this->texlist; }

// ---- pso/boss/olgaflow/TBoss6Demo15_TYPE2_WAIT_8033FE30
#include "types.h"
#include "pso/system/vector.h"
#include "pso/boss/olgaflow/TBoss6Demo15_TYPE2_WAIT.h"
#include "pso/math/AngleLookup.h"


extern "C" {
extern const f32 lbl_805DFAFC;
extern const f32 lbl_805DFB00;
extern const f32 lbl_805DFB04;
#pragma push
#pragma fp_contract on
void TBoss6Demo15_TYPE2_WAIT::sub_8033FE30() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f29;
    f32 temp_f30;
    f32 temp_f31;
    temp_f29 = (lbl_805DFB00 * sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x5C))) + lbl_805DFAFC;
    temp_f30 = sin_table_lookup(*(s32 *)&this->m_58);
    temp_f31 = cos_table_lookup(*(s32 *)&this->m_58);
    VecCopy((Vec *)&this->m_40, &lbl_80478554);
    this->m_40 = (f32) ((temp_f30 * temp_f29) + this->m_40);
    this->m_48 = (f32) ((temp_f31 * temp_f29) + this->m_48);
    *(f32 *)((s8 *)arg0 + 0x44) = (f32) (*(f32 *)((s8 *)arg0 + 0x44) + lbl_805DFB04);
}
#pragma pop

}

// ---- pso/boss/darkfalz/TBoss4Type2_8033FEEC
#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type2_8033FEEC.h"
#include "pso/boss/olgaflow/TBoss6Demo15_TYPE2_WAIT.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"

extern const f32 lbl_805DFB08;
extern const f32 lbl_805DFB0C;

void TBoss6Demo15_TYPE2_WAIT::advance_offset() {
    *(s32 *)&(this->m_58) = (s32) ((f32) *(s32 *)&(this->m_58) + lbl_805DFB08);
    *(s32 *)((s8 *)this + 0x5C) = (s32) ((f32) *(s32 *)((s8 *)this + 0x5C) + lbl_805DFB0C);
}

void TObjFish__sub_8033FF64(void* p) { *(s32*)((char*)p + 0x58) = 24576; *(s32*)((char*)p + 0x5c) = 0; }

// ---- pso/unk/text_8033FF78
#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/boss/olgaflow/TBoss6Demo15_TYPE2_WAIT.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/unk/TLobby.h"

struct Vec_8033FF78 { f32 x, y, z; };

struct O_8033FF78 { u8 pad[0x24]; s32 f24; u8 pad28[0x40 - 0x28]; Vec_8033FF78 pos; };

struct P_8033FF78 { u8 pad[0x38]; Vec_8033FF78 pos; };

struct P_8034009C {
    u8 pad0[0xC];
    Vec_8034009C a;
    s32 f18;
    s32 f1c;
    s32 f20;
    Vec_8034009C b;
    s32 f30;
    s32 f34;
};


extern "C" {
void fn_80340040(TBoss6Demo15_TYPE2_WAIT *arg0);
f32 vector_length(void *);
s32 subtract_vector(void *, void *);
extern const f32 lbl_805DFAF8;
s32 create__10TObjMapCsnFl(void *);
void fn_8034009C(TBoss6Demo15_TYPE2_WAIT *arg0);

void TBoss6Demo15_TYPE2_WAIT::check_any_player_near() {
    O_8033FF78 *arg0 = (O_8033FF78 *)this;
    Vec_8033FF78 v;
    s32 n;
    s32 i;
    f32 lim;
    f32 y;
    P_8033FF78 *p;
    arg0->f24 = 0;
    n = TLobby::get_game_mode();
    y = lbl_805DFAF8;
    lim = 25.0f;
    for (i = 0; i < n; i++) {
        p = (P_8033FF78 *)TObjPlayer::get_player_data(i);
        if (((TBoss6PlotFalz *)p)->is_active() != 0) {
            VecCopy((Vec *)&v, (const Vec *)&arg0->pos);
            subtract_vector(&v, &p->pos);
            v.y = y;
            if (vector_length(&v) <= lim) {
                arg0->f24 = 1;
                return;
            }
        }
    }
}

void fn_80340040(TBoss6Demo15_TYPE2_WAIT *arg0) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (arg0->csn_objects[i] != 0) {
            arg0->csn_objects[i]->queue_destruction();
            arg0->csn_objects[i] = 0;
        }
    }
}
void fn_8034009C(TBoss6Demo15_TYPE2_WAIT *arg0) {
    P_8034009C prm;
    s32 i;
    s32 j;
    for (j = 0; j < 10; j++) {
        arg0->csn_objects[j] = 0;
    }
    prm.f30 = 2;
    prm.f34 = 0;
    for (i = 0; i < 10; i++) {
        const E_8034009C *e = &lbl_8047843C[i];
        VecCopy((Vec *)&prm.a, (const Vec *)&e->a);
        prm.f18 = 0;
        prm.f1c = e->f18;
        prm.f20 = 0;
        VecCopy((Vec *)&prm.b, (const Vec *)&e->b);
        arg0->csn_objects[i] = (TObject *)create__10TObjMapCsnFl(&prm);
    }
}

}

// ---- pso/boss/darkfalz/TBoss4Type2_80340160
#include "types.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/ui/frontend/TAdPlyStatusGC_8033FD48.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/boss/olgaflow/TBoss6Demo15_TYPE2_WAIT.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/boss/darkfalz/TBoss4Type2_8033FEEC.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/effect/particle/TParticleCtrl.h"

extern "C" {
void *TObjFish__sub_8034029C(TBoss6Demo15_TYPE2_WAIT *, TObjFish *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

void TBoss6Demo15_TYPE2_WAIT::render() { TObjPlayer__sub_8033FDB0((s32)this); }

extern s32 lbl_804EFB78[];

void TBoss6Demo15_TYPE2_WAIT::run_task() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    if (((TObjEneDD *)arg0)->query_teammate_state() == 0) {
        ((TBoss6Demo15_TYPE2_WAIT *)arg0)->advance_offset();
        VecCopy((Vec *)(arg0 + 0x4C), (const Vec *)(arg0 + 0x40));
        ((TBoss6Demo15_TYPE2_WAIT *)arg0)->sub_8033FE30();
        temp_r3 = this->m_20;
        if (temp_r3 != NULL) {
            ((TParticleCtrl *)temp_r3)->set_position((u8 *)&this->m_40);
        }
        ((TBoss6Demo15_TYPE2_WAIT *)arg0)->check_any_player_near();
        play_persistent_sound(0x4003A126, (s32)arg0, (u32)(arg0 + 0x40), 0, 0);
        if (((TObjFish *)(*(u8 * *)&this->unk_1C))->get_phase() != 4) {
            ((TObject *)arg0)->queue_destruction();
        }
    }
}

void *TBoss6Demo15_TYPE2_WAIT::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 * *)&(*(u32 *)((u8 *)this + 0x18)) = lbl_804EFB78;
        if (this->m_20 != NULL) { TParticleCtrl::release(this->m_20); this->m_20 = 0; }
        fn_80340040(this);
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

/* One animated part of the wait demo: model, model helper and motion loaded from the fish BML. */
struct WaitDemoPart {
    s32 model;
    s32 model_aux;
    s32 motion;
};

struct WaitDemoLayout {
    u8 pad0[0x1C];
    TObjFish *fish;
    TParticleCtrl *emitter;
    s32 m_24;
    WaitDemoPart parts[2];
    Vec position;
    Vec prev_position;
};

void __ct__7TObjectFP7TObject(TObject *self, TObject *parent);
extern const char *lbl_805D42C8;
extern s32 lbl_804DF614[];
extern s32 lbl_804EFB70[];
s32 get_bml_model(s32 bml, s32 index);
s32 TObjFish__sub_8001EDB0(s32 bml, s32 index);
s32 get_bml_motion(s32 bml, s32 index);

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void *TObjFish__sub_8034029C(TBoss6Demo15_TYPE2_WAIT *wait, TObjFish *fish) {
    WaitDemoLayout *self = (WaitDemoLayout *)wait;
    s32 v;
    s32 bml;
    s32 i;
    __ct__7TObjectFP7TObject(wait, (TObject *)fish);
    *(s32 **)((u8 *)wait + 0x18) = lbl_804EFB78;
    wait->m_name = lbl_805D42C8;
    self->fish = fish;
    bml = TObjFish::get_fish_count();
    for (i = 0; i < 2; i++) {
        {
            s32 t = lbl_804DF614[i];
            v = t;
            self->parts[i].model = get_bml_model(bml, t);
        }
        self->parts[i].model_aux = TObjFish__sub_8001EDB0(bml, v);
        self->parts[i].motion = get_bml_motion(bml, lbl_804EFB70[i]);
    }
    fn_8034009C(wait);
    TObjFish__sub_8033FF64(wait);
    wait->sub_8033FE30();
    VecCopy(&self->prev_position, &self->position);
    self->emitter = create_particle_emitter(&self->position, 0x225);
    if (self->emitter != NULL) {
        self->emitter->set_flags(0x40);
    }
    self->m_24 = 0;
    return wait;
}
#pragma pop

void *TObjFish::alloc(void *fish) {
    void *o = TObject::operator new(0x88);
    if (o != NULL) {
        o = TObjFish__sub_8034029C((TBoss6Demo15_TYPE2_WAIT *)o, (TObjFish *)fish);
    }
    return o;
}

}
