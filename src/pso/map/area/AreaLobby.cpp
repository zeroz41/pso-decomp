// LOBBY's scene hooks in area_initializer_dispatch_table (FloorTransition.cpp): cleanup, then init.
#include "pso/map/area/AreaScene.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/network/TLobby.h"
#include "pso/audio/SoundPlayback.h"
#include "pso/object/ambient/TObjLight_SceneLights.h"
#include "pso/object/collision/TObjBgmColCtrl.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdMcSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/player/PlayerActionProvider.h"
#include "pso/audio/MusicControl.h"
#include "pso/map/FloorWaveEvents.h"
#include "pso/ui/charcreate/CharacterLoadBuffer.h"

// Load and release hooks run by run_load_callback_table / call_funcs_reverse.
void (*lobby_floor_scene_callbacks[12])(void) = {
    init_lobby_player_actions, release_lobby_player_actions,
    alloc_download_server, free_single_player_chr_select,
    register_texture_f256_ad_pic_2, free_global,
    register_texture_f256_backtext, free_texture_f256_backtext,
    load_title_midashi_texture, free_title_midashi_texture,
    TAdMcSelectGC::close, TAdMcSelectGC::open,
};

void cleanup_lobby_area(void) {
    TQuestVmDownLoadServer::free_download_buffers();
    unload_current_floor_resources();
    update_current_floor();
    call_funcs_reverse(lobby_floor_scene_callbacks, sizeof(lobby_floor_scene_callbacks));
    stop_audio_streams();
    refresh_render_state();
    stop_audio_streams();
    TLobby::clear_session_buffers();
}

s32 init_lobby_area(void) {
    load_floor_sound_bank(get_current_floor_area());
    if (run_load_callback_table(lobby_floor_scene_callbacks, sizeof(lobby_floor_scene_callbacks)) == 0) {
        return 0;
    }
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TQuestVmDownLoadServer::reset_download_state();
    lobby_rule_settings.reset_settings_to_default();
    TLobby::create_tasks();
    TObjBgmColCtrl::create_controller();
    debug_area_hook(0);
    return 1;
}
