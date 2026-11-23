#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/weapon/TUnk_804A2678.h"
#include "pso/item/TUnk_804A0688.h"
#include "pso/system/task/TObject.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItem.h"
#include "pso/system/ItemEffects.h"
#include "pso/map/FloorArea.h"
#include "dolphin/mtx.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/technique/TTecGiFoie.h"
#include "pso/system/task/TMainTask.h"

#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_80011014.h"

extern "C" s32 is_item_area_enabled(s32 area);



void TUnk_804A2678::emit_marker_effects() {
    s32 sp8;
    if (is_mode_two_and_ready() != 0) {
        if ((((TObjPlayer *)((u8 *)this->owner + 0x7CC))->get_stage_strike_count() == 0) && (get_joint_position(0, &sp8) != 0)) {
            TTecGiFoie::create(this->owner, &sp8, ((TItemWeapon *)this)->get_tp());
            roll_technique();
        }
    } else {
        ((TItemWeapon *)this)->update_active_game_effect();
    }
}
void TUnk_804A2678::on_unequipped() { floor_area = -1; }
void TUnk_804A2678::on_equipped() {
    floor_area = -1;
    if (effect_objects != NULL) {
        new TUnk_804A0688(effect_objects, get_owner_client(), 0x5A);
    }
    this->roll_technique();
    this->roll_technique();
}
void TUnk_804A2678::update_weapon() {
    s32 area;
    area = get_current_floor_area();
    if ((area != floor_area) && (this->is_model_shown() != 0)) {
        floor_area = area;
        if (is_item_area_enabled(area) != 0) {
            spawn_item_follow_effect((saddr)tl_05, (uaddr)this, 1, 0x1AE);
            spawn_item_follow_effect((saddr)tl_05, (uaddr)this, 2, 0x1AE);
        }
    }
}

TUnk_804A2678::~TUnk_804A2678() {

}

TUnk_804A2678::TUnk_804A2678(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    ((TObjPlayer *)this)->set_effect_state(10);
    floor_area = -1;
}

TItem *TObjPlayer::create_state_vt2678(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A2678(tl_05, item);
    }
    return NULL;
}
