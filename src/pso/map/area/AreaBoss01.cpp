// BOSS01's scene hooks in area_initializer_dispatch_table (FloorTransition.cpp): cleanup, then init.
#include "pso/map/area/AreaScene.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/network/TLobby.h"
#include "pso/audio/SoundPlayback.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/audio/MusicControl.h"
#include "pso/audio/SoundRequests.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/map/FloorWaveEvents.h"
#include "pso/boss/dragon/TObjBoss1Floor.h"

#pragma readonly_strings on

// Load and release hooks run by run_load_callback_table / call_funcs_reverse.
void (*dragon_area_scene_callbacks[2])(void) = {init_bosses, update_boss1_objects};

void cleanup_dragon_area_scene(void) {
    refresh_render_state();
    stop_audio_streams();
    stop_cue_stream();
    call_funcs_reverse(dragon_area_scene_callbacks, sizeof(dragon_area_scene_callbacks));
    update_current_floor();
    unload_current_floor_resources();
    TLobby::clear_session_buffers();
}

s32 init_dragon_area_scene(void) {
    LightEntry l;
    load_floor_sound_bank(get_current_floor_area());
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    run_load_callback_table(dragon_area_scene_callbacks, sizeof(dragon_area_scene_callbacks));
    if (TObjEneDD::check_v2_mode() == 0) {
        l.direction.x = -1.45f;
        l.direction.y = 2.8f;
        l.direction.z = -0.4f;
        l.pad_18 = 1.0f;
        l.intensity = 0.96f;
        l.ambient = 0.3f;
        l.ambient_color.a = 1.0f;
        l.ambient_color.r = 0.1f;
        l.ambient_color.g = 0.24f;
        l.ambient_color.b = 0.4f;
        l.color.a = 1.0f;
        l.color.r = 1.0f;
        l.color.g = 0.51f;
        l.color.b = 0.4f;
    } else {
        l.direction.x = -1.45f;
        l.direction.y = 2.8f;
        l.direction.z = -0.4f;
        l.pad_18 = 1.0f;
        l.intensity = 0.96f;
        l.ambient = 0.75f;
        l.ambient_color.a = 1.0f;
        l.ambient_color.r = 0.1f;
        l.ambient_color.g = 0.24f;
        l.ambient_color.b = 0.4f;
        l.color.a = 1.0f;
        l.color.r = 0.85f;
        l.color.g = 1.0f;
        l.color.b = 1.0f;
    }
    init_map_lights(&l);
    TLobby::create_tasks();
    forward_floor_2CB44();
    play_area_music("dragon.adx");
    return 1;
}
