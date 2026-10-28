#include "types.h"
#include "pso/unk/text_801250F8.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_801250F8_lbl_804A2260 {
    s32 value;
    u8 remaining[0xF4];
};

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * TItemWeapon__ct(void *, void *);
extern RecoveredGlobal_801250F8_lbl_804A2260 lbl_804A2260;
extern const f32 lbl_805DAD40;

typedef char RecoveredGlobal_801250F8_lbl_804A2260_size[sizeof(RecoveredGlobal_801250F8_lbl_804A2260) == 0xF8 ? 1 : -1];
u8 *TObjPlayer__sub_801250F8(u8 *player, u8 *arg1, s32 _w2) {
    TItemWeapon__ct(player, arg1);
    *(s32 **)((s8 *)player + 0x18) = &lbl_804A2260.value;
    ((TObjPlayer *)player)->set_status_flags(0x100022);
    *(f32 *)((s8 *)player + 0x1E4) = (f32) lbl_805DAD40;
    *(s32 *)((s8 *)player + 0x1F8) = 0;
    return player;
}

u8 *TObjPlayer::create_state_80125154(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TObjPlayer__sub_801250F8((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
