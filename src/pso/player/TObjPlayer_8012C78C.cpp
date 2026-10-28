#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TUnk_804A535C.h"
#include "pso/player/TObjPlayer_8012C78C.h"
#include "pso/unk/text_80120908.h"
#include "pso/TAdRicoRing.h"
#include "pso/player/TObjPlayer.h"

void TUnk_804A535C::reserved_53() {
    s32 temp_r31;
    u8 *arg0 = (u8 *)this;

    temp_r31 = *(s32 *)((s8 *)arg0 + 0xF4);
    ((FlagWord *)(arg0 + 0x1F8))->set(1);
    ((TItemWeapon *)arg0)->draw_weapon_model();
    ((TItemWeapon *)arg0)->get_joint_position(1, (arg0 + 0x1FC));
    *(s32 *)((s8 *)arg0 + 0xF4) = (s32) *(s32 *)((s8 *)arg0 + 0x180);
    ((FlagWord *)(arg0 + 0x1F8))->clear(1);
    draw_weapon_at_joint((s32)arg0, 0x23);
    ((TItemWeapon *)arg0)->get_joint_position(1, (arg0 + 0x208));
    *(s32 *)((s8 *)arg0 + 0xF4) = temp_r31;
}
