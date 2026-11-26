#include "types.h"
#include <string.h>
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"


extern const char lbl_805DB070 = '.';
void TLobby::debug_print(const char *fmt, ...) {}

s32 TLobby::replace_file_extension(char *dest, char *filename, char *suffix) {
    char buf[0x20];
    char *p;
    s32 n;
    memset(buf, 0, 0x20);
    if (dest == 0) {
        dest = filename;
    }
    p = buf;
    for (n = 0x20; n != 0; n--) {
        if (*filename == '.' || *filename == 0) {
            break;
        }
        *p = *filename;
        p++;
        filename++;
    }
    if (p > &buf[27]) {
        return -1;
    }
    p[1] = 0;
    strcat(buf, suffix);
    strncpy(dest, buf, 0x20);
    return 0;
}

s32 TLobby::change_file_extension(char *dest, char *filename, char *ext) {
    char buf[0x20];
    char *p;
    s32 n;
    if (dest == 0) {
        dest = filename;
    }
    p = buf;
    for (n = 0x20; n != 0; n--) {
        *p = *filename;
        if (*p == '.' || *p == 0) {
            break;
        }
        p++;
        filename++;
    }
    if (p > &buf[27]) {
        return -1;
    }
    *p = 0;
    strcat(buf, &lbl_805DB070);
    strcat(buf, ext);
    strncpy(dest, buf, 0x20);
    return 0;
}

int TLobby::compare_file_extension(const char *ext) {
    const char *s = (const char *)this;
    while (*s) {
        if (*s == '.') {
            return strcmp(s + 1, ext);
        }
        s++;
    }
    return -1;
}
