#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 is_locally_controlled__10TObjPlayerFPv();
int TObjPlayer__sub_801BEF60(void*, int);
s32 init_pad_binding(void *, void *, int);
s32 get_entity_id(void *);

extern "C" {

void TObjPlayer::init_control_mode(s32 arg1) {
    if (is_locally_controlled__10TObjPlayerFPv() != 0) {
        this->m_3d0 = (s32) (arg1 & 3);
        init_pad_binding((void *) (((u8 *)this) + 0x550), (void *) (get_entity_id(this)), (int) ((s16) this->m_3d0));
        return;
    }
    TObjPlayer__sub_801BEF60((void *) (((u8 *)this) + 0x550), 0);
}

}

}
