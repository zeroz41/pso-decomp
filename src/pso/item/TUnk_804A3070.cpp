#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TUnk_804A3070.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80120D50.h"
#include "pso/item/TItemProShield.h"

extern "C" {

s32 play_sound_effect(s32, s32, s32, s32);


void TUnk_804A3070::emit_marker_effects() {
    if (get_item_index() == 0) {
        if (is_mode_two_and_ready() != 0) {
            ((TObjPlayer *)this)->drain_owner_hp_fraction(0.07f);
            ((TObjPlayer *)this)->launch_rare_weapon_special(0, 1, 3.5f);
            play_sound_effect(0x4001A341, (s32)this->owner + 0x38, 0, 0);
            return;
        }
        ((TObjPlayer *)this)->update_active_game_effect();
        return;
    }
    ((TObjPlayer *)this)->update_active_game_effect();
}

}

TUnk_804A3070::~TUnk_804A3070() {

}

struct Self_8012712C { u8 pad[0x18]; void *vt; u8 pad1c[0x1e4 - 0x1c]; f32 f1e4; u8 pad1e8[0x1f0 - 0x1e8]; void *f1f0; };

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
void create_lavis_shot(void);
extern void *__vt__13TUnk_804A3070[];

u8 *TUnk_804A3070::construct_agito(s32 a, void *b) {
    Self_8012712C *self = (Self_8012712C *)this;
    __ct__11TItemWeaponFP7TObjectPUc((TItemWeapon *)((u8 *)self), (void *)a, (u8 *)b);
    self->vt = __vt__13TUnk_804A3070;
    ((TItemWeapon *)self)->set_weapon_flags(2);
    if (((TItem *)self)->get_item_index() == 0) {
        ((TItemWeapon *)self)->set_weapon_flags(0x20);
        self->f1f0 = (void *)create_lavis_shot;
        self->f1e4 = 10.0f;
    }
    return (u8 *)self;
}
}

u8 *create_agito_weapon(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((TUnk_804A3070 *)temp_r3)->construct_agito(tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}
