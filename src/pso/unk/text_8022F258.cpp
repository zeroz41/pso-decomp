#include "pso/effect/TechniqueChargeEmitter.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_8022F258.h"
#include "types.h"
#include "pso/misc/TechniqueBoost.h"
#include "pso/player/TObjPlayer.h"
extern u32 dark_technique_charge_effect_ids[];
extern "C" {
s32 __construct_array(void *, void *, int, int, int);
// TechniqueBoost::TechniqueBoost(), handed to __construct_array.
extern s32 __ct__14TechniqueBoostFv[];

void *fn_8022F258(void *self) {
    __construct_array(self, (void *)__ct__14TechniqueBoostFv, 0, 8, 6);
    ((TechniqueBoostTable *)self)->clear();
    return self;
}
}

void updateDarkTechniqueCharge(TechniqueChargeEmitter* state) {
    ++state->age;
    if(state->age%10==0) {
        for(int i=0;i<3;++i)spawn_particle_effect(state->position,dark_technique_charge_effect_ids[i]);
    }
    if(!((TObjPlayer *)(state->actor))->check_flag_0x80())queue_destruction__7TObjectFv(state);
    else if(state->age>=180)queue_destruction__7TObjectFv(state);
}
