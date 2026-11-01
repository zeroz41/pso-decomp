#include "types.h"
#include "pso/misc/TLobby_8028D714.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8028D738_lbl_80518850 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8028D738_lbl_80518860 {
    s32 value;
    u8 remaining[0x1C];
};

extern RecoveredGlobal_8028D738_lbl_80518850 lbl_80518850;
extern RecoveredGlobal_8028D738_lbl_80518860 chr_select_load_buffer_table;
extern u32 chr_select_load_buffer_base;
extern u32 chr_select_load_buffer;
int TLobby::start_load_default() { return alloc_load_buffer(0); }

typedef char RecoveredGlobal_8028D738_lbl_80518850_size[sizeof(RecoveredGlobal_8028D738_lbl_80518850) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_8028D738_lbl_80518860_size[sizeof(RecoveredGlobal_8028D738_lbl_80518860) == 0x20 ? 1 : -1];
s32 TLobby__sub_8028D738(s32 i) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r4;
    if ((u32) chr_select_load_buffer_base == 0U) {
        return 0;
    }
    TLobby__sub_8028D7D0(i);
    if (i < 4) {
        temp_r3_2 = chr_select_load_buffer_base + (i * 0xA000);
        *(s32 *)((s8 *)&lbl_80518850.value + (i * 4)) = temp_r3_2;
        return temp_r3_2;
    }
    temp_r4 = i - 4;
    temp_r3 = (*(s32 *)&chr_select_load_buffer) + (temp_r4 * 0xA000);
    *(s32 *)((s8 *)&chr_select_load_buffer_table.value + (temp_r4 * 4)) = temp_r3;
    return temp_r3;
}

void TLobby__sub_8028D7D0(s32 i) {
    s32 n = 4;
    if (chr_select_load_buffer_base == 0) return;
    if (chr_select_load_buffer != 0) n = 12;
    if (i < 0) return;
    if (i >= n) return;
}

void TLobby::free_single_player_chr_select() {
    if (((u32) chr_select_load_buffer_base != 0U) && ((u32) chr_select_load_buffer != 0U)) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void*)((void*)chr_select_load_buffer)));
        chr_select_load_buffer = 0U;
    }
}

void TLobby::alloc_download_server() {
    if (((u32) chr_select_load_buffer_base != 0U) && ((u32) chr_select_load_buffer == 0U)) {
        chr_select_load_buffer = (s32)TQuestVmDownLoadServer::alloc(0x50000);
        if ((u32) chr_select_load_buffer == 0U) {
            return;
        }
    }
}

void TLobby::free_chr_select_singleton() {
    if ((u32) chr_select_load_buffer_base != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void*)((void*)chr_select_load_buffer_base)));
        chr_select_load_buffer_base = 0U;
    }
}
