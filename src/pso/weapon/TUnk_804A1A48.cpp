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
    s32 temp_r3;
    void *temp_r5;
    void *child;
    void *temp_r30;
    void *temp_r29;

    if ((*(void **)&(*(s16 *)((u8 *)this + 0xF4)) != NULL) && (((TItem *)this)->is_hidden() == 0)) {
        temp_r5 = *(void **)&(*(s16 *)((u8 *)this + 0xF4));
        child = *(void **)((s8 *)temp_r5 + 0x2C);
        *(s32 *)((s8 *)child + 0) = (s32) (*(s32 *)((s8 *)child + 0) | 8);
        temp_r30 = *(void **)((s8 *)child + 0x2C);
        *(s32 *)((s8 *)temp_r30 + 0) = (s32) (*(s32 *)((s8 *)temp_r30 + 0) | 8);
        temp_r29 = *(void **)((s8 *)temp_r30 + 0x30);
        *(s32 *)((s8 *)temp_r29 + 0) = (s32) (*(s32 *)((s8 *)temp_r29 + 0) | 8);
        draw_weapon_at_joint(this, 0x30, temp_r5);
        *(s32 *)((s8 *)child + 0) = (s32) (*(s32 *)((s8 *)child + 0) & 0xFFFFFFF7);
        *(s32 *)((s8 *)temp_r30 + 0) = (s32) (*(s32 *)((s8 *)temp_r30 + 0) & 0xFFFFFFF7);
        *(s32 *)((s8 *)temp_r29 + 0) = (s32) (*(s32 *)((s8 *)temp_r29 + 0) & 0xFFFFFFF7);
        TObjPlayer__sub_80364198();
        model_render_flags &= 0xFFFFFFEF;
        TObjPlayer::set_model_fade_alpha((f32)this->get_owner_alpha());
        *(s32 *)((s8 *)child + 0) = (s32) (*(s32 *)((s8 *)child + 0) | 1);
        *(s32 *)((s8 *)temp_r30 + 0) = (s32) (*(s32 *)((s8 *)temp_r30 + 0) & 0xFFFFFFFD);
        *(s32 *)((s8 *)temp_r30 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r30 + 0x18) + this->swing_angle);
        *(s32 *)((s8 *)temp_r29 + 0) = (s32) (*(s32 *)((s8 *)temp_r29 + 0) & 0xFFFFFFFD);
        *(s32 *)((s8 *)temp_r29 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r29 + 0x18) - this->swing_angle);
        if (this->get_joint_position(1, &sp8) != 0) {
            push_matrix();
            post_translate_matrix(&sp8);
            rotate_matrix_y(0, *(s32 *)((s8 *)(*(void * *)&(*(NJS_MOTION_LINK *)((u8 *)this + 0xE4)).frame[1]) + 0x60));
            draw_ginja_object(child);
            pop_matrix();
        }
        *(s32 *)((s8 *)child + 0) = (s32) (*(s32 *)((s8 *)child + 0) & 0xFFFFFFFE);
        *(s32 *)((s8 *)temp_r30 + 0) = (s32) (*(s32 *)((s8 *)temp_r30 + 0) | 2);
        *(s32 *)((s8 *)temp_r30 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r30 + 0x18) - this->swing_angle);
        *(s32 *)((s8 *)temp_r29 + 0) = (s32) (*(s32 *)((s8 *)temp_r29 + 0) | 2);
        temp_r3 = *(s32 *)((s8 *)temp_r29 + 0x18);
        *(s32 *)((s8 *)temp_r29 + 0x18) = (s32) (temp_r3 + this->swing_angle);
        TObjPlayer::warn_if_gauge_low();
        TObjPlayer__sub_8036414C();
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

