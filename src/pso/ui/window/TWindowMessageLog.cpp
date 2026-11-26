#include "pso/ui/window/WindowTextEntry.h"
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
#include "pso/network/TLobby.h"
#include "pso/ui/frontend/TAdScrollWinGC.h"
#include "pso/system/THeap.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowCtrl_8026AD44.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/network/client_id.h"

char *chat_log_lines[30];

void TWindowMessageLog::load_chat_history() {
    s32 i;
    for (i = 0; i < 30; i++) {
        if (chat_log_lines[i] != 0) {
            append_line((saddr)chat_log_lines[i]);
        }
    }
    complete_reveal();
    this->clamp_scroll_offset();
}

#pragma readonly_strings on

extern "C" {
char *TWindowMessageLog::get_active_photon_object(u16 id) {
    TObjPlayer *entity;
    char *name;

    entity = (TObjPlayer *)find_entity_by_id(id);
    if (entity == NULL) {
        return 0;
    }
    if ((entity->obj_isState2_324() == 0) && (entity->is_locally_controlled() == 0)) {
        return 0;
    }
    name = entity->name;
    if (name == 0) {
        name = 0;
    }
    return name;
}
void TWindowMessageLog::clamp_scroll_offset() {
    NJS_POINT2 range;
    range.x = 0.0f;
    range.y = this->frame_size[1] - 20.0f;
    if (scroll_bar->clamp_offset(scroll_offset, &range) != 0) {
        this->target_scroll_y = (f32) this->scroll_offset[1];
    }
}
void TWindowMessageLog::update_scroll_position() {
    NJS_POINT2 extent;
    WindowTextEntry *first_entry;
    WindowTextEntry *last_entry;
    s32 first_line;
    s32 last_line;
    first_line = this->next_line;
    last_line = first_line - 1;
    if (last_line < 0) {
        last_line = this->line_count - 1;
    }
    first_entry = static_cast<WindowTextEntry *>(this->get_array_entry(first_line));
    last_entry = static_cast<WindowTextEntry *>(this->get_array_entry(last_line));
    extent.x = (this->frame_size[0] - 4.0f) - 9.0f;
    extent.y = (last_entry->y + last_entry->height) - first_entry->y;
    scroll_bar->set_extent(&extent);
    this->clamp_scroll_offset();
}


void TWindowMessageLog::update_fade_offset() {
    f32 height_change;
    f32 old_height;

    old_height = this->frame_size[1];
    update_fade();
    height_change = this->frame_size[1] - old_height;
    if (0.0f != height_change) {
        this->target_scroll_y = (f32) (this->target_scroll_y - height_change);
        this->scroll_offset[1] = (f32) (this->scroll_offset[1] - height_change);
        clamp_scroll_offset();
    }
}


void TWindowMessageLog::update_scroll_animation() {
    f32 pending;

    pending = this->pending_scroll;
    if (0.0f != pending) {
        this->target_scroll_y = (f32) (this->target_scroll_y + pending);
        this->scroll_offset[1] = (f32) (this->scroll_offset[1] + this->pending_scroll);
        this->pending_scroll *= 0.0f;
        clamp_scroll_offset();
    }
}

}

extern "C" {
u8 *heap_alloc__5THeapFUl(s32, s32);
extern saddr scroll_win_chat_log_heap;
extern u8 *chat_last_line_buffer;

void TAdScrollWinGC__sub_8026A5F8(void* window) { *(float*)((char*)window + 0x84) = 0.0f; *(float*)((char*)window + 0x6c) = 0.0f; *(float*)((char*)window + 0x94) = 0.0f; }

void TAdScrollWinGC::advance_scroll(f32 v) { *(f32*)((char*)this + 0x94) += v; }

void fn_8026A61C(void* p, f32 v) { *(f32*)((char*)p + 0x94) += v; }

void TWindowMessageLog::append_line(s32 shared_text_buffer) {
    ((TWindowMessage *)(this))->append_line(shared_text_buffer, 0x502);
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
        if (chat_log_lines[i] == 0) {
            return i;
        }
    }
    chat_log_remove_line(0);
    return 29;
}
}

void chat_log_remove_line(saddr index) {
    u32 *destination;
    uaddr line;
    destination = (u32 *)&chat_log_lines[index];
    line = *destination;
    if (line != 0U) {
        ((THeap *)scroll_win_chat_log_heap)->heap_free((void *)line);
        *destination = 0U;
        if (index < 0x1D) {
            move_words(reinterpret_cast<void *>(destination), &chat_log_lines[index + 1], (saddr)((void *) ((0x1D - index) & 0x3FFFFFFF)));
        }
        chat_log_lines[29] = 0;
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
    s32 lacks_language_tag;
    s32 size;
    u8 *dest;
    if ((void *) chat_last_line_buffer != NULL) {
        ((THeap *)scroll_win_chat_log_heap)->heap_free((void *) chat_last_line_buffer);
        chat_last_line_buffer = NULL;
    }
    if (text != 0U) {
        lacks_language_tag = chat_text_lacks_language_tag((const char *)(text));
        size = (s32)measure_string_len((const char *)((void *)text)) + 1;
        if (lacks_language_tag != 0) {
            size += 2;
        }
        dest = (u8 *)((THeap *)scroll_win_chat_log_heap)->heap_alloc(size);
        if (dest == NULL) {
            do {
                chat_log_remove_line(0);
                dest = (u8 *)((THeap *)scroll_win_chat_log_heap)->heap_alloc(size);
            } while (dest == NULL);
        }
        chat_last_line_buffer = dest;
        if (lacks_language_tag != 0) {
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
    s32 slot_offset;
    s32 buffer;
    s32 free_chat_log_slot;
    num = strlen(text);
    free_chat_log_slot = TLobby::find_free_chat_log_slot();
    buffer = (saddr) heap_alloc__5THeapFUl(scroll_win_chat_log_heap, num + 1);
    if (buffer == 0) {
        do {
            chat_log_remove_line(0);
            buffer = (saddr) heap_alloc__5THeapFUl(scroll_win_chat_log_heap, num + 1);
        } while (buffer == 0);
        free_chat_log_slot = TLobby::find_free_chat_log_slot();
    }
    slot_offset = free_chat_log_slot * 4;
    *(s32 *)((s8 *)((u8 *)chat_log_lines + slot_offset) + 0) = buffer;
    strncpy(*(char **)((u8 *)chat_log_lines + slot_offset), text, num);
    *(s8 *)((s8 *)(num + *(s32 *)((s8 *)((u8 *)chat_log_lines + slot_offset) + 0)) + 0) = 0;
}

void append_text_space(void);

void post_chat_log_message(u16 id, const char *text) {
    char *str;
    if ((s32) id == (s32) local_client_id) {
        cache_last_chat_line((uaddr)text);
    }
    str = TWindowMessageLog::get_active_photon_object(id);
    text_builder_reset();
    if (str != NULL) {
        text_builder_append((u8 *)str);
        append_text_space();
        text_builder_append((u8 *)">");
        append_text_space();
    }
    text_builder_append((u8 *)text);
    text = (const char *)get_shared_text_buffer();
    chat_log_add_line(text);
    {
        TWindowMessageLog *log = TWindowCtrl::get_field44();
        if (log != NULL) {
            log->append_line((saddr)text);
        }
    }
}

u8 *create_message_log_window(const NJS_POINT2 *position, saddr extent, s32 client) {
    set_message_window_size((void *)extent, 0x1E);
    return (u8 *)new TWindowMessageLog(position, client);
}



const char *TWindowMessageLog::class_name = "TWindowMessageLog";

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
    update_window();
    update_fade_offset();
    update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>(((u8 *)this) + 0x24));
}
TWindowMessageLog::~TWindowMessageLog() {
    TWindowSubStatusDisp::destroy_allocation(reinterpret_cast<saddr>(scroll_bar), 1);
    clear_message_log_window();
}
TWindowMessageLog::TWindowMessageLog(const NJS_POINT2 *position, s32 client) : TWindowMessage(position, 0x1E, client) {
    NJS_POINT2 extent;
    f32 bar_width;
    *(s32 *)(this + 0) = (s32) ((saddr)TWindowMessageLog::class_name);
    set_message_log_window(this);
    bar_width = this->target_size[0] - 8.0f;
    extent.y = 0.0f;
    extent.x = bar_width;
    scroll_bar = new WindowScrollBar(&extent);
    this->window_flags = (s32) (this->window_flags | 0x80);
    this->pending_scroll = (f32) 0.0f;
    this->load_chat_history();
}

