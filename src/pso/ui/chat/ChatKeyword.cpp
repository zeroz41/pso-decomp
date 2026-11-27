#include "types.h"
#include "pso/ui/chat/ChatKeyword.h"

s32 find_chat_keyword(char *s, char (*names)[0x20], s32 lower) {
    char buf[0x100];
    s32 len;
    s32 i;
    s32 j;
    s32 k;
    s32 m;

    len = 0;
    buf[0] = ' ';
    while (*s != 0) {
        if (lower != 0) {
            u8 alpha = 0;
            if (*s >= 'A' && *s <= 'z') {
                alpha = 1;
            }
            s32 c = *s;
            if (alpha) {
                c = (c & 0x5f) + 0x20;
            }
            buf[len + 1] = c;
        } else {
            buf[len + 1] = *s;
        }
        len++;
        s++;
    }
    buf[len + 1] = ' ';
    buf[len + 2] = (s64)(i = 0);
    for (; names[i][0] != 0; i++) {
        for (j = 0; buf[j] != 0; j++) {
            for (k = j, m = 0; buf[k] == names[i][m]; k++, m++) {
                if (names[i][m + 1] == 0) {
                    return i;
                }
            }
        }
    }
    return -1;
}
