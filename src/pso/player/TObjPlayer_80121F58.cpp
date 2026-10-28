#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/player/TObjPlayer_80121F58.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void TItemWeapon__ct(void *);

extern s32 lbl_804A0CB8[];
extern const f32 lbl_805DACD4;

void *belra_cannon_ct(void *player) {
    TItemWeapon__ct(player);
    *(s32 **)((s8 *)player + 0x18) = lbl_804A0CB8;
    ((FlagWord *)((char *)player + 376))->set(32);
    *(f32 *)((s8 *)player + 0x1E4) = lbl_805DACD4;
    ((TObjPlayer *)player)->set_status_flags(2);
    *(u32 *)((s8 *)player + 0x1F8) = 1;
    return player;
}

}
