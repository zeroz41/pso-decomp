#include "types.h"
#include "pso/misc/TUnk_804CCD0C.h"
#include "pso/misc/TLobby_80226070.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/unk/text_80087278.h"

#include "pso/system/vector.h"

#include "pso/effect/TechniqueChargeEmitter.h"
#include "pso/misc/TTecSlicer.h"
#include "pso/player/TObjPlayer.h"
extern "C" {
extern u32 lightning_charge_particle_ids[];
void queue_destruction__7TObjectFv(void *arg0);
void TTecSlicer__updateLightningTechniqueCharge(TechniqueChargeEmitter* state);
s32 play_sound_effect(int, void *, int, int);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

s32 TTecSlicer::get_field_110() { return *(s32 *)&this->model; }
s16 TTecSlicer::get_remain_count() { return *(s16*)((char*)this + 0x11e); }
void TTecSlicer::destroy_if_set() {
    u32 arg0 = (u32)this;
    if (arg0 != 0U) {
        queue_destruction__7TObjectFv((void *)arg0);
    }
}
s32 TTecSlicer::dt(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

extern s32 __vt__13TUnk_804CCD0C[];

void TTecSlicer__updateLightningTechniqueCharge(TechniqueChargeEmitter* state) {
    ++state->age;
    if(state->age%10==0) {
        for(int i=0;i<3;++i)spawn_particle_effect(state->position,lightning_charge_particle_ids[i]);
    }
    if(!((TObjPlayer *)(state->actor))->check_flag_0x80())queue_destruction__7TObjectFv((state));
    else if(state->age>=180)queue_destruction__7TObjectFv((state));
}

void *TTecSlicer::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804CCD0C;
        stop_sound_request((s32)this->m_30);
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}
TUnk_804CCD0C::TUnk_804CCD0C(s32 arg1, s32 arg2) : TObject((TObject *)((void *)arg2)) {
    *(s32 *)((s8 *)this + 0x1C) = arg1;
    VecCopy((Vec *)(((u8 *)this) + 0x20), (const Vec *)(*(s32 *)((s8 *)this + 0x1C) + 0x2FC));
    this->m_2c = 0;
    *(s32 *)((s8 *)this + 0x30) = play_sound_effect(0x4002B51E, ((u8 *)this) + 0x20, 0, 0);
}
