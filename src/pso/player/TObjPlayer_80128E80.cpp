#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/item/TUnk_804A403C.h"
#include "pso/player/TObjPlayer_80128E80.h"
#include "pso/unk/text_80120908.h"
#include "pso/TAdRicoRing.h"
#include "pso/player/TObjPlayer.h"

void TUnk_804A403C::reserved_53() {
    s32 temp_r31;
    u8 *arg0 = (u8 *)this;

    temp_r31 = *(s32 *)((s8 *)arg0 + 0xF4);
    ((FlagWord *)(arg0 + 0x1FC))->set(1);
    draw_weapon_at_joint((s32)arg0, 0x30);
    ((TObjPlayer *)arg0)->draw_icon(1, (s32)(arg0 + 0x200));
    *(s32 *)((s8 *)arg0 + 0xF4) = (s32) *(s32 *)((s8 *)arg0 + 0x180);
    ((FlagWord *)(arg0 + 0x1FC))->clear(1);
    draw_weapon_at_joint((s32)arg0, 0x23);
    ((TObjPlayer *)arg0)->draw_icon(1, (s32)(arg0 + 0x20C));
    *(s32 *)((s8 *)arg0 + 0xF4) = temp_r31;
}
