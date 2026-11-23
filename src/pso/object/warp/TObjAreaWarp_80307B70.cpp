#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"

extern "C" {


s32 TObjAreaWarp::find_active_player() {
    u32 temp_r31;
    s32 var_r30;
    TObjPlayer *player;

    if ((s32) *(s32 *)&this->m_down != 0) {
        temp_r31 = *(s32 *)&this->entity_id & *(s32 *)((s8 *)this + 0x20);
        var_r30 = 0;
loop_2:
        if (!((temp_r31 >> var_r30) & 1) && (player = get_player_by_client_id(var_r30)) != NULL) {
            return player->get_entity_id();
        }
        var_r30 += 1;
        if (var_r30 >= 4) {
            goto block_6;
        }
        goto loop_2;
    }
block_6:
    return (u16)(0U);
}

}
