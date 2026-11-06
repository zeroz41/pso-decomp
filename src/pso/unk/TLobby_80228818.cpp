#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/item/TUnk_804CC048.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/unk/TLobby_800FD78C.h"

struct O_80228A74 { u8 pad[0x1c]; char names[1][0x20]; };

struct P_80228A74 { u8 pad[0x109c]; s32 count; };

struct L_8022884C { u8 pad[0x109c]; s32 count; s32 hi; s32 lo; };

extern "C" {
char *strcpy(char *dst, const char *src);
void clear_work_buffer(u8 *arg0);
u32 strlen(const char *s);
s32 debug_printf_at(u32, void *, ...);
void __ct__7TObjectFP7TObject(void *);
void memset(void *, int, int);

Obj_80515BA0::Obj_80515BA0() {
    init_range(0);
}


#pragma push
#pragma opt_propagation off
void TUnk_804CC048::render() {
    L_8022884C *self = (L_8022884C *)this;
    s32 off;
    s32 i;
    s32 t;
    i = 0;
    off = 0;
    while (i < self->count) {
        t = off + 0x1c;
        debug_printf_at((self->hi << 16) | (self->lo + i), (u8 *)self + t);
        i++;
        off += 0x20;
    }
}
#pragma pop

void TLobby::tokenize_args(char *s) {
    char *start;
    s32 quoted;
    clear_work_buffer((u8 *)this);
    start = s;
    quoted = 0;
    for (;;) {
        switch (*s) {
        case 0:
            this->add_token(start);
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
                this->add_token(start);
                start = s;
            }
            break;
        default:
            s++;
            break;
        }
    }
}

void TLobby::parse_csv_line(char *s) {
    char *start;
    s32 quoted;
    clear_work_buffer((u8 *)this);
    start = s;
    quoted = 0;
    for (;;) {
        switch (*s) {
        case 0:
            this->add_token(start);
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
                this->add_token(start);
                start = s;
            }
            break;
        default:
            s++;
            break;
        }
    }
}

void TLobby::add_token(const char *src) {
    O_80228A74 *self = (O_80228A74 *)this;
    strcpy(self->names[((P_80228A74 *)self)->count++], src);
}

void clear_work_buffer(u8 *arg0) {
    memset(arg0 + 0x1C, 0, 0x1000);
    *(s32 *)((s8 *)arg0 + 0x109C) = 0;
}

TUnk_804CC048::TUnk_804CC048(TObject *parent, void *arg2, void *arg3) : TObject(parent) {
    *(void **)((s8 *)this + 0x10A0) = arg2;
    m_10a4 = arg3;
    memset((char *)this + 0x1C, 0, 0x1000);
    m_109c = 0;
}
void TLobby::trim_whitespace() {
    char *s = (char *)this;
    s32 len = strlen(s);
    s32 i;
    for (i = 0; i <= len && ((u8 *)s)[i] <= ' '; i++) {
    }
    if (i > len) {
        strcpy(s, "");
    } else {
        for (; ((u8 *)s)[len] <= ' '; len--) {
            s[len] = 0;
        }
        strcpy(s, s + i);
    }
}

}
