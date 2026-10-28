#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TUnk_80483B88.h"
#include "pso/boss/TBoss3VoloptCtrl.h"
#include "pso/TMainTask.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TCameraCtrl_800687BC.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLoadCtrl_80227390.h"
#include "pso/misc/TLobby_802268F4.h"
#include "pso/unk/text_801F43B4.h"

extern "C" {
extern s32 local_client_id;
TObjPlayer *get_player_by_client_id(s32 client_id);
s32 unhide_room_set_objects(s32 floor, s32, s32);
void TLobby__sub_8020C07C(s32 floor, s16, s16, s32 mask, s32 set);
void TObjPlayer__sub_801BA42C(void);
}

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
                new TUnk_80483B88;
                phase = 2;
                break;
            }
            phase = -1;
            break;
        }
        break;
    case 2:
        restore_player_cameras();
        TObjPlayer__sub_801BA42C();
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
        TLobby__sub_8020C07C(get_current_floor(), 0, 2, -0x11, 0);
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

TUnk_80483B88::TUnk_80483B88() : TObject(tl_02) {
    disallow_rendering();
}

TUnk_80483B88::~TUnk_80483B88() {}

void TUnk_80483B88::run_task() {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL && player->position.z >= 4000.0f) {
        init_music_sequencer(3);
        queue_destruction();
    }
}
