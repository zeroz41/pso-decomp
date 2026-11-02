#include "types.h"
#include "pso/player/TUnk_804A2548.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

int construct_attack_collision(void);

    extern unsigned char __vt__13TUnk_804A2548[];
    extern const float lbl_805DAD54;
void*TUnk_804A2548::construct_explosion_collider() { construct_attack_collision(); *(int*)((char*)this + 0x18) = (int)__vt__13TUnk_804A2548; *(float *)&this->unk_C4 = lbl_805DAD54; return this; }

}
