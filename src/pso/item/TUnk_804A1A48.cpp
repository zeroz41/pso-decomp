#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_80363BE0.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/item/TUnk_804A1A48.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/TMainTask.h"

struct Sp8Type_80123524 { s32 a; s32 b; s32 c; s32 d; };

extern "C" {

s32 is_hidden__5TItemFv();
s32 post_translate_matrix(Sp8Type_80123524 *);
s32 draw_weapon_at_joint(void *, s32, void *);
s32 warn_if_gauge_low__10TObjPlayerFv(s32);
s32 set_model_fade_alpha__10TObjPlayerFf();
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();

extern s32 model_render_flags;

void TUnk_804A1A48::reserved_53() {
    Sp8Type_80123524 sp8;
    s32 temp_r3;
    s32 temp_r6;
    void *temp_r5;
    void *temp_r31;
    void *temp_r30;
    void *temp_r29;

    if ((*(void **)&(*(s16 *)((u8 *)this + 0xF4)) != NULL) && (is_hidden__5TItemFv() == 0)) {
        temp_r5 = *(void **)&(*(s16 *)((u8 *)this + 0xF4));
        temp_r31 = *(void **)((s8 *)temp_r5 + 0x2C);
        *(s32 *)((s8 *)temp_r31 + 0) = (s32) (*(s32 *)((s8 *)temp_r31 + 0) | 8);
        temp_r30 = *(void **)((s8 *)temp_r31 + 0x2C);
        *(s32 *)((s8 *)temp_r30 + 0) = (s32) (*(s32 *)((s8 *)temp_r30 + 0) | 8);
        temp_r29 = *(void **)((s8 *)temp_r30 + 0x30);
        *(s32 *)((s8 *)temp_r29 + 0) = (s32) (*(s32 *)((s8 *)temp_r29 + 0) | 8);
        draw_weapon_at_joint(this, 0x30, temp_r5);
        *(s32 *)((s8 *)temp_r31 + 0) = (s32) (*(s32 *)((s8 *)temp_r31 + 0) & 0xFFFFFFF7);
        *(s32 *)((s8 *)temp_r30 + 0) = (s32) (*(s32 *)((s8 *)temp_r30 + 0) & 0xFFFFFFF7);
        *(s32 *)((s8 *)temp_r29 + 0) = (s32) (*(s32 *)((s8 *)temp_r29 + 0) & 0xFFFFFFF7);
        TObjPlayer__sub_80364198();
        model_render_flags &= 0xFFFFFFEF;
        ((TItem *)this)->get_owner_alpha();
        set_model_fade_alpha__10TObjPlayerFf();
        *(s32 *)((s8 *)temp_r31 + 0) = (s32) (*(s32 *)((s8 *)temp_r31 + 0) | 1);
        *(s32 *)((s8 *)temp_r30 + 0) = (s32) (*(s32 *)((s8 *)temp_r30 + 0) & 0xFFFFFFFD);
        *(s32 *)((s8 *)temp_r30 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r30 + 0x18) + this->swing_angle);
        *(s32 *)((s8 *)temp_r29 + 0) = (s32) (*(s32 *)((s8 *)temp_r29 + 0) & 0xFFFFFFFD);
        temp_r6 = this->swing_angle;
        *(s32 *)((s8 *)temp_r29 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r29 + 0x18) - temp_r6);
        if (((TItemWeapon *)this)->get_joint_position(1, &sp8) != 0) {
            push_matrix();
            post_translate_matrix(&sp8);
            rotate_matrix_y(0, *(s32 *)((s8 *)(*(void * *)&(*(NJS_MOTION_LINK *)((u8 *)this + 0xE4)).frame[1]) + 0x60));
            draw_ginja_object(temp_r31);
            pop_matrix();
        }
        *(s32 *)((s8 *)temp_r31 + 0) = (s32) (*(s32 *)((s8 *)temp_r31 + 0) & 0xFFFFFFFE);
        *(s32 *)((s8 *)temp_r30 + 0) = (s32) (*(s32 *)((s8 *)temp_r30 + 0) | 2);
        *(s32 *)((s8 *)temp_r30 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r30 + 0x18) - this->swing_angle);
        *(s32 *)((s8 *)temp_r29 + 0) = (s32) (*(s32 *)((s8 *)temp_r29 + 0) | 2);
        temp_r3 = *(s32 *)((s8 *)temp_r29 + 0x18);
        *(s32 *)((s8 *)temp_r29 + 0x18) = (s32) (temp_r3 + this->swing_angle);
        warn_if_gauge_low__10TObjPlayerFv(temp_r3);
        TObjPlayer__sub_8036414C();
    }
}


void TUnk_804A1A48::emit_marker_effects() {
    s32 item = (s32)this;
    if (get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effect((TItem*)item, 4);
    }
}

void TUnk_804A1A48::update_weapon() {
    if (this->swing_rising != 0) {
        this->swing_angle = (s32) (this->swing_angle + 0x38E);
        if (this->swing_angle >= 0x1555) {
            this->swing_angle = 0x1555;
            this->swing_rising = 0;
        }
    } else {
        this->swing_angle = (s32) (this->swing_angle - 0x38E);
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

extern "C" {
u8 *TObjPlayer__sub_8012380C(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A1A48(tl_05, arg0);
    }
    return NULL;
}

}
