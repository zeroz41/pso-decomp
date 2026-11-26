#include "types.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdGameStartGC.h"

extern int multi_chr_select_state;

void TAdSelectCurGC::lock_navigation() { navigation_locked = 1; }

int TAdMultiPlyChrSelectGC::get_chr_select_state() { return multi_chr_select_state; }

s32 TAdGameStartGC::is_active() { return m_active; }

s32 TAdSinglePlyChrSelectGC::check_slot_flags(s32 slot, u32 mask) {
    u32 flags;
    if (secondary_card_character_save_buffer != 0) {
        if (slot >= 7) {
            return (u8)(0);
        }
        flags = *(u32 *)((u8 *)secondary_card_character_save_buffer + slot * 0x2798 + 0x420);
        return (u8)((flags & mask) != 0);
    }
    return (u8)(0);
}
