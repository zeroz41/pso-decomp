#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/unk/text_8026A14C.h"
#include "pso/system/THeap.h"
#include "pso/ui/Language.h"

extern "C" {
extern void *chat_log_lines[];
extern void *TAdScrollWinGC__chat_log_heap;
extern void *chat_last_line_buffer;
char *strncpy(char *, const char *, u32);
u32 strlen(const char *);
void fn_8026A14C(void) {
    s32 i;
    for (i = 0x1D; i >= 0; i--) {
        if (chat_log_lines[i] != NULL) {
            ((THeap *)TAdScrollWinGC__chat_log_heap)->heap_free(chat_log_lines[i]);
            chat_log_lines[i] = NULL;
        }
    }
    if (chat_last_line_buffer != NULL) {
        ((THeap *)TAdScrollWinGC__chat_log_heap)->heap_free(chat_last_line_buffer);
        chat_last_line_buffer = NULL;
    }
}
void fn_8026A1C4(char *dst, char *src, s32 size) {
    s32 sjis;
    char *next;
    s32 len;
    s32 n;
    s8 c;
    sjis = 0;
    if (dst != NULL && size > 0) {
        if (src == NULL || size <= 1) {
            *dst = 0;
            return;
        }
        len = strlen(src) + 1;
        if (current_language == LANGUAGE_JAPANESE) {
            sjis = 1;
        }
        while (size < len) {
            if (*src == 0 || len <= 0 || size <= 1) {
                if (size > 0) {
                    *dst = 0;
                }
                return;
            }
            next = parse_text_control_codes(src, &sjis, 0);
            if (next != src) {
                n = next - src;
                if (n >= size) {
                    *dst = 0;
                    return;
                }
                strncpy(dst, src, n);
                src = next;
                dst += n;
                size -= n;
                len -= n;
            } else {
                len--;
                c = *src++;
                if (sjis != 0 && ((c & 0xE0) == 0x80 || (c & 0xE0) == 0xE0)) {
                    src++;
                    len--;
                }
            }
        }
        strncpy(dst, src, len);
        dst[len] = 0;
    }
}

}
