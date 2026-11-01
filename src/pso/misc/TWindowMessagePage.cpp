#include "types.h"
#include "pso/misc/TWindowMessagePage.h"
#include "pso/misc/TWindowCtrl_8024A054.h"
#include "pso/misc/TWindowSubStatusDisp_80228F5C.h"
#include "pso/misc/TWindowMessage.h"

#pragma readonly_strings on

extern "C" {
const char *lbl_805D3998 = "TWindowMessagePage";
}



struct RecoveredGlobal_8026B014___vt__18TWindowMessagePage { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8026B014___vt__18TWindowMessagePage_size[sizeof(RecoveredGlobal_8026B014___vt__18TWindowMessagePage) == 0x18 ? 1 : -1];

struct RecoveredGlobal_8026AF24_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct Page_8026AE20 { u8 pad[0x90]; s32 flags; void *msg; };

extern "C" {
u8 *__nw__7TObjectFUl(s32);
s32 TLobby__sub_80269DA4(void *, void *);
u8 *TWindowMessage__ct(u8 *arg0, s32 arg1, u32 arg2, s32 arg3);
extern s32 __vt__18TWindowMessagePage[];
extern const char *lbl_805D3998;
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int, int);
s32 run_task__14TWindowMessageFv();
extern RecoveredGlobal_8026AF24_lbl_8050E208 controller_input_state;
s32 get_shared_text_buffer();
u32 copy_message_page_text__20TWindowSubStatusDispFv(u32);
void render__14TWindowMessageFv(s32 arg0);
s32 append_line__14TWindowMessageFii(void *, s32, s32);

s32 TWindowMessagePage::is_ready() {
    if ((u32) this->m_94 != 0U) {
        return 0;
    }
    return is_message_window_ready() != 0 ? 1 : 0;
}

void TWindowMessagePage::update_message() {
    if ((u32) this->m_94 != 0U) {
        text_builder_reset();
        this->m_94 = copy_message_page_text__20TWindowSubStatusDispFv(this->m_94);
        append_line__14TWindowMessageFii(this, get_shared_text_buffer(), *(s32 *)((s8 *)this + 0x90));
    }
}

extern s32 local_client_id;

void TWindowMessagePage::set_message(void *msg, s32 flags) {
    Page_8026AE20 *self = (Page_8026AE20 *)this;
    while (self->msg != NULL) {
        update_message();
    }
    self->flags = flags | 2;
    self->msg = msg;
    update_message();
}

u8 *TWindowMessagePage::create(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *window_message_page;
    u8 *var_r0;
    TLobby__sub_80269DA4((void *)arg1, (void *)arg2);
    window_message_page = (u8 *)(__nw__7TObjectFUl(0x98));
    var_r0 = window_message_page;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TWindowMessagePage__ct(window_message_page, arg0, arg2, arg3));
    }
    return var_r0;
}

void TWindowMessagePage::set_text(s32 a, s32 b, s32 c) {
    TWindowMessagePage::create(a, b, c, local_client_id);
}

void TWindowMessagePage::render() { { (void)(render__14TWindowMessageFv((s32)this)); return; } }

typedef char RecoveredGlobal_8026AF24_lbl_8050E208_size[sizeof(RecoveredGlobal_8026AF24_lbl_8050E208) == 0x1B0 ? 1 : -1];
void TWindowMessagePage::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r5;
    run_task__14TWindowMessageFv();
    temp_r5 = is_player_input_active((this->m_20)) * 0x50;
    if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)&controller_input_state.value + temp_r5 + 0x20), 4, temp_r5) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 4) != 0)) {
        if (((TWindowMessagePage *)arg0)->is_message_window_ready() != 0) {
            update_message();
            return;
        }
        ((TWindowMessage *)arg0)->complete_reveal();
    }
}

}
TWindowMessagePage::~TWindowMessagePage() {

}

u8 *TWindowMessagePage__ct(u8 *window_message_page, s32 arg1, s32 arg2, s32 arg3) {
    TWindowMessage__ct((window_message_page), (arg1), (arg2), (arg3));
    *(s32 **)((s8 *)window_message_page + 0x18) = &(*(RecoveredGlobal_8026B014___vt__18TWindowMessagePage *)&__vt__18TWindowMessagePage).value;
    *(s32 *)((s8 *)window_message_page + 0) = (s32) ((s32)lbl_805D3998);
    *(s32 *)((s8 *)window_message_page + 0x90) = 0;
    ((TWindowMessagePage *)window_message_page)->m_20 = (s16) arg3;
    ((TWindowMessagePage *)window_message_page)->m_94 = 0;
    return window_message_page;
}

