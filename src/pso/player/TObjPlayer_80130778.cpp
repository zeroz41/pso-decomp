#include "types.h"
#include "pso/player/TUnk_804A69C0.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TItemShootModel_dtor.h"
#include "pso/player/TObjPlayer_80130778.h"
#include "pso/item/TUnk_804A6AD8.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void draw_weapon_at_joint(s32 arg0, s8 arg1);


}
TUnk_804A69C0::~TUnk_804A69C0() {

}


void TObjPlayer__sub_801307D0(void *arg0) {
    if (arg0 != NULL) {
        *(s32 *)((s8 *)arg0 + 0x204) = 1;
    }
}

void TUnk_804A6AD8::reserved_53() { draw_weapon_model(); get_joint_position(3, (char*)this + 0x208); get_joint_position(1, (char*)this + 0x220); draw_weapon_at_joint((s32)this, (s8)((void*)35)); get_joint_position(3, (char*)this + 0x214); get_joint_position(1, (char*)this + 0x22c); }

