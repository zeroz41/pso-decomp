#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/text_8020BFE4.h"
#include "pso/map/FloorPopulation.h"
#include "pso/unk/text_8020C9C8.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/TBoss3VoloptMusicTrigger.h"
#include "pso/boss/volopt/TBoss3VoloptCtrl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/unk/TLobby_80226C3C.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/quest/QuestStoryFlags.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"


#pragma defer_codegen on
#pragma readonly_strings on
static const char *TBoss3VoloptCtrl_name = "TBoss3VoloptCtrl";

TBoss3VoloptCtrl::TBoss3VoloptCtrl() : TObject(tl_02) {
    m_name = TBoss3VoloptCtrl_name;
    phase = 0;
    countdown = 3;
}

TBoss3VoloptCtrl::~TBoss3VoloptCtrl() {}

void TBoss3VoloptCtrl::run_task() {
    countdown--;
    switch (phase) {
    case 0:
        phase = 1;
        break;
    case 1:
        if (countdown <= 0) {
            if (volopt_resources_loaded == 0) {
                TBoss3Volopt::move_to_arena(1);
                activate_camera_mode(9);
                TObjPlayer::freeze_all_players();
                play_area_music("vol_opt2.adx");
                if (get_main_phase() != 0xF) {
                    if (TRaderMapCore::is_not_split_screen() == 1) {
                        unhide_room_set_objects(get_current_floor(), 0, 1);
                    } else if (get_story_flag(0x2F) != 0) {
                        dispatch_state(4);
                    } else {
                        dispatch_state(3);
                    }
                } else {
                    unhide_room_set_objects(get_current_floor(), 0, 1);
                }
                unhide_room_set_objects(get_current_floor(), 0, 3);
                new TBoss3VoloptMusicTrigger;
                phase = 2;
                break;
            }
            phase = -1;
            break;
        }
        break;
    case 2:
        restore_player_cameras();
        release_players_from_cutscene();
        queue_destruction();
        break;
    case -1:
        queue_destruction();
        break;
    }
}

void TBoss3VoloptCtrl::dispatch_state(s32 state) {
    switch (state) {
    case 0:
        unhide_room_set_objects(get_current_floor(), 0, 1);
        unhide_room_set_objects(get_current_floor(), 0, 3);
        return;
    case 1:
        unhide_room_set_objects(get_current_floor(), 0, 3);
    case 3:
        unhide_room_set_objects(get_current_floor(), 0, 2);
        set_wave_object_flags(get_current_floor(), 0, 2, -0x11, 0);
        return;
    case 2:
        unhide_room_set_objects(get_current_floor(), 0, 3);
    case 4:
        unhide_room_set_objects(get_current_floor(), 0, 2);
        return;
    case 5:
        unhide_room_set_objects(get_current_floor(), 0, 1);
        unhide_room_set_objects(get_current_floor(), 0, 3);
        return;
    }
}

TBoss3VoloptMusicTrigger::TBoss3VoloptMusicTrigger() : TObject(tl_02) {
    disallow_rendering();
}

TBoss3VoloptMusicTrigger::~TBoss3VoloptMusicTrigger() {}

void TBoss3VoloptMusicTrigger::run_task() {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL && player->position.z >= 4000.0f) {
        init_music_sequencer(3);
        queue_destruction();
    }
}
