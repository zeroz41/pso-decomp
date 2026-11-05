#include "types.h"
#include "pso/item/TUnk_804A1190.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80087278.h"
#include "pso/TMainTask.h"

void TUnk_804A1190::emit_marker_effects() {
    s32 sp8[6];
    s32 arg0 = (s32)this;

    ((TItemWeapon *)arg0)->get_joint_position(1, sp8);
    spawn_particle_effect(sp8, 0xC1);
}

TUnk_804A1190::~TUnk_804A1190() {}

TUnk_804A1190::TUnk_804A1190(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

extern "C" {
u8 *TObjPlayer__sub_801229EC(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A1190(tl_05, arg0);
    }
    return NULL;
}

}
