#include "types.h"
#include "pso/camera/TCameraCtrl.h"

extern "C" {

s32 pack_flags__13TRaderMapCoreFii();

u8 TCameraCtrl::is_on_current_screen() {
    return (u8) ((*(s32 *)&this->unk_48 & pack_flags__13TRaderMapCoreFii()) != 0);
}

}
