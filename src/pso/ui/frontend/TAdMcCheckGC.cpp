#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/quest/TQuestThread.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdMcCheckGC.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowMenu.h"

extern "C" {
s32 GXSetTexCoordGen2(s32, s32, s32, s32, s32, s32);
s32 create_window_menu_default(const void *, s32);
}

void set_tex_coord_gen2(s32 arg0, s32 func, s32 arg2, s32 mtx) {
    GXSetTexCoordGen2(arg0, func, arg2, mtx, 0, 0x7D);
}
void TLobby__sub_8033EE38(void* p) { *(s32*)((char*)p + 0x18) = 0; *(s32*)((char*)p + 0x1c) = 0; }
void TAdMcCheckGC::render() {  }

// Check-window position for slots A and B.
static const NJS_POINT2 mc_check_window_positions[2] = {
    {85.0f, 183.0f},
    {371.0f, 183.0f},
};

TObject *TAdMcCheckGC::create(s32 arg1) {
    saddr window_menu_default;

    window_menu_default = create_window_menu_default(&mc_check_window_positions[this->card_slot], 1);
    ((TWindowMenu *)window_menu_default)->add_text_entry(get_localized_text_entry(0x16, arg1), 0x20, 0);
    ((TWindowMenu *)window_menu_default)->set_flag_40();
    TQuestThread::set_status_flag_80((void *)window_menu_default);
    ((TWindowSubComCard *)window_menu_default)->calc_layout_height(190.0f);
    return reinterpret_cast<TObject *>(window_menu_default);
}

void TAdMcCheckGC::run_task() {

    if (TAdPlayerLoadGC::probe_card_slot(this->card_slot) == 0) {
        this->m_1c = 0;
        if (this->m_2c != NULL) {
            this->m_2c->queue_destruction();
            this->m_2c = NULL;
        }
        if (this->m_34 != NULL) {
            this->m_34->queue_destruction();
            this->m_34 = NULL;
        }
        if (this->m_30 != NULL) {
            this->m_30->queue_destruction();
            this->m_30 = NULL;
        }
        if (this->m_38 != NULL) {
            this->m_38->queue_destruction();
            this->m_38 = NULL;
        }
    }
    switch (this->m_1c) {
    case 0:
        if (TAdPlayerLoadGC::probe_card_slot(this->card_slot) != 0) {
            this->m_1c = 1;
        }
        break;
    case 1:
        if ((TAdPlayerLoadGC::probe_and_check_card(this->card_slot) == 0) && ((u32) (TAdPlayerLoadGC::get_load_result(this->card_slot) + 0x10000) == 0xFF83U)) {
            if (((s32) this->m_24 > 0xA) && (this->m_2c == NULL)) {
                this->m_2c = create(this->card_slot + 2);
            }
        } else {
            this->m_1c = 2;
            if (this->m_2c != NULL) {
                this->m_2c->queue_destruction();
                this->m_2c = NULL;
            }
        }
        break;
    case 2:
        if ((TAdPlayerLoadGC::probe_and_check_card(this->card_slot) == 0) && ((u32) (TAdPlayerLoadGC::get_load_result(this->card_slot) + 0x10000) == 0xFF21U)) {
            if (((s32) this->m_24 > 0xA) && (this->m_30 == NULL)) {
                this->m_30 = create(this->card_slot + 4);
            }
        } else {
            this->m_1c = 3;
            if (this->m_30 != NULL) {
                this->m_30->queue_destruction();
                this->m_30 = NULL;
            }
        }
        break;
    case 3:
        if (TAdPlayerLoadGC::probe_and_check_card(this->card_slot) != 0) {
            if ((s32) this->card_slot == 1) {
                this->m_1c = 5;
            } else {
                this->m_1c = 4;
            }
            if (this->m_34 != NULL) {
                this->m_34->queue_destruction();
                this->m_34 = NULL;
            }
        } else if (((s32) this->m_24 > 0xA) && (this->m_34 == NULL)) {
            this->m_34 = create(this->card_slot + 6);
        }
        break;
    case 4:
        if (TAdPlayerLoadGC::check_memcard_status(this->card_slot) == 0) {
            this->m_1c = 5;
            if (this->m_38 != NULL) {
                this->m_38->queue_destruction();
                this->m_38 = NULL;
            }
        } else if (((s32) this->m_24 > 0xA) && (this->m_38 == NULL)) {
            this->m_38 = create(this->card_slot + 8);
        }
        break;
    case 5:
        break;
    }
    if ((s32) this->m_20 != (s32) this->m_1c) {
        this->m_24 = 0;
    } else {
        this->m_24 = (this->m_24 + 1);
    }
    this->m_20 = (s32) this->m_1c;
}

const char *TAdMcCheckGC__name = "TAdMcCheckGC";

TAdMcCheckGC::~TAdMcCheckGC() {
    s32 offset = card_slot * sizeof(TAdMcCheckGC *);
    if (*reinterpret_cast<TAdMcCheckGC **>(reinterpret_cast<u8 *>(memcard_cursor_instance_table) + offset) != NULL) {
        *reinterpret_cast<TAdMcCheckGC **>(reinterpret_cast<u8 *>(memcard_cursor_instance_table) + offset) = NULL;
    }
    if (this->m_2c != NULL) {
        this->m_2c->queue_destruction();
        this->m_2c = NULL;
    }
    if (this->m_30 != NULL) {
        this->m_30->queue_destruction();
        this->m_30 = NULL;
    }
    if (this->m_34 != NULL) {
        this->m_34->queue_destruction();
        this->m_34 = NULL;
    }
    if (this->m_38 != NULL) {
        this->m_38->queue_destruction();
        this->m_38 = NULL;
    }
}
TAdMcCheckGC::TAdMcCheckGC(TObject *object, s32 slot) : TObject(object) {
    this->m_name = TAdMcCheckGC__name;
    card_slot = slot;
    this->m_1c = 0;
    m_20 = m_1c;
    this->m_24 = 0;
    this->m_2c = 0;
    this->m_30 = 0;
    this->m_34 = 0;
    this->m_38 = 0;
}

TAdMcCheckGC *memcard_cursor_instance_table[2] = { NULL, NULL };
