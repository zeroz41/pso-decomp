// BOSS03's scene hooks in area_initializer_dispatch_table (TLobby_80228154.cpp): cleanup, then init.
#include "pso/map/area/AreaScene.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_80227A2C.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/boss/volopt/TBoss3VoloptCtrl.h"

void cleanup_boss3_area(void) {
    TLobby::refresh_render_state();
    TLobby::stop_audio_streams();
    stop_cue_stream();
    unload_current_floor_resources();
    TLobby::update_current_floor();
    TLobby::clear_session_buffers();
}

s32 TLobby::spawn_boss3_volopt_ctrl() {
    load_floor_sound_bank(get_current_floor_area());
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    new TBoss3VoloptCtrl;
    return 1;
}
