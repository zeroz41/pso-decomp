#include "types.h"
#include "pso/unk/text_8013ADD0.h"

extern u8 *text_language_group_table;
s32 get_online_message_text(s32 id) {
    return *(s32 *)((s8 *)(*(saddr *)((s8 *)text_language_group_table + 0x38)) + (id * 4));
}
