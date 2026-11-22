#include "types.h"
#include "pso/player/TObjPlayer_801C1FF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"

extern "C" {

s32 construct_player_instance__10TObjPlayerFlslPUc(s32, s32, u16, s32, s32);

extern s32 tl_03;

s32 TObjPlayer::create(u32 slot, saddr arg1) {
    s32 temp_r31;
    saddr var_r30;

    var_r30 = (saddr)TObject::operator new(0xDB8);
    if (var_r30 != 0) {
        var_r30 = construct_player_instance__10TObjPlayerFlslPUc(var_r30, tl_03, (u16)slot, get_field_0_s32((void *)arg1), (saddr)((TObjPlayer *)arg1)->get_char_data());
    }
    ((TLobby *)(var_r30 + 0xDAC))->copy_header_struct((void*)(((TObjPlayer *)arg1)->get_sub_obj()));
    return var_r30;
}

}
