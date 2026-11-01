#include "pso/TAdTimeSetGC.h"
#include "pso/misc/TWindowBase.h"
#include "pso/TObject.h"
#include "pso/menu/T_ATS_DrawCalendar.h"
#include "pso/menu/TAdTimeSetGC.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_802E13C8.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
extern "C" {
s32 poll_load_status__12TAdTimeSetGCFv();
}
extern void *lbl_804E32A4[];

#pragma opt_common_subs off
void TAdTimeSetGC::run_task() {
  TAdTimeSetGCStateAction *entry_action;
  load_status = poll_load_status__12TAdTimeSetGCFv();
  if (load_status & 1)
  {
    change_state(0);
  }
  TAdTimeSetGCStateAction action = *(entry_action = &((TAdTimeSetGCStateActions *)lbl_804E32A4)[state_index].task);
  if (action != 0)
  {
    (this->*action)();
  }
  --timer;
  if (timer < 0)
  {
    timer = 0;
  }
}
#pragma opt_common_subs reset

TAdTimeSetGC::~TAdTimeSetGC() {
    if (owned_object != NULL) {
        delete owned_object;
        owned_object = NULL;
    }
    if (window != NULL) {
        ((TWindowBase *)window)->close();
        window = NULL;
    }
    if (queued_object != NULL) {
        queue_destruction__7TObjectFv(queued_object);
        queued_object = NULL;
    }
}

#include "types.h"
#include "pso/misc/TLobby.h"

extern "C" {

void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__12TAdTimeSetGC[];
extern void *TAdTimeSetGC_class_name;

void *TAdTimeSetGC__ct(void *ad_time_set_gc) {
    __ct__7TObjectFP7TObject(ad_time_set_gc);
    *(s32 **)((s8 *)ad_time_set_gc + 0x18) = __vt__12TAdTimeSetGC;
    *(void * *)&((TAdTimeSetGC *)ad_time_set_gc)->m_name = TAdTimeSetGC_class_name;
    init__23TAdSinglePlyChrSelectGCFPv(ad_time_set_gc);
    TLobby::stop_audio_streams();
    return ad_time_set_gc;
}

void TAdTimeSetGC__sub_802E34A4(void) {  }
void TAdTimeSetGC__sub_802E34A8(void) {  }

}

extern "C" void render__18T_ATS_DrawCalendarFv();
extern "C" void TAdSinglePlyChrSelectGC__sub_802E24B8();
extern "C" void TAdSinglePlyChrSelectGC__sub_802E2588();
extern "C" void handle_confirm_menu__23TAdSinglePlyChrSelectGCFv();
extern "C" void report_card_status__23TAdSinglePlyChrSelectGCFv();
extern "C" void build_selection_summary__23TAdSinglePlyChrSelectGCFv();
extern "C" void close_and_next_cancel__23TAdSinglePlyChrSelectGCFv();
extern "C" void ensure_player_loaded__23TAdSinglePlyChrSelectGCFv();
extern "C" void ensure_system_file_loaded__23TAdSinglePlyChrSelectGCFv();
extern "C" void init_menu_window__23TAdSinglePlyChrSelectGCFv();
extern "C" void init_screen__23TAdSinglePlyChrSelectGCFv();
extern "C" void open_char_select__23TAdSinglePlyChrSelectGCFv();
extern "C" void rebuild_and_maybe_close__23TAdSinglePlyChrSelectGCFv();
extern "C" void render_shadows__7TObjectFv();
extern "C" void reset_on_load_complete__23TAdSinglePlyChrSelectGCFv();
extern "C" void run_task__7TObjectFv();
extern "C" void try_setup__23TAdSinglePlyChrSelectGCFv();
extern "C" void update_char_timer__23TAdSinglePlyChrSelectGCFv();
extern "C" void update_close_on_load__23TAdSinglePlyChrSelectGCFv();
extern "C" void update_close_timer__23TAdSinglePlyChrSelectGCFv();
extern "C" void update_load_countdown__23TAdSinglePlyChrSelectGCFv();
extern "C" void update_load_state__23TAdSinglePlyChrSelectGCFv();
extern "C" void update_timer__23TAdSinglePlyChrSelectGCFv();
__declspec(section ".data") void *lbl_804E3040[2] = {
    (void *)0x0, (void *)0x42b40000,
};
__declspec(section ".data") void *lbl_804E3048[2] = {
    (void *)0x0, (void *)0x0,
};
void *lbl_804E3050[149] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)&rebuild_and_maybe_close__23TAdSinglePlyChrSelectGCFv, (void *)0x0, (void *)0xffffffff, (void *)&report_card_status__23TAdSinglePlyChrSelectGCFv,
    (void *)0x0, (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC__sub_802E3038, (void *)0x0,
    (void *)0xffffffff, (void *)&ensure_system_file_loaded__23TAdSinglePlyChrSelectGCFv, (void *)0x0, (void *)0xffffffff,
    (void *)&TAdSinglePlyChrSelectGC__sub_802E2FEC, (void *)0x0, (void *)0xffffffff, (void *)&update_load_state__23TAdSinglePlyChrSelectGCFPv,
    (void *)0x0, (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC__sub_802E2F68, (void *)0x0,
    (void *)0xffffffff, (void *)&ensure_player_loaded__23TAdSinglePlyChrSelectGCFv, (void *)0x0, (void *)0xffffffff,
    (void *)&TAdSinglePlyChrSelectGC__sub_802E2F20, (void *)0x0, (void *)0xffffffff, (void *)&reset_on_load_complete__23TAdSinglePlyChrSelectGCFv,
    (void *)0x0, (void *)0xffffffff, (void *)&open_char_select__23TAdSinglePlyChrSelectGCFv, (void *)0x0,
    (void *)0xffffffff, (void *)&handle_confirm_menu__23TAdSinglePlyChrSelectGCFv, (void *)0x0, (void *)0xffffffff,
    (void *)&close_and_next_cancel__23TAdSinglePlyChrSelectGCFv, (void *)0x0, (void *)0xffffffff, (void *)&update_load_state__23TAdSinglePlyChrSelectGCFv,
    (void *)0x0, (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC__sub_802E2D3C, (void *)0x0,
    (void *)0xffffffff, (void *)&update_load_countdown__23TAdSinglePlyChrSelectGCFv, (void *)0x0, (void *)0xffffffff,
    (void *)&TAdSinglePlyChrSelectGC::close_scene, (void *)0x0, (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC__sub_802E2BD4,
    (void *)0x0, (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC__sub_802E2BC8, (void *)0x0,
    (void *)0xffffffff, (void *)&update_timer__23TAdSinglePlyChrSelectGCFv, (void *)0x0, (void *)0xffffffff,
    (void *)&TAdSinglePlyChrSelectGC::create_backgrounds, (void *)0x0, (void *)0xffffffff, (void *)&advance_when_load_done__23TAdSinglePlyChrSelectGCFi,
    (void *)0x0, (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC__sub_802E2A7C, (void *)0x0,
    (void *)0xffffffff, (void *)&update_char_timer__23TAdSinglePlyChrSelectGCFv, (void *)0x0, (void *)0xffffffff,
    (void *)&init_screen__23TAdSinglePlyChrSelectGCFv, (void *)0x0, (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC__sub_802E289C,
    (void *)0x0, (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC__sub_802E2848, (void *)0x0,
    (void *)0xffffffff, (void *)&update_close_timer__23TAdSinglePlyChrSelectGCFv, (void *)0x0, (void *)0xffffffff,
    (void *)&update_state__23TAdSinglePlyChrSelectGCFi, (void *)0x0, (void *)0xffffffff, (void *)&try_setup__23TAdSinglePlyChrSelectGCFv,
    (void *)0x0, (void *)0xffffffff, (void *)&update_close_on_load__23TAdSinglePlyChrSelectGCFv, (void *)0x0,
    (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC__sub_802E2610, (void *)0x0, (void *)0xffffffff,
    (void *)&TAdSinglePlyChrSelectGC__sub_802E2588, (void *)0x0, (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC__sub_802E2520,
    (void *)0x0, (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC__sub_802E24B8, (void *)0x0,
    (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC__sub_802E2450, (void *)0x0, (void *)0xffffffff,
    (void *)&TAdSinglePlyChrSelectGC__sub_802E24B8, (void *)0x0, (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC__sub_802E23E8,
    (void *)0x0, (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC__sub_802E22A4, (void *)0x0,
    (void *)0xffffffff, (void *)&init_menu_window__23TAdSinglePlyChrSelectGCFv, (void *)0x0, (void *)0xffffffff,
    (void *)&TAdSinglePlyChrSelectGC__sub_802E22A4, (void *)0x0, (void *)0xffffffff, (void *)&build_selection_summary__23TAdSinglePlyChrSelectGCFv,
    (void *)0x0, (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC__sub_802E22A4, (void *)0x0,
    (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC::create_result_bg, (void *)0x0, (void *)0xffffffff,
    (void *)&TAdSinglePlyChrSelectGC__sub_802E2158, (void *)0x0, (void *)0xffffffff, (void *)&show_confirm_dialog__23TAdSinglePlyChrSelectGCFPv,
    (void *)0x0, (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC__sub_802E1FAC, (void *)0x0,
    (void *)0xffffffff, (void *)&TAdSinglePlyChrSelectGC__sub_802E1F8C, (void *)0x0, (void *)0xffffffff,
    (void *)&update_state__23TAdSinglePlyChrSelectGCFPv,
};
void *lbl_804E32A4[150] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};
void *lbl_804E34FC[6] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__18T_ATS_DrawCalendarFv, (void *)&run_task__7TObjectFv,
    (void *)&render__18T_ATS_DrawCalendarFv, (void *)&render_shadows__7TObjectFv,
};
