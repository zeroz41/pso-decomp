// MACHINE02's scene hooks in area_initializer_dispatch_table (FloorTransition.cpp): cleanup, then init.
#include "pso/map/area/AreaScene.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/network/TLobby.h"
#include "pso/audio/SoundPlayback.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/audio/MusicControl.h"
#include "pso/audio/SoundRequests.h"
#include "pso/object/ambient/TObjLight_SceneLights.h"
#include "pso/map/FloorWaveEvents.h"

#pragma readonly_strings on

void cleanup_machine2_area(void) {
    refresh_render_state();
    stop_audio_streams();
    update_current_floor();
    unload_current_floor_resources();
    TLobby::clear_session_buffers();
}

s32 init_machine2_area(void) {
    load_floor_sound_bank(get_current_floor_area());
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    debug_area_hook(0);
    if (is_split_screen() != 0) {
        play_area_music("machin_b.adx");
    } else {
        init_music_sequencer(2);
    }
    return 1;
}
