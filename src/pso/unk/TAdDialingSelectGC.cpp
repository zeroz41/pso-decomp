#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/unk/TAdDialingSelectGC.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TObjBagWarnWin.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/system/save/TCheckMemoryCard.h"
#include "pso/system/task/TObject.h"
#include "pso/network/client_id.h"
#include "pso/network/TLobby.h"
#include "pso/unk/TLobbyIdleTimer.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/audio/MusicControl.h"

void TAdDialingSelectGC::run_task() {
    Vec pos = {0.0f, 0.0f, 0.0f};
    Vec target = {0.0f, 0.0f, -100.0f};
    activate_camera_mode(9);
    set_active_camera_pose(&pos, &target);
    switch (this->state) {
    case 0:
        this->state = 1;
    case 1:
        if (this->option_window != NULL) {
            if (this->option_window->is_finished() != 0) {
                this->state = 2;
            } else {
                this->selection = this->option_window->get_dial_selection();
                if (this->selection != 4) {
                    this->state = 2;
                }
            }
        }
        break;
    case 2:
        if (this->option_window != NULL) {
            this->option_window->queue_destruction();
            this->option_window = NULL;
        }
        this->state = 3;
    case 3:
        if (TAdPlayerLoadGC::get_instance() == 0) {
            this->state = 4;
        }
        break;
    case 4:
        if (this->card == NULL) {
            this->card = TCheckMemoryCard::create_system_file_check(this, NULL, 0);
        }
        this->state = 5;
    case 5:
        if (this->card != NULL && this->card->is_card_ready() == 1) {
            this->card->queue_destruction();
            this->card = NULL;
            if (TAdSinglePlyChrSelectGC::verify_system_file() != 0) {
                pso_system_load_gc();
            }
            this->timer = 0;
            this->state = 6;
        }
        break;
    case 6:
        if (TAdPlayerLoadGC::get_instance() == 0) {
            this->state = 8;
        } else {
            DialingWindowPos a = {80.0f, 176.0f};
            DialingWindowPos b = {479.0f, 207.0f};
            this->window = create_message_window_for_size((NJS_POINT2 *)&a, (NJS_POINT2 *)&b);
            ((TWindowMessage *)(this->window))->append_line(get_message_text(0xC), 1);
            this->state = 7;
        }
        break;
    case 7:
        if (TAdPlayerLoadGC::get_instance() == 0) {
            this->window->close();
            this->window = NULL;
            this->state = 8;
        }
        break;
    case 8:
        this->timer++;
        if ((f32)this->timer > 7.5f) {
            this->update_dial_image();
            this->state = 9;
            TAdMultiChgGameModeGC::open_time_set_scene();
        }
        break;
    case 9:
        break;
    }
}

TAdDialingSelectGC::~TAdDialingSelectGC() {
    stop_audio_streams();
    if (this->card != NULL) {
        this->card->queue_destruction();
        this->card = NULL;
    }
    if (this->window != NULL) {
        this->window->queue_destruction();
        this->window = NULL;
    }
    if (this->option_window != NULL) {
        this->option_window->queue_destruction();
        this->option_window = NULL;
    }
}

TAdDialingSelectGC::TAdDialingSelectGC() : TObject(tl_00) {
    void *o;
    void *o2;
    o = new TAdBackGC(this);
    o2 = new TAdBackTxtGC(this);
    new TAdTitleGC(this, 3);
    set_fallback_main_phase(9);
    this->selection = 4;
    this->state = 0;
    this->timer = 0;
    this->option_window = new TWindowOptionCtrl(this);
    this->window = NULL;
    this->card = NULL;
}

s32 TWindowOptionCtrl::get_dial_selection() { return dial_selection; }
int TWindowOptionCtrl::is_finished() { return flags & 0x1; }

// Bits 16-17 of the client's character save record word at +0x10.
s32 TWindowShortListCtrl::get_card_window_flags(s32 client_id) {
    CharacterSaveRecord *record = get_character_save_record(client_id);
    if (record == NULL) {
        return 0;
    }
    return (record->card_window_flags >> 0x10) & 3;
}

// Bits 13-15 of the client's character save record word at +0x10.
s32 get_card_status_bits(s32 client_id) {
    CharacterSaveRecord *record = get_character_save_record(client_id);
    if (record == NULL) {
        return 0;
    }
    return (record->card_window_flags >> 0xD) & 7;
}

// Card window scale for each of the four card window flag values.
const f32 card_window_scale_table[4] = {34.0f, 51.0f, 68.0f, 0.0f};

// Idle time allowed for each idle timeout setting.
const s32 short_list_ctrl_interval_table[6] = {900, 1800, 2700, 3600, 0, 0};

s32 get_idle_timeout_limit(u32 client_id) {
    return short_list_ctrl_interval_table[get_idle_timeout_setting(client_id)];
}

// Bits 10-12 of the client's character save record word at +0x10 (the idle timeout setting).
s32 get_idle_timeout_setting(u32 client) {
    CharacterSaveRecord *record = get_character_save_record(client);
    if (record == NULL) {
        return 0;
    }
    return (record->card_window_flags >> 0xA) & 7;
}

f32 TWindowSubStatusDisp::get_card_window_scale(s32 client_id) {
    return card_window_scale_table[get_card_window_flags(client_id)];
}

// Bits 8-9 of the client's character save record word at +0x10 (1 when the slot has no record).
s32 TWindowSubStatusDisp::get_card_window_flags(s32 client_id) {
    if (client_id >= 4) {
        client_id = local_client_id;
    }
    CharacterSaveRecord *record = get_character_save_record(client_id);
    if (record == NULL) {
        return 1;
    }
    return (record->card_window_flags >> 8) & 3;
}
