// CITY's (and LABO's) scene hooks in area_initializer_dispatch_table (TLobby_80228154.cpp): cleanup, then init.
#include "pso/map/area/AreaScene.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_80227A2C.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/item/shop/ShopToolStock.h"
#include "pso/item/shop/ShopWeaponStock.h"
#include "pso/object/city/CityTraffic.h"
#include "pso/object/collision/TObjBgmColCtrl.h"
#include "pso/quest/TQuestBgmCtrl.h"
#include "pso/quest/TQuestListChallenge.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/city/TShopGetItemWindow_8021EEE4.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/unk/text_8006EBC4.h"
#include "pso/unk/text_8020EE2C.h"
#include "pso/object/city/TObjCityAirCar_Ctrl.h"

extern "C" {
// text_80184C2C.cpp; its header does not declare it yet.
void TLobby__sub_80184DF4(void);
}
// THunterGuildSeqOnlineTask_802156A0.cpp; no header declares it yet.
void load_judge_item(void);

// Load and release hooks run by run_load_callback_table / call_funcs_reverse.
void (*TLobby_scene_load_callback_table[24])(void) = {
    TLobby::create_named_lobby_object, TLobby::free_singleton,
    load_weapon_random_tables, TLobby::free_lobby_resources,
    load_armor_random_table, TLobby::free_rocks,
    load_tool_random_rel, TLobby::free_all_rocks,
    load_judge_item, TLobby::free_window,
    TLobby::clear_flag_if_not_split_screen, TLobby::free_global,
    reset_globals2__19TQuestListChallengeFv, reset_globals__19TQuestListChallengeFv,
    TLobby__sub_80184DF4, TLobby::free_buffers,
    TCheckRoomSequence::alloc_item_buffers, TCheckRoomSequence::free_bank_item_records,
    measure_traffic_path_lengths, free_buffer_pair_table,
    TQuestVmDownLoadServer::reset_download_state, TQuestVmDownLoadServer::free_download_buffers,
    TLobby::alloc_buffer, TLobby::free_buffer,
};

void TLobby::cleanup_boss3_scene() {
    TLobby::refresh_render_state();
    TLobby::stop_audio_streams();
    TTecRaFoie__sub_80226254();
    TLobby::call_funcs_reverse(TLobby_scene_load_callback_table, sizeof(TLobby_scene_load_callback_table));
    unload_current_floor_resources();
    TLobby::update_current_floor();
    TLobby::clear_session_buffers();
}

s32 TLobby::setup_scene() {
    load_floor_sound_bank(get_current_floor_area());
    TLobby__sub_80207E44();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    init_shop_world_context();
    run_load_callback_table(TLobby_scene_load_callback_table, sizeof(TLobby_scene_load_callback_table));
    ((TLobby *)lobby_rule_settings)->reset_settings_to_default();
    TLobby::create_tasks();
    TObjBgmColCtrl::create_controller();
    if (get_current_floor_area() == AREA_PIONEER2_EP1) {
        new TObjCityAirCar_Ctrl(tl_05);
    }
    new TQuestBgmCtrl(tl_05);
    fn_8006EBC4((saddr)tl_07);
    return 1;
}
