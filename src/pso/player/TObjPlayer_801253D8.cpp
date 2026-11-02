#include "types.h"
#include "pso/player/TUnk_804A2450.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

int __ct__11TItemWeaponFP7TObjectPUc(void);

    extern unsigned char spawn_shoot_particle_9f[];
    extern unsigned char lbl_804A2450[];
void*TUnk_804A2450::init_vtable_and_handler() { __ct__11TItemWeaponFP7TObjectPUc(); *(int*)((char*)this + 0x18) = (int)lbl_804A2450; *(int*)((char*)this + 0x1f0) = (int)spawn_shoot_particle_9f; (*(float *)((u8 *)this + 0x1E4)) = 11.0f; return this; }

}
