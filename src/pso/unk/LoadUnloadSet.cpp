#include "types.h"
#include <stdlib.h>
#include "pso/system/data/FlagWord.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_8010F168.h"
#include "pso/system/memory.h"
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

extern "C" {


void *TItemDrop__sub_8010F168(void *drop, s16 flags) {
    if (drop != NULL) {
        load_unload_set_unload((LoadUnloadSetUnloadSet *)drop);
        mem_free((void *)(*(saddr *)((s8 *)drop + 8)));
        if (flags > 0) {
            ::operator delete(drop);
        }
    }
    return drop;
}

u8 *TItemDrop__sub_8010F1B8(u8 *drop, s32 id, s32 size) {
    __ct__8FlagWordFv((drop + 0xC));
    *(s32 *)((s8 *)drop + 4) = id;
    *(s32 *)((s8 *)drop + 0) = size;
    *(s32 *)((s8 *)drop + 8) = (saddr)mem_alloc((size));
    load_unload_set_load((LoadUnloadSetUnloadSet *)drop);
    return drop;
}

}

// inferred: counts the {load, unload} pairs up to the null pair and builds a 0x10-byte set over them.
s32 create_load_unload_set(ItemClassLoadUnloadEntry *table) {
    s32 found;
    s32 i;
    saddr r;
    if (table != 0) {
        found = 0;
        i = 0;
        while (found == 0) {
            void (*a)() = table[i].load; void (*b)() = table[i].unload;
            if (a == 0 && b == 0) {
                found = i;
            }
            i++;
        }
        if (found != 0) {
            r = (saddr)::operator new(0x10);
            if (r != 0) {
                r = (saddr)TItemDrop__sub_8010F1B8((u8 *)r, (saddr)table, found);
            }
            return r;
        }
    }
    return 0;
}
