#include "types.h"
#include "pso/misc/TLobby_80131794.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowMakeTeam.h"
#include "pso/misc/TWindowSubTradeMain.h"

extern "C" {
int strcmp(const char *a, const char *b);
char *strcat(char *, const char *);
char *strncpy(char *, const char *, u32);
void *memset(void *, int, u32);
extern char lbl_805DB070;
void TLobby::debug_print(const char *fmt, ...) {}

s32 replace_file_extension__6TLobbyFPvPvPv(char *arg0, char *arg1, char *arg2) {
    char buf[0x20];
    char *p;
    s32 n;
    memset(buf, 0, 0x20);
    if (arg0 == 0) {
        arg0 = arg1;
    }
    p = buf;
    for (n = 0x20; n != 0; n--) {
        if (*arg1 == '.' || *arg1 == 0) {
            break;
        }
        *p = *arg1;
        p++;
        arg1++;
    }
    if (p > &buf[27]) {
        return -1;
    }
    p[1] = 0;
    strcat(buf, arg2);
    strncpy(arg0, buf, 0x20);
    return 0;
}

s32 change_file_extension__6TLobbyFPvPvPv(char *arg0, char *arg1, char *arg2) {
    char buf[0x20];
    char *p;
    s32 n;
    if (arg0 == 0) {
        arg0 = arg1;
    }
    p = buf;
    for (n = 0x20; n != 0; n--) {
        *p = *arg1;
        if (*p == '.' || *p == 0) {
            break;
        }
        p++;
        arg1++;
    }
    if (p > &buf[27]) {
        return -1;
    }
    *p = 0;
    strcat(buf, &lbl_805DB070);
    strcat(buf, arg2);
    strncpy(arg0, buf, 0x20);
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

}
