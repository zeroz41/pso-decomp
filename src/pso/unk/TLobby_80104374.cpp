#include "pso/enemy/EnemyStateRecord.h"
#include "pso/network/client_id.h"
#include "pso/item/TItemIdCounters.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "types.h"
#include "pso/player/TObjPlayer_80120FC4.h"
#include "pso/system/data/FlagWord.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/item/ItemCreateFunction.h"
#include "pso/item/TItemObject.h"
#include "pso/system/byteswap.h"
#include "pso/network/protocol/ItemDropPacket.h"
#include "pso/enemy/TObjEnemy.h"
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
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjChara.h"
#include "pso/ui/city/TShopEquipmentSellWindow_801047B4.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_80104860.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/item/TItemDisconnectCtrl.h"
#include "pso/item/TItemLoad.h"
#include "pso/item/drop/TItemDrop.h"
#include "pso/map/FloorArea.h"
#include "pso/item/MagStats.h"
#include "pso/item/TItemData_80104D0C.h"
#include "pso/unk/text_80104F4C.h"
#include "pso/unk/text_8011A780.h"
#include "pso/unk/text_80104FCC.h"
#include "pso/item/TItemMenuCtrl.h"
#include "pso/player/PlayerRequirementStats.h"
#include "pso/player/TObjPlayer_8011C000.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/item/TItemMoney.h"
#include "pso/item/armor/TItemProArmor.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/item/armor/TItemProUnit.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/player/TObjPlayer_80121010.h"
#include "pso/player/TObjPlayer_80105874.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/effect/item/TItemEffPG.h"
#include "pso/player/TObjPlayer_80125780.h"
#include "pso/player/TObjPlayer_80307618.h"
#include "pso/player/TObjPlayer_80362E60.h"
#include "pso/weapon/TUnk_804E24F0.h"
#include "pso/weapon/TUnk_804F28E0.h"
#include "pso/unk/text_80125428.h"
#include "pso/unk/text_80126740.h"
#include "pso/unk/text_80126A34.h"
#include "pso/unk/text_80128308.h"
#include "pso/unk/text_80128440.h"
#include "pso/unk/text_80129AB0.h"
#include "pso/unk/text_80129D18.h"
#include "pso/unk/text_8012AE50.h"
#include "pso/unk/text_8012C268.h"
#include "pso/unk/text_80355C1C.h"
#include "pso/unk/text_8035D444.h"
#include "pso/weapon/SpecialProjectileWeapons.h"
#include "pso/weapon/TUnk_804A204C.h"
#include "pso/weapon/TItemWeaponMechgun.h"
#include "pso/weapon/TUnk_804A07C0.h"
#include "pso/weapon/TUnk_804A0CB8.h"
#include "pso/weapon/TUnk_804A0EA8.h"
#include "pso/weapon/TUnk_804A0FA0.h"
#include "pso/weapon/TUnk_804A1098.h"
#include "pso/weapon/TUnk_804A1190.h"
#include "pso/weapon/TUnk_804A1478.h"
#include "pso/weapon/TUnk_804A1A48.h"
#include "pso/weapon/TUnk_804A1B40.h"
#include "pso/weapon/TUnk_804A1C38.h"
#include "pso/weapon/TUnk_804A1E28.h"
#include "pso/weapon/TUnk_804A1F20.h"
#include "pso/weapon/TUnk_804A2868.h"
#include "pso/weapon/TUnk_804A2960.h"
#include "pso/weapon/TUnk_804A2C90.h"
#include "pso/weapon/TUnk_804A3070.h"
#include "pso/weapon/TUnk_804A3168.h"
#include "pso/weapon/TUnk_804A3358.h"
#include "pso/weapon/TUnk_804A3738.h"
#include "pso/weapon/TUnk_804A4238.h"
#include "pso/weapon/TUnk_804A4338.h"
#include "pso/weapon/TUnk_804A4A88.h"
#include "pso/weapon/TUnk_804A4D70.h"
#include "pso/weapon/TUnk_804A4F60.h"
#include "pso/weapon/TUnk_804A5458.h"
#include "pso/weapon/TUnk_804A5550.h"
#include "pso/weapon/TUnk_804A5648.h"
#include "pso/weapon/TUnk_804A5740.h"
#include "pso/weapon/TUnk_804A5838.h"
#include "pso/weapon/TUnk_804A5930.h"
#include "pso/weapon/TUnk_804A5B20.h"
#include "pso/weapon/TUnk_804A5C18.h"
#include "pso/weapon/TUnk_804A6108.h"
#include "pso/weapon/TUnk_804A6200.h"
#include "pso/weapon/TUnk_804A62F8.h"
#include "pso/weapon/TUnk_804A66D8.h"
#include "pso/weapon/TUnk_804A68C8.h"
#include "pso/weapon/TUnk_804A6AD8.h"
#include "pso/weapon/TUnk_804A6BD0.h"
#include "pso/weapon/TUnk_804A6CC8.h"
#include "pso/weapon/TUnk_804A6DC0.h"
#include "pso/weapon/TUnk_804E1BB0.h"
#include "pso/weapon/TUnk_804ECDC0.h"
#include "pso/weapon/TUnk_804ECFB0.h"
#include "pso/weapon/TUnk_804ED1A0.h"
#include "pso/weapon/TUnk_804ED488.h"
#include "pso/weapon/TItemWeaponGuardianna.h"
#include "pso/weapon/TUnk_804F0AF8.h"
#include "pso/weapon/TUnk_804F0810.h"
#include "pso/weapon/TUnk_804F26E0.h"
#include "pso/unk/text_80103674.h"
#include "pso/unk/text_8010F168.h"
#include "pso/item/TItemBuff.h"
#include "pso/unk/TLobby_80105A2C.h"
#include "pso/item/item_pmt.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/item/TItemDisconnectCtrl_80105BE8.h"
#include "pso/item/TItemLockCountCtrl.h"
#include "pso/item/TItemTimerEvent.h"
#include "pso/item/TItemTexLoad.h"
#include "pso/effect/item/TItemEffectWeapon.h"
#include "pso/item/drop/TItemDrop_80105D0C.h"
#include "pso/unk/TLobby_80103F5C.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/item/drop/TItemDropSub_80107B74.h"
#include "pso/ui/window/TWindowSubComCard_80077788.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/player/PlayerSlots.h"

// ---- TLobby_80104374.cpp

extern "C" {
s32 get_item_icon_index();
void TLobby__sub_80104464(void);
int fn_80077788(void);
int fn_80077790(void);
s32 TItemDropSub__sub_80107B74();
}

// This unit's .sbss, in address order.
void *item_object_set_data;
s32 item_ground_placement_enabled;
FlagWord lbl_805D5440;
saddr item_class_load_handle;
int lobby_drop_flag;

// Weapon item factories, indexed by the weapon type byte (get_weapon_factory_for_item); 0 = none.
ItemCreateFunction weapon_factory_table[170] = {
    NULL,
    create_saber_weapon,
    create_sword_weapon,
    create_dagger_weapon,
    create_partisan_weapon,
    create_slicer_weapon,
    create_handgun_weapon,
    create_rifle_weapon,
    create_mechgun_weapon,
    create_shot_weapon,
    create_cane_weapon,
    create_rod_weapon,
    create_wand_weapon,
    create_claw_weapon,
    create_common_weapon,
    create_knuckle_weapon,
    create_agito_weapon,
    create_soul_eater_weapon,
    TObjPlayer::create_init_state_2,
    TObjPlayer::create_handlers_state,
    TObjPlayer::create_inferno_bazooka,
    TObjPlayer__sub_80126054,
    create_common_weapon,
    create_sorcerers_cane,
    TObjPlayer__sub_8012CF84,
    TObjPlayer::create_obj_8012B140,
    create_delsabers_buster_weapon,
    TObjPlayer::create_bringer_effect,
    TObjPlayer__sub_80125428,
    create_psycho_wand,
    create_heaven_punisher,
    TObjPlayer__sub_8012AB1C,
    create_common_weapon,
    TObjPlayer::create_state_35,
    TObjPlayer::create_obj_80122C2C,
    TObjPlayer__sub_8012EFAC,
    TObjPlayer__sub_801277EC,
    TObjPlayer::create_vtable_804A63F0,
    create_suppressed_gun_weapon,
    create_common_weapon,
    TObjPlayer::create_shot_effect_state,
    yamigarasu_create,
    create_common_weapon,
    create_common_weapon,
    TObjPlayer::create_vtable_804A3548,
    create_common_weapon,
    TObjPlayer::create_state,
    TObjPlayer::create_shot_params_state,
    TObjPlayer::create_state_80125154,
    TObjPlayer::create_state_vector_state,
    create_photon_field_weapon,
    sealed_j_sword_create,
    create_common_weapon,
    create_common_weapon,
    TObjPlayer::create_twin_chakram,
    TObjPlayer__sub_80123950,
    TObjPlayer__sub_80127314,
    create_dagger_weapon,
    TObjPlayer__sub_8012F298,
    TObjPlayer::create_fields_state,
    TObjPlayer::create_vtable_clear_field1f8,
    create_photon_field_weapon,
    create_partisan_weapon,
    TObjPlayer::create_variant_2_5a28,
    TObjPlayer::create_position_state,
    create_slicer_weapon,
    TObjPlayer__sub_80121318,
    TObjPlayer__sub_80121318,
    create_handgun_weapon,
    frozen_shooter_create,
    TObjPlayer__sub_80121318,
    TObjPlayer::create_trade_action_state,
    TObjPlayer__sub_8012CE44,
    create_twin_psychogun,
    create_drill_launcher,
    create_guld_milla,
    create_mechgun_weapon,
    create_belra_cannon,
    create_panzer_faust,
    create_common_weapon,
    TObjPlayer::create_state_35_alt,
    TUnk_804A204C::create,
    TObjPlayer::create_obj_80125F60,
    TObjPlayer::create_enter_state_804A0BC0,
    TObjPlayer__sub_801228CC,
    TObjPlayer::create_variant_ct,
    create_common_weapon,
    create_common_weapon,
    TObjPlayer__sub_8012380C,
    TObjPlayer::create_vtable_804a1288,
    TObjPlayer::create_substate_b,
    TObjPlayer::create_effect_object,
    TObjPlayer::create_state_0,
    TObjPlayer::create_substate,
    TObjPlayer::create_state_vt2678,
    TObjPlayer::create_vtable_804A08B8,
    TObjPlayer::create_configured_state,
    TObjPlayer::create_state_513,
    TObjPlayer::create_state_variant_a,
    TObjPlayer::create_state_34,
    TObjPlayer::create_effect_state,
    create_yasminkov_3000r,
    TObjPlayer__sub_80121318,
    create_baranz_launcher,
    TObjPlayer::create_set_vtable_state,
    TObjPlayer::create_state_variant,
    create_yasminkov_2000h,
    create_yasminkov_7000v,
    create_yasminkov_9000m,
    TObjPlayer::create_with_id_2,
    create_common_weapon,
    TObjPlayer__sub_801229EC,
    TObjPlayer::create_srank_common_weapon,
    TObjPlayer::create_srank_common_weapon,
    TObjPlayer__sub_80128308,
    TObjPlayer::create_srank_common_weapon,
    create_s_rank_slicer_weapon,
    TObjPlayer::create_shoot_model_callback,
    TObjPlayer::create_shoot_model_callback,
    TObjPlayer::create_variant,
    create_s_rank_shot,
    TObjPlayer::create_srank_common_weapon,
    TObjPlayer::create_srank_common_weapon,
    TObjPlayer__sub_80128440,
    TObjPlayer::create_srank_common_weapon,
    TObjPlayer::create_obj_80128580,
    create_s_rank_bazooka,
    TObjPlayer::create_state_2,
    TObjPlayer::create_state_8012934c,
    TObjPlayer::create_srank_common_weapon,
    TObjPlayer::create_srank_common_weapon,
    TObjPlayer::create_action,
    TObjPlayer::create_event_callbacks_state,
    TObjPlayer::create_state_8012a418,
    TObjPlayer::create_shot_state,
    TObjPlayer::create_srank_common_weapon,
    create_s_rank_j_cutter_weapon,
    TUnk_804E1BB0::create,
    create_common_weapon,
    TUnk_804E24F0::create,
    TObjPlayer::create_object_by_type,
    TObjPlayer::create_nug2000_bazooka,
    TObjPlayer__sub_80307800,
    create_sword_weapon,
    create_saber_weapon,
    TObjPlayer::create_gi_gue_bazooka,
    create_guardianna,
    TObjPlayer::create_object_by_type,
    create_morning_glory,
    TObjPlayer::create_vtable_1f8_state,
    TObjPlayer::create_object_by_type,
    create_common_weapon,
    TUnk_804F0810::create,
    TObjPlayer::create_vtable_variant,
    TObjPlayer::create_mode_floats_state,
    TUnk_804F0AF8::create,
    TObjPlayer__sub_803265C0,
    create_dark_flow,
    TObjPlayer::create_state_34_alt,
    dark_bridge_create,
    TObjPlayer::create_state_1536,
    TObjPlayer::create_rappys_fan,
    create_common_weapon,
    alloc_and_init_obj_effect,
    TObjPlayer::create_object_by_type,
    TObjPlayer__sub_80128308,
    TUnk_804F28E0::create,
    TObjPlayer__sub_803630F0,
    create_s_rank_knuckle,
    TObjPlayer::create_srank_common_weapon,
};
// Tool item factories, indexed by the tool type byte (TLobby__sub_8010440C).
ItemCreateFunction item_tool_factory_table[24] = {
    TUnk_8049F770::create,
    TUnk_8049FE00::create,
    create_technique_disk_item,
    create_sol_atomizer_item,
    create_moon_atomizer_item,
    create_star_atomizer_item,
    create_status_cure_item,
    create_telepipe_item,
    TUnk_8049FED0::create,
    TItemObject::create,
    create_item_grinder,
    create_material_item,
    TUnk_8049F828::create,
    TItemObject::create,
    TItemObject::create,
    create_add_slot_item,
    TItemObject::create,
    TItemObject::create,
    TItemObject::create,
    TItemObject::create,
    TUnk_804F112C::create,
    TUnk_804F0C48::create,
    TUnk_804F0D34::create,
    TUnk_804F0FF0::create,
};

void normalize_drop_area(s32 *p);

void TLobby::set_boss_buf_entry(int a0, int a1) { item_sync_counter_table[(unsigned short)(a1)] = a0; }
int TLobby::get_sync_counter(u16 a0) {  return item_sync_counter_table[a0]; }
s32 TLobby::get_item_data(u32 arg0) {
    if (arg0 != 0U) {
        return get_item_icon_index();
    }
    return 0;
}
void TLobby::forward_message(saddr buf, uaddr arg1) {
    if (arg1 != 0U) {
        ((TItemData *)arg1)->format_item_name((char *)buf);
    }
}
void TLobby::mark_selected() { lobby_drop_flag = 1; }
int TLobby::get_drop_flag() {  return lobby_drop_flag; }

ItemCreateFunction TLobby__sub_8010440C(u8 *item) {
    u8 i = item[1];
    if (i < 0x18) {
        return item_tool_factory_table[i];
    }
    return TItemObject::create;
}

ItemCreateFunction get_weapon_factory_for_item(u8 *item) {
    u8 i = item[1];
    if (i < 0xAA) {
        return weapon_factory_table[i];
    }
    return create_common_weapon;
}

void TLobby__sub_80104464(void) {  }
void TLobby::handle_select_confirm() {
    TPlyCharData *chr;

    if ((fn_80077790() == 1) || (fn_80077788() == 1)) {
        TLobby::mark_selected();
        chr = (TPlyCharData *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF);
        if (chr != NULL) {
            fn_801058E8(chr);
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

void TLobby::forward_to_player(int id, void *item) {
    TObjPlayer *player;
    if (item != NULL) {
        player = get_player_by_client_id((u16)id);
        if ((player != NULL) && ((TObjPlayer::is_locally_controlled(player) == 1) || ((player->obj_isState3_324() == 1) && ((s32) local_client_id == (s32) designated_client_id)) || ((player->is_script_controlled() == 1) && ((s32) local_client_id == (s32) designated_client_id)))) {
            player->request_inventory_item((TItemData*)item);
            send_6x25_equip_item((TObjPlayer *)player, *(s32 *)((s8 *)item + 0xC), 0);
        }
    }
}
void TLobby::handle_player_event(s32 client, s32 arg1) {
    TObjPlayer *player;
    TItem *item;
    player = get_player_by_client_id((u16)client);
    if ((player != NULL) && ((TObjPlayer::is_locally_controlled(player) == 1) || ((player->obj_isState3_324() == 1) && ((s32) local_client_id == (s32) designated_client_id)) || ((player->is_script_controlled() == 1) && ((s32) local_client_id == (s32) designated_client_id)))) {
        item = NULL;
        switch (arg1) {
        case 0:
            item = TObjPlayer::get_equipped_weapon(player);
            break;
        case 1:
            item = (TItem *)((TItemData *)player)->get_item_field_2();
            break;
        case 2:
            item = (TItem *)((TItemData *)player)->test_flag3();
            break;
        case 3:
            item = (TItem *)player->activate_d04_slot();
            break;
        case 4:
        case 5:
        case 6:
        case 7:
            item = player->get_equipped_item(arg1 + 5);
            break;
        default:
            break;
        }
        if (item != NULL) {
            TObjPlayer::send_6x26_unequip_item((TObjPlayer *)player, item->get_item_id());
        }
    }
}

// ---- TShopEquipmentSellWindow_801047B4.cpp

s32 TShopEquipmentSellWindow::get_item_data_value(uaddr arg0) {
    s32 sp8[4];

    if (arg0 != 0U) {
        ((TItem *)arg0)->copy_to_item_data((TItemData *)sp8);
        return ((TItemData *)sp8)->calc_price();
    }
    return 0;
}
s32 TItemData::calc_price_of(TItemData *data) {
    if (data != NULL) {
        return data->calc_price();
    }
    return 0;
}
s32 is_valid_drop_floor(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0x12)) {
        return 1;
    }
    return 0;
}
s32 TObjPlayer__sub_80104840(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0x24)) {
        return 1;
    }
    return 0;
}

// ---- TObjPlayer_80104860.cpp

extern "C" {
s32 item_identity_matches(u8 *arg0, u8 *arg1);
}
s32 compare_item_data_masked(void *arg0, void *arg1, s32 arg2);

s32 is_local_player_off_current_floor() {
    TObjPlayer *player;
    s32 floor;

    if (is_split_screen() != 0) {
        return 0;
    }
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        floor = get_current_floor();
        return floor - player->get_floor() ? 1 : 0;
    }
    return 0;
}


u8 TObjPlayer::find_adjacent_matching_slot(u8 slot) {
    s16 spC;
    s16 spA;
    s16 sp8;
    int prev;

    prev = (u8) slot - 1;
    get_weapon_special_type_amount((u8) prev, &spC, &sp8);
    get_weapon_special_type_amount(slot, &spA, &sp8);
    if ((spC != -1) && (spA != -1)) {
        if (spC == spA) {
            return (u8) prev;
        }
        return slot;
    }
    return slot;
}

u8 TObjPlayer::get_next_matching_special_index(u8 slot) {
    s16 spC;
    s16 spA;
    s16 sp8;
    int next;
    get_weapon_special_type_amount(slot, &spC, &sp8);
    next = (u8)slot + 1;
    get_weapon_special_type_amount((u8)next, &spA, &sp8);
    if ((spC != -1) && (spA != -1)) {
        if (spC == spA) {
            return (u8)next;
        }
        return slot;
    }
    return slot;
}

s32 item_identity_matches(u8 *arg0, u8 *arg1) {
  s32 var_r3;
  u8 var_r5;
  u8 var_r6;
  if ((((((uaddr) arg0) != 0) && (((uaddr) arg1) != 0)) && ((var_r5 = *((u8 *) (((s8 *) arg0) + 0)), (var_r5 == ((u8) (*((u8 *) (((s8 *) arg1) + 0))))) != 0))) && ((var_r6 = *((u8 *) (((s8 *) arg0) + 1)), (var_r6 == ((u8) (*((u8 *) (((s8 *) arg1) + 1))))) != 0)))
  {
    switch ((s32) var_r5)
    {
      case 0:
        var_r5 = 0x41;
        return compare_item_data_masked(arg0, arg1, 0x41);
      case 1:
        var_r5 = 1;
        return compare_item_data_masked(arg0, arg1, 1);
      case 2:
        var_r5 = 0;
        return compare_item_data_masked(arg0, arg1, 0);
      case 3:
        if (var_r6 == 2)
      {
        var_r5 = 0x41;
        return compare_item_data_masked(arg0, arg1, 0x41);
      }
        var_r5 = 1;
        return compare_item_data_masked(arg0, arg1, 1);
      case 4:
        var_r5 = 0;
        return compare_item_data_masked(arg0, arg1, 0);
    }
  }
  else
  {
    var_r3 = 0;
  }
  return 0;
}
s32 compare_item_data_masked(void *arg0, void *arg1, s32 arg2) {
    u8 *a = (u8 *)arg0;
    u8 *b = (u8 *)arg1;
    s32 r;
    s32 m;
    s32 t;
    s32 m2;
    s32 t2;
    r = 0;
    if (a[0] == b[0] && a[1] == b[1]) {
        r = 1;
        if (arg2 & 7) {
            t = 0;
            if (arg2 & 1) {
                t = (u8)(a[2] == b[2]);
            }
            m = arg2 & 2;
            if (m != 0 && !(arg2 & 4)) {
                t |= a[2] < b[2];
            }
            if (m == 0 && (arg2 & 4)) {
                t |= a[2] > b[2];
            }
            if (m != 0 && (arg2 & 4)) {
                t |= (u8)(a[2] != b[2]);
            }
        } else {
            t = 1;
        }
        r &= t;
        if (arg2 & 0x38) {
            t2 = 0;
            if (arg2 & 8) {
                t2 = a[3] == b[3];
            }
            m2 = arg2 & 0x10;
            if (m2 != 0 && !(arg2 & 0x20)) {
                t2 |= a[3] < b[3];
            }
            if (m2 == 0 && (arg2 & 0x20)) {
                t2 |= a[3] > b[3];
            }
            if (m2 != 0 && (arg2 & 0x20)) {
                t2 |= (u8)(a[3] != b[3]);
            }
        } else {
            t2 = 1;
        }
        r &= t2;
        if (arg2 & 0x40) {
            t = a[4] == b[4];
        } else {
            t = 1;
        }
        r &= t;
    }
    return r;
}

// ---- TMainTask_80104C40.cpp

extern "C" {

void TEnding__sub_8008C9F8(void);
s32 get_game_play_mode();


}

void TMainTask::cleanup_game_objects() {
    s32 floor;
    s32 main_phase;
    s32 area;

    TEnding__sub_8008C9F8();
    TItemLoad::create();
    TObjPlayer::spawn_cleanup_helper(tl_particlemodel);
    TObjPlayer::create_cleanup_object(tl_item_equip);
    main_phase = get_main_phase();
    area = get_current_floor_area();
    floor = get_current_floor();
    item_ground_placement_enabled = 0;
    TLobby::clear_object_count();
    TLobby::respawn_missing_floor_items(floor);
    if ((area == AREA_PIONEER2_EP1) || (area == AREA_PIONEER2_EP2)) {
        lbl_805D5440.set(1);
        if ((main_phase != 0xE) && (main_phase == 0xF)) {
            TItemDrop::refresh_drop_table_if_changed();
        }
    }
    if (get_game_play_mode() == 1) {
        TItemDrop::refresh_drop_table_if_changed();
    }
    if (main_phase == 0xF) {
        new TItemDisconnectCtrl;
    }
    item_ground_placement_enabled = 1;
}

// ---- TItemData_80104D0C.cpp

struct ObjBase_80104DAC { u8 pad[0x18]; };

struct Obj_80104DAC : ObjBase_80104DAC {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual s32 v14();
};

struct ItemData_80104DAC { u8 b[0x14]; };

struct MagData_80104DAC { u8 b[0x10]; };

struct Rec_80104DAC { u8 pad0[6]; u8 b6; u8 b7; u8 b8; u8 b9; u8 bA; u8 bB; u8 bC; };

Rec_80104DAC *find_item_combination_recipe(u8 *, void *);

void *lookup_item_pmt_record(u8 *);

s32 TItemData::is_item_usable(saddr arg0, u8 *item) {
    if (TItemData::is_wrapped(item) != 0) {
        return (u8)(1U);
    }
    if ((u8) *item == 3) {
        if (*(s32 *)((s8 *)(lookup_item_pmt_record(item)) + 0x10) & 1) {
            return (u8)(1U);
        }
        return (u8)((u8) (find_eligible_combination_recipe(arg0, item) != 0));
    }
    return (u8)((u8) (find_eligible_combination_recipe(arg0, item) != 0));
}
#define o ((Obj_80104DAC *)arg0)
saddr find_eligible_combination_recipe(saddr arg0, u8 *item) {
    ItemData_80104DAC d;
    ItemData_80104DAC d2;
    MagData_80104DAC mag;
    s16 m;
    Rec_80104DAC *rec;
    void *it;
    u8 v;
    rec = NULL;
    if (o != NULL && item != NULL) {
        it = find_unique_combination_target((TObjPlayer *)o, (TItemData *)item);
        if (it != NULL) {
            ((TItemData *)(&d))->init();
            ((TItem *)it)->copy_to_item_data((TItemData *)&d);
            rec = find_item_combination_recipe(item, it);
        } else {
            return 0;
        }
        if (rec->b9 != 0xFF) {
            if (d.b[0] != 2) {
                return 0;
            }
            ((MagStats *)(&mag))->init();
            TItemData::deserialize_mag(&d, &mag);
            m = rec->b9;
            if (((MagStats *)(&mag))->get_level() < m) {
                return 0;
            }
        }
        if (rec->bA != 0xFF) {
            if (d.b[0] != 0) {
                return 0;
            }
            if (d.b[3] < rec->bA) {
                return 0;
            }
        }
        v = rec->bB;
        if (v != 0xFF) {
            if (o->v14() < v - 1) {
                return 0;
            }
        }
        v = rec->bC;
        if (v != 0xFF) {
            if (v != (s32)((TPlyPhotonChair *)(o))->get_actor_section_id()) {
                return 0;
            }
        }
        ((TItemData *)(&d2))->init();
        d2.b[0] = rec->b6;
        d2.b[1] = rec->b7;
        d2.b[2] = rec->b8;
        if (check_equip_requirements(o, (TItemData *)&d2, NULL) == 0) {
            return 0;
        }
    }
    return (saddr)rec;
}

// ---- text_80104F4C.cpp
TItem *find_unique_combination_target(TObjPlayer *player, TItemData *item) {
    s32 count = 0;
    TItem *found;
    s32 i;
    TItem *e;
    for (i = 0; i != 13; i++) {
        e = player->get_equipped_item(i);
        if (find_item_combination_recipe((u8 *)item, e) != NULL) {
            found = e;
            count++;
        }
    }
    if (count != 1) {
        found = NULL;
    }
    return found;
}

// ---- text_80104FCC.cpp

// The item class resource sets, one {load, unload} pair each, ended by a null pair;
// init_game_resources hands the table to create_load_unload_set.
ItemClassLoadUnloadEntry item_class_load_unload_table[15] = {
    { load_items, unload_items },
    { TObjPlayer__sub_80121060, TObjPlayer__sub_8012105C },
    { TItemMag::load_data_files, TItemMag::cleanup },
    { TItemProArmor::load_data, TItemProArmor::free },
    { TItemProShield::load_data, TItemProShield::free },
    { TItemProUnit::load_data, TItemProUnit::free },
    { TLobby::alloc_objects, TLobby::free_boss_rocks },
    { TItemDisconnectCtrl__sub_80105BE8, NULL },
    { TItemLockCountCtrl::create_instance, TItemTimerEvent::clear_active },
    { TItemLockCountCtrl::init_effect_table, TItemLockCountCtrl::free_all },
    { load_item_kt_afs, TItemTexLoad::free_textures },
    { TItemEffectWeapon::initialize_static_effects, TItemEffectWeapon::free_static_effects },
    { init_item_drop_globals, unload_item_drop_globals },
    { TLobby::handle_select_confirm, TLobby__sub_80104464 },
    { NULL, NULL },
};

struct Blk_8010542C { u32 w[4]; };
struct Item_8010542C { u32 a; Blk_8010542C b; };
struct Entry_8010567C { u16 a; u16 b; };

struct Pkt_80105538 {
    u8 hdr[4];
    s8 f4;
    s8 f5;
    s16 f6;
    f32 x;
    f32 z;
    s16 f10;
    u8 f12[2];
    s8 f14;
};

struct Obj_80105538 {
    u8 pad[0x28];
    s16 f28;
    u8 pad2a[2];
    s16 f2c;
    u8 pad2e[0x38 - 0x2E];
    f32 x;
    f32 y;
    f32 z;
    u8 pad44[0x370 - 0x44];
    s32 f370;
};

extern "C" {
// Item factories by item group (item[0]) and, for armor, by subgroup (item[1]).
ItemCreateFunction item_pro_create_fn_table[4] = {
    0, TItemProArmor::create, TItemProShield::create, TItemProUnit::create,
};
ItemCreateFunction item_create_fn_table[5] = {
    create_weapon_for_item, TLobby__sub_801054E0, TItemMag::create, TItemObject::create_tool,
    TItemMoney::create,
};
extern Entry_8010567C *quest_object_entries;
int check_class_equip_permission(TObjPlayer *player, s32 perm);
void send_6x60_standard_drop_item_request(Obj_80105538 *self);
}
void *build_6x06_send_guild_card(void *arg0);
extern "C" s32 is_script_controlled__10TObjPlayerFv(void *);
s32 check_equip_requirements(void *self, TItemData *p, s32 *out) {
  void *new_var;
  s32 flags;
  struct
  {
    s16 a;
    s16 x2;
    s16 b;
    s16 c;
    s32 r[2];
  } st;
  u32 k;
  int new_var3;
  s32 r;
  void *new_var2;
  if (((saddr) self == 0) || (p == 0))
  {
    if (out != 0)
    {
      *out |= 0x20;
    }
    return 0;
  }
  new_var2 = self;
  if ((((TObjChara *)new_var2)->obj_isState3_324() != 0) || (is_script_controlled__10TObjPlayerFv(new_var = new_var2) != 0))
  {
    if (out != 0)
    {
      *out = 0;
    }
    return 1;
  }
  if (is_quest_active() != 0)
  {
    k = 0;
    switch (((u8 *) p)[0])
    {
      case 0:
        k = 1;
        break;

      case 1:
        switch (((u8 *) p)[1])
      {
        case 1:
          k = 2;
          break;

        case 2:
          k = 3;
          break;

        case 3:
          k = 4;
          break;

      }

        break;

      case 2:
        k = 5;
        break;

    }

    if ((k != 0) && (TItemMenuCtrl::query_flag(k) == 1))
    {
      return 0;
    }
  }
  flags = 0;
  switch (((u8 *) p)[0])
  {
    case 0:
      if ((saddr) (p = (TItemData *) lookup_item_pmt_record((u8 *) p)) != 0)
    {
      if (check_class_equip_permission((TObjPlayer *) new_var2, (s16) (*((u16 *) ((u8 *) p + 8)))) == 0)
      {
        flags |= 1;
      }
      ((TWindowSubStatusDisp *)(&st))->clear_fields();
      build_player_equipment_requirement_stats((TObjPlayer *) new_var, (PlayerRequirementStats *) (&st));
      if (st.a < (*((u16 *) ((u8 *) p + 0xe))))
      {
        flags |= 2;
      }
      if (st.c < (*((u16 *) ((u8 *) p + 0x12))))
      {
        flags |= 4;
      }
      if (st.b < (*((u16 *) ((u8 *) p + 0x10))))
      {
        flags |= 8;
      }
    }
    else
    {
      flags |= 0x20;
    }
      break;

    case 1:
      if (((u8 *) p)[1] != 3)
    {
      if ((saddr) (p = (TItemData *) lookup_item_pmt_record((u8 *) p)) != 0)
      {
        if (check_class_equip_permission((TObjPlayer *) new_var, (s16) (*((u16 *) ((u8 *) p + 0xe)))) == ((0, 0)))
        {
          flags |= 1;
        }
        r = ((TObjChara *) new_var)->get_actor_level_index();
        if (r < ((u8 *) p)[0x10])
        {
          flags |= 0x10;
        }
      }
      else
      {
        flags |= 0x20;
      }
    }
    else
      if (check_class_equip_permission((TObjPlayer *) new_var2, 0xd7) != 0)
    {
      if ((p = (TItemData *) lookup_item_pmt_record((u8 *) p)) != 0)
      {
        switch (*((s16 *) ((u8 *) p + 8)))
        {
          case 1:

          case 5:

          case 0x10:

          case 0x12:

          case 0x15:
            flags |= 1;
            break;

          default:
            break;

        }

      }
      else
      {
        flags |= 0x20;
      }
    }
      break;

    case 2:
      if ((p = (TItemData *) lookup_item_pmt_record((u8 *) p)) != 0)
    {
      if (check_class_equip_permission((TObjPlayer *) new_var, (s16) (*((u16 *) ((u8 *) p + 0x14)))) == 0)
      {
        flags |= 1;
      }
    }
    else
    {
      flags |= 0x20;
    }
      break;

    case 3:
      switch (((u8 *) p)[1])
    {
      case 2:
        r = ((u8 *) p)[4];
      {
        u8 lim = get_technique_learn_limit(*((u8 *) (((u8 *) new_var2) + 0x88d)), r);
        if ((lim == 0xff) || (lim < ((u8 *) p)[2]))
        {
          flags |= 1;
        }
      }
        break;

      case 8:
        if (check_class_equip_permission((TObjPlayer *) new_var2, 0xd7) != 0)
      {
        flags |= 1;
      }
        break;

    }

      break;

    case 4:
      new_var3 = 0xf423f;
      if (new_var3 < (*((s32 *) ((u8 *) p + 0x10))))
    {
      flags |= 0x20;
    }
      break;

  }

  if (out != 0)
  {
    *out = flags;
  }
  if (flags == 0)
  {
    return 1;
  }
  return 0;
}


int check_class_equip_permission(TObjPlayer *player, s32 perm) {
    s32 t = player->class_flags;
    if (t & CLASS_FLAG_HUNTER) {
        if (!(perm & 1)) return 0;
    } else if (t & CLASS_FLAG_RANGER) {
        if (!(perm & 2)) return 0;
    } else if (!(perm & 4)) {
        return 0;
    }
    if (t & CLASS_FLAG_ANDROID) {
        if (!(perm & 0x10)) return 0;
    } else if (t & CLASS_FLAG_NEWMAN) {
        if (!(perm & 0x20)) return 0;
    } else if (t & CLASS_FLAG_HUMAN) {
        if (!(perm & 8)) return 0;
    }
    if (t & CLASS_FLAG_MALE) {
        if (!(perm & 0x40)) return 0;
    } else if (t & CLASS_FLAG_FEMALE) {
        if (!(perm & 0x80)) return 0;
    }
    return 1;
}

u8 roll_weapon_special_channel15(u8 arg0) { return roll_weapon_special_for_stars(arg0); }

TItem *construct_item(TItemData *data) {
    Item_8010542C *src = (Item_8010542C *)data;
    ItemCreateFunction fn;
    if (src != 0) {
        Item_8010542C item = *src;
        ((TItemData *)&item)->decode_from_network();
        if (((TItemData *)(&item))->isValidGroundDrop() != 0) {
            if (*(u8 *)src < 5) {
                fn = item_create_fn_table[*(u8 *)src];
                if (fn != 0) {
                    observe_item_id(item.b.w[2]);
                    return fn((u8 *)&item);
                }
            }
        }
    }
    return 0;
}

extern "C" {

TItem *TLobby__sub_801054E0(u8 *item) {
    if (item != 0) {
        if (item[1] < 4) {
            if (item_pro_create_fn_table[item[1]] != 0) {
                return item_pro_create_fn_table[item[1]](item);
            }
        }
    }
    return 0;
}

// Dead-stripped by the linker: its 0.0f is the only trace left. The DOL pools 0.0f (0x805DAAB0)
// ahead of send_6x60_standard_drop_item_request's 100.0f, so a 0.0f user came first in this TU.
// inferred: minimal body, the real function is unknown.
void clear_drop_request_position(Vec *v) {
    v->x = 0.0f;
    v->y = 0.0f;
    v->z = 0.0f;
}

void send_6x60_standard_drop_item_request(Obj_80105538 *self) {
    void *p1;
    void *p2;
    if (self != 0) {
        p1 = get_player_by_client_id(designated_client_id);
        p2 = get_player_by_client_id(local_client_id);
        if (p1 != 0 && p2 != 0) {
            if (is_valid_drop_floor(get_current_floor()) != 0 &&
                (((TObjPlayer *)p1)->get_floor() != ((TObjPlayer *)p2)->get_floor() ||
                 designated_client_id == local_client_id)) {
                if (self->f2c != -1) {
                    EnemyStateRecord e = TLobby__data_805D6144[self->f2c];
                    if (e.drop_id != 0xFFFF) {
                        Pkt_80105538 pkt;
                        build_6x06_send_guild_card(&pkt);
                        pkt.f4 = get_current_floor();
                        pkt.f5 = self->f370;
                        pkt.f6 = self->f2c;
                        pkt.x = self->x;
                        pkt.z = self->z;
                        pkt.f10 = self->f28;
                        pkt.f14 = get_current_floor_area();
                        Vec v;
                        v.x = pkt.x;
                        v.y = 100.0f;
                        v.z = pkt.z;
                        if (csnVecterUnder(&v, 1) != 0) {
                            ((TLobby *)(&pkt))->dispatch_packet_wrapper();
                        }
                    }
                }
            }
        }
    }
}

void TObjChara::request_box_item_drop(const Vec *, s32 random_item) {
    void *p1;
    void *p2;
    if (this != NULL) {
        p1 = get_player_by_client_id(designated_client_id);
        p2 = get_player_by_client_id(local_client_id);
        if (p1 != 0 && p2 != 0 && TObjPlayer__sub_80104840(get_current_floor_area()) != AREA_PIONEER2_EP1 &&
            (((TObjPlayer *)p1)->get_floor() != ((TObjPlayer *)p2)->get_floor() ||
             designated_client_id == local_client_id)) {
            if (this->set_index != -1) {
                Entry_8010567C e = quest_object_entries[this->set_index];
                if (e.b != 0xFFFF) {
                    G_SpecializableItemDropRequest_6xA2 packet;
                    G_StandardDropItemRequest_PC_V3_BB_6x60 &extended =
                        packet.__base_G_StandardDropItemRequest_PC_V3_BB_6x60;
                    G_StandardDropItemRequest_DC_6x60 &drop = extended.__base_G_StandardDropItemRequest_DC_6x60;
                    packet.init();
                    drop.floor = get_current_floor();
                    drop.rt_index = 0x30;
                    drop.pos.x = position.x;
                    drop.pos.z = position.z;
                    drop.room = room;
                    drop.ignore_def = random_item;
                    drop.entity_index = set_index;
                    extended.effective_area = get_current_floor_area();
                    packet.param3 = scale.z;
                    packet.param4 = set_params[0];
                    packet.param5 = set_params[1];
                    packet.param6 = set_params[2];
                    packet.send();
                }
            }
        }
    }
}
}

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
Item_801057A8 *spawn_dropped_item_from_msg(Msg_801057A8 *arg0, s32 quiet);
Item_801057A8 *spawn_dropped_item_from_msg(Msg_801057A8 *arg0, s32 quiet) {
    Item_801057A8 *item;
    s8 me;
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
                ((TItem *)item)->place_on_ground(arg0->client, &item->x, 1);
            }
        }
        if (quiet == 0) {
            ((void (*)(s32, s32, u8 *, f32, f32))add_item_condition)(arg0->client, arg0->area, arg0->item, arg0->x, arg0->z);
        }
    }
    return item;
}

void TObjPlayer::free_item_globals() { TItemDrop__sub_8010F168((void *)item_class_load_handle, (s16)1); item_class_load_handle = 0; TItemLoad::free_all(); TItemBuff::free_all_and_init(); }

void TObjPlayer::init_game_resources() {
    init_item_chunk_buffers();
    TItemLoad::init_resources();
    item_class_load_handle = create_load_unload_set(item_class_load_unload_table);
    lbl_805D5440.reset();
}

void fn_801058E8(void* p) { *(u8*)((char*)p + 0x7) |= 0x1; }

s32 TObjPlayer::is_script_controlled() {
    return this->control_state == 6;
}

saddr TObjPlayer::activate_d04_slot() { return TObjPlayer::get_slot_value((s32 *)((char*)this + 0xd04), 1); }

saddr TItemData::test_flag3() { return TObjPlayer::get_slot_value((s32 *)((char*)this + 0xd04), 3); }
saddr TItemData::get_item_field_2() { return TObjPlayer::get_slot_value((s32 *)((char*)this + 0xd04), 2); }


}

MagStats *MagStats::init() { clear(); return this; }

void TWindowSubStatusDisp::clear_fields() { *(s16*)((char*)this + 0xa) = 0; *(s16 *)&this->m_prev = 0; *(s16 *)&this->m_id = 0; *(s16 *)&this->m_flags = 0; *(s16*)((char*)this + 0x2) = 0; *(s16 *)&this->m_name = 0; *(s16 *)&this->m_down = 0; *(s16*)((char*)this + 0x12) = 0; *(s16 *)&this->m_up = 0; *(s16*)((char*)this + 0xe) = 0; *(s16 *)&this->m_next = 0; }

extern "C" {

s32 test_flags_any(s32 *, s32);

s32 TItemMenuCtrl::query_flag(s32 arg0) {
    if (TItemMenuCtrl__instance != NULL) {
        return test_flags_any(&TItemMenuCtrl__instance->menu_flags.bits, 1 << arg0);
    }
    return 0;
}

}

void TLobby::dispatch_packet_wrapper() { bswap_6x60_drop_request_fields(this); send_subcommand_to_leader(this); }

void bswap_6x60_drop_request_fields(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_16((u16 *)((char*)p + 0x6)); bswap_16((u16 *)((char*)p + 0x10)); bswap_16((u16 *)((char*)p + 0x12)); bswap_32((u32 *)((char*)p + 0x8)); bswap_32((u32 *)((char*)p + 0xc)); }
void *build_6x06_send_guild_card(void *arg0) {
    build_6x05_write_switch_flag(arg0);
    *(s8 *)((s8 *)arg0 + 0) = 0x60;
    *(s8 *)((s8 *)arg0 + 1) = 6;
    return arg0;
}
void build_6x05_write_switch_flag(void* a0) { *(float*)((char*)a0 + 0xc) = 0.0f; *(float*)((char*)a0 + 0x8) = 0.0f; *(short*)((char*)a0 + 0x10) = 0; *(short*)((char*)a0 + 0x12) = 0; *(unsigned char*)((char*)a0 + 0x5) = 0; *(unsigned char*)((char*)a0 + 0x4) = 0; *(unsigned char*)((char*)a0 + 0x0) = 96; *(unsigned char*)((char*)a0 + 0x1) = 5; }

void G_SpecializableItemDropRequest_6xA2::send() {
    bswap();
    send_subcommand_to_leader(this);
}

void G_SpecializableItemDropRequest_6xA2::bswap() {
    bswap_6x60_drop_request_fields(this);
    bswap_32(reinterpret_cast<u32 *>(&param3));
    bswap_32(reinterpret_cast<u32 *>(&param4));
    bswap_32(reinterpret_cast<u32 *>(&param5));
    bswap_32(reinterpret_cast<u32 *>(&param6));
}

G_SpecializableItemDropRequest_6xA2 *G_SpecializableItemDropRequest_6xA2::init() {
    build_6x06_send_guild_card(this);
    G_UnusedHeader &header = __base_G_StandardDropItemRequest_PC_V3_BB_6x60.__base_G_StandardDropItemRequest_DC_6x60.header;
    header.subcommand = 0xA2;
    header.size = 0x0A;
    return this;
}

// ---- TItemDisconnectCtrl_80105BE8.cpp

void TItemDisconnectCtrl__sub_80105BE8(void) { lbl_805D54E0 = 0; }
