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

struct Sp8Type_80123524 { s32 a; s32 b; s32 c; s32 d; };

extern "C" {

s32 post_translate_matrix(Sp8Type_80123524 *);
s32 draw_weapon_at_joint(void *, s32, void *);

extern s32 model_render_flags;

void TUnk_804A1A48::reserved_53() {
    Sp8Type_80123524 sp8;
    NJS_OBJECT *model;
    NJS_OBJECT *child;
    NJS_OBJECT *grandchild;
    NJS_OBJECT *sibling;

    if (item_model != NULL && is_hidden() == 0) {
        model = item_model;
        child = model->child;
        child->evalflags |= NJD_EVAL_HIDE;
        grandchild = child->child;
        grandchild->evalflags |= NJD_EVAL_HIDE;
        sibling = grandchild->sibling;
        sibling->evalflags |= NJD_EVAL_HIDE;
        draw_weapon_at_joint(this, 0x30, model);
        child->evalflags &= ~NJD_EVAL_HIDE;
        grandchild->evalflags &= ~NJD_EVAL_HIDE;
        sibling->evalflags &= ~NJD_EVAL_HIDE;
        TObjPlayer::save_model_render_state();
        model_render_flags &= 0xFFFFFFEF;
        TObjPlayer::set_model_fade_alpha((f32)this->get_owner_alpha());
        child->evalflags |= NJD_EVAL_UNIT_POS;
        grandchild->evalflags &= ~NJD_EVAL_UNIT_ANG;
        grandchild->ang[1] += this->swing_angle;
        sibling->evalflags &= ~NJD_EVAL_UNIT_ANG;
        sibling->ang[1] -= this->swing_angle;
        if (this->get_joint_position(1, &sp8) != 0) {
            push_matrix();
            post_translate_matrix(&sp8);
            rotate_matrix_y(0, owner->rotation_y);
            draw_ginja_object(child);
            pop_matrix();
        }
        child->evalflags &= ~NJD_EVAL_UNIT_POS;
        grandchild->evalflags |= NJD_EVAL_UNIT_ANG;
        grandchild->ang[1] -= this->swing_angle;
        sibling->evalflags |= NJD_EVAL_UNIT_ANG;
        sibling->ang[1] += this->swing_angle;
        TObjPlayer::warn_if_gauge_low();
        TObjPlayer::restore_model_render_state();
    }
}


void TUnk_804A1A48::emit_marker_effects() {
    saddr item = (saddr)this;
    if (get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effect((TItem*)item, 4);
    }
}

void TUnk_804A1A48::update_weapon() {
    if (this->swing_rising != 0) {
        this->swing_angle = (this->swing_angle + 0x38E);
        if (this->swing_angle >= 0x1555) {
            this->swing_angle = 0x1555;
            this->swing_rising = 0;
        }
    } else {
        this->swing_angle = (this->swing_angle - 0x38E);
        if (this->swing_angle <= 0) {
            this->swing_angle = 0x1555;
            this->swing_rising = 1;
        }
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

