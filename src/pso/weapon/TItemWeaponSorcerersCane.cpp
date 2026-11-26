#include "pso/object/base/TObjChara.h"
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeaponSorcerersCane.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/MatrixStack.h"

// Eight x/y/z scales, indexed by scale_step.
struct CaneScaleTable {
    Vec value;
    Vec remaining[7];
};

const CaneScaleTable cane_node1_scale_steps = {
    {1.0f, 1.0f, 1.0f},
    {
        {150000.5f, 150000.5f, 5000.5f},
        {300000.0f, 300000.0f, 10000.0f},
        {100000.0f, 100000.0f, 10000.0f},
        {100000.0f, 100000.0f, 24062.5f},
        {100000.0f, 100000.0f, 55000.004f},
        {100000.0f, 100000.0f, 85937.5f},
        {100000.0f, 100000.0f, 100000.0f},
    },
};
const CaneScaleTable cane_node4_scale_steps = {
    {1.0f, 1.0f, 1.0f},
    {
        {150000.5f, 150000.5f, 5000.5f},
        {300000.0f, 300000.0f, 10000.0f},
        {100000.0f, 100000.0f, 10000.0f},
        {100000.0f, 100000.0f, 24062.5f},
        {100000.0f, 100000.0f, 55000.004f},
        {100000.0f, 100000.0f, 85937.5f},
        {100000.0f, 100000.0f, 100000.0f},
    },
};

LAYOUT_ASSERT(CaneScaleTable_size, sizeof(CaneScaleTable) == 0x60);
void TItemWeaponSorcerersCane::transform_model_node() {
    s32 player_list;
    s32 scale_step;
    s32 step;
    player_list = get_model_node_counter();
    switch (player_list) {
    case 1:
        TItem::begin_effect_render();
        scale_step = this->scale_step;
        scale_current_matrix((const f32 *)((u8 *)&cane_node1_scale_steps.value + (scale_step * 0xC)));
        return;
    case 4:
        TItem::begin_effect_render();
        step = this->scale_step;
        scale_current_matrix((const f32 *)((u8 *)&cane_node4_scale_steps.value + (step * 0xC)));
        return;
    case 7:
        TItem::begin_effect_render();
        return;
    }
}

void TItemWeaponSorcerersCane::update_weapon() {
    s16 tp_drop;
    s16 tp;
    s32 scale_step;
    s32 step;
    if (this->scale_state == 1) {
        scale_step = this->scale_step;
        if (scale_step == 7) {
            this->scale_state = 0;
        } else {
            this->scale_step = (scale_step + 1);
        }
    }
    if (this->scale_state == 2) {
        step = this->scale_step;
        if (step == 0) {
            this->scale_state = 3;
        } else {
            this->scale_step = (step - 1);
        }
    }
    tp = this->owner->get_actor_tp();
    tp_drop = this->cached_tp - tp;
    if (tp_drop < 0) {
        this->cached_tp = tp;
        return;
    }
    if (tp_drop > 0) {
        add_actor_tp(this->owner, 0.1f * (f32) tp_drop);
        this->cached_tp = this->owner->get_actor_tp();
    }
}

void TItemWeaponSorcerersCane::update_idle() {
    s16 scale_state;

    scale_state = this->scale_state;
    if ((scale_state == 1) || (scale_state == 0)) {
        this->scale_state = 2;
    }
}

void TItemWeaponSorcerersCane::update_attack() {
    s16 scale_state;

    scale_state = this->scale_state;
    if ((scale_state == 2) || (scale_state == 3)) {
        this->scale_state = 1;
    }
}

TItemWeaponSorcerersCane::~TItemWeaponSorcerersCane() {

}

TItemWeaponSorcerersCane::TItemWeaponSorcerersCane(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    scale_state = 3;
    scale_step = 0;
    cached_tp = -1;
}

TItem *TItemWeaponSorcerersCane::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSorcerersCane(tl_05, item);
    }
    return NULL;
}

// Sorcerer's Cane (inferred): both reset the cached owner TP.
void TItemWeaponSorcerersCane::on_equipped() { cached_tp = -1; }
void TItemWeaponSorcerersCane::on_unequipped() { cached_tp = -1; }
