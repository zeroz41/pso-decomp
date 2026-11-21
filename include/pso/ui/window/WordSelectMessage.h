#ifndef PSO_UI_WINDOW_WORDSELECTMESSAGE_H
#define PSO_UI_WINDOW_WORDSELECTMESSAGE_H

#include "types.h"

// Compact word-select payload, independent of the window displaying it.
struct WordSelectMessage {
    s16 count;
    s16 type;
    s16 ids[4];
};

LAYOUT_ASSERT(WordSelectMessage_size, sizeof(WordSelectMessage) == 12);

// The dispatcher and language formatters share the 16-bit speaker entity ID.
extern "C" {
// Spanish prefix categories, loaded from the word-select archive header.
extern u8 *lbl_805D6E4C;

s32 format_entry_text__9TWindowDDFPvPv(WordSelectMessage *words, char *buffer);
s32 format_english_message__9TWindowDDFPvPvUs(WordSelectMessage *words, char *buffer, u16 player);
s32 format_german_message__9TWindowDDFPvPvUs(WordSelectMessage *words, char *buffer, u16 player);
s32 format_message_text__9TWindowDDFPvPvUs(WordSelectMessage *words, char *buffer, u16 player);
s32 TWindowDD__sub_80345608(WordSelectMessage *words, char *buffer, u16 player);
}

#endif
