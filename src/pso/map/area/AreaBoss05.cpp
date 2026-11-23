// BOSS05's scene hooks in area_initializer_dispatch_table (TLobby_80228154.cpp): cleanup, then init.
#include "pso/map/area/AreaScene.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_80227A2C.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/boss/galgryphon/TObjBoss5Ctrl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjRainCtrl.h"

#pragma readonly_strings on

struct Light_80140514 {
    f32 dir[3];
    f32 pad[3];
    f32 amb[3];
    f32 c[4];
    f32 d[4];
};

// Load and release hooks run by run_load_callback_table / call_funcs_reverse.
void (*gryphon_area_cleanup_callbacks[2])(void) = {
    TLobby::cleanup_boss5_pillars, TLobby::cleanup_pillar_demo,
};

void TLobby::cleanup_floor_state() {
    TLobby::refresh_render_state();
    TLobby::stop_audio_streams();
    stop_cue_stream();
    TLobby::call_funcs_reverse(gryphon_area_cleanup_callbacks, sizeof(gryphon_area_cleanup_callbacks));
    TParticleCtrl::free_heap();
    TLobby::update_current_floor();
    unload_current_floor_resources();
    TLobby::clear_session_buffers();
}

s32 TLobby::init_gryphon_area() {
    Light_80140514 l;
    load_floor_sound_bank(get_current_floor_area());
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    TParticleCtrl::init_heap(0x100000);
    run_load_callback_table(gryphon_area_cleanup_callbacks, sizeof(gryphon_area_cleanup_callbacks));
    l.dir[0] = -0.46f;
    l.dir[1] = 0.88f;
    l.dir[2] = -0.13f;
    l.amb[0] = 1.0f;
    l.amb[1] = 1.0f;
    l.amb[2] = 0.15f;
    l.d[0] = 1.0f;
    l.d[1] = 0.1f;
    l.d[2] = 0.24f;
    l.d[3] = 0.4f;
    l.c[0] = 1.0f;
    l.c[1] = 0.64f;
    l.c[2] = 0.7f;
    l.c[3] = 0.74f;
    init_map_lights((LightEntry *)&l);
    TLobby::create_tasks();
    TObjRainCtrl::create();
    TObjBoss5Ctrl::create();
    play_area_music("gryphon.adx");
    return 1;
}
