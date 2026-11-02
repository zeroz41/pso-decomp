#include "types.h"

// Download-server work buffers, shared by TQuestVmDownLoadServer_803E5668 and _803E6970. Defined ahead of their
// uses in either file they change codegen of an exact function there; defined after the last use (end of _803E5668,
// after its own .bss) they compile identically, so the owner is open. They stay here because the two users disagree on
// quest_download_text_buffer (s16[0x200] in _803E5668, a 0x400-byte u8 buffer in _803E6970; the symbol is 0x404).
s32 quest_vm_download_server_file_info[0x11];
u8 quest_download_slot_table[0x2C78];
u8 quest_name_index_table[0x1000];
u8 lbl_80591AC4[0x404];
u8 lbl_80591EC8[0x2000];
void *lbl_80593EC8[0x450];
u8 lbl_80595008[0x990];
u8 quest_download_slot_chain_table[0x8C0];
u8 lbl_80596258[0xC];
u8 quest_download_text_buffer[0x404];
