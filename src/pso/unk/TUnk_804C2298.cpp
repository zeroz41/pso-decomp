#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/unk/TUnk_804C2298.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/ProgressMessageWindow.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowShortListCtrl_801A4FC0.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/system/save/TCheckMemoryCard.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject.h"
#include "pso/network/client_id.h"
#include "pso/unk/TLobby.h"
#include "pso/camera/TCameraCtrl.h"

typedef struct WindowPos {
    f32 a, b;
} WindowPos;

extern "C" {
s32 verify_system_file__23TAdSinglePlyChrSelectGCFPv(void);
s32 pso_system_load_gc(void);
void *__ct__10TAdTitleGCFP7TObjectl(void *, void *, int);
}

extern void *tl_00;

void TUnk_804C2298::run_task() {
    Vec pos = {0.0f, 0.0f, 0.0f};
    Vec target = {0.0f, 0.0f, -100.0f};
    activate_camera_mode(9);
    set_active_camera_pose(&pos, &target);
    switch (this->state) {
    case 0:
        this->state = 1;
    case 1:
        if (this->list != NULL) {
            if (TWindowShortListCtrl__sub_801A5144(this->list) != 0) {
                this->state = 2;
            } else {
                this->selection = TWindowShortListCtrl__sub_801A513C(this->list);
                if (this->selection != 4) {
                    this->state = 2;
                }
            }
        }
        break;
    case 2:
        if (this->list != NULL) {
            this->list->queue_destruction();
            this->list = NULL;
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
            if (verify_system_file__23TAdSinglePlyChrSelectGCFPv() != 0) {
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
            WindowPos a = {80.0f, 176.0f};
            WindowPos b = {479.0f, 207.0f};
            this->window = (TWindowMessage *)create_message_window_for_size((NJS_POINT2 *)&a, (NJS_POINT2 *)&b);
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
            this->sub_801A4CA4();
            this->state = 9;
            TAdMultiChgGameModeGC::request_scene_change();
        }
        break;
    case 9:
        break;
    }
}

TUnk_804C2298::~TUnk_804C2298() {
    TLobby::stop_audio_streams();
    if (this->card != NULL) {
        this->card->queue_destruction();
        this->card = NULL;
    }
    if (this->window != NULL) {
        this->window->queue_destruction();
        this->window = NULL;
    }
    if (this->list != NULL) {
        this->list->queue_destruction();
        this->list = NULL;
    }
}

TUnk_804C2298::TUnk_804C2298() : TObject((TObject *)tl_00) {
    void *o;
    void *o2;
    void *o3;
    o = new TAdBackGC(this);
    o2 = new TAdBackTxtGC(this);
    o3 = TObject::operator new(0x138);
    if (o3 != NULL) {
        __ct__10TAdTitleGCFP7TObjectl(o3, this, 3);
    }
    TKeyBoardControl__sub_8000F90C(9);
    this->selection = 4;
    this->state = 0;
    this->timer = 0;
    this->list = new TWindowOptionCtrl(this);
    this->window = NULL;
    this->card = NULL;
}

s32 TWindowShortListCtrl__sub_801A513C(void *p) { return *(s32 *)((char *)p + 0x24); }
int TWindowShortListCtrl__sub_801A5144(void *p) { return *(u8 *)((char *)p + 0x1d) & 0x1; }

// Bits 16-17 of the client's character save record word at +0x10.
s32 TWindowShortListCtrl::get_card_window_flags(s32 client_id) {
    u32 *record = (u32 *)get_character_save_record(client_id);
    if (record == NULL) {
        return 0;
    }
    return (record[4] >> 0x10) & 3;
}

// Bits 13-15 of the client's character save record word at +0x10.
s32 TWindowShortListCtrl::get_card_status_bits(s32 client_id) {
    u32 *record = (u32 *)get_character_save_record(client_id);
    if (record == NULL) {
        return 0;
    }
    return (record[4] >> 0xD) & 7;
}

// Card window scale for each of the four card window flag values.
const f32 card_window_scale_table[4] = {34.0f, 51.0f, 68.0f, 0.0f};

// Idle timeout in frames for each idle timeout setting (fn_801A51F0); 900 frames = 15 s.
const s32 short_list_ctrl_interval_table[6] = {900, 1800, 2700, 3600, 0, 0};

s32 TLobby::get_table_entry_by_index() {
    // The caller's client id passes through in r3: the parameter comes back with the hand-mangled
    // callers in TPlyJoinLobbyEntry.cpp.
    return short_list_ctrl_interval_table[((s32 (*)())fn_801A51F0)()];
}

// Bits 10-12 of the client's character save record word at +0x10 (the idle timeout setting).
s32 fn_801A51F0(u32 client) {
    u32 *record = (u32 *)get_character_save_record(client);
    if (record == NULL) {
        return 0;
    }
    return (record[4] >> 0xA) & 7;
}

f32 TWindowSubStatusDisp::get_card_window_scale(s32 client_id) {
    return card_window_scale_table[get_card_window_flags(client_id)];
}

// Bits 8-9 of the client's character save record word at +0x10 (1 when the slot has no record).
s32 TWindowSubStatusDisp::get_card_window_flags(s32 client_id) {
    if (client_id >= 4) {
        client_id = local_client_id;
    }
    u32 *record = (u32 *)get_character_save_record(client_id);
    if (record == NULL) {
        return 1;
    }
    return (record[4] >> 8) & 3;
}
