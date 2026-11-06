#include "types.h"
#include "pso/player/TObjPlayer_80128A70.h"
#include "pso/player/TUnk_804A4648.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEffNeedle.h"
#include "pso/item/TItem.h"
#include "pso/TMainTask.h"

extern "C" {
// The spread of the five needles (launch_shot angles).
extern const s32 lbl_8043E968[];
extern s32 create_shoot_model__10TObjPlayerFUiiif[];
}

void TUnk_804A4648::emit_marker_effects() {
    WeaponVector pos;
    TObjPlayer__sub_80128A70();
    get_joint_position(1, &pos);
    launch_shot((u8 *)&pos, 0, lbl_8043E968[0], 1);
    get_joint_position(1, &pos);
    launch_shot((u8 *)&pos, 1, lbl_8043E968[1], 1);
    get_joint_position(1, &pos);
    launch_shot((u8 *)&pos, 2, lbl_8043E968[2], 1);
    get_joint_position(1, &pos);
    launch_shot((u8 *)&pos, 3, lbl_8043E968[3], 1);
    get_joint_position(1, &pos);
    launch_shot((u8 *)&pos, 4, lbl_8043E968[4], 1);
}

TUnk_804A4648::TUnk_804A4648(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    set_weapon_flags(2);
    hit_callback = (WeaponHitCallback)spawn_target_needle;
    impact_callback = (WeaponHitCallback)spawn_needle_wall_impact;
    shot_callback = (WeaponShotCallback)create_shoot_model__10TObjPlayerFUiiif;
}

u8 *TObjPlayer::create_state_2(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A4648(tl_05, arg0);
    }
    return NULL;
}

TUnk_804A4648::~TUnk_804A4648() {}
