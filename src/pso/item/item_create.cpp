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
#include "pso/unk/text_8011A780.h"
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
#include "pso/unk/text_80125428.h"
#include "pso/unk/text_80126740.h"
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
#include "pso/unk/TLobby_80105A2C.h"
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

// ---- TLobby_80104374.cpp

extern "C" {
s32 get_item_icon_index();
void TLobby__sub_80104464(void);
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
// Tool item factories, indexed by the tool type byte (TLobby__sub_8010440C).
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

void normalize_drop_area(s32 *p);

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

void TLobby::forward_to_player(int id, void *item) {
    TObjPlayer *player;
    if (item != NULL) {
        player = get_player_by_client_id((u16)id);
        if ((player != NULL) && ((player->is_locally_controlled() == 1) || ((player->obj_isState3_324() == 1) && ((s32) local_client_id == (s32) designated_client_id)) || ((player->is_script_controlled() == 1) && ((s32) local_client_id == (s32) designated_client_id)))) {
            player->request_inventory_item((TItemData*)item);
            send_6x25_equip_item((TObjPlayer *)player, *(s32 *)((s8 *)item + 0xC), 0);
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
            item = player->get_equipped_item(slot + 5);
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

s32 get_game_play_mode();


}

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
#define o ((TObjPlayer *)arg0)
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
        it = find_unique_combination_target(o, (TItemData *)item);
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
            if (o->get_actor_level_index() < v - 1) {
                return 0;
            }
        }
        v = rec->bC;
        if (v != 0xFF) {
            if (v != o->get_section_id()) {
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
                    EnemyStateRecord e = enemy_state_records[self->f2c];
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
    bswap_32(reinterpret_cast<u32 *>(&scale_z));
    bswap_32(reinterpret_cast<u32 *>(&set_params[0]));
    bswap_32(reinterpret_cast<u32 *>(&set_params[1]));
    bswap_32(reinterpret_cast<u32 *>(&set_params[2]));
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
