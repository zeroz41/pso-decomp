#include "types.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/unk/text_8028EC70.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/charcreate/CharacterCreationModels.h"
#include "pso/ui/charcreate/CharacterAppearanceTables.h"

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off



#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off





extern "C" {
void TAdSinglePlyChrSelectGC__sub_8028F084(CreationTextureCacheEntry *entry, TCharaMaking *appearance);
void copy_slot_data__23TAdSinglePlyChrSelectGCFPvPv(CopySlotDataDst *d, CopySlotDataSrc *s);
void copy_player_visual_record(void *, void *);
s32 is_entry_equal__23TAdSinglePlyChrSelectGCFPvPv(IsEntryEqualA *a, IsEntryEqualB *b);
s32 count_char_diffs__23TAdSinglePlyChrSelectGCFPvPv(CountCharDiffsA *a, CountCharDiffsB *b);

s32 is_entry_equal__23TAdSinglePlyChrSelectGCFPvPv(IsEntryEqualA *a, IsEntryEqualB *b) {
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

s32 count_char_diffs__23TAdSinglePlyChrSelectGCFPvPv(CountCharDiffsA *a, CountCharDiffsB *b) {
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

void copy_slot_data__23TAdSinglePlyChrSelectGCFPvPv(CopySlotDataDst *d, CopySlotDataSrc *s) {
    s32 i;
    for (i = 0; i < 5; i++) d->a[i] = s->a[i];
    d->b = s->b;
}

#pragma push
#pragma fp_contract on
void TAdSinglePlyChrSelectGC__sub_8028ED54(saddr part) {
    ByteBlock_50 buf;
    CreationTextureCacheEntry *h;
    if (TAdSinglePlyChrSelectGC::count_remaining_slots() > 0) {
        buf = *(const ByteBlock_50 *)creation_player_character;
        if ((part < 0) || (part >= 5)) {
            if (TAdSinglePlyChrSelectGC::has_matching_entry(&buf) != 0) {
                return;
            }
            goto block_7;
        }
        if ((TAdSinglePlyChrSelectGC::has_matching_entry(&buf) == 0) || (select_unused_appearance_part(&buf, part) != 0)) {
block_7:
            h = TAdSinglePlyChrSelectGC::find_free_slot();
            if (h == 0U) {
                if (TAdSinglePlyChrSelectGC::evict_char_entries(1) == 0) {
                    return;
                }
                h = TAdSinglePlyChrSelectGC::find_free_slot();
            }
            TAdSinglePlyChrSelectGC__sub_8028F084(h, (TCharaMaking *)&buf);
        }
    }
}
#pragma pop

}

s32 select_unused_appearance_part(void *appearance, s32 part) {
    TAdSinglePlyChrSelectGCChr c = *(TAdSinglePlyChrSelectGCChr *)appearance;
    s32 max;
    s32 cur;
    s32 v;
    max = class_appearance_table[character_display_index(reinterpret_cast<uaddr>(&c))].counts[part];
    cur = c.sel[part];
    v = cur;
    do {
        if (++v >= max) {
            v = 0;
        }
    } while (v != cur);
    if (v != cur) {
        c.sel[part] = v;
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
        c.sel[part] = v;
        if (TAdSinglePlyChrSelectGC::has_matching_entry(&c) == 0) {
            goto ok;
        }
    }
    return 0;
ok:
    copy_player_visual_record(appearance, &c);
    return 1;
}
