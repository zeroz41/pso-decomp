#include "types.h"
#include "pso/player/TPlyGuildCardTag_8007B434.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/Language.h"

extern "C" {
s32 strncpy(void *, int, int);
extern u8 *TLobby__protocol_instance;
void __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(void *arg0, void *arg1) {
    *(u8 *)((s8 *)arg0 + 0) = (u8) *(u8 *)((s8 *)arg1 + 0);
    *(u8 *)((s8 *)arg0 + 1) = (u8) *(u8 *)((s8 *)arg1 + 1);
    *(u16 *)((s8 *)arg0 + 2) = (u16) *(u16 *)((s8 *)arg1 + 2);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
}
void TLobby::fill_guild_card_from_char(s32 arg1) {
    u32 temp_r3;
    u8 *temp_r31;
    temp_r3 = (u32)get_char_index__23TAdSinglePlyChrSelectGCFUi(arg1);
    if (temp_r3 != 0U) {
        temp_r31 = (unsigned char *) (temp_r3 + 0x370);
        if (temp_r31 != NULL) {
            *(u8 *)((s8 *)((u8 *)this) + 0x8C) = (u8) (*(u8 *)((s8 *)((u8 *)this) + 0x8C) | 1);
            strncpy((void *) (((u8 *)this) + 8), (int)temp_r31, 0x17);
            *(s8 *)((s8 *)((u8 *)this) + 0x1F) = 0;
            *(u8 *)((s8 *)((u8 *)this) + 0x8F) = (u8) *(u8 *)((s8 *)temp_r31 + 0x31);
            *(u8 *)((s8 *)((u8 *)this) + 0x8E) = (u8) *(u8 *)((s8 *)temp_r31 + 0x30);
            *(s8 *)((s8 *)((u8 *)this) + 0x8D) = (s8) current_language;
            if ((void *) TLobby__protocol_instance != NULL) {
                u8 *src = TLobby__protocol_instance + 0x1900;
                if ((u32) *(u32 *)((s8 *)src + 4) != 0U) {
                    __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(this, (void *) src);
                }
            }
        }
    }
}

}
