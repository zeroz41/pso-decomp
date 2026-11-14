#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8001C5E8.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

u8 chr_select_state; // inferred: only read, by TAdSinglePlyChrSelectGC::get_chr_select_state

u8 TAdSinglePlyChrSelectGC::get_chr_select_state() {
    return chr_select_state;
}

extern s32 guild_card_save_file_block_count;

s32 TAdSinglePlyChrSelectGC__sub_8001C5F0(void) {
    return guild_card_save_file_block_count;
}
