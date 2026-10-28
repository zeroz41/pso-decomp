#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TUnk_804A1E28.h"

struct RecoveredGlobal_80123CA8_lbl_8043E878 {
    s32 value;
    u8 remaining[0x5C];
};

struct RecoveredGlobal_80123CA8_lbl_8043E8D8 {
    s32 value;
    u8 remaining[0x5C];
};

extern "C" {
s32 add_actor_tp(u8 *arg0, s32 arg1);
s16 obj_getS16_32E(u8 *p);
extern const f32 lbl_805DAD20;
s32 scale_current_matrix(void *, int);
}
extern RecoveredGlobal_80123CA8_lbl_8043E878 lbl_8043E878;
extern RecoveredGlobal_80123CA8_lbl_8043E8D8 lbl_8043E8D8;
void sorcerers_cane_node_callback(u8 *arg0);

typedef char RecoveredGlobal_80123CA8_lbl_8043E878_size[sizeof(RecoveredGlobal_80123CA8_lbl_8043E878) == 0x60 ? 1 : -1];
typedef char RecoveredGlobal_80123CA8_lbl_8043E8D8_size[sizeof(RecoveredGlobal_80123CA8_lbl_8043E8D8) == 0x60 ? 1 : -1];
void sorcerers_cane_node_callback(u8 *arg0) {
    s32 player_list;
    s32 temp_r4;
    s32 temp_r4_2;
    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 1:
        TItem::begin_effect_render();
        temp_r4 = *(s32 *)((s8 *)arg0 + 0x1F8);
        scale_current_matrix((void *) ((u8 *)&lbl_8043E878.value + (temp_r4 * 0xC)), temp_r4);
        return;
    case 4:
        TItem::begin_effect_render();
        temp_r4_2 = *(s32 *)((s8 *)arg0 + 0x1F8);
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
    if ((s16) *(s16 *)&this->unk_1FE == 1) {
        temp_r3 = *(s32 *)((s8 *)arg0 + 0x1F8);
        if (temp_r3 == 7) {
            *(s16 *)&this->unk_1FE = 0;
        } else {
            *(s32 *)((s8 *)arg0 + 0x1F8) = (temp_r3 + 1);
        }
    }
    if ((s16) *(s16 *)&this->unk_1FE == 2) {
        temp_r3_2 = *(s32 *)((s8 *)arg0 + 0x1F8);
        if (temp_r3_2 == 0) {
            *(s16 *)&this->unk_1FE = 3;
        } else {
            *(s32 *)((s8 *)arg0 + 0x1F8) = (temp_r3_2 - 1);
        }
    }
    temp_r3_3 = obj_getS16_32E(*(u8 * *)&this->player);
    temp_r0 = this->m_1fc - temp_r3_3;
    if (temp_r0 < 0) {
        this->m_1fc = temp_r3_3;
        return;
    }
    if (temp_r0 > 0) {
        add_actor_tp(*(u8 * *)&this->player, (lbl_805DAD20 * (f32) temp_r0));
        this->m_1fc = obj_getS16_32E(*(u8 * *)&this->player);
    }
}
