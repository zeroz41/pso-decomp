#include "types.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/map/FloorArea.h"
#include "pso/network/TLobby.h"
#include "pso/map/area/AreaScene.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/FloorReflection.h"
#include "pso/boss/barbaray/TObjBoss7Dust.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/unk/TLobby_802268F4.h"

extern "C" {
s32 load_floor_sound_bank();
}
s32 init_scene_delo2(void);

void TLobby::update_subsystems() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); stop_cue_stream(); free_boss7_tunnel(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }

s32 init_scene_delo2(void) {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_boss7_tunnel();
    init_area_lights();
    TLobby::create_tasks();
    create_boss7_tunnel();
    debug_area_hook(0);
    play_area_music("delo2.adx");
    if (is_split_screen() == 0) {
        new TFloorReflection(tl_particlemodel);
    }
    return 1;
}
