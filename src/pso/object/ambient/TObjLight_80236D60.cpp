#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/TUnk_804CCAC8.h"

#include "pso/system/vector.h"

#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/task/TObject.h"
extern "C" {
__declspec(section ".data") u32 TObjLight__support_charge_effect_ids[2] = {0x1F4, 0x1F5};
s32 play_sound_effect(int, void *, int, int);
void stop_sound_request(s32 idx);
}

void TUnk_804CCAC8::run_task() {
    ++age;
    if(age%10==0) {
        for(int i=0;i<2;++i)spawn_particle_effect(position,TObjLight__support_charge_effect_ids[i]);
    }
    if(!((TObjPlayer *)(actor))->check_flag_0x80())queue_destruction();
    else if(age>=180)queue_destruction();
}

TUnk_804CCAC8::~TUnk_804CCAC8() {
    stop_sound_request(sound);
}

TUnk_804CCAC8::TUnk_804CCAC8(s32 actor, s32 parent) : TObject((TObject *)((void *)parent)) {
    this->actor = (void *)actor;
    VecCopy((Vec *)position, (const Vec *)((s32)this->actor + 0x2FC));
    age = 0;
    sound = play_sound_effect(0x4002B71B, position, 0, 0);
}
