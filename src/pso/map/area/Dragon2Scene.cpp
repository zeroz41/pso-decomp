#include "types.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/map/FloorArea.h"
#include "pso/boss/olgaflow/TBoss6EmptyWarp.h"
#include "pso/network/TLobby.h"
#include "pso/audio/BgmStream.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/FloorReflection.h"
#include "pso/boss/goldragon/Boss8DemoObjects.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/map/area/Dragon2Scene.h"

extern "C" {
s32 load_floor_sound_bank();
}

void refresh_lobby_state() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); stop_cue_stream(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }

s32 init_particle_model() {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    if (is_split_screen() == 0) {
        new TFloorReflection(tl_particlemodel);
    }
    TBoss6EmptyWarp::create();
    return 1;
}

void update_field_state() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); stop_cue_stream(); free_static_resource_callbacks(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }

s32 load_dragon2_scene(void) {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    load_static_resource_callbacks();
    init_area_lights();
    TLobby::create_tasks();
    create_boss8_demo_objects();
    play_area_music("dragon2.adx");
    return 1;
}
