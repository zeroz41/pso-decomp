#include "types.h"
#include "pso/unk/text_8035D49C.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8035D49C_lbl_804F1EC8 {
    s32 value;
    u8 remaining[0xF4];
};

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * TItemWeapon__ct(void *, void *);
extern RecoveredGlobal_8035D49C_lbl_804F1EC8 ruby_bullet_weapon_vtable;

typedef char RecoveredGlobal_8035D49C_lbl_804F1EC8_size[sizeof(RecoveredGlobal_8035D49C_lbl_804F1EC8) == 0xF8 ? 1 : -1];
u8 *fn_8035D49C(u8 *player, u8 *arg1, s32 _w2) {
    TItemWeapon__ct(player, arg1);
    *(s32 **)((s8 *)player + 0x18) = &ruby_bullet_weapon_vtable.value;
    ((TObjPlayer *)player)->set_status_flags(0x8000);
    return player;
}
}

u8 *alloc_and_init_obj_effect(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(fn_8035D49C((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}
