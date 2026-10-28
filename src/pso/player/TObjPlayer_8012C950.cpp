#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/unk/TUnk_804A5340.h"
#include "pso/item/TItemShootModel_dtor.h"
#include "pso/player/TObjPlayer_8012C950.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TAdRicoRing.h"

extern "C" {

s32 test_flags_any(void *, int);


}
TUnk_804A5340::~TUnk_804A5340() {

}
void rocket_punch_return_timer(u32 arg0) {
    if (arg0 != 0U) {
        ((FlagWord *)(arg0 + 0x1F8))->clear(2);
    }
}

s32 TObjPlayer::get_hp_by_flag() {
    u8 *arg0 = (u8 *)this;
    if (test_flags_any((u8 *)&this->unk_1F8, 4) != 0) {
        return *(s32 *)((s8 *)arg0 + 0x188);
    }
    return this->m_184;
}
