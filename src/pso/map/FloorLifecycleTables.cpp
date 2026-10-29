#include "pso/map/FloorLifecycleTables.h"
#include "pso/quest/TQuestThread.h"
#include "pso/misc/TODoorLabo.h"
#include "pso/misc/TODragonflyCave01.h"
#include "pso/misc/TOKeyJungleMain.h"
#include "pso/object/TObjDoorJung.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/item/TObjContainerIdo.h"
#include "pso/item/TObjContainerJung.h"
#include "pso/item/TObjContainerJungEx.h"
#include "pso/misc/TBGLightningCtrl.h"
#include "pso/misc/TButterfly.h"
#include "pso/misc/TContainerAncient01.h"
#include "pso/misc/TContainerAncient01R.h"
#include "pso/misc/TKomorebi.h"
#include "pso/misc/TLanguage.h"
#include "pso/misc/TLazerFenceSw.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TMotorcycle.h"
#include "pso/misc/TOAirconCave01.h"
#include "pso/misc/TOAirconCave02.h"
#include "pso/misc/TOBarrierEnergy01.h"
#include "pso/misc/TOBind.h"
#include "pso/misc/TOBiwaMushi.h"
#include "pso/misc/TOBoss4.h"
#include "pso/misc/TOCakeshopCave01.h"
#include "pso/misc/TOCapsuleAncient01.h"
#include "pso/misc/TOCapsuleLabo.h"
#include "pso/misc/TOCapsuleMachine01.h"
#include "pso/misc/TOChatSensor.h"
#include "pso/misc/TOComputerMachine01.h"
#include "pso/misc/TODoorAncient01.h"
#include "pso/misc/TODoorAncient03.h"
#include "pso/misc/TODoorAncient04.h"
#include "pso/misc/TODoorAncient05.h"
#include "pso/misc/TODoorAncient06.h"
#include "pso/misc/TODoorAncient07.h"
#include "pso/misc/TODoorAncient08.h"
#include "pso/misc/TODoorAncient09.h"
#include "pso/misc/TODoorCave01.h"
#include "pso/misc/TODoorCave02.h"
#include "pso/misc/TODoorCave03.h"
#include "pso/misc/TODoorJungleMain.h"
#include "pso/misc/TODoorMachine01.h"
#include "pso/misc/TODoorMachine02.h"
#include "pso/misc/TODoorVS2Door01.h"
#include "pso/misc/TODoorVoShip.h"
#include "pso/misc/TODragonflyMachine01.h"
#include "pso/misc/TOExplosiveMachine.h"
#include "pso/misc/TOFenceAncient01.h"
#include "pso/misc/TOFenceAncient02.h"
#include "pso/misc/TOFenceAncient03.h"
#include "pso/misc/TOFenceAncient04.h"
#include "pso/misc/TOGrassJungle.h"
#include "pso/misc/TOHangceilingCave01.h"
#include "pso/misc/TOHangerMachine01.h"
#include "pso/misc/TOHealGeneral.h"
#include "pso/misc/TOKeyAncient01.h"
#include "pso/misc/TOKeyAncient02.h"
#include "pso/misc/TOKeyAncient03.h"
#include "pso/misc/TOKeyCave01.h"
#include "pso/misc/TOKeyGenericSw.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TOKurage.h"
#include "pso/misc/TOLightMachine01.h"
#include "pso/misc/TOMekaFish00.h"
#include "pso/misc/TOMekaFish01.h"
#include "pso/misc/TOMine.h"
#include "pso/misc/TOMonitorMachine01.h"
#include "pso/misc/TOMonumentAncient01.h"
#include "pso/misc/TOMonumentAncient02.h"
#include "pso/misc/TORainbowCave01.h"
#include "pso/misc/TORevlightCave01.h"
#include "pso/misc/TORockCave.h"
#include "pso/misc/TORockJungleS01.h"
#include "pso/misc/TOSensorAncient01.h"
#include "pso/misc/TOSensorGeneral01.h"
#include "pso/misc/TOSignCave01.h"
#include "pso/misc/TOSignCave02.h"
#include "pso/misc/TOSignCave03.h"
#include "pso/misc/TOSparkMachine01.h"
#include "pso/misc/TOSymbolchatColli.h"
#include "pso/misc/TOTrapAncient01.h"
#include "pso/misc/TOTrapAncient02.h"
#include "pso/misc/TOTrapSeabed01.h"
#include "pso/misc/TOVS2Wall01.h"
#include "pso/misc/TOWreckAncient.h"
#include "pso/misc/TShopGenerator.h"
#include "pso/object/TObjBigTuitate.h"
#include "pso/object/TObjButterflyLobby.h"
#include "pso/object/TObjCamera.h"
#include "pso/object/TObjComputer.h"
#include "pso/object/TObjCurtainLobby.h"
#include "pso/object/TObjDoaEx01.h"
#include "pso/object/TObjDoor.h"
#include "pso/object/TObjDoorKey.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjGbAdvance.h"
#include "pso/object/TObjGoalWarpAncient.h"
#include "pso/object/TObjHashi.h"
#include "pso/object/TObjHashiVersus1.h"
#include "pso/object/TObjHashiVersus2.h"
#include "pso/object/TObjKabochaLobby.h"
#include "pso/object/TObjLaboMapWarp.h"
#include "pso/object/TObjLazerFenceNorm.h"
#include "pso/object/TObjLobbyMain.h"
#include "pso/object/TObjMapWarpAncient.h"
#include "pso/object/TObjRainbowLobby.h"
#include "pso/object/TObjSeabedSuisoBrakable.h"
#include "pso/object/TObjStendGlassLobby.h"
#include "pso/object/TObjParticleLobby.h"
#include "pso/object/TObjSuisouLobby.h"
#include "pso/object/TObjTank.h"
#include "pso/object/TObjTreeLobby.h"
#include "pso/object/TObjWarpBase.h"
#include "pso/object/TObjWarpLobby.h"
#include "pso/object/TObjWeddingLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdMultiSaveGC.h"

extern "C" {
void TMainCursor__sub_80154090();
void TMainCursor__sub_80154094();
void fn_8015C5F8();
void TODummyKeyCave01__sub_80165E88();
void TODummyKeyCave01__sub_80165E8C();
void TOSwitchAttack__sub_80177C20();
void TOSwitchAttack__sub_80177C24();
void TOSwitchItem__sub_80178080();
void TOSwitchItem__sub_80178084();
void TOSwitchTimer__sub_80178584();
void TOSwitchTimer__sub_80178588();
void fn_8017F45C();
void TContainerAncient01R__sub_8018AF74();
void TObjDoorJung__sub_8018F4AC();
void TLazerFenceSw__sub_80193C5C();
void fn_8019AD50();
void fn_8019B09C();
void fn_8019B0D4();
void TObjFish__sub_8019F72C();
void TObjWarpLobby__sub_801A0B38();
void TLanguage__sub_8029FF0C();
void TLanguage__sub_802A0204();
void TObjPlayer__sub_802C2900();
void fn_802C99D8();
void fn_8030B7B4();
void fn_8030B7B8();
void fn_803516F8();
void fn_803653A4();
}
void load_forest_box_resources();
void load_chat_sensor();
void load_turiten_singo_resources();
void load_city_common_resources();
void load_computer_resources();
void load_lazer_fence_norm_resources();
void load_forest_warp_resources();
void free_warp_jung_beam_resources();
void load_warp_beam_resources();
void load_green_door_resources();
void load_labo_door_resources();
void load_bg_lightning();
void free_object_table();
FloorLifecycleEntry floor_lifecycle_callbacks_floor_00[12] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TObjFish::load_models, TObjFish__sub_8019F72C },
    { TShopGenerator::run_fn_table_forward, TShopGenerator::run_fn_table_reverse },
    { TMainCursor__sub_80154094, TMainCursor__sub_80154090 },
    { load_city_common_resources, TLobby::free_map_resources },
    { TOSwitchItem__sub_80178084, TOSwitchItem__sub_80178080 },
    { TOSymbolchatColli::load_symbol_chat_data, TOSymbolchatColli::free_rock },
    { TOSwitchTimer__sub_80178588, TOSwitchTimer__sub_80178584 },
    { load_chat_sensor, TOChatSensor::destroy_global },
    { TObjGbAdvance::load_resource_instance, TObjGbAdvance::free_shared_data },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_01[30] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TObjDoor::load_resources, TObjDoor::free_resources },
    { TKomorebi::load_resources, TKomorebi::free_static },
    { fn_8017F45C, TButterfly::destroy_instance },
    { TObjDoorKey::load_resources, TObjDoorKey::free_key },
    { TMotorcycle::load_resources, TMotorcycle::free_statics },
    { load_forest_box_resources, TLobby::free_char_select_resources },
    { TLobby::load_console_resources, TLobby::free_chr_select_slot },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { TObjTank::load_globals, TObjTank::free_globals },
    { load_computer_resources, TObjComputer::free_resources },
    { TObjContainerIdo::load_resources, TObjContainerIdo::free_resources },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TOCapsuleAncient01::load_resource_instance, TOCapsuleAncient01::destroy_static_instance },
    { TOBarrierEnergy01::load_resources, TOBarrierEnergy01::free_resources },
    { TObjHashi::load_shared_resource, TObjHashi::unload_static_data },
    { TOKeyGenericSw::load_resources, TOKeyGenericSw::free_shared_resources },
    { TOMine::load_static_resource, TOMine::free_instance },
    { TMainCursor__sub_80154094, TMainCursor__sub_80154090 },
    { TOSensorGeneral01::load_assets, TOSensorGeneral01::free_rocks },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TOSwitchItem__sub_80178084, TOSwitchItem__sub_80178080 },
    { TOSymbolchatColli::load_symbol_chat_data, TOSymbolchatColli::free_rock },
    { TOSwitchAttack__sub_80177C24, TOSwitchAttack__sub_80177C20 },
    { TOKeyMachine01::load_assets, TOKeyMachine01::free_statics },
    { TODummyKeyCave01__sub_80165E8C, TODummyKeyCave01__sub_80165E88 },
    { TOSwitchTimer__sub_80178588, TOSwitchTimer__sub_80178584 },
    { load_chat_sensor, TOChatSensor::destroy_global },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_02[32] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TObjDoor::load_resources, TObjDoor::free_resources },
    { TKomorebi::load_resources, TKomorebi::free_static },
    { fn_8017F45C, TButterfly::destroy_instance },
    { TObjDoorKey::load_resources, TObjDoorKey::free_key },
    { TMotorcycle::load_resources, TMotorcycle::free_statics },
    { load_forest_box_resources, TLobby::free_char_select_resources },
    { TLobby::load_console_resources, TLobby::free_chr_select_slot },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { TObjTank::load_globals, TObjTank::free_globals },
    { load_computer_resources, TObjComputer::free_resources },
    { TObjContainerIdo::load_resources, TObjContainerIdo::free_resources },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TOCapsuleAncient01::load_resource_instance, TOCapsuleAncient01::destroy_static_instance },
    { TOBarrierEnergy01::load_resources, TOBarrierEnergy01::free_resources },
    { TObjHashi::load_shared_resource, TObjHashi::unload_static_data },
    { TOKeyGenericSw::load_resources, TOKeyGenericSw::free_shared_resources },
    { TOMine::load_static_resource, TOMine::free_instance },
    { TMainCursor__sub_80154094, TMainCursor__sub_80154090 },
    { TOSensorGeneral01::load_assets, TOSensorGeneral01::free_rocks },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TOMonumentAncient02::load_resources, TOMonumentAncient02::free_shared_data },
    { TObjFish::load_models, TObjFish__sub_8019F72C },
    { TOSwitchItem__sub_80178084, TOSwitchItem__sub_80178080 },
    { TOSymbolchatColli::load_symbol_chat_data, TOSymbolchatColli::free_rock },
    { TOSwitchAttack__sub_80177C24, TOSwitchAttack__sub_80177C20 },
    { TOKeyMachine01::load_assets, TOKeyMachine01::free_statics },
    { TODummyKeyCave01__sub_80165E8C, TODummyKeyCave01__sub_80165E88 },
    { TOSwitchTimer__sub_80178588, TOSwitchTimer__sub_80178584 },
    { load_chat_sensor, TOChatSensor::destroy_global },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_03[27] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TOCapsuleAncient01::load_resource_instance, TOCapsuleAncient01::destroy_static_instance },
    { TOMine::load_static_resource, TOMine::free_instance },
    { TObjDoorKey::load_resources, TObjDoorKey::free_key },
    { TOKeyCave01::load_resources, TOKeyCave01::free_objects },
    { TODoorCave01::load_resources, TODoorCave01::destroy },
    { TODoorCave02::load_resources, TODoorCave02::destroy },
    { TODoorCave03::load_resources, TODoorCave03::free_shared_data },
    { load_turiten_singo_resources, TOHangceilingCave01::destroy_instance },
    { TORockCave::load_resources, TORockCave::free_instances },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { load_forest_box_resources, TLobby::free_char_select_resources },
    { TLobby::load_console_resources, TLobby::free_chr_select_slot },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TMainCursor__sub_80154094, TMainCursor__sub_80154090 },
    { TOBind::load_static_resource, TOBind::free_static_model },
    { TOSwitchItem__sub_80178084, TOSwitchItem__sub_80178080 },
    { TOSymbolchatColli::load_symbol_chat_data, TOSymbolchatColli::free_rock },
    { TObjContainerIdo::load_resources, TObjContainerIdo::free_resources },
    { TODummyKeyCave01__sub_80165E8C, TODummyKeyCave01__sub_80165E88 },
    { TOSwitchAttack__sub_80177C24, TOSwitchAttack__sub_80177C20 },
    { load_computer_resources, TObjComputer::free_resources },
    { TOSwitchTimer__sub_80178588, TOSwitchTimer__sub_80178584 },
    { load_chat_sensor, TOChatSensor::destroy_global },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_04[38] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TOCapsuleAncient01::load_resource_instance, TOCapsuleAncient01::destroy_static_instance },
    { TOBarrierEnergy01::load_resources, TOBarrierEnergy01::free_resources },
    { TOMine::load_static_resource, TOMine::free_instance },
    { TOSensorGeneral01::load_assets, TOSensorGeneral01::free_rocks },
    { TObjDoorKey::load_resources, TObjDoorKey::free_key },
    { TOKeyCave01::load_resources, TOKeyCave01::free_objects },
    { TODoorCave01::load_resources, TODoorCave01::destroy },
    { TODoorCave02::load_resources, TODoorCave02::destroy },
    { TODoorCave03::load_resources, TODoorCave03::free_shared_data },
    { load_turiten_singo_resources, TOHangceilingCave01::destroy_instance },
    { TOSignCave01::load_shared_resource, TOSignCave01::unload_static_data },
    { TOSignCave02::load_shared_resource, TOSignCave02::free_static_model },
    { TOSignCave03::load_shared_resource, TOSignCave03::close_dialog_window },
    { TOAirconCave01::load_shared_resource, TOAirconCave01::release_static_resource },
    { TOAirconCave02::load_shared_resource, TOAirconCave02::release_static_resource },
    { TORevlightCave01::load_shared_resource, TORevlightCave01::release_static_instance },
    { TORainbowCave01::load_resource_instance, TORainbowCave01::free_static_data },
    { TOKurage::load_static_resource, TOKurage::destroy_static_instance },
    { TODragonflyCave01::load_resources, TODragonflyCave01::release_static_instance },
    { TORockCave::load_resources, TORockCave::free_instances },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { load_forest_box_resources, TLobby::free_char_select_resources },
    { TLobby::load_console_resources, TLobby::free_chr_select_slot },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TOMonumentAncient02::load_resources, TOMonumentAncient02::free_shared_data },
    { TMainCursor__sub_80154094, TMainCursor__sub_80154090 },
    { TOBind::load_static_resource, TOBind::free_static_model },
    { TODummyKeyCave01__sub_80165E8C, TODummyKeyCave01__sub_80165E88 },
    { TOSwitchItem__sub_80178084, TOSwitchItem__sub_80178080 },
    { TOSymbolchatColli::load_symbol_chat_data, TOSymbolchatColli::free_rock },
    { TOSwitchAttack__sub_80177C24, TOSwitchAttack__sub_80177C20 },
    { load_computer_resources, TObjComputer::free_resources },
    { TOSwitchTimer__sub_80178588, TOSwitchTimer__sub_80178584 },
    { load_chat_sensor, TOChatSensor::destroy_global },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_05[36] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TOCapsuleAncient01::load_resource_instance, TOCapsuleAncient01::destroy_static_instance },
    { TOBarrierEnergy01::load_resources, TOBarrierEnergy01::free_resources },
    { TOMine::load_static_resource, TOMine::free_instance },
    { TOSensorGeneral01::load_assets, TOSensorGeneral01::free_rocks },
    { TObjDoorKey::load_resources, TObjDoorKey::free_key },
    { TOKeyCave01::load_resources, TOKeyCave01::free_objects },
    { TODoorCave01::load_resources, TODoorCave01::destroy },
    { TODoorCave02::load_resources, TODoorCave02::destroy },
    { TODoorCave03::load_resources, TODoorCave03::free_shared_data },
    { load_turiten_singo_resources, TOHangceilingCave01::destroy_instance },
    { TOSignCave01::load_shared_resource, TOSignCave01::unload_static_data },
    { TOSignCave02::load_shared_resource, TOSignCave02::free_static_model },
    { TOSignCave03::load_shared_resource, TOSignCave03::close_dialog_window },
    { TOAirconCave01::load_shared_resource, TOAirconCave01::release_static_resource },
    { TOAirconCave02::load_shared_resource, TOAirconCave02::release_static_resource },
    { TORevlightCave01::load_shared_resource, TORevlightCave01::release_static_instance },
    { TOCakeshopCave01::load_shared_resource, TOCakeshopCave01::release_static_resource },
    { TORockCave::load_resources, TORockCave::free_instances },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { load_forest_box_resources, TLobby::free_char_select_resources },
    { TLobby::load_console_resources, TLobby::free_chr_select_slot },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TMainCursor__sub_80154094, TMainCursor__sub_80154090 },
    { TOBind::load_static_resource, TOBind::free_static_model },
    { TObjFish::load_models, TObjFish__sub_8019F72C },
    { TODummyKeyCave01__sub_80165E8C, TODummyKeyCave01__sub_80165E88 },
    { TOSwitchItem__sub_80178084, TOSwitchItem__sub_80178080 },
    { TOSymbolchatColli::load_symbol_chat_data, TOSymbolchatColli::free_rock },
    { TOSwitchAttack__sub_80177C24, TOSwitchAttack__sub_80177C20 },
    { load_computer_resources, TObjComputer::free_resources },
    { TOSwitchTimer__sub_80178588, TOSwitchTimer__sub_80178584 },
    { load_chat_sensor, TOChatSensor::destroy_global },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_06[34] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TOKeyGenericSw::load_resources, TOKeyGenericSw::free_shared_resources },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TOCapsuleAncient01::load_resource_instance, TOCapsuleAncient01::destroy_static_instance },
    { TOBarrierEnergy01::load_resources, TOBarrierEnergy01::free_resources },
    { TOMine::load_static_resource, TOMine::free_instance },
    { TMainCursor__sub_80154094, TMainCursor__sub_80154090 },
    { TOSensorGeneral01::load_assets, TOSensorGeneral01::free_rocks },
    { load_forest_box_resources, TLobby::free_char_select_resources },
    { TLobby::load_console_resources, TLobby::free_chr_select_slot },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TODoorMachine01::load_resources, TODoorMachine01::free_resources },
    { TODoorMachine02::load_resources, TODoorMachine02::free_statics },
    { TOKeyMachine01::load_assets, TOKeyMachine01::free_statics },
    { TOBind::load_static_resource, TOBind::free_static_model },
    { TOCapsuleMachine01::alloc_and_load_resource, TOCapsuleMachine01::reset_static_state },
    { TOComputerMachine01::load_model_resource, TOComputerMachine01::reset_state },
    { TOMonitorMachine01::load_resources, TOMonitorMachine01::reset_static_state },
    { TODragonflyMachine01::load_resources, TODragonflyMachine01::unload_static_data },
    { TOLightMachine01::load_assets, TOLightMachine01::destroy_instance },
    { TOExplosiveMachine::load_shared_resource, TOExplosiveMachine::destroy_static_lobby },
    { TOSparkMachine01::load_static_resource, TOSparkMachine01::destroy_static_instance },
    { TOHangerMachine01::load_shared_resource, TOHangerMachine01::free_static_model },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { TOSwitchItem__sub_80178084, TOSwitchItem__sub_80178080 },
    { TOSymbolchatColli::load_symbol_chat_data, TOSymbolchatColli::free_rock },
    { TODummyKeyCave01__sub_80165E8C, TODummyKeyCave01__sub_80165E88 },
    { TOSwitchAttack__sub_80177C24, TOSwitchAttack__sub_80177C20 },
    { load_computer_resources, TObjComputer::free_resources },
    { TOSwitchTimer__sub_80178588, TOSwitchTimer__sub_80178584 },
    { load_chat_sensor, TOChatSensor::destroy_global },
    { TOTrapAncient02::load_resources, TOTrapAncient02::destroy_instance },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_07[36] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TOKeyGenericSw::load_resources, TOKeyGenericSw::free_shared_resources },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TOCapsuleAncient01::load_resource_instance, TOCapsuleAncient01::destroy_static_instance },
    { TOBarrierEnergy01::load_resources, TOBarrierEnergy01::free_resources },
    { TOMine::load_static_resource, TOMine::free_instance },
    { TMainCursor__sub_80154094, TMainCursor__sub_80154090 },
    { TOSensorGeneral01::load_assets, TOSensorGeneral01::free_rocks },
    { load_forest_box_resources, TLobby::free_char_select_resources },
    { TLobby::load_console_resources, TLobby::free_chr_select_slot },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TODoorMachine01::load_resources, TODoorMachine01::free_resources },
    { TODoorMachine02::load_resources, TODoorMachine02::free_statics },
    { TOKeyMachine01::load_assets, TOKeyMachine01::free_statics },
    { TOBind::load_static_resource, TOBind::free_static_model },
    { TOCapsuleMachine01::alloc_and_load_resource, TOCapsuleMachine01::reset_static_state },
    { TOComputerMachine01::load_model_resource, TOComputerMachine01::reset_state },
    { TOMonitorMachine01::load_resources, TOMonitorMachine01::reset_static_state },
    { TODragonflyMachine01::load_resources, TODragonflyMachine01::unload_static_data },
    { TOLightMachine01::load_assets, TOLightMachine01::destroy_instance },
    { TOExplosiveMachine::load_shared_resource, TOExplosiveMachine::destroy_static_lobby },
    { TOSparkMachine01::load_static_resource, TOSparkMachine01::destroy_static_instance },
    { TOHangerMachine01::load_shared_resource, TOHangerMachine01::free_static_model },
    { TOMonumentAncient02::load_resources, TOMonumentAncient02::free_shared_data },
    { TObjFish::load_models, TObjFish__sub_8019F72C },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { TOSwitchItem__sub_80178084, TOSwitchItem__sub_80178080 },
    { TOSymbolchatColli::load_symbol_chat_data, TOSymbolchatColli::free_rock },
    { TODummyKeyCave01__sub_80165E8C, TODummyKeyCave01__sub_80165E88 },
    { TOSwitchAttack__sub_80177C24, TOSwitchAttack__sub_80177C20 },
    { load_computer_resources, TObjComputer::free_resources },
    { TOSwitchTimer__sub_80178588, TOSwitchTimer__sub_80178584 },
    { load_chat_sensor, TOChatSensor::destroy_global },
    { TOTrapAncient02::load_resources, TOTrapAncient02::destroy_instance },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_08[34] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TOCapsuleAncient01::load_resource_instance, TOCapsuleAncient01::destroy_static_instance },
    { TOMine::load_static_resource, TOMine::free_instance },
    { TOSensorAncient01::load_resources, TOSensorAncient01::destroy },
    { TObjGoalWarpAncient::load_resources, TObjMapWarpAncient::free_globals },
    { TOKeyAncient01::load_resources, TOKeyAncient01::free_shared_resources },
    { TOKeyAncient03::load_resources, TOKeyAncient03::cleanup_refs },
    { TODoorAncient01::load_resources, TODoorAncient01::free_resources },
    { TODoorAncient05::load_resources, TODoorAncient05::free_resources },
    { TODoorAncient08::load_resources, TODoorAncient08::destroy },
    { TODoorAncient09::load_resources, TODoorAncient09::destroy },
    { TOKeyAncient02::load_resources, TOKeyAncient02::free_static },
    { TOFenceAncient01::load_resources, TOFenceAncient01::free_resources },
    { TOFenceAncient02::load_assets, TOFenceAncient02::free_resources },
    { TOFenceAncient03::load_resources, TOFenceAncient03::free_shared_resources },
    { TOFenceAncient04::load_resources, TOFenceAncient04::destroy },
    { TContainerAncient01::load_resources, TContainerAncient01::release_static_resource },
    { TContainerAncient01R::init_table_entries, TContainerAncient01R__sub_8018AF74 },
    { TOTrapAncient01::load_resources, TOTrapAncient01::release_static_resource },
    { TOTrapAncient02::load_resources, TOTrapAncient02::destroy_instance },
    { TOMonumentAncient01::load_resource_instance, TOMonumentAncient01::release_static_resource },
    { TOWreckAncient::load_resources, TOWreckAncient::free_statics },
    { TLanguage::load_container_fragment_textures, fn_8015C5F8 },
    { TMainCursor__sub_80154094, TMainCursor__sub_80154090 },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TOSwitchItem__sub_80178084, TOSwitchItem__sub_80178080 },
    { TOSymbolchatColli::load_symbol_chat_data, TOSymbolchatColli::free_rock },
    { TODummyKeyCave01__sub_80165E8C, TODummyKeyCave01__sub_80165E88 },
    { TOSwitchAttack__sub_80177C24, TOSwitchAttack__sub_80177C20 },
    { load_computer_resources, TObjComputer::free_resources },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TOSwitchTimer__sub_80178588, TOSwitchTimer__sub_80178584 },
    { load_chat_sensor, TOChatSensor::destroy_global },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_09[34] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TOCapsuleAncient01::load_resource_instance, TOCapsuleAncient01::destroy_static_instance },
    { TOMine::load_static_resource, TOMine::free_instance },
    { TOSensorAncient01::load_resources, TOSensorAncient01::destroy },
    { TObjGoalWarpAncient::load_resources, TObjMapWarpAncient::free_globals },
    { TOKeyAncient01::load_resources, TOKeyAncient01::free_shared_resources },
    { TOKeyAncient03::load_resources, TOKeyAncient03::cleanup_refs },
    { TODoorAncient04::load_resources, TODoorAncient04::free_resources },
    { TODoorAncient06::load_resources, TODoorAncient06::destroy },
    { TODoorAncient08::load_resources, TODoorAncient08::destroy },
    { TODoorAncient09::load_resources, TODoorAncient09::destroy },
    { TOKeyAncient02::load_resources, TOKeyAncient02::free_static },
    { TOFenceAncient01::load_resources, TOFenceAncient01::free_resources },
    { TOFenceAncient02::load_assets, TOFenceAncient02::free_resources },
    { TOFenceAncient03::load_resources, TOFenceAncient03::free_shared_resources },
    { TOFenceAncient04::load_resources, TOFenceAncient04::destroy },
    { TContainerAncient01::load_resources, TContainerAncient01::release_static_resource },
    { TContainerAncient01R::init_table_entries, TContainerAncient01R__sub_8018AF74 },
    { TOTrapAncient01::load_resources, TOTrapAncient01::release_static_resource },
    { TOTrapAncient02::load_resources, TOTrapAncient02::destroy_instance },
    { TOMonumentAncient01::load_resource_instance, TOMonumentAncient01::release_static_resource },
    { TOWreckAncient::load_resources, TOWreckAncient::free_statics },
    { TLanguage::load_container_fragment_textures, fn_8015C5F8 },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TMainCursor__sub_80154094, TMainCursor__sub_80154090 },
    { TOSwitchItem__sub_80178084, TOSwitchItem__sub_80178080 },
    { TOSymbolchatColli::load_symbol_chat_data, TOSymbolchatColli::free_rock },
    { TODummyKeyCave01__sub_80165E8C, TODummyKeyCave01__sub_80165E88 },
    { TOSwitchAttack__sub_80177C24, TOSwitchAttack__sub_80177C20 },
    { load_computer_resources, TObjComputer::free_resources },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TOSwitchTimer__sub_80178588, TOSwitchTimer__sub_80178584 },
    { load_chat_sensor, TOChatSensor::destroy_global },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_10[35] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TOCapsuleAncient01::load_resource_instance, TOCapsuleAncient01::destroy_static_instance },
    { TOMine::load_static_resource, TOMine::free_instance },
    { TOSensorAncient01::load_resources, TOSensorAncient01::destroy },
    { TObjGoalWarpAncient::load_resources, TObjMapWarpAncient::free_globals },
    { TOKeyAncient01::load_resources, TOKeyAncient01::free_shared_resources },
    { TOKeyAncient03::load_resources, TOKeyAncient03::cleanup_refs },
    { TODoorAncient03::load_resources, TODoorAncient03::free_resources },
    { TODoorAncient07::load_resources, TODoorAncient07::destroy },
    { TODoorAncient08::load_resources, TODoorAncient08::destroy },
    { TODoorAncient09::load_resources, TODoorAncient09::destroy },
    { TOKeyAncient02::load_resources, TOKeyAncient02::free_static },
    { TOFenceAncient01::load_resources, TOFenceAncient01::free_resources },
    { TOFenceAncient02::load_assets, TOFenceAncient02::free_resources },
    { TOFenceAncient03::load_resources, TOFenceAncient03::free_shared_resources },
    { TOFenceAncient04::load_resources, TOFenceAncient04::destroy },
    { TContainerAncient01::load_resources, TContainerAncient01::release_static_resource },
    { TContainerAncient01R::init_table_entries, TContainerAncient01R__sub_8018AF74 },
    { TOTrapAncient01::load_resources, TOTrapAncient01::release_static_resource },
    { TOTrapAncient02::load_resources, TOTrapAncient02::destroy_instance },
    { TOMonumentAncient01::load_resource_instance, TOMonumentAncient01::release_static_resource },
    { TOWreckAncient::load_resources, TOWreckAncient::free_statics },
    { load_computer_resources, TObjComputer::free_resources },
    { TLanguage::load_container_fragment_textures, fn_8015C5F8 },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TMainCursor__sub_80154094, TMainCursor__sub_80154090 },
    { TObjFish::load_models, TObjFish__sub_8019F72C },
    { TOSwitchItem__sub_80178084, TOSwitchItem__sub_80178080 },
    { TOSymbolchatColli::load_symbol_chat_data, TOSymbolchatColli::free_rock },
    { TODummyKeyCave01__sub_80165E8C, TODummyKeyCave01__sub_80165E88 },
    { TOSwitchAttack__sub_80177C24, TOSwitchAttack__sub_80177C20 },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TOSwitchTimer__sub_80178588, TOSwitchTimer__sub_80178584 },
    { load_chat_sensor, TOChatSensor::destroy_global },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floors_11_12[5] = {
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TMainCursor__sub_80154094, TMainCursor__sub_80154090 },
    { TLobby::load_console_resources, TLobby::free_chr_select_slot },
    { load_forest_box_resources, TLobby::free_char_select_resources },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_13[8] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TOCapsuleAncient01::load_resource_instance, TOCapsuleAncient01::destroy_static_instance },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TMainCursor__sub_80154094, TMainCursor__sub_80154090 },
    { TODoorVoShip::load_shared_resource, TODoorVoShip::free_static_data },
    { TLobby::load_console_resources, TLobby::free_chr_select_slot },
    { load_forest_box_resources, TLobby::free_char_select_resources },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_14[6] = {
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TMainCursor__sub_80154094, TMainCursor__sub_80154090 },
    { TOBoss4::load_static_resource, TOBoss4::free_instance },
    { TLobby::load_console_resources, TLobby::free_chr_select_slot },
    { load_forest_box_resources, TLobby::free_char_select_resources },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_15[14] = {
    { TObjWarpLobby__sub_801A0B38, TObjWarpLobby::release_static },
    { TObjLobbyMain::load_resources, TObjLobbyMain::free_resources },
    { TObjFish::load_area_resource, TObjFish::free_resource },
    { TObjPlayer::load_lobby_pigeon_resource, TObjPlayer::free_static_instance },
    { fn_803516F8, TObjButterflyLobby::destroy_instance },
    { TObjRainbowLobby::load_resources, TObjRainbowLobby::free_resources },
    { TObjKabochaLobby::load_resources, TObjKabochaLobby::free_resources },
    { TObjStendGlassLobby::load_resources, TObjStendGlassLobby::free_resources },
    { TObjCurtainLobby::load_resources, TObjCurtainLobby::free_resources },
    { TObjWeddingLobby::load_resources, TObjWeddingLobby::free_resources },
    { TObjTreeLobby::load_resources, TObjTreeLobby::free_resources },
    { TObjSuisouLobby::load_resources, TObjSuisouLobby::free_resources },
    { TObjParticleLobby::load_resources, TObjParticleLobby::free_resources },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_16[24] = {
    { TOMine::load_static_resource, TOMine::free_instance },
    { TOBoss4::load_static_resource, TOBoss4::free_instance },
    { TObjCamera::load_shared_resource, TObjCamera::release_static_resource },
    { fn_8019B0D4, fn_8019B09C },
    { fn_8019AD50, TObjBigTuitate::free_instance },
    { TObjDoaEx01::load_resources, TObjDoaEx01::free_resource },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { TLanguage::load_container_fragment_textures, fn_8015C5F8 },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TOKeyGenericSw::load_resources, TOKeyGenericSw::free_shared_resources },
    { TOKeyCave01::load_resources, TOKeyCave01::free_objects },
    { TOKeyMachine01::load_assets, TOKeyMachine01::free_statics },
    { TODragonflyCave01::load_resources, TODragonflyCave01::release_static_instance },
    { TOSwitchItem__sub_80178084, TOSwitchItem__sub_80178080 },
    { TOSymbolchatColli::load_symbol_chat_data, TOSymbolchatColli::free_rock },
    { TODummyKeyCave01__sub_80165E8C, TODummyKeyCave01__sub_80165E88 },
    { TOSwitchAttack__sub_80177C24, TOSwitchAttack__sub_80177C20 },
    { load_computer_resources, TObjComputer::free_resources },
    { TOSwitchTimer__sub_80178588, TOSwitchTimer__sub_80178584 },
    { load_chat_sensor, TOChatSensor::destroy_global },
    { TODoorVS2Door01::load_resources, TODoorVS2Door01::free_resources },
    { TOVS2Wall01::load_resources, TOVS2Wall01::release_model },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_17[20] = {
    { TOMine::load_static_resource, TOMine::free_instance },
    { TODoorVS2Door01::load_resources, TODoorVS2Door01::free_resources },
    { TOVS2Wall01::load_resources, TOVS2Wall01::release_model },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { TLanguage::load_container_fragment_textures, fn_8015C5F8 },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TOKeyGenericSw::load_resources, TOKeyGenericSw::free_shared_resources },
    { TOKeyCave01::load_resources, TOKeyCave01::free_objects },
    { TOKeyMachine01::load_assets, TOKeyMachine01::free_statics },
    { TObjHashiVersus1::load_shared_resource, TObjHashiVersus1::unload_static_data },
    { TObjHashiVersus2::load_shared_resource, TObjHashiVersus2::unload_static_data },
    { TOSwitchItem__sub_80178084, TOSwitchItem__sub_80178080 },
    { TOSymbolchatColli::load_symbol_chat_data, TOSymbolchatColli::free_rock },
    { TODummyKeyCave01__sub_80165E8C, TODummyKeyCave01__sub_80165E88 },
    { TOSwitchAttack__sub_80177C24, TOSwitchAttack__sub_80177C20 },
    { load_computer_resources, TObjComputer::free_resources },
    { TOSwitchTimer__sub_80178588, TOSwitchTimer__sub_80178584 },
    { load_chat_sensor, TOChatSensor::destroy_global },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_18[16] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TObjFish::load_models, TObjFish__sub_8019F72C },
    { TShopGenerator::run_fn_table_forward, TShopGenerator::run_fn_table_reverse },
    { TMainCursor__sub_80154094, TMainCursor__sub_80154090 },
    { load_city_common_resources, TLobby::free_map_resources },
    { TOSwitchItem__sub_80178084, TOSwitchItem__sub_80178080 },
    { TOSymbolchatColli::load_symbol_chat_data, TOSymbolchatColli::free_rock },
    { TOSwitchTimer__sub_80178588, TOSwitchTimer__sub_80178584 },
    { load_chat_sensor, TOChatSensor::destroy_global },
    { load_labo_door_resources, TAdSinglePlyChrSelectGC::free_all_resources },
    { fn_803653A4, free_object_table },
    { TObjGbAdvance::load_resource_instance, TObjGbAdvance::free_shared_data },
    { TODoorLabo::load_resources, TODoorLabo::free_resources },
    { TObjLaboMapWarp::load_static_resource, TObjLaboMapWarp::release_static_resource },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floors_21_22[29] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TObjFish::load_models, TObjFish__sub_8019F72C },
    { TOMine::load_static_resource, TOMine::free_instance },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { TObjDoorKey::load_resources, TObjDoorKey::free_key },
    { TOKeyGenericSw::load_resources, TOKeyGenericSw::free_shared_resources },
    { TOKeyCave01::load_resources, TOKeyCave01::free_objects },
    { TOKeyMachine01::load_assets, TOKeyMachine01::free_statics },
    { TOSwitchAttack__sub_80177C24, TOSwitchAttack__sub_80177C20 },
    { load_computer_resources, TObjComputer::free_resources },
    { TODummyKeyCave01__sub_80165E8C, TODummyKeyCave01__sub_80165E88 },
    { TOSwitchTimer__sub_80178588, TOSwitchTimer__sub_80178584 },
    { load_chat_sensor, TOChatSensor::destroy_global },
    { TObjDoaEx01::load_resources, TObjDoaEx01::free_resource },
    { TLanguage::load_container_fragment_textures, fn_8015C5F8 },
    { TOBoss4::load_static_resource, TOBoss4::free_instance },
    { TObjCamera::load_shared_resource, TObjCamera::release_static_resource },
    { fn_8019B0D4, fn_8019B09C },
    { fn_8019AD50, TObjBigTuitate::free_instance },
    { TODragonflyCave01::load_resources, TODragonflyCave01::release_static_instance },
    { load_turiten_singo_resources, TOHangceilingCave01::destroy_instance },
    { TOTrapAncient02::load_resources, TOTrapAncient02::destroy_instance },
    { TOTrapAncient01::load_resources, TOTrapAncient01::release_static_resource },
    { load_green_door_resources, TLobby::free_shared_objects },
    { TOCapsuleLabo::load_resources, TOCapsuleLabo::unload_static_data },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floors_19_20[27] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TObjFish::load_models, TObjFish__sub_8019F72C },
    { TOMine::load_static_resource, TOMine::free_instance },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { TObjDoorKey::load_resources, TObjDoorKey::free_key },
    { TOKeyGenericSw::load_resources, TOKeyGenericSw::free_shared_resources },
    { TOKeyCave01::load_resources, TOKeyCave01::free_objects },
    { TOKeyMachine01::load_assets, TOKeyMachine01::free_statics },
    { TOSwitchAttack__sub_80177C24, TOSwitchAttack__sub_80177C20 },
    { load_computer_resources, TObjComputer::free_resources },
    { TODummyKeyCave01__sub_80165E8C, TODummyKeyCave01__sub_80165E88 },
    { TOSwitchTimer__sub_80178588, TOSwitchTimer__sub_80178584 },
    { load_chat_sensor, TOChatSensor::destroy_global },
    { TODoorVS2Door01::load_resources, TODoorVS2Door01::free_resources },
    { TLanguage::load_container_fragment_textures, fn_8015C5F8 },
    { TOVS2Wall01::load_resources, TOVS2Wall01::release_model },
    { TObjHashiVersus1::load_shared_resource, TObjHashiVersus1::unload_static_data },
    { TObjHashiVersus2::load_shared_resource, TObjHashiVersus2::unload_static_data },
    { load_turiten_singo_resources, TOHangceilingCave01::destroy_instance },
    { TOTrapAncient02::load_resources, TOTrapAncient02::destroy_instance },
    { TOTrapAncient01::load_resources, TOTrapAncient01::release_static_resource },
    { load_green_door_resources, TLobby::free_shared_objects },
    { TOCapsuleLabo::load_resources, TOCapsuleLabo::unload_static_data },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_23[29] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TObjContainerJung::load_resources, TObjContainerJung::release },
    { load_warp_beam_resources, free_warp_jung_beam_resources },
    { TObjDoorJung__sub_8018F4AC, TObjDoorJung::free_buffers },
    { TKomorebi::load_resources, TKomorebi::free_static },
    { TOMine::load_static_resource, TOMine::free_instance },
    { load_computer_resources, TObjComputer::free_resources },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TOKeyGenericSw::load_resources, TOKeyGenericSw::free_shared_resources },
    { TOKeyCave01::load_resources, TOKeyCave01::free_objects },
    { TObjContainerJungEx::load_resource_instance, TObjContainerJungEx::free_data },
    { TODoorJungleMain::load_resources, TODoorJungleMain::free_static_resources },
    { TOKeyJungleMain::load_static_resource, TOKeyJungleMain::release_static_resource },
    { TORockJungleS01::load_resources, TORockJungleS01::free_globals },
    { TOGrassJungle::load_resources, TOGrassJungle::release_static_instance },
    { load_bg_lightning, TBGLightningCtrl::destroy_instance },
    { TContainerAncient01::load_resources, TContainerAncient01::release_static_resource },
    { TContainerAncient01R::init_table_entries, TContainerAncient01R__sub_8018AF74 },
    { TOCapsuleLabo::load_resources, TOCapsuleLabo::unload_static_data },
    { TOTrapSeabed01::load_resources, TOTrapSeabed01::free_static_resources },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TObjFish::load_models, TObjFish__sub_8019F72C },
    { TObjSeabedSuisoBrakable::load_shared_models, fn_802C99D8 },
    { TOBiwaMushi::load_resource_instance, TOBiwaMushi::free_shared_data },
    { TObjPlayer::load_kamome_resources, TObjPlayer::destroy_instance },
    { TOTrapAncient02::load_resources, TOTrapAncient02::destroy_instance },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_24[31] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TObjContainerJung::load_resources, TObjContainerJung::release },
    { load_warp_beam_resources, free_warp_jung_beam_resources },
    { TObjDoorJung__sub_8018F4AC, TObjDoorJung::free_buffers },
    { TKomorebi::load_resources, TKomorebi::free_static },
    { TOMine::load_static_resource, TOMine::free_instance },
    { load_computer_resources, TObjComputer::free_resources },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TOKeyGenericSw::load_resources, TOKeyGenericSw::free_shared_resources },
    { TOKeyCave01::load_resources, TOKeyCave01::free_objects },
    { TObjContainerJungEx::load_resource_instance, TObjContainerJungEx::free_data },
    { TOKeyJungleMain::load_static_resource, TOKeyJungleMain::release_static_resource },
    { TORockJungleS01::load_resources, TORockJungleS01::free_globals },
    { TOGrassJungle::load_resources, TOGrassJungle::release_static_instance },
    { TContainerAncient01::load_resources, TContainerAncient01::release_static_resource },
    { TContainerAncient01R::init_table_entries, TContainerAncient01R__sub_8018AF74 },
    { TObjFish::load_area_resource, TObjFish::free_resource },
    { TObjPlayer::load_jungle_ebi_resources, TObjPlayer::free_chr_select },
    { TObjPlayer::load_jungle_bird_resources, TObjPlayer::free_statics },
    { TOCapsuleLabo::load_resources, TOCapsuleLabo::unload_static_data },
    { TOTrapSeabed01::load_resources, TOTrapSeabed01::free_static_resources },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TObjFish::load_models, TObjFish__sub_8019F72C },
    { TObjSeabedSuisoBrakable::load_shared_models, fn_802C99D8 },
    { TOBiwaMushi::load_resource_instance, TOBiwaMushi::free_shared_data },
    { TObjPlayer::load_kamome_resources, TObjPlayer::destroy_instance },
    { TAdMultiSaveGC::load_shared_resource, TAdMultiSaveGC::free_window },
    { TOTrapAncient02::load_resources, TOTrapAncient02::destroy_instance },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_25[30] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TObjContainerJung::load_resources, TObjContainerJung::release },
    { load_warp_beam_resources, free_warp_jung_beam_resources },
    { TObjDoorJung__sub_8018F4AC, TObjDoorJung::free_buffers },
    { TKomorebi::load_resources, TKomorebi::free_static },
    { TOMine::load_static_resource, TOMine::free_instance },
    { load_computer_resources, TObjComputer::free_resources },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TOKeyGenericSw::load_resources, TOKeyGenericSw::free_shared_resources },
    { TOKeyCave01::load_resources, TOKeyCave01::free_objects },
    { TObjContainerJungEx::load_resource_instance, TObjContainerJungEx::free_data },
    { TOKeyJungleMain::load_static_resource, TOKeyJungleMain::release_static_resource },
    { TORockJungleS01::load_resources, TORockJungleS01::free_globals },
    { TOGrassJungle::load_resources, TOGrassJungle::release_static_instance },
    { TContainerAncient01::load_resources, TContainerAncient01::release_static_resource },
    { TContainerAncient01R::init_table_entries, TContainerAncient01R__sub_8018AF74 },
    { TObjPlayer::load_jungle_ebi_resources, TObjPlayer::free_chr_select },
    { TObjPlayer::load_jungle_bird_resources, TObjPlayer::free_statics },
    { TOCapsuleLabo::load_resources, TOCapsuleLabo::unload_static_data },
    { TOTrapSeabed01::load_resources, TOTrapSeabed01::free_static_resources },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TObjFish::load_models, TObjFish__sub_8019F72C },
    { TObjSeabedSuisoBrakable::load_shared_models, fn_802C99D8 },
    { TOBiwaMushi::load_resource_instance, TOBiwaMushi::free_shared_data },
    { TObjPlayer::load_kamome_resources, TObjPlayer::destroy_instance },
    { TAdMultiSaveGC::load_shared_resource, TAdMultiSaveGC::free_window },
    { TOTrapAncient02::load_resources, TOTrapAncient02::destroy_instance },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_26[27] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TObjContainerJung::load_resources, TObjContainerJung::release },
    { load_warp_beam_resources, free_warp_jung_beam_resources },
    { TObjDoorJung__sub_8018F4AC, TObjDoorJung::free_buffers },
    { TKomorebi::load_resources, TKomorebi::free_static },
    { TOMine::load_static_resource, TOMine::free_instance },
    { load_computer_resources, TObjComputer::free_resources },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TOKeyGenericSw::load_resources, TOKeyGenericSw::free_shared_resources },
    { TOKeyCave01::load_resources, TOKeyCave01::free_objects },
    { TObjContainerJungEx::load_resource_instance, TObjContainerJungEx::free_data },
    { TOKeyJungleMain::load_static_resource, TOKeyJungleMain::release_static_resource },
    { TORockJungleS01::load_resources, TORockJungleS01::free_globals },
    { TOGrassJungle::load_resources, TOGrassJungle::release_static_instance },
    { TContainerAncient01::load_resources, TContainerAncient01::release_static_resource },
    { TContainerAncient01R::init_table_entries, TContainerAncient01R__sub_8018AF74 },
    { TOCapsuleLabo::load_resources, TOCapsuleLabo::unload_static_data },
    { TOTrapSeabed01::load_resources, TOTrapSeabed01::free_static_resources },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TObjFish::load_models, TObjFish__sub_8019F72C },
    { TObjSeabedSuisoBrakable::load_shared_models, fn_802C99D8 },
    { TObjPlayer::load_kamome_resources, TObjPlayer::destroy_instance },
    { TAdMultiSaveGC::load_shared_resource, TAdMultiSaveGC::free_window },
    { TOTrapAncient02::load_resources, TOTrapAncient02::destroy_instance },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_27[30] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TObjContainerJung::load_resources, TObjContainerJung::release },
    { load_warp_beam_resources, free_warp_jung_beam_resources },
    { TObjDoorJung__sub_8018F4AC, TObjDoorJung::free_buffers },
    { TKomorebi::load_resources, TKomorebi::free_static },
    { TOMine::load_static_resource, TOMine::free_instance },
    { load_computer_resources, TObjComputer::free_resources },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TOKeyGenericSw::load_resources, TOKeyGenericSw::free_shared_resources },
    { TOKeyCave01::load_resources, TOKeyCave01::free_objects },
    { TObjContainerJungEx::load_resource_instance, TObjContainerJungEx::free_data },
    { TOKeyJungleMain::load_static_resource, TOKeyJungleMain::release_static_resource },
    { TORockJungleS01::load_resources, TORockJungleS01::free_globals },
    { TOGrassJungle::load_resources, TOGrassJungle::release_static_instance },
    { TContainerAncient01::load_resources, TContainerAncient01::release_static_resource },
    { TContainerAncient01R::init_table_entries, TContainerAncient01R__sub_8018AF74 },
    { TObjPlayer::load_jungle_ebi_resources, TObjPlayer::free_chr_select },
    { TObjPlayer::load_jungle_bird_resources, TObjPlayer::free_statics },
    { TObjFish::load_area_resource, TObjFish::free_resource },
    { TOCapsuleLabo::load_resources, TOCapsuleLabo::unload_static_data },
    { TOTrapSeabed01::load_resources, TOTrapSeabed01::free_static_resources },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TObjFish::load_models, TObjFish__sub_8019F72C },
    { TObjSeabedSuisoBrakable::load_shared_models, fn_802C99D8 },
    { TObjPlayer::load_kamome_resources, TObjPlayer::destroy_instance },
    { TAdMultiSaveGC::load_shared_resource, TAdMultiSaveGC::free_window },
    { TOTrapAncient02::load_resources, TOTrapAncient02::destroy_instance },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_34[27] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TObjContainerJung::load_resources, TObjContainerJung::release },
    { load_warp_beam_resources, free_warp_jung_beam_resources },
    { TObjDoorJung__sub_8018F4AC, TObjDoorJung::free_buffers },
    { TOMine::load_static_resource, TOMine::free_instance },
    { load_computer_resources, TObjComputer::free_resources },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TOKeyGenericSw::load_resources, TOKeyGenericSw::free_shared_resources },
    { TOKeyCave01::load_resources, TOKeyCave01::free_objects },
    { TObjContainerJungEx::load_resource_instance, TObjContainerJungEx::free_data },
    { TOKeyJungleMain::load_static_resource, TOKeyJungleMain::release_static_resource },
    { TORockJungleS01::load_resources, TORockJungleS01::free_globals },
    { TOGrassJungle::load_resources, TOGrassJungle::release_static_instance },
    { TContainerAncient01::load_resources, TContainerAncient01::release_static_resource },
    { TContainerAncient01R::init_table_entries, TContainerAncient01R__sub_8018AF74 },
    { TObjPlayer::load_jungle_ebi_resources, TObjPlayer::free_chr_select },
    { TObjFish::load_area_resource, TObjFish::free_resource },
    { TOCapsuleLabo::load_resources, TOCapsuleLabo::unload_static_data },
    { TOTrapSeabed01::load_resources, TOTrapSeabed01::free_static_resources },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TObjFish::load_models, TObjFish__sub_8019F72C },
    { TObjSeabedSuisoBrakable::load_shared_models, fn_802C99D8 },
    { TAdMultiSaveGC::load_shared_resource, TAdMultiSaveGC::free_window },
    { TOTrapAncient02::load_resources, TOTrapAncient02::destroy_instance },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_35[33] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TObjContainerJung::load_resources, TObjContainerJung::release },
    { load_warp_beam_resources, free_warp_jung_beam_resources },
    { TObjDoorJung__sub_8018F4AC, TObjDoorJung::free_buffers },
    { TOMine::load_static_resource, TOMine::free_instance },
    { load_computer_resources, TObjComputer::free_resources },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TOKeyGenericSw::load_resources, TOKeyGenericSw::free_shared_resources },
    { TOKeyCave01::load_resources, TOKeyCave01::free_objects },
    { TObjContainerJungEx::load_resource_instance, TObjContainerJungEx::free_data },
    { TOKeyJungleMain::load_static_resource, TOKeyJungleMain::release_static_resource },
    { TContainerAncient01::load_resources, TContainerAncient01::release_static_resource },
    { TContainerAncient01R::init_table_entries, TContainerAncient01R__sub_8018AF74 },
    { TObjPlayer::load_jungle_ebi_resources, TObjPlayer::free_chr_select },
    { TObjPlayer::load_jungle_bird_resources, TObjPlayer::free_statics },
    { TOCapsuleLabo::load_resources, TOCapsuleLabo::unload_static_data },
    { TOTrapSeabed01::load_resources, TOTrapSeabed01::free_static_resources },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TObjFish::load_models, TObjFish__sub_8019F72C },
    { TObjSeabedSuisoBrakable::load_shared_models, fn_802C99D8 },
    { TObjPlayer::load_kamome_resources, TObjPlayer::destroy_instance },
    { TOTrapAncient02::load_resources, TOTrapAncient02::destroy_instance },
    { TOMonitorMachine01::load_resources, TOMonitorMachine01::reset_static_state },
    { TOCapsuleMachine01::alloc_and_load_resource, TOCapsuleMachine01::reset_static_state },
    { TOBind::load_static_resource, TOBind::free_static_model },
    { load_turiten_singo_resources, TOHangceilingCave01::destroy_instance },
    { fn_8019B0D4, fn_8019B09C },
    { fn_8019AD50, TObjBigTuitate::free_instance },
    { TObjSeabedSuisoBrakable::load_resources, TObjSeabedSuisoBrakable::free_static_resources },
    { TOComputerMachine01::load_model_resource, TOComputerMachine01::reset_state },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_28[26] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TOMine::load_static_resource, TOMine::free_instance },
    { load_computer_resources, TObjComputer::free_resources },
    { TObjFish::load_area_resource, TObjFish::free_resource },
    { TLanguage__sub_802A0204, TLobby::free_chr_select_slots },
    { TLanguage__sub_8029FF0C, TLobby::free_global_buffers },
    { load_warp_beam_resources, free_warp_jung_beam_resources },
    { TObjSeabedSuisoBrakable::load_resources, TObjSeabedSuisoBrakable::free_static_resources },
    { TOMekaFish00::load_shared_resource, TOMekaFish00::release_static_instance },
    { TOMekaFish01::load_shared_resource, TOMekaFish01::free_static_data },
    { load_forest_box_resources, TLobby::free_char_select_resources },
    { TLobby::load_console_resources, TLobby::free_chr_select_slot },
    { TOTrapAncient02::load_resources, TOTrapAncient02::destroy_instance },
    { TObjPlayer::load_seabed_dolphin, TObjPlayer__sub_802C2900 },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TOKeyGenericSw::load_resources, TOKeyGenericSw::free_shared_resources },
    { TOKeyCave01::load_resources, TOKeyCave01::free_objects },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TObjFish::load_models, TObjFish__sub_8019F72C },
    { TOTrapSeabed01::load_resources, TOTrapSeabed01::free_static_resources },
    { TOCapsuleLabo::load_resources, TOCapsuleLabo::unload_static_data },
    { TObjSeabedSuisoBrakable::load_shared_models, fn_802C99D8 },
    { TOKurage::load_static_resource, TOKurage::destroy_static_instance },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_29[26] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { TOMine::load_static_resource, TOMine::free_instance },
    { load_computer_resources, TObjComputer::free_resources },
    { TObjFish::load_area_resource, TObjFish::free_resource },
    { TLanguage__sub_802A0204, TLobby::free_chr_select_slots },
    { TLanguage__sub_8029FF0C, TLobby::free_global_buffers },
    { load_warp_beam_resources, free_warp_jung_beam_resources },
    { TObjSeabedSuisoBrakable::load_resources, TObjSeabedSuisoBrakable::free_static_resources },
    { TOMekaFish00::load_shared_resource, TOMekaFish00::release_static_instance },
    { TOMekaFish01::load_shared_resource, TOMekaFish01::free_static_data },
    { load_forest_box_resources, TLobby::free_char_select_resources },
    { TLobby::load_console_resources, TLobby::free_chr_select_slot },
    { TOTrapAncient02::load_resources, TOTrapAncient02::destroy_instance },
    { TObjPlayer::load_seabed_dolphin, TObjPlayer__sub_802C2900 },
    { load_lazer_fence_norm_resources, TObjLazerFenceNorm::free_resources },
    { TLazerFenceSw::load_resources, TLazerFenceSw__sub_80193C5C },
    { TOHealGeneral::load_resources, TOHealGeneral::unload_resources },
    { TOKeyGenericSw::load_resources, TOKeyGenericSw::free_shared_resources },
    { TOKeyCave01::load_resources, TOKeyCave01::free_objects },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TObjFish::load_models, TObjFish__sub_8019F72C },
    { TOTrapSeabed01::load_resources, TOTrapSeabed01::free_static_resources },
    { TOCapsuleLabo::load_resources, TOCapsuleLabo::unload_static_data },
    { TObjSeabedSuisoBrakable::load_shared_models, fn_802C99D8 },
    { TOKurage::load_static_resource, TOKurage::destroy_static_instance },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_30[8] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TObjContainerJung::load_resources, TObjContainerJung::release },
    { TObjContainerJungEx::load_resource_instance, TObjContainerJungEx::free_data },
    { load_bg_lightning, TBGLightningCtrl::destroy_instance },
    { TOCapsuleLabo::load_resources, TOCapsuleLabo::unload_static_data },
    { load_warp_beam_resources, free_warp_jung_beam_resources },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_31[7] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { load_forest_box_resources, TLobby::free_char_select_resources },
    { TLobby::load_console_resources, TLobby::free_chr_select_slot },
    { TOCapsuleLabo::load_resources, TOCapsuleLabo::unload_static_data },
    { load_warp_beam_resources, free_warp_jung_beam_resources },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_32[5] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TLanguage::load_container_fragment_textures, fn_8015C5F8 },
    { TOCapsuleLabo::load_resources, TOCapsuleLabo::unload_static_data },
    { 0, 0 },
};

FloorLifecycleEntry floor_lifecycle_callbacks_floor_33[6] = {
    { load_area_dialogue_script, TQuestThread::destroy_quest_obj },
    { load_forest_warp_resources, TObjWarpBase::free_globals },
    { TLanguage::load_container_fragment_textures, fn_8015C5F8 },
    { fn_8030B7B8, fn_8030B7B4 },
    { TOCapsuleLabo::load_resources, TOCapsuleLabo::unload_static_data },
    { 0, 0 },
};

FloorLifecycleEntry* floor_lifecycle_callback_tables[36] = {
    floor_lifecycle_callbacks_floor_00,
    floor_lifecycle_callbacks_floor_01,
    floor_lifecycle_callbacks_floor_02,
    floor_lifecycle_callbacks_floor_03,
    floor_lifecycle_callbacks_floor_04,
    floor_lifecycle_callbacks_floor_05,
    floor_lifecycle_callbacks_floor_06,
    floor_lifecycle_callbacks_floor_07,
    floor_lifecycle_callbacks_floor_08,
    floor_lifecycle_callbacks_floor_09,
    floor_lifecycle_callbacks_floor_10,
    floor_lifecycle_callbacks_floors_11_12,
    floor_lifecycle_callbacks_floors_11_12,
    floor_lifecycle_callbacks_floor_13,
    floor_lifecycle_callbacks_floor_14,
    floor_lifecycle_callbacks_floor_15,
    floor_lifecycle_callbacks_floor_16,
    floor_lifecycle_callbacks_floor_17,
    floor_lifecycle_callbacks_floor_18,
    floor_lifecycle_callbacks_floors_19_20,
    floor_lifecycle_callbacks_floors_19_20,
    floor_lifecycle_callbacks_floors_21_22,
    floor_lifecycle_callbacks_floors_21_22,
    floor_lifecycle_callbacks_floor_23,
    floor_lifecycle_callbacks_floor_24,
    floor_lifecycle_callbacks_floor_25,
    floor_lifecycle_callbacks_floor_26,
    floor_lifecycle_callbacks_floor_27,
    floor_lifecycle_callbacks_floor_28,
    floor_lifecycle_callbacks_floor_29,
    floor_lifecycle_callbacks_floor_30,
    floor_lifecycle_callbacks_floor_31,
    floor_lifecycle_callbacks_floor_32,
    floor_lifecycle_callbacks_floor_33,
    floor_lifecycle_callbacks_floor_34,
    floor_lifecycle_callbacks_floor_35,
};
