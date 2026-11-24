#ifndef PSO_UI_CHAT_SHORTMAIL_H
#define PSO_UI_CHAT_SHORTMAIL_H

#include "types.h"

#include <stddef.h>

struct ShortMailPacketBuffer {
    u8 header[4];
    u8 sender_tag[8];
    char sender_name[16];
    s32 target_card_id;
    u8 body[0x208];
};

struct ShortMailEntry {
    s32 sender_card_id;
    u32 sequence_id;
    char sender_name[0x18];
    char body[0xAC];
    s8 flags;
    u8 padding[3];

    s32 get_sender_card_id();
    u32 get_id();
    char *get_sender_name();
    char *get_body();
    s8 get_flags();
    void set_replied();
    void clear_unread();
    int is_active();
    void fill_from_packet(u8 *packet);
};

LAYOUT_ASSERT(ShortMailEntrySize, sizeof(ShortMailEntry) == 0xD0);
LAYOUT_ASSERT(ShortMailEntryNameOffset, offsetof(ShortMailEntry, sender_name) == 0x8);
LAYOUT_ASSERT(ShortMailEntryBodyOffset, offsetof(ShortMailEntry, body) == 0x20);
LAYOUT_ASSERT(ShortMailEntryFlagsOffset, offsetof(ShortMailEntry, flags) == 0xCC);

ShortMailEntry *get_short_mail_entry(int index);
void remove_short_mail_by_id(u32 id);
void set_short_mail_text(char *message);

extern "C" {
void TLobby__sub_802258C8(void);
void TLobby__sub_80225A08(void *p);
void TLobby__sub_80225C44(void *p);
void TLobby__sub_80225C64(void *p);
void TLobby__sub_80225CB8(void);
void *get_com_card_list__6TLobbyFv(void *p);
void try_close__6TLobbyFPv(void *p);
void *TLobby__sub_8022598C(int a0);
void TLobby__sub_80225C8C(void *p);
}

#endif
