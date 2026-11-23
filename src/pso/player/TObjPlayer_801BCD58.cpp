#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjBase.h"

extern "C" {

int TObjPlayer__sub_801BEF60(void*, int);

extern "C" {

void TObjPlayer::init_control_mode(s32 role) {
    if (TObjPlayer::is_locally_controlled(this) != 0) {
        this->controller_port = (s32) (role & 3);
        pad_binding.init(this->get_entity_id(), this->controller_port);
        return;
    }
    TObjPlayer__sub_801BEF60((void *) (((u8 *)this) + 0x550), 0);
}

}

}
