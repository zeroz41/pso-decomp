#include "types.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/ui/TAdScrollWinGC_8026A5F8.h"
#include "pso/misc/TWindowMessageLog.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdScrollWinGC.h"
#include "pso/THeap.h"
#include "pso/ui/Language.h"

struct RecoveredGlobal_8026A6DC_lbl_805187D8 {
    s32 value;
    u8 remaining[0x74];
};

extern "C" {
u8 *heap_alloc__5THeapFUl(s32, s32);
s32 measure_string_len__20TWindowSubStatusDispFv(void *);
s32 strncpy(int, void *, int);
extern s32 TAdScrollWinGC__chat_log_heap;
extern u8 *chat_last_line_buffer;
extern RecoveredGlobal_8026A6DC_lbl_805187D8 chat_log_lines;
s32 strlen();

    extern const float lbl_805DD240;
void TAdScrollWinGC__sub_8026A5F8(void* a0) { *(float*)((char*)a0 + 0x84) = lbl_805DD240; *(float*)((char*)a0 + 0x6c) = lbl_805DD240; *(float*)((char*)a0 + 0x94) = lbl_805DD240; }

void TAdScrollWinGC::advance_scroll(f32 v) { *(f32*)((char*)this + 0x94) += v; }

void fn_8026A61C(void* p, f32 v) { *(f32*)((char*)p + 0x94) += v; }

void TWindowMessageLog::append_line(s32 arg1) {
    ((TWindowMessage *)((u8 *)this))->append_line(arg1, 0x502);
    update_scroll_position();
}

void TWindowSubLog__sub_8026A664(u8 *arg0, f32 farg0) {
    if (farg0 != *(f32 *)((s8 *)arg0 + 0x3C)) {
        *(f32 *)((s8 *)arg0 + 0x3C) = farg0;
        *(s32 *)((s8 *)arg0 + 0x50) = 3;
    }
}

typedef char RecoveredGlobal_8026A6DC_lbl_805187D8_size[sizeof(RecoveredGlobal_8026A6DC_lbl_805187D8) == 0x78 ? 1 : -1];

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

void chat_log_remove_line(s32 arg0) {
    u32 *temp_r31;
    u32 temp_r4;
    temp_r31 = (u32 *)((u8 *)&chat_log_lines.value + (arg0 * 4));
    temp_r4 = *temp_r31;
    if (temp_r4 != 0U) {
        ((THeap *)TAdScrollWinGC__chat_log_heap)->heap_free((void *)temp_r4);
        *temp_r31 = 0U;
        if (arg0 < 0x1D) {
            ((TLobby *)temp_r31)->move_words((u32 *)((u8 *)&chat_log_lines.value + ((arg0 + 1) * 4)), (s32)((void *) ((0x1D - arg0) & 0x3FFFFFFF)));
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

void cache_last_chat_line(u32 text) {
    s32 temp_r31;
    s32 size;
    u8 *var_r3;
    if ((void *) chat_last_line_buffer != NULL) {
        ((THeap *)TAdScrollWinGC__chat_log_heap)->heap_free((void *) chat_last_line_buffer);
        chat_last_line_buffer = NULL;
    }
    if (text != 0U) {
        temp_r31 = chat_text_lacks_language_tag((const char *)(text));
        size = measure_string_len__20TWindowSubStatusDispFv((void *)text) + 1;
        if (temp_r31 != 0) {
            size += 2;
        }
        var_r3 = heap_alloc__5THeapFUl(TAdScrollWinGC__chat_log_heap, size);
        if (var_r3 == NULL) {
            do {
                chat_log_remove_line(0);
                var_r3 = heap_alloc__5THeapFUl(TAdScrollWinGC__chat_log_heap, size);
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
        strncpy((int)var_r3, (void *)text, (int)size);
    }
}

void chat_log_add_line(s32 arg0) {
    s32 temp_r29;
    s32 temp_r30;
    s32 var_r28;
    s32 free_chat_log_slot;
    temp_r29 = strlen();
    free_chat_log_slot = TLobby::find_free_chat_log_slot();
    var_r28 = (s32) heap_alloc__5THeapFUl(TAdScrollWinGC__chat_log_heap, temp_r29 + 1);
    if (var_r28 == 0) {
        do {
            chat_log_remove_line(0);
            var_r28 = (s32) heap_alloc__5THeapFUl(TAdScrollWinGC__chat_log_heap, temp_r29 + 1);
        } while (var_r28 == 0);
        free_chat_log_slot = TLobby::find_free_chat_log_slot();
    }
    temp_r30 = free_chat_log_slot * 4;
    *(s32 *)((s8 *)((u8 *)&chat_log_lines.value + temp_r30) + 0) = var_r28;
    strncpy((int) (*(s32 *)((s8 *)((u8 *)&chat_log_lines.value + temp_r30) + 0)), (void *)arg0, (int)temp_r29);
    *(s8 *)((s8 *)(temp_r29 + *(s32 *)((s8 *)((u8 *)&chat_log_lines.value + temp_r30) + 0)) + 0) = 0;
}
