#include "types.h"
#include "pso/unk/text_80086E28.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/frontend/TAdLoadQuestPrtTxtGC.h"
struct Rec_80086E28 { u8 pad[0x98]; };

struct Rec_80086EF8 { u8 pad[0x98]; };

extern "C" {
void *__nw__7TObjectFUl(int);
extern s32 particle_pool_limit;
extern Rec_80086E28 *particle_global_entry_table;
extern Rec_80086E28 *particle_area_entry_table;
void *__ct__13TParticleCtrlFv(void *, void *, void *, void *, s32, s32, s32, s32, u16);
void *TAdLoadQuestPrtTxtGC::create_particle(void *position, s32 arg1, s32 use_self) {
    void *o;
    if (particle_pool_limit > arg1) {
        o = __nw__7TObjectFUl(0x78);
        if (o != NULL) {
            o = ((TParticleCtrl *)o)->initialize((const void *)position, (s32)&particle_global_entry_table[arg1], 0, 0, 0, (s32)use_self);
        }
        return o;
    }
    if (particle_pool_limit + 0x40 > arg1) {
        s32 idx = arg1 - 0x200;
        o = __nw__7TObjectFUl(0x78);
        if (o != NULL) {
            o = ((TParticleCtrl *)o)->initialize((const void *)position, (s32)&particle_area_entry_table[idx], 0, 0, 0, (s32)use_self);
        }
        return o;
    }
    return NULL;
}
void *create_particle_controller_with_angles(void *arg0, void *arg1, s32 arg2, s32 arg3, u16 arg4) {
    void *o;
    if (particle_pool_limit > arg2) {
        o = __nw__7TObjectFUl(0x78);
        if (o != NULL) {
            o = __ct__13TParticleCtrlFv(o, arg0, arg1, &(*(Rec_80086EF8 * *)&particle_global_entry_table)[arg2], 0, 0, 0, arg3, arg4);
        }
        return o;
    }
    if (particle_pool_limit + 0x40 > arg2) {
        s32 idx = arg2 - 0x200;
        o = __nw__7TObjectFUl(0x78);
        if (o != NULL) {
            o = __ct__13TParticleCtrlFv(o, arg0, arg1, &(*(Rec_80086EF8 * *)&particle_area_entry_table)[idx], 0, 0, 0, arg3, arg4);
        }
        return o;
    }
    return NULL;
}

}
