#include "types.h"

// Download-server work buffers of the name-cache TU (_803E8918, .bss pool from 0x80591EC8) and the slot-table TU
// (_803E9A24, pool from 0x80595008). They stay here until those TUs link: defined in either TU the pooled-base
// addressing of 803E8DA0 / 803EA9E8 comes out as the original's. quest_download_slot_chain_table is also used by
// TQuestVmDownLoadServer_803E5668; quest_download_text_buffer is s16[0x200] there, a 0x400-byte u8 buffer in
// _803E9A24 (the symbol is 0x404).
u8 lbl_80591EC8[0x2000];
void *lbl_80593EC8[0x450];
u8 lbl_80595008[0x990];
u8 quest_download_slot_chain_table[0x8C0];
u8 lbl_80596258[0xC];
u8 quest_download_text_buffer[0x404];
