#include "types.h"
#include "pso/ui/TAdEnterPPPPassGC.h"
#include "pso/unk/text_8014618C.h"
#include "pso/TLevelSelect.h"
#include "pso/TMainTask.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/ui/TAdEnterBaseGC.h"
#include "pso/ui/TAdEnterSerialAccessGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestThread.h"

struct RecoveredGlobal_80339480_lbl_804EF500 {
    s32 value;
    u8 remaining[0x94];
};

struct RecoveredGlobal_803392F4_lbl_80477C20 {
    s32 value;
    u8 remaining[0x1C];
};

struct TAdEnterPPPPassGC {
    virtual void m0();
    char pad[0x18];
    s32 state;
    s32 f20;
    s32 f24;
    void open_keyboard_window(void *);
    void update_password_input(void *);
    void request_transition(void *);
    void forward_chg_game_mode(void *);
    void close_windows_and_advance(void *);
};
typedef TAdEnterPPPPassGC TAdEnterPPPPassGC_80339378;
typedef void (TAdEnterPPPPassGC_80339378::*Pmf_80339378)();

struct T_8033954C { s32 f0; u8 pad[0x14]; void *vt; u8 pad2[0x40 - 0x1C]; s32 f40; };

extern "C" {
void queue_destruction__7TObjectFv(void *);
void TWindow__close(u8 *arg0);
extern u8 *password_entry_keyboard_control;
extern s32 password_entry_dispatch_state;
extern const f32 lbl_805DF9E8;
void strncpy(s32, s32, s32);
s32 memset(void *, int, int);
extern TAdEnterBaseGC::Position password_screen_status_line_position[];
s32 create_default_callback__22TAdEnterSerialAccessGCFv(void *);
extern RecoveredGlobal_803392F4_lbl_80477C20 TAdEnterPPPPassGC__selection_positions;
void TKeyBoardControl__sub_8000F9CC(int);
s32 TLobby__sub_80145A94(void);
s32 TLobby__sub_80145DB4(int);
s8 *TLobby__sub_80146D14(void);
s8 *TLobby__sub_80146D44(void);
int reset_mode_state__21TAdMultiChgGameModeGCFv(void*);
void TAdEnterBaseGC__ct(void *);
extern s32 __vt__17TAdEnterPPPPassGC[];
extern s32 TAdEnterPPPPassGC__name;
T_8033954C *TAdEnterPPPPassGC__ct(T_8033954C *arg0);
char *realloc_buffer__17TWindowSubComCardFv(u8 *);
void mem_free(void *);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
void play_sound_effect(int, int, int, int);
s32 forward_input__22TAdEnterSerialAccessGCFPv(void *, int, char *);
s32 strlen(const char *);
extern u8 controller_input_state[];
extern u8 controller_physical_port_bank[];
extern s32 lbl_805DF9EC;
void __dl__7TObjectFPv(void *);
void *__dt__14TAdEnterBaseGCFv(void *arg0, s16 arg1);
int request_transition__21TAdMultiChgGameModeGCFv(void*);

void render__17TAdEnterPPPPassGCFv(void *self) {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

void close_windows_and_advance__17TAdEnterPPPPassGCFPv(u8 *arg0) {
    s32 temp_r4;
    u8 *temp_r3;
    u8 *temp_r3_2;
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x30));
    if (temp_r3 != NULL) {
        TWindow__close(temp_r3);
        *(u8 **)((s8 *)arg0 + 0x30) = NULL;
    }
    temp_r3_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x34));
    if (temp_r3_2 != NULL) {
        TWindow__close(temp_r3_2);
        *(u8 **)((s8 *)arg0 + 0x34) = NULL;
    }
    if ((void *) password_entry_keyboard_control != NULL) {
        queue_destruction__7TObjectFv(password_entry_keyboard_control);
        password_entry_keyboard_control = NULL;
    }
    temp_r4 = *(s32 *)((s8 *)arg0 + 0x24) + 1;
    *(s32 *)((s8 *)arg0 + 0x24) = temp_r4;
    if ((f32) temp_r4 > lbl_805DF9E8) {
        password_entry_dispatch_state = *(s32 *)((s8 *)arg0 + 0x20);
    }
}

int forward_chg_game_mode__17TAdEnterPPPPassGCFPv(void* p) { return reset_mode_state__21TAdMultiChgGameModeGCFv(p); }
int request_transition__17TAdEnterPPPPassGCFPv(void* p) { return request_transition__21TAdMultiChgGameModeGCFv(p); }

typedef char RecoveredGlobal_80339480_lbl_804EF500_size[sizeof(RecoveredGlobal_80339480_lbl_804EF500) == 0x98 ? 1 : -1];

typedef char RecoveredGlobal_803392F4_lbl_80477C20_size[sizeof(RecoveredGlobal_803392F4_lbl_80477C20) == 0x20 ? 1 : -1];

void update_password_input__17TAdEnterPPPPassGCFPv(u8 *ad_enter_serial_access_gc) {
    char *buf;
    s32 cur;
    buf = realloc_buffer__17TWindowSubComCardFv(password_entry_keyboard_control);
    if ((*(s32 *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_40 == 0 && TWindowShortListCtrl__check_controller_button(controller_physical_port_bank + 0x20, 2) != 0) ||
        (*(s32 *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_40 == 0 && test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state + 0x160, 2) != 0)) {
        mem_free(buf);
        set_password__17TAdEnterPPPPassGCFi((s32)&lbl_805DF9EC);
        *(s32 *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_20 = 2;
        password_entry_dispatch_state = 4;
        return;
    }
    ((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_3c = *(s32 *)((s8 *)ad_enter_serial_access_gc + 0x38);
    if (password_entry_keyboard_control != NULL) {
        if (((TWindowSubComCard *)password_entry_keyboard_control)->update_keyboard() != 0) {
            if (TWindowShortListCtrl__check_controller_button(controller_physical_port_bank + 0x20, 2) != 0 ||
                test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state + 0x160, 2) != 0) {
                free_menu_object(password_entry_keyboard_control);
                *(s32 *)((s8 *)ad_enter_serial_access_gc + 0x38) = 0;
                if (*(u32 *)((s8 *)ad_enter_serial_access_gc + 0x2C) != 0) {
                    ((TAdEnterSerialAccessGC *)(*(s32 *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->set_active();
                }
            } else if (forward_input__22TAdEnterSerialAccessGCFPv(ad_enter_serial_access_gc, 3, buf) == 0) {
                free_menu_object(password_entry_keyboard_control);
                play_sound_effect(0x53F06, 0, 0, 0);
            } else {
                *(s32 *)((s8 *)ad_enter_serial_access_gc + 0x38) = 1;
                if (*(u32 *)((s8 *)ad_enter_serial_access_gc + 0x2C) != 0) {
                    ((TAdEnterSerialAccessGC *)(*(s32 *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->set_state_3();
                }
            }
        } else {
            *(s32 *)((s8 *)ad_enter_serial_access_gc + 0x38) = 0;
            if (*(u32 *)((s8 *)ad_enter_serial_access_gc + 0x2C) != 0) {
                ((TAdEnterSerialAccessGC *)(*(s32 *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->set_active();
            }
        }
    }
    if (((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_3c != (cur = *(s32 *)((s8 *)ad_enter_serial_access_gc + 0x38))) {
        if (cur != 0) {
            if (*(u32 *)((s8 *)ad_enter_serial_access_gc + 0x2C) != 0) {
                ((TAdEnterSerialAccessGC *)(*(s32 *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->reset_input_state();
                ((TLevelSelect *)(*(s32 *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->add_item_rect((u8 *)&TAdEnterPPPPassGC__selection_positions.value + 0x18);
            }
        } else if (*(u32 *)((s8 *)ad_enter_serial_access_gc + 0x2C) != 0) {
            ((TAdEnterSerialAccessGC *)(*(s32 *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->reset_input_state();
            ((TLevelSelect *)(*(s32 *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->add_item_rect((u8 *)&TAdEnterPPPPassGC__selection_positions.value + 0x10);
        }
    }
    if (((TAdSinglePlyChrSelectGC *)(*(s32 *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->get_selected_slot() == 1 &&
        ((TWindowSubComCard *)password_entry_keyboard_control)->update_keyboard() != 0) {
        set_password__17TAdEnterPPPPassGCFi((s32)buf);
        *(s32 *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_20 = 3;
        password_entry_dispatch_state = 4;
    }
    *(s32 *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_40 = strlen(buf);
    mem_free(buf);
}

void open_keyboard_window__17TAdEnterPPPPassGCFPv(u8 *ad_enter_serial_access_gc) {
    u32 temp_r3;
    ((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_30 = TAdEnterSerialAccessGC::show_message_window((void *)ad_enter_serial_access_gc, (void *)3);
    *(s32 *)((s8 *)ad_enter_serial_access_gc + 0x34) = create_default_callback__22TAdEnterSerialAccessGCFv(ad_enter_serial_access_gc);
    temp_r3 = *(u32 *)((s8 *)ad_enter_serial_access_gc + 0x2C);
    if (temp_r3 != 0U) {
        ((TAdEnterSerialAccessGC *)temp_r3)->reset_input_state();
        ((TLevelSelect *)(*(u32 *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->add_item_rect((void *) ((u8 *)&TAdEnterPPPPassGC__selection_positions.value + 0x10));
        ((TAdEnterSerialAccessGC *)(*(u32 *)((s8 *)ad_enter_serial_access_gc + 0x2C)))->set_active();
    }
    (*(s32 *)&password_entry_keyboard_control) = TAdEnterSerialAccessGC::create_keyboard_control((s32)ad_enter_serial_access_gc, 3);
    password_entry_dispatch_state = 1;
}

void *ppp_password_buffer[8] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
};

void run_task__17TAdEnterPPPPassGCFv(TAdEnterPPPPassGC_80339378 *self) {
    ((TAdEnterBaseGC *)self)->fn_8032B318(password_screen_status_line_position);
    self->state = password_entry_dispatch_state;
    static Pmf_80339378 tbl[5] = {
        (Pmf_80339378)&TAdEnterPPPPassGC::open_keyboard_window,
        (Pmf_80339378)&TAdEnterPPPPassGC::update_password_input,
        (Pmf_80339378)&TAdEnterPPPPassGC::request_transition,
        (Pmf_80339378)&TAdEnterPPPPassGC::forward_chg_game_mode,
        (Pmf_80339378)&TAdEnterPPPPassGC::close_windows_and_advance,
    };
    (self->*tbl[password_entry_dispatch_state])();
    if (self->state != password_entry_dispatch_state) {
        self->f24 = 0;
    }
}

void set_password__17TAdEnterPPPPassGCFi(s32 arg0) {
    if ((TLobby__sub_8014618C() != 0) && (TLobby::is_state_active() != 0)) {
        TLobby::set_ppp_password(arg0);
        return;
    }
    memset(ppp_password_buffer, 0, 0x20);
    strncpy((s32) ppp_password_buffer, arg0, 0x1F);
}

void *__dt__17TAdEnterPPPPassGCFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TAdEnterPPPPassGC;
        __dt__14TAdEnterBaseGCFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
T_8033954C *TAdEnterPPPPassGC__ct(T_8033954C *ad_enter_base_gc) {
    s32 ok;
    TAdEnterBaseGC__ct(ad_enter_base_gc);
    ad_enter_base_gc->vt = __vt__17TAdEnterPPPPassGC;
    ad_enter_base_gc->f0 = TAdEnterPPPPassGC__name;
    ((TAdEnterBaseGC *)ad_enter_base_gc)->sub_8032B460(3);
    password_entry_dispatch_state = 0;
    ad_enter_base_gc->f40 = 0;
    if (TLobby__sub_80145A94() != 0) {
        TLobby::init_account_entries();
    } else {
        TKeyBoardControl__sub_8000F9CC(0x13);
        queue_destruction__7TObjectFv(ad_enter_base_gc);
        return ad_enter_base_gc;
    }
    ok = 0;
    if (TLobby__sub_8014618C() != 0) {
        if (TLobby::is_state_active() != 0) {
            if (*TLobby__sub_80146D14() != 0) {
                ok = 1;
            }
        } else {
            ok = 1;
        }
    } else if (TLobby__sub_80145DB4(1) != 0 && *TLobby__sub_80146D44() != 0) {
        ok = 1;
    }
    if (ok != 0) {
        ((int (*)(void))reset_mode_state__21TAdMultiChgGameModeGCFv)();
        queue_destruction__7TObjectFv(ad_enter_base_gc);
        return ad_enter_base_gc;
    }
    ((TAdEnterBaseGC *)ad_enter_base_gc)->create_parts();
    return ad_enter_base_gc;
}

}
