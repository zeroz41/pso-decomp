#include "types.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern u32 secondary_card_character_save_buffer;

    extern int lbl_805D69E8;
int TAdMultiPlyChrSelectGC::get_chr_select_state() {  return lbl_805D69E8; }

s32 TAdMultiPlyChrSelectGC::get_ready_state() { return *(s32*)((char*)this + 0xa0); }
u8 TAdSinglePlyChrSelectGC::check_slot_flags(s32 arg0, u32 arg1) {
    u32 flags;
    if (secondary_card_character_save_buffer != 0) {
        if (arg0 >= 7) {
            return 0;
        }
        flags = *(u32 *)((u8 *)secondary_card_character_save_buffer + arg0 * 0x2798 + 0x420);
        return (flags & arg1) != 0;
    }
    return 0;
}
