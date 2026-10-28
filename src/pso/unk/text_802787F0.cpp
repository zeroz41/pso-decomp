#include "types.h"
#include "pso/misc/TWindowSubStatusDisp_802671F0.h"
#include "pso/item/TItem.h"
#include "pso/misc/TShopJudgmentItemWindow.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"

struct Wn_802788A8 { u8 pad0[0x20]; s16 f20; u8 pad22[0x50]; s16 f72; };

struct Wn_802787F0 { u8 pad0[0x20]; s16 f20; u8 pad22[0x50]; s16 f72; };

struct Ent_802787F0 { u32 id; s32 count; };

extern "C" {
void *get_player_by_client_id(s32 i);
void calc_list_content_extent(void *);
void build_usable_item_list(Wn_802788A8 *arg0);
void fill_trade_item_list(Wn_802787F0 *arg0, Ent_802787F0 *arg1);

void fill_trade_item_list(Wn_802787F0 *arg0, Ent_802787F0 *arg1) {
    s32 sid;
    u32 i;
    s32 count;
    Ent_802787F0 *p;
    u8 *item;
    if (arg1 != NULL) {
        p = arg1;
        i = 0;
        do {
            count = p->count;
            u32 id = p->id;
            if (count > 0) {
                if (id == 0xFFFFFF01) {
                    push_status_disp_entry(arg0, count, id);
                } else {
                    sid = id;
                    item = (u8 *)find_item_by_id(sid);
                    if (item != NULL) {
                        ((TWindowSubStatusDisp *)arg0)->add_inventory_item((s32)item, (s32)count, (s32)sid);
                    }
                }
            }
            i++;
            p++;
        } while (i < 0x1F);
        if (arg0->f72 <= 0) {
            ((TWindowSubStatusDisp *)arg0)->add_list_entry(-1);
        }
        calc_list_content_extent(arg0);
    }
}

void build_usable_item_list(Wn_802788A8 *arg0) {
    s32 list[0x20];
    u8 *id;
    u32 i;
    u32 count;
    u8 *p;
    p = (u8 *)get_player_by_client_id(arg0->f20);
    if (p != NULL) {
        count = ((TObjPlayer *)(*(s32 *)(p + 0xD00)))->run_and_get_result((int)list);
        for (i = 0; i < count; i++) {
            id = (u8 *)find_item_by_id(list[i]);
            if (id != NULL && ((TItem *)id)->get_usable_action_flags(4, 0) != 0) {
                ((TShopJudgmentItemWindow *)arg0)->add_list_entry((s32)id, list[i]);
            }
        }
        if (arg0->f72 <= 0) {
            ((TWindowSubStatusDisp *)arg0)->add_list_entry(-1);
        }
        calc_list_content_extent(arg0);
    }
}

}
