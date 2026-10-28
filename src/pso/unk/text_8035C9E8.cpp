#include "types.h"
#include "pso/unk/text_8035C9E8.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemProShield.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOSwitchItem.h"
#include "pso/player/TObjPlayer.h"
extern "C" {
void *get_player_data__10TObjPlayerFi(int);
void *get_entity_id(void *);
s32 TBoss4Type3__sub_8005254C(void *);
}
extern u8 lbl_80479B4C[][3];
s32 any_player_has_listed_item(void) {
    s32 n = TLobby::get_game_mode();
    s32 i;
    for (i = 0; i < n; i++) {
        void *pl = get_player_data__10TObjPlayerFi(i);
        if (pl != NULL && TBoss4Type3__sub_8005254C(get_entity_id(pl)) != 0) {
            s32 j;
            for (j = 0; j < 3; j++) {
                u8 *e = lbl_80479B4C[j];
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
