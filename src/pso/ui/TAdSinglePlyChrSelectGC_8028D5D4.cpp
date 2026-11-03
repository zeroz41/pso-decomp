#include "types.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_8028D5D4.h"

u8 is_selection_done__23TAdSinglePlyChrSelectGCFPv(void *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x2C) == 2);
}

#include "pso/misc/TLobby.h"
#include "pso/misc/TLobby_8028D714.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {
u32 lbl_80518850[4];
u32 chr_select_load_buffer_table[8];
extern u32 chr_select_load_buffer_base;
extern u32 chr_select_load_buffer;
s32 TAdSinglePlyChrSelectGC::get_result() {
    if (((s32 (*)())is_selection_done__23TAdSinglePlyChrSelectGCFPv)() != 0) {
        return this->m_28;
    }
    return 0;
}
u32 TLobby::alloc_load_buffer(s32 size) {
    s32 slot = (s32)this;
    u32 p;
    if (chr_select_load_buffer_base == 0U) {
        return 0U;
    }
    TLobby__sub_8028D7D0(slot);
    if ((size < 0) || (size > 0xA000)) {
        return 0U;
    }
    size = (size + 0x1F) & ~0x1F;
    if (slot < 4) {
        p = lbl_80518850[slot];
        p += size;
        if (p >= chr_select_load_buffer_base + (slot + 1) * 0xA000) {
            return 0U;
        }
        lbl_80518850[slot] = p;
        return p;
    }
    {
        s32 j = slot - 4;
        p = chr_select_load_buffer_table[j];
        p += size;
        if (p >= chr_select_load_buffer + (j + 1) * 0xA000) {
            return 0U;
        }
        chr_select_load_buffer_table[j] = p;
    }
    return p;
}

}

int TLobby::start_load_default() { return alloc_load_buffer(0); }

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
        lbl_80518850[i] = temp_r3_2;
        return temp_r3_2;
    }
    temp_r4 = i - 4;
    temp_r3 = (*(s32 *)&chr_select_load_buffer) + (temp_r4 * 0xA000);
    chr_select_load_buffer_table[temp_r4] = temp_r3;
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
