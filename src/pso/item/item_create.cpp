#include "pso/player/TEquippedWeaponDrawTask.h"
#include "pso/player/TEquippedItemDrawTask.h"
#include "pso/enemy/EnemyStateRecord.h"
#include "pso/network/client_id.h"
#include "pso/item/TItemIdCounters.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/system/data/FlagWord.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/item/ItemCreateFunction.h"
#include "pso/item/item_create.h"
#include "pso/item/TItemObject.h"
#include "pso/system/byteswap.h"
#include "pso/network/protocol/ItemDropPacket.h"
#include "pso/enemy/TObjEnemy.h"
#include <stddef.h>
#include "pso/network/TLobby.h"
#include "pso/item/TItemData.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemToolMate.h"
#include "pso/item/TItemToolFluid.h"
#include "pso/item/TItemToolTechniqueDisk.h"
#include "pso/item/TItemToolSolAtomizer.h"
#include "pso/item/TItemToolMoonAtomizer.h"
#include "pso/item/TItemToolStarAtomizer.h"
#include "pso/item/TItemToolStatusCure.h"
#include "pso/item/TItemToolTelepipe.h"
#include "pso/item/TItemToolTrapVision.h"
#include "pso/item/TItemToolGrinder.h"
#include "pso/item/TItemToolMaterial.h"
#include "pso/item/TItemToolMagCell.h"
#include "pso/item/TItemToolAddSlot.h"
#include "pso/item/TUnk_804F112C.h"
#include "pso/item/TItemToolRandomItem.h"
#include "pso/item/TItemToolQuestBgm.h"
#include "pso/item/TItemToolKillCounter.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_801036CC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjChara.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/item/TItemDisconnectCtrl.h"
#include "pso/item/TItemLoad.h"
#include "pso/item/drop/TItemDrop.h"
#include "pso/map/FloorArea.h"
#include "pso/item/MagStats.h"
#include "pso/item/TItemData_80104D0C.h"
#include "pso/unk/text_80104F4C.h"
#include "pso/unk/text_80104FCC.h"
#include "pso/item/TItemMenuCtrl.h"
#include "pso/player/PlayerRequirementStats.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/item/TItemMoney.h"
#include "pso/item/armor/TItemProArmor.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/item/armor/TItemProUnit.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/effect/item/TItemEffPG.h"
#include "pso/weapon/TItemWeaponPanzerFaust.h"
#include "pso/weapon/TItemWeaponSRankCard.h"
#include "pso/weapon/TItemWeaponPhotonLauncher.h"
#include "pso/weapon/TItemWeaponSRankLauncher.h"
#include "pso/unk/text_80126A34.h"
#include "pso/unk/text_80128308.h"
#include "pso/unk/text_80128440.h"
#include "pso/unk/text_80129AB0.h"
#include "pso/unk/text_80129D18.h"
#include "pso/unk/text_8012AE50.h"
#include "pso/unk/text_8012C268.h"
#include "pso/weapon/TItemWeaponDarkMeteor.h"
#include "pso/weapon/TItemWeaponNug2000Bazooka.h"
#include "pso/weapon/TItemWeaponSBerillsHands.h"
#include "pso/weapon/TItemWeaponTsumikiri.h"
#include "pso/system/scene/TEnding.h"
#include "pso/unk/text_8035D444.h"
#include "pso/weapon/SpecialProjectileWeapons.h"
#include "pso/weapon/TItemWeaponEvilCurst.h"
#include "pso/weapon/TItemWeaponMechgun.h"
#include "pso/weapon/TItemWeaponSpecialGun.h"
#include "pso/weapon/TItemWeaponBelraCannon.h"
#include "pso/weapon/TItemWeaponGuldMilla.h"
#include "pso/weapon/TItemWeaponDagger.h"
#include "pso/weapon/TItemWeaponHildebluesCane.h"
#include "pso/weapon/TItemWeaponFlowerBouquet.h"
#include "pso/weapon/TItemWeaponWand.h"
#include "pso/weapon/TItemWeaponStrikerOfChao.h"
#include "pso/weapon/TItemWeaponWokOfAkikosShop.h"
#include "pso/weapon/TItemWeaponClaw.h"
#include "pso/weapon/TItemWeaponSorcerersCane.h"
#include "pso/weapon/TItemWeaponDelsabersBuster.h"
#include "pso/weapon/TItemWeaponFlameVisit.h"
#include "pso/weapon/TItemWeaponFrozenShooter.h"
#include "pso/weapon/TItemWeaponHandgun.h"
#include "pso/weapon/TItemWeaponAgito.h"
#include "pso/weapon/TItemWeaponLavisBlade.h"
#include "pso/weapon/TItemWeaponMagicalPiece.h"
#include "pso/weapon/TItemWeaponYamigarasu.h"
#include "pso/weapon/TItemWeaponSRankJCutter.h"
#include "pso/weapon/TItemWeaponSRankSlicer.h"
#include "pso/weapon/TItemWeaponLavisCannon.h"
#include "pso/weapon/TItemWeaponPartisan.h"
#include "pso/weapon/TItemWeaponPsychoWand.h"
#include "pso/weapon/TItemWeaponRod.h"
#include "pso/weapon/TItemWeaponSaber.h"
#include "pso/weapon/TItemWeaponSambaMaracas.h"
#include "pso/weapon/TItemWeaponSBeatsBlade.h"
#include "pso/weapon/TItemWeaponSoulEater.h"
#include "pso/weapon/TItemWeaponSealedJSword.h"
#include "pso/weapon/TItemWeaponSlicer.h"
#include "pso/weapon/TItemWeaponShot.h"
#include "pso/weapon/TItemWeaponStingTip.h"
#include "pso/weapon/TItemWeaponMadamsParasol.h"
#include "pso/weapon/TItemWeaponSword.h"
#include "pso/weapon/TItemWeaponTwinPsychogun.h"
#include "pso/weapon/TItemWeaponCane.h"
#include "pso/weapon/TItemWeaponYasminkov9000M.h"
#include "pso/weapon/TItemWeaponYasminkov3000R.h"
#include "pso/weapon/TItemWeaponYasminkov2000H.h"
#include "pso/weapon/TItemWeaponYasminkov7000V.h"
#include "pso/weapon/TItemWeaponMusashi.h"
#include "pso/weapon/TItemWeaponCard.h"
#include "pso/weapon/TItemWeaponRainbowBaton.h"
#include "pso/weapon/TItemWeaponDarkBridge.h"
#include "pso/weapon/TItemWeaponMorningGlory.h"
#include "pso/weapon/TItemWeaponDarkFlow.h"
#include "pso/weapon/TItemWeaponGuardianna.h"
#include "pso/weapon/TItemWeaponNeisClaw.h"
#include "pso/weapon/TItemWeaponRikasClaw.h"
#include "pso/weapon/TItemWeaponSRankKnuckle.h"
#include "pso/unk/text_80103674.h"
#include "pso/unk/text_8010F168.h"
#include "pso/item/TItemBuff.h"
#include "pso/item/item_pmt.h"
#include "pso/item/TItemDisconnectCtrl_80105BE8.h"
#include "pso/item/TItemLockCountCtrl.h"
#include "pso/item/TItemTimerEvent.h"
#include "pso/item/TItemTexLoad.h"
#include "pso/effect/item/TItemEffectWeapon.h"
#include "pso/unk/TLobby_80103F5C.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/item/drop/TItemDropSub.h"
#include "pso/network/protocol/choice_search.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/player/PlayerSlots.h"
#include "pso/weapon/TItemWeaponAngelHarp.h"
#include "pso/weapon/TItemWeaponBranchOfPakupaku.h"
#include "pso/weapon/TItemWeaponBringersRifle.h"
#include "pso/weapon/TItemWeaponBroom.h"
#include "pso/weapon/TItemWeaponCaduceus.h"
#include "pso/weapon/TItemWeaponChainSawd.h"
#include "pso/weapon/TItemWeaponChameleonScythe.h"
#include "pso/weapon/TItemWeaponDemolitionComet.h"
#include "pso/weapon/TItemWeaponDoubleCannon.h"
#include "pso/weapon/TItemWeaponDragonsClaw.h"
#include "pso/weapon/TItemWeaponEggBlaster.h"
#include "pso/weapon/TItemWeaponElysion.h"
#include "pso/weapon/TItemWeaponFlightFan.h"
#include "pso/weapon/TItemWeaponFlowerCane.h"
#include "pso/weapon/TItemWeaponGAssassinsSabers.h"
#include "pso/weapon/TItemWeaponGiGueBazooka.h"
#include "pso/weapon/TItemWeaponHarisenBattleFan.h"
#include "pso/weapon/TItemWeaponHeartOfPoumn.h"
#include "pso/weapon/TItemWeaponHildebearsCane.h"
#include "pso/weapon/TItemWeaponHolyRay.h"
#include "pso/weapon/TItemWeaponHugeBattleFan.h"
#include "pso/weapon/TItemWeaponImperialPick.h"
#include "pso/weapon/TItemWeaponInfernoBazooka.h"
#include "pso/weapon/TItemWeaponMadamsUmbrella.h"
#include "pso/weapon/TItemWeaponMarinasBag.h"
#include "pso/weapon/TItemWeaponMaserBeam.h"
#include "pso/weapon/TItemWeaponMeteorCudgel.h"
#include "pso/weapon/TItemWeaponMonkeyKingBar.h"
#include "pso/weapon/TItemWeaponPArmsBlade.h"
#include "pso/weapon/TItemWeaponPanthersClaw.h"
#include "pso/weapon/TItemWeaponPartisanOfLightning.h"
#include "pso/weapon/TItemWeaponPlantainFan.h"
#include "pso/weapon/TItemWeaponPlantainHugeFan.h"
#include "pso/weapon/TItemWeaponProphetsOfMotav.h"
#include "pso/weapon/TItemWeaponRabbitWand.h"
#include "pso/weapon/TItemWeaponRappysFan.h"
#include "pso/weapon/TItemWeaponRifle.h"
#include "pso/weapon/TItemWeaponSRankBazooka.h"
#include "pso/weapon/TItemWeaponSRankClaw.h"
#include "pso/weapon/TItemWeaponSRankMechgun.h"
#include "pso/weapon/TItemWeaponSRankNeedle.h"
#include "pso/weapon/TItemWeaponSRankPsychogun.h"
#include "pso/weapon/TItemWeaponSRankPunch.h"
#include "pso/weapon/TItemWeaponSRankScythe.h"
#include "pso/weapon/TItemWeaponSRankShot.h"
#include "pso/weapon/TItemWeaponSRankWand.h"
#include "pso/weapon/TItemWeaponSRankWindmill.h"
#include "pso/weapon/TItemWeaponSRedsBlade.h"
#include "pso/weapon/TItemWeaponSpreadNeedle.h"
#include "pso/weapon/TItemWeaponTechnicalCrozier.h"
#include "pso/weapon/TItemWeaponTheSighOfAGod.h"
#include "pso/weapon/TItemWeaponTwinBlaze.h"
#include "pso/weapon/TItemWeaponWindmill.h"
#include "pso/weapon/TItemWeaponBaranzLauncher.h"
#include "pso/weapon/TItemWeaponDrillLauncher.h"
#include "pso/weapon/TItemWeaponFist.h"
#include "pso/weapon/TItemWeaponFlightCutter.h"
#include "pso/weapon/TItemWeaponSRank.h"
#include "pso/weapon/TItemWeaponSRankBlade.h"
#include "pso/weapon/TItemWeaponSRankGun.h"
#include "pso/weapon/TItemWeaponSRankHarisen.h"
#include "pso/weapon/TItemWeaponTwinkleStar.h"
#include "pso/unk/TLobby_8030A6A8.h"

// ---- TLobby_80104374.cpp

extern "C" {
s32 get_item_icon_index();
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
    TItemWeaponSaber::create,
    TItemWeaponSword::create,
    TItemWeaponDagger::create,
    TItemWeaponPartisan::create,
    TItemWeaponSlicer::create,
    TItemWeaponHandgun::create,
    TItemWeaponRifle::create,
    TItemWeaponMechgun::create,
    TItemWeaponShot::create,
    TItemWeaponCane::create,
    TItemWeaponRod::create,
    TItemWeaponWand::create,
    TItemWeaponClaw::create,
    create_common_weapon,
    TItemWeaponFist::create,
    TItemWeaponAgito::create,
    TItemWeaponSoulEater::create,
    TItemWeaponSpreadNeedle::create,
    TItemWeaponHolyRay::create,
    TItemWeaponInfernoBazooka::create,
    TItemWeaponFlameVisit::create,
    create_common_weapon,
    TItemWeaponSorcerersCane::create,
    TItemWeaponSBeatsBlade::create,
    TItemWeaponPArmsBlade::create,
    TItemWeaponDelsabersBuster::create,
    TItemWeaponBringersRifle::create,
    TItemWeaponEggBlaster::create,
    TItemWeaponPsychoWand::create,
    create_heaven_punisher,
    TItemWeaponLavisCannon::create,
    create_common_weapon,
    TItemWeaponChainSawd::create,
    TItemWeaponCaduceus::create,
    TItemWeaponStingTip::create,
    TItemWeaponMagicalPiece::create,
    TItemWeaponTechnicalCrozier::create,
    TItemWeaponSuppressedGun::create,
    create_common_weapon,
    TItemWeaponHarisenBattleFan::create,
    TItemWeaponYamigarasu::create,
    create_common_weapon,
    create_common_weapon,
    TItemWeaponElysion::create,
    create_common_weapon,
    TItemWeaponMeteorCudgel::create,
    TItemWeaponMonkeyKingBar::create,
    TItemWeaponDoubleCannon::create,
    TItemWeaponHugeBattleFan::create,
    create_photon_field_weapon,
    TItemWeaponSealedJSword::create,
    create_common_weapon,
    create_common_weapon,
    TObjPlayer::create_twin_chakram,
    TItemWeaponWokOfAkikosShop::create,
    TItemWeaponLavisBlade::create,
    TItemWeaponDagger::create,
    TItemWeaponMadamsParasol::create,
    TItemWeaponMadamsUmbrella::create,
    TItemWeaponImperialPick::create,
    create_photon_field_weapon,
    TItemWeaponPartisan::create,
    TItemWeaponFlightCutter::create,
    TItemWeaponFlightFan::create,
    TItemWeaponSlicer::create,
    TItemWeaponSpecialGun::create,
    TItemWeaponSpecialGun::create,
    TItemWeaponHandgun::create,
    TItemWeaponFrozenShooter::create,
    TItemWeaponSpecialGun::create,
    TObjPlayer::create_trade_action_state,
    TItemWeaponSambaMaracas::create,
    TItemWeaponTwinPsychogun::create,
    TItemWeaponDrillLauncher::create,
    TItemWeaponGuldMilla::create,
    TItemWeaponMechgun::create,
    TItemWeaponBelraCannon::create,
    create_panzer_faust,
    create_common_weapon,
    TItemWeaponWindmill::create,
    TItemWeaponEvilCurst::create,
    TItemWeaponFlowerCane::create,
    TItemWeaponHildebearsCane::create,
    TItemWeaponHildebluesCane::create,
    TItemWeaponRabbitWand::create,
    create_common_weapon,
    create_common_weapon,
    TItemWeaponStrikerOfChao::create,
    TItemWeaponBroom::create,
    TItemWeaponProphetsOfMotav::create,
    TItemWeaponTheSighOfAGod::create,
    TItemWeaponTwinkleStar::create,
    TItemWeaponPlantainFan::create,
    TItemWeaponTwinBlaze::create,
    TItemWeaponMarinasBag::create,
    TItemWeaponDragonsClaw::create,
    TItemWeaponPanthersClaw::create,
    TItemWeaponSRedsBlade::create,
    TItemWeaponPlantainHugeFan::create,
    TItemWeaponChameleonScythe::create,
    TItemWeaponYasminkov3000R::create,
    TItemWeaponSpecialGun::create,
    TItemWeaponBaranzLauncher::create,
    TItemWeaponBranchOfPakupaku::create,
    TItemWeaponHeartOfPoumn::create,
    TItemWeaponYasminkov2000H::create,
    TItemWeaponYasminkov7000V::create,
    TItemWeaponYasminkov9000M::create,
    TItemWeaponMaserBeam::create,
    create_common_weapon,
    TItemWeaponFlowerBouquet::create,
    TItemWeaponSRank::create,
    TItemWeaponSRank::create,
    TItemWeaponSRankBlade::create,
    TItemWeaponSRank::create,
    create_s_rank_slicer_weapon,
    TItemWeaponSRankGun::create,
    TItemWeaponSRankGun::create,
    TItemWeaponSRankMechgun::create,
    TItemWeaponSRankShot::create,
    TItemWeaponSRank::create,
    TItemWeaponSRank::create,
    TItemWeaponSRankWand::create,
    TItemWeaponSRank::create,
    TItemWeaponSRankClaw::create,
    TItemWeaponSRankBazooka::create,
    TItemWeaponSRankNeedle::create,
    TItemWeaponSRankScythe::create,
    TItemWeaponSRank::create,
    TItemWeaponSRank::create,
    TItemWeaponSRankPsychogun::create,
    TItemWeaponSRankPunch::create,
    TItemWeaponSRankWindmill::create,
    TItemWeaponSRankHarisen::create,
    TItemWeaponSRank::create,
    create_s_rank_j_cutter_weapon,
    TItemWeaponMusashi::create,
    create_common_weapon,
    TItemWeaponPhotonLauncher::create,
    TItemWeaponCard::create,
    create_nug2000_bazooka,
    create_s_berills_hands_weapon,
    TItemWeaponSword::create,
    TItemWeaponSaber::create,
    TItemWeaponGiGueBazooka::create,
    create_guardianna,
    TItemWeaponCard::create,
    TItemWeaponMorningGlory::create,
    TItemWeaponPartisanOfLightning::create,
    TItemWeaponCard::create,
    create_common_weapon,
    TItemWeaponRikasClaw::create,
    TItemWeaponAngelHarp::create,
    TItemWeaponDemolitionComet::create,
    TItemWeaponNeisClaw::create,
    TItemWeaponRainbowBaton::create,
    TItemWeaponDarkFlow::create,
    create_dark_meteor_weapon,
    TItemWeaponDarkBridge::create,
    TItemWeaponGAssassinsSabers::create,
    TItemWeaponRappysFan::create,
    create_common_weapon,
    TItemWeaponRubyBullet::create,
    TItemWeaponCard::create,
    TItemWeaponSRankBlade::create,
    TItemWeaponSRankLauncher::create,
    TItemWeaponSRankCard::create,
    TItemWeaponSRankKnuckle::create,
    TItemWeaponSRank::create,
};
// Tool item factories, indexed by the tool type byte.
ItemCreateFunction item_tool_factory_table[24] = {
    TItemToolMate::create,
    TItemToolFluid::create,
    TItemToolTechniqueDisk::create,
    TItemToolSolAtomizer::create,
    TItemToolMoonAtomizer::create,
    TItemToolStarAtomizer::create,
    TItemToolStatusCure::create,
    TItemToolTelepipe::create,
    TItemToolTrapVision::create,
    TItemObject::create,
    TItemToolGrinder::create,
    TItemToolMaterial::create,
    TItemToolMagCell::create,
    TItemObject::create,
    TItemObject::create,
    TItemToolAddSlot::create,
    TItemObject::create,
    TItemObject::create,
    TItemObject::create,
    TItemObject::create,
    TUnk_804F112C::create,
    TItemToolRandomItem::create,
    TItemToolQuestBgm::create,
    TItemToolKillCounter::create,
};


void set_boss_buf_entry(int value, u16 index) { item_sync_counter_table[index] = value; }
int TLobby::get_sync_counter(u16 a0) {  return item_sync_counter_table[a0]; }
s32 get_item_data(u32 item) {
    if (item != 0U) {
        return get_item_icon_index();
    }
    return 0;
}
void forward_message(saddr buf, uaddr item) {
    if (item != 0U) {
        ((TItemData *)item)->format_item_name((char *)buf);
    }
}
void mark_selected() { lobby_drop_flag = 1; }
int get_drop_flag() {  return lobby_drop_flag; }

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
void handle_select_confirm() {
    TPlyCharData *chr;

    if ((fn_80077790() == 1) || (fn_80077788() == 1)) {
        mark_selected();
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
            *p = TItemDropSub::get_box_drop_area();
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

void TLobby::forward_to_player(int id, TItemData *item) {
    TObjPlayer *player;
    if (item != NULL) {
        player = get_player_by_client_id((u16)id);
        if ((player != NULL) && ((player->is_locally_controlled() == 1) || ((player->obj_isState3_324() == 1) && ((s32) local_client_id == (s32) designated_client_id)) || ((player->is_script_controlled() == 1) && ((s32) local_client_id == (s32) designated_client_id)))) {
            player->request_inventory_item(item);
            send_6x25_equip_item(player, item->id, 0);
        }
    }
}
void TLobby::handle_player_event(s32 client, s32 slot) {
    TObjPlayer *player;
    TItem *item;
    player = get_player_by_client_id((u16)client);
    if ((player != NULL) && ((player->is_locally_controlled() == 1) || ((player->obj_isState3_324() == 1) && ((s32) local_client_id == (s32) designated_client_id)) || ((player->is_script_controlled() == 1) && ((s32) local_client_id == (s32) designated_client_id)))) {
        item = NULL;
        switch (slot) {
        case 0:
            item = TObjPlayer::get_equipped_weapon(player);
            break;
        case 1:
            item = player->get_equipped_armor();
            break;
        case 2:
            item = player->get_equipped_shield();
            break;
        case 3:
            item = player->get_equipped_mag();
            break;
        case 4:
        case 5:
        case 6:
        case 7:
            item = player->get_equipped_item(slot + 5);
            break;
        default:
            break;
        }
        if (item != NULL) {
            TObjPlayer::send_6x26_unequip_item(player, item->get_item_id());
        }
    }
}

// ---- TShopEquipmentSellWindow_801047B4.cpp

s32 TShopEquipmentSellWindow::get_item_data_value(TItem *item) {
    TItemData data;

    if (item != NULL) {
        item->copy_to_item_data(&data);
        return data.calc_price();
    }
    return 0;
}
s32 TItemData::calc_price_of(TItemData *data) {
    if (data != NULL) {
        return data->calc_price();
    }
    return 0;
}
s32 is_valid_drop_floor(s32 floor) {
    if ((floor >= 0) && (floor < 0x12)) {
        return 1;
    }
    return 0;
}
s32 TObjPlayer__sub_80104840(s32 index) {
    if ((index >= 0) && (index < 0x24)) {
        return 1;
    }
    return 0;
}

// ---- TObjPlayer_80104860.cpp

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
    s16 prev_type;
    s16 type;
    s16 amount;
    int prev;

    prev = slot - 1;
    get_weapon_special_type_amount((u8) prev, &prev_type, &amount);
    get_weapon_special_type_amount(slot, &type, &amount);
    if ((prev_type != -1) && (type != -1)) {
        if (prev_type == type) {
            return (u8) prev;
        }
        return slot;
    }
    return slot;
}

u8 TObjPlayer::get_next_matching_special_index(u8 slot) {
    s16 type;
    s16 next_type;
    s16 amount;
    int next;
    get_weapon_special_type_amount(slot, &type, &amount);
    next = slot + 1;
    get_weapon_special_type_amount((u8)next, &next_type, &amount);
    if ((type != -1) && (next_type != -1)) {
        if (type == next_type) {
            return (u8)next;
        }
        return slot;
    }
    return slot;
}

s32 item_identity_matches(u8 *item, u8 *other) {
  s32 result;
  u8 item_type;
  u8 item_group;
  if ((((((uaddr) item) != 0) && (((uaddr) other) != 0)) && ((item_type = *((u8 *) (((s8 *) item) + 0)), (item_type == ((u8) (*((u8 *) (((s8 *) other) + 0))))) != 0))) && ((item_group = *((u8 *) (((s8 *) item) + 1)), (item_group == ((u8) (*((u8 *) (((s8 *) other) + 1))))) != 0)))
  {
    switch ((s32) item_type)
    {
      case 0:
        item_type = 0x41;
        return compare_item_data_masked(item, other, 0x41);
      case 1:
        item_type = 1;
        return compare_item_data_masked(item, other, 1);
      case 2:
        item_type = 0;
        return compare_item_data_masked(item, other, 0);
      case 3:
        if (item_group == 2)
      {
        item_type = 0x41;
        return compare_item_data_masked(item, other, 0x41);
      }
        item_type = 1;
        return compare_item_data_masked(item, other, 1);
      case 4:
        item_type = 0;
        return compare_item_data_masked(item, other, 0);
    }
  }
  else
  {
    result = 0;
  }
  return 0;
}
s32 compare_item_data_masked(void *item, void *other, s32 mode) {
    u8 *a = (u8 *)item;
    u8 *b = (u8 *)other;
    s32 r;
    s32 m;
    s32 t;
    s32 m2;
    s32 t2;
    r = 0;
    if (a[0] == b[0] && a[1] == b[1]) {
        r = 1;
        if (mode & 7) {
            t = 0;
            if (mode & 1) {
                t = (u8)(a[2] == b[2]);
            }
            m = mode & 2;
            if (m != 0 && !(mode & 4)) {
                t |= a[2] < b[2];
            }
            if (m == 0 && (mode & 4)) {
                t |= a[2] > b[2];
            }
            if (m != 0 && (mode & 4)) {
                t |= (u8)(a[2] != b[2]);
            }
        } else {
            t = 1;
        }
        r &= t;
        if (mode & 0x38) {
            t2 = 0;
            if (mode & 8) {
                t2 = a[3] == b[3];
            }
            m2 = mode & 0x10;
            if (m2 != 0 && !(mode & 0x20)) {
                t2 |= a[3] < b[3];
            }
            if (m2 == 0 && (mode & 0x20)) {
                t2 |= a[3] > b[3];
            }
            if (m2 != 0 && (mode & 0x20)) {
                t2 |= (u8)(a[3] != b[3]);
            }
        } else {
            t2 = 1;
        }
        r &= t2;
        if (mode & 0x40) {
            t = a[4] == b[4];
        } else {
            t = 1;
        }
        r &= t;
    }
    return r;
}

// ---- TMainTask_80104C40.cpp

void TMainTask::cleanup_game_objects() {
    s32 floor;
    s32 main_phase;
    s32 area;

    TEnding__sub_8008C9F8();
    TItemLoad::create();
    TEquippedWeaponDrawTask::create(tl_particlemodel);
    TEquippedItemDrawTask::create(tl_item_equip);
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


s32 TItemData::is_item_usable(saddr player, u8 *item) {
    if (TItemData::is_wrapped(item) != 0) {
        return (u8)(1U);
    }
    if ((u8) *item == 3) {
        if (*(s32 *)((s8 *)(lookup_item_pmt_record(item)) + 0x10) & 1) {
            return (u8)(1U);
        }
        return (u8)((u8) (find_eligible_combination_recipe(player, item) != 0));
    }
    return (u8)((u8) (find_eligible_combination_recipe(player, item) != 0));
}
#define o ((TObjPlayer *)player)
saddr find_eligible_combination_recipe(saddr player, u8 *item) {
    TItemData d;
    TItemData d2;
    MagStats mag;
    s16 m;
    ItemCombination *rec;
    void *it;
    u8 v;
    rec = NULL;
    if (o != NULL && item != NULL) {
        it = find_unique_combination_target(o, (TItemData *)item);
        if (it != NULL) {
            d.init();
            ((TItem *)it)->copy_to_item_data(&d);
            rec = find_item_combination_recipe(item, it);
        } else {
            return 0;
        }
        if (rec->mag_level != 0xFF) {
            if (d.data1.data_u8[0] != 2) {
                return 0;
            }
            mag.init();
            TItemData::deserialize_mag(&d, &mag);
            m = rec->mag_level;
            if (mag.get_level() < m) {
                return 0;
            }
        }
        if (rec->grind != 0xFF) {
            if (d.data1.data_u8[0] != 0) {
                return 0;
            }
            if (d.data1.data_u8[3] < rec->grind) {
                return 0;
            }
        }
        v = rec->level;
        if (v != 0xFF) {
            if (o->get_actor_level_index() < v - 1) {
                return 0;
            }
        }
        v = rec->section_id;
        if (v != 0xFF) {
            if (v != o->get_section_id()) {
                return 0;
            }
        }
        d2.init();
        d2.data1.data_u8[0] = rec->result_item[0];
        d2.data1.data_u8[1] = rec->result_item[1];
        d2.data1.data_u8[2] = rec->result_item[2];
        if (check_equip_requirements(o, &d2, NULL) == 0) {
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
    { TItemWeapon::load_data, TItemWeapon::free },
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
    { handle_select_confirm, TLobby__sub_80104464 },
    { NULL, NULL },
};

struct Entry_8010567C { u16 a; u16 b; };

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
void send_6x60_standard_drop_item_request(Obj_80105538 *self);
}
extern "C" s32 is_script_controlled__10TObjPlayerFv(void *);
s32 check_equip_requirements(void *self, TItemData *item, s32 *out) {
  void *player_alias;
  s32 flags;
  PlayerRequirementStats st;
  u32 k;
  int meseta_limit;
  s32 r;
  void *player;
  if (((saddr) self == 0) || (item == 0))
  {
    if (out != 0)
    {
      *out |= 0x20;
    }
    return 0;
  }
  player = self;
  if ((((TObjChara *)player)->obj_isState3_324() != 0) || (is_script_controlled__10TObjPlayerFv(player_alias = player) != 0))
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
    switch (item->data1.data_u8[0])
    {
      case 0:
        k = 1;
        break;

      case 1:
        switch (item->data1.data_u8[1])
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
  switch (item->data1.data_u8[0])
  {
    case 0: {
      WeaponParams *weapon;
      if ((saddr) (weapon = (WeaponParams *) lookup_item_pmt_record((u8 *) item)) != 0)
    {
      if (check_class_equip_permission((TObjPlayer *) player, (s16) weapon->class_flags) == 0)
      {
        flags |= 1;
      }
      st.clear_fields();
      build_player_equipment_requirement_stats((TObjPlayer *) player_alias, &st);
      if (st.atp < weapon->atp_required)
      {
        flags |= 2;
      }
      if (st.ata < weapon->ata_required)
      {
        flags |= 4;
      }
      if (st.mst < weapon->mst_required)
      {
        flags |= 8;
      }
    }
    else
    {
      flags |= 0x20;
    }
      break;
    }

    case 1:
      if (item->data1.data_u8[1] != 3)
    {
      ArmorPmtEntry *armor;
      if ((saddr) (armor = (ArmorPmtEntry *) lookup_item_pmt_record((u8 *) item)) != 0)
      {
        if (check_class_equip_permission((TObjPlayer *) player_alias, (s16) armor->class_flags) == ((0, 0)))
        {
          flags |= 1;
        }
        r = ((TObjChara *) player_alias)->get_actor_level_index();
        if (r < armor->required_level)
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
      if (check_class_equip_permission((TObjPlayer *) player, 0xd7) != 0)
    {
      UnitPmtEntry *unit;
      if ((unit = (UnitPmtEntry *) lookup_item_pmt_record((u8 *) item)) != 0)
      {
        switch (unit->stat)
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

    case 2: {
      MagPmtRecord *mag;
      if ((mag = (MagPmtRecord *) lookup_item_pmt_record((u8 *) item)) != 0)
    {
      if (check_class_equip_permission((TObjPlayer *) player_alias, (s16) mag->class_flags) == 0)
      {
        flags |= 1;
      }
    }
    else
    {
      flags |= 0x20;
    }
      break;
    }

    case 3:
      switch (item->data1.data_u8[1])
    {
      case 2:
        r = item->data1.data_u8[4];
      {
        u8 lim = get_technique_learn_limit(*(u8 *)&((TObjPlayer *)player)->class_index, r);
        if ((lim == 0xff) || (lim < item->data1.data_u8[2]))
        {
          flags |= 1;
        }
      }
        break;

      case 8:
        if (check_class_equip_permission((TObjPlayer *) player, 0xd7) != 0)
      {
        flags |= 1;
      }
        break;

    }

      break;

    case 4:
      meseta_limit = 0xf423f;
      if (meseta_limit < item->data2.price)
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

u8 roll_weapon_special_channel15(u8 stars) { return roll_weapon_special_for_stars(stars); }

TItem *construct_item(TItemData *data) {
    TItemData *src = data;
    ItemCreateFunction fn;
    if (src != 0) {
        TItemData item = *src;
        item.decode_from_network();
        if (item.isValidGroundDrop() != 0) {
            if (src->data1.data_u8[0] < 5) {
                fn = item_create_fn_table[src->data1.data_u8[0]];
                if (fn != 0) {
                    observe_item_id(item.id);
                    return fn((u8 *)&item);
                }
            }
        }
    }
    return 0;
}

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
extern "C" {

// Clears a drop request's position. Dead-stripped from the game: only its 0.0f literal remains.
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
                    EnemyStateRecord e = enemy_state_records[self->f2c];
                    if (e.drop_id != 0xFFFF) {
                        G_StandardDropItemRequest_PC_V3_BB_6x60 pkt;
                        G_StandardDropItemRequest_DC_6x60 &drop = pkt.__base_G_StandardDropItemRequest_DC_6x60;
                        pkt.init();
                        drop.floor = get_current_floor();
                        drop.rt_index = self->f370;
                        drop.entity_index = self->f2c;
                        drop.pos.x = self->x;
                        drop.pos.z = self->z;
                        drop.room = self->f28;
                        pkt.effective_area = get_current_floor_area();
                        Vec v;
                        v.x = drop.pos.x;
                        v.y = 100.0f;
                        v.z = drop.pos.z;
                        if (csnVecterUnder(&v, 1) != 0) {
                            pkt.send();
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
                    packet.scale_z = scale.z;
                    packet.set_params[0] = set_params[0];
                    packet.set_params[1] = set_params[1];
                    packet.set_params[2] = set_params[2];
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
Item_801057A8 *spawn_dropped_item_from_msg(Msg_801057A8 *drop, s32 quiet) {
    Item_801057A8 *item;
    s8 me;
    s32 act;
    u8 ok;
    item = NULL;
    if (drop != NULL) {
        me = get_current_floor();
        act = is_local_player_off_current_floor();
        ok = 0;
        if (drop->client == me && act != 1) {
            ok = 1;
        }
        if (ok != 0) {
            item = (Item_801057A8 *)construct_item((TItemData *)drop->item);
            if (item != NULL) {
                item->x = drop->x;
                item->z = drop->z;
                item->area = drop->area;
                ((TItem *)item)->place_on_ground(drop->client, &item->x, 1);
            }
        }
        if (quiet == 0) {
            ((void (*)(s32, s32, u8 *, f32, f32))add_item_condition)(drop->client, drop->area, drop->item, drop->x, drop->z);
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

void fn_801058E8(TPlyCharData *chr) { chr->m_inventory.m_items[0].m_present[3] |= 1; }

s32 TObjPlayer::is_script_controlled() {
    return this->control_state == 6;
}

TItem *TObjPlayer::get_equipped_mag() { return (TItem *)get_slot_value(equipped_items.items, 1); }

TItem *TObjPlayer::get_equipped_shield() { return (TItem *)get_slot_value(equipped_items.items, 3); }
TItem *TObjPlayer::get_equipped_armor() { return (TItem *)get_slot_value(equipped_items.items, 2); }


}

MagStats *MagStats::init() { clear(); return this; }

void PlayerRequirementStats::clear_fields() {
    atp = dfp = mst = ata = evp = lck = 0;
    resist[0] = resist[1] = resist[2] = resist[3] = resist[4] = 0;
}

extern "C" {

s32 test_flags_any(s32 *, s32);

s32 TItemMenuCtrl::query_flag(s32 flag_bit) {
    if (TItemMenuCtrl::instance != NULL) {
        return test_flags_any(&TItemMenuCtrl::instance->menu_flags.bits, 1 << flag_bit);
    }
    return 0;
}

}

void G_StandardDropItemRequest_PC_V3_BB_6x60::send() {
    __base_G_StandardDropItemRequest_DC_6x60.bswap();
    send_subcommand_to_leader(this);
}

void G_StandardDropItemRequest_DC_6x60::bswap() {
    reinterpret_cast<G_ClientIDHeader *>(&header)->bswap();
    bswap_16(reinterpret_cast<u16 *>(&entity_index));
    bswap_16(reinterpret_cast<u16 *>(&room));
    bswap_16(reinterpret_cast<u16 *>(&ignore_def));
    bswap_32(reinterpret_cast<u32 *>(&pos.x));
    bswap_32(reinterpret_cast<u32 *>(&pos.z));
}

G_StandardDropItemRequest_PC_V3_BB_6x60 *G_StandardDropItemRequest_PC_V3_BB_6x60::init() {
    __base_G_StandardDropItemRequest_DC_6x60.init();
    __base_G_StandardDropItemRequest_DC_6x60.header.subcommand = 0x60;
    __base_G_StandardDropItemRequest_DC_6x60.header.size = 6;
    return this;
}

void G_StandardDropItemRequest_DC_6x60::init() {
    pos.z = 0.0f;
    pos.x = 0.0f;
    room = 0;
    ignore_def = 0;
    rt_index = 0;
    floor = 0;
    header.subcommand = 0x60;
    header.size = 5;
}

void G_SpecializableItemDropRequest_6xA2::send() {
    bswap();
    send_subcommand_to_leader(this);
}

void G_SpecializableItemDropRequest_6xA2::bswap() {
    __base_G_StandardDropItemRequest_PC_V3_BB_6x60.__base_G_StandardDropItemRequest_DC_6x60.bswap();
    bswap_32(reinterpret_cast<u32 *>(&scale_z));
    bswap_32(reinterpret_cast<u32 *>(&set_params[0]));
    bswap_32(reinterpret_cast<u32 *>(&set_params[1]));
    bswap_32(reinterpret_cast<u32 *>(&set_params[2]));
}

G_SpecializableItemDropRequest_6xA2 *G_SpecializableItemDropRequest_6xA2::init() {
    __base_G_StandardDropItemRequest_PC_V3_BB_6x60.init();
    G_UnusedHeader &header = __base_G_StandardDropItemRequest_PC_V3_BB_6x60.__base_G_StandardDropItemRequest_DC_6x60.header;
    header.subcommand = 0xA2;
    header.size = 0x0A;
    return this;
}

// ---- TItemDisconnectCtrl_80105BE8.cpp

void TItemDisconnectCtrl__sub_80105BE8(void) { lbl_805D54E0 = 0; }
