// ANCIENT01's scene hooks in area_initializer_dispatch_table (FloorTransition.cpp): cleanup, then init.
#include "pso/map/area/AreaScene.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/network/TLobby.h"
#include "pso/audio/SoundPlayback.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/audio/MusicControl.h"
#include "pso/audio/SoundRequests.h"
#include "pso/object/ambient/TObjLight_SceneLights.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/quest/QuestStoryFlags.h"
#include "pso/map/FloorWaveEvents.h"

#pragma readonly_strings on

void cleanup_ancient1_area(void) {
    refresh_render_state();
    stop_audio_streams();
    unload_current_floor_resources();
    update_current_floor();
    TLobby::clear_session_buffers();
}

s32 init_ancient1_area(void) {
    load_floor_sound_bank(get_current_floor_area());
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    if (is_split_screen() != 0) {
        play_area_music("ship_b.adx");
    } else {
        init_music_sequencer(3);
    }
    set_story_flag_or_send_quest_flag(0x30);
    return 1;
}
