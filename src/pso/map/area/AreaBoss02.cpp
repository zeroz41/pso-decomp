// BOSS02's scene hooks in area_initializer_dispatch_table (TLobby_80228154.cpp): cleanup, then init.
#include "pso/map/area/AreaScene.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_80227A2C.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/unk/TLobby_8003A95C.h"

#pragma readonly_strings on

// Load and release hooks run by run_load_callback_table / call_funcs_reverse.
void (*lbl_804A7360[2])(void) = {TLobby__sub_8003A9AC, TLobby::init_boss2_stage};

void cleanup_boss2_area(void) {
    TLobby::refresh_render_state();
    TLobby::stop_audio_streams();
    TLobby::call_funcs_reverse(lbl_804A7360, sizeof(lbl_804A7360));
    unload_current_floor_resources();
    TLobby::update_current_floor();
    TLobby::clear_session_buffers();
}

s32 TLobby::setup_area() {
    load_floor_sound_bank(get_current_floor_area());
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    run_load_callback_table(lbl_804A7360, sizeof(lbl_804A7360));
    init_area_lights();
    TLobby::create_tasks();
    TLobby::create_boss2_tunnel();
    TLobby__sub_801403B4(0);
    play_area_music("delo.adx");
    return 1;
}

void TLobby__sub_801403B4(s32 _w0) {}
