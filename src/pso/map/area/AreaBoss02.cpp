// BOSS02's scene hooks in area_initializer_dispatch_table (FloorTransition.cpp): cleanup, then init.
#include "pso/map/area/AreaScene.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/network/TLobby.h"
#include "pso/audio/SoundPlayback.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/audio/MusicControl.h"
#include "pso/audio/SoundRequests.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/boss/derolle/TObjBoss2Dust.h"
#include "pso/map/FloorWaveEvents.h"

#pragma readonly_strings on

// Load and release hooks run by run_load_callback_table / call_funcs_reverse.
void (*boss2_tunnel_callbacks[2])(void) = {init_boss2_tunnel, free_boss2_tunnel};

void cleanup_boss2_area(void) {
    refresh_render_state();
    stop_audio_streams();
    call_funcs_reverse(boss2_tunnel_callbacks, sizeof(boss2_tunnel_callbacks));
    unload_current_floor_resources();
    update_current_floor();
    TLobby::clear_session_buffers();
}

s32 init_boss2_area(void) {
    load_floor_sound_bank(get_current_floor_area());
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    run_load_callback_table(boss2_tunnel_callbacks, sizeof(boss2_tunnel_callbacks));
    init_area_lights();
    TLobby::create_tasks();
    create_boss2_tunnel();
    debug_area_hook(0);
    play_area_music("delo.adx");
    return 1;
}

void debug_area_hook(s32 _w0) {}
