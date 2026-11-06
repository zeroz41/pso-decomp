#include "types.h"
#include "pso/weapon/TUnk_804A1380.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/unk/text_80087278.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecFoie.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A1380::emit_marker_effects() {
    s32 sp8;
    TObjPlayer *owner;

    get_joint_position(2, &sp8);
    spawn_particle_effect(&sp8, 0x1BF);
    if (is_mode_two_and_ready() != 0) {
        owner = this->owner;
        TTecFoie::create((void *)owner, &sp8, (void *)(*(s32 *)((s8 *)owner + 0x60)), (void *)3);
        return;
    }
    ((TObjPlayer *)this)->update_active_game_effect();
}

TUnk_804A1380::TUnk_804A1380(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
}

u8 *TObjPlayer::create_obj_80122C2C(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A1380(tl_05, arg0);
    }
    return NULL;
}

TUnk_804A1380::~TUnk_804A1380() {}
