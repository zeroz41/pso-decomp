#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TUnk_804A1E28.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/system/task/TMainTask.h"

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
s32 add_actor_tp(u8 *arg0, s32 arg1);
s16 get_actor_tp(u8 *p);
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

typedef char RecoveredGlobal_80123CA8_lbl_8043E878_size[sizeof(RecoveredGlobal_80123CA8_lbl_8043E878) == 0x60 ? 1 : -1];
typedef char RecoveredGlobal_80123CA8_lbl_8043E8D8_size[sizeof(RecoveredGlobal_80123CA8_lbl_8043E8D8) == 0x60 ? 1 : -1];
void TUnk_804A1E28::vfunc_60() {
    s32 player_list;
    s32 temp_r4;
    s32 temp_r4_2;
    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 1:
        TItem::begin_effect_render();
        temp_r4 = this->scale_step;
        scale_current_matrix((void *) ((u8 *)&lbl_8043E878.value + (temp_r4 * 0xC)), temp_r4);
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
    u8 *arg0 = (u8 *)this;
    s16 temp_r0;
    s16 temp_r3_3;
    s32 temp_r3;
    s32 temp_r3_2;
    if (this->scale_state == 1) {
        temp_r3 = this->scale_step;
        if (temp_r3 == 7) {
            this->scale_state = 0;
        } else {
            this->scale_step = (temp_r3 + 1);
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
    temp_r3_3 = get_actor_tp(*(u8 * *)&this->owner);
    temp_r0 = this->cached_tp - temp_r3_3;
    if (temp_r0 < 0) {
        this->cached_tp = temp_r3_3;
        return;
    }
    if (temp_r0 > 0) {
        add_actor_tp(*(u8 * *)&this->owner, (0.1f * (f32) temp_r0));
        this->cached_tp = get_actor_tp(*(u8 * *)&this->owner);
    }
}

void TUnk_804A1E28::update_idle() {
    s16 temp_r0;

    temp_r0 = this->scale_state;
    if ((temp_r0 == 1) || (temp_r0 == 0)) {
        this->scale_state = 2;
    }
}

void TUnk_804A1E28::update_attack() {
    s16 temp_r0;

    temp_r0 = this->scale_state;
    if ((temp_r0 == 2) || (temp_r0 == 3)) {
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

u8 *create_sorcerers_cane(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A1E28(tl_05, arg0);
    }
    return NULL;
}

// Sorcerer's Cane (inferred): both reset the cached owner TP.
void TUnk_804A1E28::vfunc_57() { cached_tp = -1; }
void TUnk_804A1E28::vfunc_58() { cached_tp = -1; }
