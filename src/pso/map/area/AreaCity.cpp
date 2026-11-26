// CITY's (and LABO's) scene hooks in area_initializer_dispatch_table (TLobby_80228154.cpp): cleanup, then init.
#include "pso/map/area/AreaScene.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/network/TLobby.h"
#include "pso/unk/TLobby_80227AA0.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/item/shop/ShopArmorStock.h"
#include "pso/item/shop/ShopToolStock.h"
#include "pso/item/shop/ShopWeaponStock.h"
#include "pso/object/city/CityTraffic.h"
#include "pso/object/collision/TObjBgmColCtrl.h"
#include "pso/quest/TQuestBgmCtrl.h"
#include "pso/quest/TQuestListChallenge.h"
#include "pso/quest/TQuestListOffline.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/GbaDownloadRuntime.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/ui/window/TObjBagWarnWin.h"
#include "pso/object/city/TObjCityAirCar_Ctrl.h"
#include "pso/object/city/CitySeasonResources.h"

// THunterGuildSeqOnlineTask_802156A0.cpp; no header declares it yet.
void load_judge_item(void);

// Load and release hooks run by run_load_callback_table / call_funcs_reverse.
void (*TLobby_scene_load_callback_table[24])(void) = {
    TLobby::create_named_lobby_object, TLobby::free_singleton,
    load_weapon_random_tables, free_weapon_random_tables,
    load_armor_random_table, free_armor_random_table,
    load_tool_random_rel, free_tool_random_rel,
    load_judge_item, TLobby::free_window,
    TQuestListOffline::reset_global_if_not_split_screen, TQuestListOffline::free_global,
    reset_globals2__19TQuestListChallengeFv, reset_globals__19TQuestListChallengeFv,
    load_city_season_resources, free_city_season_resources,
    TCheckRoomSequence::alloc_item_buffers, TCheckRoomSequence::free_bank_item_records,
    measure_traffic_path_lengths, free_buffer_pair_table,
    TQuestVmDownLoadServer::reset_download_state, TQuestVmDownLoadServer::free_download_buffers,
    gba_download_alloc_buffer, gba_download_free_buffer,
};

void cleanup_city_area(void) {
    TLobby::refresh_render_state();
    TLobby::stop_audio_streams();
    TTecRaFoie__sub_80226254();
    TLobby::call_funcs_reverse(TLobby_scene_load_callback_table, sizeof(TLobby_scene_load_callback_table));
    unload_current_floor_resources();
    TLobby::update_current_floor();
    TLobby::clear_session_buffers();
}

s32 init_city_area(void) {
    load_floor_sound_bank(get_current_floor_area());
    TLobby__sub_80207E44();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    init_shop_world_context();
    run_load_callback_table(TLobby_scene_load_callback_table, sizeof(TLobby_scene_load_callback_table));
    lobby_rule_settings.reset_settings_to_default();
    TLobby::create_tasks();
    TObjBgmColCtrl::create_controller();
    if (get_current_floor_area() == AREA_PIONEER2_EP1) {
        new TObjCityAirCar_Ctrl(tl_05);
    }
    new TQuestBgmCtrl(tl_05);
    create_bag_warn_window_4p((saddr)tl_07);
    return 1;
}
