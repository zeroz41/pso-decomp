#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804A1098.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecGiBarta.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/system/task/TMainTask.h"
#include <stdlib.h>

extern "C" {

int rotate_matrix_x(void*, void*);

void TUnk_804A1098::emit_marker_effects() {
    Vec sp8;
    void *tec_gi_barta;

    if (is_mode_two_and_ready() != 0) {
        if (get_joint_position(0, &sp8) != 0) {
            tec_gi_barta = this->owner;
            TTecGiBarta::create_ex(tec_gi_barta, &sp8, (*(saddr *)((s8 *)tec_gi_barta + 0x60)), (((TItemWeapon *)this)->get_tp()));
            roll_technique();
        }
    } else {
        ((TItemWeapon *)this)->update_active_game_effect();
    }
}
void TUnk_804A1098::vfunc_60() { if (TObjPlayer::get_player_list() == 1) { rotate_matrix_x((void*)0, (void *)this->open_angle); } }


void TUnk_804A1098::update_idle() {
    if (this->open_state == 3) {
        this->open_state = 1;
    }
    if ((this->open_state == 0) && ((3.0517578e-05f * (f32) rand()) < 0.1f)) {
        this->open_state = 2;
    }
}

void TUnk_804A1098::update_attack() {
    s32 open_state;

    open_state = this->open_state;
    if ((open_state == 1) || (open_state == 0)) {
        this->open_state = 2;
    }
}

}

void TUnk_804A1098::update_weapon() {
    s32 open_state;
    s32 open_angle;
    s32 temp_r4_2;
    open_state = this->open_state;
    if (open_state == 2) {
        open_angle = this->open_angle;
        if (open_angle < 0x2AAA) {
            this->open_angle = (open_angle + 0x888);
            if (this->open_angle >= 0x2AAA) {
                this->open_angle = 0x2AAA;
                this->open_state = 3;
            }
        }
    } else if (open_state == 1) {
        temp_r4_2 = this->open_angle;
        if (temp_r4_2 > 0) {
            this->open_angle = (temp_r4_2 - 0x444);
            if (this->open_angle <= 0) {
                this->open_angle = 0;
                this->open_state = 0;
            }
        }
    }
}

void TUnk_804A1098::on_equipped() { roll_technique(); roll_technique(); }

TUnk_804A1098::~TUnk_804A1098() {}

TUnk_804A1098::TUnk_804A1098(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    open_angle = 0;
    open_state = 0;
    set_technique_roll_range(10);
}

TItem *TObjPlayer__sub_801228CC(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A1098(tl_05, item);
    }
    return NULL;
}
