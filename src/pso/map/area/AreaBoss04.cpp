// BOSS04's scene hooks in area_initializer_dispatch_table (TLobby_80228154.cpp): cleanup, then init.
#include "pso/map/area/AreaScene.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_80227A2C.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/boss/darkfalz/TBoss4CheckEmpty.h"
#include "pso/effect/particle/TParticleCtrl.h"

void TLobby::reset_subsystems() {
    TParticleCtrl::free_heap();
    TLobby::refresh_render_state();
    TLobby::stop_audio_streams();
    stop_cue_stream();
    unload_current_floor_resources();
    TLobby::update_current_floor();
    TLobby::clear_session_buffers();
}

s32 TLobby::init_lobby_scene() {
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
