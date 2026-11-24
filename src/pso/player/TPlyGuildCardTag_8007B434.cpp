#include "types.h"
#include <string.h>
#include "pso/player/TPlyGuildCardTag_8007B434.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TProtocol.h"
#include "pso/ui/Language.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"


void __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(void *arg0, void *src) {
    *(u8 *)((s8 *)arg0 + 0) = (u8) *(u8 *)((s8 *)src + 0);
    *(u8 *)((s8 *)arg0 + 1) = (u8) *(u8 *)((s8 *)src + 1);
    *(u16 *)((s8 *)arg0 + 2) = (u16) *(u16 *)((s8 *)src + 2);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)src + 4);
}
void TLobby::fill_guild_card_from_char(s32 index) {
    uaddr char_index;
    u8 *temp_r31;
    char_index = (uaddr)TAdSinglePlyChrSelectGC::get_char_index(index);
    if (char_index != 0U) {
        temp_r31 = (unsigned char *) (char_index + 0x370);
        if (temp_r31 != NULL) {
            *(u8 *)((s8 *)((u8 *)this) + 0x8C) = (u8) (*(u8 *)((s8 *)((u8 *)this) + 0x8C) | 1);
            strncpy((char *)this + 8, (const char *)temp_r31, 0x17);
            *(s8 *)((s8 *)((u8 *)this) + 0x1F) = 0;
            *(u8 *)((s8 *)((u8 *)this) + 0x8F) = (u8) *(u8 *)((s8 *)temp_r31 + 0x31);
            *(u8 *)((s8 *)((u8 *)this) + 0x8E) = (u8) *(u8 *)((s8 *)temp_r31 + 0x30);
            *(s8 *)((s8 *)((u8 *)this) + 0x8D) = (s8) current_language;
            if (protocol_instance != NULL) {
                TPlyGuildCardTag *src = &protocol_instance->m_guildcard_tag;
                if (src->m_guildcard_number != 0) {
                    __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(this, src);
                }
            }
        }
    }
}
