#ifndef PSO_UI_WINDOW_WORDSELECTMESSAGE_H
#define PSO_UI_WINDOW_WORDSELECTMESSAGE_H

#include "types.h"

// A word-select message as it is sent (the 6x74 payload): the chosen word ids, what they are about, and a
// number some words carry (levels, amounts). The chat packet carries all 0x1C bytes.
struct WordSelectMessage {
    s16 count;
    s16 type;
    s16 ids[8];
    s32 numeric_parameter;
    s32 unknown_a4;

    void init();
    void reset_numeric_parameter();
    void set_numeric_parameter(s32 value);
    s32 get_numeric_parameter();
    void set_last_token(s16 id);
    void pop_token();
    void push_token(s16 id);
    void bswap();
    void remember_selected_id();
    void format_type6_message(char *buf, s32 *pos);
};

LAYOUT_ASSERT(WordSelectMessage_size, sizeof(WordSelectMessage) == 0x1C);

// 6x74: A word-select chat message. Sent by G_WordSelect_6x74::send_message; received by
// handle_6x74_word_select, which opens it in the word-select window. Size checked: init_header
// sets the header size to 8 words.
struct G_WordSelect_6x74 {
    u8 subcommand;
    u8 size;
    u16 client_id;
    WordSelectMessage message;

    void init_header();
    void bswap_message();
    void send();
    static void send_message(WordSelectMessage *message);
};

LAYOUT_ASSERT(G_WordSelect_6x74_size, sizeof(G_WordSelect_6x74) == 0x20);

#endif
