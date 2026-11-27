#include "pso/ui/window/TextBuilder.h"
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
#include "pso/network/TLobby.h"
#include "pso/ui/frontend/TAdScrollWinGC.h"
#include "pso/system/THeap.h"
#include "pso/ui/chat/ChatLogText.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/system/task/TObject.h"
#include "pso/enemy/BattleParamTables.h"
#include "pso/ui/window/TextBuilder.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/network/client_id.h"

char *chat_log_lines[30];

void TWindowMessageLog::load_chat_history() {
    s32 i;
    for (i = 0; i < 30; i++) {
        if (chat_log_lines[i] != 0) {
            append_line(chat_log_lines[i]);
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
    name = entity->appearance.name;
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

// Scrolls back to the newest line.
void TWindowMessageLog::reset_scroll() {
    target_scroll_y = 0.0f;
    scroll_offset[1] = 0.0f;
    pending_scroll = 0.0f;
}

void TWindowMessageLog::advance_scroll(f32 v) { pending_scroll += v; }

// Same body as advance_scroll; called with the opposite direction.
void TWindowMessageLog::add_pending_scroll(f32 v) { pending_scroll += v; }

void TWindowMessageLog::append_line(const char *shared_text_buffer) {
    ((TWindowMessage *)(this))->append_line(shared_text_buffer, 0x502);
    update_scroll_position();
}

// Grows or shrinks the window to a new height over 3 ticks.
void TWindowMessageLog::set_target_height(f32 height) {
    if (height != target_size[1]) {
        target_size[1] = height;
        tween_ticks = 3;
    }
}

}
s32 find_free_chat_log_slot() {
    s32 i;
    for (i = 0; i < 30; i++) {
        if (chat_log_lines[i] == 0) {
            return i;
        }
    }
    chat_log_remove_line(0);
    return 29;
}

void chat_log_remove_line(s32 index) {
    char **destination;
    char *line;
    destination = &chat_log_lines[index];
    line = *destination;
    if (line != NULL) {
        scroll_win_chat_log_heap->heap_free(line);
        *destination = NULL;
        if (index < 0x1D) {
            move_words(destination, &chat_log_lines[index + 1], (0x1D - index) & 0x3FFFFFFF);
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

void cache_last_chat_line(const char *text) {
    s32 lacks_language_tag;
    s32 size;
    char *dest;
    if (chat_last_line_buffer != NULL) {
        scroll_win_chat_log_heap->heap_free(chat_last_line_buffer);
        chat_last_line_buffer = NULL;
    }
    if (text != NULL) {
        lacks_language_tag = chat_text_lacks_language_tag(text);
        size = (s32)measure_string_len(text) + 1;
        if (lacks_language_tag != 0) {
            size += 2;
        }
        dest = (char *)scroll_win_chat_log_heap->heap_alloc(size);
        if (dest == NULL) {
            do {
                chat_log_remove_line(0);
                dest = (char *)scroll_win_chat_log_heap->heap_alloc(size);
            } while (dest == NULL);
        }
        chat_last_line_buffer = dest;
        if (lacks_language_tag != 0) {
            dest[0] = 9;
            if (current_language == LANGUAGE_JAPANESE) {
                dest[1] = 'J';
                dest += 2;
            } else {
                dest[1] = 'E';
                dest += 2;
            }
            size -= 2;
        }
        strncpy(dest, text, size);
    }
}

void chat_log_add_line(const char *text) {
    size_t num;
    s32 slot;
    char *buffer;
    num = strlen(text);
    slot = find_free_chat_log_slot();
    buffer = (char *)scroll_win_chat_log_heap->heap_alloc(num + 1);
    if (buffer == NULL) {
        do {
            chat_log_remove_line(0);
            buffer = (char *)scroll_win_chat_log_heap->heap_alloc(num + 1);
        } while (buffer == NULL);
        slot = find_free_chat_log_slot();
    }
    chat_log_lines[slot] = buffer;
    strncpy(chat_log_lines[slot], text, num);
    *(char *)(num + (size_t)chat_log_lines[slot]) = 0;
}

void post_chat_log_message(u16 id, const char *text) {
    char *str;
    if ((s32) id == (s32) local_client_id) {
        cache_last_chat_line(text);
    }
    str = TWindowMessageLog::get_active_photon_object(id);
    text_builder_reset();
    if (str != NULL) {
        text_builder_append(str);
        append_text_space();
        text_builder_append(">");
        append_text_space();
    }
    text_builder_append(text);
    text = get_shared_text_buffer();
    chat_log_add_line(text);
    {
        TWindowMessageLog *log = TWindowCtrl::get_message_log();
        if (log != NULL) {
            log->append_line(text);
        }
    }
}

TWindowMessageLog *create_message_log_window(const NJS_POINT2 *position, const f32 *size, s32 client) {
    set_message_window_size(size, 0x1E);
    return new TWindowMessageLog(position, client);
}



const char *TWindowMessageLog::class_name = "TWindowMessageLog";

void TWindowMessageLog::render() {
    WindowDrawContext *draw_context;
    draw_context = get_draw_context();
    draw_window_frame(draw_context);
    draw_visible_window_entries(
        this,
        &entry_list,
        draw_context);
    draw_window_scrollbar(scroll_bar, draw_context, scroll_offset);
}
void TWindowMessageLog::run_task() {
    if (!(window_flags & 2)) {
        open_tick = 0x01000000;
    }
    if ((f32)open_tick >= 7.5f) {
        scroll_bar->increment_counter();
    }
    update_scroll_animation();
    update_scroll();
    update_window();
    update_fade_offset();
    update_window_entry_list(&entry_list);
}
TWindowMessageLog::~TWindowMessageLog() {
    delete scroll_bar;
    clear_message_log_window();
}
TWindowMessageLog::TWindowMessageLog(const NJS_POINT2 *position, s32 client) : TWindowMessage(position, 0x1E, client) {
    NJS_POINT2 extent;
    f32 bar_width;
    m_name = TWindowMessageLog::class_name;
    set_message_log_window(this);
    bar_width = this->target_size[0] - 8.0f;
    extent.y = 0.0f;
    extent.x = bar_width;
    scroll_bar = new WindowScrollBar(&extent);
    this->window_flags = (s32) (this->window_flags | 0x80);
    this->pending_scroll = (f32) 0.0f;
    this->load_chat_history();
}

void free_chat_log_lines(void) {
    s32 i;
    char *v;
    for (i = 29; i >= 0; i--) {
        v = chat_log_lines[i];
        if (v != 0) {
            scroll_win_chat_log_heap->heap_free(v);
            chat_log_lines[i] = 0;
        }
    }
    if (chat_last_line_buffer != NULL) {
        scroll_win_chat_log_heap->heap_free(chat_last_line_buffer);
        chat_last_line_buffer = NULL;
    }
    delete scroll_win_chat_log_heap;
    scroll_win_chat_log_heap = NULL;
}

void init_chat_log_heap(void) {
    s32 i;
    scroll_win_chat_log_heap = new THeap(0x2000, 8);
    chat_last_line_buffer = NULL;
    for (i = 0; i < 0x1E; i++) {
        chat_log_lines[i] = NULL;
    }
}

TWindowMessageLog *TWindowCtrl::get_message_log() {
    if (instance == NULL) {
        return 0;
    }
    return instance->message_log;
}

void clear_message_log_window(void) {
    if (TWindowCtrl::instance != NULL) {
        TWindowCtrl::instance->message_log = NULL;
    }
}

void set_message_log_window(TWindowMessageLog *window_message_log) {
    if (TWindowCtrl::instance != NULL) {
        TWindowCtrl::instance->message_log = window_message_log;
    }
}
