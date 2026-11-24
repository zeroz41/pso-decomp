#include "pso/object/base/TObjChara.h"
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TUnk_804A1E28.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_80011014.h"

// Eight x/y/z scales, indexed by scale_step.
struct RecoveredGlobal_80123CA8_lbl_8043E878 {
    Vec value;
    Vec remaining[7];
};

// Eight x/y/z scales, indexed by scale_step.
struct RecoveredGlobal_80123CA8_lbl_8043E8D8 {
    Vec value;
    Vec remaining[7];
};

extern "C" {
s32 scale_current_matrix(void *, int);
}
const RecoveredGlobal_80123CA8_lbl_8043E878 lbl_8043E878 = {
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
const RecoveredGlobal_80123CA8_lbl_8043E8D8 lbl_8043E8D8 = {
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

LAYOUT_ASSERT(RecoveredGlobal_80123CA8_lbl_8043E878_size, sizeof(RecoveredGlobal_80123CA8_lbl_8043E878) == 0x60);
LAYOUT_ASSERT(RecoveredGlobal_80123CA8_lbl_8043E8D8_size, sizeof(RecoveredGlobal_80123CA8_lbl_8043E8D8) == 0x60);
void TUnk_804A1E28::vfunc_60() {
    s32 player_list;
    s32 scale_step;
    s32 temp_r4_2;
    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 1:
        TItem::begin_effect_render();
        scale_step = this->scale_step;
        scale_current_matrix((void *) ((u8 *)&lbl_8043E878.value + (scale_step * 0xC)), scale_step);
        return;
    case 4:
        TItem::begin_effect_render();
        temp_r4_2 = this->scale_step;
        scale_current_matrix((void *) ((u8 *)&lbl_8043E8D8.value + (temp_r4_2 * 0xC)), temp_r4_2);
        return;
    case 7:
        TItem::begin_effect_render();
        return;
    }
}

void TUnk_804A1E28::update_weapon() {
    s16 temp_r0;
    s16 temp_r3_3;
    s32 scale_step;
    s32 temp_r3_2;
    if (this->scale_state == 1) {
        scale_step = this->scale_step;
        if (scale_step == 7) {
            this->scale_state = 0;
        } else {
            this->scale_step = (scale_step + 1);
        }
    }
    if (this->scale_state == 2) {
        temp_r3_2 = this->scale_step;
        if (temp_r3_2 == 0) {
            this->scale_state = 3;
        } else {
            this->scale_step = (temp_r3_2 - 1);
        }
    }
    temp_r3_3 = get_actor_tp(this->owner);
    temp_r0 = this->cached_tp - temp_r3_3;
    if (temp_r0 < 0) {
        this->cached_tp = temp_r3_3;
        return;
    }
    if (temp_r0 > 0) {
        add_actor_tp(this->owner, static_cast<s32>(0.1f * (f32) temp_r0));
        this->cached_tp = get_actor_tp(this->owner);
    }
}

void TUnk_804A1E28::update_idle() {
    s16 scale_state;

    scale_state = this->scale_state;
    if ((scale_state == 1) || (scale_state == 0)) {
        this->scale_state = 2;
    }
}

void TUnk_804A1E28::update_attack() {
    s16 scale_state;

    scale_state = this->scale_state;
    if ((scale_state == 2) || (scale_state == 3)) {
        this->scale_state = 1;
    }
}

TUnk_804A1E28::~TUnk_804A1E28() {

}

TUnk_804A1E28::TUnk_804A1E28(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    scale_state = 3;
    scale_step = 0;
    cached_tp = -1;
}

TItem *create_sorcerers_cane(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A1E28(tl_05, item);
    }
    return NULL;
}

// Sorcerer's Cane (inferred): both reset the cached owner TP.
void TUnk_804A1E28::on_equipped() { cached_tp = -1; }
void TUnk_804A1E28::on_unequipped() { cached_tp = -1; }
