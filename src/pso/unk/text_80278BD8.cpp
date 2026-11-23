#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/unk/text_80278BD8.h"
#include "pso/item/TItem.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyItem.h"

struct Wn_80278DA4 { u8 pad0[0x20]; s16 f20; u8 pad22[0x50]; s16 f72; };

extern "C" {
void populate_judgment_item_list(Wn_80278DA4 *arg0);

void add_armor_equip_candidates(u8 *arg0, u16 kind, u16 sub) {
    s32 ids[30];
    u8 *item;
    u32 n;
    u32 i;
    TObjPlayer *pl;
    pl = get_player_by_client_id(*(s16 *)(arg0 + 0x20));
    if (pl != NULL) {
        n = pl->inventory_objects->run_and_get_result(ids);
        for (i = 0; i < n; i++) {
            item = (u8 *)find_item_by_id(ids[i]);
            if (item != NULL && kind == ((TItem *)item)->get_item_type() && sub == ((TItem *)item)->get_item_group() &&
                ((TItem *)item)->get_usable_action_flags(8, 0) != 0) {
                ((TShopJudgmentItemWindow *)arg0)->add_list_entry((saddr)item, ids[i]);
            }
        }
        if (*(s16 *)(arg0 + 0x72) <= 0) {
            ((TWindowSubStatusDisp *)arg0)->add_list_entry(-1);
        }
        ((TWindowMenuIconLine *)arg0)->calc_content_extent();
    }
}

void build_mag_item_candidates(void *arg0, u16 arg1) {
    s32 ids[30];
    u8 *item;
    u32 n;
    u32 i;
    TObjPlayer *pl;
    pl = get_player_by_client_id(*(s16 *)((s8 *)arg0 + 0x20));
    if (pl != NULL) {
        n = pl->inventory_objects->run_and_get_result(ids);
        for (i = 0; i < n; i++) {
            item = (u8 *)find_item_by_id(ids[i]);
            if ((item != 0) && (arg1 == ((TItem *)item)->get_item_type()) && (((TItem *)item)->get_usable_action_flags(8, 0) != 0U)) {
                ((TShopJudgmentItemWindow *)arg0)->add_list_entry((saddr)item, ids[i]);
            }
        }
        if (*(s16 *)((s8 *)arg0 + 0x72) <= 0) {
            ((TWindowSubStatusDisp *)arg0)->add_list_entry(-1);
        }
        ((TWindowMenuIconLine *)arg0)->calc_content_extent();
    }
}

void populate_judgment_item_list(Wn_80278DA4 *arg0) {
    s32 list[0x20];
    u8 *id;
    u32 i;
    u32 count;
    TObjPlayer *p;
    p = get_player_by_client_id(arg0->f20);
    if (p != NULL) {
        count = p->inventory_objects->run_and_get_result(list);
        for (i = 0; i < count; i++) {
            id = (u8 *)find_item_by_id(list[i]);
            if (id != NULL) {
                ((TShopJudgmentItemWindow *)arg0)->add_list_entry((saddr)id, list[i]);
            }
        }
        if (arg0->f72 <= 0) {
            ((TWindowSubStatusDisp *)arg0)->add_list_entry(-1);
        }
        ((TWindowMenuIconLine *)arg0)->calc_content_extent();
    }
}

}
