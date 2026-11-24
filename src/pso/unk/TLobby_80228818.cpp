#include "types.h"
#include <string.h>
#include "pso/unk/TLobby.h"
#include "pso/system/TTokenList.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/unk/text_803D853C.h"

Obj_80515BA0::Obj_80515BA0() {
    init_range(0);
}


void TTokenList::render() {
    s32 i;
    for (i = 0; i < count; i++) {
        debug_printf_at((x << 16) | (y + i), tokens[i]);
    }
}

void TTokenList::tokenize_args(char *s) {
    char *start;
    s32 quoted;
    clear();
    start = s;
    quoted = 0;
    for (;;) {
        switch (*s) {
        case 0:
            add_token(start);
            return;
        case '"':
            if (quoted) {
                quoted = 0;
                *s = 0;
                s++;
            } else {
                s++;
                quoted = 1;
                start = s;
            }
            break;
        case '\t':
        case '\n':
            if (quoted) {
                s++;
            } else {
                *s = 0;
                s++;
                add_token(start);
                start = s;
            }
            break;
        default:
            s++;
            break;
        }
    }
}

void TTokenList::parse_csv_line(char *s) {
    char *start;
    s32 quoted;
    clear();
    start = s;
    quoted = 0;
    for (;;) {
        switch (*s) {
        case 0:
            add_token(start);
            return;
        case '"':
            if (quoted) {
                quoted = 0;
                *s = 0;
                s++;
            } else {
                s++;
                quoted = 1;
                start = s;
            }
            break;
        case '\t':
        case '\n':
        case ',':
            if (quoted) {
                s++;
            } else {
                *s = 0;
                s++;
                add_token(start);
                start = s;
            }
            break;
        default:
            s++;
            break;
        }
    }
}

void TTokenList::add_token(const char *src) {
    strcpy(tokens[count++], src);
}

void TTokenList::clear() {
    memset(tokens, 0, sizeof(tokens));
    count = 0;
}

TTokenList::TTokenList(TObject *parent, s32 x, s32 y) : TObject(parent) {
    this->x = x;
    this->y = y;
    memset(tokens, 0, sizeof(tokens));
    count = 0;
}
void trim_whitespace(char *text) {
    s32 len = strlen(text);
    s32 i;
    for (i = 0; i <= len && ((u8 *)text)[i] <= ' '; i++) {
    }
    if (i > len) {
        strcpy(text, "");
    } else {
        for (; ((u8 *)text)[len] <= ' '; len--) {
            text[len] = 0;
        }
        strcpy(text, text + i);
    }
}
