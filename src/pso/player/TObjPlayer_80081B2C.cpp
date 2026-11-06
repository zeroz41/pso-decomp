#include "types.h"
#include "pso/unk/TUnk_8048E1A4.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

int queue_destruction__7TObjectFv(void*);

extern f32 lbl_805D9378;

f32 TUnk_8048E1A4::receive_physical_attack(void *arg1, f32) {
    if (arg1 != 0U) {
        this->m_354 = (this->m_354 + 1);
        if ((s32) this->m_354 >= 3) {
            *(s32 *)((s8 *)this + 0x334) = 2;
        }
    }
    return lbl_805D9378;
}

int TObjPlayer::queue_destruction() { return queue_destruction__7TObjectFv(this); }

}
