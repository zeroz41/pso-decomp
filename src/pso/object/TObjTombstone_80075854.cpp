#include "types.h"
#include "pso/object/TObjTombstone.h"

extern "C" {

u32 get_player_by_client_id(s32);
s32 TWindowCtrlMain__sub_8024CE58();

s32 obj_testFlags30__14TObjCollidableFUl(u32, s32);

s32 TObjTombstone::check_all_players_active() {
    s32 var_r31;
    u32 temp_r3;

    if (TWindowCtrlMain__sub_8024CE58() == 0) {
        return 0;
    }
    var_r31 = 0;
loop_3:
    temp_r3 = get_player_by_client_id(var_r31);
    if ((temp_r3 != 0U) && (obj_testFlags30__14TObjCollidableFUl(temp_r3, 0x02000000) != 0)) {
        return 0;
    }
    var_r31 += 1;
    if (var_r31 >= 4) {
        return 1;
    }
    goto loop_3;
}

extern f32 lbl_805D91A4;

s32 TObjTombstone::check_height_ready() {
    if (TObjTombstone::check_all_players_active() == 0) {
        return 0;
    }
    return (u32)__cntlzw(this->m_b0 > lbl_805D91A4) >> 5;
}

}
