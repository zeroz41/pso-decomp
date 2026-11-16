#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"

extern "C" {

void *TItemShootParticle__ct(void *, u32, s32, s32, f32);

extern f32 lbl_805DAC60;

void *TObjPlayer::spawn_shoot_particle(u32 arg0, s32 arg1, s32 arg2, f32 farg0) {
    if ((lbl_805DAC60 != farg0) && (arg0 != 0U)) {
        void *obj = TObject::operator new(0x64);
        if (obj != NULL) {
            obj = TItemShootParticle__ct(obj, arg0, arg1, arg2, farg0);
        }
        return obj;
    }
    return NULL;
}

}
