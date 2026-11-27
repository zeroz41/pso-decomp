#ifndef PSO_UI_CHAT_SHORTMAIL_H
#define PSO_UI_CHAT_SHORTMAIL_H

#include "types.h"

#include <stddef.h>

class TChatMessage;

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
    void fill_from_packet(TChatMessage &message);
};

LAYOUT_ASSERT(ShortMailEntrySize, sizeof(ShortMailEntry) == 0xD0);
LAYOUT_ASSERT(ShortMailEntryNameOffset, offsetof(ShortMailEntry, sender_name) == 0x8);
LAYOUT_ASSERT(ShortMailEntryBodyOffset, offsetof(ShortMailEntry, body) == 0x20);
LAYOUT_ASSERT(ShortMailEntryFlagsOffset, offsetof(ShortMailEntry, flags) == 0xCC);

ShortMailEntry *get_short_mail_entry(int index);
void remove_short_mail_by_id(u32 id);

void clear_unread_flags();
void store_short_mail(TChatMessage &message);
void clear_short_mail_on_unload();
void clear_short_mail_on_load();
void set_new_mail_flag();
void receive_short_mail(TChatMessage &message);

ShortMailEntry *find_short_mail_by_id(u32 id);
s32 find_free_short_mail_slot();
void clear_short_mails();
void remove_short_mail_at(s32 idx);

#endif
