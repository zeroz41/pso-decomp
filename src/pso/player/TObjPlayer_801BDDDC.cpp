#include "types.h"
#include "pso/player/TObjPlayer_801C1FF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"

extern "C" {

s32 construct_player_instance__10TObjPlayerFlslPUc(s32, s32, u16, s32, s32);
s32 __nw__7TObjectFUl(s32);
s32 get_char_data__10TObjPlayerFv(s32);

extern s32 tl_03;

s32 TObjPlayer::create(u32 arg0, s32 arg1) {
    s32 temp_r31;
    s32 var_r30;

    var_r30 = __nw__7TObjectFUl(0xDB8);
    if (var_r30 != 0) {
        var_r30 = construct_player_instance__10TObjPlayerFlslPUc(var_r30, tl_03, (u16)arg0, TObjPlayer__sub_801C22B4((void *)arg1), get_char_data__10TObjPlayerFv(arg1));
    }
    ((TLobby *)(var_r30 + 0xDAC))->copy_header_struct((void*)(((TObjPlayer *)arg1)->get_sub_obj()));
    return var_r30;
}

}
