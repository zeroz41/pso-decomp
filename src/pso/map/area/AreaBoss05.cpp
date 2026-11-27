// BOSS05's scene hooks in area_initializer_dispatch_table (FloorTransition.cpp): cleanup, then init.
#include "pso/map/area/AreaScene.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/network/TLobby.h"
#include "pso/audio/SoundPlayback.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/audio/MusicControl.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/object/ambient/SceneLighting.h"
#include "pso/boss/galgryphon/TObjBoss5Ctrl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjRainCtrl.h"
#include "pso/map/FloorWaveEvents.h"
#include "pso/boss/galgryphon/Boss5PillarCleanup.h"

#pragma readonly_strings on


// Load and release hooks run by run_load_callback_table / call_funcs_reverse.
void (*gryphon_area_cleanup_callbacks[2])(void) = {
    cleanup_boss5_pillars, cleanup_pillar_demo,
};

void cleanup_gryphon_area(void) {
    refresh_render_state();
    stop_audio_streams();
    stop_cue_stream();
    TLobby::call_funcs_reverse(gryphon_area_cleanup_callbacks, sizeof(gryphon_area_cleanup_callbacks));
    TParticleCtrl::free_heap();
    update_current_floor();
    unload_current_floor_resources();
    TLobby::clear_session_buffers();
}

s32 init_gryphon_area(void) {
    AreaLightParams l;
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
