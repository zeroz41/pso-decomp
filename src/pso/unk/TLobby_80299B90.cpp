#include "types.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TLobby.h"
#include "pso/map/area/AreaScene.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TUnk_804DC7C4.h"
#include "pso/boss/barbaray/TObjBoss7Dust.h"

extern "C" {
s32 load_floor_sound_bank();
}
void init_area_lights(void);
s32 init_scene_delo2(void);
void stop_cue_stream(void);

void TLobby::update_subsystems() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); stop_cue_stream(); free_boss7_tunnel(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }

s32 init_scene_delo2(void) {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_scene_boss2_tunnel();
    init_area_lights();
    TLobby::create_tasks();
    create_boss7_tunnel();
    TLobby__sub_801403B4(0);
    play_area_music("delo2.adx");
    if (is_split_screen() == 0) {
        new TUnk_804DC7C4(tl_particlemodel);
    }
    return 1;
}
