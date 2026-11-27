// BOSS04's scene hooks in area_initializer_dispatch_table (FloorTransition.cpp): cleanup, then init.
#include "pso/map/area/AreaScene.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/network/TLobby.h"
#include "pso/audio/SoundPlayback.h"
#include "pso/audio/SoundRequests.h"
#include "pso/object/ambient/SceneLighting.h"
#include "pso/boss/darkfalz/TBoss4CheckEmpty.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/audio/MusicControl.h"
#include "pso/map/FloorWaveEvents.h"

void cleanup_boss4_area(void) {
    TParticleCtrl::free_heap();
    refresh_render_state();
    stop_audio_streams();
    stop_cue_stream();
    unload_current_floor_resources();
    update_current_floor();
    TLobby::clear_session_buffers();
}

s32 init_boss4_area(void) {
    load_floor_sound_bank(get_current_floor_area());
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    TParticleCtrl::init_heap(0x10000);
    TBoss4CheckEmpty::create();
    return 1;
}
