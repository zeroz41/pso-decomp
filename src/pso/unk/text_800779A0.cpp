#include "types.h"
#include "pso/unk/text_800779A0.h"
#include "pso/network/protocol/choice_search.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {
extern u8 *lbl_805D4E5C;
void fn_800779A0(u8 *src) {
    if (lbl_805D4E5C == NULL) {
        lbl_805D4E5C = (u8 *)new ChoiceSearchResultList;
    }
    fn_800779FC((u32 *)lbl_805D4E5C, (u32 *)src);
}
u32 *fn_800779FC(u32 *dst, u32 *src) {
    u32 *d = dst;
    u32 b;
    u32 a;
    s32 i;
    *dst = *src;
    for (i = 0; i < 0x350; i++) {
        a = src[1];
        b = *(src += 2);
        d[1] = a;
        *(d += 2) = b;
    }
    return dst;
}
}

ChoiceSearchResultList::ChoiceSearchResultList() {}

ChoiceSearchResult::ChoiceSearchResult() {}
