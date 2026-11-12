#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/unk/text_8035D2EC.h"
#include "pso/unk/text_8035D444.h"
#include "pso/item/TItem.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/unk/TLobby.h"
#include "pso/object/switch/TOSwitchItem.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
int get_player_data__10TObjPlayerFi(int a0);
extern u8 listed_equipment_table[][3];
void get_weapon_color__11TItemWeaponFPv(void *, void *);
}
s32 any_player_has_listed_equipment(void) {
    s32 n = TLobby::get_game_mode();
    s32 i;
    for (i = 0; i < n; i++) {
        void *pl = (void *)get_player_data__10TObjPlayerFi(i);
        if (pl != NULL && ((TBoss6PlotFalz *)pl)->is_active() != 0) {
            s32 j;
            for (j = 0; j < 10; j++) {
                u8 *e = listed_equipment_table[j];
                s32 k;
                for (k = 0; k < 13; k++) {
                    void *it = ((TObjPlayer *)pl)->get_equipped_item(k);
                    if (it != NULL && e[0] == ((TItem *)it)->get_item_type() &&
                        e[1] == ((TItem *)it)->get_item_group() &&
                        e[2] == ((TItem *)it)->get_item_index()) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void TUnk_804F1EC8::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    f32 sp8[4];
    desc->flags |= 0x1C;
    get_weapon_color__11TItemWeaponFPv(sp8, this);
    copy_argb((NJS_ARGB *)desc->color, (NJS_ARGB *)sp8);
    desc->model = second_model;
    desc->pad_70 = (void *)TObjPlayer::forward_item_effect_callback;
}
