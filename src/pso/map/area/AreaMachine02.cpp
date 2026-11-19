// MACHINE02's scene hooks in area_initializer_dispatch_table (TLobby_80228154.cpp): cleanup, then init.
#include "pso/map/area/AreaScene.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_80227A2C.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/object/ambient/TObjLight_80133568.h"

#pragma readonly_strings on

void TLobby::update_floor_b() {
    TLobby::refresh_render_state();
    TLobby::stop_audio_streams();
    TLobby::update_current_floor();
    unload_current_floor_resources();
    TLobby::clear_session_buffers();
}

s32 init_machine_b_scene(void) {
    load_floor_sound_bank(get_current_floor_area());
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    TLobby__sub_801403B4(0);
    if (is_split_screen() != 0) {
        play_area_music("machin_b.adx");
    } else {
        init_music_sequencer(2);
    }
    return 1;
}
