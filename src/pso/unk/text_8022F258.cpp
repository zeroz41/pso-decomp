#include "pso/technique/TechniqueChargeEmitter.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "types.h"
#include "pso/technique/TechniqueBoost.h"
#include "pso/player/TObjPlayer.h"
extern u32 dark_technique_charge_effect_ids[];
TechniqueBoostTable::TechniqueBoostTable() {
    clear();
}

void updateDarkTechniqueCharge(TechniqueChargeEmitter* state) {
    ++state->age;
    if(state->age%10==0) {
        for(int i=0;i<3;++i)spawn_particle_effect(state->position,dark_technique_charge_effect_ids[i]);
    }
    if(!((TObjPlayer *)(state->actor))->check_flag_0x80())queue_destruction__7TObjectFv(state);
    else if(state->age>=180)queue_destruction__7TObjectFv(state);
}
