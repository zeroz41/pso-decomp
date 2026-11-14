#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TLobby_801E43E4.h"
#include "types.h"
#include "pso/player/TObjPlayer_80120FC4.h"
#include "pso/system/data/FlagWord.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/item/TItemObject.h"
#include "pso/system/byteswap.h"
#include "pso/network/protocol/subcmd_6x.h"
#include <stddef.h>
#include "pso/unk/TLobby.h"
#include "pso/item/TItemData.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TUnk_8049F770.h"
#include "pso/item/TUnk_8049FE00.h"
#include "pso/item/TUnk_8049FC90.h"
#include "pso/item/TUnk_8049FA50.h"
#include "pso/item/TUnk_8049F8E0.h"
#include "pso/item/TUnk_8049FB08.h"
#include "pso/item/TUnk_8049F998.h"
#include "pso/item/TUnk_8049FD48.h"
#include "pso/item/TUnk_8049FED0.h"
#include "pso/item/TUnk_8049FF88.h"
#include "pso/item/TUnk_8049FBC0.h"
#include "pso/item/TUnk_8049F828.h"
#include "pso/item/TUnk_804E6FA8.h"
#include "pso/item/TUnk_804F112C.h"
#include "pso/item/TUnk_804F0C48.h"
#include "pso/item/TUnk_804F0D34.h"
#include "pso/item/TUnk_804F0FF0.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_801036CC.h"
#include "pso/system/task/TObject.h"
#include "pso/item/TItemData.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"

struct In_8010440C { u8 pad0; u8 idx; };
struct In_80104438 { u8 pad0; u8 idx; };

extern "C" {
extern int* item_sync_counter_table;
s32 get_item_icon_index();
extern int lobby_drop_flag;
void TLobby__sub_80104464(void);
int fn_80077788(void);
int fn_80077790(void);
s32 fn_801058E8();
s32 get_char_index__23TAdSinglePlyChrSelectGCFUi(u32 arg0);
s32 is_locally_controlled__10TObjPlayerFPv();
void send_6x25_equip_item(void *arg0, s32 arg1, s32 arg2);
s32 get_player_by_client_id(u16);
extern s32 local_client_id;
extern s32 TLobby__designated_client_id;
s32 get_item_id__5TItemFv();
int get_item_field_6__10TObjPlayerFPv(void *p);
void *TLobby__sub_8010440C(In_8010440C *arg0);
void *get_weapon_factory_for_item(In_80104438 *arg0);
int is_quest_active(void);
s32 TItemDropSub__sub_80107B74();
}

extern void *weapon_factory_table[];
// Tool item factories, indexed by the tool type byte (TLobby__sub_8010440C).
void *item_tool_factory_table[24] = {
    (void *)TUnk_8049F770::create,
    (void *)TUnk_8049FE00::create,
    (void *)create_technique_disk_item,
    (void *)create_sol_atomizer_item,
    (void *)create_moon_atomizer_item,
    (void *)create_star_atomizer_item,
    (void *)create_status_cure_item,
    (void *)create_telepipe_item,
    (void *)TUnk_8049FED0::create,
    (void *)TItemObject::create,
    (void *)create_item_grinder,
    (void *)create_material_item,
    (void *)TUnk_8049F828::create,
    (void *)TItemObject::create,
    (void *)TItemObject::create,
    (void *)create_add_slot_item,
    (void *)TItemObject::create,
    (void *)TItemObject::create,
    (void *)TItemObject::create,
    (void *)TItemObject::create,
    (void *)TUnk_804F112C::create,
    (void *)TUnk_804F0C48::create,
    (void *)TUnk_804F0D34::create,
    (void *)TUnk_804F0FF0::create,
};

void normalize_drop_area(s32 *p);
extern "C" {
void TLobby::set_boss_buf_entry(int a0, int a1) { item_sync_counter_table[(unsigned short)(a1)] = a0; }
int TLobby::get_sync_counter(int a0) {  return item_sync_counter_table[(unsigned short)(a0)]; }
s32 TLobby::get_item_data(u32 arg0) {
    if (arg0 != 0U) {
        return get_item_icon_index();
    }
    return 0;
}
void TLobby::forward_message(s32 buf, u32 arg1) {
    if (arg1 != 0U) {
        ((TItemData *)arg1)->format_item_name((char *)buf);
    }
}
void TLobby::mark_selected() { lobby_drop_flag = 1; }
int TLobby::get_drop_flag() {  return lobby_drop_flag; }

void *TLobby__sub_8010440C(In_8010440C *arg0) {
    u8 i = arg0->idx;
    if (i < 0x18) {
        return item_tool_factory_table[i];
    }
    return (void *)TItemObject::create;
}

void *get_weapon_factory_for_item(In_80104438 *arg0) {
    u8 i = arg0->idx;
    if (i < 0xAA) {
        return weapon_factory_table[i];
    }
    return (void *)create_common_weapon;
}

void TLobby__sub_80104464(void) {  }
void TLobby::handle_select_confirm() {
    if ((fn_80077790() == 1) || (fn_80077788() == 1)) {
        TLobby::mark_selected();
        if (get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF) != 0U) {
            fn_801058E8();
        }
    }
}
}

void normalize_drop_area(s32 *p) {
    s32 v;
    if (is_quest_active() != 0 && p != NULL) {
        switch (*p) {
        case 0x10:
        case 0x11:
            *p = TItemDropSub__sub_80107B74();
            return;
        }
    }
    if (TLobby::get_instance() == 0) {
        if (p != NULL) {
            v = *p;
            if (v > 10) {
                switch (v) {
                case 11:
                    *p = 3;
                    break;
                case 12:
                    *p = 6;
                    break;
                case 13:
                    *p = 8;
                    break;
                default:
                    *p = 10;
                    break;
                }
            } else if (v < 1) {
                *p = 1;
            }
        }
    } else if (p != NULL) {
        v = *p;
        if (v >= 0x13 && v < 0x24) {
            s32 remap[17] = { 1, 2, 3, 4, 8, 5, 6, 7, 8, 9, 10, 9, 10, 3, 5, 8, 10 };
            *p = remap[(u32)(v - 0x13)];
        }
    }
}

void TLobby::forward_to_player(int arg0, void *item) {
    s32 player;
    if (item != NULL) {
        player = get_player_by_client_id(arg0);
        if ((player != 0) && ((is_locally_controlled__10TObjPlayerFPv() == 1) || ((((TObjChara *)player)->obj_isState3_324() == 1) && ((s32) local_client_id == (s32) TLobby__designated_client_id)) || ((((TObjPlayer *)player)->is_script_controlled() == 1) && ((s32) local_client_id == (s32) TLobby__designated_client_id)))) {
            ((TObjPlayer *)player)->request_inventory_item((TItemData*)item);
            send_6x25_equip_item((void *)player, *(s32 *)((s8 *)item + 0xC), 0);
        }
    }
}
void TLobby::handle_player_event(s32 arg0, s32 arg1) {
    s32 player;
    u32 var_r3;
    player = get_player_by_client_id((u16)arg0);
    if ((player != 0) && ((is_locally_controlled__10TObjPlayerFPv() == 1) || ((((TObjChara *)player)->obj_isState3_324() == 1) && ((s32) local_client_id == (s32) TLobby__designated_client_id)) || ((((TObjPlayer *)player)->is_script_controlled() == 1) && ((s32) local_client_id == (s32) TLobby__designated_client_id)))) {
        var_r3 = 0U;
        switch (arg1) {
        case 0:
            var_r3 = get_item_field_6__10TObjPlayerFPv((void *)player);
            break;
        case 1:
            var_r3 = ((TItemData *)player)->get_item_field_2();
            break;
        case 2:
            var_r3 = ((TItemData *)player)->test_flag3();
            break;
        case 3:
            var_r3 = ((TObjPlayer *)player)->activate_d04_slot();
            break;
        case 4:
        case 5:
        case 6:
        case 7:
            var_r3 = (u32)((TObjPlayer *)player)->get_equipped_item(arg1 + 5);
            break;
        default:
            break;
        }
        if (var_r3 != 0U) {
            TObjPlayer::send_6x26_unequip_item((void *)player, (void *)(get_item_id__5TItemFv()));
        }
    }
}
