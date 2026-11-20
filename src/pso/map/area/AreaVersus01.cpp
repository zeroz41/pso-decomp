// VERSUS01's (and SPACE01/02's) scene hooks in area_initializer_dispatch_table (TLobby_80228154.cpp): cleanup, then init.
#include "pso/map/area/AreaScene.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_80227A2C.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"

#pragma readonly_strings on

void TLobby::refresh_floor_state() {
    TLobby::refresh_render_state();
    TLobby::stop_audio_streams();
    unload_current_floor_resources();
    TLobby::update_current_floor();
    TLobby::clear_session_buffers();
}

s32 init_spaceship_area(void) {
    load_floor_sound_bank(get_current_floor_area());
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    if ((get_main_phase() != 0xE) || (is_quest_active() == 0)) {
        switch (get_current_floor_area()) {
        case AREA_VR_SPACESHIP_BETA:
            set_story_flag_or_send_quest_flag(0x4E);
            break;
        }
    }
    if (is_split_screen() != 0) {
        play_area_music("s_b.adx");
    } else if (TLobby::get_instance() == 1) {
        init_music_sequencer(8);
    }
    return 1;
}
