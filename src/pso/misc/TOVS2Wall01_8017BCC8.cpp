#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOVS2Wall01_8017BCC8.h"
#include "pso/unk/text_80087278.h"
#include "pso/misc/TOVS2Wall01.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 play_sound_effect(s32, s32, s32, s32);
s32 is_locally_controlled__10TObjPlayerFPv(u32);
u16 get_entity_id(u32);

void init__11TOVS2Wall01Fi(s32 arg0) {
    s32 var_r31;

    ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 1);
    var_r31 = 7;
    do {
        ((TOVS2Wall01 *)arg0)->spawn_debris(var_r31);
        var_r31 += 1;
    } while (var_r31 <= 0xF);
    spawn_particle_effect((void *)(arg0 + 0x38), 0x45);
    spawn_particle_effect((void *)(arg0 + 0x38), 0x46);
    play_sound_effect(0x4004BC05, arg0 + 0x38, 0, 0);
}

extern const f32 lbl_805DBAA8;

f32 take_hit__11TOVS2Wall01FPvUi(u8 *ovs2_wall01, u32 arg1) {
    u32 var_r31;

    var_r31 = 0U;
    get_entity_id(arg1);
    if (get_entity_id(arg1) < 4U) {
        var_r31 = arg1;
    }
    if ((var_r31 != 0U) && (is_locally_controlled__10TObjPlayerFPv(var_r31) == 1)) {
        ((TOVS2Wall01 *)ovs2_wall01)->m_33c = (s32) (((TOVS2Wall01 *)ovs2_wall01)->m_33c - 1);
        if ((s32) ((TOVS2Wall01 *)ovs2_wall01)->m_33c <= 0) {
            ((TOVS2Wall01 *)ovs2_wall01)->m_33c = 0;
            ((TOVS2Wall01 *)ovs2_wall01)->save_and_send_state(1);
        } else {
            ((TOVS2Wall01 *)ovs2_wall01)->save_and_send_state(0);
        }
        spawn_particle_effect((ovs2_wall01 + 0x38), 0x1D0);
        spawn_particle_effect((ovs2_wall01 + 0x38), 1);
    }
    return lbl_805DBAA8;
}

}
