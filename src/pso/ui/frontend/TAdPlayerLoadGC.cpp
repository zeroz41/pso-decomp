// Built with -inline off,deferred: the functions are generated in reverse source order, so
// they are defined here from the last one in .text to the first.
#include "pso/system/save/CardSaveFile.h"
#include "pso/system/save/CardFileInfo.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "types.h"
const char *TAdPlayerLoadGC__class_name = "TAdPlayerLoadGC";

extern "C" {
extern int TAdPlayerLoadGC__load_state;
extern int TAdChrSelBSlotGC__global_state;
}

void set_character_select_b_slot_state(int a0) { TAdChrSelBSlotGC__global_state = a0; }

int get_player_load_state(void) { return TAdPlayerLoadGC__load_state; }

TAdPlayerLoadGC::TAdPlayerLoadGC(TObject *parent, int mode) : TObject(parent) {
    m_name = TAdPlayerLoadGC__class_name;
    state = 0;
    this->mode = mode;
    set_state(0);
}

TAdPlayerLoadGC::~TAdPlayerLoadGC() {}

void TAdPlayerLoadGC::run_task() {
    set_character_select_b_slot_state((int)state);
    if (probe_card_slot(0) == 0) {
        state = 0U;
    }
    switch (state) {
    case 0:
        if (mode == 2) {
            if ((poll_memcard_result(1) == 0) && (probe_card_slot(0) != 0)) {
                state = 1U;
            }
        } else if (probe_card_slot(0) != 0) {
            state = 1U;
        }
        break;
    case 1:
        if ((probe_and_check_card(0) != 0) || ((u32)get_load_result(0) != 0xFFFFFF83U)) {
            state = 2U;
        }
        break;
    case 2:
        if ((probe_and_check_card(0) != 0) || ((u32)get_load_result(0) != 0xFFFFFF21U)) {
            state = 3U;
        }
    case 3:
        if (probe_and_check_card(0) != 0) {
            state = 4U;
        }
        break;
    case 4:
        if (check_memcard_status(0) == 0) {
            state = 5U;
        }
        break;
    case 5:
        if ((u32)find_card_file(0, pso_character_card_filename.filename) != 0xFFFFFF41U) {
            state = 6U;
        }
        break;
    case 6:
        if ((find_card_file(0, pso_character_card_filename.filename) == 0) && (get_instance() == 0)) {
            state = 7U;
        }
        break;
    case 7:
        if ((u32)find_card_file(0, pso_system_card_filename) != 0xFFFFFF41U) {
            state = 8U;
        }
        break;
    case 8:
        if ((u32)TAdSinglePlyChrSelectGC::load_system_file_flag() != 0xFFFFFF05U) {
            state = 9U;
        }
        break;
    case 9:
        if (get_instance() == 0) {
            state = 0xAU;
        }
        break;
    case 10:
        if (check_slot_a_card_save() != 1) {
            state = 0xBU;
        }
        break;
    case 11:
        if (check_slot_a_card_save() != 5) {
            state = 0xCU;
        }
        break;
    case 12:
        if (mode == 1) {
            state = 0xDU;
        }
        break;
    case 13:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else {
            state = 0xEU;
        }
        break;
    case 14:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if ((probe_and_check_card(1) != 0) || ((u32)get_load_result(1) != 0xFFFFFF83U)) {
            state = 0xFU;
        }
        break;
    case 15:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if ((probe_and_check_card(1) != 0) || ((u32)get_load_result(1) != 0xFFFFFF21U)) {
            state = 0x10U;
        }
    case 16:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if (probe_and_check_card(1) != 0) {
            state = 0x11U;
        }
        break;
    case 17:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if (check_memcard_status(1) == 0) {
            state = 0x12U;
        }
        break;
    case 18:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if ((u32)find_card_file(1, pso_character_card_filename.filename) != 0xFFFFFF41U) {
            state = 0x13U;
        }
        break;
    case 19:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if ((find_card_file(1, pso_character_card_filename.filename) == 0) && (get_instance() == 0)) {
            state = 0x14U;
        }
        break;
    case 20:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if ((u32)find_card_file(1, pso_system_card_filename) != 0xFFFFFF41U) {
            state = 0x15U;
        }
        break;
    case 21:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if ((find_card_file(1, pso_character_card_filename.filename) == 0) && ((u32)TAdSinglePlyChrSelectGC::check_system_load_result() != 0xFFFFFF05U)) {
            state = 0x16U;
        }
        break;
    case 22:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if (get_instance() == 0) {
            state = 0x17U;
        }
        break;
    case 23:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if (check_slot_b_card_save() != 1) {
            state = 0x18U;
        }
        break;
    case 24:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if (check_slot_b_card_save() != 5) {
            state = 0x19U;
        }
        break;
    case 25:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        }
        break;
    }
    if (get_player_load_state() != 0) {
        set_state(0);
        state = 0U;
    }
}

void TAdPlayerLoadGC::render() {}
