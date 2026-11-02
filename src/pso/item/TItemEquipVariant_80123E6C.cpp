#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TUnk_804A1E28.h"
#include "pso/item/TItem.h"

void TUnk_804A1E28::update_idle() {
    s16 temp_r0;

    temp_r0 = *(s16 *)((s8 *)this + 0x1FE);
    if ((temp_r0 == 1) || (temp_r0 == 0)) {
        *(s16 *)((s8 *)this + 0x1FE) = 2;
    }
}

void TUnk_804A1E28::update_attack() {
    s16 temp_r0;

    temp_r0 = *(s16 *)&this->unk_1FE;
    if ((temp_r0 == 2) || (temp_r0 == 3)) {
        *(s16 *)&this->unk_1FE = 1;
    }
}

TUnk_804A1E28::~TUnk_804A1E28() {

}
