#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/quest/TObjTagChallenge.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/ui/window/TObjCHTimeWin.h"
#include "pso/object/TObjWarnChime.h"
#include "pso/network/client_id.h"
#include "pso/quest/challenge/ChallengeModeData.h"
#include "pso/unk/text_8026A328.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_80072230.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TObjSoloPlayWin.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/player/PlayerSlots.h"
#include "pso/quest/challenge/ChallengeModeState.h"
#include "pso/quest/challenge/TChallenge.h"
#include <stddef.h>
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TObjBagWarnWin.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/object/TObjTombstone.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/camera/TCameraCtrl.h"


LAYOUT_ASSERT(TChallenge_state_offset, offsetof(TChallenge, state) == 0x1C);
LAYOUT_ASSERT(TChallenge_frame_offset, offsetof(TChallenge, frame_count) == 0x20);
LAYOUT_ASSERT(TChallenge_size, sizeof(TChallenge) == 0x30);

TChallenge *challenge_task;
s32 challenge_task_created;
s32 TLobby__data_805D4E30;

typedef void (TChallenge::*Step_80070674)(void);

ChallengeModeState challenge_settings_defaults = {
    -1, 1.0f, -1, 0, 0x39383814, -10, -1, 0, 0, -1,
};
ChallengeModeState challenge_mode_state = {0};



// lbl_805D2850 holds "TChallenge", the task name (inferred: TChallenge's class name)
extern const char *lbl_805D2850;

#pragma defer_codegen on

TChallenge::TChallenge(TObject *parent) : TObject(parent) {
    m_name = lbl_805D2850;
    challenge_mode_state = challenge_settings_defaults;
    restore_challenge_from_save();
    TLobby::send_challenge_records((uaddr)this);
    frame_count = 0;
    missing_records_timer = 0;
    records_save_pending = 1;
    quest_send_timer = 0;
    state = 0;
}

TChallenge::~TChallenge() {
    TObjTombstone::destroy();
    clear_four_slots();
    challenge_mode_state = challenge_settings_defaults;
    challenge_task = NULL;
}

void TChallenge::run_task() {
    TChallenge *self = this;
    if (get_card_wait_state() == 1) {
        return;
    }
    self->request_missing_challenge_records();
    static Step_80070674 table[3] = {
        &TChallenge::initialize_windows,
        &TChallenge::wait_for_quest,
        &TChallenge::update_active,
    };
    Step_80070674 step = table[self->state];
    if (step) {
        (self->*step)();
    } else {
        return;
    }
    self->frame_count++;
}

void *lbl_8048D0B0[22] = {
    (void *)0x6368616c, (void *)0x6c656e67, (void *)0x65000000, (void *)0x53004300,
    (void *)0x51000000, (void *)&lbl_805D90D0, (void *)&lbl_805D90D4, (void *)&lbl_805D90D8,
    (void *)&lbl_805D90DC, (void *)&lbl_805D90E0, (void *)&lbl_805D90E4, (void *)&lbl_805D90E8,
    (void *)&lbl_805D90EC, (void *)&lbl_805D90F0, (void *)&lbl_805D90F4, (void *)&lbl_805D90F8,
    (void *)&lbl_805D90FC, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};

void TChallenge::initialize_windows() {
    TChallenge *self = this;
    s32 flag = 0;
    switch (get_main_phase()) {
    case 0xf:
        if (get_current_floor_area() != AREA_LOBBY) {
            flag = 1;
        }
        break;
    default:
        flag = 1;
        break;
    }
    if (flag != 0) {
        create_obj_tag_challenge((void *)tl_07);
        TObjBagWarnWin::create((void *)tl_07);
        self->state = 1;
    }
}

void TChallenge::wait_for_quest() {
    if (destroy_on_phase_change() == 0) {
        update_quest_challenge_state();
        if (is_quest_active() != 0) {
            ((s32)TAdSinglePlyChrSelectGC::init());
            clear_challenge_record_window();
            TLobby__sub_8026A328();
            TObjWarnChime::create(this);
            this->state = 2;
        }
    }
}

void TChallenge::update_active() {
    if (destroy_on_phase_change() == 0) {
        refresh_challenge_windows();
        update_battle_cleanup_flag();
    }
}

void TChallenge::render() {  }

s32 TChallenge::destroy_on_phase_change() {
    switch (get_main_phase()) {
    case 15:
        if (get_current_floor_area() == AREA_LOBBY) {
            queue_destruction();
            return 1;
        }
        break;
    case 14:
        queue_destruction();
        return 1;
    default:
        queue_destruction();
        return 1;
    }
    return 0;
}

void TChallenge::restore_challenge_from_save() {
    ChallengeClientRecords *own;
    clear_four_slots();
    own = &challenge_mode_state.client_records[local_client_id];
    if (get_character_save_record(0xFFFF) != 0U) {
        own->present = 1;
        own->records = *(ChallengeRecord *)(get_character_save_record(0xFFFF) + 0x21C4);
    }
}

void TChallenge::clear_four_slots() {
    s32 i;
    for (i = 0; i < 4; i++) {
        challenge_mode_state.client_records[i].present = 0;
    }
}

void TChallenge::request_missing_challenge_records() {
    s32 found;
    s32 i;
    s32 *p;
    found = 0;
    for (i = 0; i < 4; i++) {
        if (i != local_client_id) {
            p = &challenge_mode_state.client_records[i].present;
            if (get_player_by_client_id(i) == NULL) {
                if (*p != 0) {
                    *p = 0;
                }
            } else if (*p == 0) {
                found = 1;
            }
        }
    }
    if (found != 0) {
        missing_records_timer++;
        if (missing_records_timer % 30 == 0) {
            send_6x7c_reset();
        }
    } else {
        missing_records_timer = 0;
    }
}

void TChallenge::refresh_challenge_windows() {
    s32 old;
    s32 v;
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
    case AREA_PIONEER2_EP2:
        old = challenge_mode_state.current_floor;
        challenge_mode_state.current_floor = -1;
        if (old != -1) {
            create_obj_tag_challenge((void *)tl_07);
            if (challenge_mode_state.pad_20 == 0) {
                create_ch_time_win((TObject *)tl_07);
            }
        }
        break;
    case AREA_LOBBY:
        challenge_mode_state.current_floor = -1;
        break;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
        challenge_mode_state.current_floor = -1;
        break;
    default:
        v = get_current_floor();
        if (challenge_mode_state.current_floor != v) {
            challenge_mode_state.current_floor = v;
            create_time_window();
        }
        break;
    }
}

void TChallenge::update_quest_challenge_state() {
    s32 id;
    s32 n;

    n = 0;
    if (local_client_id == designated_client_id) {
        switch (TQuestListOnline::get_list_state()) {
        case 1:
            break;
        case 2:
            id = TLobby::get_selected_quest_id();
            n = 1;
            if (id >= 0x33 && id <= 0x3B) {
                n = id - 0x30;
            }
            break;
        case 3:
            id = TLobby::get_selected_quest_id();
            n = 2;
            if (id >= 0x3D && id <= 0x41) {
                n = id - 0x31;
            }
            break;
        }
        if (n == 0) {
            if (--quest_send_timer < 0) {
                quest_send_timer = 0;
            }
        } else {
            quest_send_timer = 30;
        }
        if ((quest_send_timer <= 0 || n != 0) && n != challenge_mode_state.record_window_mode) {
            TLobby::send_challenge_with_value((saddr)this, n);
        }
    }
}

void TChallenge::set_challenge_record_page(s32 v) {
    if (v < 0 || v >= 0x11) {
        return;
    }
    if (challenge_mode_state.record_window_mode != v) {
        show_challenge_record_window(v);
        challenge_mode_state.record_window_mode = v;
    }
}

void TChallenge::update_battle_cleanup_flag() {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player == NULL) {
        records_save_pending = 0;
        return;
    }
    if (((TLobby *)player)->check_player_state_flag_2() != 0) {
        if (records_save_pending != 0 && challenge_mode_state.retry_menu_disabled == 0) {
            update_card_save_info();
            TLobby__sub_800722AC(local_client_id);
            TLobby__sub_80072618();
        }
        records_save_pending = 0;
    }
}

void TChallenge::create_time_window() {
    TLobby::spawn_player_tombstones();
    create_ch_time_win((TObject *)tl_07);
    ((TLobby *)tl_07)->create_new_floor_windows();
    if (challenge_mode_state.pad_30 == 0) {
        TObjSoloPlayWin::create((TObject*)tl_07);
    }
}
