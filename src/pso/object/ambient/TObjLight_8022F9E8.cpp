#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/TUnk_804CC794.h"

#include "pso/system/vector.h"

#include "pso/technique/TechniqueChargeEmitter.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/task/TObject.h"
extern "C" {
extern u32 fire_technique_charge_effect_ids[];
void TObjLight__updateFireTechniqueCharge(TechniqueChargeEmitter* state);
void *__dt__13TUnk_804CC794Fv(void *arg0, s16 arg1);
s32 play_sound_effect(int, void *, int, int);
void stop_sound_request(s32 idx);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

extern s32 __vt__13TUnk_804CC794[];

void TObjLight__updateFireTechniqueCharge(TechniqueChargeEmitter* state) {
    ++state->age;
    if(state->age%10==0) {
        for(int i=0;i<3;++i)spawn_particle_effect(state->position,fire_technique_charge_effect_ids[i]);
    }
    if(!((TObjPlayer *)(state->actor))->check_flag_0x80())((TObject *)state)->queue_destruction();
    else if(state->age>=180)((TObject *)state)->queue_destruction();
}

void *__dt__13TUnk_804CC794Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_804CC794;
        stop_sound_request((s32)(*(void **)((s8 *)arg0 + 0x30)));
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
TUnk_804CC794::TUnk_804CC794(s32 arg1, s32 arg2) : TObject((TObject *)((void *)arg2)) {
    *(s32 *)((s8 *)this + 0x1C) = arg1;
    VecCopy((Vec *)(((u8 *)this) + 0x20), (const Vec *)(*(s32 *)((s8 *)this + 0x1C) + 0x2FC));
    this->m_2c = 0;
    *(s32 *)((s8 *)this + 0x30) = play_sound_effect(0x4002B21C, ((u8 *)this) + 0x20, 0, 0);
}
