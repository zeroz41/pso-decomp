#include "types.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/ui/TAdPlyStatusGC_8033FD48.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/boss/TBoss6Demo15_TYPE2_WAIT.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/object/TObjFish.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/TNowLoading.h"
#include "pso/boss/TBoss4Type2_8033FEEC.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/TParticleCtrl.h"

extern "C" {
void *TObjFish__sub_8034029C(TBoss6Demo15_TYPE2_WAIT *, TObjFish *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void *__nw__7TObjectFUl(int);
void fn_80340040(void *);

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
            queue_destruction__7TObjectFv(arg0);
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
void fn_8034009C(TBoss6Demo15_TYPE2_WAIT *self);

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
    void *o = __nw__7TObjectFUl(0x88);
    if (o != NULL) {
        o = TObjFish__sub_8034029C((TBoss6Demo15_TYPE2_WAIT *)o, (TObjFish *)fish);
    }
    return o;
}

}
