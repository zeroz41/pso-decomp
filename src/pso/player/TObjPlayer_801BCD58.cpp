#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

int TObjPlayer__sub_801BEF60(void*, int);
s32 init_pad_binding(void *, s32, int);
s32 get_entity_id(void *);

extern "C" {

void TObjPlayer::init_control_mode(s32 role) {
    if (TObjPlayer::is_locally_controlled(this) != 0) {
        this->m_3d0 = (s32) (role & 3);
        init_pad_binding((void *) (((u8 *)this) + 0x550), (get_entity_id(this)), (int) ((s16) this->m_3d0));
        return;
    }
    TObjPlayer__sub_801BEF60((void *) (((u8 *)this) + 0x550), 0);
}

}

}
