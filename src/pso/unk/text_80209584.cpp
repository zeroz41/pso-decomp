#include "types.h"
#include "pso/misc/TLobby_8007C550.h"
#include "pso/unk/text_80209584.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Hdr_802095EC { s32 type; s32 size; s32 id; s32 x; };

struct Hdr_8020967C { s32 type; s32 size; s32 id; s32 x; };

extern "C" {
void *mem_alloc(u32 size);
Hdr_802095EC *find_type5_header__6TLobbyFPvi(Hdr_802095EC *arg, s32 id);
Hdr_8020967C *find_chunk_by_id__6TLobbyFPvi(Hdr_8020967C *arg, s32 id);
u8 *TLobby__sub_80209584(u8 *arg0, s32 arg1) {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0xE8);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = __ct__14SubtractiveRngFv((void *) temp_r3);
    }
    *(s32 *)((s8 *)arg0 + 0) = var_r0;
    *(s32 *)((s8 *)arg0 + 4) = (s32)mem_alloc((arg1 * 4));
    *(s32 *)((s8 *)arg0 + 8) = 0;
    *(s32 *)((s8 *)arg0 + 0xC) = arg1;
    *(s32 *)((s8 *)arg0 + 0x10) = arg1;
    return arg0;
}
Hdr_802095EC *find_type5_header__6TLobbyFPvi(Hdr_802095EC *arg, s32 id) {
    Hdr_802095EC *p;
    if ((p = arg) != NULL) {
        for (;;) {
            Hdr_802095EC h = *p;
            ((TLobby *)(&h))->bswap_quad_word();
            if (h.type == 5) {
                if (h.id == id) {
                    return p + 1;
                }
            }
            if (h.type == 0) {
                break;
            }
            p = (Hdr_802095EC *)((u8 *)p + h.size);
        }
    }
    return NULL;
}
Hdr_8020967C *find_chunk_by_id__6TLobbyFPvi(Hdr_8020967C *arg, s32 id) {
    Hdr_8020967C *p;
    if ((p = arg) != NULL) {
        for (;;) {
            Hdr_8020967C h = *p;
            ((TLobby *)(&h))->bswap_quad_word();
            if (h.type == 4) {
                if (h.id == id) {
                    return p + 1;
                }
            }
            if (h.type == 0) {
                break;
            }
            p = (Hdr_8020967C *)((u8 *)p + h.size);
        }
    }
    return NULL;
}

}
