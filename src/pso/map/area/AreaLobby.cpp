// LOBBY's scene hooks in area_initializer_dispatch_table (TLobby_80228154.cpp): cleanup, then init.
#include "pso/map/area/AreaScene.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_80227A2C.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/collision/TObjBgmColCtrl.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdMcSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby_802A0F3C.h"

// Load and release hooks run by run_load_callback_table / call_funcs_reverse.
void (*lobby_floor_scene_callbacks[12])(void) = {
    TLobby::update_photon_chair, TLobby::update_photon_chairs,
    TLobby::alloc_download_server, TLobby::free_single_player_chr_select,
    register_texture_f256_ad_pic_2, TAdSinglePlyChrSelectGC::free_global,
    register_texture_f256_backtext, TAdSinglePlyChrSelectGC::free_singleton_805D65C0,
    TLobby__sub_802A0F70, TLobby::free_dialog_global,
    TAdMcSelectGC::close, TAdMcSelectGC::open,
};

void TLobby::update_floor_download() {
    TQuestVmDownLoadServer::free_download_buffers();
    unload_current_floor_resources();
    TLobby::update_current_floor();
    TLobby::call_funcs_reverse(lobby_floor_scene_callbacks, sizeof(lobby_floor_scene_callbacks));
    TLobby::stop_audio_streams();
    TLobby::refresh_render_state();
    TLobby::stop_audio_streams();
    TLobby::clear_session_buffers();
}

s32 TLobby::init_lobby_floor_scene() {
    load_floor_sound_bank(get_current_floor_area());
    if (run_load_callback_table(lobby_floor_scene_callbacks, sizeof(lobby_floor_scene_callbacks)) == 0) {
        return 0;
    }
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TQuestVmDownLoadServer::reset_download_state();
    ((TLobby *)lobby_rule_settings)->reset_settings_to_default();
    TLobby::create_tasks();
    TObjBgmColCtrl::create_controller();
    TLobby__sub_801403B4(0);
    return 1;
}
