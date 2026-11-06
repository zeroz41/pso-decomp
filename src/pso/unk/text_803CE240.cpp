#include "types.h"
#include "pso/unk/text_803CE240.h"
#include "pso/unk/TLobby.h"

struct VObj_803C9E38;

struct Ent_803CE240 {
    u8 state;
    s8 phase;
    u8 pad2;
    s8 count;
    TLobby *lobby;
    TLobby *stream;
    TLobby *tracks[(0x90 - 0xC) / 4];
    VObj_803C9E38 *handlers[(0x1A8 - 0x90) / 4];
    u8 f1A8;
    u8 f1A9;
    u8 pad1AA[0x1B0 - 0x1AA];
    s32 f1B0;
    s32 f1B4;
    u8 pad1B8[0x1C0 - 0x1B8];
};

extern "C" {
void TLobby__sub_803CD99C();
void TLobby__sub_803CE2A0(Ent_803CE240 *);
s32 TLobby__sub_803CE1F4(TLobby *);
s32 TLobby__sub_803CE1D8(TLobby *);
void TLobby__sub_803C9E38(TLobby *, VObj_803C9E38 *);
s32 TLobby__sub_803C9CB0(TLobby *);
void update_scroll__6TLobbyFv(void);
s32 get_field_60__6TLobbyFv(TLobby *);
Ent_803CE240 lbl_80581330[4];
void TLobby__sub_803CE240(void) {
    s32 i;
    TLobby__sub_803CD99C();
    for (i = 0; i < 4; i++) {
        if ((s32)lbl_80581330[i].state == 1) {
            TLobby__sub_803CE2A0(&lbl_80581330[i]);
        }
    }
}

void TLobby__sub_803CE2A0(Ent_803CE240 *ent) {
    TLobby *lobby;
    TLobby **tracks;
    s32 i;
    s32 count;
    s32 a;
    s32 b;
    tracks = ent->tracks;
    lobby = ent->lobby;
    if (ent->phase == 1) {
        if (TLobby__sub_803CE1F4(lobby) == 2) {
            lobby->get_entry_pair(ent->f1B0 = ent->f1B4, &a, &b);
            ent->stream->set_scroll_offset((long long)(a / 2048));
            ent->stream->set_scroll_position((a + b) / 2048);
            ent->stream->set_coords((s32)update_scroll__6TLobbyFv, (s32)ent);
            lobby->set_client_slot(0);
            if ((s32)ent->f1A8 == 1 || (s32)ent->f1A9 == 1) {
                lobby->set_flag_4(1);
            }
            count = TLobby__sub_803CE1D8(lobby);
            for (i = 0; i < count; i++) {
                ent->tracks[i]->set_field98(1);
                TLobby__sub_803C9E38(tracks[i], ent->handlers[i]);
            }
            ent->phase = 2;
        }
    } else if (ent->phase == 2) {
        if (TLobby__sub_803CE1F4(lobby) == 3) {
            for (i = 0; i < ent->count; i++) {
                s32 r = TLobby__sub_803C9CB0(ent->tracks[i]);
                if (r != 5 && r != 0) {
                    break;
                }
            }
            if (i == ent->count) {
                ent->phase = 3;
            }
        }
    }
    for (i = 0; i < ent->count; i++) {
        if (get_field_60__6TLobbyFv(ent->tracks[i]) == -1) {
            ent->phase = 4;
            break;
        }
    }
}

}
