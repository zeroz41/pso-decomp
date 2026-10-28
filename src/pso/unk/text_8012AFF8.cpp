#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/unk/text_80120908.h"
#include "pso/player/TUnk_804A4C78.h"
#include "pso/player/TObjPlayer.h"
struct Obj_8012AFF8 {
    u8 pad0[0xF4];
    s32 unkF4;
    u8 padF8[0x188 - 0xF8];
    s32 unk188;
};

extern "C" {
void update_trail_slot__11TItemWeaponFPvi(void *, s32);
s32 is_rand_below_threshold__10TObjPlayerFv(void *);
extern u8 item_render_state;
void TUnk_804A4C78::reserved_53() {
    s32 saved;
    s32 savedF4;
    saved = sub_8012B1F8();
    savedF4 = ((Obj_8012AFF8 *)this)->unkF4;
    if (is_rand_below_threshold__10TObjPlayerFv(this) == 0) {
        sub_8012B1F0(8);
        ((TObjPlayer *)(&item_render_state))->set_flags(4);
    }
    draw_weapon_model();
    if (sub_8012B1F8() != 8) {
        update_trail_slot__11TItemWeaponFPvi(this, 0);
    }
    ((Obj_8012AFF8 *)this)->unkF4 = ((Obj_8012AFF8 *)this)->unk188;
    if (is_rand_below_threshold__10TObjPlayerFv(this) == 0) {
        sub_8012B1F0(8);
        ((TObjPlayer *)(&item_render_state))->set_flags(4);
    } else {
        sub_8012B1F0(saved);
    }
    draw_weapon_at_joint((s32)this, 0x23);
    if (sub_8012B1F8() != 8) {
        update_trail_slot__11TItemWeaponFPvi(this, 1);
    }
    ((Obj_8012AFF8 *)this)->unkF4 = savedF4;
    sub_8012B1F0(saved);
}

}
