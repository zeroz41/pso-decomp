#include "types.h"
#include "pso/item/TUnk_804A3168.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80120D50.h"

extern "C" {


void TUnk_804A3168::emit_marker_effects() {
    s32 arg0 = (s32)this;
    if (is_mode_two_and_ready() != 0) {
        ((TObjPlayer *)arg0)->drain_owner_hp_fraction(0.05f);
        ((TObjPlayer *)arg0)->launch_rare_weapon_special(0, 1, 1.1666666f);
        return;
    }
    ((TObjPlayer *)arg0)->update_active_game_effect();
}

}

TUnk_804A3168::~TUnk_804A3168() {}

struct Self_801272B4 { u8 pad[0x18]; void *vt; u8 pad1c[0x1e4 - 0x1c]; f32 f1e4; u8 pad1e8[0x1f0 - 0x1e8]; void *f1f0; };

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
void create_lavis_shot(void);
extern void *__vt__13TUnk_804A3168[];

u8 *TObjPlayer__sub_801272B4(void *self_, s32 a, void *b) {
    Self_801272B4 *self = (Self_801272B4 *)self_;
    __ct__11TItemWeaponFP7TObjectPUc((TItemWeapon *)((u8 *)self), (void *)a, (u8 *)b);
    self->vt = __vt__13TUnk_804A3168;
    ((TItemWeapon *)self)->set_weapon_flags(0x100622);
    self->f1f0 = (void *)create_lavis_shot;
    ((TObjPlayer *)self)->m_1e4 = 10.0f;
    return (u8 *)self;
}

u8 *TObjPlayer__sub_80127314(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TObjPlayer__sub_801272B4(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
