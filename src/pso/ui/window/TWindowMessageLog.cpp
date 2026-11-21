#include "pso/ui/window/MessageWindowSettingsAbi.h"
#include "types.h"
#include "pso/ui/window/Scroll_8026D790.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/player/TObjPlayer.h"
#include <stddef.h>
#include <string.h>
#include "pso/ui/window/TWindowMessageLog.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/frontend/TAdScrollWinGC_8026A5F8.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdScrollWinGC.h"
#include "pso/system/THeap.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/TWindowMessageLog_8026AA38.h"
#include "pso/unk/text_8026A93C.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowCtrl_8026AD44.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"

#pragma readonly_strings on

struct Stack_8026A434 {
    f32 sp8;
    f32 spC;
};

struct Stack_8026A494 {
    f32 sp8;
    f32 spC;
};

extern "C" {
s32 clamp_list_scroll_offset(int, void *, void *, f32);
s32 find_entity_by_id();

s32 TWindowMessageLog::get_active_photon_object() {
    saddr temp_r3;
    s32 var_r3;

    temp_r3 = find_entity_by_id();
    if (temp_r3 == 0) {
        return 0;
    }
    if ((((TObjChara *)temp_r3)->obj_isState2_324() == 0) && (TObjPlayer::is_locally_controlled((void *)temp_r3) == 0)) {
        return 0;
    }
    var_r3 = temp_r3 + 0x85C;
    if (var_r3 == 0) {
        var_r3 = 0;
    }
    return var_r3;
}
void TWindowMessageLog::clamp_scroll_offset() {
    Stack_8026A434 stack;
    f32 temp_f1;
    stack.sp8 = 0.0f;
    temp_f1 = this->frame_size[1];
    stack.spC = temp_f1 - 20.0f;
    if (clamp_list_scroll_offset((int) (*(s32 *)((s8 *)((u8 *)this) + 0x90)), (void *) (((u8 *)this) + 0x68), &stack.sp8, temp_f1) != 0) {
        this->m_84 = (f32) this->scroll_offset[1];
    }
}
void TWindowMessageLog::update_scroll_position() {
    Stack_8026A494 stack;
    saddr temp_r31;
    saddr array_entry;
    s32 temp_r4;
    s32 var_r30;
    temp_r4 = this->next_line;
    var_r30 = temp_r4 - 1;
    if (var_r30 < 0) {
        var_r30 = this->line_count - 1;
    }
    temp_r31 = reinterpret_cast<saddr>(this->get_array_entry(temp_r4));
    array_entry = reinterpret_cast<saddr>(this->get_array_entry(var_r30));
    stack.sp8 = (this->frame_size[0] - 4.0f) - 9.0f;
    stack.spC = (*(f32 *)((s8 *)array_entry + 0xC) + *(f32 *)((s8 *)array_entry + 0x14)) - *(f32 *)((s8 *)temp_r31 + 0xC);
    ((Scroll_8026D790 *)(*(u8 **)((s8 *)((u8 *)this) + 0x90)))->copy_position(&stack.sp8);
    this->clamp_scroll_offset();
}


void TWindowMessageLog::update_fade_offset() {
    f32 temp_f1;
    f32 temp_f31;

    temp_f31 = this->frame_size[1];
    update_fade();
    temp_f1 = this->frame_size[1] - temp_f31;
    if (0.0f != temp_f1) {
        this->m_84 = (f32) (this->m_84 - temp_f1);
        this->scroll_offset[1] = (f32) (this->scroll_offset[1] - temp_f1);
        clamp_scroll_offset();
    }
}


void TWindowMessageLog::update_scroll_animation() {
    f32 temp_f1;
    f32 temp_f1_2;

    temp_f1 = this->m_94;
    if (0.0f != temp_f1) {
        this->m_84 = (f32) (this->m_84 + temp_f1);
        temp_f1_2 = this->scroll_offset[1];
        this->scroll_offset[1] = (f32) (temp_f1_2 + this->m_94);
        this->m_94 *= 0.0f;
        clamp_scroll_offset();
    }
}

}

extern "C" {
u8 *heap_alloc__5THeapFUl(s32, s32);
extern saddr TAdScrollWinGC__chat_log_heap;
extern u8 *chat_last_line_buffer;
struct ChatLogLines { s32 value; u8 remaining[0x74]; };
ChatLogLines chat_log_lines;

void TAdScrollWinGC__sub_8026A5F8(void* a0) { *(float*)((char*)a0 + 0x84) = 0.0f; *(float*)((char*)a0 + 0x6c) = 0.0f; *(float*)((char*)a0 + 0x94) = 0.0f; }

void TAdScrollWinGC::advance_scroll(f32 v) { *(f32*)((char*)this + 0x94) += v; }

void fn_8026A61C(void* p, f32 v) { *(f32*)((char*)p + 0x94) += v; }

void TWindowMessageLog::append_line(s32 shared_text_buffer) {
    ((TWindowMessage *)((u8 *)this))->append_line(shared_text_buffer, 0x502);
    update_scroll_position();
}

void TWindowSubLog__sub_8026A664(u8 *arg0, f32 farg0) {
    if (farg0 != *(f32 *)((s8 *)arg0 + 0x3C)) {
        *(f32 *)((s8 *)arg0 + 0x3C) = farg0;
        *(s32 *)((s8 *)arg0 + 0x50) = 3;
    }
}

s32 TLobby::find_free_chat_log_slot() {
    s32 i;
    for (i = 0; i < 30; i++) {
        if (((char * *)&chat_log_lines)[i] == 0) {
            return i;
        }
    }
    chat_log_remove_line(0);
    return 29;
}
}

void chat_log_remove_line(saddr arg0) {
    u32 *temp_r31;
    uaddr temp_r4;
    temp_r31 = (u32 *)((u8 *)&chat_log_lines.value + (arg0 * 4));
    temp_r4 = *temp_r31;
    if (temp_r4 != 0U) {
        ((THeap *)TAdScrollWinGC__chat_log_heap)->heap_free((void *)temp_r4);
        *temp_r31 = 0U;
        if (arg0 < 0x1D) {
            ((TLobby *)temp_r31)->move_words((u32 *)((u8 *)&chat_log_lines.value + ((arg0 + 1) * 4)), (saddr)((void *) ((0x1D - arg0) & 0x3FFFFFFF)));
        }
        *(s32 *)((s8 *)&chat_log_lines.value + 0x74) = 0;
    }
}

s32 chat_text_lacks_language_tag(const char *text) {
    if (text[0] != 9) {
        return 1;
    }
    switch (text[1]) {
    case 'J':
    case 'E':
        return 0;
    }
    return 1;
}

void cache_last_chat_line(uaddr text) {
    s32 temp_r31;
    s32 size;
    u8 *var_r3;
    if ((void *) chat_last_line_buffer != NULL) {
        ((THeap *)TAdScrollWinGC__chat_log_heap)->heap_free((void *) chat_last_line_buffer);
        chat_last_line_buffer = NULL;
    }
    if (text != 0U) {
        temp_r31 = chat_text_lacks_language_tag((const char *)(text));
        size = (s32)measure_string_len((const char *)((void *)text)) + 1;
        if (temp_r31 != 0) {
            size += 2;
        }
        var_r3 = (u8 *)((THeap *)TAdScrollWinGC__chat_log_heap)->heap_alloc(size);
        if (var_r3 == NULL) {
            do {
                chat_log_remove_line(0);
                var_r3 = (u8 *)((THeap *)TAdScrollWinGC__chat_log_heap)->heap_alloc(size);
            } while (var_r3 == NULL);
        }
        chat_last_line_buffer = var_r3;
        if (temp_r31 != 0) {
            *(s8 *)((s8 *)var_r3 + 0) = 9;
            if (current_language == LANGUAGE_JAPANESE) {
                *(s8 *)((s8 *)var_r3 + 1) = 0x4A;
                var_r3 += 2;
            } else {
                *(s8 *)((s8 *)var_r3 + 1) = 0x45;
                var_r3 += 2;
            }
            size -= 2;
        }
        strncpy((char *)var_r3, (const char *)text, size);
    }
}

void chat_log_add_line(const char *text) {
    saddr temp_r29;
    s32 temp_r30;
    s32 var_r28;
    s32 free_chat_log_slot;
    temp_r29 = strlen(text);
    free_chat_log_slot = TLobby::find_free_chat_log_slot();
    var_r28 = (saddr) heap_alloc__5THeapFUl(TAdScrollWinGC__chat_log_heap, temp_r29 + 1);
    if (var_r28 == 0) {
        do {
            chat_log_remove_line(0);
            var_r28 = (saddr) heap_alloc__5THeapFUl(TAdScrollWinGC__chat_log_heap, temp_r29 + 1);
        } while (var_r28 == 0);
        free_chat_log_slot = TLobby::find_free_chat_log_slot();
    }
    temp_r30 = free_chat_log_slot * 4;
    *(s32 *)((s8 *)((u8 *)&chat_log_lines.value + temp_r30) + 0) = var_r28;
    strncpy(*(char **)((u8 *)&chat_log_lines.value + temp_r30), text, temp_r29);
    *(s8 *)((s8 *)(temp_r29 + *(s32 *)((s8 *)((u8 *)&chat_log_lines.value + temp_r30) + 0)) + 0) = 0;
}

extern "C" {
s32 *get_active_photon_object__17TWindowMessageLogFv(u16);
}
void append_text_space(void);
void text_builder_reset(void);
void cache_last_chat_line(uaddr text);

extern s32 local_client_id;

void post_chat_log_message(u16 arg0, s32 *shared_text_buffer) {
    s32 *temp_r31;
    if ((s32) arg0 == (s32) local_client_id) {
        cache_last_chat_line((uaddr)shared_text_buffer);
    }
    temp_r31 = get_active_photon_object__17TWindowMessageLogFv(arg0);
    text_builder_reset();
    if (temp_r31 != NULL) {
        text_builder_append((u8 *)temp_r31);
        append_text_space();
        text_builder_append((u8 *)">");
        append_text_space();
    }
    text_builder_append((u8 *)shared_text_buffer);
    shared_text_buffer = (s32 *) get_shared_text_buffer();
    chat_log_add_line((const char *)shared_text_buffer);
    {
        uaddr tmp_ad = TWindowCtrl::get_field44();
        if (tmp_ad != 0U) {
            ((TWindowMessageLog *)tmp_ad)->append_line((saddr) shared_text_buffer);
        }
    }
}

u8 *create_message_log_window(s32 arg0, saddr arg1, s32 client) {
    TLobby__sub_80269DA4((void *)arg1, 0x1E);
    return (u8 *)new TWindowMessageLog(arg0, client);
}



const char *TWindowMessageLog__name = "TWindowMessageLog";

struct Stack_8026ABA8 {
    f32 sp8;
    f32 spC;
};

extern "C" {
s32 draw_window_scrollbar(int, int, void *);
void TWindowMessageLog::render() {
    saddr temp_r3;
    temp_r3 = reinterpret_cast<saddr>(get_draw_context());
    draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>((void *) (((u8 *)this) + 0x24)),
        reinterpret_cast<WindowDrawContext *>(temp_r3));
    draw_window_scrollbar((int) (*(s32 *)((s8 *)((u8 *)this) + 0x90)), temp_r3, (void *) (((u8 *)this) + 0x68));
}
void TWindowMessageLog::run_task() {
    if (!(*(s32 *)&this->window_flags & 2)) {
        *(s32 *)&this->open_tick = 0x01000000;
    }
    if ((f32) *(s32 *)&this->open_tick >= 7.5f) {
        ((TWindowSubStatusDisp *)(*(u8 **)((s8 *)((u8 *)this) + 0x90)))->increment_counter();
    }
    update_scroll_animation();
    update_scroll();
    ((TWindowDD *)((u8 *)this))->initialize_subwindow();
    update_fade_offset();
    update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>(((u8 *)this) + 0x24));
}
TWindowMessageLog::~TWindowMessageLog() {
    TWindowSubStatusDisp::destroy_allocation(*(s32 *)((s8 *)this + 0x90), 1);
    TWindowCtrl__sub_8026AD60();
}
TWindowMessageLog::TWindowMessageLog(s32 parent, s32 client) : TWindowMessage(parent, 0x1E, client) {
    #define window_message_log this
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_8026ABA8, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_8026ABA8, spC) == 0x4);
    Stack_8026ABA8 stack;
    f32 temp_f1;
    f32 temp_f2;
    s32 temp_r3;
    saddr var_r0;
    *(s32 *)((s8 *)window_message_log + 0) = (s32) ((saddr)TWindowMessageLog__name);
    TWindowCtrl__sub_8026AD78((saddr)window_message_log);
    temp_f2 = window_message_log->target_size[0];
    temp_f1 = temp_f2 - 8.0f;
    stack.spC = 0.0f;
    stack.sp8 = temp_f1;
    var_r0 = reinterpret_cast<saddr>(new Scroll_8026D790(&stack.sp8));
    *(s32 *)((s8 *)window_message_log + 0x90) = var_r0;
    window_message_log->window_flags = (s32) (window_message_log->window_flags | 0x80);
    window_message_log->m_94 = (f32) 0.0f;
    window_message_log->load_chat_history();
    #undef window_message_log
}

}
