#include "types.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/item/TItemAttackCol.h"
#include "pso/player/TUnk_804A2548.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __dl__7TObjectFPv(void *);

extern s32 __vt__13TUnk_804A2548[];

void *__dt__13TUnk_804A2548Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_804A2548;
        ((TUnk_804E355C *)arg0)->destroy_attack_collision(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}

extern "C" {

int construct_attack_collision(void);

    extern const float lbl_805DAD54;
void*TUnk_804A2548::construct_explosion_collider() { construct_attack_collision(); *(int*)((char*)this + 0x18) = (int)__vt__13TUnk_804A2548; *(float *)&this->unk_C4 = lbl_805DAD54; return this; }

}
