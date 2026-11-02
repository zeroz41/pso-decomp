#include "types.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_8028D5D4.h"

u8 is_selection_done__23TAdSinglePlyChrSelectGCFPv(void *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x2C) == 2);
}

#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {
s32 TLobby__sub_8028D7D0();
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
u32 TLobby::alloc_load_buffer(s32 arg1) {
    s32 arg0 = (s32)this;
    u32 p;
    if (chr_select_load_buffer_base == 0U) {
        return 0U;
    }
    TLobby__sub_8028D7D0();
    if ((arg1 < 0) || (arg1 > 0xA000)) {
        return 0U;
    }
    arg1 = (arg1 + 0x1F) & ~0x1F;
    if (arg0 < 4) {
        p = lbl_80518850[arg0];
        p += arg1;
        if (p >= chr_select_load_buffer_base + (arg0 + 1) * 0xA000) {
            return 0U;
        }
        lbl_80518850[arg0] = p;
        return p;
    }
    {
        s32 j = arg0 - 4;
        p = chr_select_load_buffer_table[j];
        p += arg1;
        if (p >= chr_select_load_buffer + (j + 1) * 0xA000) {
            return 0U;
        }
        chr_select_load_buffer_table[j] = p;
    }
    return p;
}

}
