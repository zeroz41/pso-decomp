#include "types.h"
#include "pso/unk/text_8028EC70.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
struct ByteBlock_50 { u8 bytes[0x50]; };

struct Dst_8028ED24 { u8 pad[4]; s16 a[5]; u8 b; };

struct Src_8028ED24 { u8 pad[0x30]; u8 b; u8 pad2[7]; s16 a[5]; };

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
struct Chr_8028EE20 { u8 pad[0x38]; s16 sel[5]; u8 pad2[0x50 - 0x42]; };

struct Row_8028EE20 { s16 max[0x16]; };

struct A_8028EC70 { u8 pad0[4]; s16 v[5]; s8 e; };

struct B_8028EC70 { u8 pad0[0x30]; s8 e; u8 pad31[7]; s16 v[5]; };

struct A_8028ECCC { u8 pad0[4]; s16 v[5]; s8 e; };

struct B_8028ECCC { u8 pad0[0x30]; s8 e; u8 pad31[7]; s16 v[5]; };

extern "C" {
void TAdSinglePlyChrSelectGC__sub_8028F084(CreationTextureCacheEntry *entry, TCharaMaking *appearance);
u32 find_free_slot__23TAdSinglePlyChrSelectGCFv();
extern s32 creation_player_character;
void copy_slot_data__23TAdSinglePlyChrSelectGCFPvPv(Dst_8028ED24 *d, Src_8028ED24 *s);
void copy_player_visual_record(void *, void *);
extern Row_8028EE20 class_appearance_table[];
s32 is_entry_equal__23TAdSinglePlyChrSelectGCFPvPv(A_8028EC70 *a, B_8028EC70 *b);
s32 count_char_diffs__23TAdSinglePlyChrSelectGCFPvPv(A_8028ECCC *a, B_8028ECCC *b);

s32 is_entry_equal__23TAdSinglePlyChrSelectGCFPvPv(A_8028EC70 *a, B_8028EC70 *b) {
    s32 i;
    if (a->e != b->e) {
        return 0;
    }
    for (i = 0; i < 5; i++) {
        if (a->v[i] != b->v[i]) {
            return 0;
        }
    }
    return 1;
}

s32 count_char_diffs__23TAdSinglePlyChrSelectGCFPvPv(A_8028ECCC *a, B_8028ECCC *b) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 5; i++) {
        if (a->v[i] != b->v[i]) {
            n++;
        }
    }
    if (a->e != b->e) {
        n++;
    }
    return n;
}

void copy_slot_data__23TAdSinglePlyChrSelectGCFPvPv(Dst_8028ED24 *d, Src_8028ED24 *s) {
    s32 i;
    for (i = 0; i < 5; i++) d->a[i] = s->a[i];
    d->b = s->b;
}

#pragma push
#pragma fp_contract on
void TAdSinglePlyChrSelectGC__sub_8028ED54(s32 arg1_) {
    ByteBlock_50 buf;
    u32 h;
    if (TAdSinglePlyChrSelectGC::count_remaining_slots() > 0) {
        buf = *(const ByteBlock_50 *)creation_player_character;
        if ((arg1_ < 0) || (arg1_ >= 5)) {
            if (TAdSinglePlyChrSelectGC::has_matching_entry(&buf) != 0) {
                return;
            }
            goto block_7;
        }
        if ((TAdSinglePlyChrSelectGC::has_matching_entry((void *)&buf) == 0) || (TAdSinglePlyChrSelectGC__sub_8028EE20((void *)((void *)&buf), (void *)arg1_) != 0)) {
block_7:
            h = find_free_slot__23TAdSinglePlyChrSelectGCFv();
            if (h == 0U) {
                if (TAdSinglePlyChrSelectGC::evict_char_entries(1) == 0) {
                    return;
                }
                h = find_free_slot__23TAdSinglePlyChrSelectGCFv();
            }
            TAdSinglePlyChrSelectGC__sub_8028F084((CreationTextureCacheEntry *)h, (TCharaMaking *)&buf);
        }
    }
}
#pragma pop

s32 TAdSinglePlyChrSelectGC__sub_8028EE20(void *arg0, void *arg1_) {
    s32 arg1 = (s32)arg1_;
    Chr_8028EE20 c = *(Chr_8028EE20 *)arg0;
    s32 max;
    s32 cur;
    s32 v;
    max = class_appearance_table[((TCharaMaking *)(&c))->get_display_index()].max[arg1];
    cur = c.sel[arg1];
    v = cur;
    do {
        if (++v >= max) {
            v = 0;
        }
    } while (v != cur);
    if (v != cur) {
        c.sel[arg1] = v;
        if (TAdSinglePlyChrSelectGC::has_matching_entry(&c) == 0) {
            goto ok;
        }
    }
    v = cur;
    do {
        if (--v < 0) {
            v = max - 1;
        }
    } while (v != cur);
    if (v != cur) {
        c.sel[arg1] = v;
        if (TAdSinglePlyChrSelectGC::has_matching_entry(&c) == 0) {
            goto ok;
        }
    }
    return 0;
ok:
    copy_player_visual_record(arg0, &c);
    return 1;
}

}
