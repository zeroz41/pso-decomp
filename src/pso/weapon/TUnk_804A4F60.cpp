#include "pso/object/base/TObjChara.h"
#include "pso/math/ClampedStep.h"
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include <stdlib.h>
#include "pso/weapon/TUnk_804A4F60.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_8012121C.h"
#include "pso/technique/TTecBarta.h"
#include "pso/technique/TTecFoie.h"
#include "pso/map/FloorArea.h"
#include "pso/item/TItem.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/vector.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/CapturedTargetList.h"

extern "C" {
}

void TUnk_804A4F60::activate_effect(s32 effect) {
    if (owner != NULL && is_current_area_item_enabled() != 0) {
        if (get_current_floor() == owner->get_floor()) {
            switch (effect) {
            case 0:
                TObjPlayer::create_tec_zonde(owner, &cast_point, &targets, 10);
                return;
            case 1:
                TTecFoie::create(owner, &cast_point, cast_rotation_y, 10);
                return;
            case 2:
                TTecBarta::create_ex(owner, &cast_position, cast_rotation_y, 10);
                break;
            }
        }
    }
}

void TUnk_804A4F60::psycho_wand_roll_extra() {
    CapturedTargetList *ext;
    CapturedTarget *target;

    get_joint_position(4, &cast_point);
    ext = owner->get_extended_state();
    target = ext->get_captured_target_entry(0);
    if (ext->get_captured_target_count() != 0) {
        targets.count = 1;
        targets.records[0].id = target->get_uid();
        targets.records[0].flag = target->get_captured_target_collider_index();
    } else {
        targets.count = 0;
    }
    cast_rotation_y = owner->rotation_y;
    VecCopy(&cast_position, &owner->position);
    send_activate_effect(3.0f * (3.0517578e-05f * (f32)rand()));
}

void TUnk_804A4F60::update_weapon() {
    s16 tp;
    s16 spent;

    if (is_current_area_item_enabled() != 0) {
        tp = get_actor_tp(owner);
        spent = last_tp - tp;
        if (spent != 0) {
            last_tp = tp;
        }
        if (spent > 0) {
            TObjectV8047c128_subtract_hp((u8 *)owner, spent);
            add_actor_tp((TObjChara *)owner, (s16)(spent / 2));
        }
    }
}

void TUnk_804A4F60::emit_marker_effects() {
    if (get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effect(this, 4);
    }
    if (is_mode_two_and_ready() != 0) {
        psycho_wand_roll_extra();
        return;
    }
    ((TItemWeapon *)this)->update_active_game_effect();
}

void TUnk_804A4F60::vfunc_60() {
    switch (TObjPlayer::get_player_list()) {
    case 2:
        rotate_matrix_z(NULL, rotation_z);
        return;
    case 5:
        rotate_matrix_z(NULL, -rotation_z);
        return;
    case 1:
        translate_matrix(0, 0.0f, -1.0f * extension, 0.0f);
        return;
    case 3:
    case 4:
    case 6:
        TItem::begin_effect_render();
        return;
    }
}

void TUnk_804A4F60::update_idle() {
    ::add_angle_clamped(&rotation_z, 0x38E, 0x2AAA);
    if (rotation_z == 0x2AAA) {
        ::approach_value(&extension, 0.5f, 6.0f);
    }
}

void TUnk_804A4F60::update_attack() {
    ::approach_value(&extension, -2.0f, 0.0f);
    if (0.0f == extension) {
        ::add_angle_clamped(&rotation_z, -0x71C, 0);
    }
}

TUnk_804A4F60::TUnk_804A4F60(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x22);
    rotation_z = 0;
    extension = 0.0f;
    last_tp = -1;
    cast_point.x = cast_point.y = cast_point.z = 0.0f;
    cast_rotation_y = 0;
    targets.count = 0;
}

TItem *create_psycho_wand(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A4F60(tl_05, item);
    }
    return NULL;
}

void TUnk_804A4F60::on_equipped() {
    last_tp = -1;
}

void TUnk_804A4F60::on_unequipped() {
    last_tp = -1;
}

TUnk_804A4F60::~TUnk_804A4F60() {}
