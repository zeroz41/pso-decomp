#include "types.h"
#include "pso/player/TObjPlayer_80351748.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjBase.h"

extern "C" {

int TObjPlayer__sub_801BEF60(void*, int);

extern "C" {

void TObjPlayer::init_control_mode(s32 role) {
    if (TObjPlayer::is_locally_controlled(this) != 0) {
        this->controller_port = (s32) (role & 3);
        init_pad_binding((u8 *)this + 0x550, (this->get_entity_id()), (int) ((s16) this->controller_port));
        return;
    }
    TObjPlayer__sub_801BEF60((void *) (((u8 *)this) + 0x550), 0);
}

}

}
