#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/enemy/darkgunner/TObjEneDarkGunCenter.h"
#include "pso/player/TObjPlayer.h"
struct Obj_800A0814 { u8 pad[0x374]; s32 mode; s32 timer; s32 count; u8 pad2[4]; u16 ids[1]; };

void TObjEneDarkGunCenter::hide_linked_enemies() {
    Obj_800A0814 *self = (Obj_800A0814 *)this;
    s32 i;
    for (i = 0; i < *(s32 *)&this->m_37c; i++) {
        void *e = get_enemy_entity(self->ids[i]);
        if (e != 0) {
            ((TObjPlayer *)e)->set_hidden_flag();
        }
    }
    *(s32 *)&this->m_378 = 0x78;
    *(s32 *)&this->m_374 = 4;
}
