#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemData.h"
#include "pso/item/armor/TItemProShield.h"

struct Pl_80117F14 { u8 pad0[0x38]; f32 pos[3]; };

extern "C" {
f32 horizontal_distance_squared(void *, void *);
void *get_player_by_client_id(s32 i);
extern const f64 lbl_8043E650[];
extern const f64 lbl_8043E648[];
s32 TObjPlayer__sub_80117E50(u16 idx) {
    TObjPlayer *me;
    s32 mask;
    s32 found = 0;
    s32 floor;
    u16 i;
    TObjPlayer *other;
    me = (TObjPlayer *)get_player_by_client_id(idx);
    if (me != NULL) {
        mask = (me->class_flags & 1) + 1;
        floor = me->get_floor();
        for (i = 0; i != 4; i++) {
            if (i != idx) {
                other = (TObjPlayer *)get_player_by_client_id(i);
                if (other != NULL && (other->class_flags & mask) && floor == other->get_floor() &&
                    horizontal_distance_squared(&me->position, &other->position) < lbl_8043E648[0]) {
                    found = 1;
                    break;
                }
            }
        }
    }
    return found;
}
s32 TObjPlayer::count_nearby_players_with_shield(u16 idx, u8 *item) {
    s32 key;
    Pl_80117F14 *me;
    s32 count;
    u16 i;
    Pl_80117F14 *other;
    void *it;
    count = 0;
    me = (Pl_80117F14 *)get_player_by_client_id(idx);
    if (me != NULL && item != NULL) {
        key = ((TObjPlayer *)me)->get_floor();
        for (i = 0; i != 4; i++) {
            if (i != idx) {
                other = (Pl_80117F14 *)get_player_by_client_id(i);
                if (other != NULL && key == ((TObjPlayer *)other)->get_floor() &&
                    horizontal_distance_squared(me->pos, other->pos) < lbl_8043E650[0] &&
                    (it = (void *)((TItemData *)other)->test_flag3()) != NULL &&
                    item[2] == ((TItem *)it)->get_item_index()) {
                    count++;
                }
            }
        }
    }
    return count;
}

}
