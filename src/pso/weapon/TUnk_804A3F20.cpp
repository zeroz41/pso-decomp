#include "types.h"
#include "pso/player/TObjPlayer_80128A70.h"
#include "pso/weapon/TUnk_804A3F20.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A3F20::emit_marker_effects() {
    TObjPlayer__sub_80128A70();
    if (launch_shot((u8 *)&shot_origins[0], 0, 0, 1) != 0) {
        launch_shot((u8 *)&shot_origins[1], 0, 0, 0);
        return;
    }
    launch_shot((u8 *)&shot_origins[1], 0, 0, 1);
}

void TUnk_804A3F20::reserved_53() {
    ((TObjPlayer *)this)->draw_status_icons(&shot_origins[0], &shot_origins[1]);
}

TUnk_804A3F20::TUnk_804A3F20(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    set_weapon_flags(515);
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
}

u8 *TObjPlayer::create_variant(s32 arg0) {
    if (arg0 != 0) {
        return (u8 *)new TUnk_804A3F20(tl_05, (u8 *)arg0);
    }
    return NULL;
}

TUnk_804A3F20::~TUnk_804A3F20() {}
