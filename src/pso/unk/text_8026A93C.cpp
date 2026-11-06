#include "types.h"
#include "pso/ui/window/TWindowMessageLog_8026AA38.h"
#include "pso/unk/text_8026A93C.h"
#include "pso/ui/window/TWindowMessageLog.h"
#include "pso/ui/window/TWindowCtrl.h"

extern "C" {
u8 *__nw__7TObjectFUl(s32);
s32 TLobby__sub_80269DA4(void *, int);
s32 *get_shared_text_buffer(void);
void text_builder_append(u8 *str);
s32 *get_active_photon_object__17TWindowMessageLogFv(u16);
}
void append_text_space(void);
void text_builder_reset(void);
void cache_last_chat_line(u32 text);
extern "C" {
s32 chat_log_add_line();
extern s32 local_client_id;
extern s32 lbl_805DD250;

void post_chat_log_message(u16 arg0, s32 *shared_text_buffer) {
    s32 temp_r30;
    s32 *temp_r31;
    if ((s32) arg0 == (s32) local_client_id) {
        cache_last_chat_line((u32)shared_text_buffer);
    }
    temp_r31 = get_active_photon_object__17TWindowMessageLogFv(arg0);
    text_builder_reset();
    if (temp_r31 != NULL) {
        text_builder_append((u8 *)temp_r31);
        append_text_space();
        text_builder_append((u8 *)&lbl_805DD250);
        append_text_space();
    }
    text_builder_append((u8 *)shared_text_buffer);
    shared_text_buffer = (s32 *) get_shared_text_buffer();
    chat_log_add_line();
    {
        u32 tmp_ad = TWindowCtrl::get_field44();
        if (tmp_ad != 0U) {
            ((TWindowMessageLog *)tmp_ad)->append_line((s32) shared_text_buffer);
        }
    }
}

u8 *create_message_log_window(s32 arg0, s32 arg1, s32 arg2) {
    u8 *window_message_log;
    u8 *var_r0;
    TLobby__sub_80269DA4((void *)arg1, 0x1E);
    window_message_log = (u8 *)(__nw__7TObjectFUl(0x98));
    var_r0 = window_message_log;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TWindowMessageLog__ct((TWindowMessageLog *)window_message_log, arg0, arg2));
    }
    return var_r0;
}
}
