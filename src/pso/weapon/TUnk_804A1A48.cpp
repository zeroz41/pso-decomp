#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_80363BE0.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/weapon/TUnk_804A1A48.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/model_render_state.h"
#include "pso/unk/text_80120908.h"

void TUnk_804A1A48::reserved_53() {
    Vec pos;

    if ((item_model != NULL) && (is_hidden() == 0)) {
        NJS_OBJECT *model = item_model;
        NJS_OBJECT *child = model->child;
        child->evalflags |= NJD_EVAL_HIDE;
        NJS_OBJECT *grandchild = child->child;
        grandchild->evalflags |= NJD_EVAL_HIDE;
        NJS_OBJECT *sibling = grandchild->sibling;
        sibling->evalflags |= NJD_EVAL_HIDE;
        draw_weapon_at_joint((saddr)this, 0x30);
        child->evalflags &= ~NJD_EVAL_HIDE;
        grandchild->evalflags &= ~NJD_EVAL_HIDE;
        sibling->evalflags &= ~NJD_EVAL_HIDE;
        TObjPlayer::save_model_render_state();
        model_render_flags &= ~0x10;
        TObjPlayer::set_model_fade_alpha(get_owner_alpha());
        child->evalflags |= NJD_EVAL_UNIT_POS;
        grandchild->evalflags &= ~NJD_EVAL_UNIT_ANG;
        grandchild->ang[1] += swing_angle;
        sibling->evalflags &= ~NJD_EVAL_UNIT_ANG;
        sibling->ang[1] -= swing_angle;
        if (get_joint_position(1, &pos) != 0) {
            push_matrix();
            post_translate_matrix(&pos.x);
            rotate_matrix_y(0, owner->rotation_y);
            draw_ginja_object(child);
            pop_matrix();
        }
        child->evalflags &= ~NJD_EVAL_UNIT_POS;
        grandchild->evalflags |= NJD_EVAL_UNIT_ANG;
        grandchild->ang[1] -= swing_angle;
        sibling->evalflags |= NJD_EVAL_UNIT_ANG;
        sibling->ang[1] += swing_angle;
        TObjPlayer::warn_if_gauge_low();
        TObjPlayer::restore_model_render_state();
    }
}

void TUnk_804A1A48::emit_marker_effects() {
    if (get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effect(this, 4);
    }
}

void TUnk_804A1A48::update_weapon() {
    if (swing_rising != 0) {
        swing_angle += 0x38E;
        if (swing_angle >= 0x1555) {
            swing_angle = 0x1555;
            swing_rising = 0;
        }
    } else {
        swing_angle -= 0x38E;
        if (swing_angle <= 0) {
            swing_angle = 0x1555;
            swing_rising = 1;
        }
    }
}

TUnk_804A1A48::~TUnk_804A1A48() {}

TUnk_804A1A48::TUnk_804A1A48(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(1);
    swing_angle = 0;
    swing_rising = 1;
}


TItem *TObjPlayer__sub_8012380C(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A1A48(tl_05, item);
    }
    return NULL;
}

