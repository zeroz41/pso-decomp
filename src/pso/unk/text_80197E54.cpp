#include "types.h"
#include "pso/unk/text_80197E54.h"
#include "pso/unk/text_80197FD0.h"
#include "pso/unk/text_802432F0.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"

struct Stat_80197E64 { u8 pad0[4]; u16 blocks; u8 pad6[0xE]; };

struct Hdr_80197E64 { u8 pad0[0x58]; s32 f58; s32 f5C; u8 pad60[0xC]; };

extern s32 TObjSinBoard__texture_buffer;
extern "C" {
void *alloc__22TQuestVmDownLoadServerFv(s32);
s32 TAdPlayerLoadGC__sub_801E1538(Hdr_80197E64 *, void *);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
s32 get_card_file_info__15TAdPlayerLoadGCFiPvPv(s32, s32, Stat_80197E64 *);
void memset(void *, int, int);
}
extern s32 memcard_file_099_name;
bool is_signboard_texture_buffer_missing(void) {
    return TObjSinBoard__texture_buffer == 0;
}
void load_memcard_file(void) {
    Stat_80197E64 stat;
    Hdr_80197E64 hdr;
    s32 slot;
    void *buf;
    s32 r;
    if (get_current_floor_area() != AREA_PIONEER2_EP1 && get_current_floor_area() != AREA_PIONEER2_EP2) {
        return;
    }
    if (((s32 (*)(void))is_signboard_texture_buffer_missing)() == 0) {
        return;
    }
    while (1) {
        slot = fn_802432F0((void *)memcard_file_099_name);
        if (slot != -2) {
            break;
        }
        TLobby::run_frame();
    }
    if (slot == -1) {
        return;
    }
    do {
        r = get_card_file_info__15TAdPlayerLoadGCFiPvPv(slot, memcard_file_099_name, &stat);
    } while ((u32)r == 0xFFFFFFFF);
    if (r != 0) {
        return;
    }
    buf = alloc__22TQuestVmDownLoadServerFv(stat.blocks << 13);
    if (buf == 0) {
        return;
    }
    memset(buf, 0, stat.blocks << 13);
    TAdSinglePlyChrSelectGC::load_player_slot(slot, (const char *)memcard_file_099_name, buf);
    while (TAdPlayerLoadGC__sub_801E1B50(slot) != 0) {
        TLobby::run_frame();
    }
    if (TAdPlayerLoadGC__sub_801E1538(&hdr, buf) != 0) {
        TAdSinglePlyChrSelectGC::safe_free((u32)buf);
        return;
    }
    fn_80197FD0((void *)hdr.f58, (void *)hdr.f5C);
    TAdSinglePlyChrSelectGC::safe_free((u32)buf);
}
