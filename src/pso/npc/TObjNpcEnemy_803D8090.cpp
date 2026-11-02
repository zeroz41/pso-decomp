#include "types.h"
#include "pso/npc/TObjNpcEnemy_803D8090.h"
#include "pso/enemy/TObjEneMe1Gee.h"
#include "pso/npc/TObjNpcEnemy.h"

struct Rec_803D8098 { s16 x; s16 y; s16 z; s16 pad; s32 f8; char *name; };

extern "C" {
char *strncpy(char *, const char *, unsigned long);
unsigned long strlen(const char *);
extern char *debug_text_pool_cursor;
extern Rec_803D8098 *debug_text_record_cursor;
extern f32 debug_text_scale;
extern s32 debug_text_global_count;
int sprintf(char *, const char *, ...);
extern const f32 lbl_805E0EB8;
extern const f32 lbl_805E0EBC;
void TObjNpcEnemy::set_global_count(s32 arg0) {
    debug_text_global_count = arg0;
}
void TObjEneMe1Gee::queue_debug_text(s32 arg0, char *arg1) {
    s16 len;
    s16 x;
    f32 scale;
    Rec_803D8098 *r;
    strlen(arg1);
    x = (s16) ((s16) (arg0 >> 16) * (scale = debug_text_scale));
    len = strlen(arg1);
    r = debug_text_record_cursor++;
    r->x = x;
    r->y = (s16) ((s16) (arg0 & 0xFFFF) * scale);
    r->z = (s16) debug_text_scale;
    r->f8 = debug_text_global_count;
    r->name = debug_text_pool_cursor;
    strncpy(debug_text_pool_cursor, arg1, len);
    debug_text_pool_cursor[len] = 0;
    debug_text_pool_cursor += len + 1;
}
}

void print_float_padded(s32 arg0, s32 prec, f32 val) {
    char buf[24];
    s16 y;
    f32 scale;
    Rec_803D8098 *r;
    char *p;
    s32 n;
    s32 i;
    s32 pad;
    s32 total;
    s32 j;

    y = (s16) ((s16) (arg0 & 0xFFFF) * (scale = debug_text_scale));
    r = debug_text_record_cursor++;
    r->x = (s16) ((s16) (arg0 >> 16) * scale);
    r->y = y;
    r->z = (s16) debug_text_scale;
    r->f8 = debug_text_global_count;
    r->name = debug_text_pool_cursor;
    p = debug_text_pool_cursor;
    if (val < lbl_805E0EB8) {
        *p++ = '-';
        val *= lbl_805E0EBC;
    }
    sprintf(buf, "%0.*f", 5, val);
    n = strlen(buf);
    for (i = 0; i < n; i++) {
        if (buf[i] == '.') {
            break;
        }
    }
    pad = prec - i;
    total = n + pad;
    for (j = total; j >= pad; j--) {
        buf[j] = buf[n--];
    }
    for (j = 0; j < pad; j++) {
        buf[j] = '0';
    }
    for (j = 0; j < total; j++) {
        *p++ = buf[j];
    }
    debug_text_pool_cursor[total] = 0;
    debug_text_pool_cursor += total + 1;
}
