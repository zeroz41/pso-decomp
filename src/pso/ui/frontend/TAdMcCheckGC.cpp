#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/quest/TQuestThread.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdMcCheckGC.h"
#include "pso/unk/TUnk_804EFA88.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowMenu.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#undef PSO_SDK_COMPACT_MATH

extern "C" {
s32 create_window_menu_default(const void *, s32);
}

void clear_draw_record(IndirectDrawRecord *record) {
    record->texlist = NULL;
    record->model = NULL;
}
void TAdMcCheckGC::render() {  }

// Check-window position for slots A and B.
static const NJS_POINT2 mc_check_window_positions[2] = {
    {85.0f, 183.0f},
    {371.0f, 183.0f},
};

TObject *TAdMcCheckGC::create(s32 message) {
    saddr window_menu_default;

    window_menu_default = create_window_menu_default(&mc_check_window_positions[this->card_slot], 1);
    ((TWindowMenu *)window_menu_default)->add_text_entry(get_localized_text_entry(0x16, message), 0x20, 0);
    ((TWindowMenu *)window_menu_default)->set_flag_40();
    TQuestThread::set_status_flag_80((void *)window_menu_default);
    ((TWindowSubComCard *)window_menu_default)->calc_layout_height(190.0f);
    return reinterpret_cast<TObject *>(window_menu_default);
}

void TAdMcCheckGC::run_task() {

    if (TAdPlayerLoadGC::probe_card_slot(this->card_slot) == 0) {
        this->check_step = 0;
        if (this->warning_windows[0] != NULL) {
            this->warning_windows[0]->queue_destruction();
            this->warning_windows[0] = NULL;
        }
        if (this->warning_windows[2] != NULL) {
            this->warning_windows[2]->queue_destruction();
            this->warning_windows[2] = NULL;
        }
        if (this->warning_windows[1] != NULL) {
            this->warning_windows[1]->queue_destruction();
            this->warning_windows[1] = NULL;
        }
        if (this->warning_windows[3] != NULL) {
            this->warning_windows[3]->queue_destruction();
            this->warning_windows[3] = NULL;
        }
    }
    switch (this->check_step) {
    case 0:
        if (TAdPlayerLoadGC::probe_card_slot(this->card_slot) != 0) {
            this->check_step = 1;
        }
        break;
    case 1:
        if ((TAdPlayerLoadGC::probe_and_check_card(this->card_slot) == 0) && ((u32) (TAdPlayerLoadGC::get_load_result(this->card_slot) + 0x10000) == 0xFF83U)) {
            if (((s32) this->step_frames > 0xA) && (this->warning_windows[0] == NULL)) {
                this->warning_windows[0] = create(this->card_slot + 2);
            }
        } else {
            this->check_step = 2;
            if (this->warning_windows[0] != NULL) {
                this->warning_windows[0]->queue_destruction();
                this->warning_windows[0] = NULL;
            }
        }
        break;
    case 2:
        if ((TAdPlayerLoadGC::probe_and_check_card(this->card_slot) == 0) && ((u32) (TAdPlayerLoadGC::get_load_result(this->card_slot) + 0x10000) == 0xFF21U)) {
            if (((s32) this->step_frames > 0xA) && (this->warning_windows[1] == NULL)) {
                this->warning_windows[1] = create(this->card_slot + 4);
            }
        } else {
            this->check_step = 3;
            if (this->warning_windows[1] != NULL) {
                this->warning_windows[1]->queue_destruction();
                this->warning_windows[1] = NULL;
            }
        }
        break;
    case 3:
        if (TAdPlayerLoadGC::probe_and_check_card(this->card_slot) != 0) {
            if ((s32) this->card_slot == 1) {
                this->check_step = 5;
            } else {
                this->check_step = 4;
            }
            if (this->warning_windows[2] != NULL) {
                this->warning_windows[2]->queue_destruction();
                this->warning_windows[2] = NULL;
            }
        } else if (((s32) this->step_frames > 0xA) && (this->warning_windows[2] == NULL)) {
            this->warning_windows[2] = create(this->card_slot + 6);
        }
        break;
    case 4:
        if (TAdPlayerLoadGC::check_memcard_status(this->card_slot) == 0) {
            this->check_step = 5;
            if (this->warning_windows[3] != NULL) {
                this->warning_windows[3]->queue_destruction();
                this->warning_windows[3] = NULL;
            }
        } else if (((s32) this->step_frames > 0xA) && (this->warning_windows[3] == NULL)) {
            this->warning_windows[3] = create(this->card_slot + 8);
        }
        break;
    case 5:
        break;
    }
    if ((s32) this->previous_step != (s32) this->check_step) {
        this->step_frames = 0;
    } else {
        this->step_frames = (this->step_frames + 1);
    }
    this->previous_step = (s32) this->check_step;
}

const char *TAdMcCheckGC__name = "TAdMcCheckGC";

TAdMcCheckGC::~TAdMcCheckGC() {
    if (memcard_cursor_instance_table[card_slot] != NULL) {
        memcard_cursor_instance_table[card_slot] = NULL;
    }
    if (this->warning_windows[0] != NULL) {
        this->warning_windows[0]->queue_destruction();
        this->warning_windows[0] = NULL;
    }
    if (this->warning_windows[1] != NULL) {
        this->warning_windows[1]->queue_destruction();
        this->warning_windows[1] = NULL;
    }
    if (this->warning_windows[2] != NULL) {
        this->warning_windows[2]->queue_destruction();
        this->warning_windows[2] = NULL;
    }
    if (this->warning_windows[3] != NULL) {
        this->warning_windows[3]->queue_destruction();
        this->warning_windows[3] = NULL;
    }
}
TAdMcCheckGC::TAdMcCheckGC(TObject *object, s32 slot) : TObject(object) {
    this->m_name = TAdMcCheckGC__name;
    card_slot = slot;
    this->check_step = 0;
    previous_step = check_step;
    this->step_frames = 0;
    this->warning_windows[0] = 0;
    this->warning_windows[1] = 0;
    this->warning_windows[2] = 0;
    this->warning_windows[3] = 0;
}

TAdMcCheckGC *memcard_cursor_instance_table[2] = { NULL, NULL };
