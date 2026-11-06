#include "types.h"
#include "pso/unk/TLobby.h"
struct Hdr_80209C58 { s32 type; s32 size; s32 id; s32 x; };

extern "C" {
extern s32 lbl_805D60CC;
Hdr_80209C58 *find_header_by_id__6TLobbyFPvi(Hdr_80209C58 *arg, s32 id);
Hdr_80209C58 *find_header_by_id__6TLobbyFPvi(Hdr_80209C58 *arg, s32 id) {
    Hdr_80209C58 *p;
    if ((p = arg) != NULL) {
        for (;;) {
            Hdr_80209C58 h = *p;
            ((TLobby *)(&h))->bswap_quad_word();
            if (h.type == 3) {
                if (h.id == id) {
                    lbl_805D60CC = h.x;
                    return p + 1;
                }
            }
            if (h.type == 0) {
                break;
            }
            p = (Hdr_80209C58 *)((u8 *)p + h.size);
        }
    }
    lbl_805D60CC = -1;
    return NULL;
}

}
