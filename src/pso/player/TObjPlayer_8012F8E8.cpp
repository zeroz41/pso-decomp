#include "types.h"
#include "pso/player/TObjPlayer_8012F8E8.h"
#include "pso/item/TUnk_804A65E0.h"
#include "pso/items/TItemWeapon.h"
#include "pso/misc/TTecGiZonde.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

u8 *get_captured_target_entry(s32, s32);
s32 get_captured_target_count();
s32 get_extended_state__10TObjPlayerFv(int);

void TUnk_804A65E0::emit_marker_effects() {
    s32 temp_r3;
    u8 *var_r30;
    s32 i;
    u8 *captured_target_entry;
    u8 *arg0 = (u8 *)this;

    if (is_mode_two_and_ready() != 0) {
        ((TItemWeapon *)arg0)->get_joint_position(0, (arg0 + 0x1F8));
        temp_r3 = get_extended_state__10TObjPlayerFv((int) (*(s32 *)((s8 *)arg0 + 0xF0)));
        if (temp_r3 != 0) {
            ((TUnk_804A65E0 *)arg0)->m_204 = get_captured_target_count();
            var_r30 = arg0 + 0x208;
            i = 0;
            do {
                captured_target_entry = get_captured_target_entry(temp_r3, i);
                if (captured_target_entry != NULL) {
                    *(u16 *)((s8 *)var_r30 + 0) = (u16) *(u16 *)((s8 *)captured_target_entry + 0);
                    *(s16 *)((s8 *)var_r30 + 2) = (s16) *(s16 *)((s8 *)captured_target_entry + 2);
                    var_r30 += 8;
                }
                i += 1;
            } while (i != 0xA);
            if ((s32) ((TUnk_804A65E0 *)arg0)->m_204 != 0) {
                ((TTecGiZonde *)(*(s32 *)((s8 *)arg0 + 0xF0)))->create((u8 *)&this->unk_1F8, (u8 *)&this->m_204, (void *) (((TObjPlayer *)arg0)->get_tp()));
            }
            ((TItemWeapon *)arg0)->roll_technique();
        }
    } else {
        ((TObjPlayer *)arg0)->update_active_game_effect();
    }
}

}
