#include "types.h"
#include "pso/player/TObjPlayer_801C1FF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TLobby.h"

extern "C" {


s32 TObjPlayer::create(u32 slot, saddr player) {
    s32 temp_r31;
    saddr var_r30;

    var_r30 = (saddr)new TObjPlayer(tl_03, slot & 0xFFFF, get_field_0_s32((void *)player), ((TObjPlayer *)player)->get_char_data());
    ((TLobby *)(var_r30 + 0xDAC))->copy_header_struct((void*)(((TObjPlayer *)player)->get_sub_obj()));
    return var_r30;
}

}
