#include "pso/ui/window/MessageWindowSettingsAbi.h"
#include "pso/system/memory.h"
#include "types.h"
#include "pso/ui/window/WindowScrollBar.h"
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

extern "C" {
s32 find_entity_by_id();

s32 TWindowMessageLog::get_active_photon_object() {
    saddr entity;
    s32 var_r3;

    entity = find_entity_by_id();
    if (entity == 0) {
        return 0;
    }
    if ((((TObjChara *)entity)->obj_isState2_324() == 0) && (TObjPlayer::is_locally_controlled((void *)entity) == 0)) {
        return 0;
    }
    var_r3 = entity + 0x85C;
    if (var_r3 == 0) {
        var_r3 = 0;
    }
    return var_r3;
}
void TWindowMessageLog::clamp_scroll_offset() {
    NJS_POINT2 range;
    f32 temp_f1;
    range.x = 0.0f;
    temp_f1 = this->frame_size[1];
    range.y = temp_f1 - 20.0f;
    if (scroll_bar->clamp_offset(scroll_offset, &range) != 0) {
        this->target_scroll_y = (f32) this->scroll_offset[1];
    }
}
void TWindowMessageLog::update_scroll_position() {
    NJS_POINT2 extent;
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
    extent.x = (this->frame_size[0] - 4.0f) - 9.0f;
    extent.y = (*(f32 *)((s8 *)array_entry + 0xC) + *(f32 *)((s8 *)array_entry + 0x14)) - *(f32 *)((s8 *)temp_r31 + 0xC);
    scroll_bar->set_extent(&extent);
    this->clamp_scroll_offset();
}


void TWindowMessageLog::update_fade_offset() {
    f32 temp_f1;
    f32 temp_f31;

    temp_f31 = this->frame_size[1];
    update_fade();
    temp_f1 = this->frame_size[1] - temp_f31;
    if (0.0f != temp_f1) {
        this->target_scroll_y = (f32) (this->target_scroll_y - temp_f1);
        this->scroll_offset[1] = (f32) (this->scroll_offset[1] - temp_f1);
        clamp_scroll_offset();
    }
}


void TWindowMessageLog::update_scroll_animation() {
    f32 temp_f1;

    temp_f1 = this->m_94;
    if (0.0f != temp_f1) {
        this->target_scroll_y = (f32) (this->target_scroll_y + temp_f1);
        this->scroll_offset[1] = (f32) (this->scroll_offset[1] + this->m_94);
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

void TAdScrollWinGC__sub_8026A5F8(void* window) { *(float*)((char*)window + 0x84) = 0.0f; *(float*)((char*)window + 0x6c) = 0.0f; *(float*)((char*)window + 0x94) = 0.0f; }

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
    u32 *destination;
    uaddr temp_r4;
    destination = (u32 *)((u8 *)&chat_log_lines.value + (arg0 * 4));
    temp_r4 = *destination;
    if (temp_r4 != 0U) {
        ((THeap *)TAdScrollWinGC__chat_log_heap)->heap_free((void *)temp_r4);
        *destination = 0U;
        if (arg0 < 0x1D) {
            move_words(reinterpret_cast<void *>(destination), reinterpret_cast<u8 *>(&chat_log_lines.value) + (arg0 + 1) * 4, (saddr)((void *) ((0x1D - arg0) & 0x3FFFFFFF)));
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
    u8 *dest;
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
        dest = (u8 *)((THeap *)TAdScrollWinGC__chat_log_heap)->heap_alloc(size);
        if (dest == NULL) {
            do {
                chat_log_remove_line(0);
                dest = (u8 *)((THeap *)TAdScrollWinGC__chat_log_heap)->heap_alloc(size);
            } while (dest == NULL);
        }
        chat_last_line_buffer = dest;
        if (temp_r31 != 0) {
            *(s8 *)((s8 *)dest + 0) = 9;
            if (current_language == LANGUAGE_JAPANESE) {
                *(s8 *)((s8 *)dest + 1) = 0x4A;
                dest += 2;
            } else {
                *(s8 *)((s8 *)dest + 1) = 0x45;
                dest += 2;
            }
            size -= 2;
        }
        strncpy((char *)dest, (const char *)text, size);
    }
}

void chat_log_add_line(const char *text) {
    saddr num;
    s32 temp_r30;
    s32 var_r28;
    s32 free_chat_log_slot;
    num = strlen(text);
    free_chat_log_slot = TLobby::find_free_chat_log_slot();
    var_r28 = (saddr) heap_alloc__5THeapFUl(TAdScrollWinGC__chat_log_heap, num + 1);
    if (var_r28 == 0) {
        do {
            chat_log_remove_line(0);
            var_r28 = (saddr) heap_alloc__5THeapFUl(TAdScrollWinGC__chat_log_heap, num + 1);
        } while (var_r28 == 0);
        free_chat_log_slot = TLobby::find_free_chat_log_slot();
    }
    temp_r30 = free_chat_log_slot * 4;
    *(s32 *)((s8 *)((u8 *)&chat_log_lines.value + temp_r30) + 0) = var_r28;
    strncpy(*(char **)((u8 *)&chat_log_lines.value + temp_r30), text, num);
    *(s8 *)((s8 *)(num + *(s32 *)((s8 *)((u8 *)&chat_log_lines.value + temp_r30) + 0)) + 0) = 0;
}

extern "C" {
s32 *get_active_photon_object__17TWindowMessageLogFv(u16);
}
void append_text_space(void);
void text_builder_reset(void);
void cache_last_chat_line(uaddr text);

extern s32 local_client_id;

void post_chat_log_message(u16 arg0, s32 *shared_text_buffer) {
    s32 *str;
    if ((s32) arg0 == (s32) local_client_id) {
        cache_last_chat_line((uaddr)shared_text_buffer);
    }
    str = get_active_photon_object__17TWindowMessageLogFv(arg0);
    text_builder_reset();
    if (str != NULL) {
        text_builder_append((u8 *)str);
        append_text_space();
        text_builder_append((u8 *)">");
        append_text_space();
    }
    text_builder_append((u8 *)shared_text_buffer);
    shared_text_buffer = (s32 *) get_shared_text_buffer();
    chat_log_add_line((const char *)shared_text_buffer);
    {
        TWindowMessageLog *log = TWindowCtrl::get_field44();
        if (log != NULL) {
            log->append_line((saddr) shared_text_buffer);
        }
    }
}

u8 *create_message_log_window(s32 parent, saddr extent, s32 client) {
    TLobby__sub_80269DA4((void *)extent, 0x1E);
    return (u8 *)new TWindowMessageLog(parent, client);
}



const char *TWindowMessageLog__name = "TWindowMessageLog";

extern "C" {
void TWindowMessageLog::render() {
    WindowDrawContext *draw_context;
    draw_context = get_draw_context();
    draw_window_frame(draw_context);
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>((void *) (((u8 *)this) + 0x24)),
        draw_context);
    draw_window_scrollbar(scroll_bar, draw_context, scroll_offset);
}
void TWindowMessageLog::run_task() {
    if (!(*(s32 *)&this->window_flags & 2)) {
        *(s32 *)&this->open_tick = 0x01000000;
    }
    if ((f32) *(s32 *)&this->open_tick >= 7.5f) {
        scroll_bar->increment_counter();
    }
    update_scroll_animation();
    update_scroll();
    ((TWindowDD *)((u8 *)this))->initialize_subwindow();
    update_fade_offset();
    update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>(((u8 *)this) + 0x24));
}
TWindowMessageLog::~TWindowMessageLog() {
    TWindowSubStatusDisp::destroy_allocation(reinterpret_cast<saddr>(scroll_bar), 1);
    TWindowCtrl__sub_8026AD60();
}
TWindowMessageLog::TWindowMessageLog(s32 parent, s32 client) : TWindowMessage(parent, 0x1E, client) {
    NJS_POINT2 extent;
    f32 temp_f1;
    s32 temp_r3;
    *(s32 *)((s8 *)this + 0) = (s32) ((saddr)TWindowMessageLog__name);
    TWindowCtrl__sub_8026AD78(this);
    temp_f1 = this->target_size[0] - 8.0f;
    extent.y = 0.0f;
    extent.x = temp_f1;
    scroll_bar = new WindowScrollBar(&extent);
    this->window_flags = (s32) (this->window_flags | 0x80);
    this->m_94 = (f32) 0.0f;
    this->load_chat_history();
}

}
