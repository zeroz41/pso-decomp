#include "types.h"
#include <stdlib.h>
#include "pso/system/data/FlagWord.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/player/TObjPlayer.h"
typedef void (*Fn_801Fn)(void);
struct Ent_8010F0C0 { Fn_801Fn a; Fn_801Fn b; };
struct LoadUnloadSetUnloadSet {
    s32 count;
    Ent_8010F0C0 *ents;
    u8 *order;
    u8 pad[4];
};
struct LoadUnloadSetShuffleOrderO { s32 count; s32 f4; u8 *buf; };

struct LoadUnloadSetShuffleOrderO2 { s32 count; s32 f4; u8 *buf; };

void load_unload_set_init_order(LoadUnloadSetShuffleOrderO *self);
void load_unload_set_shuffle_order(LoadUnloadSetShuffleOrderO2 *self);

void load_unload_set_shuffle_order(LoadUnloadSetShuffleOrderO2 *self) {
    s32 i;
    u32 j;
    u8 t;
    load_unload_set_init_order((LoadUnloadSetShuffleOrderO *)(self));
    if (self->buf != NULL) {
        for (i = 0; i != self->count; i++) {
            j = (u32)((f32)self->count * (3.0517578e-05f * (f32)rand()));
            t = self->buf[i];
            self->buf[i] = self->buf[j];
            self->buf[j] = t;
        }
    }
}

void load_unload_set_init_order(LoadUnloadSetShuffleOrderO *self) {
    s32 i;
    if (self->buf == 0) {
        return;
    }
    for (i = 0; i != self->count; i++) {
        self->buf[i] = i;
    }
}

#pragma push
#pragma opt_common_subs off
extern "C" {
void load_unload_set_unload(LoadUnloadSetUnloadSet *s) {
    s32 i;
    Fn_801Fn f;
    if (test_flags_any((s32 *)((u8 *)s + 0xC), 1) != 0) {
        for (i = s->count - 1; i >= 0; i--) {
            if (s->order != 0) {
                f = s->ents[s->order[i]].b;
            } else {
                f = s->ents[i].b;
            }
            if (f != 0) {
                f();
            }
        }
        ((FlagWord *)((u8 *)s + 0xC))->clear(1);
    }
}

void load_unload_set_load(LoadUnloadSetUnloadSet *s) {
    s32 i;
    Fn_801Fn f;
    if (test_flags_any((s32 *)((u8 *)s + 0xC), 1) == 0) {
        load_unload_set_shuffle_order((LoadUnloadSetShuffleOrderO2 *)(s));
        for (i = 0; i != s->count; i++) {
            if (s->order != 0) {
                f = s->ents[s->order[i]].a;
            } else {
                f = s->ents[i].a;
            }
            if (f != 0) {
                f();
            }
        }
        ((FlagWord *)((u8 *)s + 0xC))->set(1);
    }
}
}
#pragma pop
