#include "pso/unk/text_80104FCC.h"
#include "types.h"
#include "pso/unk/text_8011A780.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80104860.h"
struct Msg_801057A8 {
    s8 client;
    u8 pad1[3];
    f32 x;
    f32 z;
    s16 area;
    u8 pad2[2];
    u8 item[1];
};

struct Item_801057A8 {
    u8 pad[0x28];
    s16 area;
    u8 pad2[0xE];
    f32 x;
    f32 y;
    f32 z;
};

extern "C" {
s8 get_current_floor(void);
s32 place_on_ground__5TItemFsPfl(Item_801057A8 *, s32, f32 *, s32);
Item_801057A8 *spawn_dropped_item_from_msg(Msg_801057A8 *arg0, s32 arg1);
Item_801057A8 *spawn_dropped_item_from_msg(Msg_801057A8 *arg0, s32 arg1) {
    Item_801057A8 *item;
    s32 me;
    s32 act;
    u8 ok;
    item = NULL;
    if (arg0 != NULL) {
        me = get_current_floor();
        act = is_local_player_off_current_floor();
        ok = 0;
        if (arg0->client == me && act != 1) {
            ok = 1;
        }
        if (ok != 0) {
            item = (Item_801057A8 *)construct_item((TItemData *)arg0->item);
            if (item != NULL) {
                item->x = arg0->x;
                item->z = arg0->z;
                item->area = arg0->area;
                place_on_ground__5TItemFsPfl(item, arg0->client, &item->x, 1);
            }
        }
        if (arg1 == 0) {
            ((void (*)(s32, s32, u8 *, f32, f32))add_item_condition)(arg0->client, arg0->area, arg0->item, arg0->x, arg0->z);
        }
    }
    return item;
}

}
